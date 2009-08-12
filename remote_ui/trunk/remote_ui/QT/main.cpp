//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// File name    : main.cpp
// Description  : contains the main entry point
//------------------------------------------------------------------------------
//
// This file may be used under the terms of the GNU General Public
// License version 2.0 as published by the Free Software Foundation
// (http://www.gnu.org/licenses/gpl-2.0.html)
//
// This file is provided AS IT IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
// If you need professional Support please contact us at www.ventas.de
// Enjoy using it!
//
//------------------------------------------------------------------------------
#include <QApplication>
#include <QDebug>
#include <QLineEdit>

#include "confwin.h"
#include "mainframe.h"
#include "clienttcp.h"

//--------------------------------------------------------- (C) VENTAS AG 2006 -
// Filename     : main.cpp
// Function     : main()
// Description  : starts the application
//                starts main frame (so called damon)
//------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString fileName; 

    QCoreApplication::setOrganizationName("VENTAS");
    QCoreApplication::setOrganizationDomain("ventas.com");
    QCoreApplication::setApplicationName("VDC - Ventas Desktop Client");

    bool loginForm = false;

    loginForm = true;

    if(argc >= 2 &&
       QString(argv[1]) == "-l")
       loginForm = true;

    QFont yavcFont("Arial", 8);
    yavcFont.setFixedPitch(true);

    app.setFont(yavcFont);

    QIcon ventasLogo("./pics/ventas-ico.png");

    app.setWindowIcon(ventasLogo);

    MainFrame mainframe(loginForm);

    // we need to register the QStringList with the meta-object system
    // to make it usable for signal/slot connections
    //
    qRegisterMetaType<QStringList>("QStringList");
    qRegisterMetaType<QModelIndex>("QModelIndex");
    qRegisterMetaType<QModelIndex>("QDomDocument");
    qRegisterMetaType<QModelIndex>("QDomElement");

    mainframe.show();
   
    mainframe.activateWindow();
    mainframe.raise();

    return app.exec();
}
