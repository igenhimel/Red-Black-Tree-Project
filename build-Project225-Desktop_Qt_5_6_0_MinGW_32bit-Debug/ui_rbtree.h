/********************************************************************************
** Form generated from reading UI file 'rbtree.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RBTREE_H
#define UI_RBTREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RBTree
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *Help;
    QPushButton *ShowList;
    QPushButton *PlayNow;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *labelabout;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RBTree)
    {
        if (RBTree->objectName().isEmpty())
            RBTree->setObjectName(QStringLiteral("RBTree"));
        RBTree->resize(1046, 646);
        centralWidget = new QWidget(RBTree);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1051, 611));
        label->setPixmap(QPixmap(QString::fromUtf8("../../Pictures/abstract-2597264_1280.jpg")));
        Help = new QPushButton(centralWidget);
        Help->setObjectName(QStringLiteral("Help"));
        Help->setGeometry(QRect(420, 330, 211, 51));
        QFont font;
        font.setFamily(QStringLiteral("Algerian"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        Help->setFont(font);
        Help->setStyleSheet(QLatin1String("\n"
"background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 65), stop:0.288557 rgba(57, 255, 0, 69), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.597015 rgba(251, 255, 0, 145), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));\n"
"font: 12pt \"Algerian\";\n"
"\n"
"color:black;"));
        ShowList = new QPushButton(centralWidget);
        ShowList->setObjectName(QStringLiteral("ShowList"));
        ShowList->setGeometry(QRect(420, 260, 211, 51));
        ShowList->setFont(font);
        ShowList->setStyleSheet(QLatin1String("color:black;\n"
"font: 12pt \"Algerian\";\n"
"background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));
        PlayNow = new QPushButton(centralWidget);
        PlayNow->setObjectName(QStringLiteral("PlayNow"));
        PlayNow->setGeometry(QRect(420, 180, 211, 51));
        PlayNow->setFont(font);
        PlayNow->setStyleSheet(QLatin1String("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));\n"
"font: 12pt \"Algerian\";\n"
"\n"
""));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 20, 861, 141));
        QFont font1;
        font1.setFamily(QStringLiteral("Imprint MT Shadow"));
        font1.setPointSize(28);
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("color:blue;\n"
"\n"
""));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(420, 400, 211, 51));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QLatin1String("color:black;\n"
"background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 65), stop:0.288557 rgba(57, 255, 0, 69), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.597015 rgba(251, 255, 0, 145), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));\n"
"font: 12pt \"Algerian\";\n"
""));
        labelabout = new QLabel(centralWidget);
        labelabout->setObjectName(QStringLiteral("labelabout"));
        labelabout->setGeometry(QRect(90, 200, 271, 251));
        QFont font2;
        font2.setPointSize(12);
        labelabout->setFont(font2);
        labelabout->setStyleSheet(QStringLiteral("color:red;"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(560, 120, 491, 331));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../Pictures/cricket_PNG66.png")));
        RBTree->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RBTree);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1046, 26));
        RBTree->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RBTree);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RBTree->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RBTree);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RBTree->setStatusBar(statusBar);

        retranslateUi(RBTree);

        QMetaObject::connectSlotsByName(RBTree);
    } // setupUi

    void retranslateUi(QMainWindow *RBTree)
    {
        RBTree->setWindowTitle(QApplication::translate("RBTree", "RBTree", 0));
        label->setText(QString());
#ifndef QT_NO_TOOLTIP
        Help->setToolTip(QApplication::translate("RBTree", "<html><head/><body><p><span style=\" font-size:10pt;\">Want Help? click me</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        Help->setText(QApplication::translate("RBTree", "Help", 0));
#ifndef QT_NO_TOOLTIP
        ShowList->setToolTip(QApplication::translate("RBTree", "<html><head/><body><p><span style=\" font-size:10pt;\">Here you show player list and decide which player you buy and take decide who is your key player.</span></p><p><span style=\" font-size:10pt;\"><br/></span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        ShowList->setText(QApplication::translate("RBTree", " Players List", 0));
#ifndef QT_NO_TOOLTIP
        PlayNow->setToolTip(QApplication::translate("RBTree", "<html><head/><body><p><span style=\" font-size:10pt;\">Here you buying your Favourite player </span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        PlayNow->setWhatsThis(QApplication::translate("RBTree", "<html><head/><body><p align=\"justify\"><br/></p><p align=\"justify\"><br/></p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        PlayNow->setText(QApplication::translate("RBTree", "Play Now", 0));
        label_2->setText(QApplication::translate("RBTree", "CRIC 11 - PLAYER AUCTION GAME", 0));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("RBTree", "<html><head/><body><p><span style=\" font-size:10pt;\">Want to know My Information? Click me<br/></span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("RBTree", "About", 0));
        labelabout->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RBTree: public Ui_RBTree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RBTREE_H
