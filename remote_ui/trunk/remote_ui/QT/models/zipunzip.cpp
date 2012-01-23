#include "models/zipunzip.h"

bool ZipUnzip::unzipArchiv(QString filePath, QString fileName)
{
    QFile fileBaseName(QDir::tempPath() + "/" + fileName);
    QFileInfo infoFileBaseName(fileBaseName);

    QuaZip zip(QString(filePath + "/" + fileName));

    if( !zip.open( QuaZip::mdUnzip ) )
    {
        qWarning ( "(unzipArchiv()): Datei konnte nicht geöffnet werden. Fehlermeldung: %d,", zip.getZipError() );
        return false;
    }

    QuaZipFile file( &zip );
    //file.setZipName( QString(QDir::tempPath() + "/") );
    //file.setFileName( fileName );
    qDebug() << "pfad:" << QString(QDir::tempPath() + "/" + fileName );

    for( bool more=zip.goToFirstFile(); more; more=zip.goToNextFile() )
    {
        file.open(QIODevice::ReadOnly);
        QString name = zip.getCurrentFileName();
        QFile meminfo( QDir::tempPath() + "/" + infoFileBaseName.baseName() + "/" + name );
        QFileInfo infofile(meminfo);
        qDebug() << infofile.baseName();

        QDir extract( QDir::tempPath() + "/" + infoFileBaseName.baseName() );

        if( !extract.mkpath( infofile.absolutePath() ) )
        {
            qWarning ( "(unzipArchiv()): Konnte Verzeichnis nicht anlegen: %d", infofile.absolutePath() );
            return false;
        }

        if( meminfo.open( QIODevice::ReadWrite ) )
        {
                qDebug() << "stream" << file.readAll();
                qDebug() << "infoFileBaseName.baseName()" << extract.absolutePath();
                meminfo.write( file.readAll() );
                meminfo.close();
            //qWarning ( "(unzipArchiv()); Konnte Dateien nicht zum Schreiben öffnen %d", name );
        }

    }
    zip.close();
    file.close();
    return true;
}


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
        qWarning("Datei konnte nicht geÃ¶ffnet werden: %d", zip.getZipError());
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
