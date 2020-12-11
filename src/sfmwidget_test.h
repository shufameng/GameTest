#ifndef SFMWIDGET_TEST_H
#define SFMWIDGET_TEST_H

#include "sfmwidget.h"

namespace Ui {
class SFMWidget_Test;
}

class SFMWidget_Test : public SFMWidget
{
    Q_OBJECT

public:
    explicit SFMWidget_Test(QWidget *parent = nullptr);
    ~SFMWidget_Test();

private slots:
    void on_pushButton_startLoading_clicked();

    void onTimerTimeout();

private:
    Ui::SFMWidget_Test *ui;
};

#endif // SFMWIDGET_TEST_H
