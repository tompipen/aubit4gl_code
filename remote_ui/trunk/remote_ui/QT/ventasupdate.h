#ifndef VENTSAUPDATE_H
#define VENTSAUPDATE_H
#include <QWidget>
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
#include "mainframe.h"


class VentasUpdate : public QWidget
{
    Q_OBJECT

public:
    VentasUpdate(int, QObject*, QWidget *parent = 0);
    void checkForNewUpdates();
private:
    QList<QList<QString> > parseXml(QString);
    void readServerXml(QString);
    void loadFileFromServer();
    void checkServerClient();

public slots:
    void readXmlFinished(QNetworkReply*);
    void updateReady(QNetworkReply*);
    void updateDownloadProgress(qint64,qint64);
    void checkOpenConnections();
    void responseDownload();
    void abortDownload();


private:
    int displayErrorDialog;
    QMessageBox *m_box;
    QLabel *m_label;
    QProgressBar *m_progress;
    QObject *m_screenhandler;
    Dialog *m_dialog;
    QString m_fileName;
    QString m_dateToDownload;
    //MainFrame m_mainFrame;
    QNetworkReply *m_reply;
    Dialog *downloadDialog;

    int mh;
    int mw;
};

#endif // VENTSAUPDATE_H
