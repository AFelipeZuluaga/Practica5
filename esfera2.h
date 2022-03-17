#ifndef ESFERA2_H
#define ESFERA2_H
#include <QGraphicsItem>
#include <QPainter>

class esfera2 : public QGraphicsItem
{
public:
    esfera2();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ESFERA2_H
