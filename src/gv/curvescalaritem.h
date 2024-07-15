#ifndef __CURVE_SCALER_ITEM_H__
#define __CURVE_SCALER_ITEM_H__

#include <QtWidgets>
#include "uicommon.h"

class CustomGraphicsView;
class CustomGraphicsScene;
class CurveScalarItem;

class CurveSliderItem : public QGraphicsObject
{
	typedef QGraphicsObject _base;
public:
	CurveSliderItem(CurveScalarItem* parent = nullptr);
	QRectF boundingRect() const override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void resetPosition();

protected:
	QVariant itemChange(GraphicsItemChange change, const QVariant& value) override;
	void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

private:
	qreal clipPos(qreal x);
	qreal pos2val(qreal val);

	const qreal width = 14;
	const qreal height = 18;
	qreal m_value;
	CurveScalarItem* m_scalar;
	QGraphicsLineItem* m_line;
	qreal m_yoffset;
};


class CurveScalarItem : public QGraphicsObject
{
	Q_OBJECT
	typedef QGraphicsObject _base;
public:
	CurveScalarItem(CustomGraphicsView* pView, CustomGraphicsScene* pScene, QGraphicsItem* parent = nullptr);
	QRectF boundingRect() const override;
    CURVE_RANGE range() const;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

signals:
	void frameChanged(qreal);

public slots:
	void update();

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

private:
	void resetPosition();

	const qreal sz = 24.;
	CustomGraphicsScene* m_scene;
	CustomGraphicsView* m_view;
	CurveSliderItem* m_slider;
	QGraphicsLineItem* m_line;
	CURVE_RANGE m_range;
};

#endif
