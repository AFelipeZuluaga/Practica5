#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    alto = screenGeometry.height()-100;
    ancho = screenGeometry.width()-100;
    x = screenGeometry.x();
    y = screenGeometry.y();


    scene=new QGraphicsScene(x,y,ancho,alto);


    puntuacion = 0;
    moverIx1=false;
    moverDx1=false;
    moverUy1=false;
    moverDy1=false;
    mover2=false;

    QImage image(":/Imagenes/Laberinto.png");
    QGraphicsScene* scene = new QGraphicsScene();
    //QGraphicsView* view = new QGraphicsView(scene);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    //view->show();
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setScene(scene);

    pcm = new pacman();

    scene->addItem(pcm);

    pcm->setPos(700,700);

    //ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/Laberinto.png")));
    //ui->graphicsView->fitInView(scene->itemsBoundingRect(),Qt::KeepAspectRatio);
    //ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);

    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(animar()));
    connect(this,SIGNAL(aviso(int)),this,SLOT(aumentarPunt()));

    timer->start(33);

    barra=new QGraphicsRectItem(-30,-10,60,20);
    scene->addItem(barra);
    barra->setPos(200,300);

    barra2=new QGraphicsRectItem(-30,-10,60,20);
    scene->addItem(barra2);
    barra2->setPos(200,200);

    l1=new QGraphicsLineItem(0,0,500,0);
    l2=new QGraphicsLineItem(0,0,0,400);
    l3=new QGraphicsLineItem(500,0,500,400);
    //l4=new QGraphicsLineItem(-100,400,500,400);
    //scene->addItem(l1);
    //scene->addItem(l2);
    //scene->addItem(l3);
    //scene->addItem(l4);

    bola = new miesfera();
    scene->addItem(bola);
    bola->setPos(200,350);

    //scene->destroyed()


}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}


void MainWindow::animar()
{
    if(moverIx1 && barra->x()>30)
    {
        pcm->setPos(pcm->x()-2,pcm->y());
    }
    if(moverDx1)
    {
        pcm->setPos(pcm->x()+2,pcm->y());
    }
    if(moverUy1)
    {
        pcm->setPos(pcm->x(),pcm->y()-2);
    }
    if(moverDy1)
    {
        pcm->setPos(pcm->x(),pcm->y()+2);
    }

    if(barra->collidesWithItem(l2) || barra->collidesWithItem(l3))
    {
        moverIx1=false;
        /*if(bola->isVisible()){
            bola->hide();
            //delete bola;
        }*/

    }
    if(barra->collidesWithItem(bola))
    {
        if(bola->isVisible()){
            bola->hide();
            emit aviso(9);
            //delete bola;
        }

    }

    /*for(int i=0; i<bolas.length();i++)
    {
        bolas.at(i)->mover();
        if(!bolas.at(i)->collidingItems().empty())
        {
            bolas.at(i)->choque();
        }
    }*/
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
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
    }*/
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverIx1=false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverDx1=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverUy1=false;
    }
    else if(ev->key()==Qt::Key_Z)
    {
        moverDy1=false;
    }
}

void MainWindow::aumentarPunt()
{
    puntuacion += 5;
    ui->lcdNumber->display(puntuacion);
    std::cout<<puntuacion<<std::endl;
}



/*void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    bolas.append(new Bola());
    scene->addItem(bolas.last());
    bolas.last()->setPos(ev->x()-83,ev->y()-83);
}*/
