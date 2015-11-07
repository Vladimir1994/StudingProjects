#include "model.h"
#include "sinfunctorone.h"
#include "sinfunctortwo.h"
#include "sinfunctorthree.h"

Model::Model(QObject *parent) : QObject(parent), columnCount_(1) {
    mdl_.resize(4);
    mdl_[0].append(0);


    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(Update()));
}

Model& Model::getInstance() {
    static Model instance;
    return instance;
}

Model::~Model() {
    delete timer_;
    foreach(auto it, functors_) {
        delete it;
    }
}

void Model::getData(QVector<double> &data, size_t data_idx) const {
    if(data_idx < columnCount_) {
        data = mdl_[data_idx];
    }
}

void Model::addData(AbstractFunctor * fnc) {
    functors_.append(fnc);
    columnCount_++;
    mdl_[columnCount_ - 1].append((*functors_[columnCount_ - 2])(0));
}

void Model::startDataGenerate() {
    timer_->start(100);
}

void Model::Notify() const {
    foreach(auto iter, observers_) {
        iter->handleEvent(*this);
    }
}

void Model::addObserver(IObserver & ref) {
    observers_.push_back(&ref);
}

void Model::removeObserver(IObserver & ref) {
    observers_.remove(&ref);
}

void Model::Update() {
    mdl_[0].append(mdl_[0].last() + 0.1);
    for(unsigned int i = 1; i < columnCount_; i++) {
        mdl_[i].append((*functors_[i - 1])(mdl_[0].last()));
    }

    Notify();
    timer_->start();
}
