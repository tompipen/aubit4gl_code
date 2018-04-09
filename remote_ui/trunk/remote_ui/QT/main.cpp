/*
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
*/


/*!
 * \mainpage Ventas Desktop Client for Aubit4GL
 * \author Ventas AG 2006-2014
 * \date Februar 2012
 * \version 2.0
 */

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
#include "models/dialog.h"

#ifdef Q_OS_WIN
#include "windows.h"
#include "include/dbghelp.h"
#include <tchar.h>
#endif

#ifdef SSH_USE
#include "libssh/libssh.h"
#include "libssh/callbacks.h"
#endif

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
void crashingMessageHandler(QtMsgType type, const char *msg)
{

    if(MainFrame *main = qobject_cast<MainFrame*> (MainFrame::lastmainframe))
    {
        if(main->debugVDC)
        {
            switch(type)
            {
                case QtDebugMsg:
                   VDC::logMessage("VDC", QString("[Debug] - %1").arg(msg));
                   break;
                case QtWarningMsg:
                   VDC::logMessage("VDC", QString("[WARNING] - %1").arg(msg));
                   break;
                case QtCriticalMsg:
                   VDC::logMessage("VDC", QString("[CRITICAL] - %1").arg(msg));
                   break;
                case QtFatalMsg:
                   VDC::logMessage("VDC", QString("[FATAL] - %1").arg(msg));
                   break;
            }
        } else {
            switch (type) {
                case QtDebugMsg:
                    fprintf(stderr, "Debug: %s\n", msg);
                    break;
                case QtWarningMsg:
                    fprintf(stderr, "Warning: %s\n", msg);
                    break;
                case QtCriticalMsg:
                    fprintf(stderr, "Critical1: %s\n", msg);
                    break;
                case QtFatalMsg:
                    fprintf(stderr, "Fatal: %s\n", msg);
                    //__asm("int3");
                    abort();
              }
        }
    }
    /*QString text = "";
    const int USE_DEBUG_FILE = 0;

    if(USE_DEBUG_FILE == 1)
    {
        switch(type)
        {
            case QtDebugMsg:
                text = QString("Debug %1").arg(msg);
                break;
            case QtWarningMsg:
                text = QString("Warning: %1").arg(msg);
                break;
            case QtCriticalMsg:
                text = QString("Critical: %1").arg(msg);
                break;
            case QtFatalMsg:
                text = QString("Fatal: %1").arg(msg);
                break;
        }

        QFile file(QDir::currentPath() + "/debug.txt");
        file.open(QIODevice::WriteOnly | QIODevice::Append);

        QTextStream outStream(&file);
        outStream << text << endl;
    }
    else
    {
        switch (type) {
            case QtDebugMsg:
                fprintf(stderr, "Debug: %s\n", msg);
                break;
            case QtWarningMsg:
                fprintf(stderr, "Warning: %s\n", msg);
                break;
            case QtCriticalMsg:
                fprintf(stderr, "Critical1: %s\n", msg);
                break;
            case QtFatalMsg:
                fprintf(stderr, "Fatal: %s\n", msg);
                __asm("int3");
                abort();
          }
    }*/
}
#else
void crashingMessageHandler(QtMsgType type, const QMessageLogContext &ctx, const QString &msg)
{
    Q_UNUSED(ctx);

    if(MainFrame *main = qobject_cast<MainFrame*> (MainFrame::lastmainframe))
    {
        if(main->debugVDC)
        {
            switch(type)
            {
                case QtDebugMsg:
                    VDC::logMessage("VDC", QString("[Debug] - %1").arg(msg));
                   break;
                case QtWarningMsg:
                   VDC::logMessage("VDC", QString("[WARNING] - %1").arg(msg));
                   break;
                case QtCriticalMsg:
                   VDC::logMessage("VDC", QString("[CRITICAL] - %1").arg(msg));
                   break;
                case QtFatalMsg:
                   VDC::logMessage("VDC", QString("[FATAL] - %1").arg(msg));
                   break;
            }
        } else {
            QByteArray ba = msg.toLocal8Bit();
            const char *cd = ba.data();
            switch (type) {
                case QtDebugMsg:
                    fprintf(stderr, "Debug: %s\n", cd);
                    break;
                case QtWarningMsg:
                    fprintf(stderr, "Warning: %s\n", cd);
                    break;
                case QtCriticalMsg:
                    fprintf(stderr, "Critical1: %s\n", cd);
                    break;
                case QtFatalMsg:
                    fprintf(stderr, "Fatal: %s\n", cd);
                    //__asm("int3");
                    abort();
              }
        }
    }
}
#endif

#ifdef Q_OS_WIN
void CreateMiniDump( EXCEPTION_POINTERS* pep )
{
  // Open the file
typedef BOOL (*PDUMPFN)(
  HANDLE hProcess,
  DWORD ProcessId,
  HANDLE hFile,
  MINIDUMP_TYPE DumpType,
  PMINIDUMP_EXCEPTION_INFORMATION ExceptionParam,
  PMINIDUMP_USER_STREAM_INFORMATION UserStreamParam,
  PMINIDUMP_CALLBACK_INFORMATION CallbackParam

);
#if (QT_VERSION > QT_VERSION_CHECK(5, 9, 1))
    HANDLE hFile = CreateFile( _T("MiniDump.dmp"), GENERIC_READ | GENERIC_WRITE,
    0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );
#else
    HANDLE hFile = CreateFileA( _T("MiniDump.dmp"), GENERIC_READ | GENERIC_WRITE,
    0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );
#endif
    HMODULE h = ::LoadLibrary(L"DbgHelp.dll");
    PDUMPFN pFn = (PDUMPFN)GetProcAddress(h, "MiniDumpWriteDump");

  if( ( hFile != NULL ) && ( hFile != INVALID_HANDLE_VALUE ) )
  {
    // Create the minidump

    MINIDUMP_EXCEPTION_INFORMATION mdei;

    mdei.ThreadId           = GetCurrentThreadId();
    mdei.ExceptionPointers  = pep;
    mdei.ClientPointers     = TRUE;

    MINIDUMP_TYPE mdt       = MiniDumpNormal;

    BOOL rv = (*pFn)( GetCurrentProcess(), GetCurrentProcessId(),
      hFile, mdt, (pep != 0) ? &mdei : 0, 0, 0);
    Q_UNUSED(rv);



    // Close the file

    CloseHandle( hFile );

  }

}

LONG WINAPI HandleExceptionFilter(struct _EXCEPTION_POINTERS* ExceptionInfo)
{
    CreateMiniDump(ExceptionInfo);
    return EXCEPTION_EXECUTE_HANDLER;
}
#endif



//--------------------------------------------------------- (C) VENTAS AG 2006 -
// Filename     : main.cpp
// Function     : main()
// Description  : starts the application
//                starts main frame (so called damon)
//------------------------------------------------------------------------------

int main(int argc, char *argv[])
{

    QApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
    QApplication::setQuitOnLastWindowClosed(false);
    QApplication app(argc, argv);

    VDC::logMessage("VDC", "VDC wird gestartet...");

    #ifdef SSH_USE
    ssh_threads_set_callbacks(ssh_threads_get_noop());
    ssh_init();
    #endif

    #ifdef Q_OS_WIN
        SetUnhandledExceptionFilter(HandleExceptionFilter);
    #endif

    QSplashScreen *splash = new QSplashScreen;
    ScreenHandler::setSearchPaths();
    splash->setPixmap(QPixmap(":pics/VENTAS_11_splashscreen.png"));

    splash->show();

    QCoreApplication::setOrganizationName("VENTAS");
    QCoreApplication::setOrganizationDomain("ventas.de");
    QCoreApplication::setApplicationName("VDC - Ventas Desktop Client");

    QString translatorFileName = QLatin1String("qt_");
    translatorFileName += QLocale::system().name();
    QTranslator *translator = new QTranslator(&app);

    if (translator->load(translatorFileName, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
    {
       app.installTranslator(translator);
    }

    QFontDatabase::addApplicationFont(":/font/OpenSans-Regular.ttf");
    QFontDatabase::addApplicationFont(":/font/OpenSans-Semibold.ttf");
    #ifdef Q_OS_MAC
        QFont yavcFont("Open Sans Semibold", 12);
    #else
        QFont yavcFont("Open Sans Semibold", 10);
    #endif
    yavcFont.setFixedPitch(true);

    app.setFont(yavcFont);


    #ifdef Q_OS_MAC
       QIcon ventasLogo(":pics/vdc.icns");
    #else
       QIcon ventasLogo(":pics/vdc.png");
    #endif

    app.setWindowIcon(ventasLogo);

    QEvent::registerEventType(1337);
    //Event to separate Keys for the Puffers(same like KeyPress)
    QEvent::registerEventType(1400);
    //Event to seperate Keys for the Puffers(same like KeyRelease)
    QEvent::registerEventType(1401);

    // we need to register the QStringList with the meta-object system
    // to make it usable for signal/slot connections

    qRegisterMetaType<QStringList>("QStringList");
    qRegisterMetaType<QModelIndex>("QModelIndex");
    qRegisterMetaType<QModelIndex>("QDomDocument");
    qRegisterMetaType<QModelIndex>("QDomElement");

    int posX = VDC::readSettingsFromIni("Ventas AG", "posX").toInt();
    int posY = VDC::readSettingsFromIni("Ventas AG", "posY").toInt();

    MainFrame *mainframe = new MainFrame;
    mainframe->move(VDC::widgetPositionValidate(posX, posY));
    mainframe->progName = argv[0];

    mainframe->addSystemProxy();

    if(mainframe->listenToPort(1350)) {
        mainframe->show();
        mainframe->adjustSize();
        mainframe->activateWindow();
        mainframe->raise();
    }

    splash->finish(mainframe);
    qApp->installEventFilter(mainframe);
    VDC::logMessage("VDC", "VDC ist gestartet und bereit!");

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    qInstallMsgHandler(crashingMessageHandler);
#else
    qInstallMessageHandler(crashingMessageHandler);
#endif
    delete splash;
    return app.exec();
}
