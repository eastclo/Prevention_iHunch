#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_iHunch.h"
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QAction>
#include <QWidget>
#include <QMenu>
#include <QStyle>
#include <Windows.h>
#include <QMultimedia>
#include "setupPose.h"
#include <QMediaPlayer>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class iHunchClass; }
QT_END_NAMESPACE

class iHunch : public QMainWindow
{
    Q_OBJECT

public:
    iHunch(QWidget *parent = Q_NULLPTR);
    ~iHunch();
    //알람 호출함수
    void alramMessage();

protected:
    //최소화 되었을 떄 또는 위젯 창이 닫혔을 때 호출
    void closeEvent(QCloseEvent* event);

private:
    Ui::iHunchClass* ui;
    //트레이아이콘 클래스 인스턴스
    QSystemTrayIcon* m_trayicon;
    setupPose* setuppose;

    //시작버튼
    bool started = false;
    //효과음
    QMediaPlayer* m_player;
    //알람 체크박스 체크 되어있는지
    bool sound_check;
    bool popup_check;

public slots:
    //시스템 트레이 아이콘 클릭 이벤트로부터 시그널을 처리하는 slot함수
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    //자세 설정 창 띄우기
    void setPose();
    void modeChanged(int mode);
    //시작버튼
    void mybtn();
};
