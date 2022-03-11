#ifndef PACMAN_H
#define PACMAN_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class pacman : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit pacman(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    float filas, columnas;

    float ancho;
    float alto;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


signals:

public slots:
    void Actualizacion();
};

#endif // PACMAN_H
