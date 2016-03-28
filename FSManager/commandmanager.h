#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include "command.h"
#include "abstractfactory.h"
#include "factory.h"

#include <QObject>
#include <QMap>

class CommandManager : public QObject
{
    Q_OBJECT    

public:  
    ~CommandManager();
    QString Execute(const QString &commandName,
                    const QStringList &arguments);
    QString UnExecute();
    QString ReExecute();

    template<typename T>
    void AddCommand(const QString &id);

    Q_INVOKABLE QString receive(const QString &cmd);
    static CommandManager & getInstance();

    CommandManager(const CommandManager &) = delete;
    CommandManager & operator = (const CommandManager &) = delete;

private:
    explicit CommandManager(QObject *parent = 0);

private:
    QMap<QString, AbstractFactory *> AvaliableCommands;
    QVector<Command *> AppliedCommands;
    QVector<Command *> CanceledCommands;
};

template<typename T>
void CommandManager::AddCommand(const QString &id)
{
    auto it = AvaliableCommands.find(id);
    if (it == AvaliableCommands.end())
        AvaliableCommands[id] = new Factory<T>();
}

#endif // COMMANDMANAGER_H
