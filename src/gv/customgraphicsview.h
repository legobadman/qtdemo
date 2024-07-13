#ifndef __CUSTOM_GRAPHICS_VIEW_H__
#define __CUSTOM_GRAPHICS_VIEW_H__

#include <QtWidgets>

class CustomGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    CustomGraphicsView(QWidget* parent = nullptr);
};



#endif