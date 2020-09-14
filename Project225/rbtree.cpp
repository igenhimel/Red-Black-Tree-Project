#include "rbtree.h"
#include "ui_rbtree.h"
#include"node.h"
#include"mydialog.h"
#include"ui_mydialog.h"
#include"playdialog.h"
#include"ui_playdialog.h"
#include"helpdialog.h"
#include"ui_helpdialog.h"
RBTree::RBTree(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RBTree)
{
    root=NULL;
    ui->setupUi(this);
    mydialog=NULL;
    playdialog=NULL;
    helpdialog=NULL;
}

RBTree::~RBTree()
{
    delete ui;
}
int RBTree::getColor(Node *&node)
{
    if (node == NULL)
        return BLACK;

    return node->color;
}
void RBTree::setColor(Node *&node, int color)
{
    if (node == NULL)
        return;

    node->color = color;
}
Node* RBTree::insertPlayer(Node *&root, Node *&ptr)
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
void RBTree::insertPlayer(QString catagory,QString team,QString name,int id,double avg,double economy,double price)
{
    Node *node = new Node(catagory,team,name,id,avg,economy,price);
    root = insertPlayer(root, node);
    fixInsertRBTree(node);
}

void RBTree::rotateLeft(Node *&ptr)
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

void RBTree::rotateRight(Node *&ptr)
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

void RBTree::fixInsertRBTree(Node *&ptr)
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


void RBTree::fixDeleteRBTree(Node *&node)
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

Node* RBTree::deleteBST(Node *&root,QString catagory,QString team,QString PlayerName,int id,double avg,double economy,double price)
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

void RBTree::deleteValue(QString catagory,QString team,QString PlayerName,int id,double avg,double economy,double price)
{
    Node *node = deleteBST(root,catagory,team,PlayerName,id,avg,economy,price);
    fixDeleteRBTree(node);
}

Node *RBTree::minValueNode(Node *&node)
{

    Node *ptr = node;

    while (ptr->left != NULL)
        ptr = ptr->left;

    return ptr;
}

Node* RBTree::maxValueNode(Node *&node)
{
    Node *ptr = node;

    while (ptr->right != NULL)
        ptr = ptr->right;

    return ptr;
}

int RBTree::getBlackHeight(Node *node)
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

bool RBTree::SearchData(Node *&root,int key)
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

bool RBTree::SearchData(int key)
{

    return SearchData(root,key);

}


void RBTree::inorderPlayer(Node *&ptr)
{
    if (ptr == NULL)
        return;

    inorderPlayer(ptr->left);

  // ui->treeWidget->rootIndex("Player Id: "+QString::number(ptr->id));
   //ui->listView->append(("Player Name: "+ptr->PlayerName+"\n"+"Player Color: "+ptr->color+"\n"));

    inorderPlayer(ptr->right);


}
void RBTree::inorderPlayer(){
    inorderPlayer(root);
}

void RBTree::on_ShowList_clicked()


{
    if(NULL==mydialog){
        mydialog=new MyDialog(this);
    }
    if(false==mydialog->isVisible()){
        hide();
        MyDialog *a=new MyDialog();
        a->insertPlayer("batsman","Bangladesh","Shakib",75,36,0.0,50.00);
        a->insertPlayer("batsman","Bangladesh","Tamim",28,34,0.0,50.00);
        a->insertPlayer("batsman","Bangladesh","Mushfiq",11,45,0.0,50.00);
        a->insertPlayer("batsman","Australia","Warner",40,56,0.0,120.00);
        a->insertPlayer("bowler","Bangladesh","Mustafizz",90,0.0,5.5,100.00);
        a->inorderPlayer();
        a->setWindowTitle("CRIC 11");
        a->show();



    }

}

void RBTree::on_PlayNow_clicked()
{
    if(NULL==playdialog){
       playdialog=new PlayDialog(this);
    }
    if(false==playdialog->isVisible()){
        hide();

        PlayDialog *b1=new PlayDialog();
        double basePrice=10.00;
        double limit=100.00;
        QString str,s;
        str.setNum(basePrice);
        s.setNum(limit);

            b1->ui->baseP->setText(str+"$");
             b1->ui->Limitp->setText(s+"$");
           b1->ui->PlayerDisplay->append("Available Player:");

            b1->insertPlayer("batsman","Bangladesh","Shakib",75,36,0.0,50.00);
            b1->insertPlayer("batsman","Bangladesh","Tamim",28,34,0.0,50.00);
            b1->insertPlayer("batsman","Bangladesh","Mushfiq",11,45,0.0,50.00);
            b1->insertPlayer("batsman","Australia","Warner",40,560,0.0,120.00);
            b1->insertPlayer("bowler","Bangladesh","Mustafizz",90,0.0,5.5,100.00);
            b1->inorderPlayer();
            b1->setWindowTitle("CRIC 11");
            b1->show();




    }

}

void RBTree::on_Help_clicked()
{
    if(NULL==helpdialog){
       helpdialog=new HelpDialog(this);
    }
    if(false==helpdialog->isVisible()){
        hide();

       HelpDialog *h=new HelpDialog();
       h->setWindowTitle("CRIC 11");
        h->show();
        }

}

void RBTree::on_pushButton_clicked()
{


    ui->labelabout->setText("CRIC 11 V 1.1\n\nData Stucture: Red Black Tree\n\nDeveloped By:\nHabib Al Hasan\nSheikh Asiful Bijoy\nIsrak Rafi");


}
