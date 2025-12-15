#include "rect.h"

const QSize Rect::r_fixedsize(50,50);

Rect::Rect(QPoint pos, const QPixmap &rect)
    :r_pos(pos),r_isrect(false),r_rect(rect)
{

}

const QPoint Rect::centerPos() const
{
    QPoint a(25,25);
    return r_pos+a;
}

void Rect::draw(QPainter *painter) const
{
    painter->drawPixmap(r_pos.x(),r_pos.y(),50,50,r_rect);
}
