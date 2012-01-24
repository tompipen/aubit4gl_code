#include "models/zipunzip.h"

/*ZipUnzip::ZipUnzip()
{

}

ZipUnzip::~ZipUnzip()
{

}*/

bool ZipUnzip::unzipArchiv(QString filePath, QString fileName)
{
    QFile fileBaseName(QDir::tempPath() + "/" + fileName);
    QFileInfo infoFileBaseName(fileBaseName);

    qDebug() << QDir::tempPath() + "/" + fileName;

    QuaZip zip(QString(filePath + "/" + fileName));

    if( !zip.open( QuaZip::mdUnzip ) )
    {
        qWarning ( "(unzipArchiv()): Datei konnte nicht geöffnet werden. Fehlermeldung: " );
        return false;
    }

    for( bool more=zip.goToFirstFile(); more; more=zip.goToNextFile() )
    {
        QuaZipFile file( &zip );

        QString name = zip.getCurrentFileName();
        QFile meminfo( QDir::tempPath() + "/" + infoFileBaseName.baseName() + "/" + name );

        QFileInfo infofile(meminfo);

        QDir extract( QDir::tempPath() + "/" + infoFileBaseName.baseName() );

        if( !extract.mkpath( infofile.absolutePath() ) )
        {
            qWarning ( "(unzipArchiv()): Konnte Verzeichnis nicht anlegen: " );
            return false;
        }

            if(name.contains(".")) {
                if( !file.open( QIODevice::ReadOnly ) && file.isReadable() ) {
                    qDebug() << "nich lesbar" << "";
                    return false;
                }

                QFile *destdir = new QFile(QString(QDir::tempPath() + "/" + infoFileBaseName.baseName() + "/" + zip.getCurrentFileName()));

                if( destdir->open( QIODevice::WriteOnly | QIODevice::Truncate) )
                {
                    QTextStream stream( destdir );
                    stream << file.readAll();
                } else {
                    return false;
                }

                file.close();
                destdir->close();
            }
    }
    zip.close();
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

bool ZipUnzip::zipFileArchiv(QString filePath, QString FileName)
{
    return true;

}
