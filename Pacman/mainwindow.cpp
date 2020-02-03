#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QRect>
#include <QPixmap>
#include <QMessageBox>
#include <QApplication>
#include <Qfile>
#include <QMediaPlayer>
#include "dialog.h"
#include "ui_dialog.h"
extern Dialog *d;

bool c;
bool keys[4];
int countL=0;
int countR=0;
int countU=0;
int countD=0;
int dirH=0;
int dirH1=0;
int dirH2=0;
int dirH3=0;
int dirV=0;
int dirV1=0;

QList<QLabel *> walls;
QList<QLabel *> food;
QList<QLabel *> enemies;

QTimer *timer = new QTimer(/*this*/);
QTimer *enemytimer = new QTimer(/*this*/);

QMediaPlayer *player = new QMediaPlayer();

bool collision(int x, int y, int width, int height);
bool enemyCollison(int x, int y, int width, int height);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->setupUi(this);
    //QTimer *timer = new QTimer(this);
   // QTimer *enemytimer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(myTimer()));
    timer->start(40);


//add walls into an array
    walls.append(ui->wall1);
    walls.append(ui->wall2);
    walls.append(ui->wall3);
    walls.append(ui->wall4);
    walls.append(ui->wall5);
    walls.append(ui->wall6);
    walls.append(ui->wall7);
    walls.append(ui->wall8);
    walls.append(ui->wall9);
    walls.append(ui->wall10);
    walls.append(ui->wall11);
    walls.append(ui->wall12);
    walls.append(ui->wall13);
    walls.append(ui->wall14);
    walls.append(ui->wall15);
    walls.append(ui->wall16);
    walls.append(ui->wall17);
    walls.append(ui->wall18);
    walls.append(ui->wall19);
    walls.append(ui->wall20);
    walls.append(ui->wall21);
    walls.append(ui->wall22);
    walls.append(ui->wall23);
    walls.append(ui->wall24);
    walls.append(ui->wall25);
    walls.append(ui->wall26);
    walls.append(ui->wall27);
    walls.append(ui->wall28);
    walls.append(ui->wall29);
    walls.append(ui->wall30);
    walls.append(ui->wall31);
    walls.append(ui->wall31);
    walls.append(ui->wall32);
    walls.append(ui->wall33);
    walls.append(ui->wall34);
    walls.append(ui->wall35);
    walls.append(ui->wall36);
    walls.append(ui->wall37);
    walls.append(ui->wall38);
    walls.append(ui->wall39);
    walls.append(ui->wall40);
    walls.append(ui->wall41);
    walls.append(ui->wall42);
    walls.append(ui->wall43);

    //add foods into an array
    food.append(ui->food1);
    food.append(ui->food2);
    food.append(ui->food3);
    food.append(ui->food4);
    food.append(ui->food5);
    food.append(ui->food6);
    food.append(ui->food7);
    food.append(ui->food8);
    food.append(ui->food9);
    food.append(ui->food10);
    food.append(ui->food11);
    food.append(ui->food12);
    food.append(ui->food13);
    food.append(ui->food14);
    food.append(ui->food15);
    food.append(ui->food17);
    food.append(ui->food18);
    food.append(ui->food19);
    food.append(ui->food20);
    food.append(ui->food21);
    food.append(ui->food22);
    food.append(ui->food23);
    food.append(ui->food24);
    food.append(ui->food25);
    food.append(ui->food26);
    food.append(ui->food27);
    food.append(ui->food28);
    food.append(ui->food29);
    food.append(ui->food30);
    food.append(ui->food31);
    food.append(ui->food32);
    food.append(ui->food33);
    food.append(ui->food34);
    food.append(ui->food35);
    food.append(ui->food36);
    food.append(ui->food37);
    food.append(ui->food38);
    food.append(ui->food39);
    food.append(ui->food40);
    food.append(ui->food41);

    //add enemies to the array
    enemies.append(ui->enemy1);
    enemies.append(ui->enemy2);
    enemies.append(ui->enemy3);
    enemies.append(ui->enemy4);
    enemies.append(ui->enemy5);
    enemies.append(ui->enemy6);
    connect(enemytimer, SIGNAL(timeout()), this, SLOT(enemyTimer()));
    enemytimer->start(40); //start enemy timer

    player->setMedia(QUrl::fromLocalFile(QApplication::applicationDirPath()+"//PacManTheme.mp3"));
    player->setVolume(50);
    player->play();

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent* event){
   // for(int c=0;c<4;c++)keys[c]=false;
    if (event->key()==Qt::Key_Left){keys[0]=true;keys[1]=false;keys[2]=false;keys[3]=false;}
    if (event->key()==Qt::Key_Right){keys[1]=true;keys[0]=false;keys[2]=false;keys[3]=false;}
    if (event->key()==Qt::Key_Up){keys[2]=true;keys[0]=false;keys[1]=false;keys[3]=false;}
    if (event->key()==Qt::Key_Down){keys[3]=true;keys[0]=false;keys[1]=false;keys[2]=false;}
}

void MainWindow::myTimer(){
    if(keys[0]){//left
    countL++;
    if(c==false){
    if(countL==1){
        ui->label->setPixmap(QPixmap(":/new/prefix1/left.jpg"));
}
else{
        ui->label->setPixmap(QPixmap(":/new/prefix1/pacman copy.jpg"));
        countL=0;
}
    }
    else  ui->label->setPixmap(QPixmap(":/new/prefix1/left.jpg"));

        if(ui->label->x()-5>=0 && !collision(ui->label->x()-5,ui->label->y(),ui->label->width(),ui->label->height())){
         ui->label->move(ui->label->x()-5,ui->label->y());
        }
    }
    if(keys[1]){//right
    countR++;
    if(c==false){
        if(countR==1){
        ui->label->setPixmap(QPixmap(":/new/prefix1/right.jpg"));
}
else{
        ui->label->setPixmap(QPixmap(":/new/prefix1/pacman copy.jpg"));
        countR=0;
}
    }
    else  ui->label->setPixmap(QPixmap(":/new/prefix1/right.jpg"));

        if(ui->label->x()+5<=450 && !collision(ui->label->x()+5,ui->label->y(),ui->label->width(),ui->label->height())){
         ui->label->move(ui->label->x()+5,ui->label->y());
        }

    }

    if(keys[2]){//up
    countU++;
        if(c==false){
        if (countU==1){
        ui->label->setPixmap(QPixmap(":/new/prefix1/up.jpg"));
}
        else{
            ui->label->setPixmap(QPixmap(":/new/prefix1/pacman copy.jpg"));
            countU=0;

}
   }
    else ui->label->setPixmap(QPixmap(":/new/prefix1/up.jpg"));

        if(ui->label->y()-5>=0 && !collision(ui->label->x(),ui->label->y()-5,ui->label->width(),ui->label->height())){
         ui->label->move(ui->label->x(),ui->label->y()-5);
        }
    }
    if(keys[3]){//down
    countD++;
        if(c==false){
        if (countD==1){
        ui->label->setPixmap(QPixmap(":/new/prefix1/down.jpg"));
}
        else{
            ui->label->setPixmap(QPixmap(":/new/prefix1/pacman copy.jpg"));
            countD=0;

        }
        }
        else ui->label->setPixmap(QPixmap(":/new/prefix1/down.jpg"));

        if(ui->label->y()+5<=380 && !collision(ui->label->x(),ui->label->y()+5,ui->label->width(),ui->label->height())){
         ui->label->move(ui->label->x(),ui->label->y()+5);
        }
    }
}

bool collision(int x, int y, int width, int height){
    bool hit=false;
    QRect r1(x,y,width,height),r2;

    for(int c=0;c<44;c++){
        r2.setX(walls.at(c)->x());
        r2.setY(walls.at(c)->y());
        r2.setWidth(walls.at(c)->width());
        r2.setHeight(walls.at(c)->height());
        if(r1.intersects(r2))hit= true;
    }
    for(int c=0;c<40;c++){
        r2.setX(food.at(c)->x());
        r2.setY(food.at(c)->y());
        r2.setWidth(food.at(c)->width());
        r2.setHeight(food.at(c)->height());
        if(r1.intersects(r2) && food.at(c)->isVisible() ){
            food.at(c)->setVisible(false);
           /* player->setMedia(QUrl::fromLocalFile(QApplication::applicationDirPath()+"//pacman_eatfruit.wave"));
            player->setVolume(50);
            player->play();*/
        }

    }
    if (hit==true){
        c=true;
    }
    else c=false;
    return hit;
}

void MainWindow::enemyTimer(){
    //enemies
    //left to right
    //enemy1
     if(dirH==0){
         enemies.at(0)->move(enemies.at(0)->x()+5,enemies.at(0)->y());
         if(enemies.at(0)->x()>=440)dirH=1;
     }
     if(dirH==1){
          enemies.at(0)->move(enemies.at(0)->x()-5,enemies.at(0)->y());
         if(enemies.at(0)->x()<=30)dirH=0;
     }

     //enemy3
     if(dirH1==0){
         enemies.at(2)->move(enemies.at(2)->x()+5,enemies.at(2)->y());
         if(enemies.at(2)->x()>=320)dirH1=1;
     }
     if(dirH1==1){
          enemies.at(2)->move(enemies.at(2)->x()-5,enemies.at(2)->y());
         if(enemies.at(2)->x()<=141)dirH1=0;
     }
     //enemy5
     if(dirH2==0){
         enemies.at(4)->move(enemies.at(4)->x()+5,enemies.at(4)->y());
         if(enemies.at(4)->x()>=320)dirH2=1;
     }
     if(dirH2==1){
          enemies.at(4)->move(enemies.at(4)->x()-5,enemies.at(4)->y());
         if(enemies.at(4)->x()<=141)dirH2=0;
     }

     //enemy6
     if(dirH3==0){
         enemies.at(5)->move(enemies.at(5)->x()+5,enemies.at(5)->y());
         if(enemies.at(5)->x()>=440)dirH3=1;
     }
     if(dirH3==1){
          enemies.at(5)->move(enemies.at(5)->x()-5,enemies.at(5)->y());
         if(enemies.at(5)->x()<=30)dirH3=0;
     }


    //up and down
     //enemy2
     if(dirV==0){
         enemies.at(1)->move(enemies.at(1)->x(),enemies.at(1)->y()+5);
         if(enemies.at(1)->y()>=338)dirV=1;
     }
     if(dirV==1){
          enemies.at(1)->move(enemies.at(1)->x(),enemies.at(1)->y()-5);
         if(enemies.at(1)->y()<=15)dirV=0;
     }
    //enemy4
     if(dirV1==0){
         enemies.at(3)->move(enemies.at(3)->x(),enemies.at(3)->y()+5);
         if(enemies.at(3)->y()>=338)dirV1=1;

     }

     if(dirV1==1){
         enemies.at(3)->move(enemies.at(3)->x(),enemies.at(3)->y()-5);
        if(enemies.at(3)->y()<=15)dirV1=0;
     }
     //check for collision between enemy and player
     if(enemyCollison(ui->label->x(),ui->label->y(),ui->label->width(),ui->label->height())){

         QMessageBox::question(this, "Collision", "Game Over?",QMessageBox::Ok);
         enemytimer->stop();
         timer->stop();
         QApplication::quit();


     }
 }

/*void MainWindow::winner(){

}*/

bool enemyCollison(int x, int y, int width, int height){
    bool hit=false;
    QRect r1(x,y,width,height),r2;

    for(int c=0;c<6;c++){
        r2.setX(enemies.at(c)->x());
        r2.setY(enemies.at(c)->y());
        r2.setWidth(enemies.at(c)->width());
        r2.setHeight(enemies.at(c)->height());
        if(r1.intersects(r2))hit= true;
    }
    return hit;
}




