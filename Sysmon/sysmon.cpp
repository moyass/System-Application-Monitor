#include "sysmon.h"
#include "ui_sysmon.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>
#include <QStandardItemModel>


void PopulateTable(QStandardItemModel *inputModel,QStandardItem *data[], int row){
    inputModel->setItem(row,0,data[0]);
    inputModel->setItem(row,1,data[1]);
    inputModel->setItem(row,2,data[2]);
}

Sysmon::Sysmon(QWidget *parent) :QWidget(parent), ui(new Ui::Sysmon)
{

    ui->setupUi(this);


    QStandardItemModel *model = new QStandardItemModel(2,3,this);


    model->setHorizontalHeaderItem(0, new QStandardItem(QString("PID")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Command")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Memory Usage (KB)")));



    QStandardItem *pid = new QStandardItem(QString("0"));
    QStandardItem *pidCommand = new QStandardItem(QString("Dis is da earf"));
    QStandardItem *pidMemUsage = new QStandardItem(QString("9000"));

    QStandardItem *myData[] = {pid, pidCommand, pidMemUsage};

    //             col col string
    //model->setItem(0,0,pid);
    //model->setItem(0,1,pidCommand);
    //model->setItem(0,2,pidMemUsage);


    PopulateTable(model,myData, 0);
    PopulateTable(model,myData, 1);

    ui->tableView->setModel(model);

}

Sysmon::~Sysmon()
{
    delete ui;
}
