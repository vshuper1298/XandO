#include "xando.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XandO w;
    w.show();

    return a.exec();
}
