#ifndef CUTTER_H
#define CUTTER_H
#include <QPoint>
#include <QPixmap>
#include <QPainter>
//切割机类实现
class Cutter
{
public:
    Cutter(int x_,int y_,int rotate_);
    int rotate = 0;
    int x = 0;
    int y = 0;
    void draw(QPainter *painter);
};

#endif // CUTTER_H
