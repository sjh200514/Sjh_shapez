#include "rubbish.h"

Rubbish::Rubbish(QPoint pos, int rotate_,const QPixmap &rubbish)
    :r_pos(pos),r_isrubbish(false),r_rubbish(rubbish),rotate(rotate_)
{

}

const QPoint Rubbish::centerPos() const
{
    return r_pos;
}


int Rubbish::r_rotate(){
    return rotate;
}

void Rubbish::draw(QPainter *painter, int rotate) const
{
    painter->save();
    QPoint center = r_pos;
    QTransform transform;
    int i = 0;
    int j = 0;
    if(rotate==90){
        i = 50;
    }
    else if(rotate==180){
        i = 50;
        j = 50;
    }
    else if(rotate==270){
        j = 50;
    }
    transform.translate(center.x()+i, center.y()+j);
    transform.rotate(rotate);
    painter->setTransform(transform);
    painter->drawPixmap(0,0,50,50,r_rubbish);
    painter->restore();
}
