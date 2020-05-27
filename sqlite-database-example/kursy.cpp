#include "kursy.h"

Kursy::Kursy(QObject *parent) : QObject(parent)
{
    QString query;

        query.append("CREATE TABLE IF NOT EXISTS kursy("
            "kursy_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
            "student_id INTEGER NOT NULL,"
            "kurs_id INTEGER NOT NULL,"
            "FOREIGN KEY(student_id) REFERENCES Student(student_id),"
            "FOREIGN KEY(kurs_id) REFERENCES kurs(kurs_id)"
            ");");
        QSqlQuery create;
        create.prepare(query);

        if (create.exec())
        {
            qDebug() << "Table kursy exists or has been created";
        }
        else
        {
            qDebug() << "Table kursy not exists or has not been created";
            qDebug() << "KURSY ERROR! " << create.lastError();
        }
}

void Kursy::insert_kursy(QString rok, QString nazwa_przedmiotu)
{
    QSqlQuery query;
        query.prepare("INSERT INTO kursy (student_id,kurs_id) SELECT DISTINCT Student.student_id,kurs.kurs_id FROM Student, kurs WHERE Student.rok_studiow=? AND kurs.nazwa=? ");
        query.addBindValue(rok);
        query.addBindValue(nazwa_przedmiotu);
        if (query.exec())
        {
            qDebug() << "The kursy is properly inserted";
        }
        else
        {
            qDebug() << "The kursy is not inserted correctly";
            qDebug() << "insert kursy ERROR! " << query.lastError();
        }
}

void Kursy::delete_kursy_rok(QString rok_studiow)
{
    QSqlQuery query;
    query.prepare("DELETE FROM kursy where student_id=(SELECT Student.student_id FROM Student WHERE Student.rok_studiow=?)");
    query.addBindValue(rok_studiow);
    if (query.exec())
    {
        qDebug()<<"The kursy is properly deleted";
    }
    else
    {
        qDebug()<<"The kursy is not deleted correctly";
        qDebug()<<"DELETE kursy ERROR! "<< query.lastError();
    }
}

void Kursy::delete_kursy_nazwa_przedmiotu(QString nazwa_przedmiotu)
{
    QSqlQuery query;
    query.prepare("DELETE FROM kursy WHERE kurs_id=(SELECT DISTINCT kurs_id FROM kurs WHERE kurs.nazwa=?)");
    query.addBindValue(nazwa_przedmiotu);
    if (query.exec())
    {
        qDebug()<<"The kursy is properly deleted";
    }
    else
    {
        qDebug()<<"The kursy is not deleted correctly";
        qDebug()<<"DELETE kursy ERROR! "<< query.lastError();
    }
}

void Kursy::delete_duplicates()
{
    QSqlQuery query;
    query.prepare("DELETE FROM kursy WHERE EXISTS (SELECT NULL FROM kursy AS k WHERE kursy.student_id = k.student_id AND kursy.kurs_id = k.kurs_id GROUP BY k.student_id, k.kurs_id HAVING kursy.kursy_id < MAX(k.kursy_id))");
    if (query.exec())
    {
        qDebug()<<"The duplicates are properly deleted";
    }
    else
    {
        qDebug()<<"The duplicates are not deleted properly";
        qDebug()<<"DELETE duplicates ERROR! "<< query.lastError();
    }
}

void Kursy::edit_kursy(QString student_id, QString kurs_id,QString id)
{
    QSqlQuery query;
        query.prepare("UPDATE kursy set student_id=?, kurs_id=? where kursy_id=?");
        query.addBindValue(student_id);
        query.addBindValue(kurs_id);
        query.addBindValue(id);
        if (query.exec())
        {
            qDebug() << "The kursy is properly edited";
        }
        else
        {
            qDebug() << "The Kursy is not Updated correctly";
            qDebug() << "UPDATE Kursy ERROR! " << query.lastError();
        }
}
