#include "end.h"
#include "ui_end.h"

End::End(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::End)
{
    ui->setupUi(this);
    setFixedSize(1000,800);
    QPixmap pixmap(":/image/win.jpg");
    pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->label->setScaledContents(true);
    ui->label->setPixmap(pixmap);
}

End::~End()
{
    delete ui;
}
