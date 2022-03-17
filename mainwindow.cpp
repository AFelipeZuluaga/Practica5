#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
miesfera* vectorBolas[240];

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


    scene=new QGraphicsScene(-50,0,1081,761);


    puntuacion = 0;
    moverIx1=false;
    moverDx1=false;
    moverUy1=false;
    moverDy1=false;
    mover2=false;

    //QImage image(":/Imagenes/Fondo.jpg");
    //QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsView* view = new QGraphicsView(scene);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/Fondo.jpg")));
    //QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    //scene->addItem(item);
    //view->show();
    ui->graphicsView->setScene(scene);

    pcm = new pacman();

    scene->addItem(pcm);

    pcm->setPos(400,370);

    //ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/Laberinto.png")));
    //ui->graphicsView->fitInView(scene->itemsBoundingRect(),Qt::KeepAspectRatio);
    //ui->graphicsView->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);

    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(animar()));
    connect(this,SIGNAL(aviso(int)),this,SLOT(aumentarPunt()));

    timer->start(33);

    barra=new QGraphicsRectItem(0,0,810,5);
    scene->addItem(barra);
    barra->setBrush(Qt::blue);
    //barra->setPos(0,0);

    barra2=new QGraphicsRectItem(10,10,380,5);
    scene->addItem(barra2);
    barra2->setBrush(Qt::blue);
    //barra2->setPos(200,200);

    barra3=new QGraphicsRectItem(390,10,5,118);
    scene->addItem(barra3);
    barra3->setBrush(Qt::blue);

    barra4=new QGraphicsRectItem(390,128,37,5);
    scene->addItem(barra4);
    barra4->setBrush(Qt::blue);

    barra5=new QGraphicsRectItem(422,10,5,118);
    scene->addItem(barra5);
    barra5->setBrush(Qt::blue);

    barra6=new QGraphicsRectItem(427,10,370,5);
    scene->addItem(barra6);
    barra6->setBrush(Qt::blue);

    barra7=new QGraphicsRectItem(10,10,5,216);
    scene->addItem(barra7);
    barra7->setBrush(Qt::blue);

    barra8=new QGraphicsRectItem(0,0,5,236);
    scene->addItem(barra8);
    barra8->setBrush(Qt::blue);

    barra9=new QGraphicsRectItem(10,226,150,5);
    scene->addItem(barra9);
    barra9->setBrush(Qt::blue);

    barra10=new QGraphicsRectItem(0,236,150,5);
    scene->addItem(barra10);
    barra10->setBrush(Qt::blue);

    barra11=new QGraphicsRectItem(160,226,5,118);
    scene->addItem(barra11);
    barra11->setBrush(Qt::blue);

    barra12=new QGraphicsRectItem(150,236,5,98);
    scene->addItem(barra12);
    barra12->setBrush(Qt::blue);

    barra13=new QGraphicsRectItem(0,344,165,5);
    scene->addItem(barra13);
    barra13->setBrush(Qt::blue);

    barra13=new QGraphicsRectItem(0,334,155,5);
    scene->addItem(barra13);
    barra13->setBrush(Qt::blue);

    barra14=new QGraphicsRectItem(0,404,165,5);
    scene->addItem(barra14);
    barra14->setBrush(Qt::blue);

    barra15=new QGraphicsRectItem(0,414,155,5);
    scene->addItem(barra15);
    barra15->setBrush(Qt::blue);

    barra16=new QGraphicsRectItem(160,409,5,118);
    scene->addItem(barra16);
    barra16->setBrush(Qt::blue);

    barra17=new QGraphicsRectItem(150,419,5,98);
    scene->addItem(barra17);
    barra17->setBrush(Qt::blue);

    barra18=new QGraphicsRectItem(0,512,150,5);
    scene->addItem(barra18);
    barra18->setBrush(Qt::blue);

    barra19=new QGraphicsRectItem(10,522,155,5);
    scene->addItem(barra19);
    barra19->setBrush(Qt::blue);

    barra20=new QGraphicsRectItem(10,522,5,93);
    scene->addItem(barra20);
    barra20->setBrush(Qt::blue);

    barra24=new QGraphicsRectItem(10,645,5,93);
    scene->addItem(barra24);
    barra24->setBrush(Qt::blue);


    barra21=new QGraphicsRectItem(0,512,5,236);
    scene->addItem(barra21);
    barra21->setBrush(Qt::blue);

    barra22=new QGraphicsRectItem(10,738,792,5);
    scene->addItem(barra22);
    barra22->setBrush(Qt::blue);

    barra23=new QGraphicsRectItem(0,748,810,5);
    scene->addItem(barra23);
    barra23->setBrush(Qt::blue);

    barra24=new QGraphicsRectItem(797,645,5,93);
    scene->addItem(barra24);
    barra24->setBrush(Qt::blue);

    barra25=new QGraphicsRectItem(805,512,5,236);
    scene->addItem(barra25);
    barra25->setBrush(Qt::blue);

    barra26=new QGraphicsRectItem(797,522,5,93);
    scene->addItem(barra26);
    barra26->setBrush(Qt::blue);

    barra27=new QGraphicsRectItem(647,522,150,5);
    scene->addItem(barra27);
    barra27->setBrush(Qt::blue);

    barra28=new QGraphicsRectItem(655,512,150,5);
    scene->addItem(barra28);
    barra28->setBrush(Qt::blue);

    barra29=new QGraphicsRectItem(647,409,5,118);
    scene->addItem(barra29);
    barra29->setBrush(Qt::blue);

    barra30=new QGraphicsRectItem(655,419,5,98);
    scene->addItem(barra30);
    barra30->setBrush(Qt::blue);

    barra31=new QGraphicsRectItem(647,404,165,5);
    scene->addItem(barra31);
    barra31->setBrush(Qt::blue);

    barra31=new QGraphicsRectItem(655,414,157,5);
    scene->addItem(barra31);
    barra31->setBrush(Qt::blue);

    barra32=new QGraphicsRectItem(647,344,165,5);
    scene->addItem(barra32);
    barra32->setBrush(Qt::blue);

    barra33=new QGraphicsRectItem(655,334,155,5);
    scene->addItem(barra33);
    barra33->setBrush(Qt::blue);

    barra34=new QGraphicsRectItem(647,226,5,118);
    scene->addItem(barra34);
    barra34->setBrush(Qt::blue);

    barra35=new QGraphicsRectItem(655,236,5,98);
    scene->addItem(barra35);
    barra35->setBrush(Qt::blue);

    barra36=new QGraphicsRectItem(647,226,150,5);
    scene->addItem(barra36);
    barra36->setBrush(Qt::blue);

    barra37=new QGraphicsRectItem(655,236,150,5);
    scene->addItem(barra37);
    barra37->setBrush(Qt::blue);

    barra38=new QGraphicsRectItem(797,15,5,216);
    scene->addItem(barra38);
    barra38->setBrush(Qt::blue);

    barra39=new QGraphicsRectItem(805,5,5,236);
    scene->addItem(barra39);
    barra39->setBrush(Qt::blue);

    barra40=new QGraphicsRectItem(10,610,54,5);
    scene->addItem(barra40);
    barra40->setBrush(Qt::blue);

    barra41=new QGraphicsRectItem(10,645,54,5);
    scene->addItem(barra41);
    barra41->setBrush(Qt::blue);

    barra42=new QGraphicsRectItem(64,610,5,40);
    scene->addItem(barra42);
    barra42->setBrush(Qt::blue);

    barra43=new QGraphicsRectItem(743,610,54,5);
    scene->addItem(barra43);
    barra43->setBrush(Qt::blue);

    barra44=new QGraphicsRectItem(743,645,54,5);
    scene->addItem(barra44);
    barra44->setBrush(Qt::blue);

    barra45=new QGraphicsRectItem(743,610,5,40);
    scene->addItem(barra45);
    barra45->setBrush(Qt::blue);



    //Parte de adentro del mapa


    barra46=new QGraphicsRectItem(55,45,120,5);
    scene->addItem(barra46);
    barra46->setBrush(Qt::blue);

    barra47=new QGraphicsRectItem(55,105,120,5);
    scene->addItem(barra47);
    barra47->setBrush(Qt::blue);

    barra48=new QGraphicsRectItem(55,145,120,5);
    scene->addItem(barra48);
    barra48->setBrush(Qt::blue);

    barra49=new QGraphicsRectItem(55,175,120,5);
    scene->addItem(barra49);
    barra49->setBrush(Qt::blue);

    barra50=new QGraphicsRectItem(55,45,5,60);
    scene->addItem(barra50);
    barra50->setBrush(Qt::blue);

    barra51=new QGraphicsRectItem(175,45,5,65);
    scene->addItem(barra51);
    barra51->setBrush(Qt::blue);

    barra52=new QGraphicsRectItem(175,145,5,35);
    scene->addItem(barra52);
    barra52->setBrush(Qt::blue);

    barra53=new QGraphicsRectItem(55,150,5,30);
    scene->addItem(barra53);
    barra53->setBrush(Qt::blue);

    barra54=new QGraphicsRectItem(225,45,125,5);
    scene->addItem(barra54);
    barra54->setBrush(Qt::blue);

    barra55=new QGraphicsRectItem(225,105,125,5);
    scene->addItem(barra55);
    barra55->setBrush(Qt::blue);

    barra55=new QGraphicsRectItem(225,45,5,60);
    scene->addItem(barra55);
    barra55->setBrush(Qt::blue);

    barra56=new QGraphicsRectItem(350,45,5,65);
    scene->addItem(barra56);
    barra56->setBrush(Qt::blue);



    barra57=new QGraphicsRectItem(465,45,125,5);
    scene->addItem(barra57);
    barra57->setBrush(Qt::blue);

    barra58=new QGraphicsRectItem(465,105,125,5);
    scene->addItem(barra58);
    barra58->setBrush(Qt::blue);

    barra59=new QGraphicsRectItem(465,45,5,60);
    scene->addItem(barra59);
    barra59->setBrush(Qt::blue);

    barra60=new QGraphicsRectItem(590,45,5,65);
    scene->addItem(barra60);
    barra60->setBrush(Qt::blue);


    barra61=new QGraphicsRectItem(640,45,120,5);
    scene->addItem(barra61);
    barra61->setBrush(Qt::blue);

    barra62=new QGraphicsRectItem(640,105,120,5);
    scene->addItem(barra62);
    barra62->setBrush(Qt::blue);

    barra63=new QGraphicsRectItem(640,145,120,5);
    scene->addItem(barra63);
    barra63->setBrush(Qt::blue);

    barra64=new QGraphicsRectItem(640,175,120,5);
    scene->addItem(barra64);
    barra64->setBrush(Qt::blue);

    barra65=new QGraphicsRectItem(640,45,5,60);
    scene->addItem(barra65);
    barra65->setBrush(Qt::blue);

    barra66=new QGraphicsRectItem(760,45,5,65);
    scene->addItem(barra66);
    barra66->setBrush(Qt::blue);

    barra67=new QGraphicsRectItem(760,145,5,35);
    scene->addItem(barra67);
    barra67->setBrush(Qt::blue);

    barra68=new QGraphicsRectItem(640,150,5,30);
    scene->addItem(barra68);
    barra68->setBrush(Qt::blue);


    //Empiezan las T superiores


    barra69=new QGraphicsRectItem(340,170,135,5);
    scene->addItem(barra69);
    barra69->setBrush(Qt::blue);

    barra70=new QGraphicsRectItem(340,170,5,30);
    scene->addItem(barra70);
    barra70->setBrush(Qt::blue);

    barra71=new QGraphicsRectItem(475,170,5,30);
    scene->addItem(barra71);
    barra71->setBrush(Qt::blue);

    barra72=new QGraphicsRectItem(340,200,50,5);
    scene->addItem(barra72);
    barra72->setBrush(Qt::blue);

    barra73=new QGraphicsRectItem(425,200,50,5);
    scene->addItem(barra73);
    barra73->setBrush(Qt::blue);

    barra74=new QGraphicsRectItem(390,200,5,60);
    scene->addItem(barra74);
    barra74->setBrush(Qt::blue);

    barra75=new QGraphicsRectItem(425,200,5,60);
    scene->addItem(barra75);
    barra75->setBrush(Qt::blue);

    barra76=new QGraphicsRectItem(390,260,35,5);
    scene->addItem(barra76);
    barra76->setBrush(Qt::blue);





    barra77=new QGraphicsRectItem(225,170,5,180);
    scene->addItem(barra77);
    barra77->setBrush(Qt::blue);

    barra78=new QGraphicsRectItem(225,170,35,5);
    scene->addItem(barra78);
    barra78->setBrush(Qt::blue);

    barra79=new QGraphicsRectItem(225,350,35,5);
    scene->addItem(barra79);
    barra79->setBrush(Qt::blue);

    barra80=new QGraphicsRectItem(255,170,5,70);
    scene->addItem(barra80);
    barra80->setBrush(Qt::blue);

    barra81=new QGraphicsRectItem(255,280,5,70);
    scene->addItem(barra81);
    barra81->setBrush(Qt::blue);

    barra82=new QGraphicsRectItem(255,240,90,5);
    scene->addItem(barra82);
    barra82->setBrush(Qt::blue);

    barra83=new QGraphicsRectItem(255,280,90,5);
    scene->addItem(barra83);
    barra83->setBrush(Qt::blue);

    barra84=new QGraphicsRectItem(345,240,5,45);
    scene->addItem(barra84);
    barra84->setBrush(Qt::blue);


    //Jaula pacman


    barra85=new QGraphicsRectItem(340,330,40,5);
    scene->addItem(barra85);
    barra85->setBrush(Qt::blue);

    barra86=new QGraphicsRectItem(350,340,30,5);
    scene->addItem(barra86);
    barra86->setBrush(Qt::blue);

    barra87=new QGraphicsRectItem(340,330,5,90);
    scene->addItem(barra87);
    barra87->setBrush(Qt::blue);

    barra88=new QGraphicsRectItem(350,340,5,70);
    scene->addItem(barra88);
    barra88->setBrush(Qt::blue);

    barra89=new QGraphicsRectItem(340,420,135,5);
    scene->addItem(barra89);
    barra89->setBrush(Qt::blue);

    barra90=new QGraphicsRectItem(350,410,115,5);
    scene->addItem(barra90);
    barra90->setBrush(Qt::blue);

    barra91=new QGraphicsRectItem(475,330,5,95);
    scene->addItem(barra91);
    barra91->setBrush(Qt::blue);

    barra92=new QGraphicsRectItem(465,340,5,75);
    scene->addItem(barra92);
    barra92->setBrush(Qt::blue);

    barra93=new QGraphicsRectItem(435,330,40,5);
    scene->addItem(barra93);
    barra93->setBrush(Qt::blue);

    barra94=new QGraphicsRectItem(435,340,30,5);
    scene->addItem(barra94);
    barra94->setBrush(Qt::blue);






    barra95=new QGraphicsRectItem(590,170,5,180);
    scene->addItem(barra95);
    barra95->setBrush(Qt::blue);

    barra96=new QGraphicsRectItem(555,170,35,5);
    scene->addItem(barra96);
    barra96->setBrush(Qt::blue);

    barra97=new QGraphicsRectItem(555,350,35,5);
    scene->addItem(barra97);
    barra97->setBrush(Qt::blue);

    barra98=new QGraphicsRectItem(555,170,5,70);
    scene->addItem(barra98);
    barra98->setBrush(Qt::blue);

    barra99=new QGraphicsRectItem(555,280,5,70);
    scene->addItem(barra99);
    barra99->setBrush(Qt::blue);

    barra100=new QGraphicsRectItem(465,240,90,5);
    scene->addItem(barra100);
    barra100->setBrush(Qt::blue);

    barra101=new QGraphicsRectItem(465,280,90,5);
    scene->addItem(barra101);
    barra101->setBrush(Qt::blue);

    barra102=new QGraphicsRectItem(465,240,5,45);
    scene->addItem(barra102);
    barra102->setBrush(Qt::blue);





    barra103=new QGraphicsRectItem(225,404,5,123);
    scene->addItem(barra103);
    barra103->setBrush(Qt::blue);

    barra104=new QGraphicsRectItem(225,404,35,5);
    scene->addItem(barra104);
    barra104->setBrush(Qt::blue);

    barra105=new QGraphicsRectItem(225,522,35,5);
    scene->addItem(barra105);
    barra105->setBrush(Qt::blue);

    barra106=new QGraphicsRectItem(260,404,5,123);
    scene->addItem(barra106);
    barra106->setBrush(Qt::blue);




    barra107=new QGraphicsRectItem(555,404,5,123);
    scene->addItem(barra107);
    barra107->setBrush(Qt::blue);

    barra108=new QGraphicsRectItem(555,404,35,5);
    scene->addItem(barra108);
    barra108->setBrush(Qt::blue);

    barra109=new QGraphicsRectItem(555,522,35,5);
    scene->addItem(barra109);
    barra109->setBrush(Qt::blue);

    barra110=new QGraphicsRectItem(590,404,5,123);
    scene->addItem(barra110);
    barra110->setBrush(Qt::blue);


    //Empiezan T inferiores


    barra111=new QGraphicsRectItem(340,487,135,5);
    scene->addItem(barra111);
    barra111->setBrush(Qt::blue);

    barra112=new QGraphicsRectItem(340,487,5,35);
    scene->addItem(barra112);
    barra112->setBrush(Qt::blue);

    barra113=new QGraphicsRectItem(475,487,5,35);
    scene->addItem(barra113);
    barra113->setBrush(Qt::blue);

    barra114=new QGraphicsRectItem(340,522,50,5);
    scene->addItem(barra114);
    barra114->setBrush(Qt::blue);

    barra115=new QGraphicsRectItem(425,522,50,5);
    scene->addItem(barra115);
    barra115->setBrush(Qt::blue);

    barra116=new QGraphicsRectItem(390,522,5,60);
    scene->addItem(barra116);
    barra116->setBrush(Qt::blue);

    barra117=new QGraphicsRectItem(425,522,5,60);
    scene->addItem(barra117);
    barra117->setBrush(Qt::blue);

    barra118=new QGraphicsRectItem(390,582,35,5);
    scene->addItem(barra118);
    barra118->setBrush(Qt::blue);





    barra119=new QGraphicsRectItem(225,605,123,5);
    scene->addItem(barra119);
    barra119->setBrush(Qt::blue);

    barra120=new QGraphicsRectItem(225,570,123,5);
    scene->addItem(barra120);
    barra120->setBrush(Qt::blue);

    barra121=new QGraphicsRectItem(225,570,5,35);
    scene->addItem(barra121);
    barra121->setBrush(Qt::blue);

    barra122=new QGraphicsRectItem(348,570,5,35);
    scene->addItem(barra122);
    barra122->setBrush(Qt::blue);





    barra124=new QGraphicsRectItem(467,570,123,5);
    scene->addItem(barra124);
    barra124->setBrush(Qt::blue);

    barra125=new QGraphicsRectItem(467,605,123,5);
    scene->addItem(barra125);
    barra125->setBrush(Qt::blue);

    barra126=new QGraphicsRectItem(467,570,5,35);
    scene->addItem(barra126);
    barra126->setBrush(Qt::blue);

    barra127=new QGraphicsRectItem(590,570,5,35);
    scene->addItem(barra127);
    barra127->setBrush(Qt::blue);





    barra128=new QGraphicsRectItem(55,555,100,5);
    scene->addItem(barra128);
    barra128->setBrush(Qt::blue);

    barra129=new QGraphicsRectItem(55,555,5,20);
    scene->addItem(barra129);
    barra129->setBrush(Qt::blue);

    barra130=new QGraphicsRectItem(55,575,80,5);
    scene->addItem(barra130);
    barra130->setBrush(Qt::blue);

    barra131=new QGraphicsRectItem(135,575,5,75);
    scene->addItem(barra131);
    barra131->setBrush(Qt::blue);

    barra132=new QGraphicsRectItem(155,555,5,100);
    scene->addItem(barra132);
    barra132->setBrush(Qt::blue);

    barra133=new QGraphicsRectItem(135,650,20,5);
    scene->addItem(barra133);
    barra133->setBrush(Qt::blue);



    barra134=new QGraphicsRectItem(645,555,100,5);
    scene->addItem(barra134);
    barra134->setBrush(Qt::blue);

    barra135=new QGraphicsRectItem(645,555,5,90);
    scene->addItem(barra135);
    barra135->setBrush(Qt::blue);

    barra136=new QGraphicsRectItem(645,645,20,5);
    scene->addItem(barra136);
    barra136->setBrush(Qt::blue);

    barra137=new QGraphicsRectItem(745,555,5,20);
    scene->addItem(barra137);
    barra137->setBrush(Qt::blue);

    barra138=new QGraphicsRectItem(665,570,80,5);
    scene->addItem(barra138);
    barra138->setBrush(Qt::blue);

    barra139=new QGraphicsRectItem(665,570,5,80);
    scene->addItem(barra139);
    barra139->setBrush(Qt::blue);





    barra140=new QGraphicsRectItem(340,635,135,5);
    scene->addItem(barra140);
    barra140->setBrush(Qt::blue);

    barra141=new QGraphicsRectItem(340,635,5,15);
    scene->addItem(barra141);
    barra141->setBrush(Qt::blue);

    barra142=new QGraphicsRectItem(475,635,5,15);
    scene->addItem(barra142);
    barra142->setBrush(Qt::blue);

    barra143=new QGraphicsRectItem(340,645,50,5);
    scene->addItem(barra143);
    barra143->setBrush(Qt::blue);

    barra144=new QGraphicsRectItem(425,645,50,5);
    scene->addItem(barra144);
    barra144->setBrush(Qt::blue);

    barra145=new QGraphicsRectItem(390,645,5,60);
    scene->addItem(barra145);
    barra145->setBrush(Qt::blue);

    barra146=new QGraphicsRectItem(425,645,5,60);
    scene->addItem(barra146);
    barra146->setBrush(Qt::blue);

    barra147=new QGraphicsRectItem(390,705,35,5);
    scene->addItem(barra147);
    barra147->setBrush(Qt::blue);






    barra148=new QGraphicsRectItem(465,705,300,5);
    scene->addItem(barra148);
    barra148->setBrush(Qt::blue);

    barra149=new QGraphicsRectItem(465,680,5,25);
    scene->addItem(barra149);
    barra149->setBrush(Qt::blue);

    barra150=new QGraphicsRectItem(595,680,170,5);
    scene->addItem(barra150);
    barra150->setBrush(Qt::blue);

    barra151=new QGraphicsRectItem(565,640,5,45);
    scene->addItem(barra151);
    barra151->setBrush(Qt::blue);

    barra152=new QGraphicsRectItem(565,640,30,5);
    scene->addItem(barra152);
    barra152->setBrush(Qt::blue);

    barra153=new QGraphicsRectItem(465,680,100,5);
    scene->addItem(barra153);
    barra153->setBrush(Qt::blue);

    barra154=new QGraphicsRectItem(595,640,5,45);
    scene->addItem(barra154);
    barra154->setBrush(Qt::blue);

    barra155=new QGraphicsRectItem(765,680,5,30);
    scene->addItem(barra155);
    barra155->setBrush(Qt::blue);







    barra156=new QGraphicsRectItem(55,705,300,5);
    scene->addItem(barra156);
    barra156->setBrush(Qt::blue);

    barra157=new QGraphicsRectItem(55,680,5,25);
    scene->addItem(barra157);
    barra157->setBrush(Qt::blue);

    barra158=new QGraphicsRectItem(55,680,170,5);
    scene->addItem(barra158);
    barra158->setBrush(Qt::blue);

    barra159=new QGraphicsRectItem(225,640,5,45);
    scene->addItem(barra159);
    barra159->setBrush(Qt::blue);

    barra160=new QGraphicsRectItem(225,640,30,5);
    scene->addItem(barra160);
    barra160->setBrush(Qt::blue);

    barra161=new QGraphicsRectItem(255,680,100,5);
    scene->addItem(barra161);
    barra161->setBrush(Qt::blue);

    barra162=new QGraphicsRectItem(255,640,5,45);
    scene->addItem(barra162);
    barra162->setBrush(Qt::blue);

    barra163=new QGraphicsRectItem(355,680,5,30);
    scene->addItem(barra163);
    barra163->setBrush(Qt::blue);


/*
    QGraphicsRectItem* vector[162]={barra,barra2,barra3,barra4,barra5,barra6,barra7,barra8,barra9,barra10,barra11,barra12,barra13,barra14,barra15,barra16,barra17,barra18,barra19,barra20,
                barra21,barra22,barra23,barra24,barra25,barra26,barra27,barra28,barra29,barra30,barra31,barra32,barra33,barra34,barra35,barra36,barra37,barra38,barra39,
                barra40,barra41,barra42,barra43,barra44,barra45,barra46,barra47,barra48,barra49,barra50,barra51,barra52,barra53,barra54,barra55,barra56,barra57,barra58,
                barra59,barra60,barra61,barra62,barra63,barra64,barra65,barra66,barra67,barra68,barra69,barra70,barra71,barra72,barra73,barra74,barra75,barra76,barra77,
                barra78,barra79,barra80,barra81,barra82,barra83,barra84,barra85,barra86,barra87,barra88,barra89,barra90,barra91,barra92,barra93,barra94,barra95,barra96,
                barra97,barra98,barra99,barra100,barra101,barra102,barra103,barra104,barra105,barra106,barra107,barra108,barra109,barra110,barra111,barra112,barra113,
                barra114,barra115,barra116,barra117,barra118,barra119,barra120,barra121,barra122,barra124,barra125,barra126,barra127,barra128,barra129,barra130,
                barra131,barra132,barra133,barra134,barra135,barra136,barra137,barra138,barra139,barra140,barra141,barra142,barra143,barra144,barra145,barra146,barra147,barra148,
                barra149,barra150,barra151,barra152,barra153,barra154,barra155,barra156,barra157,barra158,barra159,barra160,barra161,barra162,barra163};
*/










    //l4=new QGraphicsLineItem(-100,400,500,400);
    //scene->addItem(l1);
    //scene->addItem(l2);
    //scene->addItem(l3);
    //scene->addItem(l4);

    //miesfera* vectorBolas[240];

    for(int i=0; i<12; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(30+30*i,25);

    }

    for(int i=12; i<18; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(30,25+30+30*(i-12));

    }

    for(int i=18; i<30; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(30+30+28*(i-18),120);

    }

    for(int i=30; i<43; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(200,25+30+26*(i-30));

    }

    for(int i=43; i<47; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(30+30+33*(i-43),200);

    }

    for(int i=47; i<50; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(280,120+30+30*(i-47));

    }

    for(int i=50; i<53; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(280+30+30*(i-50),210);

    }

    for(int i=53; i<56; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(369,30+30+30*(i-53));

    }


    //Lado derecho Bolitas




    for(int i=56; i<68; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(770-30*(i-56),25);

    }

    for(int i=68; i<74; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(770,25+30+30*(i-68));

    }

    for(int i=74; i<86; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(740-28*(i-74),120);

    }

    for(int i=86; i<99; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(600,25+30+26*(i-86));

    }

    for(int i=99; i<103; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(740-33*(i-99),200);

    }

    for(int i=103; i<106; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(520,120+30+30*(i-103));

    }

    for(int i=106; i<109; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(490-30*(i-106),210);

    }

    for(int i=109; i<112; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(431,30+30+30*(i-109));

    }



    //Bolitas inferior izquierda

    for(int i=112; i<122; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(200,400+28*(i-112));

    }

    for(int i=122; i<133; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(30+34*(i-122),540);

    }

    for(int i=133; i<136; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(30,540+30*(i-133));

    }

    for(int i=136; i<138; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(60+30*(i-136),600);

    }

    for(int i=138; i<141; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(90,600+20+20*(i-138));

    }

    for(int i=141; i<147; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(30+30*(i-141),660);

    }

    for(int i=147; i<150; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(30,660+30*(i-147));

    }

    for(int i=150; i<153; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(370,560+30*(i-150));

    }

    for(int i=153; i<158; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(230+30*(i-153),620);

    }

    for(int i=158; i<160; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(260,640+20*(i-158));

    }

    for(int i=160; i<164; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(290+25*(i-160),660);

    }

    for(int i=164; i<166; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(365,690+30*(i-164));

    }

    for(int i=166; i<178; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(65+30*(i-166),720);

    }



    //bolitas inferior derecha

    for(int i=178; i<188; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(600,400+28*(i-178));

    }

    for(int i=188; i<199; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(770-34*(i-188),540);

    }

    for(int i=199; i<202; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(770,540+30*(i-199));

    }

    for(int i=202; i<204; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(740-30*(i-202),600);

    }

    for(int i=204; i<207; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(710,600+20+20*(i-204));

    }

    for(int i=207; i<213; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(770-30*(i-207),660);

    }

    for(int i=213; i<226; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(770,660+30*(i-213));

    }

    for(int i=226; i<229; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(430,560+30*(i-226));

    }

    for(int i=229; i<234; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(570-30*(i-229),620);

    }

    for(int i=234; i<236; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(540,640+20*(i-234));

    }

    for(int i=236; i<240; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(510-25*(i-236),660);

    }

    for(int i=240; i<242; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(435,690+30*(i-240));

    }

    for(int i=242; i<254; i++){

        vectorBolas[i] = new miesfera();
        scene->addItem(vectorBolas[i]);
        vectorBolas[i]->setPos(735-30*(i-242),720);

    }


    //Puntuación


}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}


void MainWindow::animar()
{

    bool mover=1;

    QGraphicsRectItem* vector[162]={barra,barra2,barra3,barra4,barra5,barra6,barra7,barra8,barra9,barra10,barra11,barra12,barra13,barra14,barra15,barra16,barra17,barra18,barra19,barra20,
                barra21,barra22,barra23,barra24,barra25,barra26,barra27,barra28,barra29,barra30,barra31,barra32,barra33,barra34,barra35,barra36,barra37,barra38,barra39,
                barra40,barra41,barra42,barra43,barra44,barra45,barra46,barra47,barra48,barra49,barra50,barra51,barra52,barra53,barra54,barra55,barra56,barra57,barra58,
                barra59,barra60,barra61,barra62,barra63,barra64,barra65,barra66,barra67,barra68,barra69,barra70,barra71,barra72,barra73,barra74,barra75,barra76,barra77,
                barra78,barra79,barra80,barra81,barra82,barra83,barra84,barra85,barra86,barra87,barra88,barra89,barra90,barra91,barra92,barra93,barra94,barra95,barra96,
                barra97,barra98,barra99,barra100,barra101,barra102,barra103,barra104,barra105,barra106,barra107,barra108,barra109,barra110,barra111,barra112,barra113,
                barra114,barra115,barra116,barra117,barra118,barra119,barra120,barra121,barra122,barra124,barra125,barra126,barra127,barra128,barra129,barra130,
                barra131,barra132,barra133,barra134,barra135,barra136,barra137,barra138,barra139,barra140,barra141,barra142,barra143,barra144,barra145,barra146,barra147,barra148,
                barra149,barra150,barra151,barra152,barra153,barra154,barra155,barra156,barra157,barra158,barra159,barra160,barra161,barra162,barra163};



    /*if(->collidesWithItem(barra3))
    {
        moverIx1=false;
        moverDy1=false;
        moverUy1=false;
        moverDx1=false;
        if(bola->isVisible()){
            bola->hide();
            //delete bola;
        }
     }*/
    if(moverIx1)
    {
        for(int i=0; i<162; i++){
            if(pcm->collidesWithItem(vector[i])){
                pcm->setPos(pcm->x()+2,pcm->y());
                mover=0;
            }
        }
        if(mover==1){
            pcm->setPos(pcm->x()-2,pcm->y());
            pcm->filas=300;
        }
    }
    if(moverDx1)
    {
        for(int i=0; i<162; i++){
            if(pcm->collidesWithItem(vector[i])){
                pcm->setPos(pcm->x()-2,pcm->y());
                mover=0;
            }

        }
        if(mover==1){
            pcm->setPos(pcm->x()+2,pcm->y());
            pcm->filas=0;
        }
    }
    if(moverUy1)
    {
        for(int i=0; i<162; i++){
            if(pcm->collidesWithItem(vector[i])){
                pcm->setPos(pcm->x(),pcm->y()+2);
                mover=0;
            }
        }
        if(mover==1){
            pcm->setPos(pcm->x(),pcm->y()-2);
            pcm->filas=100;
        }
    }
    if(moverDy1)
    {
        for(int i=0; i<162; i++){
            if(pcm->collidesWithItem(vector[i])){
                pcm->setPos(pcm->x(),pcm->y()-2);
                mover=0;
            }
        }
        if(mover==1){
            pcm->setPos(pcm->x(),pcm->y()+2);
            pcm->filas=200;
        }
    }

    for(int i=0; i<254; i++){
    if(pcm->collidesWithItem(vectorBolas[i]))
        {
            if(vectorBolas[i]->isVisible()){
                vectorBolas[i]->hide();
                aumentarPunt();
                //delete bola;
            }

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
/*void MainWindow::imprimirMatriz()
{
    for (int i = 0; i<2; i++)
    {
        for (int j = 0; j<40; j++);
        {
            if(matriz[i][j]==0)
            {
                cout<<" ";

            }
            if (matriz[i][j]==1)
            {
               scene->addItem(barra);
               barra->setPos(i,j);
            }
        }
    }
}*/

/*void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setBrush(Qt::darkBlue);

    painter.drawRect(QRect(10,50,100,10));
}*/

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
