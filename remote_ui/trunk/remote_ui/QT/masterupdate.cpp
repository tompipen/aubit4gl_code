#include "masterupdate.h"
#include "models/zipunzip.h"
#include <QDebug>

MasterUpdate::MasterUpdate(QObject *parent) : QWidget()
{
    Q_UNUSED(parent);
}

void MasterUpdate::start()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    manager->get(QNetworkRequest(QUrl("http://www.ventas.de/wp-content/uploads/downloads/autoupdate/update.xml")));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finish(QNetworkReply*)));
    connect(manager, SIGNAL(finished(QNetworkReply*)), manager, SLOT(deleteLater()));

}

void MasterUpdate::finish(QNetworkReply *reply)
{
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

        if(clientMd5 != md5Hash)
        {
            qDebug() << "Hash ist unterschiedlich, starte Patchvorgang für Patcher.";
            QNetworkAccessManager *manager = new QNetworkAccessManager;
            manager->get(QNetworkRequest(QUrl("http://www.ventas.de/wp-content/uploads/downloads/autoupdate/binaries/masterpatch.zip")));
            connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(extractPatcher(QNetworkReply*)));
        }
        return;
    }
}

void MasterUpdate::extractPatcher(QNetworkReply *reply)
{
    if(!reply->error())
    {
        QFile file(QDir::tempPath() + "/masterpatch.zip");

        if(!file.open(QIODevice::WriteOnly))
        {
            qDebug() << "Kann nicht schreiben";
            return;
        }
        file.write(reply->readAll());
        file.close();

        if(file.exists())
        {
            ZipUnzip *p_zipunzip = new ZipUnzip();

            if(!p_zipunzip->unzipArchiv(QDir::tempPath(), "masterpatch.zip", QApplication::applicationDirPath()))
            {
                qDebug() << "archiv konnte nicht entpackt werden";
                return;
            }
        }
    }
}
