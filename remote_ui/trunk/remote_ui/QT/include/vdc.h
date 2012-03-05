#ifndef VDC_H
#define VDC_H
#include <QApplication>
#include <QSettings>

namespace VDC
{

  void waitCursor();
  void arrowCursor();
  double getFieldSizeFactor();
  void setFieldSizeFactor(double);
  extern double fieldsizefactor;


};

#endif // VDC_H
