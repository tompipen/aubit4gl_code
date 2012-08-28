#include "ventasupdate.h"
#include <QUrl>
#include "clienttcp.h"
#include "mainframe.h"

VentasUpdate::VentasUpdate(int errorDisplay, QWidget *parent) : QWidget()
{

    QFile *XMLfile = new QFile(QDir::tempPath() + "/vdc.xml");
    QFile *VDCsetup;

    #ifdef Q_WS_WIN32
        VDCsetup = new QFile(QDir::tempPath() + "/VDCsetup.exe");
    #endif
    #ifdef Q_WS_X11
        VDCsetup = new QFile(QDir::tempPath() + "/VDCsetup.deb");
    #endif
    #ifdef Q_WS_MAC
        VDCsetup = new QFile(QDir::tempPath() + "/VDCsetup.dmg");
    #endif


    if(XMLfile->exists())
    {
        XMLfile->close();
        XMLfile->remove();
    }

    if(VDCsetup->exists())
    {
        VDCsetup->close();
        VDCsetup->remove();
    }


    displayErrorDialog = errorDisplay;
    m_box = new QMessageBox(this);
    this->setWindowTitle("VENTAS UPDATE");

}
VentasUpdate::~VentasUpdate()
{
    delete m_box;
    delete m_screenhandler;
    delete m_label;
    delete m_progress;
    delete m_dialog;
    delete downloadDialog;
    delete m_reply;
}

void VentasUpdate::checkForNewUpdates()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    manager->get(QNetworkRequest(QUrl("http://www.ventas.de/wp-content/uploads/downloads/autoupdate/vdcupdate.xml")));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(readXmlFinished(QNetworkReply*)));
    connect(manager, SIGNAL(finished(QNetworkReply*)), manager, SLOT(deleteLater()));

}

void VentasUpdate::loadFileFromServer()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager;
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(updateReady(QNetworkReply*)));

    #ifdef Q_WS_MAC
        m_fileName = QString("VDCsetup.dmg");
    #endif
    #ifdef Q_WS_X11
        m_fileName = QString("VDCsetup.deb");
    #endif
    #ifdef Q_WS_WIN
        m_fileName = QString("VDCsetup.exe");
    #endif

    QNetworkRequest request;
    request.setUrl(QUrl(QString("http://www.ventas.de/wp-content/uploads/downloads/autoupdate/binaries/%1").arg(m_fileName)));

    QNetworkReply *m_reply;

    m_reply = manager->get(request);

    connect(m_reply, SIGNAL(downloadProgress(qint64,qint64)), SLOT(updateDownloadProgress(qint64,qint64)));

    //Open GUI to display the progress of the downloaded file
    QVBoxLayout *layout = new QVBoxLayout(this);
    m_label = new QLabel(this);
    m_progress = new QProgressBar(this);

    layout->addWidget(m_label, Qt::AlignBottom);
    layout->addWidget(m_progress, Qt::AlignBottom);

    m_label->setText(tr("Connecting to Download Server..."));

    this->setLayout(layout);
    this->resize(200,100);
    this->show();
}
void VentasUpdate::updateDownloadProgress(qint64 received,qint64 total)
{
    m_label->setText("Downloading VDC...");
    m_progress->setValue((double) received * 100 / total);
}
QList<QString> VentasUpdate::clientXml(QString filePath)
{
    QFile file;
    QList<QString> clientList;

    file.setFileName(filePath);
    QString clientOs;

    if(!file.open(QIODevice::ReadOnly))
    {
        if(displayErrorDialog == 1)
        {
            //Dialog *dialog = new Dialog("VENTAS Update", QString("Failed to Open: %1").arg(filePath), "", "stop", this, Qt::WindowStaysOnTopHint);
            //dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
            //connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
            //dialog->move(600,400);
            //dialog->show();
            //connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));
            return clientList;
        }
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
QList<QList<QString> > VentasUpdate::parseXml(QString filePath)
{
    QFile file;
    QList<QString> textList;
    QList<QList<QString> > returnList;

    file.setFileName(filePath);
    QString clientOs;

    if(!file.open(QIODevice::ReadOnly))
    {
        if(displayErrorDialog == 1)
        {
            Dialog *dialog = new Dialog("VENTAS Update", QString("Failed to Open: %1").arg(filePath), "", "stop", this, Qt::WindowStaysOnTopHint);
            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
            connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
            dialog->move(600,400);
            dialog->show();
            connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));
            return returnList;
        }
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

        //Formatiertes Datumsformat
        //qDebug() << QDate::currentDate().toString("dd.MM.yyyy");
    }
    file.close();
    return returnList;
}

void VentasUpdate::readXmlFinished(QNetworkReply *reply)
{
    if(reply->error())
    {
        if(displayErrorDialog == 1)
        {
            Dialog *dialog = new Dialog("VENTAS Update", "Could not connect to the Update Server.\n Please check your Network connection", "", "stop", this, Qt::WindowStaysOnTopHint);
            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
            connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
            dialog->move(600,400);
            dialog->show();
            connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));
            return;
        }
    } else {
        QFile file(QDir::tempPath() + "/vdc.xml");
        file.open(QIODevice::WriteOnly);
        file.write(reply->readAll());
        file.close();
    }
        checkServerClient();


}
void VentasUpdate::checkServerClient()
{
    QList<QList<QString> > serverVars = parseXml(QDir::tempPath() + "/vdc.xml");
    #ifdef Q_WS_MAC
        QList<QString> clientVars = clientXml(QDir::currentPath() + "/VDC.app/Contents/MacOS/versions.xml");
    #else
        QList<QString> clientVars = clientXml(QApplication::applicationDirPath() + "/versions.xml");
    #endif
    QString A4glFromClient = VDC::readSettingsFromIni("", "a4gl_version");
    QString XmlVersionServer = VDC::readSettingsFromIni("", "xml_version");



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
                                    qDebug() << "debug4 ";
                                    Dialog *dialog = new Dialog("VENTAS Update", "There is a new VDC version available.\n Do you want to download and install it?", "", "information", this, Qt::WindowStaysOnTopHint);
                                    dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                                    dialog->createButton(2, "Abort", "Abort", "abbrechen_rot.png");
                                    connect(dialog->getAction("OK"), SIGNAL(triggered()), this, SLOT(checkOpenConnections()));
                                    connect(dialog->getAction("ABORT"), SIGNAL(triggered()), dialog, SLOT(close()));
                                    dialog->move(600,400);
                                    dialog->show();
                                    m_dialog = dialog;
                                    //m_dateToDownload  = serverVars.at(0).at(0);
                                    return;
                                } else {
                                    if(displayErrorDialog == 1)
                                    {
                                        Dialog *dialog = new Dialog("VENTAS Update", "No new Version for this XML Version!", "", "information", this, Qt::WindowStaysOnTopHint);
                                        dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                                        connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
                                        dialog->move(600,400);
                                        dialog->show();
                                        connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));
                                        return;
                                    }
                                }
                            } else {
                                if(displayErrorDialog == 1)
                                {
                                    Dialog *dialog = new Dialog("VENTAS Update", "No new Update found for this A4GL Version.", "", "information", this, Qt::WindowStaysOnTopHint);
                                    dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                                    connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
                                    dialog->move(600,400);
                                    dialog->show();
                                    connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));
                                }
                            }
                        } else {
                            if(displayErrorDialog == 1)
                            {
                                Dialog *dialog = new Dialog("VENTAS Update", "The Client is up to date!", "", "information", this, Qt::WindowStaysOnTopHint);
                                dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                                connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
                                dialog->move(600,400);
                                dialog->show();
                                connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));
                                return;
                            }
                        }
                    } else {
                        if(displayErrorDialog == 1)
                        {
                            Dialog *dialog = new Dialog("VENTAS Update", "The Client is up to date!", "", "information", this, Qt::WindowStaysOnTopHint);
                            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                            connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
                            dialog->move(600,400);
                            dialog->show();
                            connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));
                            return;
                        }
                    }
                } else {
                    Dialog *dialog = new Dialog("VENTAS Update", "Cannot find Serverinformations.", "", "information", this, Qt::WindowStaysOnTopHint);
                    dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                    connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
                    dialog->show();
                }
            }

        }

    } else {
        if(displayErrorDialog == 1)
        {

            QString filePath;
            #ifdef Q_WS_MAC
                filePath = QString(QDir::currentPath() + "/VDC.app/Contents/MacOS/versions.xml");
            #else
                filePath = QString(QApplication::applicationDirPath() + "/versions.xml");
            #endif
            Dialog *dialog = new Dialog("VENTAS Update", QString("Cannot open File: %1").arg(filePath), "", "information", this, Qt::WindowStaysOnTopHint);
            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
            connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
            dialog->move(600,400);
            dialog->show();
            connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));
            return;
        }
    }
}

void VentasUpdate::updateReady(QNetworkReply *reply)
{

    #ifdef Q_WS_MAC
       QFile *file = new QFile(QDir::tempPath() + "/vdc-update.dmg");
    #endif
    #ifdef Q_WS_X11
       QFile *file = new QFile(QDir::tempPath() + "/vdc-update.deb");
    #endif
    #ifdef Q_WS_WIN32
       QFile *file = new QFile(QDir::tempPath() + "/VDCsetup.exe");
    #endif
    if(!file->open(QIODevice::WriteOnly))
    {
        qDebug() << "Cannot write file.";
    }

    switch(reply->error())
    {
       case QNetworkReply::NoError:
          break;
       default:
          m_label->setText(QString("Cannot load File from Server: %1.\n Error code: %2 ").arg(m_fileName).arg(reply->error()));
          break;
    }

    if(reply->error() == 0)
    {
        file->write(reply->readAll());
        file->close();

        m_label->setText("Download beendet!");
        m_progress->setValue(100);
        #ifdef Q_WS_MAC
           QDesktopServices::openUrl(QUrl(QString("file:///" + QDir::tempPath() + "/vdc-update.dmg"), QUrl::TolerantMode));
        #endif
        #ifdef Q_WS_X11
            QDesktopServices::openUrl(QUrl(QString("file:///%1").arg(QDir::tempPath() + "/VDCsetup.deb"), QUrl::TolerantMode));
        #endif
        #ifdef Q_WS_WIN32
           QDesktopServices::openUrl(QUrl(QString("file:///%1").arg(QDir::tempPath() + "/VDCsetup.exe"), QUrl::TolerantMode));
        #endif
        QApplication::quit();

    }
}

void VentasUpdate::checkOpenConnections()
{
    QList<ScreenHandler*> *ql_screenhandler = MainFrame::ql_screenhandler;
    if(ql_screenhandler->count() > 0)
    {
        Dialog *dialog = new Dialog("VENTAS Update", "There are modules running.\n They will be terminated. \n Do you really want to continue?", "", "stop", this, Qt::WindowStaysOnTopHint);
        downloadDialog = dialog;
        dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
        dialog->createButton(2, "Abort", "Abort", "abbrechen_rot.png");
        connect(dialog->getAction("OK"), SIGNAL(triggered()), this, SLOT(responseDownload()));
        connect(dialog->getAction("ABORT"), SIGNAL(triggered()), this, SLOT(abortDownload()));
        dialog->move(600,400);
        dialog->show();
        connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));
    } else {
        emit responseDownload();
    }

    if(m_dialog != NULL)
    {
        m_dialog->close(); 
    }
}
void VentasUpdate::responseDownload()
{
    QList<ScreenHandler*> *ql_screenhandler = MainFrame::ql_screenhandler;
    for(int i=0; i < ql_screenhandler->count(); i++)
    {
        if(ScreenHandler *screen = qobject_cast<ScreenHandler*> (ql_screenhandler->at(i)))
        {
                screen->closeProgramm();
        }
    }

    if(downloadDialog)
    {
        downloadDialog->close();
    }
    loadFileFromServer();
}

void VentasUpdate::abortDownload()
{
    if(downloadDialog)
    {
        downloadDialog->close();
    }
}
