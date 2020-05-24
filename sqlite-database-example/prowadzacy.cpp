#include "prowadzacy.h"

Prowadzacy::Prowadzacy(QObject *parent) : QObject(parent)
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

void Prowadzacy::insert_prowadzacy(QString imie, QString nazwisko)
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

void Prowadzacy::delete_porwadzacyID(QString id_prowadzacego)
{
    QSqlQuery query;
    query.prepare("DELETE FROM prowadzacy WHERE prowadzacy_id = ?");
    query.addBindValue(id_prowadzacego);
    if (query.exec())
    {
        qDebug()<<"The Prowadzacy is properly deleted";
    }
    else
    {
        qDebug()<<"The Prowadzacy is not inserted deleted";
        qDebug()<<"DELETE Prowadzacy ERROR! "<< query.lastError();
    }
}


