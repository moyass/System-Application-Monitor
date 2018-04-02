/********************************************************************************
** Form generated from reading UI file 'sysmon.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSMON_H
#define UI_SYSMON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sysmon
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *refreshButton;
    QLabel *label_3;
    QPushButton *aboutButton;
    QPushButton *monitorButton;
    QFrame *line;
    QTableView *tableView;
    QWidget *tab_2;
    QLabel *label;

    void setupUi(QWidget *Sysmon)
    {
        if (Sysmon->objectName().isEmpty())
            Sysmon->setObjectName(QStringLiteral("Sysmon"));
        Sysmon->setWindowModality(Qt::WindowModal);
        Sysmon->resize(805, 520);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Sysmon->sizePolicy().hasHeightForWidth());
        Sysmon->setSizePolicy(sizePolicy);
        Sysmon->setMinimumSize(QSize(589, 520));
        Sysmon->setMaximumSize(QSize(805, 520));
        Sysmon->setBaseSize(QSize(589, 520));
        Sysmon->setAutoFillBackground(false);
        tabWidget = new QTabWidget(Sysmon);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 805, 521));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMaximumSize(QSize(805, 521));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        refreshButton = new QPushButton(tab);
        refreshButton->setObjectName(QStringLiteral("refreshButton"));
        refreshButton->setGeometry(QRect(599, 440, 81, 41));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 460, 321, 16));
        aboutButton = new QPushButton(tab);
        aboutButton->setObjectName(QStringLiteral("aboutButton"));
        aboutButton->setGeometry(QRect(690, 440, 101, 41));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        aboutButton->setPalette(palette);
        aboutButton->setAutoDefault(false);
        aboutButton->setFlat(false);
        monitorButton = new QPushButton(tab);
        monitorButton->setObjectName(QStringLiteral("monitorButton"));
        monitorButton->setGeometry(QRect(10, 440, 101, 41));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        monitorButton->setPalette(palette1);
        monitorButton->setAutoDefault(false);
        monitorButton->setFlat(false);
        line = new QFrame(tab);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(240, 410, 118, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        tableView = new QTableView(tab);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setEnabled(true);
        tableView->setGeometry(QRect(10, 20, 781, 391));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy2);
        tableView->setMinimumSize(QSize(800, 391));
        tableView->setMaximumSize(QSize(16777215, 391));
        tableView->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setFamily(QStringLiteral("Sans Serif"));
        font.setPointSize(10);
        tableView->setFont(font);
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setGridStyle(Qt::DashLine);
        tableView->setSortingEnabled(false);
        tableView->setWordWrap(false);
        tableView->horizontalHeader()->setCascadingSectionResizes(true);
        tableView->horizontalHeader()->setDefaultSectionSize(130);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->horizontalHeader()->setMinimumSectionSize(70);
        tableView->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableView->horizontalHeader()->setStretchLastSection(false);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setCascadingSectionResizes(false);
        tableView->verticalHeader()->setDefaultSectionSize(30);
        tableView->verticalHeader()->setMinimumSectionSize(30);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 151, 16));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(Sysmon);

        tabWidget->setCurrentIndex(0);
        aboutButton->setDefault(false);
        monitorButton->setDefault(false);


        QMetaObject::connectSlotsByName(Sysmon);
    } // setupUi

    void retranslateUi(QWidget *Sysmon)
    {
        Sysmon->setWindowTitle(QApplication::translate("Sysmon", "Sysmon", 0));
        refreshButton->setText(QApplication::translate("Sysmon", "Refresh", 0));
        label_3->setText(QApplication::translate("Sysmon", "Currently No Process Seems to have a memory leak", 0));
        aboutButton->setText(QApplication::translate("Sysmon", "About", 0));
        monitorButton->setText(QApplication::translate("Sysmon", "Monitor", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Sysmon", "Processess", 0));
        label->setText(QApplication::translate("Sysmon", "Temperature and Shit", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Sysmon", "Hardware Info", 0));
    } // retranslateUi

};

namespace Ui {
    class Sysmon: public Ui_Sysmon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSMON_H
