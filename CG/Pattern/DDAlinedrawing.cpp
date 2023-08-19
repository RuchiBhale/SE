#include <QApplication>
#include <QtGui>
#include<QLabel>
#include <iostream>
#include "linedef.h"
QImage image(300,300,QImage::Format_RGB888);


void linedraw :: DDAline(float a,float b,float c, float d)
{
    float dx,dy,xinc,yinc,x,y;
    float step;
    dx=c-a;
    dy=d-b;
    if(dy>dx)
        step=dy;
    else
        step=dx;
    xinc=dx/step;
    yinc=dy/step;
    x=a;
    y=b;
    //float i=x1;
    QRgb value;
    value=qRgb(0,255,0);
    for(int i=0;i<dx;i++){
        x=x+xinc;
        y=y+yinc;
        image.setPixel(round(x),round(y),value);
    }
    QLabel l;
    l.setPixmap(QPixmap::fromImage(image));
    l.show();

}
