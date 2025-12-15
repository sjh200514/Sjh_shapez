#include "block.h"

//设定单个障碍物固定大小为50*50
const QSize Block::b_fixedsize(50,50);

//障碍物类构造函数
Block::Block(QPoint pos, const QPixmap &block)
    :b_pos(pos),b_isblock(false),b_block(block)
{

}

//障碍物中心点
const QPoint Block::centerPos() const
{
    QPoint a(25,25);
    return b_pos+a;
}


//绘制障碍物
void Block::draw(QPainter *painter) const
{
    painter->drawPixmap(b_pos.x(),b_pos.y(),50,50,b_block);
}
