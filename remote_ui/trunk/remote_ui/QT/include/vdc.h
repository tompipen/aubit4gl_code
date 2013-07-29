#ifndef VDC_H
#define VDC_H
#include <QApplication>
#include <QSettings>
#include <QCryptographicHash>
#include <QDir>
#include <QDebug>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QTime>
#include <QDate>

namespace VDC
{
  const int DEFAULT_HEIGHT = 21;

  void setSSHCompressionsLevel(int );
  int getSSHCompressionLevel();
  void waitCursor();
  void arrowCursor();
  double getFieldSizeFactor();
  void setFieldSizeFactor(double);
  extern double fieldsizefactor;
  void removeSettingsKeysWith(QString, QString);
  QString readSettingsFromIni(QString, QString);
  QByteArray readSettingsFromIni1(QString, QString);
  void saveSettingsToIni(QString, QString, QString);
  void saveSettingsToIni(QString, QString, QByteArray);
  void removeSettingsFromIni(QString group, QString key);
  QString md5hashfromfile(QString);

  QPoint widgetPositionValidate(int, int);

  void logMessage(QString, QString);


};

#endif // VDC_H
