#ifndef ONLINEMUSICWIDGET_H
#define ONLINEMUSICWIDGET_H

#include <QMainWindow>

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

private:
    Ui::OnlineMusicWidget *ui;
};
#endif // ONLINEMUSICWIDGET_H
