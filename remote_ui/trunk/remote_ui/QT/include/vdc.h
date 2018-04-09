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

  extern QString m_dblocale;

  QColor getVentasColor(QString);

  void setSSHCompressionsLevel(int );
  int getSSHCompressionLevel();
  void waitCursor();
  void arrowCursor();
  double getFieldSizeFactor();
  QString getPathToSettingsIni();
  void setFieldSizeFactor(double);
  extern double fieldsizefactor;
  void removeSettingsKeysWith(QString, QString);
  QString getAllKeysFromGroup(QString group);

  QString readSettingsFromLocalIni(QString, QString);
  void saveSettingsToLocalIni(QString, QString, QString);
  void removeSettingsFromLocalIni(QString group, QString key);
  QString readSettingsFromIni(QString, QString);
  QString readSettingsFromIni(QString, QString, QString);
  QByteArray readSettingsFromIni1(QString, QString);
  void saveSettingsToIni(QString, QString, QString);
  void saveSettingsToIni(QString, QString, QByteArray);
  void removeSettingsFromIni(QString group, QString key);
  QString md5hashfromfile(QString);

  bool copyRecursive(const QString, const QString, int);

  QPoint widgetPositionValidate(int, int);

  void setTableViewRowHeight(int qs_value);
  QString removeUmlauts(QString absolutePath);
  int getTableViewRowHeight();

  void setDBLocale(QString locale);
  QString getDBLocale();


  void logMessage(QString, QString);


};

#endif // VDC_H
