#ifndef SYSMON_H
#define SYSMON_H

#include <QWidget>
#include <QPushButton>
#include <QTableWidget>

namespace Ui {
class Sysmon;
}

class Sysmon : public QWidget
{
    Q_OBJECT

public:
    explicit Sysmon(QWidget *parent = 0);
    ~Sysmon();

private:
    Ui::Sysmon *ui;
    QPushButton *monitorButton;
    QPushButton *aboutButton;

    QTableWidget* m_pTableWidget;

    QStringList m_TableHeader;

    void cellSelected(int nRow, int nCol);
};

#endif // SYSMON_H
