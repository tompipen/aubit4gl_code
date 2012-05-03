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
// If you need professional Support please3 contact us at www.ventas.de
// Enjoy using it!
//
//------------------------------------------------------------------------------
#include <QtGui>
#include <QFile>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QMenu>
#include <QAction>
#include <QLineEdit>
#include <QTcpSocket>
#include <qtelnet/qttelnet.h>
#if QT_VERSION >= 0x040600
#include <QProcessEnvironment>
#endif
#include "login.h"
#include "mainframe.h"
#include "include/vdc.h"
#ifdef SSH_USE
#include "vssh.h"
#endif

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

    QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
   trayIcon->setIcon(QIcon("pics:vdc.png"));

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

   QMenuBar *menuBar = mainFrame->menuBar(); //new QMenuBar(0);
   QAction *font = new QAction(tr("&Font"), this);
   QAction *feldplus = new QAction(tr("Fieldwidth + "), this);
   QAction *feldminus = new QAction(tr("Fieldwidth - "), this);
   QAction *feldreset = new QAction(tr("Default Fieldwidth"), this);
   QMenu *admin = new QMenu(tr("&Admin"), this);
   QAction *hosts = new QAction(tr("&Hosts"), this);
   QMenu *options = new QMenu(tr("&Options"), this);
   QAction *checkVersion = new QAction(tr("&Search for Update"), this);
   connect(checkVersion, SIGNAL(triggered()), this, SLOT(checkForUpdate()));
   options->addAction(checkVersion);
   toggledebug = new QAction(tr("&Toggle Debug"), this);
   toggledebug->setCheckable(true);
   toggledebug->setChecked(true);
   font->setStatusTip(tr("Opens the Font Settings"));
   hosts->setStatusTip(tr("Opens the Hosts Data Settings"));
   connect(font, SIGNAL(triggered()), this, SLOT(font()));
   options->addAction(font);
   options->addAction(feldplus);
   options->addAction(feldminus);
   options->addAction(feldreset);
   QSignalMapper* signalMapper = new QSignalMapper (this) ;
   connect(feldplus, SIGNAL(triggered()), signalMapper, SLOT(map()));
   connect(feldminus, SIGNAL(triggered()), signalMapper, SLOT(map()));
   connect(feldreset, SIGNAL(triggered()), this, SLOT(resetFactor()));

   signalMapper->setMapping(feldplus,  "0.1");
   signalMapper->setMapping(feldminus, "-0.1");

   connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(setFactorWidth(QString)));

   menuBar->addMenu(options);
   connect(toggledebug, SIGNAL(toggled(bool)), this, SLOT(debugToggle(bool)));
   if (adminMenu == true)
   {
   statusBar->showMessage("Login Screen started in Admin Mode", 3000);
//   QTimer *timer = new QTimer(this);
//   connect(timer, SIGNAL(timeout()), this, SLOT(welcomeBar()));
//   timer->start(3000);
   menuBar->addMenu(admin);
   admin->addAction(hosts);
   menuBar->addAction(toggledebug);
   connect(hosts, SIGNAL(triggered()), this, SLOT(hosts()));
   }
   if (MainFrame::b_debugmodus && adminMenu)
   {
       admin->addAction(toggledebug);
   }
   if (MainFrame::b_debugmodus && !adminMenu)
   {
       menuBar->addAction(toggledebug);
   }
else
    {
//       QTimer *timer = new QTimer(this);
//       connect(timer, SIGNAL(timeout()), this, SLOT(welcomeBar()));
//       timer->start(3000);
welcomeBar();
}



    // Add the DebugMenu
//  if (debugModus == true)
//{
//      statusBar->showMessage("Login Screen started in Debug Mode");
//      QAction *debug = new QAction(tr("&Debug"), this);
//      admin->addAction(debug);
//      connect(debug, SIGNAL(triggered()), this, SLOT(debug()));
//  }


   // instantiating labels and line edits - facilitating user input
   // labels should be filled by text-variables - later
   //
   usernameLabel       = new QLabel(tr("User:"));
   usernameLineEdit    = new QLineEdit;
   setFocusProxy(usernameLineEdit);

   passwordLabel       = new QLabel(tr("Password:"));
   passwordLineEdit    = new QLineEdit;
   passwordLineEdit->setEchoMode(QLineEdit::Password);

   serverLabel         = new QLabel(tr("Server:"));
   serverLineEdit      = new QLineEdit;

   applicationLabel    = new QLabel(tr("Application:"));
   applicationLineEdit = new QLineEdit;
   applicationLineEdit->setText("");
   QHBoxLayout *vbox = new QHBoxLayout;

   bg_connection = new QGroupBox("Connection Method:", this);
   rb_proxy  = new QRadioButton("Proxy", bg_connection);
   rb_proxy->setChecked(true);
   rb_telnet = new QRadioButton("Telnet", bg_connection);
   #ifdef SSH_USE
   rb_ssh    = new QRadioButton("SSH", bg_connection);
   #endif
   vbox->addWidget(rb_proxy);
   vbox->addWidget(rb_telnet);
   #ifdef SSH_USE
   vbox->addWidget(rb_ssh);
   rb_ssh->setChecked(true);
   #endif

   bg_connection->setLayout(vbox);
   connect(rb_telnet, SIGNAL(clicked()), this, SLOT(disableApp())); //Commandline execution works not with telnet atm
   connect(rb_proxy, SIGNAL(clicked()), this, SLOT(enableApp()));
   #ifdef SSH_USE
   connect(rb_ssh, SIGNAL(clicked()), this, SLOT(enableApp()));
   #endif
   loadSettings();


   QList<QKeySequence> ql_shortcuts;
   ql_shortcuts << QKeySequence("Return");
   ql_shortcuts << QKeySequence("Enter");

   QAction *okAction = new QAction("Connect", NULL);
   okAction->setShortcutContext(Qt::WidgetShortcut);
   okAction->setShortcuts(ql_shortcuts);
   connect(okAction, SIGNAL(triggered()), this, SLOT(okPressed()));

   QAction *cancelAction = new QAction("Cancel", NULL);
   cancelAction->setShortcutContext(Qt::WidgetShortcut);
   cancelAction->setShortcuts(ql_shortcuts);
   connect(cancelAction, SIGNAL(triggered()), this, SLOT(cancelPressed()));

   usernameLineEdit->addAction(okAction);
   passwordLineEdit->addAction(okAction);
   serverLineEdit->addAction(okAction);
   applicationLineEdit->addAction(okAction);


   // instantiating the buttons
   //
   QPushButton *okButton     = new QPushButton(tr("OK"));
   okButton->addAction(okAction);
   QPushButton *cancelButton = new QPushButton(tr("Cancel"));
   cancelButton->addAction(cancelAction);


   // functionalize the buttons by using connect
   // accept and reject are predefined by qt, so we can use them
   // without declaration
   //
   connect(okButton, SIGNAL(pressed()), this, SLOT(okPressed()));
   connect(cancelButton, SIGNAL(pressed()), this, SLOT(cancelPressed()));

   // setup the buttons layout for the form / widget
   //
   QHBoxLayout *buttonLayout = new QHBoxLayout;

   buttonLayout->addWidget(okButton);
   buttonLayout->addStretch(1);
   buttonLayout->addWidget(cancelButton);

   // setup the labels layout for the form / widget
   //
   QVBoxLayout *loginLayout = new QVBoxLayout;
 //  loginLayout->setMenuBar(menuBar);
   loginLayout->addWidget(usernameLabel);
   loginLayout->addWidget(usernameLineEdit);
   loginLayout->addWidget(passwordLabel);
   loginLayout->addWidget(passwordLineEdit);
   if(adminMenu == true)
   {
       loginLayout->addWidget(serverLabel);
       loginLayout->addWidget(serverLineEdit);
       loginLayout->addWidget(applicationLabel);
       loginLayout->addWidget(applicationLineEdit);
   }
   loginLayout->addWidget(bg_connection);
   loginLayout->addStretch(1);

   // putting buttons and line edits in one single layout
   //
   loginLayout->addLayout(buttonLayout);

   // layout is ready for use, so we can set it.
   //
   setLayout(loginLayout);

}

void LoginForm::resetFactor()
{
    VDC::setFieldSizeFactor(1);
    qDebug() << "reset Factor to default: 1.0";
}

void LoginForm::setFactorWidth(QString factor)
{
    double wert = VDC::getFieldSizeFactor();
    QString zeichen;

    if(factor.contains("-"))
    {
        zeichen = "-";
        factor.remove(zeichen);
    }

    if(!zeichen.isEmpty())
    {
        wert = wert - factor.toDouble();
    } else {
        wert = wert + factor.toDouble();
    }
    qDebug() << "New Fieldwidth factor: " << wert;
    VDC::setFieldSizeFactor(wert);
}

void LoginForm::disableApp()
{
   applicationLineEdit->setEnabled(false);
}

void LoginForm::enableApp()
{
   applicationLineEdit->setEnabled(true);
}

void LoginForm::debugToggle(bool checked)
{
    MainFrame *mainFrame = (MainFrame*) parent();
MainFrame::vdcdebug("LoginForm","debugToggle", "bool checked");
    if(checked)
    {
        mainFrame->clientTcp->dw->setVisible(true);
    }
    if(!checked)
    {
        mainFrame->clientTcp->dw->setVisible(false);
    }

}


void LoginForm::welcomeBar()
{
showMessage("Welcome!");
MainFrame::vdcdebug("LoginForm","welcomeBar", "");

}
//Hosts Settings

void LoginForm::hosts()
{
   HostsData *hosts = new HostsData(this);
MainFrame::vdcdebug("LoginForm","hosts", "");
   hosts->show();
}




//Hosts Settings
HostsData::HostsData(QWidget *parent) : QDialog(parent)
{
       hostspath = checkOS();
MainFrame::vdcdebug("HostsData","HostsData", "QWidget *parent");
       if (!hostspath.at(0).isNumber())
          {
          QLabel *description = new QLabel(tr("<h2>Host Data</h2>"));
          QLabel *description2 = new QLabel(tr("<b>CAUTION :</b> Be sure that you login as Admin/root <br> otherwise you can't edit these Settings"));
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
          mainLayout->addWidget(description2);
          mainLayout->addWidget(hostsTable);
          mainLayout->addWidget(addButton);
          mainLayout->addWidget(saveButton);
          setLayout(mainLayout);
          setWindowTitle(tr("VDC - Hosts Settings"));
          move(QCursor::pos());
          show();
          }
       else
          {
          QString errorout;
          QVBoxLayout *errorlay   = new QVBoxLayout(this);
          errorout = "Your OS is not supported. Please contact us! \n Error No. : ";
          errorout.append(hostspath);
          QLabel *errorlabel = new QLabel(errorout);
          errorlay->addWidget(errorlabel);
          setLayout(errorlay);
          setWindowTitle(tr("Error!"));
          }

}

QString HostsData::checkOS()
{
   QString pfad;
MainFrame::vdcdebug("HostsData","checkOS", "");
   pfad = "";
   #ifdef Q_WS_WIN
   int windows = QSysInfo::WindowsVersion;
   #if QT_VERSION >= 0x040600
      if(windows == QSysInfo::WV_VISTA){
         return "1";
      }
   #endif
   if (windows > 15 && windows < 159)
      {
        pfad = QProcessEnvironment::systemEnvironment().value("SYSTEMROOT", "");
        if (pfad == "")
           {
           return "1";
           }
        pfad += "\\system32\\drivers\\etc\\hosts";
       }
    if (windows > 1 && windows < 15)
       {
         QStringList system; //= QProcess::systemEnvironment();
         pfad = system.filter("WINDIR").at(0).split("=").at(1);
         if (pfad == "")
            {
            return "2";
            }
         pfad += "\\hosts";
       }
    return pfad;
    #endif

   #ifdef Q_WS_MAC
   pfad = "/private/etc/hosts";
   return pfad;
   #endif

   #ifdef Q_WS_X11
   pfad = "/etc/hosts";
   return pfad;
   #endif

   return "3";

  }


void HostsData::readHost()
{
     QFile file(hostspath);
MainFrame::vdcdebug("HostsData","readHost", "");
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
MainFrame::vdcdebug("HostsData","saveHost", "");
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
MainFrame::vdcdebug("HostsData","addHost", "");
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
MainFrame::vdcdebug("HostsData","checkipv6", "");
ipv4->hide();
ipv6->show();
    }

void HostsData::checkipv4()
{
ipcheck = true;
MainFrame::vdcdebug("HostsData","checkipv4", "");
ipv6->hide();
ipv4->show();
}

void HostsData::writeHost()
{
   QString entry;
MainFrame::vdcdebug("HostsData","writeHost", "");
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
void LoginForm::font()
{
       OptionsTab *optionsTab = new OptionsTab();
MainFrame::vdcdebug("LoginForm","font", "");
       connect(optionsTab, SIGNAL(showMessage(QString)), this, SLOT(showMessage(QString)));
       optionsTab->setWindowTitle(tr("VDC - Font Settings"));

       optionsTab->move(QCursor::pos());
       optionsTab->show();


}


void LoginForm::showMessage(QString m)
{
   MainFrame *mf = (MainFrame*) this->parent();
MainFrame::vdcdebug("LoginForm","showMessage", "QString m");

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
MainFrame::vdcdebug("LoginForm","writeFile", "QString qs_filename");
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
   #ifdef SSH_USE
void LoginForm::authfailed(int rc, QString err)
{

  QString error = "";

  switch(rc)
  {
    case SSH_AUTH_DENIED:
      error = "Die Kombination aus Usernamen und Password existiert nicht.";
      break;
    default:
      error = "Fehler beim Authentifizieren! Abbruch!";
      break;

  }

  error.append(" Fehlercode : " + QString::number(rc));

  this->error(error);

  removeCursor();

}


void LoginForm::commandfailed(int rc, QString err)
{

  this->error("Script : " + err + " nicht gefunden!");

  removeCursor();
}


void LoginForm::connectionfailed(int rc, QString err)
{
  QString error = "Verbindung zum Host : " + err + " fehlgeschlagen. Fehlercode : " + QString::number(rc);
  this->error(error);

  removeCursor();
}
#endif
void LoginForm::error(QString err)
{
  errorMessageLoginForm->showMessage(err);
}

//------------------------------------------------------------------------------
// Method       : void readEditFile()
// Filename     : login.cpp
// Description  : opens a File for binary reading
//------------------------------------------------------------------------------

void LoginForm::readEditFile(QString fname)
{
   QFile file(fname);
MainFrame::vdcdebug("LoginForm","readEditFile", "QString fname");

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

   //hideLogin();
MainFrame::vdcdebug("LoginForm","okPressed", "");
   VDC::waitCursor();
   QSettings settings;
   QString server = serverLineEdit->text();
   QString user   = usernameLineEdit->text();
   QString pass   = passwordLineEdit->text();
   QString app    = applicationLineEdit->text();
   settings.setValue("server", server);
   settings.setValue("user", user);
   settings.setValue("password", pass);
   settings.setValue("application", app);
   if(rb_telnet->isChecked())
     settings.setValue("checked", "telnet");
   #ifdef SSH_USE
   if(rb_ssh->isChecked())
     settings.setValue("checked", "ssh");
   #endif
   if(rb_proxy->isChecked())
     settings.setValue("checked", "proxy");

   settings.sync();
   if(rb_telnet->isChecked())
   {
      tn = new QtTelnet;
      connect(tn, SIGNAL(loginRequired()), this, SLOT(connectToTelnet()));
      tn->connectToHost(server, 23);
      connect(tn, SIGNAL(connectionError(QAbstractSocket::SocketError)), this, SLOT(removeCursor()));
      connect(tn, SIGNAL(loginFailed()), this, SLOT(removeCursor()));
      return;
   }
   #ifdef SSH_USE
   if(rb_ssh->isChecked())
   {
       //Initiliaze
       VSSH *ssh = new VSSH(server, user, pass, app, this);
       connect(ssh, SIGNAL(connection_established()), this, SLOT(m_c_established()));
       connect(ssh, SIGNAL(authsuccess()), this, SLOT(m_c_success()));
       connect(ssh, SIGNAL(enviorment_set()), this, SLOT(m_c_envset()));
       connect(ssh, SIGNAL(command_executed(QString)), this, SLOT(m_c_executed(QString)));
       connect(ssh, SIGNAL(connectionfailed(int,QString)), this, SLOT(connectionfailed(int,QString)));
       connect(ssh, SIGNAL(authfailed(int,QString)), this, SLOT(authfailed(int,QString)));
       connect(ssh, SIGNAL(commandnotfound(int,QString)), this, SLOT(commandfailed(int,QString)));
       connect(ssh, SIGNAL(error(QString)), this, SLOT(error(QString)));
       ssh->start(QThread::NormalPriority);
       connect(ssh, SIGNAL(finished()), ssh, SLOT(deleteLater()));

       return;

   }
   #endif
   ClientSocket *socket = new ClientSocket(0, user, pass, applicationLineEdit->text());

   socket->connectToHost(server, 3490);
   if(!socket->waitForConnected(4000)){
      QErrorMessage *errorMsg = new QErrorMessage(this);
      errorMsg->showMessage(tr("Could not connect to Host"));
   }
   VDC::arrowCursor();
}

void LoginForm::connectToTelnet()
{
   QString user   = usernameLineEdit->text();
   QString pass   = passwordLineEdit->text();
   tn->login(user, pass);
}

//------------------------------------------------------------------------------
// Method       : void cancelPressed()
// Filename     : login.cpp
// Description  : write the changed data back to file
//------------------------------------------------------------------------------
void LoginForm::cancelPressed()
{
   VDC::saveSettingsToIni("Ventas AG", "posX", QString::number(this->parentWidget()->pos().x()));
   VDC::saveSettingsToIni("Ventas AG", "posY", QString::number(this->parentWidget()->pos().y()));
   exit(0);
MainFrame::vdcdebug("LoginForm","cancelPressed", "");
}

void LoginForm::showLogin()
{
   if(QWidget *mainWin = qobject_cast<QWidget *> (parent())){
MainFrame::vdcdebug("LoginForm","showLogin", "");
      mainWin->setHidden(false);
   }
}

void LoginForm::hideLogin()
{
   if(QWidget *mainWin = qobject_cast<QWidget *> (parent())){
MainFrame::vdcdebug("LoginForm","hideLogin", "");
      mainWin->setHidden(true);
   }
}

void LoginForm::loadSettings()
{
   QSettings settings;
MainFrame::vdcdebug("LoginForm","loadSettings", "");
   QString server = settings.value("server").toString();
   QString user = settings.value("user").toString();
   QString pass = settings.value("password").toString();
   QString app = settings.value("application").toString();

   QString checked = settings.value("checked").toString();

   if(checked == "ssh")
   {
      #ifdef SSH_USE
      rb_ssh->setChecked(true);
      #else
      rb_proxy->setChecked(true);
      #endif
   }

   if(checked == "telnet")
     rb_telnet->setChecked(true);

   if(checked == "proxy")
     rb_proxy->setChecked(true);

   if(!server.isEmpty()){
      serverLineEdit->setText(server);
   }
   if(!user.isEmpty()){
      usernameLineEdit->setText(user);
   }
   if(!pass.isEmpty()){
      passwordLineEdit->setText(pass);
   }

   if(!app.isEmpty()){
      applicationLineEdit->setText(app);
   }
}
void LoginForm::debugCheck()
{
   toggledebug->setChecked(false);
MainFrame::vdcdebug("LoginForm","debugCheck", "");
}
#ifdef SSH_USE
//Slots for SSH

void LoginForm::m_c_success()
{
  showMessage("Authentifizierung erfolgreich!");
}

void LoginForm::m_c_established()
{
  showMessage("Verbindung hergestellt!");
}

void LoginForm::m_c_executed(QString cmd)
{
  QString message = "Script : \"" + cmd + "\" wird gestartet!";
  showMessage(message);
}

void LoginForm::m_c_envset()
{
  showMessage("Umgebung wurde gesetzt!");
}

#endif

void LoginForm::removeCursor()
{
  VDC::arrowCursor();
}

void LoginForm::checkForUpdate()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl("http://napo.na.funpic.de/vdc.xml")));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(downloadFinished(QNetworkReply*)));
}

void LoginForm::downloadFinished(QNetworkReply *reply)
{
    QList<QString> serverVars;
    QList<QString> clientVars = checkVersion(QDir::currentPath() + "/versions.xml");
    //QList<QString> clientVars = checkVersion("/home/da/versions.xml");
    int closeWindow = 0;
    if(reply->size() > 0 )
    {
        QFile file(QDir::tempPath() + "/vdc.xml");
        file.open(QIODevice::WriteOnly);
        file.write(reply->readAll());
        file.close();
        serverVars << checkVersion(QDir::tempPath() + "/vdc.xml");
    } else {
        QMessageBox *box = new QMessageBox(this);
        box->setWindowTitle("VENTAS UPDATE");
        box->question(0,
                      tr("VDC UPDATE"),
                      tr("Could not connect to the Update Server.\n Please check your Network connection."),
                      tr("&Ok"),
                      QString(), 0);
    }

    if(!serverVars.isEmpty() && !clientVars.isEmpty())
    {
        if(!serverVars.at(0).isEmpty() && !clientVars.at(0).isEmpty())
        {
            if(serverVars.at(0) > clientVars.at(0))
            {
                if(!serverVars.at(1).isEmpty() && !clientVars.at(1).isEmpty())
                {
                    if(serverVars.at(1) != clientVars.at(1))
                    {
                        QString a4gl_client_version = VDC::readSettingsFromIni("", "a4gl_version");
                        if(!serverVars.at(2).isEmpty() && a4gl_client_version > 0)
                        {
                            if(serverVars.at(2) == a4gl_client_version)
                            {
                                int dialogAuswahl = 0;
                                qDebug() << "Client & Server haben gleiche Version";

                                QMessageBox *box = new QMessageBox(this);
                                box->setWindowTitle("VENTAS UPDATE");
                                dialogAuswahl = box->question(0,
                                              tr("VDC UPDATE"),
                                              tr("The is a new VDC version available.\n Do you want to download an install?"),
                                              tr("&Yes"), tr("&No"),
                                              QString(), 0, 1);

                                if(dialogAuswahl == 0)
                                {
                                    qDebug() << "OK wurde gedrueckt";
                                    if(MainFrame *frame = qobject_cast<MainFrame*> (this->parent()))
                                    {
                                        if(frame->clientTcp->socket != NULL && (frame->clientTcp->socket->state() >0 && frame->clientTcp->socket->state() <6))
                                        {
                                            QMessageBox *box = new QMessageBox(this);
                                            box->setWindowTitle("VENTAS UPDATE");
                                            closeWindow = box->question(0,
                                                          tr("VDC UPDATE"),
                                                          tr("There are open Connections.\n Do you really want to quit?"),
                                                          tr("&Yes"), tr("&No"),
                                                          QString(), 0, 1);
                                            qDebug() << "Es laufen noch Anwendungen!";
                                        }
                                    }

                                    if(closeWindow == 0)
                                    {
                                        loadBinaries();

                                    }
                                }
                            }
                            //qDebug() << "var gesetzt";
                        }
                        //qDebug() << "Client Hash ist veraltet!";
                    } else {
                        QMessageBox *box = new QMessageBox(this);
                        box->setWindowTitle("VENTAS UPDATE");
                        box->question(0,
                                      tr("VDC UPDATE"),
                                      tr("The Client is up to date!"),
                                      tr("&Ok"),
                                      QString(), 0);
                    }
                }
                //qDebug() << "client ist veraltet";
            } else {
                QMessageBox *box = new QMessageBox(this);
                box->setWindowTitle("VENTAS UPDATE");
                box->question(0,
                              tr("VDC UPDATE"),
                              tr("The Client is up to date!"),
                              tr("&Ok"),
                              QString(), 0);
            }
        }
    }
}
void LoginForm::loadBinaries()
{
    QString fileName;
    QNetworkAccessManager *manager = new QNetworkAccessManager;
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(updateReady(QNetworkReply*)));

    #ifdef Q_WS_MAC
        fileName = "VDC.pkg";
    #endif
    #ifdef Q_WS_UNIX
        fileName = "VDC-unix.zip";
    #endif
    #ifdef Q_WS_WIN
        fileName = "VDC_windows.zip";
    #endif

    QNetworkRequest request;
    request.setUrl(QUrl(QString("http://www.ventas.de/wp-content/uploads/downloads/%1").arg(fileName)));

    QNetworkReply *reply;

    reply = manager->get(request);

    connect(reply, SIGNAL(downloadProgress(qint64,qint64)), SLOT(updateDownloadProgress(qint64,qint64)));


    //Open GUI to display the progress of the downloaded file
    QWidget *widget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(widget);
    m_label = new QLabel(widget);
    m_progress = new QProgressBar(widget);

    layout->addWidget(m_label, Qt::AlignBottom);
    layout->addWidget(m_progress, Qt::AlignBottom);

    m_label->setText(tr("Connecting to Download Server..."));

    widget->setLayout(layout);
    widget->resize(200,100);
    widget->show();

    //QApplication::quit();
}

void LoginForm::updateDownloadProgress(qint64 received,qint64 total)
{
    m_label->setText("Downloading VDC...");
    m_progress->setValue((double) received * 100 / total);
}
void LoginForm::updateReady(QNetworkReply *reply)
{

    #ifdef Q_WS_MAC
    QFile *file = new QFile(QDir::tempPath() + "/vdc-update.pkg");
    #else
    QFile *file = new QFile(QDir::tempPath() + "/vdc-update.zip");
    #endif
    if(!file->open(QIODevice::WriteOnly))
    {
        qDebug() << "Cannot write file.";
    }

    switch(reply->error())
    {
       default:
            qDebug() << QString("Cannot load File from Server. Error code: %1 ").arg(reply->error());
            m_label->setText(QString("Cannot load File from Server. Error code: %1 ").arg(reply->error()));
    }

    if(reply->error() == 0)
    {
        file->write(reply->readAll());
        file->close();

        m_label->setText("Download beendet!");
        m_progress->setValue(100);
        #ifdef Q_WS_MAC
        QDesktopServices::openUrl(QUrl(QString("file:///" + QDir::tempPath() + "/vdc-update.pkg"), QUrl::TolerantMode));
        #else
           QDesktopServices::openUrl(QUrl(QString("file://%1").arg(QDir::tempPath() + "/vdc-update.zip"), QUrl::TolerantMode));
        #endif
        QApplication::quit();

    }
}

QList<QString> LoginForm::checkVersion(QString filePath)
{
    QFile file;
    QList<QString> childText;
    file.setFileName(filePath);

    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox *box = new QMessageBox(this);
        box->setWindowTitle("VENTAS UPDATE");
        box->setText(QString("Failed to open File: %1").arg(filePath));
        box->show();
    }

    QDomDocument doc;
    doc.setContent(&file);

    QDomElement root = doc.documentElement();
    QDomNode node = root.firstChild();
    while(!node.isNull())
    {
        QDomElement child = node.toElement();
        if(!child.isNull())
        {
            childText << child.text();
        }
        node = node.nextSibling();

        //Formatiertes Datumsformat
        //qDebug() << QDate::currentDate().toString("dd.MM.yyyy");
    }
    return childText;
    file.close();
}

