#pragma once

#include <QDialog>
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

private:
	Ui::setupPose* ui;
};
