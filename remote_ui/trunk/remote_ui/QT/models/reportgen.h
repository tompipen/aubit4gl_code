#ifndef REPORTGEN_H
#define REPORTGEN_H
#include <QtGui>
#include <QDomDocument>

class Reportgen : public QObject
{
    Q_OBJECT;

public:
    bool createInfoFile(QFileInfo odffile, QFileInfo zieldatei);
    bool replaceTemplateVars(QString odffile, QString sedfile, QFileInfo zielDatei);
    bool startReportTemplate(QString odffile, QString sedfile, QFileInfo zielDatei);
    int checkSedFile(QString fieldname, QString filename);

    QString getTemplateHeader(QString filename);
    QString getTemplatePosition(QString odffile);
    QString prepareTemplateContent(int Position, QString odffile, QString sedfile);
    QString prepareTemplateEbene(int Position, int Ebene, int Counter, QDomDocument doc, QString odffile);
    QString getTemplateFooter(QString filename);

    QList<QString> readSedFile(QString sedfile);
    QList<QString> getTemplateVars(QString filename);



};

#endif // REPORTGEN_H
