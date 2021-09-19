#include "powerShell.h"
#include "ui_powerShell.h"

powerShell::powerShell(QWidget *parent)
	: QDockWidget(parent),
	ui(new Ui::powerShell)
{
	ui->setupUi(this);

	
}

powerShell::~powerShell()
{
	delete ui;
}
