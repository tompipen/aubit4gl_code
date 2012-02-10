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
    bool replaceEbene(QFile *file, QString odffile);
    int checkSedFile(QString fieldname, QString filename);

    QString getTemplateHeader(QString filename);
    QString getTemplatePosition(QString odffile);
    QString prepareTemplateContent(int Position, QString odffile, QString sedfile);
    QString prepareTemplateEbene(int Position, int Ebene, int eben3, int Counter, QDomDocument doc, QString odffile, QString sedfile);
    QString getTemplateFooter(QString filename);

    QList<QString> readSedFile(QString sedfile);
    QList<QString> getTemplateVars(QString filename);



};

#endif // REPORTGEN_H
