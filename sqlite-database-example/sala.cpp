#include "sala.h"

Sala::Sala(QObject *parent) : QObject(parent)
{
    QString query;

    query.append("CREATE TABLE IF NOT EXISTS sala("
                    "sala_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
                    "numer_sali INTEGER NOT NULL,"
                    "max_liczba_miejsc INTEGER NOT NULL"
                    ");");
    QSqlQuery create;
    create.prepare(query);

    if (create.exec())
    {
        qDebug()<<"Table sala exists or has been created";
    }
    else
    {
        qDebug()<<"Table sala not exists or has not been created";
        qDebug()<<"SALA ERROR! "<< create.lastError();
    }

}

void Sala::insert_sala(QString numer_sali, QString max_liczba_miejsc)
{
    QSqlQuery query;
    query.prepare("INSERT INTO sala (numer_sali, max_liczba_miejsc)"
                  "VALUES (?, ?)");
    query.addBindValue(numer_sali);
    query.addBindValue(max_liczba_miejsc);
    if (query.exec())
    {
        qDebug()<<"The sala is properly inserted";
    }
    else
    {
        qDebug()<<"The sala is not inserted correctly";
        qDebug()<<"INSTERT SALA ERROR! "<< query.lastError();
    }

}

void Sala::delete_salaID(QString sala_id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM sala WHERE sala_id = ?");
    query.addBindValue(sala_id);
    if (query.exec())
    {
        qDebug()<<"The Sala is properly deleted";
    }
    else
    {
        qDebug()<<"The Sala is not deleted correctly";
        qDebug()<<"DELETE Sala ERROR! "<< query.lastError();
    }
}

void Sala::edit_sala(QString numer_sali, QString max_liczba_miejsc,QString id)
{
    QSqlQuery query;
        query.prepare("UPDATE sala set numer_sali=?, max_liczba_miejsc=? where sala_id=?");
        query.addBindValue(numer_sali);
        query.addBindValue(max_liczba_miejsc);
        query.addBindValue(id);
        if (query.exec())
        {
            qDebug() << "The Sala is properly edited";
        }
        else
        {
            qDebug() << "The Sala is not Updated correctly";
            qDebug() << "UPDATE Sala ERROR! " << query.lastError();
        }
}
