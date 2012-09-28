#include "copybinaries.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QApplication>
#include <QProcess>
#include <QDesktopServices>
#include <QUrl>


CopyBinaries::CopyBinaries()
{
}

void CopyBinaries::start(QString tmpDirPath, QString newDirPath)
{
    copyBinaries(tmpDirPath, newDirPath);
}

void CopyBinaries::copyBinaries(QString tmpDirPath, QString newDirPath)
{
    logMessage(QString("[DEBUG] Starte Kopieren %1").arg(newDirPath));
    int wert  = 0;

    if(newDirPath.isEmpty())
    {
        return;
    }
    QDir tmpDir(tmpDirPath);
    QFileInfoList tmpDirFileInfoList = tmpDir.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);

    foreach(QFileInfo tmpDirFileInfo, tmpDirFileInfoList)
    {
        wert++;

        logMessage("[DEBUG] Laufe foreach druch");
        logMessage(QString("wert %1").arg(wert));
        logMessage(QString("Count: %1").arg(tmpDirFileInfoList.count()));
        QString tmpFilePath = tmpDirFileInfo.absoluteFilePath();
        QString destFilePath = newDirPath + "/" + tmpDirFileInfo.fileName();

        logMessage(QString("Bin bei %1").arg(tmpDirFileInfo.fileName()));

        if(tmpDirFileInfo.isDir())
        {
            QDir dir(destFilePath);
            if(!dir.exists())
            {
                if(dir.mkpath(destFilePath))
                {

                    qDebug() << "ERFOLG!";
                } else {
                    qDebug() << "MISSERFOLG!";
                }
                //subDirCreate.mkdir(tmpDirFileInfo.absoluteFilePath());
            }

            QDir subDir(tmpDirFileInfo.absoluteFilePath());
            QFileInfoList subDirInfoList = subDir.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);

            foreach (QFileInfo subDirFileInfo, subDirInfoList)
            {
                QString tmpSubFile = subDirFileInfo.absoluteFilePath();
                QString destFile = newDirPath + "/" + subDir.dirName() + "/" + subDirFileInfo.fileName();

                qDebug() << subDirFileInfo.fileName();
                qDebug() << "copyFile" << tmpSubFile;
                qDebug() << "destFile: " << destFile;
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
            qDebug() << "destFilePath" << destFilePath;
            logMessage(QString("[DEBUG] Destination123: %1 ").arg(destFilePath));

            if(QFile::exists(destFilePath))
            {
                QFile rmFile(destFilePath);
                if(!rmFile.remove())
                {
                    logMessage(QString("[ERROR] Fehler beim loeschen der Datei : %1").arg(destFilePath));
                }
            }
            if(!QFile::copy(tmpFilePath, destFilePath))
            {
                logMessage(QString("[ERROR] Kopieren fehlgeschlagen: %1").arg(destFilePath));
                qDebug() << "Kopieren fehlgeschlagen ROOT DIR. ABBRUCH!";
            }
        }
    }

    QString prog ;
#ifdef Q_WS_X11
    //setEnv("LD_LIBRARY_PATH", QApplication::applicationDirPath(), 1);
#endif
#ifdef Q_WS_MAC
    //setEnv("DYLD_LIBRARY_PATH", "/Applications/VENTAS-Software/VDC.app/Contents/Frameworks/", 1);
#endif
    prog = QString(QApplication::applicationDirPath() + "/VDC");
    QProcess process;
#ifdef Q_WS_WIN
    process.startDetached(QString("rundll32 url.dll,FileProtocolHandler \"%1\"").arg( prog));
#endif
#ifdef Q_WS_MAC
    process.start(prog);
#endif
#ifdef Q_WS_X11
    QStringList list = prog;
    process.start("/bin/sh/ -c", list);
#endif
    logMessage(QString("[DEBUG] Starte VDC erneut mit Path: %1").arg(prog));

    //exit(0);
}

void CopyBinaries::logMessage(QString msg)
{
    QDir dir(QApplication::applicationDirPath() + "/logs");

    if(!dir.exists())
    {
        dir.mkdir(QApplication::applicationDirPath() + "/logs");
    }

    QFile file(QApplication::applicationDirPath() + "/logs/copylog.log");
    qDebug() << "log path: " << QApplication::applicationDirPath() + "/logs/patchlog.log";

    if(file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream out(&file);
        msg = msg + "\r\n";
        out << msg;
        file.close();

    }

}
