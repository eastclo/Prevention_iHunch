#include "iHunch.h"
#include "alphapose.h"

#define thread std::thread

extern double healthySec, unhealthySec; //건강한시간 안건강한시간
extern int alarmInterval;
extern int alarmStart;
extern int fixDegree;

extern bool imported;
extern bool endSignal;
extern PROCESS_INFORMATION ProcessInfo;
extern bool measureStartBtn;

iHunch::iHunch(QWidget* parent)
	: QMainWindow(parent, Qt::FramelessWindowHint), ui(new Ui::iHunchClass)
{
	ui->setupUi(this);
	this->setWindowTitle("Turtle Neck");
	this->setGeometry(QRect(1250,100,600,520));
	/*********************************************************/
	//트레이아이콘
	m_trayicon = new QSystemTrayIcon(this);
	m_trayicon->setIcon(QIcon("gb.png"));
	m_trayicon->setToolTip("Turtle Neck");

	QMenu* menu = new QMenu(this);
	QAction* viewWindow = new QAction(QString::fromLocal8Bit("열기"), this);
	QAction* quitAction = new QAction(QString::fromLocal8Bit("닫기"), this);

	connect(viewWindow, SIGNAL(triggered()), this, SLOT(showNormal()));
	connect(viewWindow, SIGNAL(triggered()), this, SLOT(timeCalculator()));
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


	timeIntervalComboBox = ui->alarmIntervalComboBox;
	unHealthComboBox = ui->unHealthComboBox;
	poseFixSlider = ui->poseFixDegreeSlider;

	modeChanged(0);

	QPixmap pixmap("play.png");
	QIcon ButtonIcon(pixmap);
	QPushButton* startBtn = ui->pushButton_2;
	startBtn->setIcon(ButtonIcon);
	startBtn->setIconSize(QSize(32,32));
	over = new overlay();
}

iHunch::~iHunch()
{
	delete ui;
}

void iHunch::timeCalculator()
{
	QString calcul_time;
	QTextBrowser* fullTime = ui->fullTimeTextBar;
	QTextBrowser* badTime = ui->badTimeTextBar;
	QProgressBar* poseRatio = ui->poseRatio;
	
	int ratio;
	int hour, min, sec, temp;

	//fulltime
	temp = healthySec + unhealthySec;
	if (temp >= 60) {
		sec = (int)temp % 60;
		min = (int)temp / 60;
		if (min >= 60) {
			hour = (int)min / 60;
			min = (int)min % 60;
		}
		else {
			//sec = sec;
			min = min;
			hour = 0;
		}
	} 
	else {
		sec = temp;
		min = 0;
		hour = 0;
	}
	calcul_time.append(QByteArray::number(hour)).append(QString::fromLocal8Bit("시간 "))
		.append(QByteArray::number(min)).append(QString::fromLocal8Bit("분 "))
	.append(QByteArray::number(sec)).append(QString::fromLocal8Bit("초"));
	fullTime->setText(calcul_time);

	//badtime
	temp = unhealthySec;
	if (temp >= 60) {
		sec = (int)temp % 60;
		min = (int)temp / 60;
		if (min >= 60) {
			hour = (int)min / 60;
			min = (int)min % 60;
		}
		else {
			//sec = sec;
			min = min;
			hour = 0;
		}
	}
	else {
		sec = temp;
		min = 0;
		hour = 0;
	}
	calcul_time = "";
	calcul_time.append(QByteArray::number(hour)).append(QString::fromLocal8Bit("시간 "))
		.append(QByteArray::number(min)).append(QString::fromLocal8Bit("분 "))
		.append(QByteArray::number(sec)).append(QString::fromLocal8Bit("초"));
	badTime->setText(calcul_time);

	//pose ratio
	ratio = unhealthySec / (healthySec + unhealthySec) * 100;
	poseRatio->setValue(ratio);
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
	if (reason == QSystemTrayIcon::DoubleClick) {
		this->timeCalculator();
		this->show();
	}
}

void iHunch::modeChanged(int mode)
{
	QComboBox* modeBox = ui->comboBox;

	if (modeBox->currentIndex() == 0)	{
		ui->frame->setEnabled(false);
	}
	else if (modeBox->currentIndex() == 1) {
		ui->frame->setEnabled(true);
	}
}

void iHunch::setPose()
{   
    measureStartBtn = false;

    thread t(setSTDPose);
    t.detach();
	setuppose = new setupPose(this);
	connect(this, SIGNAL(textChanger(char*)), setuppose, SLOT(textChanged(char*)));
	connect(this, SIGNAL(closeSignal()), setuppose, SLOT(closeSlot()));
	setuppose->show();
}

void iHunch::mybtn()
{
	QPushButton* btn = ui->pushButton_2;
	QPushButton* initPoseBtn = ui->pushButton;
	if (started == false) {

		btn->setText(QString::fromLocal8Bit("  측정 종료"));
		initPoseBtn->setEnabled(false);
		int temp = timeIntervalComboBox->currentIndex();
		switch (temp) {
		case 0: alarmInterval = 5; break;
		case 1: alarmInterval = 7; break;
		case 2: alarmInterval = 10; break;
		}
		timeIntervalComboBox->setEnabled(false);
		alarmStart = unHealthComboBox->currentIndex() + 3;
		unHealthComboBox->setEnabled(false);
		fixDegree = poseFixSlider->sliderPosition();
		poseFixSlider->setEnabled(false);

		endSignal = false;
		thread t1(startFix);
		t1.detach();
		thread t2(judgePose);
		t2.detach();
		started = true;

		if (this->isVisible())
		{
			this->hide();

			m_trayicon->showMessage(
				QString::fromLocal8Bit("프로그램 실행중"), QString::fromLocal8Bit("프로그램이 백그라운드에서 실행중"),
				QIcon("gb.png"),
				500);
		}
		over->show();
		QPixmap pixmap("pause.png");
		QIcon ButtonIcon(pixmap);
		btn->setIcon(ButtonIcon);
		btn->setIconSize(QSize(32, 32));

	}
	else if (started == true) {
		timeIntervalComboBox->setEnabled(true);
		unHealthComboBox->setEnabled(true);
		poseFixSlider->setEnabled(true);
		initPoseBtn->setEnabled(true);
		checkEndSignal(true);
		TerminateProcess(ProcessInfo.hProcess, 0);
		CloseHandle(ProcessInfo.hProcess);
		CloseHandle(ProcessInfo.hThread);

		started = false;
		btn->setText(QString::fromLocal8Bit("  측정 시작"));

		QPixmap pixmap("play.png");
		QIcon ButtonIcon(pixmap);
		btn->setIcon(ButtonIcon);
		btn->setIconSize(QSize(32, 32));
		over->hide();
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
        absX = mouse->pos().x(); ///마우스 상대좌표 저장
        absY = mouse->pos().y();
        justOneCount++; //1이되면 이 블록을 연산하지 않음
    }
    this->move(mouseX - absX, mouseY - absY); //절대좌표에서 상대좌표를 빼서 이동하는 원리
}

void iHunch::mouseReleaseEvent(QMouseEvent*)
{
    justOneCount = 0; //마우스를 클릭 해제하면 다시 0으로하여 반복사용가능
}