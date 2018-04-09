#include "models/zipunzip.h"

/*ZipUnzip::ZipUnzip()
{

}

ZipUnzip::~ZipUnzip()
{

}*/

bool ZipUnzip::unzipArchiv(QString filePath, QString fileName, QString destFilePath)
{
    QuaZip zipArchiv(QString(filePath + "/" + fileName));

    if( !zipArchiv.open( QuaZip::mdUnzip ) )
    {
        qDebug() << QString("(unzipArchiv()): Datei konnte nicht geoeffnet werden. Fehlermeldung: %1").arg(filePath + "/" + fileName);
        return false;
    }

    for( bool more=zipArchiv.goToFirstFile(); more; more=zipArchiv.goToNextFile() )
    {
        QuaZipFile file( &zipArchiv );

        QString name = zipArchiv.getCurrentFileName();
        QFile meminfo( destFilePath + "/" + name );

        QFileInfo infofile(meminfo);

        QDir extract( destFilePath );

        if( !extract.mkpath( infofile.absolutePath() ) )
        {
            qWarning ( "(unzipArchiv()): Konnte Verzeichnis nicht anlegen: " );
            return false;
        }

        if( !file.open( QIODevice::ReadOnly ) && file.isReadable() && !file.isWritable()  ) {
            qDebug() << "nich lesbar" << "";
            return false;
        }

        QFile *destdir = new QFile(QString(destFilePath + "/" + zipArchiv.getCurrentFileName()));

        if(destdir->exists())
        {
            QFile::remove(destdir->fileName());
        }

        if( destdir->open( QIODevice::WriteOnly | QIODevice::Truncate) )
        {
            destdir->write(file.readAll());
        } else {
            qDebug() << "konnte ned zum schreiben oeffnen" << zipArchiv.getZipError();
            //return false;
        }

        destdir->setPermissions(QFile::ReadOwner|QFile::WriteOwner|QFile::ExeOwner|QFile::ReadGroup|QFile::ExeGroup|QFile::ReadOther|QFile::ExeOther);
        destdir->close();
        meminfo.close();
        file.close();
    }
    zipArchiv.close();
    return true;
}

bool ZipUnzip::unzipBinarieArchiv(QString filePath, QString fileName, QString destFilePath)
{
    qDebug() << "file: " << QDir::tempPath() + "/" + fileName;
    qDebug() << "destFilePath: " << destFilePath;

    QuaZip zipArchiv(QString(filePath + "/" + fileName));

    if( !zipArchiv.open( QuaZip::mdUnzip ) )
    {
        qWarning ( "(unzipArchiv()): Datei konnte nicht geoeffnet werden. Fehlermeldung: " );
        return false;
    }

    for( bool more=zipArchiv.goToFirstFile(); more; more=zipArchiv.goToNextFile() )
    {
        QuaZipFile file( &zipArchiv );

        QString name = zipArchiv.getCurrentFileName();
        QFile meminfo( destFilePath + "/" + name );

        QFileInfo infofile(meminfo);

        QDir extract( destFilePath );

        if( !extract.mkpath( infofile.absolutePath() ) )
        {
            qWarning ( "(unzipArchiv()): Konnte Verzeichnis nicht anlegen: " );
            return false;
        }

        if( !file.open( QIODevice::ReadOnly ) && file.isReadable() && !file.isWritable()  ) {
            qDebug() << "nich lesbar" << "";
            return false;
        }

        QFile *destdir = new QFile(QString(destFilePath + "/" + zipArchiv.getCurrentFileName()));

        if(destdir->exists())
        {
            if(QFile::remove(destdir->fileName()))
            {
                qDebug() << "erfolgreich" << destdir->fileName();
            } else {
                qDebug() << "fehlgeschlagen" << destdir->fileName();
            }
        }

        if( destdir->open( QIODevice::WriteOnly | QIODevice::Truncate) )
        {
            destdir->write(file.readAll());
        } else {
            qDebug() << "konnte ned zum schreiben oeffnen" << zipArchiv.getZipError();
        }

        destdir->setPermissions(QFile::ReadOwner|QFile::WriteOwner|QFile::ExeOwner|QFile::ReadGroup|QFile::ExeGroup|QFile::ReadOther|QFile::ExeOther);
        destdir->close();
        meminfo.close();
        file.close();
    }
    zipArchiv.close();
    return true;
}


bool ZipUnzip::unzipFile(QString filePath, QString fileName)
{
    Q_UNUSED(filePath);
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

bool ZipUnzip::zipFileArchiv(QString filePath, QString FileName, QFileInfo zielDatei)
{
    const QString currentDir = QDir::currentPath();
    QString absolutFilePath =  QString( filePath + "/" + FileName );
    QDir dir( absolutFilePath );
    char c;

    if( !dir.exists() ) {
        qDebug() << "Ordner nicht gefunden" << absolutFilePath ;
        return false;

    }

    //absolutFilePath.append("123.ods");

    QuaZip zip( filePath + "/" + zielDatei.fileName() );
    zip.setFileNameCodec("IBM850");

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
                        qDebug() << "Datei konnte nich zum schreiben geoeffnet werde: " << inFile.fileName();
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
            if(!inFile.open(QIODevice::ReadOnly)) {
                qDebug() << "Datei nicht gefunden: " << fileInfo.fileName();
                return false;
            }
            if( !out.open(QIODevice::WriteOnly, QuaZipNewInfo(inFile.fileName() /*QString( filePath + "/" + FileName + "/" )*/ ) ) )
            {
                qDebug() << "Datei konnte nich zum schreiben geoeffnet werde: " << inFile.fileName();
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

    QDir::setCurrent(currentDir);
    return true;

}
