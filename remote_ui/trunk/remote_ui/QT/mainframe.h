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

#include "clienttcp.h"
#include "confwin.h"


//class MainFrame : public QDialog
class MainFrame : public  QMainWindow
{
   Q_OBJECT

public:
   MainFrame(bool onlyLogin = false, QWidget *parent = 0);
   QProcess *p_currOpenNetwork;



public slots:
   void cleanUp();

private:
   QTabWidget *tabWidget;
   QErrorMessage *errorMessageMainFrame;
   void tcpListener();
   void createStatusBar();
   ClientTcp *clientTcp;
   QAction *exitAction;
   QToolBar *mainFrameToolBar;


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
};


class ConnectionsTab : public QWidget
{
   Q_OBJECT

public:
   ConnectionsTab(QWidget *parent = 0);
};


#endif
