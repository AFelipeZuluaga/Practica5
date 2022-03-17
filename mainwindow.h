#ifndef MAINWINDOW_H
#define MAINWINDOW_H

using namespace std;

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
    QGraphicsRectItem* barra3;
    QGraphicsRectItem* barra4;
    QGraphicsRectItem* barra5;
    QGraphicsRectItem* barra6;
    QGraphicsRectItem* barra7;
    QGraphicsRectItem* barra8;
    QGraphicsRectItem* barra9;
    QGraphicsRectItem* barra10;
    QGraphicsRectItem* barra11;
    QGraphicsRectItem* barra12;
    QGraphicsRectItem* barra13;
    QGraphicsRectItem* barra14;
    QGraphicsRectItem* barra15;
    QGraphicsRectItem* barra16;
    QGraphicsRectItem* barra17;
    QGraphicsRectItem* barra18;
    QGraphicsRectItem* barra19;
    QGraphicsRectItem* barra20;
    QGraphicsRectItem* barra21;
    QGraphicsRectItem* barra22;
    QGraphicsRectItem* barra23;
    QGraphicsRectItem* barra24;
    QGraphicsRectItem* barra25;
    QGraphicsRectItem* barra26;
    QGraphicsRectItem* barra27;
    QGraphicsRectItem* barra28;
    QGraphicsRectItem* barra29;
    QGraphicsRectItem* barra30;
    QGraphicsRectItem* barra31;
    QGraphicsRectItem* barra32;
    QGraphicsRectItem* barra33;
    QGraphicsRectItem* barra34;
    QGraphicsRectItem* barra35;
    QGraphicsRectItem* barra36;
    QGraphicsRectItem* barra37;
    QGraphicsRectItem* barra38;
    QGraphicsRectItem* barra39;
    QGraphicsRectItem* barra40;
    QGraphicsRectItem* barra41;
    QGraphicsRectItem* barra42;
    QGraphicsRectItem* barra43;
    QGraphicsRectItem* barra44;
    QGraphicsRectItem* barra45;
    QGraphicsRectItem* barra46;
    QGraphicsRectItem* barra47;
    QGraphicsRectItem* barra48;
    QGraphicsRectItem* barra49;
    QGraphicsRectItem* barra50;
    QGraphicsRectItem* barra51;
    QGraphicsRectItem* barra52;
    QGraphicsRectItem* barra53;
    QGraphicsRectItem* barra54;
    QGraphicsRectItem* barra55;
    QGraphicsRectItem* barra56;
    QGraphicsRectItem* barra57;
    QGraphicsRectItem* barra58;
    QGraphicsRectItem* barra59;
    QGraphicsRectItem* barra60;
    QGraphicsRectItem* barra61;
    QGraphicsRectItem* barra62;
    QGraphicsRectItem* barra63;
    QGraphicsRectItem* barra64;
    QGraphicsRectItem* barra65;
    QGraphicsRectItem* barra66;
    QGraphicsRectItem* barra67;
    QGraphicsRectItem* barra68;
    QGraphicsRectItem* barra69;
    QGraphicsRectItem* barra70;
    QGraphicsRectItem* barra71;
    QGraphicsRectItem* barra72;
    QGraphicsRectItem* barra73;
    QGraphicsRectItem* barra74;
    QGraphicsRectItem* barra75;
    QGraphicsRectItem* barra76;
    QGraphicsRectItem* barra77;
    QGraphicsRectItem* barra78;
    QGraphicsRectItem* barra79;
    QGraphicsRectItem* barra80;
    QGraphicsRectItem* barra81;
    QGraphicsRectItem* barra82;
    QGraphicsRectItem* barra83;
    QGraphicsRectItem* barra84;
    QGraphicsRectItem* barra85;
    QGraphicsRectItem* barra86;
    QGraphicsRectItem* barra87;
    QGraphicsRectItem* barra88;
    QGraphicsRectItem* barra89;
    QGraphicsRectItem* barra90;
    QGraphicsRectItem* barra91;
    QGraphicsRectItem* barra92;
    QGraphicsRectItem* barra93;
    QGraphicsRectItem* barra94;
    QGraphicsRectItem* barra95;
    QGraphicsRectItem* barra96;
    QGraphicsRectItem* barra97;
    QGraphicsRectItem* barra98;
    QGraphicsRectItem* barra99;
    QGraphicsRectItem* barra100;
    QGraphicsRectItem* barra101;
    QGraphicsRectItem* barra102;
    QGraphicsRectItem* barra103;
    QGraphicsRectItem* barra104;
    QGraphicsRectItem* barra105;
    QGraphicsRectItem* barra106;
    QGraphicsRectItem* barra107;
    QGraphicsRectItem* barra108;
    QGraphicsRectItem* barra109;
    QGraphicsRectItem* barra110;
    QGraphicsRectItem* barra111;
    QGraphicsRectItem* barra112;
    QGraphicsRectItem* barra113;
    QGraphicsRectItem* barra114;
    QGraphicsRectItem* barra115;
    QGraphicsRectItem* barra116;
    QGraphicsRectItem* barra117;
    QGraphicsRectItem* barra118;
    QGraphicsRectItem* barra119;
    QGraphicsRectItem* barra120;
    QGraphicsRectItem* barra121;
    QGraphicsRectItem* barra122;
    QGraphicsRectItem* barra123;
    QGraphicsRectItem* barra124;
    QGraphicsRectItem* barra125;
    QGraphicsRectItem* barra126;
    QGraphicsRectItem* barra127;
    QGraphicsRectItem* barra128;
    QGraphicsRectItem* barra129;
    QGraphicsRectItem* barra130;
    QGraphicsRectItem* barra131;
    QGraphicsRectItem* barra132;
    QGraphicsRectItem* barra133;
    QGraphicsRectItem* barra134;
    QGraphicsRectItem* barra135;
    QGraphicsRectItem* barra136;
    QGraphicsRectItem* barra137;
    QGraphicsRectItem* barra138;
    QGraphicsRectItem* barra139;
    QGraphicsRectItem* barra140;
    QGraphicsRectItem* barra141;
    QGraphicsRectItem* barra142;
    QGraphicsRectItem* barra143;
    QGraphicsRectItem* barra144;
    QGraphicsRectItem* barra145;
    QGraphicsRectItem* barra146;
    QGraphicsRectItem* barra147;
    QGraphicsRectItem* barra148;
    QGraphicsRectItem* barra149;
    QGraphicsRectItem* barra150;
    QGraphicsRectItem* barra151;
    QGraphicsRectItem* barra152;
    QGraphicsRectItem* barra153;
    QGraphicsRectItem* barra154;
    QGraphicsRectItem* barra155;
    QGraphicsRectItem* barra156;
    QGraphicsRectItem* barra157;
    QGraphicsRectItem* barra158;
    QGraphicsRectItem* barra159;
    QGraphicsRectItem* barra160;
    QGraphicsRectItem* barra161;
    QGraphicsRectItem* barra162;
    QGraphicsRectItem* barra163;
    miesfera* bola;
    QTimer *timer;
    pacman *pcm;
    //QPixmap *mapa;

    int puntuacion;
    int j, k;

    float x,y,ancho,alto;

    bool moverIx1;
    bool moverDx1;
    bool moverUy1;
    bool moverDy1;
    bool mover2;

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);

    //miesfera* vectorBolas[240];


/*protected:
         void paintEvent (QPaintEvent *); // reescribir el evento de dibujo


    //void mousePressEvent(QMouseEvent *ev);*/
};

#endif // MAINWINDOW_H
