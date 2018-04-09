//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : mainframe.h
// Description  : contains the mainframe class definition, tabs etc.
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
#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QDialog>
//#include <QProcess>
#include <qprocess.h>
#include <QFileInfo>
#include <QString>
#include <QTabWidget>
#include <QListWidgetItem>
#include <QStatusBar>
#include <QMainWindow>
#include <QHostInfo>
#include <QTableWidget>
#include <QSystemTrayIcon>
#include <QKeyEvent>

#include "clienttcp.h"
#include "include/fgl.h"
#include "confwin.h"
#include <screenhandler.h>

class ConnectionsTab : public QWidget
{
   Q_OBJECT;

public:
   ConnectionsTab(QWidget *parent = 0);
   int row;
   QString portshow;
   int port;
   QList<int> listpruef;


   private:
      QTableWidget *tableWidget;

   public slots:
      void addConnection();
      void delConnection();

};

//class MainFrame : public QDialog1
class MainFrame : public  QMainWindow
{
   Q_OBJECT

public:
   MainFrame(QWidget *parent = 0);
   QProcess *p_currOpenNetwork;
   ClientTcp *clientTcp;
   bool adminMenu;
   static QString progName;
   static bool b_debugmodus;
   static MainFrame *lastmainframe;
   static void vdcdebug(QString, QString, QString);
   virtual bool eventFilter(QObject *, QEvent *);
   static QList<ScreenHandler*> *ql_screenhandler;
   static void check_new_pids();
   static bool setFocusOn(int);
   void requestScreenHandler(int, int);
   QString getUserName() { return userName; }
   bool debugVDC;
   int closeSSH;
   bool listenToPort(quint16 Port);
   void addSystemProxy();

   //QSystemTrayIcon getSystemTray() {return mTray; }

public slots:
   void cleanUp();
   void debugClose();
   void deleteScreenHandler(int pid, int p_pid);
   void trayIconClicked(QSystemTrayIcon::ActivationReason);
   void closeAction();
   void debugText(QString text);
   void closeVDC();
   void setSystemTrayMessage(QString title, QString text) { mTray->showMessage(title, text); }
   void enableDebugModus();

private:
   bool b_lastAutoRepeat;
   QTabWidget *tabWidget;
   QErrorMessage *errorMessageMainFrame;
   void createStatusBar();
   QAction *exitAction;
   QToolBar *mainFrameToolBar;
   ConnectionsTab *connectionsTab;
   void ReadSettings();
   QString userName;
   QSystemTrayIcon *mTray;

signals:
       void debugSignal();

protected:
   void closeEvent(QCloseEvent *event);
   void contextMenuEvent(QContextMenuEvent*);
};


class ShortcutsTab : public QWidget
{
   Q_OBJECT

public:
   ShortcutsTab(MainFrame*, QWidget *parent = 0);
   bool readFile(QString, int);

   ShortcutsQS u_Shortcuts;
   ShortcutsQS u_arr_Shortcuts[30];

public slots:
   void requestApplication();
   void ipLookupResults(const QHostInfo&);

private slots:
   void editConfwin(QListWidgetItem *);
   void addConfwin();
   void delConfwin();
   void updateListBox();
   void processError(QProcess::ProcessError);
   void processFin(int, QProcess::ExitStatus);
   void dispErrToSB();
   void dispStdOut();

private:
   bool delFile(QString);
   QErrorMessage *errorMessageMainFrame;
   QListWidget *shortcutsListBox;

   QProcess openNetwork;
   QProcess *p_openNetwork;

   MainFrame *p_mainframe;

   void lookupForIP();
   QString qs_ipAddress;
};


class OptionsTab : public QWidget
{
   Q_OBJECT

public:
   OptionsTab(QWidget *parent = 0);
   QLineEdit *fontedit;
   QString fontconv;
   QStringList splitlist;
   QString fonteingabe;

signals:
    void showMessage(QString m);


public slots:
    void fontdialog();
    void writeSettings();
    void reset();
};

//class FontDialog : public QFontDialog
//{
//    Q_OBJECT
//
//    public:
//    FontDialog(QWidget *parent = 0);
//
//};




#endif
