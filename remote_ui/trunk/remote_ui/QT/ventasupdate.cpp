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

    this->setWindowTitle("VENTAS UPDATE");
}

void VentasUpdate::checkForNewUpdates()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    manager->get(QNetworkRequest(QUrl("http://www.ventas.de/wp-content/uploads/downloads/vdc.xml")));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(readXmlFinished(QNetworkReply*)));
}

void VentasUpdate::loadFileFromServer()
{
    QString fileName;
    QNetworkAccessManager *manager = new QNetworkAccessManager;
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(updateReady(QNetworkReply*)));

    #ifdef Q_WS_MAC
        fileName = "VDC.pkg";
    #endif
    #ifdef Q_WS_UNIX
        fileName = "VDC-unix.zip";
    #endif
    #ifdef Q_WS_WIN
        fileName = "VDC_windows.zip";
    #endif

    QNetworkRequest request;
    request.setUrl(QUrl(QString("http://www.ventas.de/wp-content/uploads/downloads/%1").arg(fileName)));

    QNetworkReply *reply;

    reply = manager->get(request);

    connect(reply, SIGNAL(downloadProgress(qint64,qint64)), SLOT(updateDownloadProgress(qint64,qint64)));


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

QList<QString> VentasUpdate::parseXml(QString filePath)
{
    QFile file;
    QList<QString> childText;
    file.setFileName(filePath);

    if(!file.open(QIODevice::ReadOnly))
    {
        m_box->setWindowTitle("VENTAS UPDATE");
        m_box->setText(QString("Failed to open File: %1").arg(filePath));
        m_box->show();
    }

    QDomDocument doc;
    doc.setContent(&file);

    QDomElement root = doc.documentElement();
    QDomNode node = root.firstChild();
    while(!node.isNull())
    {
        QDomElement child = node.toElement();
        if(!child.isNull())
        {
            childText << child.text();
        }
        node = node.nextSibling();

        //Formatiertes Datumsformat
        //qDebug() << QDate::currentDate().toString("dd.MM.yyyy");
    }
    return childText;
    file.close();
}

void VentasUpdate::readXmlFinished(QNetworkReply *reply)
{
    QList<QString> serverVars;
    QList<QString> clientVars = parseXml(QDir::currentPath() + "/versions.xml");
    //QList<QString> clientVars = checkVersion("/home/da/versions.xml");
    int closeWindow = 0;
    if(reply->error() == 0)
    {
        QFile file(QDir::tempPath() + "/vdc.xml");
        file.open(QIODevice::WriteOnly);
        file.write(reply->readAll());
        file.close();
        serverVars << parseXml(QDir::tempPath() + "/vdc.xml");
    } else {
        if(displayErrorDialog == 1)
        {
            m_box->setWindowTitle("VENTAS UPDATE");
            m_box->critical(0,
                          tr("VDC UPDATE"),
                          tr("Could not connect to the Update Server.\n Please check your Network connection."),
                          tr("&Ok"),
                          QString(), 0);
        }
    }

    if(!serverVars.isEmpty() && !clientVars.isEmpty())
    {
        if(!serverVars.at(0).isEmpty() && !clientVars.at(0).isEmpty())
        {
            if(serverVars.at(0) > clientVars.at(0))
            {
                if(!serverVars.at(1).isEmpty() && !clientVars.at(1).isEmpty())
                {
                    if(serverVars.at(1) != clientVars.at(1))
                    {
                        QString a4gl_client_version = VDC::readSettingsFromIni("", "a4gl_version");
                        if(!serverVars.at(2).isEmpty() && a4gl_client_version > 0)
                        {
                            if(serverVars.at(2) == a4gl_client_version)
                            {
                                int dialogAuswahl = 0;
                                m_box->setWindowTitle("VENTAS UPDATE");
                                dialogAuswahl = m_box->information(0,
                                              tr("VDC UPDATE"),
                                              tr("There is a new VDC version available.\n Do you want to download and install it?"),
                                              tr("&Yes"), tr("&No"),
                                              QString(), 0, 1);

                                if(dialogAuswahl == 0)
                                {
                                    if(this->m_screenhandler != NULL && this->m_screenhandler->parent() != NULL && this->m_screenhandler->parent()->parent() != NULL)
                                    {
                                         qDebug() << "bla123:" << this->m_screenhandler->parent()->parent();
                                        if(ClientTcp *cTcp = qobject_cast<ClientTcp *> (this->m_screenhandler->parent()->parent()))
                                        {
                                            if(cTcp->socket != NULL)
                                            {
                                                m_box->setWindowTitle("VENTAS UPDATE");
                                                closeWindow = m_box->question(0,
                                                              tr("VDC UPDATE"),
                                                              tr("There are modules running.\n They will be terminated. \n Do you really want to continue?"),
                                                              tr("&Yes"), tr("&No"),
                                                              QString(), 0, 1);
                                            }
                                        }
                                    }

                                    if(closeWindow == 0)
                                    {
                                        loadFileFromServer();

                                    }
                                }
                            }
                        } else {
                            if(displayErrorDialog == 1)
                            {
                                m_box->setWindowTitle("VENTAS UPDATE");
                                m_box->information(0,
                                              tr("VDC UPDATE"),
                                              tr("No A4GL informations found!!"),
                                              tr("&Ok"),
                                              QString(), 0);
                            }
                        }
                    } else {
                        if(displayErrorDialog == 1)
                        {
                            m_box->setWindowTitle("VENTAS UPDATE");
                            m_box->information(0,
                                          tr("VDC UPDATE"),
                                          tr("The Client is up to date!"),
                                          tr("&Ok"),
                                          QString(), 0);
                        }
                    }
                }
            } else {
                if(displayErrorDialog == 1)
                {
                    m_box->setWindowTitle("VENTAS UPDATE");
                    m_box->information(0,
                                  tr("VDC UPDATE"),
                                  tr("The Client is up to date!"),
                                  tr("&Ok"),
                                  QString(), 0);
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
            qDebug() << QString("Cannot load File from Server. Error code: %1 ").arg(reply->error());
            m_label->setText(QString("Cannot load File from Server. Error code: %1 ").arg(reply->error()));
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
