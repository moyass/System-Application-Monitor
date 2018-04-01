#ifndef SYSMON_H
#define SYSMON_H

#include <QWidget>
#include <QPushButton>
#include <QTableWidget>
#include <QStandardItemModel>
#include <main.h>

namespace Ui {
class Sysmon;
}

class Sysmon : public QWidget
{
    Q_OBJECT

public:
    explicit Sysmon(QWidget *parent = 0);
    procinfo procInfo;
    QStandardItemModel *model = new QStandardItemModel(2,3,this);
    std::vector<pid_t> procs;
    ~Sysmon();


public slots:
        void aboutButtonHandler();
        void monitorButtonHandler();
        void refreshButtonHandler();
        void Temp(QStandardItemModel *inputModel, std::vector<pid_t> procs);


private:
    Ui::Sysmon *ui;

    //void Temp(QStandardItemModel *inputModel, std::vector<pid_t> procs);
    void PopulateTable(QStandardItemModel *inputModel,QStandardItem *data[], int row);
    std::vector<pid_t> listDir(const std::string& path);

};

#endif // SYSMON_H
