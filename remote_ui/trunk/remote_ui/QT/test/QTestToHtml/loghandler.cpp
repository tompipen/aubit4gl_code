// Project: QTestToHTML
// Author:  Maximilian Seidel
// File:    loghandler.cpp
// This file may be used under the terms of the GNU General Public
// License version 2.0 as published by the Free Software Foundation
// (http://www.gnu.org/licenses/gpl-2.0.html)
//
// This file is provided AS IT IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
// Enjoy using it!
//
//------------------------------------------------------------------------------



#include "loghandler.h"
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>

LogHandler::LogHandler(QString filename ,QObject *parent) :
    QObject(parent)
{
    this->setFileName(filename);

}

bool LogHandler::start()
{
    if(this->getFileName().isEmpty())
    {
        qWarning("No File in LogHandler");
        return false;
    }

    QStringList htmldoc = this->initLog();
    QStringList buffer;
    bool headerflag = false;
    bool bodyflag   = false;
    bool footerflag = false;
    QFile file(this->getFileName());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    int i = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();

        if((line.contains("PASS") || line.contains("SKIP") || line.contains("FAIL") )&& !headerflag)
        {
            htmldoc << this->handleHead(buffer);
            buffer.clear();
            headerflag = true;
        }

        if((line.contains("Totals:")) && !bodyflag)
        {
            htmldoc<< this->handleTableBody(buffer);
            buffer.clear();
            bodyflag = true;
        }


        buffer << line;


        i++;
    }

    htmldoc << this->handleFooter(buffer);

    this->setHtmlString(htmldoc);
    file.close();
    return true;

}

void LogHandler::setHtmlString(QStringList qsl)
{
    QString set;
    for(int i = 0; i<qsl.count(); i++)
    {
        set += qsl.at(i)+  "\n";
    }

    this->htmlstring = set;
}

QString LogHandler::getHtmlString()
{
    return this->htmlstring;
}

QStringList LogHandler::initLog()
{
    QStringList qsl_returnLines;
    QString style = "style.css";
    if(!this->isonlyTable())
    {
       qsl_returnLines << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \n \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">";
       qsl_returnLines << "<html><head>";
       qsl_returnLines << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\"/>";
       qsl_returnLines << "<title>QT-Unittest Report Results Summary</title>";
    }

    QFile styles(style);

    if (styles.open(QIODevice::ReadOnly | QIODevice::Text) && !this->isonlyTable())
    {
    qsl_returnLines << "<style type=\"text/css\">";

    QTextStream in(&styles);

    while (!in.atEnd()) {
        qsl_returnLines << in.readLine();

   }
    qsl_returnLines <<"</style>";
    }
    if(!this->isonlyTable())
    {
       qsl_returnLines << "</head><body><h3>QT-Unittest Report Results Summary</h3><br>";
    }
    qsl_returnLines << "<table id=\"tablebody\">";
    return qsl_returnLines;
}

QStringList LogHandler::handleHead(QStringList lines)
{
    QStringList returnLines;
    for(int i = 0; i<lines.count(); i++)
    {
        QString line = lines.at(i);
        QString htmlline;
        if(i == 0)
        {
            returnLines<<"<tr id=\"rowtestname\">";
            returnLines<<"<td id=\"namelabel\">Testcase</td>";

            QString testname;

            testname = line.replace("*", "");

            testname = testname.trimmed();

            QStringList namesplit;
            namesplit = testname.split(" ");

            testname = namesplit.last();

            returnLines<<"<td id=\"namefield\">"+testname+"</td>";
        }
        if(i == 1)
        {
            returnLines<<"<tr id=\"rowqt\">";
            returnLines<<"<td id=\"qtlabel\">Qt Config</td>";
            returnLines<<"<td id=\"qtfield\">"+line.split(":").at(1).trimmed()+"</td>";


        }
    }
    return returnLines;
}

QStringList LogHandler::handleTableBody(QStringList lines)
{
    QStringList returnLines;
    bool start = true;
    bool ende   = false;
    for(int i = 0; i<lines.count(); i++)
    {
        QString line = lines.at(i);
        QString htmlline;
        if(i == 0)
        {
            returnLines << "<tr id=\"rowheadline\">";
            returnLines << "<td id =\"statusheadline\"> Status</td>";
            returnLines << "<td id =\"methodheadline\"> Testmethod </td>";
            returnLines << "</tr>";
        }


        QStringList linesplit = line.split(":");
        if(linesplit.at(0).trimmed().contains("PASS") || linesplit.at(0).trimmed().contains("FAIL") || linesplit.at(0).trimmed().contains("SIL"))
        {
           ende  = true;
           start = true;
        }
 
        if(start)
        {
       

           if(ende && i > 0)
           {
              returnLines <<"</td></tr>";
           }
           returnLines<<"<tr id=\"row" + QString::number(i) + "\">";
           start = false;
           ende = false;
           if(linesplit.at(0).trimmed().contains("PASS"))
           {
               returnLines << "<td id=\"passtdlabel\" bgcolor=\"green\">PASS</td><td id=\"passtdfield\">";
               line.remove(0, linesplit.at(0).size()+1);
           }

           if(linesplit.at(0).trimmed().contains("FAIL"))
           {
               returnLines << "<td id=\"failtdlabel\" bgcolor=\"red\">FAIL</td><td id=\"failtdfield\">";
               line.remove(0, linesplit.at(0).size()+1);
           }


           if(linesplit.at(0).trimmed().contains("SKIP"))
           {
               returnLines << "<td id=\"skiptdlabel\"  bgcolor=\"yellow\">SKIP</td><td id=\"skiptdfield\">";
               line.remove(0, linesplit.at(0).size()+1);
           }

        }
       
       returnLines << line.trimmed() + "<br>";


    }

    return returnLines;
}

QStringList LogHandler::handleFooter(QStringList lines)
{
    QStringList returnLines;
    for(int i = 0; i<lines.count(); i++)
    {
        QString line = lines.at(i);
        QString htmlline;
        if(i == 0)
        {
            returnLines<<"<tr id=\"rowtestsummary\">";
            returnLines<<"<td id=\"namelabel\">Testsummary</td>";
            QStringList qsl_tmpfirst = line.split(":");
            QStringList qsl_values = qsl_tmpfirst.at(1).split(",");

            QString color;

            if(qsl_values.at(0).trimmed().startsWith("0"))
            {
                color = "red";
            }
            else
            {
                color = "green";
            }

            returnLines<<"<td bgcolor=\""+color+"\" id=\"passfield\">"+qsl_values.at(0)+"</td>";

            if(qsl_values.at(1).trimmed().startsWith("0"))
            {
                color = "green";
            }
            else
            {
                color = "red";
            }

            returnLines<<"<td bgcolor=\""+color+"\" id=\"failfield\">"+qsl_values.at(1)+"</td>";

            if(qsl_values.at(2).trimmed().startsWith("0"))
            {
                color = "green";
            }
            else
            {
                color = "yellow";
            }

            returnLines<<"<td bgcolor=\""+color+"\" id=\"skipfield\">"+qsl_values.at(2)+"</td>";
            returnLines<<"</tr>";
        }
    }
    returnLines <<"</table>";
    if(!this->isonlyTable())
    {
       returnLines <<"</body></html>";
    }
    return returnLines;
}

void LogHandler::setFileName(QString n)
{
    this->filename = n;
}

QString LogHandler::getFileName()
{
    return this->filename;
}
void LogHandler::onlyTable(bool b)
{
   this->onlytable = b;
}

bool LogHandler::isonlyTable()
{
   return this->onlytable;
}
