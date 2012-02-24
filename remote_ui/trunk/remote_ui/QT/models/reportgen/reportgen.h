#ifndef REPORTGEN_H
#define REPORTGEN_H
#include <QThread>
#include <QDomDocument>
#include <QFileInfo>

class Reportgen : public QThread
{
    Q_OBJECT;

public:
    bool createInfoFile(QFileInfo odffile, QFileInfo zieldatei);
    bool replaceTemplateVars(QString odffile, QString sedfile, QFileInfo zielDatei);
    bool startReportTemplate(QString odffile, QString sedfile, QFileInfo zielDatei);
    bool replaceEbene(QFile *file, QString odffile);
    int checkSedFile(QString fieldname, QString filename);

    QString getTemplateHeader(QString filename);
    QString getTemplatePosition(int Table, QString odffile);
    QString prepareTemplateContent(int Table, int Position, QString odffile, QString sedfile);
    QString prepareTemplateEbene(int Position, int Ebene, int eben3, int Counter, QDomDocument doc, QString odffile, QString sedfile);
    QString getTemplateFooter(int Table, QString filename);

    bool readSedFile(QString sedfile);
    bool getTemplateVars(QString filename);
    bool checkMetaFile(QString odffile);

private:
    QList<QString> sed_fields;
    QList<QString> temp_fields;
    QList<QString> metaVar;



};

#endif // REPORTGEN_H
