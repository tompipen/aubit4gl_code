#ifndef PATCHER_H
#define PATCHER_H

#include <qglobal.h>
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
#include <QWidget>
#else
#include <QtWidgets/QtWidgets>
#endif
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDomDocument>
#include "include/vdc.h"
#include <QVBoxLayout>
#include <QProgressBar>
#include <QLabel>
#include <QDesktopServices>
#include <QTextEdit>
#include <QPushButton>
#include <QNetworkReply>

class VDCUpdate : public QWidget
{
    Q_OBJECT

public:
    VDCUpdate();
    ~VDCUpdate();
    void start();
    void logMessage(QString);

private:
    int displayErrorDialog;
    QMessageBox *mBox;
    QLabel *mLabel;
    QProgressBar *mProgress;
    QNetworkReply *mReply;
    QPushButton *mPushbutton;
    QTextEdit *mTextEdit;
    QPushButton *cButton;

public slots:
    void updateDownloadProgress(qint64,qint64);
    void loadServerXmlFinished(QNetworkReply*);
    void loadBinarieFinished(QNetworkReply*);
    void abort();
    void setUpdateComplete();

private:
    void loadServerXml();
    void requestFileFromServer();
    void checkXmlFile();
    void beginReadXml();
    void loadBinarie();
    QList<QList<QString> > readServerXml(QString);
    QList<QString> readClientXml(QString);
    QString findPackage();

    //Getter

    QProgressBar* getProgressBar() { return mProgress; };
    QLabel* getLabel() { return mLabel; };
    QTextEdit* getTextEdit() { return mTextEdit; };


    //Setter

};

#endif // PATCHER_H
