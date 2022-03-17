#ifndef PACMAN_H
#define PACMAN_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>

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
    //void keyPressEvent(QKeyEvent *ev);
    //void keyReleaseEvent(QKeyEvent *ev);

    //float orientacion();

    bool moverIx1;
    bool moverDx1;
    bool moverUy1;
    bool moverDy1;
    bool mover2;


signals:

public slots:
    void Actualizacion();
};

#endif // PACMAN_H
