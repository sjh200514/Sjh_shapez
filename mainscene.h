#ifndef MAINSCENE_H
#define MAINSCENE_H
//游戏开始界面实现
#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "gamescene.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainScene;
}
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
    QMediaPlayer *player = nullptr;
    QAudioOutput *audioOutput = nullptr;

private slots:
    void on_btn_start_clicked(bool checked);

    void on_btn_continue_clicked();

private:
    Ui::MainScene *ui;
    GameScene *gamescene;

};
#endif // MAINSCENE_H
