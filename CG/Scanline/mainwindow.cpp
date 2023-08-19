#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTime>
#include<QThread>
QImage img(1000,1000,QImage::Format_RGB888);
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

void MainWindow:: bresenhamAlg(int x0, int y0, int x1, int y1,QRgb value)
{

    int dx = abs (x1 - x0);
    int dy = abs (y1 - y0);
    int x, y;
    if (dx >= dy){

    int d = 2*dy-dx;
    int ds = 2*dy;
    int dt = 2*(dy-dx);
    if (x0 < x1)
    {
        x = x0;
        y = y0;
    }
    else
    {
        x = x1;
        y = y1;
        x1 = x0;
        y1 = y0;
    }
    img.setPixel(x, y, value);
    while (x < x1)
    {
    if (d < 0)
    d += ds;
    else {
    if (y < y1) {
        y++;
        d += dt;
    }
    else {
    y--;
    d += dt;
    }
}
    x++;
img.setPixel(x, y, value);
} }
    else {
        int d = 2*dx-dy;
        int ds = 2*dx;
        int dt = 2*(dx-dy);
    if (y0 < y1) {
        x = x0;
        y = y0;
    }
    else {
        x = x1;
        y = y1;
        y1 = y0;
        x1 = x0;
}
img.setPixel(x, y, value);
while (y < y1)
{
    if (d < 0)
    d += ds;
    else {
if (x > x1){
x--;
d += dt;
} else {
x++;
d += dt;

}
}
y++;
img.setPixel(x, y, value);
}
}
}

void MainWindow::polygon(){
    int xcor[]={300,300,475,625,600,300};
    int ycor[]={300,500,400,475,300,300};
    int n=5;
    int i=0;
    QRgb green;
    green = qRgb(0,255,0);
    for(i=0;i<n;i++){
        bresenhamAlg(xcor[i],ycor[i],xcor[i+1],ycor[i+1],green);
    }

}
void MainWindow::delay(int time){
    QTime dieTime = QTime::currentTime().addMSecs(time);
        while (QTime::currentTime() < dieTime)
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
}

void MainWindow::scanLineFill()
{
    int xcor[]={300,300,475,625,600,300};
    int ycor[]={300,500,400,475,300,300};
    int i=0;
    int n=5;
    int ymin=700;
    int ymax=0;
    QRgb green;
    green = qRgb(0,255,0);
    int c,j,y;
    float m[50],a[50],dx,dy,t;

    for(i=0;i<n;i++)
      {
            if(ycor[i]>=ymax)
            {
                ymax = ycor[i];
            }
            if(ycor[i]<=ymin)
            {
                ymin = ycor[i];
            }
            dx = xcor[i+1]-xcor[i];
            dy = ycor[i+1]-ycor[i];
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
          c = 0;
          for(i=0;i<n;i++)
          {
              if((ycor[i]>y and ycor[i+1]<=y) or (ycor[i]<=y && ycor[i+1]>y))
              {
                  a[c]=xcor[i]+(m[i]*(y-ycor[i]));
                  c++;
              }
          }

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
         if(y==400)
              {
                  QRgb red = qRgb(255,0,0);
                  bresenhamAlg(200,y,700,y,red);
              }


          for(i=0;i<c-1;i=i+2)
          {
              bresenhamAlg(a[i],y,a[i+1],y,green);
              delay(100);
              ui->label->setPixmap(QPixmap::fromImage(img));

          }



      }
    }

void MainWindow::on_pushButton_clicked()
{
    polygon();
    ui->label->setPixmap(QPixmap::fromImage(img));

}
void MainWindow::on_pushButton_2_clicked()
{
    scanLineFill();
    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_pushButton_3_clicked()
{

        QRgb red = qRgb(255,0,0);
        bresenhamAlg(200,400,700,400,red);

    ui->label->setPixmap(QPixmap::fromImage(img));
}
