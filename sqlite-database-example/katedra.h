#ifndef KATEDRA_H
#define KATEDRA_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
class katedra : public QObject
{
    Q_OBJECT
public:
    explicit katedra(QObject *parent = nullptr);
    void insert_katedra(QString nazwa, QString prowadzacy_id);
signals:

};

#endif // KATEDRA_H
