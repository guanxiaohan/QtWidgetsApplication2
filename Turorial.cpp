#include "Tutorial.h"

Tutorial::Tutorial(QMainWindow* parent):
	QMainWindow(parent),
	ui(new Ui::Tutorial) 
{
	ui->setupUi(this);
	ui->centralWidget->setLayout(ui->gridLayout);
	setCentralWidget(ui->centralWidget);

	connect(ui->actionNew, &QAction::triggered, this, &Tutorial::newFile);
	connect(ui->actionNew_command, &QAction::triggered, this, &Tutorial::newCommand);
	
	QFile Qss("styleSheet.qss");
	Qss.open(QFile::ReadOnly);
	QTextStream QssText(&Qss);
	QString styleSheet = QssText.readAll();
	setStyleSheet(styleSheet);
	Qss.close();
}

Tutorial::~Tutorial() {
	delete ui;
	for (int i = Tabs.size(); i > 0; i--) {
		Tabs.removeAt(i - (long)1);
	}
	for (int i = cmdTabs.size(); i > 0; i--) {
		cmdTabs.removeAt(i - (long)1);
	}
}

void Tutorial::newFile() 
{
	textPage* unit = new textPage();
	ui->tabWidget->addTab(unit, tr("Untitled"));
	Tabs.append(unit);
}



void Tutorial::openFile()
{

}

void Tutorial::newCommand()
{
	powerShell* unit = new powerShell();
	ui->CmdTabWidget->addTab(unit, tr("powerShell"));
	cmdTabs.append(unit);
}
