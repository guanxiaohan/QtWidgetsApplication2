#include "Tutorial.h"

Tutorial::Tutorial(QMainWindow* parent):
	QMainWindow(parent),
	ui(new Ui::Tutorial) 
{
	ui->setupUi(this);
	ui->centralWidget->setLayout(ui->gridLayout);
	setCentralWidget(ui->centralWidget);

	connect(ui->actionNew, &QAction::triggered, this, &Tutorial::newFile);
	
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
