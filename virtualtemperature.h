#ifndef VIRTUALTEMPERATURE_H
#define VIRTUALTEMPERATURE_H

#include <QObject>
#include <QTimer>
#include <QRandomGenerator>

class VirtualTemperature : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double temperature READ temperature NOTIFY temperatureChanged)
    Q_PROPERTY(double expectedTemperature READ expectedTemperature WRITE setExpectedTemperature NOTIFY expectedTemperatureChanged)

public:
    explicit VirtualTemperature(QObject *parent = nullptr);

    double temperature() const;
    double expectedTemperature() const;
    void setExpectedTemperature(double temperature);

public slots:
    void simulateTemperatureChange();

signals:
    void temperatureChanged();
    void expectedTemperatureChanged();

private:
    double m_temperature;
    double m_expectedTemperature;
    QTimer m_timer;
    QRandomGenerator m_randomGenerator;
};

#endif
