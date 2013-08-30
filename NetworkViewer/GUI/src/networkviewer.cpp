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
            typeMessage += "<span style=\"color: green\">[DEBUG]</span> ";
            break;
        case QtWarningMsg:
            typeMessage += "<span style=\"color: yellow\">[WARNING]</span> ";
            break;
        case QtCriticalMsg:
            typeMessage += "<span style=\"color: red\">[CRITICAL]</span> ";
            break;
        case QtFatalMsg:
            typeMessage += "<span style=\"color: red\">[FATAL]</span> ";
            abort();
            break;
        }

        QString contextStr = QString("<span style=\"color: blue\">(") + context.file + "," + context.line + "," + context.function + ")</span>";


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
