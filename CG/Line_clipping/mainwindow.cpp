#include "mainwindow.h"
#include "ui_mainwindow.h"
QImage img(800,800,QImage::Format_RGB888);
QImage image1(850,850,QImage::Format_RGB888);
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
const int inside=0;
const int left=1;
const int right=2;//according to conversion of binary to deicmal
const int bottom=4;
const int top=8;
/*const int top_left=9;
const int top_right=10;
const int bottom_right=6;
const int bottom_left=5;*/
const int xmin=200;
const int xmax=600;
const int ymin=300;
const int ymax=600;
void MainWindow::dda(int x1, int y1, int x2, int y2,QRgb value){
    value = qRgb(0,255,0);
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
int MainWindow::Code_compute(float a,float b){
    int code = inside;

        if (a < xmin)
            code = left;
        else if (a > xmax)
            code = right;
        if (b < ymin)
            code = bottom;
        else if (b > ymax)
            code = top;

        return code;
}
void MainWindow::lineclip(int a1, int b1,int a2,int b2){
    //int a=a1,b=b1,c=a2,d=b2;
    int codep1 = Code_compute(a1, b1);
    int codep2 = Code_compute(a2, b2);
    bool eval=false;
    while(true){
        if(codep1==0 && codep2==0){//if code is 0 then the point lies inside
            eval=true;
            break;
        }
        else if ((codep1!=0)&& (codep2!=0)) {

                    break;
                }
                else {

                    int code_out;
                    double x, y;


                    if (codep1 != 0)
                        code_out = codep1;
                    else
                        code_out = codep2;


                    if (code_out & top) {

                        x = a1 + (a2 - a1) * (ymax - b1) / (b2 - b1);
                        y = ymax;
                    }
                    else if (code_out & bottom) {

                        x = a1 + (a2 - a1) * (ymin - b1) / (b2 - b1);
                        y = ymin;
                    }
                    else if (code_out & right) {

                        y = b1 + (b2 - b1) * (xmax - a1) / (a2 - a1);
                        x = xmax;
                    }
                    else if (code_out & left) {

                        y = b1 + (b2 - b1) * (xmin - a1) / (a2 - a1);
                        x = xmin;
                    }
                    if (code_out == codep1) {
                                    a1 = x;
                                    b1 = y;
                                    codep1 = Code_compute(a1, b1);
                                }
                                else {
                                    a2 = x;
                                    b2 = y;
                                    codep2 = Code_compute(a2, b2);
                                }
                            }
                        }
                        if (eval) {

                            //dda(a,b,c,d,qRgb(0,0,0));
                            dda(a1,b1,a2,b2,qRgb(3, 207, 252));

    }

   /* dx1=a2-a1;
    dy1=b2-b1;
    m=dy1/dx1;
    dx2=a1-200;
    dy2=b1-y_new;
    y_new=b1-m*dx2;
    dda(200,y_new,a2,b2);*/


}

void MainWindow::on_pushButton_clicked()
{   QRgb value=qRgb(0,255,10);
    dda(200,300,600,300,value);
    dda(600,300,600,600,value);
    dda(600,600,200,600,value);
    dda(200,600,200,300,value);
    //dda(100,525,400,400,value);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->show();
}


void MainWindow::on_pushButton_2_clicked()
{
  //dda(100,525,400,400,qRgb(255,255,255));
  lineclip(100,525,400,400);


  ui->label->setPixmap(QPixmap::fromImage(img));
  ui->label->show();

}

