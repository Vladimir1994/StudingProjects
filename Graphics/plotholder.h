#ifndef PLOTHOLDER_H
#define PLOTHOLDER_H

#include <QVector>
#include "ui_mainwindow.h"
#include "qcustomplot.h"

#include "iobserver.h"

class PlotHolder : public IObserver {
public:
    PlotHolder(QCustomPlot * cp = 0);
    virtual ~PlotHolder() {}
    void setPlot(QCustomPlot * cp);
    void addCurve(const int & curve_idx);
    void removeCurve(const int & curve_idx);

    virtual void handleEvent(const Model & mdl) override;

private:
    QVector<int> curve_idx_;
    QCustomPlot * cp_;

};

#endif // PLOTHOLDER_H
