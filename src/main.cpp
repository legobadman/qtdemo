#include <QtWidgets>
#include "gv/customgraphicsview.h"
#include "gv/customlineedit.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    /*CustomGraphicsView view;
    view.show();*/

    //TestDialog dlg;
    //dlg.show();

    CustomLineEditor line;
    line.show();

    return app.exec();
}