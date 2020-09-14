#include "helpdialog.h"
#include "ui_helpdialog.h"
#include"rbtree.h"
HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);
}

HelpDialog::~HelpDialog()
{
    delete ui;
}


void HelpDialog::on_Back_clicked()
{

    hide();
    RBTree *a=new RBTree(this);
    a->setWindowTitle("CRIC 11");
    a->show();


}
