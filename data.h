#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QDateTime>

struct Data {
    Data(QString dataTime,
         QString dataKA,
         QString dataOKIK,
         QString dataResourses,
         QString dataTurn,
         QString dataNotification,
         QString keyRole) {
        m_dataTime = dataTime;
        m_dataKA = dataKA;
        m_dataOKIK = dataOKIK;
        m_dataResourses = dataResourses;
        m_dataTurn = dataTurn;
        m_dataNotification = dataNotification;
        m_keyRole = keyRole;
    }

    QString m_dataTime;
    QString m_dataKA;
    QString m_dataOKIK;
    QString m_dataResourses;
    QString m_dataTurn;
    QString m_dataNotification;
    QString m_keyRole;
};

#endif // DATA_H



