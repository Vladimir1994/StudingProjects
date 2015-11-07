#include "makedir.h"
#include "QDebug"

MakeDir::MakeDir() : Command(1) {}

bool MakeDir::Execute(QString &log) {
    qDebug() << args_[0];
    if(QDir(args_[0]).exists()) {
        log = "The directory " + args_[0] + " already exists.";
        return false;
    }
    if(QDir().mkdir(args_[0])) {
        log = "The directory " + args_[0] + " is successfully created.";
        return true;
    }
    else {
        log = "Can not create directory " + args_[0] +  ".";
        return false;
    }
}

bool MakeDir::UnExecute(QString &log) {
    if(!QDir(args_[0]).exists()) {
        log = "The directory " + args_[0] +  " has been already removed.";
        return false;
    }
    if(QDir(args_[0]).removeRecursively()) {
        log = "The directory " + args_[0] + " is successfully removed.";
        return true;
    }
    else {
        log = "Can not remove directory " + args_[0] +  ".";
        return false;
    }
}

