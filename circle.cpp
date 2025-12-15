#include "circle.h"

const QSize Circle::c_fixedsize(50,50);

Circle::Circle(QPoint pos, const QPixmap &circle)
    :c_pos(pos),c_iscircle(false),c_circle(circle)
{

}

const QPoint Circle::centerPos() const
{
    QPoint a(25,25);
    return c_pos+a;
}

void Circle::draw(QPainter *painter) const
{
    painter->drawPixmap(c_pos.x(),c_pos.y(),50,50,c_circle);
}
