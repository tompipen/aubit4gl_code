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

     QSettings settings("Ventas AG", "Ventas Desktop Client");
     settings.setValue("fieldSizeFactor", s);
     fieldsizefactor = s;
   }

   double getFieldSizeFactor()
   {
       QSettings settings("Ventas AG", "Ventas Desktop Client");
       fieldsizefactor = settings.value("fieldSizeFactor").toDouble();
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

}
