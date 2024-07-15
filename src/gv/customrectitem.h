#ifndef __CUSTOM_RECT_ITEM_H__
#define __CUSTOM_RECT_ITEM_H__

#include <QtWidgets>

class QGraphicsTextItem;

class CustomRectItem : public QGraphicsRectItem
{
    typedef QGraphicsRectItem _base;
public:
    CustomRectItem(QGraphicsItem* parent = nullptr);
    CustomRectItem(const QRectF& rect, QGraphicsItem* parent = nullptr);
    CustomRectItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem* parent = nullptr);
    QRectF CustomRectItem::boundingRect() const;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant& value) override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

private:
    void initUI();

    QGraphicsTextItem* m_text = nullptr;
};

#endif
