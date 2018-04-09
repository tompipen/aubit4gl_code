//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : confwin.h
// Description  : contains the confwin class definition
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
#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLineEdit>

#include <QLabel>
#include <QErrorMessage>
#include <QRadioButton>
#include <QTableWidget>

#include "clienttcp.h"
#include "qtelnet/qttelnet.h"
#include "ventasupdate.h"


class LoginForm  : public QWidget
{
   // required for slot and signal using
   //
   Q_OBJECT   


public:

   LoginForm(QWidget *parent = 0);
   void createMenu(QMenuBar*);
   QString getUserName() { return usernameLineEdit->text(); }
   QString getPassword() { return passwordLineEdit->text(); }
   QString getServer() { return serverLineEdit->text(); }
   QLineEdit *fontedit;
   QString fontconv;
   QStringList splitlist;
   QString fonteingabe;
   QtTelnet *tn;
   QMenu *admin;
   QAction *toggledebug;


public slots:
   void saveCompression(int);
   void openCompOptions();
   void compression();
   void aboutVDC(QWidget *parent = 0);
   void convertTextToIso();
   void removeIni();
   void saveSettingsOnServer();
   void setAutoUpdate();
   void setRememberMenu();
   void clearIniFile();
   void setFormat(QString);
   void font();
   void setFactorWidth(QString);
   void resetFactor();
   void showMessage(QString m);
   void hosts();
   void welcomeBar();
   void connectToTelnet();
   void debugToggle(bool checked);
   void debugCheck();
   void disableApp();
   void enableApp();
   #ifdef SSH_USE
   void authfailed(int,QString);
   void connectionfailed(int, QString);
   void commandfailed(int, QString);
   #endif
   void error(QString);
   void checkForUpdate();
   void showUpdateError();
   void setMainMenu();
   void setOfficeInstallation();
   void saveOfficeInstallation();
   void showDocumentation();
   void sendMessageToVentas();
   void removeMessageWaitTimer();
   void readMessageReply(QNetworkReply *reply);   
   void sendMessageWidget();
   void ventasMessageChanged();
   void openVdc2();
   void openQuickSupport();

private slots:
   void okPressed();
   //void cancelPressed();
   void saveEdits();
   void showLogin();
   void hideLogin();
   void closeVDC();
#ifdef SSH_USE
   void m_c_success();
   void m_c_established();
   void m_c_executed(QString cmd);
   void m_c_envset();
#endif
   void removeCursor();


private:

   QComboBox *mOfficeComboBox;
   QCheckBox *compCb;

   //Progressbar for Update GUI

   QProgressBar *m_progress;
   QLabel *m_label;

   QList<ClientSocket*> ql_connections;
   QAction *m_mainMenu;

   QLabel *textLabel;
   QLabel *criticalLabel;
   QLabel *informationLabel;
   QLabel *questionLabel;
   QLabel *warningLabel;
   QLabel *errorLabel;
   QLabel *topLabel;
   QLabel *usernameLabel;
   QLabel *passwordLabel;
   QLabel *serverLabel;
   QLabel *hostLabel;
   QLabel *applicationLabel;
   QLabel *portLabel;
   QLabel *protocolLabel;
   QGroupBox *bg_connection;
   QRadioButton *rb_proxy;
   QRadioButton *rb_telnet;
   #ifdef SSH_USE
   QRadioButton *rb_ssh;
   #endif
   QLineEdit *usernameLineEdit;
   QLineEdit *passwordLineEdit;
   QLineEdit *serverLineEdit;
   QLineEdit *hostLineEdit;
   QLineEdit *applicationLineEdit;
   QLineEdit *portLineEdit;
   QLineEdit *protocolLineEdit;
   QCheckBox *cb;
   QCheckBox *logVDC;
   QErrorMessage *errorMessageLoginForm;

   QAction *format1;
   QAction *format2;
   QAction *format3;
   QAction *format4;

   QAction *settingsServer;
   QAction *autoUpdateAction;
   QAction *rememberMenuAction;
   QAction *convertText;
   void readEditFile(QString);
   void writeFile(QString);
   bool b_savefile;

   QString qs_openFilename;
   void loadSettings();

   bool waitToSendMessage;
   QTextEdit *ventasMessage;

};

class HostsData  : public QDialog
{
   // required for slot and signal using
   //
   Q_OBJECT
public:
   HostsData(QWidget *parent = 0);
   QLineEdit *firstip;
   QLineEdit *seccondip;
   QLineEdit *thirdip;
   QLineEdit *fourthip;
   QString hostspath;
   QLineEdit *firstipv6;
   QLineEdit *seccondipv6;
   QLineEdit *thirdipv6;
   QLineEdit *fourthipv6;
   QLineEdit *fifthipv6;
   QLineEdit *sixthipv6;
   QLineEdit *seventhipv6;
   QLineEdit *eighthipv6;
   QVBoxLayout *ipfeldlayout;
   QHBoxLayout *ipfeldv4;
   QVBoxLayout *ipfeldv6;
   QLineEdit *hostnames;
   QLineEdit *comments;
   QTableWidget *hostsTable;
   QWidget *ipv4;
   QWidget *ipv6;
   bool ipcheck;

public slots:
   void addHost();
   void writeHost();
   void readHost();
   void saveHost();
   void checkipv4();
   void checkipv6();
   QString checkOS();
};

#endif

