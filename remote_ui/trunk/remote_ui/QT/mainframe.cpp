//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// File name    : mainframe.cpp
// Description  : contains the mainframe logic
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
#include <QtGui>
#include <QFile>
#include <QStatusBar>
#include <QHBoxLayout>

#include "mainframe.h"
#include "confwin.h"
#include "clienttcp.h"
#include "login.h"


//------------------------------------------------------------------------------
// Method       : MainFrame()
// Filename     : mainframe.cpp
// Description  : starts first screen window, starts tcp server (tcpListener)  
//------------------------------------------------------------------------------

MainFrame::MainFrame(bool onlyLogin, QWidget *parent)
    : QMainWindow(parent)
{
   p_currOpenNetwork=NULL;

   errorMessageMainFrame = new QErrorMessage(this);


   if(onlyLogin == false){
      tabWidget = new QTabWidget;
      setCentralWidget(tabWidget);

      setFixedSize(305,375);

      tabWidget->setGeometry(5,5,275,295);

      tabWidget->addTab(new ShortcutsTab(this),   tr("Shortcuts"));
      tabWidget->addTab(new OptionsTab(),          tr("Options"));
      tabWidget->addTab(new ConnectionsTab(),      tr("Connections"));

      // setting up actions for the clients toolbar
      //
      exitAction = new QAction(tr("Exit"), this);
      exitAction->setShortcut(tr("Ctrl+Q"));
      exitAction->setStatusTip(tr("Exit Client"));

      connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

      QToolBar *mainFrameToolBar = new QToolBar(tr("ToolBar"));
      mainFrameToolBar->addAction(exitAction); 

      mainFrameToolBar->setAllowedAreas(Qt::BottomToolBarArea); 
      addToolBar(Qt::TopToolBarArea, mainFrameToolBar);

      // making the statusbar
      //
      createStatusBar();
   }
   else{
      LoginForm *loginForm = new LoginForm;
      setCentralWidget(loginForm);
   }
      setWindowTitle(tr("VDC - Ventas Desktop Client"));

   // start listening to the network
   //
   tcpListener();
}


//------------------------------------------------------------------------------
// Method       : createStatusBar()
// Filename     : mainframe.cpp
// Description  : createStatusBar logic
//------------------------------------------------------------------------------

void MainFrame::createStatusBar()
{
   statusBar()->showMessage(tr("Welcome..."));
}


//------------------------------------------------------------------------------
// Method       : ConnectionsTab()
// Filename     : mainframe.cpp
// Description  : constructor for the instances
//------------------------------------------------------------------------------

ConnectionsTab::ConnectionsTab(QWidget *parent)
    : QWidget(parent)
{
}


//------------------------------------------------------------------------------
// Method       : OptionsTab()
// Filename     : mainframe.cpp
// Description  : constructor for the instances
//------------------------------------------------------------------------------

OptionsTab::OptionsTab(QWidget *parent)
    : QWidget(parent)
{
}


//------------------------------------------------------------------------------
// Method       : ShortcutsTab()
// Filename     : mainframe.cpp
// Description  : calling programs for testing
//------------------------------------------------------------------------------

ShortcutsTab::ShortcutsTab(MainFrame *mf, 
QWidget *parent) : QWidget(parent)
{
   errorMessageMainFrame = new QErrorMessage(this);
   QLabel *topLabel      = new QLabel(tr("Select Shortcut:"));
   shortcutsListBox      = new QListWidget;
   QStringList shortcutsList;
   QString qs_Filename;

   p_mainframe = mf;

   QSettings settings("shortcuts.ini", QSettings::IniFormat, this);
   QStringList groups = settings.childGroups();

   for(int i = 0; i < groups.count(); ++i){
      qs_Filename = groups.at(i);

      if(readFile(qs_Filename, i)){
         shortcutsList.append(qs_Filename);
      }
   }

   shortcutsListBox->insertItems(0, shortcutsList);

   QVBoxLayout *layout = new QVBoxLayout;
   layout->addWidget(topLabel);
   layout->addWidget(shortcutsListBox);

   QPushButton *connectButton = new QPushButton(tr("Connect"));
   QPushButton *addButton     = new QPushButton(tr("Add"));
   QPushButton *delButton     = new QPushButton(tr("Delete"));

   connectButton->setFocus(); 
   connectButton->update();

   connect(connectButton, SIGNAL(clicked()), this, SLOT(requestApplication()));
   connect(addButton,     SIGNAL(clicked()), this, SLOT(addConfwin()));
   connect(delButton,     SIGNAL(clicked()), this, SLOT(delConfwin()));

   connect(shortcutsListBox, SIGNAL(itemDoubleClicked(QListWidgetItem *)),  
           this, SLOT(editConfwin(QListWidgetItem *)));

   QHBoxLayout *buttonLayout = new QHBoxLayout;
   buttonLayout->addStretch(1);
   buttonLayout->addWidget(connectButton);
   buttonLayout->addWidget(addButton);
   buttonLayout->addWidget(delButton);
   layout->addLayout(buttonLayout);

   setLayout(layout);

}


//------------------------------------------------------------------------------
// Method       : editConfwin()
// Filename     : mainframe.cpp
// Description  : edit shortcuts logic
//------------------------------------------------------------------------------

void ShortcutsTab::editConfwin(QListWidgetItem *p_currWidgetItem)
{

   // instantiating configuration window to edit shortcuts
   //    - we've to check for null pointer exceptions before
   //
   if(p_currWidgetItem==NULL){
       errorMessageMainFrame->showMessage(
          tr("Error: shortcutsListBox->currentItem() "
	     "       returned a NULL-Pointer!!!"));
   }else{

       // now we can instantiate this class without fear
       //
       ConfWin *confwin = new ConfWin(p_currWidgetItem->text());
       confwin->show();

       connect(confwin, SIGNAL(accepted()), this, SLOT(updateListBox()));
   }
}


//------------------------------------------------------------------------------
// Method       : addConfwin()
// Filename     : mainframe.cpp
// Description  : add shortcuts logic
//------------------------------------------------------------------------------

void ShortcutsTab::addConfwin()
{
   bool ok;
   QString fname = QInputDialog::getText(this, tr("Add Shortcut"),
                                        tr("Filename:"), QLineEdit::Normal,
                                        "", &ok);
   if (ok && !fname.isEmpty()){
      ConfWin *confwin = new ConfWin(fname);
      confwin->show();

      // when adding is finished, we have to refresh the listbox
      //
      //  --- better put this connect in the constructor...
      //
      //
      connect(confwin, SIGNAL(accepted()), this, SLOT(updateListBox()));
   }
}


//------------------------------------------------------------------------------
// Method       : delConfwin()
// Filename     : mainframe.cpp
// Description  : delete shortcuts logic
//------------------------------------------------------------------------------

void ShortcutsTab::delConfwin()
{
   QListWidgetItem *p_currWidgetItem = shortcutsListBox->currentItem();

   // checking which entry is selected for being deleted
   //
   if(p_currWidgetItem==NULL){
      p_mainframe->statusBar()->showMessage(
            tr("Please select a File first!"),2000);
   }else{

      if(delFile(p_currWidgetItem->text())){
         QSettings settings("shortcuts.ini", QSettings::IniFormat, this);
         settings.remove(p_currWidgetItem->text());

         // when file was succesfully deleted, we have to update the listbox
         //
         updateListBox();
      }
   }
}


//------------------------------------------------------------------------------
// Method       : delFile()
// Filename     : mainframe.cpp
// Description  : deletes a file from disk
//------------------------------------------------------------------------------

bool ShortcutsTab::delFile(QString p_cFilename)
{
   QFile file(p_cFilename);

   if (!file.remove()){
      errorMessageMainFrame->showMessage(
            tr("ERROR: Cannot delete: %1").arg(p_cFilename));
      return false;
   };

   return true;
}


//------------------------------------------------------------------------------
// Method       : readFile()
// Filename     : mainframe.cpp
// Description  : read binary data from a file
//------------------------------------------------------------------------------

bool ShortcutsTab::readFile(QString p_cFilename, int i)
{
   quint32 n;
   QFile file(p_cFilename);

   if (!file.open(QIODevice::ReadOnly)){
      return false;

   }else{

       QDataStream in(&file);
       in.setVersion(QDataStream::Qt_4_1);

       in >> n >> u_Shortcuts.qs_Username 
               >> u_Shortcuts.qs_Password
               >> u_Shortcuts.qs_Application
               >> u_Shortcuts.qs_Protocol
               >> u_Shortcuts.qs_IPadress;

       u_arr_Shortcuts[i].qs_Username    = u_Shortcuts.qs_Username;
       u_arr_Shortcuts[i].qs_Password    = u_Shortcuts.qs_Password;
       u_arr_Shortcuts[i].qs_Application = u_Shortcuts.qs_Application;
       u_arr_Shortcuts[i].qs_Protocol    = u_Shortcuts.qs_Protocol;
       u_arr_Shortcuts[i].qs_IPadress    = u_Shortcuts.qs_IPadress;

   }
   return true;
}


//------------------------------------------------------------------------------
// Method       : updateListBox()
// Filename     : mainframe.cpp
// Description  : updates the entries in list box after making new files
//------------------------------------------------------------------------------

void ShortcutsTab::updateListBox()
{
   QString fname;
   QStringList shortcutsList;

   QSettings settings("shortcuts.ini", QSettings::IniFormat, this);
   QStringList groups = settings.childGroups();

   for(int i = 0; i < groups.count(); ++i){
      fname = groups.at(i);

      if(readFile(fname, i)){
         shortcutsList.append(fname);
      }
   }

   shortcutsListBox->clear();
   shortcutsListBox->insertItems(0, shortcutsList);
}


//------------------------------------------------------------------------------
// Method       : tcpListener()
// Filename     : mainframe.cpp
// Description  : listen to network port....
//------------------------------------------------------------------------------

void MainFrame::tcpListener()
{
   clientTcp = new ClientTcp(this);

   if(!clientTcp->listen(QHostAddress::Any, 1350)){
      errorMessageMainFrame->showMessage(
            tr("ERROR: Failed to bind to port"));
   }
}


//------------------------------------------------------------------------------
// Method       : updateListBox()
// Filename     : mainframe.cpp
// Description  : calls the selected program of the shortcut list
//------------------------------------------------------------------------------

void ShortcutsTab::requestApplication()
{
   QListWidgetItem *p_currWidgetItem = shortcutsListBox->currentItem();

   if(p_currWidgetItem==NULL){
      p_mainframe->statusBar()->showMessage(
            tr("Please select a File first!"),2000);
   }else{
      int i = shortcutsListBox->currentRow();
      ClientSocket *socket = new ClientSocket(0,
                                              u_arr_Shortcuts[i].qs_Username,
                                              u_arr_Shortcuts[i].qs_Password,
                                              u_arr_Shortcuts[i].qs_Application);
      socket->ph.b_read = false;
      socket->ph.b_write = false;

      socket->connectToHost(u_arr_Shortcuts[i].qs_IPadress,
                            3490);

      QList<ClientSocket*> ql_connections;
   }
}


//------------------------------------------------------------------------------
// Method       : dispErrToSB()
// Filename     : mainframe.cpp
// Description  : display QProcessErrors to Statusbar
//------------------------------------------------------------------------------

void ShortcutsTab::dispErrToSB(){

   QByteArray by_arr_newData = (QByteArray) p_openNetwork->readAllStandardError();

   QString qs_errText = QString::fromLocal8Bit(by_arr_newData);

}

void ShortcutsTab::dispStdOut(){

   QByteArray by_arr_newData = (QByteArray) p_openNetwork->readAllStandardOutput();
   QString qs_outText = QString::fromLocal8Bit(by_arr_newData);

}


//------------------------------------------------------------------------------
// Method       : processError()
// Filename     : mainframe.cpp
// Description  : processError logic
//------------------------------------------------------------------------------

void ShortcutsTab::processError(QProcess::ProcessError ProcessError){
   p_mainframe->statusBar()->showMessage(tr("ERROR: plink.exe: "
         "  %1 ").arg((ProcessError)),2000);
}


//------------------------------------------------------------------------------
// Method       : processFin()
// Filename     : mainframe.cpp
// Description  : process finish logic
//------------------------------------------------------------------------------

void ShortcutsTab::processFin(int i_exitCode, QProcess::ExitStatus exitStatus){

   Q_UNUSED(exitStatus);

   if(i_exitCode == QProcess::CrashExit){

   }else if(i_exitCode != 0){
      p_mainframe->statusBar()->showMessage(tr("plink.exe failed"),2000);

   }else{
      p_mainframe->statusBar()->showMessage(tr("plink.exe: normal exit"),2000);
   }
   p_openNetwork->close();

}


//------------------------------------------------------------------------------
// Method       : lookupForIP()
// Filename     : mainframe.cpp
// Description  : look it up...
//------------------------------------------------------------------------------

void ShortcutsTab::lookupForIP()
{
   QHostInfo::lookupHost(QHostInfo::localHostName(), 
                         this, SLOT(ipLookupResults(QHostInfo)));

}


//------------------------------------------------------------------------------
// Method       : ipLookupResults()
// Filename     : mainframe.cpp
// Description  : look it up...
//------------------------------------------------------------------------------

void ShortcutsTab::ipLookupResults(const QHostInfo& host)
{

  qs_ipAddress.clear();

  if (host.error() != QHostInfo::NoError) {
      return;
  }

  foreach (QHostAddress address, host.addresses()){
      qs_ipAddress.append(address.toString());
  }
}


//------------------------------------------------------------------------------
// Method       : cleanUp()
// Filename     : mainframe.cpp
// Description  : cleanUp logic for mainframe class
//------------------------------------------------------------------------------

void MainFrame::cleanUp()
{
   // close the ssh connection if established
   //

   if(p_currOpenNetwork!=NULL){

      if(!p_currOpenNetwork->state()==0){
         p_currOpenNetwork->close();
      }
   }

   if(clientTcp==NULL){
   }else{
      clientTcp->close();
      delete clientTcp;
   }
}

//------------------------------------------------------------------------------
// Method       : closeEvent()
// Filename     : mainframe.cpp
// Description  : override the closeEvent
//------------------------------------------------------------------------------
void MainFrame::closeEvent(QCloseEvent *event)
{
   event->ignore();
   QMessageBox *messagebox = new QMessageBox();
   int quit = 0;

      if(clientTcp->socket != NULL && (clientTcp->socket->state() >0 && clientTcp->socket->state() <6))
      {
         quit = messagebox->question(0,
                                     tr("VDC - Ventas Desktop Client"),
                                     tr("There are open Connections.\n"
                                        "Do you really want to quit?"),
                                     tr("&Yes"), tr("&No"),
                                     QString(), 0, 1);
      }

      if(quit == 0){
         cleanUp();
         event->accept();
         close();
      }
}
