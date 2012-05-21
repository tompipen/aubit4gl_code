#include "ventasupdate.h"
#include <QUrl>
#include "clienttcp.h"

VentasUpdate::VentasUpdate(int errorDisplay, QObject *screen, QWidget *parent)
{
    Q_UNUSED(parent);
    displayErrorDialog = errorDisplay;
    m_box = new QMessageBox(this);
    //m_mainFrame = mFrame;
    m_screenhandler = screen;

    /*QWidget *d = QApplication::desktop();
    int w = d->width();
    int h = d->height();*/
    mw = 600;
    mh = 400;

    this->setWindowTitle("VENTAS UPDATE");
}

void VentasUpdate::checkForNewUpdates()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    manager->get(QNetworkRequest(QUrl("http://www.ventas.de/wp-content/uploads/downloads/autoupdate/vdc.xml")));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(readXmlFinished(QNetworkReply*)));

}

void VentasUpdate::loadFileFromServer()
{
    QDate date;
    QNetworkAccessManager *manager = new QNetworkAccessManager;
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(updateReady(QNetworkReply*)));
    if(!m_dateToDownload.isEmpty())
    {
        date = QDate::fromString(m_dateToDownload, "dd.MM.yyyy");
    } else {
        return;
    }

    #ifdef Q_WS_MAC
        m_fileName = QString("WEB-Mac-vdc_" + date.toString("ddMMyyyy") + ".pkg");
    #endif
    #ifdef Q_WS_X11
        m_fileName = QString("WEB-Unix-vdc_" + date.toString("ddMMyyyy") + ".zip");
    #endif
    #ifdef Q_WS_WIN
        m_fileName = QString("WEB-Win-vdc_" + date.toString("ddMMyyyy") + ".zip");
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
            dialog->move(mw,mh);
            dialog->show();
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
    if(reply->error() == 0)
    {
        QFile file(QDir::tempPath() + "/vdc.xml");
        file.open(QIODevice::WriteOnly);
        file.write(reply->readAll());
        file.close();
    } else {
        if(displayErrorDialog == 1)
        {
            Dialog *dialog = new Dialog("VENTAS Update", "Could not connect to the Update Server.\n Please check your Network connection", "", "stop", this, Qt::WindowStaysOnTopHint);
            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
            connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
            dialog->move(mw,mh);
            dialog->show();
        }
    }
        checkServerClient();


}
void VentasUpdate::checkServerClient()
{
    QList<QList<QString> > serverVars = parseXml(QDir::tempPath() + "/vdc.xml");
    QList<QList<QString> > clientVars = parseXml(QDir::currentPath() + "/versions.xml");

    if(clientVars.isEmpty())
    {
        Dialog *dialog = new Dialog("VENTAS Update", QString("Cannot open File: %1").arg(QDir::currentPath() + "/versions.xml"), "", "information", this, Qt::WindowStaysOnTopHint);
        dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
        connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
        dialog->move(mw,mh);
        dialog->show();
        return;
    }
    if(serverVars.at(0).isEmpty())
    {
        Dialog *dialog = new Dialog("VENTAS Update", "No Updates found!", "", "information", this, Qt::WindowStaysOnTopHint);
        dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
        connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
        dialog->move(mw,mh);
        dialog->show();
        return;
    }

    for(int i=(serverVars.count()-1); i >=0; i--)
    {
        QString A4glFromClient = VDC::readSettingsFromIni("", "a4gl_version");
        QString XmlVersionServer = VDC::readSettingsFromIni("", "xml_version");

        if(serverVars.at(i).count() >= 3)
        {
            if(serverVars.at(i).at(2) == A4glFromClient)
            {
                if(serverVars.at(i).at(3) == XmlVersionServer)
                {
                    if(serverVars.at(0).at(0) != clientVars.at(0).at(0))
                    {
                        if(serverVars.at(0).at(1) != clientVars.at(0).at(1))
                        {
                            Dialog *dialog = new Dialog("VENTAS Update", "There is a new VDC version available.\n Do you want to download and install it?", "", "information", this, Qt::WindowStaysOnTopHint);
                            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                            dialog->createButton(2, "Abort", "Abort", "abbrechen_rot.png");
                            connect(dialog->getAction("OK"), SIGNAL(triggered()), this, SLOT(checkOpenConnections()));
                            connect(dialog->getAction("ABORT"), SIGNAL(triggered()), dialog, SLOT(close()));
                            dialog->move(mw,mh);
                            dialog->show();
                            m_dialog = dialog;
                            m_dateToDownload  = serverVars.at(0).at(0);
                        } else {
                            if(displayErrorDialog == 1)
                            {
                                Dialog *dialog = new Dialog("VENTAS Update", "The Client is up to date!", "", "information", this, Qt::WindowStaysOnTopHint);
                                dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                                connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
                                dialog->move(mw,mh);
                                dialog->show();
                            }
                        }
                        break;
                    }

                } else {
                    if(displayErrorDialog == 1)
                    {
                        Dialog *dialog = new Dialog("VENTAS Update", "No XML Version found!", "", "information", this, Qt::WindowStaysOnTopHint);
                        dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                        connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
                        dialog->move(mw,mh);
                        dialog->show();
                    }
                }
            } else {
                if(displayErrorDialog == 1)
                {
                    Dialog *dialog = new Dialog("VENTAS Update", "No A4GL informations found!", "", "information", this, Qt::WindowStaysOnTopHint);
                    dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                    connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
                    dialog->move(mw,mh);
                    dialog->show();
                }
            }
        }
    }
}

void VentasUpdate::updateReady(QNetworkReply *reply)
{

    #ifdef Q_WS_MAC
       QFile *file = new QFile(QDir::tempPath() + "/vdc-update.pkg");
    #else
       QFile *file = new QFile(QDir::tempPath() + "/vdc-update.zip");
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
           QDesktopServices::openUrl(QUrl(QString("file:///" + QDir::tempPath() + "/vdc-update.pkg"), QUrl::TolerantMode));
        #else
           QDesktopServices::openUrl(QUrl(QString("file:///%1").arg(QDir::tempPath() + "/vdc-update.zip"), QUrl::TolerantMode));
        #endif
        QApplication::quit();

    }
}

void VentasUpdate::checkOpenConnections()
{
    if(this->m_screenhandler != NULL && this->m_screenhandler->parent() != NULL && this->m_screenhandler->parent()->parent() != NULL)
    {
        if(ClientTcp *cTcp = qobject_cast<ClientTcp *> (this->m_screenhandler->parent()->parent()))
        {
            if(cTcp->socket != NULL)
            {
                Dialog *dialog = new Dialog("VENTAS Update", "There are modules running.\n They will be terminated. \n Do you really want to continue?", "", "stop", this, Qt::WindowStaysOnTopHint);
                downloadDialog = dialog;
                dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                dialog->createButton(2, "Abort", "Abort", "abbrechen_rot.png");
                connect(dialog->getAction("OK"), SIGNAL(triggered()), this, SLOT(responseDownload()));
                connect(dialog->getAction("ABORT"), SIGNAL(triggered()), dialog, SLOT(abortDownload()));
                dialog->move(mw,mh);
                dialog->show();
            }
        }
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
    loadFileFromServer();
}

void VentasUpdate::abortDownload()
{
    m_reply->abort();
    if(downloadDialog)
    {
        downloadDialog->close();
    }
}
