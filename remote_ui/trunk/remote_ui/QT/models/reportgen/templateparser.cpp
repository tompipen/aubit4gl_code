#include "templateparser.h"

#include <QFileInfo>
#include <QDir>

#include "models/reportgen/logger.h"
#include "models/zipunzip.h"


TemplateParser::TemplateParser(QString path, QString file)
{
   setWorkingDir(path);
   setFile(file);

   m_rememberLevel1 = false;
   m_rememberLevel2 = false;
   m_rememberLevel3 = false;

}

void TemplateParser::appendToManifestFile(QString type , QString value)
{
    QDomDocument doc;
    QFile manifestFile(getWorkingDir() + "/" + getDocumentBaseName() + "/META-INF/manifest.xml");


    if(!manifestFile.open(QIODevice::ReadWrite)) {
        qDebug() << "cannot open manifest file.";
    }

    doc.setContent(manifestFile.readAll());

    QDomElement docElement = doc.documentElement();

    if(docElement.tagName() == "manifest:manifest") {
        QDomElement fileEntry = doc.createElement("manifest:file-entry");
        fileEntry.setAttribute("manifest:media-type", type);
        fileEntry.setAttribute("manifest:full-path", value);
        docElement.appendChild(fileEntry);
    }
    manifestFile.resize(0);
    QTextStream outstream(&manifestFile);
    doc.save(outstream, 0, QDomNode::EncodingFromDocument);
    manifestFile.close();
}

void TemplateParser::pruefeBarcode(const QDomNode& rootNode)
{
    QDomNode domNode = rootNode.firstChild();
    QDomElement domElement = domNode.toElement();

    while(!domNode.isNull()) {
        domElement = domNode.toElement();

        if(domNode.isElement()) {
            pruefeBarcode(domNode);
        }

        if(domNode.isText() && domNode.nodeValue().contains("BARCODE_")) {
            QDomDocument doc;

            QDomElement drawFrameElement = doc.createElement("draw:frame");

            if(domNode.nodeValue().contains("BARCODE_ISSN")) {
                drawFrameElement.setAttribute("svg:height","5.00 mm");
                drawFrameElement.setAttribute("svg:width", + "30.00 mm");
            } else {
                drawFrameElement.setAttribute("svg:height","1.06 cm");
                drawFrameElement.setAttribute("svg:width", + "11.01 cm");
            }

            drawFrameElement.setAttribute("text:anchor-type","paragraph");
            drawFrameElement.setAttribute("draw:name","Barcode");
            drawFrameElement.setAttribute("draw:z-index","0");


            QDomElement drawImageElement = doc.createElement("draw:image");
            drawImageElement.setAttribute("xlink:actuate","onLoad");
            drawImageElement.setAttribute("xlink:show","embed");
            drawImageElement.setAttribute("xlink:type","simple");
            drawImageElement.setAttribute("xlink:href",domNode.nodeValue());

            drawFrameElement.appendChild(drawImageElement);

            domNode.parentNode().replaceChild(drawFrameElement,domNode);
        }

        domNode = domNode.nextSibling();
    }
}


/*!
 * \brief TemplateParser::readTemplateFile
 *
 * Ließt die Datei in einer member Variable mit dem typ QDomDocument ein.
 */
void TemplateParser::readTemplateFile()
{
   QFile contentFile(QDir::toNativeSeparators(getWorkingDir() + "/" + getDocumentBaseName() + "/content.xml"));

   if(!contentFile.exists()) {
       Logger::instance().log(3,"file doesnt exists.");
   }

   if(!contentFile.open(QIODevice::ReadOnly)) {
       Logger::instance().log(3,"Cannot open content xml");
       return;
   }

   QString context;

   while(!contentFile.atEnd()) {
       context.append(contentFile.readLine());
   }

   if(!m_templateDocument.setContent(context, false)) {
       Logger::instance().log(3,"Failed to setContent!");
       return;
   }

   contentFile.close();
}
/*!
 * \brief TemplateParser::unzipDocument
 * \param workingDir
 * \return false / true
 *
 * Entpackt das Dokument (ods/odt) mit hilfe von QuaZIP, sodass die einzelnen Dateien gelesen werden können.
 */

bool TemplateParser::unzipDocument(QString workingDir)
{
    ZipUnzip *p_zipunzip = new ZipUnzip();

    if(!p_zipunzip->unzipArchiv(workingDir, getDocumentWithEnding(), QString(workingDir + "/" + getDocumentBaseName())))
    {
        return false;
    }

    return true;
}

/*!
 * \brief TemplateParser::zipDocument
 * \param workingDir
 * \param destFileName
 * \return
 *
 * Erstellt ein Paket damit es mit OpenOffice geoeffnet werden kann.
 */

bool TemplateParser::zipDocument(QString workingDir, QString destFileName)
{
    QString destFilePath;

    if(destFileName.contains("/") || destFileName.contains("\\")) {
        destFilePath = destFileName;
    } else {
        destFilePath = workingDir + "/" + destFileName;
    }

    QFileInfo destFile(destFilePath);
    Logger::instance().log(1,"Packing document.");
    Logger::instance().log(1,QString("Destination file %1").arg(destFilePath));

    ZipUnzip *p_zipunzip = new ZipUnzip();

    if(!p_zipunzip->zipFileArchiv(workingDir, getDocumentBaseName(), destFile.fileName()))
    {
        Logger::instance().log(3,"Failed to pack document. ABORT!");
        return false;
    }

    if(destFileName.contains("/") || destFileName.contains("\\")) {
        QFile::copy(workingDir + "/" + destFile.fileName(), destFilePath);
    }

    return true;
}

/*!
 * \brief TemplateParser::readElementsFromDocument
 * \param rootElement
 *
 * Liest jede Ebene in eine seperate QList ein. Diese Liste dient dazu, die einzelne Positionen an das Dokument anzuhaengen.
 */

void TemplateParser::readElementsFromDocument(QDomElement rootElement)
{
    QList<QDomElement> returnElement;

    QDomNode domNode = rootElement.firstChild();
    QDomElement domElement;

    int startAppendEbene1 = 0;
    int startAppendEbene2 = 0;
    int startAppendEbene3 = 0;
    int startAppendEbene4 = 0;
    int startAppendEbene5 = 0;

    while(!domNode.isNull()) {
        if(domNode.isElement()) {
            domElement = domNode.toElement();
            if((getSuffix() == "ods" && domElement.tagName().contains("table:table-row")) ||
               (getSuffix() == "odt" && (domNode.toElement().tagName() == "text:p" || domNode.toElement().tagName() == "text:span"))) {

                    if(domElement.text().contains("[P1[")) {
                        startAppendEbene1 = 1;
                    }

                    if(domElement.text().contains("[P2[")) {
                        startAppendEbene2 = 1;
                    }

                    if(domElement.text().contains("[P3[")) {
                        startAppendEbene3 = 1;
                    }

                    if(domElement.text().contains("[P4[")) {
                        startAppendEbene4 = 1;
                    }

                    if(domElement.text().contains("[P5[")) {
                        startAppendEbene5 = 1;
                    }
            }
            if((getSuffix() == "ods" && domElement.tagName().contains("table:table-row")) ||
               (getSuffix() == "odt")) {
                    if(startAppendEbene1 == 1) {
                        firstLevelElementList << domElement;
                    }

                    if(startAppendEbene2 == 1) {
                        secondLevelElementList << domElement;
                    }

                    if(startAppendEbene3 == 1) {
                        thirdLevelElementList << domElement;
                    }

                    if(startAppendEbene4 == 1) {
                        fourthLevelElementList << domElement;
                    }

                    if(startAppendEbene5  == 1) {
                        fifthLevelElementList << domElement;
                    }
            }
            if((getSuffix() == "ods" && domElement.tagName().contains("table:table-row")) ||
               (getSuffix() == "odt" && (domNode.toElement().tagName() == "text:p" || domNode.toElement().tagName() == "text:span"))) {
                    if(domElement.text().contains("]P1]")) {
                        startAppendEbene1 = 0;
                    }

                    if(domElement.text().contains("]P2]")) {
                        startAppendEbene2 = 0;
                    }

                    if(domElement.text().contains("]P3]")) {
                        startAppendEbene3 = 0;
                    }

                    if(domElement.text().contains("]P4]")) {
                        startAppendEbene4 = 0;
                    }

                    if(domElement.text().contains("]P5]")) {
                        startAppendEbene5 = 0;
                    }
            }
            readElementsFromDocument(domElement);
        }
        domNode = domNode.nextSibling();
    }
}

/*!
 * \brief TemplateParser::getElementsByLevel
 * \param level
 * \return QList<QDomElement>
 *
 * Gibt die jeweilige QList fuer die Ebene zurueck.
 */

QList<QDomElement> TemplateParser::getElementsByLevel(int level)
{
    QList<QDomElement> returnElement;

    switch(level) {
        case 1:
            returnElement << firstLevelElementList;
            break;
        case 2:
            returnElement << secondLevelElementList;
            break;
        case 3:
            returnElement << thirdLevelElementList;
            break;
        case 4:
            returnElement << fourthLevelElementList;

        case 5:
            returnElement << fifthLevelElementList;
    }

    return returnElement;
}

/*!
 * \brief TemplateParser::getDocumentWithEnding
 * \return
 * Ueberprueft das Name + Dateiende und gibt es zurueck
 */
QString TemplateParser::getDocumentWithEnding()
{
    QFile templateFile(getFilePath());
    QFileInfo templateBaseName(templateFile.fileName());

    return templateBaseName.baseName() + "." + templateBaseName.suffix();
}

/*!
 * \brief TemplateParser::getDocumentBaseName
 * \return
 * Gibt den Namen des Dokumenten OHNE Dateiendung zurück
 */

QString TemplateParser::getDocumentBaseName()
{
    QFile templateFile(getFilePath());
    QFileInfo templateBaseName(templateFile.fileName());

    return templateBaseName.baseName();
}

/*!
 * \brief TemplateParser::getSuffix
 * \return
 *
 * Gibt ausschließlich die Dateiendung zurueck
 */

QString TemplateParser::getSuffix()
{
    QFileInfo fileInfo(m_templateFile);

    return fileInfo.completeSuffix();
}

/*!
 * \brief TemplateParser::getFilePath
 * \return
 *
 * Absoluter Pfad der Datei
 */
QString TemplateParser::getFilePath()
{
    return getWorkingDir() + "/" + getFile();
}

