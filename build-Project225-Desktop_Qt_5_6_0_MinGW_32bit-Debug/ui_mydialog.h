/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_MyDialog
{
public:
    QTextBrowser *Display;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *Search;
    QLineEdit *PlayerName;
    QLineEdit *playerID;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTextBrowser *searchDisplay;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *MyDialog)
    {
        if (MyDialog->objectName().isEmpty())
            MyDialog->setObjectName(QStringLiteral("MyDialog"));
        MyDialog->resize(1002, 578);
        Display = new QTextBrowser(MyDialog);
        Display->setObjectName(QStringLiteral("Display"));
        Display->setGeometry(QRect(0, 0, 421, 581));
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        Display->setFont(font);
        Display->setStyleSheet(QLatin1String("color:black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
""));
        pushButton = new QPushButton(MyDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(910, 0, 93, 28));
        pushButton->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color:white;\n"
"font: 10pt \"MS Shell Dlg 2\";"));
        label = new QLabel(MyDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1001, 581));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        label->setPixmap(QPixmap(QString::fromUtf8("../../Pictures/abstract-2597264_1280.jpg")));
        Search = new QPushButton(MyDialog);
        Search->setObjectName(QStringLiteral("Search"));
        Search->setGeometry(QRect(620, 200, 161, 51));
        Search->setFont(font1);
        Search->setStyleSheet(QStringLiteral("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 65), stop:0.288557 rgba(57, 255, 0, 69), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.597015 rgba(251, 255, 0, 145), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));
        PlayerName = new QLineEdit(MyDialog);
        PlayerName->setObjectName(QStringLiteral("PlayerName"));
        PlayerName->setGeometry(QRect(460, 120, 211, 51));
        PlayerName->setFont(font1);
        PlayerName->setStyleSheet(QStringLiteral("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        playerID = new QLineEdit(MyDialog);
        playerID->setObjectName(QStringLiteral("playerID"));
        playerID->setGeometry(QRect(720, 120, 211, 51));
        playerID->setFont(font1);
        playerID->setStyleSheet(QStringLiteral("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        label_2 = new QLabel(MyDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(510, 80, 171, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("NSimSun"));
        font2.setPointSize(12);
        label_2->setFont(font2);
        label_3 = new QLabel(MyDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(780, 80, 111, 31));
        label_3->setFont(font2);
        label_4 = new QLabel(MyDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(580, 20, 281, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Mongolian Baiti"));
        font3.setPointSize(12);
        label_4->setFont(font3);
        searchDisplay = new QTextBrowser(MyDialog);
        searchDisplay->setObjectName(QStringLiteral("searchDisplay"));
        searchDisplay->setGeometry(QRect(480, 260, 441, 301));
        searchDisplay->setFont(font1);
        searchDisplay->setStyleSheet(QLatin1String("color:black;\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 255, 255, 255), stop:0.1 rgba(255, 255, 255, 255), stop:0.2 rgba(255, 176, 176, 167), stop:0.3 rgba(255, 151, 151, 92), stop:0.4 rgba(255, 125, 125, 51), stop:0.5 rgba(255, 76, 76, 205), stop:0.52 rgba(255, 76, 76, 205), stop:0.6 rgba(255, 180, 180, 84), stop:1 rgba(255, 255, 255, 0));\n"
"\n"
""));
        label_5 = new QLabel(MyDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(190, 160, 201, 241));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../../Pictures/image-260nw-772072246.webp")));
        label_6 = new QLabel(MyDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(300, 390, 71, 51));
        label_6->setStyleSheet(QLatin1String("font: 14pt \"Algerian\";\n"
"font: 20pt \"Algerian\";\n"
"color:blue;\n"
""));
        label->raise();
        Display->raise();
        pushButton->raise();
        Search->raise();
        PlayerName->raise();
        playerID->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        searchDisplay->raise();
        label_5->raise();
        label_6->raise();

        retranslateUi(MyDialog);

        QMetaObject::connectSlotsByName(MyDialog);
    } // setupUi

    void retranslateUi(QDialog *MyDialog)
    {
        MyDialog->setWindowTitle(QApplication::translate("MyDialog", "Dialog", 0));
        pushButton->setText(QApplication::translate("MyDialog", "BACK", 0));
        label->setText(QString());
        Search->setText(QApplication::translate("MyDialog", "Search", 0));
        label_2->setText(QApplication::translate("MyDialog", "Player Name", 0));
        label_3->setText(QApplication::translate("MyDialog", "Player ID", 0));
        label_4->setText(QApplication::translate("MyDialog", "CRIC11- PLAYERS AUCTION", 0));
        label_5->setText(QString());
        label_6->setText(QApplication::translate("MyDialog", "11", 0));
    } // retranslateUi

};

namespace Ui {
    class MyDialog: public Ui_MyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
