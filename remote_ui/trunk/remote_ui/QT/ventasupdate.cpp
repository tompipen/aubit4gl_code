#include "ventasupdate.h"
#include "include/vdc.h"
#include "clienttcp.h"
#include "mainframe.h"
#include "models/fglform.h"
#ifdef Q_WS_WIN
#include "windows.h"
#include <unistd.h>
#include <stdlib.h>
#endif

VentasUpdate::VentasUpdate(int errorMsg, QWidget *parent) :
    QWidget(parent)
{
    displayErrorDialog = errorMsg;
    m_dialog = NULL;

}
void VentasUpdate::start()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    manager->get(QNetworkRequest(QUrl("http://www.ventas.de/wp-content/uploads/downloads/autoupdate/vdcupdate.xml")));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(readXmlFinished(QNetworkReply*)));
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
        QList<QString> clientVars = clientXml(QApplication::applicationDirPath() + "/versions.xml");
    #else
        QList<QString> clientVars = clientXml(QApplication::applicationDirPath() + "/versions.xml");
    #endif
        qDebug() << "clientVars" << QApplication::applicationDirPath() + "/versions.xml";
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
                                    Dialog *dialog = new Dialog("VENTAS Update", "There is a new VDC version available.\n Do you want to download and install it?", "", "information", this, Qt::WindowStaysOnTopHint);
                                    dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                                    dialog->createButton(2, "Abort", "Abort", "abbrechen_rot.png");
                                    connect(dialog->getAction("OK"), SIGNAL(triggered()), this, SLOT(checkOpenConnections()));
                                    connect(dialog->getAction("ABORT"), SIGNAL(triggered()), dialog, SLOT(close()));
                                    dialog->move(600,400);
                                    dialog->show();
                                    m_dialog = dialog;
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
                filePath = QString(QApplication::applicationDirPath() + "/versions.xml");
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

void VentasUpdate::checkOpenConnections()
{
    QList<ScreenHandler*> *ql_screenhandler = MainFrame::ql_screenhandler;
    if(ql_screenhandler)
    {
        if(ql_screenhandler->count() > 0)
        {
            if(m_dialog)
            {
                m_dialog->close();
                m_dialog = NULL;
            }

            Dialog *dialog = new Dialog("VENTAS Update", "There are modules running.\n They will be terminated. \n Do you really want to continue?", "", "stop", this, Qt::WindowStaysOnTopHint);
            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
            dialog->createButton(2, "Abort", "Abort", "abbrechen_rot.png");
            connect(dialog->getAction("OK"), SIGNAL(triggered()), this, SLOT(downloadBinarie()));
            connect(dialog->getAction("ABORT"), SIGNAL(triggered()), dialog, SLOT(close()));
            dialog->move(600,400);
            dialog->show();
            m_dialog = dialog;
        } else {
            emit downloadBinarie();
        }
    } else {
        emit downloadBinarie();
    }
}

void VentasUpdate::downloadBinarie()
{
    QList<ScreenHandler*> *ql_screenhandler = MainFrame::ql_screenhandler;
    QFile file;

    if(m_dialog)
    {
        m_dialog->close();
        m_dialog = NULL;
    }

    if(ql_screenhandler)
    {
        for(int i=0; i < ql_screenhandler->count(); i++)
        {

            if(ScreenHandler *screen = qobject_cast<ScreenHandler*> (ql_screenhandler->at(i)))
            {
                if(screen->p_fglform)
                {
                    if(FglForm *p_fglform = qobject_cast<FglForm*> (screen->p_fglform))
                    {
                        p_fglform->close();
                    }
                }
            }
        }
    }


    #ifdef Q_WS_WIN
        file.setFileName(QApplication::applicationDirPath() + "/update.exe");
    #else
        file.setFileName(QApplication::applicationDirPath() + "/update");
    #endif

        qDebug() << "file: " << file.fileName();
    if(file.exists())
    {
        QProcess *proc = new QProcess;
        #ifdef Q_WS_WIN
            proc->start(file.fileName());
            Sleep(1500);
            QApplication::quit();
        #endif
        #ifdef Q_WS_X11
           proc->start(file.fileName());
           //QDesktopServices::openUrl(QUrl(QString("file://" + file.fileName()), QUrl::TolerantMode));
        #endif
        #ifdef Q_WS_MAC
           proc->start(file.fileName());
           //QDesktopServices::openUrl(QUrl(QString("file:///" + file.fileName()), QUrl::TolerantMode));
        #endif
    } else {
        qDebug() << QString("Datei nicht gefunden: %1").arg(file.fileName());
    }
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
    }
    file.close();
    return returnList;
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
