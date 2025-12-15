#include "fang.h"

Fang::Fang(int x_, int y_, int qiege_, const bool exist_)
    :x(x_),y(y_),qiege(qiege_),exist(exist_)
{

}

void Fang::draw(QPainter *painter)
{
        switch (qiege) {
        case 0:
            painter->drawPixmap(x+10,y+10,30,30,QPixmap(":/image/fang.png"));
            break;
        case 1:
            painter->drawPixmap(x+10,y+10,30,30,QPixmap(":/image/left.png"));
            break;
        case 2:
            painter->drawPixmap(x+10,y+10,30,30,QPixmap(":/image/right.png"));
            break;
        case 3:
            painter->drawPixmap(x+10,y+10,30,30,QPixmap(":/image/up.png"));
            break;
        case 4:
            painter->drawPixmap(x+10,y+10,30,30,QPixmap(":/image/down.png"));
            break;
        default:
            break;
        }
}
