#ifndef MODEL_H
#define MODEL_H

#include <QVector>
#include <QObject>
#include <list>
#include <QTimer>
#include <cstdlib>

#include "iobserver.h"
#include "functor.h"

class Model : public QObject
{
    Q_OBJECT

public:
    static Model& getInstance();
    ~Model();

    Model(const Model &) = delete;
    Model& operator = (const Model &) = delete;

    void getData(QVector<double> & data, const size_t & data_idx) const;
    void addData(Functor * fnc);
    void startDataGenerate();

    void addObserver(IObserver & ref);
    void removeObserver(IObserver & ref);

private:
    QVector<QVector<double> > mdl_;
    QVector<Functor * > functors_;
    std::list<IObserver * > observers_;
    QTimer *timer_;
    size_t columnCount_;

private:
    explicit Model(QObject *parent = 0);

    void Notify() const;

private slots:
    void Update();

};

#endif // MODEL_H
