#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_iHunch.h"
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QAction>
#include <QWidget>
#include <QMenu>
#include <QMovie>
#include <QStyle>
#include <QProcess>
#include <Windows.h>
#include <QMultimedia>
#include "setupPose.h"
#include <QMediaPlayer>
#include <QFileDialog>
#include "overlay.h"

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class iHunchClass; }
QT_END_NAMESPACE

using namespace std;

class iHunch : public QMainWindow
{
    Q_OBJECT

public:
    setupPose* setuppose;
    overlay* over;
    iHunch(QWidget *parent = Q_NULLPTR);
    ~iHunch();

private:
    Ui::iHunchClass* ui;
    //트레이아이콘 클래스 인스턴스
    QSystemTrayIcon* m_trayicon;
    QComboBox* timeIntervalComboBox;
    QComboBox* unHealthComboBox;
    QSlider* poseFixSlider;

    //시작버튼
    bool started = false;
    //효과음
    QMediaPlayer* m_player;
    //알람 체크박스 체크 되어있는지
    bool sound_check;
    bool popup_check;
    //창 drag and drop 이동
    int mouseX;
    int mouseY;
    int absX;
    int absY;
    int justOneCount;

public slots:
    //시스템 트레이 아이콘 클릭 이벤트로부터 시그널을 처리하는 slot함수
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

    //자세 설정 창 띄우기
    void setPose();

    //시작버튼
    void mybtn();

    //새로만든 최소화, 닫기버튼
    void minimum_Btn();
    void close_Btn();

    //창 drag and drop 이동
    void mouseMoveEvent(QMouseEvent* mouse);
    void mouseReleaseEvent(QMouseEvent* event);

    void alramMessage();

    void modeChanged(int mode);

    void timeCalculator();

signals:
    void textChanger(string arr);
    void closeSignal();
};