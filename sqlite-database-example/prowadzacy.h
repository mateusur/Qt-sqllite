#ifndef PROWADZACY_H
#define PROWADZACY_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
class prowadzacy : public QObject
{
    Q_OBJECT
public:
    explicit prowadzacy(QObject *parent = nullptr);
    void insert_prowadzacy(QString imie, QString nazwisko);
signals:

};

#endif // PROWADZACY_H
