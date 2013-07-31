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
#include "include/vdc.h"
#include "models/progress.h"

//------------------------------------------------------------------------------
// Method       : MainFrame()
// Filename     : mainframe.cpp
// Description  : starts first screen window, starts tcp server (tcpListener)
//------------------------------------------------------------------------------

void MainFrame::ReadSettings()
{
MainFrame::vdcdebug("MainFrame","ReadSettings", "");
    QSettings settings("Ventas AG", "Ventas Desktop Client");
    QVariant fontsetting = settings.value("font");
    QString fontsetting2;
    fontsetting2 = fontsetting.toString();
    QFont fontsetting3;
    fontsetting3.fromString(fontsetting2);

    QApplication::setFont(fontsetting3);
    if(fontsetting2 == "" || fontsetting2.contains("Liberation"))
    {
      QApplication::setFont(QFont("Arial", 8));
    }

    mTray = new QSystemTrayIcon(this);
    mTray->setIcon(QIcon("pics:vdc.png"));

    QMenu *menu = new QMenu;
    QAction *showAction = menu->addAction("Show Login Window");
    connect(showAction, SIGNAL(triggered()), this, SLOT(show()));

    QAction *hideAction = menu->addAction("Hide Login Window");
    connect(hideAction, SIGNAL(triggered()), this, SLOT(hide()));

    QAction *exitAction = menu->addAction("Exit");
    connect(exitAction, SIGNAL(triggered()), this, SLOT(closeAction()));

    mTray->setContextMenu(menu);
    connect(mTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(trayIconClicked(QSystemTrayIcon::ActivationReason)));

    mTray->show();
}

bool MainFrame::b_debugmodus = false;
MainFrame* MainFrame::lastmainframe = NULL;
QList<ScreenHandler*> *MainFrame::ql_screenhandler = new QList<ScreenHandler*>();

bool MainFrame::setFocusOn(int pid)
{
    QList<ScreenHandler*> *l_ql_screenhandler = MainFrame::ql_screenhandler;
    if(pid < 0)
    {
        return false;
    }

    for(int i=0; i<l_ql_screenhandler->count(); i++)
    {
        if(l_ql_screenhandler->at(i)->p_pid == pid)
        {
            if(l_ql_screenhandler->at(i)->b_runinfo)
            {
                if(l_ql_screenhandler->at(i)->p_pid_p > 0)
                {
                    return MainFrame::setFocusOn(l_ql_screenhandler->at(i)->p_pid_p);
                }
            }
            l_ql_screenhandler->at(i)->activeFocus();
            return true;
        }
    }

    return false;
}

void MainFrame::check_new_pids()
{
    QList<ScreenHandler*> *l_ql_screenhandler = MainFrame::ql_screenhandler;

    if(l_ql_screenhandler->size() <= 1)
    {
       return;
    }

    for(int i = l_ql_screenhandler->size()-1; i>=0; i--)
    {
        if(l_ql_screenhandler->at(i) == NULL)
        {
            continue;
        }
        if(l_ql_screenhandler->at(i)->p_pid_p == 0 && l_ql_screenhandler->at(i)->b_runinfo)
        {
            for(int j = l_ql_screenhandler->size()-1; j>=0; j--)
            {
                if(l_ql_screenhandler->at(j) == NULL)
                {
                    continue;
                }

                if(l_ql_screenhandler->at(j)->programm_name.contains(l_ql_screenhandler->at(i)->programm_name_run + "."))
                {
                    if(l_ql_screenhandler->at(i)->programm_name_run.isEmpty())
                    {
                        continue;
                    }
                    if(l_ql_screenhandler->at(i)->p_pid == l_ql_screenhandler->at(j)->p_pid)
                    {
                        continue;
                    }
                    l_ql_screenhandler->at(i)->p_pid_p = l_ql_screenhandler->at(j)->p_pid;
                    //Focus of windows, when kind closes active the Focus of the Parent Window
                    connect(l_ql_screenhandler->at(i), SIGNAL(destroyed()), l_ql_screenhandler->at(j), SLOT(activeFocus()));
                }
            }
        }
    }
}



MainFrame::MainFrame(QWidget *parent) : QMainWindow(parent)
{
MainFrame::vdcdebug("MainFrame","MainFrame", "QWidget *parent");
   MainFrame::lastmainframe = this;
   p_currOpenNetwork=NULL;
   int port=1350;
   mainFrameToolBar = NULL;
   connectionsTab = NULL;
   errorMessageMainFrame = new QErrorMessage(this);
  QStringList parameter;
  parameter = QCoreApplication::arguments();
   bool onlyLogin;

   adminMenu = true;
   onlyLogin = true;
 for(int i=0; i<parameter.count(); i++)
  {
     if (parameter.at(i) == "-l")
     {
         onlyLogin = true;
     }

     if (parameter.at(i) == "-p")
     {
     i++;
         port= parameter.at(i).toInt();
    qDebug() << "Using non-standard port:"<< port;
     }

     if (parameter.at(i) == "-a")
     {
         adminMenu = true;
     }
          if (parameter.at(i) == "-D")
     {
         MainFrame::b_debugmodus = true;
     }
 }

   if(onlyLogin == false){
      tabWidget = new QTabWidget;
      setCentralWidget(tabWidget);

      setFixedSize(305,375);

      tabWidget->setGeometry(5,5,275,295);

      tabWidget->addTab(new ShortcutsTab(this),   tr("Shortcuts"));
      tabWidget->addTab(new OptionsTab(),          tr("Options"));
      connectionsTab = new ConnectionsTab(this);
      tabWidget->addTab(connectionsTab,      tr("Connections"));

      // setting up actions for the clients toolbar
      //


      exitAction = new QAction(tr("Exit"), this);
      exitAction->setShortcut(tr("Ctrl+Q"));
      exitAction->setStatusTip(tr("Exit Client"));

      connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
      mainFrameToolBar = new QToolBar(tr("ToolBar"));
      mainFrameToolBar->addAction(exitAction);
      mainFrameToolBar->setAllowedAreas(Qt::BottomToolBarArea|Qt::TopToolBarArea);
      addToolBar(Qt::TopToolBarArea, mainFrameToolBar);



      // making the statusbar
      //
      createStatusBar();
   }
   else{
      LoginForm *loginForm = new LoginForm(this);
      setCentralWidget(loginForm);
      userName = loginForm->getUserName();
      connect(this, SIGNAL(debugSignal()), loginForm, SLOT (debugCheck()));
   }
      setWindowTitle(tr("VDC - Ventas Desktop Client"));

   // start listening to the network
   //
   ReadSettings();
   tcpListener(port);
}
void MainFrame::contextMenuEvent ( QContextMenuEvent * event)
{
  if(mainFrameToolBar != NULL)
    {
  QMenu contextMenu(this);
MainFrame::vdcdebug("MainFrame","contextMenuEvent ", " QContextMenuEvent * event");
  contextMenu.addAction(mainFrameToolBar->toggleViewAction());
  contextMenu.exec(event->globalPos());
}

}

void MainFrame::vdcdebug(QString obj, QString funk, QString uebergabe)
{
    if(MainFrame::b_debugmodus)
    {
       qDebug() << obj + "::" + funk + "(" + uebergabe + ")";
    }

    if(VDC::readSettingsFromIni("", "debugVDC") == "yes")
    {
        VDC::logMessage("CALLTREE", obj + "::" + funk + "(" + uebergabe + ")");
    }
}


bool MainFrame::eventFilter(QObject *obj, QEvent *event)
{
    /*
    if(FglForm *p_fglform = qobject_cast<FglForm*> (obj))
    {
       if(event->type() == QEvent::WindowActivate && p_fglform != NULL && !p_fglform->screenhandler()->b_runinfo)
       {

           if(p_fglform->dialog() == NULL && p_fglform->pulldown() == NULL){

               p_fglform->raise();
               p_fglform->activateWindow();

           }
           if(p_fglform->dialog() != NULL)
           {
               p_fglform->dialog()->raise();
               p_fglform->dialog()->activateWindow();
               QApplication::setActiveWindow((QWidget*) p_fglform->dialog());
           }

       }
    }
*/
       return QMainWindow::eventFilter(obj, event);

}

//------------------------------------------------------------------------------
// Method       : createStatusBar()
// Filename :S    : mainframe.cpp
// Description  : createStatusBar logic
//------------------------------------------------------------------------------

void MainFrame::createStatusBar()
{
MainFrame::vdcdebug("MainFrame","createStatusBar", "");
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

    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *connectionLabel = new QLabel(tr("Connections:"));
    tableWidget = new QTableWidget(0, 4, this);
    QStringList labels;

    labels << tr("Name") << tr("Id") << tr("Typ") << tr("Date");
    tableWidget->setHorizontalHeaderLabels(labels);
    tableWidget->verticalHeader()->hide();
    tableWidget->setShowGrid(false);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->resizeColumnsToContents();
    tableWidget->horizontalHeader()->setStretchLastSection(true);

    layout->addWidget(connectionLabel);
    layout->addWidget(tableWidget);
MainFrame::vdcdebug("ConnectionsTab","addConnection", "");
    setLayout(layout);
}

void ConnectionsTab::addConnection()
{
    ClientTcp *clientTcp = (ClientTcp*) QObject::sender();
    QObject::connect(clientTcp->socket, SIGNAL(disconnected()), this, SLOT(delConnection()));

    QString ip = clientTcp->socket->peerAddress().toString();
    port = clientTcp->socket->peerPort();

    //int row = listpruef.count();

    portshow = QString::number(port);
    tableWidget->insertRow(listpruef.count());
    tableWidget->setItem(listpruef.count(), 0, new QTableWidgetItem(portshow));
    listpruef << port;
    tableWidget->resizeColumnsToContents();
MainFrame::vdcdebug("ConnectionsTab","delConnection", "");
    tableWidget->horizontalHeader()->setStretchLastSection(true);
}

void ConnectionsTab::delConnection()
{

ClientSocket *socket = (ClientSocket*) QObject::sender();
int checkport = socket->peerPort();
for(int i=0; i<listpruef.count(); i++) {
    if(listpruef.at(i) == checkport){
       tableWidget->removeRow(i);
       listpruef.removeAt(i);
   }
}

}

//------------------------------------------------------------------------------
// Method       : OptionsTab()
// Filename     : mainframe.cpp
// Description  : constructor for the instances
//------------------------------------------------------------------------------

OptionsTab::OptionsTab(QWidget *parent)
    : QWidget(parent)
{

       QPalette palette;
       palette.setBrush(this->backgroundRole(), QBrush(QImage("pics:VENTAS_9_alu_1080p.png")));
       this->setPalette(palette);

       QGroupBox *fontbox = new QGroupBox(tr("Font"));
       QLabel *fontlabel = new QLabel(tr("Font : "));

       QPushButton *select = new QPushButton("&Select",this);
       select->setIcon(QIcon(QString("pics:vor.png")));
       select->setIconSize(QSize(40,25));

       QPushButton *reset = new QPushButton("&Reset",this);
       reset->setIcon(QIcon(QString("pics:loeschen.png")));
       reset->setIconSize(QSize(40,25));

       QPushButton *close = new QPushButton("&Close", this);
       close->setIcon(QIcon(QString("pics:nein.png")));
       close->setIconSize(QSize(40,25));
       close->setShortcut(Qt::Key_Escape);

       QPushButton *save = new QPushButton("Save", this);
       save->setIcon(QIcon(QString("pics:ok_gruen.png")));
       save->setIconSize(QSize(40,25));
       save->setShortcut(Qt::Key_F12);

       fontedit = new QLineEdit;
       fontedit->setReadOnly(true);


       QHBoxLayout *layoutbox = new QHBoxLayout;
       fontbox->setLayout(layoutbox);


       QHBoxLayout *fontlayout = new QHBoxLayout;
       fontlayout->addWidget(fontlabel);
       fontlayout->addWidget(fontedit);

       QVBoxLayout *leftlayout = new QVBoxLayout;
       leftlayout->addLayout(fontlayout);
        leftlayout->addStretch();

       QVBoxLayout *buttonlayout = new QVBoxLayout;

       buttonlayout->addWidget(select);
       buttonlayout->addWidget(reset);
       buttonlayout->addWidget(save);
       buttonlayout->addWidget(close);
       buttonlayout->setSpacing(5);

       layoutbox->addLayout(leftlayout);
       layoutbox->addLayout(buttonlayout);


       QVBoxLayout *mainlayout = new QVBoxLayout;
       mainlayout->addWidget(fontbox);

       setStyleSheet("QPushButton { border-image: url(pics:VENTAS_9_knopf_menu_inaktiv.png); padding-top: -1; padding-right: 10; text-align: left; height: 36px; min-width: 50px; }");
       setLayout(mainlayout);


       connect(select,SIGNAL(clicked()), this,SLOT(fontdialog()));
       connect(reset,SIGNAL(clicked()), this,SLOT(reset()));
       connect(save,SIGNAL(clicked()), this,SLOT(close()));
       connect(close,SIGNAL(clicked()), this,SLOT(close()));
     //LineEdit
QFont fontload;
fontload = QApplication::font();
QString fontconv;
fontconv = fontload.toString();
QStringList splitlist;
splitlist = fontconv.split(",");
QString fonteingabe;
fonteingabe.append(splitlist[0]);
fonteingabe.append(",");
fonteingabe.append(splitlist[1]);
if (fonteingabe == "Arial,8")
{
fonteingabe.append("(Default)");
fontedit->insert(fonteingabe);
}

else
{
fontedit->insert(fonteingabe);
}
fonteingabe = "";


}




void OptionsTab::reset()
{
MainFrame::vdcdebug("OptionsTab","reset", "");
fontedit->clear();
QFont base = QFont("Arial", 8);
QApplication::setFont(base);
fonteingabe = "Arial,8(Default)";
fontedit->insert(fonteingabe);
fonteingabe = "";
showMessage("Font set to Default");
writeSettings();
}


void OptionsTab::fontdialog()
{
MainFrame::vdcdebug("OptionsTab","fontdialog", "");
 bool ok;
 QFont font = QFontDialog::getFont(&ok, QApplication::font(), this);
 if (ok) {
fontedit->clear();
QApplication::setFont(font);
fontconv = font.toString();
splitlist = fontconv.split(",");

fonteingabe.append(splitlist[0]);
fonteingabe.append(",");
fonteingabe.append(splitlist[1]);
if (fonteingabe == "Arial,8")
{
fonteingabe.append("(Default)");
fontedit->insert(fonteingabe);
showMessage("Font set to Default");
}
else
{
fontedit->insert(fonteingabe);
QString showstatus = "Font set to ";
showstatus.append(fonteingabe);
showMessage(showstatus);
}
fonteingabe = "";
 }
 else {

 }
writeSettings();
}
void OptionsTab::writeSettings()
{
MainFrame::vdcdebug("OptionsTab","writeSettings", "");
   QSettings settings("Ventas AG", "Ventas Desktop Client");
   //int status = settings.status();
   QString fontsettingwrite;
   fontsettingwrite = QApplication::font().toString();
   settings.setValue("font", fontsettingwrite);
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
MainFrame::vdcdebug("ShortcutsTab","editConfwin", "QListWidgetItem *p_currWidgetItem");

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
MainFrame::vdcdebug("ShortcutsTab","addConfwin", "");
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
MainFrame::vdcdebug("ShortcutsTab","delConfwin", "");
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
MainFrame::vdcdebug("ShortcutsTab","delFile", "QString p_cFilename");
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
MainFrame::vdcdebug("ShortcutsTab","readFile", "QString p_cFilename, int i");
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
MainFrame::vdcdebug("ShortcutsTab","updateListBox", "");
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

void MainFrame::tcpListener(int port)
{
MainFrame::vdcdebug("MainFrame","tcpListener", "int port");
   clientTcp = new ClientTcp(this);
   clientTcp->setDebugModus(MainFrame::b_debugmodus, this);

   if(!clientTcp->listen(QHostAddress::Any, port)){
      errorMessageMainFrame->showMessage(
            tr("ERROR: VDC already running"));
   }

   if(connectionsTab != NULL){
      connect(clientTcp,SIGNAL(newConnection()),connectionsTab,SLOT(addConnection()));
   }
}




//------------------------------------------------------------------------------
// Method       : updateListBox()
// Filename     : mainframe.cpp
// Description  : calls the selected program of the shortcut list
//------------------------------------------------------------------------------

void ShortcutsTab::requestApplication()
{
MainFrame::vdcdebug("ShortcutsTab","requestApplication", "");
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
// Description  : display QProcessErrors to
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
MainFrame::vdcdebug("ShortcutsTab","lookupForIP", "");
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
MainFrame::vdcdebug("ShortcutsTab","ipLookupResults", "const QHostInfo& host");

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
MainFrame::vdcdebug("MainFrame","cleanUp", "");
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

void MainFrame::trayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::Trigger)
    {
        if(!this->isVisible())
        {
            this->show();
        } else {
            this->hide();
        }
    }
}
void MainFrame::closeAction()
{
    int closeApplication = 0;
    if(this->ql_screenhandler)
    {
        if(ql_screenhandler->count() > 0)
        {
           closeApplication = QMessageBox::question(0,
                                       tr("VDC - Ventas Desktop Client"),
                                       tr("There are open Connections.\n"
                                          "Do you really want to quit?"),
                                       tr("&Yes"), tr("&No"),
                                       QString(), 0, 1);
        }
    }

    if(closeApplication == 0){
       VDC::saveSettingsToIni("Ventas AG", "posX", QString::number(pos().x()));
       VDC::saveSettingsToIni("Ventas AG", "posY", QString::number(pos().y()));
       cleanUp();
       exit(0);
    }
}

//------------------------------------------------------------------------------
// Method       : closeEvent()
// Filename     : mainframe.cpp
// Description  : override the closeEvent
//------------------------------------------------------------------------------
void MainFrame::closeEvent(QCloseEvent *event)
{
MainFrame::vdcdebug("MainFrame","closeEvent", "QCloseEvent *event");
    if (mTray->isVisible())
    {
        mTray->showMessage("Ventas Desktop Client", "The VDC runs in System Tray");
        this->hide();
        event->ignore();
    }
}
void MainFrame::debugClose()
{
MainFrame::vdcdebug("MainFrame","debugClose", "");
emit debugSignal();
}

void MainFrame::debugText(QString text)
{
    this->clientTcp->dw->append(text);
}

void MainFrame::requestScreenHandler(int pid, int p_pid)
{
MainFrame::vdcdebug("MainFrame","requestScreenHandler", "int pid, int p_pid");

    ScreenHandler *sh = new ScreenHandler(this->lastmainframe);
    sh->moveToThread(QApplication::instance()->thread());
    sh->pid = pid;
    sh->p_pid = p_pid;

}

void MainFrame::deleteScreenHandler(int pid, int p_pid)
{
MainFrame::vdcdebug("MainFrame","deleteScreenHandler", "int pid, int p_pid");
for(int i=0; i<ql_screenhandler->size();i++)
    {
        if(ql_screenhandler->at(i)->pid == pid && ql_screenhandler->at(i)->p_pid == p_pid)
        {
            ScreenHandler *p_currScreenHandler = ql_screenhandler->at(i);

            if(p_currScreenHandler->p_prompt != NULL){
               p_currScreenHandler->p_prompt->setVisible(false);
               p_currScreenHandler->p_prompt->close();
               p_currScreenHandler->p_prompt->deleteLater();
            }

            p_currScreenHandler->closeAllWindows();
           delete p_currScreenHandler;
        }
    }

}

