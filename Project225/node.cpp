#include "node.h"

#include<QString>

Node::Node(QString catagory,QString team,QString name,int id,double avg,double economy,double price){






        this->catagory = catagory;
        this->team=team;
        this->PlayerName=name;
        this->id=id;
        this->avg=avg;
        this->economy=economy;
        this->price=price;
        count=0;
        color = RED;
        left = right = parent = NULL;
}

