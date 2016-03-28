#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "iobserver.h"

#include <QMainWindow>
#include <QList>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList<IObserver *> obsList_;
};

#endif // MAINWINDOW_H
