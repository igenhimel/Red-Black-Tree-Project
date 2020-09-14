#include "mydialog.h"
#include "ui_mydialog.h"
#include"node.h"
#include"rbtree.h"
#include"ui_rbtree.h"
MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    root=NULL;
    ui->setupUi(this);


}

MyDialog::~MyDialog()
{
    delete ui;
}

int MyDialog::getColor(Node *&node)
{
    if (node == NULL)
        return BLACK;

    return node->color;
}
void MyDialog::setColor(Node *&node, int color)
{
    if (node == NULL)
        return;

    node->color = color;
}
Node* MyDialog::insertPlayer(Node *&root, Node *&ptr)
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
void MyDialog::insertPlayer(QString catagory,QString team,QString name,int id,double avg,double economy,double price)
{
    Node *node = new Node(catagory,team,name,id,avg,economy,price);
    root = insertPlayer(root, node);
    fixInsertRBTree(node);
}

void MyDialog::rotateLeft(Node *&ptr)
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

void MyDialog::rotateRight(Node *&ptr)
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

void MyDialog::fixInsertRBTree(Node *&ptr)
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


void MyDialog::fixDeleteRBTree(Node *&node)
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

Node* MyDialog::deleteBST(Node *&root,QString catagory,QString team,QString PlayerName,int id,double avg,double economy,double price)
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

void MyDialog::deleteValue(QString catagory,QString team,QString PlayerName,int id,double avg,double economy,double price)
{
    Node *node = deleteBST(root,catagory,team,PlayerName,id,avg,economy,price);
    fixDeleteRBTree(node);
}

Node *MyDialog::minValueNode(Node *&node)
{

    Node *ptr = node;

    while (ptr->left != NULL)
        ptr = ptr->left;

    return ptr;
}

Node* MyDialog::maxValueNode(Node *&node)
{
    Node *ptr = node;

    while (ptr->right != NULL)
        ptr = ptr->right;

    return ptr;
}

int MyDialog::getBlackHeight(Node *node)
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

bool MyDialog::SearchData(Node *&root,int key)
{


    if(root==NULL)
    {
        return root;
    }
    if(root->id==key)
    {
         ui->searchDisplay->append("Your Searching Player is Available: \n");
         if(root->avg!=0.0){
                 ui->searchDisplay->append("Player Name: "+root->PlayerName+"\nCatagory: "+root->catagory+"\nTeam: "+root->team
                 +"\nAverage: "+QString::number(root->avg)+"\nPlayer Color: "+root->color+"\n");
                 }
         else{
             ui->searchDisplay->append("Player Name: "+root->PlayerName+"\nCatagory: "+root->catagory+"\nTeam: "+root->team
             +"\nEconomy: "+QString::number(root->economy)+"\nPlayer Color: "+root->color+"\n");
         }



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

bool MyDialog::SearchData(int key)
{

    return SearchData(root,key);

}


void MyDialog::inorderPlayer(Node *&ptr)
{
    if (ptr == NULL)
        return;

    inorderPlayer(ptr->left);
    if(ptr->avg!=0.0)
       {
     ui->Display->append("Player Id: "+QString::number(ptr->id));
     ui->Display->append("Player Name: "+ptr->PlayerName+"\nCatagory: "+ptr->catagory+"\nTeam: "+ptr->team+"\nPlayer Average: "
                               " "+QString::number(ptr->avg)+"\nPlayer Color: "+ptr->color+"\n");
    }
    else{
        ui->Display->append("Player Id: "+QString::number(ptr->id));
        ui->Display->append("Player Name: "+ptr->PlayerName+"\nCatagory: "+ptr->catagory+"\nTeam: "+ptr->team+"\nPlayer Economy: "
                                  " "+QString::number(ptr->economy)+"\nPlayer Color: "+ptr->color+"\n");

    }



    inorderPlayer(ptr->right);


}
void MyDialog::inorderPlayer(){
    inorderPlayer(root);

}

void MyDialog::on_pushButton_clicked()
{
        hide();
        RBTree *a=new RBTree(this);
        a->setWindowTitle("CRIC 11");
        a->show();



}

void MyDialog::on_Search_clicked()
{
 QString name;
 int id;
 name=ui->PlayerName->text();
 id=ui->playerID->text().toInt();

 if(SearchData(id)==true){


 }
 else{
     ui->searchDisplay->append("Your Searching Player is Not Available");

 }




}
