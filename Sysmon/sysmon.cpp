#include "sysmon.h"
#include "ui_sysmon.h"
#include "main.h"
#include "process.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>
#include <QStandardItemModel>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <QTimer>
#include <QObject>
#include <QtCharts>

using namespace std;

/* Lists all directories in the provided directory */
vector<pid_t> Sysmon::listDir(const string& path)
{
    DIR *dir;
    struct dirent *ent;
    pid_t current;
    vector<pid_t> listofprocs;

    if((dir = opendir (path.c_str())) != NULL)
        while ((ent = readdir (dir)) != NULL)
            if(sscanf(ent->d_name, "%d%*c", &current) == 1)
                listofprocs.push_back(current);


    closedir (dir);
    return listofprocs;
}

void GetAllProcsInfo(procinfo *tProcInfo, vector<pid_t> *procs, bool display){
    for (pid_t pid : *procs){
        get_proc_info(pid, tProcInfo);

        if(display){
            cout << tProcInfo -> pid << setw(6)
                << "  :" << setw(30) <<  tProcInfo -> exName
                << setw(20) << tProcInfo -> rss
                << setw(20) << tProcInfo -> vsize
                << endl;

            /**
             * LOGIC
             * Get the value in the first loop and store it in old
             * in the second loop we compare that last value of old
             * memory old history.
             */


            if (strcmp(tProcInfo -> exName, "a.out") == 0){
                cout << tProcInfo -> exName << " under PID " << tProcInfo -> pid
                     << " is using " << tProcInfo -> vsize / 1024 << " MB" << endl;
            }
        }
    }

}

void Sysmon::Temp(QStandardItemModel *inputModel, vector<pid_t> procs){

    QStandardItem *currentPID, *pidCommand, *pidMemUsage, *pidRssSize, *pidState;
    QString myString = "";
    int row = 0;
    bool FOUND = false;


    for (pid_t pid : procs){
        Process tempProcess;
        get_proc_info(pid, &procInfo);

        myString = QString(procInfo.state);

        if (myString.compare("S")){
            myString = QString("Running");
        } else {
            myString = QString("Sleeping");
        }

        currentPID  = new QStandardItem(QString::number(procInfo.pid));
        pidCommand  = new QStandardItem(procInfo.exName);
        pidMemUsage = new QStandardItem(QString::number(procInfo.vsize));
        pidRssSize  = new QStandardItem(QString::number(procInfo.rss));
        pidState    = new QStandardItem(myString);

        // LOGIC:

        if (procDB.size() == 0) {
            tempProcess.setName(procInfo.exName);
            tempProcess.insert(PID, procInfo.pid);
            tempProcess.insert(RSS, procInfo.rss);
            tempProcess.insert(VM, procInfo.vsize);
            procDB.push_back(tempProcess);
            FOUND = true;
        }

        // Look for the process and make sure it is not already
        // there. If the process is there already, just add to
        // it's values vector

        for (Process &d: procDB){
            if(d.getPID() == procInfo.pid){
                if(d.WithinRange(RSS, procInfo.rss)){
                    d.insert(RSS, procInfo.rss);
                }
                d.insert(VM, procInfo.vsize);
                FOUND = true;
                if(DEBUG_MODE)
                cout << "Exists: " << d.getName() << endl;
                break;
            } else {
                FOUND = false;
            }
        }

        // If not found
        if(!FOUND){
            tempProcess.setName(procInfo.exName);
            tempProcess.insert(PID, procInfo.pid);
            tempProcess.insert(RSS, procInfo.rss);
            tempProcess.insert(VM, procInfo.vsize);
            procDB.push_back(tempProcess);
            FOUND = false;
        }

        QStandardItem *myData[] = {pidState, currentPID, pidCommand, pidMemUsage, pidRssSize };
        PopulateTable(inputModel,myData, row++);
        ui->tableView->update();
    }
}

void Sysmon::PopulateTable(QStandardItemModel *inputModel,QStandardItem *data[], int row){
    inputModel->setItem(row,0,data[0]);
    inputModel->setItem(row,1,data[1]);
    inputModel->setItem(row,2,data[2]);
    inputModel->setItem(row,3,data[3]);
    inputModel->setItem(row,4,data[4]);
}

void Sysmon::fetch () {
  qDebug() << "Something was clicked!";
  QObject *s = sender();
  qDebug() << s->objectName();
}

void Sysmon :: OnDoubleClicked ( const  QModelIndex  & index )
{
   //QString a = ( index.model()-> data ( index.model() -> index ( index. row ( ) , index. column ( ) ) ) . toString ( ) ) ;
   QString pid =  index.model()->data(index.model()->index(index.row(), 1)).toString();
   for (Process s : procDB){
       if(s.getPID() == pid.toInt(NULL,10)){
        Sysmon::ClickOnProcess(s);
        break;
       }
   }

   cout << pid.toStdString() << endl;

}

Sysmon::Sysmon(QWidget *parent) :QWidget(parent), ui(new Ui::Sysmon)
{
    ui->setupUi(this);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Process State")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("PID")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Command")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("Memory Usage (KB)")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QString("Resident Memory (KB)")));

    Sysmon::refreshButtonHandler();

    connect(ui->aboutButton   , SIGNAL(released()), this, SLOT(aboutButtonHandler()));
    connect(ui->monitorButton , SIGNAL(released()), this, SLOT(monitorButtonHandler()));
    connect(ui->refreshButton , SIGNAL(released()), this, SLOT(refreshButtonHandler()));
    connect(ui->toolButton    , SIGNAL(released()), this, SLOT(debugButtonHandler()));
    connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(OnDoubleClicked(QModelIndex)));

    QWidget * tab = ui->tab_2;
    QVBoxLayout * layout = new QVBoxLayout;
    tab->setLayout(layout);
    tab->show();



    ui->tableView->setModel(model);
}


void Sysmon::aboutButtonHandler(){
    QMessageBox::information(
        this,
        tr("About"),
        tr("System Monitor by\nMohamad Yassine & Tamara Alhajj\nAlso this is the earf"));

}

void Sysmon::ClickOnProcess(Process input){
    using namespace QtCharts;
    int counter = 0;
    QString appName = QString::fromStdString(input.getName());

    QLineSeries *series = new QLineSeries();

    for (double s : input.getVector()){
        series->append(counter++, s);
        *series << QPointF(counter++, s);

    }

    QChart *chart = new QChart();

    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axisX()->setTitleText("Interval");
    chart->axisY()->setTitleText("Usage in KB");
    chart->setTitle(appName);

    QChartView *chartView = new QChartView(chart);

    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setGeometry(100,200,400,400);
    chartView->activateWindow();
    chartView->raise();
    chartView->show();
}

void Sysmon::monitorButtonHandler(){
    QDialog dialog;
    QMessageBox msgBox;
    msgBox.setText("The proccess monitoring system has started. To turn it off press 'Monitor' once more");
    msgBox.exec();

    // Timer that refreshes the process table (vector) every INTERVAL_SECONDSS
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(refreshButtonHandler()));
    if(!timer->isActive()){
        timer->start(INTERVAL_SECONDS); // time specified in ms
        cout << "Constant monitoring has started" << endl;
    }else{
        timer->stop(); // stop the timer
        cout << "Constant monitoring has been stopped" << endl;
    }

}

void Sysmon::debugButtonHandler(){
    if(DEBUG_MODE) DEBUG_MODE = false;
    else DEBUG_MODE = true;
}

void Sysmon::refreshButtonHandler(){
    procs = listDir("/proc/");
    GetAllProcsInfo(&procInfo, &procs, 0);
    Sysmon::Temp(model,procs);

    ui->tableView->setModel(model);

    for (Process s : procDB){
       // Check if process is still running or not
       if (!kill(s.getPID(),0)){
        s.FLAG=true;
        s.model();
        s.FLAG=false;
       }
    }

    if (DEBUG_MODE){
        for (Process s : procDB){
            cout << endl << s.getName() << endl;
            s.printOutValues(RSS);
        }
        cout << endl;
        cout << "Size of DB (bytes): " << sizeof(Process) << endl;
        cout << "Size of DB: " << procDB.size() * sizeof(Process) << endl;
    }

}

Sysmon::~Sysmon()
{
    delete ui;
}
