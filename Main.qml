import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 200
    title: "Temperature Simulator"

    Column {
        anchors.centerIn: parent
        spacing: 20

        Slider {
            id: temperatureSlider
            from: 0
            to: 30
            stepSize: 0.1
            value: sliderValue

            onValueChanged: {
                console.log("Slider Value:", temperatureSlider.value);
                if (radiatorValveController) {
                    console.log("Setting Expected Temperature:", temperatureSlider.value);
                    radiatorValveController.adjustExpectedTemperature(temperatureSlider.value);
                } else {
                    console.error("RadiatorValveController is null");
                }
            }
        }

        Text {
            text: "Virtual Temperature: " + (virtualTemperature ? virtualTemperature.temperature.toFixed(1) : "N/A") + " °C"
            font.pixelSize: 18
        }

        Text {
            text: "Expected Temperature: " + (radiatorValveController ? radiatorValveController.expectedTemperature.toFixed(1) : "N/A") + " °C"
            font.pixelSize: 18
        }

    }
}
