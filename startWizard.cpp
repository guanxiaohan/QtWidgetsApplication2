#include "startWizard.h"
#include "ui_startWizard.h"

startWizard::startWizard(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::startWizard();
	ui->setupUi(this);
}

startWizard::~startWizard()
{
	delete ui;
}
