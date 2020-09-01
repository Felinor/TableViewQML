import QtQuick 2.0
import SortFilterProxyModel 1.0

 SortFilterProxyModel {
    id: proxyModel
    property alias proxyModel: proxyModel

    source: dataModel.count > 0 ? dataModel : null

    sortOrder: tableView.sortIndicatorOrder
    sortCaseSensitivity: Qt.CaseInsensitive
    sortRole: dataModel.count > 0 ? tableView.getColumn(tableView.sortIndicatorColumn).role : ""
}

