#include "models/zipunzip.h"


bool ZipUnzip::unzipFile(QString filePath, QString fileName)
{
    QuaZip zip(fileName);
    QString ausgabe;


    if( !zip.open( QuaZip::mdUnzip ) )
    {
        qWarning("(unzipFile()): Datei konnte nicht gelesen werden. ERROR: %d", zip.getZipError());
        return false;
    }

    QuaZipFile file(&zip);

    if( !zip.setCurrentFile( fileName ) )
    {
        qDebug() << "Es wurde ein Fehler in der Zip Datei festgestellt.";
        return false;
    }

    if( !file.open( QIODevice::ReadOnly ) )
    {
        qWarning("Datei konnte nicht geöffnet werden: %d", zip.getZipError());
        return false;
    }

    QTextStream stream( &file );

    while( !stream.atEnd() )
    {
        ausgabe.append( stream.readLine() );
        qDebug() << "ausgabe: " << ausgabe;
    }

    return true;
}

bool ZipUnzip::zipFile(QString filePath, QString FileName)
{
    return true;

}
