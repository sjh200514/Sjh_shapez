#ifndef GAMESCENE_H
#define GAMESCENE_H
//游戏主场景
#include <QMainWindow>
#include "block.h"
#include "circle.h"
#include "rect.h"
#include "center.h"
#include "miner.h"
#include "rubbish.h"
#include "belt.h"
#include "yuan.h"
#include "fang.h"
#include "cutter.h"
#include "shengji.h"
#include "end.h"
#include "shopping.h"
#include "gold.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTimer>
#include <QFile>
#include <QFileDialog>

namespace Ui {
class GameScene;
}

class GameScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameScene(QWidget *parent = nullptr);//构造函数
    ~GameScene();//析构函数

    void paintEvent(QPaintEvent *event);//绘图事件函数重载
    void mousePressEvent(QMouseEvent *event);//鼠标点击事件重载
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动事件重载
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放事件重载
    void keyPressEvent(QKeyEvent *event);//键盘事件重载

    void setboundary();//设置地图边界
    void loadblock();//加载矿地
    void loadcenter();//加载交付中心
    void loadrect();//加载矩形矿地
    void loadcircle();//加载圆形矿地
    void loadminer();//加载采矿机
    void loadrubbish();//加载垃圾桶
    void loadbelt();//加载传送带
    void loadcutter();//加载切割机
    void loadgold();//加载点石成金机

    void addminer(QMouseEvent *event);//添加采矿机
    void addrubbish(QMouseEvent *event);//添加垃圾桶
    void addbelt(QMouseEvent *event);//添加传送带
    void addcutter(QMouseEvent *event);//添加切割机
    void addgold(QMouseEvent *event); //添加点石成金机

    void deleteminer(QMouseEvent *event);//去除采矿机
    void deleterubbish(QMouseEvent *event);//去除垃圾桶
    void deletebelt(QMouseEvent *event);//去除传送带
    void deletecutter(QMouseEvent *event);//去除切割机
    void deletegold(QMouseEvent *event);//去除点石成金机

    //矿物的逻辑生成以及位置变化
    void drawyuan();
    void drawfang();
    void generateyuan();
    void generatefang();

    //存档
    void saveGame();
    void LoadGame(QTextStream &in);

    //定时器
    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;
    QTimer *timer5;

    QString str_money;
    QString str_yuan;
    QString str_fang;
    QString str_rect;

    friend class MainScene;

private slots:


private:
    Ui::GameScene *ui;

    QList<Block> m_block;
    QList<Circle> m_circle;
    QList<Rect> m_rect;
    QList<Center> m_center;
    QList<Miner> m_miner;
    QList<Miner*> m_minerlist;
    QList<Rubbish> m_rubbish;
    QList<Rubbish*> m_rubbishlist;
    QList<Belt> m_belt;
    QList<Belt*> m_beltlist;
    QList<Yuan*> m_yuanlist;
    QList<Fang*> m_fanglist;
    QList<Cutter> m_cutter;
    QList<Cutter*> m_cutterlist;
    QList<Gold> m_gold;
    QList<Gold*> m_goldlist;

    QPoint m_currentmouse;
    int m_rotate = 0;
    int belt_rotate = 0;
    int signal = 0;
    int guanqia = 1;
    int num_yuan = 0;
    int num_fang = 0;
    int num_rect = 0;
    int value1 = 5;
    int value2 = 5;
    int value3 = 10;
    int time1_ = 2000;
    int time2_ = 800;
    int cutter_w = 1;

    bool jiang1 = false;
    bool jiang2 = false;
    bool jiang3 = false;


    bool miner_release = false;
    bool rubbish_release = false;
    bool belt_release = false;
    bool cutter_release = false;
    bool gold_release = false;

    bool is_map[20][16];
    bool is_center[20][16];
    bool is_block[20][16];
    bool is_circle[20][16];
    bool is_rect[20][16];
    bool is_miner[20][16];
    bool is_rubbish[20][16];
    bool is_belt[20][16];
    bool is_cutter[20][16];
    bool is_yuan[20][20];
    bool is_gold[20][16];
    int miner_num[20][16] = {0};
    int belt_num[20][16] = {0};
    int cutter_num[20][16] = {0};
    Shopping *shop;
    Shengji *shengji;
    End *end;

};

#endif // GAMESCENE_H
