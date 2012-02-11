// Project: QTestToHTML
// Author:  Maximilian Seidel
// File:    loghandler.h
// 2012
// This file may be used under the terms of the GNU General Public
// License version 2.0 as published by the Free Software Foundation
// (http://www.gnu.org/licenses/gpl-2.0.html)
//
// This file is provided AS IT IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
// Enjoy using it!
//
//------------------------------------------------------------------------------


#ifndef LOGHANDLER_H
#define LOGHANDLER_H

#include <QObject>

class LogHandler : public QObject
{
    Q_OBJECT
public:
    explicit LogHandler(QString, QObject *parent = 0);
    void setFileName(QString);
    QString getFileName();
    void setHtmlString(QStringList);
    QString getHtmlString();
    bool start();

private:
    QString filename;
    QString htmlstring;
    QStringList handleFooter(QStringList);
    QStringList handleHead(QStringList);
    QStringList handleTableBody(QStringList);
    QStringList initLog();
signals:

public slots:

};

#endif // LOGHANDLER_H
