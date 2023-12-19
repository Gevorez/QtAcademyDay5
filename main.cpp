#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "VirtualTemperature.h"
#include "RadiatorValveController.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<VirtualTemperature>("TemperatureSimulator", 1, 0, "VirtualTemperature");
    qmlRegisterType<RadiatorValveController>("TemperatureSimulator", 1, 0, "RadiatorValveController");

    VirtualTemperature virtualTemperature;
    RadiatorValveController radiatorValveController;

    engine.rootContext()->setContextProperty("virtualTemperature", &virtualTemperature);
    engine.rootContext()->setContextProperty("radiatorValveController", &radiatorValveController);

    engine.rootContext()->setContextProperty("sliderValue", 0.0);

    engine.load(QUrl(QStringLiteral("/Users/kmr/QtAcademyCourse/Day5App/Main.qml")));

    if (engine.rootObjects().isEmpty()) {
        qWarning() << "Failed to load QML file.";
        return -1;
    }

    return app.exec();
}


