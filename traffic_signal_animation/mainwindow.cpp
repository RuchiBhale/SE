#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTime>
#include <string>


QImage img(1300,1300,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dda(int x1,int y1,int x2,int y2,QRgb value){
    float dy,dx,xinc,yinc,step,x,y;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy))
        step=abs(dx);
    else
        step=abs(dy);
    xinc=dx/step;
    yinc=dy/step;
    x=x1;
    y=y1;
    for(int i=0;i<step;i++){
        img.setPixel(x,y,value);
         x=x+xinc;
         y=y+yinc;

    }
}
void MainWindow::circle(int xc, int yc, int rad, QRgb value){
    int x=0, y=rad;
    int d = 3 - 2*rad;


        while(x<=y){
            img.setPixel(xc + x, yc + y, value);
            img.setPixel(xc - x, yc + y, value);
            img.setPixel(xc + x, yc - y, value);
            img.setPixel(xc - x, yc - y, value);
            img.setPixel(xc + y, yc + x, value);
            img.setPixel(xc - y, yc + x, value);
            img.setPixel(xc + y, yc - x, value);
            img.setPixel(xc - y, yc - x, value);

            if(d<0)
                d += 4*x+6;
            else{
                d += 4*(x-y)+10;
                y --;
            }
            x ++;

        }
    }
void MainWindow::Scanline(int x1[],int y1[],QRgb value)
{

  //int x1[] = {100,300,300,100,100};
  //int y1[] = {200,200,600,600,200};
  int i = 0;
  int n = 4;
  int ymin = 700;
  int ymax = 0;
  int c,j,y;
  float m[50],a[50],dx,dy,t; // a[] used to store x coordinates of intersection points

// Storing slopes of all the lines and also ymin and ymax

  for(i=0;i<n;i++)
  {
        if(y1[i]>=ymax)
        {
            ymax = y1[i];
        }
        if(y1[i]<=ymin)
        {
            ymin = y1[i];
        }
        dx = x1[i+1]-x1[i];
        dy = y1[i+1]-y1[i];
        if(dx==0)
        {
            m[i] = 0;
        }
        if(dy==0)
        {
            m[i] = 1;
        }
        if(dx!=0 and dy!=0)
        {
            m[i] = dx/dy;
        }

  }


  for(y = ymax;y>=ymin;y--)
  {

      // Starting from Ymax and going all the way to Ymin


      c = 0;
      for(i=0;i<n;i++)
      {
          if((y1[i]>y and y1[i+1]<=y) or (y1[i]<=y && y1[i+1]>y))
          {

              // x2 = x1 + (y2-y1)/m

              a[c]=x1[i]+(m[i]*(y-y1[i]));
              c++;
          }
      }

     // Bubble sorting all the X coordinates of intersection of Scan Line at y

     for(i=0;i<c-1;i++)
     {
       for(j=0;j<c-1;j++)
       {
           if(a[j]>a[j+1])
           {
               t=a[j];
               a[j]=a[j+1];
               a[j+1]=t;
           }
       }
     }

     // Filling in between alternate pairs of coordinates

     for(i=0;i<c-1;i=i+2)
     {
         dda(a[i],y,a[i+1],y,value);
         ui->label->setPixmap(QPixmap::fromImage(img));

     }

  }
}

void delay(int n)
{
    QTime dieTime= QTime::currentTime().addMSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void MainWindow::translation(int t)
{   int ty=0;
    //int a[5]={700,900,900,700,700};
    //int b[5]={500,500,600,600,500};
    int a[7]={800,800,900,925,1200,1200,800};
    int b[7]={750,650,650,550,550,750,750};

        for (int i = 1; i <= 6; i++)
        { int x1=a[i],y1=b[i];
          int x2=a[i-1],y2=b[i-1];
          x1=x1+t;y1=y1+ty;x2=x2+t;y2=y2+ty;
          dda(x1,y1,x2,y2,qRgb(128,0,0));
}
}


void MainWindow::translationb(int t)
{   int ty=0;
//    int a[5]={700,900,900,700,700};
//        int b[5]={500,500,600,600,500};
    int a[7]={800,800,900,925,1200,1200,800};
    int b[7]={750,650,650,550,550,750,750};
        for (int i = 1; i <= 6; i++)
        { int x1=a[i],y1=b[i];
          int x2=a[i-1],y2=b[i-1];
          x1=x1+t;y1=y1+ty;x2=x2+t;y2=y2+ty;
          dda(x1,y1,x2,y2,qRgb(30,139,195));

}
}


void MainWindow::on_pushButton_clicked()//traffic shoes initial situation
{   int xw1[]={0,1300,1300,0,0};
    int yw1[]={800,800,0,0,800};
    Scanline(xw1,yw1,qRgb(30,139,195));
    int xw2[]={0,1300,1300,0,0};
    int yw2[]={800,800,1300,1300,800};
    Scanline(xw2,yw2,qRgb(211,211,211));
    dda(100,200,300,200,qRgb(53,50,47));
    dda(300,200,300,600,qRgb(53,50,47));
    dda(300,600,100,600,qRgb(53,50,47));
    dda(100,600,100,200,qRgb(53,50,47));
    dda(200,600,200,800,qRgb(53,50,47));
    int x1[]={100,300,300,100,100};
    int y1[]={200,200,600,600,200};

    Scanline(x1,y1,qRgb(53,50,47));

        circle(200,275,50,qRgb(255,0,0));//redlight
        circle(200,400,50,qRgb(255,140,0));//yellow
        circle(200,525,50,qRgb(0,255,0));//green
        for(int i=0;i<=100;i++)
        {
        circle(675,200,i,qRgb(255,102,0));//sun
        }
        //sunrays
        dda(575,200,500,200,qRgb(255,102,0));
        dda(575,225,475,300,qRgb(255,102,0));
        dda(600,275,575,325,qRgb(255,102,0));
        dda(650,300,625,425,qRgb(255,102,0));
        dda(700,300,700,350,qRgb(255,102,0));
        dda(750,275,820,350,qRgb(255,102,0));
        dda(775,225,825,250,qRgb(255,102,0));
        dda(775,175,875,125,qRgb(255,102,0));
        dda(750,125,800,75,qRgb(255,102,0));
        dda(700,100,725,25,qRgb(255,102,0));
         dda(650,100,600,25,qRgb(255,102,0));
        dda(600,125,550,75,qRgb(255,102,0));
        dda(575,175,475,125,qRgb(255,102,0));
        dda(875,150,925,125,qRgb(0,0,0));
        dda(925,125,925,175,qRgb(0,0,0));
         dda(925,175,950,150,qRgb(0,0,0));
          dda(950,150,975,175,qRgb(0,0,0));
           dda(350,200,350,150,qRgb(0,0,0));
            dda(350,150,400,175,qRgb(0,0,0));
//             dda(350,200,925,175,qRgb(0,0,0));
              dda(400,175,400,125,qRgb(0,0,0));
               dda(400,125,425,155,qRgb(0,0,0));
//           dda(925,125,925,125,qRgb(0,0,0));

//        dda(575,125,425,100,qRgb(255,102,0));

//    dda(700,500,900,500,qRgb(0,0,255));
//    dda(900,500,900,600,qRgb(0,0,255));
//    dda(900,600,700,600,qRgb(0,0,255));
//    dda(700,600,700,500,qRgb(0,0,255));
      dda(100,800,1300,800,qRgb(255,255,255));
      dda(800,750,800,650,qRgb(128,0,0));
      dda(800,650,900,650,qRgb(128,0,0));
      dda(900,650,925,550,qRgb(128,0,0));
      dda(925,550,1200,550,qRgb(128,0,0));
      dda(1200,550,1200,750,qRgb(128,0,0));
      dda(1200,750,800,750,qRgb(128,0,0));
      for(int i=0;i<=50;i++){
          circle(900,750,i,qRgb(192,192,192));
          circle(1100,750,i,qRgb(192,192,192));
      }



    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->show();
}
void MainWindow::translate_circle(int t){
    for(int r=0;r<=50;r++){
        circle((900+t),750,r,qRgb(192,192,192));
        circle((1100+t),750,r,qRgb(192,192,192));
    }


}
void MainWindow::translateb_circle(int tb){
    for(int r=0;r<=50;r++){
        circle((900+tb),750,r,qRgb(30,139,195));
        circle((1100+tb),750,r,qRgb(30,139,195));
    }

}

void MainWindow::on_pushButton_2_clicked()
{

for(int r=0;r<50;r++){
    circle(200,275,r,qRgb(53,50,47));
    circle(200,400,r,qRgb(255,140,0));
    circle(200,525,r,qRgb(53,50,47));

}
delay(100);
ui->label->setPixmap(QPixmap::fromImage(img));
ui->label->show();

for(int r=0;r<50;r++){
    circle(200,400,r,qRgb(53,50,47));
    circle(200,525,r,qRgb(53,50,47));
    circle(200,275,r,qRgb(255,0,0));


}
delay(5000);
ui->label->setPixmap(QPixmap::fromImage(img));
ui->label->show();


for(int r=0;r<50;r++){
    circle(200,275,r,qRgb(53,50,47));
    circle(200,400,r,qRgb(53,50,47));
    circle(200,525,r,qRgb(0,255,0));

}
delay(5000);
ui->label->setPixmap(QPixmap::fromImage(img));
ui->label->show();


for(int i=-2;i>=-310;i-=2){
        dda(100,800,1300,800,qRgb(255,255,255));
        translationb(i+2);
        translation(i);
        translateb_circle(i+2);
        translate_circle(i);
        delay(50);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->show();
    }


//}

}



