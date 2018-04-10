#include "documentinfo.h"

#include <QTextStream>
#include <QDir>
#include <QDomDocument>

#include "models/zipunzip.h"

DocumentInfo::DocumentInfo(QString templateFile, QString zielInfoDatei)
{
    m_templateFile= templateFile;
    m_zielInfoFile = zielInfoDatei;
    m_infoEbeneCnt = 0;

}

DocumentInfo::~DocumentInfo()
{

}

bool DocumentInfo::createInfoFile()
{

    QList<QString> fields;
    QFileInfo odffile = getTempateFile();
    QFileInfo zieldatei = getZielInfoFile();

    setWorkingDir(QDir::tempPath() + "/" + odffile.baseName());

    //printMsg("erstellen der Info Datei" + odffile.fileName());

    ZipUnzip *p_zipunzip = new ZipUnzip();

    if(!p_zipunzip->unzipArchiv(QDir::tempPath(), QString(odffile.fileName()), QString(getWorkingDir())))
    {
        //printMsg("Es ist ein Fehler beim entpacken aufgetreten");
        return false;
    }

    checkMetaFile(odffile.baseName());
    fields << checkVariablesInXmlFile(odffile, "content.xml");
    fields << checkVariablesInXmlFile(odffile, "styles.xml");


    QFile *file1 = new QFile( QDir::tempPath() + "/" + zieldatei.fileName() );

    if(!file1->open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        //printMsg("konnte template to sed nicht schreiben");
        return false;
    }

    QTextStream stream1( file1 );
    stream1 << QString( "EBENEN:" );

    switch(m_infoEbeneCnt)
    {
    case 1:
        stream1 << QString( "0" ) << QString( "%1" ).arg( m_infoEbeneCnt );
        break;
    case 2:
        stream1 << QString( "0" ) << QString ( "1" ) << QString( "%1" ).arg( m_infoEbeneCnt );
        break;
    case 3:
        stream1 << QString( "0" ) << QString ( "1" ) << QString ( "2" ) << QString( "%1" ).arg( m_infoEbeneCnt );
        break;
    }

    stream1 << "\n";

    if(!metaVar.isEmpty())
    {
        for(int i=0; i < metaVar.count(); i++)
        {
            stream1 << "0:" + QString(metaVar.at(i)).replace("@","") + "\n";
        }
    }
    for(int i=0; i < fields.count(); i++)
    {
        stream1 << fields.at(i).trimmed() + "\n";
    }

    file1->close();

    return true;

}

QList<QString> DocumentInfo::checkVariablesInXmlFile(QFileInfo dirName, QString filename)
{

    QFile *file = new QFile( QDir::tempPath() + "/"  + dirName.baseName() + "/" + filename);

    if( !file->open( QIODevice::ReadOnly ) )
    {
        //printMsg("konnte datei nicht oeffnen");
        //qWarning(QString("Konnte Datei nicht zum lesen oeffnen: %1").arg(templateFile).toLatin1());
        //return false;
    }

    QDomDocument doc1;
    doc1.setContent(file);
    QString xml = doc1.toString();
    QString ausgabe;
    int counter = 0;
    int found = 0;
    QList<QString> fields;

    QTextStream stream(&xml);

    while( !stream.atEnd() )
    {
        ausgabe = stream.readLine();

        if( ausgabe.contains("[P1["))
        {
            m_infoEbeneCnt = 1;
        }

        if( ausgabe.contains("[P2["))
        {
            m_infoEbeneCnt = 2;
        }

        if( ausgabe.contains("[P3["))
        {
            m_infoEbeneCnt = 3;
        }

        if( ausgabe.contains("[") )
        {
            counter = counter + 1;
        }

        if(ausgabe.contains("]"))
        {
            counter = counter - 1;
        }

        if(ausgabe.contains("@"))
        {
            QRegExp rxlen("^(.*)(@([A-Z][A-Z0-9_]+))(.*)$");

            int pos = 0;
            while (1==1) {
               pos = rxlen.indexIn(ausgabe, pos); //prueft ob der regex im text vorkommt

               if (pos > -1) {
                   //QString davor     = rxlen.cap(1); // String vor Variable
                   //QString variable1 = rxlen.cap(3); // Variable
                   //QString variable2 = "@" + praefix + variable1;
                   //QString danach    = rxlen.cap(4); // String nach Variable

                   ausgabe.remove(rxlen.cap(1).length(), rxlen.cap(2).length());

                   QString variable = QString::number(counter) + ":" + rxlen.cap(3);

                   if(!fields.contains(variable + "\n")) {
                       fields << variable + "\n";
                   }
               } else {
                   break;
               }
            }

            /*QString str;
            int startAppend = 0;
            for(int i=0; i < ausgabe.length(); i++)
            {
                QString character = ausgabe.at(i);
                if(ausgabe.at(i) == QChar('@'))
                {
                    startAppend = 1;
                }

                if(startAppend == 1 && (!character.contains(QRegExp("^[a-zA-Z0-9@_]+$")) ))
                {
                    startAppend = 0;

                    str.replace("@",QString("%1:").arg(counter)).trimmed();

                    if(!fields.isEmpty())
                    {
                        for(int i=0; i < fields.count(); i++)
                        {
                            if(fields.at(i).contains(str + "\n"))
                            {
                                found = found + 1;
                            }
                        }
                        if(found == 0)
                        {
                            fields << str + "\n";
                        }
                        found = 0;
                    } else {
                        fields << str + "\n";
                    }
                    str.clear();
                }

                if(startAppend == 1)
                {
                    str.append(ausgabe.at(i));
                }
            }*/
        }
    }
    return fields;
}

bool DocumentInfo::checkMetaFile(QString odffile)
{
    QFile *file = new QFile(getWorkingDir() + "/" + odffile + "/meta.xml");

    if(!file->open(QIODevice::ReadOnly))
    {
        //printMsg("(checkMetaFile()): Konnte meta.xml nicht zum lesen oeffnen");
        return false;
    }

    QDomDocument doc;
    doc.setContent(file);
    QString xmlMeta = doc.toString();
    QString ausgabe;
    QString variable;
    QTextStream stream(&xmlMeta);

    int start = 0;

    while(!stream.atEnd())
    {
        ausgabe = stream.readLine();
        if( ausgabe.contains("<dc:description>") )
        {
            ausgabe.remove("<dc:description>");
            ausgabe.remove("</dc:description>");
            for(int i=0; i < ausgabe.length(); i++)
            {
                if(ausgabe.at(i) == QChar('@') )
                {
                    start = 1;
                }
                if(ausgabe.at(i) == QChar(' ') || (i+1) == ausgabe.length())
                {
                    start = 0;
                    if(!variable.isEmpty())
                    {
                        metaVar << QString(variable + ausgabe.at(i)).trimmed();
                        variable.clear();
                    }
                }

                if(start == 1)
                {
                    variable = variable + ausgabe.at(i);
                }
            }
        }
    }
    file->close();
    return true;
}
