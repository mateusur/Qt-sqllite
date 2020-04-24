#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlRecord>
#include <QStringList>

#include "prowadzacy.h"
#include "student.h"
#include "katedra.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    prowadzacy *nauczyciel;
    Student *uczen;
    katedra *katedra2;
    QString aktutlanie_wybrany;

     void select(QString kogo);

private slots:

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButtonInsert_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
