#ifndef MASTERUPDATE_H
#define MASTERUPDATE_H
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QFile>
#include <QApplication>
#include <QDir>
#include <QThread>

class MasterUpdate : public QThread
{
    Q_OBJECT

public:
    MasterUpdate(QObject *parent = 0);
    void start();
    void run();

public slots:
    void finish(QNetworkReply*);
    void extractPatcher(QNetworkReply*);
};

#endif // MASTERUPDATE_H
