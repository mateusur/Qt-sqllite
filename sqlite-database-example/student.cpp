#include "student.h"

Student::Student(QObject *parent,QMessageBox *box) : QObject(parent),msgBox(box)
{
    QString query;
    query.append("CREATE TABLE IF NOT EXISTS Student("
                    "student_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
                    "imie VARCHAR(100) NOT NULL,"
                    "nazwisko VARCHAR(100) NOT NULL,"
                    "numer_indeksu INTEGER NOT NULL UNIQUE,"
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
    QSqlError error2;
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
        error2=insert.lastError();
        qDebug()<<"INSTERT Student ERROR! "<< error2;
        msgBox.setText(error2.databaseText());
        msgBox.exec();
    }
}
void Student::insert_student(QString imie, QString nazwisko, QString numer_indeksu, QString rok_studiow)
{
    QSqlError error2;
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
        error2=insert.lastError();
        qDebug()<<"INSTERT Student ERROR! "<< error2;
        msgBox.setText(error2.databaseText());
        msgBox.exec();
    }
}

void Student::delete_studentNAME(QString imie)
{
    QSqlError error2;
    QSqlQuery query;
    query.prepare("DELETE FROM Student WHERE imie = ?");
    query.addBindValue(imie);
    if (query.exec())
    {
        qDebug()<<"The Student is properly deleted";
    }
    else
    {
        qDebug()<<"The Student is not deleted correctly";
        qDebug()<<"DELETE Student ERROR! "<< query.lastError();
        msgBox.setText("Wiele takich samych imion, usunięcie niemożliwe");
        msgBox.exec();

    }
}

void Student::edit_student(QString imie, QString nazwisko, QString numer_indeksu, QString rok_studiow, QString deficyt,QString id)
{
    QSqlQuery query;
        query.prepare("UPDATE Student set imie=?, nazwisko=?, numer_indeksu=?,rok_studiow=?,deficyt=? where student_id=?");
        query.addBindValue(imie);
        query.addBindValue(nazwisko);
        query.addBindValue(numer_indeksu);
        query.addBindValue(rok_studiow);
        query.addBindValue(deficyt);
        query.addBindValue(id);
        if (query.exec())
        {
            qDebug() << "The Student is properly edited";
        }
        else
        {
            qDebug() << "The Student is not edited correctly";
            qDebug() << "UPDATE Student ERROR! " << query.lastError();
        }
}

void Student::delete_studentID(QString student_id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Student WHERE student_id = ?");
    query.addBindValue(student_id);
    if (query.exec())
    {
        qDebug()<<"The Student is properly deleted";
    }
    else
    {
        qDebug()<<"The Student is not deleted correctly";
        qDebug()<<"DELETE Student ERROR! "<< query.lastError();
    }
}
