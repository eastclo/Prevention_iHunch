#include "iHunch.h"

iHunch::iHunch(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::iHunchClass)
{
    ui->setupUi(this);
    this->setWindowTitle("Turtle Neck");

    m_trayicon = new QSystemTrayIcon(this);
    m_trayicon->setIcon(QIcon("gb.png"));
    m_trayicon->setToolTip("Turtle Neck");

    QMenu* menu = new QMenu(this);
    QAction* viewWindow = new QAction(QString::fromLocal8Bit("열기"), this);
    QAction* quitAction = new QAction(QString::fromLocal8Bit("종료"), this);
    QAction* event1 = new QAction(QString::fromLocal8Bit("이벤트1"), this);

    connect(viewWindow, SIGNAL(triggered()), this, SLOT(showNormal()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(event1, SIGNAL(triggered()), this, SLOT(popupslot()));

    menu->addAction(event1);
    menu->addAction(viewWindow);
    menu->addAction(quitAction);

    m_trayicon->setContextMenu(menu);
    m_trayicon->show();

    connect(m_trayicon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
        this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

    ui->mainToolBar->hide();
    QStatusBar* myStatusBar = ui->statusBar;
    myStatusBar->showMessage("Developed by asd", 0);


    QWidget* modeAlarm = ui->modeAlarm;
    modeAlarm->hide();

    //효과음관련
    m_player = new QMediaPlayer();
    m_player->setMedia(QUrl::fromLocalFile("effect sound.mp3"));
    m_player->setVolume(50);

}

iHunch::~iHunch()
{
    delete ui;
}

void iHunch::closeEvent(QCloseEvent* event)
{
    if (this->isVisible())
    {
        event->ignore();
        this->hide();

        m_trayicon->showMessage(
            QString::fromLocal8Bit("프로그램 실행중"), QString::fromLocal8Bit("프로그램이 백그라운드에서 실행중"),
            QIcon("gb.png"),
            2000);
    }
}

void iHunch::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::DoubleClick)
        this->show();
}

void iHunch::popupslot()
{
    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
    m_trayicon->showMessage(
        QString::fromLocal8Bit("Turtle Neck"), QString::fromLocal8Bit("안좋은 자세가 유지되고 있어요."),
        QIcon("gb.png"),
        500);
}

void iHunch::setPose()
{
    setuppose = new setupPose(this);
    setuppose->show();
}

void iHunch::modeChanged(int mode)
{
    QComboBox* modeBox = ui->comboBox;
    QWidget* modeAlarm = ui->modeAlarm;

    if (modeBox->currentIndex() == 0) {
        modeAlarm->hide();
    }
    else if (modeBox->currentIndex() == 1) {
        modeAlarm->show();
    }
}

void iHunch::mybtn()
{
    QPushButton* btn = ui->pushButton_2;
    if (started == false) {
        started = true;
        btn->setText(QString::fromLocal8Bit("측정 종료"));

        //효과음 관련
        m_player->play();
    }
    else if (started == true) {
        started = false;
        btn->setText(QString::fromLocal8Bit("측정 시작"));
    }
}