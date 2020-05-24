#ifndef KURS_H
#define KURS_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
class Kurs : public QObject
{
    Q_OBJECT
public:
    explicit Kurs(QObject *parent = nullptr);
    void insert_kurs(QString prowadzacy_id, QString sala_id,QString nazwa, QString ECTS);
    void delete_kursID(QString kurs_id);
signals:

};

#endif // KURS_H
