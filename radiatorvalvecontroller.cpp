#include "RadiatorValveController.h"
#include <QDebug>

RadiatorValveController::RadiatorValveController(QObject *parent)
    : QObject(parent), m_expectedTemperature(20.0), m_sliderValue(0.0)
{
}

double RadiatorValveController::expectedTemperature() const
{
    return m_expectedTemperature;
}

double RadiatorValveController::sliderValue() const
{
    return m_sliderValue;
}

void RadiatorValveController::setSliderValue(double value)
{
    if (qFuzzyCompare(m_sliderValue, value))
        return;

    m_sliderValue = value;
    emit sliderValueChanged();
}

void RadiatorValveController::adjustExpectedTemperature(double newTemperature)
{
    if (qFuzzyCompare(m_expectedTemperature, newTemperature))
        return;

    m_expectedTemperature = newTemperature;
    qDebug() << "Adjusted Expected Temperature:" << m_expectedTemperature;

    emit expectedTemperatureChanged();
}

