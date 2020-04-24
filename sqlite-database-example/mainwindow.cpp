#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug()<<"Application initialized...";

    QString name;
    name.append("test22.sqlite");

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(name);


    if(db.open())
    {
       qDebug()<<"Successful database connection";
       QSqlQuery query(db);
       query.exec("PRAGMA foreign_keys = ON;");
    }
    else
    {
       qDebug()<<"Error: failed database connection";
    }

    //createUserTable();
    nauczyciel = new prowadzacy();
    uczen = new Student();
    katedra2 = new katedra();
    //uczen->insert_student("Rocky","Stawarz","2314","2","3");
    //uczen->insert_student("Rocky","BLbla","2314","2");
    nauczyciel->insert_prowadzacy("Rocky","BLbla");
    katedra2->insert_katedra("Elektorniki", "1");

    aktutlanie_wybrany= ui->comboBox->currentText();
    select(aktutlanie_wybrany);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::select(QString kogo)
{
    QString query;
    query.append("SELECT * FROM "+kogo );
     qDebug()<<"Query: " <<  query<<endl;
    QSqlQuery select;
    select.prepare(query);

    if (select.exec())
    {
        qDebug()<<"The user is properly selected";
    }
    else
    {
        qDebug()<<"The user is not selected correctly";
        qDebug()<<"ERROR! "<< select.lastError();
    }

    int row = 0;
    ui->tableWidgetAll->setRowCount(0);

    QSqlRecord rec = select.record();
    int liczba_kolumn = rec.count();
    //qDebug() << "Number of columns: " << liczba_kolumn;
    ui->tableWidgetAll->setColumnCount(liczba_kolumn);
    QStringList label;
    //Pobieram poszczegolne headery dzieki fieldName;
    for(int i=0;i<liczba_kolumn;i++){
        QString nazwa_kolumny= rec.fieldName(i);
        //qDebug() << "Nazwa kolumny: " << nazwa_kolumny;
        label += nazwa_kolumny;
        ui->tableWidgetAll->setColumnWidth(i,880/liczba_kolumn);
    }
    ui->tableWidgetAll->verticalHeader()->setVisible(false);
    //qDebug() << "Label size: " << label.size();
    //Ustawiam wszystkie headery na raz
    ui->tableWidgetAll->setHorizontalHeaderLabels(label);
    //int nameCol = rec.indexOf("name"); // index of the field "name"
   // while (select.next())
   //qDebug() << select.value(nameCol).toString(); // output all names

    while (select.next())
    {
        //qDebug() << "Ilosc kolumn: " << select.record(0).
        ui->tableWidgetAll->insertRow(row);
        for(int j=0;j<=liczba_kolumn;j++){
            ui->tableWidgetAll->setItem(row,j,new QTableWidgetItem(select.value(j).toByteArray().constData()));
        }
        row++;
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    qDebug() << "Argument : " << arg1;
    aktutlanie_wybrany=arg1;
     select(aktutlanie_wybrany);
}

void MainWindow::on_pushButtonInsert_clicked()
{
    QString aktualny = ui->comboBox->currentText();
    if(aktualny=="prowadzacy"){
        QString imie, nazwisko, wiek;
        imie=ui->lineEditName->text();
        nazwisko= ui->lineEditSurname->text();
        wiek= ui->lineEditAge->text();
        qDebug() << imie << " " << nazwisko << " " << wiek;
        nauczyciel->insert_prowadzacy(imie,nazwisko);

    }
    else if(aktualny=="Student"){
        QString student_id,imie;
        if(ui->lineEditClass->text().size()>0){
            student_id= ui->lineEditClass->text();
            uczen->delete_studentID(student_id);
        }
        else if(ui->lineEditName->text().size()>0){
            imie=ui->lineEditName->text();
            uczen->delete_studentNAME(imie);
        }

    }

    select(aktutlanie_wybrany);
}
