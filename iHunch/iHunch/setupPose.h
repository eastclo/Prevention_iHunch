#pragma once

#include <QDialog>
#include <QMessageBox>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
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
	void initCamera();
	void cameraDeviceSearch();

protected:
	//À§Á¬Ã¢ÀÌ ´ÝÇûÀ»¶§
	void closeEvent(QCloseEvent* event);

private:
	Ui::setupPose* ui;
	QCamera* myCamera;
	QCameraViewfinder* myViewfinder;
	QCameraImageCapture* myCapture;
	QList<QByteArray> camDevNameLists;

private slots:
	void onStartBtn();
	void onStopBtn();
	void onCaptureBtn();
	void camError(QCamera::Error error);
	void imageCapture(int pid, QImage pPriview);
};
