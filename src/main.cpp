#include "gametestwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameTestWindow w;
    w.show();
    return a.exec();
}
