#include "iHunch.h"
#include "alphapose.h"

#define thread std::thread

extern int alarmInterval;
extern int alarmStart;
extern int fixDegree;

extern bool endSignal;
extern PROCESS_INFORMATION ProcessInfo;

iHunch::iHunch(QWidget* parent)
	: QMainWindow(parent, Qt::FramelessWindowHint), ui(new Ui::iHunchClass)
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


	//���?���� ����
	QWidget* modeAlarm = ui->modeAlarm;
	modeAlarm->hide();
	modeflag = 0;

	//ȿ��������
	m_player = new QMediaPlayer();
	m_player->setMedia(QUrl::fromLocalFile("effect sound.mp3"));
	m_player->setVolume(50);

	//Ÿ��Ʋ��
	QWidget* myTitleBar = ui->myTitleBar;
	myTitleBar->setStyleSheet("QWidget {background : rgb(255,255,255); }");

	//â drag and drop �̵�
	justOneCount = 0;
	mouseX = this->geometry().x();
	mouseY = this->geometry().y();
	absY = this->geometry().y();
	absX = this->geometry().x();

	//
	timeIntervalComboBox = ui->alarmIntervalComboBox;
	unHealthComboBox = ui->unHealthComboBox;
	poseFixSlider = ui->poseFixDegreeSlider;

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
			QString::fromLocal8Bit("Turtle Neck"), QString::fromLocal8Bit("������ �ڼ��� �����ǰ� �־��?"),
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
	QPushButton* initPoseBtn = ui->pushButton;
	if (started == false) {

		btn->setText(QString::fromLocal8Bit("���� ����"));
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
				QString::fromLocal8Bit("���α׷� ������"), QString::fromLocal8Bit("���α׷��� ��׶��忡��?������"),
				QIcon("gb.png"),
				500);
		}
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
		btn->setText(QString::fromLocal8Bit("���� ����"));

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
			QString::fromLocal8Bit("���α׷� ������"), QString::fromLocal8Bit("���α׷��� ��׶��忡��?������"),
			QIcon("gb.png"),
			500);
	}
}

void iHunch::mouseMoveEvent(QMouseEvent* mouse)
{
	if (this->isMaximized() == true) //�ִ�ȭ �Ǿ��������?����
		return;

	if (mouse->button() == Qt::RightButton) //������Ŭ���������?����
		return;

	mouseX = QCursor::pos().x(); //���콺 ������ǥ
	mouseY = QCursor::pos().y();

	if (justOneCount == 0)
	{
		absX = mouse->pos().x(); //���콺 ������?����
		absY = mouse->pos().y();
		justOneCount++; //1�̵Ǹ� �� ������ �������� ����
	}
	this->move(mouseX - absX, mouseY - absY); //������ǥ���� �����ǥ��?���� �̵��ϴ� ����
}

void iHunch::mouseReleaseEvent(QMouseEvent*)
{
	justOneCount = 0; //���콺�� Ŭ�� �����ϸ� �ٽ� 0�����Ͽ� �ݺ���밡��?
}
