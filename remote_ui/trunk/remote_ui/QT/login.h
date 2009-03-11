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

#include "clienttcp.h"


class LoginForm : public QWidget
{
   // required for slot and signal using
   //
   Q_OBJECT   


public:

   LoginForm(QWidget *parent = 0);

private slots:

   void okPressed();
   void cancelPressed();
   void saveEdits();
   void showLogin();
   void hideLogin();

private:

   QList<ClientSocket*> ql_connections;

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

   QErrorMessage *errorMessageLoginForm;

   void readEditFile(QString);
   void writeFile(QString);
   bool b_savefile;

   QString qs_openFilename;
   void loadSettings();
};

#endif

