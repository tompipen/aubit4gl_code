//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : tcpclient.h
// Description  : contains the tcpclient class definition
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
#ifndef CLIENTTCP_H
#define CLIENTTCP_H

#include <QTcpSocket>
#include <QTcpServer>

#include <QErrorMessage>
#include <QObject>
#include <QThread>
#include <QTextStream>

#include <QDomNode>
#include <QDomDocument>

#include "screenhandler.h"

class DebugWindow : public QDialog
{

    Q_OBJECT;

    public:
      DebugWindow(QWidget *parent = 0);
      QVBoxLayout *mainLayout;
      QTextEdit *edit;
      QString debugfull;
      QLineEdit *search;

    public slots:
      void debugOut(QString);
      void forwardsearch();
      void clear();
      void backwardsearch();
      void closeEvent(QCloseEvent *event);
    signals:
      void debugClose();

};

class ProtocolHandler : public QThread
{
   Q_OBJECT;

public:
   ProtocolHandler(QObject *parent = NULL);
   ~ProtocolHandler();
   void run();

   // Holds the XMLProtocolString
   QByteArray request;
   DebugWindow *dw;
   ScreenHandler *p_currScreenHandler;
   QString qs_shortCutUser;
   QString qs_shortCutPass;
   QString qs_shortCutProgram;
   QString fileName;
   bool b_read;
   bool b_write;
   int pid;
   int id;
   bool startReportTemplate(QString odffile, QString sedfile);
   void replaceTempateVars(QString odffile, QString sedfile);
   QString prepareTemplateContent(int Position, QString odffile, QString sedfile);
   QString prepareTemplateEbene(int Position, int Ebene, int Counter, QDomDocument doc, QString odffile);
   QString getTemplateHeader(QString odffile);
   QString getTemplateFooter(QString odffile);
   QString getTemplatePosition(QString odffile);
   QList<QString> readSedFile(QString seddatei);
   int checkSedFile(QString fieldname, QString sedfile);
   QList<QString> getTemplateVars(QString filename);

private:
   QString decodeFile(QString);
   void outputTree(QDomNode);

   QDomDocument encodeXMLFile(QString);
   void handleStartup(const QDomNode&);
   void handleDisplayToElement(const QDomNode&, QString parentNodeName = "");
   void handleDisplayArrayElement(const QDomNode&, QString parentNodeName = "");
   void handleInputElement(const QDomNode&, int attribute = 0);
   void handleConstructElement(const QDomNode&);
   void handleWaitForEventElement(const QDomNode&);
   void handleMenuElement(const QDomNode&);
   void handleEventsElement(const QDomNode&);
   bool sendFile(QString name);
   bool saveFile(const QDomNode&, QString fileName = "");
   QString filterUmlauts(QString);

   QStringList qsl_fieldList, qsl_arrayTabNames, qsl_arrayValues, qsl_receivedFiles;


signals:
   void makeResponse(QString);
   void setUpdatesEnabled(bool);

   // ProtocolHandler -> ScreenHandler (WorkerThread -> GuiThread)
   void createWindow(QString, QString, int, int, int, int, QString);
   void setWindowTitle(QString);

   void createPrompt(QString, int, int, QString);

   void createMenu(QString, QString, QString, QString);
   void createMenuButton(int, QString, QString, QStringList);
   void createMenuAction(int, QString);
   void setMenuEnabled(bool);
   void setProgramName(QString);
   void hideOption(int);
   void hideOption(QString);
   void showOption(QString);
   void nextOption(QString, int context);


   void displayError(QString);
   void displayMessage(QString);

   void createActionMenu();
   void createActionMenuButton(QString, QString);
   void debugtext( const QString& );

   void setKeyLabel(QString, QString);
   void setCursorPosition(int);

   void handleAubitForm(QString, QString, bool);
   void displayForm(QString);

   void handleXMLForm(QString, QString, bool);
   void handleXMLToolBar(QString);
   void handleXMLStartMenu(QString);
   void handleXMLActions(QString);
   void handleXMLStyles(QString);


   void setFieldBuffer(QStringList, QStringList, int);
   void setFieldBuffer(int, QString, int);
   void setArrayBuffer(int, QString, QStringList);
   void setArrayBuffer(int, QStringList);
   void clearFieldBuffer(QString);
   void setFieldEnabled(QString, bool, bool, int);
   void setFieldFocus(QString);
   void setFieldHidden(QString, bool);
   void setElementHidden(QString, bool);
   void setRuninfo(int, QString, int, bool);
   void setScreenRecordEnabled(QString,bool, bool);
   void loadArrayValues(QStringList, QStringList);
   void loadArrayValues(QStringList);
   void setArrLine(int);
   void setScrLine(int);
   void setFieldOrder(QStringList);
   void setEvent(QString, QString, int);

   void setFormOpts(QString, bool, int);
   void setFormOpts(QString, QString, int);

   void waitForEvent();
   void free(QString);
   void MsgBox(QString,QString,QString,QString,QString,int);
   void closeWindow(QString);
   void activeWindow(QString);
   void fileBrowser(QString, QString, QString, QString, QString);

public slots:
   void fglFormResponse(QString);

};

class ClientSocket : public QTcpSocket
{
   Q_OBJECT;

   public:
      ClientSocket(QObject *parent = 0, QString user = "", QString pass = "", QString program = "");
      ~ClientSocket();
      DebugWindow *dw;
      ProtocolHandler ph;
      QTextCodec *codec;

   private:
      ScreenHandler *p_currScreenHandler;


signals:
      void makeResponse(QString);
      void makeResponse(int);
      void makeResponse();

private slots:
   void readClient();
   void makeOwnResponse(QString);
};


class ClientTcp : public QTcpServer
{
   Q_OBJECT

   public:
      ClientTcp(QObject *parent = 0);
      ~ClientTcp();
      ClientSocket *socket;
      //ClientSocket *p_arr_socket[16];
      QList<ClientSocket*> p_arr_socket;
      int i_cnt_socket;
      void setDebugModus(bool, QWidget*);
      DebugWindow *dw;
      bool debugModus;
//      MainFrame *mf;
      public slots:
         void newSocket();
      //   void makeNewConnection();
        void socketDisconnected();

      void clientReturn(QString);
      void replyWith(QString);

   private:
      QErrorMessage *errorMessageTcpClient;
      QTextStream out;


      int cnt_replied;


   protected:
      void incomingConnection(int socketID);
};




#endif
