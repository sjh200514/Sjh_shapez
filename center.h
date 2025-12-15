#ifndef CENTER_H
#define CENTER_H
#include <QPoint>
#include <QPixmap>
#include <QPainter>
//交付中心类实现
class Center
{
public:
    Center(QPoint pos, const QPixmap &center = QPixmap(":/image/center1.png"));

    const QPoint centerPos() const;

    void draw(QPainter *painter) const;

private:
    QPoint t_pos;
    bool t_iscenter;
    QPixmap t_center;

    static const QSize t_fixedsize;
};

#endif // CENTER_H
