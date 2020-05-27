#include "kurs.h"

Kurs::Kurs(QObject *parent) : QObject(parent)
{
    QString query;

        query.append("CREATE TABLE IF NOT EXISTS kurs("
            "kurs_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
            "prowadzacy_id INTEGER NOT NULL,"
            "sala_id INTEGER NOT NULL,"
            "nazwa VARCHAR(100) NOT NULL,"
            "ECTS INTEGER NOT NULL,"
            "FOREIGN KEY(prowadzacy_id) REFERENCES prowadzacy(prowadzacy_id),"
            "FOREIGN KEY(sala_id) REFERENCES sala(sala_id)"
            ");");
        QSqlQuery create;
        create.prepare(query);

        if (create.exec())
        {
            qDebug() << "Table kurs exists or has been created";
        }
        else
        {
            qDebug() << "Table kurs not exists or has not been created";
            qDebug() << "KURS ERROR! " << create.lastError();
        }
}

void Kurs::insert_kurs(QString prowadzacy_id, QString sala_id, QString nazwa,QString ECTS)
{
    QSqlQuery query;
        query.prepare("INSERT INTO kurs (prowadzacy_id, sala_id, nazwa,ECTS)"
            "VALUES (?, ?, ?, ?)");
        query.addBindValue(prowadzacy_id);
        query.addBindValue(sala_id);
        query.addBindValue(nazwa);
        query.addBindValue(ECTS);
        if (query.exec())
        {
            qDebug() << "The kurs is properly inserted";
        }
        else
        {
            qDebug() << "The kurs is not inserted correctly";
            qDebug() << "INSTERT KURS ERROR! " << query.lastError();
        }
}

void Kurs::delete_kursID(QString kurs_id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM kurs WHERE kurs_id = ?");
    query.addBindValue(kurs_id);
    if (query.exec())
    {
        qDebug()<<"The kurs is properly deleted";
    }
    else
    {
        qDebug()<<"The Kurs is not deleted correctly";
        qDebug()<<"DELETE Kurs ERROR! "<< query.lastError();
    }
}

void Kurs::edit_kurs(QString prowadzacy_id, QString sala_id, QString nazwa, QString ECTS, QString id)
{
    QSqlQuery query;
        query.prepare("UPDATE kurs set prowadzacy_id=?, sala_id=?, nazwa=?,ECTS=? where kurs_id=?");
        query.addBindValue(prowadzacy_id);
        query.addBindValue(sala_id);
        query.addBindValue(nazwa);
        query.addBindValue(ECTS);
        query.addBindValue(id);
        if (query.exec())
        {
            qDebug() << "The kurs is properly edited";
        }
        else
        {
            qDebug() << "The Kurs is not Updated correctly";
            qDebug() << "UPDATE Kurs ERROR! " << query.lastError();
        }
}
