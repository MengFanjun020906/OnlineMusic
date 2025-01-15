#include "onlinemusicwidget.h"
#include "ui_onlinemusicwidget.h"

#include "QPainter"

OnlineMusicWidget::OnlineMusicWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OnlineMusicWidget)
{
    ui->setupUi(this);

    //禁止窗口改变尺寸
    this->setFixedSize(this->geometry().size());
    //去掉窗口标题
    this->setWindowFlag(Qt::FramelessWindowHint);
}

OnlineMusicWidget::~OnlineMusicWidget()
{
    delete ui;


}
void OnlineMusicWidget:: paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //更改背景图片
    painter.drawPixmap(0,0,width(),height(),QPixmap(":/new/prefix1/Images/musicplayer_ui.png"));
}

void OnlineMusicWidget::on_pushButton_Close_clicked()
{
    //关闭窗口
    close();
}

