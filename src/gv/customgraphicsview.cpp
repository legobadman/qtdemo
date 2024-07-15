#include "customgraphicsview.h"
#include "customgraphicsscene.h"


CustomGraphicsView::CustomGraphicsView(QWidget* parent)
    : QGraphicsView(parent)
    , m_scene(nullptr)
{
    m_scene = new CustomGraphicsScene;
    this->setScene(m_scene);
}