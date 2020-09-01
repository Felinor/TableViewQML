import QtQuick 2.0

Item {
    clip: true

    Text {
        anchors.fill: parent
        anchors.verticalCenter: parent.verticalCenter
        verticalAlignment: Text.AlignVCenter
        renderType: Text.NativeRendering
        text: styleData.value
        color: "white"
        font { pointSize: 16; family: "Avenir Heavy"; wordSpacing: 1 }
    }
}

