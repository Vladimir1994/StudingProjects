#ifndef MAKEPATH_H
#define MAKEPATH_H

#include "command.h"

class MakePath : public Command
{
public:
    MakePath();
    ~MakePath() {}
    bool Execute(QString &);
    bool UnExecute(QString &);

private:
    QString firstCreatedDir_;
};

#endif // MAKEPATH_H
