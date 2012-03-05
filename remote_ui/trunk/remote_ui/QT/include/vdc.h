#ifndef VDC_H
#define VDC_H
#include <QApplication>

namespace VDC
{

  void waitCursor();
  void arrowCursor();
  int getFieldSizeFactor();
  void setFieldSizeFactor(int);
  extern int fieldsizefactor;


};

#endif // VDC_H
