//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// File name    : main.cpp
// Description  : contains the tcpclient class logic
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

#include <QFile>
#include <QProcess>
#include <QDir>
#include <QTextCodec>
#include <QDesktopServices>
#include <QFileInfo>
#include <QUrl>
#include <QDebug>
#include <QMessageBox>
#include <QVector>
#include <QVariant>
#include <QXmlSimpleReader>
#include <QXmlInputSource>
#include "clienttcp.h"
#include "mainframe.h"
#include "quazip/quazip.h"
#include "quazip/quazipfile.h"
#ifdef VREPGEN_USE
#include "models/reportgen/reportgen.cpp"
#include "models/reportgen/documentinfo.h"

#endif
#include <models/fglform.h>
#ifdef Q_OS_WIN
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#endif

//------------------------------------------------------------------------------
// Method       : ClientTcp()
// Filename     : tcpclient.cpp
// Description  : Initialize tcp server. Next:  incomingConnection()
//------------------------------------------------------------------------------

ClientTcp::ClientTcp(QObject *parent)
    : QTcpServer(parent)
{
   MainFrame::vdcdebug("ClientTcp", "ClientTcp", "QObject *parent");
   cnt_replied=0;
   i_cnt_socket=0;

   socket = NULL;
   {
      //Commandline arguments for Debugging
      QStringList args = QApplication::arguments();
   }
}

//------------------------------------------------------------------------------
// Method       : ~ClientTcp()
// Filename     : tcpclient.cpp
// Description  : destructor for the instances
//------------------------------------------------------------------------------

ClientTcp::~ClientTcp(){
}

//------------------------------------------------------------------------------
// Method       : ~ClientTcp()
// Filename     : tcpclient.cpp
// Description  : destructor for the instances
//------------------------------------------------------------------------------

void ClientTcp::socketDisconnected(){
   socket = NULL;
   MainFrame::vdcdebug("ClientTcp", "socketDisconnected", "");
}


//------------------------------------------------------------------------------
// Method       : incomingConnection()
// Filename     : tcpclient.cpp
// Description  : starts communication socket between server and client 
//------------------------------------------------------------------------------

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
void ClientTcp::incomingConnection(int socketID)
{
MainFrame::vdcdebug("ClientTcp","incomingConnection", "int socketID");
//   qDebug("incomingConnection - open socket with id: %d", socketID);

   // creates a QTcpSocket child for the QTcpServer parent
   // to read from network
   //
   socket = new ClientSocket(this);
   socket->ph.t_tunnel = NULL;//Avoid seg. faults in listen mode
   //VDC::waitCursor();
   p_arr_socket << socket;
   i_cnt_socket++;


   // when socket gets data the server has to reply
   //
   connect(&socket->ph, SIGNAL(debugtext(const QString&)) ,dw , SLOT(debugOut(const QString&)));

   connect(socket, SIGNAL(makeResponse(QString)),
           this, SLOT(clientReturn(QString)));

   connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));

// ---------------------------------------------------

   socket->setSocketDescriptor(socketID);

   {
      //Initialize the protocolhandler debug variables
      socket->ph.b_read = false;
      socket->ph.b_write = false;

      //Commandline arguments for Debugging
      QStringList args = QApplication::arguments();

//      if(args.contains("-D")){
//         //graphical debug (open Debug window)
//          //qsl_xmlCommands.at(i);
//      qDebug() << "-D läuft";
//      }

      if(args.contains("-d")){
         //non-graphical debug (write to file)
         int index = args.indexOf("-d");

         socket->ph.b_write = true;
         if(index < args.count()-1){
            socket->ph.fileName = args.at(index+1);
         }
         else{
            socket->ph.fileName = "debug.out";
         }
      }

      if(args.contains("-r")){
         //read from debug file
         int index = args.indexOf("-r");

         socket->ph.b_read = true;

         if(index < args.count()-1){
            socket->ph.fileName = args.at(index+1);
         }
         else{
            socket->ph.fileName = "debug.in";
         }
      }
   }

}

#else
void ClientTcp::incomingConnection(qintptr socketID)
{
MainFrame::vdcdebug("ClientTcp","incomingConnection", "int socketID");
//   qDebug("incomingConnection - open socket with id: %d", socketID);

   // creates a QTcpSocket child for the QTcpServer parent
   // to read from network
   //
   socket = new ClientSocket(this);
   socket->ph.t_tunnel = NULL;//Avoid seg. faults in listen mode
   //VDC::waitCursor();
   p_arr_socket << socket;
   i_cnt_socket++;


   // when socket gets data the server has to reply
   //
   connect(&socket->ph, SIGNAL(debugtext(const QString&)) ,dw , SLOT(debugOut(const QString&)));

   connect(socket, SIGNAL(makeResponse(QString)), 
           this, SLOT(clientReturn(QString)));

   connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));

// ---------------------------------------------------

   socket->setSocketDescriptor(socketID);

   {
      //Initialize the protocolhandler debug variables
      socket->ph.b_read = false;
      socket->ph.b_write = false;

      //Commandline arguments for Debugging
      QStringList args = QApplication::arguments();

//      if(args.contains("-D")){
//         //graphical debug (open Debug window)
//          //qsl_xmlCommands.at(i);
//      qDebug() << "-D läuft";
//      }

      if(args.contains("-d")){
         //non-graphical debug (write to file)
         int index = args.indexOf("-d");

         socket->ph.b_write = true;
         if(index < args.count()-1){
            socket->ph.fileName = args.at(index+1);
         }
         else{
            socket->ph.fileName = "debug.out";
         }
      }

      if(args.contains("-r")){
         //read from debug file
         int index = args.indexOf("-r");

         socket->ph.b_read = true;

         if(index < args.count()-1){
            socket->ph.fileName = args.at(index+1);
         }
         else{
            socket->ph.fileName = "debug.in";
         }
      }
   }

}
#endif
//------------------------------------------------------------------------------
// Method       : newSocket()
// Filename     : tcpclient.cpp
// Description  : newSocket method... --- atm not in use
//-------------ClientTcp-----------------------------------------------------------------

void ClientTcp::newSocket()
{
MainFrame::vdcdebug("ClientTcp","newSocket", "");
   setMaxPendingConnections(16);
}

void ClientTcp::setDebugModus(bool debugModus, QWidget *parent)
{
MainFrame::vdcdebug("ClientTcp","setDebugModus", "bool debugModus, QWidget *parent");
   dw = new DebugWindow(parent);
   connect(dw , SIGNAL(debugClose()), parent, SLOT(debugClose()));

   if (debugModus)
   {
      dw->show();
   }
}


//------------------------------------------------------------------------------
// Method       : ClientSocket()
// Filename     : tcpclient.cpp
// Description  : relates screen and protocol handler for later data interchange.
//                defines signals for every 4gl command that has a relation to gui
//------------------------------------------------------------------------------

ClientSocket::ClientSocket(QObject *parent, QString name, QString pass, QString program)
    : QTcpSocket(parent)
{
   MainFrame::vdcdebug("ClientSocket", "ClientSocket", "QObject *parent, QString name, QString pass, QString program");
   ph.qs_shortCutUser = name;
   ph.qs_shortCutPass = pass;
   ph.qs_shortCutProgram = program;
   // instantiate the screenHandler

   // wich deals with the low level calls arriving in the
   // ProtocolHandlers section
   //
  // p_currScreenHandler = new ScreenHandler(this);
//   QList<ScreenHandler*> *l_ql_screenhandler =  QList<ScreenHandler*> MainFrame::ql_screenhandler;
//   MainFrame::ql_screenhandler->append(p_currScreenHandler);
   // Thread to handle protocols data
   //
  // ph.p_currScreenHandler = p_currScreenHandler;

   QList<ScreenHandler*> *l_ql_screenhandler = MainFrame::ql_screenhandler;
   if(l_ql_screenhandler->count() > 0)
   {
       QMetaObject::invokeMethod(l_ql_screenhandler->last(), "stopProtocolTimer", Qt::QueuedConnection);
   }

   connect(this, SIGNAL(readyRead()),    this, SLOT(readClient()));
   connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));

   connect(&ph, SIGNAL(makeResponse(QString)), 
          this, SIGNAL(makeResponse(QString)));

   if(parent == NULL){
      connect(&ph, SIGNAL(makeResponse(QString)), 
             this, SLOT(makeOwnResponse(QString)));
   }

/*
   connect(&ph, SIGNAL(setUpdatesEnabled(bool)),
           p_currScreenHandler, SLOT(setUpdatesEnabled(bool)));
   // OPEN FORM
   connect(&ph, SIGNAL(createWindow(QString, QString, int, int, int, int, QString, QString)),
           p_currScreenHandler, SLOT(createWindow(QString, QString, int, int, int, int, QString, QString)));
   // PROMPT
   connect(&ph, SIGNAL(createPrompt(QString, int, int, QString)), 
           p_currScreenHandler, SLOT(createPrompt(QString, int, int, QString)));
   // Title line of the screen form
   connect(&ph, SIGNAL(setWindowTitle(QString)), 
           p_currScreenHandler, SLOT(setWindowTitle(QString)));
   // handles original aubit4gl forms
   connect(&ph, SIGNAL(handleAubitForm(QString, QString, bool)  ),
           p_currScreenHandler, SLOT(handleAubitForm(QString, QString, bool)));
   // handles original aubit4gl forms
   connect(&ph, SIGNAL(displayForm(QString)), 
           p_currScreenHandler, SLOT(displayForm(QString)));
   // handles the new xml forms
   connect(&ph, SIGNAL(handleXMLForm(QString, QString, bool)), 
           p_currScreenHandler, SLOT(handleXMLForm(QString, QString, bool)));
   // transfer the received tool bar to the screen handler (4tb file)
   connect(&ph, SIGNAL(handleXMLToolBar(QString)),  
           p_currScreenHandler, SLOT(handleXMLToolBar(QString)));
   // transfer the received main menu to the screen handler (4st file)
   connect(&ph, SIGNAL(handleXMLStartMenu(QString)),
           p_currScreenHandler, SLOT(handleXMLStartMenu(QString)));
   // transfer the received action defaults (4ad file) to the screen handler
   connect(&ph, SIGNAL(handleXMLActions(QString)), 
           p_currScreenHandler, SLOT(handleXMLActions(QString)));

   connect(&ph, SIGNAL(handleXMLColors(QString)),
           p_currScreenHandler, SLOT(handleXMLColors(QString)));

   // transfer the received styles (4st file) to the screen handler
   connect(&ph, SIGNAL(handleXMLStyles(QString)), 
           p_currScreenHandler, SLOT(handleXMLStyles(QString)));
   // activates or deactivates displaying of the ring menu
   connect(&ph, SIGNAL(setMenuEnabled(bool)), 
           p_currScreenHandler, SLOT(setMenuEnabled(bool)));
   // hide commands of the ring menu
   connect(&ph, SIGNAL(hideOption(QString)), 
           p_currScreenHandler, SLOT(hideOption(QString)));
   // show commands of the ring menu (if hidden)
   connect(&ph, SIGNAL(showOption(QString)), 
           p_currScreenHandler, SLOT(showOption(QString)));
   // select next command of the ring menu
   connect(&ph, SIGNAL(nextOption(QString, int)), 
           p_currScreenHandler, SLOT(nextOption(QString, int)));
   // display errors in message line
   connect(&ph, SIGNAL(displayError(QString)), 
           p_currScreenHandler, SLOT(displayError(QString)));
   // display messages in message line
   connect(&ph, SIGNAL(displayMessage(QString)), 
           p_currScreenHandler, SLOT(displayMessage(QString)));
   // shows and handles function keys in input, construct etc.
   connect(&ph, SIGNAL(createActionMenu()), 
           p_currScreenHandler, SLOT(createActionMenu()));
   // shows buttons of F-keys
   connect(&ph, SIGNAL(createActionMenuButton(QString, QString)), 
           p_currScreenHandler, SLOT(createActionMenuButton(QString, QString)));
   // new: replaces createActionMenu() and createActionMenuButton()
   connect(&ph, SIGNAL(setKeyLabel(QString, QString)), 
           p_currScreenHandler, SLOT(setKeyLabel(QString, QString)));
   // set cursor position for editor
   connect(&ph, SIGNAL(setCursorPosition(int)), 
           p_currScreenHandler, SLOT(setCursorPosition(int)));
   // attribute in open form boolean (set "input" to "on" for example)
   connect(&ph, SIGNAL(setFormOpts(QString, bool, int)), 
           p_currScreenHandler, SLOT(setFormOpts(QString, bool, int)));
   connect(&ph, SIGNAL(setFormOpts(QString, QString, int)), 
           p_currScreenHandler, SLOT(setFormOpts(QString, QString, int)));
   connect(&ph, SIGNAL(clearDisplayArrayRows(QStringList)),
           p_currScreenHandler, SLOT(clearDisplayArrayRows(QStringList)));
   // DISPLAY variable TO field (for example)
   connect(&ph, SIGNAL(setFieldBuffer(int, QString, int)),
           p_currScreenHandler, SLOT(setFieldBuffer(int, QString, int)));
   // DISPLAY variable TO field (for example)
   connect(&ph, SIGNAL(setFieldBuffer(QStringList, QStringList, int)),
           p_currScreenHandler, SLOT(setFieldBuffer(QStringList, QStringList, int)));
   // CLEAR variable TO field (for example)
   connect(&ph, SIGNAL(clearFieldBuffer(QString)), 
           p_currScreenHandler, SLOT(clearFieldBuffer(QString)));
   // DISPLAY variables TO screenRecord (for example)
   connect(&ph, SIGNAL(setArrayBuffer(int, QString, QStringList)), 
           p_currScreenHandler, SLOT(setArrayBuffer(int, QString, QStringList)));
   // DISPLAY variables TO screenRecord (for example)
   connect(&ph, SIGNAL(setArrayBuffer(int, QStringList)), 
           p_currScreenHandler, SLOT(setArrayBuffer(int, QStringList)));
   // set field input order according to the input list (form field order is not relevant)
   connect(&ph, SIGNAL(setFieldOrder(QStringList)), 
           p_currScreenHandler, SLOT(setFieldOrder(QStringList)));
   // field is in input and not hidden in form, then activate it
   connect(&ph, SIGNAL(setFieldEnabled(QString,bool, bool, int)),
           p_currScreenHandler, SLOT(setFieldEnabled(QString, bool, bool, int)));
   // cursor on a field
   connect(&ph, SIGNAL(setFieldFocus(QString)), 
           p_currScreenHandler, SLOT(setFieldFocus(QString)));
   connect(&ph, SIGNAL(setNewTabName(QString, QString)),
           p_currScreenHandler, SLOT(setNewTabName(QString, QString)));
   connect(&ph, SIGNAL(setAttributes(QString, QString, QString)),
           p_currScreenHandler, SLOT(setAttributes(QString, QString, QString)));   connect(&ph, SIGNAL(setFieldHidden(QString, bool)), 
           p_currScreenHandler, SLOT(setFieldHidden(QString, bool)));
   connect(&ph, SIGNAL(setElementHidden(QString, bool)), 
           p_currScreenHandler, SLOT(setElementHidden(QString, bool)));
   // activates table in screen form
   connect(&ph, SIGNAL(setScreenRecordEnabled(QString, bool, bool)), 
           p_currScreenHandler, SLOT(setScreenRecordEnabled(QString, bool, bool)));
   // load values in input or display array by tablename
   connect(&ph, SIGNAL(loadArrayValues(QStringList, QStringList)), 
           p_currScreenHandler, SLOT(loadArrayValues(QStringList, QStringList)));
   // load values in input or display array
   connect(&ph, SIGNAL(loadArrayValues(QStringList)), 
           p_currScreenHandler, SLOT(loadArrayValues(QStringList)));
   //SETARRLINE for screen records
   connect(&ph, SIGNAL(setArrLine(int)), 
           p_currScreenHandler, SLOT(setArrLine(int)));
   //SETSCRLINE for screen records
   connect(&ph, SIGNAL(setScrLine(int)), 
           p_currScreenHandler, SLOT(setScrLine(int)));
   // defines all events like "before field" or "on key F9"
   connect(&ph, SIGNAL(setEvent(QString, QString, QString)), 
           p_currScreenHandler, SLOT(setEvent(QString, QString, QString)));

      connect(&ph, SIGNAL(MsgBox(QString, QString,QString,QString,QString,int)), p_currScreenHandler, SLOT(MsgBox(QString, QString,QString,QString,QString,int)));

   // ring menu
   connect(&ph, SIGNAL(createMenu(QString, QString, QString, QString)), 
           p_currScreenHandler, SLOT(createMenu(QString, QString, QString, QString)));
   // menu commands
   connect(&ph, SIGNAL(createMenuButton(int, QString, QString, QStringList)), 
           p_currScreenHandler, SLOT(createMenuButton(int, QString, QString, QStringList)));
   connect(&ph, SIGNAL(createMenuAction(int, QString)), 
           p_currScreenHandler, SLOT(createMenuAction(int, QString)));
   // server waits for user interaction
   connect(&ph, SIGNAL(waitForEvent()), p_currScreenHandler, SLOT(waitForEvent()));
   // END of input, menu etc.
   connect(&ph, SIGNAL(free(QString)), p_currScreenHandler, SLOT(free(QString)));
   // CURRENT WINDOW
   connect(&ph, SIGNAL(activeWindow(QString)), p_currScreenHandler, SLOT(activeWindow(QString)));
   // RUN
   connect(&ph, SIGNAL(setRuninfo(int,QString,int,bool)), p_currScreenHandler, SLOT(setRuninfo(int, QString, int, bool)));
   // CLOSE WINDOW
   connect(&ph, SIGNAL(closeWindow(QString)), p_currScreenHandler, SLOT(closeWindow(QString)));
   // activates connection to the server when the user reacts
   connect(p_currScreenHandler, SIGNAL(fglFormResponse(QString)), &ph, SLOT(fglFormResponse(QString)));
   // opens filebrowser
   connect(&ph, SIGNAL(fileBrowser(QString, QString, QString, QString, QString)), p_currScreenHandler, SLOT(fileBrowser(QString, QString, QString, QString, QString)));
   // set the Programname 
   connect(&ph, SIGNAL(setProgramName(QString)), p_currScreenHandler, SLOT(setProgramName(QString)));

   // UI-Browser
   connect(&ph, SIGNAL(setUrl(int, QUrl)), p_currScreenHandler, SLOT(setUrl(int, QUrl)));
   connect(&ph, SIGNAL(createBrowser()), p_currScreenHandler, SLOT(createBrowser()));
   connect(&ph, SIGNAL(closeBrowser(int)), p_currScreenHandler, SLOT(closeBrowser(int)));
#ifdef KDChart_Version
   connect(&ph, SIGNAL(openChartWindow(QString)), p_currScreenHandler, SLOT(openChartWindow(QString)));
   connect(&ph, SIGNAL(setGanttTitle(int,QString)), p_currScreenHandler, SLOT(setTitle(int,QString)));
   connect(&ph, SIGNAL(createGantt()), p_currScreenHandler, SLOT(createGantt()));
   connect(&ph, SIGNAL(ganttReadCsv(int,QString)), p_currScreenHandler, SLOT(readCsv(int,QString)));
#endif
connect(&ph, SIGNAL(checkForUpdate()), p_currScreenHandler, SLOT(checkForUpdate()));
connect(&ph, SIGNAL(createStdProgWindow()), p_currScreenHandler, SLOT(createStdProgWindow()));

//Ui.Progress
connect(&ph, SIGNAL(createProgressWindow()), p_currScreenHandler, SLOT(createProgressWindow()));

connect(&ph, SIGNAL(setProgressText(int,QString)), p_currScreenHandler, SLOT(setProgressText(int,QString)));

connect(&ph, SIGNAL(setProgressTitle(int,QString)), p_currScreenHandler, SLOT(setProgressTitle(int,QString)));

connect(&ph, SIGNAL(closeProgressWindow(int)), p_currScreenHandler, SLOT(closeProgressWindow(int)));


connect(&ph, SIGNAL(setProgressVisible(int,bool)), p_currScreenHandler, SLOT(setProgressVisible(int,bool)));


connect(&ph, SIGNAL(printpdf(QString)), p_currScreenHandler, SLOT(printpdf(QString)));

//UI-Combobox

connect(&ph, SIGNAL(fornameComboBox(QString)), p_currScreenHandler, SLOT(fornameComboBox(QString)));

connect(&ph, SIGNAL(getColumnNameComboBox(int)), p_currScreenHandler, SLOT(getColumnNameComboBox(int)));

connect(&ph, SIGNAL(clearComboBox(int)), p_currScreenHandler, SLOT(clearComboBox(int)));
connect(&ph, SIGNAL(addComboBoxItem(int, QString, QString)), p_currScreenHandler, SLOT(addComboBoxItem(int, QString, QString)));
connect(&ph, SIGNAL(removeComboBoxItem(int, QString)), p_currScreenHandler, SLOT(removeComboBoxItem(int, QString)));
connect(&ph, SIGNAL(getItemNameComboBox(int,int)), p_currScreenHandler, SLOT(getItemNameComboBox(int,int)));
connect(&ph, SIGNAL(getItemCountComboBox(int)), p_currScreenHandler, SLOT(getItemCountComboBox(int)));
connect(&ph, SIGNAL(getItemTextComboBox(int, int)), p_currScreenHandler, SLOT(getItemTextComboBox(int,int)));
connect(&ph, SIGNAL(getTableNameComboBox(int)), p_currScreenHandler, SLOT(getTableNameComboBox(int)));
connect(&ph, SIGNAL(getIndexOfComboBox(int,QString)), p_currScreenHandler, SLOT(getIndexOfComboBox(int,QString)));
connect(&ph, SIGNAL(setOptions(QString,QString)), p_currScreenHandler, SLOT(setOptions(QString,QString)));

*/


}



void ClientSocket::makeOwnResponse(QString qs_replyString)
{
MainFrame::vdcdebug("ClientSocket","makeOwnResponse", "QString qs_replyString");
   QTextStream out;
   out.setDevice(this);
   if(this->ph.qs_dblocale.contains("UTF8")) {
       out.setCodec(QTextCodec::codecForName("UTF-8"));

   } else {
       out.setCodec(QTextCodec::codecForName("ISO-8859-1"));
   }

   qs_replyString+="\n";
   qs_replyString.replace("\n", "");
   out << qs_replyString.toLatin1();
}
//------------------------------------------------------------------------------
// Method       : ~ClientSocket()
// Filename     : tcpclient.cpp
// Description  : destructor for the instances. closes all activities if needed
//------------------------------------------------------------------------------

ClientSocket::~ClientSocket(){


   // terminate the Ll handling thread
   // to avoid clients segfault when 4gl-applications get canceled or killed
   //
   while(ph.isRunning()){
   waitTimer::msleep(5);
   }

   ph.closeAllScreenHandler();
//   QMetaObject::invokeMethod(&ph, "closeAllScreenHandler", Qt::DirectConnection);
}


//------------------------------------------------------------------------------
// Method       : readClient()
// Filename     : tcpclient.cpp
// Description  : reading datastream when server sends. starts protocol handler (ph)
//------------------------------------------------------------------------------

void ClientSocket::readClient()
{
MainFrame::vdcdebug("ClientSocket","readClient", "");
   QByteArray request;

   // reading in all portions of the first command block
   //
   //
   request = NULL;


   while(canReadLine()){
      request.append(readLine());
   }

   // while existing thread is running 
   // wait until it's done to start a new one
   //


   while(ph.isRunning()){
   waitTimer::msleep(5);
   }


   if(!request.isNull()){
      ph.protocol_mutex.lock();
      ph.request.append(request);
      ph.protocol_mutex.unlock();
      ph.start();
   }
}


//------------------------------------------------------------------------------
// Method       : clientReturn() - overloaded
// Filename     : tcpclient.cpp
// Description  : reply data to stream
//------------------------------------------------------------------------------

void ClientTcp::clientReturn(QString qs_returnString)
{
MainFrame::vdcdebug("ClientTcp","clientReturn", "QString qs_returnString");
   replyWith(qs_returnString);

   cnt_replied++;
}


//------------------------------------------------------------------------------
// Method       : replyWith()
// Filename     : tcpclient.cpp
// Description  : reply data to stream. sends protocol data to the server
//------------------------------------------------------------------------------

void ClientTcp::replyWith(QString qs_replyString)
{
MainFrame::vdcdebug("ClientTcp","replyWith", "QString qs_replyString");
      QTextStream out;
      //dbu Job 18058: if sender is ClientSocket we dont need the array
      //               we can talk directly to this socket
      if(QObject::sender() != NULL && QObject::sender()->inherits("ClientSocket")){
         ClientSocket *cl = static_cast<ClientSocket*>(QObject::sender());
         out.setDevice(cl);
         if(cl->ph.qs_dblocale.contains("UTF8")) {
             out.setCodec(QTextCodec::codecForName("UTF-8"));

         } else {
             out.setCodec(QTextCodec::codecForName("ISO-8859-1"));
         }

         qs_replyString+="\n";
         //out << qs_replyString.toLatin1();

         /*while(cl->ph.isRunning())
             usleep(500000l);
         */
            #if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
               out << qs_replyString.toLatin1();
            #else
               out << qs_replyString;
            #endif 
      }
}


//------------------------------------------------------------------------------
// Method       : run()
// Filename     : tcpclient.cpp
// Description  : thread to handle protocol - 
//                this is where the underlying client server
//                communication happens
//------------------------------------------------------------------------------

void ProtocolHandler::run()
{
MainFrame::vdcdebug("ProtocolHandler","run", "");
   // request holds the current command from
   // the application server(proxy)
   //
p_currScreenHandler = NULL;
   openFileSuccess = 0;
   QByteArray qs_protocolCommand;

   if(qs_dblocale.isEmpty())
   {
       qs_dblocale = "UTF-8";

   //Auch wenns derzeit falsch ist immer IBM850 zu nehmen, wenn man DB_LOCALE nutzt läuft nix mehr
      QTextCodec *codec = QTextCodec::codecForName(qPrintable(QString("UTF-8")));
      QTextStream in_request(&request);
      in_request.setCodec(codec);
      qs_protocolCommand.clear();
      qs_protocolCommand.append(in_request.readAll());
      
   }
   else{
      qs_protocolCommand = request;
   }
   if(qs_protocolCommand.trimmed() == "PROTOCOL?")
   {
      makeResponse(QString("UIVERSION %1").arg("1.0"));
      request.clear();
      return;
   }

   if(qs_protocolCommand.trimmed() == "PROGRAMNAME?")
   {
      makeResponse(qs_shortCutProgram);
      request.clear();
      return;
   }

   if(qs_protocolCommand.trimmed() == "USER?")
   {
      makeResponse(qs_shortCutUser);
      request.clear();
      return;
   }

   if(qs_protocolCommand.trimmed() == "PASSWORD?")
   {
      makeResponse(qs_shortCutPass);
      request.clear();
      return;
   }
   if(qs_protocolCommand.trimmed() == "TIMEOUT"){
      makeResponse("100");
      MsgBox("Timeout","Connection Timeout","Error","Ok","Ok",0);
      request.clear();
      return;
   }

   if(qs_protocolCommand.trimmed() == "START"){
      request.clear();
      return;
   }

   if(qs_protocolCommand.trimmed() == "FAILED TO START"){
      MsgBox("Start failed","Program not found","Error","Ok","Ok",0);
      request.clear();
      return;
   }

   if(qs_protocolCommand.trimmed() == "AUTHFAILED"){
      MsgBox("Authentication failed","Wrong Username or Password","Warning","Ok","Ok",0);
      request.clear();
      return;
   }

   if(b_read){
      // Read Commands from File
      QFile file(fileName);
      if (!file.open(QIODevice::ReadOnly)){
         qDebug() << "Could not read File!" << fileName;
         return;
      }

      QTextStream in(&file);
      qs_protocolCommand = "";
      while (!in.atEnd()) {
            qs_protocolCommand += in.readLine();
      }
   }

   QStringList qsl_protocolCmds;
   QString qs_commandBuffer;

   // storing in a list all transmited commands of the row
   QStringList qsl_xmlCommands;

   // reading the protocol
   for(int i=0; i<qs_protocolCommand.size(); i++){
      // We assume every command starts with "<ENVELOPE" and ends with "</ENVELOPE>"
      int index_end = qs_protocolCommand.indexOf("</ENVELOPE>", i);

      if(index_end > -1){
         qsl_xmlCommands << qs_protocolCommand.mid(0, index_end+11);
         qs_protocolCommand.remove(0, index_end+11);
         protocol_mutex.lock();
         request.remove(0, index_end+11);
         protocol_mutex.unlock();
         i=0;
      }
      else{
         if(index_end == -1)
         {
             i = qs_protocolCommand.size();
          /*   return;
             qFatal("ENVELOPE missed");*/
         }
      }
   }

   QDomDocument doc;
   QMetaObject::invokeMethod(p_currScreenHandler, "stopProtocolTimer", Qt::QueuedConnection);
   
   for(int i=0; i<qsl_xmlCommands.size(); i++)
   {
      QString tmpstring = qsl_xmlCommands.takeAt(i);
      qsl_xmlCommands.insert(i, tmpstring);
      QString errorMsg;
      int errorLine, errorCol;
      QXmlSimpleReader reader;
      QXmlInputSource source;

      source.setData(qsl_xmlCommands.at(i));

      //TODO: fehler finden warum DISPLAYTO elemente verschwinden wenn DISPLAYAT mit drin ist.
      /*if(qsl_xmlCommands.at(i).contains("DISPLAYAT") && !qsl_xmlCommands.at(i).contains("DISPLAYTO")) {

          if (!doc.setContent(&source, &reader, &errorMsg, &errorLine, &errorCol)){
             qDebug()<<"MISSMATCH : "<<qsl_xmlCommands.at(i);
             QString str = errorMsg + "\n" +
                           "Line:" + QString::number(errorLine) + "\n" +
                           "Column" + QString::number(errorCol);
             MsgBox("Protocol Error",str,"Warning","Ok","Ok",0);
             break;
          }
      } else {*/

      if (!doc.setContent(qsl_xmlCommands.at(i), &errorMsg, &errorLine, &errorCol)){
         qDebug()<<"MISSMATCH : "<<qsl_xmlCommands.at(i);
         QString str = errorMsg + "\n" +
                       "Line:" + QString::number(errorLine) + "\n" +
                       "Column" + QString::number(errorCol);
         MsgBox("Protocol Error",str,"Warning","Ok","Ok",0);
         break;
      //}
      }
   if(b_write){
      // -- Record Datastream
      QFile file(fileName);
      if (!file.open(QIODevice::WriteOnly | QIODevice::Append)){
         return;
      }
      QTextStream out(&file);
      out << qsl_xmlCommands.at(i);
   }


   /*QString test = doc.toString();
   test = filterUmlauts(test);
   doc.clear();

   if (!doc.setContent(test, &errorMsg, &errorLine, &errorCol)){
      QString str = errorMsg + "\n" +
                    "Line:" + QString::number(errorLine) + "\n" +
                    "Column" + QString::number(errorCol);
      MsgBox("Protocol Error",str,"Warning","Ok","Ok",0);
      break;
   }*/


   qDebug()<< qsl_xmlCommands.at(i)<<__LINE__<<__FILE__;
   QMetaObject::invokeMethod(MainFrame::lastmainframe, "debugText", Q_ARG(QString, "<< " + qsl_xmlCommands.at(i)));
   //emit debugtext(QString("<< " + qsl_xmlCommands.at(i)));
         QDomElement envelope = doc.documentElement();
         pid = envelope.attribute("ID").toInt();
         int p_pid = envelope.attribute("PID").toInt();
         ScreenHandler *curr_sh = NULL;
         if(qh_screenhandler[pid] == NULL)
         {
             if(MainFrame *main = qobject_cast<MainFrame*> (MainFrame::lastmainframe))
             {
                main->requestScreenHandler(pid, p_pid);
             }

                     //QMetaObject::invokeMethod(MainFrame::lastmainframe, "requestScreenHandler", Qt::BlockingQueuedConnection, Q_ARG(int, pid), Q_ARG(int, p_pid));

             for(int i = 0; i<MainFrame::ql_screenhandler->size(); i++)
             {
                 if(MainFrame::ql_screenhandler->at(i)->pid == pid && MainFrame::ql_screenhandler->at(i)->p_pid == p_pid)
                 {
                     curr_sh = MainFrame::ql_screenhandler->at(i);
                     break;
                 }
                 if(i+1 == MainFrame::ql_screenhandler->size())
                 {
                     qWarning("ScreenHandler request failed!");
                 }
             }


             qh_screenhandler[pid] = curr_sh;
             if(this->t_tunnel)
             curr_sh->ph = this;
             else
             {
                 curr_sh->ph = NULL;

             }
                 connect(curr_sh, SIGNAL(fglFormResponse(QString)), this, SLOT(fglFormResponse(QString)));
             }
         else
         {
             curr_sh = qh_screenhandler[pid];
         }

         p_currScreenHandler = curr_sh;
      //   connect(p_currScreenHandler, SIGNAL(fglFormResponse(QString)), this, SLOT(fglFormResponse(QString)));

         QDomElement commands = envelope.firstChildElement("COMMANDS");
         QDomElement child    = commands.firstChildElement();

         while(!child.isNull()){
           // setUpdatesEnabled(false);
            outputTree(child);
           // setUpdatesEnabled(true);
            QDomElement childElement = child.toElement();
            if(childElement.nodeName() == "PROGRAMSTOP")
            {
               break;
            }
            child = child.nextSiblingElement();
         }


   p_currScreenHandler = NULL;

   }
}


//------------------------------------------------------------------------------
// Method       : outputTree(QDomNode domNode)
// Filename     : tcpclient.cpp
// Description  : parses the XML Commands and passes them to the 
//                corresponding functions
//------------------------------------------------------------------------------
void ProtocolHandler::outputTree(QDomNode domNode)
{
  if(!p_currScreenHandler)
    return;

MainFrame::vdcdebug("ProtocolHandler","outputTree", "QDomNode domNode");
   QDomElement childElement = domNode.toElement();
   QMetaObject::invokeMethod(p_currScreenHandler, "stopProtocolTimer", Qt::QueuedConnection);
if(childElement.nodeName() == "PROGRAMSTARTUP"){
      handleStartup(childElement);
      QString programName = childElement.attribute("PROGRAMNAME");
      QMetaObject::invokeMethod(p_currScreenHandler, "setProgramName", Qt::QueuedConnection, Q_ARG(QString, programName));
      MainFrame::check_new_pids();
      QString a4gl_version_client = VDC::readSettingsFromIni("", "a4gl_version");
      QString xml_version_client = VDC::readSettingsFromIni("", "xml_version");
      QString a4gl_version_server = p_currScreenHandler->qh_env["A4GL_VERSION"];
      QString xml_version_server = p_currScreenHandler->qh_env["XML_VERSION"];


      /*if(a4gl_version_client.isNull() || a4gl_version_client != a4gl_version_server)
      {
          VDC::saveSettingsToIni("", "a4gl_version", a4gl_version_server);
      }

      if(xml_version_client.isNull() || xml_version_client != xml_version_server)
      {
          if(!xml_version_server.isEmpty())
          {
                  VDC::saveSettingsToIni("", "xml_version", xml_version_server);
          }
      }*/

      if(!a4gl_version_client.isNull())
      {
          if(programName == "./p_master.4ae")
          {
#ifdef Q_OS_WIN
              qDebug() << "QSysInfo::windowsVersion(): " << QSysInfo::windowsVersion();
            switch(QSysInfo::windowsVersion())
            {
                case QSysInfo::WV_95:
                case QSysInfo::WV_2000:
                case QSysInfo::WV_XP:
                case QSysInfo::WV_VISTA:
                   QMetaObject::invokeMethod(p_currScreenHandler, "showUpdateError", Qt::QueuedConnection);
                   break;
                default:
                   QMetaObject::invokeMethod(p_currScreenHandler, "checkForUpdate", Qt::QueuedConnection);
                   break;
              }
#else
              QMetaObject::invokeMethod(p_currScreenHandler, "checkForUpdate", Qt::QueuedConnection);
#endif
          }
      }
      QFile stylesFile(QString("%1.4st").arg(programName));
      if (stylesFile.open(QIODevice::ReadOnly | QIODevice::Text)){
          QString qs_defaultStyle = stylesFile.readAll();
    //      handleXMLStyles(qs_defaultStyle);
          QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLStyles", Qt::QueuedConnection, Q_ARG(QString, qs_defaultStyle));
          stylesFile.close();
      }
      else{
          stylesFile.setFileName(QDir::tempPath() + "/" +"default_vdc3.4st");
           if (stylesFile.open(QIODevice::ReadOnly | QIODevice::Text)){
               QString qs_defaultStyle = stylesFile.readAll();
               QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLStyles", Qt::QueuedConnection, Q_ARG(QString, qs_defaultStyle));
 //              handleXMLStyles(qs_defaultStyle);
               stylesFile.close();
           } else {
               stylesFile.setFileName(QDir::tempPath() + "/" +"default.4st");
                if (stylesFile.open(QIODevice::ReadOnly | QIODevice::Text)){
                    QString qs_defaultStyle = stylesFile.readAll();
                    QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLStyles", Qt::QueuedConnection, Q_ARG(QString, qs_defaultStyle));
      //              handleXMLStyles(qs_defaultStyle);
                    stylesFile.close();
                }
           }
          
      }

      QFile toolbarFile(QString("%1.4tb").arg(programName));
      if (toolbarFile.open(QIODevice::ReadOnly | QIODevice::Text)){
          QString qs_defaultToolbar = toolbarFile.readAll();
          QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLToolBar", Qt::QueuedConnection, Q_ARG(QString, qs_defaultToolbar));
          //handleXMLToolBar(qs_defaultToolbar);
          toolbarFile.close();
      }
      else{
          toolbarFile.setFileName(QDir::tempPath() + "/" +"default.4tb");
           if (toolbarFile.open(QIODevice::ReadOnly | QIODevice::Text)){
               QString qs_defaultToolbar = toolbarFile.readAll();
               QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLToolBar", Qt::QueuedConnection, Q_ARG(QString, qs_defaultToolbar));
               //handleXMLToolBar(qs_defaultToolbar);
               toolbarFile.close();
           }
          
      }

      QFile actionsFile(QString("%1.4ad").arg(programName));
      if (actionsFile.open(QIODevice::ReadOnly | QIODevice::Text)){
          QString qs_defaultActions = actionsFile.readAll();
          QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLActions", Qt::QueuedConnection, Q_ARG(QString, qs_defaultActions));
        //  handleXMLActions(qs_defaultActions);
          actionsFile.close();
      }
      else{
          actionsFile.setFileName(QDir::tempPath() + "/" +"default.4ad");
           if (actionsFile.open(QIODevice::ReadOnly | QIODevice::Text)){
               QString qs_defaultActions = actionsFile.readAll();
               QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLActions", Qt::QueuedConnection, Q_ARG(QString, qs_defaultActions));
             //  handleXMLActions(qs_defaultActions);
               actionsFile.close();
           }
      }

      QFile colorFile(QString("%1.4cf").arg(programName));
      if (colorFile.open(QIODevice::ReadOnly | QIODevice::Text)){
          QString qs_defaultColors = colorFile.readAll();
          QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLColors", Qt::QueuedConnection, Q_ARG(QString, qs_defaultColors));
          //handleXMLColors(qs_defaultColors);
          colorFile.close();
      }
      else{
          colorFile.setFileName(QDir::tempPath() + "/" +"vdc.4cf");
           if (colorFile.open(QIODevice::ReadOnly | QIODevice::Text)){
               QString qs_defaultColors = colorFile.readAll();
               QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLColors", Qt::QueuedConnection, Q_ARG(QString, qs_defaultColors));
              // handleXMLColors(qs_defaultColors);
               colorFile.close();
           }

      }

      QFile iconFile(QString("%1.4id").arg(programName));
      if (iconFile.open(QIODevice::ReadOnly | QIODevice::Text)){
          QString qs_defaultIcon = iconFile.readAll();
          QDomDocument doc;
          //doc.setContent(qs_defaultIcons);
          //p_currScreenHandler->xmlIconDoc = doc;
          QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLActions", Qt::QueuedConnection, Q_ARG(QString, qs_defaultIcon));
          //handleXMLActions(qs_defaultIcon);
          iconFile.close();
      }
      else{
          iconFile.setFileName(QDir::tempPath() + "/" +"vdc.4id");
           if (iconFile.open(QIODevice::ReadOnly | QIODevice::Text)){
                QDomDocument doc;
                QString qs_defaultShortcuts = iconFile.readAll();
                doc.setContent(qs_defaultShortcuts);
                p_currScreenHandler->xmlIconDocDe = doc;
                iconFile.close();
           }

            iconFile.setFileName(QDir::tempPath() + "/" +"vdc_en.4id");
            if (iconFile.open(QIODevice::ReadOnly | QIODevice::Text)){
                QDomDocument doc;
                doc.setContent(iconFile.readAll());
                iconFile.close();
                if(doc.hasChildNodes()) {
                    QMetaObject::invokeMethod(p_currScreenHandler, "parseXmlFile", Qt::DirectConnection, Q_ARG(QDomDocument, doc));
                }
            }
            
            iconFile.setFileName(QDir::tempPath() + "/" +"vdc_de.4id");
            if (iconFile.open(QIODevice::ReadOnly | QIODevice::Text)){
                QDomDocument doc;
                doc.setContent(iconFile.readAll());
                iconFile.close();
                if(doc.hasChildNodes()) {
                    QMetaObject::invokeMethod(p_currScreenHandler, "parseXmlFile", Qt::DirectConnection, Q_ARG(QDomDocument, doc));
                }
            }

            iconFile.setFileName(QDir::tempPath() + "/" +"vdc_fr.4id");
            if (iconFile.open(QIODevice::ReadOnly | QIODevice::Text)){
                QDomDocument doc;
                doc.setContent(iconFile.readAll());
                iconFile.close();
                if(doc.hasChildNodes()) {
                    QMetaObject::invokeMethod(p_currScreenHandler, "parseXmlFile", Qt::DirectConnection, Q_ARG(QDomDocument, doc));
                }
            }


            iconFile.setFileName(QDir::tempPath() + "/" +"vdc_sp.4id");
            if (iconFile.open(QIODevice::ReadOnly | QIODevice::Text)){
                QDomDocument doc;
                doc.setContent(iconFile.readAll());
                iconFile.close();
                if(doc.hasChildNodes()) {
                    QMetaObject::invokeMethod(p_currScreenHandler, "parseXmlFile", Qt::DirectConnection, Q_ARG(QDomDocument, doc));
                }
            }

      }

      QFile shortcutFile(QString("%1.4sc").arg(programName));
      if (shortcutFile.open(QIODevice::ReadOnly | QIODevice::Text)){
          QDomDocument doc;
          doc.setContent(shortcutFile.readAll());
          shortcutFile.close();
          if(doc.hasChildNodes()) {
              QMetaObject::invokeMethod(p_currScreenHandler, "parseXmlFile", Qt::DirectConnection, Q_ARG(QDomDocument, doc));
          }
      }
      else{
          shortcutFile.setFileName(QDir::tempPath() + "/" +"vdc.4sc");
           if (shortcutFile.open(QIODevice::ReadOnly | QIODevice::Text)){
               QDomDocument doc;
               doc.setContent(shortcutFile.readAll());
               shortcutFile.close();
               if(doc.hasChildNodes()) {
                   QMetaObject::invokeMethod(p_currScreenHandler, "parseXmlFile", Qt::DirectConnection, Q_ARG(QDomDocument, doc));
               }
           }

      }

      QString id = childElement.attribute("ID");
      QMetaObject::invokeMethod(p_currScreenHandler, "createWindow", Qt::QueuedConnection, Q_ARG(QString, "dummy_ventas"), Q_ARG(QString, ""), Q_ARG(int, 0), Q_ARG(int, 0), Q_ARG(int, 100), Q_ARG(int, 100), Q_ARG(QString, ""), Q_ARG(QString, id));
     // createWindow("dummy_ventas", "", 0, 0, 100, 100, "", id);
      return;
   }

   if(childElement.nodeName() == "SETAPPLICATIONLAUNCHERXML"){
      QString fileName = childElement.attribute("NAME");

      // 4JS ToolBar XML File
      if(fileName.trimmed().endsWith(".4tb")){
         QString xmlFileString = encodeXMLFile(childElement.text());
         QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLToolBar", Qt::QueuedConnection, Q_ARG(QString, xmlFileString));
         //handleXMLToolBar(xmlFileString);
         return;
      }

      // 4JS Actions XML File
      if(fileName.trimmed().endsWith(".4ad")){
         QString xmlFileString = encodeXMLFile(childElement.text());
         QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLActions", Qt::QueuedConnection, Q_ARG(QString, xmlFileString));
         //handleXMLActions(xmlFileString);
         return;
      }

      // 4JS Style XML File
      if(fileName.trimmed().endsWith(".4st")){
         QString xmlFileString = encodeXMLFile(childElement.text());
         QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLStyles", Qt::QueuedConnection, Q_ARG(QString, xmlFileString));
   //      handleXMLStyles(xmlFileString);
         return;
      }

      // 4JS StartMenu XML File
      if(fileName.trimmed().endsWith(".4sm")){
         QString xmlFileString = encodeXMLFile(childElement.text());
         QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLStartMenu", Qt::QueuedConnection, Q_ARG(QString, xmlFileString));
//         handleXMLStartMenu(xmlFileString);
         return;
      }
      return;
   }

      
   if(childElement.nodeName() == "FILE"){
      QString fileName = childElement.attribute("NAME");
      
      // 4JS ToolBar XML File
      if(fileName.trimmed().endsWith(".4tb")){
         QString xmlFileString = encodeXMLFile(childElement.text());
         QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLToolBar", Qt::QueuedConnection, Q_ARG(QString, xmlFileString));
         //handleXMLToolBar(xmlFileString);
          }

      // 4JS Actions XML File
      if(fileName.trimmed().endsWith(".4ad")){
         QString xmlFileString = encodeXMLFile(childElement.text());
         QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLActions", Qt::QueuedConnection, Q_ARG(QString, xmlFileString));
//         handleXMLActions(xmlFileString);
      }

      // 4JS Style XML File
      if(fileName.trimmed().endsWith(".4st")){
         QString xmlFileString = encodeXMLFile(childElement.text());
         QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLStyles", Qt::QueuedConnection, Q_ARG(QString, xmlFileString));
    //     handleXMLStyles(xmlFileString);
      }

      // VENTAS Color Bars XML-FILE (4cf)
      if(fileName.trimmed().endsWith(".4cf")){
         QString xmlFileString = encodeXMLFile(childElement.text());
         QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLColors", Qt::QueuedConnection, Q_ARG(QString, xmlFileString));
         //handleXMLColors(xmlFileString);
      }
      if(fileName.trimmed().endsWith(".4id")){
          QDomDocument doc;
          QString xmlString = encodeXMLFile(childElement.text());
          doc.setContent(xmlString);
          if(doc.hasChildNodes()) {
                 QMetaObject::invokeMethod(p_currScreenHandler, "parseXmlFile", Qt::DirectConnection, Q_ARG(QDomDocument, doc));
             }
      }

      if(fileName.trimmed().endsWith(".4sc")){
         QDomDocument doc;
         QString xmlString = encodeXMLFile(childElement.text());
         doc.setContent(xmlString);
         if(doc.hasChildNodes()) {
             QMetaObject::invokeMethod(p_currScreenHandler, "parseXmlFile", Qt::DirectConnection, Q_ARG(QDomDocument, doc));
         }
      }

      // 4JS StartMenu XML File
      if(fileName.trimmed().endsWith(".4sm")){
         QString xmlFileString = encodeXMLFile(childElement.text());

         xmlFileString = xmlFileString;
         QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLStartMenu", Qt::QueuedConnection, Q_ARG(QString, xmlFileString));
         //handleXMLStartMenu(xmlFileString);
      return;
        }

      if(saveFile(childElement)) {

      }

      return;
   }

   if(childElement.nodeName() == "RUNINFO"){
      bool startstop = childElement.attribute("STARTSTOP").toInt();
      QString cmd = childElement.attribute("CMD");
      int runcnt = childElement.attribute("RUNCNT").toInt();
      int mode = childElement.attribute("MODE").toInt();
      QMetaObject::invokeMethod(p_currScreenHandler, "setRuninfo", Qt::QueuedConnection, Q_ARG(int, mode), Q_ARG(QString, cmd), Q_ARG(int, runcnt), Q_ARG(bool, startstop));
    //  setRuninfo(mode, cmd, runcnt, startstop);
   }

   if(childElement.nodeName() == "REQUESTFILE"){
      QString fileId = childElement.attribute("FILEID");
      sendFile(fileId);
   }
   
   if(childElement.nodeName() == "EXECUTE"){
      QString value = childElement.text();
      QString fileName = value.toLower();
      int openFileType = 1;

      if (fileName.contains("to=") && !fileName.contains("http:"))
      {
          openFileType = 2;
      }

      if(fileName.contains("mailto:") && !fileName.contains("http:"))
      {
          openFileType = 3;
      }

      if(fileName.startsWith("tic://")) {
          openFileType = 4;
      }


      switch(openFileType)
      {
      case 1:
          QMetaObject::invokeMethod(p_currScreenHandler, "openLocalFile", Qt::QueuedConnection, Q_ARG(QString, value));
          break;
      case 2:
          QMetaObject::invokeMethod(p_currScreenHandler, "openEmailWithAttach", Qt::QueuedConnection, Q_ARG(QString, value));
          break;
      case 3:
          QMetaObject::invokeMethod(p_currScreenHandler, "openEmail", Qt::QueuedConnection, Q_ARG(QString, value));
          break;
      case 4:
          QMetaObject::invokeMethod(p_currScreenHandler, "openEmailWithTobit", Qt::QueuedConnection, Q_ARG(QString, value));
          break;
      default:
          break;
      }

      //Auslagern in Screenhandler
      /*if(openLocalFile == 0)
      {
         //If we want to open a Email Programm or a Website.
        #ifdef Q_OS_LINUX
           QDesktopServices::openUrl(QUrl(fileName, QUrl::TolerantMode));
        #endif
        #ifdef Q_OS_MAC
           QDesktopServices::openUrl(QUrl(fileName, QUrl::TolerantMode));
        #endif
        #ifdef Q_OS_WIN
           QProcess process;
           process.startDetached(QString("rundll32 url.dll,FileProtocolHandler \"%1\"").arg( fileName));
        #endif
        return;
      } else if (openLocalFile == 1){

          //Open File local
      fileName = QDir::tempPath() + "/" + fileName;
      QFileInfo fileInfo(fileName);

          #ifdef Q_OS_LINUX
             QDesktopServices::openUrl(QUrl(QString("file://" + fileInfo.absoluteFilePath()), QUrl::TolerantMode));
          #endif
          #ifdef Q_OS_MAC
             QDesktopServices::openUrl(QUrl(QString("file:///" + fileInfo.absoluteFilePath()), QUrl::TolerantMode));
          #endif
          #ifdef Q_OS_WIN
             QProcess process;
             process.startDetached(QString("rundll32 url.dll,FileProtocolHandler \"%1\"").arg( fileInfo.absoluteFilePath()));
          #endif
      return;
   }*/
   }

   if(childElement.nodeName() == "CALL"){
      //int paramCount = childElement.attribute("NPARAMS").toInt();
      QDomElement paramsElement = childElement.firstChildElement();

      QString qs_function = paramsElement.text();
      paramsElement = paramsElement.nextSiblingElement();

      QString qs_defPath = paramsElement.text();
      paramsElement = paramsElement.nextSiblingElement();

      QString qs_fileNames = paramsElement.text();
      paramsElement = paramsElement.nextSiblingElement();

      QString qs_fileTypes = paramsElement.text();
      paramsElement = paramsElement.nextSiblingElement();

      QString qs_caption = paramsElement.text();

      if(qs_function == "opendir" ||
         qs_function == "openfile" ||
         qs_function == "savefile"){
          QMetaObject::invokeMethod(p_currScreenHandler, "fileBrowser", Qt::QueuedConnection, Q_ARG(QString, qs_function), Q_ARG(QString, qs_defPath), Q_ARG(QString, qs_fileNames), Q_ARG(QString, qs_fileTypes), Q_ARG(QString, qs_caption));

  //       fileBrowser(qs_function,qs_defPath, qs_fileNames, qs_fileTypes, qs_caption);
      }
   }

   if(childElement.nodeName() == "FRONTCALL"){
      QString qs_module = childElement.attribute("MODULE");
      QString qs_name = childElement.attribute("NAME");
      int expect = childElement.attribute("EXPECT").toInt();

      QDomElement paramsElement = childElement.firstChildElement();
      QStringList returnvalues;

      if(qs_module == "Standard"){
       
      }

      if(qs_module == "INTERNAL"){
         if(qs_name == "ui.window.getcurrent"){
            //TODO
            returnvalues << QString::number(p_currScreenHandler->getCurrWindow());
         }

         if(qs_name == "ui.window.getform"){
            //TODO
            returnvalues << QString::number(p_currScreenHandler->getCurrForm());
         }

         if(qs_name == "ui.window.settext"){
            QDomElement values = childElement.firstChildElement();
            QDomElement valueElement = values.firstChildElement().nextSiblingElement();
            QString value =  valueElement.text();
            QMetaObject::invokeMethod(p_currScreenHandler, "setWindowTitle", Qt::QueuedConnection, Q_ARG(QString, value));

            //setWindowTitle(value);
         }

         if(qs_name == "ui.form.setelementhidden"){
            QString fieldName;
            int hidden = false;
            for(int k=0; k<paramsElement.childNodes().count(); k++){
               QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();

               if(k == 1){
                  fieldName = valuesElement.text();
               }

               if(k == 2){
                  hidden = valuesElement.text().toInt();
               }
            }
            setElementHidden(fieldName, hidden);
         }
          if(qs_name == "ui.form.setpagetitle")
          {
              QString oldTabName;
              QString newTabName;
              QString value;
              for(int k=0; k<paramsElement.childNodes().count(); k++){
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 if(k == 0){
                    oldTabName = valuesElement.text();
                 }

                if(k == 1){
                   newTabName = valuesElement.text();
                }
             }
             QMetaObject::invokeMethod(p_currScreenHandler, "setNewTabName", Qt::QueuedConnection, Q_ARG(QString, oldTabName), Q_ARG(QString, newTabName));
         }

         if(qs_name == "ui.form.setattributes")
         {
             QString fieldName;
             QString attribute;
             QString value;
             for(int k=0; k<paramsElement.childNodes().count(); k++){
                QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                if(k == 0){
                    fieldName = valuesElement.text();
                }
                if(k == 1){
                    attribute = valuesElement.text();
                }
                if(k == 2){
                    value = valuesElement.text();
                }
             }
             QMetaObject::invokeMethod(p_currScreenHandler, "setAttributes", Qt::QueuedConnection, Q_ARG(QString, fieldName), Q_ARG(QString, attribute), Q_ARG(QString, value));

         }
         if(qs_name == "ui.form.setelementhidden"){
            QString fieldName;
            int hidden = false;
            for(int k=0; k<paramsElement.childNodes().count(); k++){
               QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();

               if(k == 1){
                  fieldName = valuesElement.text();
               }

               if(k == 2){
                  hidden = valuesElement.text().toInt();
               }
            }
            QMetaObject::invokeMethod(p_currScreenHandler, "setElementHidden", Qt::QueuedConnection, Q_ARG(QString, fieldName), Q_ARG(bool, hidden));
          //  setElementHidden(fieldName, hidden);
         }

         if(qs_name == "ui.form.setfieldhidden"){
            QString fieldName;
            int hidden = false;
            for(int k=0; k<paramsElement.childNodes().count(); k++){
               QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
               if(k == 1){
                  fieldName = valuesElement.text();
               }

               if(k == 2){
                  hidden = valuesElement.text().toInt();
               }
            }
            QMetaObject::invokeMethod(p_currScreenHandler, "setFieldHidden", Qt::QueuedConnection, Q_ARG(QString, fieldName), Q_ARG(bool, hidden));
//            setFieldHidden(fieldName, hidden);
         }
         #ifdef KDChart_Version
         if(qs_name == "ui.gantt.create")
         {
             QMetaObject::invokeMethod(p_currScreenHandler, "createGantt", Qt::QueuedConnection);
//            emit createGantt();

            expect = 0;
         }
         if(qs_name == "ui.gantt.readcsv")
         {
             QStringList params;
              for(int k=0; k<paramsElement.childNodes().count(); k++){
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 params << valuesElement.text();
              }
              QMetaObject::invokeMethod(p_currScreenHandler, "readCsv", Qt::QueuedConnection, Q_ARG(int, params.at(0).toInt()), Q_ARG(QString, params.at(1)));
              //emit ganttReadCsv(params.at(0).toInt(), params.at(1));

              expect = 0;
         }
         if(qs_name == "ui.gantt.setTitle")
         {
             QStringList params;
             for(int k=0; k<paramsElement.childNodes().count(); k++){
                QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                params << valuesElement.text();
             }
             QMetaObject::invokeMethod(p_currScreenHandler, "setGanttTitle", Qt::QueuedConnection, Q_ARG(int, params.at(0).toInt()), Q_ARG(QString, params.at(1)));

//             emit setGanttTitle(params.at(0).toInt(), params.at(1));
             expect = 0;
         }
         #endif
         if(qs_name == "ui.browser.create")
         {
             QStringList params;
              for(int k=0; k<paramsElement.childNodes().count(); k++){
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 params << valuesElement.text();
              }
              QMetaObject::invokeMethod(p_currScreenHandler, "createBrowser", Qt::QueuedConnection);
              //emit createBrowser();
              //Important, we want sending the triggered out of the screenhandler, because there we have the initial index for the browser.
              expect = 0;

         }
         if(qs_name == "ui.browser.openurl")
         {
             QStringList params;
              for(int k=0; k<paramsElement.childNodes().count(); k++){
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 params << valuesElement.text();
              }
           //   emit setUrl(params.at(0).toInt(), QUrl(params.at(1)));

              bool isoEncoding = true;

              if(this->qs_dblocale.contains("UTF8")) {
                  isoEncoding = false;
              }
              QMetaObject::invokeMethod(p_currScreenHandler, "setUrl", Qt::QueuedConnection, Q_ARG(int, params.at(0).toInt()), Q_ARG(QUrl, QUrl(params.at(1))), Q_ARG(bool, isoEncoding));
              //Important, we want sending the triggered out of the screenhandler, because there we have the errorcodes.
              expect = 0;

         }
         if(qs_name == "ui.browser.close")
         {
             QStringList params;
              for(int k=0; k<paramsElement.childNodes().count(); k++){
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 params << valuesElement.text();
              }
              QMetaObject::invokeMethod(p_currScreenHandler, "closeBrowser", Qt::QueuedConnection, Q_ARG(int, params.at(0).toInt()));

              //emit closeBrowser(params.at(0).toInt());
         }
         if(qs_name == "ui.dashboard.additem") {
             QStringList params;
             for(int k=0; k<paramsElement.childNodes().count(); k++){
                QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                params << valuesElement.text();
             }

             ScreenHandler *p_screenHandler = p_currScreenHandler;
             if(p_currScreenHandler->getDashboard() == NULL) {
                 for(int i=0; i < MainFrame::ql_screenhandler->count(); i++)
                 {
                     ScreenHandler *screen = MainFrame::ql_screenhandler->at(i);
                     if(screen->getDashboard() != NULL) {
                        p_screenHandler = screen;
                        break;
                     }
                 }
             }

             QMetaObject::invokeMethod(p_screenHandler, "addDashboardItem", Qt::QueuedConnection, Q_ARG(QString, params.at(0)), Q_ARG(QString, params.at(1)), Q_ARG(QString, params.at(2)), Q_ARG(QString, params.at(3)));

         }

         if(qs_name == "ui.dashboard.getabonnements") {
             QMetaObject::invokeMethod(p_currScreenHandler, "getAbonnements", Qt::QueuedConnection);
             expect = 0;
         }

         if(qs_name == "ui.vdc.dial") {
             QStringList params;
              for(int k=0; k<paramsElement.childNodes().count(); k++){
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 params << valuesElement.text();
              }

             QMetaObject::invokeMethod(p_currScreenHandler, "dial", Qt::QueuedConnection,Q_ARG(QString, params.at(0)));
             //expect = 0;
         }

         if(qs_name == "ui.vdc.playsound") {
             QStringList params;
              for(int k=0; k<paramsElement.childNodes().count(); k++){
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 params << valuesElement.text();
              }

             QMetaObject::invokeMethod(p_currScreenHandler, "playSound", Qt::QueuedConnection,Q_ARG(QString, params.at(0)));
             expect = 0;
         }

         if(qs_name == "ui.vdc.openchartwindow")
         {
             QStringList params;
              for(int k=0; k<paramsElement.childNodes().count(); k++){
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 params << valuesElement.text();
              }
              QMetaObject::invokeMethod(p_currScreenHandler, "openChartWindow", Qt::QueuedConnection, Q_ARG(QString, params.at(0)), Q_ARG(QString, params.at(1)));
              expect = 0;
         }


         if(qs_name == "ui.vdc.texteditor")
         {
             QStringList params;
              for(int k=0; k<paramsElement.childNodes().count(); k++){
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 params << valuesElement.text();
              }
              bool isoEncoding = true;

              if(this->qs_dblocale.contains("UTF8")) {
                  isoEncoding = false;
              }
              QMetaObject::invokeMethod(p_currScreenHandler, "createTextEditor", Qt::QueuedConnection, Q_ARG(QString, params.at(0)), Q_ARG(QString, params.at(1)), Q_ARG(int, params.at(2).toInt()), Q_ARG(bool, isoEncoding));
              expect = 0;
         }

         if(qs_name == "ui.vdc.get_last_sort")
         {
             QStringList params;
              for(int k=0; k<paramsElement.childNodes().count(); k++){
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 params << valuesElement.text();
              }

              int sortIndex = VDC::readSettingsFromIni(params.at(0), "sortLogicalIndex").toInt();
              QString sortIndicator = VDC::readSettingsFromIni(params.at(0), "sortIndicator");

              if(sortIndicator.isEmpty())
              {
                  sortIndicator = "DESC";
              }
              sortIndex++;

//              if ((params.at(0) == "m2zagk") ||
//                  (params.at(0) == "m2zagd") ||
//                  (params.at(0) == "a_vanf") ||
//                  (params.at(0) == "m_mave") ||
//                  (params.at(0) == "m_mave2")) {
//                 sortIndex++;
//              } else {
//                 if(sortIndex == 0) {
//                    sortIndex = 1;
//                 }
//              }

              //returnvalues << getVentasLogicalIndex(sortIndex, params.at(0)) + " " + sortIndicator;
              returnvalues << QString::number(sortIndex) + " " + sortIndicator;
         }

         if(qs_name == "ui.vdc.settingonserver") {
             bool value = false;

             if(VDC::readSettingsFromLocalIni("","saveSettingsOnServer").toInt() != -1)
             {
                 value = VDC::readSettingsFromLocalIni("","saveSettingsOnServer").toInt();
             }

             returnvalues << QString::number(!value);
         }

         if(qs_name == "ui.vdc.action"){
           qDebug() << "werde aufgerufen!!!" << "";
           QStringList params;
            for(int k=0; k<paramsElement.childNodes().count(); k++){
               QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
               params << valuesElement.text();
            }
            
            returnvalues << "0";
            returnvalues <<"Test"; 
         }

         if(qs_name == "ui.vdc.printpdf"){
             QStringList params;
             for(int k=0; k<paramsElement.childNodes().count(); k++){
                QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                params << valuesElement.text();
             }
             QMetaObject::invokeMethod(p_currScreenHandler, "printpdf", Qt::QueuedConnection, Q_ARG(QString, params.at(0)));
           //  emit printpdf(params.at(0));
             //We open the qprintdialog in the screenhandler so we have only there the returncode
             expect = 0;

           }
         if(qs_name == "ui.vdc.openeditor")
         {
             QStringList params;
              for(int k=0; k<paramsElement.childNodes().count(); k++){
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 params << valuesElement.text();
              }

              QMetaObject::invokeMethod(p_currScreenHandler, "createEditor", Qt::BlockingQueuedConnection, Q_ARG(QString, params.at(1)));
              while(!p_currScreenHandler->mHtmlEditor->getEditorStatus())
              {
                  waitTimer::msleep(100);
              }
              returnvalues << "0";
         }

         if(qs_name == "ui.vdc.getdevice")
         {
              returnvalues << "desktop" << "max";
         }

         if(qs_name == "ui.vdc.version")
         {
              returnvalues << "vdc3";
         }

         if(qs_name == "ui.vdc.setclipboard")
         {
             QStringList params;
             for(int k=0; k<paramsElement.childNodes().count(); k++){
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 params << valuesElement.text();
             }
             QMetaObject::invokeMethod(p_currScreenHandler, "setClipboard", Qt::QueuedConnection, Q_ARG(QString, params.at(0)));
         } 

         if(qs_name == "ui.vdc.repgen"){

           QStringList params;
           QString odffile;
           QString sedfile;
           QString temp_datei;
           QString extension;

            for(int k=0; k<paramsElement.childNodes().count(); k++){
               QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
               params << valuesElement.text();
            }
           //params 0-2 sind die uebergabeparameter 
           //Rueckgabe werte:
           //   - Exitcode
            #ifdef VREPGEN_USE
                /*Reportgen *p_reportgen = new Reportgen();
                QFileInfo file(params.at(0));
                sedfile = params.at(1);
                temp_datei = file.baseName();
                extension = file.completeSuffix();
                QFileInfo zieldatei = params.at(2);
                QFile *file1 = new QFile(QDir::tempPath() + "/" + QString(temp_datei + "." + extension));
                #ifdef KDChart_Version
                typedef QVector<QVariant> chartVector;
                qRegisterMetaType<chartVector>("chartVector");
                connect(p_reportgen, SIGNAL(createChart(QString)), this->p_currScreenHandler, SLOT(createChart(QString)));
                connect(p_reportgen, SIGNAL(addChartValue(QString,QString)), this->p_currScreenHandler, SLOT(addChartValue(QString,QString)));
                connect(p_reportgen, SIGNAL(addChartValue(chartVector,chartVector)), this->p_currScreenHandler, SLOT(addChartValue(chartVector, chartVector)));
                connect(p_reportgen, SIGNAL(displayChart(QString, int)), this->p_currScreenHandler, SLOT(displayChart(QString, int)));
                #endif
                if( file.completeSuffix() == "ods" || file.completeSuffix() == "odt" )
                {
                    if(!file1->open(QIODevice::ReadOnly)) {
                        qDebug() << "Datei vom Server nicht empfangen" << "";
                        returnvalues << QString::number(file1->open(QIODevice::ReadOnly));
                    } else {
                        returnvalues << QString::number(p_reportgen->startReportTemplate(QString(temp_datei + "." + extension), sedfile, zieldatei.baseName() + "." + zieldatei.completeSuffix()));
                    }
                } else
                {
                    QString error;
                    error = "Die empfangene Datei ist kein OpenOffice Format :<b>\n" +
                            odffile;
                    MsgBox("Unbekanntes Format", error, "Error", "Ok", "Ok", 0);
                }
                returnvalues << "0";*/

                QFileInfo file(params.at(0));

                if(file.completeSuffix() == "ods" || file.completeSuffix() == "odt")
                {
                    if(QFile::exists(QDir::tempPath() + "/" + params.at(0)))
                    {
                        ReportGenerator *reportgen = new ReportGenerator(params.at(0), params.at(1), params.at(2));
                        reportgen->start();
                        returnvalues <<  QString::number(0);
                    }
                } else {
                    returnvalues << "500";
                }

                returnvalues << "0";
		#endif
		#ifndef VREPGEN_USE
                qDebug() << "Umgebungsvariable nicht gesetzt. Benutz export VREPGEN=YES";
                MsgBox("Unbekannte Umgebungsvariable", "Reportgen wurde nicht mitkompiliert.", "Error", "Ok", "Ok", 0);
                returnvalues << "0";
            #endif
          }
         
          if(qs_name == "ui.vdc.checkodffile")
          {
             QStringList params;
             for(int k=0; k<paramsElement.childNodes().count(); k++){
                QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                params << valuesElement.text();
            
             }
            #ifdef VREPGEN_USE
             QFileInfo odffile(params.at(0));
             QString zieldatei = params.at(1);
             QFile *file = new QFile(QDir::tempPath() + "/" + odffile.baseName() + "." + odffile.completeSuffix());

             if(file->open(QIODevice::ReadOnly))
             {
                 DocumentInfo *documentInfo = new DocumentInfo(odffile.baseName() + "." + odffile.completeSuffix(), zieldatei);
                 returnvalues << QString::number(documentInfo->createInfoFile());

        
             } else {
                qDebug() << "Datei nicht geoffnet" << "";
                returnvalues << "0";
             }
             file->close();
            #endif
            #ifndef VREPGEN_USE
                qDebug() << "Umgebungsvariable nicht gesetzt: benutz export VREPGEN=YES ";
                MsgBox("Unbekannte Umgebungsvariable", "Reportgen wurde nicht mitkompiliert.", "Error", "Ok", "Ok", 0);
                returnvalues << "0";
            #endif
          }  

         if(qs_name == "ui.vdc.odftopdf"){
 
           QStringList params;
            for(int k=0; k<paramsElement.childNodes().count(); k++){
               QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
               params << valuesElement.text();
            
            }

           

            returnvalues << "0";
            returnvalues << "";

         }  

         //returnvalue: 0 for file not found, otherwiese the hash
         if(qs_name == "ui.vdc.md5hashfile")
         {

             QStringList params;

             for(int k=0; k<paramsElement.childNodes().count(); k++){
                QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                params << valuesElement.text();

             }

             QString filename = params.at(0);
             QByteArray ba_filedata = "";
             if(filename == "settings.ini") {
                 filename.prepend(VDC::getPathToSettingsIni());
                 returnvalues << VDC::md5hashfromfile(filename);
             } else {
                 if(QFile::exists(filename)) {
                     returnvalues << VDC::md5hashfromfile(filename);
                 } else {
                     filename.prepend(QDir::tempPath().append("/"));

                     if(QFile::exists(filename)) {
                         returnvalues << VDC::md5hashfromfile(filename);
                     } else {
                         returnvalues << "0"; //File not Found
                     }
                 }
             }
         }

         if(qs_name == "ui.vdc.execute")
         {

             QStringList params;

             for(int k=0; k<paramsElement.childNodes().count(); k++){
                QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                params << valuesElement.text();

             }
             QString fileName = params.at(0);


             //fileName = QDir::tempPath() + "/" + fileName;
             QFileInfo fileInfo(fileName);
             int foundFormat = 0;
             qDebug() << "bin dran";

             if(fileInfo.suffix() == "ods")
             {
                 executeFile(1, fileName);
                 returnvalues << QString::number(openFileSuccess);
                 foundFormat = 1;
             }

             if(fileInfo.suffix() == "odt")
             {
                 executeFile(1, fileName);
                 returnvalues << QString::number(openFileSuccess);
                 foundFormat = 1;
             }
             if(fileInfo.suffix() == "xls" || fileInfo.suffix() == "xlsx")
             {
                 executeFile(1, fileName);
                 returnvalues << QString::number(openFileSuccess);
                 foundFormat = 1;
             }

             if(fileInfo.suffix() == "xlsm")
             {
             #ifndef Q_OS_WIN
                 ExecuteFile *exec = new ExecuteFile;
                 exec->setFileName(fileName);
                 exec->start();

                 while(!exec->isFinished())
                 {
                     waitTimer::msleep(5);
                 }
             #else
                 executeFile(1, fileName);
                 returnvalues << QString::number(openFileSuccess);
             #endif
                 foundFormat = 1;
            }

             if(fileInfo.suffix() == "doc")
             {
                 executeFile(1, fileName);
                 returnvalues << QString::number(openFileSuccess);
                 foundFormat = 1;
             }

             if(fileInfo.suffix() == "docx")
             {
             #ifndef Q_OS_WIN
                 executeFile(0, fileName);
                 returnvalues << "3";
             #else
                 executeFile(1, fileName);
                 returnvalues << QString::number(openFileSuccess);
             #endif
                 foundFormat = 1;
             }

             if(fileInfo.suffix() == "rtf")
             {
                 executeFile(1, fileName);
                 returnvalues << QString::number(openFileSuccess);
                 foundFormat = 1;
                
                 /*while(true)
                 {
                     QFile file(QDir::tempPath() + "/" + fileName);

                     if(file.open(QIODevice::WriteOnly))
                     {
                         break;
                     }
                     waitTimer::msleep(100);
                 }*/
             }

             if(fileInfo.suffix() == "csv")
             {
                 returnvalues << QString::number(openFileSuccess);
                 executeFile(1, fileName);
                 foundFormat = 1;
             }

             if(fileInfo.suffix() == "html1")
             {
                 returnvalues << QString::number(openFileSuccess);
                 executeFile(1, fileName);
                 foundFormat = 1;
             }


             if(fileInfo.suffix() == "txt" || fileInfo.suffix().isEmpty())
             {
                 bool isoEncoding = true;

                 if(this->qs_dblocale.contains("UTF8")) {
                     isoEncoding = false;
                 }

                 QMetaObject::invokeMethod(p_currScreenHandler, "createTextEditor", Qt::QueuedConnection, Q_ARG(QString, fileName), Q_ARG(QString, "nowrap"), Q_ARG(int, 0), Q_ARG(bool, isoEncoding));
                 foundFormat = 1;
                 expect = 0;
             }
             if(foundFormat == 0)
             {
                 executeFile(0, fileName);
                 returnvalues << "1";
             }

         }

         if(qs_name == "ui.vdc.getstdofficeprog")
         {
             int stdOfficeProg = VDC::readSettingsFromLocalIni("","officeStdProg").toInt();

             if(stdOfficeProg > 0)
             {
                 returnvalues << QString::number(stdOfficeProg);
             } else {

                 QMetaObject::invokeMethod(p_currScreenHandler, "createStdProgWindow", Qt::QueuedConnection);
                 for(int i=0; i < 100000; i++)
                 {
                     sleep(1);
                     if(p_currScreenHandler->stdOfficeProg > 0)
                     {
                         returnvalues << QString::number(p_currScreenHandler->stdOfficeProg);
                         break;
                     }
                 }
             }
         }

         if(qs_name == "ui.interface.settext"){
            QDomElement values = childElement.firstChildElement();
            QDomElement valueElement = values.firstChildElement();
            QString value = valueElement.text();
            QMetaObject::invokeMethod(p_currScreenHandler, "setInterfaceText", Qt::QueuedConnection, Q_ARG(QString, value));
         }

        if(qs_name == "ui.vdc.filebrowser")
        {
            QStringList params;

            for(int k=0; k<paramsElement.childNodes().count(); k++){
            QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
            params << valuesElement.text();
            }

            QString function = params.at(0);
            QString filename = params.at(1);

            QMetaObject::invokeMethod(p_currScreenHandler, "getFileBrowser", Qt::QueuedConnection, Q_ARG(QString, function), Q_ARG(QString, filename));
            expect = 0;

        }


         if(qs_name == "ui.combobox.additem"){
            int id = -1;
            QString text;
            QString value;
            for(int k=0; k<paramsElement.childNodes().count(); k++){
               QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
               if(k == 0){
                  id = valuesElement.text().toInt();
               }

               if(k == 1){
                  text = valuesElement.text();
               }

               if(k == 2){
                  value = valuesElement.text();
               }
            }
            QMetaObject::invokeMethod(p_currScreenHandler, "addComboBoxItem", Qt::QueuedConnection, Q_ARG(int, id), Q_ARG(QString, text), Q_ARG(QString, value));
        //    addComboBoxItem(id, text, value);
         }

         if(qs_name == "ui.combobox.removeitem"){
            int id = -1;
            QString text;
            QString value;
            for(int k=0; k<paramsElement.childNodes().count(); k++){
               QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
               if(k == 0){
                  id = valuesElement.text().toInt();
               }

               if(k == 1){
                  text = valuesElement.text();
               }
            }
             QMetaObject::invokeMethod(p_currScreenHandler, "removeComboBoxItem", Qt::QueuedConnection, Q_ARG(int, id), Q_ARG(QString, text));
         //   removeComboBoxItem(id, text);
         }

         if(qs_name == "ui.combobox.clear"){
            QDomElement values = childElement.firstChildElement();
            QDomElement valueElement = values.firstChildElement();
            id = valueElement.text().toInt();
            QMetaObject::invokeMethod(p_currScreenHandler, "clearComboBox", Qt::QueuedConnection, Q_ARG(int, id));
            //p_currScreenHandler->clearComboBox(id);
         }

         if(qs_name == "ui.combobox.forname"){
            QDomElement values = childElement.firstChildElement();
            QDomElement valueElement = values.firstChildElement();
            QString value = valueElement.text();

            while(p_currScreenHandler->currForm() == NULL)
            {
                waitTimer::msleep(100);
            }
            int waitcounter = 0;

            while(p_currScreenHandler->currForm()->findFieldIdByName(value) == -1)
            {
                waitTimer::msleep(100);
                waitcounter++;
                if(waitcounter > 10)
                {
                    break;
                }
            }

            returnvalues << QString::number(p_currScreenHandler->currForm()->findFieldIdByName(value));
            //fornameComboBox(value);
            /*QMetaObject::invokeMethod(p_currScreenHandler, "fornameComboBox", Qt::DirectConnection, Q_ARG(QString, value));
            //Important, threadsafe
            expect = 0;*/
         }

         if(qs_name == "ui.combobox.getcolumnname"){
            QDomElement values = childElement.firstChildElement();
            QDomElement valueElement = values.firstChildElement();
            int id = valueElement.text().toInt();
        //    returnvalues <<  WidgetHelper::getWidgetColName(p_currScreenHandler->currForm()->findFieldById(id));
            QMetaObject::invokeMethod(p_currScreenHandler, "getColumnNameComboBox", Qt::QueuedConnection, Q_ARG(int, id));
         //   getColumnNameComboBox(id);
            expect = 0;
         }

         if(qs_name == "ui.combobox.getitemname"){
            int id = -1;
            int pos = -1;
            for(int k=0; k<paramsElement.childNodes().count(); k++){
               QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
               if(k == 0){
                  id = valuesElement.text().toInt();
               }

               if(k == 1){
                  pos = valuesElement.text().toInt();
               }
            }
            QMetaObject::invokeMethod(p_currScreenHandler, "getItemNameComboBox", Qt::QueuedConnection, Q_ARG(int, id), Q_ARG(int, pos));
         //   getItemNameComboBox(id, pos);


            expect = 0;
         }

         if(qs_name == "ui.combobox.getitemcount"){
            QDomElement values = childElement.firstChildElement();
            QDomElement valueElement = values.firstChildElement();
            int id = valueElement.text().toInt();
            QMetaObject::invokeMethod(p_currScreenHandler, "getItemCountComboBox", Qt::QueuedConnection, Q_ARG(int, id));
            //getItemCountComboBox(id);
            expect = 0;
         }

         if(qs_name == "ui.combobox.getitemtext"){
            int id = -1;
            int pos = -1;
            for(int k=0; k<paramsElement.childNodes().count(); k++){
               QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
               if(k == 0){
                  id = valuesElement.text().toInt();
               }

               if(k == 1){
                  pos = valuesElement.text().toInt();
               }
            }

            getItemTextComboBox(id, pos);
            expect = 0;
         }

         if(qs_name == "ui.combobox.gettablename"){
            QDomElement values = childElement.firstChildElement();
            QDomElement valueElement = values.firstChildElement();
            int id = valueElement.text().toInt();
            QMetaObject::invokeMethod(p_currScreenHandler, "getTableNameComboBox", Qt::QueuedConnection, Q_ARG(int, id));
      //      getTableNameComboBox(id);
            expect = 0;
         }

         if(qs_name == "ui.combobox.gettag"){
         }

         if(qs_name == "ui.combobox.getindexof"){
             int id = -1;
             QString text;
             for(int k=0; k<paramsElement.childNodes().count(); k++){
                QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                if(k == 0){
                   id = valuesElement.text().toInt();
                }

                if(k == 1){
                   text = valuesElement.text();
                }
             }
             QMetaObject::invokeMethod(p_currScreenHandler, "getIndexOfComboBox", Qt::QueuedConnection, Q_ARG(int, id), Q_ARG(QString, text));
//             getIndexOfComboBox(id, text);
             expect = 0;

         }

         if(qs_name == "ui.menu.showhide"){
             QHash<QString, bool> qh_menuoptions;
             QDomElement values = childElement.firstChildElement();
             QString commandName;
             for(int i=0; i<values.childNodes().count(); i++){
                 QDomElement valueElement = values.childNodes().at(i).toElement();

                 if(i%2 == 0){
                     commandName = valueElement.text();
                 }
                 else{
                     if(valueElement.text() == "Y"){
                         QMetaObject::invokeMethod(p_currScreenHandler, "showOption", Qt::QueuedConnection, Q_ARG(QString, commandName));
//                         showOption(commandName);
                         commandName = "";
                     }
                     else{
                         QMetaObject::invokeMethod(p_currScreenHandler, "hideOption", Qt::QueuedConnection, Q_ARG(QString, commandName));
                         hideOption(commandName);
                         commandName = "";
                     }
                 }

             }
         }


         if(qs_name == "ui.progress.create")
         {
             QStringList params;
              for(int k=0; k<paramsElement.childNodes().count(); k++){
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 params << valuesElement.text();
              }

         /*                hideOption(commandName);
                         commandName = "";
                     }
                 }

             }*/
         }


         if(qs_name == "ui.progress.create")
         {
             QStringList params;
              for(int k=0; k<paramsElement.childNodes().count(); k++){
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 params << valuesElement.text();
              }

              QMetaObject::invokeMethod(p_currScreenHandler, "createProgressWindow", Qt::QueuedConnection, Q_ARG(int, true));
              //  emit createProgressWindow();
              //Important, we want sending the triggered out of the screenhandler, because there we have the initial index for the progress-window.
              expect = 0;

         }

         if(qs_name == "ui.progress.show")
         {
             QStringList params;
              for(int k=0; k<paramsElement.childNodes().count(); k++){
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 params << valuesElement.text();
              }
              QMetaObject::invokeMethod(p_currScreenHandler, "setProgressVisible", Qt::QueuedConnection, Q_ARG(int, params.at(0).toInt()), Q_ARG(bool, true));
              //emit setProgressVisible(params.at(0).toInt(), true);

         }

         if(qs_name == "ui.progress.hide")
         {

             QStringList params;
              for(int k=0; k<paramsElement.childNodes().count(); k++){
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 params << valuesElement.text();
              }
              QMetaObject::invokeMethod(p_currScreenHandler, "setProgressVisible", Qt::QueuedConnection, Q_ARG(int, params.at(0).toInt()), Q_ARG(bool, false));
            //  emit setProgressVisible(params.at(0).toInt(), false);

         }

         if(qs_name == "ui.progress.settitle")
         {
             QStringList params;
              for(int k=0; k<paramsElement.childNodes().count(); k++){
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 params << valuesElement.text();
              }
              QMetaObject::invokeMethod(p_currScreenHandler, "setProgressTitle", Qt::QueuedConnection, Q_ARG(int, params.at(0).toInt()), Q_ARG(QString, params.at(1)));
              //emit setProgressTitle(params.at(0).toInt(), params.at(1));

         }

         if(qs_name == "ui.progress.settext")
         {

             QStringList params;
             for(int k=0; k<paramsElement.childNodes().count(); k++){
                QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                params << valuesElement.text();
             }

             if(params.count() > 2)
             {
                 QMetaObject::invokeMethod(p_currScreenHandler, "setProgressText", Qt::QueuedConnection, Q_ARG(int, params.at(0).toInt()), Q_ARG(QString, params.at(1)), Q_ARG(int, params.at(2).toInt()));
             } else {
                 QMetaObject::invokeMethod(p_currScreenHandler, "setProgressText", Qt::QueuedConnection, Q_ARG(int, params.at(0).toInt()), Q_ARG(QString, params.at(1)), Q_ARG(int, 0));
             }
         }

         if(qs_name == "ui.progress.close")
         {

             QStringList params;
              for(int k=0; k<paramsElement.childNodes().count(); k++){
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 params << valuesElement.text();
              }
              QMetaObject::invokeMethod(p_currScreenHandler, "closeProgressWindow", Qt::QueuedConnection, Q_ARG(int, params.at(0).toInt()));
             // emit closeProgressWindow(params.at(0).toInt());
         }




      }

      if(expect > 0){
         QDomDocument doc;
         QDomElement triggeredElement = doc.createElement("TRIGGERED");
         triggeredElement.setAttribute("ID", -123);
         doc.appendChild(triggeredElement);

         QDomElement syncValuesElement = doc.createElement("SVS");
         triggeredElement.appendChild(syncValuesElement);
         for(int v = 0; v<returnvalues.size(); v++)
         {
            QDomElement syncValueElement = doc.createElement("SV");
            syncValuesElement.appendChild(syncValueElement);
            QDomText text = doc.createTextNode(returnvalues.at(v));
            syncValueElement.appendChild(text);
         }

         QString returnString = doc.toString();

         //makeResponse(returnString.trimmed());
         QMetaObject::invokeMethod(p_currScreenHandler, "sendDirect", Qt::DirectConnection, Q_ARG(QString, returnString.trimmed()));
         //p_currScreenHandler->sendDirect(returnString.trimmed());
      }
      
   }


   if(childElement.nodeName() == "CREATEWINDOW"){
      // Window Title
      QString window = childElement.attribute("NAME");
      QString id = childElement.attribute("ID");
      
      // Position X
      int x = childElement.attribute("X").toInt();
      
      // Position Y
      int y = childElement.attribute("Y").toInt();

      int h = childElement.attribute("H").toInt();
      int w = childElement.attribute("W").toInt();

      // ATTRIBUTE - not used atm
      QString attribute = childElement.attribute("ATTRIBUTE");
      
      // SOURCE (FORMFILE NAME) - not used atm
      QString source = childElement.attribute("SOURCE");
      
      // TEXT  - not used atm
      QString text = childElement.attribute("TEXT");
      
      // STYLE - window Style
      QString style = childElement.attribute("STYLE");
      
      /* maybe in the furue... 
      // ERROR_LINE  - not used atm
      int error_line = childElement.attribute("ERROR_LINE").toInt();
      
      // PROMPT_LINE  - not used atm
      int prompt_line = childElement.attribute("PROMPT_LINE").toInt();
      
      // MENU_LINE  - not used atm
      int menu_line = childElement.attribute("MENU_LINE").toInt();
      
      // BORDER  - not used atm
      int border = childElement.attribute("BORDER").toInt();
      
      // COMMENT_LINE  - not used atm
      int comment_line = childElement.attribute("COMMENT_LINE").toInt();
      
      // MESSAGE_LINE  - not used atm
      int message_line = childElement.attribute("MESSAGE_LINE").toInt();
      */

      QMetaObject::invokeMethod(p_currScreenHandler, "createWindow", Qt::QueuedConnection, Q_ARG(QString, window), Q_ARG(QString, style), Q_ARG(int, x), Q_ARG(int, y), Q_ARG(int, h), Q_ARG(int, w), Q_ARG(QString, source), Q_ARG(QString, id));
     // createWindow(window, style, x, y, h, w, source,id);
      return;
   }

   if(childElement.nodeName() == "OPENFORM"){
      QString window = childElement.attribute("FORMNAME");

      //createWindow(window, "", 0, 0, 0, 0, "", "");
      //QMetaObject::invokeMethod(p_currScreenHandler, "createWindow", Qt::QueuedConnection, Q_ARG(QString, window), Q_ARG(QString, ""), Q_ARG(int, 0), Q_ARG(int, 0), Q_ARG(int, 0), Q_ARG(int, 0), Q_ARG(QString, ""), Q_ARG(QString, ""));


      if(childElement.firstChildElement().nodeName() == "XMLFORM"){
        QString xmlFormString = encodeXMLFile(childElement.text());
        QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLForm", Qt::QueuedConnection, Q_ARG(QString, window), Q_ARG(QString, xmlFormString), Q_ARG(bool, false));
//        handleXMLForm(window, xmlFormString, false);
      }

      if(childElement.firstChildElement().nodeName() == "FORM"){
         QDomDocument xmlForm("FORM");
         xmlForm.appendChild(childElement.firstChildElement());
         
         QString xmlFormString = xmlForm.toString();
     //    handleAubitForm(window, xmlFormString, false);
         QMetaObject::invokeMethod(p_currScreenHandler, "handleAubitForm", Qt::QueuedConnection, Q_ARG(QString, window), Q_ARG(QString, xmlFormString), Q_ARG(bool, false));
      }

      QDomNodeList ql_nodes = childElement.childNodes();
      for(int k=0; k<ql_nodes.count(); k++){
         if(ql_nodes.at(k).nodeName() == "FORM"){
            QDomDocument xmlForm("FORM");
            xmlForm.appendChild(ql_nodes.at(k));
         
            QString xmlFormString = xmlForm.toString();
            QMetaObject::invokeMethod(p_currScreenHandler, "handleAubitForm", Qt::QueuedConnection, Q_ARG(QString, window), Q_ARG(QString, xmlFormString), Q_ARG(bool, false));
//            handleAubitForm(window, xmlFormString, false);
         }
      }
      return;
   }

   if(childElement.nodeName() == "DISPLAYFORM"){
//      displayForm( childElement.attribute("FORMNAME"));
      QMetaObject::invokeMethod(p_currScreenHandler, "displayForm", Qt::QueuedConnection, Q_ARG(QString, childElement.attribute("FORMNAME")));
   }

   if(childElement.nodeName() == "OPENWINDOWWITHFORM"){

//      closeWindow("screen");

      // Window Title
      QString window = childElement.attribute("WINDOW");
      QString id = childElement.attribute("ID");
      
      // Position X
      int x = childElement.attribute("X").toInt();
      
      // Position Y
      int y = childElement.attribute("Y").toInt();

      // ATTRIBUTE - not used atm
      QString attribute = childElement.attribute("ATTRIBUTE");
      
      // SOURCE (FORMFILE NAME) - not used atm
      QString source = childElement.attribute("SOURCE");
      
      // TEXT  - not used atm
      QString text = childElement.attribute("TEXT");
      
      // STYLE - window Style
      QString style = childElement.attribute("STYLE");
      
      /* maybe in the furue... 
      // ERROR_LINE  - not used atm
      int error_line = childElement.attribute("ERROR_LINE").toInt();
      
      // PROMPT_LINE  - not used atm
      int prompt_line = childElement.attribute("PROMPT_LINE").toInt();
      
      // MENU_LINE  - not used atm
      int menu_line = childElement.attribute("MENU_LINE").toInt();
      oc
      // BORDER  - not used atm
      int border = childElement.attribute("BORDER").toInt();
      
      // COMMENT_LINE  - not used atm
      int comment_line = childElement.attribute("COMMENT_LINE").toInt();
      
      // MESSAGE_LINE  - not used atm
      int message_line = childElement.attribute("MESSAGE_LINE").toInt();
      */

     // createWindow(window, style, x, y, 0, 0, source,id);
      QMetaObject::invokeMethod(p_currScreenHandler, "createWindow", Qt::QueuedConnection, Q_ARG(QString, window), Q_ARG(QString, style), Q_ARG(int, x), Q_ARG(int, y), Q_ARG(int, 0), Q_ARG(int, 0), Q_ARG(QString, source), Q_ARG(QString, id));

      if(childElement.firstChildElement().nodeName() == "XMLFORM"){
        QString xmlFormString = encodeXMLFile(childElement.text());

        QMetaObject::invokeMethod(p_currScreenHandler, "handleXMLForm", Qt::QueuedConnection, Q_ARG(QString, window), Q_ARG(QString, xmlFormString), Q_ARG(bool, true));
       // handleXMLForm(window, xmlFormString, true);
      }

      if(childElement.firstChildElement().nodeName() == "FORM"){
         QDomDocument xmlForm("FORM");
         xmlForm.appendChild(childElement.firstChildElement());
         
         QString xmlFormString = xmlForm.toString();
         QMetaObject::invokeMethod(p_currScreenHandler, "handleAubitForm", Qt::QueuedConnection, Q_ARG(QString, window), Q_ARG(QString, xmlFormString), Q_ARG(bool, true));
      //   handleAubitForm(window, xmlFormString, true);
      }

      QDomNodeList ql_nodes = childElement.childNodes();
      for(int k=0; k<ql_nodes.count(); k++){
         if(ql_nodes.at(k).nodeName() == "FORM"){
            QDomDocument xmlForm("FORM");
            xmlForm.appendChild(ql_nodes.at(k));
         
            QString xmlFormString = xmlForm.toString();
      //      handleAubitForm(window, xmlFormString, true);
            QMetaObject::invokeMethod(p_currScreenHandler, "handleAubitForm", Qt::QueuedConnection, Q_ARG(QString, window), Q_ARG(QString, xmlFormString), Q_ARG(bool, true));
         }
      }
      return;
   }

   if(childElement.nodeName() == "UIOPTION"){
      QString name = childElement.attribute("NAME");
      QString value = childElement.attribute("VALUE");
      return;
   }

   if(childElement.nodeName() == "OPTIONS"){
      QString type = childElement.attribute("TYPE");
      QString value = childElement.attribute("VALUE");
      QMetaObject::invokeMethod(p_currScreenHandler, "setOptions", Qt::QueuedConnection, Q_ARG(QString, type), Q_ARG(QString, value));

      return;
   }

   if(childElement.nodeName() == "SETWINDOWTITLE"){
      QString title = childElement.attribute("TEXT");
      //setWindowTitle(title);
      QMetaObject::invokeMethod(p_currScreenHandler, "setInterfaceText", Qt::QueuedConnection, Q_ARG(QString, title));
      //p_currScreenHandler->setInterfaceText(title);
      return;
   }

   if(childElement.nodeName() == "CURRENTWINDOW"){
      QString name = childElement.attribute("WINDOW");
      QMetaObject::invokeMethod(p_currScreenHandler, "activeWindow", Qt::QueuedConnection, Q_ARG(QString, name));
     // activeWindow(name);
      return;
   }


   if(childElement.nodeName() == "MENU"){
      int context = childElement.attribute("CONTEXT").toInt();
      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, childElement.nodeName()), Q_ARG(bool, true), Q_ARG(int, context));
    //  setFormOpts(childElement.nodeName(), true, context);
      this->handleMenuElement(childElement);
      //QMetaObject::invokeMethod(p_currScreenHandler, "showWindow", Qt::QueuedConnection);
      QMetaObject::invokeMethod(p_currScreenHandler, "setWaitCursor", Qt::QueuedConnection);
      return;
   }

   if(childElement.nodeName() == "NEXTOPTION"){
      int context = childElement.attribute("CONTEXT").toInt();
      QString name = childElement.attribute("OPTION").trimmed();
      QMetaObject::invokeMethod(p_currScreenHandler, "nextOption", Qt::QueuedConnection, Q_ARG(QString, name), Q_ARG(int, context));
      //nextOption(name, context);
      return;
   }

   if(childElement.nodeName() == "PROMPT"){
      //int context = childElement.attribute("CONTEXT").toInt();
      //int promptAttribute = childElement.attribute("PROMPTATTRIBUTE").toInt();
      //int fieldAttribute = childElement.attribute("FIELDATTRIBUTE").toInt();
      QString text = childElement.attribute("TEXT");
      int charMode = childElement.attribute("CHARMODE").toInt();
      //int helpNo = childElement.attribute("CHARMODE").toInt();
      int fieldAttribute = childElement.attribute("FIELDATTRIBUTE").toInt();
      QString attributeStyle = childElement.attribute("ATTRIB_STYLE");
      QString attributeText = childElement.attribute("ATTRIB_TEXT");
      QMetaObject::invokeMethod(p_currScreenHandler, "createPrompt", Qt::QueuedConnection, Q_ARG(QString, text), Q_ARG(int, charMode), Q_ARG(int, fieldAttribute), Q_ARG(QString, attributeStyle));
     // createPrompt(text, charMode, fieldAttribute, attributeStyle);
      return;
   }



   if(childElement.nodeName() == "SETKEYLABEL"){
      //int dialog = childElement.attribute("DIALOG").toInt();
      QString label = childElement.attribute("LABEL");
      QString text  = childElement.attribute("TEXT").trimmed();
      QMetaObject::invokeMethod(p_currScreenHandler, "setKeyLabel", Qt::QueuedConnection, Q_ARG(QString, label), Q_ARG(QString, text));
      QMetaObject::invokeMethod(p_currScreenHandler, "checkFglformState", Qt::QueuedConnection);
      // setKeyLabel(label, text);
      return;
   }

   if(childElement.nodeName() == "SETCURSOR"){
      int position = childElement.attribute("POSITION").toInt();
      QMetaObject::invokeMethod(p_currScreenHandler, "setCursorPosition", Qt::QueuedConnection, Q_ARG(int, position-1));
      //setCursorPosition(position-1);
      return;
   }

   if(childElement.nodeName() == "ERROR"){
      QString text = childElement.text();
 //     displayError(text);
      QMetaObject::invokeMethod(p_currScreenHandler, "displayError", Qt::QueuedConnection, Q_ARG(QString, text));
      return;
   }

   if(childElement.nodeName() == "MESSAGE"){
      QString text = childElement.text();
    //  displayMessage(text);
      QMetaObject::invokeMethod(p_currScreenHandler, "displayMessage", Qt::QueuedConnection, Q_ARG(QString, text));
      return;
   }

   if(childElement.nodeName() == "HIDEOPTION"){
      QString id = childElement.attribute("OPTION");
      QMetaObject::invokeMethod(p_currScreenHandler, "hideOption", Qt::QueuedConnection, Q_ARG(QString, id));
      //hideOption(id);
      return;
   }

   if(childElement.nodeName() == "SHOWOPTION"){
      QString id = childElement.attribute("OPTION");
      QMetaObject::invokeMethod(p_currScreenHandler, "showOption", Qt::QueuedConnection, Q_ARG(QString, id));
      //showOption(id)
      return;
   }

   if(childElement.nodeName() == "CLEAR"){
      clearDisplayArray(childElement);
      return;
   }

   if(childElement.nodeName() == "DISPLAYAT"){
      handleDisplayAtElement(childElement);
      return;
   }

   if(childElement.nodeName() == "DISPLAYTO"){
      handleDisplayToElement(childElement);
      return;
   }

   if(childElement.nodeName() == "DISPLAYARRAY"){
      int context = childElement.attribute("CONTEXT").toInt();
      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, "DISPLAYARRAY"), Q_ARG(bool, true), Q_ARG(int, context));
 //     setFormOpts("DISPLAYARRAY", true, context);
      handleEventsElement(childElement);
      handleDisplayArrayElement(childElement);
      QMetaObject::invokeMethod(p_currScreenHandler, "checkFglformState", Qt::QueuedConnection);
      return;
   }

   if(childElement.nodeName() == "INPUTARRAY"){
      int context = childElement.attribute("CONTEXT").toInt();
      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, "INPUTARRAY"), Q_ARG(bool, true), Q_ARG(int, context));//setFormOpts("INPUTARRAY", true, context);

      handleEventsElement(childElement);
      handleDisplayArrayElement(childElement);
      QMetaObject::invokeMethod(p_currScreenHandler, "checkFglformState", Qt::QueuedConnection);
      return;
   }

   //SET ARR LINE FOR SCREEN RECORD
   if(childElement.nodeName() == "SETARRLINE"){
      int line = childElement.attribute("LINE").toInt();
      QMetaObject::invokeMethod(p_currScreenHandler, "setArrLine", Qt::QueuedConnection, Q_ARG(int, line));
     // setArrLine(line);
   }
   
   //SET SCR LINE FOR SCREEN RECORD
   if(childElement.nodeName() == "SETSCRLINE"){
      int line = childElement.attribute("LINE").toInt();
      QMetaObject::invokeMethod(p_currScreenHandler, "setScrLine", Qt::QueuedConnection, Q_ARG(int, line));
    //  setScrLine(line);
   }


   if(childElement.nodeName() == "INPUT"){
      int context = childElement.attribute("CONTEXT").toInt();
      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, "INPUT"), Q_ARG(bool, true), Q_ARG(int, context));
      //setFormOpts("INPUT", true, context);
      handleEventsElement(childElement);
      handleInputElement(childElement);
      QMetaObject::invokeMethod(p_currScreenHandler, "setFieldOrder", Qt::QueuedConnection, Q_ARG(QStringList, qsl_fieldList));
     // setFieldOrder(qsl_fieldList);
      QMetaObject::invokeMethod(p_currScreenHandler, "setFieldFocus", Qt::QueuedConnection);
     // setFieldFocus(qsl_fieldList.first());
      QMetaObject::invokeMethod(p_currScreenHandler, "checkFglformState", Qt::QueuedConnection);
      return;
   }

   if(childElement.nodeName() == "CONSTRUCT"){
      int context = childElement.attribute("CONTEXT").toInt();
      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, childElement.nodeName()), Q_ARG(bool, true), Q_ARG(int, context));
//      setFormOpts(childElement.nodeName(), true, context);
      handleEventsElement(childElement);
     // createActionMenu();
      QMetaObject::invokeMethod(p_currScreenHandler, "createActionMenu", Qt::QueuedConnection);
/*
      createActionMenuButton("ACCEPT", "ACCEPT", "");
      createActionMenuButton("CANCEL", "CANCEL", "");
*/
      handleConstructElement(childElement);
      QMetaObject::invokeMethod(p_currScreenHandler, "setFieldOrder", Qt::QueuedConnection, Q_ARG(QStringList, qsl_fieldList));
     // setFieldOrder(qsl_fieldList);
      QMetaObject::invokeMethod(p_currScreenHandler, "setFieldFocus", Qt::QueuedConnection);
      QMetaObject::invokeMethod(p_currScreenHandler, "checkFglformState", Qt::QueuedConnection);
     // setFieldFocus(qsl_fieldList.first());
      return;
   }

   if(childElement.nodeName() == "NEXTFIELD"){
      QString field = childElement.attribute("FIELD");
      QMetaObject::invokeMethod(p_currScreenHandler, "setFieldFocus", Qt::QueuedConnection, Q_ARG(QString, field));
      //setFieldFocus(field);
      return;
   }

   
   if(childElement.nodeName() == "WAITFOREVENT"){
      handleWaitForEventElement(childElement);
      return;
   }

   if(childElement.nodeName() == "FREE"){
      QString type = childElement.attribute("TYPE");
      p_currScreenHandler->qsl_activeFieldNames.clear();
      int context = childElement.attribute("CONTEXT").toInt();
   //   setFormOpts(type, false, context);
      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, type), Q_ARG(bool, false), Q_ARG(int, context));
      return;
   }

   
   if(childElement.nodeName() == "CLOSEWINDOW"){
      QString name = childElement.attribute("WINDOW");
      QMetaObject::invokeMethod(p_currScreenHandler, "closeWindow", Qt::QueuedConnection, Q_ARG(QString, name));
    //  closeWindow(name);
      return;
   }

      if(childElement.nodeName() == "WINQUESTION"){
      QString title;
       QString text;
       QString defaultBtn;
       QString possibleButtons;
       QString icon;
              title = childElement.attribute("TITLE");
              text = childElement.attribute("TEXT");
              defaultBtn = childElement.attribute("DEFAULT");
              possibleButtons = childElement.attribute("POS");
              icon = childElement.attribute("ICON");
            //  MsgBox(title,text,icon,possibleButtons,defaultBtn,1);
              QMetaObject::invokeMethod(p_currScreenHandler, "MsgBox", Qt::QueuedConnection, Q_ARG(QString, title), Q_ARG(QString, text), Q_ARG(QString, icon), Q_ARG(QString, possibleButtons), Q_ARG(QString, defaultBtn), Q_ARG(int, 1));
              //makeResponse("<TRIGGERED ID=\""+ret+"\"/>");

      return;
   }


   if(childElement.nodeName() == "PROGRAMSTOP"){
       QString str="";
      int exitCode = childElement.attribute("EXITCODE").toInt();
      if(exitCode != 0){
          QString res;
         QFile file("error.log");
         if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

         QTextStream out(&file);
         QDomNodeList children = domNode.childNodes();
         for(int i=0; i<children.count(); ++i){
            QDomNode child = children.at(i);
            if(!child.isElement()){
               return;
            }

            QDomElement currentElement = child.toElement();

            QString nodeName = currentElement.nodeName();

            if(nodeName == "line"){
                   str+=currentElement.text()+"\n";
                    out << currentElement.text()+"\n";
            }
         }

         file.close();
         QMetaObject::invokeMethod(p_currScreenHandler, "MsgBox", Qt::QueuedConnection, Q_ARG(QString, "Program stopped"), Q_ARG(QString, str), Q_ARG(QString, "Warning"), Q_ARG(QString, "Ok"), Q_ARG(QString, "Ok"), Q_ARG(int, 0));
        // MsgBox("Program stopped",str,"Warning","Ok","Ok",0);

      }

      for(int j=0; j<qsl_receivedFiles.count(); j++){
         QFile::remove(qsl_receivedFiles.at(j));
      }
      return;
   }

   
}

QString ProtocolHandler::getVentasLogicalIndex(int index, QString formmask)
{
    int logicalIndex = -1;
    QString form = formmask;

    if(form == "a_r4s")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_vkopf")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_akontr")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_apos")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_akpos")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_dassdok")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_akprov2")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_sammel")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_rech1")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_vlkopf")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_lskopf")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_rgko")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_partie")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_job")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_jobhis")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_vkposhis")
    {
        logicalIndex = index + 1;
    }

    /*if(form == "a_vpos")
    {
        logicalIndex = index + 1;
    }*/

    if(form == "a_vkap")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_pzkopf")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_plos")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_pkopf")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_zuord")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_zugang")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_zollsatz")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_zeilenk")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_wrg_kurs")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_wgr2")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_wgr")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_waehrung")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_provwgr")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_vprov")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_vkpr3")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_vkpr_2")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_vkpr2")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_vkpr")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_vers")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_vakopfgrund")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_umrch_e")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_uebkonto")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_tarifmtx")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_tariflz")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_tarif")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_stueck")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_strukt")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_spstext")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_stext")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_stdzetpos")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_stdzet")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_stamm_k3")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_stamm_k2")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_stamm_ky")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_sprache")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_serie")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_histser")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_sdmcds")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_sbreite")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_reklam")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_pzeabwes")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_port")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_police")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_pmasch")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_pmaschwe")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_pmaschar")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_plz")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_platztyp")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_plansch")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_pkschema")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_pkreis")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_pkalend")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_pkalpmas")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_pkalpers_b")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_pkalpers")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_personal")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_persarko")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_periode")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_sppaymen")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_payment")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_spparity")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_parity")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_palette")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_mwst")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_metlstf")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_merkmal")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_ltst")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_ltgr")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_ltgart")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_lohnart")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_lizenz")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_ligen")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_land")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_lagertyp")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_lagerplz")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_lagerfrm")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_lager")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_kzusch")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_ksttr")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_kstst")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_kstart")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_kschema")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_konto")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_konto2")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_konten")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_kond_wertk")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_kombi")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_kgr")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_kdst")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_kdrw")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_kdra")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_kdarvk")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_indkst")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_hpreise")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_spguvpos")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_guvpos")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_gart")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_firma")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_feiertag3")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_feiertag")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_fcmatrix")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_farbe")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_ekpr")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_ekpr3")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_speinhei")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_einheit")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_eig_prg2")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_eig_prg")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_edioption")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_ean")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_drucker")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_datev_sort")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_contyp")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_buchkz")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_bran")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_spbilpos")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_bilpos")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_bdland")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_bank")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_ban2")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_spatext")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_atext")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_arvk")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_sparko")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_arkd")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_arko")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_arkd")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_arliek2")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_arliek")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_arli")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_arko_zl")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_arkolplz")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_arkobez")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_anwend")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_option")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_adrgr")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_adress")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_anspwgr")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_vtst")
    {
        logicalIndex = index + 1;
    }
/* 
    if(form == "a_partie2")
    {
        logicalIndex = index + 1;
    }
*/
    if(form == "a_eposhi")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_eliefer")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_ekvorgng")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_ekposhi")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_epos")
    {
        logicalIndex = index + 1;
    }
/*
    if(form == "a_ekopf")
    {
        logicalIndex = index + 1;
    }
*/
    if(form == "a_ekpos")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_ekontr")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_eapos")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_eakopf")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_dampfer")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_cont")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_bl")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_bestvo")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_bestand")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_banf0")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_zuekvk")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_vposoffn")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_vliefer")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_vkwertk")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_vkvorg")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_vkstdzet")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_veinswb")
    {
        logicalIndex = index + 1;
    }

    if(form == "a_veinssp")
    {
        logicalIndex = index + 1;
    }

    if(form == "m_vapos")
    {
        logicalIndex = index + 1;
    }
/*
    if(form == "a_vakopf")
    {
        logicalIndex = index + 1;
    }
    if(form == "a_vkontr")
    {
        logicalIndex = index + 1;
    }
*/

    if(form == "a_vkpos")
    {
        logicalIndex = index + 1;
    }

    if(form == "m2infdk")
    {
        logicalIndex = index + 1;
    }

    if(logicalIndex == -1)
    {
        logicalIndex = index;
    }

    return QString::number(logicalIndex);
}
void ProtocolHandler::executeFile(int waitforFinish, QString fileName)
{

    QString fileLockName = QString(".~lock.%1#").arg(fileName);
    fileName = QDir::tempPath() + "/" + fileName;
    QFileInfo fileNameInfo(fileName);
    qDebug() << "LockFile: " << fileLockName;
    qDebug() << "fileName: " << fileNameInfo.absoluteFilePath();
    qDebug() << "waitForFinish: " << QString::number(waitforFinish);
#ifdef Q_OS_LINUX
   if(QDesktopServices::openUrl(QUrl(QString("file://" + fileNameInfo.absoluteFilePath()), QUrl::TolerantMode)))
   {
       int cnt = 0;
       if(waitforFinish == 1)
       {
           sleep(1);
           for(int i=0; i < 10000000; i++)
           {
               QFile file(QDir::tempPath() + "/" + fileLockName);
               if(!file.exists())
               {
                   if(cnt == 1)
                   {
                       openFileSuccess = 1;
                       break;
                   }
               } else {
                   cnt = 1;
               }
               sleep(2);
           }
       } else {
           openFileSuccess = 1;
       }
   }
   #endif
   #ifdef Q_OS_MAC
      if(QDesktopServices::openUrl(QUrl(QString("file:///" + fileNameInfo.absoluteFilePath()), QUrl::TolerantMode)))
      {
          if(waitforFinish == 1)
          {
              sleep(3);
              for(int i=0; i < 10000; i++)
              {
                  QFile file(QDir::tempPath() + "/" + fileLockName);
                  if(!file.exists())
                  {
                      openFileSuccess = 1;
                      break;
                  }
                  sleep(2);
              }
          } else {
              openFileSuccess = 1;
          }
      }
   #endif
   #ifdef Q_OS_WIN
      if (waitforFinish == 1)
      {
         STARTUPINFO si;
         PROCESS_INFORMATION pi;
         LPWSTR szCommandLine;
         QString defaultProg = "";
         QString regValue = "";
         openFileSuccess = 1;

         ZeroMemory( &si, sizeof(si));
         si.cb = sizeof(si);
         ZeroMemory( &pi, sizeof(pi));

         QSettings *settings = new QSettings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FileExts\\." + fileNameInfo.completeSuffix() + "\\UserChoice", QSettings::NativeFormat);
         regValue = settings->value("Progid").toString();

         if(regValue.isEmpty())
         {
             qDebug() << "regValue is empty";
             settings = new QSettings("HKEY_CLASSES_ROOT\\." + fileNameInfo.completeSuffix(), QSettings::NativeFormat);
             qDebug() << "HKEY_CLASSES_ROOT\\" + fileNameInfo.completeSuffix();
             regValue = settings->value(".").toString();
         }

         settings = new QSettings("HKEY_CLASSES_ROOT\\" + regValue + "\\Shell\\open\\command", QSettings::NativeFormat);
         defaultProg = settings->value(".").toString();

         if(defaultProg.contains("/n"))
         {
             defaultProg.replace("/n", "/w /n");
         }

         if(defaultProg.contains("%1"))
         {
             defaultProg.replace("%1", QDir::toNativeSeparators(fileNameInfo.absoluteFilePath()));
         }
         else
         {
             defaultProg.append(" \"" + QDir::toNativeSeparators(fileNameInfo.absoluteFilePath()) + "\"");
         }
      
         if(defaultProg.contains("%ProgramFiles%"))
         {
            defaultProg.replace("%ProgramFiles%", getenv("ProgramFiles"));
         }

         if(defaultProg.contains("%SystemRoot%"))
         {
             defaultProg.replace("%SystemRoot%", getenv("SystemRoot"));
         }

         qDebug() << "Open File with Program: " << defaultProg;

         szCommandLine = (LPWSTR)defaultProg.data();

         if(sizeof(szCommandLine) > 0)
         {
             if(!CreateProcess( NULL,
                                szCommandLine,
                                NULL,
                                NULL,
                                FALSE,
                                NORMAL_PRIORITY_CLASS,
                                NULL,
                                NULL,
                                &si,
                                &pi ))
             {
                 QMetaObject::invokeMethod(p_currScreenHandler, "MsgBox", Qt::QueuedConnection, Q_ARG(QString, "ERROR"), Q_ARG(QString, "Could not find a default program for this file."), Q_ARG(QString, "Critical"), Q_ARG(QString, "Ok"), Q_ARG(QString, "Ok"), Q_ARG(int, 0));
                 qDebug() << "FEHLER BEI PROZESS ERSTELLEN!!!!";
                 openFileSuccess = 0;
                 return;

             }
                qDebug() << "Prozess wurde erstellt.";
                WaitForSingleObject( pi.hProcess, INFINITE);

                CloseHandle(pi.hProcess);
                CloseHandle(pi.hThread);
                delete settings;
        }
    } else if(waitforFinish == 0)
    {
       qDebug() << "Starte Prozess ohne warten.";
       QProcess::startDetached(QString("rundll32 url.dll,FileProtocolHandler \"%1\"").arg( fileNameInfo.absoluteFilePath()));
    }

      /* QProcess::startDetached(QString("rundll32 url.dll,FileProtocolHandler \"%1\"").arg( fileNameInfo.absoluteFilePath()));
       if(waitforFinish == 1)
       {
           sleep(10);
           for(int i=0; i < 10000; i++)
           {
               QFile file(fileNameInfo.absoluteFilePath());

               if(file.open(QIODevice::ReadWrite))
               {
                   openFileSuccess = 1;
                   break;
               }
               sleep(2);
           }
       } else {
           openFileSuccess = 1;
       }*/
#endif
}

//------------------------------------------------------------------------------
// Method       : encodeXMLFile(QString)
// Filename     : tcpclient.cpp
// Description  : encodes the decoded XMLFile back to XML
//------------------------------------------------------------------------------
QString ProtocolHandler::encodeXMLFile(QString xmlString)
{
MainFrame::vdcdebug("ProtocolHandler","encodeXMLFile", "QString xmlString");
   QString textBuffer;
   QByteArray ba;
   ba.append(xmlString);
   QByteArray ba2 = QByteArray::fromBase64(ba);
   xmlString = ba2.data();

   for(int i=0; i<xmlString.size(); i++)
   {
      if(xmlString.at(i) != QChar('\n')){
         textBuffer.append(xmlString.at(i));
      }
   }

   xmlString = textBuffer;

   // QT4 doesnt like the encoding so dont tell it what encoding it is
   if(xmlString.indexOf("?xml") >= 0){
      xmlString.remove(0,1);
      for(int i=0; i<xmlString.size(); i++){
         if(xmlString.at(i) != QChar('<')){
            xmlString.remove(i,1);
            i--;
         }
         else{
            break;
         }
      }
   }

   //delete &textBuffer;

   /*
   xmlString.replace("&lt;","<");
   xmlString.replace("&gt;",">");
   xmlString.replace("&quot;","\"");
   xmlString.replace("&quot;","\"");
   xmlString.replace("&#10;"," ");
   */

   return xmlString;

   //We dont need the XML convertion ... its slows the vdc much!

/*
   QString errorMsg;
   int errorLine = 0;
   int errorColumn;
   
   QDomDocument xmlDoc;
   xmlDoc.setContent(xmlString, false, &errorMsg, &errorLine, &errorColumn);

   if(errorLine == 0){
   }
   else{
      qDebug() << errorMsg << "\n"
               << "Line:" << errorLine << "\n"
               << "Col:" << errorColumn << "\n"
               << xmlString;
   }
   
   return xmlDoc;*/
}

//------------------------------------------------------------------------------
// Method       : handleStartup()
// Filename     : tcpclient.cpp
// Description  : handles the Environment Variables
//------------------------------------------------------------------------------
void ProtocolHandler::handleStartup(const QDomNode& domNode)
{
MainFrame::vdcdebug("ProtocolHandler","handleStartup", "const QDomNode& domNode");
   QDomElement startupElement = domNode.toElement();

   QDomElement currentElement = domNode.firstChild().toElement();

   while(!currentElement.isNull()){
      QString nodeName = currentElement.nodeName();

      if(nodeName == "ENV"){
         QString name = currentElement.attribute("NAME");
         QString value = currentElement.attribute("VALUE");

         p_currScreenHandler->qh_env[name] = value;
         QMetaObject::invokeMethod(p_currScreenHandler, "setEnv", Qt::QueuedConnection, Q_ARG(QString, name), Q_ARG(QString, value));
         //p_currScreenHandler->setEnv(name, value);

         if(name == "DB_LOCALE")
         {
             this->qs_dblocale = value;
         }
         /*
         if(name == "DBPATH"){
            //p_currScreenHandler->setSearchPaths();
            ScreenHandler::setSearchPaths();
         }
         */
      }

      currentElement = currentElement.nextSiblingElement();
   }
   // ALWAYS set search Paths
   //p_currScreenHandler->setSearchPaths();
   ScreenHandler::setSearchPaths();
}

void ProtocolHandler::handleDisplayAtElement(const QDomNode& domNode)
{
    QDomElement displayAtElement = domNode.toElement();

    int row  = displayAtElement.attribute("Y").toInt();
    int column  = displayAtElement.attribute("X").toInt()-1;
    bool clearLine  = displayAtElement.attribute("CLRLINE").toInt();
    QString displayText = displayAtElement.text();

    QMetaObject::invokeMethod(p_currScreenHandler, "displayAt", Qt::QueuedConnection, Q_ARG(int, row), Q_ARG(int, column), Q_ARG(bool, clearLine), Q_ARG(QString, displayText));
}

//------------------------------------------------------------------------------
// Method       : handleDisplayToElements()
// Filename     : tcpclient.cpp
// Description  : handles the DISPLAYTO command and tells the screenhandler to 
//                set the FieldBuffer 
//------------------------------------------------------------------------------
void ProtocolHandler::handleDisplayToElement(const QDomNode& domNode, QString parentNodeName)
{
MainFrame::vdcdebug("ProtocolHandler","handleDisplayToElement", "const QDomNode& domNode, QString parentNodeName");
   //maybe we need this in the future
   Q_UNUSED(parentNodeName);


   QDomElement displayToElement = domNode.toElement();

   int attribute = -1;


   if(displayToElement.nodeName() == "DISPLAYTO"){
      attribute = displayToElement.attribute("ATTRIBUTE").toInt();
   }


 
   QDomElement currentElement = domNode.firstChild().toElement();

   QStringList qsl_fieldNames;
   QStringList qsl_fieldValues;

   while(!currentElement.isNull()){
      QString nodeName = currentElement.nodeName();

      if(nodeName == "FIELDLIST"){
         QDomNodeList children = currentElement.childNodes();
         for(int i=0; i<children.count(); ++i){
            QDomNode child = children.at(i);
            if(!child.isElement()){
               continue;
            }

            QDomElement fieldElement = child.toElement();

            if(fieldElement.nodeName() == "FIELD"){
               qsl_fieldNames << fieldElement.attribute("NAME");
            }
         }
      }

      if(nodeName == "VS"){
         QDomNodeList children = currentElement.childNodes();
         for(int i=0; i<children.count(); ++i){
            QDomNode child = children.at(i);
            if(!child.isElement()){
               continue;
            }

            QDomElement textElement = child.toElement();

            //DISPLAYTO
            if(textElement.nodeName() == "TEXT"){
               QString qs_type = textElement.attribute("TYPE");
               /*
               QString qs_text = textElement.text();
               # .trimmed() is needed to display the images correct with DISPLAY TO in the window
               */
               QString qs_text = textElement.text().trimmed();
               if(qs_type == "BLOB"){
                   QByteArray ba;
                   ba.append(textElement.text());
                   QByteArray ba2 = QByteArray::fromBase64(ba);
                   qs_text = QString(ba2);
               }


               qsl_fieldValues << qs_text;

            }

            //WAITFOREVENT
            if(textElement.nodeName() == "V"){
               qsl_fieldValues << textElement.text();

            }
         }
      }

      currentElement = currentElement.nextSiblingElement();
   }

   if(qsl_fieldNames.count() > 0){
       QMetaObject::invokeMethod(p_currScreenHandler, "setFieldBuffer", Qt::QueuedConnection, Q_ARG(QStringList, qsl_fieldNames), Q_ARG(QStringList, qsl_fieldValues), Q_ARG(int, attribute));
    //  setFieldBuffer(qsl_fieldNames, qsl_fieldValues, attribute);
   }
   else{
      for(int i=0; i<qsl_fieldValues.count(); i++){
         QMetaObject::invokeMethod(p_currScreenHandler, "setFieldBuffer", Qt::QueuedConnection, Q_ARG(int, i), Q_ARG(QString, qsl_fieldValues.at(i)), Q_ARG(int, attribute));
         //setFieldBuffer(i,qsl_fieldValues.at(i), attribute);
      }
   }
}

void ProtocolHandler::clearDisplayArray(const QDomNode &domNode, QString parentNodeName)
{
    Q_UNUSED(parentNodeName);
    QDomElement currentElement = domNode.firstChild().toElement();

    QStringList qsl_fieldNames;

    while(!currentElement.isNull()){
       QString nodeName = currentElement.nodeName();

       if(nodeName == "FIELDLIST"){
          QDomNodeList children = currentElement.childNodes();
          for(int i=0; i<children.count(); ++i){
             QDomNode child = children.at(i);
             if(!child.isElement()){
                continue;
             }

             QDomElement fieldElement = child.toElement();

             if(fieldElement.nodeName() == "FIELD"){
                qsl_fieldNames << fieldElement.attribute("NAME");
             }
          }
       }
       currentElement = currentElement.nextSiblingElement();

       //emit clearDisplayArrayRows(qsl_fieldNames);
    }
    QMetaObject::invokeMethod(p_currScreenHandler, "clearDisplayArrayRows", Qt::QueuedConnection, Q_ARG(QStringList, qsl_fieldNames));
    //emit clearDisplayArrayRows(qsl_fieldNames);
}

//------------------------------------------------------------------------------
// Method       : handleDisplayArrayElement()
// Filename     : tcpclient.cpp
// Description  : handles the DISPLAYARRAY command and tells the screenhandler to 
//                set the FieldBuffer 
//------------------------------------------------------------------------------
void ProtocolHandler::handleDisplayArrayElement(const QDomNode& domNode, QString parentNodeName)
{
MainFrame::vdcdebug("ProtocolHandler","handleDisplayArrayElement", "const QDomNode& domNode, QString parentNodeName");

   Q_UNUSED(parentNodeName);

   QDomElement arrayElement = domNode.toElement();

   bool input = false;
   int arrCount = arrayElement.attribute("ARRCOUNT").toInt();
   int arrVariables = arrayElement.attribute("ARRVARIABLES").toInt();
   int maxArrSize = arrayElement.attribute("MAXARRSIZE").toInt();
   bool withoutDefaults = arrayElement.attribute("WITHOUT_DEFAULTS").toInt();
   bool allowInsert = arrayElement.attribute("ALLOWINSERT").toInt();
   bool allowDelete = arrayElement.attribute("ALLOWDELETE").toInt();
   bool noNewLines = arrayElement.attribute("NONEWLINES").toInt();
   bool wrap = arrayElement.attribute("WRAP").toInt();

   if(arrayElement.nodeName() == "DISPLAYARRAY" ||
      arrayElement.nodeName() == "INPUTARRAY"){

      //int context = arrayElement.attribute("CONTEXT").toInt();
      //setFormOpts(arrayElement.nodeName(), true, context);

      if(arrayElement.nodeName() == "INPUTARRAY"){
         input = true;
      }

      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, arrayElement.nodeName()), Q_ARG(QString, QString("ARRCOUNT")), Q_ARG(int, arrCount));
      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, arrayElement.nodeName()), Q_ARG(QString, QString("ARRVARIABLES")), Q_ARG(int, arrVariables));
      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, arrayElement.nodeName()), Q_ARG(QString, QString("MAXARRSIZE")), Q_ARG(int, maxArrSize));
      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, arrayElement.nodeName()), Q_ARG(QString, QString("WITHOUT_DEFAULTS")), Q_ARG(int, withoutDefaults));
      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, arrayElement.nodeName()), Q_ARG(QString, QString("ALLOWINSERT")), Q_ARG(int, allowInsert));
      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, arrayElement.nodeName()), Q_ARG(QString, QString("ALLOWDELETE")), Q_ARG(int, allowDelete));
      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, arrayElement.nodeName()), Q_ARG(QString, QString("NONEWLINES")), Q_ARG(int, noNewLines));
      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, arrayElement.nodeName()), Q_ARG(QString, QString("WRAP")), Q_ARG(int, wrap));

     /*

      setFormOpts(arrayElement.nodeName(), QString("ARRCOUNT"), arrCount);
      setFormOpts(arrayElement.nodeName(), QString("ARRVARIABLES"), arrVariables);
      setFormOpts(arrayElement.nodeName(), QString("MAXARRSIZE"), maxArrSize);
      setFormOpts(arrayElement.nodeName(), QString("WITHOUT_DEFAULTS"), withoutDefaults);
      setFormOpts(arrayElement.nodeName(), QString("ALLOWINSERT"), allowInsert);
      setFormOpts(arrayElement.nodeName(), QString("ALLOWDELETE"), allowDelete);
      setFormOpts(arrayElement.nodeName(), QString("NONEWLINES"), noNewLines);
      setFormOpts(arrayElement.nodeName(), QString("WRAP"), wrap);
*/
      QMetaObject::invokeMethod(p_currScreenHandler, "createActionMenu", Qt::QueuedConnection);
     // createActionMenu();
/*
      createActionMenuButton("ACCEPT", "ACCEPT", "");
      createActionMenuButton("CANCEL", "CANCEL", "");
*/


   }
 
   QDomElement currentElement = domNode.firstChild().toElement();

   QString screenRecordName;

   while(!currentElement.isNull()){
      QString nodeName = currentElement.nodeName();

      if(nodeName == "FIELDLIST"){
         QDomNodeList children = currentElement.childNodes();
         for(int i=0; i<children.count(); ++i){
            QDomNode child = children.at(i);
            if(!child.isElement()){
               continue;
            }

            QDomElement fieldElement = child.toElement();

            if(fieldElement.nodeName() == "FIELD"){
               screenRecordName = fieldElement.attribute("NAME");

               if(arrayElement.nodeName() == "DISPLAYARRAY" ||
                  arrayElement.nodeName() == "INPUTARRAY"){
                  QMetaObject::invokeMethod(p_currScreenHandler, "setScreenRecordEnabled", Qt::QueuedConnection, Q_ARG(QString, screenRecordName), Q_ARG(bool, true), Q_ARG(bool, input));
                  //setScreenRecordEnabled(screenRecordName, true, input);
               }
            }
         }
      }

      if(nodeName == "ROWS"){
         QDomNodeList children = currentElement.childNodes();
         for(int i=0; i<children.count(); ++i){
            QDomNode child = children.at(i);
            if(!child.isElement()){
               continue;
            }

            QDomElement rowElement = child.toElement();

            if(rowElement.nodeName() == "ROW"){
               //We begin with 0 in the vdc
               int row = rowElement.attribute("SUBSCRIPT").toInt()-1;
               QStringList qsl_arrayValues;

               QDomElement valuesElement = rowElement.firstChildElement();
               QDomNodeList children = valuesElement.childNodes();
               for(int i=0; i<children.count(); ++i){
                  QDomNode child = children.at(i);
                  if(!child.isElement()){
                     continue;
                  }

                  QDomElement valueElement = child.toElement();

                  if(valueElement.nodeName() == "V"){
                     qsl_arrayValues << valueElement.text();
                  }
               }

               if(screenRecordName.count() > 0){
                  QMetaObject::invokeMethod(p_currScreenHandler, "setArrayBuffer", Qt::QueuedConnection, Q_ARG(int, row), Q_ARG(QString, screenRecordName), Q_ARG(QStringList, qsl_arrayValues));
           //       setArrayBuffer(row, screenRecordName, qsl_arrayValues);
               }
               else{
                  QMetaObject::invokeMethod(p_currScreenHandler, "setArrayBuffer", Qt::QueuedConnection, Q_ARG(int, row), Q_ARG(QStringList, qsl_arrayValues));
               //   setArrayBuffer(row, qsl_arrayValues);
               }
            }
         }
      }

      currentElement = currentElement.nextSiblingElement();
   }

   if(arrayElement.nodeName() == "DISPLAYARRAY" ||
      arrayElement.nodeName() == "INPUTARRAY"){



   }



}

//------------------------------------------------------------------------------
// Method       : handleInputElement()
// Filename     : tcpclient.cpp
// Description  : handles the INPUT command and activates the Fields
//------------------------------------------------------------------------------
void ProtocolHandler::handleInputElement(const QDomNode& domNode, int attribute)
{
MainFrame::vdcdebug("ProtocolHandler","handleInputElement", "const QDomNode& domNode, int attribute");
   QDomElement currentElement = domNode.toElement();
   QString nodeName = currentElement.nodeName();
   if(nodeName == "INPUT"){
      int withoutDefaults = currentElement.attribute("WITHOUT_DEFAULTS").toInt();
      int wrap = currentElement.attribute("WRAP").toInt();
      attribute = currentElement.attribute("ATTRIBUTE").toInt();
      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, nodeName), Q_ARG(QString, QString("WITHOUT_DEFAULTS")), Q_ARG(int, withoutDefaults));
      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, nodeName), Q_ARG(QString, QString("WRAP")), Q_ARG(int, wrap));
      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, nodeName), Q_ARG(QString, QString("ATTRIBUTE")), Q_ARG(int, attribute));

      //setFormOpts(nodeName, QString("WITHOUT_DEFAULTS"), withoutDefaults);
      //setFormOpts(nodeName, QString("WRAP"), wrap);
      //setFormOpts(nodeName, QString("ATTRIBUTE"), attribute);
      QMetaObject::invokeMethod(p_currScreenHandler, "createActionMenu", Qt::QueuedConnection);
//      createActionMenu();
/*
      createActionMenuButton("ACCEPT", "ACCEPT", "");
      createActionMenuButton("CANCEL", "CANCEL", "");
*/
   }

   QDomNodeList children = domNode.childNodes();
   for(int i=0; i<children.count(); ++i){

      QDomNode child = children.at(i);
      if(!child.isElement()){
         continue;
      }

      currentElement = child.toElement();

      nodeName = currentElement.nodeName();

      if(nodeName == "FIELDLIST"){
         qsl_fieldList.clear();
      }

      if(nodeName == "FIELD"){
         QString field = currentElement.attribute("NAME");
         qsl_fieldList << field;
         QMetaObject::invokeMethod(p_currScreenHandler, "setFieldEnabled", Qt::QueuedConnection, Q_ARG(QString, field), Q_ARG(bool, true), Q_ARG(bool, false), Q_ARG(int, attribute));
         //setFieldEnabled(field, true, false, attribute);
      }

      handleInputElement(currentElement, attribute);
   }
}

//------------------------------------------------------------------------------
// Method       : handleConstructElement()
// Filename     : tcpclient.cpp
// Description  : handles the CONSTRUCT command and activates the Fields
//------------------------------------------------------------------------------
void ProtocolHandler::handleConstructElement(const QDomNode& domNode)
{
MainFrame::vdcdebug("ProtocolHandler","handleConstructElement", "const QDomNode& domNode");
   QDomElement currentElement = domNode.toElement();
   QString nodeName = currentElement.nodeName();
   int attribute = 0;
   if(nodeName == "CONSTRUCT"){
      int wrap = currentElement.attribute("WRAP").toInt();
      attribute = currentElement.attribute("ATTRIBUTE").toInt();
      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, nodeName), Q_ARG(QString, QString("WRAP")), Q_ARG(int, wrap));
      QMetaObject::invokeMethod(p_currScreenHandler, "setFormOpts", Qt::QueuedConnection, Q_ARG(QString, nodeName), Q_ARG(QString, QString("ATTRIBUTE")), Q_ARG(int, attribute));
     // setFormOpts(nodeName, QString("WRAP"), wrap);
     // setFormOpts(nodeName, QString("ATTRIBUTE"), attribute);
   }

   QDomNodeList children = domNode.childNodes();
   for(int i=0; i<children.count(); ++i){

      QDomNode child = children.at(i);
      if(!child.isElement()){
         continue;
      }

      currentElement = child.toElement();

      nodeName = currentElement.nodeName();

      if(nodeName == "FIELDLIST"){
         qsl_fieldList.clear();
      }

      if(nodeName == "FIELD"){
         // Set focus for the first field in the list
         bool focus = false;
         if(i == 0)
            focus = true;

         QString field = currentElement.attribute("NAME");
         qsl_fieldList << field;
         QMetaObject::invokeMethod(p_currScreenHandler, "setFieldEnabled", Qt::QueuedConnection, Q_ARG(QString, field), Q_ARG(bool, true), Q_ARG(bool, focus), Q_ARG(int, attribute));
      //   setFieldEnabled(field, true, focus, attribute);
      }

      /*
      if(nodeName == "COLUMNS"){
         qsl_fieldList.clear();
      }

      if(nodeName == "COLUMN"){
         // Set focus for the first field in the list
         bool focus = false;
         if(i == 0)
            focus = true;

         QString field = currentElement.attribute("NAME");
         qsl_fieldList << field;
         setFieldEnabled(field, true, focus);
      }
      */

      handleConstructElement(currentElement);
   }
}

//------------------------------------------------------------------------------
// Method       : handleMenuElement()
// Filename     : tcpclient.cpp
// Description  : handles the MENU command and tells the screenhandler to
//                create the Menu
//------------------------------------------------------------------------------
void ProtocolHandler::handleMenuElement(const QDomNode& domNode)
{
MainFrame::vdcdebug("ProtocolHandler","handleMenuElement", "const QDomNode& domNode");

   QDomElement currentElement = domNode.toElement();
   QString nodeName = currentElement.nodeName();
   
   // The MenuGroup wich holds all Buttons
   if(nodeName == "MENU"){
      // Not used
      QString context = currentElement.attribute("CONTEXT");
     
      // Headline for the Menu
      QString title   = currentElement.attribute("TITLE");

      QString comment = currentElement.attribute("COMMENT");

      // Style name (from *.4st)
      QString style   = currentElement.attribute("STYLE");

      // Image to Show (only used for Dialogs ( MENU inside INPUT etc) )
      QString image   = currentElement.attribute("IMAGE");
      QMetaObject::invokeMethod(p_currScreenHandler, "createMenu", Qt::QueuedConnection, Q_ARG(QString, title.trimmed()), Q_ARG(QString, comment), Q_ARG(QString, style), Q_ARG(QString, image));
      //createMenu(title, comment, style, image);
   }

   QDomNodeList children = domNode.childNodes();
   for(int i=0; i<children.count(); ++i){

      QDomNode child = children.at(i);
      if(!child.isElement()){
         continue;
      }

      currentElement = child.toElement();

      nodeName = currentElement.nodeName();

      // The MenuButton
      if(nodeName == "MENUCOMMAND"){
         // Not used
         QString context = currentElement.attribute("CONTEXT");

         QStringList keys = currentElement.attribute("KEYS").split(",", QString::SkipEmptyParts);

         // Button ID
         int id = currentElement.attribute("ID").toInt();

         //Buttons Text
         QString text = currentElement.attribute("TEXT");

         // Buttons description (ToolTip)
         QString desc = currentElement.attribute("DESCRIPTION");

         // HelpNumer of HelpMenu - not used
         //int helpno = currentElement.attribute("HELPNO").toInt();

         // TODO: Implement KEYS (text is NULL)
         if(!text.isEmpty()){
            QMetaObject::invokeMethod(p_currScreenHandler, "createMenuButton", Qt::QueuedConnection, Q_ARG(int, id), Q_ARG(QString, text), Q_ARG(QString, desc), Q_ARG(QStringList, keys));
            QMetaObject::invokeMethod(p_currScreenHandler, "setIconForCommand", Qt::QueuedConnection, Q_ARG(QString, text));
         }
      }

      //TODO: Implement MenuAction
      if(nodeName == "MENUACTION"){
         // Not used
         QString context = currentElement.attribute("CONTEXT");

         // Button ID
         int id = currentElement.attribute("ID").toInt();

         //Buttons Text
         QString text = currentElement.attribute("ACTION");

         // TODO: Implement KEYS (text is NULL)
         if(!text.isEmpty()){
            QMetaObject::invokeMethod(p_currScreenHandler, "createMenuAction", Qt::QueuedConnection, Q_ARG(int, id), Q_ARG(QString, text));
           // createMenuAction(id, text);
         }
      }

      handleMenuElement(currentElement);
   }
}

//------------------------------------------------------------------------------
// Method       : handleEventsElement()
// Filename     : tcpclient.cpp
// Description  : handles the EVENTS command 
//------------------------------------------------------------------------------
void ProtocolHandler::handleEventsElement(const QDomNode& domNode)
{
MainFrame::vdcdebug("ProtocolHandler","handleEventsElement", "const QDomNode& domNode");
   QDomElement currentElement = domNode.toElement();
   QString nodeName = currentElement.nodeName();
   
   QDomNodeList children = domNode.childNodes();
   for(int i=0; i<children.count(); ++i){

      QDomNode child = children.at(i);
      if(!child.isElement()){
         continue;
      }

      currentElement = child.toElement();

      nodeName = currentElement.nodeName();

      if(nodeName == "BEFORE_INPUT_EVENT" ||
         nodeName == "BEFORE_CONSTRUCT_EVENT" ||
         nodeName == "BEFORE_DISPLAY_EVENT" ||
         nodeName == "BEFORE_INSERT_EVENT" ||
         nodeName == "BEFORE_DELETE_EVENT"){
         QString id = currentElement.attribute("ID");
         QMetaObject::invokeMethod(p_currScreenHandler, "setEvent", Qt::QueuedConnection, Q_ARG(QString, nodeName), Q_ARG(QString, ""), Q_ARG(QString, id));
 //        setEvent(nodeName, QString(), id);
      }

      if(nodeName == "AFTER_INPUT_EVENT" ||
         nodeName == "AFTER_CONSTRUCT_EVENT" ||
         nodeName == "AFTER_DISPLAY_EVENT" ||
         nodeName == "AFTER_INSERT_EVENT" ||
         nodeName == "AFTER_DELETE_EVENT"){
         QString id = currentElement.attribute("ID");
         QMetaObject::invokeMethod(p_currScreenHandler, "setEvent", Qt::QueuedConnection, Q_ARG(QString, nodeName), Q_ARG(QString, ""), Q_ARG(QString, id));
         //setEvent(nodeName, QString(), id);
      }

      if(nodeName == "BEFORE_FIELD_EVENT" || 
         nodeName == "AFTER_FIELD_EVENT"){
         QString field = currentElement.attribute("FIELD");
         QString id = currentElement.attribute("ID");
         QMetaObject::invokeMethod(p_currScreenHandler, "setEvent", Qt::QueuedConnection, Q_ARG(QString, nodeName), Q_ARG(QString, field), Q_ARG(QString, id));
      //   setEvent(nodeName, field, id);
      }

      if(nodeName == "BEFORE_ROW_EVENT" || 
         nodeName == "AFTER_ROW_EVENT"){
         QString id = currentElement.attribute("ID");
         QMetaObject::invokeMethod(p_currScreenHandler, "setEvent", Qt::QueuedConnection, Q_ARG(QString, nodeName), Q_ARG(QString, ""), Q_ARG(QString, id));
         //setEvent(nodeName, QString(), id);
      }

      if(nodeName == "ONKEY_EVENT"){
         QString id  = currentElement.attribute("ID");
         int key = currentElement.attribute("KEY").toInt();
         QMetaObject::invokeMethod(p_currScreenHandler, "setEvent", Qt::QueuedConnection, Q_ARG(QString, nodeName), Q_ARG(QString, QString::number(key)), Q_ARG(QString, id));
         //setEvent(nodeName, QString::number(key), id);
      }

      if(nodeName == "ON_ACTION_EVENT"){
         QString id  = currentElement.attribute("ID");
         QString key = currentElement.attribute("ACTION");
         QMetaObject::invokeMethod(p_currScreenHandler, "setEvent", Qt::QueuedConnection, Q_ARG(QString, nodeName), Q_ARG(QString, key), Q_ARG(QString, id));
      //   setEvent(nodeName, key, id);
      }

      if(nodeName == "EVENTS"){
         handleEventsElement(currentElement);
      }
   }
}

void ProtocolHandler::handleWaitForEventElement(const QDomNode& domNode)
{
MainFrame::vdcdebug("ProtocolHandler","handleWaitForEventElement", "const QDomNode& domNode");
   QDomElement currentElement = domNode.toElement();
   QString nodeName = currentElement.nodeName();

   if(currentElement.attribute("ERR").size() > 0)
   {
      qFatal("Bad Id in Triggered");
   }

   if(currentElement.attribute("CACHED").toInt() != 0)
       return;

   //Not needed atm
   int changed = -1;
   if(nodeName == "WAITFOREVENT"){
      changed = currentElement.attribute("CHANGED").toInt();
      
   }
   //Catch ID Errors from a4gl and qFatal
   // currently not used
   if(currentElement.firstChildElement().nodeName() == "ROWS"){
      handleDisplayArrayElement(currentElement);
   }


   if(currentElement.firstChildElement().nodeName() == "VS"){
      if(changed > 0){
         handleDisplayToElement(currentElement, currentElement.nodeName());
      }
   }

   QMetaObject::invokeMethod(p_currScreenHandler, "waitForEvent", Qt::QueuedConnection);

   return;
}


//------------------------------------------------------------------------------
// Method       : fglFormResponse()
// Filename     : tcpclient.cpp
// Description  : destructor for the thread object
//------------------------------------------------------------------------------
void ProtocolHandler::fglFormResponse(QString qs_id)
{
MainFrame::vdcdebug("ProtocolHandler","fglFormResponse", "QString qs_id");
//   QDomDocument doc;
//   doc.setContent(qs_id);
 //  QDomElement triggeredElement = doc.documentElement();
 //  triggeredElement.setAttribute("ENVELOPEID", pid);
 //  qs_id = doc.toString();
   qs_id = qs_id.replace("&amp;#x0A;", "&#x0A;");
 //  qs_id.replace("\n","");
   if(this->t_tunnel)
   {
       QMetaObject::invokeMethod(t_tunnel, "sendData", Qt::DirectConnection, Q_ARG(QString, qs_id));
   }
   else
   {
       makeResponse(qs_id);
   }
   //qDebug()<<qs_id;
   QMetaObject::invokeMethod(MainFrame::lastmainframe, "debugText", Q_ARG(QString, ">> " + qs_id));
   //emit debugtext(QString(">> " + qs_id));
}

void ProtocolHandler::closeAllScreenHandler()
{

  foreach(p_currScreenHandler, qh_screenhandler)
  {
      /*
      if(p_currScreenHandler->p_prompt != NULL){
         p_currScreenHandler->p_prompt->setVisible(false);
         p_currScreenHandler->p_prompt->close();
         p_currScreenHandler->p_prompt->deleteLater();
      }

      QList<FglForm*> ql_forms = p_currScreenHandler->ql_fglForms;
      for(int i=0; i<ql_forms.size(); i++){
         p_currScreenHandler->closeWindow(ql_forms.at(i)->windowName);
      }

     delete p_currScreenHandler;*/

      int pid = p_currScreenHandler->pid;
      int p_pid = p_currScreenHandler->p_pid;
      if(t_tunnel)
          QMetaObject::invokeMethod(MainFrame::lastmainframe, "deleteScreenHandler", Qt::QueuedConnection, Q_ARG(int, pid), Q_ARG(int, p_pid));
          else
      QMetaObject::invokeMethod(MainFrame::lastmainframe, "deleteScreenHandler", Qt::DirectConnection, Q_ARG(int, pid), Q_ARG(int, p_pid));

  }

}

//------------------------------------------------------------------------------
// Method       : ~ProtocolHandler()
// Filename     : tcpclient.cpp
// Description  : destructor for the thread object
//------------------------------------------------------------------------------
ProtocolHandler::~ProtocolHandler()
{
MainFrame::vdcdebug("ProtocolHandler","~ProtocolHandler", "");

}

ProtocolHandler::ProtocolHandler(QObject *parent) : QThread(parent)
{
MainFrame::vdcdebug("ProtocolHandler","ProtocolHandler", "QObject *parent");

   b_read = false;
   b_write = false;
}

bool ProtocolHandler::sendFile(QString name)
{
MainFrame::vdcdebug("ProtocolHandler","sendFile", "QString name");
   QByteArray data;

   if(name.isNull()) {
      return false;
   }

   QFile file;
   file.setFileName(name);

   if(!QFile::exists(name)) {
       file.setFileName(QString(QDir::tempPath() + "/" + name));
   }

   if(name == "settings.ini")
   {
        QString filePath = VDC::getPathToSettingsIni() + "settings.ini";
        file.setFileName(filePath);
   }

   if(!file.open(QIODevice::ReadOnly | QIODevice::Unbuffered)){
      QFileInfo inf(name);
      file.setFileName(QDir::tempPath() + "/" + inf.fileName());
      if(!file.open(QIODevice::ReadOnly | QIODevice::Unbuffered)){
          data = 0;
      }
   }

   while(!file.atEnd()){
      data = file.readAll();
   }

   data = data.toBase64();

   //Split the string if bytes are greater then 100000.
   while(data.count() >= 100000)
   {
       QString sendText = data.mid(0, 100000);
       QString returnString = "<TRIGGERED ID=\"FILEREQUEST\" FILEID=\"";
       returnString.append(name);
       returnString.append("\" ");
       returnString.append("FILELEN=\"");
       returnString.append(QString::number(-100000));
       returnString.append("\">");
       returnString.append("<SVS><SV>");
       returnString.append(sendText);
       returnString.append("</SV></SVS></TRIGGERED>");

       if(this->t_tunnel)
       {
           QMetaObject::invokeMethod(t_tunnel, "sendData", Qt::DirectConnection, Q_ARG(QString, returnString.trimmed()));
       }
       else
       {
           makeResponse(returnString.trimmed());
       }
       //We dont want to send the characters again
       data.remove(0, 100000);
   }

   QString returnString = "<TRIGGERED ID=\"FILEREQUEST\" FILEID=\"";
   returnString.append(name);
   returnString.append("\" ");
   returnString.append("FILELEN=\"");
   returnString.append(QString::number(data.count()));
   returnString.append("\">");
   returnString.append("<SVS><SV>");
   returnString.append(data);
   returnString.append("</SV></SVS></TRIGGERED>");

   if(this->t_tunnel)
   {
       QMetaObject::invokeMethod(t_tunnel, "sendData", Qt::DirectConnection, Q_ARG(QString, returnString.trimmed()));
   }
   else
   {
       makeResponse(returnString.trimmed());
   }

   return true;
}

bool ProtocolHandler::saveFile(const QDomNode &domNode, QString fileName)
{
MainFrame::vdcdebug("ProtocolHandler","saveFile", "const QDomNode &domNode, QString fileName");
   QDomElement currentElement = domNode.toElement();

   if(currentElement.nodeName() == "FILE"){
      if(fileName.isEmpty()){
         QFileInfo fi(currentElement.attribute("NAME").trimmed());
         fileName = fi.fileName();


         if(fileName.contains("settings.ini")) {
             fileName = VDC::getPathToSettingsIni() + fileName;
         } else {
             fileName = QDir::tempPath() + "/" + fileName;
         }
      }
      QByteArray ba;
      ba.append(currentElement.text());
      QByteArray ba2 = QByteArray::fromBase64(ba);

      QFile file(fileName);
      if (!file.open(QIODevice::WriteOnly)){
         QString str = "Filename: " + fileName;
         MsgBox("Save File Error",str,"Warning","Ok","Ok",0);
         return false;
      }

      file.write(ba2);
      file.close();

      //qsl_receivedFiles << fileName;
      return true;
   }

   return false;

}

DebugWindow::DebugWindow(QWidget *parent) : QDialog(parent)
{
MainFrame::vdcdebug("DebugWindow","DebugWindow", "QWidget *parent");
   mainLayout = new QVBoxLayout;
   QHBoxLayout *searchline = new QHBoxLayout;
   edit = new QTextEdit();
   edit->setReadOnly(true);
   search = new QLineEdit();
   QPushButton *backward = new QPushButton(tr("Backward"));
   QPushButton *forward = new QPushButton(tr("Forward"));
   QPushButton *clear = new QPushButton(tr("Clear"));
   backward->setDefault(true);
   connect(forward,SIGNAL(clicked()), this, SLOT(forwardsearch()));
   connect(backward,SIGNAL(clicked()), this, SLOT(backwardsearch()));
   connect(clear,SIGNAL(clicked()), this, SLOT(clear()));
   mainLayout->addWidget(edit);
   mainLayout->addLayout(searchline);
   searchline->addWidget(search);
   searchline->addWidget(backward);
   searchline->addWidget(forward);
   searchline->addWidget(clear);
   setLayout(mainLayout);
   xml = "";
}

void DebugWindow::debugOut(QString debugtext)
{
MainFrame::vdcdebug("DebugWindow","debugOut", "QString debugtext");
//debugfull.append(debugtext);
xml += debugtext;
if(isVisible())
    edit->append(debugtext);

}
void DebugWindow::clear()
{
MainFrame::vdcdebug("DebugWindow","clear", "");
    edit->clear();
    xml = "";
}
void DebugWindow::forwardsearch()
{
MainFrame::vdcdebug("DebugWindow","forwardsearch", "");
edit->find(search->text());

if (!edit->find(search->text()))
if (edit->find(search->text(), QTextDocument::FindBackward))
{
edit->moveCursor(QTextCursor::Start);
edit->find(search->text());
}
}

void DebugWindow::backwardsearch()
{
MainFrame::vdcdebug("DebugWindow","backwardsearch", "");
edit->find(search->text(), QTextDocument::FindBackward);

if (!edit->find(search->text(), QTextDocument::FindBackward))
if (edit->find(search->text()))
{
edit->moveCursor(QTextCursor::End);
edit->find(search->text(), QTextDocument::FindBackward);
}
}
void DebugWindow::closeEvent(QCloseEvent *event)
{
MainFrame::vdcdebug("DebugWindow","closeEvent", "QCloseEvent *event");
   Q_UNUSED(event);
   edit->clear();
   emit debugClose();
}

void DebugWindow::showEvent(QShowEvent *ev)
{
  Q_UNUSED(ev);
  edit->setText(xml);
}

void ExecuteFile::run()
{
    exitCode = 0;

    fileName = QDir::tempPath() + "/" + fileName;
    QFileInfo fileNameInfo(fileName);

    #ifdef Q_OS_WIN
        QProcess::startDetached(QString("rundll32 url.dll,FileProtocolHandler \"%1\"").arg( fileNameInfo.absoluteFilePath()));
    #endif
#ifdef Q_OS_LINUX
    if(!QDesktopServices::openUrl(QUrl(QString("file://" + fileNameInfo.absoluteFilePath()), QUrl::TolerantMode)))
    {
        exitCode = 404;
    }
#endif

#ifdef Q_OS_MAC
    if(!QDesktopServices::openUrl(QUrl(QString("file:///" + fileNameInfo.absoluteFilePath()), QUrl::TolerantMode)))
    {
        exitCode = 404;
    }
#endif

    sleep(5);

    setHashSum();

    for(int i=0; i < 1200; i++)
    {
        if(md5Hash != VDC::md5hashfromfile(fileName))
        {
            break;
        }
        this->msleep(500);
    }
}

void ExecuteFile::setHashSum()
{
    md5Hash = VDC::md5hashfromfile(fileName);
}

