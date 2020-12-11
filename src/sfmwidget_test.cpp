#include "sfmwidget_test.h"
#include "ui_sfmwidget_test.h"
#include <map>

SFMWidget_Test::SFMWidget_Test(QWidget *parent) :
    SFMWidget(parent),
    ui(new Ui::SFMWidget_Test)
{
    ui->setupUi(this);
    createLoadingWidget();
}

SFMWidget_Test::~SFMWidget_Test()
{
    delete ui;
}

void SFMWidget_Test::on_pushButton_startLoading_clicked()
{
    QTimer *t = new QTimer;
    t->setInterval(10000);
    t->setSingleShot(true);
    connect(t, &QTimer::timeout, this, &SFMWidget_Test::onTimerTimeout);
    t->start();

    startLoading();std::map<int,int> m;m.insert()
}

void SFMWidget_Test::onTimerTimeout()
{
    finishLoading();
}
