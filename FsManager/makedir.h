#ifndef MAKEDIR_H
#define MAKEDIR_H

#include "command.h"

class MakeDir : public Command
{
public:
    MakeDir();
    ~MakeDir() {}
    bool Execute(QString &log);
    bool UnExecute(QString &log);
};

#endif // MAKEDIR_H
