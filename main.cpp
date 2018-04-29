#include "xando.h"
#include "startgamedialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartGameDialog w;
    w.show();

    return a.exec();
}
