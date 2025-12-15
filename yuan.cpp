#include "yuan.h"

Yuan::Yuan(int x1,int y1,const bool set)
    :x(x1),y(y1),exist(set)
{

}

void Yuan::draw(QPainter *painter)
{
    painter->drawPixmap(x+10,y+10,30,30,QPixmap(":/image/yuan.png"));
}
