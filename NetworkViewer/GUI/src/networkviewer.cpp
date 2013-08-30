#include "networkviewer.h"
#include "CoreDriverFactory.h"

//Test application
#include <QApplication>

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{

    NetworkViewerApp *app = dynamic_cast<NetworkViewerApp*>(QCoreApplication::instance());

    if (app)
    {
        QString typeMessage;

        switch (type) {
        case QtDebugMsg:
            typeMessage += "[DEBUG] ";
            break;
        case QtWarningMsg:
            typeMessage += "[WARNING] ";
            break;
        case QtCriticalMsg:
            typeMessage += "[CRITICAL] ";
            break;
        case QtFatalMsg:
            typeMessage += "[FATAL] ";
            abort();
            break;
        }

        QString contextStr = QString("(") + context.file + "," + context.line + "," + context.function + ")";


        app->emitDebugInfo(typeMessage + contextStr + " - " + msg);
    }
}



int main(int argc, char* argv[])
{
    NetworkViewerApp app(argc,argv);
    app.init();
    qInstallMessageHandler(myMessageOutput);
    return app.exec();
}
