#include "lineas.h"

lineas::lineas(){}

/*QRectF lineas::boundingRect() const
{
    return QRectF(-10,-10,7,7);
}*/



void lineas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkBlue);
    painter->drawEllipse(boundingRect());
}
