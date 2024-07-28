#ifndef __CUSTOM_LINE_EDIT_H__
#define __CUSTOM_LINE_EDIT_H__

#include <QtWidgets>

class QGraphicsTextItem;

class CustomLineEditor : public QLineEdit
{
    typedef QLineEdit _base;
public:
    CustomLineEditor(QWidget* parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void focusOutEvent(QFocusEvent* event) override;
    void leaveEvent(QEvent* event) override;
private:
    bool m_bPress = false;
    QPointF m_lastPos;
};

#endif
