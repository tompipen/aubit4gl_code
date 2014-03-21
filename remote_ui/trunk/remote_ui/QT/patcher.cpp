#include "patcher.h"
#include "models/zipunzip.h"
#include <QUrl>
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("VENTAS");
    QCoreApplication::setOrganizationDomain("ventas.de");
    QCoreApplication::setApplicationName("VDC - Ventas Desktop Client");

    VDCUpdate *mVentas = new VDCUpdate();
    mVentas->start();

    return app.exec();
}

VDCUpdate::VDCUpdate() : QWidget()
{
    QVBoxLayout *vLayout = new QVBoxLayout();
    QLabel *iconLabel = new QLabel();
    QPixmap pix(QString(":pics/VENTAS_10_splashscreen.png"));


    iconLabel->setPixmap(pix);
    mLabel = new QLabel(this);
    mProgress = new QProgressBar(this);
    mReply = NULL;
    cButton = new QPushButton(tr("&Cancel"), this);
    cButton->setIcon(QIcon(QString(":pics/escape.png")));
    cButton->setIconSize(QSize(40,25));
    cButton->setShortcut(Qt::Key_Escape);
    cButton->setStyleSheet("QPushButton { border-image: url(:pics/VENTAS_9_knopf_menu_inaktiv.png); padding-top: -1; padding-right: 10; text-align: left; height: 36px; min-width: 50px; }");

    connect(cButton, SIGNAL(clicked()), this, SLOT(abort()));

    vLayout->addWidget(iconLabel);
    vLayout->addWidget(mLabel, Qt::AlignLeft);
    vLayout->addWidget(getProgressBar(), Qt::AlignRight);
    vLayout->addWidget(cButton, 0, Qt::AlignRight);

    mLabel->setText(tr("Connecting to Download Server..."));

    getProgressBar()->setValue(0);
    getProgressBar()->setStyleSheet("QProgressBar { font-weight: bold; text-align: center; } ");

    this->setLayout(vLayout);
    logMessage(QString("[DEBUG] ###START: Initialisiere Patchlauf - %1").arg(QDate::currentDate().toString()));

}
void VDCUpdate::start()
{
        this->show();
        this->adjustSize();
        this->loadServerXml();
}

void VDCUpdate::loadServerXml()
{
    logMessage("[DEBUG] Hole vdcupdate.xml vom Server");
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    manager->get(QNetworkRequest(QUrl("http://www.ventas.de/wp-content/uploads/downloads/autoupdate/vdcupdate.xml")));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loadServerXmlFinished(QNetworkReply*)));
    connect(manager, SIGNAL(finished(QNetworkReply*)), manager, SLOT(deleteLater()));


}

void VDCUpdate::loadServerXmlFinished(QNetworkReply *nReply)
{
    if(nReply->error())
    {
        logMessage("[DEBUG] XML konnte nicht vom Server geholt werden");
        getProgressBar()->setValue(100);
        mLabel->setText(tr("Could not connect to the Update Server. Please check your Network connection."));
        mLabel->setStyleSheet("QLabel { color: red; font-weight: bold; }");

        return;
    } else {
        logMessage("[DEBUG] Datei erfolgreich geholt.");
        mLabel->setText(tr("Xml file successfully loaded."));
        QFile file(QDir::tempPath() + "/vdc.xml");
        file.open(QIODevice::WriteOnly);
        file.write(nReply->readAll());
        file.close();

        beginReadXml();
    }
}

void VDCUpdate::beginReadXml()
{
    QList<QList<QString> > serverVars = readServerXml(QDir::tempPath() + "/vdc.xml");
    #ifdef Q_OS_MAC
        QList<QString> clientVars = readClientXml(QApplication::applicationDirPath() + "/versions.xml");
    #else
        QList<QString> clientVars = readClientXml(QApplication::applicationDirPath() + "/versions.xml");
    #endif
    QString A4glFromClient = VDC::readSettingsFromIni("", "a4gl_version");
    QString XmlVersionServer = VDC::readSettingsFromIni("", "xml_version");

    logMessage("[DEBUG] Lese XML vom Client und vom Server ein.");

    if(clientVars.count() > 0 && !clientVars.isEmpty())
    {
        if(serverVars.count() > 0)
        {
            for(int i=0; i < serverVars.count(); i++)
            {
                int j=0;
                if(serverVars.at(i).count() > 0)
                {
                    if(clientVars.count() < j)
                    {
                        return;
                    }
                    QDate serverdate = QDate::fromString(serverVars.at(i).at(j), "dd.MM.yyyy");
                    QDate clientdate = QDate::fromString(clientVars.at(j), "dd.MM.yyyy");
                    if(serverdate >= clientdate)
                    {
                        j++;
                        if(serverVars.at(i).at(j) != clientVars.at(j))
                        {
                            j++;
                            if(serverVars.at(i).at(j) <= A4glFromClient)
                            {
                                j++;
                                if(serverVars.at(i).at(j) == XmlVersionServer)
                                {
                                    logMessage("[DEBUG] Lade Paket herunter.");
                                    mLabel->setText(tr("Attempt to download the Package..."));
                                    loadBinarie();
                                    return;
                                } else {
                                    mLabel->setText(tr("No new Version for this XML Version."));
                                    getProgressBar()->setValue(100);
                                    return;
                                }
                            } else {
                                mLabel->setText(tr("No new Update found for this A4GL Version."));
                                getProgressBar()->setValue(100);
                            }
                        } else {
                            logMessage("[DEBUG] Der Client ist aktuell.");
                            mLabel->setText(tr("The Client is up to date."));
                            getProgressBar()->setValue(100);
                            return;
                        }
                    } else {
                        logMessage("[DEBUG] Der Client ist aktuell.");
                        mLabel->setText(tr("The Client is up to date."));
                        getProgressBar()->setValue(100);
                        return;
                    }
                } else {
                    mLabel->setText(tr("No Serverinformations found. Update failed"));
                    mLabel->setStyleSheet("QLabel { color: red; font-weight: bold; }");
                    getProgressBar()->setValue(100);
                    return;
                }
            }

        }

    } else {
        QString filePath;
        #ifdef Q_OS_MAC
            filePath = QString(QApplication::applicationDirPath() + "/versions.xml");
        #else
            filePath = QString((QApplication::applicationDirPath() + "/versions.xml"));
        #endif
        mLabel->setText(QString("Cannot open File: %1").arg(filePath));
        mLabel->setStyleSheet("QLabel { color: red; font-weight: bold; }");
        getProgressBar()->setValue(100);
        return;
    }
}

void VDCUpdate::loadBinarie()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager;
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loadBinarieFinished(QNetworkReply*)));

    QNetworkRequest request;
    request.setUrl(QUrl(QString("http://www.ventas.de/wp-content/uploads/downloads/autoupdate/binaries/%1").arg(findPackage())));

    QNetworkReply *reply;

    reply = manager->get(request);

    connect(reply, SIGNAL(downloadProgress(qint64,qint64)), SLOT(updateDownloadProgress(qint64,qint64)));


    QString applicationPath = QApplication::applicationDirPath();


    QDir applicationDir(applicationPath);
    QFileInfoList applicationpDirFileInfoList = applicationDir.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);

    QDir backupDir(applicationPath + "/backup");
    if(!backupDir.exists())
    {
        if(!backupDir.mkpath(applicationPath + "/backup"))
        {
            qDebug() << "Cannot create backup directory.";
        }
    }

    foreach(QFileInfo applicationDirFileInfo, applicationpDirFileInfoList)
    {
        QString destFilePath = applicationPath + "/backup/" + applicationDirFileInfo.fileName();
        if(applicationDirFileInfo.isDir())
        {
            QDir dir(destFilePath);
            if(!dir.exists())
            {
                if(!dir.mkpath(destFilePath))
                {
                    qDebug() << "MISSERFOLG!";
                }
            }

            QDir subDir(applicationDirFileInfo.absoluteFilePath());
            QFileInfoList subDirInfoList = subDir.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);

            foreach (QFileInfo subDirFileInfo, subDirInfoList)
            {
                QString tmpSubFile = subDirFileInfo.absoluteFilePath();
                QString destFile = applicationPath + "/backup/" + "/" + subDir.dirName() + "/" + subDirFileInfo.fileName();

                logMessage(QString("[DEBUG] Destination: %1 ").arg(destFile));

                if(QFile::exists(destFile))
                {
                    QFile rmFile(destFile);
                    if(!rmFile.remove())
                    {
                        logMessage(QString("[ERROR] Fehler beim loeschen der Datei : %1").arg(destFile));
                    }
                }
                if(!QFile::copy(tmpSubFile, destFile))
                {
                    logMessage(QString("[ERROR] Kopieren fehlgeschlagen: %1").arg(destFile));
                    qDebug() << "Kopieren fehlgeschlagen. ABBRUCH!";
                }
            }
        } else {
            logMessage(QString("[DEBUG] Destination123: %1 ").arg(destFilePath));

            if(QFile::exists(destFilePath))
            {
                QFile rmFile(destFilePath);
                if(!rmFile.remove())
                {
                    logMessage(QString("[ERROR] Fehler beim loeschen der Datei : %1").arg(destFilePath));
                }
            }
            if(!QFile::copy(applicationDirFileInfo.absoluteFilePath(), destFilePath))
            {
                logMessage(QString("[ERROR] Kopieren fehlgeschlagen: %1").arg(destFilePath));
            }
       }
    }
}

QList<QString> VDCUpdate::readClientXml(QString filePath)
{
    QFile file;
    QList<QString> clientList;

    file.setFileName(filePath);
    QString clientOs;

    if(!file.open(QIODevice::ReadOnly))
    {
        return clientList;
    }

    #ifdef Q_OS_WIN
        clientOs = "WINDOWS";
    #endif
    #ifdef Q_OS_MAC
        clientOs = "MAC";
    #endif
    #ifdef Q_OS_LINUX
        clientOs = "LINUX";
    #endif

        QDomDocument doc;
        doc.setContent(&file);

        QDomElement root = doc.documentElement();
        QDomNode node = root.firstChildElement();
        while(!node.isNull() && node.isElement())
        {
            QDomElement secElement = node.toElement();
            if(!secElement.isNull())
            {
                if(secElement.nodeName() == clientOs)
                {
                    QDomNode child = secElement.firstChild();
                    while(!child.isNull())
                    {
                        QDomElement text = child.toElement();
                        clientList << text.text();
                        child = child.nextSibling();
                    }
                }

            }
            node = node.nextSiblingElement();
        }
        return clientList;

}

QList<QList<QString> > VDCUpdate::readServerXml(QString filePath)
{
    QFile file;
    QList<QString> textList;
    QList<QList<QString> > returnList;

    file.setFileName(filePath);
    QString clientOs;

    if(!file.open(QIODevice::ReadOnly))
    {
        logMessage(QString("[DEBUG] XML Datei konnte nicht geoeffnet werden: %1").arg(filePath));
        mLabel->setText(QString("Failed to Open: %1").arg(filePath));
        getProgressBar()->setValue(100);

        return returnList;
    }

    #ifdef Q_OS_WIN
        clientOs = "WINDOWS";
    #endif
    #ifdef Q_OS_MAC
        clientOs = "MAC";
    #endif
    #ifdef Q_OS_LINUX
        clientOs = "LINUX";
    #endif

    QDomDocument doc;
    doc.setContent(&file);

    QDomElement root = doc.documentElement();
    QDomNode node = root.firstChildElement();
    while(!node.isNull() && node.isElement())
    {
        QDomElement secElement = node.toElement();
        if(!secElement.isNull())
        {
            if(secElement.nodeName() == clientOs)
            {
                QDomNode child = secElement.firstChild();
                while(!child.isNull())
                {
                    QDomElement text = child.toElement();
                    textList << text.text();
                    child = child.nextSibling();
                }
                returnList.insert(returnList.count(), textList);
                textList.clear();
            }

        }
        node = node.nextSiblingElement();
    }
    file.close();
    return returnList;
}

void VDCUpdate::requestFileFromServer()
{
    QString fileName = findPackage();
    mLabel->setText(tr("Request Package from Server"));

    QNetworkRequest nRequest;
    nRequest.setUrl(QUrl(QString("http://www.ventas.de/wp-content/uploads/downloads/autoupdate/binaries/%1").arg(fileName)));

    QNetworkAccessManager *manager = new QNetworkAccessManager;
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loadBinarieFinished(QNetworkReply*)));

    QNetworkReply *reply = manager->get(nRequest);
    mReply = reply;

    connect(reply, SIGNAL(downloadProgress(qint64,qint64)), SLOT(updateDownloadProgress(qint64,qint64)));
}
void VDCUpdate::loadBinarieFinished(QNetworkReply *reply)
{
    QFile *file = new QFile(QDir::tempPath() + "/" + findPackage());
    if(!file->open(QIODevice::WriteOnly))
    {
        mLabel->setText(tr("Cannot write file to disk."));
        getProgressBar()->setValue(100);
    }

    switch(reply->error())
    {
       case QNetworkReply::NoError:
          break;
       default:
        logMessage(QString("[DEBUG] Datei auf Webserver nicht gefunden: %1 Error Code: %2").arg(findPackage()).arg(reply->error()));
          mLabel->setText(tr("Cannot load File from Server: %1. Error code: %2 ").arg(findPackage()).arg(reply->error()));
          getProgressBar()->setValue(100);
          break;
    }

    if(reply->error() == 0)
    {
        file->write(reply->readAll());
        file->close();

        logMessage("[DEBUG] Dateien werden Entpackt.");
        mLabel->setText(tr("Unzip files. This can take a while."));
        getProgressBar()->setValue(1);

        ZipUnzip *p_zipunzip = new ZipUnzip();

        if(p_zipunzip->unzipBinarieArchiv(QDir::tempPath(), findPackage(), QString(QDir::tempPath() + "/VDC")))
        {
            cButton->setText("&Close");
            logMessage("[DEBUG] Entpacken war erfolgreich.");
            mLabel->setText(tr("Copy files to workdirectory."));
            getProgressBar()->setValue(50);
            QTimer *timer = new QTimer;
            connect(timer, SIGNAL(timeout()), this, SLOT(setUpdateComplete()));
            timer->setSingleShot(true);
            timer->start(2000);

            QProcess *proc = new QProcess;
            QString prog;
            QStringList args;

            args << QString(QDir::tempPath() + "/VDC") << QString(QApplication::applicationDirPath());
            #ifdef Q_OS_WIN
                prog = QString(QApplication::applicationDirPath() + "/updatecp.exe");
            #else
                prog = QString(QApplication::applicationDirPath() + "/updatecp");
            #endif

            logMessage(QString("[DEBUG] oeffne: %1").arg(prog));
            logMessage(QString("[DEBUG] Application Dir: %1").arg(QApplication::applicationDirPath()));

            proc->start(prog, args);
            QFile file(prog);

            if(file.exists())
            {
                if(proc->waitForStarted(6000))
                {
                } else {
                    mLabel->setText(QString("Datei konnte nicht ausgefuehrt: %1").arg(prog));
                }
            } else {
                mLabel->setText(QString("Datei konnte nicht gefunden werden: <b>%1</b>").arg(prog));
            }
        } else {
            logMessage("[DEBUG] Entpacken ist fehlgeschlagen.");
            mLabel->setText(tr("Unzip failed."));
            mLabel->setStyleSheet("QLabel { color: red; font-weight: bold; }");
            getProgressBar()->setValue(100);
        }

    }
}

void VDCUpdate::setUpdateComplete()
{
    mLabel->setText(tr("Update successfull. Wait until the VDC has been started."));
    getProgressBar()->setValue(100);
}

void VDCUpdate::updateDownloadProgress(qint64 received, qint64 total)
{
    getProgressBar()->setValue((double) received * 100 / total);
}
QString VDCUpdate::findPackage()
{
    QString packageName;

    #ifdef Q_OS_MAC
        packageName = QString("VDCUpdateMac.zip");
    #endif
    #ifdef Q_OS_LINUX
        packageName = QString("VDCUpdateLin.zip");
    #endif
    #ifdef Q_OS_WIN
        packageName = QString("VDCUpdateWin.zip");
    #endif

    return packageName;
}
void VDCUpdate::logMessage(QString msg)
{
    QDir dir(QApplication::applicationDirPath() + "/logs");

    if(!dir.exists())
    {
        dir.mkdir(QApplication::applicationDirPath() + "/logs");
    }

    QFile file(QApplication::applicationDirPath() + "/logs/patchlog.log");

    if(file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream out(&file);
        msg = msg + "\r\n";
        out << msg;
        file.close();

    }

}

void VDCUpdate::abort()
{
    if(mReply)
    {
        mReply->close();
    }
    exit(0);
}

VDCUpdate::~VDCUpdate()
{
    delete mBox;
    delete mLabel;
    delete mProgress;
    delete mReply;
    delete mPushbutton;
    delete cButton;
}
