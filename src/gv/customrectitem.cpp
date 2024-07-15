#include "customrectitem.h"
#include <QGraphicsTextItem>


CustomRectItem::CustomRectItem(QGraphicsItem* parent)
    : QGraphicsRectItem(parent)
{
    initUI();
}

CustomRectItem::CustomRectItem(const QRectF& rect, QGraphicsItem* parent)
    : QGraphicsRectItem(rect, parent)
{
    initUI();
}

CustomRectItem::CustomRectItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem* parent)
    : QGraphicsRectItem(x, y, w, h, parent)
{
    initUI();
}

QRectF CustomRectItem::boundingRect() const
{
    return _base::boundingRect();
}

QVariant CustomRectItem::itemChange(GraphicsItemChange change, const QVariant& value) {
    if (change == QGraphicsItem::ItemSelectedHasChanged)
    {
    }
    else if (change == QGraphicsItem::ItemPositionChange)
    {
        QPointF pos = value.toPointF();
        qreal yfix = 0;
        /*if (pos.y() >= 50 && pos.y() < 100) {
            yfix = 50;
        }
        else if (pos.y() >= 100 && pos.y() < 150) {
            yfix = 100;
        }
        else if (pos.y() >= 150 && pos.y() < 200) {
            yfix = 150;
        }
        else 
        {
            yfix = 200;
        }*/
        return QPointF(pos.x() < 0 ? 0: pos.x(), yfix);
    }
    else if (change == QGraphicsItem::ItemPositionHasChanged)
    {

    }
    return value;
}

void CustomRectItem::initUI() {
    setFlags(ItemIsMovable | ItemIsSelectable | ItemSendsGeometryChanges | ItemSendsScenePositionChanges);
    setAcceptHoverEvents(true);
    m_text = new QGraphicsTextItem("text", this);
    m_text->setParentItem(this);
    m_text->setPos(QPointF(20, 0));
}

void CustomRectItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    _base::paint(painter, option, widget);
}