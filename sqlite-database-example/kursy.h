#ifndef KURSY_H
#define KURSY_H

#include <QObject>
#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
class Kursy : public QObject
{
    Q_OBJECT
public:
    explicit Kursy(QObject *parent = nullptr);
    void insert_kursy(QString rok, QString nazwa_przedmiotu);
    void delete_kursy_rok(QString rok_studiow);
    void delete_kursy_nazwa_przedmiotu(QString nazwa_przedmiotu);
    void delete_duplicates();
    void edit_kursy(QString student_id, QString kurs_id,QString id);
signals:

};

#endif // KURSY_H
