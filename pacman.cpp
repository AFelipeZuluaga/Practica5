#include "pacman.h"

pacman::pacman(QObject *parent) : QObject(parent)
{
    timer = new QTimer();

    filas = 0;
    columnas = 0;

    pixmap = new QPixmap(":/Imagenes/pacman.png");
    //pixmap->scaled(400/5, 100/5);

    //dimensiones de cada imagen
    ancho = 100;
    alto = 100;

    timer->start(150);

    connect(timer,&QTimer::timeout,this,&pacman::Actualizacion);

}
void pacman::Actualizacion()
{
    columnas +=100;
    if(columnas >= 400){
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

QRectF pacman::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho, alto);
}

void pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}

