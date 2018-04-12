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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "QRoundProgressBar.h"

QT_BEGIN_NAMESPACE

class Ui_Sysmon
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *refreshButton;
    QPushButton *aboutButton;
    QPushButton *monitorButton;
    QFrame *line;
    QTableView *tableView;
    QToolButton *toolButton;
    QWidget *tab_2;
    QPushButton *PowersaveButton;
    QPushButton *PerformanceButton;
    QRoundProgressBar *RoundBar1;
    QRoundProgressBar *RoundBar2;
    QRoundProgressBar *RoundBar3;
    QRoundProgressBar *MemoryUsageBar;
    QRoundProgressBar *CPUUsageBar;
    QGroupBox *groupBox;
    QLabel *distro;
    QLabel *cpu;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *platform;
    QLabel *kernel;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *hostname;
    QLabel *storage;
    QLabel *memory;
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
        tabWidget->setTabPosition(QTabWidget::North);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        refreshButton = new QPushButton(tab);
        refreshButton->setObjectName(QStringLiteral("refreshButton"));
        refreshButton->setGeometry(QRect(599, 440, 81, 41));
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
        tableView->setGeometry(QRect(0, 20, 800, 391));
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
        tableView->horizontalHeader()->setDefaultSectionSize(155);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->horizontalHeader()->setMinimumSectionSize(140);
        tableView->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableView->horizontalHeader()->setStretchLastSection(false);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setCascadingSectionResizes(false);
        tableView->verticalHeader()->setDefaultSectionSize(30);
        tableView->verticalHeader()->setMinimumSectionSize(30);
        toolButton = new QToolButton(tab);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(770, 0, 21, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        PowersaveButton = new QPushButton(tab_2);
        PowersaveButton->setObjectName(QStringLiteral("PowersaveButton"));
        PowersaveButton->setGeometry(QRect(29, 210, 241, 40));
        PerformanceButton = new QPushButton(tab_2);
        PerformanceButton->setObjectName(QStringLiteral("PerformanceButton"));
        PerformanceButton->setGeometry(QRect(29, 160, 241, 40));
        RoundBar1 = new QRoundProgressBar(tab_2);
        RoundBar1->setObjectName(QStringLiteral("RoundBar1"));
        RoundBar1->setGeometry(QRect(580, 290, 181, 181));
        RoundBar2 = new QRoundProgressBar(tab_2);
        RoundBar2->setObjectName(QStringLiteral("RoundBar2"));
        RoundBar2->setGeometry(QRect(290, 30, 231, 221));
        RoundBar3 = new QRoundProgressBar(tab_2);
        RoundBar3->setObjectName(QStringLiteral("RoundBar3"));
        RoundBar3->setGeometry(QRect(540, 30, 231, 221));
        MemoryUsageBar = new QRoundProgressBar(tab_2);
        MemoryUsageBar->setObjectName(QStringLiteral("MemoryUsageBar"));
        MemoryUsageBar->setGeometry(QRect(160, 30, 111, 111));
        CPUUsageBar = new QRoundProgressBar(tab_2);
        CPUUsageBar->setObjectName(QStringLiteral("CPUUsageBar"));
        CPUUsageBar->setGeometry(QRect(30, 30, 111, 111));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 270, 531, 201));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        groupBox->setFont(font1);
        distro = new QLabel(groupBox);
        distro->setObjectName(QStringLiteral("distro"));
        distro->setGeometry(QRect(100, 70, 171, 16));
        cpu = new QLabel(groupBox);
        cpu->setObjectName(QStringLiteral("cpu"));
        cpu->setGeometry(QRect(100, 109, 301, 16));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 107, 81, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 47, 81, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 27, 71, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 87, 81, 20));
        platform = new QLabel(groupBox);
        platform->setObjectName(QStringLiteral("platform"));
        platform->setGeometry(QRect(100, 49, 171, 16));
        kernel = new QLabel(groupBox);
        kernel->setObjectName(QStringLiteral("kernel"));
        kernel->setGeometry(QRect(100, 89, 171, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 67, 81, 20));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 127, 81, 20));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 147, 81, 20));
        hostname = new QLabel(groupBox);
        hostname->setObjectName(QStringLiteral("hostname"));
        hostname->setGeometry(QRect(100, 27, 171, 16));
        storage = new QLabel(groupBox);
        storage->setObjectName(QStringLiteral("storage"));
        storage->setGeometry(QRect(100, 149, 171, 16));
        memory = new QLabel(groupBox);
        memory->setObjectName(QStringLiteral("memory"));
        memory->setGeometry(QRect(100, 129, 171, 16));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 141, 16));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        tabWidget->addTab(tab_2, QString());

        retranslateUi(Sysmon);

        tabWidget->setCurrentIndex(1);
        aboutButton->setDefault(false);
        monitorButton->setDefault(false);


        QMetaObject::connectSlotsByName(Sysmon);
    } // setupUi

    void retranslateUi(QWidget *Sysmon)
    {
        Sysmon->setWindowTitle(QApplication::translate("Sysmon", "Sysmon", 0));
        refreshButton->setText(QApplication::translate("Sysmon", "Refresh", 0));
        aboutButton->setText(QApplication::translate("Sysmon", "About", 0));
        monitorButton->setText(QApplication::translate("Sysmon", "Monitor", 0));
        toolButton->setText(QApplication::translate("Sysmon", "...", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Sysmon", "Processess", 0));
        PowersaveButton->setText(QApplication::translate("Sysmon", "Powersaver Mode", 0));
        PerformanceButton->setText(QApplication::translate("Sysmon", "Performance Mode", 0));
        groupBox->setTitle(QString());
        distro->setText(QApplication::translate("Sysmon", "distro", 0));
        cpu->setText(QApplication::translate("Sysmon", "cpu", 0));
        label_6->setText(QApplication::translate("Sysmon", "CPU Model:", 0));
        label_3->setText(QApplication::translate("Sysmon", "Platform:", 0));
        label_2->setText(QApplication::translate("Sysmon", "Hostname:", 0));
        label_5->setText(QApplication::translate("Sysmon", "Kernel:", 0));
        platform->setText(QApplication::translate("Sysmon", "platform", 0));
        kernel->setText(QApplication::translate("Sysmon", "kernel", 0));
        label_4->setText(QApplication::translate("Sysmon", "Distrobution:", 0));
        label_7->setText(QApplication::translate("Sysmon", "Memory:", 0));
        label_8->setText(QApplication::translate("Sysmon", "Storage:", 0));
        hostname->setText(QApplication::translate("Sysmon", "localhost", 0));
        storage->setText(QApplication::translate("Sysmon", "storage", 0));
        memory->setText(QApplication::translate("Sysmon", "memory", 0));
        label->setText(QApplication::translate("Sysmon", "System Information", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Sysmon", "Hardware Info", 0));
    } // retranslateUi

};

namespace Ui {
    class Sysmon: public Ui_Sysmon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSMON_H
