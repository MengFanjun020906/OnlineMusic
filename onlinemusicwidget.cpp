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


    // 播放进度条控件美化
    ui->horizontalSlider_PlayProgress->setStyleSheet("QSlider::groove:horizontal {"
                                                     "    border: 1px solid #bbb;"
                                                     "    background: white;"
                                                     "    height: 10px;"
                                                     "    border-radius: 5px;"
                                                     "}"
                                                     "QSlider::sub-page:horizontal {"
                                                     "    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #66e, stop: 1 #bbf);"
                                                     "    border: 1px solid #777;"
                                                     "    height: 10px;"
                                                     "    border-radius: 5px;"
                                                     "}"
                                                     "QSlider::add-page:horizontal {"
                                                     "    background: #fff;"
                                                     "    border: 1px solid #777;"
                                                     "    height: 10px;"
                                                     "    border-radius: 5px;"
                                                     "}"
                                                     "QSlider::handle:horizontal {"
                                                     "    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #eee, stop:1 #ccc);"
                                                     "    border: 1px solid #777;"
                                                     "    width: 18px;"
                                                     "    margin-top: -4px;"
                                                     "    margin-bottom: -4px;"
                                                     "    border-radius: 9px;"
                                                     "}");


    ui->horizontalSlider_Volume->setStyleSheet("QSlider::groove:horizontal {"
                                                     "    border: 1px solid #bbb;"
                                                     "    background: white;"
                                                     "    height: 10px;"
                                                     "    border-radius: 5px;"
                                                     "}"
                                                     "QSlider::sub-page:horizontal {"
                                                     "    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #66e, stop: 1 #bbf);"
                                                     "    border: 1px solid #777;"
                                                     "    height: 10px;"
                                                     "    border-radius: 5px;"
                                                     "}"
                                                     "QSlider::add-page:horizontal {"
                                                     "    background: #fff;"
                                                     "    border: 1px solid #777;"
                                                     "    height: 10px;"
                                                     "    border-radius: 5px;"
                                                     "}"
                                                     "QSlider::handle:horizontal {"
                                                     "    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #eee, stop:1 #ccc);"
                                                     "    border: 1px solid #777;"
                                                     "    width: 18px;"
                                                     "    margin-top: -4px;"
                                                     "    margin-bottom: -4px;"
                                                     "    border-radius: 9px;"
                                                     "}");
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

//音乐歌曲下载和播放
void OnlineMusicWidget::DownloadPlayer(QString album_id,QString hash)
{

}


//访问HTTP网页
void OnlineMusicWidget::HttpAccessFunc(QString)
{

}

//音乐的hash和ablum_id值解析(使用JSON)
void OnlineMusicWidget::HashJsonAnalysis(QByteArray)
{

}

//搜索音乐数据信息的JSON解析，解析真是的音乐文件和歌词
// QString OnlineMusicWidget::MusicJsonAnalysis(QByteArray)
// {

// }

// 鼠标拖动窗口实现移动


void OnlineMusicWidget::mouseMoveEvent(QMouseEvent *et)
{
    if(mousepress)
    {
        QPoint movePos=et->globalPos();//窗口初始位置
        move(movePos-movepoint);
    }
}
void OnlineMusicWidget::mousePressEvent(QMouseEvent *et)
{
    if(et->button()==Qt::LeftButton)
    {
        mousepress=true;
    }
    // 窗口移动距离
    movepoint=et->globalPos()-pos();

}
void OnlineMusicWidget::mouseReleaseEvent(QMouseEvent *et)
{
    Q_UNUSED(et);
    mousepress=false;
}

void OnlineMusicWidget::on_pushButton_AddSong_clicked()
{

}


void OnlineMusicWidget::on_pushButton_PlaySong_clicked()
{

}


void OnlineMusicWidget::on_pushButton_PauseSong_clicked()
{

}


void OnlineMusicWidget::on_pushButton_StopPlaySong_clicked()
{

}


void OnlineMusicWidget::on_pushButton_PreviousSong_clicked()
{

}


void OnlineMusicWidget::on_pushButton_NextSong_clicked()
{

}


void OnlineMusicWidget::on_pushButton_NextSong_2_clicked()
{

}


void OnlineMusicWidget::on_pushButton_SoundYesNo_clicked()
{

}


void OnlineMusicWidget::on_pushButton_About_clicked()
{
    //QMessageBox::information(this,"提示","这是一个基于QT的音频播放器项目",QMessageBox::Yes);


    AboutDialog *pAboutDialogs=new AboutDialog(this);


    pAboutDialogs->exec();
}

