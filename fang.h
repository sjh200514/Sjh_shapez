#ifndef FANG_H
#define FANG_H
//方形矿物类实现
#include <QPoint>
#include <QPixmap>
#include <QPainter>

class Fang
{
public:
    Fang(int x_,int y_,int qiege_,const bool exist_ = true);
    int x = 0;
    int y = 0;
    int speedx = 50;
    int speedy = 50;
    bool exist = false;
    int qiege = 0;
    int count = 0;
    void draw(QPainter *painter);
};

#endif // FANG_H
