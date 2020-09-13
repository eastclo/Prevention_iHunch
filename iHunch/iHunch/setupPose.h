#pragma once

#include <QDialog>
#include <QMessageBox>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QAbstractVideoSurface>
#include <QMouseEvent>
#include <Windows.h>
#include "ui_setupPose.h"

QT_BEGIN_NAMESPACE
namespace Ui { class setupPose; }
QT_END_NAMESPACE

class setupPose : public QDialog
{
	Q_OBJECT

public:
	setupPose(QWidget *parent = Q_NULLPTR);
	~setupPose();
	//void initCamera();
	//void cameraDeviceSearch();

private:
	Ui::setupPose* ui;
	//QCamera* myCamera;
	//QCameraViewfinder* myViewfinder;
	//QCameraImageCapture* myCapture;
	//QList<QByteArray> camDevNameLists;
	//QPushButton* initBtn;
	//QLabel* count;

	//window drag and drop move
	int mouseX;
	int mouseY;
	int absX;
	int absY;
	int justOneCount;

private slots:
	//void onStartBtn();
	//void onStopBtn();
	//void onCaptureBtn();
	//void camError(QCamera::Error error);
	//void imageCapture(int pid, QImage pPriview);
	void initPoseBtn();

	//window drag and drop move
	void mouseMoveEvent(QMouseEvent* mouse);
	void mouseReleaseEvent(QMouseEvent* event);

	//void initClose();
	//void setCount(int count);
};
