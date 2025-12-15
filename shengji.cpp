#include "shengji.h"
#include "ui_shengji.h"

Shengji::Shengji(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Shengji)
{
    ui->setupUi(this);
    setFixedSize(1000,800);
    miner_rise = false;
    cutter_rise = false;
    belt_rise = false;

    connect(ui->pushButton,&QPushButton::pressed,this,[=](){
        miner_rise = true;
        this->close();
    });
    connect(ui->pushButton_2,&QPushButton::pressed,this,[=](){
        cutter_rise = true;
        this->close();
    });
    connect(ui->pushButton_3,&QPushButton::pressed,this,[=](){
        belt_rise = true;
        this->close();
    });
}

Shengji::~Shengji()
{
    delete ui;
}
