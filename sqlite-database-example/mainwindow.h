#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlRecord>
#include <QStringList>

#include <QMessageBox>

#include "prowadzacy.h"
#include "student.h"
#include "katedra.h"
#include "kurs.h"
#include "sala.h"
#include "kursy.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QMessageBox msgBox2;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Prowadzacy *nowy_prowadzacy;
    Student *nowy_student;
    Katedra *nowa_katedra;
    Kurs *nowy_kurs;
    Sala *nowa_sala;
    Kursy *nowe_kursy;
    QString aktutlanie_wybrany;

    void select(QString kogo);
    void showStudent();
    void showProwadzacy();
    void showKurs();
    void showKatedra();
    void showSala();
    void showKursy();

    void fill_tables();
    void add_to_comboBox();
private slots:

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButtonInsert_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonInsertShow_clicked();

    void on_pushButtonHelp_clicked();

    void on_comboBox_usuwanie_currentTextChanged(const QString &arg1);

    void on_comboBox_dodawanie_currentIndexChanged(int index);

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
