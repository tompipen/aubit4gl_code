#ifndef VDCUPDATE_H
#define VDCUPDATE_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMap>

class DownloadManager : public QObject
{
    Q_OBJECT
public:
    DownloadManager(bool);

    void searchForUpdate();
    bool checkClientVersion();

    bool showErrorMessage() { return mShowErrorMsg; }

    void createWorkingDir();
    void cleanVdcFolder();

    QHash<QString,QString> parseXmlFile(QString file);
public slots:
    void readVersionXml(QNetworkReply *reply = NULL);
    void openPatcher();
protected:
    bool mAutoUpdate;
    bool mShowErrorMsg;
    bool mUpdateRequired;

};

#endif // VDCUPDATE_H
