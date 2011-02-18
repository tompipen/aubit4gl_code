//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : fglform.cpp
// Description  : contains the fglform class definition
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
#include <QStatusBar>
#include <QDomDocument>
#include <QSplitter>

#include <mainframe.h>
#include <models/fglform.h>
#include <models/statusbar.h>
#include <models/toolbar.h>
#include <fieldparsers/xml2fields.h>
#include <fieldparsers/xml2form.h>
#include <fieldparsers/parser.h>
#include <xmlparsers/xml2menu.h>
#include <xmlparsers/xml2style.h>

//------------------------------------------------------------------------------
// Method       : FglForm()
// Filename     : fglform.cpp
// Description  : constructor for the instances
//------------------------------------------------------------------------------

FglForm::FglForm(QString windowName, QWidget *parent) : QMainWindow(parent){

   context = NULL;
   this->b_newForm = true;
   if(parent != NULL){
      setWindowModality(Qt::WindowModal);
   }

   if(!windowName.isEmpty()){
      this->windowName = windowName;
   }


   QSplitter *formSplitter = new QSplitter;
   formSplitter->setChildrenCollapsible(false);
   setCentralWidget(formSplitter);

   setState(Fgl::IDLE);


   b_getch_swin = false;
   p_actionMenu = NULL;
   p_toolBar = NULL;
   b_denyFocus = false;
   b_allowClose = false;
   b_bufferTouched = false;
   i_lastCursor = 1;

   b_menu = false;
   b_input = false;
   b_screenRecord = false;
   p_dialog = NULL;
   formWidget = NULL;

   currentWidget = NULL;

   // Default Propertys/Styleattributes (can be overridden in *.4st files);
   setProperty("startMenuPosition", "tree");
   setProperty("windowType", "normal");
   setProperty("startMenuShortcut", QString());
   setProperty("ringMenuButtonSize", QString());
   setProperty("position", QString());
   setProperty("ringMenuPosition", "right");
   setProperty("sizable", "yes");
   setProperty("actionPanelPosition", "right");
   setProperty("toolBarPosition", "top");

   createStatusBar();

   connect(this, SIGNAL(accepted()), this, SLOT(acceptTriggered()));

   this->installEventFilter(this);

   readSettingsLocal();
}

FglForm::~FglForm()
{
MainFrame::vdcdebug("FglForm","~FglForm", "");
   writeSettingsLocal();
}

//------------------------------------------------------------------------------
// Method       : createStatusBar()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::createStatusBar()
{
MainFrame::vdcdebug("FglForm","createStatusBar", "");
   StatusBar *status = new StatusBar;
   setStatusBar(status);
}

//------------------------------------------------------------------------------
// Method       : buttonClicked()
// Filename     : fglform.cpp
// Description  : is called whenever a menuButton is pressed
//                and saves it to the response queue
//------------------------------------------------------------------------------
void FglForm::buttonClicked(QString id)
{
MainFrame::vdcdebug("FglForm","buttonClicked", "QString id");
   Q_UNUSED(id);
/*
      bool ok = false;
      int i_id = id.toInt(&ok);
      if(ok){
         if(i_id >= 3000){
            Fgl::Event event;
            event.type = Fgl::ONKEY_EVENT;
            event.attribute = id;
            fieldEvent(event);
            return;
         }
      }
      
      addToQueue(id);
*/
   qFatal("::buttonClicked called");
}

//------------------------------------------------------------------------------
// Method       : addToQueue()
// Filename     : fglform.cpp
// Description  : receives the Triggered id and execs the processResponse slot
//------------------------------------------------------------------------------
void FglForm::addToQueue(QString id)
{
MainFrame::vdcdebug("FglForm","addToQueue", "QString id");
/*
      for(int i=0; i<ql_formEvents.count(); i++){
         Fgl::Event event = ql_formEvents.at(i);
         if(event.type == Fgl::ONACTION_EVENT && event.attribute == id.toLower()){
            id = QString::number(event.id);
            break;
         }
      }
*/
      ql_responseQueue << id;
      processResponse();
}

//------------------------------------------------------------------------------
// Method       : setActions()
// Filename     : fglform.cpp
// Description  : init the standard actions (ESC = INTERRUPT, F12 = ACCEPT, etc)
//                and adds them to the Form
//------------------------------------------------------------------------------
void FglForm::setActions(QDomDocument xmlFile)
{
MainFrame::vdcdebug("FglForm","setActions", "QDomDocument xmlFile");
   for(int i=0; i<defActions().size(); i++){
      removeAction(defActions().at(i));
   }

   Actions *actions = new Actions(this);
   actions->parseFile(xmlFile);


   ql_actionDefaults = actions->actions();
   QStringList names = actions->names();
   for(int i=0; i<ql_actionDefaults.size(); i++){
      QAction *action = ql_actionDefaults.at(i);
      QString name = action->objectName();

      addFormAction(action);
      continue;

      this->addAction(action);

      if(name == "accept"){
         connect(action, SIGNAL(triggered()), this, SLOT(accept()));
         continue;
      }

      if(name == "cancel"){
         connect(action, SIGNAL(triggered()), this, SLOT(cancelTriggered()));
         continue;
      }

      if(name == "editcopy"){
         connect(action, SIGNAL(triggered()), this, SLOT(editcopy()));
         continue;
      }

      if(name == "editcut"){
         connect(action, SIGNAL(triggered()), this, SLOT(editcut()));
         continue;
      }

      if(name == "editpaste"){
         connect(action, SIGNAL(triggered()), this, SLOT(editpaste()));
         continue;
      }

      if(name == "nextfield"){
         connect(action, SIGNAL(triggered()), this, SLOT(nextfield()));
         continue;
      }

      if(name == "prevfield"){
         connect(action, SIGNAL(triggered()), this, SLOT(prevfield()));
         continue;
      }
 
      if(name == "nextrow"){
         connect(action, SIGNAL(triggered()), this, SLOT(nextrow()));
         continue;
      }

      if(name == "prevrow"){
         connect(action, SIGNAL(triggered()), this, SLOT(prevrow()));
         continue;
      }

      if(name == "firstrow"){
         connect(action, SIGNAL(triggered()), this, SLOT(firstrow()));
         continue;
      }

      if(name == "lastrow"){
         connect(action, SIGNAL(triggered()), this, SLOT(lastrow()));
         continue;
      }
         
      if(name == "nextpage"){
         connect(action, SIGNAL(triggered()), this, SLOT(nextpage()));
         continue;
      }

      if(name == "prevpage"){
         connect(action, SIGNAL(triggered()), this, SLOT(prevpage()));
         continue;
      }

      if(name == "nexttab"){
         connect(action, SIGNAL(triggered()), this, SLOT(nexttab()));
         continue;
      }

      if(name == "prevtab"){
         connect(action, SIGNAL(triggered()), this, SLOT(prevtab()));
         continue;
      }

      connect(action, SIGNAL(triggered()), this, SLOT(actionTriggered()));
      action->setEnabled(false);
   }
}

//------------------------------------------------------------------------------
// Method       : initActions()
// Filename     : fglform.cpp
// Description  : init the standard actions (ESC = INTERRUPT, F12 = ACCEPT, etc)
//                and adds them to the Form
//------------------------------------------------------------------------------
void FglForm::initActions()
{
MainFrame::vdcdebug("FglForm","initActions", "");
   Action *acceptA = new Action("accept", tr("Accept"));
   acceptA->setAcceleratorName("F12");
   addFormAction(acceptA);

   Action *cancelA = new Action("cancel", tr("Cancel"));
   cancelA->setAcceleratorName("Escape");
   addFormAction(cancelA);

   Action *nextRowA = new Action("nextrow", tr("Next Row"));
   nextRowA->setAcceleratorName("Down");
//   nextRowA->setAcceleratorName2("Down");
   addFormAction(nextRowA);

   Action *prevRowA = new Action("prevrow", tr("Previous Row"));
   prevRowA->setAcceleratorName("Shift+Tab");
   prevRowA->setAcceleratorName("Up");
   addFormAction(prevRowA);

   Action *nextFieldA = new Action("nextfield", tr("Next Field"));
   nextFieldA->setAcceleratorName("Tab");
   addFormAction(nextFieldA);

   Action *prevFieldA = new Action("prevfield", tr("Previous Field"));
   prevFieldA->setAcceleratorName("Shift+Tab");
   addFormAction(prevFieldA);


   return;
}

//------------------------------------------------------------------------------
// Method       : setMenu()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::setMenu(RingMenu* p_menu)
{
MainFrame::vdcdebug("FglForm","setMenu", "RingMenu* p_menu");

   if(p_menu == NULL)
      return;

   if(menu() != NULL && menu() != p_menu){
      menu()->setParent(NULL);
/*
      disconnect(menu(), SIGNAL(menuButtonPressed(QString)),
                 this, SLOT(buttonClicked(QString)));
*/
   }

   ql_menus << p_menu;

   if(QSplitter *formSplitter = qobject_cast<QSplitter *> (this->centralWidget())){
      formSplitter->addWidget(p_menu);
      setRingMenuPosition(getRingMenuPosition());

/*
      connect(p_menu, SIGNAL(menuButtonPressed(QString)),
              this, SLOT(buttonClicked(QString)));
*/
   }
}

//------------------------------------------------------------------------------
// Method       : removeMenu()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::removeMenu()
{
MainFrame::vdcdebug("FglForm","removeMenu", "");

   // if count bigger than 1 set the old menu = act. menu
   if(ql_menus.count() > 1){
      RingMenu *p_menu = ql_menus.last();
      p_menu->setParent(NULL);
      ql_menus.removeLast();
      p_menu->deleteLater();
      //new menu
      p_menu = ql_menus.last();
      ql_menus.removeLast();
      setMenu(p_menu);
   }
}

//------------------------------------------------------------------------------
// Method       : setMenuEnabled()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::setMenuEnabled(bool enable)
{
MainFrame::vdcdebug("FglForm","setMenuEnabled", "bool enable");

   RingMenu *p_menu = menu();
   if(p_menu == NULL)
      return;

   setActionMenuEnabled(!enable);
   p_menu->setVisible(enable);
   p_menu->setEnabled(enable);
   if(enable){
      p_menu->setFocus();
   }
   
   if(this->p_toolBar == NULL)
      return;

/*
   if(ToolBar *toolBar = qobject_cast<ToolBar *> (this->p_toolBar)){
      QList<QPushButton*> buttons = menu()->buttons();
      QList<QString> actions;
      for(int i=0; i<buttons.size(); i++){
         if(buttons.at(i)->isEnabled()){
            QString action = buttons.at(i)->text();
            action.remove(0,1);
            actions << action;
         }
      }

      QList<QAction*> toolBarActions = toolBar->actions();
      for(int i=0; i<toolBarActions.size(); i++){
         toolBarActions.at(i)->showStatusText(this);
      }
   }
*/

   b_menu = enable;
}

//------------------------------------------------------------------------------
// Method       : setActionMenu()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::setActionMenu(ActionMenu* menu)
{
MainFrame::vdcdebug("FglForm","setActionMenu", "ActionMenu* menu");

   if(menu == NULL || p_actionMenu == menu)
      return;

   if(p_actionMenu != NULL){
      p_actionMenu->deleteLater();
   }

   p_actionMenu = menu;

   QSplitter *formSplitter = (QSplitter*) this->centralWidget();
   formSplitter->addWidget(menu);

/*
   connect(menu, SIGNAL(menuButtonPressed(QString)),
           this, SLOT(buttonClicked(QString)));
*/

   setActionMenuEnabled(!b_menu);
}

//------------------------------------------------------------------------------
// Method       : setActionMenuEnabled()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::setActionMenuEnabled(bool enable)
{
MainFrame::vdcdebug("FglForm","setActionMenuEnabled", "bool enable");


   if(p_actionMenu == NULL)
      return;

   p_actionMenu->setVisible(enable);
   p_actionMenu->setEnabled(enable);


//   p_actionMenu->hideButtons(!enable);
}

//------------------------------------------------------------------------------
// Method       : actionTriggered()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::actionTriggered()
{
MainFrame::vdcdebug("FglForm","actionTriggered", "");
   QObject *obj = QObject::sender();

//   qDebug() << "ACTION TRIGGERED!" << obj;
   if(Action *action = qobject_cast<Action *> (obj)){
      if(!handleGuiAction(action)){
         Fgl::Event ev;
         ev.type = Fgl::ONACTION_EVENT;
         ev.attribute = action->name();
         emit fieldEvent(ev);
      }
   }
   else{
      qFatal("Action error");
   }
}

//------------------------------------------------------------------------------
// Method       : actionTriggered()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
/*
void FglForm::actionTriggered()
{
MainFrame::vdcdebug("FglForm","actionTriggered", "");
   QObject *obj = QObject::sender();

   if(QAction *action = qobject_cast<QAction *> (obj)){

      if(RingMenu *p_menu = qobject_cast<RingMenu *> (menu())){
         QList<QPushButton*> buttons = p_menu->buttons();
         for(int i=0; i<buttons.size(); i++){
            QString name = buttons.at(i)->text();
            if(name.mid(0,1) == "&"){
               name.remove(0,1);
            }

            if(name == action->objectName()){
               addToQueue(QString::number(p_menu->buttonId(buttons.at(i))));
               return;
            }
         }

         if(!action->shortcut().toString().isEmpty()){
            bool ok;
            QString key = action->shortcut().toString();
            int num = key.mid(1, key.length()-1).toInt(&ok);
            int fKeyNum = 2999+num;
            Fgl::Event event;
            event.type = Fgl::ONKEY_EVENT;
            event.attribute = QString::number(fKeyNum);
            fieldEvent(event);
         }
      }
   }
}
*/

//------------------------------------------------------------------------------
// Method       : toolBarActionTriggered()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::toolBarActionTriggered()
{
MainFrame::vdcdebug("FglForm","toolBarActionTriggered", "");
   QObject *obj = QObject::sender();
   if(menu() != NULL && menu()->isEnabled()){
      if(QAction *action = qobject_cast<QAction *> (obj)){
         QList<QPushButton*> ql_buttons = menu()->buttons();
         for(int i=0; i<ql_buttons.size(); i++){
            QString text = ql_buttons.at(i)->text();
            if(text.mid(0,1) == "&"){
               text.remove(0,1);
            }
            if(text == action->text() || text == action->objectName()){
               addToQueue(QString::number(menu()->buttonId(ql_buttons.at(i))));
            }
         }
      }
   }
   else{
      // OK - CANCEL
      if(QAction *action = qobject_cast<QAction *> (obj)){
         if(action->objectName() == "accept"){
            accept();
         }
         if(action->objectName() == "cancel"){
            cancelTriggered();
         }
      }
   }
}

//------------------------------------------------------------------------------
// Method       : setDialog()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::setDialog(Dialog* dialog)
{
MainFrame::vdcdebug("FglForm","setDialog", "Dialog* dialog");

   p_dialog = dialog;
//   this->setEnabled(false);

/*
   if(dialog != NULL){
      connect(dialog, SIGNAL(dialogButtonPressed(QString)),
              this, SLOT(buttonClicked(QString)));
   }
*/

}

//------------------------------------------------------------------------------
// Method       : setToolBar()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::setToolBar(ToolBar *toolBar)
{
MainFrame::vdcdebug("FglForm","setToolBar", "ToolBar *toolBar");

   this->p_toolBar = toolBar;

   if(toolBarPosition() != Qt::NoToolBarArea){
      if(this->p_toolBar != this->toolBar()){
         QList<QAction*> ql_actions = this->p_toolBar->actions();
         for(int i=0; i<ql_actions.size(); i++){
//            connect(ql_actions.at(i), SIGNAL(triggered()), this, SLOT(toolBarActionTriggered()));
            connect(ql_actions.at(i), SIGNAL(triggered()), this, SLOT(actionTriggered()));
         }
      }
      this->addToolBar(toolBarPosition(), this->p_toolBar);
   }
   else{
      p_toolBar->setVisible(false);
      QList<QAction*> ql_actions = this->p_toolBar->actions();
      for(int i=0; i<ql_actions.size(); i++){
         //connect(ql_actions.at(i), SIGNAL(triggered()), this, SLOT(toolBarActionTriggered()));
         connect(ql_actions.at(i), SIGNAL(triggered()), this, SLOT(actionTriggered()));
      }
   }
}

//------------------------------------------------------------------------------
// Method       : setToolBar()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::setToolBar(QDomDocument xmlFile)
{
MainFrame::vdcdebug("FglForm","setToolBar", "QDomDocument xmlFile");
   QSize currSize = this->sizeHint();

   this->p_toolBar = new ToolBar;
   this->p_toolBar->parseFile(xmlFile);

   if(toolBarPosition() != Qt::NoToolBarArea){
         QList<QAction*> ql_actions = this->p_toolBar->actions();
         for(int i=0; i<ql_actions.size(); i++){
            //connect(ql_actions.at(i), SIGNAL(triggered()), this, SLOT(toolBarActionTriggered()));
            connect(ql_actions.at(i), SIGNAL(triggered()), this, SLOT(actionTriggered()));
         }
      this->addToolBar(toolBarPosition(), this->p_toolBar);
   }
   else{
      p_toolBar->setVisible(false);
      QList<QAction*> ql_actions = this->p_toolBar->actions();
      for(int i=0; i<ql_actions.size(); i++){
         //connect(ql_actions.at(i), SIGNAL(triggered()), this, SLOT(toolBarActionTriggered()));
         connect(ql_actions.at(i), SIGNAL(triggered()), this, SLOT(actionTriggered()));
      }
   }
}

//------------------------------------------------------------------------------
// Method       : eventFilter()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
bool FglForm::eventFilter(QObject *obj, QEvent *event)
{
//MainFrame::vdcdebug("FglForm","eventFilter", "QObject *obj, QEvent *event");

   if(event->type() == QEvent::MouseButtonRelease){
      QMouseEvent *mev = (QMouseEvent*) event;
      if(mev->button() == Qt::LeftButton){
         mev->ignore();
         QWidget *w = (QWidget*) obj;
         if(input() || construct()){
            if(context->fieldList().contains(w)){
               while(w != currentWidget){
                  nextfield();
               }
               return true;
            }
         }
      }
      if(!input() && !construct() && !screenRecord()){
         createContextMenu(mev->globalPos());
      }
   }

   processResponse();

/*
   if(event->type() == QEvent::FocusIn ||
      event->type() == QEvent::FocusOut){
      QFocusEvent *fe = (QFocusEvent*) event;
      if(fe->reason() != Qt::OtherFocusReason &&
         fe->reason() != Qt::ActiveWindowFocusReason &&
         fe->reason() != Qt::TabFocusReason){
         QWidget *w = (QWidget*) obj;
         if(w != currentWidget){
         w->clearFocus();
         event->ignore();
            return true;
         }
         while(w != currentWidget){
            nextfield();
         }
         return false;
      }
   }
*/

/*
   if(event->type() == QEvent::FocusIn){
      if(WidgetHelper::isFieldWidget(obj) && (input() || screenRecord() || construct())){
         if(QWidget *widget = qobject_cast<QWidget *> (obj)){
            if(this->focusWidget() != currentWidget){
               currentWidget = widget;
               qs_currentFieldBuffer = WidgetHelper::fieldText(widget);
               Fgl::Event fgl_event;
               fgl_event.type = Fgl::BEFORE_FIELD_EVENT;
               fgl_event.attribute = widget->objectName();
               fieldEvent(fgl_event);

               if(LineEdit *le = qobject_cast<LineEdit *> (widget)){
                  if(le->isReadOnly())
                     nextfield();
               }
            }
         }
      }
   }

   if(event->type() == QEvent::FocusOut){
      qDebug() << "FOCUS OUT:" << obj;
      if(WidgetHelper::isFieldWidget(obj) && (input() || screenRecord() || construct())){
         if(QWidget *widget = qobject_cast<QWidget *> (obj)){
            QFocusEvent *fe = (QFocusEvent*) event;
            if(fe->reason() != Qt::ActiveWindowFocusReason &&
               fe->reason() != Qt::PopupFocusReason){
               Fgl::Event event;
               event.type = Fgl::AFTER_FIELD_EVENT;
               fieldEvent(event, widget);
               currentWidget = NULL;
            }
         }
      }
   }
*/

   if(event->type() == QEvent::KeyPress){
      QKeyEvent *keyEvent = (QKeyEvent*) event;
      StatusBar *status = (StatusBar*) statusBar();
      QString keyEventString;
      keyEventString = keyEvent->text();
      if(keyEvent->key() == Qt::Key_Tab)
      {
          if(TextEdit *te = qobject_cast<TextEdit *> (obj))
          {
             if(!te->wantTabs())
             {
                 event->ignore();
                 nextfield();
                 return true;
             }
          }
      }


      if((keyEvent->modifiers() == 0 ) && (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter))
      {
          if(TextEdit *te = qobject_cast<TextEdit *> (obj))
          {
             if(!te->wantReturns())
             {
                 event->ignore();
                 nextfield();
                 return true;
             }
          }
      }

      if(keyEvent->key() == Qt::Key_Insert){
         status->toggleOverwriteMode();
         return true;
      }
      if(keyEventString != "" && status->b_overwrite )
      {

          if(LineEdit *le = qobject_cast<LineEdit *> (obj))
          {
             QString lestring;
             int pos;
             lestring = le->text();
             pos = le->cursorPosition();
             lestring.replace(pos,1,keyEventString);
             le->setText(lestring);
             le->setCursorPosition(pos+1);
             return true;
          }
          if(TextEdit *te = qobject_cast<TextEdit *> (obj))
          {
             te->setOverwriteMode(true);

          }
      }
      if(!status->b_overwrite)
      {
         if(TextEdit *te = qobject_cast<TextEdit *> (obj))
         {
                  te->setOverwriteMode(false);
         }
      }
   }


/*
      for(int i=0; i<35; i++){
         int key = 0x01000030 + i;

         if(keyEvent->key() == key){
            int fKeyNum = 3000 + i;
            Fgl::Event event;
            event.type = Fgl::ONKEY_EVENT;
            event.attribute = QString::number(fKeyNum);
            fieldEvent(event);
            return true;
         }
      }
   }
*/

   return QMainWindow::eventFilter(obj, event);
}

//------------------------------------------------------------------------------
// Method       : fieldEvent()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::fieldEvent(Fgl::Event type, QWidget* widget)
{
MainFrame::vdcdebug("FglForm","fieldEvent", "Fgl");
   //type.attribute = Fgl::stringToKey(type.attribute);

   QList<Fgl::Event> ql_events = ql_contextEvents.last();
/*
   ql_events << ql_dialogEvents;
   ql_events << ql_menuEvents;
   ql_events << ql_formEvents;
*/

   switch(type.type)
   {
      case Fgl::BEFORE_FIELD_EVENT:
      case Fgl::AFTER_FIELD_EVENT:

           for(int i=0; i<ql_events.size(); i++){
              Fgl::Event event = ql_events.at(i);
              if(event.type == type.type){
                 if(widget != NULL){
                    if(widget->objectName() == event.attribute ||
                       widget->accessibleName() == event.attribute){
                       addToQueue(QString::number(event.id));
                       return;
                    }
                 }
                 else{
                    if(type.attribute == event.attribute){
                       addToQueue(QString::number(event.id));
                       return;
                    }
                 }
              }
           }
           break;

      case Fgl::BEFORE_INSERT_DELETE_EVENT:
      case Fgl::AFTER_INSERT_DELETE_EVENT:
      case Fgl::BEFORE_MENU_EVENT:
      case Fgl::AFTER_MENU_EVENT:
      case Fgl::BEFORE_INPUT_EVENT:
      case Fgl::AFTER_INPUT_EVENT:
      case Fgl::BEFORE_CONSTRUCT_EVENT:
      case Fgl::AFTER_CONSTRUCT_EVENT:
      case Fgl::BEFORE_DISPLAY_EVENT:
      case Fgl::AFTER_DISPLAY_EVENT:
      case Fgl::BEFORE_ROW_EVENT:
      case Fgl::AFTER_ROW_EVENT:
           for(int i=0; i<ql_events.size(); i++){
              Fgl::Event event = ql_events.at(i);
              if(event.type == type.type){
                 addToQueue(QString::number(event.id));
                 return;
              }
           }
           break;

/*
      case Fgl::ONKEY_EVENT:
      case Fgl::ONACTION_EVENT:
           for(int i=0; i<ql_events.size(); i++){
              Fgl::Event event = ql_events.at(i);
              if(event.type == type.type && 
                 event.attribute.toLower() == type.attribute.toLower()){
                 addToQueue(QString::number(event.id));
                 return;
              }
           }
           break;
      case Fgl::MENUCOMMAND_EVENT:
         break;
*/
      case Fgl::ONACTION_EVENT:
      case Fgl::ONKEY_EVENT:
      case Fgl::MENUACTION_EVENT:
           for(int i=0; i<ql_events.size(); i++){
              Fgl::Event event = ql_events.at(i);
/*
              if((event.type == Fgl::ONACTION_EVENT ||
                 event.type == Fgl::MENUACTION_EVENT) && 
                 event.attribute.toLower() == type.attribute.toLower()){
*/
              if(event.attribute.toLower() == type.attribute.toLower() ||
                 Fgl::keyToString(event.attribute).toLower() == type.attribute.toLower()){
                 if(event.id >= 0){
                    addToQueue(QString::number(event.id));
                    return;
                 }
              }
           }
           //if no action was found
           if(type.attribute == "accept"){
              accept();
              return;
           }

           if(type.attribute == "cancel"){
              cancelTriggered();
              return;
           }
           break;
   }
}

//------------------------------------------------------------------------------
// Method       : closeEvent()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::closeEvent(QCloseEvent *event)
{
MainFrame::vdcdebug("FglForm","closeEvent", "QCloseEvent *event");
   if(b_allowClose){
      event->accept();
      return QMainWindow::closeEvent(event);
   }
   event->ignore();

   if(menu() != NULL && menu()->isEnabled()){
      QList<QPushButton*> buttons = menu()->buttons();
      for(int i=0; i< buttons.size(); i++){
         if(buttons.at(i)->text() == "&Ende"){
            addToQueue(QString::number(i+1));
         }
      }
   }
   else{
      addToQueue("INTERRUPT");
   }

}

//------------------------------------------------------------------------------
// Method       : sendMenuCommand()
// Filename     : fglform.cpp
// Description  : sends commands from startmenus
//               
//------------------------------------------------------------------------------
void FglForm::sendMenuCommand(QString cmd)
{
MainFrame::vdcdebug("FglForm","sendMenuCommand", "QString cmd");

   QString trigger = "<TRIGGERED ID=\"EXEC\" PROGRAMNAME=\"";
   trigger.append(cmd);
//   trigger.append("&amp;");
   trigger.append("\"/>");
   sendDirect(trigger);
}

//------------------------------------------------------------------------------
// Method       : setFormLayout()
// Filename     : fglform.cpp
// Description  : creates the formparser and adds its element
//               
//------------------------------------------------------------------------------
void FglForm::setFormLayout(const QDomDocument& docLayout)
{
MainFrame::vdcdebug("FglForm","setFormLayout", "const QDomDocument& docLayout");
   Parser *formParser = new Parser(this);
   formParser->parseForm(docLayout);
   formWidget = formParser->getFormWidget();
   //formWidget->setEnabled(false);

   QSplitter *formSplitter = (QSplitter*) this->centralWidget();
   /*
   if(formSplitter->count() > 0){
      QWidget *widget = formSplitter->widget(0);
      widget->hide();
      widget->deleteLater();
   }
   */
   //formSplitter->insertWidget(0,formWidget);
   formSplitter->addWidget(formWidget);
   //formParser->getFormWidget()->show();

   this->ql_formFields << formParser->getFieldList();

   for(int i=0; i<formElements().size(); i++){
      if(LineEdit *lineEdit = qobject_cast<LineEdit *> (formElements().at(i))){
         connect(lineEdit, SIGNAL(fieldEvent(Fgl::Event)), this, SLOT(fieldEvent(Fgl::Event)));
         connect(lineEdit, SIGNAL(nextField()), this, SLOT(nextfield()));
         connect(lineEdit, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(createContextMenu(const QPoint&)));
         connect(lineEdit, SIGNAL(error(const QString&)), this, SLOT(error(const QString&)));
         connect(lineEdit, SIGNAL(textEdited(QString)), this, SLOT(setBufferTouched()));
         connect(lineEdit, SIGNAL(editingFinished()), this, SLOT(checkField()));
         connect(lineEdit, SIGNAL(cursorPositionChanged(int, int)), this, SLOT(setLastCursor(int, int)));
         lineEdit->installEventFilter(this);
      }

      if(Button *button = qobject_cast<Button *> (formElements().at(i))){
         connect(button, SIGNAL(fieldEvent(Fgl::Event)), this, SLOT(fieldEvent(Fgl::Event)));
         button->installEventFilter(this);
      }

      if(TextEdit *textEdit = qobject_cast<TextEdit *> (formElements().at(i))){
       //  connect(textEdit, SIGNAL(returnPressed()), this, SLOT(nextfield()));
         connect(textEdit, SIGNAL(cursorPositionChanged()), this, SLOT(setLastCursor()));
         textEdit->installEventFilter(this);
      }

      if(TableView *tableView = qobject_cast<TableView *> (formElements().at(i))){
         connect(tableView, SIGNAL(fieldEvent(Fgl::Event)), this, SLOT(fieldEvent(Fgl::Event)));
         connect(tableView, SIGNAL(setArrLineSignal(int)), this, SLOT(setScreenRecordArrLine(int)));
         connect(tableView, SIGNAL(accepted()), this, SLOT(acceptTriggered()));
         connect(tableView, SIGNAL(error(const QString&)), this, SLOT(error(const QString&)));
         connect(tableView, SIGNAL(nextfield()), this, SLOT(nextfield()));
         connect(tableView, SIGNAL(prevfield()), this, SLOT(prevfield()));
      }

      if(LineEditDelegate *delegate = qobject_cast<LineEditDelegate *> (formElements().at(i))){
         delegate->setForm(this);
      }
   }
}

QList<QWidget*> FglForm::formElements()
{
MainFrame::vdcdebug("FglForm","formElements", "");
   return formWidget == NULL ? QList<QWidget*>() : formWidget->findChildren<QWidget*>();
}

//------------------------------------------------------------------------------
// Method       : clearCurrentFocus()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::clearCurrentFocus()
{
MainFrame::vdcdebug("FglForm","clearCurrentFocus", "");
   if(this->focusWidget() != NULL){
      this->focusWidget()->clearFocus();
   }
}

//------------------------------------------------------------------------------
// Method       : acceptTriggered()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::acceptTriggered()
{
MainFrame::vdcdebug("FglForm","acceptTriggered", "");
   addToQueue("ACCEPT");
}

//------------------------------------------------------------------------------
// Method       : cancelTriggered()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::cancelTriggered()
{
MainFrame::vdcdebug("FglForm","cancelTriggered", "");
   addToQueue("INTERRUPT");
}

//------------------------------------------------------------------------------
// Method       : accept()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::accept()
{
MainFrame::vdcdebug("FglForm","accept", "");
   //setClearEvents();
   //validateFields();
   clearCurrentFocus();
   emit accepted();
}

//------------------------------------------------------------------------------
// Method       : interrupt()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::interrupt()
{
MainFrame::vdcdebug("FglForm","interrupt", "");
}

//------------------------------------------------------------------------------
// Method       : setStartMenu()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::setStartMenu(const QDomDocument &doc)
{
MainFrame::vdcdebug("FglForm","setStartMenu", "const QDomDocument &doc");
   if(doc.childNodes().count() <= 0)
      return;

   XML2Menu *xml2Menu = new XML2Menu(this->property("startMenuPosition").toString());
   xml2Menu->readXML(doc);
   connect(xml2Menu, SIGNAL(sendMenuCommand(QString)), this, SLOT(sendMenuCommand(QString)));

   if(property("startMenuPosition") == "tree"){
      QSplitter *formSplitter = (QSplitter*) this->centralWidget();
      formSplitter->addWidget(xml2Menu->getMenu());
   }

   if(property("startMenuPosition") == "menu"){
      this->setMenuBar((QMenuBar*) xml2Menu->getMenu());
   }
}

//------------------------------------------------------------------------------
// Method       : setStartMenu()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::setStyles(const QDomDocument& doc)
{
MainFrame::vdcdebug("FglForm","setStyles", "const QDomDocument& doc");
   XML2Style *xml2Style = new XML2Style(this);
   xml2Style->readXML(doc);
   this->setStyleSheet(xml2Style->getStyleSheet());
}

//------------------------------------------------------------------------------
// Method       : setStartMenu()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::setToolBarPosition(const QString &sm)
{
MainFrame::vdcdebug("FglForm","setToolBarPosition", "const QString &sm");

   m_toolBarPosition = sm;

   if(toolBar() != NULL){
      setToolBar(this->p_toolBar);
   }

}

Qt::ToolBarArea FglForm::toolBarPosition()
{
MainFrame::vdcdebug("FglForm","ToolBarArea FglForm", """");
   QString toolBarPosition = getToolBarPosition();
   if(toolBarPosition == "left"){
      return Qt::LeftToolBarArea;
   }
   if(toolBarPosition == "right"){
      return Qt::RightToolBarArea;
   }
   if(toolBarPosition == "top"){
      return Qt::TopToolBarArea;
   }
   if(toolBarPosition == "bottom"){
      return Qt::BottomToolBarArea;
   }
   if(toolBarPosition == "none"){
      return Qt::NoToolBarArea;
   }

   //default
   return Qt::TopToolBarArea;
}

//------------------------------------------------------------------------------
// Method       : setStartMenu()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::setRingMenuPosition(const QString &sm)
{
MainFrame::vdcdebug("FglForm","setRingMenuPosition", "const QString &sm");
   sm.toLower();
   if(sm == "top" ||
      sm == "bottom" ||
      sm == "left" ||
      sm == "right"||
      sm == "none"){
      m_ringMenuPosition = sm;
   }
   else{
      return;
   }
   

   if(QSplitter *p_splitter = qobject_cast<QSplitter *> (centralWidget())){
      if(sm == "top" ||
         sm == "bottom"){
         p_splitter->setOrientation(Qt::Vertical);
         if(RingMenu *p_menu = qobject_cast<RingMenu *> (menu())){
            p_menu->setOrientation(Qt::Vertical);
            if(sm == "top") p_splitter->insertWidget(0, p_menu);
         }
      }
      else{
         //Left - Right
         if(sm == "left" ||
            sm == "right"){
            p_splitter->setOrientation(Qt::Horizontal);
            if(RingMenu *p_menu = qobject_cast<RingMenu *> (menu())){
               p_menu->setOrientation(Qt::Horizontal);
               if(sm == "left") p_splitter->insertWidget(0, p_menu);
            }
         }
         // None
         else{
            if(RingMenu *p_menu = qobject_cast<RingMenu *> (menu())){
               p_menu->setVisible(false);
            }
         }
      }
   }
}

//------------------------------------------------------------------------------
// Method       : setStartMenu()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::setActionPanelPosition(const QString &sm)
{
MainFrame::vdcdebug("FglForm","setActionPanelPosition", "const QString &sm");

   sm.toLower();
   if(sm == "top" ||
      sm == "bottom" ||
      sm == "left" ||
      sm == "right"||
      sm == "none"){
      m_actionPanelPosition = sm;
   }
   else{
      return;
   }


   if(QSplitter *p_splitter = qobject_cast<QSplitter *> (centralWidget())){
      if(sm == "top" ||
         sm == "bottom"){
         p_splitter->setOrientation(Qt::Vertical);
         if(ActionMenu *p_actionMenu = qobject_cast<ActionMenu *> (actionMenu())){
            p_actionMenu->setOrientation(Qt::Vertical);
            if(sm == "top") p_splitter->insertWidget(0, p_actionMenu);
         }
      }
      else{
         //Left - Right
         if(sm == "left" ||
            sm == "right"){
            p_splitter->setOrientation(Qt::Horizontal);
            if(ActionMenu *p_actionMenu = qobject_cast<ActionMenu *> (actionMenu())){
               p_actionMenu->setOrientation(Qt::Horizontal);
               if(sm == "left") p_splitter->insertWidget(0, p_actionMenu);
            }
         }
         // None
         else{
            if(ActionMenu *p_actionMenu = qobject_cast<ActionMenu *> (actionMenu())){
               p_actionMenu->setVisible(false);
            }
         }
      }
   }
}

//------------------------------------------------------------------------------
// Method       : setStartMenu()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::setSizable(const QString &sm)
{
MainFrame::vdcdebug("FglForm","setSizable", "const QString &sm");
   Q_UNUSED(sm);
}

//------------------------------------------------------------------------------
// Method       : setStartMenu()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::setDefaultStatusBar(const bool &sm)
{
MainFrame::vdcdebug("FglForm","setDefaultStatusBar", "const bool &sm");
   Q_UNUSED(sm);
}

//------------------------------------------------------------------------------
// Method       : setStartMenu()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::setWindowType(const QString &sm)
{
MainFrame::vdcdebug("FglForm","setWindowType", "const QString &sm");
   //TODO
   return;

   if(sm == "modal"){
      setWindowModality(Qt::WindowModal);
   }

   if(sm == "normal"){
      setWindowModality(Qt::NonModal);
   }

}

void FglForm::setCurrentField(QString fieldName, bool sendEvents)
{
MainFrame::vdcdebug("FglForm","setCurrentField", "QString fieldName, bool sendEvents");
   if(!screenRecord()){
      QWidget *wi = currentWidget;

      if(wi != NULL){
         wi->clearFocus();
      }

      if(wi != NULL && wi->objectName() != fieldName && sendEvents){
               Fgl::Event event;
               event.type = Fgl::AFTER_FIELD_EVENT;
               event.attribute = wi->objectName();
               fieldEvent(event);
      }

      QWidget *next = NULL;
      if(wi == NULL || (wi != NULL && wi->objectName() != fieldName)){
         for(int i=0; i<context->fieldList().count(); i++){
            if(context->fieldList().at(i)->objectName() == fieldName){
               next = context->fieldList().at(i);
               break;
            }
         }
      }
      else{
         next = wi;
      }

      if(next != NULL){
         QList<QTabWidget*> ql_tabList = formWidget->findChildren<QTabWidget*>();
         for(int i=0; i<ql_tabList.count(); i++){
            QTabWidget *tabWidget = ql_tabList.at(i);

            for(int j=0; j<tabWidget->count(); j++){
                QWidget* tab = tabWidget->widget(j);
                if(tab->findChild<QWidget*>(next->objectName())){
                   tabWidget->setCurrentIndex(j);
                   break;
               }
            }
         }
         Fgl::Event event;
         event.type = Fgl::BEFORE_FIELD_EVENT;
         event.attribute = next->objectName();
         fieldEvent(event);

         next->setFocus(Qt::TabFocusReason);
         currentWidget = next;
      }
      else{
         //NO FIELD FOUND
         qDebug() << "NO FIELD FOUND: " << fieldName;
      }
   }
   else{
      for(int i=0; i<context->fieldList().size(); i++){
         if(context->fieldList().at(i)->inherits("TableView")){
            TableView *view = (TableView*) context->fieldList().at(i);
            if(view->isEnabled()){
               QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (view->model());
               TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
               int row = view->currentIndex().row()+1;
               int column = -1;
               int columnCount = table->columnCount(QModelIndex());

               for(int i=0; i<columnCount; i++){
                  if(view->getColumnName(i) == fieldName){
                     column = i+1;
                     break;
                  }
               }

               if(column == -1){
                  //NO FIELD FOUND
                  qDebug() << "NO FIELD FOUND: " << fieldName;
                  return;
               }

               switch(state()){
                  case Fgl::INPUTARRAY:
                  case Fgl::INPUT:
                     view->setCurrentField(row, column);
                     break;
                  case Fgl::DISPLAYARRAY:
                     break;
                  default:
                     return;
               }
            }
         }
      }
   }
}

//------------------------------------------------------------------------------
// Method       : editcopy()
// Filename     : fglform.cpp
// Description  : ActionDefaults
//------------------------------------------------------------------------------
void FglForm::editcopy()
{
MainFrame::vdcdebug("FglForm","editcopy", "");

   if(WidgetHelper::isFieldWidget(this->focusWidget())){
      WidgetHelper::copy(this->focusWidget());
   }

}

//------------------------------------------------------------------------------
// Method       : editcut()
// Filename     : fglform.cpp
// Description  : ActionDefaults
//------------------------------------------------------------------------------
void FglForm::editcut()
{
MainFrame::vdcdebug("FglForm","editcut", "");
}

//------------------------------------------------------------------------------
// Method       : editpaste()
// Filename     : fglform.cpp
// Description  : ActionDefaults
//------------------------------------------------------------------------------
void FglForm::editpaste()
{
MainFrame::vdcdebug("FglForm","editpaste", "");
}
//------------------------------------------------------------------------------
// Method       : nextfield()
// Filename     : fglform.cpp
// Description  : ActionDefaults
//------------------------------------------------------------------------------
void FglForm::nextfield(bool change)
{
MainFrame::vdcdebug("FglForm","nextfield", "bool change");

   bool b_sendEvent = (QObject::sender() != NULL); //If called from screenHandler this is NULL
   b_sendEvent = change;
                                                   // Programatical change (NEXT FIELD NEXT)-> No AFTER_FIELD_EVENT

   if(!screenRecord()){
      //  If context option says not to wrap
      //  and input field is the last field in the list
      //  then trigger after "INPUT" event

      if(!this->context->getOption("WRAP")){
         if(context->fieldList().count() > 0){
            QWidget* lastField = context->fieldList().last();
            if(lastField == currentWidget){
               switch(state()){
                  case Fgl::INPUT:
                  case Fgl::CONSTRUCT:
                     acceptTriggered();
                     break;
                  default:
                     break;
               }
               return;
            }
         }
      }


      QWidget *next = NULL;
      for(int i=0; i<context->fieldList().count()-1; i++){
          if(context->fieldList().at(i) == currentWidget){
              next = context->fieldList().at(i+1);
              break;
          }
      }

      if(next == NULL){ //no next field -> go to first field
          next = context->fieldList().first();
      }

      setCurrentField(next->objectName(), b_sendEvent);
   }
   else{
      for(int i=0; i<context->fieldList().size(); i++){
         if(context->fieldList().at(i)->inherits("TableView")){
            TableView *view = (TableView*) context->fieldList().at(i);
            if(view->isEnabled()){
               //view->nextfield();
               QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (view->model());
               TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
               int row = view->currentIndex().row()+1;
               int rowCount = table->rowCount(QModelIndex());
               int column = view->currentIndex().column()+1;
               int columnCount = table->columnCount(QModelIndex());
               switch(state()){
                  case Fgl::INPUTARRAY:
                  case Fgl::INPUT:
                        if(column < columnCount){
                           //GO TO NEXT FIELD
/*
                           QModelIndex tindex = table->index(row, column+1);
                           QModelIndex index = proxyModel->mapFromSource(tindex);

                           view->setCurrentIndex(index);
*/
                           view->setCurrentField(row, column+1);
                           return;
                        }
                        else{
                           if(row < rowCount){
                              //CHANGE ROW
/*
                              QModelIndex tindex = table->index(row+1, 0);
                              QModelIndex index = proxyModel->mapFromSource(tindex);

                              view->setCurrentIndex(index);
*/
                              view->setCurrentField(row+1, 1);
                           }
                           else{
                              //CHANGE TO FIRST ROW
/*
                              QModelIndex tindex = table->index(0, 0);
                              QModelIndex index = proxyModel->mapFromSource(tindex);

                              view->setCurrentIndex(index);
*/
                           }
                        }

                     break;
                  case Fgl::DISPLAYARRAY:
                     if(row <= rowCount){
                        view->selectRow(row+1);
                     }

                     break;
                  default:
                     return;
               }
            }
         }
      }
   }
}
//------------------------------------------------------------------------------
// Method       : prevfield()
// Filename     : fglform.cpp
// Description  : ActionDefaults
//------------------------------------------------------------------------------
void FglForm::prevfield()
{
MainFrame::vdcdebug("FglForm","prevfield", "");
   bool b_sendEvent = (QObject::sender() != NULL); //If called from screenHandler this is NULL
                                                   // Programatical change (NEXT FIELD PREVIOUS)-> No AFTER_FIELD_EVENT
   if(!screenRecord()){
       QWidget *prev = NULL;
       for(int i=1; i<context->fieldList().count(); i++){
           if(context->fieldList().at(i) == currentWidget){
               prev = context->fieldList().at(i-1);
               break;
           }
       }

       if(prev == NULL){ //no next field -> go to first field
           prev = context->fieldList().last();
       }

       setCurrentField(prev->objectName(), b_sendEvent);
   }
   else{
      //find active screenRecord
      /*
      for(int i=0; i<formElements().size(); i++){
         if(formElements().at(i)->inherits("TableView")){
            TableView *view = (TableView*) formElements().at(i);
            if(view->isEnabled()){
               view->prevfield();
            }
         }
      }
      */
      for(int i=0; i<context->fieldList().size(); i++){
         if(context->fieldList().at(i)->inherits("TableView")){
            TableView *view = (TableView*) context->fieldList().at(i);
            if(view->isEnabled()){
               QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (view->model());
               TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
               int row = view->currentIndex().row();
               int rowCount = table->rowCount(QModelIndex());
               int column = view->currentIndex().column();
               int columnCount = table->columnCount(QModelIndex());
               switch(state()){
                  case Fgl::INPUTARRAY:
                  case Fgl::INPUT:
                        if(column > 0){
                           //GO TO PREV FIELD
                           QModelIndex tindex = table->index(row, column-1);
                           QModelIndex index = proxyModel->mapFromSource(tindex);

                           view->setCurrentIndex(index);
                        }
                        else{
                           if(row > 0){
                              //CHANGE ROW
                              QModelIndex tindex = table->index(row-1, columnCount-1);
                              QModelIndex index = proxyModel->mapFromSource(tindex);

                              view->setCurrentIndex(index);
                           }
                           else{
                              //CHANGE TO LAST ROW
                              QModelIndex tindex = table->index(rowCount-1,columnCount-1);
                              QModelIndex index = proxyModel->mapFromSource(tindex);

                              view->setCurrentIndex(index);
                           }
                        }

                     break;
                  case Fgl::DISPLAYARRAY:
                     if(row <= rowCount){
                        view->selectRow(row+1);
                     }

                     break;
                  default:
                     return;
               }
            }
         }
      }
   }
};

//------------------------------------------------------------------------------
// Method       : nextrow()
// Filename     : fglform.cpp
// Description  : ActionDefaults
//------------------------------------------------------------------------------
void FglForm::nextrow()
{
MainFrame::vdcdebug("FglForm","nextrow", "");
   //find active screenRecord
   for(int i=0; i<formElements().size(); i++){
      if(formElements().at(i)->inherits("TableView")){
         TableView *view = (TableView*) formElements().at(i);
         if(view->isEnabled()){
            QModelIndex currentIndex = view->currentIndex();
            int currentRow = currentIndex.row()+1;
            int currentColumn = currentIndex.column()+1;
            if(!inputArray()){
               if(currentRow <= view->model()->rowCount()){
                  view->selectRow(currentRow);
               }
            }
            else{
               view->setCurrentField(currentRow+1, currentColumn);
            }
         }
      }
   }
};

//------------------------------------------------------------------------------
// Method       : prevrow()
// Filename     : fglform.cpp
// Description  : ActionDefaults
//------------------------------------------------------------------------------
void FglForm::prevrow()
{
MainFrame::vdcdebug("FglForm","prevrow", "");
   //find active screenRecord
   for(int i=0; i<formElements().size(); i++){
      if(formElements().at(i)->inherits("TableView")){
         TableView *view = (TableView*) formElements().at(i);
         if(view->isEnabled()){
            QModelIndex currentIndex = view->currentIndex();
            int currentRow = currentIndex.row()+1;
            int currentColumn = currentIndex.column()+1;
            if(!inputArray()){
               if(currentRow <= view->model()->rowCount()){
                  view->selectRow(currentRow-2);
               }
            }
            else{
               view->setCurrentField(currentRow-1, currentColumn);
            }
         }
      }
   }
};
void FglForm::firstrow()
{
MainFrame::vdcdebug("FglForm","firstrow", "");
   //find active screenRecord
   for(int i=0; i<formElements().size(); i++){
      if(formElements().at(i)->inherits("TableView")){
         TableView *view = (TableView*) formElements().at(i);
         if(view->isEnabled()){
            QModelIndex currentIndex = view->currentIndex();
            int currentRow = currentIndex.row()+1;
            int currentColumn = currentIndex.column()+1;
            if(!inputArray()){
               if(currentRow <= view->model()->rowCount()){
                  view->selectRow(0);
               }
            }
            else{
               view->setCurrentField(1, currentColumn);
            }
         }
      }
   }
};
void FglForm::lastrow()
{
MainFrame::vdcdebug("FglForm","lastrow", "");
   //find active screenRecord
   for(int i=0; i<formElements().size(); i++){
      if(formElements().at(i)->inherits("TableView")){
         TableView *view = (TableView*) formElements().at(i);
         if(view->isEnabled()){
            QModelIndex currentIndex = view->currentIndex();
            int currentRow = currentIndex.row()+1;
            int currentColumn = currentIndex.column()+1;
            int rowCount = view->model()->rowCount(QModelIndex());
            if(!inputArray()){
               if(currentRow <= view->model()->rowCount()){
                  view->selectRow(0);
               }
            }
            else{
               view->setCurrentField(rowCount, currentColumn);
            }
         }
      }
   }
};
void FglForm::nextpage(){};
void FglForm::prevpage(){};
void FglForm::nexttab()
{
MainFrame::vdcdebug("FglForm","nexttab", "");
   for(int i=0; i<formWidget->children().size(); i++){
      if(QTabWidget *p_tabWidget = qobject_cast<QTabWidget *> (formWidget->children().at(i))){
         if(p_tabWidget->isEnabled()){
            int currentIndex = p_tabWidget->currentIndex();
            if(currentIndex < p_tabWidget->count())
               p_tabWidget->setCurrentIndex(currentIndex+1);
         }
      }
   }
};
void FglForm::prevtab()
{
MainFrame::vdcdebug("FglForm","prevtab", "");
   for(int i=0; i<formWidget->children().size(); i++){
      if(QTabWidget *p_tabWidget = qobject_cast<QTabWidget *> (formWidget->children().at(i))){
         if(p_tabWidget->isEnabled()){
            int currentIndex = p_tabWidget->currentIndex();
            if(currentIndex >= p_tabWidget->count()-1)
               p_tabWidget->setCurrentIndex(currentIndex-1);
         }
      }
   }
};

//------------------------------------------------------------------------------
// Method       : validateFields()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::validateFields()
{
MainFrame::vdcdebug("FglForm","validateFields", "");
   int start=0;

   for(int k=0; k<qsl_fieldOrder.size(); k++){
      if(WidgetHelper::isFieldWidget(this->focusWidget(), qsl_fieldOrder.at(k))){
         start=k;
         break;
      }
   }

   for(int i=start; i<qsl_fieldOrder.size(); i++){
      for(int j=0; j<formElements().size(); j++){
         if(WidgetHelper::isFieldWidget(formElements().at(j), qsl_fieldOrder.at(i))){
            QWidget *widget = (QWidget*) formElements().at(j);
            widget->setFocus();
            widget->clearFocus();
            continue;
         }
      }
   }
}

//------------------------------------------------------------------------------
// Method       : checkToolBar()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
/*
void FglForm::checkToolBar()
{
MainFrame::vdcdebug("FglForm","checkToolBar", "");
   if(ToolBar *p_toolBar = qobject_cast<ToolBar *> (toolBar())){

      QList<QAction*> toolBarActions = p_toolBar->actions();
      for(int i=0; i<toolBarActions.size(); i++){
         toolBarActions.at(i)->setEnabled(false);
      }

      if(RingMenu *p_menu = qobject_cast<RingMenu *> (menu())){
         QList<QPushButton*> buttons = p_menu->buttons();
         QList<QString> menuActions;

         for(int i=0; i<buttons.size(); i++){
            if(buttons.at(i)->isEnabled()){
               QString action = buttons.at(i)->text();
               if(action.mid(0,1) == "&"){
                  action.remove(0,1);
               }
               menuActions << action;
            }
         }

         for(int i=0; i<menuActions.size(); i++){
            QString menuAction = menuActions.at(i);
            for(int k=0; k<toolBarActions.size(); k++){
               QString toolBarAction = toolBarActions.at(k)->text();
               QString toolBarActionName = toolBarActions.at(k)->objectName();
               if(menuAction == toolBarAction || menuAction == toolBarActionName){
                  toolBarActions.at(k)->setEnabled(true);
               }
            }
         }
      }

      QList<QString> actionDefaults;
      for(int i=0; i<actions().size(); i++){
         if(actions().at(i)->isEnabled()){
            QString action = actions().at(i)->objectName();
            actionDefaults << action;
         }
      }

      for(int i=0; i<actionDefaults.size(); i++){
         QString formAction = actionDefaults.at(i);
         for(int k=0; k<toolBarActions.size(); k++){
            QString toolBarAction = toolBarActions.at(k)->objectName();
            if(formAction == toolBarAction){
               toolBarActions.at(k)->setEnabled(true);
               break;
            }
         }
      }
   }
}
*/

//------------------------------------------------------------------------------
// Method       : revertState()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::revertState(Fgl::State state){

   for(int i=ql_states.count()-1; i>=0; i--){
      if(state == ql_states.at(i)){
         ql_states.takeAt(i);
         ql_contextEvents.takeAt(i);
         break;
      }
   }
   checkState();
}


//------------------------------------------------------------------------------
// Method       : checkState()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::checkState()
{
MainFrame::vdcdebug("FglForm","checkState", "");
   if(p_dialog != NULL){
      checkActions();
      return;
   }

   Fgl::State state = ql_states.last();

   bool enable = (state == Fgl::MENU);

   if(m_actionPanelPosition == "none")
   {
      setActionMenuEnabled(false);
   }
   else
   {
      setActionMenuEnabled(!enable);
   }
   if(m_ringMenuPosition == "none")
   {
      setMenuEnabled(false);
   }
   else
   {
      setMenuEnabled(enable);
   }
/*
   if(state == Fgl::INPUT ||
      state == Fgl::CONSTRUCT ||
      state == Fgl::DISPLAYARRAY ||
      state == Fgl::INPUTARRAY){
      setActionMenuEnabled(true);
      setMenuEnabled(false);
   }
   else{
      setActionMenuEnabled(false);
      setMenuEnabled(true);
   }
*/

   checkActions();
}

//------------------------------------------------------------------------------
// Method       : writeSettingsLocal()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::writeSettingsLocal()
{
MainFrame::vdcdebug("FglForm","writeSettingsLocal", "");
   QSettings settings;

   settings.beginGroup(windowName);
   settings.setValue("pos", pos());
   settings.endGroup();
}

//------------------------------------------------------------------------------
// Method       : readSettingsLocal()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::readSettingsLocal()
{
MainFrame::vdcdebug("FglForm","readSettingsLocal", "");
   QSettings settings;
                    

    settings.beginGroup(windowName);
    move(settings.value("pos").toPoint());
    settings.endGroup();

    update();

}

//------------------------------------------------------------------------------
// Method       : contextMenuEvent()
// Filename     : fglform.cpp
// Description  : opens the contextmenu when clicked right button on the form
//------------------------------------------------------------------------------
void FglForm::contextMenuEvent(QContextMenuEvent *ev)
{
MainFrame::vdcdebug("FglForm","contextMenuEvent", "QContextMenuEvent *ev");
   createContextMenu(ev->globalPos());
   
}
void FglForm::createContextMenu(const QPoint &pos)
{
MainFrame::vdcdebug("FglForm","createContextMenu", "const QPoint &pos");
   QMenu* contextMenu = new QMenu(this);
/*
   contextMenu->setStyleSheet("QMenu { background-color: blue;}  \
                               QMenu::item {background-color: transparent;}  \
                               QMenu::item:selected {background-color: red;}");
*/
   QPoint menuPos;

   if(QObject::sender() != NULL){
      QWidget *w = (QWidget*) QObject::sender();
      //Map pos from Widget to Form
      menuPos = w->mapToGlobal(pos);

      if(LineEdit *lineEdit = qobject_cast<LineEdit *> (w)){
         contextMenu = lineEdit->createStandardContextMenu();
         contextMenu->addSeparator();
      }

   }
   else{
      menuPos = pos;
   }

   //dbutest
   QList<QAction*> ql_actions;
   if(RingMenu *p_menu = qobject_cast<RingMenu *> (menu())){
      ql_actions << p_menu->actions();
   }

/*
   for(int i=0; i<actions().size(); i++){
      //if(Action *action = qobject_cast<Action *> (actions.at(i))){
      if(actions().at(i)->isEnabled() && actions().at(i)->isVisible())
            ql_actions << actions().at(i);
   }
*/

   contextMenu->addActions(ql_actions);

   if(contextMenu->actions().count() > 0){
      contextMenu->exec(menuPos);
   }
   delete contextMenu;
   return;

   switch(state())
   {
      case Fgl::IDLE:
         break;

      case Fgl::MENU:

         // Add all active menuactions to the contextmenu
         if(RingMenu *p_menu = qobject_cast<RingMenu *> (menu())){
            if(p_menu->isVisible()){
               QList<QPushButton*> buttons = p_menu->buttons();
               for(int i=0; i<buttons.size(); i++){
                  QPushButton *button = buttons.at(i);
                  if(button->isEnabled() && button->isVisible()){
                     QString buttonText = button->text();
                     QIcon icon = button->icon();
                     QAction *action = new QAction(icon, buttonText, this);
                     contextMenu->addAction(action);
                     connect(action, SIGNAL(triggered()), button, SLOT(click()));
                  }
               }
               //Add all active formactions to the contextmenu
               for(int i=0; i<actions().size(); i++){
                  QAction *formAction = actions().at(i);
                  if(formAction->isEnabled() || formAction->isVisible()){
                     QAction *action = new QAction(formAction->text(), this);
                     contextMenu->addAction(action);
                     connect(action, SIGNAL(triggered()), formAction, SLOT(trigger()));
                  }
               }
            }
         }
         
         break;

      case Fgl::INPUT:
      case Fgl::CONSTRUCT:
      case Fgl::DISPLAYARRAY:
      case Fgl::INPUTARRAY:
         //Add all active formactions to the contextmenu
         for(int i=0; i<actions().size(); i++){
            QAction *formAction = actions().at(i);
            if(formAction->isEnabled() && formAction->isVisible()){
               QAction *action = new QAction(formAction->text(), this);
               contextMenu->addAction(action);
               connect(action, SIGNAL(triggered()), formAction, SLOT(trigger()));
            }
         }
         
         //Add all active actions from actionmenu to the contextmenu
         if(ActionMenu *p_menu = qobject_cast<ActionMenu *> (actionMenu())){
            if(p_menu->isVisible()){
               QList<QPushButton*> buttons = p_menu->buttons();
               for(int i=0; i<buttons.size(); i++){
                  QPushButton *button = buttons.at(i);
                  QString buttonText = button->text();
                  QIcon icon = button->icon();
                  QAction *action = new QAction(icon, buttonText, this);
                  contextMenu->addAction(action);
                  connect(action, SIGNAL(triggered()), button, SLOT(click()));
               }
            }
         }
         break;
   }
         
   if(contextMenu->actions().count() > 0){
      contextMenu->exec(menuPos);
   }
   delete contextMenu;
}

QWidget* FglForm::findFieldByName(QString fieldName)
{
MainFrame::vdcdebug("FglForm","findFieldByName", "QString fieldName");
   QList<QWidget*> ql_fields = ql_formFields;

   int index = fieldName.indexOf(".");
   int index2 = fieldName.indexOf("[");

   if(index2 > 0){
      int index3 = fieldName.indexOf("]")+1;

      fieldName.remove(index2, index3-index2);
      index = fieldName.indexOf(".");
   }

   if(index < 0){
      // DISPLAY BY NAME
      QList<QString> keys = recordView.keys();
      for(int i=0; i<keys.count(); i++){
         QList<Fgl::Link> links = recordView[keys.at(i)];
         for(int j=0; j<links.count(); j++){
            Fgl::Link link = links.at(j);
            if(link.colName == fieldName)
               return ql_fields.at(link.fieldIdRef);
         }
      }
   }
   else{
     QString tabName = fieldName.mid(0,index);
     fieldName = fieldName.mid(index+1,fieldName.length()-index-1);
      // DISPLAY TO
     QList<Fgl::Link> links = recordView[tabName];
     for(int i=0; i<links.count(); i++){
        Fgl::Link link = links.at(i);
        if(link.colName == fieldName){
           return ql_fields.at(link.fieldIdRef);
        }
     }
   }

   return NULL;
}

QList<QWidget*> FglForm::findFieldsByName(QString fieldName)
{
MainFrame::vdcdebug("FglForm","findFieldsByName", "QString fieldName");

   QList<QWidget*> ql_foundFields;

   QList<QWidget*> ql_fields = ql_formFields;

   int index = fieldName.indexOf(".*");

   QString tabName = fieldName.left(index);

   QList<Fgl::Link> links = recordView[tabName];
   for(int i=0; i<links.count(); i++){
      Fgl::Link link = links.at(i);
      ql_foundFields << ql_fields.at(link.fieldIdRef);
   }

   return ql_foundFields;
}

void FglForm::setScreenRecordArrLine(int line)
{
MainFrame::vdcdebug("FglForm","setScreenRecordArrLine", "int line");

   setArrLine(line);

}

void FglForm::error(const QString& text){

   StatusBar *statusBar = (StatusBar*) this->statusBar();
   statusBar->displayError(text);
}

void FglForm::addFormAction(QAction *qaction)
{
MainFrame::vdcdebug("FglForm","addFormAction", "QAction *qaction");
   QList<QAction*> formActions = this->actions();
   bool createAction = true;

   Action *action = qobject_cast<Action *> (qaction);

   if(!action)
      return;

   for(int i=0; i<formActions.count(); i++){
      if(Action *fAction = qobject_cast<Action *> (formActions.at(i))){
         if(fAction->name() == action->name()){

            createAction = false;
            if(!action->text().isEmpty())
               fAction->setText(action->text());

            if(!action->comment().isEmpty())
               fAction->setComment(action->comment());

            if(!action->image().isEmpty())
               fAction->setImage(action->image());

            if(!action->acceleratorName().isEmpty())
               fAction->setAcceleratorName(action->acceleratorName());

            if(!action->acceleratorName2().isEmpty())
               fAction->setAcceleratorName2(action->acceleratorName2());

            if(!action->acceleratorName3().isEmpty())
               fAction->setAcceleratorName3(action->acceleratorName3());

            if(!action->acceleratorName4().isEmpty())
               fAction->setAcceleratorName4(action->acceleratorName4());

            if(!action->defaultView().isEmpty())
               fAction->setDefaultView(action->defaultView());

            break;
         }
      }
   }

   if(createAction){
      action->setEnabled(false);
      this->addAction(action);
      connect(action, SIGNAL(triggered()), this, SLOT(actionTriggered()));
   }
}

void FglForm::addFormAction(QString name, QString text, QString comment, QString image, QString accName, QString accName2, QString accName3, QString accName4, QString defaultView)
{
MainFrame::vdcdebug("FglForm","addFormAction", "QString name, QString text, QString comment, QString image, QString accName, QString accName2, QString accName3, QString accName4, QString defaultView");
   QList<QAction*> formActions = this->actions();
   bool createAction = true;

   for(int i=0; i<formActions.count(); i++){
      if(Action *fAction = qobject_cast<Action *> (formActions.at(i))){
         if(fAction->name() == name){

            createAction = false;
            if(!text.isEmpty())
               fAction->setText(text);

            if(!comment.isEmpty())
               fAction->setComment(comment);

            if(!image.isEmpty())
               fAction->setImage(image);

            if(!accName.isEmpty())
               fAction->setAcceleratorName(accName);

            if(!accName2.isEmpty())
               fAction->setAcceleratorName2(accName2);

            if(!accName3.isEmpty())
               fAction->setAcceleratorName3(accName3);

            if(!accName4.isEmpty())
               fAction->setAcceleratorName4(accName4);

            if(!defaultView.isEmpty())
               fAction->setDefaultView(defaultView);
         }
      }
   }

   if(createAction){
      Action *action = new Action(name, text, this);
      action->setComment(comment);
      action->setImage(image);
      action->setAcceleratorName(accName);
      action->setAcceleratorName2(accName2);
      action->setAcceleratorName3(accName3);
      action->setAcceleratorName4(accName4);
      this->addAction(action);
      connect(action, SIGNAL(triggered()), this, SLOT(actionTriggered()));
   }
}

void FglForm::addFormEvent(Fgl::Event newEvent)
{
MainFrame::vdcdebug("FglForm","addFormEvent", "Fgl");
   QList<Fgl::Event> ql_events = ql_contextEvents.last();

//old
/*
   for(int i=0; i<ql_formEvents.count(); i++){
      Fgl::Event ev = ql_formEvents.at(i);

      if(ev.attribute == newEvent.attribute){
         ql_formEvents.replace(i, newEvent);
         return;
      }
   }
*/

//new
   for(int i=0; i<ql_events.count(); i++){
      Fgl::Event ev = ql_events.at(i);

      if(ev.type == newEvent.type &&
         ev.attribute == newEvent.attribute){
         ql_events.replace(i, newEvent);
         ql_contextEvents.replace(ql_contextEvents.count()-1, ql_events);
         return;
      }
   }

   ql_formEvents << newEvent;
   ql_events << newEvent;
   ql_contextEvents.replace(ql_contextEvents.count()-1, ql_events);
}

void FglForm::checkToolBar()
{
MainFrame::vdcdebug("FglForm","checkToolBar", "");
   if(this->toolBar() == NULL)
      return;

   QList<QAction*> tbActions = this->toolBar()->actions();
   QList<QAction*> menuActions;
   QList<QAction*> formActions = this->actions();

    //first disable all toolabr actions
   for(int i=0; i<tbActions.count(); i++){
      tbActions.at(i)->setEnabled(false);
   }

   if(state() == Fgl::IDLE)
      return;

   //if menu is enabled..
   if(state() == Fgl::MENU){
      //get alle menu entries
      if(RingMenu *p_menu = qobject_cast<RingMenu *> (menu())){
         menuActions << p_menu->actions();
      }
      for(int i=0; i<tbActions.count(); i++){
         if(Action *tbAction = qobject_cast<Action *> (tbActions.at(i))){
            for(int i=0; i<menuActions.count(); i++){
               if(Action *menuAction = qobject_cast<Action *> (menuActions.at(i))){
                  if(tbAction->name() == menuAction->name()){
                     tbAction->setEnabled(true);
                     break;
                  }
               }
            }
         }
      }
      return;
   }


   for(int i=0; i<tbActions.count(); i++){
      if(Action *tbAction = qobject_cast<Action *> (tbActions.at(i))){
         for(int i=0; i<formActions.count(); i++){
            if(Action *formAction = qobject_cast<Action *> (formActions.at(i))){
               if(tbAction->name() == formAction->name()){
                  if(formAction->isEnabled())
                     tbAction->setEnabled(true);
                  break;
               }
            }
         }
      }
   }
}

void FglForm::checkActions()
{
MainFrame::vdcdebug("FglForm","checkActions", "");
   QList<QAction*> formActions = this->actions();
   for(int i=0; i<formActions.count(); i++){
      formActions.at(i)->setEnabled(false);
   }

   checkGuiActions();

   if(state() == Fgl::MENU){
      //checkMenu();
      if(RingMenu *p_menu = qobject_cast<RingMenu *> (menu())){
         QList<QAction*> menuActions = p_menu->actions();

         for(int i=0; i<menuActions.count(); i++){
            if(Action *mAction = qobject_cast<Action *> (menuActions.at(i))){
               for(int j=0; j<formActions.count(); j++){
                  if(Action *fAction = qobject_cast<Action *> (formActions.at(j))){
                     if(mAction->name() == fAction->name()){
                        fAction->setEnabled(true);
                        if(QPushButton *button = qobject_cast<QPushButton *> (mAction->parent())){
                           if(!fAction->image().isEmpty()){
                              mAction->setImage(fAction->image());
                              button->setIcon(QIcon(QString("pics:%1").arg(fAction->image())));
                           }
                           if(p_menu->isActionButton(button)){
                              button->setText(fAction->text());
                           }
                        }
                        break;
                     }
                  }
               }
            }
         }
      }
      if(Dialog *p_dialog = qobject_cast<Dialog *> (dialog())){
         QList<QAction*> dialogActions = p_dialog->actions();

         for(int i=0; i<dialogActions.count(); i++){
            if(Action *dAction = qobject_cast<Action *> (dialogActions.at(i))){
               for(int j=0; j<formActions.count(); j++){
                  if(Action *fAction = qobject_cast<Action *> (formActions.at(j))){
                     if(dAction->name() == fAction->name()){
                        fAction->setEnabled(true);
                        if(QPushButton *button = qobject_cast<QPushButton *> (dAction->parent())){
                           if(!fAction->image().isEmpty()){
                              dAction->setImage(fAction->image());
                              button->setIcon(QIcon(QString("pics:%1").arg(fAction->image())));
                           }
                        }
                        break;
                     }
                  }
               }
            }
         }
        
      }
   }

   if(input() || construct() || screenRecord()){
      for(int i=0; i<formActions.count(); i++){
         if(Action *fAction = qobject_cast<Action *> (formActions.at(i))){
            for(int j=0; j<ql_contextEvents.last().count(); j++){
               Fgl::Event ev = ql_contextEvents.last().at(j);
               if(ev.type == Fgl::ONACTION_EVENT ||
                  ev.type == Fgl::ONKEY_EVENT){
                  if(fAction->name() == ev.attribute){
                     fAction->setEnabled(true);
                     if(fAction->defaultView() == "yes"){
                        if(ActionMenu *aMenu = qobject_cast<ActionMenu *> (actionMenu())){
                           if(!(fAction == actionMenu()->getAction(fAction->name()))){
                              aMenu->createButton(fAction->name(), fAction->text(), fAction->comment(), fAction);
                           }
                        }
                     }
                     else{
                        if(fAction->defaultView() == "auto"){
                           //check Toolbar for action
                           bool found = false;
                           if(ToolBar *p_toolBar = qobject_cast<ToolBar *> (toolBar())){
                              if(p_toolBar->isVisible()){
                                 QList<QAction*> tbActions = p_toolBar->actions();
                                 for(int i=0; i<tbActions.count(); i++){
                                    if(Action *tbAction = qobject_cast<Action *> (tbActions.at(i))){
                                       if(tbAction->name() == fAction->name() && tbAction->isVisible()){
                                          found = true;
                                          break;
                                       }
                                    }
                                 }
                              }
                           }
                           if(!found){
                              if(ActionMenu *aMenu = qobject_cast<ActionMenu *> (actionMenu())){
                                 if(!(fAction == actionMenu()->getAction(fAction->name()))){
                                    aMenu->createButton(fAction->name(), fAction->text(), fAction->comment(), fAction);
                                 }
                              }
                           }
                        }
                     }
                     break;
                  }
               }
            }
         }
      }
   }

   checkShortcuts();
   checkToolBar();
}

void FglForm::checkGuiActions()
{
MainFrame::vdcdebug("FglForm","checkGuiActions", "");
   QList<QAction*> formActions = this->actions();
   for(int i=0; i<formActions.count(); i++){
      
      if(Action *fAction = qobject_cast<Action *> (formActions.at(i))){
         if(fAction->name() == "accept")
            fAction->setEnabled((input() || construct() || screenRecord()));

         if(fAction->name() == "cancel")
            fAction->setEnabled((input() || construct() || screenRecord()));

         if(fAction->name() == "insert")
            fAction->setEnabled(inputArray());

         if(fAction->name() == "append")
            fAction->setEnabled(inputArray());

         if(fAction->name() == "delete")
            fAction->setEnabled(inputArray());

         if(fAction->name() == "editcopy")
            fAction->setEnabled((input() || construct() || screenRecord() || dialog()));

         if(fAction->name() == "editcut")
            fAction->setEnabled((input() || construct() || screenRecord() || dialog()));

         if(fAction->name() == "editpaste")
            fAction->setEnabled((input() || construct() || screenRecord() || dialog()));

         if(fAction->name() == "nextfield")
            fAction->setEnabled((input() || construct() || (inputArray())));

         if(fAction->name() == "prevfield")
            fAction->setEnabled((input() || construct() || (inputArray())));

         if(fAction->name() == "nextrow")
            fAction->setEnabled(screenRecord());

         if(fAction->name() == "prevrow")
            fAction->setEnabled(screenRecord());

         if(fAction->name() == "firstrow")
            fAction->setEnabled(screenRecord());

         if(fAction->name() == "lastrow")
            fAction->setEnabled(screenRecord());

         if(fAction->name() == "nextpage")
            fAction->setEnabled(screenRecord());

         if(fAction->name() == "prevpage")
            fAction->setEnabled(screenRecord());

         if(fAction->name() == "nexttab")
            fAction->setEnabled((state() != Fgl::IDLE));

         if(fAction->name() == "prevtab")
            fAction->setEnabled((state() != Fgl::IDLE));

      }
      
   }

}

void FglForm::checkMenu()
{
MainFrame::vdcdebug("FglForm","checkMenu", "");

   
}

bool FglForm::handleGuiAction(Action* fAction)
{
MainFrame::vdcdebug("FglForm","handleGuiAction", "Action* fAction");
   for(int j=0; j<ql_contextEvents.last().count(); j++){
      Fgl::Event ev = ql_contextEvents.last().at(j);
      if(ev.type == Fgl::ONACTION_EVENT || ev.type == Fgl::ONKEY_EVENT || ev.type == Fgl::MENUACTION_EVENT){
         if(ev.attribute == fAction->name())
            return false;
      }
   }

   if(fAction->name() == "accept"){
      accept();
      return true;
   }

   if(fAction->name() == "cancel"){
      cancelTriggered();
      return true;
   }

   if(fAction->name() == "insert"){
      return true;
   }

   if(fAction->name() == "append"){
      return true;
   }

   if(fAction->name() == "delete"){
      return true;
   }

   if(fAction->name() == "editcopy"){
      editcopy();
      return true;
   }

   if(fAction->name() == "editcut"){
      editcut();
      return true;
   }

   if(fAction->name() == "editpaste"){
      editpaste();
      return true;
   }

   if(fAction->name() == "nextfield"){
      nextfield();
      return true;
   }

   if(fAction->name() == "prevfield"){
      prevfield();
      return true;
   }

   if(fAction->name() == "nextrow"){
      nextrow();
      return true;
   }

   if(fAction->name() == "prevrow"){
      prevrow();
      return true;
   }

   if(fAction->name() == "firstrow"){
      firstrow();
      return true;
   }

   if(fAction->name() == "lastrow"){
      lastrow();
      return true;
   }

   if(fAction->name() == "nextpage"){
      nextpage();
      return true;
   }

   if(fAction->name() == "prevpage"){
      prevpage();
      return true;
   }

   if(fAction->name() == "nexttab"){
      nexttab();
      return true;
   }

   if(fAction->name() == "prevtab"){
      prevtab();
      return true;
   }

   return false;
}

void FglForm::checkShortcuts()
{
MainFrame::vdcdebug("FglForm","checkShortcuts", "");

    QList<QAction*> actions = this->actions();
    for(int i=0; i<actions.count(); i++){
       if(Action *action = qobject_cast<Action *> (actions.at(i))){
          action->setAccNameEnabled(true);
       }
    }


    for(int i=actions.count()-1; i>=0; i--){
       if(Action *action = qobject_cast<Action *> (actions.at(i))){
          QString s1 = action->acceleratorName();
          QString s2 = action->acceleratorName2();
          QString s3 = action->acceleratorName3();
          QString s4 = action->acceleratorName4();

          if(!action->isEnabled() || !action->accNameEnabled())
             continue;

          if(!s1.isEmpty()){
             for(int j=0; j<actions.count(); j++){
                if(Action *action2 = qobject_cast<Action *> (actions.at(j))){
                   if(action == action2 || !action2->isEnabled())
                      continue;
   
                   if(bool enable = Fgl::stringToKey(action2->acceleratorName()) == Fgl::stringToKey(s1)){
                      action2->setAccNameEnabled(!enable);
                   }

                   if(bool enable = Fgl::stringToKey(action2->acceleratorName2()) == Fgl::stringToKey(s1)){
                      action2->setAccName2Enabled(!enable);
                   }

                   if(bool enable = Fgl::stringToKey(action2->acceleratorName3()) == Fgl::stringToKey(s1)){
                      action2->setAccName3Enabled(!enable);
                   }

                   if(bool enable = Fgl::stringToKey(action2->acceleratorName4()) == Fgl::stringToKey(s1)){
                      action2->setAccName4Enabled(!enable);
                   }
                }
             }
          }

          if(!s2.isEmpty()){
             for(int j=0; j<actions.count(); j++){
                if(Action *action2 = qobject_cast<Action *> (actions.at(j))){
                   if(action == action2 || !action2->isEnabled())
                      continue;
   
                   if(bool enable = Fgl::stringToKey(action2->acceleratorName2()) == Fgl::stringToKey(s1)){
                      action2->setAccName2Enabled(!enable);
                   }

                   if(bool enable = Fgl::stringToKey(action2->acceleratorName3()) == Fgl::stringToKey(s1)){
                      action2->setAccName3Enabled(!enable);
                   }

                   if(bool enable = Fgl::stringToKey(action2->acceleratorName4()) == Fgl::stringToKey(s1)){
                      action2->setAccName4Enabled(!enable);
                   }
                }
             }
          }

          if(!s3.isEmpty()){
             for(int j=0; j<actions.count(); j++){
                if(Action *action2 = qobject_cast<Action *> (actions.at(j))){
                   if(action == action2 || !action2->isEnabled())
                      continue;
   
                   if(bool enable = Fgl::stringToKey(action2->acceleratorName3()) == Fgl::stringToKey(s1)){
                      action2->setAccName3Enabled(!enable);
                   }

                   if(bool enable = Fgl::stringToKey(action2->acceleratorName4()) == Fgl::stringToKey(s1)){
                      action2->setAccName4Enabled(!enable);
                   }
                }
             }
          }

          if(!s3.isEmpty()){
             for(int j=0; j<actions.count(); j++){
                if(Action *action2 = qobject_cast<Action *> (actions.at(j))){
                   if(action == action2 || !action2->isEnabled())
                      continue;
   
                   if(bool enable = Fgl::stringToKey(action2->acceleratorName4()) == Fgl::stringToKey(s1)){
                      action2->setAccName4Enabled(!enable);
                   }
                }
             }
          }
       }
    }
}

bool FglForm::focusNextPrevChild(bool next)
{
MainFrame::vdcdebug("FglForm","focusNextPrevChild", "bool next");
   return false;
   QWidget *nextWidget = NULL;

   switch(state()){
      case Fgl::MENU:
         if(menu() != NULL){
            if(next){
               QList<QPushButton*> ql_buttons = menu()->buttons();
               QWidget *current = menu()->focusWidget();
               for(int i=0; i<ql_buttons.count(); i++){
                  bool found = false;
                  if(current == ql_buttons.at(i)){
                     for(int j=i+1; j<ql_buttons.count()-1; j++){
                        if(ql_buttons.at(j)->isEnabled() &&
                           ql_buttons.at(j)->isVisible()){
                           nextWidget = ql_buttons.at(j);
                           found = true;
                           break;
                        }
                     }
                     if(found){
                        break;
                     }
                  }
               }

               if(nextWidget == NULL){
                  for(int i=0; i<ql_buttons.count(); i++){
                     if(ql_buttons.at(i)->isEnabled() &&
                        ql_buttons.at(i)->isVisible()){
                        nextWidget = ql_buttons.at(i);
                        break;
                     }
                  }
               }

               nextWidget->setFocus();
            }
            else{
               QList<QPushButton*> ql_buttons = menu()->buttons();
               QWidget *current = menu()->focusWidget();
               for(int i=ql_buttons.count()-1; i>=0; i--){
                  bool found = false;
                  if(current == ql_buttons.at(i)){
                     for(int j=i-1; j>=0; j--){
                        if(ql_buttons.at(j)->isEnabled() &&
                           ql_buttons.at(j)->isVisible()){
                           nextWidget = ql_buttons.at(j);
                           found = true;
                           break;
                        }
                     }
                     if(found){
                        break;
                     }
                  }
               }

               if(nextWidget == NULL){
                  nextWidget = ql_buttons.last();
                  for(int i=ql_buttons.count()-1; i>=0; i--){
                     if(ql_buttons.at(i)->isEnabled() &&
                        ql_buttons.at(i)->isVisible()){
                        nextWidget = ql_buttons.at(i);
                        break;
                     }
                  }
               }

               if(nextWidget != NULL){
                  nextWidget->setFocus();
               }
            }
         }
         break;
      case Fgl::INPUT:
      case Fgl::CONSTRUCT:
         break;

      case Fgl::DISPLAYARRAY:
         break;
      case Fgl::INPUTARRAY:
         break;
      default:
          return false;
   }
   return true;
}

void FglForm::setLastCursor(int i_old, int i_new)
{
MainFrame::vdcdebug("FglForm","setLastCursor", "int i_old, int i_new");
   Q_UNUSED(i_old);
   this->i_lastCursor = i_new+1;
}

void FglForm::setLastCursor()
{
MainFrame::vdcdebug("FglForm","setLastCursor", "");
    QObject *obj = QObject::sender();

    if(TextEdit *textedit = qobject_cast<TextEdit *> (obj)){
       QTextCursor cursor = textedit->textCursor();
       this->i_lastCursor = cursor.position()+1;
    }
}

void FglForm::checkField()
{
MainFrame::vdcdebug("FglForm","checkField", "");

   QObject *obj = QObject::sender();
   if(LineEdit *widget = qobject_cast<LineEdit *> (obj)){
      if(state() != Fgl::IDLE &&
         state() != Fgl::CONSTRUCT){
         //widget->check();
         QString text = widget->text();

         //Set textformat if format given
         if(Fgl::isValidForType(widget->dataType(), text, widget->format())){
            text = Fgl::usingFunc(widget->format(), text, widget->dataType());
            widget->setText(text);
         }
         else{
            emit error("ERROR in Character conversion");
            widget->setText("");
         }
      }
   }
}
