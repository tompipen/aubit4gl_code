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
    logMessage(QString("[DEBUG] ###START: Initialisiere Patchlauf - %1").arg(QDate::currentDate().toString()));
    QVBoxLayout *vLayout = new QVBoxLayout();
    QHBoxLayout *hLayout = new QHBoxLayout();

    mLabel = new QLabel(this);
    mProgress = new QProgressBar(this);
    mTextEdit = new QTextEdit(this);
    mReply = NULL;
    cButton = new QPushButton(tr("&Abort"), this);
    connect(cButton, SIGNAL(clicked()), this, SLOT(abort()));
    //QPushButton *showLogButton = new QPushButton(tr("Show Log"), this);
    //showLogButton->setEnabled(false);


    hLayout->addWidget(getProgressBar(), Qt::AlignRight);
    vLayout->addLayout(hLayout);
    vLayout->addWidget(getLabel(), Qt::AlignBottom);
    vLayout->addWidget(getTextEdit());
    vLayout->addWidget(cButton, 0, Qt::AlignRight);
    //vLayout->addWidget(showLogButton, 0, Qt::AlignRight);
    getTextEdit()->append(tr("Connecting to Download Server..."));
    getProgressBar()->setFixedWidth(200);
    getProgressBar()->setValue(1);

    getTextEdit()->setReadOnly(true);
    getTextEdit()->append("Starting Patch progress");

    this->setLayout(vLayout);

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
       getTextEdit()->append(tr("Could not connect to the Update Server.\n Please check your Network connection."));
        return;
    } else {
        logMessage("[DEBUG] Datei erfolgreich geholt.");
        getTextEdit()->append(tr("Xml file successfully loaded."));
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
    #ifdef Q_WS_MAC
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
                    if(serverdate > clientdate)
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
                                    // TODO: HIER WEITERMACHEN BINARIE HERUNTERLADEN
                                    logMessage("[DEBUG] Lade Paket herunter.");
                                    getTextEdit()->append(tr("Attempt to download the Package..."));
                                    loadBinarie();
                                    return;
                                } else {
                                    getTextEdit()->append(tr("No new Version for this XML Version."));
                                    getProgressBar()->setValue(100);
                                    return;
                                }
                            } else {
                                getTextEdit()->append(tr("No new Update found for this A4GL Version."));
                                getProgressBar()->setValue(100);
                            }
                        } else {
                            logMessage("[DEBUG] Der Client ist aktuell.");
                            getTextEdit()->append(tr("The Client is up to date."));
                            getProgressBar()->setValue(100);
                            return;
                        }
                    } else {
                        logMessage("[DEBUG] Der Client ist aktuell.");
                        getTextEdit()->append(tr("The Client is up to date."));
                        getProgressBar()->setValue(100);
                        return;
                    }
                } else {
                    getTextEdit()->append(tr("No Serverinformations found."));
                    getProgressBar()->setValue(100);
                    return;
                }
            }

        }

    } else {
        QString filePath;
        #ifdef Q_WS_MAC
            filePath = QString(QApplication::applicationDirPath() + "/versions.xml");
        #else
            filePath = QString((QApplication::applicationDirPath() + "/versions.xml"));
        #endif
        getTextEdit()->append(QString("Cannot open File: %1").arg(filePath));
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

    #ifdef Q_WS_WIN
        clientOs = "WINDOWS";
    #endif
    #ifdef Q_WS_MAC
        clientOs = "MAC";
    #endif
    #ifdef Q_WS_X11
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
        getTextEdit()->append(QString("Failed to Open: %1").arg(filePath));
        getProgressBar()->setValue(100);

        return returnList;
    }

    #ifdef Q_WS_WIN
        clientOs = "WINDOWS";
    #endif
    #ifdef Q_WS_MAC
        clientOs = "MAC";
    #endif
    #ifdef Q_WS_X11
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
    getTextEdit()->append(tr("Request Package from Server"));

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
        getTextEdit()->append(tr("Cannot write file to disk. Abort!"));
        getProgressBar()->setValue(100);
    }

    switch(reply->error())
    {
       case QNetworkReply::NoError:
          break;
       default:
        logMessage(QString("[DEBUG] Datei auf Webserver nicht gefunden: %1 Error Code: %2").arg(findPackage()).arg(reply->error()));
          getTextEdit()->append(QString("Cannot load File from Server: %1.\n Error code: %2 ").arg(findPackage()).arg(reply->error()));
          getProgressBar()->setValue(100);
          break;
    }

    if(reply->error() == 0)
    {
        file->write(reply->readAll());
        file->close();

        logMessage("[DEBUG] Dateien werden Entpackt.");
        getTextEdit()->append(tr("Extracting Files...\n This can take a while."));
        getProgressBar()->setValue(1);

        ZipUnzip *p_zipunzip = new ZipUnzip();

        if(p_zipunzip->unzipArchiv(QDir::tempPath(), findPackage(), QString(QDir::tempPath() + "/VDC")))
        {
            cButton->setText("&Close");
            logMessage("[DEBUG] Entpacken war erfolgreich.");
            getTextEdit()->append(tr("Extracting finished."));
            getTextEdit()->append(tr("Copy files to workdirectory."));
            getProgressBar()->setValue(90);
            QTimer *timer = new QTimer;
            connect(timer, SIGNAL(timeout()), this, SLOT(setUpdateComplete()));
            timer->setSingleShot(true);
            timer->start(2000);

            QProcess *proc = new QProcess;
            QString prog;
            QStringList args;

            args << QString(QDir::tempPath() + "/VDC") << QString(QApplication::applicationDirPath());
            #ifdef Q_WS_WIN
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
                    //QApplication::quit();
                } else {
                    getTextEdit()->append(QString("Datei konnte nicht ausgefuehrt: %1").arg(prog));
                }
            } else {
                getTextEdit()->append(QString("Datei konnte nicht gefunden werden: <b>%1</b>").arg(prog));
            }
            //CopyBinaries *cBinaries = new CopyBinaries;
            //cBinaries->start(QString(QDir::tempPath() + "/VDC"),   QString(QApplication::applicationDirPath()));

        } else {
            logMessage("[DEBUG] Entpacken ist fehlgeschlagen.");
            getTextEdit()->append(tr("Extracting failed."));
            getProgressBar()->setValue(100);
        }

    }
}

void VDCUpdate::setUpdateComplete()
{
    getTextEdit()->append(tr("Update successfull. Starting VDC binarie."));
    getProgressBar()->setValue(100);
}

void VDCUpdate::updateDownloadProgress(qint64 received, qint64 total)
{
    getProgressBar()->setValue((double) received * 100 / total);
}
QString VDCUpdate::findPackage()
{
    QString packageName;
    #ifdef Q_WS_MAC
        packageName = QString("VDCUpdateMac.zip");
    #endif
    #ifdef Q_WS_X11
        packageName = QString("VDCUpdateLin.zip");
    #endif
    #ifdef Q_WS_WIN
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
}
