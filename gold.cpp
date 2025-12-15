#include "gold.h"

Gold::Gold(int x_,int y_)
    :x(x_),y(y_)
{

}

void Gold::draw(QPainter *painter)
{
    painter->drawPixmap(x,y,50,50,QPixmap(":/image/gold.png"));
}
