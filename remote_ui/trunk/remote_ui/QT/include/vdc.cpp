#include <include/vdc.h>
#include <QDir>

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
       QSettings settings(QDir::homePath() + "/.vdc/settings.ini", QSettings::IniFormat);

       settings.beginGroup(group);
       value.append(settings.value(key).toString());
       settings.endGroup();

       return value;
   }

   void saveSettingsToIni(QString group, QString key, QString value)
   {
       QSettings settings(QDir::homePath() + "/.vdc/settings.ini", QSettings::IniFormat);
       settings.beginGroup(group);
       settings.setValue(key, value);
       settings.endGroup();
   }

   void removeSettingsFromIni(QString group, QString key)
   {
       QSettings settings(QDir::homePath() + "/.vdc/settings.ini", QSettings::IniFormat);
       settings.beginGroup(group);
       settings.remove(key);
       settings.endGroup();
   }

}
