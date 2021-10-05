#pragma once
#include <QDir>
#include <QFile>
#include <QList>
#include <QFileInfo>
#include <QTextStream>
#include <QMessageBox>
/*
	ProjectDir;;
	ProjectType;;
	    ProjectFile1Dir//ProjectFile1Type//ProjectFile1Id;
		ProjectFile2Dir//ProjectFile2Type//ProjectFile2Id;
		......
*/
//https://github.com/guanxiaohan/QtWidgetsApplication2.git
class Projecter:public QObject
{
public:
	enum fileTypes {
		Unknown,
		Unset, Text, Cpp, Cpp_Header, C, Dll, Python, Json, HTML, Xml, CSS, JavaScript, SQL, VB, VBS, Java,
		Unset_picture, Png, Jpg, Svg, Bmp, Ico,
		Unset_audio, Mp3, Wav, Ogg, Flav
	};
	QString ProjectName;
	QString ProjectType;
	struct File {
		QString FileName;
		fileTypes FileType;
		int fileId;
	};
	QList<File> ProjectFiles;
	QString ProjectLocation;

	Projecter();
	Projecter(QString fileUrl);
	~Projecter();

	void setProjectDir(QString dir);
	File addFile(QString fileName, fileTypes fileType, int fileId);
	File removeFile(QString fileName);
	File removeFile(int fileId);
	QList<File> removeFiles(fileTypes type);
	QList<File> removeFiles(QList<fileTypes> types);
	bool setFile(int fileId, QString fileName);
	/*
	File fileAt(int fileId);
	QList<File> filesOfType(fileTypes type);
	int idOf(File file);
	int idOf(QString fileName, fileTypes type = Unknown);
	*/
	QList<File> allFiles();
};

