#ifndef MODEL_H
#define MODEL_H

#include "iobserver.h"
#include "generator.h"

#include <QVector>
#include <QObject>
#include <QTimer>

#include <list>

#include <cstdlib>

class Model : public QObject
{
    Q_OBJECT

public:
    static Model & getInstance();
    ~Model();

    Model(const Model &) = delete;
    Model& operator = (const Model &) = delete;

    void getData(QVector<double> &data, const size_t &dataIdx) const;
    void addData(Generator *fnc);
    void startDataGenerate();

    void addObserver(IObserver &ref);
    void removeObserver(IObserver &ref);

private:
    QVector<QVector<double>> mdl_;
    QVector<Generator *> generators_;
    std::list<IObserver *> observers_;
    QTimer *timer_;
    size_t columnCount_;

private:
    explicit Model(QObject *parent = 0);

    void notify() const;

private slots:
    void Update();

};

#endif // MODEL_H
