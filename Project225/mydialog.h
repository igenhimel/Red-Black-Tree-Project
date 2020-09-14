#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include"node.h"
namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();
    void Function();
    void insertPlayer(QString catagory,QString team,QString name,int id,double avg,double economy,double price);
    void deleteValue(QString catagory,QString,QString PlayerName,int id,double avg,double economy,double price);
    void inorderPlayer();
    void inorder();
    void preorder();
    void CreatNewTeam();
    void ShowPlayerList();
    bool SearchData(int key);


    Node *root;
    Ui::MyDialog *ui;

protected:
    bool SearchData(Node *&root,int key);
       void inorderPlayer(Node *&ptr);
       void rotateLeft(Node *&);
       void rotateRight(Node *&);
       void fixInsertRBTree(Node *&);
       void fixDeleteRBTree(Node *&);
       void inorderBST(Node *&);
       void preorderBST(Node *&);
       int getColor(Node *&);
       void setColor(Node *&, int);
       Node *minValueNode(Node *&);
       Node *maxValueNode(Node *&);
       Node* insertPlayer(Node *&, Node *&);
       Node* deleteBST(Node *&, QString catagory,QString team,QString name,int id,double avg,double economy,double price);
       int getBlackHeight(Node *);

private slots:
       void on_pushButton_clicked();
       void on_Search_clicked();
};

#endif // MYDIALOG_H
