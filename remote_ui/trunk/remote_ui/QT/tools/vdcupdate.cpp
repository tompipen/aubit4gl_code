#include "vdcupdate.h"
#include "screenhandler.h"
#include "mainframe.h"
#include "include/vdc.h"
#include "models/dialog.h"
#include "models/fglform.h"
#include "login.h"
#include "patcher/ssh/scpconnector.h"

#include <QAction>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QDomDocument>
#include <QApplication>

DownloadManager::DownloadManager( bool showError)
{
    if(VDC::readSettingsFromLocalIni("","updateWithoutAsk").toInt() == 2) {
        mAutoUpdate = false;
    } else {
        mAutoUpdate = true;
    }
    mUpdateRequired = false;
    mShowErrorMsg = showError;
    VDC::saveSettingsToLocalIni("","vdcInstallDir", QString(QApplication::applicationDirPath()));
}

void DownloadManager::createWorkingDir()
{

    const QString workingDirPath = QDir::tempPath() + "/VDC_UPDATE";
    const QString vdcInstallDir = VDC::readSettingsFromLocalIni("","vdcInstallDir");

    if(!vdcInstallDir.isEmpty())
    {
        VDC::copyRecursive(vdcInstallDir, workingDirPath, 1);
    }

}

void DownloadManager::cleanVdcFolder()
{
    const QString vdcLogsDirPath = VDC::readSettingsFromLocalIni("","vdcInstallDir") + "/logs/";
    const QString vdcBackupDirPath = VDC::readSettingsFromLocalIni("","vdcInstallDir") + "/backup/";
    const QString vdcUpdatePath = QDir::tempPath() + "/VDC_UPDATE";

    //Remove VDC.log
    QDir vdcLogsDir(vdcLogsDirPath);
    //vdcLogsDir.removeRecursively();

    //Remove backup folder
    QDir vdcBackupDir(vdcBackupDirPath);
    //vdcBackupDir.removeRecursively();

    //VDC Update Diretory
    QDir vdcUpdateDir(vdcUpdatePath);
    //vdcUpdateDir.removeRecursively();

}

void DownloadManager::searchForUpdate()
{
#ifndef Q_OS_MAC
    LoginForm *login = qobject_cast<LoginForm*> (MainFrame::lastmainframe->centralWidget());
    ScpConnector *scp = new ScpConnector(login->getUserName(),login->getPassword(), login->getServer(), "vdcupdate.xml");
    scp->start();

    while(!scp->isFinished()) {
        QApplication::processEvents();
    }

    //exitcode: 1 - an error has been occurred
    //exitcode: 0 - all is ok

    switch(scp->getExitCode()) {
    case 0:
        //vdcupdate.xml has been downloaded from Local Server
        this->readVersionXml();
        break;
    default:
        QNetworkAccessManager *manager = new QNetworkAccessManager();
        manager->get(QNetworkRequest(QUrl("http://www.ventas.de/wp-content/uploads/downloads/autoupdate/vdcupdate.xml")));
        connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(readVersionXml(QNetworkReply*)));
        break;
    }
#endif

}

void DownloadManager::openPatcher()
{
    QList<ScreenHandler*> *ql_screenhandler = MainFrame::ql_screenhandler;
    QFile file;
    cleanVdcFolder();
    createWorkingDir();
    LoginForm *login = qobject_cast<LoginForm*> (MainFrame::lastmainframe->centralWidget());


#ifdef Q_OS_WIN
    file.setFileName(QDir::tempPath() + "/VDC_UPDATE/update.exe");
    //file.setFileName(QDir::toNativeSeparators("F:/Firma/Qt-Workspace/build-VDC-Desktop_Qt_5_5_1_MSVC2013_32bit-Debug/patcher/debug/update.exe"));
#else
    file.setFileName(QApplication::applicationDirPath() + "/update");
#endif

    if(!file.exists()) {
        qDebug() << QString("Update Programm nicht gefunden: %1").arg(file.fileName());
        return;
    }

    //Close all windows
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
    QProcess *proc = new QProcess;
    QStringList env = QProcess::systemEnvironment();
    QStringList args;
    args << login->getUserName() << login->getPassword() << login->getServer();
#ifdef Q_OS_WIN
    proc->setEnvironment(env);
    proc->start(file.fileName(), args);
#endif

#ifdef Q_OS_MAC
   QString library_path = QApplication::applicationDirPath();
   library_path.replace("MacOS", "Frameworks");
   library_path.prepend("DYLD_LIBRARY_PATH=");
   env << library_path;
#endif

#ifdef Q_OS_LINUX
   env << QApplication::applicationDirPath();
#endif
   proc->setEnvironment(env);
   proc->start(file.fileName(), args);

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

    if(serverVars.count() <= 0)
    {
        return false;
    }

    if(clientVars.count() <= 0)
    {
        return false;
    }

    QString A4glFromClient = VDC::readSettingsFromIni("", "a4gl_version");
    QString XmlVersionServer = VDC::readSettingsFromIni("", "xml_version");

    QDate serverdate = QDate::fromString(serverVars["VDC_RELEASE_DATE"], "dd.MM.yyyy");
    QDate clientdate = QDate::fromString(clientVars["VDC_RELEASE_DATE"], "dd.MM.yyyy");
    mUpdateRequired = serverVars["UPDATE_REQUIRED"].toInt();
    VDC::saveSettingsToIni("","lastVDCUpdate", clientVars["VDC_RELEASE_DATE"]);

    //No Update if the client version is newer
    if(serverdate < clientdate) {
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

    if(serverVars["A4GL_VERSION"] < A4glFromClient) {
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

    if(serverVars["XML_VERSION"] < XmlVersionServer) {
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

    QDomNodeList rootNodes;

#ifdef Q_OS_WIN
    rootNodes = doc.elementsByTagName("WINDOWS");
#endif

#ifdef Q_OS_MAC
    rootNodes = doc.elementsByTagName("MAC");
#endif
#ifdef Q_OS_LINUX
    rootNodes = doc.elementsByTagName("LINUX");
#endif

    QDomNode node = rootNodes.at(0);

    for (int i=0; i < node.childNodes().count(); i++) {
        QDomNode childNodes = node.childNodes().at(i);
        QDomElement childElements = childNodes.toElement();
        QString key = childElements.tagName();
        QString value = childElements.text();
        qDebug() << "key: " << key << " - value: " << value;
        result.insert(key, value);
    }

    xmlFile.close();

    return result;
}

void DownloadManager::readVersionXml(QNetworkReply *reply)
{

    if(reply != NULL) {
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
    }

    if(checkClientVersion())
    {
        //Update erzwingen
        if(mUpdateRequired) {
            emit openPatcher();
            return;
        }

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

    if(reply != NULL) {
        reply->deleteLater();
    }

}
