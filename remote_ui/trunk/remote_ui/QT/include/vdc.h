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
  QByteArray readSettingsFromIni1(QString, QString);
  void saveSettingsToIni(QString, QString, QString);
  void saveSettingsToIni(QString, QString, QByteArray);
  void removeSettingsFromIni(QString group, QString key);


};

#endif // VDC_H
