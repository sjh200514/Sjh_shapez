#include "shopping.h"
#include "ui_shopping.h"

Shopping::Shopping(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Shopping)
{
    ui->setupUi(this);
    setFixedSize(1000,800);
    setWindowIcon(QIcon(":/image/shop.png"));
    setWindowTitle("商店");
    ui->btn_back->setIcon(QPixmap(":/image/back.jpg"));
    connect(ui->btn_back,&QPushButton::pressed,this,[=](){
        this->close();
    });
    connect(ui->btn_select1,&QPushButton::pressed,this,[=](){
        if(select1)
        {
            if(money>=100){
                money-=100;
                select1 = false;
                message = 3;
            }
            else{
                message = 1;
            }
        }
        else
        {
            message = 2;
        }
    });
    connect(ui->btn_select2,&QPushButton::pressed,this,[=](){
        if(select2)
        {
            if(money>=300){
                money-=300;
                select2 = false;
                message = 3;
            }
            else{
                message = 1;
            }
        }
        else
        {
            message = 2;
        }
    });
    connect(ui->btn_select3,&QPushButton::pressed,this,[=](){
        if(select3)
        {
            if(money>=500){
                money-=500;
                select3 = false;
                message = 3;
            }
            else{
                message = 1;
            }
        }
        else
        {
            message = 2;
        }
    });
}

Shopping::~Shopping()
{
    delete ui;
}

void Shopping::paintEvent(QPaintEvent *event)
{
    str_money = QString("金 币 数: %1 ").arg(money);
    ui->label_money->setText(str_money);
    str_1 = QString("提升矿物获得的金币价值(100金币)");
    ui->btn_select1->setText(str_1);
    str_2 = QString("移除障碍物(300金币)");
    ui->btn_select2->setText(str_2);
    str_3 = QString("扩大交付中心(500金币)");
    ui->btn_select3->setText(str_3);
    switch(message){
    case 1:
        str_message = QString("金币不足！");
        ui->label_message->setText(str_message);
        break;
    case 2:
        str_message = QString("超过最大购买次数！");
        ui->label_message->setText(str_message);
        break;
    case 3:
        str_message = QString("购买成功！");
        ui->label_message->setText(str_message);
    default:
        break;
    }
}
