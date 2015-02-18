#ifndef REPORTGEN_H
#define REPORTGEN_H
#include <QThread>
#include <QDomDocument>
#include <QFileInfo>
#include <QPair>
#include <QVector>
#include <QVariant>
#include <QStringList>
#include <QElapsedTimer>

#include "screenhandler.h"

class Reportgen : public QThread
{
    Q_OBJECT;

public:


    void run();
    Reportgen();
    Reportgen(ScreenHandler*);

    void setOdfFile(QString odfFile) { mOdfFile = odfFile; }
    void setSedFile(QString sedFile) { mSedFile = sedFile; }
    void setDestinationFile(QString destinationFile) { mDestinationFile = destinationFile; }
    void setWorkingDir(QString filePath) { mWorkingDir = filePath; }
    void setDebugModus(bool debug) { mDebugModus = debug; }

    QString getWorkingDir() { return mWorkingDir; }
    bool getDebugModus() { return mDebugModus; }


    void printMsg(QString text);

    int getExitCode() { return mExitCode; }

    QString createFirstTable(QString odffile);
    void createXmlFile(int Table, int Position, QString odffile);
    QStringList getHeaderFooterVariables(int, QString);
    void replaceHeaderFooterVariables(int );

    bool createInfoFile(QFileInfo odffile, QFileInfo zieldatei);
    bool replaceTemplateVars(QString odffile, QString sedfile, QFileInfo zielDatei);
    bool replaceTemplateWithoutPosition(QString odffile, QString sedFile, QFileInfo zielDatei);
    bool startReportTemplate(QString odffile, QString sedfile, QFileInfo zielDatei);
    bool replaceEbene(QString file, QString odffile);
    int checkSedFile(QString fieldname, QString filename);

    QString getTemplateHeader(QString filename);
    QString getTemplateHeader(QString filename, QString endung);
    QString getTemplatePosition(int Table, QString TemplateFile);
    QString getTemplatePosition(QString TemplateFile);
    QString prepareTemplateContent(int Table, int Position, QString TemplateFile, QString sedfile);
    QString prepareTemplateContentOdt(int Table, int Position, QString TemplateFile, QString sedfile);
    QString prepareTemplateEbene(int Position, int Ebene, int eben3, int ebene4, int ebene5, int Counter, QDomDocument doc, QString TemplateFile, QString sedfile);
    QString getTemplateFooter(int Table, QString filename, QString suffix);

    QString filterString(QString);
    void filterSedFile();

    void readSedFile(QString sedfile);
    void getTemplateVars(QString filename);
    bool checkMetaFile(QString TemplateFile);
    bool replaceMetaFile(QString TemplateFile);
    QString getVariable(QString);

    typedef QVector<QVariant> chartVector;


    void logMessage(QString);
    QString getXmlStringFromEbene(int, int, QString, int, int, int);
    QString getEbeneVariable(int);

private:

    QStringList sed_fields;
    QList<QString> temp_fields;
    QList<QString> metaVar;
    QList<QString> chartVar;
    QList<QString> chartValues1;
    QList<QString> chartValues2;

    bool mDebugModus;
    ScreenHandler *p_screenHandler;


    QString mOdfFile;
    QString mSedFile;
    QString mDestinationFile;
    QString mWorkingDir;

    QString replaceEbene2;
    QString replaceEbene3;


    QStringList tableCell;

    int mExitCode;

    QElapsedTimer *elapsedTimer;

signals:
    void createChart(QString diag);
    void addChartValue(QString, QString);
    void addChartValue(const chartVector &name , const chartVector &wert);
    void displayChart(QString, int);

public slots:
    void finished();

};

#endif // REPORTGEN_H
