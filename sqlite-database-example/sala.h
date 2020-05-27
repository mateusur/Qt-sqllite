#ifndef SALA_H
#define SALA_H


#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
class Sala : public QObject
{
    Q_OBJECT
public:
    explicit Sala(QObject *parent = nullptr);
    void insert_sala(QString numer_sali, QString max_liczba_miejsc);
    void delete_salaID(QString sala_id);
    void edit_sala(QString numer_sali, QString max_liczba_miejsc,QString id);
signals:

};

#endif // SALA_H
