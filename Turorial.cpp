#include "Tutorial.h"

Tutorial::Tutorial(QMainWindow* parent):
	QMainWindow(parent),
	ui(new Ui::Tutorial) 
{
	ui->setupUi(this);
	ui->centralWidget->setLayout(ui->gridLayout);
	setCentralWidget(ui->centralWidget);
	ui->CmdTabWidget->setHidden(true);
	ui->gridLayoutWidget_2->setLayout(ui->gridLayout_2);
	ui->ProjectViewer->setWidget(ui->gridLayoutWidget_2);
	Projecter project();

	connect(ui->actionNew, &QAction::triggered, this, &Tutorial::newFile);
	connect(ui->actionNew_command, &QAction::triggered, this, &Tutorial::newCommand);
	connect(ui->actionOpen_file, &QAction::triggered, this, &Tutorial::openFile);
	connect(ui->actionOpen_project, &QAction::triggered, this, &Tutorial::openProject);
	connect(ui->actionSave, &QAction::triggered, this, &Tutorial::saveFile);
	connect(ui->actionNew_command, &QAction::triggered, this, &Tutorial::showCommand);
	connect(ui->actionPrint, &QAction::triggered, this, &Tutorial::printCode);

	connect(ui->projectListWidget, &QListWidget::itemDoubleClicked, this, &Tutorial::projectFileOpened);
		
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
		Tabs.removeAt(i - 1);
	}
	for (int i = cmdTabs.size(); i > 0; i--) {
		cmdTabs.removeAt((long)i - (long)1);
	}
}

void Tutorial::newFile() 
{
	if (!projectOpened) {
		textPage* unit = new textPage();
		ui->tabWidget->addTab(unit, tr("Untitled"));
		Tabs.append(unit);
	}
	else {
		NewFileDialog dialog({ "Unset", "Cpp" });
		if (dialog.exec() == QDialog::Accepted) {
			auto args = dialog.getResult();
			auto arg = args.split(";;");
			QFile file(arg[1] + "/" + arg[2]);
			file.open(QFile::WriteOnly);
			file.close();
			project.addFile(arg[1] + "/" + arg[2], Projecter::Unset);
			reflashProjectTreeWidget();
		}
	}
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
			QMessageBox::information(this, "Debug", "File:" + fileName + " Text:\n" + content);
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

void Tutorial::reflashProjectTreeWidget()
{
	ui->projectListWidget->clear();
	ProjectFilesItem.clear();
	auto fileList = project.allFiles();
	for (auto i : fileList) {
		auto item = new QListWidgetItem(ui->projectListWidget);
		item->setText(i.FileName);
		ProjectFilesItem.append(item);
		ui->projectListWidget->update();
	}
}

void Tutorial::saveFile()
{
	if (Tabs[ui->tabWidget->currentIndex()]->currentFile.isEmpty()) {
		Tabs[ui->tabWidget->currentIndex()]->currentFile = QFileDialog::getSaveFileName(this, "Save file to:", "./", "All files(*.*);;Text file(*.txt);;C++ files(*.cpp;*.h)");
		if (Tabs[ui->tabWidget->currentIndex()]->currentFile.isEmpty())return;
	}
	QString fileName = Tabs[ui->tabWidget->currentIndex()]->currentFile;
	QFile file(fileName);
	QMessageBox::information(this, "Debug", "File:" + fileName);
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

void Tutorial::printCode()
{
	QPrinter printer;
	QPrintDialog pDialog(&printer, this);
	pDialog.exec();
}

void Tutorial::openProject()
{
	auto projectDir = QFileDialog::getOpenFileName(this, "Open project from project file:*.iep:", "./", "IDLE Project(*.iep)");
	project.setProjectDir(projectDir);
	auto fileList = project.allFiles();
	for (auto i : fileList) {
		auto item = new QListWidgetItem(ui->projectListWidget);
		item->setText(i.FileName);
		ProjectFilesItem.append(item);
		ui->projectListWidget->update();
	}
	projectOpened = true;
	//Not all.
}

void Tutorial::openProjectFile(const QString dir)
{
	if (!dir.isEmpty()) {
		QFile file(dir);
		if (file.open(QFile::ReadOnly)) {
			QTextStream out(&file);
			QString content;
			content = out.readAll();
			textPage* unit = new textPage(dir, content);
			ui->tabWidget->addTab(unit, QFileInfo(dir).fileName());
			QMessageBox::information(this, "Debug", "File:" + dir + " Text:\n" + content);
			Tabs.append(unit);
			file.close();
		}
		else {
			if (file.exists()) {
				QMessageBox::warning(this, "File open error", "Uncaught error with opening file:\n" + file.errorString());
			}
			else {
				auto result = QMessageBox::warning(this, "File open error", 
					"File doesn't exists!\nDo you want to remove it from the project?",
					QMessageBox::Yes|QMessageBox::Retry|QMessageBox::No);
				if (result == QMessageBox::Yes) {
					project.removeFile(file.fileName());
					reflashProjectTreeWidget();
				}
				else if (result == QMessageBox::Retry) {
					openProjectFile(dir);
				}
				else {
					;
				}
			}
		}
	}
}

void Tutorial::projectFileOpened(QListWidgetItem* item)
{
	openProjectFile(item->text());
}
