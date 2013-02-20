#ifndef VENTASUPDATE_H
#define VENTASUPDATE_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDomDocument>
#include <QApplication>
#include <QDate>
#include "mainframe.h"

class VentasUpdate : public QWidget
{
    Q_OBJECT

public:
    VentasUpdate(int, QWidget *parent = 0);
    void start();
    void checkServerClient();

public slots:
    void readXmlFinished(QNetworkReply*);
    void checkOpenConnections();
    void downloadBinarie();
    void closeVdc();

private:
    QList<QList<QString> > parseXml(QString);
    QList<QString> clientXml(QString);
    int displayErrorDialog;
    Dialog *m_dialog;
    
};

#endif // VENTASUPDATE_H
