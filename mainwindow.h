#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QDebug>
#include <QGraphicsItem>
#include <QRectF>
#include <QScreen>
#include <QGuiApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include "miesfera.h"
#include <iostream>
#include "lineas.h"
#include "pacman.h"
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void aviso(int);

public slots:
    void animar();
    void aumentarPunt();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsRectItem* barra;
    QGraphicsRectItem* barra2;
    QGraphicsLineItem* l1;
    QGraphicsLineItem* l2;
    QGraphicsLineItem* l3;
    QGraphicsLineItem* l4;
    miesfera* bola;
    QTimer *timer;
    pacman *pcm;
    QPixmap *mapa;

    int puntuacion;

    float x,y,ancho,alto;

    bool moverIx1;
    bool moverDx1;
    bool moverUy1;
    bool moverDy1;
    bool mover2;

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
    //void mousePressEvent(QMouseEvent *ev);
};
#endif // MAINWINDOW_H
