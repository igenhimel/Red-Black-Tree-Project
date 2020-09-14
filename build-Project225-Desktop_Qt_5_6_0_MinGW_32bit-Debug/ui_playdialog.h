/********************************************************************************
** Form generated from reading UI file 'playdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYDIALOG_H
#define UI_PLAYDIALOG_H

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

class Ui_PlayDialog
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QTextBrowser *PlayerDisplay;
    QPushButton *ProjectMain;
    QLineEdit *baseP;
    QLineEdit *Limitp;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *PointP;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QDialog *PlayDialog)
    {
        if (PlayDialog->objectName().isEmpty())
            PlayDialog->setObjectName(QStringLiteral("PlayDialog"));
        PlayDialog->resize(1059, 643);
        pushButton = new QPushButton(PlayDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(960, 0, 93, 28));
        pushButton->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 12pt \"MS Shell Dlg 2\";\n"
"color:white;"));
        label = new QLabel(PlayDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1061, 641));
        label->setPixmap(QPixmap(QString::fromUtf8("../../Pictures/abstract-2597264_1280.jpg")));
        PlayerDisplay = new QTextBrowser(PlayDialog);
        PlayerDisplay->setObjectName(QStringLiteral("PlayerDisplay"));
        PlayerDisplay->setGeometry(QRect(50, 80, 471, 541));
        QFont font;
        font.setFamily(QStringLiteral("Nirmala UI"));
        font.setPointSize(10);
        PlayerDisplay->setFont(font);
        PlayerDisplay->setStyleSheet(QLatin1String("\n"
"color:black;"));
        ProjectMain = new QPushButton(PlayDialog);
        ProjectMain->setObjectName(QStringLiteral("ProjectMain"));
        ProjectMain->setGeometry(QRect(690, 320, 221, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Algerian"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        ProjectMain->setFont(font1);
        ProjectMain->setStyleSheet(QLatin1String("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 65), stop:0.288557 rgba(57, 255, 0, 69), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.597015 rgba(251, 255, 0, 145), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));\n"
"font: 12pt \"Algerian\";"));
        baseP = new QLineEdit(PlayDialog);
        baseP->setObjectName(QStringLiteral("baseP"));
        baseP->setGeometry(QRect(570, 130, 171, 41));
        QFont font2;
        font2.setPointSize(12);
        baseP->setFont(font2);
        baseP->setStyleSheet(QLatin1String("color:red;\n"
"\n"
""));
        baseP->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        Limitp = new QLineEdit(PlayDialog);
        Limitp->setObjectName(QStringLiteral("Limitp"));
        Limitp->setGeometry(QRect(830, 130, 171, 41));
        Limitp->setFont(font2);
        Limitp->setStyleSheet(QStringLiteral("color:red;"));
        Limitp->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_2 = new QLabel(PlayDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(610, 100, 141, 21));
        label_2->setFont(font2);
        label_3 = new QLabel(PlayDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(834, 90, 191, 31));
        label_3->setFont(font2);
        label_4 = new QLabel(PlayDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 40, 241, 21));
        QFont font3;
        font3.setFamily(QStringLiteral("Imprint MT Shadow"));
        font3.setPointSize(10);
        label_4->setFont(font3);
        PointP = new QLineEdit(PlayDialog);
        PointP->setObjectName(QStringLiteral("PointP"));
        PointP->setGeometry(QRect(710, 50, 141, 41));
        PointP->setFont(font2);
        PointP->setStyleSheet(QLatin1String("color:red;\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        PointP->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_5 = new QLabel(PlayDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(750, 20, 55, 16));
        label_5->setFont(font2);
        label_6 = new QLabel(PlayDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(290, 210, 211, 251));
        label_6->setPixmap(QPixmap(QString::fromUtf8("../../Pictures/image-260nw-772072246.webp")));
        label_7 = new QLabel(PlayDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(400, 440, 71, 51));
        label_7->setStyleSheet(QLatin1String("font: 14pt \"Algerian\";\n"
"font: 20pt \"Algerian\";\n"
"color:blue;\n"
""));
        label->raise();
        pushButton->raise();
        PlayerDisplay->raise();
        ProjectMain->raise();
        baseP->raise();
        Limitp->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        PointP->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();

        retranslateUi(PlayDialog);

        QMetaObject::connectSlotsByName(PlayDialog);
    } // setupUi

    void retranslateUi(QDialog *PlayDialog)
    {
        PlayDialog->setWindowTitle(QApplication::translate("PlayDialog", "Dialog", 0));
        pushButton->setText(QApplication::translate("PlayDialog", "Back", 0));
        label->setText(QString());
        ProjectMain->setText(QApplication::translate("PlayDialog", "Buy Now", 0));
        label_2->setText(QApplication::translate("PlayDialog", "Base Price", 0));
        label_3->setText(QApplication::translate("PlayDialog", "Remaining Balance", 0));
        label_4->setText(QApplication::translate("PlayDialog", "CRIC-11 PLAYERS AUCTION", 0));
        label_5->setText(QApplication::translate("PlayDialog", "Points", 0));
        label_6->setText(QString());
        label_7->setText(QApplication::translate("PlayDialog", "11", 0));
    } // retranslateUi

};

namespace Ui {
    class PlayDialog: public Ui_PlayDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYDIALOG_H
