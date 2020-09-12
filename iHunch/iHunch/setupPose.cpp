#include "setupPose.h"
extern bool imported;
setupPose::setupPose(QWidget *parent)
	: QDialog(parent, Qt::FramelessWindowHint), ui(new Ui::setupPose)
{
	ui->setupUi(this);
	this->initCamera();
	this->cameraDeviceSearch();

	this->onStartBtn();
	
	QComboBox* comboBox = ui->comboBox;
	QPushButton* startBtn = ui->startBtn;
	QPushButton* stopBtn = ui->stopBtn;
	QPushButton* captureBtn = ui->captureBtn;

	comboBox->hide();
	startBtn->hide();
	stopBtn->hide();
	captureBtn->hide();

	//window drag and drop move
	justOneCount = 0;
	mouseX = this->geometry().x();
	mouseY = this->geometry().y();
	absY = this->geometry().y();
	absX = this->geometry().x();
}

setupPose::~setupPose()
{
	delete myCamera;
	delete myCapture;
	delete ui;
	
}

void setupPose::initCamera()
{
	myCamera = new QCamera;
	myCapture = new QCameraImageCapture(myCamera);
	myViewfinder = new QCameraViewfinder();

	QVBoxLayout* vLay = new QVBoxLayout();
	vLay->addWidget(myViewfinder);
	ui->camOut->setLayout(vLay);
}

void setupPose::cameraDeviceSearch()
{
	camDevNameLists.clear();
	ui->comboBox->clear();

	for each (const QByteArray &deviceName in QCamera::availableDevices())
	{
		QString description;
		description = myCamera->deviceDescription(deviceName);
		camDevNameLists.append(deviceName);
		ui->comboBox->addItem(description);
	}
}

void setupPose::onStartBtn()
{
	delete myCapture;
	delete myCamera;
	if (camDevNameLists.count() < 1) {
		myCamera = new QCamera;
	}
	else {
		int curIndex = ui->comboBox->currentIndex();
		myCamera = new QCamera(camDevNameLists.at(curIndex));
	}

	connect(myCamera, SIGNAL(error(QCamera::Error)), this, SLOT(camError(QCamera::Error)));

	myCamera->setViewfinder(myViewfinder);
	myCamera->setCaptureMode(QCamera::CaptureVideo);
	myCapture = new QCameraImageCapture(myCamera);

	myCapture->setCaptureDestination(QCameraImageCapture::CaptureToBuffer | QCameraImageCapture::CaptureToFile);
	myCapture->setBufferFormat(QVideoFrame::Format_RGB32);

	connect(myCapture, SIGNAL(imageCaptured(int, QImage)), this, SLOT(imageCaptured(int, QImage)));
	
	while (!imported);
	myCamera->start();
}

void setupPose::onStopBtn()
{
	myCamera->stop();
}

void setupPose::onCaptureBtn()
{
	myCapture->capture("c:\CuptureImage.jpg");
}

void setupPose::camError(QCamera::Error error)
{
	qDebug() << Q_FUNC_INFO << "ERROR : " << error;
}

void setupPose::imageCapture(int pid, QImage pPriview)
{
	Q_UNUSED(pid);

	qDebug() << "IMAGE CAPTURE SIZE (WIDTH X HEIGHT) : " << pPriview.byteCount();
}

void setupPose::initPoseBtn()
{


}

void setupPose::mouseMoveEvent(QMouseEvent* mouse)
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

void setupPose::mouseReleaseEvent(QMouseEvent*)
{
	justOneCount = 0; //���콺�� Ŭ�� �����ϸ� �ٽ� 0�����Ͽ� �ݺ���밡��?
}