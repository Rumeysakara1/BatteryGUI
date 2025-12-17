#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnAddBattery, &QPushButton::clicked, this, &MainWindow::addBattery);
    connect(ui->btnCreatePack, &QPushButton::clicked, this, &MainWindow::createPack);
    connect(ui->btnUsePack, &QPushButton::clicked, this, &MainWindow::usePack);
    connect(ui->btnRechargePack, &QPushButton::clicked, this, &MainWindow::rechargePack);
}

// Destructor
MainWindow::~MainWindow()
{
    for(auto b: temporaryBatteries) delete b;
    for(auto p: packs) delete p;
    delete ui;
}

QVector<BatteryData> MainWindow::getBatteryDataForWidget() const
{
    QVector<BatteryData> data;
    if (!packs.isEmpty()) {
        const std::vector<Battery*>& cells = packs[0]->getCells();
        for (Battery* cell : cells) {
            BatteryData bd;
            bd.voltage = cell->getVoltage();
            bd.capacity = cell->getCapacity();
            bd.charge = cell->getCharge();
            data.append(bd);
        }
    } else {
        for (Battery* temp : temporaryBatteries) {
            BatteryData bd;
            bd.voltage = temp->getVoltage();
            bd.capacity = temp->getCapacity();
            bd.charge = temp->getCharge();
            data.append(bd);
        }
    }
    return data;
}

void MainWindow::addBattery()
{

    double voltage = ui->lineVoltage->text().toDouble();
    double capacity = ui->lineCapacity->text().toDouble();

    if (voltage <= 0 || capacity <= 0) {
        QMessageBox::warning(this, "Error", "Voltage and capacitance must be positive.");
        return;
    }

    Battery* b = new Battery(voltage, capacity, capacity);
    temporaryBatteries.append(b);

    ui->batteryWidget->setBatteries(getBatteryDataForWidget());
    ui->batteryWidget->update();

    QMessageBox::information(this, "Added.",
                             QString("Battery added. Total Battery: %1")
                                 .arg(temporaryBatteries.size()));
}

void MainWindow::createPack()
{
    if(temporaryBatteries.isEmpty()){
        QMessageBox::warning(this, "Error", "Please add the battery first.");
        return;
    }

    QString typeStr = ui->comboPackType->currentText();

    BatteryPack::ConnectionType type;
    if(typeStr == "SERIES") {
        type = BatteryPack::SERIES;
        ui->batteryWidget->setSeries(true);
    }
    else if(typeStr == "PARALLEL") {
        type = BatteryPack::PARALLEL;
        ui->batteryWidget->setSeries(false);
    } else {
        QMessageBox::critical(this, "Error", "An invalid connection type was selected.");
        return;
    }

    BatteryPack* pack = new BatteryPack(type);

    for(auto b: temporaryBatteries) {
        pack->add(b);
    }

    packs.append(pack);
    temporaryBatteries.clear();

    ui->batteryWidget->setBatteries(getBatteryDataForWidget());
    ui->batteryWidget->update();
    updateDisplay();
}

void MainWindow::usePack()
{
    if(packs.isEmpty()){
        QMessageBox::warning(this, "Error", "First, create a package.");
        return;
    }

    double hours = 1.0;

    packs[0]->use(hours);

    ui->batteryWidget->setBatteries(getBatteryDataForWidget());
    ui->batteryWidget->update();
    updateDisplay();
}

void MainWindow::rechargePack()
{
    if(packs.isEmpty()){
        QMessageBox::warning(this, "Error", "First, create a package..");
        return;
    }

    double hours = 1.0;

    packs[0]->recharge(hours);

    ui->batteryWidget->setBatteries(getBatteryDataForWidget());
    ui->batteryWidget->update();
    updateDisplay();
}

void MainWindow::updateDisplay()
{
    QString text;
    for(int i = 0; i < packs.size(); ++i){

        text += QString("--- PACK #%1 (%2) ---\n")
                    .arg(i+1)
                    .arg(packs[i]->isSeries() ? "SERIES" : "PARALEL");

        text += QString("   Total Voltage = %1 V\n").arg(packs[i]->getVoltage(), 0, 'f', 2);
        text += QString("   Total Capacity = %1 mAh\n").arg(packs[i]->getCapacity(), 0, 'f', 0);
        text += QString("   Current Charge = %1 mAh (%2%)\n")
                    .arg(packs[i]->getCharge(), 0, 'f', 0)
                    .arg(packs[i]->getCharge() * 100.0 / packs[i]->getCapacity(), 0, 'f', 1);
        text += "\n";
    }

    ui->textEditDisplay->setText(text);
}
