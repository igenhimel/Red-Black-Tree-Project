#include "rbtree.h"
#include <QApplication>
#include"mydialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RBTree w;
    w.setWindowTitle("CRIC 11");
    w.show();
    return a.exec();
}
