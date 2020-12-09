#include "gametestwindow.h"
#include "ui_gametestwindow.h"

GameTestWindow::GameTestWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameTestWindow)
{
    ui->setupUi(this);
}

GameTestWindow::~GameTestWindow()
{
    delete ui;
}

