/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEditName;
    QLineEdit *lineEditSurname;
    QLineEdit *lineEditAge;
    QLineEdit *lineEditClass;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QPushButton *pushButtonInsert;
    QTableWidget *tableWidgetAll;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(953, 641);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEditName = new QLineEdit(centralWidget);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setGeometry(QRect(30, 40, 113, 27));
        lineEditSurname = new QLineEdit(centralWidget);
        lineEditSurname->setObjectName(QString::fromUtf8("lineEditSurname"));
        lineEditSurname->setGeometry(QRect(170, 40, 113, 27));
        lineEditAge = new QLineEdit(centralWidget);
        lineEditAge->setObjectName(QString::fromUtf8("lineEditAge"));
        lineEditAge->setGeometry(QRect(310, 40, 113, 27));
        lineEditClass = new QLineEdit(centralWidget);
        lineEditClass->setObjectName(QString::fromUtf8("lineEditClass"));
        lineEditClass->setGeometry(QRect(450, 40, 113, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 67, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 20, 67, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(310, 20, 67, 17));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(450, 20, 67, 17));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 0, 141, 21));
        pushButtonInsert = new QPushButton(centralWidget);
        pushButtonInsert->setObjectName(QString::fromUtf8("pushButtonInsert"));
        pushButtonInsert->setGeometry(QRect(580, 40, 131, 28));
        tableWidgetAll = new QTableWidget(centralWidget);
        tableWidgetAll->setObjectName(QString::fromUtf8("tableWidgetAll"));
        tableWidgetAll->setGeometry(QRect(10, 140, 900, 431));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 953, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Surname:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Age:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Class:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Student", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "prowadzacy", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "katedra", nullptr));

        pushButtonInsert->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
