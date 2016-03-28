#include "plotholder.h"
#include "model.h"

PlotHolder::PlotHolder(QCustomPlot *cp) : cp_(cp)
{
    cp_->xAxis->setLabel("x");
    cp_->yAxis->setLabel("y");
    cp_->xAxis->setRange(0, 100);
    cp_->yAxis->setRange(-2, 2);
}

void PlotHolder::setPlot(QCustomPlot *cp)
{
    cp_ = cp;
}

void PlotHolder::addCurve(const int &curveIdx)
{
    if (!curveIdx_.contains(curveIdx))
        curveIdx_.append(curveIdx);
}

void PlotHolder::removeCurve(const int &curveIdx)
{
    foreach (int i, curveIdx_) {
        if (curveIdx_[i] == curveIdx)
            curveIdx_.remove(i);
    }
}

void PlotHolder::handleEvent(const Model &mdl)
{
    if (cp_ == 0 || curveIdx_.length() == 0)
        return;

    QVector<double> x;
    mdl.getData(x, 0);
    cp_->addGraph();
    if (cp_->graphCount() > 0)
        cp_->clearGraphs();
    for (int i = 0; i < curveIdx_.length(); i++) {
        cp_->addGraph();
        QVector<double> y;
        mdl.getData(y, curveIdx_[i]);
        cp_->graph(i)->setData(x, y);
    }
    cp_->replot();
}
