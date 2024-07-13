#ifndef __CUSTOM_RECT_ITEM_H__
#define __CUSTOM_RECT_ITEM_H__

#include <QtWidgets>

class CustomRectItem : public QGraphicsRectItem
{
public:
    CustomRectItem(QGraphicsItem* parent = nullptr);
    CustomRectItem(const QRectF& rect, QGraphicsItem* parent = nullptr);
    CustomRectItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem* parent = nullptr);
};

#endif
