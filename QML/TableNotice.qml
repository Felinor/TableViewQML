import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4

TableView {
    id: tableView

    property int heightRows: 50
    property var currentGradient

    function resizeColumns() {
        tableView.resizeColumnsToContents();
        column_6.width = tableView.contentItem.width -
                (column_1.width + column_2.width +
                 column_3.width + column_4.width + column_5.width)
    }

    clip: true
    sortIndicatorVisible: true
    model: ProxyModel {}
    onWidthChanged: resizeColumns()

    TableViewColumn {
        id: column_1
        width: tableView.contentItem.width / tableView.columnCount
        title: "First column"
        role: "dataTime"
    }
    TableViewColumn {
        id: column_2
        width: tableView.contentItem.width / tableView.columnCount
        title: "Second column"
        role: "dataKA"
    }
    TableViewColumn {
        id: column_3
        width: tableView.contentItem.width / tableView.columnCount
        title: "Third column"
        role: "dataOKIK"
    }
    TableViewColumn {
        id: column_4
        width: tableView.contentItem.width / tableView.columnCount
        title: "Fourth column"
        role: "dataResourses"
    }
    TableViewColumn {
        id: column_5
        width: tableView.contentItem.width / tableView.columnCount
        title: "Fifth column"
        role: "dataTurn"
    }
    TableViewColumn {
        id: column_6
        title: "Sixth column"
        role: "dataNotification"
    }
    TableViewColumn {
        visible: false
        role: "keyRole"
    }   

    style: TableViewStyle {
        backgroundColor: "#9199A1"

        headerDelegate: DelegateHeader {}
        rowDelegate: DelegateRow {}
        itemDelegate: DelegateItem {}
    }
}
