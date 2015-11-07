#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "model.h"
#include "sinfunctorone.h"
#include "sinfunctortwo.h"
#include "sinfunctorthree.h"
#include "plotholder.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    PlotHolder * holder_1 = new PlotHolder(ui->customPlot_1);
    holder_1->addCurve(1);
    obsList_.append(holder_1);
    PlotHolder * holder_2 = new PlotHolder(ui->customPlot_2);
    holder_2->addCurve(2);
    obsList_.append(holder_2);
    PlotHolder * holder_3 = new PlotHolder(ui->customPlot_3);
    holder_3->addCurve(3);
    obsList_.append(holder_3);

    Model::getInstance().addObserver(*holder_1);
    Model::getInstance().addObserver(*holder_2);
    Model::getInstance().addObserver(*holder_3);

    Model::getInstance().addData(new SinFunctorOne());
    Model::getInstance().addData(new SinFunctorTwo());
    Model::getInstance().addData(new SinFunctorThree());

    Model::getInstance().startDataGenerate();
}

MainWindow::~MainWindow()
{
    foreach(auto iter, obsList_) {
        delete iter;
    }
    delete ui;
}
