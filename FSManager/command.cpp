#include "command.h"

Command::Command(int args_count) : args_count_(args_count) {}

bool Command::SetArgs(QStringList args_list) {
    for(int i = 0; i < args_count_; i++) {
        if(!args_list.empty()) {
            args_.push_back(args_list.first());
            args_list.pop_front();
        }
        else
            return false;
    }
    return true;
}
