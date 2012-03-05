#include <include/vdc.h>

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

}
