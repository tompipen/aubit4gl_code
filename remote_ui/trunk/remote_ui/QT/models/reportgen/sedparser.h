#ifndef SEDPARSER_H
#define SEDPARSER_H

#include <QObject>
#include <QHash>
#include <QFile>
#include <QDomNode>

class SedParser : public QObject
{
public:
    SedParser(QString path, QString filePath);
    ~SedParser();

    void clear() { m_sedContainer.clear(); }
    void readFile();
    void setFile(QString file ) { m_sedFileName = file; }
    void setWorkingDir(QString path ) { m_workingDir = path; }
    void setValue(QString key, QString value);
    QString filterSed(QString text, QString fileEnding);

    int count(int level1, int level2, int level3, int level4);

    bool readPosFromSed(QString suffix);
    bool readKopfFromSed(QString suffix);
    void closeFile();

    QHash<QString, QString> getColorContainer() { return m_colorContainer; }
    QHash<QString, QString> getPosContainer() { return m_posContainer; }
    QHash<QString, QString> getKopfContainer() { return m_kopfContainer; }

    QString getFile() { return m_sedFileName; }
    QString getWorkingDir() { return m_workingDir; }
    int getPosIndex() { return m_posIndex; }

    bool itemExists(QString key);
    bool isNumber(QString value);
    QList<QString> erseteImage(const QDomNode &rootNode, QString praefix);

    private:

    int m_posIndex;

    QFile *m_sedFile;
    QString m_sedFileName;
    QString m_workingDir;
    QString m_lastFilePos;

    QHash<QString, QString> m_sedContainer;
    QHash <QString, QString> m_posContainer;
    QHash <QString, QString> m_kopfContainer;
    QHash<QString, QString> m_colorContainer;



};

#endif // SEDPARSER_H
