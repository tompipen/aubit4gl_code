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
    bool unzipArchiv(QString filePath, QString fileName, QString destFilePath);
    bool unzipFile(QString filePath, QString fileName);
    bool zipFileArchiv(QString filePath, QString FileName, QFileInfo zielDatei);

};

#endif // ZIPUNZIP_H
