#ifndef IOBSERVER_H
#define IOBSERVER_H

class Model;

class IObserver {

public:
    virtual void handleEvent(const Model & mdl) = 0;
    virtual ~IObserver() {}

};

#endif // IOBSERVER_H
