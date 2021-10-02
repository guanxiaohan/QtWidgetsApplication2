#include "Projecter.h"
//abc
Projecter::Projecter(QString fileUrl)
{
	QFile file(fileUrl);
	QTextStream out(&file);
	if (/*QFileInfo(fileUrl).suffix().toLower() == QString(".iep")*/true) {
		if (file.open(QFile::ReadOnly)) {
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
			abort();
		}
	}
	else {
		qDebug() << "Not .iep file";
	}
}

Projecter::~Projecter()
{
}

Projecter::File Projecter::addFile(QString fileName, fileTypes fileType = Unset, int fileId = 1)
{
	return File();
}

Projecter::File Projecter::removeFile(QString fileName)
{
	return File();
}

Projecter::File Projecter::removeFile(int fileId)
{
	return File();
}

QList<Projecter::File> Projecter::removeFiles(fileTypes type)
{
	return QList<File>();
}

QList<Projecter::File> Projecter::removeFiles(QList<fileTypes> types)
{
	return QList<File>();
}

bool Projecter::setFile(int fileId, QString fileName)
{
	return false;
}

Projecter::File Projecter::fileAt(int fileId)
{
	return File();
}

QList<Projecter::File> Projecter::filesOfType(fileTypes type)
{
	return QList<File>();
}

int Projecter::idOf(File file)
{
	return 0;
}

int Projecter::idOf(QString fileName, fileTypes type)
{
	return 0;
}

QList<Projecter::File> Projecter::allFiles()
{
	return ProjectFiles;
}
