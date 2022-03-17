#include "esfera2.h"

esfera2::esfera2()
{

}

QRectF esfera2::boundingRect() const
{
    return QRectF(0,0,25,25);
}

void esfera2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);
    painter->drawEllipse(boundingRect());
    /*QPixmap pixmap;
    pixmap.load(":/Imagenes/pokebola.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());*/
}
