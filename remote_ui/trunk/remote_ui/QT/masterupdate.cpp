#include "masterupdate.h"
#include "models/zipunzip.h"
#include <QDebug>

MasterUpdate::MasterUpdate(QObject *parent) : QThread()
{
    Q_UNUSED(parent);
}
void MasterUpdate::run()
{
    this->start();
}

void MasterUpdate::start()
{
    QString patcherXmlFile;
    #ifdef Q_WS_MAC
        patcherXmlFile = "patchermac.xml";
    #endif
    #ifdef Q_WS_X11
        patcherXmlFile = "patcherlin.xml";
    #endif
    #ifdef Q_WS_WIN
        patcherXmlFile = "patcherwin.xml";
    #endif

    qDebug() << "Lade update.xml vom Server";
    QNetworkAccessManager *manager = new QNetworkAccessManager;
    manager->get(QNetworkRequest(QUrl(QString("http://www.ventas.de/wp-content/uploads/downloads/autoupdate/%1").arg(patcherXmlFile))));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finish(QNetworkReply*)));

}

void MasterUpdate::finish(QNetworkReply *reply)
{
    qDebug() << "Ueberpruefe hash Summe";
    QString md5Hash;
    if(!reply->error())
    {
        QByteArray ba_read = reply->readAll();
        md5Hash = ba_read;

        QFile file(QApplication::applicationDirPath() + "/update.ini");

        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << QString("ERROR: update.ini nicht lesbar in: %1").arg(file.fileName());
            return;
        }
        QString clientMd5 = file.readAll().trimmed();

        if(clientMd5 != md5Hash.trimmed())
        {
            QString patchFileName;
            #ifdef Q_WS_WIN
                patchFileName = "masterwin.zip";
            #endif
            #ifdef Q_WS_X11
                patchFileName = "masterlin.zip";
            #endif
            #ifdef Q_WS_MAC
                patchFileName = "mastermac.zip";
            #endif
            qDebug() << "Hash ist unterschiedlich, starte Patchvorgang für Patcher.";
            QNetworkAccessManager *manager = new QNetworkAccessManager;
            manager->get(QNetworkRequest(QUrl(QString("http://www.ventas.de/wp-content/uploads/downloads/autoupdate/binaries/%1").arg(patchFileName))));
            connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(extractPatcher(QNetworkReply*)));
        }
        return;
    } else {
        qDebug() << "Network error!";
    }
}

void MasterUpdate::extractPatcher(QNetworkReply *reply)
{
    if(!reply->error())
    {
        QString patchFileName;
        #ifdef Q_WS_WIN
            patchFileName = "masterwin.zip";
        #endif
        #ifdef Q_WS_X11
            patchFileName = "masterlin.zip";
        #endif
        #ifdef Q_WS_MAC
            patchFileName = "mastermac.zip";
        #endif
        QFile file(QString(QDir::tempPath() + "/%1").arg(patchFileName));

        if(!file.open(QIODevice::WriteOnly))
        {
            qDebug() << "Kann nicht schreiben";
            return;
        }
        file.write(reply->readAll());
        file.close();

        if(file.exists())
        {
            #ifdef VREPGEN_USE
                ZipUnzip *p_zipunzip = new ZipUnzip();

                if(!p_zipunzip->unzipArchiv(QDir::tempPath(), patchFileName, QApplication::applicationDirPath()))
                {
                    qDebug() << "archiv konnte nicht entpackt werden";
                    return;
                }
            #endif
        }
    } else {
        qDebug() << "Datei auf Webserver nicht gefunden!";
    }
}
