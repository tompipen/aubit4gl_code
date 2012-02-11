#------------------------------------------------------------------------------
# Project: QTestToHTML
# Author:  Maximilian Seidel
# File:    main.cpp
# 2012
# This file may be used under the terms of the GNU General Public
# License version 2.0 as published by the Free Software Foundation
# (http://www.gnu.org/licenses/gpl-2.0.html)
#
# This file is provided AS IT IS with NO WARRANTY OF ANY KIND, INCLUDING THE
# WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
# Enjoy using it!
#
#------------------------------------------------------------------------------


#include <QtCore/QCoreApplication>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QFile>
#include <QTextStream>

#include "loghandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList argvs;
    QString inputfile;
    QString outputfile;
    argvs = QCoreApplication::arguments();
    for(int i =0; i<argvs.count();i++)
    {
        if(argvs.at(i) == "-i")
        {
            i++;
            inputfile = argvs.at(i);
        }
        if(argvs.at(i) == "-o")
        {
            i++;
            outputfile = argvs.at(i);
        }

    }

    if(outputfile.isEmpty())
    {
        if(inputfile.contains("."))
        {
            QString tempstring = inputfile;
            tempstring.remove(tempstring.indexOf("."), tempstring.length()-tempstring.indexOf("."));
            tempstring.append(".html");
            outputfile = tempstring;
        }
        else
        {
            outputfile = inputfile;

        }
    }


    if(outputfile.isEmpty())
    {
        qWarning("Outputfile is missing");
        return 1;
    }


    if(outputfile.isEmpty())
    {
        qWarning("Inputfile is missing");
        return 2;
    }

    LogHandler *lh = new LogHandler(inputfile);

    lh->start();
    QString html = lh->getHtmlString();

    QFile out(outputfile);
        if (!out.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qWarning("Cannot open Outputfile");
            return 3;
        }
        QTextStream outstream(&out);
        outstream << html;
        out.close();



    return 0;
}
