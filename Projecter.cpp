#include "Projecter.h"
Projecter::Projecter()
{

}
//ddd
//15966862453b
Projecter::Projecter(QString fileUrl)
{
	setProjectDir(fileUrl);
}

Projecter::~Projecter()
{
}

void Projecter::setProjectDir(QString dir)
{
	QFile file(dir);
	QTextStream out(&file);
	if (/*QFileInfo(fileUrl).suffix().toLower() == QString(".iep")*/true) {
		if (file.open(QFile::ReadOnly)) {
			ProjectLocation = dir;
			QString ProjectText = out.readAll();
			file.close();
			ProjectText.replace("\n", "");
			ProjectText.replace("\t", "");
			ProjectText.replace(" ", "");
			auto Arguments = ProjectText.split(";;");
			ProjectName = Arguments[0];
			ProjectType = Arguments[1];
			auto Files = Arguments[2].split(";");
			for (auto file : Files) {
				auto FileArguments = file.split("//");
				File m_file;
				m_file.FileName = FileArguments[0];
				switch (FileArguments[1].toInt()) {
				case 0:m_file.FileType = Unknown;
				case 1:m_file.FileType = Unset;
				case 2:m_file.FileType = Text;
				case 3:m_file.FileType = Cpp;
				case 4:m_file.FileType = Cpp_Header;
				case 5:m_file.FileType = C;
				case 6:m_file.FileType = Dll;
				case 7:m_file.FileType = Python;
				case 8:m_file.FileType = Json;
				case 9:m_file.FileType = HTML;
				case 10:m_file.FileType = Xml;
				case 11:m_file.FileType = CSS;
				case 12:m_file.FileType = JavaScript;
				case 13:m_file.FileType = SQL;
				case 14:m_file.FileType = VB;
				case 15:m_file.FileType = VBS;
				case 16:m_file.FileType = Java;
					//Not all, add it later.
				}
				m_file.fileId = FileArguments[2].toInt();
				ProjectFiles.append(m_file);
			}
		}
		else {
			;
		}
	}
	else {
		qDebug() << "Not .iep file";
	}
}

Projecter::File Projecter::addFile(QString fileName, fileTypes fileType, int fileId)
{
	if (fileId == -1) {
		fileId = ProjectFiles.count();
	}
	ProjectFiles.append(File(fileName, fileType, fileId));
	return File(fileName, fileType, fileId);
}

Projecter::File Projecter::removeFile(QString fileName)
{
	int count = 0;
	for (auto i : ProjectFiles) {
		if (i.FileName == fileName) {
			ProjectFiles.removeAt(count);
			return i;
		}
		count++;
	}
	return File();
}

Projecter::File Projecter::removeFile(int fileId)
{
	int count = 0;
	for (auto i : ProjectFiles) {
		if (i.fileId == fileId) {
			ProjectFiles.removeAt(count);
			return i;
		}
		count++;
	}
	return File();
}

QList<Projecter::File> Projecter::removeFiles(fileTypes type)
{
	/*
	QList<Projecter::File> file_list;
	for (auto i : ProjectFiles) {
		if (i.FileType == type) {
			file_list.append(i);
			ProjectFiles.removeOne(i);
		}
	}
	return file_list;*/
	return QList<File>();
}

QList<Projecter::File> Projecter::removeFiles(QList<fileTypes> types)
{
	/*
	QList<Projecter::File> file_list;
	for (auto i : ProjectFiles) {
		for (auto j : types) {
			if (i.FileType == j) {
				file_list.append(i);
				ProjectFiles.removeOne(i);
			}
		}
	}
	return file_list;*/
	return QList<File>();
}

bool Projecter::setFile(int fileId, QString fileName)
{
	for (auto i : ProjectFiles) {
		if (i.fileId == fileId) {
			i.FileName = fileName;
			return true;
		}
	}
	return false;
}

Projecter::File Projecter::fileAt(int fileId)
{
	for (auto i : ProjectFiles) {
		if (i.fileId == fileId) {
			return i;
		}
	}
	return File();
}

QList<Projecter::File> Projecter::filesOfType(fileTypes type)
{
	return QList<File>();
}

int Projecter::idOf(File file)
{
	return file.fileId;
}

int Projecter::idOf(QString fileName)
{
	for (auto i : ProjectFiles){
		if (i.FileName == fileName) {
			return i.fileId;
		}
	}
	return -1;
}

QList<Projecter::File> Projecter::allFiles()
{
	return ProjectFiles;
}
