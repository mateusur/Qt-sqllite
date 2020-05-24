#ifndef PROWADZACY_H
#define PROWADZACY_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
class Prowadzacy : public QObject
{
    Q_OBJECT
public:
    explicit Prowadzacy(QObject *parent = nullptr);
    void insert_prowadzacy(QString imie, QString nazwisko);
    void delete_porwadzacyID(QString id_prowadzacego);
signals:

};

#endif // PROWADZACY_H
