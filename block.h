#ifndef BLOCK_H
#define BLOCK_H
#include <QPoint>
#include <QPixmap>
#include <QPainter>
//障碍物类实现
class Block
{
public:
    Block(QPoint pos, const QPixmap &block = QPixmap(":/image/block.png"));

    const QPoint centerPos() const;

    void draw(QPainter *painter) const;

private:
    QPoint b_pos;
    bool b_isblock;
    QPixmap b_block;

    static const QSize b_fixedsize;
};

#endif // BLOCK_H
