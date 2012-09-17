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

class MasterUpdate : public QWidget
{
    Q_OBJECT

public:
    MasterUpdate(QObject *parent = 0);
    void start();

public slots:
    void finish(QNetworkReply*);
    void extractPatcher(QNetworkReply*);
};

#endif // MASTERUPDATE_H
