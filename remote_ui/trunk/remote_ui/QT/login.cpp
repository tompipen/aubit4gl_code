//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// File name    : login.cpp
// Description  : contains login class logic
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
#include <QSystemTrayIcon>
#include <QIcon>
#include <QMenu>
#include <QAction>
#include "login.h"
#include "mainframe.h"


//------------------------------------------------------------------------------
// Method       : LoginForm()
// Filename     : login.cpp
// Description  : constructor for the instances
//                LoginForm represents the shortcuts configure window
//------------------------------------------------------------------------------

LoginForm::LoginForm(QWidget *parent)
    : QWidget(parent)
{
   MainFrame *mainFrame = (MainFrame*) parent;
   bool adminMenu = mainFrame->adminMenu;
   QStatusBar *statusBar = mainFrame->statusBar();
   statusBar->showMessage("Welcome!", 2000);

    QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
   trayIcon->setIcon(QIcon("./pics/ventas.ico"));

   QMenu *menu = new QMenu;
   QAction *showAction = menu->addAction("Show Login Window");
   connect(showAction, SIGNAL(triggered()), this, SLOT(showLogin()));
   QAction *hideAction = menu->addAction("Hide Login Window");
   connect(hideAction, SIGNAL(triggered()), this, SLOT(hideLogin()));
   QAction *exitAction = menu->addAction("Exit");
   connect(exitAction, SIGNAL(triggered()), this, SLOT(cancelPressed()));

   trayIcon->setContextMenu(menu);

   trayIcon->show();

   b_savefile=false;

   errorMessageLoginForm = new QErrorMessage(this);

   // MenuBar

   QMenuBar *menuBar = new QMenuBar;
   QAction *option = new QAction(tr("&Option"), this);
   QMenu *admin = new QMenu(tr("&Admin"), this);
   QAction *hosts = new QAction(tr("&Hosts"), this);
   option->setStatusTip(tr("Opens the Option Window"));
   hosts->setStatusTip(tr("Opens the Hosts Data Settings"));
   admin->setStatusTip(tr("Opens the Hosts Data Settings"));
   connect(option, SIGNAL(triggered()), this, SLOT(option()));
   menuBar->addAction(option);

   if (adminMenu == true)
   {
   statusBar->showMessage("Login Screen started in Admin Mode", 3000);
   QTimer *timer = new QTimer(this);
   connect(timer, SIGNAL(timeout()), this, SLOT(welcomeBar()));
   timer->start(3000);
   menuBar->addMenu(admin);
   admin->addAction(hosts);
   connect(hosts, SIGNAL(triggered()), this, SLOT(hosts()));
   }

   // instantiating labels and line edits - facilitating user input
   // labels should be filled by text-variables - later
   //
   usernameLabel       = new QLabel(tr("Username:"));
   usernameLineEdit    = new QLineEdit;
   setFocusProxy(usernameLineEdit);

   passwordLabel       = new QLabel(tr("Password:"));
   passwordLineEdit    = new QLineEdit;
   passwordLineEdit->setEchoMode(QLineEdit::Password);

   serverLabel         = new QLabel(tr("Server:"));
   serverLineEdit      = new QLineEdit;

   applicationLabel    = new QLabel(tr("Application"));
   applicationLineEdit = new QLineEdit;
   applicationLineEdit->setText("p_master");

   loadSettings();

   // instantiating the buttons
   //
   QPushButton *okButton     = new QPushButton(tr("OK"));
   QPushButton *cancelButton = new QPushButton(tr("Cancel"));

   // functionalize the buttons by using connect
   // accept and reject are predefined by qt, so we can use them
   // without declaration
   //
   connect(okButton, SIGNAL(clicked()), this, SLOT(okPressed()));
   connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelPressed()));

   // setup the buttons layout for the form / widget
   //
   QHBoxLayout *buttonLayout = new QHBoxLayout;

   buttonLayout->addWidget(okButton);
   buttonLayout->addStretch(1);
   buttonLayout->addWidget(cancelButton);

   // setup the labels layout for the form / widget
   //
   QVBoxLayout *loginLayout = new QVBoxLayout;
   loginLayout->setMenuBar(menuBar);
   loginLayout->addWidget(serverLabel);
   loginLayout->addWidget(serverLineEdit);
   loginLayout->addWidget(usernameLabel);
   loginLayout->addWidget(usernameLineEdit);
   loginLayout->addWidget(passwordLabel);
   loginLayout->addWidget(passwordLineEdit);
   loginLayout->addStretch(1);

   // putting buttons and line edits in one single layout
   //
   loginLayout->addLayout(buttonLayout);

   // layout is ready for use, so we can set it.
   //
   setLayout(loginLayout);

}

void LoginForm::welcomeBar()
{
showMessage("Welcome!");
}
//Hosts Settings
void LoginForm::hosts()
{
       QDialog *hostsDialog = new QDialog(this);
       QLabel *description = new QLabel(tr("Hosts Data"));
       QVBoxLayout *mainLayout = new QVBoxLayout;
       QTableWidget *hostsTable = new QTableWidget(this);
       QStringList labels;
       labels << tr("IP-Adress") << tr("Host-Name") << tr("Comments");
       hostsTable->setColumnCount(3);
       hostsTable->setHorizontalHeaderLabels(labels);
       hostsTable->verticalHeader()->hide();
       hostsTable->setShowGrid(false);
       hostsTable->resizeColumnsToContents();
       hostsTable->horizontalHeader()->setStretchLastSection(true);

       QFile file("/etc/hosts");
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         return;

     QTextStream in(&file);
     int rowcount = 0;
     QString feld;
     QStringList feldarray;
     QVector<QStringList> dateiarray;
     int feldcount = 0;
     while (!in.atEnd()) {
         QString line = in.readLine();

         for(int i=0; i<line.count(); i++){

             if(line.at(i).isSpace() || i+1 == line.count()){

                 if(i+1 == line.count())
                     feld += line.at(i);

                 if(!feld.isEmpty()){
                    feldarray.insert(feldcount,feld);
                    feldcount++;
                    feld.clear();
                 }
             }
             else{
                 if(line.at(i) == '#' && i == 0)
                 {
                  i=1000000;
                 }

                 else
                 {
                   feld += line.at(i);
                 }
             }

         }
         if(feldarray.count() > 0){

                 feldcount = 0;
                 dateiarray.insert(rowcount, feldarray);
                 rowcount++;
                 feldarray.clear();
         }
     }

hostsTable->setRowCount(rowcount);
QString addhost;
int check2 = 0;
for(int i=0; i < dateiarray.count(); i++)
{
     feldarray = dateiarray.at(i);
     for(int j=0; j<feldarray.count(); j++)
     {
         QString feld = feldarray.at(j);
         if (j > 1 && !feld.startsWith("#"))
         {
         check2--;

         addhost = hostsTable->item(i, check2)->text();
         addhost += "    ";
         addhost += feld;

         hostsTable->setItem(i ,check2, new QTableWidgetItem(addhost));
     check2++;
     }
         else
         {
             hostsTable->setItem(i, check2, new QTableWidgetItem(feld));
             check2++;

                             }

     }
     check2 = 0;
 }
       QPushButton *addButton = new QPushButton(tr("Add Host"));
       connect(addButton, SIGNAL(clicked()), this, SLOT(addHost()));
       mainLayout->addWidget(description);
       mainLayout->addWidget(hostsTable);
       mainLayout->addWidget(addButton);
       hostsDialog->setLayout(mainLayout);
       hostsDialog->setWindowTitle(tr("VDC - Hosts Settings"));
       hostsDialog->move(QCursor::pos());
       hostsDialog->show();

}

void LoginForm::addHost()
{
        QDialog *hostsAdd = new QDialog(this);
        QVBoxLayout *mainLayout = new QVBoxLayout;
        QHBoxLayout *ipfeld = new QHBoxLayout;
        firstip = new QLineEdit;
        seccondip = new QLineEdit;
        thirdip = new QLineEdit;
        fourthip = new QLineEdit;
        hostnames = new QLineEdit;
        comments = new QLineEdit;
        QPushButton *add = new QPushButton(tr("Add Host"), hostsAdd);


        ipfeld->addWidget(firstip);
        ipfeld->addWidget(new QLabel(tr("<b>.</b>")));
        ipfeld->addWidget(seccondip);
        ipfeld->addWidget(new QLabel(tr("<b>.</b>")));
        ipfeld->addWidget(thirdip);
        ipfeld->addWidget(new QLabel(tr("<b>.</b>")));
        ipfeld->addWidget(fourthip);
        mainLayout->addLayout(ipfeld);
        mainLayout->addWidget(hostnames);
        mainLayout->addWidget(comments);
        mainLayout->addWidget(add);
        connect(add, SIGNAL(clicked()), this, SLOT(writeHost()));
        hostsAdd->setLayout(mainLayout);
        hostsAdd->setWindowTitle(tr("VDC - Add Host"));
        hostsAdd->move(QCursor::pos());
        hostsAdd->show();
}

void LoginForm::writeHost()
{
   QString entry;
   QFile file("/etc/hosts");
   if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
   return;
  entry += "\n";
  entry += firstip->text();
  entry +=  ".";
  entry += seccondip->text();
  entry +=  ".";
  entry += thirdip->text();
  entry += ".";
  entry += fourthip->text();
  entry += "  ";
  entry += hostnames->text();
  entry += "  ";
  entry += "#";
  entry += comments->text();
  QTextStream stream(&file);
  stream << entry;
  QDialog *dia = (QDialog*) QObject::sender()->parent();
  dia->close();
}

void LoginForm::option()
{
       OptionsTab *optionsTab = new OptionsTab();
       connect(optionsTab, SIGNAL(showMessage(QString)), this, SLOT(showMessage(QString)));
       optionsTab->setWindowTitle(tr("VDC - Options"));

       optionsTab->move(QCursor::pos());
       optionsTab->show();


}

void LoginForm::showMessage(QString m)
{
   MainFrame *mf = (MainFrame*) this->parent();

   if(mf != NULL){
      mf->statusBar()->showMessage(m, 2000);
   }
}

//------------------------------------------------------------------------------
// Method       : void writeFile()
// Filename     : login.cpp
// Description  : opens a File for binary writing
//------------------------------------------------------------------------------

void LoginForm::writeFile(QString qs_filename)
{
   // instantiating from class QFile to handle a data stream
   //
   QFile file(qs_filename);

   // open the file for next procedure
   //
   if (!file.open(QIODevice::WriteOnly)){

       errorMessageLoginForm->showMessage(
                 tr("Error: Cannot open File for writing"));
   }else{

       // write the data out to file
       //
       QDataStream out(&file);
       out.setVersion(QDataStream::Qt_4_1);
   }
}


//------------------------------------------------------------------------------
// Method       : void readEditFile()
// Filename     : login.cpp
// Description  : opens a File for binary reading
//------------------------------------------------------------------------------

void LoginForm::readEditFile(QString fname)
{
   QFile file(fname);

   // open the file for next procedure
   //
   if (!file.open(QIODevice::ReadOnly)){
    }else{
       QDataStream in(&file);
       in.setVersion(QDataStream::Qt_4_1);
   }
}


//------------------------------------------------------------------------------
// Method       : void saveEdits()
// Filename     : login.cpp
// Description  : write the changed data back to file
//------------------------------------------------------------------------------

void LoginForm::saveEdits(){
   if(b_savefile){
      writeFile(qs_openFilename);
      b_savefile = false;	
   }
}

//------------------------------------------------------------------------------
// Method       : void okPressed()
// Filename     : login.cpp
// Description  : write the changed data back to file
//------------------------------------------------------------------------------
void LoginForm::okPressed()
{

   hideLogin();
   QSettings settings;
   QString server = serverLineEdit->text();
   QString user = usernameLineEdit->text();
   QString pass = passwordLineEdit->text();
   settings.setValue("server", server);
   settings.setValue("user", user);
   settings.setValue("password", pass);
   settings.sync();

   ClientSocket *socket = new ClientSocket(0, user, pass, applicationLineEdit->text());

   socket->connectToHost(server, 3490);
}

//------------------------------------------------------------------------------
// Method       : void cancelPressed()
// Filename     : login.cpp
// Description  : write the changed data back to file
//------------------------------------------------------------------------------
void LoginForm::cancelPressed()
{
   exit(0);
}

void LoginForm::showLogin()
{
   if(QWidget *mainWin = qobject_cast<QWidget *> (parent())){
      mainWin->setHidden(false);
   }
}

void LoginForm::hideLogin()
{
   if(QWidget *mainWin = qobject_cast<QWidget *> (parent())){
      mainWin->setHidden(true);
   }
}

void LoginForm::loadSettings()
{
   QSettings settings;
   QString server = settings.value("server").toString();
   QString user = settings.value("user").toString();
   QString pass = settings.value("password").toString();

   if(!server.isEmpty()){
      serverLineEdit->setText(server);
   }
   if(!user.isEmpty()){
      usernameLineEdit->setText(user);
   }
   if(!pass.isEmpty()){
      passwordLineEdit->setText(pass);
   }
}
