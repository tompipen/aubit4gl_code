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

    QDate date;
    QList<QString> serverVars;
    //QList<QString> clientVars = parseXml("/home/da/versions.xml");
    serverVars << parseXml(QDir::tempPath() + "/vdc.xml");
    QNetworkAccessManager *manager = new QNetworkAccessManager;
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(updateReady(QNetworkReply*)));
    if(!serverVars.isEmpty())
    {
        date = QDate::fromString(serverVars.at(0), "dd.MM.yyyy");
    } else {
        return;
    }

    #ifdef Q_WS_MAC
        m_fileName = QString("WEB_mac_vdc_" + date.toString("ddMMyyyy") + ".zip");
    #endif
    #ifdef Q_WS_X11
        m_fileName = QString("WEB_unix_vdc_" + date.toString("ddMMyyyy") + ".zip");
    #endif
    #ifdef Q_WS_WIN
        m_fileName = QString("WEB_windows_vdc_" + date.toString("ddMMyyyy") + ".zip");
    #endif

    QNetworkRequest request;
    request.setUrl(QUrl(QString("http://www.ventas.de/wp-content/uploads/downloads/%1").arg(m_fileName)));

    qDebug() << "fileName" << m_fileName;
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
        if(displayErrorDialog == 1)
        {
            Dialog *dialog = new Dialog("VENTAS Update", QString("Failed to Open: %1").arg(filePath), "", "stop");
            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
            connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
            dialog->show();
        }
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
    //QList<QString> clientVars = parseXml("/home/da/versions.xml");
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
            Dialog *dialog = new Dialog("VENTAS Update", "Could not connect to the Update Server.\n Please check your Network connection", "", "stop");
            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
            connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
            dialog->show();
        }
    }

    if(!serverVars.isEmpty() && !clientVars.isEmpty() && serverVars.count() >= 3 && clientVars.count() >= 3)
    {
        QString a4gl_client_version = VDC::readSettingsFromIni("", "a4gl_version");
        QString xml_client_version = VDC::readSettingsFromIni("", "xml_version");

        if(!a4gl_client_version.isEmpty())
        {
            if(serverVars.at(2) == a4gl_client_version)
            {
                if(!xml_client_version.isEmpty())
                {
                    if(serverVars.at(3) == xml_client_version)
                    {
                        if(!serverVars.at(0).isEmpty() && !clientVars.at(0).isEmpty() && serverVars.at(0) > clientVars.at(0))
                        {
                            if(serverVars.at(1) != clientVars.at(1))
                            {
                                Dialog *dialog = new Dialog("VENTAS Update", "There is a new VDC version available.\n Do you want to download and install it?", "", "information");
                                dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                                dialog->createButton(2, "Abort", "Abort", "abbrechen_rot.png");
                                connect(dialog->getAction("OK"), SIGNAL(triggered()), this, SLOT(checkOpenConnections()));
                                connect(dialog->getAction("ABORT"), SIGNAL(triggered()), dialog, SLOT(close()));
                                dialog->show();
                                m_dialog = dialog;
                            } else {
                                if(displayErrorDialog == 1)
                                {
                                    Dialog *dialog = new Dialog("VENTAS Update", "The Client is up to date!", "", "information");
                                    dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                                    connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
                                    dialog->show();
                                }
                            }
                        } else {
                            if(displayErrorDialog == 1)
                            {
                                Dialog *dialog = new Dialog("VENTAS Update", "The Client is up to date!", "", "information");
                                dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                                connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
                                dialog->show();
                            }
                        }
                    } else {
                        // TODO
                        // Pruefen ob es für eine andere XML Version ein Download gibt!!!
                    }
                } else {
                    if(displayErrorDialog == 1)
                    {
                        Dialog *dialog = new Dialog("VENTAS Update", "No XML Version found!", "", "information");
                        dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                        connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
                        dialog->show();
                    }
                }
            } else {
                // TODO
                // Pruefen ob es für eine andere a4gl version ein download gibt!!!
            }
        } else {
            if(displayErrorDialog == 1)
            {
                Dialog *dialog = new Dialog("VENTAS Update", "No A4GL informations found!", "", "information");
                dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
                dialog->show();
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
    qDebug() << "bin dran!";
    if(this->m_screenhandler != NULL && this->m_screenhandler->parent() != NULL && this->m_screenhandler->parent()->parent() != NULL)
    {
        if(ClientTcp *cTcp = qobject_cast<ClientTcp *> (this->m_screenhandler->parent()->parent()))
        {
            if(cTcp->socket != NULL)
            {
                Dialog *dialog = new Dialog("VENTAS Update", "There are modules running.\n They will be terminated. \n Do you really want to continue?", "", "stop");
                dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                dialog->createButton(2, "Abort", "Abort", "abbrechen_rot.png");
                connect(dialog->getAction("OK"), SIGNAL(triggered()), this, SLOT(responseDownload()));
                connect(dialog->getAction("ABORT"), SIGNAL(triggered()), dialog, SLOT(close()));
                dialog->show();
            }
        }
    } else {
        loadFileFromServer();
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
