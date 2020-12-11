#include "gametestwindow.h"
#include "sfmwidget_test.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    SFMWidget_Test wnd;
    wnd.show();


    //GameTestWindow w;
    //w.show();
    return a.exec();
}
