#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
QImage img(500,500,QImage::Format_RGB888);

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
void MainWindow::dda(int x1, int y1, int x2, int y2)
{
    QRgb value;
    value = qRgb(0,255,0);
    int length = 0;
    if (abs(x2-x1) >= abs(y2-y1))
        length = abs(x2-x1);
    else
        length = abs(y2-y1);
    float dx = ((x2-x1)/length);
    float dy = ((y2-y1)/length);
    float x = x1 ;
    float y = x2 ;
    int i = 1;
    while(i <= length){
        img.setPixel(int(x), int(y), value);
        x = x + dx;
        y = y + dy;
        i++;
    }
}
void MainWindow::circle(int xc, int yc, int xr)
{
    QRgb value;
    value = qRgb(0,255,0);
    int x = 0;
    int y = xr;
    int d;
    d = 3 - (2*xr);
    while (x<=y) {
    img.setPixel(int(y + xc), int(x + yc), value);
    img.setPixel(int(x + xc), int(y + yc), value);
    img.setPixel(int(-x + xc), int(y + yc), value);
    img.setPixel(int(-y + xc), int(x + yc), value);
    img.setPixel(int(-y + xc), int(-x + yc), value);
    img.setPixel(int(-x + xc), int(-y + yc), value);
    img.setPixel(int(x + xc), int(-y + yc), value);
    img.setPixel(int(y + xc), int(-x + yc), value);
    if (d<0){
        d = d + (4*x) + 6;
        x++;
    }
    else {
        d = d + 4*(x-y) + 10;
        x++;
        y--;
    }
  }
}
void MainWindow:: bresenhamAlg(int x0, int y0, int x1, int y1)
{
    QRgb value;
    value = qRgb(0,255,0);
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

void MainWindow:: triangle (int ix , int iy, int r)

{
    float theta = 2.0933;
    int x=ix, y=iy-r,x1,x2,y1,y2;
    x1=ix+(x-ix)*cos(theta)-(y-iy)*sin(theta);
    y1=iy+r/2;
    x2=ix+(x-ix)*cos(theta)+(y-iy)*sin(theta);
    y2=iy+r/2;;
    bresenhamAlg(x, y, x1, y1);
    bresenhamAlg(x, y, x2, y2);
    bresenhamAlg(x1, y1, x2, y2);
}


void MainWindow::on_pushButton_clicked()
{
    int x0=ui->textEdit->toPlainText().toInt();
    int y0=ui->textEdit_2->toPlainText().toInt();
    int x1=ui->textEdit_3->toPlainText().toInt();
    int y1=ui->textEdit_4->toPlainText().toInt();
    dda(x0,y0,x1,y1);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->show();


}




void MainWindow::on_pushButton_2_clicked()
{
    int xc=ui->textEdit_5->toPlainText().toInt();
    int yc=ui->textEdit_6->toPlainText().toInt();
    int r=ui->textEdit_7->toPlainText().toInt();
    circle(xc, yc, r);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    int xi = ui->textEdit_5->toPlainText().toInt();
    int yi = ui->textEdit_6->toPlainText().toInt();
    int r = ui->textEdit_7->toPlainText().toInt();
    circle(xi,yi,r);
    circle(xi,yi,r/2);
    triangle(xi,yi, r);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->show();
}


