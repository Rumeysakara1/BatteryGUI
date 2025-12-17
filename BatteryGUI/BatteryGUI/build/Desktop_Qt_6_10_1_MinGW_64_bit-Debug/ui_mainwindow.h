/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <batterywidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    BatteryWidget *batteryWidget;
    QTextEdit *textEditDisplay;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineCapacity;
    QLineEdit *lineVoltage;
    QPushButton *btnAddBattery;
    QLabel *label_2;
    QComboBox *comboPackType;
    QPushButton *btnCreatePack;
    QPushButton *btnUsePack;
    QPushButton *btnRechargePack;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 70, 481, 481));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(horizontalLayoutWidget);
        widget->setObjectName("widget");
        batteryWidget = new BatteryWidget(widget);
        batteryWidget->setObjectName("batteryWidget");
        batteryWidget->setGeometry(QRect(260, 50, 211, 321));
        textEditDisplay = new QTextEdit(widget);
        textEditDisplay->setObjectName("textEditDisplay");
        textEditDisplay->setGeometry(QRect(10, 390, 201, 101));
        verticalLayoutWidget = new QWidget(widget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 50, 251, 331));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineCapacity = new QLineEdit(verticalLayoutWidget);
        lineCapacity->setObjectName("lineCapacity");

        verticalLayout->addWidget(lineCapacity);

        lineVoltage = new QLineEdit(verticalLayoutWidget);
        lineVoltage->setObjectName("lineVoltage");

        verticalLayout->addWidget(lineVoltage);

        btnAddBattery = new QPushButton(verticalLayoutWidget);
        btnAddBattery->setObjectName("btnAddBattery");

        verticalLayout->addWidget(btnAddBattery);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        comboPackType = new QComboBox(verticalLayoutWidget);
        comboPackType->addItem(QString());
        comboPackType->addItem(QString());
        comboPackType->setObjectName("comboPackType");

        verticalLayout->addWidget(comboPackType);

        btnCreatePack = new QPushButton(verticalLayoutWidget);
        btnCreatePack->setObjectName("btnCreatePack");

        verticalLayout->addWidget(btnCreatePack);

        btnUsePack = new QPushButton(verticalLayoutWidget);
        btnUsePack->setObjectName("btnUsePack");

        verticalLayout->addWidget(btnUsePack);

        btnRechargePack = new QPushButton(verticalLayoutWidget);
        btnRechargePack->setObjectName("btnRechargePack");

        verticalLayout->addWidget(btnRechargePack);


        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Add Battery", nullptr));
        lineCapacity->setText(QString());
        lineCapacity->setPlaceholderText(QCoreApplication::translate("MainWindow", "Capacity (mAh)", nullptr));
        lineVoltage->setText(QString());
        lineVoltage->setPlaceholderText(QCoreApplication::translate("MainWindow", "Voltage (V)", nullptr));
        btnAddBattery->setText(QCoreApplication::translate("MainWindow", "Add Battery", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Create Pack", nullptr));
        comboPackType->setItemText(0, QCoreApplication::translate("MainWindow", "SERIES", nullptr));
        comboPackType->setItemText(1, QCoreApplication::translate("MainWindow", "PARALLEL", nullptr));

        btnCreatePack->setText(QCoreApplication::translate("MainWindow", "Create Pack", nullptr));
        btnUsePack->setText(QCoreApplication::translate("MainWindow", "Use Battery", nullptr));
        btnRechargePack->setText(QCoreApplication::translate("MainWindow", "Recharge Battery", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
