#ifndef SALA_H
#define SALA_H


#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
class sala : public QObject
{
    Q_OBJECT
public:
    explicit sala(QObject *parent = nullptr);
    //void insert_prowadzacy(QString imie, QString nazwisko);
signals:

};

#endif // SALA_H
