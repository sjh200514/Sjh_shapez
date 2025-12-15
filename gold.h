#ifndef GOLD_H
#define GOLD_H
//自定义设备（点石成金机实现）
#include <QPixmap>
#include <QPainter>
class Gold
{
public:
    Gold(int x_,int y_);
    int x;
    int y;
    void draw(QPainter *painter);
};

#endif // GOLD_H
