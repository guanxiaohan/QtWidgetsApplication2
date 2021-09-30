#include "Tutorial.h"

Tutorial::Tutorial(QMainWindow* parent):
	QMainWindow(parent),
	ui(new Ui::Tutorial) 
{
	ui->setupUi(this);
	ui->centralWidget->setLayout(ui->gridLayout);
	setCentralWidget(ui->centralWidget);
	ui->CmdTabWidget->setHidden(true);

	connect(ui->actionNew, &QAction::triggered, this, &Tutorial::newFile);
	connect(ui->actionNew_command, &QAction::triggered, this, &Tutorial::newCommand);
	connect(ui->actionOpen_file, &QAction::triggered, this, &Tutorial::openFile);
	connect(ui->actionSave, &QAction::triggered, this, &Tutorial::saveFile);
	//connect(ui->CmdTabWidget, &QTabWidget::, this, &Tutorial::showCommand);
		
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
		Tabs.removeAt(i - (int)1);
	}
	for (int i = cmdTabs.size(); i > 0; i--) {
		cmdTabs.removeAt(i - (int)1);
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
	auto fileName = QFileDialog::getOpenFileName(this, "Open file:", "./",
		"Text file(*.txt);;C++ files(*.cpp;*.h)");
	if (!fileName.isEmpty()) {
		QFile file(fileName);
		if (file.open(QFile::ReadOnly)) {
			QTextStream out(&file);
			QString content;
			content = out.readAll();
			textPage* unit = new textPage(fileName, content);
			ui->tabWidget->addTab(unit, QFileInfo(fileName).fileName());
			Tabs.append(unit);
			file.close();
		}
		else {
			QMessageBox::warning(this, "File open error", "Uncaught error with opening file:\n" + file.errorString());
		}
	}
}

void Tutorial::newCommand()
{
	powerShell* unit = new powerShell();
	ui->CmdTabWidget->addTab(unit, tr("powerShell"));
	cmdTabs.append(unit);
}

void Tutorial::saveFile()
{
	if (Tabs[ui->tabWidget->currentIndex()]->currentFile.isEmpty()) {
		Tabs[ui->tabWidget->currentIndex()]->currentFile = QFileDialog::getSaveFileName(this, "Save file to:", "./", "Text file(*.txt);;C++ files(*.cpp;*.h)");
		if (Tabs[ui->tabWidget->currentIndex()]->currentFile.isEmpty())return;
	}
	QString fileName = Tabs[ui->tabWidget->currentIndex()]->currentFile;
	QFile file(fileName);
	if (file.open(QFile::WriteOnly)) {
		QString fileText = Tabs[ui->tabWidget->currentIndex()]->GetText();
		file.write(fileText.toStdString().data());
		Tabs[ui->tabWidget->currentIndex()]->setFile(fileName);
		ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), QFileInfo(fileName).fileName());
		file.close();
		statusBar()->showMessage(tr("File saved successfully."), 4000);
	}
	else {
		QMessageBox::warning(this, "File open error", "Uncaught error with opening file:\n" + file.errorString());
	}
	return;
}

void Tutorial::showCommand()
{
	ui->CmdTabWidget->show();
}
