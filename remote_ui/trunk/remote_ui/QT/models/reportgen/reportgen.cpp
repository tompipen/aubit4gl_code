#include <QDomDocument>
#include "models/reportgen/reportgen.h"
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
    readSedFile(sedfile);

    ZipUnzip *p_zipunzip = new ZipUnzip();

    if(p_zipunzip->unzipArchiv(QDir::tempPath(), QString(odffile)) == FALSE)
    {
        qDebug() << "Es ist ein Fehler beim entpacken aufgetreten" << "";
        return false;
    }

   QString content;
   QFileInfo oldFileName = odffile;
   QString fileBaseName = oldFileName.baseName();

   int wiederholen = 0;
   int ebene1 = 1;
   int ebene2 = 0;
   int gefunden = 0;

   checkMetaFile(fileBaseName);

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
   xmlsave << getTemplateHeader( fileBaseName + "/content.xml" ); //<< getTemplatePosition( fileBaseName + "/content.xml" ).toUtf8();
   getTemplateVars(fileBaseName + "/content.xml");

   for(int i=0; i < temp_fields.count(); i++)
   {
       if(temp_fields.at(i).contains("[P1["))
       {
           gefunden = gefunden + 1;
           qDebug() << "gefunden: " << gefunden;
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

   for(int i=1; i < temp_fields.count(); i++)
   {
       if(temp_fields.at(i).contains("[")) {
           i = i + 1;
           for(int k=0; k < sed_fields.count(); k++)
           {
               qDebug() << "Suche in SED nach Anfang: " << k << "von" << sed_fields.count();
               if(sed_fields.at(k).contains(QString("%1"+ temp_fields.at(i)).arg(ebene1)))
               {
                   ebene1++;
               }
           }
           break;
       }
   }

   for(int i=1; i < temp_fields.count(); i++)
   {
       if(temp_fields.at(i).contains("[P2["))
       {
           i = i + 1;
           for(int k=0; k < sed_fields.count(); k++)
           {
               if(sed_fields.at(k).contains(QString("%1_0" + temp_fields.at(i)).arg(ebene2)))
               {
                   ebene2++;
               }

           }
       }
   }

   if(ebene1 <= ebene2)
   {
       wiederholen = wiederholen + ebene2;
   } else {
       wiederholen = wiederholen + ebene1;
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

   for(int i=0; i < gefunden; i++) {
   content.append(getTemplatePosition(i+1, fileBaseName + "/content.xml"));//.toUtf8());
       for(int j=1; j < wiederholen; j++) {
           qDebug() << "ergaenze Ebene";
           qDebug() << j << "von" << wiederholen;
           content.append(prepareTemplateContent(i+1, j, oldFileName.baseName() + "/content.xml", sedfile));
           xmlsave << content;
           content.clear();
       }
       xmlsave << getTemplateFooter( i+1, fileBaseName + "/content.xml" );
   }

   xmlsave << "</office:spreadsheet></office:body></office:document-content>";
   //xmlsave << getTemplateFooter( fileBaseName + "/content.xml" );
   file->close();
   replaceEbene(file, fileBaseName);

   replaceTemplateVars(fileBaseName, sedfile, zielDatei);

   return true;

}

bool Reportgen::checkMetaFile(QString odffile)
{
    QFile *file = new QFile(QDir::tempPath() + "/" + odffile + "/meta.xml");

    if(!file->open(QIODevice::ReadOnly))
    {
        qDebug() << "(checkMetaFile()): Konnte meta.xml nicht zum lesen oeffnen";
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
    xml = doc.toString();
    QTextStream stream1(&xml);
    stream1.setCodec("UTF-8");
    QTextStream xmlsave1(newFile);
    xmlsave1.setCodec("UTF-8");
    QString xmlsave;
    QString ausgabe;
    QString behalten;
    QString var;

    int merken = 0;
    int start = 0;
    int found = 0;
    int tableFound = 0;
    int tableEnd = 0;

    xmlsave1 << getTemplateHeader(odffile + "/content.xml");
    while(!stream1.atEnd())
    {
        ausgabe = stream1.readLine();

        if(start == 1)
        {
            if(ausgabe.contains("[P2[") || ausgabe.contains("]P1]"))
            {
                found = 0;
            }
        }

        if(found > 0 && tableFound < 2  && ausgabe.contains("@"))
        {

            var = ausgabe.trimmed();
            var.remove("<text:p>");
            var.remove("</text:p>");
            var.replace(0, 2, "");
            if(!chartVar.contains(var))
            {
                chartVar << var;

            }
        }

        if(ausgabe.contains("<table:table table:name"))
        {
            xmlsave1 <<getTemplatePosition(tableFound+1, odffile + "/content.xml");
            tableFound = tableFound + 1;
        }

        if(merken == 0 && ausgabe.contains("</table:table>"))
        {
            xmlsave1 << getTemplateFooter(tableEnd+1, odffile + "/content.xml");
            tableEnd = tableEnd + 1;
        }

        if(ausgabe.contains("[P1["))
        {
            start = 1;
            found = 1;
        }
        if(ausgabe.contains("]P1]"))
        {
            start = 0;
        }
        if(ausgabe.contains("<table:table-row"))
        {
            merken = 1;
        }
        if(merken == 1 && start == 1)
        {
                xmlsave = xmlsave + ausgabe;
        }
        if(ausgabe.contains("</table:table-row"))
        {
            merken = 0;
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
    temp_file->close();
    temp_file->remove();
    newFile->close();
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

        if(header.contains("<office:spreadsheet>")) {
            cnt = 1;
        }
        /*if(header.contains("<office:body>")) {
            //header.append("</table:table-row>");
            cnt = 1;
        }*/

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

QString Reportgen::getTemplatePosition(int Table, QString odffile)
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
    int foundTable = 0;

    while(!stream.atEnd()) {
        ausgabe = stream.readLine();

        if(ausgabe.contains("<table:table table:name"))
        {
            foundTable = foundTable + 1;
            stop = 0;
        }

        if(ausgabe.contains("[")) {
            stop = 1;
        }

        if(foundTable == Table)
        {
            if(stop  < 1)
            {
            behalten = behalten + ausgabe;
            }
        }

        /*if(ausgabe.contains("<office:body>")) {
            cnt = 1;

        }*/

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

QString Reportgen::prepareTemplateContent(int Table, int Position, QString odffile, QString sedfile)
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
    xmlout.append("<table:table-row><table:table-cell>");

    int cnt = 0;
    int counter = 0;
    int ebene = 0;
    int tableFound = 0;

    while(!stream.atEnd()) {
        ausgabe = stream.readLine().trimmed();


        if(ausgabe.contains("<table:table table:name"))
        {
            tableFound = tableFound + 1;
            counter = 0;
            //qDebug() << "tableFound: " << tableFound;
        }

        if(ausgabe.contains("[P1[")) {
        //if(ausgabe.contains("<table:table-row")) {
            counter = counter + 1;
        }

        if(counter > 0 && tableFound == Table) {

            if(ausgabe.contains("[")) {
                ebene = ebene + 1;
            }
            //qDebug() << ebene;
            if(ausgabe.contains("@") && ebene == 1) {
                for(int i=0; i < temp_fields.count(); i++) {
                    if(ausgabe.contains(temp_fields.at(i))) {
                        ausgabe.replace("@" + temp_fields.at(i), QString("@%1" + temp_fields.at(i)).arg(QString::number(Position)));
                    }
                }
            }

            if(ausgabe.contains("@") && ebene == 2) {
                for(int i=0; i < temp_fields.count(); i++) {
                    if(ausgabe.contains("@" + temp_fields.at(i))) {
                        ausgabe.replace("@" + temp_fields.at(i), QString("@%1_1" + temp_fields.at(i)).arg(QString::number(Position)));
                    }
                }
            }

            if(ausgabe.contains("@") && ebene == 3) {
                for(int i=0; i < temp_fields.count(); i++) {
                    if(ausgabe.contains("@" + temp_fields.at(i))) {
                        ausgabe.replace("@" + temp_fields.at(i), QString("@%1_1_1" + temp_fields.at(i)).arg(QString::number(Position)));
                    }
                }
            }

            if(ebene == 2) {
                test = test + ausgabe;
                if(ausgabe.contains(QString("]P%1]").arg(ebene))) {
                    for(int i=1; i < temp_fields.count(); i++) {
                        int found = 0;
                        if(temp_fields.at(i).contains(QString("[P%1[").arg(ebene))) {
                            i = i +1;
                            //ausgabe.append("</table:table-cell></table:table-row>");
                            for(int j=2; j < (temp_fields.count() *1000); j++) {
                                //qDebug() << j << "von" << temp_fields.count() * 1000 << " moeglichen Datensaetze. Aktuelle Position in Ebene2: " << Position;
                                found = checkSedFile(QString("@%1_%2" + temp_fields.at(i)).arg(Position).arg(j), sedfile);
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
                    for(int i=1; i < temp_fields.count(); i++) {
                        int found = 0;
                        if(temp_fields.at(i).contains(QString("[P%1[").arg(ebene))) {
                            i = i +1;
                            //ausgabe.append("</table:table-cell></table:table-row>");
                            found = checkSedFile(QString("@%1_%2_1" + temp_fields.at(i)).arg(Position).arg(1), sedfile);
                            if(found > 0) {
                                for(int k=2; k < (temp_fields.count() *1000); k++)
                                {
                                    int found1 = 0;
                                    qDebug() << "von" << temp_fields.count() * 1000 << " moeglichen Datensaetze";
                                    qDebug() << "found123: " << QString("@%1_%2_%3" + temp_fields.at(i)).arg(Position).arg(1).arg(k);
                                    found1 = checkSedFile(QString("@%1_%2_%3" + temp_fields.at(i)).arg(Position).arg(1).arg(k), sedfile);
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
            counter = counter - 1;
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
    QString ausgabe;
    QString xmlout;
    QString xmlout1;
    QString behalten;
    QString ersetzeVar;
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
                                    ersetzeVar = behalten;
                                    ersetzeVar.replace(QString("@"), QString("@%1_%2_%3").arg(QString::number(Position)).arg(QString::number(Counter)).arg(QString::number(j)));
                                    xmlout1 = xmlout1 + ersetzeVar;
                                    //behalten.clear();
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

bool Reportgen::replaceMetaFile(QString odffile)
{
    QFile *file = new QFile(QDir::tempPath() + "/" + odffile + "/meta.xml");

    if(!file->open(QIODevice::ReadOnly))
    {
        qDebug() << "(replaceMetaFile(): Konnte META.xml nicht lesen.";
        return false;
    }

    QDomDocument doc;
    doc.setContent(file);
    QString xml = doc.toString();
    QString sedLine;
    QString ausgabe;
    QString outString;

    QTextStream inStream(&xml);

    while(!inStream.atEnd())
    {
        ausgabe = inStream.readLine();

        if(ausgabe.contains("@"))
        {
            for(int i=0; i < metaVar.count(); i++)
            {
                if(ausgabe.contains(metaVar.at(i)))
                {
                    for(int j=0; j < sed_fields.count(); j++)
                    {
                        if(sed_fields.at(j).contains(metaVar.at(i)))
                        {
                            sedLine = sed_fields.at(j);
                            qDebug() << "metaVar: " << metaVar.at(i);
                            sedLine.replace(metaVar.at(i) + "/", "");
                            ausgabe.replace(metaVar.at(i), sedLine);
                            qDebug() << "sedLine: " << sedLine;
                            //break;

                        }
                    }
                }
            }
        }
        outString = outString + ausgabe;
    }

    file->close();

    QFile *outFile = new QFile(QDir::tempPath() + "/" + odffile + "/meta.xml");
    if(!outFile->open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        qDebug() << "(replaceMetaFile()): Konnte meta.xml nicht zum schreiben �ffnen";
        return false;
    }

    QTextStream outStream(outFile);

    outStream << outString;
    outString.clear();

    outFile->close();

    return true;
}

//------------------------------------------------------------------------------
// Method       : getTemplateFooter(QString filename)
// Filename     : clienttcp.cpp
// Description  : returns the footer of each Template file.
//
//------------------------------------------------------------------------------

QString Reportgen::getTemplateFooter(int Table, QString filename)
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
       int tableFound = 0;

       while(!stream.atEnd()) {
           readLine = stream.readLine();
           if(readLine.contains("<table:table table:name"))
           {
                tableFound = tableFound + 1;
           }
           if(tableFound == Table)
           {
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

bool Reportgen::readSedFile(QString sedfile)
{
    QFile *file = new QFile(QDir::tempPath() + "/" + sedfile);
    QTextStream stream(file);
    stream.setCodec("UTF-8");


    if(!file->open(QIODevice::ReadOnly)) {
        qDebug() << "(readSed): Konnte SED Datei nicht lesen." << "";
    }

    while(!stream.atEnd()) {
        sed_fields << stream.readLine();
    }
    file->close();
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

bool Reportgen::getTemplateVars(QString filename)
{

    QFile *file = new QFile(QDir::tempPath() + "/" + filename);

    if(file->open(QIODevice::ReadOnly)) {

        QDomDocument doc;
        doc.setContent(file);
        QString xmlout = doc.toString();
        QTextStream stream(&xmlout);
        stream.setCodec("UTF-8");
        QString ausgabe;
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
                temp_fields << ausgabe.trimmed();
            }
        }
        file->close();
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
    temp_fields.clear();
    getTemplateVars(odffile + "/1-content.xml");
    QString ausgabe;
    QString temp_var;
    QString sedLine;
    int cnt = 0;
    int makeChart = 0;
    int wiederholen = 0;
    int diag_state = 0;
    QFile *file = new QFile(QDir::tempPath() + "/" + odffile + "/1-content.xml");
    QFile *file1 = new QFile(QDir::tempPath() + "/" + odffile + "/content.xml");

    //String diag_pfad = "/home/da/";
    //Kompilierbar gemacht behebt einer aus den Repgen teeam bitte den fehler
    QString diag_bild = "DIAG_BAR.png";

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
            //qDebug() << "Suche nach: " << temp_var;

            if(temp_var.contains("@DIAG_"))
            {
                qDebug() << temp_var;
                if(temp_var == "@DIAG_BAR")
                {
                    diag_state = 1;
                } else if(temp_var == "@DIAG_PIE")
                {
                    diag_state = 2;
                }
                qDebug() << "diag_state" << diag_state;
                emit createChart(temp_var);
                ausgabe.replace(QString("<text:p>" + temp_var + "</text:p>"), QString("<draw:frame table:end-cell-address=\"Tabelle1.E20\" draw:text-style-name=\"P1\" svg:width=\"16.93cm\" svg:x=\"0.081cm\" draw:style-name=\"gr1\" svg:y=\"0.016cm\" draw:name=\"Graphics 1\" table:end-x=\"2.181cm\" table:end-y=\"0.419cm\" svg:height=\"12.70cm\" draw:z-index=\"0\"><draw:image xlink:type=\"simple\" xlink:show=\"embed\" xlink:href=\"Pictures/" + diag_bild + "\" xlink:actuate=\"onLoad\"> <text:p/></draw:image></draw:frame>"));

                makeChart = 1;
            }

            if(cnt < temp_fields.count())
            {
                for (int i=0; i < sed_fields.count(); i++)
                {
                    //qDebug() << "Verbleibende Datensaetze: " << sed_fields.count();
                    if(sed_fields.at(i).contains(temp_var))
                    {
                        qDebug() << "Es wurde gefunden: " << sed_fields.at(i);
                        sedLine = sed_fields.at(i).trimmed();
                        sedLine.replace(QString(temp_var + "/"), "");
                        ausgabe.replace(temp_var, sedLine);
                        if(!temp_var.endsWith("1"))
                        {
                           sed_fields.removeAt(i);
                        } else {
                            if(!chartVar.isEmpty())
                            {
                                for(int j=0; j < chartVar.count(); j++)
                                {
                                    if(temp_var.contains(chartVar.at(j)))
                                    {
                                        if(j == 0)
                                        {
                                            if(!chartValues1.contains(sedLine))
                                            {
                                                chartValues1 << sedLine;
                                            }
                                        } else if(j == 1)
                                        {
                                                    chartValues2 << sedLine;
                                        }
                                    }
                                }
                            }
                        }
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

    //if(chartValues1.count() == chartValues2.count())
    //{


    switch(diag_state)
    {
        case 1:
            if(chartValues1.count() > chartValues2.count())
            {
                wiederholen = chartValues2.count();
            } else if(chartValues2.count() > chartValues1.count())
            {
                wiederholen = chartValues1.count();
            }

                for(int i=0; i < wiederholen; i++)
                {
                //qDebug() << "Werte fuer KD Charts: " << chartValues1.at(i) << ","<< chartValues2.at(i);
                    //qDebug() << "chartValues1.at(i)" << chartValues1.at(i) << " " <<  chartValues2.at(i);
                    if(!chartValues1.at(i).isNull() && !chartValues2.at(i).isNull())
                    {
                        emit addChartValue(chartValues1.at(i), chartValues2.at(i));
                    }
                }
          break;
        case 2:
        QVector< QVariant > wertList;
        QVector< QVariant > nameList;
        for(int i=0; i < chartValues2.count(); i++)
        {
            if(!chartValues2.at(i).isEmpty())
            {
                wertList.append(chartValues2.at(i));
            }

        }
        for(int i=0; i < chartValues1.count(); i++)
        {
            if(!chartValues1.at(i).isEmpty())
            {
                nameList.append(chartValues1.at(i));
            }
        }
        addChartValue(nameList, wertList);
        break;
    }

    if(makeChart == 1)
    {
        emit displayChart(diag_bild);
        sleep(2);
        if(QFile::exists(QString(QDir::tempPath() + "/" + diag_bild)));
        {
            if(QFile::copy(QString(QDir::tempPath() + "/" + diag_bild), QString( QDir::tempPath() + "/" + odffile + "/Pictures/" + diag_bild )))
            {
                QFile *manifestfile = new QFile(QDir::tempPath() + "/" + odffile + "/META-INF/manifest.xml");
                if(!manifestfile->open(QIODevice::ReadWrite))
                {
                    qDebug() << "Manifest nicht geoeffnet zum lesen";
                }
                QDomDocument doc;
                doc.setContent(manifestfile);
                QString xml = doc.toString();
                QTextStream manistream(&xml);
                QString manifestText;
                QString save;
                while(!manistream.atEnd())
                {
                    manifestText = manistream.readLine();

                    if(manifestText.contains("image/jpeg"))
                    {
                        manifestText = manifestText.append("<manifest:file-entry manifest:media-type=\"image/jpeg\" manifest:full-path=\"Pictures/" + diag_bild + "\"/>");
                    }
                    save = save + manifestText;
                }
                QFile *manisave = new QFile(QDir::tempPath() + "/" + odffile + "/META-INF/manifest.xml");
                if(!manisave->open(QIODevice::WriteOnly | QIODevice::Truncate))
                {
                    qDebug() << "Manifest konnte nicht zum schreiben geoeffnet werden";
                }
                manifestfile->close();
                QTextStream maniWritter(manisave);
                maniWritter << save;
                manisave->close();
            }
        }
    }


    replaceMetaFile(odffile);
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

    checkMetaFile(odffile.baseName());

    QDomDocument doc1;
    doc1.setContent(file);
    QString xml = doc1.toString();
    QString ausgabe;
    int counter = 0;
    int ebenen = 0;
    int found = 0;
    QList<QString> fields;

    QTextStream stream(&xml);

    while( !stream.atEnd() )
    {
        ausgabe = stream.readLine();

        if( ausgabe.contains("[P1["))
        {
            ebenen = 1;
        }

        if( ausgabe.contains("[P2["))
        {
            ebenen = 2;
        }

        if( ausgabe.contains("[P3["))
        {
            ebenen = 3;
        }

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
            ausgabe.replace( "@", QString("%1:" ).arg( counter ) ).trimmed();
            if(!fields.isEmpty())
            {
                for(int i=0; i < fields.count(); i++)
                {
                    if(fields.at(i).contains(ausgabe))
                    {
                        found = found + 1;
                    }
                }
                if(found == 0)
                {
                    fields << ausgabe;
                }
                found = 0;
            } else {
                fields << ausgabe;
            }
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

    switch(ebenen)
    {
    case 1:
        stream1 << QString( "0" ) << QString( "%1" ).arg( ebenen ) << "\n";
        break;
    case 2:
        stream1 << QString( "0" ) << QString ( "1" ) << QString( "%1" ).arg( ebenen ) << "\n";
        break;
    case 3:
        stream1 << QString( "0" ) << QString ( "1" ) << QString ( "2" ) << QString( "%1" ).arg( ebenen ) << "\n";
        break;

    }

    qSort(fields);

    if(!metaVar.isEmpty())
    {
        for(int i=0; i < metaVar.count(); i++)
        {
            stream1 << "0:" + QString(metaVar.at(i)).replace("@","") + "\n";
        }
    }
    for(int i=0; i < fields.count(); i++)
    {
        stream1 << fields.at( i ).trimmed() + "\n";
    }
    return true;
}
