#include "vdcupdate.h"
#include "screenhandler.h"
#include "mainframe.h"

#include "include/vdc.h"

#include "models/dialog.h"
#include "models/fglform.h"

#include <QAction>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QDomDocument>
#include <QApplication>

DownloadManager::DownloadManager( bool showError)
{
    if(VDC::readSettingsFromIni("","updateWithoutAsk").toInt() == 2) {
        mAutoUpdate = false;
    } else {
        mAutoUpdate = true;
    }
    mShowErrorMsg = showError;
}

void DownloadManager::searchForUpdate()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    manager->get(QNetworkRequest(QUrl("http://www.ventas.de/wp-content/uploads/downloads/autoupdate/vdcupdate.xml")));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(readVersionXml(QNetworkReply*)));
}

void DownloadManager::openPatcher()
{
    QList<ScreenHandler*> *ql_screenhandler = MainFrame::ql_screenhandler;
    QFile file;

#ifdef Q_OS_WIN
    file.setFileName(QApplication::applicationDirPath() + "/update.exe");
#else
    file.setFileName(QApplication::applicationDirPath() + "/update");
#endif

    if(ql_screenhandler) {
        for(int i=ql_screenhandler->count()-1; i >= 0; i--) {

            if(ScreenHandler *p_screenhandler = qobject_cast<ScreenHandler*> (ql_screenhandler->at(i))) {
                if(p_screenhandler->p_fglform) {
                    if(FglForm *p_fglform = qobject_cast<FglForm*> (p_screenhandler->p_fglform)) {
                        p_fglform->close();
                    }
                }
            p_screenhandler->closeProgramm();
            }
        }
    }
    if(!file.exists()) {
        qDebug() << QString("Datei nicht gefunden: %1").arg(file.fileName());
        return;
    }
#ifdef Q_OS_WIN
    QDesktopServices::openUrl(QUrl::fromLocalFile(file.fileName()));
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

   //Wait 2 Seconds before quit the Application
   for(int i=0; i < 11; i++) {
       waitTimer::msleep(200);
   }
   QApplication::quit(); //close the VDC with exitcode SUCCESS

}

bool DownloadManager::checkClientVersion()
{
    QString serverXmlFile = QDir::tempPath() + "/vdc.xml";
    QString clientXmlFile = QApplication::applicationDirPath() + "/versions.xml";

    QHash<QString,QString> serverVars = parseXmlFile(serverXmlFile);
    QHash<QString,QString> clientVars = parseXmlFile(clientXmlFile);

    QDate serverdate = QDate::fromString(serverVars["VDC_RELEASE_DATE"], "dd.MM.yyyy");
    QDate clientdate = QDate::fromString(clientVars["VDC_RELEASE_DATE"], "dd.MM.yyyy");

    //No Update if the client version is newer
    if(serverdate < clientdate) {
        if(showErrorMessage()) {

        }
        return false;
    }

    //No Update is the same
    if(serverVars["VDC_CHECKSUM"] == clientVars["VDC_CHECKSUM"]) {
        if(showErrorMessage()) {
            Dialog *dialog = new Dialog(tr("VDC Update"), tr("The Client is up to date!"), "", "information", NULL, Qt::WindowStaysOnTopHint);
            dialog->setVentasStyle();

            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
            dialog->getAction("OK")->setShortcut(Qt::Key_F12);

            connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
            connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));

            dialog->move(600,400);
            dialog->show();
        }
        return false;
    }

    //No Update if a4gl version is not the same
    if(serverVars["A4GL_VERSION"] < clientVars["A4GL_VERSION"]) {
        if(showErrorMessage()) {
            Dialog *dialog = new Dialog(tr("VDC Update"), tr("No new Update found for this A4GL Version."), "", "information", NULL, Qt::WindowStaysOnTopHint);
            dialog->setVentasStyle();

            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
            dialog->getAction("OK")->setShortcut(Qt::Key_F12);

            connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
            connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));

            dialog->move(600,400);
            dialog->show();
        }
        return false;
    }

    //No Update if xml version is not the same
    if(serverVars["XML_VERSION"] != clientVars["XML_VERSION"]) {
        if(showErrorMessage()) {
            Dialog *dialog = new Dialog(tr("VDC Update"), tr("No new Version for this XML Version!"), "", "information", NULL, Qt::WindowStaysOnTopHint);
            dialog->setVentasStyle();

            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
            dialog->getAction("OK")->setShortcut(Qt::Key_F12);

            connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
            connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));

            dialog->move(600,400);
            dialog->show();
        }
        return false;
    }

    return true;
}

QHash<QString, QString> DownloadManager::parseXmlFile(QString file)
{

    QHash<QString, QString> result;
    QFile xmlFile(file);
    QDomDocument doc;

    if(!xmlFile.open(QIODevice::ReadOnly)) {
        if(showErrorMessage()) {
            Dialog *dialog = new Dialog(tr("VDC Update"), tr("Cannot open file: %1").arg(file), "", "information", NULL, Qt::WindowStaysOnTopHint);
            dialog->setVentasStyle();

            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
            dialog->getAction("OK")->setShortcut(Qt::Key_F12);

            connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
            connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));

            dialog->move(600,400);
            dialog->show();
        }
        xmlFile.close();
        return result;
    }

    doc.setContent(&xmlFile);

    QDomElement root = doc.documentElement();
    QDomNode node = root.firstChildElement();
    QString clientOs = "";

#ifdef Q_OS_WIN
    clientOs = "WINDOWS";
#endif
#ifdef Q_OS_MAC
    clientOs = "MAC";
#endif
#ifdef Q_OS_LINUX
    clientOs = "LINUX";
#endif

    while(!node.isNull() && node.isElement()) {
        QDomElement secElement = node.toElement();
        if(!secElement.isNull()) {
            if(secElement.nodeName() == clientOs) {
                QDomNode child = secElement.firstChild();
                while(!child.isNull()) {
                    QDomElement text = child.toElement();
                    result.insert(text.tagName(), text.text());
                    child = child.nextSibling();
                }
            }

        }
        node = node.nextSiblingElement();
    }

    xmlFile.close();
    return result;

}

void DownloadManager::readVersionXml(QNetworkReply *reply)
{

    if(reply->error()) {
        if(showErrorMessage()) {
            Dialog *dialog = new Dialog(tr("VDC Update"), tr("Could not connect to the Update Server.\n Please check your Network connection"), "", "stop", NULL, Qt::WindowStaysOnTopHint);
            dialog->setVentasStyle();

            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
            dialog->getAction("OK")->setShortcut(Qt::Key_F12);
            connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
            connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));

            dialog->move(600,400);
            dialog->show();
        }
        return;
    }

    QFile file(QDir::tempPath() + "/vdc.xml");
    file.open(QIODevice::WriteOnly);
    file.write(reply->readAll());
    file.close();

    if(checkClientVersion())
    {
        if(!mAutoUpdate) {
            Dialog *dialog = new Dialog(tr("VDC Update"), tr("There is a new VDC version available.\n Do you want to download and install it?"), "", "stop", NULL, Qt::WindowStaysOnTopHint);
            dialog->setVentasStyle();

            dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
            dialog->createButton(2, "Cancel", "Cancel", "escape.png");

            dialog->getAction("CANCEL")->setShortcut(Qt::Key_Escape);
            dialog->getAction("OK")->setShortcut(Qt::Key_F12);

            connect(dialog->getAction("OK"), SIGNAL(triggered()), this, SLOT(openPatcher()));
            connect(dialog->getAction("OK"), SIGNAL(triggered()), dialog, SLOT(close()));
            connect(dialog->getAction("CANCEL"), SIGNAL(triggered()), dialog, SLOT(close()));


            connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));

            dialog->move(600,400);
            dialog->show();
        } else {
            emit openPatcher();
        }
    }

    reply->deleteLater();

}
