#include "virtualtemperature.h"
#include <QTimer>
#include <QDateTime>
#include <QRandomGenerator>

VirtualTemperature::VirtualTemperature(QObject *parent)
    : QObject(parent), m_temperature(20.0), m_expectedTemperature(20.0)
{
    connect(&m_timer, &QTimer::timeout, this, &VirtualTemperature::simulateTemperatureChange);
    m_timer.start(1000);

    m_randomGenerator.seed(static_cast<uint>(QDateTime::currentMSecsSinceEpoch()));

    m_temperature += (m_randomGenerator.generate() % 5 - 2.5);
}

double VirtualTemperature::temperature() const
{
    return m_temperature;
}

double VirtualTemperature::expectedTemperature() const
{
    return m_expectedTemperature;
}

void VirtualTemperature::setExpectedTemperature(double temperature)
{
    if (qFuzzyCompare(m_expectedTemperature, temperature))
        return;

    m_expectedTemperature = temperature;
    emit expectedTemperatureChanged();
}

void VirtualTemperature::simulateTemperatureChange()
{
    double difference = m_expectedTemperature - m_temperature;

    m_temperature += qBound(-2.5, difference, 2.5);

    qDebug() << "Simulated temperature change. Current Temperature:" << m_temperature << "Expected Temperature:" << m_expectedTemperature;

    emit temperatureChanged();
}

