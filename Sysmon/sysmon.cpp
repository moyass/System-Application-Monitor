#include "sysmon.h"
#include "ui_sysmon.h"
#include "main.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>
#include <QStandardItemModel>
#include <string>
#include <vector>
#include <iomanip>

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


            /** LOGIC
             * Get the value in the first loop and store it in old
             * in the second loop we compare that last value of old
             * memory old history.
             *
             */
            if (strcmp(tProcInfo -> exName, "a.out") == 0){
                cout << tProcInfo -> exName << " under PID " << tProcInfo -> pid
                     << " is using " << tProcInfo -> vsize / 1024 << " MB" << endl;
            }
        }
    }

}

void Sysmon::Temp(QStandardItemModel *inputModel, vector<pid_t> procs){

    QStandardItem *currentPID, *pidCommand, *pidMemUsage;

    QString myString = "";

    int row = 0;

    for (pid_t pid : procs){
        get_proc_info(pid, &procInfo);

        myString = QString::number(procInfo.pid);
        currentPID = new QStandardItem(myString);
        pidCommand = new QStandardItem(procInfo.exName);
        pidMemUsage = new QStandardItem(QString::number(procInfo.vsize));

        QStandardItem *myData[] = {currentPID, pidCommand, pidMemUsage};

        PopulateTable(inputModel,myData, row++);

    }
}

void Sysmon::PopulateTable(QStandardItemModel *inputModel,QStandardItem *data[], int row){
    inputModel->setItem(row,0,data[0]);
    inputModel->setItem(row,1,data[1]);
    inputModel->setItem(row,2,data[2]);
}

Sysmon::Sysmon(QWidget *parent) :QWidget(parent), ui(new Ui::Sysmon)
{

    ui->setupUi(this);



    /*
    cout << "Total Process Count " << procs.size() << endl;
       cout << "Process PID  " << setw(6) << setw(20) <<  "COMMAND NAME"
                << setw(20) << "RSS" << setw(20) << "VmSize" << endl;
    */

    procs = listDir("/proc/");
    GetAllProcsInfo(&procInfo, &procs, 0);

    model->setHorizontalHeaderItem(0, new QStandardItem(QString("PID")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Command")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Memory Usage (KB)")));

    Sysmon::Temp(model,procs);


    connect(ui->aboutButton   , SIGNAL(released()), this, SLOT(aboutButtonHandler()));
    connect(ui->monitorButton , SIGNAL(released()), this, SLOT(monitorButtonHandler()));
    //connect(ui->refreshButton , SIGNAL(released()), this, SLOT(refreshButtonHandler()));


    /*
    QStandardItem *currentPID, *pidCommand, *pidMemUsage;


    QString myString = "";

    int row = 0;


    for (pid_t pid : procs){
        get_proc_info(pid, &procInfo);

        myString = QString::number(procInfo.pid);
        currentPID = new QStandardItem(myString);
        pidCommand = new QStandardItem(procInfo.exName);
        pidMemUsage = new QStandardItem(QString::number(procInfo.vsize));

        QStandardItem *myData[] = {currentPID, pidCommand, pidMemUsage};

        PopulateTable(model,myData, row++);

    }*/

    ui->tableView->setModel(model);


}

void Sysmon::aboutButtonHandler(){

    QMessageBox::information(
        this,
        tr("About"),
        tr("System Monitor by\nMohamad Yassine & Tamara Alhajj\nAlso this is the earf"));

}

void Sysmon::monitorButtonHandler(){
    QMessageBox msgBox;
    msgBox.setText("The proccess monitoring system has started. To turn it off press 'Monitor' once more");
    msgBox.exec();
}

void Sysmon::refreshButtonHandler(){
    procs = listDir("/proc/");
    GetAllProcsInfo(&procInfo, &procs, 0);
    Sysmon::Temp(model,procs);
    ui->tableView->setModel(model);
}

Sysmon::~Sysmon()
{
    delete ui;
}
