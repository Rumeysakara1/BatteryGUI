#include "batterywidget.h"
#include <QPainter>

BatteryWidget::BatteryWidget(QWidget *parent) : QWidget(parent)
{
}

void BatteryWidget::setBatteries(const QVector<BatteryData>& batteries)
{
    m_batteries = batteries;
    update();
}

void BatteryWidget::setSeries(bool isSeries)
{
    m_series = isSeries;
    update();
}

void BatteryWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int w = width();
    int h = height();
    int batteryWidth = m_series ? w - 20 : (w - 20) / (m_batteries.size() ? m_batteries.size() : 1);
    int batteryHeight = m_series ? (h - 20) / (m_batteries.size() ? m_batteries.size() : 1) : h - 20;

    for (int i = 0; i < m_batteries.size(); ++i) {
        int x = m_series ? 10 : 10 + i * batteryWidth;
        int y = m_series ? 10 + i * batteryHeight : 10;
        QRect rect(x, y, batteryWidth - 5, batteryHeight - 5);
        painter.setBrush(Qt::gray);
        painter.drawRect(rect);

        double fillRatio = m_batteries[i].charge / m_batteries[i].capacity;
        QRect fillRect = rect;
        if (m_series) fillRect.setHeight(rect.height() * fillRatio);
        else fillRect.setWidth(rect.width() * fillRatio);
        painter.setBrush(Qt::green);
        painter.drawRect(fillRect);
    }
}
