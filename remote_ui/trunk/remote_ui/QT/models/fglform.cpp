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

   context = 0;

   if(!windowName.isEmpty()){
      this->windowName = windowName;
   }


   QSplitter *formSplitter = new QSplitter;
   formSplitter->setChildrenCollapsible(false);
   setCentralWidget(formSplitter);

   setState(Fgl::IDLE);


   b_getch_swin = false;
   p_actionMenu = NULL;
   p_dialog = NULL;
   p_toolBar = NULL;
   b_denyFocus = false;
   b_allowClose = false;

   b_menu = false;
   b_input = false;
   b_screenRecord = false;
   p_toolBar = NULL;
   p_actionMenu = NULL;
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
   writeSettingsLocal();
}

//------------------------------------------------------------------------------
// Method       : createStatusBar()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::createStatusBar()
{
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
}

//------------------------------------------------------------------------------
// Method       : addToQueue()
// Filename     : fglform.cpp
// Description  : receives the Triggered id and execs the processResponse slot
//------------------------------------------------------------------------------
void FglForm::addToQueue(QString id)
{
      for(int i=0; i<ql_formEvents.count(); i++){
         Fgl::Event event = ql_formEvents.at(i);
         if(event.type == Fgl::ONACTION_EVENT && event.attribute == id.toLower()){
            id = QString::number(event.id);
            break;
         }
      }
      ql_responseQueue << id;
      processResponse();
}

//------------------------------------------------------------------------------
// Method       : initActions()
// Filename     : fglform.cpp
// Description  : init the standard actions (ESC = INTERRUPT, F12 = ACCEPT, etc)
//                and adds them to the Form
//------------------------------------------------------------------------------
void FglForm::setActions(QDomDocument xmlFile)
{
   for(int i=0; i<defActions().size(); i++){
      removeAction(defActions().at(i));
   }

   Actions *actions = new Actions(this);
   actions->parseFile(xmlFile);


   ql_formActions = actions->actions();
   QStringList names = actions->names();
   for(int i=0; i<ql_formActions.size(); i++){
      QAction *action = ql_formActions.at(i);
      QString name = action->objectName();

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
   QAction *interruptAction = new QAction(tr("INTERRUPT"), this);
   interruptAction->setShortcut(Qt::Key_Escape);
   interruptAction->setVisible(true);
   interruptAction->setEnabled(true);
   connect(interruptAction, SIGNAL(triggered()), this, SLOT(cancelTriggered()));
   ql_defaultActions << interruptAction;

   QAction *acceptAction = new QAction(tr("ACCEPT"), this);
   acceptAction->setVisible(true);
   acceptAction->setEnabled(true);
   acceptAction->setShortcut(Qt::Key_F12);
   connect(acceptAction, SIGNAL(triggered()), this, SLOT(acceptTriggered()));
   ql_defaultActions << acceptAction;

   QAction *enterAction = new QAction(tr("Next Field"), this);
   enterAction->setVisible(true);
   enterAction->setEnabled(true);

   QList<QKeySequence> enterShortcuts;
   enterShortcuts << Qt::Key_Tab;
   enterShortcuts << Qt::Key_Return;
   enterShortcuts << Qt::Key_Enter;
   enterShortcuts << Qt::Key_Down;
   enterAction->setShortcuts(enterShortcuts);

   connect(enterAction, SIGNAL(triggered()), this, SLOT(nextfield()));
   ql_defaultActions << enterAction;

   QAction *stabAction = new QAction(tr("Previous Field"), this);
   stabAction->setVisible(true);
   stabAction->setEnabled(true);

   QList<QKeySequence> stabShortcuts;
   stabShortcuts << Qt::Key_Up;
   stabShortcuts << (Qt::SHIFT|Qt::Key_Tab);
   stabAction->setShortcuts(stabShortcuts);

   connect(stabAction, SIGNAL(triggered()), this, SLOT(prevfield()));
   ql_defaultActions << stabAction;

   this->addActions(ql_defaultActions);

}

//------------------------------------------------------------------------------
// Method       : setMenu()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::setMenu(RingMenu* p_menu)
{

   if(p_menu == NULL)
      return;

   if(menu() != NULL && menu() != p_menu){
      menu()->setParent(NULL);
      disconnect(menu(), SIGNAL(menuButtonPressed(QString)),
                 this, SLOT(buttonClicked(QString)));
   }

   ql_menus << p_menu;

   if(QSplitter *formSplitter = qobject_cast<QSplitter *> (this->centralWidget())){
      formSplitter->addWidget(p_menu);
      setRingMenuPosition(getRingMenuPosition());

      connect(p_menu, SIGNAL(menuButtonPressed(QString)),
              this, SLOT(buttonClicked(QString)));
   }
}

//------------------------------------------------------------------------------
// Method       : removeMenu()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::removeMenu()
{

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

   b_menu = enable;
}

//------------------------------------------------------------------------------
// Method       : setActionMenu()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::setActionMenu(ActionMenu* menu)
{

   if(menu == NULL || p_actionMenu == menu)
      return;

   if(p_actionMenu != NULL){
      p_actionMenu->deleteLater();
   }

   p_actionMenu = menu;

   QSplitter *formSplitter = (QSplitter*) this->centralWidget();
   formSplitter->addWidget(menu);

   connect(menu, SIGNAL(menuButtonPressed(QString)),
           this, SLOT(buttonClicked(QString)));

   setActionMenuEnabled(!b_menu);
}

//------------------------------------------------------------------------------
// Method       : setActionMenuEnabled()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::setActionMenuEnabled(bool enable)
{


   if(p_actionMenu == NULL)
      return;

   p_actionMenu->setVisible(enable);
   p_actionMenu->setEnabled(enable);


   if(!enable){
      p_actionMenu->removeButtons();
   }
}

//------------------------------------------------------------------------------
// Method       : actionTriggered()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::actionTriggered()
{
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

//------------------------------------------------------------------------------
// Method       : toolBarActionTriggered()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::toolBarActionTriggered()
{
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

   p_dialog = dialog;

   if(dialog != NULL){
      connect(dialog, SIGNAL(dialogButtonPressed(QString)),
              this, SLOT(buttonClicked(QString)));
   }

}

//------------------------------------------------------------------------------
// Method       : setToolBar()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::setToolBar(ToolBar *toolBar)
{

   this->p_toolBar = toolBar;

   if(toolBarPosition() != Qt::NoToolBarArea){
      if(this->p_toolBar != this->toolBar()){
         QList<QAction*> ql_actions = this->p_toolBar->actions();
         for(int i=0; i<ql_actions.size(); i++){
            connect(ql_actions.at(i), SIGNAL(triggered()), this, SLOT(toolBarActionTriggered()));
         }
      }
      this->addToolBar(toolBarPosition(), this->p_toolBar);
   }
   else{
      p_toolBar->setVisible(false);
      QList<QAction*> ql_actions = this->p_toolBar->actions();
      for(int i=0; i<ql_actions.size(); i++){
         connect(ql_actions.at(i), SIGNAL(triggered()), this, SLOT(toolBarActionTriggered()));
      }
   }
   checkToolBar();
}

//------------------------------------------------------------------------------
// Method       : setToolBar()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::setToolBar(QDomDocument xmlFile)
{
   QSize currSize = this->sizeHint();

   this->p_toolBar = new ToolBar;
   this->p_toolBar->parseFile(xmlFile);

   if(toolBarPosition() != Qt::NoToolBarArea){
         QList<QAction*> ql_actions = this->p_toolBar->actions();
         for(int i=0; i<ql_actions.size(); i++){
            connect(ql_actions.at(i), SIGNAL(triggered()), this, SLOT(toolBarActionTriggered()));
         }
      this->addToolBar(toolBarPosition(), this->p_toolBar);
   }
   else{
      p_toolBar->setVisible(false);
      QList<QAction*> ql_actions = this->p_toolBar->actions();
      for(int i=0; i<ql_actions.size(); i++){
         connect(ql_actions.at(i), SIGNAL(triggered()), this, SLOT(toolBarActionTriggered()));
      }
   }
   checkToolBar();

}

//------------------------------------------------------------------------------
// Method       : eventFilter()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
bool FglForm::eventFilter(QObject *obj, QEvent *event)
{

   if(event->type() == QEvent::ShortcutOverride){
      event->ignore();
      return true;
   }

   processResponse();

   if(event->type() == QEvent::FocusIn){
      if(WidgetHelper::isFieldWidget(obj)){
         if(QWidget *widget = qobject_cast<QWidget *> (obj)){
            QFocusEvent *fe = (QFocusEvent*) event;
               if(this->focusWidget() != currentWidget){
                  currentWidget = widget;
                  Fgl::Event fgl_event;
                  fgl_event.type = Fgl::BEFORE_FIELD_EVENT;
                  fgl_event.attribute = widget->objectName();
                  fieldEvent(fgl_event);
               }
         }
      }
   }

   if(event->type() == QEvent::FocusOut){
      if(WidgetHelper::isFieldWidget(obj)){
         if(QWidget *widget = qobject_cast<QWidget *> (obj)){
            QFocusEvent *fe = (QFocusEvent*) event;
            if(fe->reason() != Qt::ActiveWindowFocusReason &&
               fe->reason() != Qt::PopupFocusReason){
               Fgl::Event event;
               event.type = Fgl::AFTER_FIELD_EVENT;
               fieldEvent(event, widget);
            }
         }
      }
   }

   if(event->type() == QEvent::KeyPress){
      QKeyEvent *keyEvent = (QKeyEvent*) event;

      if(keyEvent->key() == Qt::Key_Insert){
         StatusBar *status = (StatusBar*) statusBar();
         status->toggleOverwriteMode();
         return true;
      }

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
   switch(type.type)
   {
      case Fgl::BEFORE_FIELD_EVENT:
      case Fgl::AFTER_FIELD_EVENT:

           for(int i=0; i<ql_formEvents.size(); i++){
              Fgl::Event event = ql_formEvents.at(i);
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

      case Fgl::BEFORE_INPUT_EVENT:
      case Fgl::AFTER_INPUT_EVENT:
      case Fgl::BEFORE_CONSTRUCT_EVENT:
      case Fgl::AFTER_CONSTRUCT_EVENT:
      case Fgl::BEFORE_DISPLAY_EVENT:
      case Fgl::AFTER_DISPLAY_EVENT:
      case Fgl::BEFORE_ROW_EVENT:
      case Fgl::AFTER_ROW_EVENT:
           for(int i=0; i<ql_formEvents.size(); i++){
              Fgl::Event event = ql_formEvents.at(i);
              if(event.type == type.type){
                 addToQueue(QString::number(event.id));
                 return;
              }
           }
           break;

      case Fgl::ONKEY_EVENT:
      case Fgl::ONACTION_EVENT:
           for(int i=0; i<ql_formEvents.size(); i++){
              Fgl::Event event = ql_formEvents.at(i);
              if(event.type == type.type && 
                 event.attribute.toLower() == type.attribute.toLower()){
                 addToQueue(QString::number(event.id));
                 return;
              }
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

   QString trigger = "<TRIGGERED ID=\"EXEC\" PROGRAMNAME=\"";
   trigger.append(cmd);
   trigger.append("&amp;");
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
   Parser *formParser = new Parser(this);
   formParser->parseForm(docLayout);
   formWidget = formParser->getFormWidget();
   //formWidget->setEnabled(false);

   QSplitter *formSplitter = (QSplitter*) this->centralWidget();
   formSplitter->addWidget(formWidget);
   //formParser->getFormWidget()->show();

   this->ql_formFields << formParser->getFieldList();

   for(int i=0; i<formElements().size(); i++){
      if(LineEdit *lineEdit = qobject_cast<LineEdit *> (formElements().at(i))){
         connect(lineEdit, SIGNAL(fieldEvent(Fgl::Event)), this, SLOT(fieldEvent(Fgl::Event)));
         connect(lineEdit, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(createContextMenu(const QPoint&)));
         lineEdit->installEventFilter(this);
      }

      if(Button *button = qobject_cast<Button *> (formElements().at(i))){
         connect(button, SIGNAL(fieldEvent(Fgl::Event)), this, SLOT(fieldEvent(Fgl::Event)));
         button->installEventFilter(this);
      }

      if(TextEdit *textEdit = qobject_cast<TextEdit *> (formElements().at(i))){
         connect(textEdit, SIGNAL(returnPressed()), this, SLOT(nextfield()));
         textEdit->installEventFilter(this);
      }

      if(TableView *tableView = qobject_cast<TableView *> (formElements().at(i))){
         connect(tableView, SIGNAL(fieldEvent(Fgl::Event)), this, SLOT(fieldEvent(Fgl::Event)));
         connect(tableView, SIGNAL(setArrLine(int)), this, SLOT(setScreenRecordArrLine(int)));
         connect(tableView, SIGNAL(accepted()), this, SLOT(acceptTriggered()));
      }

      if(LineEditDelegate *delegate = qobject_cast<LineEditDelegate *> (formElements().at(i))){
         delegate->setForm(this);
      }
   }
}

QList<QWidget*> FglForm::formElements()
{
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
}

//------------------------------------------------------------------------------
// Method       : setStartMenu()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::setStartMenu(const QDomDocument &doc)
{
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

   m_toolBarPosition = sm;

   if(toolBar() != NULL){
      setToolBar(this->p_toolBar);
   }

}

Qt::ToolBarArea FglForm::toolBarPosition()
{
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
}

//------------------------------------------------------------------------------
// Method       : setStartMenu()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::setSizable(const QString &sm)
{
}

//------------------------------------------------------------------------------
// Method       : setStartMenu()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::setDefaultStatusBar(const bool &sm)
{
}

//------------------------------------------------------------------------------
// Method       : setStartMenu()
// Filename     : fglform.cpp
// Description  : 
//               
//------------------------------------------------------------------------------
void FglForm::setWindowType(const QString &sm)
{

   if(sm == "modal"){
      setWindowModality(Qt::WindowModal);
   }

   if(sm == "normal"){
      setWindowModality(Qt::NonModal);
   }

}

//------------------------------------------------------------------------------
// Method       : editcopy()
// Filename     : fglform.cpp
// Description  : ActionDefaults
//------------------------------------------------------------------------------
void FglForm::editcopy()
{

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
}

//------------------------------------------------------------------------------
// Method       : editpaste()
// Filename     : fglform.cpp
// Description  : ActionDefaults
//------------------------------------------------------------------------------
void FglForm::editpaste()
{
}
//------------------------------------------------------------------------------
// Method       : nextfield()
// Filename     : fglform.cpp
// Description  : ActionDefaults
//------------------------------------------------------------------------------

void FglForm::nextfield()
{
   if(!screenRecord()){
      //  If context option says not to wrap
      //  and input field is the last field in the list
      //  then trigger after "INPUT" event
      if(!this->context->options["WRAP"]){
         if(context->fieldList.count() > 0){
            QString lastField = context->fieldList.last();
            if(lastField == currentWidget->accessibleName() ||
               lastField == currentWidget->objectName()){
               Fgl::Event event;
               switch(state()){
                  case Fgl::INPUT:
                  case Fgl::INPUTARRAY:
                     acceptTriggered();
                     break;
                  case Fgl::CONSTRUCT:
                     acceptTriggered();
                     break;
                  case Fgl::MENU:
                  case Fgl::IDLE:
                  case Fgl::DISPLAYARRAY:
                     break;
               }

               fieldEvent(event);
            }
            else{
               focusNextChild();
            }
         }
      }
      else{
         focusNextChild();
      }
   }
   else{
      //find active screenRecord
      for(int i=0; i<formElements().size(); i++){
         if(formElements().at(i)->inherits("TableView")){
            TableView *view = (TableView*) formElements().at(i);
            if(view->isEnabled()){
               view->nextfield();
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
   if(!screenRecord()){
      focusPreviousChild();
   }
   else{
      //find active screenRecord
      for(int i=0; i<formElements().size(); i++){
         if(formElements().at(i)->inherits("TableView")){
            TableView *view = (TableView*) formElements().at(i);
            if(view->isEnabled()){
               view->prevfield();
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
   //find active screenRecord
   for(int i=0; i<formElements().size(); i++){
      if(formElements().at(i)->inherits("TableView")){
         TableView *view = (TableView*) formElements().at(i);
         if(view->isEnabled()){
            QModelIndex currentIndex = view->currentIndex();
            int currentRow = currentIndex.row();
            if(currentRow <= view->model()->rowCount()){
               view->selectRow(currentRow+1);
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
   for(int i=0; i<formElements().size(); i++){
      if(formElements().at(i)->inherits("TableView")){
         TableView *view = (TableView*) formElements().at(i);
         if(view->isEnabled()){
            QModelIndex currentIndex = view->currentIndex();
            int currentRow = currentIndex.row();
            if(currentRow <= view->model()->rowCount()){
               view->selectRow(currentRow-1);
            }
         }
      }
   }
};
void FglForm::firstrow()
{
   for(int i=0; i<formElements().size(); i++){
      if(formElements().at(i)->inherits("TableView")){
         TableView *view = (TableView*) formElements().at(i);
         if(view->isEnabled()){
            view->selectRow(0);
         }
      }
   }
};
void FglForm::lastrow()
{
   for(int i=0; i<formElements().size(); i++){
      if(formElements().at(i)->inherits("TableView")){
         TableView *view = (TableView*) formElements().at(i);
         if(view->isEnabled()){
            view->selectRow(view->model()->rowCount()-1);
         }
      }
   }
};
void FglForm::nextpage(){};
void FglForm::prevpage(){};
void FglForm::nexttab()
{
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
// Method       : enableActions()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::enableActions(bool enable)
{
   for(int i=0; i<actions().size(); i++){
      actions().at(i)->setEnabled(false);
   }

   QList<QString> menuActions;
   if(RingMenu *p_menu = qobject_cast<RingMenu *> (menu())){
      QList<QPushButton*> buttons = p_menu->buttons();
      for(int j=0; j<buttons.size(); j++){
         if(buttons.at(j)->isEnabled()){
            QString action = buttons.at(j)->text();
            action.remove(0,1);
            menuActions << action;
         }
      }
   }


   for(int i=0; i<this->actions().size(); i++){

      QAction *action = this->actions().at(i);
      QString name = action->objectName();
      
      if(input() || construct() || screenRecord()){
         if(name == "accept"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "cancel"){
            action->setEnabled(enable);
            continue;
         }
      }

      if(inputArray()){
         if(name == "insert"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "append"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "delete"){
            action->setEnabled(enable);
            continue;
         }
      }

      if(input() || construct() || screenRecord() || dialog()){
         if(name == "editcopy"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "editcut"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "editpaste"){
            action->setEnabled(enable);
            continue;
         }
      }

      if(input() || construct() || (inputArray())){
         if(name == "nextfield"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "prevfield"){
            action->setEnabled(enable);
            continue;
         }
      }

      if(screenRecord()){
 
         if(name == "nextrow"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "prevrow"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "firstrow"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "lastrow"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "nextpage"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "prevpage"){
            action->setEnabled(enable);
            continue;
         }
      }
         

      if(name == "nexttab"){
         action->setEnabled(enable);
            continue;
      }

      if(name == "prevtab"){
         action->setEnabled(enable);
            continue;
      }


      for(int k=0; k<menuActions.size(); k++){
         if(name == menuActions.at(k)){
            action->setEnabled(true);
            break;
         }
      }

   }

   checkToolBar();
}

//------------------------------------------------------------------------------
// Method       : validateFields()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::validateFields()
{
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
void FglForm::checkToolBar()
{
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

      QList<QString> formActions;
      for(int i=0; i<actions().size(); i++){
         if(actions().at(i)->isEnabled()){
            QString action = actions().at(i)->objectName();
            formActions << action;
         }
      }

      for(int i=0; i<formActions.size(); i++){
         QString formAction = formActions.at(i);
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

//------------------------------------------------------------------------------
// Method       : revertState()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::revertState(Fgl::State state){

   for(int i=ql_states.count()-1; i>=0; i--){
      if(state == ql_states.at(i)){
         ql_states.takeAt(i);
         break;
      }
   }
}


//------------------------------------------------------------------------------
// Method       : checkState()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::checkState()
{
   if(p_dialog != NULL)
      return;

   Fgl::State state = ql_states.last();

   if(state == Fgl::MENU){
      setActionMenuEnabled(false);
      setMenuEnabled(true);
   }

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

   if(state != Fgl::IDLE){
     bool en = (state == Fgl::INPUT || state == Fgl::CONSTRUCT || state == Fgl::DISPLAYARRAY || state == Fgl::INPUTARRAY);
     checkToolBar();
   }

   checkActions();
   checkMenu();
}

//------------------------------------------------------------------------------
// Method       : checkMenu()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::checkMenu()
{

   if(RingMenu *p_menu = qobject_cast<RingMenu *> (menu())){
      if(!p_menu->isVisible())
         return;
      QList<QPushButton*> buttons = p_menu->buttons();
      if(ToolBar *p_toolBar = qobject_cast<ToolBar *> (toolBar())){
         QList<QAction*> actions = p_toolBar->actions();
         for(int i=0; i<buttons.size(); i++){
            QPushButton *button = buttons.at(i);
            QString buttonText = button->text().remove(0,1);
            for(int j=0; j<actions.size(); j++){
               QAction *action = actions.at(j);
               QString actionText = action->text();
               if((buttonText == actionText)){
                     button->setIcon(action->icon());
                  break;
               }
            }
         }
      }
   }

}

//------------------------------------------------------------------------------
// Method       : checkActions()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::checkActions()
{
   for(int i=0; i<actions().size(); i++){
      actions().at(i)->setEnabled(false);
   }

   QList<QString> menuActions;
   if(RingMenu *p_menu = qobject_cast<RingMenu *> (menu())){
      QList<QPushButton*> buttons = p_menu->buttons();
      for(int j=0; j<buttons.size(); j++){
         if(buttons.at(j)->isEnabled()){
            QString action = buttons.at(j)->text();
            if(action.mid(0,1) == "&"){
               action.remove(0,1);
            }
            menuActions << action;
         }
      }
   }


   for(int i=0; i<this->actions().size(); i++){

      QAction *action = this->actions().at(i);
      QString name = action->objectName();
      
      if(bool enable = (input() || construct() || screenRecord())){
         if(name == "accept"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "cancel"){
            action->setEnabled(enable);
            continue;
         }
      }

      if(bool enable = inputArray()){
         if(name == "insert"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "append"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "delete"){
            action->setEnabled(enable);
            continue;
         }
      }

      if(bool enable = (input() || construct() || screenRecord() || dialog())){
         if(name == "editcopy"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "editcut"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "editpaste"){
            action->setEnabled(enable);
            continue;
         }
      }

      if(bool enable = (input() || construct() || (inputArray()))){
         if(name == "nextfield"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "prevfield"){
            action->setEnabled(enable);
            continue;
         }
      }

      if(bool enable = screenRecord()){
 
         if(name == "nextrow"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "prevrow"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "firstrow"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "lastrow"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "nextpage"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "prevpage"){
            action->setEnabled(enable);
            continue;
         }
      }
         

      if(bool enable = (state() != Fgl::IDLE)){
         if(name == "nexttab"){
            action->setEnabled(enable);
            continue;
         }

         if(name == "prevtab"){
            action->setEnabled(enable);
            continue;
         }
      }

      for(int k=0; k<menuActions.size(); k++){
         if(name == menuActions.at(k)){
            action->setEnabled(true);
            break;
         }
      }

   }

   checkToolBar();
}


//------------------------------------------------------------------------------
// Method       : writeSettingsLocal()
// Filename     : fglform.cpp
// Description  : 
//------------------------------------------------------------------------------
void FglForm::writeSettingsLocal()
{
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
   createContextMenu(ev->globalPos());
   
}
void FglForm::createContextMenu(const QPoint &pos)
{
   QMenu* contextMenu = new QMenu(this);
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
                  if(formAction->isEnabled()){
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
            if(formAction->isEnabled()){
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
}

QList<QWidget*> FglForm::findFieldsByName(QString fieldName)
{

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

   setArrLine(line);

}
