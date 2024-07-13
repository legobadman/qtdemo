#ifndef __CUSTOMGRAPHICS_SCENE_H__
#define __CUSTOMGRAPHICS_SCENE_H__

#include <QtWidgets>

class CustomGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    CustomGraphicsScene(QObject* parent = nullptr);
};


#endif