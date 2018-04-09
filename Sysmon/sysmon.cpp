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
    int row = 0, index = 0;
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



        // TODO: Fix up algorithm of storing the information
        // TODO: If a process is closed, remove it from the vector

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
        for (Process d: procDB){
            if(d.getPID() == procInfo.pid){
                d.insert(RSS, procInfo.rss);
                d.insert(VM, procInfo.vsize);
                FOUND = true;
                break;
            } else {
                FOUND = false;
            }
        }

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

    for (Process s : procDB){
       // if (s.getName().compare("Sysmon") == 0){
                cout << endl << s.getName() << endl;
                s.printOutValues(RSS);
       // }
    }

    Process temp;
    cout << endl;
    cout << "Size of DB (bytes): " << sizeof(temp) << endl;
    cout << "Size of DB: " << procDB.size() * sizeof(Process) << endl;

}

Sysmon::~Sysmon()
{
    delete ui;
}
