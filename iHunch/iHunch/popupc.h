#pragma once

#include <QDialog>
#include <QCloseEvent>
#include <QAction>
#include "ui_popupc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class popupc; }
QT_END_NAMESPACE

class popupc : public QDialog
{
	Q_OBJECT

public:
	popupc(QWidget *parent = Q_NULLPTR);
	~popupc();

private:
	Ui::popupc* ui;
};
