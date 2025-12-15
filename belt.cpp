#include "belt.h"

Belt::Belt(QPoint pos, int rotate_,int rotate2,const QPixmap &belt)
    :Rubbish(pos,rotate_,belt),rotate(rotate2)
{

}

void Belt::draw(QPainter *painter,int rotate)
{
    switch(rotate){
    case 0:
        painter->drawPixmap(r_pos.x(),r_pos.y(),50,50,QPixmap(":/image/DU.png"));
        break;
    case 1:
        painter->drawPixmap(r_pos.x(),r_pos.y(),50,50,QPixmap(":/image/DR.png"));
        break;
    case 2:
        painter->drawPixmap(r_pos.x(),r_pos.y(),50,50,QPixmap(":/image/LR.png"));
        break;
    case 3:
        painter->drawPixmap(r_pos.x(),r_pos.y(),50,50,QPixmap(":/image/LD.png"));
        break;
    case 4:
        painter->drawPixmap(r_pos.x(),r_pos.y(),50,50,QPixmap(":/image/UD.png"));
        break;
    case 5:
        painter->drawPixmap(r_pos.x(),r_pos.y(),50,50,QPixmap(":/image/UL.png"));
        break;
    case 6:
        painter->drawPixmap(r_pos.x(),r_pos.y(),50,50,QPixmap(":/image/RL.png"));
        break;
    case 7:
        painter->drawPixmap(r_pos.x(),r_pos.y(),50,50,QPixmap(":/image/RU.png"));
        break;
    case 8:
        painter->drawPixmap(r_pos.x(),r_pos.y(),50,50,QPixmap(":/image/RD.png"));
        break;
    case 9:
        painter->drawPixmap(r_pos.x(),r_pos.y(),50,50,QPixmap(":/image/UR.png"));
        break;
    case 10:
        painter->drawPixmap(r_pos.x(),r_pos.y(),50,50,QPixmap(":/image/LU.png"));
        break;
    case 11:
        painter->drawPixmap(r_pos.x(),r_pos.y(),50,50,QPixmap(":/image/DL.png"));
        break;
    default:
        break;
    }
}
