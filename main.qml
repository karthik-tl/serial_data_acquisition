import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("ui_test1")
    Rectangle {
        anchors.fill: parent

        // Text box to display values
        Text {
            x:0
            y: 22
            id: port
            text: "Ports"
        }
        ComboBox {
            x:50
            y:20
            id: comboBox
            width: 150
            model: SerialCommunication.availablePorts()
            onCurrentTextChanged: {
                // Call a C++ function to handle the selection
                 SerialAquisition.handleComboBoxSelection(currentText)
            }
        }
        Button{
            x: 210
            y:20
            id: connect
            text: "Connect"
            onClicked: {
                // Call the C++ function to display a message in the console
               SerialAquisition.connectPort()
            }
        }
    }
}
