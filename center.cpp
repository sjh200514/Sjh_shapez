#include "center.h"

const QSize Center::t_fixedsize(50,50);

Center::Center(QPoint pos, const QPixmap &center)
    :t_pos(pos),t_iscenter(false),t_center(center)
{

}

const QPoint Center::centerPos() const
{
    QPoint a(25,25);
    return t_pos+a;
}


void Center::draw(QPainter *painter) const
{
    painter->drawPixmap(t_pos.x(),t_pos.y(),100,100,t_center);
}

