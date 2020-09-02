#include "popupc.h"

popupc::popupc(QWidget *parent)
	: QDialog(parent), ui(new Ui::popupc)
{
	ui->setupUi(this);
}

popupc::~popupc()
{
	delete ui;
}
