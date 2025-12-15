#include "miner.h"

const QSize Miner::m_fixedsize(50,50);

Miner::Miner(QPoint pos, int rotate_, const QPixmap &miner)
    :m_pos(pos),m_isminer(false),m_miner(miner),rotate(rotate_)
{

}

const QPoint Miner::centerPos() const
{
    return m_pos;
}


int Miner::m_rotate(){
    return rotate;
}

void Miner::draw(QPainter *painter, int rotate) const
{
    painter->save();
    QPoint center = m_pos;
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
    painter->drawPixmap(0,0,50,50,m_miner);
    painter->restore();
}
