#include "prowadzacy.h"

prowadzacy::prowadzacy(QObject *parent) : QObject(parent)
{
    QString query;

    query.append("CREATE TABLE IF NOT EXISTS prowadzacy("
                    "prowadzacy_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
                    "imie VARCHAR(50) NOT NULL,"
                    "nazwisko VARCHAR(50) NOT NULL"
                    ");");
    QSqlQuery create;
    create.prepare(query);

    if (create.exec())
    {
        qDebug()<<"Table prowadzacy exists or has been created";
    }
    else
    {
        qDebug()<<"Table prowadzacy not exists or has not been created";
        qDebug()<<"PROWADZACY ERROR! "<< create.lastError();
    }
}

void prowadzacy::insert_prowadzacy(QString imie, QString nazwisko)
{

    QSqlQuery query;
    query.prepare("INSERT INTO prowadzacy (imie, nazwisko)"
                  "VALUES (?, ?)");
    query.addBindValue(imie);
    query.addBindValue(nazwisko);
    if (query.exec())
    {
        qDebug()<<"The prowadzacy is properly inserted";
    }
    else
    {
        qDebug()<<"The prowadzacy is not inserted correctly";
        qDebug()<<"INSTERT PROWADZACY ERROR! "<< query.lastError();
    }
}
