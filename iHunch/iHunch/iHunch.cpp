#include "iHunch.h"
#include "alphapose.h"

#define thread std::thread

extern double healthySec, unhealthySec; //ÁÁÀº, ³ª»ÛÀÚ¼¼ ÃÑ ½Ã°£
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

	/*********************************************************/
	//Æ®ï¿½ï¿½ï¿½Ì¾ï¿½ï¿½ï¿½ï¿½ï¿½
	m_trayicon = new QSystemTrayIcon(this);
	m_trayicon->setIcon(QIcon("gb.png"));
	m_trayicon->setToolTip("Turtle Neck");

	QMenu* menu = new QMenu(this);
	QAction* viewWindow = new QAction(QString::fromLocal8Bit("ï¿½ï¿½ï¿½ï¿½"), this);
	QAction* quitAction = new QAction(QString::fromLocal8Bit("ï¿½ï¿½ï¿½ï¿½"), this);

	connect(viewWindow, SIGNAL(triggered()), this, SLOT(showNormal()));
	connect(viewWindow, SIGNAL(triggered()), this, SLOT(timeCalculator()));
	connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

	menu->addAction(viewWindow);
	menu->addAction(quitAction);

	m_trayicon->setContextMenu(menu);
	m_trayicon->show();

	connect(m_trayicon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
		this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
	//Æ®ï¿½ï¿½ï¿½Ì¾ï¿½ï¿½ï¿½ï¿½ï¿½
	/*********************************************************/

	//ï¿½âº» ui ï¿½ß°ï¿½ï¿½ï¿½ï¿½ï¿½
	ui->mainToolBar->hide();
	QStatusBar* myStatusBar = ui->statusBar;
	myStatusBar->showMessage("Developed by asd", 0);

	//È¿ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	m_player = new QMediaPlayer();
	m_player->setMedia(QUrl::fromLocalFile("effect sound.mp3"));
	m_player->setVolume(50);

	//Å¸ï¿½ï¿½Æ²ï¿½ï¿½
	QWidget* myTitleBar = ui->myTitleBar;
	myTitleBar->setStyleSheet("QWidget {background : rgb(255,255,255); }");

	//Ã¢ drag and drop ï¿½Ìµï¿½
	justOneCount = 0;
	mouseX = this->geometry().x();
	mouseY = this->geometry().y();
	absY = this->geometry().y();
	absX = this->geometry().x();

	//
	timeIntervalComboBox = ui->alarmIntervalComboBox;
	unHealthComboBox = ui->unHealthComboBox;
	poseFixSlider = ui->poseFixDegreeSlider;

	modeChanged(0);

	QPixmap pixmap("play.png");
	QIcon ButtonIcon(pixmap);
	QPushButton* startBtn = ui->pushButton_2;
	startBtn->setIcon(ButtonIcon);
	startBtn->setIconSize(QSize(32,32));
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
	calcul_time.append(QByteArray::number(hour)).append(QString::fromLocal8Bit("½Ã "))
		.append(QByteArray::number(min)).append(QString::fromLocal8Bit("ºÐ "))
	.append(QByteArray::number(sec)).append(QString::fromLocal8Bit("ÃÊ"));
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
	calcul_time.append(QByteArray::number(hour)).append(QString::fromLocal8Bit("½Ã "))
		.append(QByteArray::number(min)).append(QString::fromLocal8Bit("ºÐ "))
		.append(QByteArray::number(sec)).append(QString::fromLocal8Bit("ÃÊ"));
	badTime->setText(calcul_time);

	//pose ratio
	ratio = unhealthySec / (healthySec + unhealthySec);
	poseRatio->setValue(ratio);
}

void iHunch::alramMessage()
{
	QCheckBox* popup_box = ui->popup_checkbox;
	QCheckBox* sound_box = ui->soundAlram_checkbox;

	popup_check = popup_box->isChecked();
	sound_check = sound_box->isChecked();

    if (popup_check != true) {
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
        m_trayicon->showMessage(
            QString::fromLocal8Bit("Turtle Neck"), QString::fromLocal8Bit("ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Ú¼ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ç°ï¿½ ï¿½Ö¾ï¿½ï¿?"),
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
		ui->modeAlarm->setEnabled(false);
	}
	else if (modeBox->currentIndex() == 1) {
		ui->modeAlarm->setEnabled(true);
	}
}

void iHunch::setPose()
{   
    imported = false;
    measureStartBtn = false;

    thread t(setSTDPose);
    t.detach();
	setuppose = new setupPose(this);
	connect(this, SIGNAL(textChanger(char*)), setuppose, SLOT(textChanged(char*)));
	setuppose->show();
}

void iHunch::mybtn()
{
	QPushButton* btn = ui->pushButton_2;
	QPushButton* initPoseBtn = ui->pushButton;
	if (started == false) {

		btn->setText(QString::fromLocal8Bit("ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½"));
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
				QString::fromLocal8Bit("ï¿½ï¿½ï¿½Î±×·ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½"), QString::fromLocal8Bit("ï¿½ï¿½ï¿½Î±×·ï¿½ï¿½ï¿½ ï¿½ï¿½×¶ï¿½ï¿½å¿¡ï¿½ï¿?ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½"),
				QIcon("gb.png"),
				500);
		}

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
		btn->setText(QString::fromLocal8Bit("ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½"));

		QPixmap pixmap("play.png");
		QIcon ButtonIcon(pixmap);
		btn->setIcon(ButtonIcon);
		btn->setIconSize(QSize(32, 32));
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
            QString::fromLocal8Bit("ï¿½ï¿½ï¿½Î±×·ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½"), QString::fromLocal8Bit("ï¿½ï¿½ï¿½Î±×·ï¿½ï¿½ï¿½ ï¿½ï¿½×¶ï¿½ï¿½å¿¡ï¿½ï¿?ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½"),
            QIcon("gb.png"),
            500);
    }
}

void iHunch::mouseMoveEvent(QMouseEvent* mouse)
{
    if (this->isMaximized() == true) //ï¿½Ö´ï¿½È­ ï¿½Ç¾ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?ï¿½ï¿½ï¿½ï¿½
        return;

    if (mouse->button() == Qt::RightButton) //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Å¬ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?ï¿½ï¿½ï¿½ï¿½
        return;

	mouseX = QCursor::pos().x(); //ï¿½ï¿½ï¿½ì½º ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ç¥
	mouseY = QCursor::pos().y();

    if (justOneCount == 0)
    {
        absX = mouse->pos().x(); //ï¿½ï¿½ï¿½ì½º ï¿½ï¿½ï¿½ï¿½ï¿½Ç?ï¿½ï¿½ï¿½ï¿½
        absY = mouse->pos().y();
        justOneCount++; //1ï¿½ÌµÇ¸ï¿½ ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
    }
    this->move(mouseX - absX, mouseY - absY); //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ç¥ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ç¥ï¿½ï¿?ï¿½ï¿½ï¿½ï¿½ ï¿½Ìµï¿½ï¿½Ï´ï¿½ ï¿½ï¿½ï¿½ï¿½
}

void iHunch::mouseReleaseEvent(QMouseEvent*)
{
    justOneCount = 0; //ï¿½ï¿½ï¿½ì½ºï¿½ï¿½ Å¬ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ï¸ï¿½ ï¿½Ù½ï¿½ 0ï¿½ï¿½ï¿½ï¿½ï¿½Ï¿ï¿½ ï¿½Ýºï¿½ï¿½ï¿½ë°¡ï¿½ï¿?
}
