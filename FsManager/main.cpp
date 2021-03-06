#include "makedir.h"
#include "makepath.h"
#include "commandmanager.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QQmlContext *context = engine.rootContext();

    CommandManager::getInstance().AddCommand<MakeDir>("mkdir");
    CommandManager::getInstance().AddCommand<MakePath>("mkpath");

    context->setContextProperty("CommandManager",
                                &CommandManager::getInstance());

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
