#include "kurs.h"

kurs::kurs(QObject *parent) : QObject(parent)
{
	QString query;

	query.append("CREATE TABLE IF NOT EXISTS kurs("
		"kurs_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
		"prowadzacy_id INTEGER NOT NULL,"
		"student_id INTEGER NOT NULL,"
		"sala_id INTEGER NOT NULL,"
		"nazwa VARCHAR(100) NOT NULL,"
		"ECTS INTEGER NOT NULL,"
		"godzina_rozpoczecia VARCHAR(100) NOT NULL,"
		"godzina_zakonczenia NOT NULL,"
		"FOREIGN KEY(prowadzacy_id) REFERENCES prowadzacy(prowadzacy_id),"
		"FOREIGN KEY(student_id) REFERENCES Student(student_id)"
		"FOREIGN KEY(sala_id) REFERENCES sala(sala_id)"
		");");
	QSqlQuery create;
	create.prepare(query);

	if (create.exec())
	{
		qDebug() << "Table kurs exists or has been created";
	}
	else
	{
		qDebug() << "Table kurs not exists or has not been created";
		qDebug() << "KURS ERROR! " << create.lastError();
	}
}

//moim zdaniem powinno byæ rozbite na 4 funkcje:
//1 - tworzenie kursu (nazwa, ECTS, godzina rozpoczecia i zakonczenia
//2 - dodanie prowadzacego
//3 - dodanie studenta
//4 - przypisanie sali
//tylko wtedy do tych 3 funkcji trzeba sprawdzaæ, czy dany kurs ju¿ istnieje

void kurs::insert_kurs(QString nazwa, QString ECTS, QString ECTS, QString godzina_rozpoczecia, QString godzina_zakonczenia)
{

	QSqlQuery query;
	query.prepare("INSERT INTO kurs (nazwa, ECTS, godzina_rozpoczecia, godzina_zakonczenia)"
		"VALUES (?, ?, ?, ?)");
	query.addBindValue(nazwa);
	query.addBindValue(ECTS);
	query.addBindValue(godzina_rozpoczecia);
	query.addBindValue(godzina_zakonczenia);
	if (query.exec())
	{
		qDebug() << "The kurs is properly inserted";
	}
	else
	{
		qDebug() << "The kurs is not inserted correctly";
		qDebug() << "INSTERT KURS ERROR! " << query.lastError();
	}
}

