#include "ventasupdate.h"
#include "include/vdc.h"
#include "clienttcp.h"
#include "mainframe.h"
#include "models/fglform.h"
#ifdef Q_OS_WIN
#include "windows.h"
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
            Dialog *dialog = new Dialog(tr("VDC Update"), tr("Could not connect to the update server.\n Please check your network connection"), "", "stop", this, Qt::WindowStaysOnTopHint);
            QPalette palette;
            palette.setBrush(this->backgroundRole(), QBrush(QImage("pics:VENTAS_11_bg.png")));
            dialog->setPalette(palette);
            dialog->setStyleSheet("QPushButton { border-image: url(pics:VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(pics:VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(pics:VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(pics:VENTAS_11_btn_dialog_gelb_grau.png);}");
            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
            dialog->getAction("OK")->setShortcut(Qt::Key_F12);
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
    #ifdef Q_OS_MAC
        QList<QString> clientVars = clientXml(QApplication::applicationDirPath() + "/versions.xml");
    #else
        QList<QString> clientVars = clientXml(QApplication::applicationDirPath() + "/versions.xml");
    #endif
        qDebug() << "clientVars" << QApplication::applicationDirPath() + "/versions.xml";
    QString A4glFromClient = VDC::readSettingsFromIni("", "a4gl_version");
    QString XmlVersionServer = VDC::readSettingsFromIni("", "xml_version");

    if(clientVars.count() >= 3)
    {

        if(clientVars.at(3) < XmlVersionServer)
                {
                    Dialog *dialog = new Dialog(tr("VDC Update"), QString(tr("Incompatible VDC version found.\n\nIt is strongly recommended to update the VDC.\n\nClient version: %1 \nServer version %2 \n\nPlease contact the VENTAS support team: support@ventas.de")).arg(clientVars.at(3)).arg(XmlVersionServer), "", "stop", this, Qt::WindowStaysOnTopHint);
                    QPalette palette;
                    palette.setBrush(this->backgroundRole(), QBrush(QImage("pics:VENTAS_11_bg.png")));
                    dialog->setPalette(palette);
                    dialog->createButton(1, "Update", "UPDATE", "ok_gruen.png", "QPushButton { border-image: url(pics:VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(pics:VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(pics:VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(pics:VENTAS_11_btn_dialog_gelb_grau.png);}");
                    dialog->createButton(1, "CANCEL", "CANCEL", "escape.png", "QPushButton { border-image: url(pics:VENTAS_11_btn_dialog_rot.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(pics:VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(pics:VENTAS_11_btn_dialog_rot_grau.png);}" "QPushButton:focus:hover { border-image: url(pics:VENTAS_11_btn_dialog_gelb_grau.png);}");
                    dialog->getAction("CANCEL")->setShortcut(Qt::Key_Escape);
                    connect(dialog->getAction("UPDATE"), SIGNAL(triggered()), this, SLOT(checkOpenConnections()));
                    connect(dialog->getAction("CANCEL"), SIGNAL(triggered()), this, SLOT(closeVdc()));
                    dialog->move(600,400);
                    dialog->show();
                }
    }

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
                                    Dialog *dialog = new Dialog(tr("VDC Update"), tr("There is a new VDC version available.\n Do you want to download and install it?"), "", "information", this, Qt::WindowStaysOnTopHint);
                                    QPalette palette;
                                    palette.setBrush(this->backgroundRole(), QBrush(QImage("pics:VENTAS_11_bg.png")));
                                    dialog->setPalette(palette);
                                    dialog->createButton(1, "Ok", "Ok", "ok_gruen.png", "QPushButton { border-image: url(pics:VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(pics:VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(pics:VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(pics:VENTAS_11_btn_dialog_gelb_grau.png);}");
                                    dialog->getAction("OK")->setShortcut(Qt::Key_F12);
                                    dialog->createButton(1, "Cancel", "Cancel", "escape.png", "QPushButton { border-image: url(pics:VENTAS_11_btn_dialog_rot.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(pics:VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(pics:VENTAS_11_btn_dialog_rot_grau.png);}" "QPushButton:focus:hover { border-image: url(pics:VENTAS_11_btn_dialog_gelb_grau.png);}");
                                    dialog->getAction("CANCEL")->setShortcut(Qt::Key_Escape);
                                    connect(dialog->getAction("OK"), SIGNAL(triggered()), this, SLOT(checkOpenConnections()));
                                    connect(dialog->getAction("CANCEL"), SIGNAL(triggered()), dialog, SLOT(close()));
                                    dialog->move(600,400);
                                    dialog->show();
                                    m_dialog = dialog;
                                    return;
                                } else {
                                    if(displayErrorDialog == 1)
                                    {
                                        Dialog *dialog = new Dialog(tr("VDC Update"), tr("No new version for this XML version!"), "", "information", this, Qt::WindowStaysOnTopHint);
                                        QPalette palette;
                                        palette.setBrush(this->backgroundRole(), QBrush(QImage("pics:VENTAS_11_bg.png")));
                                        dialog->setPalette(palette);
                                        dialog->setStyleSheet("QPushButton { border-image: url(pics:VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(pics:VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(pics:VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(pics:VENTAS_11_btn_dialog_gelb_grau.png);}");
                                        dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                                        dialog->getAction("OK")->setShortcut(Qt::Key_F12);
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
                                    Dialog *dialog = new Dialog(tr("VDC Update"), tr("No new update found for this A4GL version."), "", "information", this, Qt::WindowStaysOnTopHint);
                                    QPalette palette;
                                    palette.setBrush(this->backgroundRole(), QBrush(QImage("pics:VENTAS_11_bg.png")));
                                    dialog->setPalette(palette);
                                    dialog->setStyleSheet("QPushButton { border-image: url(pics:VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(pics:VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(pics:VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(pics:VENTAS_11_btn_dialog_gelb_grau.png);}");
                                    dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                                    dialog->getAction("OK")->setShortcut(Qt::Key_F12);
                                    connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
                                    dialog->move(600,400);
                                    dialog->show();
                                    connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));
                                }
                            }
                        } else {
                            if(displayErrorDialog == 1)
                            {
                                Dialog *dialog = new Dialog(tr("VDC Update"), tr("The client is already up to date!"), "", "information", this, Qt::WindowStaysOnTopHint);
                                QPalette palette;
                                palette.setBrush(this->backgroundRole(), QBrush(QImage("pics:VENTAS_11_bg.png")));
                                dialog->setPalette(palette);
                                dialog->setStyleSheet("QPushButton { border-image: url(pics:VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(pics:VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(pics:VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(pics:VENTAS_11_btn_dialog_gelb_grau.png);}");
                                dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                                dialog->getAction("OK")->setShortcut(Qt::Key_F12);
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
                            Dialog *dialog = new Dialog(tr("VDC Update"), tr("The Client is already up to date!"), "", "information", this, Qt::WindowStaysOnTopHint);
                            QPalette palette;
                            palette.setBrush(this->backgroundRole(), QBrush(QImage("pics:VENTAS_11_bg.png")));
                            dialog->setPalette(palette);
                            dialog->setStyleSheet("QPushButton { border-image: url(pics:VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(pics:VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(pics:VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(pics:VENTAS_11_btn_dialog_gelb_grau.png);}");
                            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                            connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
                            dialog->getAction("OK")->setShortcut(Qt::Key_F12);
                            dialog->move(600,400);
                            dialog->show();
                            connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));
                            return;
                        }
                    }
                } else {
                    Dialog *dialog = new Dialog(tr("VDC Update"), tr("Cannot find server information."), "", "information", this, Qt::WindowStaysOnTopHint);
                    QPalette palette;
                    palette.setBrush(this->backgroundRole(), QBrush(QImage("pics:VENTAS_11_bg.png")));
                    dialog->setPalette(palette);
                    dialog->setStyleSheet("QPushButton { border-image: url(pics:VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(pics:VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(pics:VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(pics:VENTAS_11_btn_dialog_gelb_grau.png);}");
                    dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
                    dialog->getAction("OK")->setShortcut(Qt::Key_F12);
                    connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
                    dialog->show();
                }
            }

        }

    } else {
        if(displayErrorDialog == 1)
        {

            QString filePath;
            #ifdef Q_OS_MAC
                filePath = QString(QApplication::applicationDirPath() + "/versions.xml");
            #else
                filePath = QString(QApplication::applicationDirPath() + "/versions.xml");
            #endif
            Dialog *dialog = new Dialog(tr("VDC Update"), QString(tr("Cannot open File: %1")).arg(filePath), "", "information", this, Qt::WindowStaysOnTopHint);
            QPalette palette;
            palette.setBrush(this->backgroundRole(), QBrush(QImage("pics:VENTAS_11_bg.png")));
            dialog->setPalette(palette);
            dialog->setStyleSheet("QPushButton { border-image: url(pics:VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(pics:VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(pics:VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(pics:VENTAS_11_btn_dialog_gelb_grau.png);}");
            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
            connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
            dialog->getAction("OK")->setShortcut(Qt::Key_F12);
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

            Dialog *dialog = new Dialog(tr("VDC Update"), tr("There are modules running.\n They will be terminated. \n Do you really want to continue?"), "", "stop", this, Qt::WindowStaysOnTopHint);
            QPalette palette;
            palette.setBrush(this->backgroundRole(), QBrush(QImage("pics:VENTAS_11_bg.png")));
            dialog->setPalette(palette);
            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png", "QPushButton { border-image: url(pics:VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(pics:VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(pics:VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(pics:VENTAS_11_btn_dialog_gelb_grau.png);}");
            dialog->getAction("OK")->setShortcut(Qt::Key_F12);
            dialog->createButton(1, "Cancel", "Cancel", "escape.png", "QPushButton { border-image: url(pics:VENTAS_11_btn_dialog_rot.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(pics:VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(pics:VENTAS_11_btn_dialog_rot_grau.png);}" "QPushButton:focus:hover { border-image: url(pics:VENTAS_11_btn_dialog_gelb_grau.png);}");
            dialog->getAction("CANCEL")->setShortcut(Qt::Key_Escape);
            connect(dialog->getAction("OK"), SIGNAL(triggered()), this, SLOT(downloadBinarie()));
            connect(dialog->getAction("CANCEL"), SIGNAL(triggered()), dialog, SLOT(close()));
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

    /*f(m_dialog)
    {
        m_dialog->close();
        m_dialog = NULL;
    }*/

    if(ql_screenhandler)
    {
        for(int i=ql_screenhandler->count()-1; i >= 0; i--)
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
            screen->closeProgramm();
            }
        }
    }

    #ifdef Q_OS_WIN
        file.setFileName(QApplication::applicationDirPath() + "/update.exe");
    #else
        file.setFileName(QApplication::applicationDirPath() + "/update");
    #endif

    qDebug() << "file: " << file.fileName();

    if(file.exists())
    {
        #ifdef Q_OS_WIN
            //QProcess process;
            //process.startDetached(QString("rundll32 url.dll,FileProtocolHandler \"%1\"").arg( file.fileName()));
            QDesktopServices::openUrl(QUrl::fromLocalFile(file.fileName()));
            //Sleep(1500);
        #endif
        #ifdef Q_OS_MAC
           QProcess *proc = new QProcess;
           QStringList env = QProcess::systemEnvironment();
           QString library_path = QApplication::applicationDirPath();
           library_path.replace("MacOS", "Frameworks");
           library_path.prepend("DYLD_LIBRARY_PATH=");
           env << library_path;
           proc->setEnvironment(env);
           proc->start(file.fileName());
        #endif
        #ifdef Q_OS_LINUX
           QProcess *proc = new QProcess;
           QStringList env = QProcess::systemEnvironment();;
           env << QApplication::applicationDirPath();
           proc->setEnvironment(env);
           proc->start(file.fileName());
        #endif
        exit(0);
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
            Dialog *dialog = new Dialog(tr("VDC Update"), QString(tr("Failed to Open: %1")).arg(filePath), "", "stop", this, Qt::WindowStaysOnTopHint);
            QPalette palette;
            palette.setBrush(this->backgroundRole(), QBrush(QImage("pics:VENTAS_11_bg.png")));
            dialog->setPalette(palette);
            dialog->setStyleSheet("QPushButton { border-image: url(pics:VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(pics:VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(pics:VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(pics:VENTAS_11_btn_dialog_gelb_grau.png);}");
            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
            dialog->getAction("OK")->setShortcut(Qt::Key_F12);
            connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
            dialog->move(600,400);
            dialog->show();
            connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));
            return returnList;
        }
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
            return clientList;
        }
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
void VentasUpdate::closeVdc()
{
    exit(0);
}
