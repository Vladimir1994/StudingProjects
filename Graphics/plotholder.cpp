#include "plotholder.h"
#include "model.h"

PlotHolder::PlotHolder(QCustomPlot * cp) : cp_(cp) {
    cp_->xAxis->setLabel("x");
    cp_->yAxis->setLabel("y");
    cp_->xAxis->setRange(0, 100);
    cp_->yAxis->setRange(-2, 2);
}

void PlotHolder::setPlot(QCustomPlot * cp) {
    cp_ = cp;
}

void PlotHolder::addCurve(int curve_idx) {
    if(!curve_idx_.contains(curve_idx))
        curve_idx_.append(curve_idx);
}

void PlotHolder::removeCurve(int curve_idx) {
    foreach(int i, curve_idx_) {
        if(curve_idx_[i] == curve_idx)
            curve_idx_.remove(i);
    }
}

void PlotHolder::handleEvent(const Model & mdl) {
    if(cp_ == 0 || curve_idx_.length() == 0)
        return;

    QVector<double> x;
    mdl.getData(x, 0);
    cp_->addGraph();
    if(cp_->graphCount() > 0)
        cp_->clearGraphs();
    for(int i = 0; i < curve_idx_.length(); i++) {
        cp_->addGraph();
        QVector<double> y;
        mdl.getData(y, curve_idx_[i]);
        cp_->graph(i)->setData(x, y);
    }
    cp_->replot();
}
