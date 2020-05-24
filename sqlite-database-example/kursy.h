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

signals:

};

#endif // KURSY_H
