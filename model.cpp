#include "model.h"
#include <QObject>
#include <QDebug>

DataModel::DataModel(QObject *parent): QAbstractListModel(parent)
{
    m_data.append(Data("element 1", "content 1", "something", "anything", "row 1", "parameter 1", "1"));
    m_data.append(Data("element 2", "content 6", "something", "anything", "row 2", "parameter 2", "2"));
    m_data.append(Data("element 3", "content 3", "something", "anything", "row 3", "parameter 3", "3"));
    m_data.append(Data("element 4", "content 4", "something", "anything", "row 4", "parameter 4", "4"));
    m_data.append(Data("element 5", "content 5", "something", "anything", "row 5", "parameter 5", "5"));
    m_data.append(Data("element 6", "content 6", "something", "anything", "row 6", "parameter 6", "6"));
    m_data.append(Data("element 7", "content 7", "something", "anything", "row 7", "parameter 7", "7"));
    m_data.append(Data("element 8", "content 8", "something", "anything", "row 8", "parameter 8", "8"));
    m_data.append(Data("element 9", "content 9", "something", "anything", "row 9", "parameter 9", "9"));
    m_data.append(Data("element 10", "content 10", "something", "anything", "row 10", "parameter 10", "10"));
    m_data.append(Data("element 11", "content 11", "something", "anything", "row 11", "parameter 11", "11"));
    m_data.append(Data("element 12", "content 12", "something", "anything", "row 12", "parameter 12", "12"));
    m_data.append(Data("element 13", "content 13", "something", "anything", "row 13", "parameter 13", "13"));
    m_data.append(Data("element 14", "content 14", "something", "anything", "row 14", "parameter 14", "14"));
    m_data.append(Data("element 15", "content 15", "something", "anything", "row 15", "parameter 15", "15"));
    m_data.append(Data("element 16", "content 16", "something", "anything", "row 16", "parameter 16", "16"));
    m_data.append(Data("element 17", "content 17", "something", "anything", "row 17", "parameter 17", "17"));
    m_data.append(Data("element 18", "content 18", "something", "anything", "row 18", "parameter 18", "18"));
    m_data.append(Data("element 19", "content 19", "something", "anything", "row 19", "parameter 19", "19"));
    m_data.append(Data("element 20", "content 20", "something", "anything", "row 20", "parameter 20", "20"));
    m_data.append(Data("element 21", "content 21", "something", "anything", "row 21", "parameter 21", "21"));
    m_data.append(Data("element 22", "content 22", "something", "anything", "row 22", "parameter 22", "22"));
    m_data.append(Data("element 23", "content 23", "something", "anything", "row 23", "parameter 23", "23"));
    m_data.append(Data("element 24", "content 24", "something", "anything", "row 24", "parameter 24", "24"));
    m_data.append(Data("element 25", "content 25", "something", "anything", "row 25", "parameter 25", "25"));
    m_data.append(Data("element 26", "content 26", "something", "anything", "row 26", "parameter 26", "26"));
    m_data.append(Data("element 27", "content 27", "something", "anything", "row 27", "parameter 27", "27"));
    m_data.append(Data("element 28", "content 28", "something", "anything", "row 28", "parameter 28", "28"));
    m_data.append(Data("element 29", "content 29", "something", "anything", "row 29", "parameter 29", "29"));
    m_data.append(Data("element 30", "content 30", "something", "anything", "row 30", "parameter 30", "30"));
    m_data.append(Data("element 30", "content 30", "something", "anything", "row 30", "parameter 30", "30"));
}

int DataModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }

    return m_data.length();
}

QVariant DataModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return  QVariant();

    switch (role) {
    case dataTime:
        return m_data[index.row()].m_dataTime;
    case dataKA:
        return m_data[index.row()].m_dataKA;
    case dataOKIK:
        return m_data[index.row()].m_dataOKIK;
    case dataResourses:
        return m_data[index.row()].m_dataResourses;
    case dataTurn:
        return m_data[index.row()].m_dataTurn;
    case dataNotification:
        return m_data[index.row()].m_dataNotification;
    case keyRole:
        return m_data[index.row()].m_keyRole;
    }
    return  QVariant();
}

QHash<int, QByteArray> DataModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[dataTime] = "dataTime";
    roles[dataKA] = "dataKA";
    roles[dataOKIK] = "dataOKIK";
    roles[dataResourses] = "dataResourses";
    roles[dataTurn] = "dataTurn";
    roles[dataNotification] = "dataNotification";
    roles[keyRole] = "keyRole";

    return roles;
}

void DataModel::clear()
{
    beginResetModel();
    m_data.clear();
    setCount(m_data.count());
    endResetModel();
}

void DataModel::remove(int index)
{
    beginResetModel();
    m_data.removeAt(index);
    setCount(m_data.count());
    endResetModel();
}

void DataModel::append(const QString &time
                       , const QString &KA
                       , const QString &OKIK
                       , const QString &resources
                       , const QString &turn
                       , const QString &notification
                       , const QString &keyRole)
{
    beginResetModel();
    m_data.append(Data(time, KA, OKIK, resources, turn, notification, keyRole));
    clearOldRows();
    //setCount(m_data.count());
    endResetModel();
}

void DataModel::setCount(int count)
{
    if (m_count == count)
        return;

    m_count = count;
    emit countChanged(m_count);
}

QString DataModel::getCurrentKeyRole() const
{
    return m_currentKeyRole;
}

void DataModel::setCurrentKeyRole(const QString &value)
{
    m_currentKeyRole = value;
}

int DataModel::getMaxRowCount() const
{
    return m_maxRowCount;
}

void DataModel::setMaxRowCount(int maxRowCount)
{
    if (m_maxRowCount == maxRowCount)
        return;

    m_maxRowCount = maxRowCount;
    emit maxRowCountChanged(m_maxRowCount);
}

void DataModel::clearOldRows()
{
    beginResetModel();

    while(m_data.count() > m_maxRowCount)
        m_data.removeFirst();

    setCount(m_data.count());
    endResetModel();
}

int DataModel::count() const
{
    return m_count;
}

void DataModel::extractLastReserveItem()
{
    beginResetModel();

    if (!m_reserveData.isEmpty()) {
        m_data.append(m_reserveData.last());
        m_reserveData.removeLast();
    }

    endResetModel();
}

void DataModel::extractAllReserve()
{
    beginResetModel();

    for (auto element: m_reserveData) {
        m_data.append(element);
    }
    m_reserveData.clear();
    endResetModel();
}

void DataModel::reserve(int index)
{
    m_reserveData.append(m_data.at(index));
    remove(index);
    QVariantList currentKeyRole;
    currentKeyRole << QVariant::fromValue(m_currentKeyRole);
    emit sendNotification("notice_message_delete_row", currentKeyRole);
}
