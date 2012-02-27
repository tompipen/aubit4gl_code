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
                                        ersetzen.replace("ß", "ss");
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
