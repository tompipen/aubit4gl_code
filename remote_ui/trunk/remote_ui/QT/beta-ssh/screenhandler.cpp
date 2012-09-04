//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// File name    : screenhandler.cpp
// Description  : this is the handler class for the gui
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
#include <QObject>
#include <QHBoxLayout>
#include <QSortFilterProxyModel>
#include <QItemSelectionModel>
#include <QStatusBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QSettings>

#include "screenhandler.h"
#include "mainframe.h"
#include "models/response.h"
#include "models/pulldown.h"
#include "models/statusbar.h"
#include "models/table.h"
#include "models/matrix.h"
#include "xmlparsers/xml2menu.h"
#include "xmlparsers/xml2style.h"
#include <QMutex>
#include "ventasupdate.h"

//------------------------------------------------------------------------------
// Method       : ScreenHandler()
// Filename     : screenhandler.cpp
// Description  : constructor for the instances
//------------------------------------------------------------------------------
ScreenHandler::ScreenHandler(QObject *parent) : QObject(parent)
{
MainFrame::vdcdebug("ScreenHandler","ScreenHandler", "QObject *parent");

   ScreenHandler::cnt_screenhandler++;
   QString test = QString::number(ScreenHandler::cnt_screenhandler);
   this->setObjectName(test);
   //QList<ScreenHandler*> *l_ql_screenhandler =  QList<ScreenHandler*> MainFrame::ql_screenhandler;
   MainFrame::ql_screenhandler->append(this);
   p_pid_p = 0;
   i_mode = 0;
   p_pid = 0;
   cnt_form = 0;
   b_menuEnabled = false;
   p_screenRecord = NULL;
   p_fglform = NULL;
   cursorPos = false;
   p_prompt = NULL;
   timer = NULL;
   w_progress = NULL;
   b_runinfo = false;
   this->installEventFilter(this);
   QApplication::processEvents();
 }


void ScreenHandler::closeAllWindows()
{
    for(int i=ql_fglForms.size()-1; i>=0; i--){
       this->closeWindow(ql_fglForms.at(i)->windowName);
    }

}

void ScreenHandler::setCurrentFocus(QWidget *old, QWidget *current)
{
    Q_UNUSED(old);
    Q_UNUSED(current);

    return;
    if(p_fglform == NULL)
      return;
  QWidget *qw_form = (QWidget*) p_fglform;
  qApp->setActiveWindow(qw_form);
  if(!p_fglform->isEnabled())
  {
      return;
  }

  p_fglform->activateWindow();
  p_fglform->raise();
}

//------------------------------------------------------------------------------
// Method       : ~ScreenHandler()
// Filename     : screenhandler.cpp
// Description  : destructor for the instances
//------------------------------------------------------------------------------
ScreenHandler::~ScreenHandler()
{
MainFrame::vdcdebug("ScreenHandler","~ScreenHandler", "");
    QList<ScreenHandler*> *l_ql_screenhandler = MainFrame::ql_screenhandler;

    for(int i = 0; i<l_ql_screenhandler->size(); i++)
    {
        if(l_ql_screenhandler->at(i)->p_pid_p == this->p_pid)
        {
            //Reset Runinfo
            l_ql_screenhandler->at(i)->setRuninfo(0, "", 0, false);
        }
    }

    if(w_progress != NULL)
    {
        w_progress->hide();
        w_progress->deleteLater();
    }

    l_ql_screenhandler->removeOne(this);

    foreach(Context *c, contexts)
    {
        delete c;
    }
    //delete  &contexts;

    QApplication::processEvents();
}

//------------------------------------------------------------------------------
// Method       : ~ScreenHandler()
// Filename     : screenhandler.cpp
// Description  : initializes some values
//------------------------------------------------------------------------------
void ScreenHandler::initForm(int i_Frm)
{
MainFrame::vdcdebug("ScreenHandler","initForm", "int i_Frm");
   qh_formFields.remove(i_Frm);
   qh_formActionMenus.remove(i_Frm);
}

//------------------------------------------------------------------------------
// Method       : ~ScreenHandler()
// Filename     : screenhandler.cpp
// Description  : returns actual form count
//------------------------------------------------------------------------------
int ScreenHandler::getCurrForm()
{
MainFrame::vdcdebug("ScreenHandler","getCurrForm", "");
   return cnt_form-1;
}

int ScreenHandler::getCurrWindow()
{
MainFrame::vdcdebug("ScreenHandler","getCurrWindow", "");
   return cnt_form-1;
}

//------------------------------------------------------------------------------
// Method       : createWindow()
// Filename     : screenhandler.cpp
// Description  : creates the Form. prepares for displaying it
//------------------------------------------------------------------------------
void ScreenHandler::createWindow(QString windowTitle,QString style, int x, int y, int h, int w, QString formfile, QString id)
{
MainFrame::vdcdebug("ScreenHandler","createWindow", "QString windowTitle,QString style, int x, int y, int h, int w, QString id");
   Q_UNUSED(x);
   Q_UNUSED(y);
   Q_UNUSED(h);
   Q_UNUSED(w);

   cnt_form++;
   if(p_fglform != NULL)
   {
      p_fglform->setEnabled(false);
      /*
      if(p_fglform->actionMenu())
      {
         p_fglform->actionMenu()->restoreButtonIcon();
         p_fglform->actionMenu()->restoreButtonPalette();
      }*/
/*
      if(p_fglform->menu() != NULL)
         p_fglform->menu()->setEnabled(false);
*/
   }
   //p_fglform = new FglForm(windowTitle, parentWidget);
   //p_fglform = new FglForm(windowTitle, p_fglform);
   p_fglform = new FglForm(windowTitle);
   p_fglform->setFormName(formfile);
   p_fglform->installEventFilter(this);
   p_fglform->setScreenHandler(this);
   if(windowTitle == "dummy_ventas")
   {
       p_fglform->hide();
       p_fglform->b_dummy = true;
       dummy_fglform = p_fglform;
       cnt_form--;
   }
   p_fglform->setId(id);
   connect(p_fglform, SIGNAL(processResponse()), this, SLOT(processResponse()));
   connect(p_fglform, SIGNAL(sendDirect(QString)), this, SLOT(sendDirect(QString)));
   connect(p_fglform, SIGNAL(setClearEvents()), this, SLOT(setClearEvents()));
   connect(p_fglform, SIGNAL(setArrLine(int)), this, SLOT(setArrLine(int)));
 //  connect(p_fglform, SIGNAL(closeAction()), this, SLOT(closeProgramm()));

   if(!qs_interfaceTitle.isNull())
      p_fglform->setWindowTitle(qs_interfaceTitle);
   else{
      p_fglform->setWindowTitle(windowTitle);
   }

   p_fglform->windowName = windowTitle;


   if(!p_fglform->b_dummy)
   {
      p_fglform->setStartMenu(startMenu);
      startMenu.clear();
   }
   if(style.isEmpty()){
      style = "default";
   }

   p_fglform->setProperty("style", style);

   ql_fglForms << p_fglform;

   if(formsToolBar.hasChildNodes()){
      p_fglform->setToolBar(formsToolBar);
   }

   p_fglform->setStyles(formsStyles);

   p_fglform->initActions();
   this->handleIconFile(xmlIconDoc);
   this->handleShortcutsFile(xmlShortcutDoc);
   if(formsActions.hasChildNodes()){
      p_fglform->setActions(formsActions);
   }

   checkColors();
}

FglForm* ScreenHandler::currForm()
{
MainFrame::vdcdebug("ScreenHandler","currForm", "");
   return p_fglform;
}

//------------------------------------------------------------------------------
// Method       : handleXMLForm()
// Filename     : screenhandler.cpp
// Description  : passes the FormFile to the parsing function and adds
//                the returning layouts and fields to the FglForm
//------------------------------------------------------------------------------
void ScreenHandler::handleXMLForm(QString formName, QString xmlFormString, bool openWindow)
{
MainFrame::vdcdebug("ScreenHandler","handleXMLForm", "QString formName, QString xmlFormString, bool openWindow");
   qh_formFiles[formName] = xmlFormString;

   if(openWindow){
      QDomDocument xmlForm;
      xmlForm.setContent(xmlFormString);

      p_fglform->setFormLayout(xmlForm);
   }
}

//------------------------------------------------------------------------------
// Method       : handleAubitForm()
// Filename     : screenhandler.cpp
// Description  : passes the FormFile to the parsing function and adds
//                the returning layouts and fields to the FglForm
//------------------------------------------------------------------------------
void ScreenHandler::handleAubitForm(QString formName, QString xmlFormString, bool openWindow)
{
MainFrame::vdcdebug("ScreenHandler","handleAubitForm", "QString formName, QString xmlFormString, bool openWindow");

   qh_formFiles[formName] = xmlFormString;

   if(openWindow){
      QDomDocument xmlForm;
      xmlForm.setContent(xmlFormString);

      p_fglform->setFormLayout(xmlForm);
   }

}
//------------------------------------------------------------------------------
// Method       : closeProgramm()
// Filename     : screenhandler.cpp
// Description  : close the programm
//------------------------------------------------------------------------------
void ScreenHandler::closeProgramm()
{
   if(p_fglform != NULL)
   {
      QString qs_pid;
      qs_pid.number(this->pid);
      QString qs_resp = "<TRIGGERED ID=\"-999\" ENVELOPEID=\""+qs_pid+"\"/>";
      if(this->ph)
          QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, qs_resp));
      else
        fglFormResponse(qs_resp);
   }
}

//------------------------------------------------------------------------------
// Method       : handleXMLForm()
// Filename     : screenhandler.cpp
// Description  : passes the FormFile to the parsing function and adds
//                the returning layouts and fields to the FglForm
//------------------------------------------------------------------------------
void ScreenHandler::displayForm(QString formName)
{
MainFrame::vdcdebug("ScreenHandler","displayForm", "QString formName");
   QString xmlFormString = qh_formFiles[formName];

   if(!xmlFormString.isEmpty()){

      QDomDocument xmlForm;
      xmlForm.setContent(xmlFormString);

      p_fglform->setFormLayout(xmlForm);
   }
   else{
      qFatal("No such form %s", qPrintable(formName));
   }
   if(!p_fglform->b_dummy)
   {
       p_fglform->show();
   }
}

//-------------------------------------------------------       -----------------------
// Method       : handleXMLToolBar(QString xmlFile)
// Filename     : screenhandler.cpp
// Description  : creates the ToolBar (4tb file)
//------------------------------------------------------------------------------
void ScreenHandler::handleXMLToolBar(QString xmlFileString)
{
MainFrame::vdcdebug("ScreenHandler","handleXMLToolBar", "QString xmlFileString");

   QDomDocument xmlFile;
   xmlFile.setContent(xmlFileString);

   formsToolBar = xmlFile;
}

//------------------------------------------------------------------------------
// Method       : handleXMLToolBar(QString xmlFile)
// Filename     : screenhandler.cpp
// Description  : creates the ToolBar
//------------------------------------------------------------------------------
void ScreenHandler::handleXMLStartMenu(QString xmlFileString)
{
MainFrame::vdcdebug("ScreenHandler","handleXMLStartMenu", "QString xmlFileString");

   QDomDocument xmlFile;
   if(!xmlFile.setContent(xmlFileString)){
   }

   if(getCurrForm() == -1){
      startMenu = xmlFile;
   }
   else{
      if(p_fglform != NULL && !p_fglform->b_dummy)
       {
          p_fglform->setStartMenu(xmlFile);
       }
      if(!p_fglform->b_dummy)
      {
          startMenu = xmlFile;
      }
  }

}

//------------------------------------------------------------------------------
// Method       : handleXMLActions(QString xmlFile)
// Filename     : screenhandler.cpp
// Description  : action defaults like "Find" etc. 4ad file
//------------------------------------------------------------------------------
void ScreenHandler::handleXMLActions(QString xmlFileString)
{
MainFrame::vdcdebug("ScreenHandler","handleXMLActions", "QString xmlFileString");

   QDomDocument xmlFile;
   QString errorMsg;
   int errorLine, errorCol;
   if (!xmlFile.setContent(xmlFileString, &errorMsg, &errorLine, &errorCol)){
      QString str = errorMsg + "\n" +
                    "Line:" + QString::number(errorLine) + "\n" +
                    "Column" + QString::number(errorCol) + "\n\n" +
                    "Protocol : " + "\n" +
                    xmlFileString;
      MsgBox("Protocol Error",str,"Warning","Ok","Ok",0);
   }


   if(formsActions.isNull())
   {
       formsActions = xmlFile;
   } else if(formsActions1.isNull()){
       formsActions1 = xmlFile;
   } else {
       formsActions2 = xmlFile;
   }
}

void ScreenHandler::handleIconFile(QDomDocument xmlFileString)
{
    p_fglform->ql_actions = new Actions(p_fglform);
    p_fglform->ql_actions->parseFile(xmlFileString);
}

void ScreenHandler::handleShortcutsFile(QDomDocument xmlFileString)
{
    if(p_fglform->ql_actions == NULL)
    {
        p_fglform->ql_actions = new Actions(p_fglform);
    }
    p_fglform->ql_actions->parseFile(xmlFileString);
}

void ScreenHandler::handleXMLColors(QString xmlFileString)
{
MainFrame::vdcdebug("ScreenHandler","handleXMLFormColors", "QString xmlFileString");

   QDomDocument xmlFile;
   QString errorMsg;
   int errorLine, errorCol;
   if (!xmlFile.setContent(xmlFileString, &errorMsg, &errorLine, &errorCol)){
      QString str = errorMsg + "\n" +
                    "Line:" + QString::number(errorLine) + "\n" +
                    "Column" + QString::number(errorCol) + "\n\n" +
                    "Protocol : " + "\n" +
                    xmlFileString;
      MsgBox("Protocol Error",str,"Warning","Ok","Ok",0);
   }



   if(xmlFile.firstChild().nodeName().toUpper() ==  "FORMS")
   {
       QDomNodeList children = xmlFile.firstChild().childNodes();

       for(int i=0; i<children.count(); ++i){
          QDomNode child = children.at(i);

          QDomElement ele = child.toElement();

          if(ele.nodeName().toUpper() == "FORM"){
              QString form = ele.attribute("name");
              QString color = ele.attribute("color");

              qh_formcolors[form] = color;
            }
   }

}
   checkColors();
}

void ScreenHandler::checkColors()
{
  if(ql_fglForms.size() > 0)
  {
      for(int i = 0; i<ql_fglForms.size(); i++)
      {

          QString form = ql_fglForms.at(i)->formName();
          if(form.length() > 0)
          {
              QString color = qh_formcolors[form];
              if(color.length() > 0)
              {
                 ql_fglForms.at(i)->showColorBar(color);
              }
          }

      }
  }
}


//------------------------------------------------------------------------------
// Method       : handleXMLStyles(QString xmlFile)
// Filename     : screenhandler.cpp
// Description  : stylesheets 4st file
//------------------------------------------------------------------------------
void ScreenHandler::handleXMLStyles(QString xmlFileString)
{
MainFrame::vdcdebug("ScreenHandler","handleXMLStyles", "QString xmlFileString");

   QDomDocument xmlFile;
   QString errorMsg;
   int errorLine, errorCol;
   if (!xmlFile.setContent(xmlFileString, &errorMsg, &errorLine, &errorCol)){
      QString str = errorMsg + "\n" +
                    "Line:" + QString::number(errorLine) + "\n" +
                    "Column" + QString::number(errorCol) + "\n\n" +
                    "Protocol : " + "\n" +
                    xmlFileString;
      MsgBox("Protocol Error",str,"Warning","Ok","Ok",0);
   }

   formsStyles = xmlFile;
}

//------------------------------------------------------------------------------
// Method       : createMenu(QString title, QString FieldValue)
// Filename     : screenhandler.cpp
// Description  : creates the ring menu element (ButtonGroup)
//------------------------------------------------------------------------------
void ScreenHandler::createMenu(QString title, QString comment, QString style, QString image)
{
MainFrame::vdcdebug("ScreenHandler","createMenu", "QString title, QString comment, QString style, QString image");
   int i_Frm = getCurrForm();


   // If menustyle is dialog
   if(style == "dialog"){
      createDialog(title, comment, style, image);
      return;
   }
   if(style == "pulldown")
   {
       createPulldown(title, comment, style, image);
       return;
   }
   if(i_Frm < 0)
      return;
   QWidget *fglform = p_fglform;
   RingMenu *ringMenu = new RingMenu(title, fglform, style);

   p_fglform->setMenu(ringMenu);
}

//------------------------------------------------------------------------------
// Method       : createMenuButton(int buttonId, QString text, QString desc)
// Filename     : screenhandler.cpp
// Description  : creates the menubutton and adds it to the buttongroup
//------------------------------------------------------------------------------
void ScreenHandler::createMenuButton(int buttonId, QString text, QString desc, QStringList keys)
{
MainFrame::vdcdebug("ScreenHandler","createMenuButton", "int buttonId, QString text, QString desc, QStringList keys");

  Q_UNUSED(keys);

  int i_Frm = getCurrForm();


   if(p_fglform == NULL)
      return;

   if(p_fglform->dialog() != NULL){
      createDialogButton(buttonId, text, desc);
      return;
  }

   if(p_fglform->ringMenuPulldown() != NULL){
      this->createPulldownButton(buttonId, text, desc);
      return;
   }

   if(p_fglform->menu() == NULL)
      return;

   if(i_Frm < 0)
      return;
   RingMenu *ringMenu = p_fglform->menu();

   QPushButton *pb = ringMenu->createButton(buttonId, text, desc);
   QAction *action = ringMenu->getAction(text.toLower());
   connect(action, SIGNAL(triggered()), p_fglform, SLOT(actionTriggered()));
   connect(pb, SIGNAL(pressed()), p_fglform->context, SLOT(focusChanged()));

   Fgl::Event event;
   event.type = Fgl::MENUACTION_EVENT;
   event.id = QString::number(buttonId);
   event.attribute = text.toLower(); //Fgl::stringToKey(attribute);
   p_fglform->ql_menuEvents << event;
   p_fglform->addFormEvent(event);
}

//------------------------------------------------------------------------------
// Method       : createMenuAction(int buttonId, QString text)
// Filename     : screenhandler.cpp
// Description  : creates the menuaction and adds it to the buttongroup
//------------------------------------------------------------------------------
void ScreenHandler::createMenuAction(int buttonId, QString text)
{
MainFrame::vdcdebug("ScreenHandler","createMenuAction", "int buttonId, QString text");

  int i_Frm = getCurrForm();



   if(p_fglform == NULL)
      return;

   if(p_fglform->dialog() != NULL){
      createDialogAction(buttonId, text);
      return;
   }

   if(p_fglform->ringMenuPulldown() != NULL){
       createPulldownButton(buttonId,text,"");
       return;
   }
   if(i_Frm < 0)
      return;

   if(p_fglform->menu() == NULL)
      return;

   RingMenu *ringMenu = p_fglform->menu();

   ringMenu->createAction(buttonId, text);
   QAction *action = ringMenu->getAction(text.toLower());
   connect(action, SIGNAL(triggered()), p_fglform, SLOT(actionTriggered()));

   Fgl::Event event;
   event.type = Fgl::MENUACTION_EVENT;
   event.id = QString::number(buttonId);
   event.attribute = text.toLower(); //Fgl::stringToKey(attribute);
   p_fglform->ql_menuEvents << event;
   p_fglform->addFormEvent(event);

}

//------------------------------------------------------------------------------
// Method       : enableMenu(bool enable)
// Filename     : screenhandler.cpp
// Description  : Enables or disables the menu
//------------------------------------------------------------------------------
void ScreenHandler::setMenuEnabled(bool enable)
{
MainFrame::vdcdebug("ScreenHandler","setMenuEnabled", "bool enable");
  int i_Frm = getCurrForm();

   if(i_Frm < 0)
      return;

   b_menuEnabled = enable;
   p_fglform->setMenuEnabled(enable);
   p_fglform->setActionMenuEnabled(!enable);

}

//------------------------------------------------------------------------------
// Method       : hideOption(QString title, QString FieldValue)
// Filename     : screenhandler.cpp
//------------------------------------------------------------------------------
void ScreenHandler::hideOption(QString name)
{
MainFrame::vdcdebug("ScreenHandler","hideOption", "QString name");
   if(p_fglform == NULL)
      return;
   // Description  : hide menu commands

   if(p_fglform->dialog() != NULL){
      p_fglform->dialog()->hideButton(name);
      return;
   }

   if(p_fglform->ringMenuPulldown() != NULL){
      p_fglform->ringMenuPulldown()->hideButton(name);
       return;
   }

   if(p_fglform->menu() != NULL){
      p_fglform->menu()->hideButton(name);
      return;
   }
}

//------------------------------------------------------------------------------
// Method       : hideOption(QString title, QString FieldValue)
// Filename     : screenhandler.cpp
// Description  : hide menu commands
//------------------------------------------------------------------------------
void ScreenHandler::showOption(QString name)
{
MainFrame::vdcdebug("ScreenHandler","showOption", "QString name");
   if(p_fglform == NULL)
      return;

   if(p_fglform->dialog() != NULL){
      p_fglform->dialog()->showButton(name);
      return;
   }
   if(p_fglform->ringMenuPulldown() != NULL){
       p_fglform->ringMenuPulldown()->showButton(name);
       return;
   }

   if(p_fglform->menu() != NULL){
      p_fglform->menu()->showButton(name);
      return;
   }
}

//------------------------------------------------------------------------------
// Method       : hideOption(QString name)
// Filename     : screenhandler.cpp
// Description  : hide menu commands
//------------------------------------------------------------------------------
void ScreenHandler::nextOption(QString name, int i_context)
{
MainFrame::vdcdebug("ScreenHandler","nextOption", "QString name, int context");

   Context *context = this->getContext(i_context);

   for(int i=0; i<ql_fglForms.size(); i++){
      if(ql_fglForms.at(i)->context == context){
         this->activeWindow(ql_fglForms.at(i)->windowName);
      }
   }

   if(p_fglform == NULL)
      return;

   if(p_fglform->dialog() != NULL){
      return;
   }
   if(p_fglform->ringMenuPulldown() != NULL){
       return;
   }

   if(p_fglform->menu() != NULL){
      // p_fglform->menu()->selectButton(name);
       p_fglform->menu()->setFocusName(name.trimmed());
       return;
    }
 }

//------------------------------------------------------------------------------
// Method       : createDialog(QString title, QString FieldValue)
// Filename     : screenhandler.cpp
// Description  : creates the horizontal ring menu or some other dialog
//------------------------------------------------------------------------------
void ScreenHandler::createDialog(QString title, QString comment, QString style, QString image)
{
MainFrame::vdcdebug("ScreenHandler","createDialog", "QString title, QString comment, QString style, QString image");
   if(p_fglform == NULL)
      return;

   //Dialog *p_dialog = new Dialog(title, comment, style, image, p_fglform);
   Dialog *p_dialog = new Dialog(title, comment, style, image, p_fglform);
   connect(p_dialog, SIGNAL(destroyed()), this, SLOT(activeFocus()));
   p_fglform->setDialog(p_dialog);
   //clearEvents();

}

//------------------------------------------------------------------------------
// Method       : createDialogButton(int buttonId, QString text, QString desc)
// Filename     : screenhandler.cpp
// Description  : creates the menubutton and adds it to the buttongroup
//------------------------------------------------------------------------------
void ScreenHandler::createDialogButton(int buttonId, QString text, QString desc)
{
MainFrame::vdcdebug("ScreenHandler","createDialogButton", "int buttonId, QString text, QString desc");

  //int i_Frm = getCurrForm();

   Dialog* p_dialog = p_fglform->dialog();
   if(p_fglform == NULL)
      return;

   if(p_dialog == NULL)
      return;

   p_dialog->createButton(buttonId, text, desc);
   QAction *action = p_dialog->getAction(text.toLower());
   connect(action, SIGNAL(triggered()), p_fglform, SLOT(actionTriggered()));

   Fgl::Event event;
   event.type = Fgl::MENUACTION_EVENT;
   event.id = QString::number(buttonId);
   event.attribute = text.toLower(); //Fgl::stringToKey(attribute);
   p_fglform->ql_dialogEvents << event;
   p_fglform->addFormEvent(event);
}

//------------------------------------------------------------------------------
// Method       : createPulldown(QString title, QString FieldValue)
// Filename     : screenhandler.cpp
// Description  : creates the pulldownmenu
//------------------------------------------------------------------------------
void ScreenHandler::createPulldown(QString title, QString comment, QString style, QString image)
{
MainFrame::vdcdebug("ScreenHandler","createDialog", "QString title, QString comment, QString style, QString image");
   if(p_fglform == NULL)
      return;

   //Dialog *p_dialog = new Dialog(title, comment, style, image, p_fglform);
   RingMenuPulldown *pulldown = new RingMenuPulldown(title, comment, style, image); //, p_fglform);
   pulldown->setStyleSheet(p_fglform->styleSheet());
   //connect(pulldown, SIGNAL(clicked()), p_fglform, SLOT(close()));
   p_fglform->setRingMenuPulldown(pulldown);
   connect(pulldown, SIGNAL(destroyed()), this, SLOT(activeFocus()));
   //clearEvents();

}

//------------------------------------------------------------------------------
// Method       : createPulldownButton(int buttonId, QString text, QString desc)
// Filename     : screenhandler.cpp
// Description  : creates the menubutton and adds it to the Pulldownmenu
//------------------------------------------------------------------------------
void ScreenHandler::createPulldownButton(int buttonId, QString text, QString desc)
{
MainFrame::vdcdebug("ScreenHandler","createPulldownButton", "int buttonId, QString text, QString desc");

  //int i_Frm = getCurrForm();

   RingMenuPulldown* pulldown = p_fglform->ringMenuPulldown();
   if(p_fglform == NULL)
      return;

   if(pulldown == NULL)
      return;

   pulldown->createButton(buttonId, text, desc);
   QAction *action = pulldown->getAction(text.toLower());
   connect(action, SIGNAL(triggered()), p_fglform, SLOT(actionTriggered()));


   Fgl::Event event;
   event.type = Fgl::MENUACTION_EVENT;
   event.id = QString::number(buttonId);
   event.attribute = text.toLower(); //Fgl::stringToKey(attribute);
   p_fglform->ql_pulldownEvents << event;
   p_fglform->addFormEvent(event);
}


//------------------------------------------------------------------------------
// Method       : createDialogButton(int buttonId, QString text, QString desc)
// Filename     : screenhandler.cpp
// Description  : creates the menubutton and adds it to the buttongroup
//------------------------------------------------------------------------------
void ScreenHandler::createDialogAction(int buttonId, QString text)
{
MainFrame::vdcdebug("ScreenHandler","createDialogAction", "int buttonId, QString text");

  //int i_Frm = getCurrForm();

   Dialog* p_dialog = p_fglform->dialog();
   if(p_fglform == NULL)
      return;

   if(p_dialog == NULL)
      return;

   p_dialog->createAction(buttonId, text);
   QAction *action = p_dialog->getAction(text.toLower());
   connect(action, SIGNAL(triggered()), p_fglform, SLOT(actionTriggered()));

   Fgl::Event event;
   event.type = Fgl::MENUACTION_EVENT;
   event.id = QString::number(buttonId);
   event.attribute = text.toLower(); //Fgl::stringToKey(attribute);
   p_fglform->ql_dialogEvents << event;
   p_fglform->addFormEvent(event);
}

//------------------------------------------------------------------------------
// Method       : createDialog(QString title, QString FieldValue)
// Filename     : screenhandler.cpp
// Description  : creates the horizontal ring menu or some other dialog
//------------------------------------------------------------------------------
void ScreenHandler::createPrompt(QString text, int charMode, int fieldAttribute, QString style)
{
MainFrame::vdcdebug("ScreenHandler","createPrompt", "QString text, int charMode, int fieldAttribute, QString style");
   Q_UNUSED(style);

   p_prompt = new Prompt(text, charMode, fieldAttribute);
   p_prompt->activateWindow();
   p_prompt->raise();
   connect(p_prompt, SIGNAL(sendDirect(QString)), this, SLOT(sendDirect(QString)));
}

//------------------------------------------------------------------------------
// Method       : setFieldBuffer(QStringList FieldNames, QStringList FieldValues)
// Filename     : screenhandler.cpp
// Description  : sets the Text for the Field
//------------------------------------------------------------------------------
void ScreenHandler::setFieldBuffer(QStringList fieldNames, QStringList fieldValues, int attr)
{
MainFrame::vdcdebug("ScreenHandler","setFieldBuffer", "QStringList fieldNames, QStringList fieldValues, int attr");
   int value_cnt = 0;
   if(p_fglform == NULL)
      return;

   for(int i=0; i<fieldNames.count(); i++){
      QString fieldName = fieldNames.at(i);

      int index = fieldName.indexOf(".*");

      if(index < 0){
         QWidget *widget = p_fglform->findFieldByName(fieldName);
         if(widget == NULL){
            return;
         }

         if(LineEditDelegate *led = qobject_cast<LineEditDelegate *> (widget)){
             Q_UNUSED(led);
            int index2 = fieldName.indexOf("[");
            int index3 = fieldName.indexOf("]")+1;
            int row;

            if(index2 > 0){
               row = fieldName.mid(index2+1, index3-index2-1-1).toInt()-1;
               fieldName.remove(index2, index3-index2);
            }
            else{
               row = 0;
            }
    //Deactive because Segmentationfaults on Screenarrays. For Ventas currently not needed, but planed for the feature.
    //        WidgetHelper::setDisplayAttributes(attr, widget);

            //count +1 cause we reduce the row in setArrayBuffer
          //  row++;
            QStringList values;
            values << fieldValues.at(i);
            setArrayBuffer(row, fieldName, values);
         }
         else{
            WidgetHelper::setDisplayAttributes(attr, widget);
            WidgetHelper::setFieldText(widget, fieldValues.at(i));
         }
      }
      else{
         QList<QWidget*> ql_fields = p_fglform->findFieldsByName(fieldName);
         for(int j=0; j<ql_fields.count(); j++){
            QWidget *widget = ql_fields.at(j);
            if(qobject_cast<LineEditDelegate *> (widget)){
               int index2 = fieldName.indexOf("[");
               int index3 = fieldName.indexOf("]")+1;
               int row;

               if(index2 > 0){
                  row = fieldName.mid(index2+1, index3-index2-1-1).toInt()-1;
                  fieldName.remove(index2, index3-index2);
               }
               else{
                  row = 0;
               }

               QStringList values;
               for(int k=0; k<ql_fields.count(); k++){
                  values << fieldValues.at(value_cnt+k);
               }
               WidgetHelper::setDisplayAttributes(attr, widget);
               setArrayBuffer(row, fieldName, values);
               value_cnt = ql_fields.count();
               break;
            }
            else{
               WidgetHelper::setDisplayAttributes(attr, widget);
               WidgetHelper::setFieldText(widget, fieldValues.at(value_cnt));
               value_cnt++;
            }
         }
      }
   }
}

//------------------------------------------------------------------------------
// Method       : setFieldBuffer(QString FieldName, QString FieldValue)
// Filename     : screenhandler.cpp
// Description  : sets the Text for the Field
//------------------------------------------------------------------------------
void ScreenHandler::setFieldBuffer(int fieldNo, QString fieldValue, int attr)
{
MainFrame::vdcdebug("ScreenHandler","setFieldBuffer", "int fieldNo, QString fieldValue, int attr");
   int i_Frm = getCurrForm();
   if(i_Frm < 0)
      return;

   Context *context = getCurrentContext();
   if(context == NULL)
      return;

   if(context->fieldList().count()-1 >= fieldNo){
      QWidget *widget = context->fieldList().at(fieldNo);
      if(widget == NULL)
      {
         return;
      }
      if(LineEditDelegate *de = qobject_cast<LineEditDelegate *> (widget)){
         Q_UNUSED(de);
      }
      else{
              WidgetHelper::setDisplayAttributes(attr, widget);
              WidgetHelper::setFieldText(widget, fieldValue);

      }
      return;
   }
   else{
     qWarning("ERROR: Too many Fields for setFieldBuffer");
      return;
   }


   QString fieldName;
   if(context->fieldList().count()-1 >= fieldNo){
      fieldName = context->fieldList().at(fieldNo)->accessibleName();
   }
   else{
      qFatal("Field not found in ScreenHandler::setFieldBuffer(int, QString)");
   }

   QWidget *widget = p_fglform->findFieldByName(fieldName);
   if(qobject_cast<LineEditDelegate *> (widget)){
      int index2 = fieldName.indexOf("[");
      int index3 = fieldName.indexOf("]")+1;
      int row;

      if(index2 > 0){
         row = fieldName.mid(index2+1, index3-index2-1-1).toInt()-1;
         fieldName.remove(index2, index3-index2);
      }
      else{
         row = 0;
      }

      QStringList values;
      values << fieldValue;
      setArrayBuffer(row+1, fieldName, values);
   }
   else{
      WidgetHelper::setDisplayAttributes(attr, widget);
      WidgetHelper::setFieldText(widget, fieldValue);

   }
}

//------------------------------------------------------------------------------
// Method       : setFieldBuffer(QString FieldName, QString FieldValue)
// Filename     : screenhandler.cpp
// Description  : sets the Text for the Field
//------------------------------------------------------------------------------
void ScreenHandler::clearFieldBuffer(QString fieldName)
{
MainFrame::vdcdebug("ScreenHandler","clearFieldBuffer", "QString fieldName");
   int index = fieldName.indexOf(".*");

   if(index < 0){
      QWidget *widget = p_fglform->findFieldByName(fieldName);
      if(LineEditDelegate *de = qobject_cast<LineEditDelegate *> (widget)){
         if(qobject_cast<TableView *> (de->parent())){
            int index2 = fieldName.indexOf("[");
            int index3 = fieldName.indexOf("]")+1;
            int row;

            if(index2 > 0){
               row = fieldName.mid(index2+1, index3-index2-1-1).toInt()-1;
               fieldName.remove(index2, index3-index2);
            }
            else{
               row = 0;
            }
            QStringList values;
            values << QString("");
            setArrayBuffer(row, fieldName, values);
         }
      }
      else{
         WidgetHelper::setFieldText(widget, "");
      }
   }
   else{
      QList<QWidget*> ql_fields = p_fglform->findFieldsByName(fieldName);
      for(int j=0; j<ql_fields.count(); j++){
         QWidget *widget = ql_fields.at(j);
         WidgetHelper::setFieldText(widget, "");
      }
   }
}

//------------------------------------------------------------------------------
// Method       : setArrayBuffer(QWidget* tableView, QString fieldName, QString fieldValue)
// Filename     : screenhandler.cpp
// Description  : sets the Text for the Field in display/input array
//------------------------------------------------------------------------------
/*void ScreenHandler::setArrayBuffer(QWidget* tableView, QString fieldName, QString fieldValue)
{
MainFrame::vdcdebug("ScreenHandler","setArrayBuffer", "QWidget* tableView, QString fieldName, QString fieldValue");
   TableView *screenRecord = qobject_cast<TableView *> (tableView);
   if(screenRecord == NULL){
      return;
   }

   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (screenRecord->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());


   int row = -1;
   int col = -1;

   if(!fieldName.contains("[") && !fieldName.contains("]")){
      int index1 = fieldName.indexOf(".");
      fieldName.insert(index1, "[1]");
   }

   int index = fieldName.indexOf("[");
   int index2 = fieldName.indexOf("]");
   row = fieldName.mid(index+1, (index2-index-1)).toInt()-1;

   index = fieldName.indexOf(".");
   QString colName = fieldName.mid(index+1, fieldName.length()-index+1);

   for(int i=0; i<table->qsl_colNames.count(); i++){
      if(table->qsl_colNames.at(i) == colName){
         col = i;
      }
   }

   if(!(row < 0 || col < 0)){
      screenRecord->setText(fieldValue.trimmed(),row, col);
   }
}
*/

void ScreenHandler::setArrayBuffer(int row, QString tabName, QStringList fieldValues)
{
MainFrame::vdcdebug("ScreenHandler","setArrayBuffer", "int row, QString tabName, QStringList fieldValues");
   int index = tabName.indexOf(".*");
   int cnt_values = 0;
   //TableView *tableView;
   if(index < 0){
      for(int i=0; i<fieldValues.count(); i++){
         if(LineEditDelegate *de = qobject_cast<LineEditDelegate *> (p_fglform->findFieldByName(tabName))){
            int col = de->column();
            if(TableView *tableView = qobject_cast<TableView *> (de->parent())){
               //QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (tableView->model());
               //TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

               QString fieldValue = fieldValues.at(i);
               tableView->setText(fieldValue, row, col);
            }
         }
      }
   }
   else{
      QList<QWidget*> ql_fields = p_fglform->findFieldsByName(tabName);
      for(int i=0; i<ql_fields.count(); i++){
         QWidget *widget = ql_fields.at(i);

         if(LineEditDelegate *de = qobject_cast<LineEditDelegate *> (widget)){
            if(TableView *tableView = qobject_cast<TableView *> (de->parent())){
               QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (tableView->model());
               TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
               int col = table->columnCount(QModelIndex())-1;
               if(col > 0)
                  col = i;
   
               /*
               if(table->rowCount(QModelIndex()) < row+1){
                  table->insertRow(row, QModelIndex());
               }
               */
   
               QString fieldValue = fieldValues.at(i);
               tableView->setText(fieldValue, row, col);
            }
            cnt_values++;
         }
      }
   }

   //Edit wurde für jede zeile ausgeführt, so ging der fokus kaputt und immer diese
   //nervigen Shell prints: invalid index

   /*
   // VERMUTLICH HIER WEITERMACHEN
QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (tableView->model());
TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
QModelIndex qmindex = tableView->currentIndex();
if(table->b_input){

//tableView->setCurrentField(tableView->row, tableView->col);
}*/
}

void ScreenHandler::setArrayBuffer(int row, QStringList fieldValues)
{
MainFrame::vdcdebug("ScreenHandler","setArrayBuffer", "int row, QStringList fieldValues");
   Context *context = getCurrentContext();

   for(int i=0; i<context->fieldList().count(); i++){
      QWidget *widget = context->fieldList().at(i);

      if(TableView *tableView = qobject_cast<TableView *> (widget)){
         QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (tableView->model());
         TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

         if(fieldValues.count() != table->columnCount(QModelIndex())){
            qFatal("ERROR: Too many or too few values for Table");
         }

         for(int col=0; col<table->columnCount(QModelIndex()); col++){
            QString fieldValue = fieldValues.at(col);
            tableView->setText(fieldValue, row, col);
         }
      }
   }
}

//------------------------------------------------------------------------------
// Method       : setArrayBuffer(QStringList fieldValues)
// Filename     : screenhandler.cpp
// Description  : sets the Text for the Fields in display/input array
//------------------------------------------------------------------------------
void ScreenHandler::loadArrayValues(QStringList qsl_arrayValues)
{
MainFrame::vdcdebug("ScreenHandler","loadArrayValues", "QStringList qsl_arrayValues");
   if(p_fglform == NULL)
      return;

//   QList<QWidget*> ql_fields = p_fglform->formElements();
   QList<QWidget*> ql_fields = p_fglform->ql_formFields;
   for(int k=0; k<ql_fields.size(); k++){
      if(TableView *tableView = qobject_cast<TableView *> (ql_fields.at(k))){

         QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (tableView->model());
         TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
         if(tableView->isEnabled()){
            if(tableView->maxArrSize() < table->rowCount(QModelIndex())){
               for(int p=table->rowCount(QModelIndex()); p>0; p--){
                  table->removeRows(p, 1, QModelIndex());
               }
            }

            int colCount = table->columnCount(QModelIndex());
            int row = 0;

            for(int i=0; i<qsl_arrayValues.count(); i+=colCount){
               if(i+colCount<=qsl_arrayValues.count()){
                  for(int j=0; j<colCount; j++){
                     // if table has not enough rows add one
                     /*
                     if(table->rowCount(QModelIndex()) < row+1){
                        table->insertRows(row, 1, QModelIndex());
                     }
                     */

                     tableView->setText(qsl_arrayValues.at(i+j), row, j);
                  }
                  row++;
               }
            }
            return;
         }
      }
   }
}
//------------------------------------------------------------------------------
// Method       : setFieldEnabled(QString fieldName, bool enable, bool focus)
// Filename     : screenhandler.cpp
// Description  : enables or disables the Field
//------------------------------------------------------------------------------
void ScreenHandler::setFieldEnabled(QString fieldName, bool enable, bool focus, int attr)
{
MainFrame::vdcdebug("ScreenHandler","setFieldEnabled", "QString fieldName, bool enable, bool focus, int attr");
   Q_UNUSED(focus);

   fieldName = fieldName.trimmed();

   int i_Frm = getCurrForm();
   if(i_Frm < 0)
      return;
   Context *context = getCurrentContext();
   if(context == NULL)
      return;
   
   // For fieldlist = table.*
   int index = fieldName.indexOf(".*");
   QWidget *widget = NULL;
   if(index < 0){
      // No wildcard
      widget = p_fglform->findFieldByName(fieldName);
      if(widget != NULL){
         //widget->setEnabled(enable);
         if(enable) {
            context->addField(widget);
            WidgetHelper::setDisplayAttributes(attr, widget);
         }
      }
      else{
         qWarning("No such Field %s", qPrintable(fieldName));
      }
   }
   else{
      QList<QWidget*> ql_fields = p_fglform->findFieldsByName(fieldName);
      for(int i=0; i<ql_fields.count(); i++){
         widget = ql_fields.at(i);
         if(widget != NULL){
            //widget->setEnabled(enable);
            if(enable) {
               context->addField(widget);
               WidgetHelper::setDisplayAttributes(attr, widget);
            }
         }
         else{
            qFatal("No such Field %s", qPrintable(fieldName));
         }
      }
   }

   if(context->fieldList().size() == 1)
   {
      p_fglform->setCurrentWidget(widget);
   }

}

//------------------------------------------------------------------------------se
// Method       : setFieldFocus(QString FieldName )
// Filename     : screenhandler.cpp
// Description  : sets the focus for the Field
//------------------------------------------------------------------------------
void ScreenHandler::setFieldFocus(QString fieldName)
{
MainFrame::vdcdebug("ScreenHandler","setFieldFocus", "QString fieldName");
   fieldName = fieldName.trimmed();

   int i_Frm = getCurrForm();

   if(i_Frm < 0)
      return;

   clearEvents();
   p_fglform->nextclick = NULL;
   if(p_fglform->focusWidget() != NULL && !p_fglform->screenRecord()){
      clearEvents();
   }

   if(fieldName.toUpper() == "NEXT"){
      p_fglform->nextfield(false);
      return;
   }

   if(fieldName.toUpper() == "PREVIOUS"){
      p_fglform->prevfield();
      return;
   }

   if(fieldName.toUpper() == "CURRENT"){
      if(p_fglform->currentField() != NULL){
         p_fglform->setCurrentField(p_fglform->currentField()->objectName(), false);
      }
   }
   else{
       if(p_fglform->input() || p_fglform->construct())
       {
          for(int i = 0; i<p_fglform->ql_formFields.size(); i++)
          {
              if(p_fglform->ql_formFields.at(i)->objectName() == fieldName)
              {
                     p_fglform->jumpToField(p_fglform->ql_formFields.at(i), false);
                     return;
              }
          }
      }
      p_fglform->setCurrentField(fieldName, false);

/*
      // For fieldlist = table.*
      int index = fieldName.indexOf(".*");


      if(index < 0){
         widget = p_fglform->findFieldByName(fieldName);
      }
      else{
         widget = p_fglform->findFieldsByName(fieldName).first();
      }

      if(widget == NULL){
         qFatal("No Field found to set Focus: %s", qPrintable(fieldName));
         return;
      }
    
      if(LineEditDelegate *de = qobject_cast<LineEditDelegate *> (widget)){
         if(TableView *tableView = qobject_cast<TableView *> (de->parent())){
            int index = fieldName.indexOf(".");
            if(index > 0){
               fieldName.remove(index+1, fieldName.length()-index-1);
            }

            int index2 = fieldName.indexOf("[");
            if(index2 < 0){
               fieldName = QString("%1[%2]").arg(fieldName).arg(tableView->currentIndex().row()+1);
            }
            setArrayFocus(tableView, fieldName);
         }
      }
      else{
         widget->setFocus();
      }
*/
   }
}

//------------------------------------------------------------------------------
// Method       : setFieldFocus(QString FieldName )
// Filename     : screenhandler.cpp
// Description  : sets the focus for the Field
//------------------------------------------------------------------------------
void ScreenHandler::setFieldHidden(QString fieldName, bool hidden)
{
MainFrame::vdcdebug("ScreenHandler","setFieldHidden", "QString fieldName, bool hidden");
   fieldName = fieldName.trimmed();

   int i_Frm = getCurrForm();

   if(i_Frm < 0)
      return;

   if(QWidget *widget = qobject_cast<QWidget *> (p_fglform->findFieldByName(fieldName))){
       //widget->setVisible(hidden) with setVisible the formfields are visible changed to setHidden
       widget->setHidden(hidden);
   }
   else{
      if(LineEditDelegate *widget = qobject_cast<LineEditDelegate *> (p_fglform->findFieldByName(fieldName))){
         int col = widget->column();
         if(TableView *tableView = qobject_cast<TableView *> (widget->parent())){
            if(hidden){
               tableView->hideColumn(col);
            }
            else{
               tableView->showColumn(col);
            }
         }
      }
   }
   
}

void ScreenHandler::setNewTabName(QString oldTabName, QString newTabName)
{
    QList<QTabWidget*> ql_tabList = p_fglform->findChildren<QTabWidget*>();

    for(int i=0; i < ql_tabList.count(); i++)
    {
        for(int j=0; j < ql_tabList.at(i)->count(); j++)
        {
            if(oldTabName == ql_tabList.at(i)->tabText(j))
            {
                ql_tabList.at(i)->setTabText(j, newTabName);
            }
        }
    }

}

void ScreenHandler::setAttributes(QString fieldName, QString attribute, QString value)
{
    if(Edit *widget = qobject_cast<Edit*> (p_fglform->findFieldByName(fieldName)))
    {
        if(attribute == "picture")
        {
                widget->setPicture(value);
        }
    }
}

//------------------------------------------------------------------------------
// Method       : setFieldFocus(String FieldName )
// Filename     : screenhandler.cpp
// Description  : sets the focus for the Field
//------------------------------------------------------------------------------
void ScreenHandler::setElementHidden(QString fieldName, bool hidden)
{
MainFrame::vdcdebug("ScreenHandler","setElementHidden", "QString fieldName, bool hidden");
   fieldName = fieldName.trimmed();

   int i_Frm = getCurrForm();

   if(i_Frm < 0)
      return;

   if(QWidget *widget = qobject_cast<QWidget *> (p_fglform->findFieldByName(fieldName))){
      widget->setHidden(hidden);
   }
   else{
      if(LineEditDelegate *widget = qobject_cast<LineEditDelegate *> (p_fglform->findFieldByName(fieldName))){
         int col = widget->column();
         if(TableView *tableView = qobject_cast<TableView *> (widget->parent())){
            if(hidden){
               tableView->hideColumn(col);
            }
            else{
               tableView->showColumn(col);
            }
         }
      }
   }
   
}

//------------------------------------------------------------------------------
// Method       : setArrayFocus()
// Filename     : screenhandler.cpp
// Description  : sets focus for a field in an array
//------------------------------------------------------------------------------
void ScreenHandler::setArrayFocus(QWidget *tableView, QString fieldName){

   TableView *screenRecord = (TableView*) tableView;

   if(screenRecord == NULL){
      return;
   }

   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (screenRecord->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

   int index = fieldName.indexOf("[");
   int index2 = fieldName.indexOf("]");

   int col = -1;
   int row = fieldName.mid(index+1, (index2-index-1)).toInt()-1;
   fieldName.remove(index, fieldName.length()-index);

   index = fieldName.indexOf(".");
   QString colName = fieldName.mid(0, index);
   fieldName.remove(0, index+1);

   for(int i=0; i<table->qsl_colNames.count(); i++){
      if(table->qsl_colNames.at(i) == fieldName){
         col = i;
      }
   }

   if(!(row < 0 && col < 0)){
      screenRecord->setCurrentField(row+1, col+1);
   }

}

//------------------------------------------------------------------------------
// Method       : clearFieldFocusEvents()
// Filename     : screenhandler.cpp
// Description  : release the field focus
//------------------------------------------------------------------------------
void ScreenHandler::clearEvents()
{
MainFrame::vdcdebug("ScreenHandler","clearEvents", "");
   if(p_fglform == NULL)
      return;

   if(p_fglform->ql_responseQueue.size() > 0){
      p_fglform->ql_responseQueue.clear();
   }
   p_fglform->clearKeyboardBuffer();

   this->clearFieldEvents = false;
}

//------------------------------------------------------------------------------
// Method       : setEvent(QString event, QString attribute, int id)
// Filename     : screenhandler.cpp
// Description  : relates field with events and activate it
//------------------------------------------------------------------------------
void ScreenHandler::setEvent(QString event, QString attribute, QString id)
{
MainFrame::vdcdebug("ScreenHandler","setEvent", "QString event, QString attribute, int id");
   if(event == "BEFORE_MENU_EVENT"){
      Fgl::Event event;
      event.type = Fgl::BEFORE_INPUT_EVENT;
      event.id = id;

      //p_fglform->ql_formEvents << event;
      p_fglform->addFormEvent(event);
      return;
   }

   if(event == "BEFORE_INPUT_EVENT"){
      Fgl::Event event;
      event.type = Fgl::BEFORE_INPUT_EVENT;
      event.id = id;

      //p_fglform->ql_formEvents << event;
      p_fglform->addFormEvent(event);
      return;
   }

   if(event == "BEFORE_CONSTRUCT_EVENT"){
      Fgl::Event event;
      event.type = Fgl::BEFORE_CONSTRUCT_EVENT;
      event.id = id;

      //p_fglform->ql_formEvents << event;
      p_fglform->addFormEvent(event);
      return;
   }

   if(event == "BEFORE_DISPLAY_EVENT"){
      Fgl::Event event;
      event.type = Fgl::BEFORE_DISPLAY_EVENT;
      event.id = id;

      //p_fglform->ql_formEvents << event;
      p_fglform->addFormEvent(event);
      return;
   }

   if(event == "AFTER_INPUT_EVENT"){
      Fgl::Event event;
      event.type = Fgl::AFTER_INPUT_EVENT;
      event.id = id;

      //p_fglform->ql_formEvents << event;
      p_fglform->addFormEvent(event);
      return;
   }

   if(event == "AFTER_CONSTRUCT_EVENT"){
      Fgl::Event event;
      event.type = Fgl::AFTER_CONSTRUCT_EVENT;
      event.id = id;

      //p_fglform->ql_formEvents << event;
      p_fglform->addFormEvent(event);
      return;
   }

   if(event == "AFTER_DISPLAY_EVENT"){
      Fgl::Event event;
      event.type = Fgl::AFTER_DISPLAY_EVENT;
      event.id = id;

      //p_fglform->ql_formEvents << event;
      p_fglform->addFormEvent(event);
      return;
   }

   if(event == "BEFORE_FIELD_EVENT"){
      Fgl::Event event;
      event.type = Fgl::BEFORE_FIELD_EVENT;
      event.id = id;
      event.attribute= attribute;

      //p_fglform->ql_formEvents << event;
      p_fglform->addFormEvent(event);
      return;
   }

   if(event == "AFTER_FIELD_EVENT"){
      Fgl::Event event;
      event.type = Fgl::AFTER_FIELD_EVENT;
      event.id = id;
      event.attribute= attribute;

      //p_fglform->ql_formEvents << event;
      p_fglform->addFormEvent(event);
      return;
   }

   if(event == "BEFORE_ROW_EVENT"){
      Fgl::Event event;
      event.type = Fgl::BEFORE_ROW_EVENT;
      event.id = id;

      //p_fglform->ql_formEvents << event;
      p_fglform->addFormEvent(event);
      return;
   }

   if(event == "AFTER_ROW_EVENT"){
      Fgl::Event event;
      event.type = Fgl::AFTER_ROW_EVENT;
      event.id = id;

      //p_fglform->ql_formEvents << event;
      p_fglform->addFormEvent(event);
      return;
   }

   if(event == "BEFORE_INSERT_DELETE_EVENT"){
      Fgl::Event event;
      event.type = Fgl::BEFORE_INSERT_DELETE_EVENT;
      event.id = id;

      //p_fglform->ql_formEvents << event;
      p_fglform->addFormEvent(event);
      return;
   }

   if(event == "AFTER_INSERT_DELETE_EVENT"){
      Fgl::Event event;
      event.type = Fgl::AFTER_INSERT_DELETE_EVENT;
      event.id = id;

      //p_fglform->ql_formEvents << event;
      p_fglform->addFormEvent(event);
      return;
   }

   if(event == "ONKEY_EVENT"){
      Fgl::Event event;
      event.type = Fgl::ONKEY_EVENT;
      event.id = id;
      event.attribute = attribute; //Fgl::stringToKey(attribute);

      Action *action = new Action(attribute, "", p_fglform);
      action->setAcceleratorName(Fgl::keyToString(attribute));
      action->setDefaultView("no");
      p_fglform->addFormAction(action);
      action->setEnabled(true);

      //p_fglform->ql_formEvents << event;
      p_fglform->addFormEvent(event);
      return;
   }

   if(event == "ON_ACTION_EVENT"){
      Fgl::Event event;
      event.type = Fgl::ONACTION_EVENT;
      event.id = id;
      event.attribute = attribute; //Fgl::stringToKey(attribute);

      Action *action = new Action(attribute, "", p_fglform);
      action->setDefaultView("yes");
      p_fglform->addFormAction(action);
      action->setEnabled(true);

      //p_fglform->ql_formEvents << event;
      p_fglform->addFormEvent(event);
      return;
   }


   if(event == "MENUACTION_EVENT")
   {
       Fgl::Event event;
       event.type      = Fgl::MENUACTION_EVENT;
       event.id        = id;
       //event.keys      =
       return;
   }
}

//------------------------------------------------------------------------------
// Method       : createActionMenu()
// Filename     : screenhandler.cpp
// Description  : defines F-keys buttons functionality
//------------------------------------------------------------------------------
void ScreenHandler::createActionMenu()
{
MainFrame::vdcdebug("ScreenHandler","createActionMenu", "");
   int i_Frm = getCurrForm();

   if(i_Frm < 0)
      return;

   if(p_fglform == NULL){
      return;
   }

   if(qh_formActionMenus[i_Frm] == NULL){
      ActionMenu *actionMenu = new ActionMenu("", "");
      qh_formActionMenus[i_Frm] = actionMenu;
      p_fglform->setActionMenu(qh_formActionMenus[i_Frm]);
      p_fglform->setMenuEnabled(false);

      Context *context = getCurrentContext();
      if(context == NULL)
         return;
   }

}

//------------------------------------------------------------------------------
// Method       : createActionMenuButton(QString buttonId, QString text, QString desc)
// Filename     : screenhandler.cpp
// Description  : defines and show F-keys buttons
//------------------------------------------------------------------------------
void ScreenHandler::createActionMenuButton(QString text, QString desc)
{
MainFrame::vdcdebug("ScreenHandler","createActionMenuButton", "QString text, QString desc");

  int i_Frm = getCurrForm();

   if(i_Frm < 0)
      return;

   if(p_fglform == NULL)
      return;

   if(qh_formActionMenus[i_Frm] == NULL)
      return;

   //ActionMenu *actionMenu = qh_formActionMenus[i_Frm];

   Action *fAction = new Action(Fgl::stringToKey(desc), text);
   fAction->setAcceleratorName(desc);
   /*
   if(desc.toLower().trimmed() != "insert" && desc.toLower().trimmed() != "delete")
   {
      fAction->setAcceleratorName(desc);
   }*/
   fAction->setDefaultView("yes");
   fAction->setVisible(false);
   p_fglform->addFormAction(fAction);

}

//------------------------------------------------------------------------------
// Method       : setFormOpts(QString type, bool value)
// Filename     : screenhandler.cpp
// Description  : activate input construct etc (or deactivate it)
//------------------------------------------------------------------------------
void ScreenHandler::setFormOpts(QString type, bool value, int i_context)
{
MainFrame::vdcdebug("ScreenHandler","setFormOpts", "QString type, bool value, int i_context");

   if(!value){
      if(p_prompt != NULL && type == "PROMPT"){
         p_prompt->setVisible(false);
         p_prompt->close();
         p_prompt->deleteLater();
         p_prompt = NULL;
      }
   }

   int i_Frm = getCurrForm();

   if(p_fglform == NULL)
   {
       return;
   }

   if(i_Frm < 0 && p_fglform != NULL && p_fglform->dialog() == NULL)
      return;

   Context *context = getContext(i_context);
  /* if(context != p_fglform->context)
     {
       if(p_fglform->context)
       {
           if(value)
           {
              p_fglform->context->restoreFieldPalette();
              p_fglform->actionMenu()->setButtonIcons();
              p_fglform->actionMenu()->setButtonPalette();
           }
       }
     }*/
   p_fglform->context = context;


   if(value){

      if(type == "MENU"){
         p_fglform->setState(Fgl::MENU);
         context->setState(Fgl::MENU);
      }

      if(type == "INPUT"){
         p_fglform->setState(Fgl::INPUT);
         context->setState(Fgl::INPUT);
//         p_fglform->addFormAction("accept", "Ok");

         Fgl::Event event;
         event.type = Fgl::ONACTION_EVENT;
         event.id = "-1";
         event.attribute = "accept"; 

         p_fglform->addFormEvent(event);

         event.type = Fgl::ONACTION_EVENT;
         event.id = "-1";
         event.attribute = "cancel";

         p_fglform->addFormEvent(event);
      }

      if(type == "CONSTRUCT"){
         p_fglform->setState(Fgl::CONSTRUCT);
         context->setState(Fgl::CONSTRUCT);

         Fgl::Event event;
         event.type = Fgl::ONACTION_EVENT;
         event.id = "-1";
         event.attribute = "accept"; 

         p_fglform->addFormEvent(event);

         event.type = Fgl::ONACTION_EVENT;
         event.id = "-1";
         event.attribute = "cancel";

         p_fglform->addFormEvent(event);
      }

      if(type == "DISPLAYARRAY"){
         p_fglform->setState(Fgl::DISPLAYARRAY);
         context->setState(Fgl::DISPLAYARRAY);
//         p_fglform->addFormAction("accept", "Ok");

         Fgl::Event event;
         event.type = Fgl::ONACTION_EVENT;
         event.id = "-1";
         event.attribute = "accept"; 

         p_fglform->addFormEvent(event);

         event.type = Fgl::ONACTION_EVENT;
         event.id = "-1";
         event.attribute = "cancel";

         p_fglform->addFormEvent(event);


     }

      if(type == "INPUTARRAY"){
         p_fglform->setState(Fgl::INPUTARRAY);
         context->setState(Fgl::INPUTARRAY);
//         p_fglform->addFormAction("accept", "Ok");

         Fgl::Event event;
         event.type = Fgl::ONACTION_EVENT;
         event.id = "-1";
         event.attribute = "accept"; 

         p_fglform->addFormEvent(event);

         event.type = Fgl::ONACTION_EVENT;
         event.id = "-1";
         event.attribute = "cancel";

         p_fglform->addFormEvent(event);

         event.type = Fgl::GUI_ACTION_EVENT;
         event.id = "-1";
         event.attribute = "insert";

         p_fglform->addFormEvent(event);


         event.type = Fgl::GUI_ACTION_EVENT;
         event.id = "-1";
         event.attribute = "delete";

         p_fglform->addFormEvent(event);

         for(int i=0; i<context->fieldList().count(); i++){
             if(TableView *tv = qobject_cast<TableView*> (context->fieldList().at(i)))
             {
                 tv->setIgnoreRowChange(false);
            }
         }


      }
   }
   else{
      if(type == "MENU"){
         if(p_fglform->dialog() != NULL){
            p_fglform->dialog()->b_allowCloseDialog = true;
            p_fglform->dialog()->close();
            p_fglform->setDialog(NULL);
            p_fglform->setEnabled(true);
            p_fglform->revertState(Fgl::MENU);
            freeContext(i_context);
            p_fglform->ql_dialogEvents.clear();
            return;
         }
         if(p_fglform->ringMenuPulldown() != NULL){
            p_fglform->ringMenuPulldown()->closeWindow();
            p_fglform->setRingMenuPulldown(NULL);
            p_fglform->setEnabled(true);
            p_fglform->revertState(Fgl::MENU);
            freeContext(i_context);
            p_fglform->ql_pulldownEvents.clear();
            return;
         }
         else{
            p_fglform->removeMenu();
            p_fglform->revertState(Fgl::MENU);
            freeContext(i_context);
            p_fglform->ql_menuEvents.clear();
         }
      }

      if(type == "INPUT"){
         if(p_fglform->input()){
            p_fglform->revertState(Fgl::INPUT);

/*
            QStringList fields = context->fieldList();
            for(int i=0; i<fields.count(); i++){
               setFieldEnabled(fields.at(i), false, false);
            }
*/
            freeContext(i_context);
            p_fglform->ql_responseQueue.clear();
            p_fglform->ql_formEvents.clear();
            return;
         }
      }
      if(type == "INPUTARRAY")
      {
         if(p_fglform->inputArray()){
//            QList<QWidget*> ql_fields = p_fglform->formElements();

            for(int i=0; i<context->fieldList().count(); i++){
                  if(TableView *tableView = qobject_cast<TableView *> (context->fieldList().at(i))){
                     tableView->setCurrentField(0,0, false);
                  }
               }


            p_fglform->revertState(Fgl::INPUTARRAY);
            freeContext(i_context);
            p_fglform->ql_responseQueue.clear();
            p_fglform->ql_formEvents.clear();
            return;
         }
      }

      if(type == "CONSTRUCT"){
         p_fglform->revertState(Fgl::CONSTRUCT);
//         QList<QWidget*> ql_fields = p_fglform->formElements();
/*
         QList<QWidget*> ql_fields = p_fglform->ql_formFields;
         for(int i=0; i<ql_fields.size(); i++){
            QWidget *widget = (QWidget*) ql_fields.at(i);

            if(widget->isEnabled()){
               if(LineEdit *lineEdit = qobject_cast<LineEdit *> (ql_fields.at(i))){
                  lineEdit->setEnabled(false);
               }

            if(TextEdit *textEdit = qobject_cast<TextEdit *> (ql_fields.at(i))){
               textEdit->setEnabled(false);
            }
         }
*/
         freeContext(i_context);
      }

   if(type == "DISPLAY"){
//      QList<QWidget*> ql_fields = p_fglform->formElements();
/*
      for(int i=0; i<context->fieldList().count(); i++){
         QWidget *widget = p_fglform->findFieldByName(context->fieldList().at(i));
         if(LineEditDelegate *de = qobject_cast<LineEditDelegate *> (widget)){
            if(TableView *tableView = qobject_cast<TableView *> (de->parent())){
               tableView->setEnabled(false);
               }
         }
      }
*/
      p_fglform->revertState(Fgl::DISPLAYARRAY);
   }


   p_fglform->ql_responseQueue.clear();
   p_fglform->ql_formEvents.clear();
   p_fglform->qsl_activeFields.clear();
   freeContext(i_context);
   }

   //p_fglform->checkState();

}

//------------------------------------------------------------------------------
// Method       : setFormOpts(QString type, QString attribute, bool int)
// Filename     : screenhandler.cpp
// Description  : activate input construct etc (or deactivate it)
//------------------------------------------------------------------------------
void ScreenHandler::setFormOpts(QString type, QString attribute, int value)
{
MainFrame::vdcdebug("ScreenHandler","setFormOpts", "QString type, QString attribute, int value");
   Q_UNUSED(type);
   if(value < 0)
      return;

   Context *context = getCurrentContext();

   context->setOption(attribute,value);

}

//------------------------------------------------------------------------------
// Method       : waitForEvent()
// Filename     : screenhandler.cpp
// Description  : display form if preapared but not yet displayed,
//                gui waits for user activity
//------------------------------------------------------------------------------
void ScreenHandler::waitForEvent()
{

MainFrame::vdcdebug("ScreenHandler","waitForEvent", "");
if(qsl_triggereds.size() > 0)
{
    if(p_fglform)
    {
       p_fglform->b_getch_swin = true;
    }
   sendDirect(qsl_triggereds.takeFirst());
   return;
}

   FglForm *saveactive = p_fglform;
   if(p_fglform == NULL)
      return;

   if(p_fglform->context != getCurrentContext()){
      p_fglform->context = getCurrentContext();
      connect(p_fglform->context, SIGNAL(fieldEvent(Fgl::Event)), p_fglform, SLOT(fieldEvent(Fgl::Event)));
   }


   for(int i= 0; i < this->ql_fglForms.count(); i++)
   {
      p_fglform = ql_fglForms.at(i);

      p_fglform->checkState();
     //Hier evt abfragen ob IDLE und das Menu gesetzt ist. Es sollte aufjedenfall machbarsein ...
      if(p_fglform->b_newForm && p_fglform->dialog () == NULL && p_fglform->ringMenuPulldown() == NULL && saveactive->state() != Fgl::IDLE && !p_fglform->b_dummy){
         p_fglform->b_newForm = false;

         //Load the Actions again, before display the form
        // p_fglform->checkActions(); bullshit its called allready in checkState()
        // p_fglform->adjustSize();
         //p_fglform->resize(500,500);

         QSize widgetSize (VDC::readSettingsFromIni(p_fglform->formName(), "width").toInt(), VDC::readSettingsFromIni(p_fglform->formName(), "height").toInt());
         if(!widgetSize.isEmpty())
         {
             p_fglform->resize(widgetSize);
             p_fglform->show();
         } else {
             p_fglform->show();
             p_fglform->adjustSize();
         }

         if(p_fglform->context != NULL)
         {
             p_fglform->context->checkOptions();
         }

         emit windowCreated();
      }
      else{
         if(p_fglform->dialog() != NULL){
         //   p_fglform->checkActions(); allready in checkState
              //Not needed under mac, cause the dialog i opend in top of the qmainwindow
              #ifndef Q_WS_MAC
             //Noch moven solange es unsichtbar ist

            if(!p_fglform->dialog()->isVisible())
            {
               QRect rect;
               if(p_fglform->b_dummy)
               {

                 rect = QApplication::desktop()->screenGeometry();
                 QRect w_p_rect = QRect(0,0, p_fglform->dialog()->sizeHint().width(), p_fglform->dialog()->sizeHint().height());
                 p_fglform->dialog()->move(rect.center() - w_p_rect.center());

               }
               else
               {

                   QPoint pos = p_fglform->mapToGlobal(QPoint(0,0));
                   p_fglform->dialog()->move(pos + p_fglform->rect().center() - p_fglform->dialog()->rect().center());
               }
            }
            #endif
            p_fglform->dialog()->show();
            p_fglform->dialog()->adjustSize();
         }

         if(p_fglform->ringMenuPulldown() != NULL){
        //    p_fglform->checkActions(); allredy in checkState
            /*QString style = QString("QMenu::item:disabled { width: 20px; background-image: url(none); padding-left: 110px; height: 26px; color: #000000;}") + " " + p_fglform->styleSheet();
            p_fglform->setStyleSheet(style);

            int cnt = 0;
            for(int i = 0; i < p_fglform->pulldown()->actions().count(); i++){
                if(Action *action = qobject_cast<Action*> (p_fglform->pulldown()->getAction(p_fglform->pulldown()->actions().at(i)->text()))) {
                    if(action->isVisible()) {
                        if(action->text() == "Ende" || action->text() == "Exit") {
                            action->setIcon((QIcon(QString(":pics/pulldown-esc.png"))));
                        } else {
                            action->setIcon((QIcon(QString(":pics/%1.png").arg(cnt))));
                        }
                        cnt++;
                    }
                }
            }*/
            //p_fglform->ringMenuPulldown()->showWindow();
             //Noch moven solange es unsichtbar ist
             if(!p_fglform->ringMenuPulldown()->isVisible())
             {
                 QRect rect;
                 if(p_fglform->b_dummy || !p_fglform->isVisible())
                 {

                   rect = QApplication::desktop()->screenGeometry();
                   QRect w_p_rect = QRect(0,0, p_fglform->ringMenuPulldown()->sizeHint().width(), p_fglform->ringMenuPulldown()->sizeHint().height());
                   p_fglform->ringMenuPulldown()->move(rect.center() - w_p_rect.center());

                 }
                 else
                 {

                     QPoint pos = p_fglform->mapToGlobal(QPoint(0,0));
                     p_fglform->ringMenuPulldown()->move(pos + p_fglform->rect().center() - p_fglform->ringMenuPulldown()->rect().center());
                 }
             }
            p_fglform->ringMenuPulldown()->show();
         }

         if(p_fglform->menu() != NULL)
         {
             if(p_fglform->state() == Fgl::MENU )
             {
                 p_fglform->menu()->selectButton(p_fglform->menu()->getFocusName());
             }
         }
      }
   }
   p_fglform = saveactive;
   /*
   if(p_fglform->inputArray() || p_fglform->construct() || p_fglform->input() || p_fglform->displayArray())
   {

       if(p_fglform->actionMenu())
       {
          p_fglform->actionMenu()->setButtonIcons();
          p_fglform->actionMenu()->setButtonPalette();
       }

   }*/
   checkFields();

/*
   if(p_fglform->context != NULL)
      p_fglform->context->checkOptions();
*/
   p_fglform->raise();

   //p_fglform->checkState();



     if(p_fglform->ql_responseQueue.size() > 0)
     {
         p_fglform->b_getch_swin = true;
         if(TableView *tableView = qobject_cast<TableView *> (p_fglform->currentField())){
             if(p_fglform->inputArray())
             {
                 tableView->eventfield = QModelIndex();
                 tableView->b_ignoreFocus = false;

                 if(tableView->curr_editor != NULL)
                 {
              //      tableView->curr_editor->setFocus(Qt::OtherFocusReason);
                    //p_fglform->setFocusOnWidget(tableView->curr_editor);
                 }
             }
         }
         processResponse();
         return;
     }
      setUpdatesEnabled(true);


   if(p_fglform->currentField() == NULL)
   {

   }
   else
   {
       if(TableView *tableView = qobject_cast<TableView *> (p_fglform->currentField())){
           if(p_fglform->inputArray())
           {
               //Unter Mac enfernt er das gesammte TableView wenn nen PaintEvent kommt... Das sieht noch beschissener aus als so eine dumme Feldselektierung. Deswegen für Mac raus
               #ifndef Q_WS_MAC
               //Fuer p_veinswb mit der kranken BeforeField/Nextfield Logik über mehrere Zeilen... Sah zwischen den Events einfach scheisse aus mit der Feldselektierung.
               tableView->setUpdatesEnabled(true);
               #endif
               tableView->eventfield = QModelIndex();

               tableView->b_ignoreFocus = false;
             //  tableView->edit(tableView->currentIndex());
               if(tableView->curr_editor != NULL)
               {
            //      tableView->curr_editor->setFocus(Qt::OtherFocusReason);
                  //p_fglform->setFocusOnWidget(tableView->curr_editor);
               }
           }
       }
       else
       {
           p_fglform->setFocusOnWidget(p_fglform->currentField());

           if(p_fglform->nextclick != NULL)
           {
               if(ButtonEdit *be = qobject_cast<ButtonEdit*> (p_fglform->nextclick->parentWidget()))
               {
                   if(p_fglform->currentField() == p_fglform->nextclick->parentWidget())
                      be->buttonClicked();
               }
               if(DateEdit *de = qobject_cast<DateEdit*> (p_fglform->nextclick->parentWidget()))
               {
                   if(p_fglform->currentField() == p_fglform->nextclick->parentWidget())
                      de->buttonClicked();
               }

                   p_fglform->nextclick = NULL;
           }
       }
   }
   if(p_fglform->ql_responseQueue.size() == 0)
   {
       if(p_fglform->state() == Fgl::INPUTARRAY)
       {
           if(TableView *tv = qobject_cast<TableView*> (p_fglform->currentWidget))
           {
               int col = tv->currentIndex().column();
               if(tv->isReadOnlyColumn(col) || tv->isColumnHidden(col))
               {
                   p_fglform->b_getch_swin = true;
                   p_fglform->nextfield();
                   return;
               }

           }
       }


     p_fglform->b_getch_swin = true;
     p_fglform->replayKeyboard();

   VDC::arrowCursor();
}
   else
   {
   p_fglform->b_getch_swin = true;
   processResponse();
   }


}

//------------------------------------------------------------------------------
// Method       : processResponse()
// Filename     : screenhandler.cpp
// Description  : sends user inputs to the protocol as xml
//------------------------------------------------------------------------------
void ScreenHandler::processResponse()
{
//MainFrame::vdcdebug("ScreenHandler","processResponse", "");

   if(p_fglform == NULL)
      return;


Fgl::Event id;
   if(p_fglform->ql_responseQueue.size() <= 0)
   {
       return;
   }
   else
   {

       if(!p_fglform->b_getch_swin)
       {
          return;
      }

       p_fglform->b_getch_swin = false;

       id = p_fglform->ql_responseQueue.takeFirst();

         setUpdatesEnabled(false);
         VDC::waitCursor();
         }
/*
   if(!p_fglform->context == NULL)
   {
      for(int i=0; i<p_fglform->context->fieldList().count(); i++){
         if(TableView *tableView = qobject_cast<TableView *> (p_fglform->context->fieldList().at(i))){
   //         tableView->setEnabled(false);
         }
      }
   }*/

   if(id.id.indexOf(",") == -1){

      p_fglform->b_svs = true;
      Response resp(id, p_fglform, cursorPos);
      QString qs_resp = resp.toString().replace("\n","");
      QDomDocument doc;
      doc.setContent(qs_resp);
      QDomElement triggeredElement = doc.documentElement();
      triggeredElement.setAttribute("ENVELOPEID", pid);
      qs_resp = doc.toString();
      if(qs_resp.isEmpty())
         return;

      if(this->ph)
          QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, qs_resp));
      else
        fglFormResponse(qs_resp);
   }
   else{
       QDomNodeList qdl_node;
       QStringList qsl_ids = id.id.split(",");
       QString qs_resp;
       for(int i=0; i<qsl_ids.size(); i++){
           Fgl::Event fevent;
           fevent.id = qsl_ids.at(i);
           if((i+1) == qsl_ids.size())
           {
               fevent.field = id.field;
           }
           if(i>0)
           {
               p_fglform->b_svs = false;
           }
           Response resp(fevent, p_fglform, cursorPos);
           resp.firstChildElement().setAttribute("CNT", i+1);
           resp.firstChildElement().setAttribute("MAXCNT", qsl_ids.size());
           resp.firstChildElement().setAttribute("ENVELOPEID", pid);

           qs_resp.append(resp.toString().replace("\n",""));
           if(i+1<qsl_ids.size()){
               qs_resp.append("\n");
           }
       }

       p_fglform->b_svs = true;
       if(qs_resp.isEmpty())
          return;
       if(this->ph)
           QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, qs_resp));
       else
         fglFormResponse(qs_resp);
   }


}
//------------------------------------------------------------------------------
// Method       : sendDirect(QString cmd)
// Filename     : screenhandler.cpp
// Description  : sends user inputs to the protocol without xml preparation (for RUN)
//------------------------------------------------------------------------------

void ScreenHandler::sendDirect(QString cmd)
{
MainFrame::vdcdebug("ScreenHandler","sendDirect", "QString cmd");

if(p_fglform != NULL)
{

  if(!p_fglform->b_getch_swin)
  {
      qsl_triggereds << cmd;
      return;
  }

  p_fglform->b_getch_swin = false;
}
if(this->ph)
    QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, cmd));
else
  fglFormResponse(cmd);


}

//------------------------------------------------------------------------------
// Method       : free(QString type)
// Filename     : screenhandler.cpp
// Description  : END INPUT, END MENU etc
//------------------------------------------------------------------------------
void ScreenHandler::free(QString type)
{
MainFrame::vdcdebug("ScreenHandler","free", "QString type");

   if(p_prompt != NULL && type == "PROMPT"){
      p_prompt->setVisible(false);
      p_prompt->close();
      p_prompt->deleteLater();
      p_prompt = NULL;
   }

   if(p_fglform == NULL)
      return;

   if(type == "MENU"){
      if(p_fglform->dialog() != NULL){
         p_fglform->dialog()->b_allowCloseDialog = true;
         p_fglform->dialog()->close();
         p_fglform->setDialog(NULL);
         p_fglform->revertState(Fgl::MENU);
         return;
      }
      if(p_fglform->ringMenuPulldown() != NULL){
         //p_fglform->ringMenuPulldown()->close();
         p_fglform->setRingMenuPulldown(NULL);
         p_fglform->revertState(Fgl::MENU);
         return;
      }
      else{
         p_fglform->removeMenu();
         p_fglform->revertState(Fgl::MENU);
      }
   }

   if(type == "INPUT"){
      if(p_fglform->input()){
         p_fglform->revertState(Fgl::INPUT);

         for(int i=0; i<p_fglform->qsl_activeFields.count(); i++){
            setFieldEnabled(p_fglform->qsl_activeFields.at(i), false, false);
         }
      }
      if(p_fglform->inputArray()){
         //         QList<QWidget*> ql_fields = p_fglform->formElements();
         QList<QWidget*> ql_fields = p_fglform->ql_formFields;
         for(int i=0; i<ql_fields.size(); i++){
            QWidget *widget = (QWidget*) ql_fields.at(i);

            if(widget->isEnabled()){
               if(TableView *tableView = qobject_cast<TableView *> (ql_fields.at(i))){
                   QModelIndex current = tableView->currentIndex();
                   tableView->closePersistentEditor(current);
                   tableView->setEnabled(false);
               }
            }
         }
         p_fglform->revertState(Fgl::INPUTARRAY);
      }
   }

   if(type == "CONSTRUCT"){
      p_fglform->revertState(Fgl::CONSTRUCT);
      //      QList<QWidget*> ql_fields = p_fglform->formElements();
      QList<QWidget*> ql_fields = p_fglform->ql_formFields;
      for(int i=0; i<ql_fields.size(); i++){
         QWidget *widget = (QWidget*) ql_fields.at(i);

         if(widget->isEnabled()){
            if(LineEdit *lineEdit = qobject_cast<LineEdit *> (ql_fields.at(i))){
               lineEdit->setEnabled(false);
            }

            if(TextEdit *textEdit = qobject_cast<TextEdit *> (ql_fields.at(i))){
               textEdit->setEnabled(false);
            }
         }
      }
   }

   if(type == "DISPLAY"){
      //      QList<QWidget*> ql_fields = p_fglform->formElements();
      QList<QWidget*> ql_fields = p_fglform->ql_formFields;
      for(int i=0; i<ql_fields.size(); i++){
         QWidget *widget = (QWidget*) ql_fields.at(i);

         if(widget->isEnabled()){
            if(TableView *tableView = qobject_cast<TableView *> (ql_fields.at(i))){
               tableView->setEnabled(false);
            }
         }
      }
      p_fglform->revertState(Fgl::DISPLAYARRAY);
   }

   //if(p_fglform->finalWidget != NULL){
  //     p_fglform->nextfield();
  // }

   p_fglform->ql_responseQueue.clear();
   p_fglform->ql_formEvents.clear();
   p_fglform->qsl_activeFields.clear();

}

//------------------------------------------------------------------------------
// Method       : displayError(QString text)
// Filename     : screenhandler.cpp
// Description  : displays error in message line and in a Dialog Box
//------------------------------------------------------------------------------
void ScreenHandler::displayError(QString text)
{
MainFrame::vdcdebug("ScreenHandler","displayError", "QString text");

   if(!p_fglform->b_dummy)
   {
      StatusBar *statusBar = (StatusBar*) p_fglform->statusBar();
      statusBar->displayError(text);
   }
   else
   {

      if(text.isEmpty())
        return;
      if(FglForm *form = qobject_cast<FglForm*> (QApplication::activeWindow()))
    //  if(FglForm *form = qobject_cast<FglForm*> (MainFrame::getTopLevelPointerOfParent(this->p_pid_p)))
      {
         StatusBar *sb = (StatusBar*) form->statusBar();
         sb->displayError(text);
         return;
      }
      Dialog *errorDialog = new Dialog(tr("Error"), text, "dialog", "stop", NULL);
      errorDialog->setModal(true);
      errorDialog->createButton(1, "OK", "OK", "ok.png");
      QPushButton *qpb = (QPushButton *) errorDialog->getAction("OK")->parent();
      QString shortcut = "F12";
      qpb->setShortcut(shortcut);
      XML2Style *xml2Style = new XML2Style();
      xml2Style->readXML(formsStyles);
      errorDialog->setStyleSheet(xml2Style->getStyleSheet());
      xml2Style->deleteLater();
      connect(errorDialog->getAction("OK"), SIGNAL(triggered()), errorDialog, SLOT(close()));
      connect(errorDialog, SIGNAL(finished(int)), errorDialog, SLOT(deleteLater()));
      errorDialog->setAttribute(Qt::WA_DeleteOnClose, true);
      errorDialog->show();
      errorDialog->raise();
   }

}

//------------------------------------------------------------------------------
// Method       : displayMessage(QString text)
// Filename     : screenhandler.cpp
// Description  : displays message in message line
//------------------------------------------------------------------------------
void ScreenHandler::displayMessage(QString text)
{
MainFrame::vdcdebug("ScreenHandler","displayMessage", "QString text");


   if(!p_fglform->b_dummy)
   {
      StatusBar *statusBar = (StatusBar*) p_fglform->statusBar();
      statusBar->displayMessage(text);
   }
   else
   {
       if(text.isEmpty())
         return;
       if(FglForm *form = qobject_cast<FglForm*> (QApplication::activeWindow()))
//       if(FglForm *form = qobject_cast<FglForm*> (MainFrame::getTopLevelPointerOfParent(this->p_pid_p)))
       {
          StatusBar *sb = (StatusBar*) form->statusBar();
          sb->displayError(text);
          return;
       }
       Dialog *errorDialog = new Dialog(tr("Message"), text, "dialog", "info", NULL);
      errorDialog->setModal(true);
      errorDialog->createButton(1, "OK", "OK", "ok.png");
      QPushButton *qpb = (QPushButton *) errorDialog->getAction("OK")->parent();
      QString shortcut = "F12";
      qpb->setShortcut(shortcut);
      XML2Style *xml2Style = new XML2Style();
      xml2Style->readXML(formsStyles);
      errorDialog->setStyleSheet(xml2Style->getStyleSheet());
      xml2Style->deleteLater();
      connect(errorDialog->getAction("OK"), SIGNAL(triggered()), errorDialog, SLOT(close()));
      connect(this, SIGNAL(windowCreated()), errorDialog, SLOT(close()));
      connect(errorDialog, SIGNAL(finished(int)), errorDialog, SLOT(deleteLater()));
      errorDialog->setAttribute(Qt::WA_DeleteOnClose, true);
      errorDialog->show();
      errorDialog->raise();
   }



}

//------------------------------------------------------------------------------
// Method       : setWindowTitle(QString title)
// Filename     : screenhandler.cpp
// Description  : defines window title
//------------------------------------------------------------------------------
void ScreenHandler::setWindowTitle(QString title)
{
MainFrame::vdcdebug("ScreenHandler","setWindowTitle", "QString title");
   if(p_fglform == NULL)
      return;

   p_fglform->setWindowTitle(title);

}


void ScreenHandler::MsgBox (QString title, QString text, QString logo, QString buttons, QString defButton,int reply)
{
MainFrame::vdcdebug("ScreenHandler","MsgBox ", "QString title, QString text, QString logo, QString buttons, QString defButton,int reply");
   QString rstr = "NotSet";
   QMessageBox::StandardButtons btns = 0;
   QMessageBox::StandardButton defBtn = QMessageBox::NoButton;

   if (buttons.toUpper ().contains ("OK"))
      btns |= QMessageBox::Ok;
   if (buttons.toUpper ().contains ("YES"))
      btns |= QMessageBox::Yes;
   if (buttons.toUpper ().contains ("NO"))
      btns |= QMessageBox::No;
   if (buttons.toUpper ().contains ("CANCEL"))
      btns |= QMessageBox::Cancel;
   if (buttons.toUpper ().contains ("ABORT"))
      btns |= QMessageBox::Abort;
   if (buttons.toUpper ().contains ("RETRY"))
      btns |= QMessageBox::Retry;


   if (defButton.toUpper ().contains ("OK"))
      defBtn = QMessageBox::Ok;
   if (defButton.toUpper ().contains ("YES"))
      defBtn = QMessageBox::Yes;
   if (defButton.toUpper ().contains ("NO"))
      defBtn = QMessageBox::No;
   if (defButton.toUpper ().contains ("CANCEL"))
      defBtn = QMessageBox::Cancel;
   if (defButton.toUpper ().contains ("ABORT"))
      defBtn = QMessageBox::Abort;
   if (defButton.toUpper ().contains ("RETRY"))
      defBtn = QMessageBox::Abort;


   QMessageBox msgbox;
   msgbox.setText (title);
   if (logo.toUpper () == "WARNING")
   {
      msgbox.setIcon (QMessageBox::Warning);
   }
   if (logo.toUpper () == "QUESTION")
   {
      msgbox.setIcon (QMessageBox::Question);
   }
   if (logo.toUpper () == "INFO" || logo.toUpper () == "INFORMATION")
   {
      msgbox.setIcon (QMessageBox::Information);
   }
   if (logo.toUpper () == "CRITICAL" || logo.toUpper () == "ERROR")
   {
      msgbox.setIcon (QMessageBox::Critical);
   }


   msgbox.setInformativeText (text);
   msgbox.setStandardButtons (btns);
   msgbox.setDefaultButton (defBtn);
   int ret = msgbox.exec ();

   if (ret == QMessageBox::Ok)
   {
      rstr = "OK";
   }
   if (ret == QMessageBox::Cancel)
   {
      rstr = "CANCEL";
   }
   if (ret == QMessageBox::Yes)
   {
      rstr = "YES";
   }
   if (ret == QMessageBox::No)
   {
      rstr = "NO";
   }
   if (ret == QMessageBox::Abort)
   {
      rstr = "ABORT";
   }
   if (ret == QMessageBox::Retry)
   {
      rstr = "RETRY";
   }

   if (reply) {
       QString cmd = "<TRIGGERED ID=\""+rstr+"\" ENVELOPEID=\""+this->pid+"\"/>";
       if(this->ph)
           QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, cmd));
       else
         fglFormResponse(cmd);
     // fglFormResponse("<TRIGGERED ID=\""+rstr+"\" ENVELOPEID=\""+this->pid+"\"/>");
   }
   //return rstr;
}
int ScreenHandler::cnt_screenhandler = 0;
//------------------------------------------------------------------------------
// Method       : closeWindow(QString windowName)
// Filename     : screenhandler.cpp
// Description  : CLOSE WINDOW
//------------------------------------------------------------------------------
void ScreenHandler::closeWindow(QString windowName)
{
    MainFrame::vdcdebug("ScreenHandler","closeWindow", "QString windowName");
   VDC::waitCursor();
   for(int i=0; i<ql_fglForms.size(); i++){
      FglForm *form = ql_fglForms.at(i);

      if(form->windowName == windowName){
         form->b_allowClose = true;
         form->close();
         int i_Frm = getCurrForm();
         initForm(i_Frm);
         cnt_form--;
         //form->writeSettingsLocal();
         ql_fglForms.takeAt(i)->deleteLater();
//         window->deleteLater();
         i_Frm = getCurrForm();


         if(i_Frm > -1){
            p_fglform = ql_fglForms.at(i_Frm+1);
            p_fglform->setEnabled(true);
         }
         else{
            p_fglform = dummy_fglform;
            VDC::arrowCursor();
         }
      }
   }

}

//------------------------------------------------------------------------------
// Method       : activeWindow(QString windowName)
// Filename     : screenhandler.cpp
// Description  : ACTIVE WINDOW
//------------------------------------------------------------------------------
void ScreenHandler::activeWindow(QString windowName)
{
MainFrame::vdcdebug("ScreenHandler","activeWindow", "QString windowName");

   if(p_fglform == NULL)
      return;
   
   // p_fglform->setEnabled(false);

   for(int i=0; i<ql_fglForms.size(); i++){
      FglForm *form = ql_fglForms.at(i);

      if(form->windowName == windowName){
         p_fglform = form;
         form->setEnabled(true);
         form->raise();
      }

   }



}
//------------------------------------------------------------------------------
// Method       : setKeyLabel(int dialog, QString label, QString text)
// Filename     : screenhandler.cpp
// Description  : describe F-keys
//------------------------------------------------------------------------------
void ScreenHandler::setKeyLabel(QString label, QString text)
{
MainFrame::vdcdebug("ScreenHandler","setKeyLabel", "QString label, QString text");
   int i_Frm = getCurrForm();

   if(i_Frm < 0)
      return;

   if(p_fglform == NULL)
      return;

   if(qh_formActionMenus[i_Frm] == NULL){
      createActionMenu();
      p_fglform->setMenuEnabled(false);
   }




   // If Key has a Text then show it
   if(!text.isEmpty()){
      createActionMenuButton(text, label);
   }
   else{ // else hide the button
      QList<QAction*> ql_actions = p_fglform->actions();
      for(int i=0; i<ql_actions.size(); i++){
         if(Action *a = qobject_cast<Action *> (ql_actions.at(i))){
            if(a->name() == Fgl::stringToKey(label)){
               if(ActionMenu *aMenu = qobject_cast<ActionMenu *> (p_fglform->actionMenu())){
                  if(aMenu->getAction(a->text())){
                     aMenu->removeButton(a->text());
                     a->setDefaultView("no");
                     break;
                  }
               }
            }
         }
      }
   }

}

//------------------------------------------------------------------------------
// Method       : setScreenRecordEnabled(QStringList qsl_tabNames, bool enable, bool input)
// Filename     : screenhandler.cpp
// Description  : activates table on screen forms
//------------------------------------------------------------------------------
void ScreenHandler::setScreenRecordEnabled(QString fieldName, bool enable, bool input)
{
MainFrame::vdcdebug("ScreenHandler","setScreenRecordEnabled", "QString fieldName, bool enable, bool input");
   Q_UNUSED(enable);
   Context *context = getCurrentContext();
   QWidget *widget = NULL;
   TableView *tableView = NULL;
   QList<QWidget*> ql_fields = p_fglform->findFieldsByName(fieldName);
   for(int i=0; i< ql_fields.count(); i++){

      widget = ql_fields.at(i);

      if(LineEditDelegate *de = qobject_cast<LineEditDelegate *> (widget)){
         if(tableView = qobject_cast<TableView *> (de->parent())){
            context->addScreenRecord(tableView, input);
            break;
         }
      }
   }
   if(context->fieldList().size() == 1)
   {
       p_fglform->setCurrentWidget(tableView);
   }

}

//------------------------------------------------------------------------------
// Method       : loadArrayValues(QStringList qsl_tabNames, QStringList qsl_arrayValues)
// Filename     : screenhandler.cpp
// Description  : load data on table for being displayed
//------------------------------------------------------------------------------
void ScreenHandler::loadArrayValues(QStringList qsl_tabNames, QStringList qsl_arrayValues)
{
MainFrame::vdcdebug("ScreenHandler","loadArrayValues", "QStringList qsl_tabNames, QStringList qsl_arrayValues");
   for(int i=0; i<qsl_tabNames.size(); i++){
      QString fieldName = qsl_tabNames.at(i);

//      QList<QWidget*> ql_fields = p_fglform->formElements();
      QList<QWidget*> ql_fields = p_fglform->ql_formFields;
      for(int k=0; k<ql_fields.size(); k++){
         if(TableView *tableView = qobject_cast<TableView *> (ql_fields.at(k))){
            QString tabName;
            int index = fieldName.indexOf(".");
            if(index >= 0){
               tabName.append(fieldName.mid(0,index));
            }

            if(tableView->tabName == tabName && fieldName.indexOf("*") >= 0){
               QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (tableView->model());
               TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

               for(int p=table->rowCount(QModelIndex()); p>0; p--){
                  table->removeRow(p-1);
               }

               int colCount = table->columnCount(QModelIndex());
               int row = 0;

               for(int i=0; i<qsl_arrayValues.count(); i+=colCount){
                  if(i+colCount<=qsl_arrayValues.count()){
                     for(int j=0; j<colCount; j++){
                        // if table has not enough rows add one
                        if(table->rowCount(QModelIndex()) < row+1){
                           table->insertRows(row, 1, QModelIndex());
                        }

                        tableView->setText(qsl_arrayValues.at(i+j), row, j);
                     }
                     row++;
                  }
               }

               tableView->update();
               return;
            }
         }
      }
   }
}

//------------------------------------------------------------------------------
// Method       : setFieldOrder(QStringList qsl_fields)
// Filename     : screenhandler.cpp
// Description  : defines field order according to input list
//------------------------------------------------------------------------------
void ScreenHandler::setFieldOrder(QStringList qsl_fields)
{
MainFrame::vdcdebug("ScreenHandler","setFieldOrder", "QStringList qsl_fields");
   QWidget *widget = NULL;
   QWidget *firstWidget = NULL;
   QWidget *nextWidget = NULL;


   for(int i=0; i<qsl_fields.count(); i++){
//      QList<QWidget*> ql_fields = p_fglform->formElements();
      QList<QWidget*> ql_fields = p_fglform->ql_formFields;
      for(int j=0; j<ql_fields.size(); j++){
         if(LineEdit *lineEdit = qobject_cast<LineEdit *> (ql_fields.at(j))){
            if(lineEdit->name == qsl_fields.at(i) || lineEdit->colName == qsl_fields.at(i)){
               if(firstWidget == NULL){
                  firstWidget = lineEdit;
                  widget = lineEdit;
                  continue;
                }

               if(nextWidget == NULL){
                  nextWidget = lineEdit;
                }

            }
         }

         if(TextEdit *textEdit = qobject_cast<TextEdit *> (ql_fields.at(j))){
            if(textEdit->name == qsl_fields.at(i) || textEdit->colName == qsl_fields.at(i)){
               if(firstWidget == NULL){
                  firstWidget = textEdit;
                  widget = textEdit;
                  continue;
                }

               if(nextWidget == NULL){
                  nextWidget = textEdit;
                }
            }
         }
      }
      if(firstWidget != NULL && nextWidget != NULL){
         p_fglform->setTabOrder(firstWidget, nextWidget);
         firstWidget = nextWidget;
         nextWidget = NULL;
      }
   }
}

void ScreenHandler::setCursorPosition(int pos)
{
MainFrame::vdcdebug("ScreenHandler","setCursorPosition", "int pos");

if(TextEdit *edit = qobject_cast<TextEdit *> (p_fglform->currentField())){
    if(edit->toPlainText().length() < pos )
    {
        pos = edit->toPlainText().length();
    }

    QTextCursor cursor = edit->textCursor();
    cursor.setPosition(pos, QTextCursor::MoveAnchor);
    edit->setTextCursor(cursor);
    return;
}
if(LineEdit *edit = qobject_cast<LineEdit *> (p_fglform->currentField())){
    if(edit->text().length() < pos )
    {
        pos = edit->text().length();
    }

    edit->cursorForward(false, pos);
    return;
}
}

void ScreenHandler::setInputFields(QStringList qsl_fields)
{
MainFrame::vdcdebug("ScreenHandler","setInputFields", "QStringList qsl_fields");

   int i_Frm = getCurrForm();

   if(i_Frm < 0)
      return;

   if(p_fglform == NULL)
      return;

   p_fglform->qsl_fieldOrder = qsl_fields;

}

void ScreenHandler::setClearEvents()
{
MainFrame::vdcdebug("ScreenHandler","setClearEvents", "");
   clearFieldEvents = true;
}

void ScreenHandler::setArrLine(int line)
{
MainFrame::vdcdebug("ScreenHandler","setArrLine", "int line");
   if(p_fglform == NULL)
      return;

   Context *context = getCurrentContext();

   if(context == NULL)
      return;

   for(int i=0; i<context->fieldList().count(); i++){
      if(TableView *tableView = qobject_cast<TableView *> (context->fieldList().at(i))){
            tableView->setArrLine(line-1);
            context->setOption("ARRLINE", line-1);
      }
   }
}

void ScreenHandler::setScrLine(int line)
{
MainFrame::vdcdebug("ScreenHandler","setScrLine", "int line");
   if(p_fglform == NULL)
      return;
   Context *context = getCurrentContext();
   if(context == NULL)
      return;

   for(int i=0; i<context->fieldList().count(); i++){
      if(TableView *tableView = qobject_cast<TableView *> (context->fieldList().at(i))){
            tableView->setScrLine(line-1);
            context->setOption("SCRLINE", line-1);
      }
   }
}

Context* ScreenHandler::getContext(int i_context)
{
MainFrame::vdcdebug("ScreenHandler","getContext", "int i_context");
   int contextCount = contexts.count()-1;

   for(int i=contextCount; i<i_context; i++){
       //Speichere die Events im Context, da sie wenn der Context aktiv werden wieder abgearbeitet werden sollen
       if(p_fglform)
       {
           if(p_fglform->context)
           {
               p_fglform->context->ql_pandingevents += p_fglform->ql_responseQueue;
               p_fglform->ql_responseQueue.clear();
           }
       }
      Context *context = new Context;
      if(!contexts.isEmpty())
      {
          if(p_fglform)
             p_fglform->clearFieldFocus();

          int f = contexts.last()->fieldList().size();
          QList<QWidget*> ql_widgets = contexts.last()->fieldList();
          if(f > 0)
          {
              for(int i = 0; i < f; i++)
              {
                  ql_widgets.at(i)->blockSignals(true);
                  if(TableView *tableView = qobject_cast<TableView *> (ql_widgets.at(i))){
                      tableView->setIgnoreRowChange(true);

                      QModelIndex current = tableView->currentIndex();
                      tableView->closePersistentEditor(current);

                  }
                  ql_widgets.at(i)->setEnabled(false);
                  ql_widgets.at(i)->blockSignals(false);

              }
          }
      }

      contexts << context;
   }

   return contexts.at(i_context);

}

Context* ScreenHandler::getCurrentContext()
{
MainFrame::vdcdebug("ScreenHandler","getCurrentContext", "");
   if(contexts.count() > 0){
      return contexts.at(contexts.count()-1);
   }

   return NULL;

}

void ScreenHandler::freeContext(int i_context)
{
MainFrame::vdcdebug("ScreenHandler","freeContext", "int i_context");
   int contextCount = contexts.count()-1;
   if(contextCount >= i_context){
      Context *context = contexts.takeAt(i_context);
      for(int i=0; i<context->fieldList().count(); i++){
         QWidget *field = context->fieldList().at(i);
         field->blockSignals(true);
         field->setEnabled(false);
         field->clearFocus();
         if(TableView *tableView = qobject_cast<TableView *> (field)){
             tableView->setIgnoreRowChange(true);

             QModelIndex current = tableView->currentIndex();
             tableView->closePersistentEditor(current);
                if(QSortFilterProxyModel *proxyModel = qobject_cast<QSortFilterProxyModel *> (tableView->model())){
                   QModelIndex proxyIndex = proxyModel->index(0, 0);
                   tableView->selectionModel()->setCurrentIndex(current, QItemSelectionModel::Clear);
             }

         }
         if(LineEdit *le = qobject_cast<LineEdit *> (field)){
             le->setTouchendEnabled(false);
         }
         field->blockSignals(false);
      }
      //context->restoreFieldPalette();

      delete context;

      context = getCurrentContext();
      if(context)
      {
          if(!context->ql_pandingevents.isEmpty())
             p_fglform->ql_responseQueue += context->ql_pandingevents;
             context->ql_pandingevents.clear();
      }

      p_fglform->context = context;

      if(p_fglform)
         p_fglform->clearFieldFocus();

      if(context)
      {
         p_fglform->setCurrentWidget(context->lastFocusWidget());
         int f = context->fieldList().size();
         QList<QWidget*> ql_widgets = context->fieldList();
         if(f > 0)
         {
             for(int i = 0; i < f; i++)
             {
                 ql_widgets.at(i)->setEnabled(true);
                 if(TableView *tableView = qobject_cast<TableView *> (ql_widgets.at(i)))
                 {
                     QModelIndex current = tableView->currentIndex();
                     tableView->edit(current);
                 }
             }
         }
      }
      else
      {
        p_fglform->setCurrentWidget(NULL);
      }
   /*   if(context)
         context->setPaletteList();
      if(p_fglform->displayArray() || p_fglform->inputArray() || p_fglform->input() || p_fglform->construct())
        {
          p_fglform->actionMenu()->setButtonIcons();
          p_fglform->actionMenu()->setButtonPalette();
        }*/

      //->deleteLater();
   }


}

void ScreenHandler::fileBrowser(QString function, QString defPath, QString fileNames, QString fileTypes, QString caption)
{
MainFrame::vdcdebug("ScreenHandler","fileBrowser", "QString function, QString defPath, QString fileNames, QString fileTypes, QString caption");
   QString fileName;
   if(function == "opendir"){
      if(caption.isEmpty()){
         caption = tr("Open Directory");
      }
      fileName = QFileDialog::getExistingDirectory(NULL, caption,
                                                 defPath,
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
   }

   if(function == "openfile"){
      if(caption.isEmpty()){
         caption = tr("Open File");
      }
      fileName = QFileDialog::getOpenFileName(NULL, caption,
                                              defPath,
                                              QString("%1 (%2)").arg(fileNames).arg(fileTypes));
   }

   if(function == "savefile"){
      if(caption.isEmpty()){
         caption = tr("Save File");
      }
      fileName = QFileDialog::getSaveFileName(NULL, caption,
                                              defPath,
                                              QString("%1 (%2)").arg(fileNames).arg(fileTypes));
   }

   QString qs_resp;
   QDomDocument doc;
   QDomElement docElement = doc.createElement("TRIGGERED");
   doc.appendChild(docElement);

   docElement.setAttribute("ID", "RETURN");
   docElement.setAttribute("ENVELOPEID", pid);

   QDomElement syncValuesElement = doc.createElement("SVS");
   docElement.appendChild(syncValuesElement);

   QDomElement paramElement = doc.createElement("SV");
   QDomText param = doc.createTextNode(fileName);
   paramElement.appendChild(param);

   syncValuesElement.appendChild(paramElement);

   qs_resp = doc.toString();
   if(this->ph)
       QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, qs_resp));
   else
     fglFormResponse(qs_resp);
   p_fglform->b_getch_swin = false;
}

void ScreenHandler::setSearchPaths()
{
MainFrame::vdcdebug("ScreenHandler","setSearchPaths", "");
   //set the separator depending on the OS
   QChar sep;
#ifdef __WIN32__
sep = QChar(';');
#else
sep = QChar(':');
#endif

   QStringList dbPaths;

/*
   if(!qh_env["DBPATH"].isEmpty()){
      QString fullDBPath = qh_env["DBPATH"];


      int s = fullDBPath.count(sep);

      if(s > 0 ){
         dbPaths = qh_env["DBPATH"].split(sep);
      }
      else{
         // we assume theres only one Path in there
         dbPaths << qh_env["DBPATH"];
      }
   }
*/

   QDir current = QDir::current();
   if(current.cd("pics")){
      dbPaths << current.path();
      current.cdUp();
   }
   if(current.cd("images")){
      dbPaths << current.path();
      current.cdUp();
   }

   dbPaths << QDir::searchPaths("pics");
   dbPaths << ":/pics/";

   // Clean search Paths
   QDir::setSearchPaths("pics", dbPaths);
}

void ScreenHandler::checkFields()
{
MainFrame::vdcdebug("ScreenHandler","checkFields", "");
   return;
   if(p_fglform == NULL)
      return;

   bool enable = (p_fglform->state() != Fgl::CONSTRUCT);
   Q_UNUSED(enable);
}


void ScreenHandler::setUpdatesEnabled(bool en)
{
MainFrame::vdcdebug("ScreenHandler","setUpdatesEnabled", "bool en");
if(p_fglform == NULL)
{
    return;

}
p_fglform->setUserInputEnabled(en);

/*
for(int i=0; i<ql_fglForms.size(); i++){
         FglForm *form = ql_fglForms.at(i);

      if(form != NULL){
         form->setUpdatesEnabled(en);
      }
   }*/
}

void ScreenHandler::setEnv(QString name, QString env)
{
MainFrame::vdcdebug("ScreenHandler","setEnv", "QString name, QString env");
   Fgl::env[name] = env;
}

void ScreenHandler::activeFocus()
{

    if(p_fglform == NULL)
    {
        return;
    }

    if(p_fglform->dialog() == NULL && p_fglform->ringMenuPulldown() == NULL){
        p_fglform->setWindowState(Qt::WindowActive);
        p_fglform->raise();
        QApplication::setActiveWindow((QWidget*) p_fglform);
        p_fglform->activateWindow();
        //Qt3 weg, static QMetaobject::invokeoMethod in zukunft
        QApplication::postEvent(this, new QEvent((QEvent::Type)1337));

    }
    if(p_fglform->dialog() != NULL)
    {
        QApplication::setActiveWindow((QWidget*) p_fglform->dialog());
        p_fglform->dialog()->raise();
        p_fglform->dialog()->activateWindow();
    }
    if(p_fglform->ringMenuPulldown() != NULL)
    {
        QApplication::setActiveWindow((QWidget*) p_fglform->ringMenuPulldown());
        p_fglform->ringMenuPulldown()->raise();
        p_fglform->ringMenuPulldown()->activateWindow();
    }
}

bool ScreenHandler::eventFilter(QObject *obj, QEvent *event)
{
/*
  if(event->type() == QEvent::EnabledChange)
  {
      if(FglForm *p_form = qobject_cast<FglForm*> (obj))
      {
          if(!p_form->isEnabled())
          {
             if(p_form->actionMenu())
             {
                p_form->actionMenu()->restoreButtonIcon();
                p_form->actionMenu()->restoreButtonPalette();
             }
             if(p_form->context)
             {
                p_form->context->restoreFieldPalette();
             }

          }
          else
          {
              if(p_form->actionMenu())
              {
                 p_form->actionMenu()->setButtonIcons();
                 p_form->actionMenu()->setButtonPalette();
              }
          }
      }
  }
*/



    if(event->type() == QEvent::WindowActivate)
    {
        if(this->b_runinfo && this->p_pid_p > 0 && this->i_mode != 2)
        {
            MainFrame::setFocusOn(this->p_pid_p);
            //emit changefocus();
        }
        else
        {
            if(this->b_runinfo && this->i_mode != 2)
            {
                MainFrame::check_new_pids();
                if(this->b_runinfo && this->p_pid_p > 0)
                {
                    MainFrame::setFocusOn(this->p_pid_p);
                }
            }
            else
            {
               this->activeFocus();

            }
        }

    }
    if(p_fglform != NULL && event->type() == 1337)
    if(!p_fglform->b_dummy && p_fglform->isEnabled()&&p_fglform->currentField() != NULL && (p_fglform->state() == Fgl::CONSTRUCT || p_fglform->state() == Fgl::INPUT || p_fglform->state() == Fgl::INPUTARRAY))
    {

        if(TableView *tableView = qobject_cast<TableView *> (p_fglform->currentField())){
            if(p_fglform->inputArray())
            {
                if(tableView->curr_editor != NULL)
                {
                   p_fglform->setFocusOnWidget(tableView->curr_editor);
                }
            }
        }
        else
        {
            p_fglform->setFocusOnWidget(p_fglform->currentField());

        }
       // p_fglform->setCurrentField(p_fglform->currentField()->objectName(), false);

    }

//MainFrame::vdcdebug("ScreenHandler","eventFilter", "QObject *obj, QEvent *event");

/*
   if(event->type() == QEvent::WindowActivate){
      if(obj != p_fglform){
         if(p_fglform != NULL){
            if(p_fglform->dialog() == NULL){
               p_fglform->raise();
               p_fglform->activateWindow();
            }
            else{
               p_fglform->dialog()->raise();
            }
         }
      }
   }
*/

   return QObject::eventFilter(obj, event);

}

void ScreenHandler::setInterfaceText(QString text)
{
MainFrame::vdcdebug("ScreenHandler","setInterfaceText", "QString text");
   qs_interfaceTitle = text;
   for(int i=0; i<ql_fglForms.size(); i++){
       //ql_fglForms.at(i)->setWindowTitle(text);
       QMetaObject::invokeMethod(ql_fglForms.at(i), "setWindowTitle", Qt::QueuedConnection, Q_ARG(QString, text));
   }
}

void ScreenHandler::addComboBoxItem(int id, QString text, QString value)
{
   qDebug() << "p_fglform->findFieldById(id)" << p_fglform->findFieldById(id);
   if(ComboBox *cb = qobject_cast<ComboBox *> (p_fglform->findFieldById(id))){
      cb->addItem(value, text);
   } else if(LineEditDelegate *le = qobject_cast<LineEditDelegate*> (p_fglform->findFieldById(id)))
   {
       if(ComboBox *cb = qobject_cast<ComboBox*> (le->qw_editor))
       {
          cb->addItem(value, text);
       }
   }
}

void ScreenHandler::removeComboBoxItem(int id, QString text)
{
   if(ComboBox *cb = qobject_cast<ComboBox *> (p_fglform->findFieldById(id))){
      for(int i=0; i<cb->count(); i++){
         if(cb->itemText(i) == text){
            cb->removeItem(i);
            break;
         }
      }
   } else if(LineEditDelegate *le = qobject_cast<LineEditDelegate*> (p_fglform->findFieldById(id)))
   {
       if(ComboBox *cb = qobject_cast<ComboBox*> (le->qw_editor))
       {
           for(int i=0; i<cb->count(); i++){
              if(cb->itemText(i) == text){
                 cb->removeItem(i);
                 break;
              }
           }
       }
   }
}

void ScreenHandler::clearComboBox(int id)
{
   if(ComboBox *cb = qobject_cast<ComboBox *> (p_fglform->findFieldById(id))){
      cb->clear();
      cb->clearEditText();
   } else if(LineEditDelegate *le = qobject_cast<LineEditDelegate*> (p_fglform->findFieldById(id)))
   {
       if(ComboBox *cb = qobject_cast<ComboBox*> (le->qw_editor))
       {
           cb->clear();
           cb->clearEditText();
       }
   }
}

void ScreenHandler::fornameComboBox(QString fieldname)
{
    QString qs_resp = "<TRIGGERED ID=\"-123\"><SVS><SV>" + QString::number(currForm()->findFieldIdByName(fieldname)) + "</SV></SVS></TRIGGERED>";
    if(this->ph)
        QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, qs_resp));
    else
      fglFormResponse(qs_resp);

}

void ScreenHandler::getColumnNameComboBox(int id)
{
    QString qs_resp = "<TRIGGERED ID=\"-123\"><SVS><SV>" + WidgetHelper::getWidgetColName(currForm()->findFieldById(id)) + "</SV></SVS></TRIGGERED>";
    if(this->ph)
        QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, qs_resp));
    else
      fglFormResponse(qs_resp);

}

void ScreenHandler::getItemNameComboBox(int id, int pos)
{
    QString ret = "";

    if(ComboBox *cb = qobject_cast<ComboBox *> (currForm()->findFieldById(id))){
       ret = cb->itemData(pos-1).toString();
    }

    QString qs_resp = "<TRIGGERED ID=\"-123\"><SVS><SV>" + ret + "</SV></SVS></TRIGGERED>";
    if(this->ph)
        QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, qs_resp));
    else
      fglFormResponse(qs_resp);

}

void ScreenHandler::getItemCountComboBox(int id)
{
    QString ret = "-1";
    if(ComboBox *cb = qobject_cast<ComboBox *> (currForm()->findFieldById(id))){
        ret =  QString::number(cb->count());
    }
    QString qs_resp = "<TRIGGERED ID=\"-123\"><SVS><SV>" + ret + "</SV></SVS></TRIGGERED>";
    if(this->ph)
        QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, qs_resp));
    else
      fglFormResponse(qs_resp);

}

void ScreenHandler::getItemTextComboBox(int id, int pos)
{
    QString ret = "";
    if(ComboBox *cb = qobject_cast<ComboBox *> (currForm()->findFieldById(id))){
       ret =  cb->itemText(pos-1);
    }

    QString qs_resp = "<TRIGGERED ID=\"-123\"><SVS><SV>" + ret + "</SV></SVS></TRIGGERED>";
    if(this->ph)
        QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, qs_resp));
    else
      fglFormResponse(qs_resp);


}

void ScreenHandler::getTableNameComboBox(int id)
{
    QString qs_resp = "<TRIGGERED ID=\"-123\"><SVS><SV>" + WidgetHelper::getWidgetTabName(currForm()->findFieldById(id)) + "</SV></SVS></TRIGGERED>";
    if(this->ph)
        QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, qs_resp));
    else
      fglFormResponse(qs_resp);

}

void ScreenHandler::getIndexOfComboBox(int id, QString text)
{
    QString ret = "-1";
    if(ComboBox *cb = qobject_cast<ComboBox *> (currForm()->findFieldById(id))){
        ret = QString::number(cb->findText(text));
    }

    QString qs_resp = "<TRIGGERED ID=\"-123\"><SVS><SV>" + ret + "</SV></SVS></TRIGGERED>";
    if(this->ph)
        QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, qs_resp));
    else
      fglFormResponse(qs_resp);

}


void ScreenHandler::setRuninfo(int mode, QString cmd, int runcnt, bool start)
{
    /*
    if(mode == 2)
    {
       this->b_runinfo = false;
    }
    else
    {*/
        if(start)
        {
           this->b_runinfo = true;
           this->i_mode = mode;
           QStringList qsl_cmd = cmd.split(" ");
           for(int i = 0; i<qsl_cmd.size(); i++)
           {
               if(qsl_cmd.at(i).startsWith("p_"))
               {
                   this->programm_name_run = qsl_cmd.at(i);
                   break;
               }
           }

           if(this->programm_name_run.isEmpty())
           {
               if(p_fglform)
               {                   
                  if(timer == NULL)
                  {
                     timer = new QTimer(this);
                     timer->setSingleShot(true);
                     connect(timer, SIGNAL(timeout()), p_fglform, SLOT(disableForm()));
                     timer->start(1000);
                     i_runcnt = runcnt;
                  }
               }

              //Timerfall
           }
           else
           {
               if(p_fglform != NULL)
               {
                   p_fglform->setEnabled(false);
               }
           }
           VDC::waitCursor();

           this->cmd = cmd;

        }
        else
        {
            delete timer;
            timer = NULL;
            /*
            if(timer != NULL && i_runcnt == runcnt)
            {
               if(timer->isActive())
               {
                 timer->stop();
               }

               delete timer;
               timer = NULL;
             }
*/
            this->programm_name_run = "";
            this->b_runinfo = false;
            this->p_pid_p = 0;
            this->i_mode = 0;
            if(p_fglform != NULL)
            {
                p_fglform->setEnabled(true);
            }
            VDC::arrowCursor();

        }
    }
//}
    void ScreenHandler::setProgramName(QString pn)
    {

        this->programm_name = pn;
        MainFrame::check_new_pids();
    }


#ifdef KDChart_Version

void ScreenHandler::createChart(QString chart2)
{
    qDebug() << "chart2:" << chart2;
    ChartInterface *chart;
    if(chart2 == "@DIAG_BAR")
    {
        chart = new ChartInterface(ChartInterface::DIAG_BAR);
        m_bar = dynamic_cast<KDChart::BarDiagram*>(chart->getDiagram());
        chart->initBar(m_bar);
    } else if (chart2 == "@DIAG_PIE")
    {
        qDebug() << "erstelle pie";
        chart = new ChartInterface(ChartInterface::DIAG_PIE);
        m_pie = dynamic_cast<KDChart::PieDiagram*>(chart->getDiagram());
        chart->initPie(m_pie);
    }

    m_chart = chart;

}

void ScreenHandler::addChartValue(QString name, QString wert)
{
    if(wert.contains(","))
    {
        wert.replace(",", ".");
    }

        m_model.addChartData(name, wert);

}

void ScreenHandler::addChartValue(const chartVector &name, const chartVector &wert)
{
        m_model.addChartData(name, wert);

}

void ScreenHandler::displayChart(QString fileName, int diag_state)
{
    if(m_chart)
    {
        if(diag_state == 1)
        {
            m_chart->addAxis(KDChart::CartesianAxis::Left);
            m_chart->addAxis(KDChart::CartesianAxis::Bottom);
            m_chart->setDiagramColor(&m_model);
        }
        m_chart->setModel(&m_model);
        m_chart->saveAs(fileName);
    }

}

void ScreenHandler::createGantt()
{
    qDebug() << "createGantt";
    int next = ql_ganttWidget.size();
    QWidget *widget = p_fglform;
    GanttWidget *p_gantt = new GanttWidget(p_fglform);
    p_gantt->createGanttWidget();
    ql_ganttWidget << p_gantt;
    QString qs_resp = "<TRIGGERED ID=\"-123\"><SVS><SV>" + QString::number(next) + "</SV></SVS></TRIGGERED>";
    if(this->ph)
        QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, qs_resp));
    else
      fglFormResponse(qs_resp);
}

void ScreenHandler::setTitle(int ganttId, const QString title)
{
    qDebug() << "setTitle";
    QString qs_resp = "<TRIGGERED ID=\"-123\"><SVS><SV>" + QString::number(ganttId) + "</SV></SVS></TRIGGERED>";
    if(this->ph)
        QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, qs_resp));
    else
      fglFormResponse(qs_resp);
}

void ScreenHandler::readCsv(int ganttId, QString fileName)
{
    qDebug() << "readCsv";
    ql_ganttWidget.at(ganttId)->readCsv(fileName);
    ql_ganttWidget.at(ganttId)->show();

    //fglFormResponse("<TRIGGERED ID=\"-123\"><SVS><SV>" + QString::number(ganttId) + "</SV></SVS></TRIGGERED>");
}

#endif

void ScreenHandler::createBrowser()
{
    int next = ql_browser.size();
    WebBrowser *p_browser = new WebBrowser();
    p_browser->setObjectName(QString::number(next));
    p_browser->createBrowser();
    ql_browser << p_browser;

    QString qs_resp = "<TRIGGERED ID=\"-123\"><SVS><SV>" + QString::number(next) + "</SV></SVS></TRIGGERED>";
    if(this->ph)
        QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, qs_resp));
    else
      fglFormResponse(qs_resp);

}
void ScreenHandler::setUrl(int id, const QUrl &http)
{
  int code = 408; //Browser not initialised


    foreach(WebBrowser *p_browser, ql_browser)
    {
        if(QString::number(id) == p_browser->objectName())
        {
            code = 0;
            p_browser->loadUrl(http);
            break;
        }
    }

    QString qs_resp = "<TRIGGERED ID=\"-123\"><SVS><SV>" + QString::number(code) + "</SV></SVS></TRIGGERED>";
    if(this->ph)
        QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, qs_resp));
    else
      fglFormResponse(qs_resp);


}
void ScreenHandler::closeBrowser(int id)
{
  foreach(WebBrowser *p_browser, ql_browser)
  {
      if(QString::number(id) == p_browser->objectName())
      {
          p_browser->closeBrowser();
          return;
      }
  }
}


void ScreenHandler::makeFglFormResponse(QString bla)
{
    if(this->ph)
        QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, bla));
    else
      fglFormResponse(bla);
}

void ScreenHandler::checkForUpdate()
{
    QString a4gl_version_client = VDC::readSettingsFromIni("", "a4gl_version");
    if(!a4gl_version_client.isNull())
    {
        VentasUpdate *vu = new VentasUpdate(0);
        vu->checkForNewUpdates();
    }
}

void ScreenHandler::setProgressTitle(int obj, QString title)
{
Q_UNUSED(obj);

  if(!w_progress)
    return;
  w_progress->setTitle(title);
}

void ScreenHandler::setProgressText(int obj, QString text)
{
Q_UNUSED(obj);

  if(!w_progress)
    return;
  w_progress->setText1(text);
}

void ScreenHandler::setProgressVisible(int obj, bool vis)
{
Q_UNUSED(obj);

  if(!w_progress)
    return;

  QRect rect;
  if(p_fglform->b_dummy)
  {

    rect = QApplication::desktop()->screenGeometry();
    QRect w_p_rect = QRect(0,0, w_progress->sizeHint().width(), w_progress->sizeHint().height());
    w_progress->move(rect.center() - w_p_rect.center());

  }
  else
  {

      QPoint pos = p_fglform->mapToGlobal(QPoint(0,0));
      QRect w_p_rect = QRect(0,0, w_progress->sizeHint().width(), w_progress->sizeHint().height());
      w_progress->move(pos + p_fglform->rect().center() - w_p_rect.center());
  }



  w_progress->setVisible(vis);




}

void ScreenHandler::createProgressWindow()
{
  w_progress = new Progress();

  QString qs_resp = "<TRIGGERED ID=\"-123\"><SVS><SV>0</SV></SVS></TRIGGERED>";
  if(this->ph)
      QMetaObject::invokeMethod(this->ph, "fglFormResponse", Qt::DirectConnection, Q_ARG(QString, qs_resp));
  else
    fglFormResponse(qs_resp);
}

void ScreenHandler::closeProgressWindow(int obj)
{
Q_UNUSED(obj);

  if(!w_progress)
    return;
  w_progress->hide();
  delete w_progress;
  w_progress = NULL;
}

void ScreenHandler::printpdf(QString filename)
{
/*

  QFile pdffile(filename);
  if(!pdffile.open(QFile::ReadOnly))
  {
      QFile tmppdffile(QDir::tempPath() + "/" + filename);
      if(!tmppdffile.open(QFile::ReadOnly))
      {
         return; // File not found
      }
      else
      {
         filename = QDir::tempPath() + "/" + filename;
      }
      tmppdffile.close();
  }

  pdffile.close();

  Poppler::Document *pdf = Poppler::Document::load(filename);


//  pdf->setRenderHint(Poppler::Document::Antialiasing);
 // pdf->setRenderHint(Poppler::Document::TextAntialiasing);

  qDebug()<<pdf->renderBackend();

  pdf->setRenderBackend(Poppler::Document::ArthurBackend);
  QPrinter printer(QPrinter::ScreenResolution);
  QPrintDialog printdialog(&printer, p_fglform);


  printdialog.setMinMax(1, pdf->numPages());


  if(printdialog.exec() == QDialog::Accepted)
  {

  int start = printdialog.fromPage()-1;
  int end   = printdialog.toPage();

  if(start == -1)
    start = 0;

  if(end == 0)
  {
     end = pdf->numPages();
  }


  int print_dpi_y = printer.physicalDpiY();

  int print_dpi_x = printer.physicalDpiX();



  int pagewidth = printerrect.wi

  //QPainter painter;

  QPainter *painter = new QPainter();

  painter->begin(&printer);
//  painter.setRenderHint(QPainter::Antialiasing);
 // painter.setRenderHint(QPainter::TextAntialiasing);

  for(int i = start; i<end; i++)
  {
      if(i != start)
      {
          printer.newPage();
      }

      Poppler::Page *page = pdf->page(i);


      if(page->renderToPainter(painter, print_dpi_x, print_dpi_y))
      {
          qDebug()<<"Lübt";
      }
      else
      {
          qDebug()<<"Fail";
      }

     //  QImage img = page->renderToImage(print_dpi_x, print_dpi_y);
   //   QPixmap pix = QPixmap::fromImage(img, Qt::AutoColor);
  //    int pixWidth = printerrect.width();
  //    int pixHeight = printerrect.height();
  //    pix = pix.scaled(pixWidth, pixHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
     // QLabel *label = new QLabel();

    //  label->setPixmap(pix);
    //  label->show();
      //painter.drawImage(0,0,img);
      //painter.drawPixmap(0, 0, pix);
      //painter.drawImage(painter.window(), img, QRectF(0,0, img.width(), img.height()));

      delete page;
  }

 // delete painter;
  painter->end();


}



  delete pdf;
*/
}


