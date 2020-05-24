#include "kursy.h"

Kursy::Kursy(QObject *parent) : QObject(parent)
{
    QString query;

        query.append("CREATE TABLE IF NOT EXISTS kursy("
            "kursy_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
            "student_id INTEGER NOT NULL,"
            "kurs_id INTEGER NOT NULL,"
            "FOREIGN KEY(student_id) REFERENCES Student(student_id),"
            "FOREIGN KEY(kurs_id) REFERENCES kurs(kurs_id)"
            ");");
        QSqlQuery create;
        create.prepare(query);

        if (create.exec())
        {
            qDebug() << "Table kursy exists or has been created";
        }
        else
        {
            qDebug() << "Table kursy not exists or has not been created";
            qDebug() << "KURSY ERROR! " << create.lastError();
        }
}
