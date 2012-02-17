#include <QtGui>
#include <QDomDocument>
#include "models/reportgen.h"
#include "models/zipunzip.h"
#include "libgen.h"
//--------------------------------------------------------------------------------
// Method       : startReportTemplate(QString odffile, QString sedfile)
// Filename     : clienttcp.cpp
// Description  : Main function to handle the append and replace of each Template.
//
//--------------------------------------------------------------------------------

bool Reportgen::startReportTemplate(QString odffile, QString sedfile, QFileInfo zielDatei)
{

    ZipUnzip *p_zipunzip = new ZipUnzip();

    if(p_zipunzip->unzipArchiv(QDir::tempPath(), QString(odffile)) == FALSE)
    {
        qDebug() << "Es ist ein Fehler beim entpacken aufgetreten" << "";
        return false;
    }

   QString content;
   QList<QString> temp_fields;
   QList<QString> sed_fields;
   QFileInfo oldFileName = odffile;
   QString fileBaseName = oldFileName.baseName();

   int wiederholen = 0;
   int cnt = 0;
   int gefunden = 0;
   int zaehler = 0;

   QFile *file = new QFile(QDir::tempPath() + "/" + fileBaseName + "/1-content.xml");

   if(!file->open(QIODevice::WriteOnly | QIODevice::Truncate)) {
       qDebug() << "(startReport): XML Datei konnte nicht erzeugt werden." << "";
       QMessageBox msgbox;
       msgbox.setText("Ventas Report Generator");
       msgbox.setInformativeText("Es ist ein Fehler aufgetreten beim erzeugen des Dokumentes.");
       msgbox.setIcon(QMessageBox::Information);
       msgbox.exec();
       return false;
   }

   QTextStream xmlsave(file);
   xmlsave.setCodec("UTF-8");
   xmlsave << getTemplateHeader( fileBaseName + "/content.xml" ) << getTemplatePosition( fileBaseName + "/content.xml" ).toUtf8();
   temp_fields << getTemplateVars(fileBaseName + "/content.xml");
   sed_fields << readSedFile(sedfile);

   for(int i=0; i < temp_fields.count(); i++)
   {
       if(temp_fields.at(i).contains("[P1["))
       {
           gefunden = 1;
       }
   }

   if(gefunden == 0)
   {
       qDebug() << "Es sind keine Ebenen im Dokument vorhanden ABBRUCH!" << "";
       QMessageBox msgbox;
       msgbox.setText("Ventas Report Generator");
       msgbox.setInformativeText("Das Dokument entaehlt keine Ebenen. Falsches Dokument ausgewaehlt?");
       msgbox.setIcon(QMessageBox::Information);
       msgbox.exec();
       return false;
   }

   //Ueberpruefen der SED Datei wie viele eintraege der ersten Variable von der 1ten Ebene vorhanden ist.

   for(int i=0; i < temp_fields.count(); i++)
   {
       if(temp_fields.at(i).contains("[")) {
           i = i + 1;
           qDebug() << "gefunden: " << temp_fields.at(i);
           for(int k=0; k < sed_fields.count(); k++)
           {
               qDebug() << "Suche in SED nach Anfang: " << k << "von" << sed_fields.count();
               if(sed_fields.at(k).contains(QString("%1"+ temp_fields.at(i)).arg(zaehler)))
               {
                   wiederholen++;
                   zaehler++;
                   qDebug() << "gefunden " << temp_fields.at(i) << wiederholen;
               }
           }
           break;
       }
   }

   /*for(int i=0; i < temp_fields.count(); i++) {
       if(temp_fields.at(i).contains("[")) {
           i = i + 1;
           if(!temp_fields.at(i).contains("[") && !temp_fields.at(i).contains("]")) {
               for(int k=0; k<sed_fields.count(); k++) {
                   for(int j=0; j<sed_fields.count(); j++) {
                       if(sed_fields.at(j).contains(QString("@%1" + temp_fields.at(i)).arg(k))) {
                           wiederholen = wiederholen + 1;
                       }
                   }

               }
               break;
           }
       }
   }*/

   for(int i=0; i < temp_fields.count(); i++) {
       if(cnt == 1) {
           for(int j=0; j < wiederholen; j++) {
               qDebug() << "ergaenze Ebene";
               qDebug() << j << "von" << wiederholen;
               content = prepareTemplateContent(j, oldFileName.baseName() + "/content.xml", sedfile);
               xmlsave << content;
           }
           break;
       }
       if(temp_fields.at(i).contains("[")) {
         cnt = cnt + 1;
       }

       if(cnt == 2) {
           break;
       }

   }

   xmlsave << getTemplateFooter( fileBaseName + "/content.xml" );
   file->close();
   replaceEbene(file, fileBaseName);

   replaceTemplateVars(fileBaseName, sedfile, zielDatei);

   return true;

}

//-------------------------------------------------------------------------------
// Method       : getTemplateHeader(QString filename)
// Filename     : clienttcp.cpp
// Description  : Returns the Header from the top of the file till <office:body>.
//
//-------------------------------------------------------------------------------

bool Reportgen::replaceEbene(QFile *file, QString odffile)
{

    QTemporaryFile *temp_file = new QTemporaryFile(QDir::tempPath() + "/" + odffile + "/tmp.xml");

    if(!temp_file->open())
    {
        qDebug() << "(replaceEbene()): Konnte Tempfile nicht erstellen" << "";
        return false;
    }

    if(!file->open(QIODevice::ReadOnly))
    {
        qDebug() << "(replaceEbene()): konnte XML nicht lesen" << "";
        return false;
    }

    QTextStream stream(temp_file);
    stream.setCodec("UTF-8");

    stream << file->readAll();

    temp_file->close();
    file->close();

    QFile *newFile = new QFile(QDir::tempPath() + "/" + odffile + "/1-content.xml");

    if(!newFile->open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        qDebug() << "(replaceEbene()): Konnte XML nicht zum schreiben oeffnen";
        return false;
    }

    QDomDocument doc;
    doc.setContent(temp_file);
    QString xml;
    int merken = 0;
    int start = 0;

    xml = doc.toString();

    QTextStream stream1(&xml);
    stream1.setCodec("UTF-8");
    QTextStream xmlsave1(newFile);
    xmlsave1.setCodec("UTF-8");
    QString xmlsave;
    QString ausgabe;
    QString behalten;

    xmlsave1 << getTemplateHeader(odffile + "/content.xml") << getTemplatePosition(odffile + "/content.xml");

    while(!stream1.atEnd())
    {

        ausgabe = stream1.readLine();
        if(ausgabe.contains("[P1["))
        {
            start = 1;
        }

        if(ausgabe.contains("]P1]"))
        {
            start = 0;
        }

        if(ausgabe.contains("<table:table-row"))
        {
            merken = 1;
            qDebug() << "merken ist 1";
        }

        if(merken == 1 && start == 1)
        {
                xmlsave = xmlsave + ausgabe;
        }

        if(ausgabe.contains("</table:table-row"))
        {
            merken = 0;
            qDebug() << "merken ist 0";
        }

        if(merken == 0 && start == 1)
        {
            if(xmlsave.contains("[") || xmlsave.contains("]"))
            {
                xmlsave.clear();
            } else if(xmlsave.contains("@")){
                behalten = xmlsave;
                xmlsave.clear();
            }
        }
        xmlsave1 << behalten;
        behalten.clear();
    }

    QFile::remove(temp_file->fileName());

    xmlsave1 << getTemplateFooter( odffile + "/content.xml" ); //<< "</office:spreadsheet>";

}

QString Reportgen::getTemplateHeader(QString filename)
{
    QFile *file = new QFile(QDir::tempPath() + "/" + filename );

    if(!file->open(QIODevice::ReadOnly)) {
        qDebug() << "Konnte Template file nicht oeffnen" << "";
    }

    QDomDocument doc;
    doc.setContent(file);

    QString xml = doc.toString();
    QTextStream stream(&xml);
    stream.setCodec("UTF-8");
    QString header;
    int cnt = 0;
    while(!stream.atEnd()) {
        header = header + stream.readLine().trimmed();

        if(header.contains("<office:body>")) {
            //header.append("</table:table-row>");
            cnt = 1;
        }
        if(cnt == 1) {
            return header;
        }
    }
   file->close();

}

//---------------------------------------------------------------------------------------
// Method       : getTemplatePosition(QString odffile)
// Filename     : clienttcp.cpp
// Description  : Get the Vars from <office:body> (header) till the first position ([P1[).
//
//---------------------------------------------------------------------------------------

QString Reportgen::getTemplatePosition(QString odffile)
{

    //qDebug() << "odf: " << odffile;
    QFile *file = new QFile(QDir::tempPath() + "/" + odffile);

    if(!file->open(QIODevice::ReadOnly)) {
        qDebug() << "konnte kopf datei nicht lesen" << "";
    }

    QDomDocument doc;
    doc.setContent(file);

    QString xml = doc.toString();
    QTextStream stream(&xml);
    stream.setCodec("UTF-8");
    QString ausgabe;
    QString behalten;
    int cnt = 0;
    int stop = 0;

    while(!stream.atEnd()) {
        ausgabe = stream.readLine();

        if(ausgabe.contains("[")) {
            stop = 1;
        }

        if(cnt > 0 && stop  < 1) {
            behalten = behalten + ausgabe;
        }

        if(ausgabe.contains("<office:body>")) {
            cnt = 1;

        }

        /*if(ausgabe.contains("</table:table-row")) {
            cnt = 0;
        }*/

    }

    behalten.append("</table:table-cell></table:table-row>");

    file->close();

    return behalten;
}


//------------------------------------------------------------------------------
// Method       : prepareTemplateContent(int, Position, QString odffile, QString sedfile)
// Filename     : clienttcp.cpp
// Description  : Create the content of each Template.
//
//------------------------------------------------------------------------------

QString Reportgen::prepareTemplateContent(int Position, QString odffile, QString sedfile)
{

    QFile *file = new QFile(QDir::tempPath() + "/" + odffile);

    if(!file->open(QIODevice::ReadOnly)) {
        qDebug() << "Template Datei nicht lesbar" << "";
    }

    QDomDocument doc;
    doc.setContent(file);
    QString xmlfile = doc.toString();
    QTextStream stream(&xmlfile);
    stream.setCodec("UTF-8");
    QString ausgabe;
    QString xmlout;
    QString test;
    QList<QString> fieldlist;
    xmlout.append("<table:table-row><table:table-cell>");

    int cnt = 0;
    int counter = 0;
    int ebene = 0;
    fieldlist << getTemplateVars(odffile);

    while(!stream.atEnd()) {
        ausgabe = stream.readLine().trimmed();


        if(ausgabe.contains("[P1[")) {
        //if(ausgabe.contains("<table:table-row")) {
            counter = counter + 1;
        }

        if(counter > 0) {

            if(ausgabe.contains("[")) {
                ebene = ebene + 1;
            }
            //qDebug() << ebene;
            if(ausgabe.contains("@") && ebene == 1) {
                for(int i=0; i < fieldlist.count(); i++) {
                    if(ausgabe.contains(fieldlist.at(i))) {
                        ausgabe.replace("@" + fieldlist.at(i), QString("@%1" + fieldlist.at(i)).arg(QString::number(Position)));
                    }
                }
            }

            if(ausgabe.contains("@") && ebene == 2) {
                for(int i=0; i < fieldlist.count(); i++) {
                    if(ausgabe.contains("@" + fieldlist.at(i))) {
                        ausgabe.replace("@" + fieldlist.at(i), QString("@%1_0" + fieldlist.at(i)).arg(QString::number(Position)));
                    }
                }
            }

            if(ausgabe.contains("@") && ebene == 3) {
                for(int i=0; i < fieldlist.count(); i++) {
                    if(ausgabe.contains("@" + fieldlist.at(i))) {
                        ausgabe.replace("@" + fieldlist.at(i), QString("@%1_0_0" + fieldlist.at(i)).arg(QString::number(Position)));
                    }
                }
            }

            if(ebene == 2) {
                test = test + ausgabe;
                if(ausgabe.contains(QString("]P%1]").arg(ebene))) {
                    for(int i=0; i < fieldlist.count(); i++) {
                        int found = 0;
                        if(fieldlist.at(i).contains(QString("[P%1[").arg(ebene))) {
                            i = i +1;
                            //ausgabe.append("</table:table-cell></table:table-row>");
                            for(int j=1; j < (fieldlist.count() *1000); j++) {
                                qDebug() << j << "von" << fieldlist.count() * 1000 << " moeglichen Datensaetze. Aktuelle Position in Ebene2: " << Position;
                                found = checkSedFile(QString("@%1_%2" + fieldlist.at(i)).arg(Position).arg(j), sedfile);
                                if(found > 0) {
                                    ausgabe.append(prepareTemplateEbene(Position, ebene, 0, j, doc, odffile, sedfile));
                                } else {
                                    break;
                                }
                            }
                        }
                    }

                }
            }

            if(ebene == 3 ) {
                test = test + ausgabe;
                if(ausgabe.contains(QString("]P%1]").arg(ebene))) {
                    for(int i=0; i < fieldlist.count(); i++) {
                        int found = 0;
                        if(fieldlist.at(i).contains(QString("[P%1[").arg(ebene))) {
                            i = i +1;
                            //ausgabe.append("</table:table-cell></table:table-row>");
                            found = checkSedFile(QString("@%1_%2_0" + fieldlist.at(i)).arg(Position).arg(0), sedfile);
                            if(found > 0) {
                                for(int k=1; k < (fieldlist.count() *1000); k++)
                                {
                                    int found1 = 0;
                                    qDebug() << "von" << fieldlist.count() * 1000 << " moeglichen Datensaetze";
                                    qDebug() << "found123: " << QString("@%1_%2_%3" + fieldlist.at(i)).arg(Position).arg(0).arg(k);
                                    found1 = checkSedFile(QString("@%1_%2_%3" + fieldlist.at(i)).arg(Position).arg(0).arg(k), sedfile);
                                    qDebug() << "found: " << found;
                                    if(found1 > 0) {
                                        ausgabe.append(prepareTemplateEbene(Position, ebene, k, 0, doc, odffile, sedfile));
                                        cnt++;
                                    } else {
                                        break;
                                    }
                                }
                            } else {
                                break;
                            }
                        }
                    }

                }
            }

            if(ausgabe.contains("]")) {
                ebene = ebene -1;
            }

            xmlout = xmlout + ausgabe;
        }

        if(ausgabe.contains("</table:table-row") && xmlout.contains("]P1]")) {
            //ausgabe.append("</table:table-cell></table:table-row>");
            counter = 0;
        }
    }
    file->close();
    return xmlout;
}

//-------------------------------------------------------------------------------------------------------------
// Method       : prepareTemplateEbene(int Position, int Ebene, int Counter, QDomDocument doc, QString odffile)
// Filename     : clienttcp.cpp
// Description  : Make a QString with the Positions Vars.
//
//-------------------------------------------------------------------------------------------------------------

QString Reportgen::prepareTemplateEbene(int Position, int Ebene, int Ebene3, int Counter, QDomDocument doc, QString odffile, QString sedfile)
{
    QFile *file = new QFile(QDir::tempPath() + "/" + QString("1-" + odffile));
    QList<QString> temp_fields = getTemplateVars(odffile);
    QString ausgabe;
    QString xmlout;
    QString xmlout1;
    QString behalten;
    int cnt = 0;
    int found = 0;

    /*if(!file->open(QIODevice::ReadOnly)) {
        qDebug() << "content1.xml konnte nicht geoeffnet werden" << "";
    }*/

    xmlout = doc.toString();
    //xmlout1.append("<table:table-row><table:table-cell>");

    QTextStream stream(&xmlout);
    stream.setCodec("UTF-8");

    while(!stream.atEnd()) {
        ausgabe = stream.readLine();

        if(ausgabe.contains(QString("[P%1[").arg(Ebene))) {
            cnt = cnt + 1;
        }
        if(ausgabe.contains("["))
        {
            found = found + 1;
        }

        if(found == 3)
        {
            behalten = behalten + ausgabe;
        }

        if(cnt  == 1) {
            if(ausgabe.contains("@")) {
                if(found == 1)
                {
                    ausgabe.replace("@", QString("@%1").arg(QString::number(Position)/*, QString::number(Counter)*/));
                } else if (found == 2)
                {
                    ausgabe.replace("@", QString("@%1_%2").arg(QString::number(Position)).arg(QString::number(Counter)));
                } else if (found == 3)
                {
                ausgabe.replace("@", QString("@%1_%2_%3").arg(QString::number(Position)).arg(QString::number(Counter)).arg(QString::number(Ebene3))/*, QString::number(Counter)*/);
                }
            }
            if(found == 3)
            {
                if(ausgabe.contains("]P3]"))
                {
                    if(Ebene3 == 0)
                    {
                        int found = 0;
                        for(int j=1; j < temp_fields.count(); j++)
                        {
                            qDebug() << QString("@%1_%2_%3").arg(QString::number(Position)).arg(QString::number(Counter)).arg(QString::number(j));
                            found = checkSedFile(QString("@%1_%2_%3").arg(QString::number(Position)).arg(QString::number(Counter)).arg(QString::number(j)), sedfile);
                            if(found > 0)
                            {
                                if(ausgabe.contains("]P3]"))
                                {
                                    behalten.replace("@", QString("@%1_%2_%3").arg(QString::number(Position)).arg(QString::number(Counter)).arg(QString::number(j)));
                                    xmlout1 = xmlout1 + behalten;
                                }
                            } else {
                                break;
                            }
                        }
                    }
                }
                //behalten.append("</table:table-row></table:table-cell>");
            }
            xmlout1 = xmlout1 + ausgabe;
        }

        if(ausgabe.contains(QString("]P%1]").arg(Ebene))) {
            cnt = cnt - 1;
        }

        if(ausgabe.contains("]"))
        {
            found = found - 1;
        }
    }

    //xmlout1.append(QString("</table:table-cell></table:table-row>"));

    return xmlout1;
}

//------------------------------------------------------------------------------
// Method       : getTemplateFooter(QString filename)
// Filename     : clienttcp.cpp
// Description  : returns the footer of each Template file.
//
//------------------------------------------------------------------------------

QString Reportgen::getTemplateFooter(QString filename)
{
    QFile *file = new QFile(QDir::tempPath() + "/" + filename);
    QDomDocument doc;
       doc.setContent(file);
       QString xml = doc.toString();
       QTextStream stream(&xml);
       stream.setCodec("UTF-8");
       QString footer;
       QString readLine;
       int cnt = 0;
       int start = 0;

       while(!stream.atEnd()) {
           readLine = stream.readLine();

           if(readLine.contains("]P1]")) {
               cnt = 1;
           }
           if(start > 0) {
               footer = footer + readLine.trimmed();
           }
           if(cnt > 0 && /*readLine.contains("<table:table") || */ readLine.contains("</table:table-row")) {
               start = 1;
           }
       }
       file->close();
       return footer;
}

//------------------------------------------------------------------------------
// Method       : readSedFile(QString sedfile)
// Filename     : clienttcp.cpp
// Description  : Read each Line from the SED File and save it as a QList.
//
//------------------------------------------------------------------------------

QList<QString> Reportgen::readSedFile(QString sedfile)
{
    QFile *file = new QFile(QDir::tempPath() + "/" + sedfile);
    QTextStream stream(file);
    stream.setCodec("UTF-8");
    QList<QString> temp_fields;


    if(!file->open(QIODevice::ReadOnly)) {
        qDebug() << "(readSed): Konnte SED Datei nicht lesen." << "";
    }

    while(!stream.atEnd()) {
        temp_fields << stream.readLine();
    }
    file->close();
    return temp_fields;
}

//------------------------------------------------------------------------------
// Method       : checkSedFile(QString fieldname, QString filename)
// Filename     : clienttcp.cpp
// Description  : read the SED File complete and return ne number of found
//
//------------------------------------------------------------------------------

int Reportgen::checkSedFile(QString fieldname, QString filename)
{
    QFile *file = new QFile (QDir::tempPath() + "/" + filename);

    QTextStream stream(file);
    stream.setCodec("UTF-8");
    QString ausgabe;
    QList<QString> suchliste;
    int cnt = 0;

    if(!file->open(QIODevice::ReadOnly)) {
        qDebug() << "cannot open file!!!" << "";
    }

    while(!stream.atEnd()) {
        ausgabe = stream.readAll();
        suchliste << ausgabe.split("/g");

        if(!suchliste.isEmpty()) {
            for(int i=0; i < suchliste.count(); i++) {
                if(suchliste.at(i).contains(fieldname)) {
                    cnt = cnt + 1;
                }
            }
        }
    }
    file->close();
    return cnt;
}

//------------------------------------------------------------------------------
// Method       : getTemplateVars(QString filename)
// Filename     : clienttcp.cpp
// Description  : Get the Vars from the Template file and save it as a QList.
//
//------------------------------------------------------------------------------

QList<QString> Reportgen::getTemplateVars(QString filename)
{

    QFile *file = new QFile(QDir::tempPath() + "/" + filename);

    if(file->open(QIODevice::ReadOnly)) {

        QDomDocument doc;
        doc.setContent(file);
        QString xmlout = doc.toString();
        QTextStream stream(&xmlout);
        stream.setCodec("UTF-8");
        QString ausgabe;
        QList<QString> t_fieldlist;
        int counter = 0;

        while(!stream.atEnd()) {
            ausgabe = stream.readLine();

            if(ausgabe.contains("[")) {
                counter = counter + 1;
            }

            if(ausgabe.contains("@") || ausgabe.contains("[") || ausgabe.contains("]")) {
                ausgabe.remove("<text:p text:style-name=\"Normal\">");
                ausgabe.remove("<text:p>");
                ausgabe.remove("</text:p>");
                ausgabe.remove("@");
                t_fieldlist << ausgabe.trimmed();
            }
        }
        file->close();
        return t_fieldlist;
    }

}

//------------------------------------------------------------------------------
// Method       : replaceTemplateVars(QString odffile, QString sedfile)
// Filename     : clienttcp.cpp
// Description  : replace te vars with the value from the SED File.
//
//------------------------------------------------------------------------------

bool Reportgen::replaceTemplateVars(QString odffile, QString sedfile, QFileInfo zielDatei)
{
    QList<QString> temp_fields = getTemplateVars(odffile + "/1-content.xml");
    QList<QString> sed_fields = readSedFile(sedfile);
    QString ausgabe;
    QString temp_var;
    QString sedLine;
    int cnt = 0;
    QFile *file = new QFile(QDir::tempPath() + "/" + odffile + "/1-content.xml");
    QFile *file1 = new QFile(QDir::tempPath() + "/" + odffile + "/content.xml");

    if(!file->open(QIODevice::ReadOnly)) {
        qDebug() << "cannot open content1.xml (ersetzung)";
        return false;
    }
    if(!file1->open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        qDebug() << "(replaceTemplateVars()): Konnte XML nicht zum schreiben oeffnen";
        return false;
    }

    if(sed_fields.isEmpty())
    {
        qDebug() << "Konnte SED Datei nicht lesen. ABBRUCH!";
        return false;
    }

    QTextStream stream1(file1);
    stream1.setCodec("UTF-8");
    //stream1.setCodec("ISO-8859-1");

    QDomDocument doc;
    doc.setContent(file);
    QString xml = doc.toString();

    QTextStream stream(&xml);
    stream.setCodec("UTF-8");

    while(!stream.atEnd()) {
        ausgabe = stream.readLine().trimmed();
        if(ausgabe.contains("@"))
        {
            temp_var = ausgabe;
            temp_var.replace("<text:p>", "");
            temp_var.replace("</text:p>", "");
            qDebug() << "Suche nach: " << temp_var;

            if(cnt < temp_fields.count())
            {
                qDebug() << temp_fields.at(cnt);
                for (int i=0; i < sed_fields.count(); i++)
                {
                    //qDebug() << "Verbleibende Datensaetze: " << sed_fields.count();
                    if(sed_fields.at(i).contains(temp_var))
                    {
                        qDebug() << "Es wurde gefunden: " << sed_fields.at(i);
                        sedLine = sed_fields.at(i).trimmed();
                        sedLine.replace(QString(temp_var + "/"), "");
                        ausgabe.replace(temp_var, sedLine);
                        sed_fields.removeAt(i);
                        break;
                    }
                }
            }
        } else if(ausgabe.contains("["))
        {
            ausgabe.replace("<text:p>[P1[</text:p>", "");
            ausgabe.replace("<text:p>[P2[</text:p>", "");
            ausgabe.replace("<text:p>[P3[</text:p>", "");
        } else if(ausgabe.contains("]"))
        {
            ausgabe.replace("<text:p>]P1]</text:p>", "");
            ausgabe.replace("<text:p>]P2]</text:p>", "");
            ausgabe.replace("<text:p>]P3]</text:p>", "");
        }
        //qDebug() << "ausgabe: " << ausgabe;
        stream1 << ausgabe.trimmed();
    }
    file1->close();
    file->close();

    //QFile *oldContent = new QFile(QDir::tempPath() + "/" + odffile + "/content.xml" );
    QString buffer;
    QFile *newContent = new QFile(QDir::tempPath() + "/" + odffile + "/1-content.xml" );

    if(newContent->exists())
    {
        if(!newContent->open(QIODevice::ReadOnly))
        {
            qDebug("konnte 1-content. nicht zum lesen oeffnen");
        }
        newContent->remove();
        //buffer = newContent->readAll().trimmed();
    }

    /*if(oldContent->exists()) {
        if(oldContent->open(QIODevice::WriteOnly | QIODevice::Truncate))
        {
            QTextStream stream(oldContent);
            stream << buffer.trimmed();
            newContent->remove();
        }

    }*/
    ZipUnzip *p_zip = new ZipUnzip();
    p_zip->zipFileArchiv(QDir::tempPath(), odffile, zielDatei);

    return true;
}

/*bool Reportgen::replaceTemplateVars(QString odffile, QString sedfile, QFileInfo zielDatei)
{
    QList <QString> temp_fields = getTemplateVars(odffile + "/1-content.xml");
    QFileInfo sedInfo =  sedfile;
    QString ausgabe;
    QString sedLine;
    QList<QString> templateVars;


    QFile *file = new QFile(QDir::tempPath() + "/" + sedInfo.baseName());
    if(!file->open(QIODevice::ReadOnly))
    {
        qDebug() << "(replaceTemplateVars()): Konnte SED Datei nicht zum lesen oeffnen";
        qDebug() << "Suche in: " << QDir::tempPath() + "/" + sedInfo.baseName();
        return false;
    }

    while(!file->atEnd())
    {
        sedLine = file->readLine().trimmed();
        if(sedLine.contains("@"))
        {
            templateVars = getTemplateVars(odffile + "/1-content.xml");
            if(templateVars.isEmpty())
            {
                qDebug() << "(replaceTemplateVars()): Keine Template Variablen gefunden. Abbruch!";
                break;
            }

            for( int i=0; i < templateVars.count(); i++)
            {
                qDebug() << "Suche nach Variable: " << QString("@" + templateVars.at(i));
                if(sedLine.contains("@" + templateVars.at(i)))
                {
                    sedLine.replace("s/", "");
                    sedLine.replace("@" + templateVars.at(i) + "/", "");
                    sedLine.replace("/g", "");

                    QFile *oldContent = new QFile(QDir::tempPath() + "/" + odffile + "/1-content.xml");
                    if(!oldContent->open(QIODevice::ReadOnly))
                    {
                        qDebug() << "(replaceTemplateVars()): 1-content.xml konnte nicht zum lesen geoeffnet werden.";
                    }
                        QTextStream oldStream(oldContent);
                        oldStream.setCodec("UTF-8");
                        while(!oldStream.atEnd())
                        {
                            ausgabe = oldStream.readAll().trimmed();
                        }

                        if(ausgabe.contains("@" + templateVars.at(i))) {
                            qDebug() << "Variable gefunden: " << QString("@" + templateVars.at(i));
                            if(!sedLine.trimmed().isEmpty())
                            {
                                ausgabe.replace("@" + templateVars.at(i), sedLine.trimmed());
                            } else {
                                ausgabe.replace("@" + templateVars.at(i), "");
                            }
                        }
                        if(ausgabe.contains("["))
                        {
                            ausgabe.replace("[P1[", "").trimmed();
                            ausgabe.replace("[P2[", "").trimmed();
                            ausgabe.replace("[P3[", "").trimmed();
                        } else if (ausgabe.contains("]"))
                        {
                            ausgabe.replace("]P1]", "").trimmed();
                            ausgabe.replace("]P2]", "").trimmed();
                            ausgabe.replace("]P3]", "").trimmed();
                        }

                        QFile *newContent = new QFile(QDir::tempPath() + "/" + odffile + "/1-content.xml");
                        if(!newContent->open(QIODevice::WriteOnly | QIODevice::Truncate))
                        {
                            qDebug() << "(replaceTemplateVars()): content.xml konnte nicht zum schreiben geoeffnet werden.";
                        }

                        QTextStream newContentstream(newContent);
                        newContentstream << ausgabe.trimmed();
                        newContent->close();
                        ausgabe.clear();
                        oldContent->close();
                }

            }
        }
    }

    file->close();

    QFile *oldContent = new QFile(QDir::tempPath() + "/" + odffile + "/content.xml" );
    QString buffer;
    QFile *newContent = new QFile(QDir::tempPath() + "/" + odffile + "/1-content.xml" );

    if(newContent->exists())
    {
        if(!newContent->open(QIODevice::ReadOnly))
        {
            qDebug("konnte 1-content. nicht zum lesen oeffnen");
        }

        buffer = newContent->readAll().trimmed();
    }

    if(oldContent->exists()) {
        if(oldContent->open(QIODevice::WriteOnly | QIODevice::Truncate))
        {
            QTextStream stream(oldContent);
            stream << buffer.trimmed();
            newContent->remove();
        }

    }
    ZipUnzip *p_zip = new ZipUnzip();
    p_zip->zipFileArchiv(QDir::tempPath(), odffile, zielDatei);

    return true;

}*/

/*bool Reportgen::replaceTemplateVars(QString odffile, QString sedfile)
{
    QList<QString> temp_fields = getTemplateVars(odffile + "/1-content.xml");
    QList<QString> sed_fields = readSedFile(sedfile);
    QString ausgabe;
    QString ersetzen;
    int start = 0;
    int ebene = 0;

    QFile *file = new QFile(QDir::tempPath() + "/" + odffile + "/1-content.xml");

    if(!file->open(QIODevice::ReadOnly)) {
        qDebug() << "cannot open content1.xml (ersetzung)";
    }

    QDomDocument doc;
    doc.setContent(file);
    QString xml = doc.toString();
    QString xmlout;

    QTextStream stream(&xml);
    stream.setCodec("UTF-8");

    while(!stream.atEnd()) {
        ausgabe = stream.readLine();


        if(ausgabe.contains("@")) {
            for(int i=0; i < temp_fields.count(); i++) {
                if(temp_fields.at(i).contains("[")) {
                    ebene = ebene + 1;
                }
                if (temp_fields.at(i).contains("]")) {
                    ebene = ebene - 1;
                }

                if(ausgabe.contains(temp_fields.at(i))) {
                    if(ebene == 0) {
                        for(int j=0; j < sed_fields.count(); j++) {
                            if(sed_fields.at(j).contains(temp_fields.at(i))) {
                                ersetzen = sed_fields.at(j);
                                ersetzen.replace(QString("s/@" + temp_fields.at(i) + "/"), " ");
                                ersetzen.replace(QString("/g"), "");
                                ausgabe.replace("@" + temp_fields.at(i), ersetzen.trimmed());
                            }
                        }
                    } else if (ebene == 1) {
                        for(int i=0; i < temp_fields.count(); i++) {
                            if(temp_fields.at(i).contains("]P1]")) {
                                start = 0;
                            }

                            if(ausgabe.contains(temp_fields.at(i)) && start == 1) {
                                for(int j=0; j < sed_fields.count(); j++) {
                                    if (sed_fields.at(j).contains(temp_fields.at(i))) {
                                        ersetzen = sed_fields.at(j);
                                        ersetzen.replace("�", "ss");
                                        ersetzen.replace(QString("s/@" + temp_fields.at(i) + "/"), " ");
                                        ersetzen.replace(QString("/g"), "");
                                        ausgabe.replace(QString("@" + temp_fields.at(i)), p_protocol->filterUmlauts(ersetzen.trimmed());//);
                                    }
                                }
                            }

                            if(temp_fields.at(i).contains("[P1[")) {
                                start = 1;
                            }
                        }
                    }
                }
            }
        }
        xmlout = xmlout + ausgabe;

    }

    QFile *file1 = new QFile(QDir::tempPath() + "/" + odffile + "/1-content.xml");

    if(!file1->open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qDebug() << "konnte nicht zum schreiben oeffnen (ersetzen)" << "";
    }

    QTextStream stream1(file1);

    stream1 << xmlout;

    file1->close();
    file->close();

    QFile *oldContent = new QFile(QDir::tempPath() + "/" + odffile + "/content.xml" );
    QString buffer;
    QFile *newContent = new QFile(QDir::tempPath() + "/" + odffile + "/1-content.xml" );

    if(newContent->exists())
    {
        if(!newContent->open(QIODevice::ReadOnly))
        {
            qDebug("konnte 1-content. nicht zum lesen oeffnen");
        }

        buffer = newContent->readAll();
    }

    if(oldContent->exists()) {
        if(oldContent->open(QIODevice::WriteOnly | QIODevice::Truncate))
        {
            QTextStream stream(oldContent);
            stream << buffer;
            newContent->remove();
        }

    }

    //QFile::rename( QString( QDir::tempPath() + "/" + odffile + "/1-content.xml" ) , QString( QDir::tempPath() + "/" + odffile + "/content.xml" ) );

    ZipUnzip *p_zip = new ZipUnzip();
    p_zip->zipFileArchiv(QDir::tempPath(), odffile);

    return true;

}*/

bool Reportgen::createInfoFile(QFileInfo odffile, QFileInfo zieldatei)
{
    qDebug() << "erstellen der Info Datei" << odffile.fileName();

    ZipUnzip *p_zipunzip = new ZipUnzip();

    if(p_zipunzip->unzipArchiv(QDir::tempPath(), QString(odffile.fileName())) == FALSE)
    {
        qDebug() << "Es ist ein Fehler beim entpacken aufgetreten" << "";
        return false;
    }
    QFile *file = new QFile( QDir::tempPath() + "/"  + odffile.baseName() + "/content.xml");

    if( !file->open( QIODevice::ReadOnly ) )
    {
        qDebug() << "konnte datei nicht oeffnen" << "";
        //qWarning(QString("Konnte Datei nicht zum lesen oeffnen: %1").arg(templateFile).toLatin1());
        return false;
    }

    QDomDocument doc1;
    doc1.setContent(file);
    QString xml = doc1.toString();
    QString ausgabe;
    int counter = 0;
    QList<QString> fields;

    QTextStream stream(&xml);

    while( !stream.atEnd() )
    {
        ausgabe = stream.readLine();
        if( ausgabe.contains("[") )
        {
            counter = counter + 1;
        }

        if(ausgabe.contains("]"))
        {
            counter = counter - 1;
        }

        if( ausgabe.contains("@") )
        {
            ausgabe.replace( "<text:p>", "" );
            ausgabe.replace( "</text:p>", "" );
            ausgabe.replace( "@", QString("%1:" ).arg( counter ) );
            fields << ausgabe;
        }
    }

    QFile *file1 = new QFile( QDir::tempPath() + "/" + zieldatei.fileName() );

    if(!file1->open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        qDebug() << "konnte template to sed nicht schreiben" << "";
        return false;
    }

    QTextStream stream1( file1 );
    stream1 << QString( "EBENEN:" );

    switch(counter)
    {
    case 1:
        stream1 << QString( "0" ) << QString( "%1" ).arg( counter ) << "\n";
        break;
    case 2:
        stream1 << QString( "0" ) << QString ( "1" ) << QString( "%1" ).arg( counter ) << "\n";
        break;
    case 3:
        stream1 << QString( "0" ) << QString ( "1" ) << QString ( "2" ) << QString( "%1" ).arg( counter ) << "\n";
        break;

    }

    for(int i=0; i < fields.count(); i++)
    {
        stream1 << fields.at( i ).trimmed() + "\n";
    }
    return true;
}

/*void ProtocolHandler::replaceTemplateVars(QString odffile, QString sedfile)
{
    QList<QString> fieldlist = getTemplateVars(odffile);
    QString ausgabe;

    QFile *file = new QFile(QDir::tempPath() + "/1-" + odffile);

    if(!file->open(QIODevice::ReadOnly)) {
        qDebug() << "cannot open content1.xml (ersetzung)";
    }

    QDomDocument doc;
    doc.setContent(file);
    QString xml = doc.toString();

    QTextStream stream(&xml);
    stream.setCodec("UTF-8");

    while(!stream.atEnd()) {
        ausgabe = ausgabe + stream.readLine();

        if(ausgabe.contains("@")) {
            for(int i=0; i<fieldlist.count(); i++) {
                if(ausgabe.contains(fieldlist.at(i))) {
                    if(ausgabe.contains("[")) {
                        break;
                    }
                    if(checkSedFile(fieldlist.at(i), sedfile)) {
                        QFile *seddatei = new QFile(QDir::tempPath() + "/" + sedfile);
                        QString ersetze;
                        if(!seddatei->open(QIODevice::ReadOnly)) {
                            qDebug() << "konnte SED Datei nicht zum lesen oeffnen (ersetzen)" << "";
                        }

                        while(!seddatei->atEnd()) {
                            ersetze = seddatei->readLine();

                            if(ersetze.contains(fieldlist.at(i))) {
                                ersetze.replace("s/@" + fieldlist.at(i) + "/", " ");
                                ersetze.replace("/g", "");
                                ausgabe.replace("@" + fieldlist.at(i), ersetze.trimmed());
                            }
                        }

                        seddatei->close();
                    } else {
                        ausgabe.replace("@" + fieldlist.at(i), " ");
                    }
                }
            }
        }
    }

    file->close();

    QFile *file1 = new QFile(QDir::tempPath() + "/" + QString("1-" + odffile));

    if(!file1->open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qDebug() << "konnte nicht zum schreiben oeffnen (ersetzen)" << "";
    }

    QTextStream stream1(file1);

    stream1 << ausgabe;

    file1->close();



}*/

