#include "customrectitem.h"


CustomRectItem::CustomRectItem(QGraphicsItem* parent)
    : QGraphicsRectItem(parent)
{

}

CustomRectItem::CustomRectItem(const QRectF& rect, QGraphicsItem* parent)
    : QGraphicsRectItem(rect, parent)
{

}

CustomRectItem::CustomRectItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem* parent)
    : QGraphicsRectItem(x, y, w, h, parent)
{

}