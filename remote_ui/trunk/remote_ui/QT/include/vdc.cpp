#include <include/vdc.h>

namespace VDC {
   double fieldsizefactor;

   int getSSHCompressionLevel()
   {
        int sshCompressionLevel = VDC::readSettingsFromIni("Ventas AG", "sshCompressionLevel").toInt();
        if(sshCompressionLevel == 0 )
        {
          sshCompressionLevel = 2;
        }

   return sshCompressionLevel;
   }

   void setSSHCompressionsLevel(int value)
   {
        VDC::saveSettingsToIni("Ventas AG", "sshCompressionLevel", QString::number(value));
   }

   void waitCursor()
   {

       if(!QApplication::overrideCursor())
       {
           QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
       }
   }

   void arrowCursor()
   {
       QApplication::restoreOverrideCursor();
   }

   void setFieldSizeFactor(double s)
   {
     VDC::saveSettingsToIni("Ventas AG", "fieldSizeFactor", QString::number(s));
     fieldsizefactor = s;
   }

   double getFieldSizeFactor()
   {
       fieldsizefactor = VDC::readSettingsFromIni("Ventas AG", "fieldSizeFactor").toDouble();
       if(fieldsizefactor == 0)
       {
           fieldsizefactor = 1.1;
       }
     return fieldsizefactor;
   }

   void removeSettingsKeysWith(QString group, QString text)
   {
    #ifdef Q_OS_WIN
        #if QT_VERSION < QT_VERSION_CHECK(5,0,9)
           QSettings settings(QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
        #else
           QSettings settings(QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
        #endif
    #else
    QSettings settings(QDir::homePath() + "/.vdc/settings.ini", QSettings::IniFormat);
    #endif

    settings.beginGroup(group);
    foreach(QString value, settings.allKeys())
    {
        if(value.contains(text))
        {
            settings.remove(value);
        }
    }
    settings.endGroup();
   }

   QString readSettingsFromIni(QString group, QString key)
   {
       QString value;
        #ifdef Q_OS_WIN
            #if QT_VERSION < QT_VERSION_CHECK(5,0,9)
               QSettings settings(QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
            #else
               QSettings settings(QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
            #endif
        #else
       QSettings settings(QDir::homePath() + "/.vdc/settings.ini", QSettings::IniFormat);
       #endif
       settings.beginGroup(group);
       value.append(settings.value(key).toString());
       settings.endGroup();

       return value;
   }

   QByteArray readSettingsFromIni1(QString group, QString key)
   {
        QByteArray value;
        #ifdef Q_OS_WIN
            #if QT_VERSION < QT_VERSION_CHECK(5,0,9)
               QSettings settings(QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
            #else
               QSettings settings(QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
            #endif
        #else
        QSettings settings(QDir::homePath() + "/.vdc/settings.ini", QSettings::IniFormat);
        #endif

       settings.beginGroup(group);
       value.append(settings.value(key).toByteArray());
       settings.endGroup();

       return value;
   }

   void saveSettingsToIni(QString group, QString key, QString value)
   {
        #ifdef Q_OS_WIN
            #if QT_VERSION < QT_VERSION_CHECK(5,0,9)
               QSettings settings(QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
            #else
               QSettings settings(QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
            #endif
        #else
        QSettings settings(QDir::homePath() + "/.vdc/settings.ini", QSettings::IniFormat);
        #endif
       settings.beginGroup(group);
       settings.setValue(key, value);
       settings.endGroup();
   }
   void saveSettingsToIni(QString group, QString key, QByteArray value)
   {
        #ifdef Q_OS_WIN
            #if QT_VERSION < QT_VERSION_CHECK(5,0,9)
               QSettings settings(QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
            #else
               QSettings settings(QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
            #endif
        #else
        QSettings settings(QDir::homePath() + "/.vdc/settings.ini", QSettings::IniFormat);
        #endif
       settings.beginGroup(group);
       settings.setValue(key, value);
       settings.endGroup();
   }

   void removeSettingsFromIni(QString group, QString key)
   {
        #ifdef Q_OS_WIN
            #if QT_VERSION < QT_VERSION_CHECK(5,0,9)
               QSettings settings(QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
            #else
               QSettings settings(QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
            #endif
        #else
        QSettings settings(QDir::homePath() + "/.vdc/settings.ini", QSettings::IniFormat);
        #endif
       settings.beginGroup(group);
       settings.remove(key);
       settings.endGroup();
   }

   QString md5hashfromfile(QString filename)
   {

     QByteArray ba_filedata;
     QFile file(filename);
     if(!file.open(QFile::ReadOnly))
     {
         return "-1";
     }


     ba_filedata = file.readAll();


     QCryptographicHash hash(QCryptographicHash::Md5);
     hash.addData(ba_filedata);
     QByteArray ba_hash = hash.result().toHex();
     return ba_hash.data();
   }

   QPoint widgetPositionValidate(int posX, int posY)
   {
       QDesktopWidget *desktop = new QDesktopWidget();
       if((posX > desktop->screen()->width()) || (posX < 0))
       {
           qDebug() << "Invalid PosX: " << posX;
           posX = 0;

       }

       if((posY > desktop->screen()->height()) || ( posY < 0))
       {
           qDebug() << "Invalid PosY: " << posY;
           posY = 0;
       }

       return QPoint(posX, posY);
   }
   void logMessage(QString type, QString text)
   {
       if(type == "VDC")
       {
           QDir dir(QApplication::applicationDirPath() + "/logs");

           if(!dir.exists())
           {
               dir.mkdir(QApplication::applicationDirPath() + "/logs");
           }

           QFile file(QApplication::applicationDirPath() + "/logs/VDC.log");

           if(!file.open(QIODevice::WriteOnly | QIODevice::Append))
           {
               qDebug() << "cannot open file to log VDC messages.";
           }

           QTextStream stream(&file);
           stream << "[" + QTime::currentTime().toString("HH:mm") + " - " + QDate::currentDate().toString("dd.MM.yyyy") + "] " + text + "\n";
           file.close();
       }

       if(type == "CALLTREE")
       {
           QDir dir(QApplication::applicationDirPath() + "/logs");

           if(!dir.exists())
           {
               dir.mkdir(QApplication::applicationDirPath() + "/logs");
           }

           QFile file(QApplication::applicationDirPath() + "/logs/calltree.log");

           if(!file.open(QIODevice::WriteOnly | QIODevice::Append))
           {
               qDebug() << "cannot open file to log VDC messages.";
           }

           QTextStream stream(&file);
           stream << "[" + QTime::currentTime().toString("HH:mm") + " - " + QDate::currentDate().toString("dd.MM.yyyy") + "] " + text + "\n";
           file.close();
       }
   }

   bool copyRecursive(const QString sourceFilePath, const QString targetFilePath, int overwrite)
   {
       QFileInfo srcFileInfo(sourceFilePath);
       if(srcFileInfo.isDir()) {
           QDir targetDir(targetFilePath);
           //move on directory up
           targetDir.cdUp();
           targetDir.mkdir(QFileInfo(targetFilePath).fileName());

           QDir sourceDir(sourceFilePath);
           QStringList fileNames = sourceDir.entryList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System);

           foreach (QString file, fileNames) {
               const QString newSourceFilePath = sourceFilePath + "/" + file;
               const QString newTargetFilePath = targetFilePath + "/" + file;

               if(!copyRecursive(newSourceFilePath, newTargetFilePath, overwrite)) {
                   return false;
               }
           }
       } else {
           if(QFile::exists(targetFilePath) && overwrite == 0) {
              return true;
           }

           if(QFile::copy(sourceFilePath, targetFilePath)) {
               return true;
           }
       }
   }
}
