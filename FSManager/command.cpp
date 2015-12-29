#include "command.h"

Command::Command(int argsCount) : argsCount(argsCount) {}

bool Command::SetArgs(const QStringList & argsList) {
    args_ = argsList.toVector();
    if(!args_.empty())
        return true;
    else
        return false;
}
