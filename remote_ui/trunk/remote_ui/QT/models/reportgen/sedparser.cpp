#include "sedparser.h"
#include <QFileInfo>
#include <QFile>
#include <QRegExp>
#include <QDomElement>
#include <QDomNode>
#include <QList>

#include "models/reportgen/logger.h"


/*!
    \class SedParser
    \brief Die Klasse SedParser dient zum einlesen einer SED Datei und deren Verarbeitung.

    Die Klasse SedParser dient zum einlesen einer SED Datei und deren Verarbeitung.

    Beispielinhalt einer SED Datei:

    @1G_NR_WAEHRUNG%/GBP@#

    Die SED Datei wird dann in Variable und Inhalt gesplittet und der Inhalt kann über die Funktion getValue(QString key) ausgelesen werden.
*/


SedParser::SedParser(QString path, QString file)
{
    setFile(file);
    setWorkingDir(path); // Setzt das Arbeitsverzeichnis

    m_posIndex = 0;

    m_sedFile = new QFile(path + "/" + file); // Instanziert die Datei als Membervariable

    if(!m_sedFile->open(QIODevice::ReadOnly)) {
        Logger::instance().log(3,"Failed to open SED File.");
        return;
    }
}

SedParser::~SedParser()
{
    m_sedFile->close();
}

void SedParser::readFile()
{
    QFile sedFile(getWorkingDir() + "/" + getFile());

    if(!sedFile.open(QIODevice::ReadOnly)) {
        Logger::instance().log(3,"Failed to open SED File.");
        return;
    }

    while(!sedFile.atEnd()) {
        QString sedText = filterSed(sedFile.readLine(), "ods");
        QStringList sedValues = sedText.split("@#");

        //qDebug() << "sedValues: " << sedValues; //ans: bitte pruefen, warum zweites leeres element
        foreach (QString text, sedValues) {
            // The Regexp splits the string in 3 parts: 1) Variable 2) Color 3) Text
            //QRegExp rxlen("^(@[A-Z0-9_]+)%([^%\\/]*)/(.*)$");
            //QRegExp rxlen("^(@([0-9]+)(_[0-9]+)*[A-Z0-9_]+))%([^%\\/]*)/(.*)$");
            QRegExp rxlen("^(@(([0-9]+)(_[0-9]+)*){0,1}[A-Z0-9_]+)%([^%\\/]*)/(.*)$");
            int pos = rxlen.indexIn(text);

            if(pos > -1 ) {
                QString variable = rxlen.cap(1); // @BEARBEITER @1PREIS_GES_WR
                               //= rxlen.cap(2); // "3_1" - not used
                               //= rxlen.cap(3).toInt(); // Index 1,2,3...n
                               //= rxlen.cap(4); // subIndex "_1" - not used
                QString color    = rxlen.cap(5); // Color for the cell (e.g R for RED)
                QString value    = rxlen.cap(6); // variable content

                setValue(variable, value); // Fuegt Variable und Inhalt in einen QHash Container
            }
        }
        sedValues.clear();
        sedText = "";
    }
    sedFile.close();
}
/*!
   Schreibt den Inhalt und die Variable in ein QHash Container
*/

void SedParser::setValue(QString key, QString value)
{
    m_sedContainer.insert(key, value);
}


/*!
   Filterfunktion um unnötige Newlines von gewollten Newlines zu unterscheiden
*/

QString SedParser::filterSed(QString text, QString fileEnding)
{
    QRegExp rxlen("^(.*)(\\n)$");
    int pos = rxlen.indexIn(text);

    if(pos > -1 ) {
        QString content = rxlen.cap(1);

        if (content.endsWith("@#")) { // Segmentende
           text = content;
        } else if (fileEnding == "ods") { // ods, kein Segmentende
           text = content + " "; // ods hat keinen Umbruch
        } else { // odt, kein Segmentende
           text = content + "<line-break>";
        }
    }
    text.replace("<bla>", "@#");

    return text;
}

/*!
   Liefert den Praefix anhand der Übergabeparameter zurueck

   Beispiel:

   @1_2_1
*/

int SedParser::count(int level1, int level2, int level3, int level4)
{
    QString praefix = "";

    if(level4 > 0) {
       praefix = QString::number(level1) + "_" + QString::number(level2) + "_" + QString::number(level3) + "_" + QString::number(level4) + "_";
    } else if(level3 > 0) {
        praefix = QString::number(level1) + "_" + QString::number(level2) + "_" + QString::number(level3);
    } else if (level2 > 0) {
        praefix = QString::number(level1) + "_" + QString::number(level2);
    } else if(level1 > 0) {
        praefix = QString::number(level1);
    }

    int posIndex=0;
    foreach (QString value, m_posContainer.keys()) { // TODO Sort rueckwaerts, Tuning: Abbruch nach erstem Fund

        QRegExp rxlen("^@" + praefix + "_([0-9]+)(_[0-9]+)*[A-Z].*$");
        int pos = rxlen.indexIn(value);

        if(pos > -1 ) {
            int index = rxlen.cap(1).toInt(); // subIndex "_1"

            if (index > posIndex) {
                posIndex = index;
            }
        }
    }
    return posIndex;
}

/*!
   Liest die Kopfvariablen in ein QHash Container in der nur Kopf und Fußvariablen vorhanden sind.
*/

bool SedParser::readKopfFromSed(QString suffix)
{
    while(!m_sedFile->atEnd()) {
        QString sedText;
        QString string1;

        if(!m_lastFilePos.isEmpty()) {
            string1 = m_lastFilePos;
            m_lastFilePos.clear();
        } else {
            while(!m_sedFile->atEnd()) {
                sedText = filterSed(m_sedFile->readLine(), suffix);
                string1.append(sedText);

                if(string1.contains("@#")) {
                   break;
                }
                if(suffix == "ods") {
                    string1.append("\n");
                }
            }
        }

        QRegExp rxlen("^(@(([0-9]+)(_[0-9]+)*){0,1}[A-Z0-9_]+)%([^%\\/]*)/(.*)(@#)$");
        int pos = rxlen.indexIn(string1);

        if(pos > -1 ) {
            QString variable = rxlen.cap(1); // @BEARBEITER @1PREIS_GES_WR
                            //= rxlen.cap(2); // "3_1" - not used
            int currIndex     = rxlen.cap(3).toInt(); // Index 1,2,3...n
                            //= rxlen.cap(4); // subIndex "_1" - not used
                            //= rxlen.cap(5); // Color for the cell (e.g R for RED)
            QString value    = rxlen.cap(6); // variable content

            if (currIndex > 0) { // naechste Position gefunden
               m_lastFilePos = string1;
               break;
            }
            //qDebug() << "value - " << value << " - variable - " << variable;
            m_kopfContainer.insert(variable, value);
        }
        sedText = "";
    }

    if(m_kopfContainer.isEmpty()) {
        return false;
    }

    return true;
}

void SedParser::closeFile()
{
    m_sedFile->close();
}

/*!
   Liest die Positionsvariablen in ein QHash Container in der nur Positionsvariablen vorhanden sind.
*/

bool SedParser::readPosFromSed(QString suffix)
{
    m_posContainer.clear();

    bool posGefunden = false;

    while(!m_sedFile->atEnd()) {
        QString sedText;
        QString string1;

        if(!m_lastFilePos.isEmpty()) {
            string1 = m_lastFilePos;
            m_lastFilePos.clear();
        } else {
            while(!m_sedFile->atEnd()) {
                sedText = filterSed(m_sedFile->readLine(), suffix);
                string1.append(sedText);

                if(string1.contains("@#")) {
                   break;
                }
            }
        }

        //qDebug() << "sedValues: " << sedValues; //ans: bitte pruefen, warum zweites leeres element
        // The Regexp splits the string in 3 parts: 1) Variable 2) Color 3) Text
        //QRegExp rxlen("^(@" + QString::number(m_posIndex) + "(_[0-9]+)*[A-Z0-9_]+)%([^%\\/]*)/(.*)$");
        QRegExp rxlen("^(@(([0-9]+)(_[0-9]+)*){0,1}[A-Z0-9_]+)%([^%\\/]*)/(.*)(@#)$");
        int pos = rxlen.indexIn(string1);

        if(pos > -1 ) {

            QString variable = rxlen.cap(1); // @BEARBEITER @1PREIS_GES_WR
                           //= rxlen.cap(2); // "3_1" - not used
            int currIndex    = rxlen.cap(3).toInt(); // Index 1,2,3...n
                           //= rxlen.cap(4); // subIndex "_1" - not used
            QString color    = rxlen.cap(5); // Color for the cell (e.g R for RED)
            QString value    = rxlen.cap(6); // variable content

            if (currIndex == 0 && m_posIndex>0) { // Positionsende erreicht
              m_lastFilePos = string1;
              break;
            }

            if(!color.isEmpty()) {
                m_colorContainer.insert(variable, color);
            }

            if (currIndex > m_posIndex) { // naechste Position gefunden
                if (posGefunden) {
                    m_lastFilePos = string1;
                    break;
                } else {
                    m_posIndex = currIndex;
                    posGefunden=true;
                }
            }

            if (posGefunden && currIndex == m_posIndex) { // merken im Container
                m_posContainer.insert(variable, value);
            }
        }
        sedText = "";
    }

    if(m_posContainer.isEmpty()) {
        return false;
    }

    return true;
}

/*!
   Ueberprüft ob die Variable existiert. Ist die Variable vorhanden dann wird true zurueckgegeben andernfalls wird false zurueckgegeben
*/

bool SedParser::itemExists(QString key)
{
    if(m_sedContainer.count() > 0) {
        if(m_sedContainer.contains(key)) {
            return true;
        }
    }
    return false;
}


QList<QString> SedParser::erseteImage(const QDomNode &rootNode, QString praefix)
{
    QList<QString> params;
    //TODO: Format aus SED Datei lesen
    params << "image/png";
    for(int i=0; i < rootNode.childNodes().count(); i++) {
        QDomNode domNode = rootNode.childNodes().at(i);
        QDomElement domElement = domNode.toElement();
        QString variable;
        QString value;

        if(domElement.tagName() == "draw:image") {
            variable = domElement.attribute("xlink:href");
            variable.replace("@", "@" + praefix);

            if(m_posContainer.count() > 0) {
                params << m_posContainer.value(variable);
                variable = m_posContainer.value(variable);
                QFile barcodeImg(params.at(1));
                QString imgFile = "Pictures/" + barcodeImg.fileName().section('/', -1);
                domElement.setAttribute("xlink:href", imgFile);
            }
        }
    }
    return params;
}

/*!
   Prueft ob der Uebergebene string eine Zahl ist.
*/

bool SedParser::isNumber(QString value)
{
    //QRegExp rxlenFloatWithPoint1("^ *[ -]*[1-9]{1,3}(\\.[0-9]{3})*(,[0-9]+){0,1} *$"); // Zahl mit Tausenderpunkt
    //QRegExp rxlenFloatWithoutPoint1("^ *[ -]*[1-9]+*(,[0-9]+){0,1} *$"); // Zahl ohne Tausenderpunkt

    //with decimals
    QRegExp rxlenFloatWithPoint1("^ *[ -]*[0-9]{1,3}(\\.[0-9]{3})*(,[0-9]+) *$"); // Zahl mit Tausenderpunkt
    QRegExp rxlenFloatWithoutPoint1("^ *[ -]*[0-9]+(,[0-9]+) *$"); // Zahl ohne Tausenderpunkt
    //without decimals
    QRegExp rxlenFloatWithPoint2("^ *[ -]*[1-9]{1,3}(\\.[0-9]{3})* *$"); // Zahl mit Tausenderpunkt
    QRegExp rxlenFloatWithoutPoint2("^ *[ -]*[1-9]+ *$"); // Zahl ohne Tausenderpunkt

    if(rxlenFloatWithPoint1.exactMatch(value)) {
        return true;
    }

    if(rxlenFloatWithoutPoint1.exactMatch(value)) {
        return true;
    }

    if(rxlenFloatWithPoint2.exactMatch(value)) {
        return true;
    }

    if(rxlenFloatWithoutPoint2.exactMatch(value)) {
        return true;
    }

    return false;
}
