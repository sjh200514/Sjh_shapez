#ifndef YUAN_H
#define YUAN_H
//圆形矿物实现
#include <QPoint>
#include <QPixmap>
#include <QPainter>

class Yuan
{
public:
    Yuan(int x1,int y1,const bool set = true);
    int x = 0;
    int y = 0;
    int speedx = 50;
    int speedy = 50;
    void draw(QPainter *painter);
    bool exist = false;
};

#endif // YUAN_H
