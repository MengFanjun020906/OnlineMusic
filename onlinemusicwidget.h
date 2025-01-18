#ifndef ONLINEMUSICWIDGET_H
#define ONLINEMUSICWIDGET_H

#include <QMainWindow>

#include <QNetworkRequest> //HTTP的URL请求管理类
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonArray>
#include <QJsonObject>
#include <QMediaPlayer>
//#include <QMediaPlaylist>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTime>
#include<math.h>
#include <QMouseEvent>
#include <QMessageBox>
#include <aboutdialog.h>
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

private:
    //定义坐标
    QPoint m_mousepoint;
    QPoint movepoint;
    bool mousepress;



};




#endif // ONLINEMUSICWIDGET_H
