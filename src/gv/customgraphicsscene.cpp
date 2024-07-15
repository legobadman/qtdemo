#include "customgraphicsscene.h"
#include "customrectitem.h"
#include "curvescalaritem.h"
#include "customgraphicsview.h"


CustomGraphicsScene::CustomGraphicsScene(CustomGraphicsView* pView, QObject* parent)
    : QGraphicsScene(parent)
{
    CustomRectItem* pItem = new CustomRectItem(0,50, 100, 32);
    addItem(pItem);

    CurveScalarItem* pScalar = new CurveScalarItem(pView, this);
    addItem(pScalar);

    this->setSceneRect(QRectF(0, 0, 10000, 256));

    pItem->setBrush(QColor(255,0,0));
}