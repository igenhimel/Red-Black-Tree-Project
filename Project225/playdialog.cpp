#include "playdialog.h"
#include "ui_playdialog.h"
#include"rbtree.h"
#include"ui_rbtree.h"
#include<QInputDialog>
#include<QMessageBox>
#include<QDebug>

PlayDialog::PlayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayDialog)
{
    root=NULL;
    ui->setupUi(this);

}

PlayDialog::~PlayDialog()
{
    delete ui;
}

int PlayDialog::getColor(Node *&node)
{
    if (node == NULL)
        return BLACK;

    return node->color;
}
void PlayDialog::setColor(Node *&node, int color)
{
    if (node == NULL)
        return;

    node->color = color;
}
Node* PlayDialog::insertPlayer(Node *&root, Node *&ptr)
{
    if (root == NULL)
        return ptr;

    if (ptr->id<=root->id)
    {
        root->left = insertPlayer(root->left, ptr);
        root->left->parent = root;

        return root;
    }

    else if (ptr->id>=root->id)
    {
        root->right = insertPlayer(root->right, ptr);
        root->right->parent = root;
        return root;
    }

    return root;
}
void PlayDialog::insertPlayer(QString catagory,QString team,QString name,int id,double avg,double economy,double price)
{
    Node *node = new Node(catagory,team,name,id,avg,economy,price);
    root = insertPlayer(root, node);
    fixInsertRBTree(node);
}

void PlayDialog::rotateLeft(Node *&ptr)
{
    Node *right_child = ptr->right;
    ptr->right = right_child->left;

    if (ptr->right != NULL)
        ptr->right->parent = ptr;

    right_child->parent = ptr->parent;

    if (ptr->parent == NULL)
        root = right_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = right_child;
    else
        ptr->parent->right = right_child;

    right_child->left = ptr;
    ptr->parent = right_child;
}

void PlayDialog::rotateRight(Node *&ptr)
{
    Node *left_child = ptr->left;
    ptr->left = left_child->right;

    if (ptr->left != NULL)
        ptr->left->parent = ptr;

    left_child->parent = ptr->parent;

    if (ptr->parent == NULL)
        root = left_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = left_child;
    else
        ptr->parent->right = left_child;

    left_child->right = ptr;
    ptr->parent = left_child;
}

void PlayDialog::fixInsertRBTree(Node *&ptr)
{
    Node *parent = NULL;
    Node *grandparent = NULL;
    while (ptr != root && getColor(ptr) == RED && getColor(ptr->parent) == RED)
    {
        parent = ptr->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left)
        {
            Node *uncle = grandparent->right;
            if (getColor(uncle) == RED)
            {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            }
            else
            {
                if (ptr == parent->right)
                {
                    rotateLeft(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateRight(grandparent);
                qSwap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
        else
        {
            Node *uncle = grandparent->left;
            if (getColor(uncle) == RED)
            {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            }
            else
            {
                if (ptr == parent->left)
                {
                    rotateRight(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateLeft(grandparent);
                qSwap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
    }
    setColor(root, BLACK);
}


void PlayDialog::fixDeleteRBTree(Node *&node)
{
    if (node == NULL)
        return;

    if (node == root)
    {
        root = NULL;
        return;
    }

    if (getColor(node) == RED || getColor(node->left) == RED || getColor(node->right) == RED)
    {
        Node *child = node->left != NULL ? node->left : node->right;

        if (node == node->parent->left)
        {
            node->parent->left = child;
            if (child != NULL)
                child->parent = node->parent;
            setColor(child, BLACK);
            delete (node);
        }
        else
        {
            node->parent->right = child;
            if (child != NULL)
                child->parent = node->parent;
            setColor(child, BLACK);
            delete (node);
        }
    }
    else
    {
        Node *sibling = NULL;
        Node *parent = NULL;
        Node *ptr = node;
        setColor(ptr, DOUBLE_BLACK);
        while (ptr != root && getColor(ptr) == DOUBLE_BLACK)
        {
            parent = ptr->parent;
            if (ptr == parent->left)
            {
                sibling = parent->right;
                if (getColor(sibling) == RED)
                {
                    setColor(sibling, BLACK);
                    setColor(parent, RED);
                    rotateLeft(parent);
                }
                else
                {
                    if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK)
                    {
                        setColor(sibling, RED);
                        if(getColor(parent) == RED)
                            setColor(parent, BLACK);
                        else
                            setColor(parent, DOUBLE_BLACK);
                        ptr = parent;
                    }
                    else
                    {
                        if (getColor(sibling->right) == BLACK)
                        {
                            setColor(sibling->left, BLACK);
                            setColor(sibling, RED);
                            rotateRight(sibling);
                            sibling = parent->right;
                        }
                        setColor(sibling, parent->color);
                        setColor(parent, BLACK);
                        setColor(sibling->right, BLACK);
                        rotateLeft(parent);
                        break;
                    }
                }
            }
            else
            {
                sibling = parent->left;
                if (getColor(sibling) == RED)
                {
                    setColor(sibling, BLACK);
                    setColor(parent, RED);
                    rotateRight(parent);
                }
                else
                {
                    if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK)
                    {
                        setColor(sibling, RED);
                        if (getColor(parent) == RED)
                            setColor(parent, BLACK);
                        else
                            setColor(parent, DOUBLE_BLACK);
                        ptr = parent;
                    }
                    else
                    {
                        if (getColor(sibling->left) == BLACK)
                        {
                            setColor(sibling->right, BLACK);
                            setColor(sibling, RED);
                            rotateLeft(sibling);
                            sibling = parent->left;
                        }
                        setColor(sibling, parent->color);
                        setColor(parent, BLACK);
                        setColor(sibling->left, BLACK);
                        rotateRight(parent);
                        break;
                    }
                }
            }
        }
        if (node == node->parent->left)
            node->parent->left = NULL;
        else
            node->parent->right = NULL;
        delete(node);
        setColor(root, BLACK);
    }
}

Node* PlayDialog::deleteBST(Node *&root,QString catagory,QString team,QString PlayerName,int id,double avg,double economy,double price)
{
    if (root == NULL)
        return root;

    if (id < root->id)
        return deleteBST(root->left,catagory,team,PlayerName,id,avg,economy,price);

    if (id > root->id)
        return deleteBST(root->right, catagory,team,PlayerName,id,avg,economy,price);

    if (root->left == NULL || root->right == NULL)
        return root;

    Node *temp = minValueNode(root->right);

    root->catagory=temp->catagory;
    root->team=temp->team;
    root->PlayerName=temp->PlayerName;
    root->id = temp->id;
    root->avg=temp->avg;
    root->economy=temp->economy;
    root->price=temp->price;
    return deleteBST(root->right,temp->catagory,temp->team,temp->PlayerName, temp->id,temp->avg,temp->economy,temp->price);


}

void PlayDialog::deleteValue(QString catagory,QString team,QString PlayerName,int id,double avg,double economy,double price)
{
    Node *node = deleteBST(root,catagory,team,PlayerName,id,avg,economy,price);
    fixDeleteRBTree(node);
}

Node *PlayDialog::minValueNode(Node *&node)
{

    Node *ptr = node;

    while (ptr->left != NULL)
        ptr = ptr->left;

    return ptr;
}

Node* PlayDialog::maxValueNode(Node *&node)
{
    Node *ptr = node;

    while (ptr->right != NULL)
        ptr = ptr->right;

    return ptr;
}

int PlayDialog::getBlackHeight(Node *node)
{
    int blackheight = 0;
    while (node != NULL)
    {
        if (getColor(node) == BLACK)
            blackheight++;
        node = node->left;
    }
    return blackheight;
}

bool PlayDialog::SearchData(Node *&root,int key)
{


    if(root==NULL)
    {
        return root;
    }
    if(root->id==key)
    {

        return root;
    }
    else if(key<root->id)
    {
        if(root->left!=NULL)
            return SearchData(root->left,key);
    }
    else if(key>root->id)
    {
        if(root->right!=NULL)
            return SearchData(root->right,key);
    }
//    cout<<"Not Found"<<endl;
    return false;
}

bool PlayDialog::SearchData(int key)
{

    return SearchData(root,key);

}


void PlayDialog::inorderPlayer(Node *&ptr)
{
    if (ptr == NULL)
        return;

    inorderPlayer(ptr->left);


 ui->PlayerDisplay->append(("Player Name: "+ptr->PlayerName+"\n"+"Player Id: "+QString::number(ptr->id)+"\n"+"Player color: "+ptr->color+"\n"));


    inorderPlayer(ptr->right);


}
void PlayDialog::inorderPlayer(){
    inorderPlayer(root);
}

void PlayDialog::Function(){



    PlayDialog *m=new PlayDialog();
        QString catagory,Team,name;
        double avg,economy,price,tk=0.0;
        int id;
        double limit=100.00;
        double limitation=100.00;
        double basePrice=10.00;
        int point=0;


        while(tk!=limit){

            catagory=QInputDialog::getText(this,"CRIC11","Enter Player Catagory ");

            Team=QInputDialog::getText(this,"CRIC11","Enter Team Name");
            name=QInputDialog::getText(this,"CRIC11","Enter Player Name");
            id=QInputDialog::getInt(this,"CRIC11","Enter Id");
            if(SearchData(id)==false)
                   {
                      QMessageBox::information(this,"CRIC11","Player Already sold out");
                       continue;
                   }
            if(catagory=="batsman")
                   {
                      avg=QInputDialog::getDouble(this,"CRIC11","Enter Average");

                       economy=0.0;
                   }
            else
                    {
                        economy=QInputDialog::getDouble(this,"CRIC11","Enter Economy");

                        avg=0.0;
                    }
            price=QInputDialog::getDouble(this,"CRIC11","Enter Price");
                   while(price>=basePrice!=true || price<=limitation!=true){

                          QMessageBox::warning(this,"CRIC11","price is less than base price or Price Exceeded to limitation!");
                       price=QInputDialog::getDouble(this,"CRIC11","Enter Price");
                    }
                   basePrice=basePrice+5.00;
                   point=point+20;

                          tk=tk+price;

                          m->insertPlayer(catagory,Team,name,id,avg,economy,price);

                          QString str;
                          str.setNum(basePrice);

                          ui->baseP->setText("$"+str);
                                 limitation=limitation-price;
                                 QString s;
                                 s.setNum(limitation);
                                 QString o;
                                  o.setNum(point);
                                 ui->PointP->setText(o);

                                 ui->Limitp->setText("$"+s);
                                 ui->PlayerDisplay->append("Remaining Player:");
                                 deleteValue(catagory,Team,name,id,avg,economy,price);
                                 inorderPlayer();

                                 if(root==NULL)
                                        {
                                            m->ui->PlayerDisplay->append("All players are Sold Out!!! No Available Player Right Now....Thanks for participating!!!");

                                            break;
                                        }
                                        if(limitation==0)
                                        {
                                            m->ui->PlayerDisplay->append("No Remaining Balance");
                                            break;
                                        }

                                        if(root->color==DOUBLE_BLACK)

                                        {
                                            ui->PlayerDisplay->append("Warning!!! Double black exists");
                                        }

                                        QMessageBox::StandardButton reply=QMessageBox ::question(this,"CRIC11","Your Remaining Balance is $"+s+

                                            " & Key Player: ("+root->PlayerName+" )\nDo you want to Continue?",QMessageBox::Yes|QMessageBox::No);


                                        if(reply==QMessageBox::Yes){

                                            continue;
                                        }
                                        if(reply==QMessageBox::No)
                                          {

                                              break;
                                            break;
                                          }


            }
        hide();
        QString p;
        p.setNum(point);
        m->ui->PointP->setText(p);
        if(point==20*5){
            m->ui->PlayerDisplay->append("                                WINNER");
        }
        else{
            m->ui->PlayerDisplay->append("                  LOST... SORRY FOR YOU!! TRY AGAIN!");
        }
        m->ui->PlayerDisplay->append("BPL Players List:");
        m->inorderPlayer();
        m->setWindowTitle("CRIC 11");
        m->show();
}

void PlayDialog::on_pushButton_clicked()
{
    hide();
    RBTree *a=new RBTree(this);
    a->setWindowTitle("CRIC 11");
    a->show();
}

void PlayDialog::on_ProjectMain_clicked()
{



Function();


}
