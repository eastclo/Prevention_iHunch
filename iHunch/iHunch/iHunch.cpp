#include "iHunch.h"
#include "alphapose.h"

#define thread std::thread

extern bool endSignal;
extern PROCESS_INFORMATION ProcessInfo;

iHunch::iHunch(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::iHunchClass)
{
    ui->setupUi(this);
    this->setWindowTitle("Turtle Neck");

    /*********************************************************/
    //Ʈ���̾�����
    m_trayicon = new QSystemTrayIcon(this);
    m_trayicon->setIcon(QIcon("gb.png"));
    m_trayicon->setToolTip("Turtle Neck");

    QMenu* menu = new QMenu(this);
    QAction* viewWindow = new QAction(QString::fromLocal8Bit("����"), this);
    QAction* quitAction = new QAction(QString::fromLocal8Bit("����"), this);

    connect(viewWindow, SIGNAL(triggered()), this, SLOT(showNormal()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    menu->addAction(viewWindow);
    menu->addAction(quitAction);

    m_trayicon->setContextMenu(menu);
    m_trayicon->show();

    connect(m_trayicon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
        this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
    //Ʈ���̾�����
    /*********************************************************/
    
    //�⺻ ui �߰�����
    ui->mainToolBar->hide();
    QStatusBar* myStatusBar = ui->statusBar;
    myStatusBar->showMessage("Developed by asd", 0);


    //��� ���� ����
    QWidget* modeAlarm = ui->modeAlarm;
    modeAlarm->hide();
    modeflag = 0;

    //ȿ��������
    m_player = new QMediaPlayer();
    m_player->setMedia(QUrl::fromLocalFile("effect sound.mp3"));
    m_player->setVolume(50);

    connect(this, SIGNAL(getAlarm()), this, SLOT(alramMessage()));

}

iHunch::~iHunch()
{
    delete ui;
}

void iHunch::alramMessage()
{
    QCheckBox* popup_box = ui->popup_checkbox;
    QCheckBox* sound_box = ui->soundAlram_checkbox;

    popup_check = popup_box->isChecked();
    sound_check = sound_box->isChecked();

    if (popup_check == true) {
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
        m_trayicon->showMessage(
            QString::fromLocal8Bit("Turtle Neck"), QString::fromLocal8Bit("������ �ڼ��� �����ǰ� �־��."),
            QIcon("gb.png"),
            500);
    }

    if (sound_check == true) {
        m_player->play();
    }
}

void iHunch::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::DoubleClick)
        this->show();
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
        modeflag = 0;
    }
    else if (modeBox->currentIndex() == 1) {
        modeAlarm->show();
        modeflag = 1;
    }
}

void iHunch::mybtn()
{
    QPushButton* btn = ui->pushButton_2;
    if (started == false) {
    endSignal = false;
    thread t1(startFix);
    t1.detach();
    thread t2(judgePose);
    t2.detach();
        started = true;
        btn->setText(QString::fromLocal8Bit("���� ����"));

        if (this->isVisible())
        {
            this->hide();

            m_trayicon->showMessage(
                QString::fromLocal8Bit("���α׷� ������"), QString::fromLocal8Bit("���α׷��� ��׶��忡�� ������"),
                QIcon("gb.png"),
                500);
        }
    }
    else if (started == true) {
        checkEndSignal(true);
        TerminateProcess(ProcessInfo.hProcess, 0);
        CloseHandle(ProcessInfo.hProcess);
        CloseHandle(ProcessInfo.hThread);

        started = false;
        btn->setText(QString::fromLocal8Bit("���� ����"));

    }
}