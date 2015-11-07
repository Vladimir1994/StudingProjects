import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {
    visible: true
    width: 640
    height: 360
    property double widthScale: width / 640
    property double heightScale: height / 360

    title: qsTr("FSManager")
    color: "Lightslategray"

    TextArea {
        id: command_history
        x: 20 * widthScale
        y: 30 * heightScale
        z: 1
        width: 600 * widthScale
        height: 230 * heightScale
        backgroundVisible: false
        textColor: "Darkslategray"

        readOnly: true
        font.pixelSize: 20
    }

    Rectangle {
        color: "Gainsboro"
        anchors.fill: command_history
    }

    Text {
        x: 20 * widthScale
        y: 5 * heightScale

        text: "Command History:"
        color: "Ivory"
        font.pixelSize: 15 * heightScale
    }

    Text {
        x: 20 * widthScale
        y: 275 * heightScale

        text: "Command:"
        color: "Ivory"
        font.pixelSize: 15 * heightScale
    }

    Rectangle {
        id: command_window
        x: 20 * widthScale
        y: 300 * heightScale
        width: 600 * widthScale
        height: 55 * heightScale
        color: "Gainsboro"
        clip: true

        TextInput {
            id: command_line
            x: 10 * widthScale
            y: 15 * heightScale
            width: 590 * widthScale
            height: 55 * heightScale

            clip: true

            autoScroll : true
            cursorVisible : true

            font.pixelSize: 20//*heightScale
            color: "Darkslategray"

            onAccepted: {
                if(text != "") {
                    if(command_history.text === "")
                        command_history.text = command_history.text + "Command: " + text
                    else
                        command_history.text = command_history.text + "\n" + "Command: " + text

                    command_history.text =command_history.text + "\n" + "Echo: " + CommandManager.receive(text) + "\n";
                    text = ""
                }
            }
        }
    }

}
