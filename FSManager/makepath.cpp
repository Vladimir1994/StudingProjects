#include "makepath.h"
#include "QStringList"

MakePath::MakePath() : Command(1), first_created_dir_("") {}

bool MakePath::Execute(QString &log) {

    QStringList dirList = args_[0].split("/");
    QString LastFolder;
    while(!QDir(dirList.join("/")).exists()) {
        LastFolder = dirList.last();
        dirList.pop_back();
    }
    dirList.push_back(LastFolder);
    first_created_dir_ = dirList.join("/");

    if(QDir(args_[0]).exists()) {
        log = "The path " + args_[0] + " already exists.";
        return false;
    }
    if(QDir().mkpath(args_[0])) {
        log = "The path " + args_[0] + " is successfully created.";
        return true;
    }
    else {
        log = "Can not create path " + args_[0] +  ".";
        return false;
    }
}

bool MakePath::UnExecute(QString &log) {
    if(!QDir(first_created_dir_).exists()) {
        log = "The directory " + first_created_dir_ +  " has been already removed.";
        return false;
    }
    if(QDir(first_created_dir_).removeRecursively()) {
        log = "The directory " + first_created_dir_ + " is successfully removed.";
        return true;
    }
    else {
        log = "Can not remove directory " + first_created_dir_ +  ".";
        return false;
    }
}

