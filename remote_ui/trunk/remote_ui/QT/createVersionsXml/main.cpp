#include <QtCore/QCoreApplication>
#include <QXmlStreamWriter>
#include <QDir>
#include <QDebug>
#include <QDate>
#include <QCryptographicHash>
#include <QByteArray>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QByteArray ba_file;


    qDebug() << "QDir:: " << QDir::currentPath();
    QFile *file = new QFile(QDir::currentPath() + "../../versions.xml");
    if(!file->open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        qWarning("Cannot open file!");
        //qWarning(QString("Cannot create versions.xml in: %1\nPlease check Permissions!").arg(QDir::currentPath()));
        return 1;
    }
    QXmlStreamWriter *writer = new QXmlStreamWriter(file);

    writer->writeStartDocument();
    writer->writeStartElement("VDC");

#ifdef Q_WS_WIN32
    writer->writeStartElement("WINDOWS");
#endif
#ifdef Q_WS_MAC
    writer->writeStartElement("MAC");
#endif
#ifdef Q_WS_X11
    writer->writeStartElement("LINUX");
#endif

    writer->writeTextElement("VDC_RELEASE_DATE", QDate::currentDate().toString(QString("dd.MM.yyyy")));
    QFile *fileHash = new QFile(QDir::currentPath() + "../../release/VDC.exe");
    if(!fileHash->open(QFile::ReadOnly))
    {
        writer->writeTextElement("VDC_CHECKSUM", "0");
    } else {
        ba_file = fileHash->readAll();
        QCryptographicHash hash(QCryptographicHash::Md5);
        hash.addData(ba_file);
        QByteArray ba_hash = hash.result().toHex();
        writer->writeTextElement("VDC_CHECKSUM", ba_hash.data());
    }
    writer->writeTextElement("A4GL_VERSION", "1.2.29");
    writer->writeTextElement("XML_VERSION", "1.0");
    writer->writeEndElement();
    writer->writeEndDocument();

    file->close();

    qWarning("bin am ende angekommen");

    return 0;

}
