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
/*void Student::insert_student(QString imie, QString nazwisko, QString numer_indeksu, QString rok_studiow)
{
    QString query;
    query.append("INSERT INTO Student("
                    "imie,"
                    "nazwisko,"
                     "numer_indeksu,"
                     "rok_studiow)"
                    "VALUES("
                    "'"+imie+"',"
                    "'"+nazwisko+"',"
                    "'"+numer_indeksu+"',"
                    ""+rok_studiow+""
                    ");");

    QSqlQuery insert;
    insert.prepare(query);

    if (insert.exec())
    {
        qDebug()<<"The Student is properly inserted";
    }
    else
    {
        qDebug()<<"The Student is not inserted correctly";
        qDebug()<<"INSTERT Student ERROR! "<< insert.lastError();
    }
}

void Student::delete_studentNAME(QString imie)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Student WHERE imie = ?");
    query.addBindValue(imie);
    if (query.exec())
    {
        qDebug()<<"The Student is properly inserted";
    }
    else
    {
        qDebug()<<"The Student is not inserted correctly";
        qDebug()<<"INSTERT Student ERROR! "<< query.lastError();
    }
}

void Student::delete_studentID(QString student_id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Student WHERE student_id = ?");
    query.addBindValue(student_id);
    if (query.exec())
    {
        qDebug()<<"The Student is properly inserted";
    }
    else
    {
        qDebug()<<"The Student is not inserted correctly";
        qDebug()<<"INSTERT Student ERROR! "<< query.lastError();
    }
}*/

