#include "customlineedit.h"


CustomLineEditor::CustomLineEditor(QWidget* parent)
    :_base(parent)
{
    setFixedWidth(40);
    setText("123");
}

void CustomLineEditor::mousePressEvent(QMouseEvent* event)
{
    m_bPress = true;
    m_lastPos = event->pos();
    _base::mousePressEvent(event);
}
void CustomLineEditor::mouseMoveEvent(QMouseEvent* event)
{
    if (m_bPress)
    {
        QPointF pos = event->pos();
        qreal dx = pos.x() - m_lastPos.x();
        if (dx != 0)
        {
            int value = text().toInt();
            setText(QString::fromUtf8("%1").arg(value + dx));
            m_lastPos = event->pos();
        }
    }
    _base::mouseMoveEvent(event);
}
void CustomLineEditor::mouseReleaseEvent(QMouseEvent* event)
{
    m_bPress = false;
    _base::mouseReleaseEvent(event);
}

void CustomLineEditor::focusOutEvent(QFocusEvent* event) {
    m_bPress = false;
    _base::focusOutEvent(event);
}

void CustomLineEditor::leaveEvent(QEvent* event) {
    m_bPress = false;
    _base::leaveEvent(event);
}