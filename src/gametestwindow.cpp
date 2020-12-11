#include "gametestwindow.h"
#include "ui_gametestwindow.h"
#include <QDebug>

class MyCls {
public:
    MyCls() : a(0), b(0) {

    }

    unsigned int handleId() const {
        return (unsigned int)(this);
    }

    int a;
    int b;
};

GameTestWindow::GameTestWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameTestWindow)
{
    ui->setupUi(this);

    MyCls *c = new MyCls;
    MyCls *p = c;

    qDebug() << c->handleId() << p->handleId() << (uint)c << (uint)p;

    QString debug_msg  = QString::asprintf("0x%08X, 0x%08X", c->handleId(), p->handleId());
    //debug_msg.sprintf("%08X, %08X", c->handleId(), p->handleId());
    qDebug() << debug_msg;
}

GameTestWindow::~GameTestWindow()
{
    delete ui;
}

