#include "setupPose.h"

setupPose::setupPose(QWidget *parent)
	: QDialog(parent), ui(new Ui::setupPose)
{
	ui->setupUi(this);
}

setupPose::~setupPose()
{
	delete ui;
}
