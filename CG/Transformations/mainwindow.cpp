#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
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

void MainWindow::translation(int Tx, int Ty){
    int a[4]={300,500,400,300};
        int b[4]={300,300,175,300};
        for (int i = 1; i <= 3; i++)
        { int x1=a[i],y1=b[i];
          int x2=a[i-1],y2=b[i-1];
          x1=a[i]+Tx;y1=b[i]+Ty;x2=a[i-1]+Tx;y2=b[i-1]+Ty;
          dda(x1,y1,x2,y2,qRgb(255,0,0));
}

}
void MainWindow::scaling(float sx,float sy)
{  int a[4]={300,500,400,300};
    int b[4]={300,300,175,300};
    for (int i = 1; i <= 3; i++)
    { int x1=a[i],y1=b[i];
      int x2=a[i-1],y2=b[i-1];
      x1=a[i]*sx;y1=b[i]*sy;x2=a[i-1]*sx;y2=b[i-1]*sy;
      dda(x1,y1,x2,y2,qRgb(255,0,0));

    }
}
void MainWindow::rotation(float angle){
    int t1[3],t2[3];
    int a[4]={300,500,400,300};
        int b[4]={300,300,175,300};
            angle=angle * 3.14 / 180;

            for(int i =0;i<=3;i++)
            {
                int x = a[i] - 300;
                int y = 300 - b[i];

                t1[i] = x*cos(angle) - y*sin(angle);
                t2[i] = x*sin(angle) + y*cos(angle);
            }

            for(int i=0;i<3-1;i++)
            {
                dda(t1[i]+300,300-t2[i],300+t1[i+1],300-t2[i+1],qRgb(255,0,0));
            }

}

void MainWindow::on_pushButton_clicked()
{
    QRgb value=qRgb(0,255,0);
    QRgb blue=qRgb(0,0,255);
    dda(300,0,300,600,blue);
    dda(0,300,600,300,blue);
    QRgb red=qRgb(255,0,0);
    img.setPixel(300,300,red);
    dda(300,300,500,300,value);
    dda(500,300,400,175,value);
    dda(400,175,300,300,value);

    /*dda(100,300,200,300,value);
    dda(200,300,200,400,value);
    dda(200,400,100,400,value);
    dda(100,400,100,300,value);*/
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->show();

}

void MainWindow::on_pushButton_3_clicked()
{
    int Tx=ui->textEdit_3->toPlainText().toInt();
    int Ty=ui->textEdit_5->toPlainText().toInt();


    translation(Tx,Ty);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->show();


}
void MainWindow::on_pushButton_2_clicked()
{
    float Sx=ui->textEdit->toPlainText().toFloat();
    float Sy=ui->textEdit_4->toPlainText().toFloat();
    scaling(Sx,Sy);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->show();

}


void MainWindow::on_pushButton_4_clicked()
{
    float angle=ui->textEdit_2->toPlainText().toFloat();
    rotation(angle);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->show();

}
