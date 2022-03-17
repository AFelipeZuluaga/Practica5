#include "pacman.h"

/*float pacman::orientacion()
{
    if(moverIx1)
    {
        filas=300;
    }
    if(moverDx1)
    {
        filas=0;
    }
    if(moverUy1)
    {
        filas=200;
    }
    if(moverDy1)
    {
        filas=100;
    }
    return filas;
}




void pacman::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverIx1=true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverDx1=true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverUy1=true;
    }
    else if(ev->key()==Qt::Key_Z)
    {
        moverDy1=true;
    }
    /*else if(ev->key()==Qt::Key_X)
    {
        delete bola;
    }
}
*/


pacman::pacman(QObject *parent) : QObject(parent)
{
    timer = new QTimer();

    //filas = orientacion();
    columnas = 0;

    QImage img(":/Imagenes/pacman.png");
    img = img.scaled(img.width()/4, img.height()/4, Qt::KeepAspectRatio);
    pixmap = new QPixmap();
    pixmap->convertFromImage(img);

    //dimensiones de cada imagen
    ancho = 100/4;
    alto = 100/4;

    timer->start(150);

    connect(timer,&QTimer::timeout,this,&pacman::Actualizacion);

}
void pacman::Actualizacion()
{
    columnas +=100/4;
    if(columnas >= 400/4){
        columnas =0;
    }
    this->update(-ancho/4,-alto/4,ancho,alto);
}

QRectF pacman::boundingRect() const
{
    return QRectF(-ancho/4, -alto/4, ancho, alto);
}


void pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/4,-alto/4,*pixmap,columnas,filas/4,ancho,alto);
}


