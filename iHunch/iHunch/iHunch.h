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
    //��� Ȯ�� ����
    int modeflag;
    //�˶� ȣ���Լ�
 //   void alramMessage();

private:
    Ui::iHunchClass* ui;
    //Ʈ���̾����� Ŭ���� �ν��Ͻ�
    QSystemTrayIcon* m_trayicon;
    setupPose* setuppose;

    //���۹�ư
    bool started = false;
    //ȿ����
    QMediaPlayer* m_player;
    //�˶� üũ�ڽ� üũ �Ǿ��ִ���
    bool sound_check;
    bool popup_check;
    //â drag and drop �̵�
    int mouseX;
    int mouseY;
    int absX;
    int absY;
    int justOneCount;

public slots:
    //�ý��� Ʈ���� ������ Ŭ�� �̺�Ʈ�κ��� �ñ׳��� ó���ϴ� slot�Լ�
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

    //�ڼ� ���� â ����
    void setPose();
    void modeChanged(int mode);

    //���۹�ư
    void mybtn();

    //���θ��� �ּ�ȭ, �ݱ��ư
    void minimum_Btn();
    void close_Btn();

    //â drag and drop �̵�
    void mouseMoveEvent(QMouseEvent* mouse);
    void mouseReleaseEvent(QMouseEvent* event);

    void alramMessage();
};
