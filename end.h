#ifndef END_H
#define END_H
//通关界面实现
#include <QMainWindow>
#include <QPixmap>

namespace Ui {
class End;
}

class End : public QMainWindow
{
    Q_OBJECT

public:
    explicit End(QWidget *parent = nullptr);
    ~End();

private:
    Ui::End *ui;
};

#endif // END_H
