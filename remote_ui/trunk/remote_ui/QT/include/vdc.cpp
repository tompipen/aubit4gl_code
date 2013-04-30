#include <include/vdc.h>
#include <QDir>
#include <QDebug>
#include <QDesktopServices>
#include <QDesktopWidget>

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
    #ifdef Q_WS_WIN
    QSettings settings(QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
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
       #ifdef Q_WS_WIN
       QSettings settings(QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
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
        #ifdef Q_WS_WIN
        QSettings settings(QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
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
        #ifdef Q_WS_WIN
        QSettings settings(QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
        #else
        QSettings settings(QDir::homePath() + "/.vdc/settings.ini", QSettings::IniFormat);
        #endif
       settings.beginGroup(group);
       settings.setValue(key, value);
       settings.endGroup();
   }
   void saveSettingsToIni(QString group, QString key, QByteArray value)
   {
        #ifdef Q_WS_WIN
        QSettings settings(QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
        #else
        QSettings settings(QDir::homePath() + "/.vdc/settings.ini", QSettings::IniFormat);
        #endif
       settings.beginGroup(group);
       settings.setValue(key, value);
       settings.endGroup();
   }

   void removeSettingsFromIni(QString group, QString key)
   {
        #ifdef Q_WS_WIN
        QSettings settings(QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
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
}
