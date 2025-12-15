#ifndef SHENGJI_H
#define SHENGJI_H
//关卡升级实现
#include <QMainWindow>

namespace Ui {
class Shengji;
}

class Shengji : public QMainWindow
{
    Q_OBJECT

public:
    explicit Shengji(QWidget *parent = nullptr);
    ~Shengji();
    bool miner_rise = false;
    bool cutter_rise = false;
    bool belt_rise = false;

private:
    Ui::Shengji *ui;

};

#endif // SHENGJI_H
