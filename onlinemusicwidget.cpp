#include "onlinemusicwidget.h"
#include "ui_onlinemusicwidget.h"

OnlineMusicWidget::OnlineMusicWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OnlineMusicWidget)
{
    ui->setupUi(this);
}

OnlineMusicWidget::~OnlineMusicWidget()
{
    delete ui;
}
