#include "customgraphicsview.h"
#include "customgraphicsscene.h"


CustomGraphicsView::CustomGraphicsView(QWidget* parent)
    : QGraphicsView(parent)
    , m_scene(nullptr)
{
    m_scene = new CustomGraphicsScene(this);
    QBrush brush(QColor(23, 23, 23));
    m_scene->setBackgroundBrush(brush);
    this->setScene(m_scene);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
}

void CustomGraphicsView::wheelEvent(QWheelEvent* event)
{
    qreal zoomFactor = 1;
    if (event->angleDelta().y() > 0)
        zoomFactor = 1.25;
    else if (event->angleDelta().y() < 0)
        zoomFactor = 1 / 1.25;
    scale(zoomFactor, zoomFactor);
}