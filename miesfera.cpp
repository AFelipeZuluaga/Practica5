#include "miesfera.h"

miesfera::miesfera()
{
    vy=7;
}

QRectF miesfera::boundingRect() const
{
    return QRectF(0,0,10,10);
}

void miesfera::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);
    painter->drawEllipse(boundingRect());
    /*QPixmap pixmap;
    pixmap.load(":/Imagenes/pokebola.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());*/
}

void miesfera::choque()
{
    vy=-vy/1.3;
}
