#include "cutter.h"

Cutter::Cutter(int x_, int y_,int rotate_)
    :x(x_),y(y_),rotate(rotate_)
{

}

void Cutter::draw(QPainter *painter)
{
    switch(rotate){
    case 0:
        painter->drawPixmap(x,y,100,50,QPixmap(":/image/cutU.png"));
        break;
    case 90:
        painter->drawPixmap(x,y,50,100,QPixmap(":/image/cutR.png"));
        break;
    case 180:
        painter->drawPixmap(x-50,y,100,50,QPixmap(":/image/cutD.png"));
        break;
    case 270:
        painter->drawPixmap(x,y-50,50,100,QPixmap(":/image/cutL.png"));
        break;
    default:
        break;
    }
}
