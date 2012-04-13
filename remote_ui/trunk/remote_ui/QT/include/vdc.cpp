#include <include/vdc.h>
#include <QDir>
#include <QDebug>
#include <QDesktopServices>

namespace VDC {
   double fieldsizefactor;

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
           fieldsizefactor = 1;
       }
     return fieldsizefactor;
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

}
