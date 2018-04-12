#ifndef SYSMON_H
#define SYSMON_H

#include <QWidget>
#include <QPushButton>
#include <QTableWidget>
#include <QStandardItemModel>
#include <main.h>
#include <QPaintEvent>
#include <qobject.h>
#include <QTimer>
#include "process.h"
#include "QRoundProgressBar.h"

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
    std::vector<Process> procDB;
    unsigned int INTERVAL_SECONDS = 1000;
    bool DEBUG_MODE = false;
    void ClickOnProcess(Process input);
    ~Sysmon();


public slots:
        void aboutButtonHandler();
        void monitorButtonHandler();
        void refreshButtonHandler();
        void debugButtonHandler();
        void fetch();
        void setProgress(int val);
        void connectToSlider();
        void OnDoubleClicked ( const  QModelIndex  & index ) ;
        void Temp(QStandardItemModel *inputModel, std::vector<pid_t> procs);

protected:
        void paintEvent(QPaintEvent *);

private:
    double progress;
    Ui::Sysmon *ui;
    QTimer *timer = new QTimer(this);
    QTimer *timer_hw = new QTimer(this);
    void PopulateTable(QStandardItemModel *inputModel,QStandardItem *data[], int row);
    std::vector<pid_t> listDir(const std::string& path);


};

#endif // SYSMON_H
