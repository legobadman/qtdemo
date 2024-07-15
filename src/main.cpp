#include <QtWidgets>
#include "gv/customgraphicsview.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    CustomGraphicsView view;
    view.show();

    //TestDialog dlg;
    //dlg.show();

    return app.exec();
}