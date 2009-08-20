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
   HostsData *hosts = new HostsData(this);
   hosts->show();
}
//Hosts Settings
HostsData::HostsData(QWidget *parent) : QDialog(parent)
{
       hostspath = checkOS();

       QLabel *description = new QLabel(tr("<h2>Host Data</h2> <br> <b>CAUTION :</b> Be sure that you login as Admin/root <br> otherwise you can't edit these Settings"));
       QVBoxLayout *mainLayout = new QVBoxLayout;
       hostsTable = new QTableWidget(this);
       QStringList labels;
       labels << tr("IP-Adress") << tr("Host-Name") << tr("Comments");
       hostsTable->setColumnCount(3);
       hostsTable->setHorizontalHeaderLabels(labels);
       hostsTable->verticalHeader()->hide();
       hostsTable->setShowGrid(false);
       hostsTable->resizeColumnsToContents();
       hostsTable->horizontalHeader()->setStretchLastSection(true);
readHost();

       QPushButton *addButton = new QPushButton(tr("Add Host"));
       QPushButton *saveButton = new QPushButton(tr("Save Hosts Data"));
       connect(addButton, SIGNAL(clicked()), this, SLOT(addHost()));
       connect(saveButton, SIGNAL(clicked()), this, SLOT(saveHost()));
       mainLayout->addWidget(description);
       mainLayout->addWidget(hostsTable);
       mainLayout->addWidget(addButton);
       mainLayout->addWidget(saveButton);
       setLayout(mainLayout);
       setWindowTitle(tr("VDC - Hosts Settings"));
       move(QCursor::pos());
       show();

}

QString HostsData::checkOS()
{

   QString pfad;

   #ifdef Q_WS_WIN
   int windows = QSysInfo::WindowsVersion;
   if (windows > 15 && windows < 159)
      {
        QStringList system = QProcess::systemEnvironment();
        pfad = system.filter("SYSTEMROOT").at(0).split("=").at(1);
        pfad += "\\system32\\drivers\\etc\\hosts";
      }
   if (windows > 1 && windows < 15)
      {
        QStringList system = QProcess::systemEnvironment();
        pfad = system.filter("WINDIR").at(0).split("=").at(1);
        pfad += "\\hosts";
      }
   #endif

   #ifdef Q_WS_MAC
   pfad = "/private/etc/hosts";
   #endif

   #ifdef Q_WS_X11
   pfad = "/etc/hosts";
   #endif



    return pfad;
  }


void HostsData::readHost()
{
     QFile file(hostspath);
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

                   feld += line.at(i);
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
             if(j == 0 && feld.startsWith("#"))
             {
               hostsTable->hideRow(i);
             }

                             }

     }
     check2 = 0;
 }
  file.close();
}

void HostsData::saveHost()
{
   QFile file(hostspath);
   if (!file.open(QIODevice::WriteOnly))
   return;

  QTextStream stream(&file);
  for(int i=0; i < hostsTable->rowCount();i++)
  {
      for(int j=0; j < hostsTable->columnCount();j++)
      {
         QTableWidgetItem *item = hostsTable->item(i,j);
         if(item != NULL && item->text() != " " && !item->text().isNull() && !item->text().isEmpty())
         {
            QString txt = item->text();
            stream << txt << " ";
         }
        }
//      QTableWidgetItem *item = hostsTable->item(i,0);
//      if(item != NULL || item->text() != " " || item->text().isNull() || item->text().isEmpty())
//      {
        stream << "\n";
//     }
     }

           file.close();
           readHost();
  }


void HostsData::addHost()
{
        QDialog *hostsAdd = new QDialog(this);
        QVBoxLayout *mainLayoutAdd = new QVBoxLayout;
        QHBoxLayout *ipfeld = new QHBoxLayout;
        QHBoxLayout *ipfeldv4 = new QHBoxLayout;
        QHBoxLayout *ipfeldv6 = new QHBoxLayout;
        QHBoxLayout *select = new QHBoxLayout;
        QRadioButton *radioipv4 = new QRadioButton("Select IPv4", this);
        QRadioButton *radioipv6 = new QRadioButton("Select IPv6", this);
        QLabel *iplabel = new QLabel(tr("IP-Address :"));
        QLabel *hostnamelabel = new QLabel(tr("Hostnames :"));
        QLabel *commentlabel = new QLabel(tr("Comments :"));
        ipv4 = new QWidget(this);
        ipv6 = new QWidget(this);
        ipv4->setLayout(ipfeldv4);
        ipv6->setLayout(ipfeldv6);
        radioipv4->setChecked(true);
        firstip = new QLineEdit;
        seccondip = new QLineEdit;
        thirdip = new QLineEdit;
        fourthip = new QLineEdit;
        hostnames = new QLineEdit;
        comments = new QLineEdit;
        firstipv6 = new QLineEdit;
        seccondipv6 = new QLineEdit;
        thirdipv6 = new QLineEdit;
        fourthipv6 = new QLineEdit;
        fifthipv6 = new QLineEdit;
        sixthipv6 = new QLineEdit;
        seventhipv6 = new QLineEdit;
        eighthipv6 = new QLineEdit;
        ipfeld->addWidget(ipv4);
        ipfeld->addWidget(ipv6);

        QRegExp regExpv4("25[0-4]|2[0-4][0-9]|[01]?[0-9][0-9]");
        QRegExp regExpv6("[0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F]");
        firstip->setValidator(new QRegExpValidator(regExpv4, this));
        seccondip->setValidator(new QRegExpValidator(regExpv4, this));
        thirdip->setValidator(new QRegExpValidator(regExpv4, this));
        fourthip->setValidator(new QRegExpValidator(regExpv4, this));
        firstipv6->setValidator(new QRegExpValidator(regExpv6, this));
        seccondipv6->setValidator(new QRegExpValidator(regExpv6, this));
        thirdipv6->setValidator(new QRegExpValidator(regExpv6, this));
        fourthipv6->setValidator(new QRegExpValidator(regExpv6, this));
        fifthipv6->setValidator(new QRegExpValidator(regExpv6, this));
        sixthipv6->setValidator(new QRegExpValidator(regExpv6, this));
        seventhipv6->setValidator(new QRegExpValidator(regExpv6, this));
        eighthipv6->setValidator(new QRegExpValidator(regExpv6, this));
        QPushButton *add = new QPushButton(tr("Add Host"), hostsAdd);
        select->addWidget(radioipv4);
        select->addWidget(radioipv6);

        mainLayoutAdd->addLayout(select);
        connect(radioipv4,SIGNAL(clicked()), this, SLOT(checkipv4()));
        connect(radioipv6,SIGNAL(clicked()), this, SLOT(checkipv6()));
        mainLayoutAdd->addWidget(iplabel);

        //ipfeldv4

        ipfeldv4->addWidget(firstip);
        ipfeldv4->addWidget(new QLabel(tr("<b>.</b>")));
        ipfeldv4->addWidget(seccondip);
        ipfeldv4->addWidget(new QLabel(tr("<b>.</b>")));
        ipfeldv4->addWidget(thirdip);
        ipfeldv4->addWidget(new QLabel(tr("<b>.</b>")));
        ipfeldv4->addWidget(fourthip);

        //ipfeldv6

        ipfeldv6->addWidget(firstipv6);
        ipfeldv6->addWidget(new QLabel(tr("<b>:</b>")));
        ipfeldv6->addWidget(seccondipv6);
        ipfeldv6->addWidget(new QLabel(tr("<b>:</b>")));
        ipfeldv6->addWidget(thirdipv6);
        ipfeldv6->addWidget(new QLabel(tr("<b>:</b>")));
        ipfeldv6->addWidget(fourthipv6);
        ipfeldv6->addWidget(new QLabel(tr("<b>:</b>")));
        ipfeldv6->addWidget(fifthipv6);
        ipfeldv6->addWidget(new QLabel(tr("<b>:</b>")));
        ipfeldv6->addWidget(sixthipv6);
        ipfeldv6->addWidget(new QLabel(tr("<b>:</b>")));
        ipfeldv6->addWidget(seventhipv6);
        ipfeldv6->addWidget(new QLabel(tr("<b>:</b>")));
        ipfeldv6->addWidget(eighthipv6);


        checkipv4();

        mainLayoutAdd->addLayout(ipfeld);
        mainLayoutAdd->addWidget(hostnamelabel);
        mainLayoutAdd->addWidget(hostnames);
        mainLayoutAdd->addWidget(commentlabel);
        mainLayoutAdd->addWidget(comments);
        mainLayoutAdd->addWidget(add);
        connect(add, SIGNAL(clicked()), this, SLOT(writeHost()));
        hostsAdd->setLayout(mainLayoutAdd);
        hostsAdd->setWindowTitle(tr("VDC - Add Host"));
        hostsAdd->move(QCursor::pos());
        hostsAdd->show();
}

void HostsData::checkipv6()
{
ipcheck = false;
ipv4->hide();
ipv6->show();
    }

void HostsData::checkipv4()
{
ipcheck = true;
ipv6->hide();
ipv4->show();
}

void HostsData::writeHost()
{
   QString entry;
   QFile file(hostspath);
   if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
   return;
  entry += "\n";
  if(ipcheck == true)
  {
  entry += firstip->text();
  entry +=  ".";
  entry += seccondip->text();
  entry +=  ".";
  entry += thirdip->text();
  entry += ".";
  entry += fourthip->text();
}
  if(ipcheck == false)
  {
  entry += firstipv6->text();
  entry +=  ":";
  entry += seccondipv6->text();
  entry +=  ":";
  entry += thirdipv6->text();
  entry +=  ":";
  entry += fourthipv6->text();
  entry +=  ":";
  entry += fifthipv6->text();
  entry +=  ":";
  entry += sixthipv6->text();
  entry +=  ":";
  entry += seventhipv6->text();
  entry +=  ":";
  entry += eighthipv6->text();
}
  entry += "  ";
  entry += hostnames->text();
  entry += "  ";
  entry += "#";
  entry += comments->text();
  QTextStream stream(&file);
  stream << entry;
  QDialog *dia = (QDialog*) QObject::sender()->parent();
  file.close();
  readHost();
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
