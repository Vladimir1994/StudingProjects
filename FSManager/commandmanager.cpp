#include "commandmanager.h"
#include "QDebug"

CommandManager::CommandManager(QObject *parent) :
    QObject(parent)
{}

CommandManager::~CommandManager() {
    foreach(auto it, AvaliableCommands ) {
        delete it;
    }
    foreach(auto it, AppliedCommands ) {
        delete it;
    }
    foreach(auto it, CanceledCommands ) {
        delete it;
    }
}

CommandManager& CommandManager::getInstance() {
    static CommandManager instance;
    return instance;
}

QString CommandManager::Execute(const QString & commandName, const QStringList & arguments) {
    if(!AvaliableCommands.contains(commandName))
        return "This command " + commandName + " does not exist.";
    AbstractFactory * factory = * AvaliableCommands.find(commandName);
    Command * cmd_ = factory->create();
    bool check = cmd_->SetArgs(arguments);
    if(!check)
        return "Not enough input arguments.";

    QString logMessage;
    bool isExecuted = cmd_->Execute(logMessage);
    if(isExecuted) {
        AppliedCommands.push_back(cmd_);
    }
    return logMessage;
}

QString CommandManager::UnExecute() {
    if(AppliedCommands.empty())
        return "There is nothing to undo.";

    QString logMessage;
    bool isUnExecuted = AppliedCommands.last()->UnExecute(logMessage);
    if(isUnExecuted) {
        CanceledCommands.push_back(AppliedCommands.last());
    }
    AppliedCommands.pop_back();
    return logMessage;
}

QString CommandManager::ReExecute() {
    if(CanceledCommands.empty())
        return "There is nothing to redo.";

    QString logMessage;
    bool isReExecuted = CanceledCommands.last()->Execute(logMessage);
    if(isReExecuted) {
        AppliedCommands.push_back(CanceledCommands.last());
    }
    CanceledCommands.pop_back();
    return logMessage;
}

QString CommandManager::receive(const QString & cmd) {
    QStringList splitCmd = cmd.split(" ");
    QString cmdName = splitCmd.first();
    splitCmd.pop_front();

    QStringList cmdArgs;

    foreach(auto it, splitCmd) {
        cmdArgs.push_back(it);
    }

    QString logMessage;
    if(cmdName == "undo") {
        logMessage = this->UnExecute();
    }
    else if(cmdName == "redo") {
        logMessage = this->ReExecute();
    }
    else {
        logMessage = this->Execute(cmdName, cmdArgs);
    }
    return logMessage;
}


