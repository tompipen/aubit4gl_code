#ifndef ZIPUNZIP_H
#define ZIPUNZIP_H
#include <quazip/quazip.h>
#include <quazip/quazipfile.h>
#include <QtGui>

class ZipUnzip : public QObject
{
    //Q_OBJECT;

public:

   /* ~ZipUnzip();
    ZipUnzip();*/
    bool unzipArchiv(QString filePath, QString fileName);
    bool unzipFile(QString filePath, QString fileName);
    bool zipFile(QString filePath, QString FileName);

};

#endif // ZIPUNZIP_H
