#ifndef MIESFERA_H
#define MIESFERA_H

#include <QGraphicsItem>
#include <QPainter>

class miesfera : public QGraphicsItem
{
public:
    miesfera();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // MIESFERA_H
