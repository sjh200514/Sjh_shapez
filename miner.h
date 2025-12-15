#ifndef MINER_H
#define MINER_H
//采矿机类实现
#include <QPoint>
#include <QPixmap>
#include <QPainter>
#include <QTransform>
#include <QDebug>
//采矿机类实现
class Miner
{
public:
    Miner(QPoint pos, int rotate_,const QPixmap &miner = QPixmap(":/image/miner.png"));

    const QPoint centerPos() const;

    int m_rotate();

    void draw(QPainter *painter,int rotate) const;

private:
    QPoint m_pos;
    bool m_isminer;
    QPixmap m_miner;
    int rotate = 0;

    static const QSize m_fixedsize;
};

#endif // MINER_H
