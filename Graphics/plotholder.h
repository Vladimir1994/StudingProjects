#ifndef PLOTHOLDER_H
#define PLOTHOLDER_H

#include "iobserver.h"

#include "ui_mainwindow.h"

#include "qcustomplot.h"

#include <QVector>

class PlotHolder : public IObserver
{
public:
    PlotHolder(QCustomPlot *cp = 0);
    virtual ~PlotHolder() {}
    void setPlot(QCustomPlot *cp);
    void addCurve(const int &curveIdx);
    void removeCurve(const int &curveIdx);

    virtual void handleEvent(const Model &mdl) override;

private:
    QVector<int> curveIdx_;
    QCustomPlot *cp_;

};

#endif // PLOTHOLDER_H
