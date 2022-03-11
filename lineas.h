#ifndef LINEAS_H
#define LINEAS_H

#include <QGraphicsItem>
#include <QPainter>

class lineas : public QGraphicsItem
{
private:
    lineas();
    //QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

};

#endif // LINEAS_H
