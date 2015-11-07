#ifndef MAKEDIR_H
#define MAKEDIR_H

#include "command.h"

class MakeDir : public Command
{
public:
    MakeDir();
    ~MakeDir() {}
    bool Execute(QString&);
    bool UnExecute(QString&);
};

#endif // MAKEDIR_H
