#ifndef KATEDRA_H
#define KATEDRA_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

#include <QMessageBox>

class Katedra : public QObject
{
    Q_OBJECT
public:
    explicit Katedra(QObject *parent = nullptr);
    void insert_katedra(QString nazwa, QString prowadzacy_id);
    void edit_katedra(QString nazwa, QString prowadzacy_id, QString id);
    void delete_katedra(QString id);
signals:

};

#endif // KATEDRA_H
