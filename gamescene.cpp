#include "gamescene.h"
#include "qforeach.h"
#include "ui_gamescene.h"
#include <QPen>
#include <QPoint>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QPoint>
#include <QTransform>
#include <QDebug>
#include <algorithm>

GameScene::GameScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameScene)
{
    ui->setupUi(this);
    ui->setupUi(this);
    //设定窗口固定大小，图标，标题
    setFixedSize(1000,800);
    setWindowIcon(QIcon(":/image/starticon.jpg"));
    setWindowTitle("SJH's shapez");
    shop = new Shopping;
    shengji = new Shengji;
    end = new End;

    //计时器设置
    timer1 = new QTimer(this);
    connect(timer1,&QTimer::timeout,this,&GameScene::generateyuan);
    timer1->start(time1_);

    timer2 = new QTimer(this);
    connect(timer2,&QTimer::timeout,this,&GameScene::generatefang);
    timer2->start(time1_);

    timer3 = new QTimer(this);
    connect(timer3,&QTimer::timeout,this,&GameScene::drawyuan);
    timer3->start(time2_);

    timer4 = new QTimer(this);
    connect(timer4,&QTimer::timeout,this,&GameScene::drawfang);
    timer4->start(time2_);

    connect(ui->btn_shop,&QPushButton::pressed,this,[=](){
        shop->show();
    });

    timer5 = new QTimer(this);
    connect(timer5,&QTimer::timeout,this,[=](){
        shop->money+=m_goldlist.size();
    });
    timer5->start(1000);

    connect(ui->btn_save,&QPushButton::pressed,this,&GameScene::saveGame);

    //设置边界
    setboundary();

    //障碍物加载
    loadblock();

    //圆形矿物加载
    loadcircle();

    //方形矿物加载
    loadrect();

    //交付中心加载
    loadcenter();

    //采矿器加载
    loadminer();

    //垃圾桶加载
    loadrubbish();

    //传送带加载
    loadbelt();

    //切割机加载
    loadcutter();

    //点石成金机加载
    loadgold();

    ui->label_money->move(0,0);
    ui->label_yuan->move(0,40);
}

void GameScene::setboundary()
{
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            if(j<=3||j>=14){
                is_map[i][j] = false;
                is_block[i][j] = false;
                is_circle[i][j] = false;
                is_rect[i][j] = false;
                is_center[i][j] = false;
                is_yuan[i][j] = false;
            }
            else{
                is_map[i][j] = true;
                is_block[i][j] = false;
                is_circle[i][j] = false;
                is_rect[i][j] = false;
                is_center[i][j] = false;
                is_yuan[i][j] = false;
            }
        }
    }
}

void GameScene::loadblock()
{
    QPoint pos_block[] =
        {
            QPoint(200, 300),
            QPoint(200, 350),
            QPoint(250, 200),
            QPoint(350, 400),

            QPoint(0, 200),
            QPoint(300,600),
            QPoint(600, 450),
            QPoint(650, 550),

        };

    is_block[4][6] = true;
    is_block[4][7] = true;
    is_block[5][4] = true;
    is_block[7][8] = true;
    is_block[0][4] = true;
    is_block[6][12] = true;
    is_block[12][9] = true;
    is_block[13][11] = true;

    int len_block	= sizeof(pos_block) / sizeof(pos_block[0]);
    for (int i = 0; i < len_block; ++i){
        m_block.push_back(Block(pos_block[i]));
    }
}

void GameScene::loadcircle()
{
    QPoint pos_circle[] =
        {
            QPoint(100, 500),
            QPoint(150, 500),
            QPoint(100, 550),
            QPoint(150, 550),

            QPoint(700, 250),
            QPoint(750, 250),
            QPoint(700, 200),
            QPoint(750, 200),


        };

    is_circle[2][10] = true;
    is_circle[3][10] = true;
    is_circle[2][11] = true;
    is_circle[3][11] = true;
    is_circle[14][5] = true;
    is_circle[15][5] = true;
    is_circle[14][4] = true;
    is_circle[15][4] = true;

    int len_circle	= sizeof(pos_circle) / sizeof(pos_circle[0]);
    for (int i = 0; i < len_circle; ++i){
        m_circle.push_back(Circle(pos_circle[i]));
    }
}
void GameScene::loadrect()
{
    QPoint pos_rect[] =
        {
            QPoint(700, 600),
            QPoint(750, 600),
            QPoint(700, 550),
            QPoint(750, 550),

            QPoint(100, 300),
            QPoint(150, 300),
            QPoint(100, 250),
            QPoint(150, 250)
        };

    is_rect[14][12] = true;
    is_rect[15][12] = true;
    is_rect[14][11] = true;
    is_rect[15][11] = true;
    is_rect[2][6] = true;
    is_rect[3][6] = true;
    is_rect[2][5] = true;
    is_rect[3][5] = true;

    int len_rect = sizeof(pos_rect) / sizeof(pos_rect[0]);
    for (int i = 0; i < len_rect; ++i){
        m_rect.push_back(Rect(pos_rect[i]));
    }
}
void GameScene::loadcenter()
{
    QPoint pos_center[] =
        {
            QPoint(450,450),
        };
    m_center.push_back((Center(pos_center[0])));

    is_center[10][10] = true;
    is_center[9][10] = true;
    is_center[9][9] = true;
    is_center[10][9] = true;
}

void GameScene::loadminer()
{
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 16; j++){
            if(is_circle[i][j]||is_rect[i][j]){
                m_miner.push_back(Miner(QPoint(50*i,50*j),0));
            }
            is_miner[i][j] = false;
        }
    }
    connect(ui->btn_miner,&QPushButton::pressed
            ,this,[=](){
                signal = 1;
    });
}

void GameScene::loadrubbish()
{
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 16; j++){
            if(is_map[i][j]&&!is_block[i][j]&&!is_center[i][j]&&!is_circle[i][j]&&!is_rect[i][j]&&!is_belt[i][j]&&!is_cutter[i][j]){
                m_rubbish.push_back(Rubbish(QPoint(50*i,50*j),0));
            }
            is_rubbish[i][j] = false;
        }
    }
    connect(ui->btn_trash,&QPushButton::pressed
            ,this,[=](){
                signal = 2;
    });
}

void GameScene::loadbelt()
{
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 16; j++){
            if(is_map[i][j]&&!is_block[i][j]&&!is_center[i][j]&&!is_circle[i][j]&&!is_rect[i][j]&&!is_rubbish[i][j]&&!is_cutter[i][j]){
                m_belt.push_back(Belt(QPoint(50*i,50*j),0,0));
            }
            is_belt[i][j] = false;
        }
    }
    connect(ui->btn_belt,&QPushButton::pressed
            ,this,[=](){
                signal = 3;
            });
}

void GameScene::loadcutter()
{
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            if(is_map[i][j]&&!is_block[i][j]&&!is_center[i][j]&&!is_circle[i][j]&&!is_rect[i][j]&&!is_rubbish[i][j]&&!is_belt[i][j])
            {
                m_cutter.push_back(Cutter(50*i,50*j,0));
            }
            is_cutter[i][j] = false;
        }
    }
    connect(ui->btn_cutter,&QPushButton::pressed,this,[=](){
        signal = 4;
    });
}

void GameScene::loadgold()
{
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 16; j++){
            if(is_circle[i][j]||is_rect[i][j]){
                m_gold.push_back(Gold(50*i,50*j));
            }
            is_gold[i][j] = false;
        }
    }
    connect(ui->btn_gold,&QPushButton::pressed
            ,this,[=](){
                signal = 5;
            });
}

void GameScene::addminer(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    for(auto it = m_miner.begin(); it!=m_miner.end(); it++){
        if(!is_miner[pressPos.x()/50][pressPos.y()/50]&&it->centerPos().x()/50==pressPos.x()/50&&it->centerPos().y()/50==pressPos.y()/50)
        {
            Miner *miner = new Miner(it->centerPos(),0);
            m_minerlist.push_back(miner);
            is_miner[pressPos.x()/50][pressPos.y()/50] = true;

            update();
            break;
        }
    }
}

void GameScene::addrubbish(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    for(auto it = m_rubbish.begin(); it!=m_rubbish.end(); it++){
        if(!is_rubbish[pressPos.x()/50][pressPos.y()/50]&&it->centerPos().x()/50==pressPos.x()/50&&it->centerPos().y()/50==pressPos.y()/50)
        {
            Rubbish *rubbish = new Rubbish(it->centerPos(),0);
            m_rubbishlist.push_back(rubbish);
            is_rubbish[pressPos.x()/50][pressPos.y()/50] = true;

            update();
            break;
        }
    }
}

void GameScene::addbelt(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    for(auto it = m_belt.begin(); it!=m_belt.end(); it++){
        if(!is_belt[pressPos.x()/50][pressPos.y()/50]&&it->centerPos().x()/50==pressPos.x()/50&&it->centerPos().y()/50==pressPos.y()/50)
        {
            Belt *belt = new Belt(it->centerPos(),0,0);
            m_beltlist.push_back(belt);
            is_belt[pressPos.x()/50][pressPos.y()/50] = true;
            signal = 0;
            update();
            break;
        }
    }
}

void GameScene::addcutter(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    for(auto it = m_cutter.begin(); it!=m_cutter.end(); it++){
        if(!is_cutter[pressPos.x()/50][pressPos.y()/50]&&it->x/50==pressPos.x()/50&&it->y/50==pressPos.y()/50)
        {
            Cutter *cutter = new Cutter(it->x,it->y,0);
            m_cutterlist.push_back(cutter);
            is_cutter[pressPos.x()/50][pressPos.y()/50] = true;
            is_cutter[pressPos.x()/50+1][pressPos.y()/50] = true;
            signal = 0;
            update();
            break;
        }
    }
}

void GameScene::addgold(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    for(auto it = m_gold.begin(); it!=m_gold.end(); it++){
        if(!is_gold[pressPos.x()/50][pressPos.y()/50]&&it->x/50==pressPos.x()/50&&it->y/50==pressPos.y()/50)
        {
            Gold *gold = new Gold(it->x,it->y);
            m_goldlist.push_back(gold);
            is_gold[pressPos.x()/50][pressPos.y()/50] = true;

            update();
            break;
        }
    }
}

void GameScene::deleteminer(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    for(auto it = m_minerlist.begin(); it!=m_minerlist.end(); it++){
        Miner *miner = *it;
        if(miner->centerPos().x()/50==pressPos.x()/50&&miner->centerPos().y()/50==pressPos.y()/50)
        {
            delete miner;
            it = m_minerlist.erase(it);
            is_miner[pressPos.x()/50][pressPos.y()/50] = false;
            signal = 0;
            update();
            break;
        }
    }
}

void GameScene::deleterubbish(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    for(auto it = m_rubbishlist.begin(); it!=m_rubbishlist.end(); it++){
        Rubbish *rubbish = *it;
        if(rubbish->centerPos().x()/50==pressPos.x()/50&&rubbish->centerPos().y()/50==pressPos.y()/50)
        {
            delete rubbish;
            it = m_rubbishlist.erase(it);
            is_rubbish[pressPos.x()/50][pressPos.y()/50] = false;
            signal = 0;
            update();
            break;
        }
    }
}

void GameScene::deletebelt(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    for(auto it = m_beltlist.begin(); it!=m_beltlist.end(); it++){
        Rubbish *belt = *it;
        if(belt->centerPos().x()/50==pressPos.x()/50&&belt->centerPos().y()/50==pressPos.y()/50)
        {
            delete belt;
            it = m_beltlist.erase(it);
            is_belt[pressPos.x()/50][pressPos.y()/50] = false;
            is_yuan[pressPos.x()/50][pressPos.y()/50] = false;
            signal = 0;
            update();
            break;
        }
    }
}

void GameScene::deletecutter(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    for(auto it = m_cutterlist.begin(); it!=m_cutterlist.end(); it++){
        Cutter *cutter = *it;
        if(cutter->x/50==pressPos.x()/50&&cutter->y/50==pressPos.y()/50)
        {
            switch(cutter->rotate){
            case 0:
                is_cutter[cutter->x/50][cutter->y/50] = false;
                is_cutter[cutter->x/50+1][cutter->y/50] = false;
                cutter_num[cutter->x/50][cutter->y/50] = 0;
                break;
            case 90:
                is_cutter[cutter->x/50][cutter->y/50] = false;
                is_cutter[cutter->x/50][cutter->y/50+1] = false;
                cutter_num[cutter->x/50][cutter->y/50] = 0;
                break;
            case 180:
                is_cutter[cutter->x/50-1][cutter->y/50] = false;
                is_cutter[cutter->x/50][cutter->y/50] = false;
                cutter_num[cutter->x/50][cutter->y/50] = 0;
                break;
            case 270:
                is_cutter[cutter->x/50][cutter->y/50] = false;
                is_cutter[cutter->x/50][cutter->y/50-1] = false;
                cutter_num[cutter->x/50][cutter->y/50] = 0;
                break;
            default:
                break;
            }
            delete cutter;
            it = m_cutterlist.erase(it);
            signal = 0;
            update();
            break;
        }
    }
}

void GameScene::deletegold(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    for(auto it = m_goldlist.begin(); it!=m_goldlist.end(); it++){
        Gold *gold = *it;
        if(gold->x/50==pressPos.x()/50&&gold->y/50==pressPos.y()/50)
        {
            delete gold;
            it = m_goldlist.erase(it);
            is_gold[pressPos.x()/50][pressPos.y()/50] = false;
            signal = 0;
            update();
            break;
        }
    }
}

GameScene::~GameScene()
{
    delete ui;
}

void GameScene::mousePressEvent(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    if(event->button() == Qt::LeftButton&&signal == 1){
        addminer(event);
    }
    else if(event->button() == Qt::LeftButton&&signal == 2){
        addrubbish(event);
    }
    else if(event->button() == Qt::LeftButton&&signal == 3){
        addbelt(event);
    }
    else if(event->button() == Qt::LeftButton&&signal == 4){
        addcutter(event);
    }
    else if(event->button() == Qt::LeftButton&&signal == 5){
        addgold(event);
    }
    else if(event->button() == Qt::RightButton){
        if(is_miner[pressPos.x()/50][pressPos.y()/50]){
            deleteminer(event);
        }
        else if(is_rubbish[pressPos.x()/50][pressPos.y()/50]){
            deleterubbish(event);
        }
        else if(is_belt[pressPos.x()/50][pressPos.y()/50]){
            deletebelt(event);
        }
        else if(is_cutter[pressPos.x()/50][pressPos.y()/50]){
            deletecutter(event);
        }
        else if(is_gold[pressPos.x()/50][pressPos.y()/50]){
            deletegold(event);
        }
    }
}

void GameScene::mouseMoveEvent(QMouseEvent *event)
{
    QPoint t = QPoint((event->pos().x()/50)*50,(event->pos().y()/50)*50);
    m_currentmouse = t;
    update();
}

void GameScene::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton&&signal==1){
        if(!miner_release){
        miner_release = true;
        }
        if((is_circle[event->pos().x()/50][event->pos().y()/50]||is_rect[event->pos().x()/50][event->pos().y()/50])&&!is_miner[event->pos().x()/50][event->pos().y()/50]&&!is_gold[event->pos().x()/50][event->pos().y()/50]){
        QPoint t = QPoint((event->pos().x()/50)*50,(event->pos().y()/50)*50);
        m_currentmouse = t;
        Miner *miner_t = new Miner(t,m_rotate);
        m_minerlist.push_back(miner_t);
        is_miner[t.x()/50][t.y()/50] = true;
        miner_num[t.x()/50][t.y()/50] = m_rotate/90;

        update();
        }
        else{
        update();
        }
    }
    else if(event->button()==Qt::LeftButton&&signal==2){
        if(!rubbish_release){
            rubbish_release = true;
        }
        if(is_map[event->pos().x()/50][event->pos().y()/50]&&!is_block[event->pos().x()/50][event->pos().y()/50]&&!is_center[event->pos().x()/50][event->pos().y()/50]&&!is_center[event->pos().x()/50][event->pos().y()/50]&&!is_circle[event->pos().x()/50][event->pos().y()/50]&&!is_rect[event->pos().x()/50][event->pos().y()/50]&&!is_rubbish[event->pos().x()/50][event->pos().y()/50]&&!is_belt[event->pos().x()/50][event->pos().y()/50]&&!is_cutter[event->pos().x()/50][event->pos().y()/50]){
            QPoint t = QPoint((event->pos().x()/50)*50,(event->pos().y()/50)*50);
            m_currentmouse = t;
            Rubbish *rubbish_t = new Rubbish(t,m_rotate);
            m_rubbishlist.push_back(rubbish_t);
            is_rubbish[t.x()/50][t.y()/50] = true;

            update();
        }
        else{
            update();
        }
    }
    else if(event->button()==Qt::LeftButton&&signal==3){
        if(!belt_release){
            belt_release = true;
        }
        if(is_map[event->pos().x()/50][event->pos().y()/50]&&!is_block[event->pos().x()/50][event->pos().y()/50]&&!is_center[event->pos().x()/50][event->pos().y()/50]&&!is_center[event->pos().x()/50][event->pos().y()/50]&&!is_circle[event->pos().x()/50][event->pos().y()/50]&&!is_rect[event->pos().x()/50][event->pos().y()/50]&&!is_belt[event->pos().x()/50][event->pos().y()/50]&&!is_rubbish[event->pos().x()/50][event->pos().y()/50]&&!is_cutter[event->pos().x()/50][event->pos().y()/50]){
            QPoint t = QPoint((event->pos().x()/50)*50,(event->pos().y()/50)*50);
            m_currentmouse = t;
            Belt *belt_t = new Belt(t,m_rotate,belt_rotate);
            m_beltlist.push_back(belt_t);
            is_belt[t.x()/50][t.y()/50] = true;
            belt_num[t.x()/50][t.y()/50] = belt_rotate;

            update();
        }
        else{
            update();
        }
    }
    else if(event->button()==Qt::LeftButton&&signal==4){
        if(!cutter_release){
            cutter_release = true;
        }
        if(is_map[event->pos().x()/50][event->pos().y()/50]&&!is_block[event->pos().x()/50][event->pos().y()/50]&&!is_center[event->pos().x()/50][event->pos().y()/50]&&!is_center[event->pos().x()/50][event->pos().y()/50]&&!is_circle[event->pos().x()/50][event->pos().y()/50]&&!is_rect[event->pos().x()/50][event->pos().y()/50]&&!is_belt[event->pos().x()/50][event->pos().y()/50]&&!is_rubbish[event->pos().x()/50][event->pos().y()/50]&&!is_cutter[event->pos().x()/50][event->pos().y()/50]){
            QPoint t = QPoint((event->pos().x()/50)*50,(event->pos().y()/50)*50);
            m_currentmouse = t;
            Cutter *cutter_t = new Cutter(t.x(),t.y(),m_rotate);
            m_cutterlist.push_back(cutter_t);
            switch(cutter_t->rotate){
            case 0:
                is_cutter[t.x()/50][t.y()/50] = true;
                is_cutter[t.x()/50+1][t.y()/50] = true;
                cutter_num[t.x()/50][t.y()/50] = 1;
                break;
            case 90:
                is_cutter[t.x()/50][t.y()/50] = true;
                is_cutter[t.x()/50][t.y()/50+1] = true;
                cutter_num[t.x()/50][t.y()/50] = 2;
                break;
            case 180:
                is_cutter[t.x()/50-1][t.y()/50] = true;
                is_cutter[t.x()/50][t.y()/50] = true;
                cutter_num[t.x()/50][t.y()/50] = 3;
                break;
            case 270:
                is_cutter[t.x()/50][t.y()/50-1] = true;
                is_cutter[t.x()/50][t.y()/50] = true;
                cutter_num[t.x()/50][t.y()/50] = 4;
                break;
            default:
                break;
            }

            update();
        }
        else{
            update();
        }
    }
    else if(event->button()==Qt::LeftButton&&signal==5){
        if(!gold_release){
            gold_release = true;
        }
        if((is_circle[event->pos().x()/50][event->pos().y()/50]||is_rect[event->pos().x()/50][event->pos().y()/50])&&!is_miner[event->pos().x()/50][event->pos().y()/50]&&!is_gold[event->pos().x()/50][event->pos().y()/50]){
            QPoint t = QPoint((event->pos().x()/50)*50,(event->pos().y()/50)*50);
            m_currentmouse = t;
            Gold *gold_t = new Gold(t.x(),t.y());
            m_goldlist.push_back(gold_t);
            is_gold[t.x()/50][t.y()/50] = true;

            update();
        }
        else{
            update();
        }
    }
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    if(signal>0&&event->key()==Qt::Key_E){
        m_rotate = (m_rotate + 90) % 360;
        update();
    }
    else if(signal>0&&event->key()==Qt::Key_Q){
        m_rotate = (m_rotate+270) % 360;
        update();
    }
    else if(signal>0&&event->key()==Qt::Key_T){
        belt_rotate = (belt_rotate+1)%12;
        update();
    }
    else if(signal>0&&event->key()==Qt::Key_R){
        belt_rotate = (belt_rotate+11)%12;
        update();
    }

}

void GameScene::drawyuan()
{
    for(auto current = m_yuanlist.begin();current!=m_yuanlist.end();)
    {
        Yuan *yuan = *current;
        if(!is_belt[yuan->x/50][yuan->y/50]){
            current = m_yuanlist.erase(current);
            delete yuan;
        }
        else{
            switch(belt_num[yuan->x/50][yuan->y/50]){
            case 0:
                is_yuan[yuan->x/50][yuan->y/50] = false;
                yuan->y-=yuan->speedy;
                if(is_center[yuan->x/50][yuan->y/50])
                {
                    break;
                }
                else{
                    if(!is_belt[yuan->x/50][yuan->y/50]||is_yuan[yuan->x/50][yuan->y/50])
                    {
                        yuan->y+=yuan->speedy;
                        is_yuan[yuan->x/50][yuan->y/50] = true;
                        break;
                    }
                }
            case 1:
                is_yuan[yuan->x/50][yuan->y/50] = false;
                yuan->x+=yuan->speedx;
                if(is_center[yuan->x/50][yuan->y/50])
                {
                    break;
                }
                else{
                    if(!is_belt[yuan->x/50][yuan->y/50]||is_yuan[yuan->x/50][yuan->y/50])
                    {
                        yuan->x-=yuan->speedx;
                        is_yuan[yuan->x/50][yuan->y/50] = true;
                        break;
                    }
                }
            case 2:
                is_yuan[yuan->x/50][yuan->y/50] = false;
                yuan->x+=yuan->speedx;
                if(is_center[yuan->x/50][yuan->y/50])
                {
                    break;
                }
                else{
                    if(!is_belt[yuan->x/50][yuan->y/50]||is_yuan[yuan->x/50][yuan->y/50])
                    {
                        yuan->x-=yuan->speedx;
                        is_yuan[yuan->x/50][yuan->y/50] = true;
                        break;
                    }
                }
            case 3:
                is_yuan[yuan->x/50][yuan->y/50] = false;
                yuan->y+=yuan->speedy;
                if(is_center[yuan->x/50][yuan->y/50])
                {
                    break;
                }
                else{
                    if(!is_belt[yuan->x/50][yuan->y/50]||is_yuan[yuan->x/50][yuan->y/50])
                    {
                        yuan->y-=yuan->speedy;
                        is_yuan[yuan->x/50][yuan->y/50] = true;
                        break;
                    }
                }
            case 4:
                is_yuan[yuan->x/50][yuan->y/50] = false;
                yuan->y+=yuan->speedy;
                if(is_center[yuan->x/50][yuan->y/50])
                {
                    break;
                }
                else{
                    if(!is_belt[yuan->x/50][yuan->y/50]||is_yuan[yuan->x/50][yuan->y/50])
                    {
                        yuan->y-=yuan->speedy;
                        is_yuan[yuan->x/50][yuan->y/50] = true;
                        break;
                    }
                }
            case 5:
                is_yuan[yuan->x/50][yuan->y/50] = false;
                yuan->x-=yuan->speedx;
                if(is_center[yuan->x/50][yuan->y/50])
                {
                    break;
                }
                else{
                    if(!is_belt[yuan->x/50][yuan->y/50]||is_yuan[yuan->x/50][yuan->y/50])
                    {
                        yuan->x+=yuan->speedx;
                        is_yuan[yuan->x/50][yuan->y/50] = true;
                        break;
                    }
                }
            case 6:
                is_yuan[yuan->x/50][yuan->y/50] = false;
                yuan->x-=yuan->speedx;
                if(is_center[yuan->x/50][yuan->y/50])
                {
                    break;
                }
                else{
                    if(!is_belt[yuan->x/50][yuan->y/50])
                    {
                        yuan->x+=yuan->speedx;
                        is_yuan[yuan->x/50][yuan->y/50] = true;
                        break;
                    }
                }
            case 7:
                is_yuan[yuan->x/50][yuan->y/50] = false;
                yuan->y-=yuan->speedy;
                if(is_center[yuan->x/50][yuan->y/50])
                {
                    break;
                }
                else{
                    if(!is_belt[yuan->x/50][yuan->y/50]||is_yuan[yuan->x/50][yuan->y/50])
                    {
                        yuan->y+=yuan->speedy;
                        is_yuan[yuan->x/50][yuan->y/50] = true;
                        break;
                    }
                }
            case 8:
                is_yuan[yuan->x/50][yuan->y/50] = false;
                yuan->y+=yuan->speedy;
                if(is_center[yuan->x/50][yuan->y/50])
                {
                    break;
                }
                else{
                    if(!is_belt[yuan->x/50][yuan->y/50]||is_yuan[yuan->x/50][yuan->y/50])
                    {
                        yuan->y-=yuan->speedy;
                        is_yuan[yuan->x/50][yuan->y/50] = true;
                        break;
                    }
                }
            case 9:
                is_yuan[yuan->x/50][yuan->y/50] = false;
                yuan->x+=yuan->speedx;
                if(is_center[yuan->x/50][yuan->y/50])
                {
                    break;
                }
                else{
                    if(!is_belt[yuan->x/50][yuan->y/50]||is_yuan[yuan->x/50][yuan->y/50])
                    {
                        yuan->x-=yuan->speedx;
                        is_yuan[yuan->x/50][yuan->y/50] = true;
                        break;
                    }
                }
            case 10:
                is_yuan[yuan->x/50][yuan->y/50] = false;
                yuan->y-=yuan->speedy;
                if(is_center[yuan->x/50][yuan->y/50])
                {
                    break;
                }
                else{
                    if(!is_belt[yuan->x/50][yuan->y/50]||is_yuan[yuan->x/50][yuan->y/50])
                    {
                        yuan->y+=yuan->speedy;
                        is_yuan[yuan->x/50][yuan->y/50] = true;
                        break;
                    }
                }
            case 11:
                is_yuan[yuan->x/50][yuan->y/50] = false;
                yuan->x-=yuan->speedx;
                if(is_center[yuan->x/50][yuan->y/50])
                {
                    break;
                }
                else{
                    if(!is_belt[yuan->x/50][yuan->y/50]||is_yuan[yuan->x/50][yuan->y/50])
                    {
                        yuan->x+=yuan->speedx;
                        is_yuan[yuan->x/50][yuan->y/50] = true;
                        break;
                    }
                }
            default:
                break;
            }
            if(is_center[yuan->x/50][yuan->y/50]){
                shop->money+=value1;
                num_yuan++;
                current = m_yuanlist.erase(current);
                delete yuan;
                if(num_yuan>=20){
                    num_yuan = 20;
                    if(!jiang1)
                    {
                        shengji->show();
                        jiang1 =true;
                    }
                }
            }
            else{
                current++;
            }
        }
    }
    update();
}

void GameScene::drawfang()
{
    for(auto current = m_fanglist.begin();current!=m_fanglist.end();)
    {
        Fang *fang = *current;
        if(!is_belt[fang->x/50][fang->y/50]){
            if(cutter_num[fang->x/50][fang->y/50]>0){
                switch(cutter_num[fang->x/50][fang->y/50]){
                case 1:
                    if(is_rubbish[fang->x/50+1][fang->y/50-1]){
                    fang->y-=fang->speedy;
                    fang->qiege = 3;
                    }
                    break;
                case 2:
                    if(is_rubbish[fang->x/50+1][fang->y/50+1]){
                        fang->x+=fang->speedx;
                        fang->qiege = 2;
                    }
                    break;
                case 3:
                    if(is_rubbish[fang->x/50-1][fang->y/50+1]){
                        fang->y+=fang->speedy;
                        fang->qiege = 4;
                    }
                    break;
                case 4:
                    if(is_rubbish[fang->x/50-1][fang->y/50-1]){
                        fang->x-=fang->speedx;
                        fang->qiege = 1;
                    }
                    break;
                default:
                    break;
                }
            }
        }
        else{
            switch(belt_num[fang->x/50][fang->y/50]){
            case 0:
                fang->y-=fang->speedy;
                break;
            case 1:
                fang->x+=fang->speedx;
                break;
            case 2:
                fang->x+=fang->speedx;
                break;
            case 3:
                fang->y+=fang->speedy;
                break;
            case 4:
                fang->y+=fang->speedy;
                break;
            case 5:
                fang->x-=fang->speedx;
                break;
            case 6:
                fang->x-=fang->speedx;
                break;
            case 7:
                fang->y-=fang->speedy;
                break;
            case 8:
                fang->y+=fang->speedy;
                break;
            case 9:
                fang->x+=fang->speedx;
                break;
            case 10:
                fang->y-=fang->speedy;
                break;
            case 11:
                fang->x-=fang->speedx;
                break;
            default:
                break;
            }
        }
        if((!is_belt[fang->x/50][fang->y/50]||is_center[fang->x/50][fang->y/50])&&cutter_num[fang->x/50][fang->y/50]==0){
            if(is_center[fang->x/50][fang->y/50]){
                if(fang->qiege==0){
                    shop->money+=value2;
                    num_fang++;
                    if(num_fang>=30){
                        num_fang = 30;
                        if(!jiang2)
                        {
                            shengji->show();
                            jiang2 = true;
                        }
                    }
                }
                else{
                    shop->money+=value3;
                    num_rect+=cutter_w;
                    if(num_rect>=50){
                        num_rect = 50;
                        if(!jiang3)
                        {
                            jiang3 = true;
                        }
                    }
                }
            }
            current = m_fanglist.erase(current);
            delete fang;
        }
        else{
            current++;
        }
    }
    update();
}

void GameScene::generateyuan()
{
    for(auto it = m_minerlist.begin(); it!=m_minerlist.end();it++){
        Miner *miner = *it;
        if(is_circle[miner->centerPos().x()/50][miner->centerPos().y()/50])
        {
            switch(miner->m_rotate()){
            case 0:
                if(is_belt[miner->centerPos().x()/50][miner->centerPos().y()/50-1]&&(belt_num[miner->centerPos().x()/50][miner->centerPos().y()/50-1]==0||belt_num[miner->centerPos().x()/50][miner->centerPos().y()/50-1]==1||belt_num[miner->centerPos().x()/50][miner->centerPos().y()/50-1]==11)){
                    Yuan *temp = new Yuan(miner->centerPos().x(),miner->centerPos().y()-50);
                    auto i = std::find_if(m_yuanlist.begin(),m_yuanlist.end(),[&temp](Yuan *yuan){
                        return yuan!= nullptr && yuan->x==temp->x && yuan->y==temp->y;
                    });
                    if(i==m_yuanlist.end())
                    {
                        m_yuanlist.push_back(temp);
                    }
                }
                break;
            case 90:
                if(is_belt[miner->centerPos().x()/50+1][miner->centerPos().y()/50]&&(belt_num[miner->centerPos().x()/50+1][miner->centerPos().y()/50]==2||belt_num[miner->centerPos().x()/50+1][miner->centerPos().y()/50]==3||belt_num[miner->centerPos().x()/50+1][miner->centerPos().y()/50]==10)){
                    Yuan *temp = new Yuan(miner->centerPos().x()+50,miner->centerPos().y());
                    auto i = std::find_if(m_yuanlist.begin(),m_yuanlist.end(),[&temp](Yuan *yuan){
                        return yuan!= nullptr && yuan->x==temp->x && yuan->y==temp->y;
                    });
                    if(i==m_yuanlist.end())
                    {
                        m_yuanlist.push_back(temp);
                    }
                }
                break;
            case 180:
                if(is_belt[miner->centerPos().x()/50][miner->centerPos().y()/50+1]&&(belt_num[miner->centerPos().x()/50][miner->centerPos().y()/50+1]==4||belt_num[miner->centerPos().x()/50][miner->centerPos().y()/50+1]==5||belt_num[miner->centerPos().x()/50][miner->centerPos().y()/50+1]==9)){
                    Yuan *temp = new Yuan(miner->centerPos().x(),miner->centerPos().y()+50);
                    auto i = std::find_if(m_yuanlist.begin(),m_yuanlist.end(),[&temp](Yuan *yuan){
                        return yuan!= nullptr && yuan->x==temp->x && yuan->y==temp->y;
                    });
                    if(i==m_yuanlist.end())
                    {
                        m_yuanlist.push_back(temp);
                    }
                }
                break;
            case 270:
                if(is_belt[miner->centerPos().x()/50-1][miner->centerPos().y()/50]&&(belt_num[miner->centerPos().x()/50-1][miner->centerPos().y()/50]==6||belt_num[miner->centerPos().x()/50-1][miner->centerPos().y()/50]==8||belt_num[miner->centerPos().x()/50-1][miner->centerPos().y()/50]==7)){
                    Yuan *temp = new Yuan(miner->centerPos().x()-50,miner->centerPos().y());
                    auto i = std::find_if(m_yuanlist.begin(),m_yuanlist.end(),[&temp](Yuan *yuan){
                        return yuan!= nullptr && yuan->x==temp->x && yuan->y==temp->y;
                    });
                    if(i==m_yuanlist.end())
                    {
                        m_yuanlist.push_back(temp);
                    }
                }
                break;
            default:
                break;
            }
        }
    }
    update();
}

void GameScene::generatefang()
{
    for(auto it = m_minerlist.begin(); it!=m_minerlist.end();it++){
        Miner *miner = *it;
        if(is_rect[miner->centerPos().x()/50][miner->centerPos().y()/50])
        {
            switch(miner->m_rotate()){
            case 0:
                if(is_belt[miner->centerPos().x()/50][miner->centerPos().y()/50-1]&&(belt_num[miner->centerPos().x()/50][miner->centerPos().y()/50-1]==0||belt_num[miner->centerPos().x()/50][miner->centerPos().y()/50-1]==1||belt_num[miner->centerPos().x()/50][miner->centerPos().y()/50-1]==11)){
                    Fang *temp = new Fang(miner->centerPos().x(),miner->centerPos().y()-50,0);
                    auto i = std::find_if(m_fanglist.begin(),m_fanglist.end(),[&temp](Fang *fang){
                        return fang!= nullptr && fang->x==temp->x && fang->y==temp->y;
                    });
                    if(i==m_fanglist.end())
                    {
                        m_fanglist.push_back(temp);
                    }
                }
                break;
            case 90:
                if(is_belt[miner->centerPos().x()/50+1][miner->centerPos().y()/50]&&(belt_num[miner->centerPos().x()/50+1][miner->centerPos().y()/50]==2||belt_num[miner->centerPos().x()/50+1][miner->centerPos().y()/50]==3||belt_num[miner->centerPos().x()/50+1][miner->centerPos().y()/50]==10)){
                    Fang *temp = new Fang(miner->centerPos().x()+50,miner->centerPos().y(),0);
                    auto i = std::find_if(m_fanglist.begin(),m_fanglist.end(),[&temp](Fang *fang){
                        return fang!= nullptr && fang->x==temp->x && fang->y==temp->y;
                    });
                    if(i==m_fanglist.end())
                    {
                        m_fanglist.push_back(temp);
                    }
                }
                break;
            case 180:
                if(is_belt[miner->centerPos().x()/50][miner->centerPos().y()/50+1]&&(belt_num[miner->centerPos().x()/50][miner->centerPos().y()/50+1]==4||belt_num[miner->centerPos().x()/50][miner->centerPos().y()/50+1]==5||belt_num[miner->centerPos().x()/50][miner->centerPos().y()/50+1]==9)){
                    Fang *temp = new Fang(miner->centerPos().x(),miner->centerPos().y()+50,0);
                    auto i = std::find_if(m_fanglist.begin(),m_fanglist.end(),[&temp](Fang *fang){
                        return fang!= nullptr && fang->x==temp->x && fang->y==temp->y;
                    });
                    if(i==m_fanglist.end())
                    {
                        m_fanglist.push_back(temp);
                    }
                }
                break;
            case 270:
                if(is_belt[miner->centerPos().x()/50-1][miner->centerPos().y()/50]&&(belt_num[miner->centerPos().x()/50-1][miner->centerPos().y()/50]==6||belt_num[miner->centerPos().x()/50-1][miner->centerPos().y()/50]==8||belt_num[miner->centerPos().x()/50-1][miner->centerPos().y()/50]==7)){
                    Fang *temp = new Fang(miner->centerPos().x()-50,miner->centerPos().y(),0);
                    auto i = std::find_if(m_fanglist.begin(),m_fanglist.end(),[&temp](Fang *fang){
                        return fang!= nullptr && fang->x==temp->x && fang->y==temp->y;
                    });
                    if(i==m_fanglist.end())
                    {
                        m_fanglist.push_back(temp);
                    }
                }
                break;
            default:
                break;
            }
        }
    }
    update();
}

void GameScene::paintEvent(QPaintEvent *event){
    str_money = QString("金 币 数: %1 ").arg(shop->money);
    ui->label_money->setText(str_money);
    str_yuan =QString("任 务一: 采集20个圆形矿物 已采集的圆形矿物数: %1/20").arg(num_yuan);
    ui->label_yuan->setText(str_yuan);
    str_fang =QString("任 务二: 采集30个方形矿物 已采集的方形矿物数: %1/30").arg(num_fang);
    ui->label_fang->setText(str_fang);
    str_rect =QString("任 务三: 采集50个半矩形矿物 已采集的半矩形矿物数: %1/50").arg(num_rect);
    ui->label_rect->setText(str_rect);
    if(jiang1&&jiang2&&jiang3)
    {
        end->show();
        this->close();
    }
    if(shengji->miner_rise||shengji->cutter_rise||shengji->belt_rise)
    {
        if(shengji->miner_rise)
        {
           ui->label->setText("当前强化设备：采矿机");
        }
        else if(shengji->cutter_rise)
        {
           ui->label->setText("当前强化设备：切割机");
        }
        else
        {
            ui->label->setText("当前强化设备：传送带");
        }
    }
    if(shengji->miner_rise)
    {
        timer3->setInterval(400);
        timer4->setInterval(400);
    }
    if(shengji->cutter_rise)
    {
        cutter_w = 2;
    }
    if(shengji->miner_rise)
    {
        timer3->setInterval(400);
        timer4->setInterval(400);
    }
    if(!shop->select1)
    {
        value1 = 10;
        value2 = 10;
        value3 = 20;
    }
    //绘制基础地块
    QPen pen(Qt::gray, 2);
    QPainter painter(this);
    painter.setPen(pen);
    for(int i=200;i <= 700; i+=50){
        painter.drawLine(0, i, 1000, i);
    }
    for(int j=0;j <= 1000;j+=50){
        painter.drawLine(j, 200, j, 700);
    }
    //绘制障碍物
    if(!shop->select2)
    {
        is_block[4][6] = false;
        is_block[4][7] = false;
        is_block[5][4] = false;
        is_block[7][8] = false;
        is_block[0][4] = false;
        is_block[6][12] = false;
        is_block[12][9] = false;
        is_block[13][11] = false;
    }
    else
    {
        for(int i = 0; i < m_block.size();i++){
            m_block[i].draw(&painter);
        }
    }
    //绘制圆形矿物
    for(int i = 0; i < m_circle.size();i++){
        m_circle[i].draw(&painter);
    }
    //绘制方形矿物
    for(int i = 0; i < m_rect.size();i++){
        m_rect[i].draw(&painter);
    }
    //绘制交付中心
    if(!shop->select3)
    {
        is_center[8][8] = true;
        is_center[9][8] = true;
        is_center[10][8] = true;
        is_center[11][8] = true;
        is_center[8][9] = true;
        is_center[11][9] = true;
        is_center[8][10] = true;
        is_center[11][10] = true;
        is_center[8][11] = true;
        is_center[9][11] = true;
        is_center[10][11] = true;
        is_center[11][11] = true;
        is_belt[9][9] = false;
        is_belt[9][10] = false;
        is_belt[10][9] = false;
        is_belt[10][10] = false;
        is_belt[8][8] = false;
        is_belt[9][8] = false;
        is_belt[10][8] = false;
        is_belt[11][8] = false;
        is_belt[8][9] = false;
        is_belt[11][9] = false;
        is_belt[8][10] = false;
        is_belt[11][10] = false;
        is_belt[8][11] = false;
        is_belt[9][11] = false;
        is_belt[10][11] = false;
        is_belt[11][11] = false;
        painter.drawPixmap(400,400,200,200,QPixmap(":/image/center2.png"));
    }
    else{
        m_center[0].draw(&painter);
    }

    if(signal==1&&!miner_release&&is_map[m_currentmouse.x()/50][m_currentmouse.y()/50]){
        Miner miner_temp = Miner(m_currentmouse,m_rotate);
        miner_temp.draw(&painter,m_rotate);
    }
    if(signal==1&&miner_release){
        miner_release = false;
    }
    foreach (Miner *miner, m_minerlist) {
        miner->draw(&painter,miner->m_rotate());
    }
    if(signal==2&&!rubbish_release&&is_map[m_currentmouse.x()/50][m_currentmouse.y()/50]){
        Rubbish rubbish_temp = Rubbish(m_currentmouse,m_rotate);
        rubbish_temp.draw(&painter,m_rotate);
    }
    if(signal==2&&rubbish_release){
        rubbish_release = false;
    }
    foreach (Rubbish *rubbish, m_rubbishlist) {
        rubbish->draw(&painter,rubbish->r_rotate());
    }
    if(signal==3&&!belt_release&&is_map[m_currentmouse.x()/50][m_currentmouse.y()/50]){
        Belt belt_temp = Belt(m_currentmouse,m_rotate,belt_rotate);
        belt_temp.draw(&painter,belt_rotate);
    }
    if(signal==3&&belt_release){
        belt_release = false;
    }
    foreach (Belt *belt, m_beltlist) {
        belt->draw(&painter,belt->rotate);
    }
    if(signal==4&&!cutter_release&&is_map[m_currentmouse.x()/50][m_currentmouse.y()/50]){
        Cutter cutter_temp = Cutter(m_currentmouse.x(),m_currentmouse.y(),m_rotate);
        cutter_temp.draw(&painter);
    }
    if(signal==4&&cutter_release){
        cutter_release = false;
    }
    foreach (Cutter *cutter, m_cutterlist) {
        cutter->draw(&painter);
    }
    foreach (Yuan *yuan, m_yuanlist) {
        yuan->draw(&painter);
    }
    foreach (Fang *fang, m_fanglist) {
        fang->draw(&painter);
    }
    if(signal==5&&!gold_release&&is_map[m_currentmouse.x()/50][m_currentmouse.y()/50]){
        Gold gold_temp = Gold(m_currentmouse.x(),m_currentmouse.y());
        gold_temp.draw(&painter);
    }
    if(signal==5&&gold_release){
        gold_release = false;
    }
    foreach (Gold *gold, m_goldlist) {
        gold->draw(&painter);
    }
}

void GameScene::saveGame()
{
    QString path = QFileDialog::getSaveFileName(this,"write","../");
    if(path.isEmpty() == false)
    {
        QFile file;            //创建对象
        file.setFileName(path);
        QDataStream out(&file);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "金币数" << '\n';
            out << shop->money << '\n';
            out << "任务一（完成：1 未完成：0）" << '\n';
            out << jiang1 << '\n';
            out << "任务二（完成：1 未完成：0）" << '\n';
            out << jiang2 << '\n';
            out << "任务三（完成：1 未完成：0）" << '\n';
            out << jiang3 << '\n';
            out << "采矿机（已升级：1 未升级：0）" << '\n';
            out << shengji->miner_rise << '\n';
            out << "切割机（已升级：1 未升级：0）" << '\n';
            out << shengji->cutter_rise << '\n';
            out << "传送带（已升级：1 未升级：0）" << '\n';
            out << shengji->belt_rise << '\n';
            out << "已采集的圆形矿物数" << '\n';
            out << num_yuan << '\n';
            out << "已采集的方形矿物数" << '\n';
            out << num_fang << '\n';
            out << "已采集的矩形矿物数" << '\n';
            out << num_rect << '\n';
            out << "商店升级项目1（已升级：0 未升级：1）" << '\n';
            out << shop->select1 << '\n';
            out << "商店升级项目1（已升级：0 未升级：1）" << '\n';
            out << shop->select2 << '\n';
            out << "商店升级项目1（已升级：0 未升级：1）" << '\n';
            out << shop->select3 << '\n';
            file.close(); //
        } else {
            qDebug() << "无法打开文件：" << file.errorString();
        }
    }

}

void GameScene::LoadGame(QTextStream &in)
{
    QString line;
    line = in.readLine().trimmed();
    line = in.readLine().trimmed();
    bool ok;
    int number = line.toInt(&ok);
    shop->money = number;
    line = in.readLine().trimmed();
    line = in.readLine().trimmed();
    number = line.toInt(&ok);
    jiang1 = number;
    line = in.readLine().trimmed();
    line = in.readLine().trimmed();
    number = line.toInt(&ok);
    jiang2 = number;
    line = in.readLine().trimmed();
    line = in.readLine().trimmed();
    number = line.toInt(&ok);
    jiang3 = number;
    line = in.readLine().trimmed();
    line = in.readLine().trimmed();
    number = line.toInt(&ok);
    shengji->miner_rise = number;
    line = in.readLine().trimmed();
    line = in.readLine().trimmed();
    number = line.toInt(&ok);
    shengji->cutter_rise = number;
    line = in.readLine().trimmed();
    line = in.readLine().trimmed();
    number = line.toInt(&ok);
    shengji->belt_rise = number;
    line = in.readLine().trimmed();
    line = in.readLine().trimmed();
    number = line.toInt(&ok);
    num_yuan = number;
    line = in.readLine().trimmed();
    line = in.readLine().trimmed();
    number = line.toInt(&ok);
    num_fang = number;
    line = in.readLine().trimmed();
    line = in.readLine().trimmed();
    number = line.toInt(&ok);
    num_rect = number;
    line = in.readLine().trimmed();
    line = in.readLine().trimmed();
    number = line.toInt(&ok);
    shop->select1 = number;
    line = in.readLine().trimmed();
    line = in.readLine().trimmed();
    number = line.toInt(&ok);
    shop->select2 = number;
    line = in.readLine().trimmed();
    line = in.readLine().trimmed();
    number = line.toInt(&ok);
    shop->select3 = number;
}



