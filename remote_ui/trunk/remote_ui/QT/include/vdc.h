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
  QString readSettingsFromIni(QString, QString);
  void saveSettingsToIni(QString, QString, QString);


};

#endif // VDC_H
