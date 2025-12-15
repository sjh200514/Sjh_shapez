#include "mainscene.h"
#include "ui_mainscene.h"
#include <QTimer>
#include <QPushButton>
#include <QMediaPlayer>
#include <QFile>
#include <QFileDialog>
#include <QDebug>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    setFixedSize(1000,800);
    setWindowIcon(QIcon(":/image/starticon.jpg"));
    setWindowTitle("开始游戏吧！");
    gamescene = new GameScene;

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.5);  //调节音频音量
    player->setSource(QUrl("qrc:/image/ne.mp3"));
    player->play();
    player->setLoops(999);
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::on_btn_start_clicked(bool checked)
{
    QTimer::singleShot(300,this,[=](){
        this->hide();
        gamescene->show();
    });
}

void MainScene::on_btn_continue_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Read File", "../");
    if(!path.isEmpty())
    {
        QFile file; // 创建QFile对象
        file.setFileName(path);
        // 打开文件，只读
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "打开文件失败！";
            return;
        }

        QTextStream in(&file);
        gamescene->LoadGame(in);
        file.close();
        this->hide();
        gamescene->show();
    }
}
