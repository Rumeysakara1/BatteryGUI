#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "Battery.h"
#include "BatteryPack.h"
#include "batterywidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addBattery();
    void createPack();
    void usePack();
    void rechargePack();

    void updateDisplay();

private:
    Ui::MainWindow *ui;

    QList<Battery*> temporaryBatteries;
    QList<BatteryPack*> packs;

    QVector<BatteryData> getBatteryDataForWidget() const;
};
#endif // MAINWINDOW_H
