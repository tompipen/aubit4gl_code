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
#include <QMutex>
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

      void append(QString text) { edit->append(text); }

    public slots:
      void debugOut(QString);
      void forwardsearch();
      void clear();
      void backwardsearch();
      void closeEvent(QCloseEvent *event);
      void showEvent(QShowEvent *ev);
    signals:
      void debugClose();
    private:
      QString xml;

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
   QHash<int,ScreenHandler*> qh_screenhandler;
   ScreenHandler *p_currScreenHandler;
   QString qs_shortCutUser;
   QString qs_shortCutPass;
   QString qs_shortCutProgram;
   QString fileName;
   bool b_read;
   QString qs_dblocale;
   QMutex protocol_mutex;

   bool b_write;
   int pid;
   int id;
   QThread *t_tunnel;

private:
   int openFileSuccess;
   QString decodeFile(QString);
   void outputTree(QDomNode);
   void executeFile(int,QString);
   QString encodeXMLFile(QString);
   void handleStartup(const QDomNode&);
   void handleDisplayAtElement(const QDomNode&);
   void handleDisplayToElement(const QDomNode&, QString parentNodeName = "");
   void handleDisplayArrayElement(const QDomNode&, QString parentNodeName = "");
   void clearDisplayArray(const QDomNode&, QString parentNodeName = "");
   void handleInputElement(const QDomNode&, int attribute = 0);
   void handleConstructElement(const QDomNode&);
   void handleWaitForEventElement(const QDomNode&);
   void handleMenuElement(const QDomNode&);
   void handleEventsElement(const QDomNode&);
   bool sendFile(QString name);
   bool saveFile(const QDomNode&, QString fileName = "");
   QString hexToString(QString);
   QString filterUmlauts(QString);

   QString getVentasLogicalIndex(int, QString);

   QStringList qsl_fieldList, qsl_arrayTabNames, qsl_arrayValues, qsl_receivedFiles;


signals:
   void makeResponse(QString);
   void setUpdatesEnabled(bool);
   void createBrowser();
   void setUrl(int, const QUrl);
   void closeBrowser(int);
   void openChartWindow(QString);

   // ProtocolHandler -> ScreenHandler (WorkerThread -> GuiThread)
   void setOptions(QString, QString);
   void createWindow(QString, QString, int, int, int, int, QString,QString);
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

   void printpdf(QString);


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
   void handleXMLColors(QString);


   void clearDisplayArrayRows(QStringList);
   void setFieldBuffer(QStringList, QStringList, int);
   void setFieldBuffer(int, QString, int);
   void setArrayBuffer(int, QString, QStringList);
   void setArrayBuffer(int, QStringList);
   void clearFieldBuffer(QString);
   void setFieldEnabled(QString, bool, bool, int);
   void setFieldFocus(QString);
   void setNewTabName(QString, QString);
   void setAttributes(QString, QString, QString);
   void setFieldHidden(QString, bool);
   void setElementHidden(QString, bool);
   void setRuninfo(int, QString, int, bool);
   void setScreenRecordEnabled(QString,bool, bool);
   void loadArrayValues(QStringList, QStringList);
   void loadArrayValues(QStringList);
   void setArrLine(int);
   void setScrLine(int);
   void setFieldOrder(QStringList);
   void setEvent(QString, QString, QString);

   void setFormOpts(QString, bool, int);
   void setFormOpts(QString, QString, int);

   void waitForEvent();
   void free(QString);
   void MsgBox(QString,QString,QString,QString,QString,int);
   void closeWindow(QString);
   void activeWindow(QString);
   void fileBrowser(QString, QString, QString, QString, QString);

   void fornameComboBox(QString);
   void getColumnNameComboBox(int);
   void clearComboBox(int);
   void addComboBoxItem(int, QString, QString);
   void removeComboBoxItem(int, QString);
   void getItemNameComboBox(int, int);
   void getItemCountComboBox(int);
   void getItemTextComboBox(int, int);
   void getTableNameComboBox(int);
   void getIndexOfComboBox(int, QString);
   void createStdProgWindow();

   #ifdef KDChart_Version
   void createGantt();
   void setGanttTitle(int, const QString);
   void ganttReadCsv(int, QString);
   #endif

   void checkForUpdate();


   //ui.progress
   void setProgressTitle(int, QString);
   void setProgressText(int, QString);
   void setProgressVisible(int, bool);
   void createProgressWindow();
   void closeProgressWindow(int);

public slots:
   void fglFormResponse(QString);
   void closeAllScreenHandler();

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
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
      void incomingConnection(int socketID);
#else
      void incomingConnection(qintptr socketID);
#endif
};

class ExecuteFile : public QThread {
    public:
        void run();
        void setFileName(QString name ) { fileName = name; };
        void setHashSum();
 
    private:
        int exitStatus;
        QString fileName;
        int exitCode;
        QString md5Hash;
};


#endif
