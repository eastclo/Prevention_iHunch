#include "iHunch.h"

iHunch::iHunch(QWidget *parent)
    : QMainWindow(parent, Qt::FramelessWindowHint | Qt::WindowFlags()), ui(new Ui::iHunchClass)
{
    ui->setupUi(this);
    this->setWindowTitle("Turtle Neck");

    /*********************************************************/
    //트레이아이콘
    m_trayicon = new QSystemTrayIcon(this);
    m_trayicon->setIcon(QIcon("gb.png"));
    m_trayicon->setToolTip("Turtle Neck");

    QMenu* menu = new QMenu(this);
    QAction* viewWindow = new QAction(QString::fromLocal8Bit("열기"), this);
    QAction* quitAction = new QAction(QString::fromLocal8Bit("종료"), this);

    connect(viewWindow, SIGNAL(triggered()), this, SLOT(showNormal()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    menu->addAction(viewWindow);
    menu->addAction(quitAction);

    m_trayicon->setContextMenu(menu);
    m_trayicon->show();

    connect(m_trayicon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
        this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
    //트레이아이콘
    /*********************************************************/
    
    //기본 ui 추가설정
    ui->mainToolBar->hide();
    QStatusBar* myStatusBar = ui->statusBar;
    myStatusBar->showMessage("Developed by asd", 0);


    //모드 관련 설정
    QWidget* modeAlarm = ui->modeAlarm;
    modeAlarm->hide();
    modeflag = 0;

    //효과음관련
    m_player = new QMediaPlayer();
    m_player->setMedia(QUrl::fromLocalFile("effect sound.mp3"));
    m_player->setVolume(50);

    //타이틀바
    QWidget* myTitleBar = ui->myTitleBar;
    myTitleBar->setStyleSheet("QWidget {background : rgb(255,255,255); }");

    //창 drag and drop 이동
    justOneCount = 0;
    mouseX = this->geometry().x();
    mouseY = this->geometry().y();
    absY = this->geometry().y();
    absX = this->geometry().x();
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
            QString::fromLocal8Bit("Turtle Neck"), QString::fromLocal8Bit("안좋은 자세가 유지되고 있어요."),
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
        started = true;
        btn->setText(QString::fromLocal8Bit("측정 종료"));

        if (this->isVisible())
        {
            this->hide();

            m_trayicon->showMessage(
                QString::fromLocal8Bit("프로그램 실행중"), QString::fromLocal8Bit("프로그램이 백그라운드에서 실행중"),
                QIcon("gb.png"),
                500);
        }
    }
    else if (started == true) {
        started = false;
        btn->setText(QString::fromLocal8Bit("측정 시작"));

    }
}

void iHunch::minimum_Btn() {
    this->showMinimized();
}

void iHunch::close_Btn() {
    if (this->isVisible())
    {
        this->hide();

        m_trayicon->showMessage(
            QString::fromLocal8Bit("프로그램 실행중"), QString::fromLocal8Bit("프로그램이 백그라운드에서 실행중"),
            QIcon("gb.png"),
            500);
    }
}

void iHunch::mouseMoveEvent(QMouseEvent* mouse)
{
    if (this->isMaximized() == true) //최대화 되어있을경우 무시
        return;

    if (mouse->button() == Qt::RightButton) //오른쪽클릭했을경우 무시
        return;

    mouseX = QCursor::pos().x(); //마우스 절대좌표
    mouseY = QCursor::pos().y();

    if (justOneCount == 0)
    {
        absX = mouse->pos().x(); //마우스 상대좌표 저장
        absY = mouse->pos().y();
        justOneCount++; //1이되면 이 블록을 연산하지 않음
    }
    this->move(mouseX - absX, mouseY - absY); //절대좌표에서 상대좌표를 빼서 이동하는 원리
}

void iHunch::mouseReleaseEvent(QMouseEvent*)
{
    justOneCount = 0; //마우스를 클릭 해제하면 다시 0으로하여 반복사용가능
}

