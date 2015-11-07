#ifndef COMMAND_H
#define COMMAND_H

#include <QDir>
#include <QString>
#include <QVector>
#include <QStringList>

class Command
{
public:
   Command(int);
   virtual ~Command() {}
   virtual bool Execute(QString&) = 0;
   virtual bool UnExecute(QString&) = 0;
   bool SetArgs(QStringList);

protected:
   int args_count_;
   QVector<QString> args_;
};

#endif // COMMAND_H
