#ifndef NODE_H
#define NODE_H

#include<QString>
enum Color {RED, BLACK, DOUBLE_BLACK};
class Node
{
public:


    int color;
    Node *left, *right, *parent;
    double avg,economy;
    int id;
    QString PlayerName,team, catagory;
    double price;
    int count;

    explicit Node(QString catagory,QString team,QString name,int id,double avg,double economy,double price);
};

#endif // NODE_H
