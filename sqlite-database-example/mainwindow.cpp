#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
/*
 * 1.Dodac edytowanie do kursy -ZROBIONE
 * 2.Usuwanie kursy - ZROBIONE
 * 3.Uzupelnic funkcje fill_tables()
 * 4. (ewentualnie) usuwanie kurs (tam jest ograniczenie obcego klucza)
 * 5.Posprzatanie kodu
 * 6.Dodac ewentualne komunikaty odnosnie pustych pol przy dodawaniu elementow
 * 7.Dodać Unique numer sali
 *
 * */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"Application initialized...";
    QString name;
    name.append("test31.sqlite");
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

    QMessageBox *msgBox=new QMessageBox;

    nowy_prowadzacy = new Prowadzacy();
    nowy_student = new Student(msgBox);
    nowa_katedra = new Katedra();
    nowa_sala = new Sala();
    nowy_kurs = new Kurs();
    nowe_kursy = new Kursy();

    //Funkcja pomocnicza sluzaca do wypelenienia bazy przykladowymi danymi
    //fill_tables();
    aktutlanie_wybrany= ui->comboBox->currentText();
    add_to_comboBox();
    select(aktutlanie_wybrany);
    ui->lineEdit_9->hide();
    ui->label_9->hide();
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
        qDebug()<<"The "+kogo +" is properly selected";
    }
    else
    {
        qDebug()<<"The "+kogo +" is not selected correctly";
        qDebug()<<"ERROR! "<< select.lastError();
    }

    int row = 0;
    ui->tableWidgetAll->setRowCount(0);

    QSqlRecord rec = select.record();
    int liczba_kolumn = rec.count();
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
    //Ustawiam wszystkie headery na raz
    ui->tableWidgetAll->setHorizontalHeaderLabels(label);
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

void MainWindow::showStudent()
{
    ui->label->setText("Imie:");
    ui->label_2->setText("Nazwisko: ");
    ui->label_3->setText("Numer indeksu:");
    ui->label_4->setText("Rok studiow: ");
    ui->label_5->setText("Deficyt:");
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_5->show();
    ui->lineEdit_1->show();
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->lineEdit_5->show();
}

void MainWindow::showProwadzacy()
{
    ui->label->setText("Imie:");
    ui->label_2->setText("Nazwisko: ");
    ui->label->show();
    ui->label_2->show();
    ui->lineEdit_1->show();
    ui->lineEdit_2->show();

    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
}

void MainWindow::showKurs()
{
    ui->label->setText("Prowadzacy_id: ");
    ui->label_2->setText("Sala_id: ");
    ui->label_3->setText("Nazwa kursu:");
    ui->label_4->setText("Liczba ECTS:");
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_5->hide();
    ui->lineEdit_1->show();
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->lineEdit_5->hide();
}

void MainWindow::showKatedra()
{
    ui->label->setText("Nazwa:");
    ui->label_2->setText("Prowadzacy_id: ");
    ui->label->show();
    ui->label_2->show();
    ui->lineEdit_1->show();
    ui->lineEdit_2->show();

    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
}

void MainWindow::showSala()
{
    ui->label->setText("Numer sali:");
    ui->label_2->setText("Max. liczba miejsc: ");
    ui->label->show();
    ui->label_2->show();
    ui->lineEdit_1->show();
    ui->lineEdit_2->show();

    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
}

void MainWindow::showKursy()
{
    ui->label->setText("Rok studiów:");
    ui->label_2->setText("Nazwa kursu: ");
    ui->label->show();
    ui->label_2->show();
    ui->lineEdit_1->show();
    ui->lineEdit_2->show();

    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
}

void MainWindow::fill_tables()
{
    nowy_student->insert_student("Mateusz","Urbaniak","241614","2","0");
    nowy_student->insert_student("Mikolaj","Urbaniak","253153","3","0");
    nowy_student->insert_student("Aleksandra","Stawarz","241612","2","0");
    nowy_student->insert_student("Monika","Kowalska","153245","1","3");
    nowy_student->insert_student("Aleksandra","Stawarz","554864","5","6");
    nowy_student->insert_student("Mikolaj","Mazurek","253153","3","10");
    nowy_student->insert_student("Joanna","Kopiec","252525","6","7");
    nowy_prowadzacy->insert_prowadzacy("Grzegorz","Mzyk");
    nowy_prowadzacy->insert_prowadzacy("Joanna","Ratajczak");
    nowy_prowadzacy->insert_prowadzacy("Robert","Muszyński");
    nowy_prowadzacy->insert_prowadzacy("Katarzyna","Zadarnowska");
    nowa_katedra->insert_katedra("Robotyki","4");
    nowa_katedra->insert_katedra("Sterowania","1");
    nowa_katedra->insert_katedra("Mechatroniki","2");
    nowa_katedra->insert_katedra("Informatyki","3");
    nowa_sala->insert_sala("235","200");
    nowa_sala->insert_sala("5","20");
    nowa_sala->insert_sala("100","100");
    nowa_sala->insert_sala("35","50");
}

void MainWindow::add_to_comboBox()
{   ui->comboBox_2->clear();
    QString query;
    query.append("SELECT kurs.nazwa FROM kurs");
     qDebug()<<"Query: " <<  query<<endl;
    QSqlQuery select;
    select.prepare(query);

    if (select.exec())
    {
        qDebug()<<"The kurs.nazwa is properly selected";
    }
    else
    {
        qDebug()<<"The kurs.nazwa is not selected correctly";
        qDebug()<<"ERROR! kurs.nazwa "<< select.lastError();
    }
    QSqlRecord rec = select.record();
    QStringList label2;
    label2+="-------";
    int nameCol = rec.indexOf("nazwa"); // index of the field "name"
    while (select.next())
    label2+= select.value(nameCol).toString(); // add all names
    ui->comboBox_2->addItems(label2);
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    qDebug() << "Argument : " << arg1;
    aktutlanie_wybrany=arg1;
    ui->pushButtonInsert->show();
     select(aktutlanie_wybrany);
}

void MainWindow::on_pushButtonInsert_clicked()
{   if(ui->checkBox->isChecked()){
        QString aktualny = ui->comboBox_dodawanie->currentText();
        if(aktualny=="Student"){
            QString imie,nazwisko,numer_indeksu,rok_studiow,deficyt,id;
            imie=ui->lineEdit_1->text();
            nazwisko=ui->lineEdit_2->text();
            numer_indeksu=ui->lineEdit_3->text();
            rok_studiow=ui->lineEdit_4->text();
            deficyt=ui->lineEdit_5->text();
            id=ui->lineEdit_9->text();
            nowy_student->edit_student(imie,nazwisko,numer_indeksu,rok_studiow,deficyt,id);
        }
        else if(aktualny=="prowadzacy"){
            QString imie,nazwisko,id;
            imie=ui->lineEdit_1->text();
            nazwisko=ui->lineEdit_2->text();
            id=ui->lineEdit_9->text();
            nowy_prowadzacy->edit_prowadzacy(imie,nazwisko,id);
        }
        else if(aktualny=="katedra"){
            QString nazwa,prowadzacy_id,id;
            nazwa=ui->lineEdit_1->text();
            prowadzacy_id=ui->lineEdit_2->text();
            id=ui->lineEdit_9->text();
            nowa_katedra->edit_katedra(nazwa,prowadzacy_id,id);
        }
        else if(aktualny=="sala"){
            QString numer_sali,max_liczba_miejsc,id;
            numer_sali=ui->lineEdit_1->text();
            max_liczba_miejsc=ui->lineEdit_2->text();
            id=ui->lineEdit_9->text();
            nowa_sala->edit_sala(numer_sali,max_liczba_miejsc,id);
        }
        else if(aktualny=="kurs"){
            QString prowadzacy_id,sala_id,nazwa,ECTS,id;
            prowadzacy_id=ui->lineEdit_1->text();
            sala_id=ui->lineEdit_2->text();
            nazwa=ui->lineEdit_3->text();
            ECTS =ui->lineEdit_4->text();
            id=ui->lineEdit_9->text();
            nowy_kurs->edit_kurs(prowadzacy_id,sala_id,nazwa,ECTS,id);
            add_to_comboBox();
        }
        else if(aktualny=="kursy"){
            ui->label->setText("Student id:");
            ui->label_2->setText("Kurs id:");
            QString student_id,kurs_id,id;
            student_id=ui->lineEdit_1->text();
            kurs_id=ui->lineEdit_2->text();
            id=ui->lineEdit_9->text();
            nowe_kursy->edit_kursy(student_id,kurs_id,id);
            nowe_kursy->delete_duplicates();
        }
    }
    else {
        QString aktualny = ui->comboBox_dodawanie->currentText();
        if(aktualny=="Student"){
            QString imie,nazwisko,numer_indeksu,rok_studiow,deficyt;
            if(ui->lineEdit_1->text().size()==0 || ui->lineEdit_2->text().size()==0 || ui->lineEdit_3->text().size()==0 || ui->lineEdit_4->text().size()==0 || ui->lineEdit_5->text().size()==0){
                msgBox2.setText("Pola nie mogą być puste");
                msgBox2.exec();
            }
            else{
                imie=ui->lineEdit_1->text();
                nazwisko=ui->lineEdit_2->text();
                numer_indeksu=ui->lineEdit_3->text();
                rok_studiow=ui->lineEdit_4->text();
                deficyt=ui->lineEdit_5->text();
                nowy_student->insert_student(imie,nazwisko,numer_indeksu,rok_studiow,deficyt);}

        }
        else if(aktualny=="prowadzacy"){
            if(ui->lineEdit_1->text()==0 || ui->lineEdit_2->text()==0){
                msgBox2.setText("Pola nie mogą być puste");
                msgBox2.exec();
            }
            else{
                QString imie,nazwisko;
                imie=ui->lineEdit_1->text();
                nazwisko=ui->lineEdit_2->text();
                nowy_prowadzacy->insert_prowadzacy(imie,nazwisko);}

        }
        else if(aktualny=="katedra"){
            if(ui->lineEdit_1->text()==0 || ui->lineEdit_2->text()==0){
                msgBox2.setText("Pola nie mogą być puste");
                msgBox2.exec();
            }
            else{
                QString nazwa,prowadzacy_id;
                nazwa=ui->lineEdit_1->text();
                prowadzacy_id=ui->lineEdit_2->text();
                nowa_katedra->insert_katedra(nazwa,prowadzacy_id);
            }

        }
        else if(aktualny=="sala"){
            if(ui->lineEdit_1->text()==0 || ui->lineEdit_2->text()==0){
                msgBox2.setText("Pola nie mogą być puste");
                msgBox2.exec();
            }
            else{
                QString numer_sali,max_liczba_miejsc;
                numer_sali=ui->lineEdit_1->text();
                max_liczba_miejsc=ui->lineEdit_2->text();
                nowa_sala->insert_sala(numer_sali,max_liczba_miejsc);}

        }
        else if(aktualny=="kurs"){
            if(ui->lineEdit_1->text()==0 || ui->lineEdit_2->text()==0 || ui->lineEdit_3->text()==0 || ui->lineEdit_4->text()==0){
                msgBox2.setText("Pola nie mogą być puste");
                msgBox2.exec();
            }
            else{
                QString prowadzacy_id,sala_id,nazwa,ECTS;
                prowadzacy_id=ui->lineEdit_1->text();
                sala_id=ui->lineEdit_2->text();
                nazwa=ui->lineEdit_3->text();
                ECTS =ui->lineEdit_4->text();
                nowy_kurs->insert_kurs(prowadzacy_id,sala_id,nazwa,ECTS);
                add_to_comboBox();
            }

        }
        else if(aktualny=="kursy"){
            if(ui->lineEdit_1->text()==0 || ui->lineEdit_2->text()==0 ){
                msgBox2.setText("Pola nie mogą być puste");
                msgBox2.exec();
            }
            else{
                QString rok_studiow,nazwa;
                rok_studiow=ui->lineEdit_1->text();
                nazwa=ui->lineEdit_2->text();
                nowe_kursy->insert_kursy(rok_studiow,nazwa);
                nowe_kursy->delete_duplicates();
            }

        }
    }


    select(aktutlanie_wybrany);
}

void MainWindow::on_pushButtonDelete_clicked()
{
    if(ui->comboBox_usuwanie->currentText()=="Student"){
        if(ui->lineEdit_7->text().size()>0 && ui->lineEdit_8->text().size()>0){
            QMessageBox msgBox;
            msgBox.setText("Nie ma takiej opcji usuwania. Uzupełnij tylko jedno pole");
            msgBox.exec();
        }
        else if(ui->lineEdit_7->text().size()>0){
            QString student_id;
            student_id=ui->lineEdit_7->text();
            nowy_student->delete_studentID(student_id);

        }
        else if(ui->lineEdit_8->text().size()>0){
            QString imie;
            imie=ui->lineEdit_8->text();
            nowy_student->delete_studentNAME(imie);

        }
    }
    else if(ui->comboBox_usuwanie->currentText()=="prowadzacy"){
        QString prowadzacy_id;
        prowadzacy_id=ui->lineEdit_7->text();
        nowy_prowadzacy->delete_porwadzacyID(prowadzacy_id);
    }
    else if(ui->comboBox_usuwanie->currentText()=="sala"){
        QString sala_id;
        sala_id=ui->lineEdit_7->text();
        nowa_sala->delete_salaID(sala_id);
    }
    else if(ui->comboBox_usuwanie->currentText()=="katedra"){
        QString id;
        id=ui->lineEdit_7->text();
        nowa_katedra->delete_katedra(id);
    }
    else if(ui->comboBox_usuwanie->currentText()=="kurs"){
        QString id;
        id=ui->lineEdit_7->text();
        nowy_kurs->delete_kursID(id);
    }
    else if(ui->comboBox_usuwanie->currentText()=="kursy"){

        if(ui->lineEdit_7->text().size()>0 && ui->lineEdit_8->text().size()>0){
            QMessageBox msgBox;
            msgBox.setText("Nie ma takiej opcji usuwania. Uzupełnij tylko jedno pole");
            msgBox.exec();
        }
        else if(ui->lineEdit_7->text().size()>0){
            QString rok;
            rok=ui->lineEdit_7->text();
             nowe_kursy->delete_kursy_rok(rok);

        }
        else if(ui->lineEdit_8->text().size()>0){
            QString nazwa_przedmiotu;
            nazwa_przedmiotu=ui->lineEdit_8->text();
           nowe_kursy->delete_kursy_nazwa_przedmiotu(nazwa_przedmiotu);

        }
    }
    select(aktutlanie_wybrany);
}

void MainWindow::on_pushButtonInsertShow_clicked()
{
    QString co_wypisac;
    if(ui->lineEdit_6->text().size()>0 && ui->comboBox_2->currentText()!="-------"){
        msgBox2.setText("Nie ma takiej opcji wyświetlania. Wyczyść pole lub wybierz -------");
        msgBox2.exec();
    }
    else if(ui->lineEdit_6->text().size()>0){
        if(ui->lineEdit_6->text()=="*")
            co_wypisac="*";
        else
            co_wypisac=ui->lineEdit_6->text();
        QString query;
        query.append("SELECT "+co_wypisac+" FROM "+ aktutlanie_wybrany );
        qDebug()<<"Query: " <<  query<<endl;
        QSqlQuery select;
        select.prepare(query);

        if (select.exec())
        {
            qDebug()<<"The "+aktutlanie_wybrany +" is properly selected";
        }
        else
        {
            qDebug()<<"The "+aktutlanie_wybrany +" is not selected correctly";
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
        //Ustawiam wszystkie headery na raz
        ui->tableWidgetAll->setHorizontalHeaderLabels(label);
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
    else{
        co_wypisac=ui->comboBox_2->currentText();
        QString query;
        query.append("SELECT DISTINCT Student.imie,Student.nazwisko,Student.numer_indeksu FROM Student,kurs,prowadzacy JOIN kursy WHERE kursy.student_id=Student.student_id AND kursy.kurs_id=kurs.kurs_id AND kurs.nazwa=\""+co_wypisac+"\"");
        qDebug()<<"Query: " <<  query<<endl;
        QSqlQuery select;
        select.prepare(query);

        if (select.exec())
        {
            qDebug()<<"The is properly selected";
        }
        else
        {
            qDebug()<<"The is not selected correctly";
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
        //Ustawiam wszystkie headery na raz
        ui->tableWidgetAll->setHorizontalHeaderLabels(label);
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
}

void MainWindow::on_pushButtonHelp_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Wpisz po przecinku co chcesz zobaczyć, np \"imie,nazwisko\" lub wpisz \"*\", żeby zobaczyć wszystkie kolumny ");
    msgBox.exec();
}

void MainWindow::on_comboBox_usuwanie_currentTextChanged(const QString &arg1)
{
    QString aktualny_tekst=ui->comboBox_usuwanie->currentText();
    ui->label_6->setText(aktualny_tekst+" id:");
    if(aktualny_tekst=="Student" || aktualny_tekst=="kursy"){
        ui->label_7->show();
        ui->lineEdit_8->show();
        if(aktualny_tekst=="kursy"){
            ui->label_6->setText("Rok:");
            ui->label_7->setText("Nazwa przedmiotu:");
        }
    }
    else{
        ui->label_7->hide();
        ui->lineEdit_8->hide();
    }


}

void MainWindow::on_comboBox_dodawanie_currentIndexChanged(int index)
{
    if(index==0)
        showStudent();
    else if(index==1)
        showProwadzacy();
    else if(index==2)
        showKatedra();
    else if(index==3)
        showSala();
    else if(index==4)
        showKurs();
    else if(index==5 && ui->checkBox->isChecked()){
    showKursy();
    ui->label->setText("Student id:");
    ui->label_2->setText("Kurs id:");
    }
    else if(index==5)
        showKursy();

}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
   if(arg1==2){
       ui->lineEdit_9->show();
       ui->label_9->show();
       ui->pushButtonInsert->setText("Zaktualizauj");
       if(ui->comboBox_dodawanie->currentText()=="kursy"){
           ui->label->setText("Student id:");
           ui->label_2->setText("Kurs id:");
       }
   }
   else{
       ui->lineEdit_9->hide();
       ui->label_9->hide();
       ui->pushButtonInsert->setText("Dodaj");
       if(ui->comboBox_dodawanie->currentText()=="kursy"){
           ui->label->setText("Rok studiów:");
           ui->label_2->setText("Nazwa kursu:");
       }
   }
}
