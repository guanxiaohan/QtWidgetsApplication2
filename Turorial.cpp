#include "Tutorial.h"

Tutorial::Tutorial(QMainWindow* parent):
	QMainWindow(parent),
	ui(new Ui::Tutorial) 
{
	ui->setupUi(this);
	ui->centralWidget->setLayout(ui->gridLayout);
	setCentralWidget(ui->centralWidget);
}

Tutorial::~Tutorial() {
	delete ui;
}