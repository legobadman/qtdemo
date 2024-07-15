#include <QtWidgets>
#include "curvescalaritem.h"
#include "customgraphicsview.h"
#include "customgraphicsscene.h"


CurveSliderItem::CurveSliderItem(CurveScalarItem *parent)
    : QGraphicsObject(parent)
    , m_value(0)
    , m_scalar(parent)
    , m_yoffset(5)
{
    setPos(QPointF(0 + width/2, m_yoffset));
    setFlags(ItemIsMovable | ItemSendsScenePositionChanges | ItemIsSelectable);
    m_line = new QGraphicsLineItem(this);
    m_line->setPen(QPen(QColor(17, 204, 70), 2));
    m_line->setLine(QLineF(0, height + 1, 0, 10000));
}

QRectF CurveSliderItem::boundingRect() const
{
    return QRectF(-width / 2, 0, width, height);
}

void CurveSliderItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing, true);

    QRectF rc = boundingRect();
    QPen pen(QColor(17, 204, 70), 1);
    painter->setPen(pen);
    painter->setBrush(QColor(17, 204, 70));
    painter->drawRect(rc);

    QPointF points[5] = {
        rc.topLeft(),
        rc.bottomLeft(),
        QPointF(rc.x() + rc.width() / 2, rc.y() + rc.height() + 6),
        rc.bottomRight(),
        rc.topRight(),
    };
    painter->drawPolygon(points, 5);
    painter->restore();
}

QVariant CurveSliderItem::itemChange(GraphicsItemChange change, const QVariant& value)
{
    if (change == QGraphicsItem::ItemPositionChange)
    {
        qreal w = m_scalar->boundingRect().width();
        QPointF newPos = value.toPointF();
        newPos.setX(qMax(0., qMin(w, newPos.x())));
        qreal x_ = clipPos(newPos.x());
        newPos.setX(x_);
        newPos.setY(m_yoffset);
        return newPos;
    }
    else if (change == QGraphicsItem::ItemPositionHasChanged)
    {
        QPointF newPos = value.toPointF();
        m_value = pos2val(newPos.x());
        emit m_scalar->frameChanged(m_value);
    }
    return value;
}

qreal CurveSliderItem::clipPos(qreal x)
{
    CURVE_RANGE rg = m_scalar->range();
    int nFrames = rg.xTo - rg.xFrom;
    int nGrids = nFrames * 5;
    qreal w = m_scalar->boundingRect().width();
    qreal szGrid = w / nGrids;
    int n = x / szGrid;
    qreal x_ = n * szGrid + 0.0000001;
    return x_;
}

qreal CurveSliderItem::pos2val(qreal x)
{
    CURVE_RANGE rg = m_scalar->range();
    int nFrames = rg.xTo - rg.xFrom;
    int nGrids = nFrames * 5;
    qreal w = m_scalar->boundingRect().width();
    qreal szGrid = w / nGrids;
    int n = x / szGrid;
    qreal val = n * (rg.xTo - rg.xFrom) / nGrids;
    return val;
}

void CurveSliderItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsObject::mousePressEvent(event);
}

void CurveSliderItem::resetPosition()
{
    qreal w = m_scalar->boundingRect().width();
    CURVE_RANGE rg = m_scalar->range();
    int nFrames = rg.xTo - rg.xFrom;
    if (nFrames > 0)
    {
        int nGrids = nFrames * 5;
        qreal szPerGrid = w / nGrids;
        int n = m_value * nGrids / (rg.xTo - rg.xFrom);
        qreal x = n * szPerGrid;
        setPos(x, m_yoffset);
    }
}


CurveScalarItem::CurveScalarItem(CustomGraphicsView* pView, CustomGraphicsScene* pScene, QGraphicsItem* parent)
    : QGraphicsObject(parent)
    , m_scene(pScene)
    , m_slider(nullptr)
    , m_view(pView)
{
    m_range.xFrom = 0;
    m_range.xTo = 200;
    setFlag(QGraphicsItem::ItemIgnoresTransformations);
    setZValue(-20);

    m_slider = new CurveSliderItem(this);
    m_line = new QGraphicsLineItem(this);
    m_line->setPen(QPen(QColor(17, 204, 70), 3));
    
    
}

CURVE_RANGE CurveScalarItem::range() const
{
    return m_range;
}

QRectF CurveScalarItem::boundingRect() const
{
    QRectF rcScene = m_scene->sceneRect();
    qreal w = rcScene.width();
    qreal h = 64;
    return QRectF(0, 0, w, h);
    /*const QMargins margins = m_view->margins();
    const QTransform& trans = m_view->transform();
    const QRectF& rcGrid = m_view->boundingRect();
    if (m_bHorizontal)
    {
        qreal height = sz;
        if (m_bFrame)
        {
            height = 45;
        }
        qreal width = rcGrid.width();
        QRectF orginalRc(rcGrid.left(), 0, width * trans.m11(), height);
        return orginalRc;
    }
    else
    {
        qreal width = sz;
        qreal height = rcGrid.height();
        QRectF orginalRc(0, rcGrid.top(), width, height * trans.m22());
        return orginalRc;
    }*/
}

void CurveScalarItem::resetPosition()
{
    QRectF rcScene = m_scene->sceneRect();
    QRectF rcViewport = m_scene->sceneRect();
    QPointF lt = rcViewport.topLeft();
    QPointF wtf = m_view->mapToScene(lt.toPoint());
    const QTransform& trans = m_view->transform();
   
    setX(0);
    setY(wtf.y());
    m_slider->resetPosition();
    m_view->scene()->update();
}

void CurveScalarItem::update()
{
    resetPosition();
    _base::update();
}

void CurveScalarItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (m_slider)
    {
        QPointF pos = event->pos();
        qreal w = boundingRect().width();
        m_slider->setPos(pos);
    }
    _base::mousePressEvent(event);
}

void CurveScalarItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (m_slider)
    {
        QPointF pos = event->pos();
        qreal w = boundingRect().width();
        m_slider->setPos(pos);
    }
    _base::mouseMoveEvent(event);
}

void CurveScalarItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->save();

    const QRectF& rcScence = m_scene->sceneRect();
    if (rcScence.width() <= 0 || rcScence.height() <= 0)
        return;

    const QTransform &trans = m_view->transform();
    qreal scaleX = trans.m11();
    qreal scaleY = trans.m22();

    int prec = 2;
    auto frames = numframes(trans.m11(), trans.m22());

    CURVE_RANGE rg = range();

    QFont font = QApplication::font();
    QFontMetrics metrics(font);
    painter->setFont(font);
    painter->setPen(QPen(QColor(153, 153, 153)));
    painter->setRenderHint(QPainter::Antialiasing, false);

    const QRectF& rcBound = boundingRect();

    painter->fillRect(QRectF(0, 0, rcBound.width(), rcBound.height()), QColor(36, 36, 36));

    int m_nFrames = rg.xTo - rg.xFrom;
    {
        qreal realWidth = rcScence.width() * scaleX;
        qreal step = realWidth / m_nFrames;
        qreal y = option->rect.top();
        for (int i = 0; i <= m_nFrames; i++)
        {
            const qreal x = step * i;
            qreal scalar = (rg.xTo - rg.xFrom) * i / m_nFrames + rg.xFrom;

            QString numText = QString::number(scalar);//, 'g', prec);
            qreal textWidth = metrics.horizontalAdvance(numText);
            painter->setPen(QPen(QColor(153, 153, 153)));
            painter->drawText(QPoint(x - textWidth / 2, y + 22), numText);//大刻度线

            {
                qreal y = 3./4 * rcBound.height();
                painter->setPen(QColor(100, 100, 100));
                painter->drawLine(QPointF(x, y), QPointF(x, rcBound.height() - 1));
                if (i < m_nFrames)
                {
                    int _nFrames = 5;
                    const qreal _step = step / _nFrames;
                    for (int j = 1; j < _nFrames; j++)
                    {
                        const qreal x_ = x + _step * j;
                        y = 9./10 * rcBound.height();
                        painter->drawLine(QPointF(x_, y), QPointF(x_, rcBound.height() - 1));//小刻度线
                    }
                }
            }
        }
    }
    qreal y = rcBound.y() + rcBound.height() - 3;
    m_line->setLine(QLineF(0, y, m_slider->pos().x()-2, y));
    painter->restore();
}