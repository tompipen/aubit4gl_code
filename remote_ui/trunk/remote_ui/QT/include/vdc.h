#ifndef VDC_H
#define VDC_H
#include <QApplication>
#include <QSettings>
#include <QCryptographicHash>

namespace VDC
{
  const int DEFAULT_HEIGHT = 21;




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
  QString md5hashfromfile(QString);


};

#endif // VDC_H
