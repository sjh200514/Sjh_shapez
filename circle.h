#ifndef CIRCLE_H
#define CIRCLE_H
#include <QPoint>
#include <QPixmap>
#include <QPainter>
//圆形矿物实现，具体实现类似障碍物
class Circle
{
public:
    Circle(QPoint pos, const QPixmap &circle = QPixmap(":/image/circle.png"));

    const QPoint centerPos() const;


    void draw(QPainter *painter) const;

private:
    QPoint c_pos;
    bool c_iscircle;
    QPixmap c_circle;

    static const QSize c_fixedsize;
};

#endif // CIRCLE_H
