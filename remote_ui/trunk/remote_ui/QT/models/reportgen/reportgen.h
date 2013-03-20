#ifndef REPORTGEN_H
#define REPORTGEN_H
#include <QThread>
#include <QDomDocument>
#include <QFileInfo>
#include <QPair>
#include <QVector>
#include <QVariant>
#include <QStringList>
#include <screenhandler.h>

class Reportgen : public QThread
{
    Q_OBJECT;

public:


    void run();
    Reportgen(ScreenHandler*);
    Reportgen();

    void setOdfFile(QString odfFile) { mOdfFile = odfFile; }
    void setSedFile(QString sedFile) { mSedFile = sedFile; }
    void setDestinationFile(QString destinationFile) { mDestinationFile = destinationFile; }

    int getExitCode() { return mExitCode; }

    QString createFirstTable(QString odffile, int wiederholen);
    void createXmlFile(int Table, int Position, QString odffile, QString sedfile);
    QStringList getHeaderVariables();
    void replaceHeaderVariables();

    bool createInfoFile(QFileInfo odffile, QFileInfo zieldatei);
    bool replaceTemplateVars(QString odffile, QString sedfile, QFileInfo zielDatei);
    bool replaceTemplateWithoutPosition(QString odffile, QString sedFile, QFileInfo zielDatei);
    //bool startReportTemplate(QString odffile, QString sedfile, QFileInfo zielDatei);
    bool replaceEbene(QFile file, QString odffile);
    int checkSedFile(QString fieldname, QString filename);

    QString getTemplateHeader(QString filename);
    QString getTemplateHeader(QString filename, QString endung);
    QString getTemplatePosition(int Table, QString odffile);
    QString getTemplatePosition(QString odffile);
    QString prepareTemplateContent(int Table, int Position, QString odffile, QString sedfile);
    QString prepareTemplateContentOdt(int Table, int Position, QString odffile, QString sedfile);
    QString prepareTemplateEbene(int Position, int Ebene, int eben3, int ebene4, int ebene5, int Counter, QDomDocument doc, QString odffile, QString sedfile);
    QString getTemplateFooter(int Table, QString filename);

    void readSedFile(QString sedfile);
    void getTemplateVars(QString filename);
    bool checkMetaFile(QString odffile);
    bool replaceMetaFile(QString odffile);
    QString getVariable(QString);

    typedef QVector<QVariant> chartVector;


    void logMessage(QString);
    QString getXmlStringFromEbene(int, int, QString);
    QString getEbeneVariable(int);

private:

    QStringList sed_fields;
    QList<QString> temp_fields;
    QList<QString> metaVar;
    QList<QString> chartVar;
    QList<QString> chartValues1;
    QList<QString> chartValues2;


    QString mOdfFile;
    QString mSedFile;
    QString mDestinationFile;

    QString replaceEbene2;
    QString replaceEbene3;


    QStringList tableCell;

    ScreenHandler *p_screenHandler;

    int mExitCode;

signals:
    void createChart(QString diag);
    void addChartValue(QString, QString);
    void addChartValue(const chartVector &name , const chartVector &wert);
    void displayChart(QString, int);

public slots:
    void finished();



};

#endif // REPORTGEN_H
