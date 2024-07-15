#ifndef __CUSTOM_GRAPHICS_VIEW_H__
#define __CUSTOM_GRAPHICS_VIEW_H__

#include <QtWidgets>

class CustomGraphicsScene;

class CustomGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    CustomGraphicsView(QWidget* parent = nullptr);

private:
    CustomGraphicsScene* m_scene;
};



#endif