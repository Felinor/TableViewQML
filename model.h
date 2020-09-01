#ifndef MODEL_H
#define MODEL_H

#include <QAbstractListModel>
#include "data.h"

class DataModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged) // свойство для подсчета количества элементов в основной модели
    Q_PROPERTY(QString currentKeyRole READ getCurrentKeyRole WRITE setCurrentKeyRole NOTIFY currentKeyRoleChanged) // получаем текущее значение unique_id из qml
    Q_PROPERTY(int maxRowCount READ getMaxRowCount WRITE setMaxRowCount NOTIFY maxRowCountChanged) // сво-во для установки максимального кол-ва отображаемых строк
public:
    DataModel(QObject *parent = nullptr);

    enum Roles {
        dataTime,
        dataKA,
        dataOKIK,
        dataResourses,
        dataTurn,
        dataNotification,
        keyRole
    };

    int rowCount(const QModelIndex &parent) const override; // сказать модели сколько у нее элементов
    QVariant data(const QModelIndex &index, int role) const override; // привязать данные модели к ролям
    QHash<int, QByteArray> roleNames() const override;  // указать как в qml будут называться роли

    int count() const;

    Q_INVOKABLE void extractLastReserveItem(); // вынести из резервной модели последний элемент в основную модель
    Q_INVOKABLE void extractAllReserve(); // вынести все элементы резервной модели в основную модель
    Q_INVOKABLE void reserve(int index); // сохранить текущий элемент основной модели в резервную модель
    Q_INVOKABLE void clear(); // очистить всю основную модель
    Q_INVOKABLE void remove(int index); // удалить элемент из основной модели
    Q_INVOKABLE void clearOldRows(); // удалить из модели элементы превышающие значение m_maxRowCount
    Q_INVOKABLE void append(const QString &time
                            , const QString &KA
                            , const QString &OKIK
                            , const QString &resources
                            , const QString &turn
                            , const QString &notification
                            , const QString &keyRole); // добавить элемент в основную модель из qml

    QString getCurrentKeyRole() const;
    void setCurrentKeyRole(const QString &value);  

    int getMaxRowCount() const;

public slots:
    void setMaxRowCount(int maxRowCount);

signals:
    void countChanged(int count);
    void currentKeyRoleChanged(QString currentKeyRole);
    void sendNotification(const QString &notify, const QVariantList & parameters = QVariantList()); // сигнал для удаления строки из БД    
    void maxRowCountChanged(int maxRowCount);

private:
    void setCount(int count);

private:
    QList<Data> m_data; //данные модели
    QList<Data> m_reserveData; // резервная модель
    QString m_currentKeyRole; // поле для записи unique_id из qml
    int m_count;
    int m_maxRowCount = 1000; // максимальное количество строк по умолчанию
};


#endif // MODEL_H
