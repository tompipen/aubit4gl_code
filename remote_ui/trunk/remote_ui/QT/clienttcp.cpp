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
#include "clienttcp.h"
#include "mainframe.h"

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

void ClientTcp::incomingConnection(int socketID)
{
MainFrame::vdcdebug("ClientTcp","incomingConnection", "int socketID");
//   qDebug("incomingConnection - open socket with id: %d", socketID);

   // creates a QTcpSocket child for the QTcpServer parent
   // to read from network
   //
   socket = new ClientSocket(this);
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

//------------------------------------------------------------------------------
// Method       : newSocket()
// Filename     : tcpclient.cpp
// Description  : newSocket method... --- atm not in use
//-------------entTcp-----------------------------------------------------------------

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
   p_currScreenHandler = new ScreenHandler(this);
//   QList<ScreenHandler*> *l_ql_screenhandler =  QList<ScreenHandler*> MainFrame::ql_screenhandler;
   MainFrame::ql_screenhandler->append(p_currScreenHandler);
   // Thread to handle protocols data
   //
   ph.p_currScreenHandler = p_currScreenHandler;

   connect(this, SIGNAL(readyRead()),    this, SLOT(readClient()));
   connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));

   connect(&ph, SIGNAL(makeResponse(QString)), 
          this, SIGNAL(makeResponse(QString)));

   if(parent == NULL){
      connect(&ph, SIGNAL(makeResponse(QString)), 
             this, SLOT(makeOwnResponse(QString)));
   }
   connect(&ph, SIGNAL(setUpdatesEnabled(bool)),
           p_currScreenHandler, SLOT(setUpdatesEnabled(bool)));
   // OPEN FORM
   connect(&ph, SIGNAL(createWindow(QString, QString, int, int, int, int, QString)), 
           p_currScreenHandler, SLOT(createWindow(QString, QString, int, int, int, int, QString)));
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
   connect(&ph, SIGNAL(setFieldHidden(QString, bool)), 
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
   connect(&ph, SIGNAL(setEvent(QString, QString, int)), 
           p_currScreenHandler, SLOT(setEvent(QString, QString, int)));

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
}



void ClientSocket::makeOwnResponse(QString qs_replyString)
{
MainFrame::vdcdebug("ClientSocket","makeOwnResponse", "QString qs_replyString");
   QTextStream out;
   out.setDevice(this);

   qs_replyString+="\n";
   qs_replyString.replace("\n", "");
   out << qs_replyString;
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
   }

   if(p_currScreenHandler->p_prompt != NULL){
      p_currScreenHandler->p_prompt->setVisible(false);
      p_currScreenHandler->p_prompt->close();
      p_currScreenHandler->p_prompt->deleteLater();
   }

   QList<FglForm*> ql_forms = p_currScreenHandler->ql_fglForms;
   for(int i=0; i<ql_forms.size(); i++){
      p_currScreenHandler->closeWindow(ql_forms.at(i)->windowName);
   }

  delete p_currScreenHandler;
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
      
   while(canReadLine()){
      request.append(readLine());
   }

   // while existing thread is running 
   // wait until it's done to start a new one
   //


   while(ph.isRunning()){
   }

   if(!request.isNull()){
      ph.request.append(request);
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
         if(cl->ph.p_currScreenHandler->qh_env.contains("DB_LOCALE")){
             out.setCodec(QTextCodec::codecForName("IBM850"));
         }

         qs_replyString+="\n";

         out << qs_replyString;
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
   QString qs_protocolCommand;
   if(p_currScreenHandler != NULL &&
      p_currScreenHandler->qh_env.contains("DB_LOCALE")){

      p_currScreenHandler->qh_env["DB_LOCALE"] = "IBM850";
      QTextCodec *codec = QTextCodec::codecForName(qPrintable(p_currScreenHandler->qh_env["DB_LOCALE"]));
      QTextStream in_request(&request);
      in_request.setCodec(codec);
      qs_protocolCommand = in_request.readAll();
      qs_protocolCommand = filterUmlauts(qs_protocolCommand);
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
      while (!in.atEnd()) {
            qs_protocolCommand = in.readAll();
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
         request.remove(0, index_end+11);
         i=0;
      }
      else{
         if(index_end == -1)
         {
            i = qs_protocolCommand.size();
         }
      }
   }

   QDomDocument doc;
      
   for(int i=0; i<qsl_xmlCommands.size(); i++)
   {
         QString tmpstring = filterUmlauts(qsl_xmlCommands.takeAt(i));
         qsl_xmlCommands.insert(i, tmpstring);
      QString errorMsg;
      int errorLine, errorCol;
      if (!doc.setContent(qsl_xmlCommands.at(i), &errorMsg, &errorLine, &errorCol)){
         QString str = errorMsg + "\n" +
                       "Line:" + QString::number(errorLine) + "\n" +
                       "Column" + QString::number(errorCol);
         MsgBox("Protocol Error",str,"Warning","Ok","Ok",0);
         break;
      }
      else{
   if(b_write){
      // -- Record Datastream
      QFile file(fileName);
      if (!file.open(QIODevice::WriteOnly | QIODevice::Append)){
         return;
      }
      QTextStream out(&file);
      out << qsl_xmlCommands.at(i);
   }
   QString test = doc.toString();
   test = filterUmlauts(test);
   doc.clear();
   if (!doc.setContent(test, &errorMsg, &errorLine, &errorCol)){
      QString str = errorMsg + "\n" +
                    "Line:" + QString::number(errorLine) + "\n" +
                    "Column" + QString::number(errorCol);
      MsgBox("Protocol Error",str,"Warning","Ok","Ok",0);
      break;
   }
   emit debugtext(QString("<< " + qsl_xmlCommands.at(i)));
         QDomElement envelope = doc.documentElement();
         pid = envelope.attribute("ID").toInt();
         int p_pid = envelope.attribute("PID").toInt();
         p_currScreenHandler->pid = pid;
         p_currScreenHandler->p_pid = p_pid;
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
      }
   }
}

QString ProtocolHandler::getTemplateHeader(QString filename)
{
    QFile *file = new QFile(QDir::tempPath() + "/" + filename);

    if(!file->open(QIODevice::ReadOnly)) {
        qDebug() << "Konnte Template file nicht �ffnen" << "";
    }

    QDomDocument doc;
    doc.setContent(file);

    QString xml = doc.toString();
    QTextStream stream(&xml);
    QString header;
    int cnt = 0;
    while(!stream.atEnd()) {
        header = header + stream.readLine();

        if(header.contains("<table:table-row")) {
            header.append("</table:table-row>");
            cnt = 1;
        }
        if(cnt == 1) {
            return header;
        }
    }
   file->close();

}

QString ProtocolHandler::getTemplatePosition(QString odffile)
{

    //qDebug() << "odf: " << odffile;
    QFile *file = new QFile(QDir::tempPath() + "/" + odffile);

    if(!file->open(QIODevice::ReadOnly)) {
        qDebug() << "konnte kopf datei nicht lesen" << "";
    }

    QDomDocument doc;
    doc.setContent(file);

    QString xml = doc.toString();
    QTextStream stream(&xml);
    QString ausgabe;
    QString behalten;
    int cnt = 0;
    int stop = 0;

    while(!stream.atEnd()) {
        ausgabe = stream.readLine();

        if(ausgabe.contains("[")) {
            stop = 1;
        }

        if(ausgabe.contains("<table:table-row")) {
            cnt = 1;

        }

        if(cnt > 0 && stop  < 1) {
            behalten = behalten + ausgabe;
        }

        if(ausgabe.contains("</table:table-row")) {
            cnt = 0;
        }

    }

    behalten.append("</table:table-cell></table:table-row>");

    file->close();

    return behalten;
}

void ProtocolHandler::startReportTemplate(QString odffile, QString sedfile)
{
   QString content;
   QList<QString> fieldlist;
   int wiederholen = 0;
   int cnt = 0;

   QFile *file = new QFile(QDir::tempPath() + "/content1.xml");

   if(!file->open(QIODevice::WriteOnly | QIODevice::Truncate)) {
       qDebug() << "content1.xml konnte nicht ge�ffnet werden." << "";
   }

   QTextStream xmlsave(file);
   fieldlist << getTemplateVars(odffile);

   for(int i=0; i < fieldlist.count(); i++) {
       if(cnt == 1) {
           wiederholen = checkSedFile(fieldlist.at(i), sedfile);
           for(int j=0; j < wiederholen; j++) {
               content = content + prepareTemplateContent(j, odffile, sedfile);
           }
           break;
       }
       if(fieldlist.at(i).contains("[")) {
         cnt = cnt + 1;
       }

       if(cnt == 2) {
           break;
       }

   }

   content.replace("[P1[", "");
   content.replace("[P2[", "");
   content.replace("]P1]", "");
   content.replace("]P2]", "");

   xmlsave << getTemplateHeader(odffile) << getTemplatePosition(odffile) << content << getTemplateFooter(odffile);

   file->close();

}

QString ProtocolHandler::prepareTemplateContent(int Position, QString odffile, QString sedfile)
{

    QFile *file = new QFile(QDir::tempPath() + "/" + odffile);

    if(!file->open(QIODevice::ReadOnly)) {
        qDebug() << "Template Datei nicht lesbar" << "";
    }

    QDomDocument doc;
    doc.setContent(file);
    QString xmlfile = doc.toString();
    QTextStream stream(&xmlfile);
    QString ausgabe;
    QString xmlout;
    QString test;
    QList<QString> fieldlist;
    xmlout.append("<table:table-row><table:table-cell>");

    int cnt = 0;
    int counter = 0;
    int ebene = 0;
    fieldlist << getTemplateVars(odffile);

    while(!stream.atEnd()) {
        ausgabe = stream.readLine();


        if(ausgabe.contains("[P1[")) {
        //if(ausgabe.contains("<table:table-row")) {
            counter = counter + 1;
        }

        if(counter > 0) {

            if(ausgabe.contains("[")) {
                ebene = ebene + 1;
            }
            //qDebug() << ebene;
            if(ausgabe.contains("@") && ebene == 1) {
                for(int i=0; i < fieldlist.count(); i++) {
                    if(ausgabe.contains(fieldlist.at(i))) {
                        ausgabe.replace("@" + fieldlist.at(i), QString("@%1" + fieldlist.at(i)).arg(QString::number(Position)));
                    }
                }
            }
            if(ausgabe.contains("@") && ebene == 2) {
                        cnt = cnt + 1;
            }

            if(ausgabe.contains("@") && ebene == 2) {
                for(int i=0; i < fieldlist.count(); i++) {
                    if(ausgabe.contains("@" + fieldlist.at(i))) {
                        ausgabe.replace("@" + fieldlist.at(i), QString("@%1_0" + fieldlist.at(i)).arg(QString::number(Position)));
                    }
                }
            }

            if(ausgabe.contains("@") && ebene == 3) {
                for(int i=0; i < fieldlist.count(); i++) {
                    if(ausgabe.contains("@" + fieldlist.at(i))) {
                        ausgabe.replace("@" + fieldlist.at(i), QString("@%1_0_0" + fieldlist.at(i)).arg(QString::number(Position)));
                    }
                }
            }

            if(ebene == 2) {
                test = test + ausgabe;
                if(ausgabe.contains(QString("]P%1]").arg(ebene))) {
                    for(int i=0; i < fieldlist.count(); i++) {
                        int found = 0;
                        if(fieldlist.at(i).contains(QString("[P%1[").arg(ebene))) {
                            i = i +1;
                            ausgabe.append("</table:table-cell></table:table-row>");
                            for(int j=1; j < fieldlist.count(); j++) {
                                found = checkSedFile(QString("@%1_%2" + fieldlist.at(i)).arg(Position).arg(j), sedfile);
                                if(found > 0) {
                                    ausgabe.append(prepareTemplateEbene(Position, ebene, j, doc, sedfile));
                                }
                            }
                        }
                    }

                }
            }

            if(ausgabe.contains("]")) {
                ebene = ebene -1;
            }

            xmlout = xmlout + ausgabe;
        }

        if(ausgabe.contains("</table:table-row") && xmlout.contains("]")) {
            counter = 0;
        }
    }

    file->close();

    return xmlout;



}

QString ProtocolHandler::prepareTemplateEbene(int Position, int Ebene, int Counter, QDomDocument doc, QString sedfile)
{
    QFile *file = new QFile(QDir::tempPath() + "/content1.xml");
    QString ausgabe;
    QString xmlout;
    QString xmlout1;
    int cnt = 0;

    if(!file->open(QIODevice::ReadOnly)) {
        qDebug() << "content1.xml konnte nicht ge�ffnet werden" << "";
    }

    xmlout = doc.toString();
    xmlout1.append("<table:table-row><table:table-cell>");

    QTextStream stream(&xmlout);

    while(!stream.atEnd()) {
        ausgabe = stream.readLine();

        if(ausgabe.contains(QString("[P%1[").arg(Ebene))) {
            cnt = cnt + 1;
        }

        if(cnt  == 1) {
            if(ausgabe.contains("@")) {
                ausgabe.replace("@", QString("@%1_%2").arg(QString::number(Position), QString::number(Counter)));
            }
            xmlout1 = xmlout1 + ausgabe;
        }

        if(ausgabe.contains(QString("]P%1]").arg(Ebene))) {
            cnt = cnt - 1;
        }
    }

    xmlout1.append(QString("</table:table-cell></table:table-row>"));

    return xmlout1;
}

QString ProtocolHandler::getTemplateFooter(QString filename)
{
    QFile *file = new QFile(QDir::tempPath() + "/" + filename);
    QDomDocument doc;
       doc.setContent(file);
       QString xml = doc.toString();
       QTextStream stream(&xml);
       QString footer;
       QString readLine;
       int cnt = 0;

       while(!stream.atEnd()) {
           readLine = stream.readLine();

           if(readLine.contains("</table:table>")) {
               cnt = 1;
           }
           if(cnt > 0) {
               footer = footer.trimmed() + readLine.trimmed();
           }
       }
       file->close();
       return footer;

}

int ProtocolHandler::checkSedFile(QString fieldname, QString filename)
{
    QFile *file = new QFile (QDir::tempPath() + "/" + filename);

    QTextStream stream(file);
    QString ausgabe;
    QList<QString> suchliste;
    int cnt = 0;

    if(!file->open(QIODevice::ReadOnly)) {
        qDebug() << "cannot open file!!!" << "";
    }

    while(!stream.atEnd()) {
        ausgabe = stream.readAll();
        suchliste << ausgabe.split("/g");

        if(!suchliste.isEmpty()) {
            for(int i=0; i < suchliste.count(); i++) {
                if(suchliste.at(i).contains(fieldname)) {
                    cnt = cnt + 1;
                }
            }
        }
    }
    file->close();
    return cnt;
}

QList<QString> ProtocolHandler::getTemplateVars(QString filename)
{

    QFile *file = new QFile(QDir::tempPath() + "/" + filename);

    if(file->open(QIODevice::ReadOnly)) {

        QDomDocument doc;
        doc.setContent(file);
        QString xmlout = doc.toString();
        QTextStream stream(&xmlout);
        QString ausgabe;
        QList<QString> t_fieldlist;
        int counter = 0;

        while(!stream.atEnd()) {
            ausgabe = stream.readLine();

            if(ausgabe.contains("[")) {
                counter = counter + 1;
            }

            if(ausgabe.contains("@") || ausgabe.contains("[") || ausgabe.contains("]")) {
                ausgabe.remove("<text:p>");
                ausgabe.remove("</text:p>");
                ausgabe.remove("@");
                t_fieldlist << ausgabe.trimmed();
            }
        }
        file->close();
        return t_fieldlist;
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
MainFrame::vdcdebug("ProtocolHandler","outputTree", "QDomNode domNode");
   QDomElement childElement = domNode.toElement();
   if(childElement.nodeName() == "PROGRAMSTARTUP"){
      handleStartup(childElement);
      QString programName = childElement.attribute("PROGRAMNAME");
      setProgramName(programName);
      MainFrame::check_new_pids();
      QFile stylesFile(QString("%1.4st").arg(programName));
      if (stylesFile.open(QIODevice::ReadOnly | QIODevice::Text)){
          QString qs_defaultStyle = stylesFile.readAll();
          handleXMLStyles(qs_defaultStyle);
          stylesFile.close();
      }
      else{
          stylesFile.setFileName("default.4st");
           if (stylesFile.open(QIODevice::ReadOnly | QIODevice::Text)){
               QString qs_defaultStyle = stylesFile.readAll();
               handleXMLStyles(qs_defaultStyle);
               stylesFile.close();
           }
          
      }

      QFile toolbarFile(QString("%1.4tb").arg(programName));
      if (toolbarFile.open(QIODevice::ReadOnly | QIODevice::Text)){
          QString qs_defaultToolbar = toolbarFile.readAll();
          handleXMLToolBar(qs_defaultToolbar);
          toolbarFile.close();
      }
      else{
          toolbarFile.setFileName("default.4tb");
           if (toolbarFile.open(QIODevice::ReadOnly | QIODevice::Text)){
               QString qs_defaultToolbar = toolbarFile.readAll();
               handleXMLToolBar(qs_defaultToolbar);
               toolbarFile.close();
           }
          
      }

      QFile actionsFile(QString("%1.4ad").arg(programName));
      if (actionsFile.open(QIODevice::ReadOnly | QIODevice::Text)){
          QString qs_defaultActions = actionsFile.readAll();
          handleXMLActions(qs_defaultActions);
      }
      else{
          actionsFile.setFileName("default.4ad");
           if (actionsFile.open(QIODevice::ReadOnly | QIODevice::Text)){
               QString qs_defaultActions = actionsFile.readAll();
               handleXMLActions(qs_defaultActions);
           }
          
      }
      QString id = childElement.attribute("ID");
      createWindow("dummy_ventas", "", 0, 0, 100, 100, id);
      return;
   }

   if(childElement.nodeName() == "SETAPPLICATIONLAUNCHERXML"){
      QString fileName = childElement.attribute("NAME");

      // 4JS ToolBar XML File
      if(fileName.trimmed().endsWith(".4tb")){
         QDomDocument xmlFile = encodeXMLFile(childElement.text());
         QString xmlFileString = xmlFile.toString();
         handleXMLToolBar(xmlFileString);
         return;
      }

      // 4JS Actions XML File
      if(fileName.trimmed().endsWith(".4ad")){
         QDomDocument xmlFile = encodeXMLFile(childElement.text());
         QString xmlFileString = xmlFile.toString();
         handleXMLActions(xmlFileString);
         return;
      }

      // 4JS Style XML File
      if(fileName.trimmed().endsWith(".4st")){
         QDomDocument xmlFile = encodeXMLFile(childElement.text());
         QString xmlFileString = xmlFile.toString();
         handleXMLStyles(xmlFileString);
         return;
      }

      // 4JS StartMenu XML File
      if(fileName.trimmed().endsWith(".4sm")){
         QDomDocument xmlFile = encodeXMLFile(childElement.text());
         QString xmlFileString = xmlFile.toString();
         handleXMLStartMenu(xmlFileString);
         return;
      }
      return;
   }

      
   if(childElement.nodeName() == "FILE"){
      QString fileName = childElement.attribute("NAME");
      
      // 4JS ToolBar XML File
      if(fileName.trimmed().endsWith(".4tb")){
         QDomDocument xmlFile = encodeXMLFile(childElement.text());
         QString xmlFileString = xmlFile.toString();
         handleXMLToolBar(xmlFileString);
         return;
      }

      // 4JS Actions XML File
      if(fileName.trimmed().endsWith(".4ad")){
         QDomDocument xmlFile = encodeXMLFile(childElement.text());
         QString xmlFileString = xmlFile.toString();
         handleXMLActions(xmlFileString);
         return;
      }

      // 4JS Style XML File
      if(fileName.trimmed().endsWith(".4st")){
         QDomDocument xmlFile = encodeXMLFile(childElement.text());
         QString xmlFileString = xmlFile.toString();
         handleXMLStyles(xmlFileString);
         return;
      }

      // 4JS StartMenu XML File
      if(fileName.trimmed().endsWith(".4sm")){
         QDomDocument xmlFile = encodeXMLFile(childElement.text());
         QString xmlFileString = xmlFile.toString();
/*
         p_currScreenHandler->qh_env["DB_LOCALE"] = "IBM850";
         QTextCodec *codec = QTextCodec::codecForName(qPrintable(p_currScreenHandler->qh_env["DB_LOCALE"]));
         QFile file("T1.txt");
         if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            return;
         }
         QByteArray ba = xmlFileString.toAscii();
         QTextStream in_request(&ba);
         in_request.setCodec(codec);
         in_request << xmlFileString;
         xmlFileString = in_request.readAll();
*/
         xmlFileString = filterUmlauts(xmlFileString);

         handleXMLStartMenu(xmlFileString);
         return;
      }

      if(fileName.trimmed() == "Client"){
         if(saveFile(childElement, "Client.tmp")){
            QDir dir = QDir::current();
            QString path = QDir::currentPath();

            QString fileName = "Client";
            if("Windows" == QString()){
              fileName += ".exe";
            }
            dir.rename(fileName, "Client.bak");
            dir.rename("Client.tmp", fileName);
         }
         return;
      }

      if(saveFile(childElement)){
      }

      return;
   }

   if(childElement.nodeName() == "RUNINFO"){
      bool startstop = childElement.attribute("STARTSTOP").toInt();
      QString cmd = childElement.attribute("CMD");
      int runcnt = childElement.attribute("RUNCNT").toInt();
      int mode = childElement.attribute("MODE").toInt();
      setRuninfo(mode, cmd, runcnt, startstop);
   }

   if(childElement.nodeName() == "REQUESTFILE"){
      QString fileId = childElement.attribute("FILEID");
      sendFile(fileId);
   }
   
   if(childElement.nodeName() == "EXECUTE"){
      QString fileName = childElement.text();
      fileName = QDir::tempPath() + "/" + fileName;
      QFileInfo fileInfo(fileName);

/*
      //QString prog = "xdg-open";
      QString prog = "finder";
      QStringList args;
      args << fileInfo.absoluteFilePath();
      QProcess process;
      qDebug() << "RUN: " << prog << args;
      process.execute(prog, args);
*/
      #ifdef Q_WS_X11      
         QDesktopServices::openUrl(QUrl(QString("file://" + fileInfo.absoluteFilePath()), QUrl::TolerantMode));
      #else
         QDesktopServices::openUrl(QUrl(QString("file:///" + fileInfo.absoluteFilePath()), QUrl::TolerantMode));
      #endif
      //sleep(3);
      return;
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
         fileBrowser(qs_function,qs_defPath, qs_fileNames, qs_fileTypes, qs_caption);
      }
   }

   if(childElement.nodeName() == "FRONTCALL"){
      QString qs_module = childElement.attribute("MODULE");
      QString qs_name = childElement.attribute("NAME");
      int expect = childElement.attribute("EXPECT").toInt();

      QDomElement paramsElement = childElement.firstChildElement();
      QString value;

      if(qs_module == "Standard"){
       
      }

      if(qs_module == "INTERNAL"){
         if(qs_name == "ui.window.getcurrent"){
            //TODO
            value = QString::number(p_currScreenHandler->getCurrWindow());
         }

         if(qs_name == "ui.window.getform"){
            //TODO
            value = QString::number(p_currScreenHandler->getCurrForm());
         }

         if(qs_name == "ui.window.settext"){
            QDomElement values = childElement.firstChildElement();
            QDomElement valueElement = values.firstChildElement().nextSiblingElement();
            value = valueElement.text();
            setWindowTitle(value);
         }

         if(qs_name == "ui.window.repgen") {
             QString odffile;
             QString sedfile;
             for(int k=0; k < paramsElement.childNodes().count(); k++) {
                 QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
                 if(k == 0) {
                    odffile = valuesElement.text();
                 }
                 if(k == 1) {
                     sedfile = valuesElement.text();
                 }
             }
             startReportTemplate(odffile, sedfile);
         }


         if(qs_name == "ui.form.setelementhidden"){
            int form = -1;
            QString fieldName;
            int hidden = false;
            for(int k=0; k<paramsElement.childNodes().count(); k++){
               QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
               if(k == 0){
                  form = valuesElement.text().toInt();
               }

               if(k == 1){
                  fieldName = valuesElement.text();
               }

               if(k == 2){
                  hidden = valuesElement.text().toInt();
               }
            }
            setElementHidden(fieldName, hidden);
         }

         if(qs_name == "ui.form.setfieldhidden"){
            int form = -1;
            QString fieldName;
            int hidden = false;
            for(int k=0; k<paramsElement.childNodes().count(); k++){
               QDomElement valuesElement = paramsElement.childNodes().at(k).toElement();
               if(k == 0){
                  form = valuesElement.text().toInt();
               }

               if(k == 1){
                  fieldName = valuesElement.text();
               }

               if(k == 2){
                  hidden = valuesElement.text().toInt();
               }
            }

            setFieldHidden(fieldName, hidden);
         }

         if(qs_name == "ui.interface.refresh"){
         }

         if(qs_name == "ui.interface.settext"){
            QDomElement values = childElement.firstChildElement();
            QDomElement valueElement = values.firstChildElement();
            QString value = valueElement.text();

            p_currScreenHandler->setInterfaceText(value);
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
            p_currScreenHandler->addComboBoxItem(id, text, value);
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
            p_currScreenHandler->removeComboBoxItem(id, text);
         }

         if(qs_name == "ui.combobox.clear"){
            QDomElement values = childElement.firstChildElement();
            QDomElement valueElement = values.firstChildElement();
            id = valueElement.text().toInt();
            p_currScreenHandler->clearComboBox(id);
         }

         if(qs_name == "ui.combobox.forname"){
            QDomElement values = childElement.firstChildElement();
            QDomElement valueElement = values.firstChildElement();
            value = valueElement.text();
            value = QString::number(p_currScreenHandler->currForm()->findFieldIdByName(value));
         }

         if(qs_name == "ui.combobox.getcolumnname"){
            QDomElement values = childElement.firstChildElement();
            QDomElement valueElement = values.firstChildElement();
            int id = valueElement.text().toInt();
            value = WidgetHelper::getWidgetColName(p_currScreenHandler->currForm()->findFieldById(id));
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
            if(ComboBox *cb = qobject_cast<ComboBox *> (p_currScreenHandler->currForm()->findFieldById(id))){
               value = cb->itemData(pos-1).toString();
            }
         }

         if(qs_name == "ui.combobox.getitemcount"){
            QDomElement values = childElement.firstChildElement();
            QDomElement valueElement = values.firstChildElement();
            int id = valueElement.text().toInt();
            if(ComboBox *cb = qobject_cast<ComboBox *> (p_currScreenHandler->currForm()->findFieldById(id))){

                value = QString::number(cb->count());
            }
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
            if(ComboBox *cb = qobject_cast<ComboBox *> (p_currScreenHandler->currForm()->findFieldById(id))){
               value = cb->itemText(pos-1);
            }
         }

         if(qs_name == "ui.combobox.gettablename"){
            QDomElement values = childElement.firstChildElement();
            QDomElement valueElement = values.firstChildElement();
            int id = valueElement.text().toInt();
            value = WidgetHelper::getWidgetTabName(p_currScreenHandler->currForm()->findFieldById(id));
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
             if(ComboBox *cb = qobject_cast<ComboBox *> (p_currScreenHandler->currForm()->findFieldById(id))){
                 value = QString::number(cb->findText(text));
             }
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
                         showOption(commandName);
                         commandName = "";
                     }
                     else{
                         hideOption(commandName);
                         commandName = "";
                     }
                 }

             }
         }

      }

      if(expect > 0){
         QDomDocument doc;
         QDomElement triggeredElement = doc.createElement("TRIGGERED");
         triggeredElement.setAttribute("ID", -123);
         doc.appendChild(triggeredElement);

         QDomElement syncValuesElement = doc.createElement("SVS");
         triggeredElement.appendChild(syncValuesElement);
         QDomElement syncValueElement = doc.createElement("SV");
         syncValuesElement.appendChild(syncValueElement);
         QDomText text = doc.createTextNode(value);
         syncValueElement.appendChild(text);
         QString returnString = doc.toString();

         //makeResponse(returnString.trimmed());
         p_currScreenHandler->sendDirect(returnString.trimmed());
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

      createWindow(window, style, x, y, h, w, id);
      return;
   }

   if(childElement.nodeName() == "OPENFORM"){
      QString window = childElement.attribute("FORMNAME");

      createWindow(window, "", 0, 0, 0, 0, 0);

      if(childElement.firstChildElement().nodeName() == "XMLFORM"){
        QDomDocument xmlForm = encodeXMLFile(childElement.text());
        QString xmlFormString = xmlForm.toString();
        handleXMLForm(window, xmlFormString, false);
      }

      if(childElement.firstChildElement().nodeName() == "FORM"){
         QDomDocument xmlForm("FORM");
         xmlForm.appendChild(childElement.firstChildElement());
         
         QString xmlFormString = xmlForm.toString();
         handleAubitForm(window, xmlFormString, false);
      }

      QDomNodeList ql_nodes = childElement.childNodes();
      for(int k=0; k<ql_nodes.count(); k++){
         if(ql_nodes.at(k).nodeName() == "FORM"){
            QDomDocument xmlForm("FORM");
            xmlForm.appendChild(ql_nodes.at(k));
         
            QString xmlFormString = xmlForm.toString();
            handleAubitForm(window, xmlFormString, false);
         }
      }
      return;
   }

   if(childElement.nodeName() == "DISPLAYFORM"){
      displayForm(childElement.attribute("FORMNAME"));
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
      
      // BORDER  - not used atm
      int border = childElement.attribute("BORDER").toInt();
      
      // COMMENT_LINE  - not used atm
      int comment_line = childElement.attribute("COMMENT_LINE").toInt();
      
      // MESSAGE_LINE  - not used atm
      int message_line = childElement.attribute("MESSAGE_LINE").toInt();
      */

      createWindow(window, style, x, y, 0, 0, id);

      if(childElement.firstChildElement().nodeName() == "XMLFORM"){
        QDomDocument xmlForm = encodeXMLFile(childElement.text());
        QString xmlFormString = xmlForm.toString();

        handleXMLForm(window, xmlFormString, true);
      }

      if(childElement.firstChildElement().nodeName() == "FORM"){
         QDomDocument xmlForm("FORM");
         xmlForm.appendChild(childElement.firstChildElement());
         
         QString xmlFormString = xmlForm.toString();
         handleAubitForm(window, xmlFormString, true);
      }

      QDomNodeList ql_nodes = childElement.childNodes();
      for(int k=0; k<ql_nodes.count(); k++){
         if(ql_nodes.at(k).nodeName() == "FORM"){
            QDomDocument xmlForm("FORM");
            xmlForm.appendChild(ql_nodes.at(k));
         
            QString xmlFormString = xmlForm.toString();
            handleAubitForm(window, xmlFormString, true);
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
      return;
   }

   if(childElement.nodeName() == "SETWINDOWTITLE"){
      QString title = childElement.attribute("TEXT");
      //setWindowTitle(title);
      p_currScreenHandler->setInterfaceText(title);
      return;
   }

   if(childElement.nodeName() == "CURRENTWINDOW"){
      QString name = childElement.attribute("WINDOW");
      activeWindow(name);
      return;
   }


   if(childElement.nodeName() == "MENU"){
      int context = childElement.attribute("CONTEXT").toInt();

      setFormOpts(childElement.nodeName(), true, context);
      handleMenuElement(childElement);
      return;
   }

   if(childElement.nodeName() == "NEXTOPTION"){
      //TODO
      int context = childElement.attribute("CONTEXT").toInt();
      QString name = childElement.attribute("OPTION");
      nextOption(name, context);
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

      createPrompt(text, charMode, fieldAttribute, attributeStyle);
      return;
   }



   if(childElement.nodeName() == "SETKEYLABEL"){
      //int dialog = childElement.attribute("DIALOG").toInt();
      QString label = childElement.attribute("LABEL");
      QString text  = childElement.attribute("TEXT").trimmed();

      setKeyLabel(label, text);
      return;
   }

   if(childElement.nodeName() == "SETCURSOR"){
      int position = childElement.attribute("POSITION").toInt();
      setCursorPosition(position-1);
      return;
   }

   if(childElement.nodeName() == "ERROR"){
      QString text = childElement.text();
      displayError(text);
      return;
   }

   if(childElement.nodeName() == "MESSAGE"){
      QString text = childElement.text();
      displayMessage(text);
      return;
   }

   if(childElement.nodeName() == "HIDEOPTION"){
      QString id = childElement.attribute("OPTION");
      hideOption(id);
      return;
   }

   if(childElement.nodeName() == "SHOWOPTION"){
      QString id = childElement.attribute("OPTION");
      showOption(id);
      return;
   }

   if(childElement.nodeName() == "DISPLAYTO"){
      handleDisplayToElement(childElement);
      return;
   }

   if(childElement.nodeName() == "DISPLAYARRAY"){
      int context = childElement.attribute("CONTEXT").toInt();
      setFormOpts("DISPLAYARRAY", true, context);
      handleEventsElement(childElement);
      handleDisplayArrayElement(childElement);
      return;
   }

   if(childElement.nodeName() == "INPUTARRAY"){
      int context = childElement.attribute("CONTEXT").toInt();
      setFormOpts("INPUTARRAY", true, context);

      handleEventsElement(childElement);
      handleDisplayArrayElement(childElement);
      return;
   }

   //SET ARR LINE FOR SCREEN RECORD
   if(childElement.nodeName() == "SETARRLINE"){
      int line = childElement.attribute("LINE").toInt();
      setArrLine(line);
   }
   
   //SET SCR LINE FOR SCREEN RECORD
   if(childElement.nodeName() == "SETSCRLINE"){
      int line = childElement.attribute("LINE").toInt();
      setScrLine(line);
   }


   if(childElement.nodeName() == "INPUT"){
      int context = childElement.attribute("CONTEXT").toInt();

      setFormOpts("INPUT", true, context);
      handleEventsElement(childElement);
      handleInputElement(childElement);
      setFieldOrder(qsl_fieldList);
      setFieldFocus(qsl_fieldList.first());
      return;
   }

   if(childElement.nodeName() == "CONSTRUCT"){
      int context = childElement.attribute("CONTEXT").toInt();

      setFormOpts(childElement.nodeName(), true, context);
      handleEventsElement(childElement);
      createActionMenu();
/*
      createActionMenuButton("ACCEPT", "ACCEPT", "");
      createActionMenuButton("CANCEL", "CANCEL", "");
*/
      handleConstructElement(childElement);
      setFieldOrder(qsl_fieldList);
      setFieldFocus(qsl_fieldList.first());

      return;
   }

   if(childElement.nodeName() == "NEXTFIELD"){
      QString field = childElement.attribute("FIELD");
      setFieldFocus(field);
      return;
   }

   
   if(childElement.nodeName() == "WAITFOREVENT"){
      handleWaitForEventElement(childElement);
      waitForEvent();
      return;
   }

   if(childElement.nodeName() == "FREE"){
      QString type = childElement.attribute("TYPE");
      p_currScreenHandler->qsl_activeFieldNames.clear();
      int context = childElement.attribute("CONTEXT").toInt();
      setFormOpts(type, false, context);
      return;
   }

   
   if(childElement.nodeName() == "CLOSEWINDOW"){
      QString name = childElement.attribute("WINDOW");
      closeWindow(name);
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
              MsgBox(title,text,icon,possibleButtons,defaultBtn,1);

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
         MsgBox("Program stopped",str,"Warning","Ok","Ok",0);

      }

      for(int j=0; j<qsl_receivedFiles.count(); j++){
         QFile::remove(qsl_receivedFiles.at(j));
      }
      return;
   }

   
}
//------------------------------------------------------------------------------
// Method       : encodeXMLFile(QString)
// Filename     : tcpclient.cpp
// Description  : encodes the decoded XMLFile back to XML
//------------------------------------------------------------------------------
QDomDocument ProtocolHandler::encodeXMLFile(QString xmlString)
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
   
   return xmlDoc;
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
         p_currScreenHandler->setEnv(name, value);

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
                   qs_text = filterUmlauts(QString(ba2));
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
      setFieldBuffer(qsl_fieldNames, qsl_fieldValues, attribute);
   }
   else{
      for(int i=0; i<qsl_fieldValues.count(); i++){
         setFieldBuffer(i,qsl_fieldValues.at(i), attribute);
      }
   }
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

      setFormOpts(arrayElement.nodeName(), QString("ARRCOUNT"), arrCount);
      setFormOpts(arrayElement.nodeName(), QString("ARRVARIABLES"), arrVariables);
      setFormOpts(arrayElement.nodeName(), QString("MAXARRSIZE"), maxArrSize);
      setFormOpts(arrayElement.nodeName(), QString("WITHOUT_DEFAULTS"), withoutDefaults);
      setFormOpts(arrayElement.nodeName(), QString("ALLOWINSERT"), allowInsert);
      setFormOpts(arrayElement.nodeName(), QString("ALLOWDELETE"), allowDelete);
      setFormOpts(arrayElement.nodeName(), QString("NONEWLINES"), noNewLines);
      setFormOpts(arrayElement.nodeName(), QString("WRAP"), wrap);

      createActionMenu();
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
                  setScreenRecordEnabled(screenRecordName, true, input);
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
               int row = rowElement.attribute("SUBSCRIPT").toInt();
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
                  setArrayBuffer(row, screenRecordName, qsl_arrayValues);
               }
               else{
                  setArrayBuffer(row-1, qsl_arrayValues);
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
      setFormOpts(nodeName, QString("WITHOUT_DEFAULTS"), withoutDefaults);
      setFormOpts(nodeName, QString("WRAP"), wrap);
      setFormOpts(nodeName, QString("ATTRIBUTE"), attribute);
      createActionMenu();
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
         // Set focus for the first field in the list
         bool focus = false;
         if(i == 0)
            focus = true;

         QString field = currentElement.attribute("NAME");
         qsl_fieldList << field;
         setFieldEnabled(field, true, false, attribute);
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
      setFormOpts(nodeName, QString("WRAP"), wrap);
      setFormOpts(nodeName, QString("ATTRIBUTE"), attribute);
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
         setFieldEnabled(field, true, focus, attribute);
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

      createMenu(title, comment, style, image);
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
            createMenuButton(id, text, desc, keys);
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
            createMenuAction(id, text);
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
         nodeName == "BEFORE_DISPLAY_EVENT"){
         int id = currentElement.attribute("ID").toInt();
         setEvent(nodeName, QString(), id);
      }

      if(nodeName == "AFTER_INPUT_EVENT" ||
         nodeName == "AFTER_CONSTRUCT_EVENT" ||
         nodeName == "AFTER_DISPLAY_EVENT"){
         int id = currentElement.attribute("ID").toInt();
         setEvent(nodeName, QString(), id);
      }

      if(nodeName == "BEFORE_FIELD_EVENT" || 
         nodeName == "AFTER_FIELD_EVENT"){
         QString field = currentElement.attribute("FIELD");
         int id = currentElement.attribute("ID").toInt();
         setEvent(nodeName, field, id);
      }

      if(nodeName == "BEFORE_ROW_EVENT" || 
         nodeName == "AFTER_ROW_EVENT"){
         int id = currentElement.attribute("ID").toInt();
         setEvent(nodeName, QString(), id);
      }

      if(nodeName == "ONKEY_EVENT"){
         int id  = currentElement.attribute("ID").toInt();
         int key = currentElement.attribute("KEY").toInt();

         setEvent(nodeName, QString::number(key), id);
      }

      if(nodeName == "ON_ACTION_EVENT"){
         int id  = currentElement.attribute("ID").toInt();
         QString key = currentElement.attribute("ACTION");

         setEvent(nodeName, key, id);
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


   if(currentElement.attribute("CACHED").toInt() != 0)
       return;

   //Not needed atm
   int changed = -1;
   if(nodeName == "WAITFOREVENT"){
      changed = currentElement.attribute("CHANGED").toInt();
   }

   // currently not used
   if(currentElement.firstChildElement().nodeName() == "ROWS"){
      handleDisplayArrayElement(currentElement);
   }


   if(currentElement.firstChildElement().nodeName() == "VS"){
      if(changed > 0){
         handleDisplayToElement(currentElement, currentElement.nodeName());
      }
   }

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
   makeResponse(qs_id);
   emit debugtext(QString(">> " + qs_id));
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
   QDomDocument doc;

   
   if(name.isNull())
      return false;

   QFile file;
   file.setFileName(name);
   if(!file.open(QIODevice::ReadOnly | QIODevice::Unbuffered)){
      QFileInfo inf(name);
      file.setFileName(QDir::tempPath() + "/" + inf.fileName());
      if(!file.open(QIODevice::ReadOnly | QIODevice::Unbuffered)){
         return false;
      }
   }
   // Get Filesize
   qint64 fileSize = file.size();

   QDomElement triggeredElement = doc.createElement("TRIGGERED");
   triggeredElement.setAttribute("ID", "FILEREQUEST");
   triggeredElement.setAttribute("FILEID", name);
   triggeredElement.setAttribute("FILELEN", fileSize);
   doc.appendChild(triggeredElement);

   QDomElement syncValuesElement = doc.createElement("SVS");
   triggeredElement.appendChild(syncValuesElement);
   QDomElement syncValueElement = doc.createElement("SV");
   syncValuesElement.appendChild(syncValueElement);

   QByteArray data;

   while(!file.atEnd()){
      data = file.readAll();
   }

   data = data.toBase64();

   QString returnString = "<TRIGGERED ID=\"FILEREQUEST\" FILEID=\"";
   returnString.append(name);
   returnString.append("\" ");
   returnString.append("FILELEN=\"");
   returnString.append(QString::number(fileSize));
   returnString.append("\">");
   returnString.append("<SVS><SV>");
   returnString.append(data);
   returnString.append("</SV></SVS></TRIGGERED>");

   makeResponse(returnString.trimmed());

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
         fileName = QDir::tempPath() + "/" + fileName;
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


QString ProtocolHandler::filterUmlauts(QString qs_text)
{
MainFrame::vdcdebug("ProtocolHandler","filterUmlauts", "QString qs_text");

   qs_text.replace(QChar(129), QString::fromUtf8("ü")); 
   qs_text.replace(QChar(130), QString::fromUtf8("é")); 
   qs_text.replace(QChar(131), QString::fromUtf8("â")); 
   qs_text.replace(QChar(132), QString::fromUtf8("ä")); 
   qs_text.replace(QChar(133), QString::fromUtf8("� ")); 
   qs_text.replace(QChar(134), QString::fromUtf8("å")); 
   qs_text.replace(QChar(135), QString::fromUtf8("ç")); 
   qs_text.replace(QChar(136), QString::fromUtf8("ê")); 
   qs_text.replace(QChar(137), QString::fromUtf8("ë")); 
   qs_text.replace(QChar(138), QString::fromUtf8("è")); 
   qs_text.replace(QChar(139), QString::fromUtf8("ï")); 
   qs_text.replace(QChar(140), QString::fromUtf8("î")); 
   qs_text.replace(QChar(141), QString::fromUtf8("ì"));
   qs_text.replace(QChar(142), QString::fromUtf8("Ä"));


   qs_text.replace(QChar(145), QString::fromUtf8("æ")); 
   qs_text.replace(QChar(146), QString::fromUtf8("Æ")); 
   qs_text.replace(QChar(147), QString::fromUtf8("ô")); 
   qs_text.replace(QChar(148), QString::fromUtf8("ö")); 
   qs_text.replace(QChar(149), QString::fromUtf8("ò")); 
   qs_text.replace(QChar(150), QString::fromUtf8("û"));
   qs_text.replace(QChar(153), QString::fromUtf8("Ö"));
   qs_text.replace(QChar(154), QString::fromUtf8("Ü"));
   qs_text.replace(QChar(225), QString::fromUtf8("ß"));
   qs_text.replace(QChar(245), QString::fromUtf8("ä"));

   return qs_text;
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
}

void DebugWindow::debugOut(QString debugtext)
{
MainFrame::vdcdebug("DebugWindow","debugOut", "QString debugtext");
//debugfull.append(debugtext);
edit->append(debugtext);
}
void DebugWindow::clear()
{
MainFrame::vdcdebug("DebugWindow","clear", "");
    edit->clear();
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
   emit debugClose();
}
