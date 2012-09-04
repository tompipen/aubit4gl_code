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
#include <QSplashScreen>
#include <QFontDatabase>
#include <QSettings>
#include "confwin.h"
#include "mainframe.h"
#include "login.h"
#include "clienttcp.h"
#include <string>
#include <iostream>

#ifdef SSH_USE
#include "libssh/libssh.h"
#include "libssh/callbacks.h"
#endif

/*#ifdef Q_WS_X11
#include "client/linux/handler/exception_handler.h"

static bool dumpCallback(const google_breakpad::MinidumpDescriptor &md,
                         void* context,
                         bool succeeded)
{
     printf("Dump path: %s\n", md.path());
     return succeeded;
}

void crash()
{
  volatile int* a = (int*)(NULL);
  *a = 1;
}
#endif
*/

//--------------------------------------------------------- (C) VENTAS AG 2006 -
// Filename     : main.cpp
// Function     : main()
// Description  : starts the application
//                starts main frame (so called damon)
//------------------------------------------------------------------------------
/*!
 * \mainpage Ventas Desktop Client for Aubit4GL
 * \author Ventas AG 2006-2012
 * \date Februar 2012
 * \version 1.0
 */

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    #ifdef SSH_USE
    ssh_threads_set_callbacks(ssh_threads_get_pthread());
    ssh_init();
    #endif

/*    QString crashdumpTmp = QDir::currentPath() + "/crashreport";
    const std::string &clientTmpDir = crashdumpTmp.toStdString();

    QDir dir(crashdumpTmp);

    if(!dir.exists())
    {
        dir.mkdir(crashdumpTmp);
    }

    #ifdef Q_WS_X11
    google_breakpad::MinidumpDescriptor md(clientTmpDir);
    google_breakpad::ExceptionHandler eh(md, NULL, dumpCallback, NULL, true, -1);
    #endif
*/

    QSplashScreen *splash = new QSplashScreen;
    ScreenHandler::setSearchPaths();
    //splash->setPixmap(QPixmap("./pics/splash.png"));
    splash->setPixmap(QPixmap("pics:VENTAS_9_splashscreen.png"));
    QEvent::registerEventType(1337);
    //Event to seperate Keys for the Puffers(same like KeyPress)
    QEvent::registerEventType(1400);
    //Event to seperate Keys for the Puffers(same like KeyRelease)
    QEvent::registerEventType(1401);

    splash->show();
    QString fileName; 
    QCoreApplication::setOrganizationName("VENTAS");
    QCoreApplication::setOrganizationDomain("ventas.de");
    QCoreApplication::setApplicationName("VDC - Ventas Desktop Client");

    //sleep(3);


    QString translatorFileName = QLatin1String("qt_");
    translatorFileName += QLocale::system().name();
    QTranslator *translator = new QTranslator(&app);

    if (translator->load(translatorFileName, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
       app.installTranslator(translator);


//    if(argc >= 2 &&
//       QString(argv[1]) == "-l")
//       loginForm = true;

    QFontDatabase::addApplicationFont(":/font/LiberationMono-Regular.ttf");
    QFont yavcFont("Arial", 8);
    yavcFont.setFixedPitch(true);

    app.setFont(yavcFont);


    #ifdef Q_WS_MAC
       QIcon ventasLogo("pics:vdc.icns");
    #else
       QIcon ventasLogo("pics:vdc.png");
    #endif

    app.setWindowIcon(ventasLogo);

    // we need to register the QStringList with the meta-object system
    // to make it usable for signal/slot connections
    //
    qRegisterMetaType<QStringList>("QStringList");
    qRegisterMetaType<QModelIndex>("QModelIndex");
    qRegisterMetaType<QModelIndex>("QDomDocument");
    qRegisterMetaType<QModelIndex>("QDomElement");
    MainFrame mainframe;
    mainframe.move(VDC::readSettingsFromIni("Ventas AG", "posX").toInt(), VDC::readSettingsFromIni("Ventas AG", "posY").toInt());
    mainframe.show();
    mainframe.adjustSize();


    splash->finish(&mainframe);
    mainframe.activateWindow();
    mainframe.raise();
    delete splash;
    return app.exec();
}
