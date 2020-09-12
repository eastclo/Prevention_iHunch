#include "setupPose.h"

setupPose::setupPose(QWidget *parent)
	: QDialog(parent), ui(new Ui::setupPose)
{
	ui->setupUi(this);
	this->initCamera();
	this->cameraDeviceSearch();

	this->onStartBtn();

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

void setupPose::closeEvent(QCloseEvent* event)
{
	myCamera->stop();
	QWidget::closeEvent(event);
}