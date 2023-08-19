/*#include <QApplication>
#include <QtGui>
#include<QLabel>
#include <iostream>
#include "circledef.h"
QImage image1(300,300,QImage::Format_RGB888);
void Circledraw:: bcircle(float x,float y,float r){
    float x2, y2;
    float dp;
    x2=0;
    y2=0;
    dp=3-(2*r);
    QRgb value;
    value=qRgb(0,255,0);
    while(x2<y2){
        image1.setPixel(x-y2,y-x2,value);
        image1.setPixel(x+y2,y-x2,value);
        image1.setPixel(x-y2,y+x2,value);
        image1.setPixel(x+y2,y+x2,value);
        image1.setPixel(x+x2,y+y2,value);
        image1.setPixel(x+x2,y-y2,value);
        image1.setPixel(x-x2,y-y2,value);
        if(dp<0)
            dp=dp+4*x2+6;
        else{
            dp=dp+4*(x2-y2)+10;
            y2=y2-1;
        }
        x2=x2+1;
    }


}
QImage Circledraw:: getimage(){
    return image1;
}
*/
