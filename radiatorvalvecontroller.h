#ifndef RADIATORVALVECONTROLLER_H
#define RADIATORVALVECONTROLLER_H

#include <QObject>

class RadiatorValveController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double expectedTemperature READ expectedTemperature NOTIFY expectedTemperatureChanged)
    Q_PROPERTY(double sliderValue READ sliderValue WRITE setSliderValue NOTIFY sliderValueChanged)

public:
    explicit RadiatorValveController(QObject *parent = nullptr);

    double expectedTemperature() const;
    double sliderValue() const;
    void setSliderValue(double value);

public slots:
    void adjustExpectedTemperature(double newTemperature);

signals:
    void expectedTemperatureChanged();
    void sliderValueChanged();

private:
    double m_expectedTemperature;
    double m_sliderValue;
};

#endif
