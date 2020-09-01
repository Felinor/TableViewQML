import QtQuick 2.0
import QtQuick.Controls 2.0

ItemDelegate  {
    id: control
    height: textHeader.implicitHeight * 1.5
    clip: true

    background: Rectangle {
        id: backgroundRect
        gradient: styleData.containsMouse ? gradientCurrentRow : gradientNormal

        Gradient {
            id: gradientNormal
            GradientStop { position: 0; color: "#A7ADB4" }
            GradientStop { position: 0.5; color: "#9199A1" }
        }
        Gradient {
            id: gradientCurrentRow
            GradientStop { position: 0; color: "#56789D" }
            GradientStop { position: 0.5; color: "#45607E" }
        }        
    }

    contentItem: Text {
        id: textHeader
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        text: styleData.value
        color: "white"
        renderType: Text.NativeRendering
        font {
            family : "Avenir Heavy"
            letterSpacing: 1
            preferShaping: false
            weight: Font.Medium
            pointSize: 17
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        onEntered: control.hovered ? cursorShape = Qt.PointingHandCursor : cursorShape = Qt.PointingHandCursor
        //pressAndHoldInterval: 100
        onPressAndHold: control.pressed ? cursorShape = Qt.ClosedHandCursor : cursorShape = Qt.PointingHandCursor
        onReleased: cursorShape = Qt.OpenHandCursor
    }
}


