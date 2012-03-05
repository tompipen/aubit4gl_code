#include <include/vdc.h>

namespace VDC {


   int fieldsizefactor = 1;

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

   void setFieldSizeFactor(int s)
   {
     fieldsizefactor = s;
   }

   int getFieldSizeFactor()
   {
     return fieldsizefactor;
   }

}
