#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
class Student : public QObject
{
    Q_OBJECT
    QMessageBox msgBox;
public:
    explicit Student(QObject *parent = nullptr,QMessageBox *box=nullptr);
    void insert_student(QString imie,QString nazwisko,QString numer_indeksu, QString rok_studiow,QString deficyt);
    void insert_student(QString imie, QString nazwisko, QString numer_indeksu, QString rok_studiow);
    void delete_studentID(QString student_id);
    void delete_studentNAME(QString imie);
signals:

};

#endif // STUDENT_H
