//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// File name    : mainframe.cpp
// Description  : contains the mainframe logic
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
#include <QStatusBar>
#include <QHBoxLayout>
#include <QMenu>
#include <QHeaderView>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>

#include "mainframe.h"
#include "confwin.h"
#include "clienttcp.h"
#include "login.h"
#include "include/vdc.h"
#include "models/progress.h"
#include "models/fglform.h"

//------------------------------------------------------------------------------
// Method       : MainFrame()
// Filename     : mainframe.cpp
// Description  : starts first screen window, starts tcp server (listenToPort)
//------------------------------------------------------------------------------

void MainFrame::ReadSettings()
{
MainFrame::vdcdebug("MainFrame","ReadSettings", "");
    int firstStartWithNewDesign = VDC::readSettingsFromLocalIni("", "firstStartWithNewDesign").toInt();
    QSettings settings("Ventas AG", "Ventas Desktop Client");

    if(firstStartWithNewDesign == -1) {
    #ifdef Q_OS_WIN
        #if QT_VERSION < QT_VERSION_CHECK(5,0,9)
           QSettings settings(QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
        #else
           QSettings settings(QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/.vdc/settings.ini", QSettings::IniFormat);
        #endif
    #else
        QSettings settings(QDir::homePath() + "/.vdc/settings.ini", QSettings::IniFormat);
    #endif

    settings.remove("");

    #ifdef Q_OS_MAC
        QApplication::setFont(QFont("Open Sans Semibold", 12));
    #else
        QApplication::setFont(QFont("Open Sans Semibold", 10));
    #endif
        settings.setValue("font", QApplication::font().toString());
        settings.sync();
        VDC::saveSettingsToLocalIni("", "firstStartWithNewDesign", "1");
    }

    QVariant fontsetting = settings.value("font");
    QString fontsetting2;
    fontsetting2 = fontsetting.toString();
    QFont fontsetting3;
    fontsetting3.fromString(fontsetting2);

    QApplication::setFont(fontsetting3);
    if(fontsetting2 == "")
    {
        #ifdef Q_OS_MAC
            QApplication::setFont(QFont("Open Sans Semibold", 12));
        #else
            QApplication::setFont(QFont("Open Sans Semibold", 10));
        #endif
    }

    QMenu *menu = new QMenu;
    QAction *showAction = menu->addAction(tr("Show Login Window"));
    connect(showAction, SIGNAL(triggered()), this, SLOT(show()));

    QAction *hideAction = menu->addAction(tr("Hide Login Window"));
    connect(hideAction, SIGNAL(triggered()), this, SLOT(hide()));

    QAction *exitAction = menu->addAction(tr("Exit"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(closeAction()));

    mTray = new QSystemTrayIcon(this);
    mTray->setIcon(QIcon(":pics/vdc.png"));
    mTray->setContextMenu(menu);
    connect(mTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(trayIconClicked(QSystemTrayIcon::ActivationReason)));
    mTray->show();

    this->setStyleSheet("QMainWindow { margin-top: 15px; background-color: white; }");
}

bool MainFrame::b_debugmodus = false;
QString MainFrame::progName = "";
MainFrame* MainFrame::lastmainframe = NULL;
QList<ScreenHandler*> *MainFrame::ql_screenhandler = new QList<ScreenHandler*>();

bool MainFrame::setFocusOn(int pid)
{
    QList<ScreenHandler*> *l_ql_screenhandler = MainFrame::ql_screenhandler;
    if(pid < 0)
    {
        return false;
    }

    for(int i=0; i<l_ql_screenhandler->count(); i++)
    {
        if(l_ql_screenhandler->at(i)->p_pid == pid)
        {
            if(l_ql_screenhandler->at(i)->b_runinfo)
            {
                if(l_ql_screenhandler->at(i)->p_pid_p > 0)
                {
                    return MainFrame::setFocusOn(l_ql_screenhandler->at(i)->p_pid_p);
                }
            }
            l_ql_screenhandler->at(i)->activeFocus();
            return true;
        }
    }

    return false;
}

void MainFrame::check_new_pids()
{
    QList<ScreenHandler*> *l_ql_screenhandler = MainFrame::ql_screenhandler;

    if(l_ql_screenhandler->size() <= 1)
    {
       return;
    }

    for(int i = l_ql_screenhandler->size()-1; i>=0; i--)
    {
        if(l_ql_screenhandler->at(i) == NULL)
        {
            continue;
        }
        if(l_ql_screenhandler->at(i)->p_pid_p == 0 && l_ql_screenhandler->at(i)->b_runinfo)
        {
            for(int j = l_ql_screenhandler->size()-1; j>=0; j--)
            {
                if(l_ql_screenhandler->at(j) == NULL)
                {
                    continue;
                }

                if(l_ql_screenhandler->at(j)->programm_name.contains(l_ql_screenhandler->at(i)->programm_name_run + "."))
                {
                    if(l_ql_screenhandler->at(i)->programm_name_run.isEmpty())
                    {
                        continue;
                    }
                    if(l_ql_screenhandler->at(i)->p_pid == l_ql_screenhandler->at(j)->p_pid)
                    {
                        continue;
                    }
                    l_ql_screenhandler->at(i)->p_pid_p = l_ql_screenhandler->at(j)->p_pid;
                    //Focus of windows, when kind closes active the Focus of the Parent Window
                    connect(l_ql_screenhandler->at(i), SIGNAL(destroyed()), l_ql_screenhandler->at(j), SLOT(activeFocus()));
                }
            }
        }
    }
}



MainFrame::MainFrame(QWidget *parent) : QMainWindow(parent)
{
MainFrame::vdcdebug("MainFrame","MainFrame", "QWidget *parent");
   MainFrame::lastmainframe = this;
   p_currOpenNetwork=NULL;
   quint16 port=1350;
   closeSSH = 0;
   mainFrameToolBar = NULL;
   connectionsTab = NULL;
   errorMessageMainFrame = new QErrorMessage(this);
  QStringList parameter;
  parameter = QCoreApplication::arguments();
   bool onlyLogin;
   debugVDC = VDC::readSettingsFromLocalIni("", "debugVDC").toInt();

   adminMenu = true;
   onlyLogin = true;
 for(int i=0; i<parameter.count(); i++)
  {
     if (parameter.at(i) == "-l")
     {
         onlyLogin = true;
     }

     if (parameter.at(i) == "-p")
     {
     i++;
         port= parameter.at(i).toInt();
    qDebug() << "Using non-standard port:"<< port;
     }

     if (parameter.at(i) == "-a")
     {
         adminMenu = true;
     }
          if (parameter.at(i) == "-D")
     {
         MainFrame::b_debugmodus = true;
     }
 }

   if(onlyLogin == false){
      tabWidget = new QTabWidget;
      setCentralWidget(tabWidget);

      setFixedSize(305,375);

      tabWidget->setGeometry(5,5,275,295);

      tabWidget->addTab(new ShortcutsTab(this),   tr("Shortcuts"));
      tabWidget->addTab(new OptionsTab(),          tr("Options"));
      connectionsTab = new ConnectionsTab(this);
      tabWidget->addTab(connectionsTab,      tr("Connections"));

      // setting up actions for the clients toolbar
      //


      exitAction = new QAction(tr("Exit"), this);
      exitAction->setShortcut(tr("Ctrl+Q"));
      exitAction->setStatusTip(tr("Exit Client"));

      connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
      mainFrameToolBar = new QToolBar(tr("ToolBar"));
      mainFrameToolBar->addAction(exitAction);
      mainFrameToolBar->setAllowedAreas(Qt::BottomToolBarArea|Qt::TopToolBarArea);
      addToolBar(Qt::TopToolBarArea, mainFrameToolBar);



      // making the statusbar
      //
      createStatusBar();
   }
   else{
      LoginForm *loginForm = new LoginForm(this);
      setCentralWidget(loginForm);
      userName = loginForm->getUserName();
      connect(this, SIGNAL(debugSignal()), loginForm, SLOT (debugCheck()));
   }
      setWindowTitle(tr("VDC - Ventas Desktop Client"));

   // start listening to the network
   //
   ReadSettings();
   if(port != 1350) {
       listenToPort(port);
   }

}
void MainFrame::contextMenuEvent ( QContextMenuEvent * event)
{
  if(mainFrameToolBar != NULL)
    {
  QMenu contextMenu(this);
MainFrame::vdcdebug("MainFrame","contextMenuEvent ", " QContextMenuEvent * event");
  contextMenu.addAction(mainFrameToolBar->toggleViewAction());
  contextMenu.exec(event->globalPos());
}

}

void MainFrame::vdcdebug(QString obj, QString funk, QString uebergabe)
{
    if(MainFrame::b_debugmodus)
    {
       qDebug() << obj + "::" + funk + "(" + uebergabe + ")";
    }
}


bool MainFrame::eventFilter(QObject *obj, QEvent *event)
{
    QKeyEvent *kev = (QKeyEvent*) event;

    if((event->type() == QEvent::KeyPress))
    {
        ScreenHandler *p_screen = NULL;

        for(int i=0; i < ql_screenhandler->count(); i++) {
            if(ql_screenhandler->at(i) != NULL) {
                if(ql_screenhandler->at(i)->p_fglform != NULL) {
                    if(ql_screenhandler->at(i)->p_fglform->isActiveWindow()) {
                        p_screen = ql_screenhandler->at(i);
                    }
                }
            }
        }

        if(p_screen != NULL) {
            QKeyEvent *mykev = new QKeyEvent(kev->type(),
                                             kev->key(),
                                             kev->modifiers(),
                                             kev->text(),
                                             kev->isAutoRepeat(),
                                             kev->count());
            //SHIFT + Return nicht im buffer schreiben damit umbrueche moeglich sind.
            if((kev->modifiers() == Qt::ShiftModifier && kev->key() == Qt::Key_Return) || kev->nativeVirtualKey() == 65505) {
                return false;
            }

            b_lastAutoRepeat = kev->isAutoRepeat();

            if((!kev->isAutoRepeat() && kev->spontaneous() && p_screen->p_fglform->state() != Fgl::MENU) ||
               (kev->isAutoRepeat() && p_screen->p_fglform->state() != Fgl::MENU &&
               (kev->key() == Qt::Key_Tab || kev->key() == Qt::Key_Enter || kev->key() == Qt::Key_Return || kev->key() == Qt::Key_Backtab || kev->key() == Qt::Key_Up || kev->key() == Qt::Key_Down))) {
                p_screen->ql_keybuffer << mykev;
                QTimer::singleShot(50, p_screen, SLOT(replayKeyboard()));
                return true;
            }
        }
    }

    if((event->type() == QEvent::KeyRelease)) {
        if(kev->isAutoRepeat() == false && b_lastAutoRepeat) {
            ScreenHandler *p_screen = NULL;

            for(int i=0; i < ql_screenhandler->count(); i++) {
                if(ql_screenhandler->at(i) != NULL) {
                    if(ql_screenhandler->at(i)->p_fglform != NULL) {
                        if(ql_screenhandler->at(i)->p_fglform->isActiveWindow()) {
                            p_screen = ql_screenhandler->at(i);
                        }
                    }
                }
            }

            if(p_screen == NULL) {
                return QMainWindow::eventFilter(obj, event);
            }

            if(!p_screen->p_fglform->menu()) {
                if(p_screen->p_fglform->currentField() != NULL) {
                    p_screen->p_fglform->setFocusOnWidget(p_screen->p_fglform->currentField());
                    QMetaObject::invokeMethod(p_screen, "sendBeforeEvents", Qt::QueuedConnection);
                }
            }
            b_lastAutoRepeat = false;
        }
    }


    /*
    if(FglForm *p_fglform = qobject_cast<FglForm*> (obj))
    {
       if(event->type() == QEvent::WindowActivate && p_fglform != NULL && !p_fglform->screenhandler()->b_runinfo)
       {

           if(p_fglform->dialog() == NULL && p_fglform->pulldown() == NULL){

               p_fglform->raise();
               p_fglform->activateWindow();

           }
           if(p_fglform->dialog() != NULL)
           {
               p_fglform->dialog()->raise();
               p_fglform->dialog()->activateWindow();
               QApplication::setActiveWindow((QWidget*) p_fglform->dialog());
           }

       }
    }
*/
       return QMainWindow::eventFilter(obj, event);

}

//------------------------------------------------------------------------------
// Method       : createStatusBar()
// Filename :S    : mainframe.cpp
// Description  : createStatusBar logic
//------------------------------------------------------------------------------

void MainFrame::createStatusBar()
{
MainFrame::vdcdebug("MainFrame","createStatusBar", "");
   statusBar()->showMessage(tr("Welcome..."));
}


//------------------------------------------------------------------------------
// Method       : ConnectionsTab()
// Filename     : mainframe.cpp
// Description  : constructor for the instances
//------------------------------------------------------------------------------

ConnectionsTab::ConnectionsTab(QWidget *parent)
    : QWidget(parent)
{
    MainFrame::vdcdebug("ConnectionsTab","ConnectionsTab", "");

    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *connectionLabel = new QLabel(tr("Connections:"));
    tableWidget = new QTableWidget(0, 4, this);
    QStringList labels;

    labels << tr("Name") << tr("Id") << tr("Typ") << tr("Date");
    tableWidget->setHorizontalHeaderLabels(labels);
    tableWidget->verticalHeader()->hide();
    tableWidget->setShowGrid(false);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->resizeColumnsToContents();
    tableWidget->horizontalHeader()->setStretchLastSection(true);

    layout->addWidget(connectionLabel);
    layout->addWidget(tableWidget);
    setLayout(layout);
}

void ConnectionsTab::addConnection()
{
    MainFrame::vdcdebug("ConnectionsTab","addConnection", "");

    ClientTcp *clientTcp = (ClientTcp*) QObject::sender();
    QObject::connect(clientTcp->socket, SIGNAL(disconnected()), this, SLOT(delConnection()));

    QString ip = clientTcp->socket->peerAddress().toString();
    port = clientTcp->socket->peerPort();

    //int row = listpruef.count();

    portshow = QString::number(port);
    tableWidget->insertRow(listpruef.count());
    tableWidget->setItem(listpruef.count(), 0, new QTableWidgetItem(portshow));
    listpruef << port;
    tableWidget->resizeColumnsToContents();
    tableWidget->horizontalHeader()->setStretchLastSection(true);
}

void ConnectionsTab::delConnection()
{
    MainFrame::vdcdebug("ConnectionsTab","delConnection", "");

    ClientSocket *socket = (ClientSocket*) QObject::sender();
    int checkport = socket->peerPort();
    for(int i=0; i<listpruef.count(); i++) {
        if(listpruef.at(i) == checkport){
           tableWidget->removeRow(i);
           listpruef.removeAt(i);
       }
    }

}

//------------------------------------------------------------------------------
// Method       : OptionsTab()
// Filename     : mainframe.cpp
// Description  : constructor for the instances
//------------------------------------------------------------------------------

OptionsTab::OptionsTab(QWidget *parent)
    : QWidget(parent)
{

       QPalette palette;
       palette.setBrush(this->backgroundRole(), Qt::white);
       this->setPalette(palette);

       QGroupBox *fontbox = new QGroupBox();
       fontbox->setStyleSheet("QGroupBox {border: 0px;}");
       QLabel *fontlabel = new QLabel(tr("Font : "));

       QPushButton *select = new QPushButton(tr("&Select"),this);
       select->setIcon(QIcon(QString(":pics/vor.png")));
       select->setIconSize(QSize(53,37));
       select->setStyleSheet("QPushButton { border-image: url(:pics/VENTAS_11_btn_dialog_blau.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(:pics/VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(:pics/VENTAS_11_btn_dialog_blau_grau.png);}" "QPushButton:focus:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gelb_grau.png);}");

       QPushButton *reset = new QPushButton(tr("&Reset"),this);
       reset->setIcon(QIcon(QString(":pics/loeschen.png")));
       reset->setIconSize(QSize(53,37));
       reset->setStyleSheet("QPushButton { border-image: url(:pics/VENTAS_11_btn_dialog_blau.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(:pics/VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(:pics/VENTAS_11_btn_dialog_blau_grau.png);}" "QPushButton:focus:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gelb_grau.png);}");

       QPushButton *save = new QPushButton(tr("Save"), this);
       save->setIcon(QIcon(QString(":pics/ok_gruen.png")));
       save->setIconSize(QSize(53,37));
       save->setShortcut(Qt::Key_F12);
       save->setStyleSheet("QPushButton { border-image: url(:pics/VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(:pics/VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gelb_grau.png);}");

       QPushButton *close = new QPushButton(tr("&Close"), this);
       close->setIcon(QIcon(QString(":pics/abbrechen_rot.png")));
       close->setIconSize(QSize(53,37));
       close->setShortcut(Qt::Key_Escape);
       close->setStyleSheet("QPushButton { border-image: url(:pics/VENTAS_11_btn_dialog_rot.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(:pics/VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(:pics/VENTAS_11_btn_dialog_rot_grau.png);}" "QPushButton:focus:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gelb_grau.png);}");

       fontedit = new QLineEdit;
       fontedit->setReadOnly(true);


       QHBoxLayout *layoutbox = new QHBoxLayout;
       fontbox->setLayout(layoutbox);


       QHBoxLayout *fontlayout = new QHBoxLayout;
       fontlayout->addWidget(fontlabel);
       fontlayout->addWidget(fontedit);

       QVBoxLayout *leftlayout = new QVBoxLayout;
       leftlayout->addLayout(fontlayout);
       leftlayout->addStretch();

       QVBoxLayout *buttonlayout = new QVBoxLayout;

       buttonlayout->addWidget(select);
       buttonlayout->addWidget(reset);
       buttonlayout->addWidget(save);
       buttonlayout->addWidget(close);
       buttonlayout->setSpacing(5);

       layoutbox->addLayout(leftlayout);
       layoutbox->addLayout(buttonlayout);


       QVBoxLayout *mainlayout = new QVBoxLayout;
       mainlayout->addWidget(fontbox);

       setStyleSheet("QPushButton { border-image: url(:pics/VENTAS_11_btn_blau.png); padding-bottom: -1; padding-right: 10; text-align: left; height: 36px; min-width: 50px; }");
       setLayout(mainlayout);


       connect(select,SIGNAL(clicked()), this,SLOT(fontdialog()));
       connect(reset,SIGNAL(clicked()), this,SLOT(reset()));
       connect(save,SIGNAL(clicked()), this,SLOT(close()));
       connect(close,SIGNAL(clicked()), this,SLOT(close()));
     //LineEdit
QFont fontload;
fontload = QApplication::font();
QString fontconv;
fontconv = fontload.toString();
QStringList splitlist;
splitlist = fontconv.split(",");
QString fonteingabe;
fonteingabe.append(splitlist[0]);
fonteingabe.append(",");
fonteingabe.append(splitlist[1]);

#ifdef Q_OS_MAC
    if (fonteingabe == "Open Sans Semibold,12") {
        fonteingabe.append("(Default)");
        fontedit->insert(fonteingabe);
    } else {
        fontedit->insert(fonteingabe);
    }
#else
    if (fonteingabe == "Open Sans Semibold,10") {
        fonteingabe.append("(Default)");
        fontedit->insert(fonteingabe);
    } else {
        fontedit->insert(fonteingabe);
    }
#endif

fonteingabe = "";


}




void OptionsTab::reset()
{
MainFrame::vdcdebug("OptionsTab","reset", "");
fontedit->clear();
#ifdef Q_OS_MAC
    QFont base = QFont("Open Sans Semibold", 12);
    QApplication::setFont(base);
    fonteingabe = "Open Sans Semibold,12 (Default)";
#else
    QFont base = QFont("Open Sans Semibold", 10);
    QApplication::setFont(base);
    fonteingabe = "Open Sans Semibold,10 (Default)";
#endif
fontedit->insert(fonteingabe);
fonteingabe = "";
showMessage(tr("Font set to default"));
writeSettings();
}


void OptionsTab::fontdialog()
{
MainFrame::vdcdebug("OptionsTab","fontdialog", "");
 bool ok;
 QFont font = QFontDialog::getFont(&ok, QApplication::font(), this);
 if (ok) {
fontedit->clear();
QApplication::setFont(font);
fontconv = font.toString();
splitlist = fontconv.split(",");

fonteingabe.append(splitlist[0]);
fonteingabe.append(",");
fonteingabe.append(splitlist[1]);
if (fonteingabe == "Open Sans Semibold,10")
{
fonteingabe.append("(Default)");
fontedit->insert(fonteingabe);
showMessage(tr("Font set to default"));
}
else
{
fontedit->insert(fonteingabe);
QString showstatus = "Font set to ";
showstatus.append(fonteingabe);
showMessage(showstatus);
}
fonteingabe = "";
 }
 else {

 }
writeSettings();
}
void OptionsTab::writeSettings()
{
MainFrame::vdcdebug("OptionsTab","writeSettings", "");
   QSettings settings("Ventas AG", "Ventas Desktop Client");
   //int status = settings.status();
   QString fontsettingwrite;
   fontsettingwrite = QApplication::font().toString();
   settings.setValue("font", fontsettingwrite);
}

//------------------------------------------------------------------------------
// Method       : ShortcutsTab()
// Filename     : mainframe.cpp
// Description  : calling programs for testing
//------------------------------------------------------------------------------

ShortcutsTab::ShortcutsTab(MainFrame *mf,
QWidget *parent) : QWidget(parent)
{
   errorMessageMainFrame = new QErrorMessage(this);
   QLabel *topLabel      = new QLabel(tr("Select Shortcut:"));
   shortcutsListBox      = new QListWidget;
   QStringList shortcutsList;
   QString qs_Filename;

   p_mainframe = mf;

   QSettings settings("shortcuts.ini", QSettings::IniFormat, this);
   QStringList groups = settings.childGroups();

   for(int i = 0; i < groups.count(); ++i){
      qs_Filename = groups.at(i);

      if(readFile(qs_Filename, i)){
         shortcutsList.append(qs_Filename);
      }
   }

   shortcutsListBox->insertItems(0, shortcutsList);

   QVBoxLayout *layout = new QVBoxLayout;
   layout->addWidget(topLabel);
   layout->addWidget(shortcutsListBox);

   QPushButton *connectButton = new QPushButton(tr("Connect"));
   QPushButton *addButton     = new QPushButton(tr("Add"));
   QPushButton *delButton     = new QPushButton(tr("Delete"));

   connectButton->setFocus();
   connectButton->update();

   connect(connectButton, SIGNAL(clicked()), this, SLOT(requestApplication()));
   connect(addButton,     SIGNAL(clicked()), this, SLOT(addConfwin()));
   connect(delButton,     SIGNAL(clicked()), this, SLOT(delConfwin()));

   connect(shortcutsListBox, SIGNAL(itemDoubleClicked(QListWidgetItem *)),
           this, SLOT(editConfwin(QListWidgetItem *)));

   QHBoxLayout *buttonLayout = new QHBoxLayout;
   buttonLayout->addStretch(1);
   buttonLayout->addWidget(connectButton);
   buttonLayout->addWidget(addButton);
   buttonLayout->addWidget(delButton);
   layout->addLayout(buttonLayout);

   setLayout(layout);

}


//------------------------------------------------------------------------------
// Method       : editConfwin()
// Filename     : mainframe.cpp
// Description  : edit shortcuts logic
//------------------------------------------------------------------------------

void ShortcutsTab::editConfwin(QListWidgetItem *p_currWidgetItem)
{
MainFrame::vdcdebug("ShortcutsTab","editConfwin", "QListWidgetItem *p_currWidgetItem");

   // instantiating configuration window to edit shortcuts
   //    - we've to check for null pointer exceptions before
   //
   if(p_currWidgetItem==NULL){
       errorMessageMainFrame->showMessage(
          tr("Error: shortcutsListBox->currentItem() "
         "       returned a NULL-Pointer!!!"));
   }else{

       // now we can instantiate this class without fear
       //
       ConfWin *confwin = new ConfWin(p_currWidgetItem->text());
       confwin->show();

       connect(confwin, SIGNAL(accepted()), this, SLOT(updateListBox()));
   }
}


//------------------------------------------------------------------------------
// Method       : addConfwin()
// Filename     : mainframe.cpp
// Description  : add shortcuts logic
//------------------------------------------------------------------------------

void ShortcutsTab::addConfwin()
{
MainFrame::vdcdebug("ShortcutsTab","addConfwin", "");
   bool ok;
   QString fname = QInputDialog::getText(this, tr("Add Shortcut"),
                                        tr("Filename:"), QLineEdit::Normal,
                                        "", &ok);
   if (ok && !fname.isEmpty()){
      ConfWin *confwin = new ConfWin(fname);
      confwin->show();

      // when adding is finished, we have to refresh the listbox
      //
      //  --- better put this connect in the constructor...
      //
      //
      connect(confwin, SIGNAL(accepted()), this, SLOT(updateListBox()));
   }
}


//------------------------------------------------------------------------------
// Method       : delConfwin()
// Filename     : mainframe.cpp
// Description  : delete shortcuts logic
//------------------------------------------------------------------------------

void ShortcutsTab::delConfwin()
{
MainFrame::vdcdebug("ShortcutsTab","delConfwin", "");
   QListWidgetItem *p_currWidgetItem = shortcutsListBox->currentItem();

   // checking which entry is selected for being deleted
   //
   if(p_currWidgetItem==NULL){
      p_mainframe->statusBar()->showMessage(
            tr("Please select a File first!"),2000);
   }else{

      if(delFile(p_currWidgetItem->text())){
         QSettings settings("shortcuts.ini", QSettings::IniFormat, this);
         settings.remove(p_currWidgetItem->text());

         // when file was succesfully deleted, we have to update the listbox
         //
         updateListBox();
      }
   }
}


//------------------------------------------------------------------------------
// Method       : delFile()
// Filename     : mainframe.cpp
// Description  : deletes a file from disk
//------------------------------------------------------------------------------

bool ShortcutsTab::delFile(QString p_cFilename)
{
MainFrame::vdcdebug("ShortcutsTab","delFile", "QString p_cFilename");
   QFile file(p_cFilename);

   if (!file.remove()){
      errorMessageMainFrame->showMessage(
            tr("ERROR: Cannot delete: %1").arg(p_cFilename));
      return false;
   };

   return true;
}


//------------------------------------------------------------------------------
// Method       : readFile()
// Filename     : mainframe.cpp
// Description  : read binary data from a file
//------------------------------------------------------------------------------

bool ShortcutsTab::readFile(QString p_cFilename, int i)
{
MainFrame::vdcdebug("ShortcutsTab","readFile", "QString p_cFilename, int i");
   quint32 n;
   QFile file(p_cFilename);

   if (!file.open(QIODevice::ReadOnly)){
      return false;

   }else{

       QDataStream in(&file);
       in.setVersion(QDataStream::Qt_4_1);

       in >> n >> u_Shortcuts.qs_Username
               >> u_Shortcuts.qs_Password
               >> u_Shortcuts.qs_Application
               >> u_Shortcuts.qs_Protocol
               >> u_Shortcuts.qs_IPadress;

       u_arr_Shortcuts[i].qs_Username    = u_Shortcuts.qs_Username;
       u_arr_Shortcuts[i].qs_Password    = u_Shortcuts.qs_Password;
       u_arr_Shortcuts[i].qs_Application = u_Shortcuts.qs_Application;
       u_arr_Shortcuts[i].qs_Protocol    = u_Shortcuts.qs_Protocol;
       u_arr_Shortcuts[i].qs_IPadress    = u_Shortcuts.qs_IPadress;

   }
   return true;
}


//------------------------------------------------------------------------------
// Method       : updateListBox()
// Filename     : mainframe.cpp
// Description  : updates the entries in list box after making new files
//------------------------------------------------------------------------------

void ShortcutsTab::updateListBox()
{
MainFrame::vdcdebug("ShortcutsTab","updateListBox", "");
   QString fname;
   QStringList shortcutsList;

   QSettings settings("shortcuts.ini", QSettings::IniFormat, this);
   QStringList groups = settings.childGroups();

   for(int i = 0; i < groups.count(); ++i){
      fname = groups.at(i);

      if(readFile(fname, i)){
         shortcutsList.append(fname);
      }
   }

   shortcutsListBox->clear();
   shortcutsListBox->insertItems(0, shortcutsList);
}


//------------------------------------------------------------------------------
// Method       : listenToPort()
// Filename     : mainframe.cpp
// Description  : listen to network port....
//------------------------------------------------------------------------------
void MainFrame::addSystemProxy()
{
    QNetworkProxyQuery npq(QUrl("http://www.google.com"));
    QList<QNetworkProxy> listOfProxies = QNetworkProxyFactory::systemProxyForQuery(npq);

    foreach(QNetworkProxy proxy, listOfProxies)
    {
        if(!proxy.hostName().isEmpty())
        {
            QNetworkProxy::setApplicationProxy(proxy);
            qDebug() << "proxyuser: " << proxy.user();
            qDebug() << "proxyhost: " <<proxy.hostName();
            break;
        }
    }
}

bool MainFrame::listenToPort(quint16 port)
{
MainFrame::vdcdebug("MainFrame","listenToPort", "int port");
   clientTcp = new ClientTcp(this);
   clientTcp->setDebugModus(MainFrame::b_debugmodus, this);

   QStringList arguments = QApplication::arguments();

   clientTcp->listen(QHostAddress::Any, port);

   if(arguments.contains("-squish")) {
       return true;
   }

   qDebug() << "clientTcp->serverError(): " << clientTcp->errorString();

   if(!clientTcp->errorString().isEmpty()) {
       Dialog *dialog = NULL;
       if (clientTcp->serverError() == QAbstractSocket::AddressInUseError) {
           dialog = new Dialog(tr("VDC"), tr("VDC is already running."), "", "stop", this, Qt::WindowStaysOnTopHint, true);
           dialog->setStyleSheet("QDialog { background-color: #FFFFFF; }" "QPushButton { border-image: url(:pics/VENTAS_11_btn_dialog_rot.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(:pics/VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(:pics/VENTAS_11_btn_dialog_rot_grau.png);}" "QPushButton:focus:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gelb_grau.png);}");
           dialog->createButton(1, "Quit", "Quit", "abbrechen_rot.png");
           connect(dialog->getAction("Quit"), SIGNAL(triggered()), QApplication::instance(), SLOT(quit()));
           dialog->show();
           return false;
      } else {
           dialog = new Dialog(tr("VDC"), QString("There was an error while starting the application.\n\nError message: %1").arg(clientTcp->errorString()), "", "stop", this, Qt::WindowStaysOnTopHint, true);
           dialog->setStyleSheet("QDialog { background-color: #FFFFFF; }" "QPushButton { border-image: url(:pics/VENTAS_11_btn_dialog_gruen.png); padding-right: 10; text-align: left; min-width: 88px; }" "QPushButton:focus { border-image: url(:pics/VENTAS_11_btn_dialog_gelb.png); outline: none;}" "QPushButton:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gruen_grau.png);}" "QPushButton:focus:hover { border-image: url(:pics/VENTAS_11_btn_dialog_gelb_grau.png);}");;
           dialog->createButton(1, "Ok", "Ok", "ok_gruen.png");
           connect(dialog->getAction("Ok"), SIGNAL(triggered()), dialog, SLOT(close()));
           dialog->show();
           return true;
       }
   }

   if(connectionsTab != NULL){
      connect(clientTcp,SIGNAL(newConnection()),connectionsTab,SLOT(addConnection()));
   }
   return true;
}




//------------------------------------------------------------------------------
// Method       : updateListBox()
// Filename     : mainframe.cpp
// Description  : calls the selected program of the shortcut list
//------------------------------------------------------------------------------

void ShortcutsTab::requestApplication()
{
MainFrame::vdcdebug("ShortcutsTab","requestApplication", "");
   QListWidgetItem *p_currWidgetItem = shortcutsListBox->currentItem();

   if(p_currWidgetItem==NULL){
      p_mainframe->statusBar()->showMessage(
            tr("Please select a File first!"),2000);
   }else{
      int i = shortcutsListBox->currentRow();
      ClientSocket *socket = new ClientSocket(0,
                                              u_arr_Shortcuts[i].qs_Username,
                                              u_arr_Shortcuts[i].qs_Password,
                                              u_arr_Shortcuts[i].qs_Application);
      socket->ph.b_read = false;
      socket->ph.b_write = false;

      socket->connectToHost(u_arr_Shortcuts[i].qs_IPadress,
                            3490);

      QList<ClientSocket*> ql_connections;
   }
}


//------------------------------------------------------------------------------
// Method       : dispErrToSB()
// Filename     : mainframe.cpp
// Description  : display QProcessErrors to
//------------------------------------------------------------------------------

void ShortcutsTab::dispErrToSB(){

   QByteArray by_arr_newData = (QByteArray) p_openNetwork->readAllStandardError();

   QString qs_errText = QString::fromLocal8Bit(by_arr_newData);

}

void ShortcutsTab::dispStdOut(){

   QByteArray by_arr_newData = (QByteArray) p_openNetwork->readAllStandardOutput();
   QString qs_outText = QString::fromLocal8Bit(by_arr_newData);

}


//------------------------------------------------------------------------------
// Method       : processError()
// Filename     : mainframe.cpp
// Description  : processError logic
//------------------------------------------------------------------------------

void ShortcutsTab::processError(QProcess::ProcessError ProcessError){
   p_mainframe->statusBar()->showMessage(tr("ERROR: plink.exe: "
         "  %1 ").arg((ProcessError)),2000);
}


//------------------------------------------------------------------------------
// Method       : processFin()
// Filename     : mainframe.cpp
// Description  : process finish logic
//------------------------------------------------------------------------------

void ShortcutsTab::processFin(int i_exitCode, QProcess::ExitStatus exitStatus){

   Q_UNUSED(exitStatus);

   if(i_exitCode == QProcess::CrashExit){

   }else if(i_exitCode != 0){
      p_mainframe->statusBar()->showMessage(tr("plink.exe failed"),2000);

   }else{
      p_mainframe->statusBar()->showMessage(tr("plink.exe: normal exit"),2000);
   }
   p_openNetwork->close();

}


//------------------------------------------------------------------------------
// Method       : lookupForIP()
// Filename     : mainframe.cpp
// Description  : look it up...
//------------------------------------------------------------------------------

void ShortcutsTab::lookupForIP()
{
MainFrame::vdcdebug("ShortcutsTab","lookupForIP", "");
   QHostInfo::lookupHost(QHostInfo::localHostName(),
                         this, SLOT(ipLookupResults(QHostInfo)));

}


//------------------------------------------------------------------------------
// Method       : ipLookupResults()
// Filename     : mainframe.cpp
// Description  : look it up...
//------------------------------------------------------------------------------

void ShortcutsTab::ipLookupResults(const QHostInfo& host)
{
MainFrame::vdcdebug("ShortcutsTab","ipLookupResults", "const QHostInfo& host");

  qs_ipAddress.clear();

  if (host.error() != QHostInfo::NoError) {
      return;
  }

  foreach (QHostAddress address, host.addresses()){
      qs_ipAddress.append(address.toString());
  }
}


//------------------------------------------------------------------------------
// Method       : cleanUp()
// Filename     : mainframe.cpp
// Description  : cleanUp logic for mainframe class
//------------------------------------------------------------------------------

void MainFrame::cleanUp()
{
MainFrame::vdcdebug("MainFrame","cleanUp", "");
   // close the ssh connection if established
   //

   if(p_currOpenNetwork!=NULL){
      if(!p_currOpenNetwork->state()==0){
         p_currOpenNetwork->close();
      }
   }

   if(clientTcp==NULL){
   }else{
      clientTcp->close();
      delete clientTcp;
   }
}

void MainFrame::trayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::Trigger) {
        if(this->isVisible()) {
            this->hide();
        } else {
            this->show();
        }
    }
}
void MainFrame::closeAction()
{
    QList<ScreenHandler*> *ql_screenhandler = MainFrame::ql_screenhandler;

    if(ql_screenhandler)
    {
        if(ql_screenhandler->count() > 0){
            Dialog *dialog = new Dialog("VDC - Ventas Desktop Client", tr("There are open connections.\nDo you really want to quit?"), "", "stop", this, Qt::WindowStaysOnTopHint, true);
            QPalette palette;
            palette.setBrush(dialog->backgroundRole(), Qt::white);
            dialog->setPalette(palette);

            dialog->createButton(1, tr("Yes"), "Yes", "ja.png");
            dialog->getAction("Yes")->setShortcut(Qt::Key_F12);
            dialog->createButton(2, tr("No"), "No", "escape.png");
            dialog->getAction("No")->setShortcut(Qt::Key_Escape);
            connect(dialog->getAction("YES"), SIGNAL(triggered()), this, SLOT(closeVDC()));
            connect(dialog->getAction("NO"), SIGNAL(triggered()), dialog, SLOT(close()));
            dialog->move(600,400);
            dialog->show();
        } else {
            closeSSH = 1;
            waitTimer::msleep(200);
            exit(EXIT_SUCCESS);
        }
    } else {
        closeSSH = 1;
        waitTimer::msleep(200);
        exit(EXIT_SUCCESS);
    }
}

void MainFrame::closeVDC()
{
    VDC::saveSettingsToIni("Ventas AG", "posX", QString::number(pos().x()));
    VDC::saveSettingsToIni("Ventas AG", "posY", QString::number(pos().y()));

    if(ql_screenhandler)
    {
        for(int i=ql_screenhandler->count()-1; i >= 0; i--) {
            if(ScreenHandler *screen = qobject_cast<ScreenHandler*> (ql_screenhandler->at(i))) {
                if(screen->p_fglform) {
                    if(FglForm *p_fglform = qobject_cast<FglForm*> (screen->p_fglform)){
                        p_fglform->close();
                    }
                }
            screen->closeProgramm();
            }
        }
    }

    closeSSH = 1;
    waitTimer::msleep(200);
    exit(EXIT_SUCCESS);

}

void MainFrame::enableDebugModus()
{

    if(this->debugVDC) {
        this->debugVDC = false;
        VDC::saveSettingsToLocalIni("", "debugVDC", QString::number(0));
    } else {
        this->debugVDC = true;
        VDC::saveSettingsToLocalIni("", "debugVDC", QString::number(1));

    }
}

//------------------------------------------------------------------------------
// Method       : closeEvent()
// Filename     : mainframe.cpp
// Description  : override the closeEvent
//------------------------------------------------------------------------------
void MainFrame::closeEvent(QCloseEvent *event)
{
MainFrame::vdcdebug("MainFrame","closeEvent", "QCloseEvent *event");
    QStringList arguments = QApplication::arguments();

    //if(!arguments.contains("-squish")) {
        if (mTray->isVisible()) {
            mTray->showMessage("Ventas Desktop Client", tr("The VDC runs in System Tray"));
            this->hide();
            event->ignore();
        }
    //}
}
void MainFrame::debugClose()
{
MainFrame::vdcdebug("MainFrame","debugClose", "");
emit debugSignal();
}

void MainFrame::debugText(QString text)
{
    if(this->clientTcp->dw->isVisible())
    {
        this->clientTcp->dw->append(text);
    }
}

void MainFrame::requestScreenHandler(int pid, int p_pid)
{
MainFrame::vdcdebug("MainFrame","requestScreenHandler", "int pid, int p_pid");

    ScreenHandler *sh = new ScreenHandler(this->lastmainframe);
    sh->moveToThread(QApplication::instance()->thread());
    sh->pid = pid;
    sh->p_pid = p_pid;

}
void MainFrame::deleteScreenHandler(int pid, int p_pid)
{
MainFrame::vdcdebug("MainFrame","deleteScreenHandler", "int pid, int p_pid");
for(int i=0; i<ql_screenhandler->size();i++)
    {
        if(ql_screenhandler->at(i)->pid == pid && ql_screenhandler->at(i)->p_pid == p_pid)
        {
            ScreenHandler *p_currScreenHandler = ql_screenhandler->at(i);

            if(p_currScreenHandler->p_prompt != NULL){
               p_currScreenHandler->p_prompt->setVisible(false);
               p_currScreenHandler->p_prompt->close();
               p_currScreenHandler->p_prompt->deleteLater();
            }

            p_currScreenHandler->closeAllWindows();
           delete p_currScreenHandler;
        }
    }

}

