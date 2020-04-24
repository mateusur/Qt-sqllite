#include "student.h"

Student::Student(QObject *parent) : QObject(parent)
{
    QString query;
    query.append("CREATE TABLE IF NOT EXISTS Student("
                    "student_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
                    "imie VARCHAR(100) NOT NULL,"
                    "nazwisko VARCHAR(100) NOT NULL,"
                    "numer_indeksu INTEGER NOT NULL,"
                    "rok_studiow INTEGER NOT NULL,"
                    "deficyt INTEGER DEFAULT 0"
                    ");");
    QSqlQuery create;
    create.prepare(query);
    if (create.exec())
    {
        qDebug()<<"Table Student exists or has been created";
    }
    else
    {
        qDebug()<<"Table Student not exists or has not been created";
        qDebug()<<"Student ERROR! "<< create.lastError();
    }
}

void Student::insert_student(QString imie, QString nazwisko, QString numer_indeksu, QString rok_studiow, QString deficyt)
{
    QString query;
    query.append("INSERT INTO Student("
                    "imie,"
                    "nazwisko,"
                     "numer_indeksu,"
                     "rok_studiow,"
                    "deficyt)"
                    "VALUES("
                    "'"+imie+"',"
                    "'"+nazwisko+"',"
                    "'"+numer_indeksu+"',"
                    "'"+rok_studiow+"',"
                    ""+deficyt+""
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
void Student::insert_student(QString imie, QString nazwisko, QString numer_indeksu, QString rok_studiow)
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
}
