#ifndef REPORTGEN_H
#define REPORTGEN_H

#include <QObject>
#include <QTime>


#include "sedparser.h"
#include "templateparser.h"

#define REPGEN_VERSION_MAJOR  3
#define REPGEN_VERSION_MINOR  0
#define REPGEN_VERSION_MICRO  1

class ReportGenerator : public QObject
{
public:
    ReportGenerator(QString templateFileName, QString sedFileName, QString destinationFileName);
    ~ReportGenerator();
    void start();
    bool isValidDate(QString value);

    void copyFilesToWorkingDir(QString templateFileName, QString sedFileName);
    void createOpenDocumentSpreadsheet();
    void saveTemplate();
    void mergeFiles();
    void replaceVariable(QDomElement rootElement);
    void cleanWorkspace();
    bool removeDir(const QString &dirName);

    void replaceVarsInStylesFile();

    void expandVarsKopf(QDomElement node);
    int expandVarsPos(QString praefix, int stufe, int machStufe, QDomElement node);


    void appendLevelsToXml(int ebene1, int ebene2, int ebene3, int ebene4, QDomElement rootElement);

    int getLogLevel();
    void setLogLevel(int level);


    void setDestinationFile(QString file ) { m_destinationFile = file; }
    void setWorkingDir(QString path) { m_workingDir = path; }

    QString getWorkingDir() { return m_workingDir; }

private:

    QTime m_time;

    SedParser *p_sedParser;
    TemplateParser *p_templateParser;
    QString m_destinationFile;
    QString m_workingDir;

    bool start1;
    bool startRemove;

};

#endif // REPORTGEN_H
