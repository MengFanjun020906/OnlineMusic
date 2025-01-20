#ifndef ONLINEMUSICWIDGET_H
#define ONLINEMUSICWIDGET_H

#include <QMainWindow>

#include <QNetworkRequest> //HTTP的URL请求管理类
#include <QNetworkAccessManager>//使用该类可以进行网络请求、获取响应
#include <QNetworkReply>//是QNetworkAccessManager发送请求后的响应类
#include <QEventLoop>
#include <QJsonArray>
#include <QJsonObject>
//添加多媒体播放器类
#include <QMediaPlayer>
#include <QtMultimedia>
#include <QTextBlock>
#include <QTimer>
#include <QFileDialog>
#include <QJsonParseError>
#include<QJsonObject>
#include <QLCDNumber>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTime>
#include <QMouseEvent>
#include <aboutdialog.h>
#include <playlist.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class OnlineMusicWidget;
}
QT_END_NAMESPACE

class OnlineMusicWidget : public QMainWindow
{
    Q_OBJECT

public:
    OnlineMusicWidget(QWidget *parent = nullptr);
    ~OnlineMusicWidget();

    //处理播放器背景画布
    void paintEvent(QPaintEvent *event);


    //自定义槽函数
public slots:
    //处理数据信息返回函数
    void HandleDataBackFunc(QNetworkReply *pReply);
    //处理LCD控件时间变化
    void HandleLCDNumberTimeChangeFunc(qint64 duration);
    // 处理进度条控件变化
    void HandleProgressTimeChangeFunc(qint64 duration);
    // 处理播放位置变换
    void HandlePositionChangeFunc(qint64 position);

    //处理播放歌曲
    void HanglePlaySongFunc();

private slots:
    void on_pushButton_Close_clicked();

    void on_pushButton_AddSong_clicked();

    void on_pushButton_PlaySong_clicked();

    void on_pushButton_PauseSong_clicked();

    void on_pushButton_StopPlaySong_clicked();

    void on_pushButton_PreviousSong_clicked();

    void on_pushButton_NextSong_clicked();

    void on_pushButton_NextSong_2_clicked();

    void on_pushButton_SoundYesNo_clicked();

    void on_pushButton_About_clicked();

    void on_pushButton_SearchSong_clicked();

private:
    Ui::OnlineMusicWidget *ui;


protected:
    //音乐歌曲下载和播放
    void DownloadPlayer(QString album_id,QString hash);

    //访问HTTP网页
    void HttpAccessFunc(QString);

    //音乐的hash和ablum_id值解析(使用JSON)
    void HashJsonAnalysis(QByteArray);

    //搜索音乐数据信息的JSON解析，解析真是的音乐文件和歌词
    QString MusicJsonAnalysis(QByteArray);

protected:
    // 鼠标拖动窗口实现移动
    void mouseMoveEvent(QMouseEvent *et);//移动事件
    void mousePressEvent(QMouseEvent *et);//按住事件
    void mouseReleaseEvent(QMouseEvent *et);//释放时间

public:
    QMediaPlayer *p_PlayerObject;//定义播放器对象
    //QMediaPlaylist *P_PlayerList; 定义播放器列表
    QMediaPlayer* player = new QMediaPlayer;




    QByteArray QBbyteArySearchInfo;//存储搜索数据信息
    QString StrLoaclMusicPath;//导入本地音乐路径

    //歌曲ID
    int I_MusicID;
    // 歌曲名称 歌手姓名
    QString StrMusicName,StrSingerName;

    QTextDocument *docTextObject;//处理富文本内容
    QTextBlock *qRextLine;//处理文本块指针

    int iPos; //标记

    QNetworkAccessManager *NetworkAccessManager;






private:
    //定义坐标
    QPoint m_mousepoint;
    QPoint movepoint;
    bool mousepress;


};




#endif // ONLINEMUSICWIDGET_H
