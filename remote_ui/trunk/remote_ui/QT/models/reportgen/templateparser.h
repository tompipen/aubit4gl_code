#ifndef TEMPLATEPARSER_H
#define TEMPLATEPARSER_H

#include <QObject>
#include <QDomDocument>

class TemplateParser
{
public:
    TemplateParser(QString path, QString file);
    void pruefeBarcode(const QDomNode& rootNode);
    void readTemplateFile();
    bool unzipDocument(QString workingDir);
    bool zipDocument(QString workingDir, QString destFileName);
    void readVariables(QDomElement rootElement);

    void setFile(QString file) { m_templateFile = file; }
    void setWorkingDir(QString path) {m_workingDir = path; }
    void setOrigDocument() { m_templateDocument = m_templateDocument_orig; }

    QDomDocument getDocument() { return m_templateDocument; }
    void readElementsFromDocument(QDomElement rootElement);
    QList<QDomElement> getElementsByLevel(int level);

    QString getVariableFromLevel(int level);
    QString getDocumentWithEnding();
    QString getDocumentBaseName();
    QString getSuffix();
    QString getFilePath();
    QString getFile() { return m_templateFile; }
    QString getWorkingDir() {return m_workingDir; }
    QStringList getVariableList(QString value);

    void appendToManifestFile(QString type, QString value);
private:
    QString m_templateFile;
    QString m_workingDir;
    QDomDocument m_templateDocument;
    QDomDocument m_templateDocument_orig;

    QList<QDomElement> firstLevelElementList;
    QList<QDomElement> secondLevelElementList;
    QList<QDomElement> thirdLevelElementList;
    QList<QDomElement> fourthLevelElementList;
    QList<QDomElement> fifthLevelElementList;

    bool m_rememberLevel1;
    bool m_rememberLevel2;
    bool m_rememberLevel3;

    QString m_variableLevel1;
    QString m_variableLevel2;
    QString m_variableLevel3;

    static const int FIRST_VALID_YEAR = 1970;

};

#endif // TEMPLATEPARSER_H
