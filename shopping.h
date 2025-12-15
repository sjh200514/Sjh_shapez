#ifndef SHOPPING_H
#define SHOPPING_H
//商店实现
#include <QMainWindow>
#include <QString>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>

namespace Ui {
class Shopping;
}

class Shopping : public QMainWindow
{
    Q_OBJECT

public:
    explicit Shopping(QWidget *parent = nullptr);
    ~Shopping();

    int money = 0;
    QString str_money;
    QString str_1;
    QString str_2;
    QString str_3;
    QString str_message;
    bool select1 = true;
    bool select2 = true;
    bool select3 = true;
    int message = 0;


    void paintEvent(QPaintEvent *event);

private:
    Ui::Shopping *ui;
};

#endif // SHOPPING_H
