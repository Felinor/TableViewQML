import QtQuick 2.0
import QtQuick.Window 2.0
import DataModel 1.0

Window {
    visible: true
    width: 1200
    height: 500

    TableNotice { id: tableView; anchors.fill: parent; anchors.topMargin: 30 }
    SearchField { id: searchBox; anchors.horizontalCenter: parent.horizontalCenter; width: parent.width / 5 }
    ProxyModel { id: proxyModel }
    DataModel { id: dataModel }
}
