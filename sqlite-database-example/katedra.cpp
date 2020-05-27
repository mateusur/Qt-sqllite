#include "katedra.h"

Katedra::Katedra(QObject *parent) : QObject(parent)
{
    QString query;
    query.append("CREATE TABLE IF NOT EXISTS katedra("
                    "katedra_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
                    "nazwa VARCHAR(100) NOT NULL,"
                    "prowadzacy_id INTEGER NOT NULL,"
                    "FOREIGN KEY(prowadzacy_id) REFERENCES prowadzacy(prowadzacy_id)"
                    ");");
    QSqlQuery create;
    create.prepare(query);
    if (create.exec())
    {
        qDebug()<<"Table Katedra exists or has been created";
    }
    else
    {

        qDebug()<<"Table Katedra not exists or has not been created";
        qDebug()<<"Student ERROR! "<< create.lastError();

    }
}

void Katedra::insert_katedra(QString nazwa, QString prowadzacy_id)
{
    QSqlQuery query;
    query.prepare("INSERT INTO katedra (nazwa, prowadzacy_id)"
                  "VALUES (?, ?)");
    query.addBindValue(nazwa);
    query.addBindValue(prowadzacy_id);
    if (query.exec())
    {
        qDebug()<<"The Katerdra is properly inserted";
    }
    else
    {
        qDebug()<<"The Katedra is not inserted correctly";
        qDebug()<<"INSTERT Katedra ERROR! "<< query.lastError();


    }
}

void Katedra::edit_katedra(QString nazwa, QString prowadzacy_id, QString id)
{
    QSqlQuery query;
        query.prepare("UPDATE katedra set nazwa=?, prowadzacy_id=? where katedra_id=?");
        query.addBindValue(nazwa);
        query.addBindValue(prowadzacy_id);
        query.addBindValue(id);
        if (query.exec())
        {
            qDebug() << "The Katedra is properly edited";
        }
        else
        {
            qDebug() << "The Katedra is not Updated correctly";
            qDebug() << "UPDATE Katedra ERROR! " << query.lastError();
        }
}

void Katedra::delete_katedra(QString id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM katedra WHERE katedra_id = ?");
    query.addBindValue(id);
    if (query.exec())
    {
        qDebug()<<"The Katedra is properly deleted";
    }
    else
    {
        qDebug()<<"The Katedra is not deleted correctly";
        qDebug()<<"DELETE Katedra ERROR! "<< query.lastError();
    }
}


