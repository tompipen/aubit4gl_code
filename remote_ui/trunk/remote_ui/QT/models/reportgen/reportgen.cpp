#include <QDomDocument>
#include <QCoreApplication>
#include <QDir>
#include <QTextStream>
#include <QDebug>
#include <QTemporaryFile>
#include <QThread>

#include "models/reportgen/reportgen.h"
#include "models/zipunzip.h"
#ifndef Q_OS_WIN
#include "libgen.h"
#endif

#include "logger.h"

ReportGenerator::ReportGenerator(QString templateFileName, QString sedFileName, QString destinationFileName)
{

    start1 = false;
    startRemove = false;

    setWorkingDir(QDir::tempPath()  + "/repgen_" + QString::number(QCoreApplication::applicationPid())); //Pfad zum Arbeitsverezcihnis setzen z.b /tmp/repgen_23434/

    copyFilesToWorkingDir(templateFileName, sedFileName); //Dateien ins Arbeitsverzeichnis kopieren

    QFileInfo templateFileInfo(templateFileName);
    QFileInfo sedFileInfo(sedFileName);

    templateFileName = templateFileInfo.baseName() + "." + templateFileInfo.completeSuffix();
    sedFileName = sedFileInfo.baseName() + "." + sedFileInfo.completeSuffix();

    p_templateParser = new TemplateParser(getWorkingDir(), templateFileName);
    p_sedParser = new SedParser(getWorkingDir(), sedFileName);
    setDestinationFile(destinationFileName);
}

ReportGenerator::~ReportGenerator()
{
    p_sedParser->clear();
    delete p_sedParser;
    delete p_templateParser;
}

void ReportGenerator::start()
{
    if(!p_templateParser->unzipDocument(getWorkingDir())) {
        Logger::instance().log(3,"Failed to extract Template. ABORT!");
        return;
    }

    p_templateParser->readTemplateFile();

    p_templateParser->pruefeBarcode(p_templateParser->getDocument());

    p_templateParser->readElementsFromDocument(p_templateParser->getDocument().documentElement());

    QDomDocument doc1;
    QDomElement position1 = doc1.createElement("POSITION-1");
    //Entfernt die komplette P1 Ebene aus dem Hauptdokument
    if(!p_templateParser->getElementsByLevel(1).isEmpty()) {
        p_templateParser->getElementsByLevel(1).first().parentNode().insertBefore(position1, p_templateParser->getElementsByLevel(1).first());
        for(int i=0; i < p_templateParser->getElementsByLevel(1).count(); i++) {
            p_templateParser->getElementsByLevel(1).at(i).parentNode().removeChild(p_templateParser->getElementsByLevel(1).at(i));
        }
    }

    createOpenDocumentSpreadsheet();
    expandVarsKopf(p_templateParser->getDocument().documentElement());
    saveTemplate();

    replaceVarsInStylesFile();

    mergeFiles();
    p_templateParser->zipDocument(getWorkingDir(), m_destinationFile);

    p_sedParser->closeFile();
    cleanWorkspace();

}

bool ReportGenerator::isValidDate(QString value )
{

    return false;
}

/*!
 * \brief ReportGenerator::copyFilesToWorkingDir
 * \param templateFileName
 * \param sedFileName
 *
 * Kopiert alle benoetigtten dateien in das Arbeitsverzeichnis
 */

void ReportGenerator::copyFilesToWorkingDir(QString templateFileName, QString sedFileName)
{
    QDir workingDir(getWorkingDir());

    Logger::instance().log(1,QString("Working directory: %1").arg(getWorkingDir()));

    if(!workingDir.exists()) {
        workingDir.mkdir(getWorkingDir());
    }

    QFileInfo templateFileInfo(templateFileName);
    QFileInfo sedFileInfo(sedFileName);

    QFile::copy(sedFileName, getWorkingDir() + "/" + sedFileInfo.baseName() + "." + sedFileInfo.completeSuffix());
    QFile::copy(templateFileName, getWorkingDir() + "/" + templateFileInfo.baseName() + "." + templateFileInfo.completeSuffix());
}

/*!
 * \brief ReportGenerator::createOpenDocumentSpreadsheet
 * Hauptfunktion fuer die Dokumentenerstellung
 */

void ReportGenerator::createOpenDocumentSpreadsheet()
{
    QList<QDomElement> xmlPosition = p_templateParser->getElementsByLevel(1);

    QByteArray buffer;
    QDomDocument positionsDoc;

    QFile positionsFile(getWorkingDir() + "/" + p_templateParser->getDocumentBaseName() + "/position.xml");
    if(!positionsFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        Logger::instance().log(3,"Cannot open file positions.xml");
        return;
    }

    QTextStream stream(&positionsFile);
    QDomDocument *doc1 = new QDomDocument;
    QDomElement rootElement = doc1->createElement("root");

    QTextStream bufferStream(&buffer, QIODevice::ReadWrite | QIODevice::Text);
    //Anfueger an root da Qt sonst sagt es waere nicht valide bei setContent();
    for(int i=0; i < xmlPosition.count(); i++) {
        rootElement.appendChild(xmlPosition.at(i).cloneNode());
    }

    //Doc in "buffer" schreiben damit es neu gesetzt werden kann da es sonst geaendert wird
    doc1->appendChild(rootElement);
    doc1->save(bufferStream,QDomNode::EncodingFromDocument);

    //TODO: evtl brauch mans spaeter fuer debug
    /*QFile myfile("C:\\Users\\da\\AppData\\Local\\Temp\\ebene.xml");
    if(!myfile.open(QIODevice::WriteOnly)) {
        qDebug() << "konnte nicht oeffnen";
    }
    QTextStream mystream (&myfile);
    xmlPosition.at(xmlPosition.count()-1).save(mystream, QDomNode::EncodingFromDocument);
    qDebug() << "doc1: " << doc1->toString();
    qDebug() << "bufferStream: " << bufferStream.readAll();*/

    p_sedParser->readKopfFromSed(p_templateParser->getSuffix());

    //Hauptschleife für um die P1 Positionen anzuhaengen
    while(p_sedParser->readPosFromSed(p_templateParser->getSuffix())) {

        positionsDoc.setContent(buffer); // ergänzt Positions-Temp-Datei um eine Position
        appendLevelsToXml(p_sedParser->getPosIndex(), 0, 0, 0, positionsDoc.documentElement()); // fuegt Unter-Positionen unter Ebene 1 an
        stream << positionsDoc.documentElement(); // hängt die ganze Ebene 1 an die Position "Temp-Datei" an
     }

    p_sedParser->readKopfFromSed(p_templateParser->getSuffix());

    delete doc1;
    positionsFile.close();
}


/*!
 * \brief ReportGenerator::mergeFiles
 * Speichert das QDomDocuent welches im RAM ist als physische Datei
 */

void ReportGenerator::saveTemplate()
{
    QFile templateFile(getWorkingDir() + "/" + p_templateParser->getDocumentBaseName() + "/template.xml");

    if(!templateFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        Logger::instance().log(3,"Cannot open template file for write.");
    }
    QTextStream out(&templateFile);
    p_templateParser->getDocument().save(out, QDomNode::EncodingFromDocument);

    templateFile.close();
}

/*!
 * \brief ReportGenerator::mergeFiles
 * Fuegt die template.xml und position.xml zusammen zu der content.xml da diese von OpenOffice benoetigt wird.
 */
void ReportGenerator::mergeFiles()
{
    Logger::instance().log(1,"Merge Files");

    QFile contentFile(getWorkingDir() + "/" + p_templateParser->getDocumentBaseName() + "/content.xml");
    if(!contentFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {

    }
    QTextStream contentStream(&contentFile);
    contentStream.setCodec("UTF-8");

    QFile templateFile(getWorkingDir() + "/" + p_templateParser->getDocumentBaseName() + "/template.xml");
    if(!templateFile.open(QIODevice::ReadOnly)) {
        Logger::instance().log(3,"Cannot open template.xml for read");
    }
    QTextStream templateStream(&templateFile);
    templateStream.setCodec("UTF-8");

    QFile positionFile(getWorkingDir() + "/" + p_templateParser->getDocumentBaseName() + "/position.xml");
    if(!positionFile.open(QIODevice::ReadOnly)) {
        Logger::instance().log(3,"Cannot open position.xml for read");
    }
    QTextStream positionStream(&positionFile);

    //merge both files position.xml and tempalte.xml for a valid xml document
    while(!templateStream.atEnd()) {
        QString text = templateStream.readLine();

        if(text.contains("POSITION-1")) { //Lesen bis er am Platzhalter angekommen ist
            while(!positionStream.atEnd())
            {
                QString positionText = positionStream.readLine();
                if(!positionText.contains("<root>") && !positionText.contains("</root>")) { //<root> bzw </root> darf nicht mit in die content.xml
                    contentStream << positionText;
                }
            }
            text = "";
        }
        contentStream << text;
    }

    contentFile.close();
    templateFile.close();
    positionFile.close();

    //remove not needed files we only need content.xml
    templateFile.remove();
    positionFile.remove();
}

/*!
 * \brief ReportGenerator::cleanWorkspace
 * Aufraumen des Arbeitsverzeichnis wenn loglevel <= 1 ist
 */
void ReportGenerator::cleanWorkspace()
{
    if(getLogLevel() <= 1) {
        removeDir(getWorkingDir());
    }
}

/*!
 * \brief ReportGenerator::removeDir
 * \param dirName
 * Recrusive Funktion zum loeschen von kompletten Ordner.
 */

bool ReportGenerator::removeDir(const QString & dirName)
{
    bool result = true;
    QDir dir(dirName);

    if (dir.exists(dirName)) {
        Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst)) {
            if (info.isDir()) {
                result = removeDir(info.absoluteFilePath());
            }
            else {
                result = QFile::remove(info.absoluteFilePath());
            }

            if (!result) {
                return result;
            }
        }
        result = dir.rmdir(dirName);
    }
    return result;
}

/*!
 * \brief ReportGenerator::replaceVarsInStylesFile
 * Ersetzt die Variable in der styles.xml
 */

void ReportGenerator::replaceVarsInStylesFile()
{
    QDomDocument doc;

    QFile file(getWorkingDir() + "/" + p_templateParser->getDocumentBaseName() + "/styles.xml");

    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << "replaceVarsInStylesFile: failed to open";
        return;
    }

    doc.setContent(file.readAll());

    expandVarsKopf(doc.documentElement());

    file.close();

    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        return;
    }

    QTextStream stream(&file);

    doc.save(stream, QDomNode::EncodingFromDocument);

}

/*!
 * \brief ReportGenerator::expandVarsKopf
 * \param rootElement
 * Rekrusive Funktion um kopfvariablen zu uebersetzen.
 */
void ReportGenerator::expandVarsKopf(QDomElement rootElement)
{
    QDomNode node = rootElement.firstChild();

    while(!node.isNull()) {

        if(node.childNodes().count() > 0){
             expandVarsKopf(node.toElement());
        }

        QString content = node.nodeValue();
        QRegExp rxlen("^(.*)*(@[A-Z][A-Z0-9_]+)(.*)*$");

        int pos = 0;
        while (1==1) {
          pos = rxlen.indexIn(content, pos);

           if (pos > -1) {
             if(getLogLevel() <= 3) {
                QString variable = rxlen.cap(2);
                QString value = p_sedParser->getKopfContainer().value(variable);
                content = rxlen.cap(1) + value + rxlen.cap(3);

                node.setNodeValue(content); // Variable durch Inhalt ersetzen
             }          
           } else {
              break;
           }
        }

        //Zeilenumbruch als Element einfuegen da < bzw > als html entitaet umgewandelt wird durch setNodeValue
        if(content.contains("<line-break>")) {
            QStringList valueList = content.split("<line-break>");
            QDomDocument doc;

            //ersetzt den text bis zum ersten line break
            node.setNodeValue(valueList.first());
            valueList.removeAt(0);

            QDomNode currNode = node;
            //Haengt alles nach den <line-break> an
            foreach(QString value, valueList) {
                QDomElement newElementLineBreak = doc.createElement("text:line-break");
                node.parentNode().insertAfter(newElementLineBreak, currNode);

                QDomText nodeText = doc.createTextNode(value);
                node.parentNode().insertAfter(nodeText, newElementLineBreak);
                currNode = nodeText;
            }
            qDebug() << "LINEBRK";
        } else {
            if(p_templateParser->getSuffix() == "ods" && p_sedParser->isNumber(content)) {
                //Wandelt datentyp char nach float um
                content.remove(".");
                content.replace(",",".");
                node.parentNode().parentNode().toElement().setAttribute("office:value-type", "float");
                node.parentNode().parentNode().toElement().setAttribute("calcext:value-type", "float");
                node.parentNode().parentNode().toElement().setAttribute("office:value", content.simplified());
            }
        }
        node = node.nextSibling();
    }
}

/*!
 * \brief ReportGenerator::expandVarsPos
 * \param praefix
 * \param stufe
 * \param machStufe
 * \param rootElement
 * \return
 *
 * Rekrusive Funktion um Positionsvariablen zu ersetzen.
 */

int ReportGenerator::expandVarsPos(QString praefix, int stufe, int machStufe, QDomElement rootElement)
{
    QDomNode node = rootElement.firstChild();

    while(!node.isNull()) {

        if(node.childNodes().count() > 0){
            stufe = expandVarsPos(praefix, stufe, machStufe, node.toElement());
        }

        if(node.toElement().tagName() == "draw:frame") {
            QList<QString> params = p_sedParser->erseteImage(node, praefix);
            QFile barcodeImg(params.at(1));
            QString imgFile = "Pictures/" + barcodeImg.fileName().section('/', -1);
            //if(barcodeImg.exists()) {
                QDir pictureDir(getWorkingDir() + "/" + p_templateParser->getDocumentBaseName() + "/Pictures");
                if(!pictureDir.exists()) {
                    pictureDir.mkdir(getWorkingDir() + "/" + p_templateParser->getDocumentBaseName() + "/Pictures");
                }

                barcodeImg.copy(getWorkingDir() + "/" + p_templateParser->getDocumentBaseName() + "/" + imgFile);
                p_templateParser->appendToManifestFile(params.at(0), imgFile);
            //}
        }

        if(node.nodeName() != "#text") {
            node = node.nextSibling();
            continue;
        }

        if((node.nodeValue() == "[P1["  ||
           node.nodeValue() == "[P2["  ||
           node.nodeValue() == "[P3["  ||
           node.nodeValue() == "[P4["  ||
           node.nodeValue() == "[P5[") &&
           node.nodeValue() == QString("[P%1[").arg(machStufe)) {
            stufe++;
            node = node.nextSibling();
            continue;
        }

        if((node.nodeValue() == "]P1]" ||
           node.nodeValue() == "]P2]"  ||
           node.nodeValue() == "]P3]"  ||
           node.nodeValue() == "]P4]"  ||
           node.nodeValue() == "]P5]") &&
           node.nodeValue() == QString("]P%1]").arg(machStufe)) {

           stufe--;
           node = node.nextSibling();
           continue;
        }

        if(stufe!=machStufe) {
            node = node.nextSibling();
            continue;
        }

        QString content = node.nodeValue();
        QRegExp rxlen("^(.*)(@([A-Z][A-Z0-9_]+))(.*)$");

        int pos = 0;
        while (1==1) {
           pos = rxlen.indexIn(content, pos); //prueft ob der regex im text vorkommt
           if (pos > -1) {
             //QString davor     = rxlen.cap(1); // String vor Variable
             //QString variable1 = rxlen.cap(3); // Variable
             //QString variable2 = "@" + praefix + variable1;
             //QString danach    = rxlen.cap(4); // String nach Variable

             //           "davor"              Praefix   Variable       "danach"
             if(getLogLevel() >= 3) {
                content = rxlen.cap(1) + "@" + praefix + rxlen.cap(3) + rxlen.cap(4);
             } else {
                QString variable = "@" + praefix + rxlen.cap(3);
                QString value = p_sedParser->getPosContainer().value(variable);
                QString color = p_sedParser->getColorContainer().value(variable);

                content = rxlen.cap(1) + value + rxlen.cap(4);
                node.setNodeValue(content); //ersetzt Variable mit den Inhalt
                QDomNodeList styleElements = p_templateParser->getDocument().documentElement().elementsByTagName("style:style");

                if(!color.isEmpty()) {
                    bool found = false;
                    QDomNode copyStyleNode;
                    for(int i=0; i < styleElements.count(); i++) {
                        QDomNode styleNode = styleElements.at(i);
                        QDomElement styleNodeElement = styleNode.toElement();
                        QDomElement parentStyleElement = node.parentNode().parentNode().toElement();

                        QString styleName = parentStyleElement.attribute("table:style-name") + "-" + color;

                        if(styleNodeElement.attribute("style:name") == parentStyleElement.attribute("table:style-name")) {
                            copyStyleNode = styleNodeElement;
                        }

                        if(styleNodeElement.attribute("style:name") == styleName) {
                            found = true;
                            break;
                        }
                    }

                    QDomElement parentStyleElement = node.parentNode().parentNode().toElement();
                    if(!found) {
                        qDebug() << "No element found using " << copyStyleNode.toElement().tagName();

                        QDomElement copyStyleElement = copyStyleNode.toElement();
                        QDomElement newCopyStyleElement = copyStyleElement.cloneNode(true).toElement();

                        newCopyStyleElement.setAttribute("style:name", copyStyleElement.attribute("style:name")+ "-" + color);

                        if(color == "R") {
                            newCopyStyleElement.firstChildElement("style:table-cell-properties").setAttribute("fo:background-color", "#ff8080");
                        } else if(color == "G") {
                            newCopyStyleElement.firstChildElement("style:table-cell-properties").setAttribute("fo:background-color", "#94bd5e");
                        } else if(color == "O") {
                            newCopyStyleElement.firstChildElement("style:table-cell-properties").setAttribute("fo:background-color", "#ffcc99");
                        }

                        copyStyleNode.parentNode().insertBefore(newCopyStyleElement, copyStyleElement);

                        qDebug() << "parentStyleElement.attribute: " << parentStyleElement.attribute("table:style-name") + "-" + color;
                    }
                    parentStyleElement.setAttribute("table:style-name", parentStyleElement.attribute("table:style-name") + "-" + color);

                }
            }
           } else {
              break;
           }
        }

        if(content.contains("<line-break>")) {
            QStringList valueList = content.split("<line-break>");
            QDomDocument doc;

            //ersetzt den text bis zum ersten line break
            node.setNodeValue(valueList.first());
            valueList.removeAt(0);

            QDomNode currNode = node;
            //Haengt alles nach den <line-break> an
            foreach(QString value, valueList) {
                QDomElement newElementLineBreak = doc.createElement("text:line-break");
                node.parentNode().insertAfter(newElementLineBreak, currNode);

                QDomText nodeText = doc.createTextNode(value);
                node.parentNode().insertAfter(nodeText, newElementLineBreak);
                currNode = nodeText;
            }
            qDebug() << "LINEBRK";
        } else {
            if(p_templateParser->getSuffix() == "ods" && p_sedParser->isNumber(content)) {
                content.remove(".");
                content.replace(",",".");
                node.parentNode().parentNode().toElement().setAttribute("office:value-type", "float");
                node.parentNode().parentNode().toElement().setAttribute("calcext:value-type", "float");
                node.parentNode().parentNode().toElement().setAttribute("office:value", content.simplified());
            }
        }
        node = node.nextSibling();
    }
    return stufe;
}

/*!
 * \brief ReportGenerator::appendLevelsToXml
 * \param ebene1
 * \param ebene2
 * \param ebene3
 * \param ebene4
 * \param rootElement
 *
 * Diese funktionen haengt die verschiedenen Ebenen an das rootElement an.
 *
 */

void ReportGenerator::appendLevelsToXml(int ebene1, int ebene2, int ebene3, int ebene4, QDomElement rootElement)
{
    QDomNode node = rootElement.firstChild();

    int stufe = 0;
    int machStufe = 1;

    while(!node.isNull()) {
        QDomElement nodeElement = node.toElement();

        if((p_templateParser->getSuffix() == "ods" && nodeElement.tagName() == "table:table-row") ||
           (p_templateParser->getSuffix() == "odt")) {

            if(nodeElement.text().contains("[P2[")) {
                    machStufe = 2;
                    ebene2++;
                    ebene3 = 0;
                    ebene4 = 0;
            }

            if(nodeElement.text().contains("[P3[")) {
                    machStufe = 3;
                    ebene3++;
                    ebene4 = 0;
            }

            if(nodeElement.text().contains("[P4[")) {
                    machStufe = 4;
                    ebene4++;
            }

            if(nodeElement.isElement()) {
                //Prafix zusammenbauen fuer die verschiedenen ebenen
                QString praefix = "";
                if(ebene4 > 0 && machStufe == 4) {
                   praefix = QString::number(ebene1) + "_" + QString::number(ebene2) + "_" + QString::number(ebene3) + "_" + QString::number(ebene4) + "_";
                } else if(ebene3 > 0 && machStufe == 3) {
                    praefix = QString::number(ebene1) + "_" + QString::number(ebene2) + "_" + QString::number(ebene3);
                } else if (ebene2 > 0 && machStufe == 2) {
                    praefix = QString::number(ebene1) + "_" + QString::number(ebene2);
                } else if(ebene1 > 0 && machStufe == 1) {
                    praefix = QString::number(ebene1);
                }

                stufe = expandVarsPos(praefix, stufe, machStufe, nodeElement);

            }

            if(nodeElement.text().contains("]P2]")) {
                if (ebene2 == 1) {
                    int maxRows = p_sedParser->count(ebene1, 0, 0, 0);

                    for(int i=1; i < maxRows; i++) {
                        //ebene2++;
                        QList<QDomElement> position = p_templateParser->getElementsByLevel(2);

                        for(int j=position.count()-1; j >= 0; j--) {
                          nodeElement.parentNode().insertAfter(position.at(j).cloneNode(), node);
                        }
                    }
                }
                ebene3 = 0;
                ebene4 = 0;
                machStufe = 1;
            }

            if(nodeElement.text().contains("]P3]")) {
                if (ebene3 == 1) {
                    int maxRows = p_sedParser->count(ebene1, ebene2, 0, 0);

                    for(int i=1; i < maxRows; i++) {
                        QList<QDomElement> position = p_templateParser->getElementsByLevel(3);

                        for(int j=position.count()-1; j >= 0; j--) {
                          nodeElement.parentNode().insertAfter(position.at(j).cloneNode(), node);
                        }
                    }
                }
                ebene4 = 0;
                machStufe = 2;
            }

            if(nodeElement.text().contains("]P4]")) {
                if (ebene4 == 1) {
                    int maxRows = p_sedParser->count(ebene1, ebene2, ebene3, 0);

                    for(int i=1; i < maxRows; i++) {
                        QList<QDomElement> position = p_templateParser->getElementsByLevel(4);

                        for(int j=position.count()-1; j >= 0; j--) {
                          nodeElement.parentNode().insertAfter(position.at(j).cloneNode(), node);
                        }
                    }
                }
                machStufe = 3;
            }
        }
        node = node.nextSibling();
    }

    QDomNodeList nodeList;
    //Es wird geprueft ob es en [P1[ ode ]P1] in einem text:p element gibt
    nodeList = rootElement.elementsByTagName("text:p");

    for(int i=0;i < nodeList.count(); i++) {
        QDomNode node = nodeList.at(i);
        for(int j=0; j < node.childNodes().count(); j++) {
            QDomNode childNode = node.childNodes().at(j);

            //QRegExp rxlen("^(.*)(\[P[1-5]\[\|\]P[1-5]\])(.*)$");
            QRegExp rxlen("^(.*)(\\[P[1-5]\\[|\\]P[1-5]\\])(.*)$");
            while (1==1) {
                int pos = rxlen.indexIn(childNode.nodeValue());

                if(pos == -1 ) {
                   break;
                }
                childNode.setNodeValue(rxlen.cap(1) + rxlen.cap(3));
            }
        }
    }

    //Es wird geprueft ob es en [P1[ ode ]P1] in einem text:span element gibt
    nodeList = rootElement.elementsByTagName("text:span");

    for(int i=0;i < nodeList.count(); i++) {
        QDomNode node = nodeList.at(i);
        for(int j=0; j < node.childNodes().count(); j++) {
            QDomNode childNode = node.childNodes().at(j);

            //QRegExp rxlen("^(.*)(\[P[1-5]\[\|\]P[1-5]\])(.*)$");
            QRegExp rxlen("^(.*)(\\[P[1-5]\\[|\\]P[1-5]\\])(.*)$");
            while (1==1) {
                int pos = rxlen.indexIn(childNode.nodeValue());

                if(pos == -1 ) {
                   break;
                }

                QString content = rxlen.cap(1) + rxlen.cap(3);
                if(!content.isEmpty()) {
                    childNode.setNodeValue(rxlen.cap(1) + rxlen.cap(3));
                } else {
                    childNode.setNodeValue("");
                }
            }
        }
    }
}

/*!
 * \brief Setter function to set the Loglevel
 * \param level
 */

void ReportGenerator::setLogLevel(int level)
{
    Logger::instance().setLogLevel(level);
}

/*!
 * \brief Getter to return the loglevel
 * \return Loglevel
 */

int ReportGenerator::getLogLevel()
{
    return Logger::instance().getLogLevel();
}
