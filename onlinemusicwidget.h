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

private:
    Ui::OnlineMusicWidget *ui;
};
#endif // ONLINEMUSICWIDGET_H
