#include "sysmon.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sysmon w;

    w.show();

    return a.exec();
}
