#ifndef KURS_H
#define KURS_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
class kurs : public QObject
{
	Q_OBJECT
public:
	explicit kurs(QObject *parent = nullptr);
	void insert_kurs(QString prowadzacy_id, QString student_id, QString sala_id, 
		QString nazwa, QString ECTS, QString godzina_rozpoczecia, QString godzina_zakonczenia);
signals:

};

#endif // KURS_H
