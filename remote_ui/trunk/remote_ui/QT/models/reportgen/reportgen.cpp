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
    //emit createRepgenProgressBar();
    readSedFile(sedfile);

    ZipUnzip *p_zipunzip = new ZipUnzip();
    QFileInfo odfFileInfo = odffile;

    if(!p_zipunzip->unzipArchiv(QDir::tempPath(), odffile, QString(QDir::tempPath() + "/" + odfFileInfo.baseName())))
    {
        qDebug() << "Es ist ein Fehler beim entpacken aufgetreten" << "";
        return false;
    }

   QString content;
   QFileInfo oldFileName = odffile;
   QString fileBaseName = oldFileName.baseName();

   int wiederholen = 0;
   int ebene1 = 1;
   int ebene2 = 1;
   int gefunden = 0;
   int varCount = 0;
   int anfang = 1;

   checkMetaFile(fileBaseName);

   QFile *file = new QFile(QDir::tempPath() + "/" + fileBaseName + "/1-content.xml");

   if(!file->open(QIODevice::WriteOnly | QIODevice::Truncate)) {
       qDebug() << "1-content.xml Konnte nicht zum schreiben erstellt werden. Permission Problem?";
       return 404;
   }

   QTextStream xmlsave(file);
   xmlsave.setCodec("UTF-8");
   xmlsave << getTemplateHeader( fileBaseName + "/content.xml", oldFileName.completeSuffix() ); //<< getTemplatePosition( fileBaseName + "/content.xml" ).toUtf8();
   getTemplateVars(fileBaseName + "/content.xml");

   for(int i=0; i < temp_fields.count(); i++)
   {
       if(temp_fields.at(i).contains("[P1["))
       {
           gefunden = gefunden + 1;
           qDebug() << "gefunden: " << gefunden;
       }
   }
   //Ueberpruefen der SED Datei wie viele eintraege der ersten Variable von der 1ten Ebene vorhanden ist.

  for(int j=0; j < sed_fields.count(); j++)
  {
          if(sed_fields.at(j).contains(QString("@%1").arg(anfang)))
          {
              anfang++;
              varCount = varCount + 1;
          }
       qDebug() << "varCount: " << varCount;
  }

   for(int i=1; i < temp_fields.count(); i++)
   {
       if(temp_fields.at(i).contains("[")) {
           i = i + 1;
           for(int k=0; k < sed_fields.count(); k++)
           {
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
               if(sed_fields.at(k).contains(QString("%1_1" + temp_fields.at(i)).arg(ebene2)))
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

   for(int i=0; i < gefunden; i++) {
       if(oldFileName.completeSuffix() == "ods")
       {
           content.append(getTemplatePosition(i+1, fileBaseName + "/content.xml"));//.toUtf8());
           for(int j=1; j < varCount+1; j++) {
               qDebug() << "ergaenze Ebene";
               qDebug() << j << "von" << varCount;
               //emit setRepgenText(QString("Ergaenze Template %1 von %2").arg(j).arg(varCount));
               content.append(prepareTemplateContent(i+1, j, oldFileName.baseName() + "/content.xml", sedfile));
               xmlsave << content;
               content.clear();
           }
           xmlsave << getTemplateFooter( i+1, fileBaseName + "/content.xml" );
       } else if(oldFileName.completeSuffix() == "odt"){
           content.append(getTemplatePosition( fileBaseName + "/content.xml" ));//.toUtf8());
           for(int j=1; j < varCount+1; j++) {
               qDebug() << "ergaenze Ebene";
               qDebug() << j << "von" << varCount;
               content.append(prepareTemplateContentOdt(i+1, j, oldFileName.baseName() + "/content.xml", sedfile));
               xmlsave << content;
               content.clear();
           }
       }
   }

   if(oldFileName.completeSuffix() == "ods")
   {
       xmlsave <<  "</office:spreadsheet>";
   } else {
       xmlsave << "</office:text>";
   }
   xmlsave << "</office:body></office:document-content>";
   file->close();
   if(oldFileName.completeSuffix() == "ods")
   {
       replaceEbene(file, fileBaseName);
   }

   if(varCount > 0)
   {
       replaceTemplateVars(fileBaseName, sedfile, zielDatei);
   } else {
       replaceTemplateWithoutPosition(fileBaseName, sedfile, zielDatei);
   }

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
    xmlsave1 << "</office:spreadsheet></office:body></office:document-content>";
    temp_file->close();
    temp_file->remove();
    newFile->close();
    return true;
}
QString Reportgen::getTemplateHeader(QString filename, QString endung)
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
    qDebug() << "endung: " << endung;
    while(!stream.atEnd()) {
        header = header + stream.readLine().trimmed();
        if(endung == "ods")
        {
            if(header.contains("<office:spreadsheet>")) {
                cnt = 1;
            }
        } else {
            if(header.contains("<office:body>")) {
                cnt = 1;
            }
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

QString Reportgen::getTemplatePosition(QString odffile)
{
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

    while(!stream.atEnd()) {
        ausgabe = stream.readLine();

        if(ausgabe.contains("[P1["))
        {
            cnt = 0;
            return behalten;
        }

        if(cnt == 1)
        {
            behalten = behalten + ausgabe;
        }

        if(ausgabe.contains("<office:body>"))
        {
            cnt = 1;
        }
    }

    file->close();

    return behalten;
}
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
                        int found = checkSedFile(QString("@%1" + temp_fields.at(i)).arg(QString::number(Position)), sedfile);
                            if(found > 0)
                            {
                                ausgabe.replace("@" + temp_fields.at(i), QString("@%1" + temp_fields.at(i)).arg(QString::number(Position)));
                            } else {
                                ausgabe.remove("@" + temp_fields.at(i));
                            }
                        //ausgabe.replace("@" + temp_fields.at(i), QString("@%1" + temp_fields.at(i)).arg(QString::number(Position)));
                    }
                }
            }

            if(ausgabe.contains("@") && ebene == 2) {
                for(int i=0; i < temp_fields.count(); i++) {
                    if(ausgabe.contains("@" + temp_fields.at(i))) {
                        int found = checkSedFile(QString("@%1_1" + temp_fields.at(i)).arg(QString::number(Position)), sedfile);
                        if(found > 0)
                        {
                            ausgabe.replace("@" + temp_fields.at(i), QString("@%1_1" + temp_fields.at(i)).arg(QString::number(Position)));
                        } else {
                            ausgabe.remove("@" + temp_fields.at(i));
                        }
                    }
                }
            }

            if(ausgabe.contains("@") && ebene == 3) {
                for(int i=0; i < temp_fields.count(); i++) {
                    if(ausgabe.contains("@" + temp_fields.at(i))) {
                        int found = checkSedFile(QString("@%1_1_1" + temp_fields.at(i)).arg(QString::number(Position)), sedfile);
                        if(found > 0)
                        {
                            ausgabe.replace("@" + temp_fields.at(i), QString("@%1_1_1" + temp_fields.at(i)).arg(QString::number(Position)));
                        } else {
                            ausgabe.remove("@" + temp_fields.at(i));
                        }
                    }
                }
            }
            if(ausgabe.contains("@") && ebene == 4) {
                for(int i=0; i < temp_fields.count(); i++) {
                    if(ausgabe.contains("@" + temp_fields.at(i))) {
                        int found = checkSedFile(QString("@%1_1_1_1" + temp_fields.at(i)).arg(QString::number(Position)), sedfile);
                        if(found > 0)
                        {
                            ausgabe.replace("@" + temp_fields.at(i), QString("@%1_1_1_1" + temp_fields.at(i)).arg(QString::number(Position)));
                        } else {
                            ausgabe.remove("@" + temp_fields.at(i));
                        }
                    }
                }
            }
            if(ausgabe.contains("@") && ebene == 5) {
                for(int i=0; i < temp_fields.count(); i++) {
                    if(ausgabe.contains("@" + temp_fields.at(i))) {
                        int found = checkSedFile(QString("@%1_1_1_1_1" + temp_fields.at(i)).arg(QString::number(Position)), sedfile);
                        if(found > 0)
                        {
                            ausgabe.replace("@" + temp_fields.at(i), QString("@%1_1_1_1_1" + temp_fields.at(i)).arg(QString::number(Position)));
                        } else {
                            ausgabe.remove("@" + temp_fields.at(i));
                        }
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
                                    ausgabe.append(prepareTemplateEbene(Position, ebene, 1, 1, 1, j, doc, odffile, sedfile));
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
                                        ausgabe.append(prepareTemplateEbene(Position, ebene, k, 1, 1, 1, doc, odffile, sedfile));
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

QString Reportgen::prepareTemplateContentOdt(int Table, int Position, QString odffile, QString sedfile)
{
Q_UNUSED(Table);

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
    //xmlout.append("<table:table-row><table:table-cell>");

    int cnt = 0;
    int counter = 0;
    int ebene = 0;;

    while(!stream.atEnd()) {
        ausgabe = stream.readLine().trimmed();


        /*if(ausgabe.contains("<table:table table:name"))
        {
            tableFound = tableFound + 1;
            counter = 0;
            //qDebug() << "tableFound: " << tableFound;
        }*/

        if(ausgabe.contains("[P1[")) {
            qDebug() << ausgabe;
        //if(ausgabe.contains("<table:table-row")) {
            counter = counter + 1;
        }

        if(counter > 0) {

            if(ausgabe.contains("[")) {
                ebene = ebene + 1;
            }
            //qDebug() << ebene;
            if(ausgabe.contains("@") && ebene == 1) {
                for(int i=0; i < temp_fields.count(); i++) {
                    if(ausgabe.contains("@" + temp_fields.at(i))) {
                        //qDebug() << "ebene1: " << QString("@%1" + temp_fields.at(i)).arg(QString::number(Position));
                        int found = checkSedFile(QString("@%1" + temp_fields.at(i)).arg(QString::number(Position)), sedfile);
                        if(found > 0)
                        {
                            ausgabe.replace("@" + temp_fields.at(i), QString("@%1" + temp_fields.at(i)).arg(QString::number(Position)));
                        } else {
                            ausgabe.remove("@" + temp_fields.at(i));
                        }
                        //ausgabe.replace("@" + temp_fields.at(i), QString("@%1" + temp_fields.at(i)).arg(QString::number(Position)));
                    }
                }
            }

            if(ausgabe.contains("@") && ebene == 2) {
                for(int i=0; i < temp_fields.count(); i++) {
                    if(ausgabe.contains("@" + temp_fields.at(i))) {
                        int found = checkSedFile(QString("@%1_1" + temp_fields.at(i)).arg(QString::number(Position)), sedfile);
                        if(found > 0)
                        {
                            ausgabe.replace("@" + temp_fields.at(i), QString("@%1_1" + temp_fields.at(i)).arg(QString::number(Position)));
                        } else {
                            ausgabe.remove("@" + temp_fields.at(i));
                        }
                    }
                }
            }

            if(ausgabe.contains("@") && ebene == 3) {
                for(int i=0; i < temp_fields.count(); i++) {
                    if(ausgabe.contains("@" + temp_fields.at(i))) {
                        int found = checkSedFile(QString("@%1_1_1" + temp_fields.at(i)).arg(QString::number(Position)), sedfile);
                        if(found > 0)
                        {
                            ausgabe.replace("@" + temp_fields.at(i), QString("@%1_1_1" + temp_fields.at(i)).arg(QString::number(Position)));
                        } else {
                            ausgabe.remove("@" + temp_fields.at(i));
                        }
                    }
                }
           }
           if(ausgabe.contains("@") && ebene == 4) {
                for(int i=0; i < temp_fields.count(); i++) {
                    if(ausgabe.contains("@" + temp_fields.at(i))) {
                        int found = checkSedFile(QString("@%1_1_1_1" + temp_fields.at(i)).arg(QString::number(Position)), sedfile);
                        if(found > 0)
                        {
                            ausgabe.replace("@" + temp_fields.at(i), QString("@%1_1_1_1" + temp_fields.at(i)).arg(QString::number(Position)));
                        } else {
                            ausgabe.remove("@" + temp_fields.at(i));
                        }
                    }
                }
            }
            if(ausgabe.contains("@") && ebene == 5) {
                for(int i=0; i < temp_fields.count(); i++) {
                    if(ausgabe.contains("@" + temp_fields.at(i))) {
                        int found = checkSedFile(QString("@%1_1_1_1_1" + temp_fields.at(i)).arg(QString::number(Position)), sedfile);
                        if(found > 0)
                        {
                            ausgabe.replace("@" + temp_fields.at(i), QString("@%1_1_1_1_1" + temp_fields.at(i)).arg(QString::number(Position)));
                        } else {
                            ausgabe.remove("@" + temp_fields.at(i));
                        }
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
                                    ausgabe.append(prepareTemplateEbene(Position, ebene, 1, j, 1, 1, doc, odffile, sedfile));
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
                                        ausgabe.append(prepareTemplateEbene(Position, ebene, k, 1, 1, 1, doc, odffile, sedfile));
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
            //qDebug() << "xmlout:" << xmlout;
        }

        if(xmlout.contains("]P1]")) {
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

QString Reportgen::prepareTemplateEbene(int Position, int Ebene, int Ebene3, int Ebene4, int Ebene5, int Counter, QDomDocument doc, QString odffile, QString sedfile)
{
    Q_UNUSED(odffile);
    //QFile *file = new QFile(QDir::tempPath() + "/" + QString("1-" + odffile));
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
                int found1 = 0;
                if(found == 1)
                {
                    found1 = checkSedFile(QString("@%1").arg(QString::number(Position)), sedfile);
                    if(found1 > 0)
                    {
                        ausgabe.replace("@", QString("@%1").arg(QString::number(Position)/*, QString::number(Counter)*/));
                    } else {
                        for(int i=0; i < temp_fields.count(); i++)
                        {
                            if(ausgabe.contains(temp_fields.at(i)))
                            {
                                ausgabe.remove("@" + temp_fields.at(i));
                            }
                        }
                    }
                } else if (found == 2)
                {
                    found1 = checkSedFile(QString("@%1_%2").arg(QString::number(Position)).arg(QString::number(Counter)), sedfile);
                    if(found1 > 0)
                    {
                        ausgabe.replace("@", QString("@%1_%2").arg(QString::number(Position)).arg(QString::number(Counter)));
                    } else {
                        for(int i=0; i < temp_fields.count(); i++)
                        {
                            if(ausgabe.contains(temp_fields.at(i)))
                            {
                                ausgabe.remove("@" + temp_fields.at(i));
                            }
                        }
                    }
                } else if (found == 3)
                {
                    found1 = checkSedFile(QString("@%1_%2_%3").arg(QString::number(Position)).arg(QString::number(Counter)).arg(QString::number(Ebene3)), sedfile);
                    if(found1 > 0)
                    {
                        ausgabe.replace("@", QString("@%1_%2_%3").arg(QString::number(Position)).arg(QString::number(Counter)).arg(QString::number(Ebene3))/*, QString::number(Counter)*/);
                    } else {
                        for(int i=0; i < temp_fields.count(); i++)
                        {
                            if(ausgabe.contains(temp_fields.at(i)))
                            {
                                ausgabe.remove("@" + temp_fields.at(i));
                            }
                        }
                    }
                } else if (found == 4)
                {
                    found1 = checkSedFile(QString("@%1_%2_%3_%4").arg(QString::number(Position)).arg(QString::number(Counter)).arg(QString::number(Ebene3)).arg(QString::number(Ebene4)), sedfile);
                    if(found1 > 0)
                    {
                        ausgabe.replace("@", QString("@%1_%2_%3_%4").arg(QString::number(Position)).arg(QString::number(Counter)).arg(QString::number(Ebene3)).arg(QString::number(Ebene4))/*, QString::number(Counter)*/);
                    } else {
                        for(int i=0; i < temp_fields.count(); i++)
                        {
                            if(ausgabe.contains(temp_fields.at(i)))
                            {
                                ausgabe.remove("@" + temp_fields.at(i));
                            }
                        }
                    }
                } else if (found1 == 5)
                {
                    found1 = checkSedFile(QString("@%1_%2_%3_%4_%5").arg(QString::number(Position)).arg(QString::number(Counter)).arg(QString::number(Ebene3)).arg(QString::number(Ebene4)).arg(QString::number(Ebene5)), sedfile);
                    if(found1 > 0)
                    {
                        ausgabe.replace("@", QString("@%1_%2_%3_%4_%5").arg(QString::number(Position)).arg(QString::number(Counter)).arg(QString::number(Ebene3)).arg(QString::number(Ebene4)).arg(QString::number(Ebene5))/*, QString::number(Counter)*/);
                    } else {
                        for(int i=0; i < temp_fields.count(); i++)
                        {
                            if(ausgabe.contains(temp_fields.at(i)))
                            {
                                ausgabe.remove("@" + temp_fields.at(i));
                            }
                        }
                    }
                }
            }
            if(found == 3)
            {
                if(ausgabe.contains("]P3]"))
                {
                    if(Ebene3 == 1)
                    {
                        int found = 0;
                        for(int j=2; j < temp_fields.count(); j++)
                        {
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
            if(found == 4)
            {
                if(ausgabe.contains("]P4]"))
                {
                    if(Ebene4 == 1)
                    {
                        int found = 0;
                        for(int j=2; j < temp_fields.count(); j++)
                        {
                            found = checkSedFile(QString("@%1_%2_%3_%4").arg(QString::number(Position)).arg(QString::number(Counter)).arg(QString::number(j)), sedfile);
                            if(found > 0)
                            {
                                if(ausgabe.contains("]P4]"))
                                {
                                    ersetzeVar = behalten;
                                    ersetzeVar.replace(QString("@"), QString("@%1_%2_%3_%4").arg(QString::number(Position)).arg(QString::number(Counter)).arg(QString::number(j)));
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
            if(found == 5)
            {
                if(ausgabe.contains("]P5]"))
                {
                    if(Ebene5 == 1)
                    {
                        int found = 0;
                        for(int j=2; j < temp_fields.count(); j++)
                        {
                            found = checkSedFile(QString("@%1_%2_%3_%4_%5").arg(QString::number(Position)).arg(QString::number(Counter)).arg(QString::number(j)).arg(QString::number(Ebene4)), sedfile);
                            if(found > 0)
                            {
                                if(ausgabe.contains("]P5]"))
                                {
                                    ersetzeVar = behalten;
                                    ersetzeVar.replace(QString("@"), QString("@%1_%2_%3_%4_%5").arg(QString::number(Position)).arg(QString::number(Counter)).arg(QString::number(j)).arg(QString::number(Ebene4)).arg(QString::number(Ebene5)));
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
        qDebug() << "(replaceMetaFile()): Konnte meta.xml nicht zum schreiben öffnen";
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

void Reportgen::readSedFile(QString sedfile)
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

void Reportgen::getTemplateVars(QString filename)
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
                ausgabe.remove("<text:p text:style-name=\"Standard\">");
                ausgabe.remove("<text:p>");
                ausgabe.remove("</text:p>");
                ausgabe.remove("@");
                temp_fields << ausgabe.trimmed();
            }
        }
        file->close();
    }

}
QString Reportgen::getVariable(QString line)
{
    int start = 0;
    QString behalten;
    for(int i=0; i < line.length(); i++)
    {
        if(line.at(i) == QChar('@'))
        {
                start = 1;
        }
        if(line.at(i) == QChar('<') || line.at(i) == QChar(' '))
        {
            start = 0;
        }

        if(start > 0)
        {
            behalten.append(line.at(i));
        }
    }
    return behalten;
}

bool Reportgen::replaceTemplateWithoutPosition(QString odffile, QString sedFile, QFileInfo zielDatei)
{
    QFile *xmlFile = new QFile(QDir::tempPath() + "/" + odffile + "/content.xml");
    QDomDocument doc;
    QString xmlString;
    QString xmlLine;
    QString xmlOutString;
    QString xmlVar;
    QString sedAusgabe;


    temp_fields.clear();
    getTemplateVars(odffile + "/content.xml");

    if(!xmlFile->open(QIODevice::ReadOnly))
    {
        qDebug() << "(replaceTemplateWithoutPosition()): Datei konnte nicht zum Schreiben geoeffnet werden";
        return 404;
    }
    doc.setContent(xmlFile);


    xmlString = doc.toString();
    QTextStream streamIn(&xmlString);

    while(!streamIn.atEnd())
    {
        xmlLine = streamIn.readLine();

        if(xmlLine.contains("@"))
        {
            xmlVar = getVariable(xmlLine);
            if(checkSedFile(xmlVar, sedFile))
            {
                for(int j=0; j < sed_fields.count(); j++)
                {
                    if(sed_fields.at(j).contains(xmlVar))
                    {
                        sedAusgabe = sed_fields.at(j);
                        sedAusgabe.remove(QString(xmlVar + "/"));
                        xmlLine.replace(xmlVar, sedAusgabe);
                    }
                }
            } else {
                xmlLine.remove(xmlVar);
            }
        }
        if(xmlLine.contains("[P") || xmlLine.contains("]P"))
        {
            xmlLine.remove("[P1[");
            xmlLine.remove("[P2[");
            xmlLine.remove("[P3[");
            xmlLine.remove("]P3]");
            xmlLine.remove("]P2]");
            xmlLine.remove("]P1]");
        }
        xmlOutString.append(xmlLine);
    }

    if(xmlFile->isOpen())
    {
        xmlFile->close();
    }

    if(!xmlFile->open(QIODevice::WriteOnly))
    {
        qDebug() << "(replaceTemplateWithoutPosition()): Konnte Datei nicht zum Schreiben oeffnen.";
        return 404;
    }

    QTextStream xmlOut(xmlFile);
    xmlOut << xmlOutString;

    xmlFile->close();


    ZipUnzip *p_zip = new ZipUnzip();
    p_zip->zipFileArchiv(QDir::tempPath(), odffile, zielDatei);
    return true;
}

//------------------------------------------------------------------------------
// Method       : replaceTemplateVars(QString odffile, QString sedfile)
// Filename     : clienttcp.cpp
// Description  : replace te vars with the value from the SED File.
//
//------------------------------------------------------------------------------

bool Reportgen::replaceTemplateVars(QString odffile, QString sedfile, QFileInfo zielDatei)
{
    Q_UNUSED(sedfile);
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
            temp_var.remove("<text:p text:style-name=\"Standard\">");
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
                ausgabe.replace(QString("<text:p>" + temp_var + "</text:p>"), QString("<draw:frame table:end-cell-address=\"Tabelle1.E22\" table:end-x=\"0.6953in\" table:end-y=\"0.0075in\" draw:z-index=\"0\" draw:name=\"Graphics 1\" draw:style-name=\"gr1\" draw:text-style-name=\"P1\" svg:width=\"6.5126in\" svg:height=\"3.8528in\" svg:x=\"0.585in\" svg:y=\"0.0732in\"><draw:image xlink:href=\"Pictures/" + diag_bild + "\" xlink:type=\"simple\" xlink:show=\"embed\" xlink:actuate=\"onLoad\"><text:p/></draw:image></draw:frame>"));

                makeChart = 1;
            }

            if(cnt < temp_fields.count())
            {
                for (int i=0; i < sed_fields.count(); i++)
                {
                    //qDebug() << "Verbleibende Datensaetze: " << sed_fields.count();
                    if(sed_fields.at(i).contains(temp_var.trimmed() + "/"))
                    {
                        qDebug() << "Es wurde gefunden: " << sed_fields.at(i);
                        sedLine = sed_fields.at(i).trimmed();
                        sedLine.replace(QString(temp_var.trimmed() + "/"), "");
                        ausgabe.replace(temp_var.trimmed(), sedLine);
                        if(!temp_var.endsWith("1"))
                        {
                           sed_fields.removeAt(i);
                        } else {
                            if(!chartVar.isEmpty())
                            {
                                qDebug() << "chartVar: " << chartVar;
                                for(int j=0; j < chartVar.count(); j++)
                                {
                                    if(temp_var.contains(chartVar.at(j)))
                                    {
                                        if(j == 0)
                                        {
                                            if(!chartValues1.contains(sedLine))
                                            {
                                                if(sedLine.contains(","))
                                                {
                                                    sedLine.replace(",",".");
                                                }
                                                if(sedLine.isEmpty())
                                                {
                                                    //chartValues1 << "(null)";
                                                } else {
                                                    chartValues1 << sedLine;
                                                }
                                            }
                                        } else if(j == 1)
                                        {
                                            if(sedLine.contains("."))
                                            {
                                                sedLine.remove(".");
                                            }
                                            if(sedLine.contains(","))
                                            {
                                                sedLine.replace(",",".");
                                            }
                                            chartValues2 << sedLine;
                                            qDebug() << "chartValues2 "<< sedLine;
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
            ausgabe.remove("[P1[");
            ausgabe.remove("[P2[");
            ausgabe.remove("[P3[");
        } else if(ausgabe.contains("]"))
        {
            ausgabe.remove("]P1]");
            ausgabe.remove("]P2]");
            ausgabe.remove("]P3]");
        }
        stream1 << ausgabe.trimmed();
    }
    file1->close();
    file->close();

    //if(chartValues1.count() == chartValues2.count())
    //{


    switch(diag_state)
    {
        case 1:
    {
        qDebug() << "chartValues1.count()" << chartValues1.count();
        qDebug() << "chartValues2.count()" << chartValues2.count();
            if(chartValues1.count() > chartValues2.count())
            {
                wiederholen = chartValues2.count();
            } else if(chartValues2.count() > chartValues1.count())
            {
                wiederholen = chartValues1.count();
            }
            qDebug() << "wiederholen" << wiederholen;

                /*for(int i=0; i < wiederholen; i++)
                {
                //qDebug() << "Werte fuer KD Charts: " << chartValues1.at(i) << ","<< chartValues2.at(i);
                    if(!chartValues1.at(i).isEmpty() && !chartValues2.at(i).isEmpty())
                    {
                        //qDebug() << "chartValues1.at(i)" << chartValues1.at(i) << chartValues2.at(i);
                        emit addChartValue(chartValues1.at(i), chartValues2.at(i));
                    }
                }*/
            QVector<QVariant> wertList;
            QVector<QVariant> nameList;
            if(wertList.isEmpty())
            {
                wertList << "VENTAS BAR DIAGRAMM";
            }
            for(int i=0; i < wiederholen; i++)
            {
                if(!chartValues2.at(i).isEmpty() && !chartValues1.at(i).isEmpty())
                {
                    nameList << chartValues1.at(i);
                    wertList << chartValues2.at(i);
                }

            }
            /*qDebug() << "nameList: " << nameList;
            qDebug() << "wertList: " << wertList;*/
            emit addChartValue(nameList, wertList);
          break;
    }
        case 2:
    {
        QVector<QVariant> wertList1;
        QVector<QVariant> nameList1;
        if(wertList1.isEmpty())
        {
            wertList1 << "VENTAS PIE DIAGRAMM";
        }
        for(int i=0; i < chartValues1.count(); i++)
        {
            if(!chartValues2.at(i).isEmpty())
            {
                wertList1 << chartValues2.at(i);
            }

        }
        for(int i=0; i < chartValues1.count(); i++)
        {
            if(!chartValues1.at(i).isEmpty())
            {
                nameList1 << chartValues1.at(i);
            }
        }
        emit addChartValue(nameList1, wertList1);
        break;

    }
    }

    if(makeChart == 1)
    {
        emit displayChart(diag_bild, diag_state);
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
                        manifestText = manifestText.append("<manifest:file-entry manifest:media-type=\"image/png\" manifest:full-path=\"Pictures/" + diag_bild + "\"/>");
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

    QDir dir;
    dir.setPath(QDir::tempPath() + "/" + odffile);

    QList<QString> fileEntrys = dir.entryList( QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);

    for(int i=0; i < fileEntrys.count(); i++)
    {
        QFile *file = new QFile(dir.path() + "/" + fileEntrys.at(i));
        QFileInfo *fileInfo = new QFileInfo(dir.path() + "/" + fileEntrys.at(i));

        if(fileInfo->isFile())
        {
            if(file->exists())
            {
                file->remove();
            }
        } else if(fileInfo->isDir())
        {
            QDir dir1;
            dir1.setPath(QDir::tempPath() + "/" + odffile + "/" + fileEntrys.at(i));

            QList<QString> fileEntrys1 = dir1.entryList( QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);

            for(int j=0; j < fileEntrys1.count(); j++)
            {
                QFile *file1 = new QFile(dir1.path() + "/" + fileEntrys1.at(j));
                QFileInfo *fileInfo1 = new QFileInfo(dir1.path() + "/" + fileEntrys1.at(j));

                if(fileInfo1->isFile())
                {
                    if(file1->exists())
                    {
                        file1->remove();
                    }
                }
            }
        }
    }

    return true;
}

bool Reportgen::createInfoFile(QFileInfo odffile, QFileInfo zieldatei)
{
    qDebug() << "erstellen der Info Datei" << odffile.fileName();

    ZipUnzip *p_zipunzip = new ZipUnzip();

    if(!p_zipunzip->unzipArchiv(QDir::tempPath(), QString(odffile.fileName()), QString(QDir::tempPath() + "/" + odffile.baseName())))
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

        if(ausgabe.contains("@"))
        {
            QString str;
            int startAppend = 0;
            for(int i=0; i < ausgabe.length(); i++)
            {
                if(ausgabe.at(i) == QChar('@'))
                {
                    startAppend = 1;
                }

                if(ausgabe.at(i) == QChar('<') || ausgabe.at(i) == QChar(' '))
                {
                    startAppend = 0;
                }

                if(startAppend == 1)
                {
                    str.append(ausgabe.at(i));
                }
            }

            str.replace("@",QString("%1:").arg(counter)).trimmed();

            if(!fields.isEmpty())
            {
                for(int i=0; i < fields.count(); i++)
                {
                    if(fields.at(i).contains(str))
                    {
                        found = found + 1;
                    }
                }
                if(found == 0)
                {
                    fields << str;
                }
                found = 0;
            } else {
                fields << str;
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
