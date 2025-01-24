#include "onlinemusicwidget.h"
#include "ui_onlinemusicwidget.h"
#include "playlist.h"
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

    //将光标焦点定位到搜索歌曲名称的控件
    ui->lineEdit_InputSong->setFocus();

    //初始化
    NetworkAccessManager = new QNetworkAccessManager(this);

    iPos=0;

    //初始文本对象
    docTextObject = ui->plainTextEdit_SongList->document();

    //将控件设置为只读
    ui->plainTextEdit_SongList->setReadOnly(true);

    //初始化多媒体实例
    p_PlayerObject=new QMediaPlayer(this);
    //p_PlayerList = new
    Playlist *p_PlayList = new Playlist(this);

    //设置播放列表
    //p_PlayerObject->setSource(p_PlayList);
    //设置播放模式
    p_PlayList->setPlaybackMode(Playlist::Loop);

    //信号与槽处理如下
    connect(p_PlayerObject,SIGNAL(positionChanged(qint64)),this,SLOT(HandleLCDNumberTimeChangeFunc(qint64)));
    connect(p_PlayerObject,SIGNAL(positionChanged(qint64)),this,SLOT(HandlePositionChangeFunc(qint64)));
    connect(p_PlayerObject,SIGNAL(positionChanged(qint64)),this,SLOT(HandleProgressTimeChangeFunc(qint64)));
    connect(NetworkAccessManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(HandleDataBackFunc(QNetworkReply*)));



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

//处理数据信息返回函数
void OnlineMusicWidget::HandleDataBackFunc(QNetworkReply *pReply)
{
    //读取网络回款数据
    QByteArySearchInfo = pReply->readAll();

    QJsonParseError JSonPError;//定义错误信息对象

    //将json文本转换为json文件对象
    QJsonDocument JSonDoc_RecvData=QJsonDocument::fromJson(QByteArySearchInfo,&JSonPError);
    if(JSonPError.error!=QJsonParseError::NoError)//判断是否符合规则
    {
        QMessageBox::critical(this,"Prompt","提示：获取歌曲json出错，请重新检查",QMessageBox::Yes);
        return;
    }
    //QJsonObject使用函数object();
    QJsonObject TotalJsonObject = JSonDoc_RecvData.object();

    //列出json里面的所有key
    QStringList strKeys=TotalJsonObject.keys();

    if(strKeys.contains("result"))//与数据信息
    {
        //将带有result的数据内容提取之后转换为对象
        QJsonObject resultobject=TotalJsonObject["result"].toObject();

        //存储所有keys
        QStringList strResultKeys=resultobject.keys();

        if(strResultKeys.contains("songs"))
        {
            QJsonArray array=resultobject["songs"].toArray();

            //通过for循环查找歌曲当中的字段信息
            for(auto isong:array)
            {
                QJsonObject jsonobject1 = isong.toObject();
                //获取歌曲ID 歌名 歌手
                I_MusicID = jsonobject1["id"].toInt();
                StrMusicName = jsonobject1["name"].toString();


                QStringList strkeys = jsonobject1.keys();

                if(strkeys.contains("artists"))
                {
                    QJsonArray artitstsjsonarray= jsonobject1["artists"].toArray();
                    for(auto js:artitstsjsonarray)
                    {
                        QJsonObject jsonobject2=js.toObject();
                        StrSingerName = jsonobject2["name"].toString();
                    }
                }
            }
        }

    }
    // 生成歌曲 URL
    QString url = QString("https://music.163.com/song/media/outer/url?id=%0").arg(I_MusicID);

    // 创建一个 QVariantMap 并将歌曲 URL 存储在 "path" 键下
    QVariantMap song;
    song["path"] = url;
    // 调用 appendSong 函数将歌曲添加到播放列表
    p_PlayList->appendSong(song);

    ui->plainTextEdit_SongList->appendPlainText(StrMusicName+"-"+StrSingerName);

}
//处理LCD控件时间变化
void OnlineMusicWidget::HandleLCDNumberTimeChangeFunc(qint64 duration)
{

}
// 处理进度条控件变化
void OnlineMusicWidget::HandleProgressTimeChangeFunc(qint64 duration)
{

}
// 处理播放位置变换
void OnlineMusicWidget::HandlePositionChangeFunc(qint64 position)
{

}

//处理播放歌曲
void OnlineMusicWidget::HanglePlaySongFunc()
{

}
//搜索歌曲名称实现
void OnlineMusicWidget::on_pushButton_SearchSong_clicked()
{
    QString str1,str2;
    str1=ui->lineEdit_InputSong->text();


    str2="http://music.163.com/api/search/get/web?csrf_token=hlpretag=&hlposttag=&s={"+str1+"}&type=1&offset=0&total=true&limit=1";

    //定义一个请求对象
    QNetworkRequest networkRequest;
    networkRequest.setUrl(str2);

    //将请求格式设置给对应请求对象
    networkRequest.setUrl(str2);
    //使用QNetworkAccessManager类对应的API发送GET请求并获取响应数据





    NetworkAccessManager->get(networkRequest);

}

