#pragma once

#include <QWidget>
#include "ui_overlay.h"

QT_BEGIN_NAMESPACE
namespace Ui { class overlay; }
QT_END_NAMESPACE

class overlay : public QWidget
{
	Q_OBJECT

public:
	overlay(QWidget *parent = Q_NULLPTR);
	~overlay();

public:
	Ui::overlay* ui;
public slots:
	void overlayColorChange(int mode);
};