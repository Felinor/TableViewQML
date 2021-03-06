import QtQuick 2.0
import QtQuick.Controls 2.15

ItemDelegate {
    id: delegateRow
    height: heightRows
    clip: true
    hoverEnabled: true

    function colorNotify() {
        var key = proxyModel.get(styleData.row).dataNotification
        if (key === "parameter 1")
            return gradientAttention
        else if (key === "parameter 10")
            return gradientWarning
        else if (delegateRow.hovered)
            return gradientCurrentRow

        return gradientNormal
    }

//    function colorNotify(index) {
//        var key = proxyModel.getIndex(index)
//        if (key === 0)
//            return key
//    }

    background: Rectangle {
        id: backgroundRect
        anchors.fill: delegateRow
        clip: true
        gradient: colorNotify() //colorNotify(styleData.row) === 0 ? gradientAttention : gradientNormal

        Gradient {
            id: gradientNormal
            GradientStop { position: 0; color: "#75808A" }
            GradientStop { position: 0.5; color: "#52606D" }
        }

        Gradient {
            id: gradientCurrentRow
            GradientStop { position: 0; color: "#56789D" }
            GradientStop { position: 0.5; color: "#45607E" }
        }

        Gradient {
            id: gradientAttention
            GradientStop { position: 0.00; color: "tomato" }
            GradientStop { position: 0.5; color: "red" }
        }

        Gradient {
            id: gradientWarning
            GradientStop { position: 0.00; color: "khaki" }
            GradientStop { position: 0.5; color: "orange" }
        }
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor
        onClicked: {
                console.log("Model index " + proxyModel.getIndex(styleData.row))
                console.log("Row delegate index " + styleData.row)
                console.log(proxyModel.getIndex(styleData.row) === styleData.row)                        
        }
    }
}

