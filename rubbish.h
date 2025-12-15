#ifndef RUBBISH_H
#define RUBBISH_H
//垃圾桶类实现
#include <QPoint>
#include <QPixmap>
#include <QPainter>
#include <QTransform>
#include <QDebug>
class Rubbish
{
public:
    Rubbish(QPoint pos, int rotate_,const QPixmap &rubbish = QPixmap(":/image/eraser.png"));

    const QPoint centerPos() const;

    int r_rotate();

    void draw(QPainter *painter,int rotate) const;

protected:
    QPoint r_pos;

private:
    bool r_isrubbish;
    QPixmap r_rubbish;
    int rotate = 0;

    static const QSize r_fixedsize;
};

#endif // RUBBISH_H
