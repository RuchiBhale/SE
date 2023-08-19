#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

QImage img(600,600,QImage::Format_RGB888);
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
void MainWindow::dda(int x1, int y1, int x2, int y2,QRgb value){

    float x_inc, y_inc, dx, dy, x, y;
    dx = x2-x1;
    dy = y2-y1;
    int len = abs(dx)>abs(dy)? abs(dx):abs(dy);
    x_inc = dx / len;
    y_inc = dy / len;
    x = x1;
    y = y1;
    for(int i=0; i<len; i++){
        img.setPixel(x, y,value);
        x += x_inc;
        y += y_inc;
    }
}
void MainWindow::iterate(int x1,int y1,int x2,int y2,int n)
{   /*int a=x1;int b=y1;int c=x2;int d=y2;
    int len=c-a;
    int part=len/3;

        int mid=a+part+(part/2);
        dda(a,b,(a+part),d,qRgb(255,0,0));
        dda((a+part),b,mid,(d-50),qRgb(255,0,0));
        dda(mid,(d-50),(c-part),d,qRgb(255,0,0));
        dda((c-part),d,c,d,qRgb(255,0,0));*/

    float theta=60;
    theta=theta*3.14/180;

   int x3 = (2*x1+x2)/3;
    int y3 = (2*y1+y2)/3;
    int x4 = (x1+2*x2)/3;
    int y4 = (y1+2*y2)/3;
    int x,y;
    x=x3+(x4-x3)*cos(theta)+(y4-y3)*sin(theta);
    y=y3-(x4-x3)*sin(theta)+(y4-y3)*cos(theta);
    if(n>0){
        iterate(x1,y1,x3,y3,n-1);
        iterate(x3,y3,x,y,n-1);
        iterate(x,y,x4,y4,n-1);
        iterate(x4,y4,x2,y2,n-1);
    }
    else{
    dda(x1,y1,x3,y3,qRgb(255,0,0));
    dda(x3,y3,x,y,qRgb(255,0,0));
    dda(x,y,x4,y4,qRgb(255,0,0));
    dda(x4,y4,x2,y2,qRgb(255,0,0));

}



    }






void MainWindow::on_pushButton_2_clicked()
{   int n=ui->textEdit->toPlainText().toInt();
    iterate(125,400,300,100,n);
    iterate(300,100,475,400,n);
    iterate(475,400,125,400,n);

    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->show();

}

