#ifndef RBTREE_H
#define RBTREE_H

#include <QMainWindow>
#include"node.h"
#include"mydialog.h"
#include"playdialog.h"
#include"helpdialog.h"
namespace Ui {
class RBTree;
}

class RBTree : public QMainWindow
{
    Q_OBJECT

public:
    explicit RBTree(QWidget *parent = 0);
    ~RBTree();
        void Function();
        void insertPlayer(QString catagory,QString team,QString name,int id,double avg,double economy,double price);
        void deleteValue(QString catagory,QString,QString PlayerName,int id,double avg,double economy,double price);
        void inorderPlayer();
        void inorder();
        void preorder();
        void CreatNewTeam();
        void ShowPlayerList();
        bool SearchData(int key);
        void in();

        Node *root;
    Ui::RBTree *ui;
    MyDialog *mydialog;
    PlayDialog *playdialog;
    HelpDialog *helpdialog;


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
       void on_ShowList_clicked();
       void on_PlayNow_clicked();
       void on_Help_clicked();
       void on_pushButton_clicked();
};

#endif // RBTREE_H
