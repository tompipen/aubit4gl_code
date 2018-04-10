#ifndef DOCUMENTINFO_H
#define DOCUMENTINFO_H

#include <QObject>
#include <QFileInfo>
#include <QStringList>

class DocumentInfo : public QObject
{
public:
    DocumentInfo(QString templateFile, QString zielInfoDatei);
    ~DocumentInfo();

    bool  createInfoFile();
    QList<QString> checkVariablesInXmlFile(QFileInfo dirName, QString filename);
    bool checkMetaFile(QString odffile);

    void setZielInfoFile(QString file) {  m_zielInfoFile = file; }
    void setTemplateFile(QString file ) { m_zielInfoFile = file; }
    void setWorkingDir(QString path) { m_workingDir = path; }

    QString getZielInfoFile() { return m_zielInfoFile; }
    QString getTempateFile() { return m_templateFile; }
    QString getWorkingDir() { return m_workingDir; }

private:
    QString m_templateFile;
    QString m_zielInfoFile;
    QString m_workingDir;
    int m_infoEbeneCnt;
    QStringList metaVar;

};

#endif // DOCUMENTINFO_H
