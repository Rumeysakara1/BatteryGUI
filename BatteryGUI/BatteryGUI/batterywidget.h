#ifndef BATTERYWIDGET_H
#define BATTERYWIDGET_H

#include <QWidget>
#include <QVector>

struct BatteryData {
    double voltage;
    double capacity;
    double charge;
};

class BatteryWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BatteryWidget(QWidget *parent = nullptr);

    void setBatteries(const QVector<BatteryData>& batteries);
    void setSeries(bool isSeries);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QVector<BatteryData> m_batteries;
    bool m_series = true;
};

#endif // BATTERYWIDGET_H
