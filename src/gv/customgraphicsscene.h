#ifndef __CUSTOMGRAPHICS_SCENE_H__
#define __CUSTOMGRAPHICS_SCENE_H__

#include <QtWidgets>

class CustomGraphicsView;

class CustomGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    CustomGraphicsScene(CustomGraphicsView* pView, QObject* parent = nullptr);
};


#endif