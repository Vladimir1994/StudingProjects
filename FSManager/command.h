#ifndef COMMAND_H
#define COMMAND_H

#include <QDir>
#include <QString>
#include <QVector>
#include <QStringList>

class Command
{
public:
   Command(int argsCount);
   virtual ~Command() {}
   virtual bool Execute(QString &log) = 0;
   virtual bool UnExecute(QString &log) = 0;
   bool SetArgs(const QStringList &argsList);

protected:
   int argsCount;
   QVector<QString> args_;
};

#endif // COMMAND_H
