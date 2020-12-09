#ifndef GAMETESTWINDOW_H
#define GAMETESTWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class GameTestWindow; }
QT_END_NAMESPACE

class GameTestWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameTestWindow(QWidget *parent = nullptr);
    ~GameTestWindow();

private:
    Ui::GameTestWindow *ui;
};
#endif // GAMETESTWINDOW_H
