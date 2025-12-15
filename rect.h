#ifndef RECT_H
#define RECT_H
//方形矿地实现
#include <QPoint>
#include <QPixmap>
#include <QPainter>
class Rect
{
public:
    Rect(QPoint pos, const QPixmap &rect = QPixmap(":/image/rectangle.png"));

    const QPoint centerPos() const;

    void draw(QPainter *painter) const;

private:
    QPoint r_pos;
    bool r_isrect;
    QPixmap r_rect;

    static const QSize r_fixedsize;
};

#endif // RECT_H
