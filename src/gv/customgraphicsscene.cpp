#include "customgraphicsscene.h"
#include "customrectitem.h"


CustomGraphicsScene::CustomGraphicsScene(QObject* parent)
    : QGraphicsScene(parent)
{
    CustomRectItem* pItem = new CustomRectItem(0,0, 100, 32);
    addItem(pItem);

    pItem->setBrush(QColor(255,0,0));
}