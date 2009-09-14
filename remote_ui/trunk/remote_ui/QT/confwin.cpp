//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// File name    : confwin.cpp
// Description  : contains the confwin class logic
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
#include <QPushButton>
#include <QHBoxLayout>
#include <QSettings>
#include "confwin.h"


//------------------------------------------------------------------------------
// Method       : ConfWin()
// Filename     : confwin.cpp
// Description  : constructor for the instances
//                ConfWin represents the shortcuts configure window
//------------------------------------------------------------------------------

ConfWin::ConfWin(QWidget *parent)
    : QDialog(parent)
{
   b_savefile=false;

   errorMessageConfWin = new QErrorMessage(this);

   // instantiating labels and line edits - facilitating user input
   // labels should be filled by text-variables - later
   //
   usernameLabel       = new QLabel(tr("Username:"));
   usernameLineEdit    = new QLineEdit;
   setFocusProxy(usernameLineEdit);

   passwordLabel       = new QLabel(tr("Password"));
   passwordLineEdit    = new QLineEdit;
   passwordLineEdit->setEchoMode(QLineEdit::Password);

   serverLabel         = new QLabel(tr("Server"));
   serverLineEdit      = new QLineEdit;

   applicationLabel    = new QLabel(tr("Application"));
   applicationLineEdit = new QLineEdit;

   // instantiating the buttons
   //
   QPushButton *okButton     = new QPushButton(tr("OK"));
   QPushButton *cancelButton = new QPushButton(tr("Cancel"));

   // functionalize the buttons by using connect
   // accept and reject are predefined by qt, so we can use them
   // without declaration
   //
   connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
   connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

   // setup the buttons layout for the form / widget
   //
   QHBoxLayout *buttonLayout = new QHBoxLayout;
   buttonLayout->addStretch(1);
   buttonLayout->addWidget(okButton);
   buttonLayout->addWidget(cancelButton);

   // setup the labels layout for the form / widget
   //
   QVBoxLayout *confwinLayout = new QVBoxLayout;
   confwinLayout->addWidget(usernameLabel);
   confwinLayout->addWidget(usernameLineEdit);
   confwinLayout->addWidget(passwordLabel);
   confwinLayout->addWidget(passwordLineEdit);
   confwinLayout->addWidget(serverLabel);
   confwinLayout->addWidget(serverLineEdit);
   confwinLayout->addWidget(applicationLabel);
   confwinLayout->addWidget(applicationLineEdit);
   confwinLayout->addStretch(1);

   // putting buttons and line edits in one single layout
   //
   confwinLayout->addLayout(buttonLayout);

   // layout is ready for use, so we can set it.
   //
   setLayout(confwinLayout);

}


//------------------------------------------------------------------------------
// Method       : ConfWin()
// Filename     : confwin.cpp
// Description  : constructor for the instances
//------------------------------------------------------------------------------

ConfWin::ConfWin(const QString &fname, QWidget *parent)
    : QDialog(parent)
{
   b_savefile=true;
   qs_openFilename = fname;
   errorMessageConfWin = new QErrorMessage(this);

   readEditFile(qs_openFilename);

   topLabel = new QLabel(tr("<center><b>Add/Edit Shortcuts</b></center>"));
   topLabel->setWordWrap(false);

   usernameLabel = new QLabel(tr("Username:"));
   usernameLineEdit = new QLineEdit;
   usernameLabel->setBuddy(usernameLineEdit);
   usernameLineEdit->setText(u_Shortcuts.qs_Username);
   setFocusProxy(usernameLineEdit);

   passwordLabel = new QLabel(tr("Password"));
   passwordLineEdit = new QLineEdit;
   passwordLabel->setBuddy(passwordLineEdit);
   passwordLineEdit->setEchoMode(QLineEdit::Password);
   passwordLineEdit->setText(u_Shortcuts.qs_Password);

   serverLabel = new QLabel(tr("Server"));
   serverLineEdit = new QLineEdit;
   serverLineEdit->setText(u_Shortcuts.qs_IPadress);

   hostLabel = new QLabel(tr("Host"));
   hostLineEdit = new QLineEdit;
   hostLineEdit->setText(u_Shortcuts.qs_hostIP);

   applicationLabel = new QLabel(tr("Application"));
   applicationLineEdit = new QLineEdit;
   applicationLabel->setBuddy(passwordLineEdit);
   applicationLineEdit->setText(u_Shortcuts.qs_Application);

   protocolLabel = new QLabel(tr("Protocol"));
   protocolLineEdit = new QLineEdit;
   protocolLabel->setBuddy(passwordLineEdit);
   protocolLineEdit->setText(u_Shortcuts.qs_Protocol);

   QPushButton *okButton = new QPushButton(tr("OK"));
   QPushButton *cancelButton = new QPushButton(tr("Cancel"));

   connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
   connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

   connect(this, SIGNAL(accepted()), this, SLOT(saveEdits()));


   connect(usernameLineEdit, SIGNAL(textChanged(const QString &)),
           this, SLOT(changedUsername(const QString &)));

   connect(passwordLineEdit, SIGNAL(textChanged(const QString &)),
           this, SLOT(changedPassword(const QString &)));

   connect(serverLineEdit, SIGNAL(textChanged(const QString &)),
           this, SLOT(changedServer(const QString &)));

   connect(hostLineEdit, SIGNAL(textChanged(const QString &)),
           this, SLOT(changedHost(const QString &)));

   connect(applicationLineEdit, SIGNAL(textChanged(const QString &)),
           this, SLOT(changedApplication(const QString &)));

   connect(protocolLineEdit, SIGNAL(textChanged(const QString &)),
           this, SLOT(changedProtocol(const QString &)));


   QHBoxLayout *buttonLayout = new QHBoxLayout;
   buttonLayout->addStretch(1);
   buttonLayout->addWidget(okButton);
   buttonLayout->addWidget(cancelButton);

   QVBoxLayout *confwinLayout = new QVBoxLayout;
   confwinLayout->addWidget(usernameLabel);
   confwinLayout->addWidget(usernameLineEdit);
   confwinLayout->addWidget(passwordLabel);
   confwinLayout->addWidget(passwordLineEdit);
   confwinLayout->addWidget(serverLabel);
   confwinLayout->addWidget(serverLineEdit);
   confwinLayout->addWidget(applicationLabel);
   confwinLayout->addWidget(applicationLineEdit);
   confwinLayout->addStretch(1);
   confwinLayout->addLayout(buttonLayout);

   setLayout(confwinLayout);

   setWindowTitle(tr("Add/Edit Shortcut"));
}


//------------------------------------------------------------------------------
// Method       : void writeFile()
// Filename     : confwin.cpp
// Description  : opens a File for binary writing
//------------------------------------------------------------------------------

void ConfWin::writeFile(QString qs_filename)
{
   // instantiating from class QFile to handle a data stream
   //
   QFile file(qs_filename);

   // open the file for next procedure
   //
   if (!file.open(QIODevice::WriteOnly)){

       errorMessageConfWin->showMessage(
                 tr("Error: Cannot open File for writing"));
   }else{

       // write the data out to file
       //
       QDataStream out(&file);
       out.setVersion(QDataStream::Qt_4_1);



       out << quint32(0x12345678) << u_Shortcuts.qs_Username
                                  << u_Shortcuts.qs_Password
                                  << u_Shortcuts.qs_Application
                                  << u_Shortcuts.qs_Protocol
                                  << u_Shortcuts.qs_IPadress
                                  << u_Shortcuts.qs_hostIP;

       QSettings settings("shortcuts.ini", QSettings::IniFormat, this);
       settings.beginGroup(qs_filename);
       settings.setValue("user", u_Shortcuts.qs_Username);
       settings.setValue("passwd", u_Shortcuts.qs_Password);
       settings.setValue("application", u_Shortcuts.qs_Application);
       settings.setValue("protocol", u_Shortcuts.qs_Protocol);
       settings.setValue("ip-adress", u_Shortcuts.qs_IPadress);
       settings.setValue("host-ip", u_Shortcuts.qs_hostIP);
       settings.endGroup();
       settings.sync();

   }
}


//------------------------------------------------------------------------------
// Method       : void readEditFile()
// Filename     : confwin.cpp
// Description  : opens a File for binary reading
//------------------------------------------------------------------------------

void ConfWin::readEditFile(QString fname)
{
   quint32 n;
   QFile file(fname);

   // open the file for next procedure
   //
   if (!file.open(QIODevice::ReadOnly)){
    }else{
       QDataStream in(&file);
       in.setVersion(QDataStream::Qt_4_1);

       // it's recommanded to use qt data-types for streaming data in. 
       // e.g. QString
       //
       in >> n >> u_Shortcuts.qs_Username
               >> u_Shortcuts.qs_Password
               >> u_Shortcuts.qs_Application
               >> u_Shortcuts.qs_Protocol
               >> u_Shortcuts.qs_IPadress
               >> u_Shortcuts.qs_hostIP;

       QSettings settings("shortcuts.ini", QSettings::IniFormat, this);
       settings.beginGroup(fname);
       settings.setValue("user", u_Shortcuts.qs_Username);
       settings.setValue("passwd", u_Shortcuts.qs_Password);
       settings.setValue("application", u_Shortcuts.qs_Application);
       settings.setValue("protocol", u_Shortcuts.qs_Protocol);
       settings.setValue("ip-adress", u_Shortcuts.qs_IPadress);
       settings.setValue("host-ip", u_Shortcuts.qs_hostIP);
       settings.endGroup();
       settings.sync();

   }
}


//------------------------------------------------------------------------------
// Method       : void changedUsername()
// Filename     : confwin.cpp
// Description  : undertake the changes
//------------------------------------------------------------------------------

void ConfWin::changedUsername(const QString &uname){
   u_Shortcuts.qs_Username = uname;
   b_savefile = true;
}


//------------------------------------------------------------------------------
// Method       : void changedPassword()
// Filename     : confwin.cpp
// Description  : undertake the changes
//------------------------------------------------------------------------------

void ConfWin::changedPassword(const QString &pword){
   u_Shortcuts.qs_Password = pword;
   b_savefile = true;
}


//------------------------------------------------------------------------------
// Method       : void changedHost()
// Filename     : confwin.cpp
// Description  : undertake the changes
//------------------------------------------------------------------------------

void ConfWin::changedHost(const QString &sname){
   u_Shortcuts.qs_hostIP = sname;
   b_savefile = true;
}


//------------------------------------------------------------------------------
// Method       : void changedServer()
// Filename     : confwin.cpp
// Description  : undertake the changes
//------------------------------------------------------------------------------

void ConfWin::changedServer(const QString &sname){
   u_Shortcuts.qs_IPadress = sname;
   b_savefile = true;
}


//------------------------------------------------------------------------------
// Method       : void changedApplication()
// Filename     : confwin.cpp
// Description  : undertake the changes
//------------------------------------------------------------------------------

void ConfWin::changedApplication(const QString &aname){
   u_Shortcuts.qs_Application = aname;
   b_savefile = true;
}


//------------------------------------------------------------------------------
// Method       : void changedProtocol()
// Filename     : confwin.cpp
// Description  : undertake the changes
//------------------------------------------------------------------------------

void ConfWin::changedProtocol(const QString &prot){
   u_Shortcuts.qs_Protocol = prot;
   b_savefile = true;
}


//------------------------------------------------------------------------------
// Method       : void saveEdits()
// Filename     : confwin.cpp
// Description  : write the changed data back to file
//------------------------------------------------------------------------------

void ConfWin::saveEdits(){
   if(b_savefile){
      writeFile(qs_openFilename);
      b_savefile = false;	
   }
}


