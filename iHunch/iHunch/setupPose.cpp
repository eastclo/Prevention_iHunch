#include "setupPose.h"
#include "alphapose.h"

#define thread std::thread

extern bool measureStartBtn;
extern bool imported;
extern bool measuring;
extern bool measureError;

setupPose::setupPose(QWidget *parent)
	: QDialog(parent, Qt::FramelessWindowHint), ui(new Ui::setupPose)
{
	ui->setupUi(this);
	//this->initCamera();
	//this->cameraDeviceSearch();
	//
	//QComboBox* comboBox = ui->comboBox;
	//QPushButton* startBtn = ui->startBtn;
	//QPushButton* stopBtn = ui->stopBtn;
	//QPushButton* captureBtn = ui->captureBtn;

	//comboBox->hide();
	//startBtn->hide();
	//stopBtn->hide();
	//captureBtn->hide();

	//window drag and drop move
	justOneCount = 0;
	mouseX = this->geometry().x();
	mouseY = this->geometry().y();
	absY = this->geometry().y();
	absX = this->geometry().x();

	//initBtn = ui->initBtn;
	//initBtn->setEnabled(false);

	//count = ui->count;

	//this->onStartBtn();
}

setupPose::~setupPose()
{
	//delete myCamera;
	//delete myCapture;
	delete ui;
	
}

void setupPose::mouseMoveEvent(QMouseEvent* mouse)
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

void setupPose::mouseReleaseEvent(QMouseEvent*)
{
	justOneCount = 0; //마우스를 클릭 해제하면 다시 0으로하여 반복사용가능
}

void setupPose::initPoseBtn()
{
	if (imported == true) {
		measureStartBtn = true;
	}
	else if (imported == false) {
		QLabel* info_text = ui->infomtxt;
		//임포트 안돼있으므로 새로운 창띄우기if(imported)
		info_text->setText(QString::fromLocal8Bit("모듈임포트 중입니다"));
	}
}

void setupPose::textChanged(string arr)
{
	QLabel* info_text = ui->infomtxt;
	//받은 문자열 qt에서 사용가능하게 변환후 세팅
	if (arr.find("-1") != -1) {
		info_text->setText(QString::fromLocal8Bit("자세가 불안정합니다. 잠시 후 다시 시도해주세요."));
		thread t(setSTDPose);
		t.detach();
	}
	else
		info_text->setText(QString::fromStdString(arr));
}

void setupPose::closeSlot()
{
	this->hide();
}

//void setupPose::initCamera()
//{
//	myCamera = new QCamera;
//	myCapture = new QCameraImageCapture(myCamera);
//	myViewfinder = new QCameraViewfinder();
//
//	QVBoxLayout* vLay = new QVBoxLayout();
//	vLay->addWidget(myViewfinder);
//	ui->camOut->setLayout(vLay);
//}
//
//void setupPose::cameraDeviceSearch()
//{
//	camDevNameLists.clear();
//	ui->comboBox->clear();
//
//	for each (const QByteArray &deviceName in QCamera::availableDevices())
//	{
//		QString description;
//		description = myCamera->deviceDescription(deviceName);
//		camDevNameLists.append(deviceName);
//		ui->comboBox->addItem(description);
//	}
//}
//
//void setupPose::onStartBtn()
//{
//	delete myCapture;
//	delete myCamera;
//	if (camDevNameLists.count() < 1) {
//		myCamera = new QCamera;
//	}
//	else {
//		int curIndex = ui->comboBox->currentIndex();
//		myCamera = new QCamera(camDevNameLists.at(curIndex));
//	}
//
//	connect(myCamera, SIGNAL(error(QCamera::Error)), this, SLOT(camError(QCamera::Error)));
//
//	myCamera->setViewfinder(myViewfinder);
//	myCamera->setCaptureMode(QCamera::CaptureVideo);
//	myCapture = new QCameraImageCapture(myCamera);
//
//	myCapture->setCaptureDestination(QCameraImageCapture::CaptureToBuffer | QCameraImageCapture::CaptureToFile);
//	myCapture->setBufferFormat(QVideoFrame::Format_RGB32);
//
//	connect(myCapture, SIGNAL(imageCaptured(int, QImage)), this, SLOT(imageCaptured(int, QImage)));
//
//
//	initBtn->setEnabled(true); 
//	myCamera->start();
//	
//}
//
//void setupPose::onStopBtn()
//{
//	myCamera->stop();
//}
//
//void setupPose::onCaptureBtn()
//{
//	myCapture->capture("c:\CuptureImage.jpg");
//}
//
//void setupPose::camError(QCamera::Error error)
//{
//	qDebug() << Q_FUNC_INFO << "ERROR : " << error;
//}
//
//void setupPose::imageCapture(int pid, QImage pPriview)
//{
//	Q_UNUSED(pid);
//
//	qDebug() << "IMAGE CAPTURE SIZE (WIDTH X HEIGHT) : " << pPriview.byteCount();
//}
//
//void setupPose::initPoseBtn()
//{
//	measureStartBtn = true;
//}

//void setupPose::initClose()
//{
//	myCamera->stop();
//	this->hide();
//	delete ui;
//}
//
//void setupPose::setCount(int count)
//{	
//	//if complete immediate end
//
//	//else not complete re shoot
//}
