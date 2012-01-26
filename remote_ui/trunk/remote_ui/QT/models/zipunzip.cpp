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
                destdir->setPermissions(QFile::ReadOther | QFile::WriteOther | QFile::ReadOwner | QFile::WriteOwner);
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
    const QString currentDir = QDir::currentPath();
    QString absolutFilePath =  QString( filePath + "/" + FileName );
    QDir dir( absolutFilePath );
    char c;

    if( !dir.exists() ) {
        qDebug() << "Ordner nicht gefunden" << absolutFilePath ;
        return false;

    }

    absolutFilePath.append("123.ods");
    QuaZip zip( absolutFilePath );
    zip.setFileNameCodec("IBM866");

    if( !zip.open(QuaZip::mdCreate ) )
    {
        qDebug() << "Konnte Archiv nicht anlegen: " << absolutFilePath;
        return false;
    }

    QFile inFile;
    QuaZipFile out( &zip );
    QFileInfo fileInfo;
    const QFileInfoList list = dir.entryInfoList();

    for( int i=0; i < list.count(); i++ )
    {
        fileInfo = list.at(i);
        if( fileInfo.isDir() && fileInfo.fileName() != "." && fileInfo.fileName() != ".." )
        {
            QString subDirPath = QString( filePath + "/" + FileName + "/" + list.at(i).fileName() + "/" );
            QDir subdir( subDirPath);
            const QFileInfoList listsub = subdir.entryInfoList();
            QFileInfo subFileInfo;

            for(int j=0; j < listsub.count(); j++)
            {
                subFileInfo = listsub.at(j);

                if(subFileInfo.isDir() && subFileInfo.fileName() != "." && subFileInfo.fileName() != ".." )
                {

                } else if ( subFileInfo.isFile() && subFileInfo.fileName() != QString("LTGR_Template.ods") )
                {
                    QDir::setCurrent( dir.absolutePath() );
                    inFile.setFileName( fileInfo.fileName() + "/" + subFileInfo.fileName() );
                    if(!inFile.open(QIODevice::ReadOnly)) {
                        qDebug() << "Datei nicht gefunden: " << subFileInfo.fileName();
                        return false;
                    }
                    if( !out.open(QIODevice::WriteOnly, QuaZipNewInfo(inFile.fileName()/*, QString( filePath + "/" + FileName + "/" ) */) ) )
                    {
                        qDebug() << "Datei konnte nich zum schreiben geöffnet werde: " << inFile.fileName();
                        return false;
                    }

                    while( inFile.getChar(&c) && out.putChar(c) );

                    if( out.getZipError() != UNZ_OK )
                    {
                        qDebug() << "Es ist ein Schreibfehler aufgetreten: " << out.getZipError();
                        return false;
                    }
                    out.close();

                    if( out.getZipError() != UNZ_OK )
                    {
                        qDebug() << "Es ist ein Schreibfehler aufgetreten: " << out.getZipError();
                        return false;
                    }
                    inFile.close();
                }
            }
        } else if ( fileInfo.isFile() && fileInfo.fileName() != QString("LTGR_Template.ods"))
        {
            QDir::setCurrent( dir.absolutePath() );
            inFile.setFileName( fileInfo.fileName() );
            qDebug() << "inFile: " << inFile.fileName();
            if(!inFile.open(QIODevice::ReadOnly)) {
                qDebug() << "Datei nicht gefunden: " << fileInfo.fileName();
                return false;
            }
            if( !out.open(QIODevice::WriteOnly, QuaZipNewInfo(inFile.fileName() /*QString( filePath + "/" + FileName + "/" )*/ ) ) )
            {
                qDebug() << "Datei konnte nich zum schreiben geöffnet werde: " << inFile.fileName();
                return false;
            }

            while( inFile.getChar(&c) && out.putChar(c) );

            if( out.getZipError() != UNZ_OK )
            {
                qDebug() << "Es ist ein Schreibfehler aufgetreten: " << out.getZipError();
                return false;
            }
            out.close();

            if( out.getZipError() != UNZ_OK )
            {
                qDebug() << "Es ist ein Schreibfehler aufgetreten: " << out.getZipError();
                return false;
            }
            inFile.close();
        }
    }

    zip.close();
    if( zip.getZipError() !=0 ) {
        qDebug() << "Es sit ein Fehler beim Packen aufgetreten: " << zip.getZipError();
        QDir::setCurrent(currentDir);
    }

    qDebug() << "currentDir: " << currentDir;
    QDir::setCurrent(currentDir);
    return true;

}
