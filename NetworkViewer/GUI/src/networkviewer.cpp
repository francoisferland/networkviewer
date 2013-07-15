#include "networkviewer.h"

//Test application
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc,argv);
    NetworkViewer nv;
    nv.show();
    return app.exec();
}
