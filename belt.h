#ifndef BELT_H
#define BELT_H
//垃圾桶类实现
#include "rubbish.h"

class Belt : public Rubbish
{
public:
    Belt(QPoint pos, int rotate_,int rotate2,const QPixmap &belt = QPixmap(":/image/conveyor.png"));
    void draw(QPainter *painter, int rotate);
    int rotate = 0;
};

#endif // BELT_H
