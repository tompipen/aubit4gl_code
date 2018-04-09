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
#ifndef CONFWIN_H
#define CONFWIN_H

#include <QDialog>
#include <QLineEdit>

#include <QLabel>
#include <QErrorMessage>


/*
class QLabel;
class QErrorMessage;
class QLineEdit;
*/
struct ShortcutsQS{
   QString qs_Username,
           qs_Password,
	   qs_Application,
	   qs_Protocol,
	   qs_IPadress,
      qs_hostIP;
};


class ConfWin : public QDialog
{
   // required for slot and signal using
   //
   Q_OBJECT   


public:

   //fdinfo: ueberladen, weil einmal soll er werte anzeigen zum editieren...
   //        und einmal keine, zum neu anlegen....!
   //
   //        - mal versuchen die LineEdits als classmember zu definieren
   //          das sollte diesen ueberladenen constructor hinfaellig machen.
   ConfWin(const QString &fname, QWidget *parent = 0);
   ConfWin(QWidget *parent = 0);

   ShortcutsQS u_Shortcuts;

private slots:

   void changedUsername(const QString &);
   void changedPassword(const QString &);
   void changedServer(const QString &);
   void changedHost(const QString &);
   void changedApplication(const QString &);
   void changedProtocol(const QString &);

   void saveEdits();

private:

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
   QLabel *protocolLabel;

   QLineEdit *usernameLineEdit;
   QLineEdit *passwordLineEdit;
   QLineEdit *serverLineEdit;
   QLineEdit *hostLineEdit;
   QLineEdit *applicationLineEdit;
   QLineEdit *protocolLineEdit;

   QErrorMessage *errorMessageConfWin;

   void readEditFile(QString);
   void writeFile(QString);
   bool b_savefile;

   QString qs_openFilename;
};

#endif

