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

#include "screenhandler.h"
#include "models/response.h"
#include "models/statusbar.h"
#include "models/table.h"
#include "models/matrix.h"
#include "xmlparsers/xml2menu.h"

//------------------------------------------------------------------------------
// Method       : ScreenHandler()
// Filename     : screenhandler.cpp
// Description  : constructor for the instances
//------------------------------------------------------------------------------
ScreenHandler::ScreenHandler(QObject *parent) : QObject(parent)
{

   cnt_form = 0;
   b_menuEnabled = false;
   p_screenRecord = NULL;
   p_fglform = NULL;
   cursorPos = false;
   p_prompt = NULL;
   QApplication::processEvents();

}

//------------------------------------------------------------------------------
// Method       : ~ScreenHandler()
// Filename     : screenhandler.cpp
// Description  : destructor for the instances
//------------------------------------------------------------------------------
ScreenHandler::~ScreenHandler()
{
    QApplication::processEvents();
}

//------------------------------------------------------------------------------
// Method       : ~ScreenHandler()
// Filename     : screenhandler.cpp
// Description  : initializes some values
//------------------------------------------------------------------------------
void ScreenHandler::initForm(int i_Frm)
{
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
   return cnt_form-1;
}

int ScreenHandler::getCurrWindow()
{
   return cnt_form-1;
}

//------------------------------------------------------------------------------
// Method       : createWindow()
// Filename     : screenhandler.cpp
// Description  : creates the Form. prepares for displaying it
//------------------------------------------------------------------------------
void ScreenHandler::createWindow(QString windowTitle,QString style, int x, int y, int h, int w, QString id)
{
   Q_UNUSED(x);
   Q_UNUSED(y);
   Q_UNUSED(h);
   Q_UNUSED(w);

   cnt_form++;
   if(p_fglform != NULL)
   {
      if(p_fglform->menu() != NULL)
         p_fglform->menu()->setEnabled(false);
   }
   //p_fglform = new FglForm(windowTitle, parentWidget);
   //p_fglform = new FglForm(windowTitle, p_fglform);
   p_fglform = new FglForm(windowTitle);
   p_fglform->installEventFilter(this);

   p_fglform->setId(id);
   connect(p_fglform, SIGNAL(processResponse()), this, SLOT(processResponse()));
   connect(p_fglform, SIGNAL(sendDirect(QString)), this, SLOT(sendDirect(QString)));
   connect(p_fglform, SIGNAL(setClearEvents()), this, SLOT(setClearEvents()));
   connect(p_fglform, SIGNAL(setArrLine(int)), this, SLOT(setArrLine(int)));

   if(!qs_interfaceTitle.isNull())
      p_fglform->setWindowTitle(qs_interfaceTitle);
   else{
      p_fglform->setWindowTitle(windowTitle);
   }

   p_fglform->windowName = windowTitle;

   p_fglform->setStartMenu(startMenu);
   startMenu.clear();

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
   if(formsActions.hasChildNodes()){
      p_fglform->setActions(formsActions);
   }

   b_newForm = true;

}

FglForm* ScreenHandler::currForm()
{
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

   qh_formFiles[formName] = xmlFormString;

   if(openWindow){
      QDomDocument xmlForm;
      xmlForm.setContent(xmlFormString);

      p_fglform->setFormLayout(xmlForm);
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
   QString xmlFormString = qh_formFiles[formName];

   if(!xmlFormString.isEmpty()){

      QDomDocument xmlForm;
      xmlForm.setContent(xmlFormString);

      p_fglform->setFormLayout(xmlForm);
   }
   else{
      qFatal("No such form %s", qPrintable(formName));
   }

   p_fglform->show();
}

//------------------------------------------------------------------------------
// Method       : handleXMLToolBar(QString xmlFile)
// Filename     : screenhandler.cpp
// Description  : creates the ToolBar (4tb file)
//------------------------------------------------------------------------------
void ScreenHandler::handleXMLToolBar(QString xmlFileString)
{

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

   QDomDocument xmlFile;
   if(!xmlFile.setContent(xmlFileString)){
   }

   if(getCurrForm() == -1){
      startMenu = xmlFile;
   }
   else{
      if(p_fglform != NULL)
         p_fglform->setStartMenu(xmlFile);
   }
}

//------------------------------------------------------------------------------
// Method       : handleXMLActions(QString xmlFile)
// Filename     : screenhandler.cpp
// Description  : action defaults like "Find" etc. 4ad file
//------------------------------------------------------------------------------
void ScreenHandler::handleXMLActions(QString xmlFileString)
{

   QDomDocument xmlFile;
   QString errorMsg;
   int errorLine, errorCol;
   if (!xmlFile.setContent(xmlFileString, &errorMsg, &errorLine, &errorCol)){
      QString str = errorMsg + "\n" +
                    "Line:" + QString::number(errorLine) + "\n" +
                    "Column" + QString::number(errorCol);
      MsgBox("Protocol Error",str,"Warning","Ok","Ok",0);
   }


   formsActions = xmlFile;
}

//------------------------------------------------------------------------------
// Method       : handleXMLStyles(QString xmlFile)
// Filename     : screenhandler.cpp
// Description  : stylesheets 4st file
//------------------------------------------------------------------------------
void ScreenHandler::handleXMLStyles(QString xmlFileString)
{

   QDomDocument xmlFile;
   xmlFile.setContent(xmlFileString);

   formsStyles = xmlFile;
}

//------------------------------------------------------------------------------
// Method       : createMenu(QString title, QString FieldValue)
// Filename     : screenhandler.cpp
// Description  : creates the ring menu element (ButtonGroup)
//------------------------------------------------------------------------------
void ScreenHandler::createMenu(QString title, QString comment, QString style, QString image)
{
   int i_Frm = getCurrForm();

   if(i_Frm < 0)
      return;

   // If menustyle is dialog
   if(style == "dialog"){
      createDialog(title, comment, style, image);
      return;
   }


   RingMenu *ringMenu = new RingMenu(title, style);

   p_fglform->setMenu(ringMenu);
}

//------------------------------------------------------------------------------
// Method       : createMenuButton(int buttonId, QString text, QString desc)
// Filename     : screenhandler.cpp
// Description  : creates the menubutton and adds it to the buttongroup
//------------------------------------------------------------------------------
void ScreenHandler::createMenuButton(int buttonId, QString text, QString desc, QStringList keys)
{

  Q_UNUSED(keys);

  int i_Frm = getCurrForm();

   if(i_Frm < 0)
      return;

   if(p_fglform == NULL)
      return;

   if(p_fglform->dialog() != NULL){
      createDialogButton(buttonId, text, desc);
      return;
   }

   if(p_fglform->menu() == NULL)
      return;

   RingMenu *ringMenu = p_fglform->menu();

   ringMenu->createButton(buttonId, text, desc);
   QAction *action = ringMenu->getAction(text.toLower());
   connect(action, SIGNAL(triggered()), p_fglform, SLOT(actionTriggered()));

   Fgl::Event event;
   event.type = Fgl::MENUACTION_EVENT;
   event.id = buttonId;
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

  int i_Frm = getCurrForm();

   if(i_Frm < 0)
      return;

   if(p_fglform == NULL)
      return;

   if(p_fglform->dialog() != NULL){
      createDialogAction(buttonId, text);
      return;
   }

   if(p_fglform->menu() == NULL)
      return;

   RingMenu *ringMenu = p_fglform->menu();

   ringMenu->createAction(buttonId, text);
   QAction *action = ringMenu->getAction(text.toLower());
   connect(action, SIGNAL(triggered()), p_fglform, SLOT(actionTriggered()));

   Fgl::Event event;
   event.type = Fgl::MENUACTION_EVENT;
   event.id = buttonId;
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
// Description  : hide menu commands
//------------------------------------------------------------------------------
void ScreenHandler::hideOption(QString name)
{
   if(p_fglform == NULL)
      return;

   if(p_fglform->dialog() != NULL){
      p_fglform->dialog()->hideButton(name);
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
   if(p_fglform == NULL)
      return;

   if(p_fglform->dialog() != NULL){
      p_fglform->dialog()->showButton(name);
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
void ScreenHandler::nextOption(QString name)
{
   if(p_fglform == NULL)
      return;

   if(p_fglform->dialog() != NULL){
      return;
   }

   if(p_fglform->menu() != NULL){
      p_fglform->menu()->selectButton(name);
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
   if(p_fglform == NULL)
      return;

   //Dialog *p_dialog = new Dialog(title, comment, style, image, p_fglform);
   Dialog *p_dialog = new Dialog(title, comment, style, image, p_fglform);
   p_fglform->setDialog(p_dialog);
   clearEvents();

}

//------------------------------------------------------------------------------
// Method       : createDialogButton(int buttonId, QString text, QString desc)
// Filename     : screenhandler.cpp
// Description  : creates the menubutton and adds it to the buttongroup
//------------------------------------------------------------------------------
void ScreenHandler::createDialogButton(int buttonId, QString text, QString desc)
{

  int i_Frm = getCurrForm();

   Dialog* p_dialog = p_fglform->dialog();
   if(i_Frm < 0 || p_fglform == NULL)
      return;

   if(p_dialog == NULL)
      return;

   p_dialog->createButton(buttonId, text, desc);
   QAction *action = p_dialog->getAction(text.toLower());
   connect(action, SIGNAL(triggered()), p_fglform, SLOT(actionTriggered()));

   Fgl::Event event;
   event.type = Fgl::MENUACTION_EVENT;
   event.id = buttonId;
   event.attribute = text.toLower(); //Fgl::stringToKey(attribute);
   p_fglform->ql_dialogEvents << event;
   p_fglform->addFormEvent(event);
}

//------------------------------------------------------------------------------
// Method       : createDialogButton(int buttonId, QString text, QString desc)
// Filename     : screenhandler.cpp
// Description  : creates the menubutton and adds it to the buttongroup
//------------------------------------------------------------------------------
void ScreenHandler::createDialogAction(int buttonId, QString text)
{

  int i_Frm = getCurrForm();

   Dialog* p_dialog = p_fglform->dialog();
   if(i_Frm < 0 || p_fglform == NULL)
      return;

   if(p_dialog == NULL)
      return;

   p_dialog->createAction(buttonId, text);
   QAction *action = p_dialog->getAction(text.toLower());
   connect(action, SIGNAL(triggered()), p_fglform, SLOT(actionTriggered()));

   Fgl::Event event;
   event.type = Fgl::MENUACTION_EVENT;
   event.id = buttonId;
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
            WidgetHelper::setDisplayAttributes(attr, widget);
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
      setArrayBuffer(row, fieldName, values);
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
void ScreenHandler::setArrayBuffer(QWidget* tableView, QString fieldName, QString fieldValue)
{
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
      screenRecord->setText(fieldValue.trimmed(), row, col);
   }
}

void ScreenHandler::setArrayBuffer(int row, QString tabName, QStringList fieldValues)
{
   int index = tabName.indexOf(".*");
   int cnt_values = 0;
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
}

void ScreenHandler::setArrayBuffer(int row, QStringList fieldValues)
{
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

   if(index < 0){
      // No wildcard
      QWidget *widget = p_fglform->findFieldByName(fieldName);
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
   else{
      QList<QWidget*> ql_fields = p_fglform->findFieldsByName(fieldName);
      for(int i=0; i<ql_fields.count(); i++){
         QWidget *widget = ql_fields.at(i);
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

}

//------------------------------------------------------------------------------
// Method       : setFieldFocus(QString FieldName )
// Filename     : screenhandler.cpp
// Description  : sets the focus for the Field
//------------------------------------------------------------------------------
void ScreenHandler::setFieldFocus(QString fieldName)
{
   fieldName = fieldName.trimmed();

   int i_Frm = getCurrForm();

   if(i_Frm < 0)
      return;

   clearEvents();

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
   fieldName = fieldName.trimmed();

   int i_Frm = getCurrForm();

   if(i_Frm < 0)
      return;

   if(QWidget *widget = qobject_cast<QWidget *> (p_fglform->findFieldByName(fieldName))){
      widget->setHidden(hidden);
   }
   
}

//------------------------------------------------------------------------------
// Method       : setFieldFocus(QString FieldName )
// Filename     : screenhandler.cpp
// Description  : sets the focus for the Field
//------------------------------------------------------------------------------
void ScreenHandler::setElementHidden(QString fieldName, bool hidden)
{
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
   if(p_fglform == NULL)
      return;

   if(p_fglform->ql_responseQueue.size() > 0){
      p_fglform->ql_responseQueue.clear();
   }

   this->clearFieldEvents = false;
}

//------------------------------------------------------------------------------
// Method       : setEvent(QString event, QString attribute, int id)
// Filename     : screenhandler.cpp
// Description  : relates field with events and activate it
//------------------------------------------------------------------------------
void ScreenHandler::setEvent(QString event, QString attribute, int id)
{
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

      Action *action = new Action(attribute);
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

      Action *action = new Action(attribute);
      action->setDefaultView("yes");
      p_fglform->addFormAction(action);
      action->setEnabled(true);

      //p_fglform->ql_formEvents << event;
      p_fglform->addFormEvent(event);
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

   if(!value){
      if(p_prompt != NULL && type == "PROMPT"){
         p_prompt->setVisible(false);
         p_prompt->close();
         p_prompt->deleteLater();
         p_prompt = NULL;
      }
   }

   int i_Frm = getCurrForm();

   if(i_Frm < 0)
      return;

   Context *context = getContext(i_context);
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
         event.id = -1;
         event.attribute = "accept"; 

         p_fglform->addFormEvent(event);

         event.type = Fgl::ONACTION_EVENT;
         event.id = -1;
         event.attribute = "cancel";

         p_fglform->addFormEvent(event);
      }

      if(type == "CONSTRUCT"){
         p_fglform->setState(Fgl::CONSTRUCT);
         context->setState(Fgl::CONSTRUCT);

         Fgl::Event event;
         event.type = Fgl::ONACTION_EVENT;
         event.id = -1;
         event.attribute = "accept"; 

         p_fglform->addFormEvent(event);

         event.type = Fgl::ONACTION_EVENT;
         event.id = -1;
         event.attribute = "cancel";

         p_fglform->addFormEvent(event);
      }

      if(type == "DISPLAYARRAY"){
         p_fglform->setState(Fgl::DISPLAYARRAY);
         context->setState(Fgl::DISPLAYARRAY);
//         p_fglform->addFormAction("accept", "Ok");

         Fgl::Event event;
         event.type = Fgl::ONACTION_EVENT;
         event.id = -1;
         event.attribute = "accept"; 

         p_fglform->addFormEvent(event);

         event.type = Fgl::ONACTION_EVENT;
         event.id = -1;
         event.attribute = "cancel";

         p_fglform->addFormEvent(event);
      }

      if(type == "INPUTARRAY"){
         p_fglform->setState(Fgl::INPUTARRAY);
         context->setState(Fgl::INPUTARRAY);
//         p_fglform->addFormAction("accept", "Ok");

         Fgl::Event event;
         event.type = Fgl::ONACTION_EVENT;
         event.id = -1;
         event.attribute = "accept"; 

         p_fglform->addFormEvent(event);

         event.type = Fgl::ONACTION_EVENT;
         event.id = -1;
         event.attribute = "cancel";

         p_fglform->addFormEvent(event);
      }
   }
   else{
      if(type == "MENU"){
         if(p_fglform->dialog() != NULL){
            p_fglform->dialog()->close();
            p_fglform->setDialog(NULL);
            p_fglform->setEnabled(true);
            p_fglform->revertState(Fgl::MENU);
            freeContext(i_context);
            p_fglform->ql_dialogEvents.clear();
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

         if(p_fglform->inputArray()){
//            QList<QWidget*> ql_fields = p_fglform->formElements();
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
   if(p_fglform == NULL)
      return;


   if(p_fglform->context != getCurrentContext()){
      p_fglform->context = getCurrentContext();
      connect(p_fglform->context, SIGNAL(fieldEvent(Fgl::Event)), p_fglform, SLOT(fieldEvent(Fgl::Event)));
   }

   p_fglform->checkState();

   if(b_newForm && p_fglform->dialog () == NULL && p_fglform->state() != Fgl::IDLE){
      b_newForm = false;
      p_fglform->show();
   }
   else{
      if(p_fglform->dialog() != NULL){
         p_fglform->dialog()->show();
         p_fglform->dialog()->adjustSize();
      }
   }

   checkFields();
   if(p_fglform->context != NULL)
      p_fglform->context->checkOptions();

   p_fglform->raise();

   //p_fglform->checkState();
   p_fglform->b_getch_swin = true;
   processResponse();
}

//------------------------------------------------------------------------------
// Method       : processResponse()
// Filename     : screenhandler.cpp
// Description  : sends user inputs to the protocol as xml
//------------------------------------------------------------------------------
void ScreenHandler::processResponse()
{
   if(p_fglform == NULL)
      return;

   if(!p_fglform->b_getch_swin)
      return;

   if(p_fglform->ql_responseQueue.size() <= 0)
      return;


   QString id = p_fglform->ql_responseQueue.takeFirst();
   Response resp(id, p_fglform, cursorPos);
   QString qs_resp = resp.toString();
   if(qs_resp.isEmpty())
      return;

   fglFormResponse(qs_resp);
   p_fglform->b_getch_swin = false;

}
//------------------------------------------------------------------------------
// Method       : sendDirect(QString cmd)
// Filename     : screenhandler.cpp
// Description  : sends user inputs to the protocol without xml preparation (for RUN)
//------------------------------------------------------------------------------

void ScreenHandler::sendDirect(QString cmd)
{
   fglFormResponse(cmd);
   if(p_fglform != NULL)
      p_fglform->b_getch_swin = false;
}

//------------------------------------------------------------------------------
// Method       : free(QString type)
// Filename     : screenhandler.cpp
// Description  : END INPUT, END MENU etc
//------------------------------------------------------------------------------
void ScreenHandler::free(QString type)
{

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
         p_fglform->dialog()->close();
         p_fglform->setDialog(NULL);
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

   if(p_fglform == NULL)
      return;

   StatusBar *statusBar = (StatusBar*) p_fglform->statusBar();

   statusBar->displayError(text);
   Dialog *errorDialog = new Dialog(tr("Error"), text, "dialog", "exclamation", p_fglform);
   errorDialog->setModal(true);
   errorDialog->createButton(1, "OK", "OK", "ok.png");
   connect(errorDialog->getAction("OK"), SIGNAL(triggered()), errorDialog, SLOT(close())); 
   errorDialog->show();
   errorDialog->raise();

}

//------------------------------------------------------------------------------
// Method       : displayMessage(QString text)
// Filename     : screenhandler.cpp
// Description  : displays message in message line
//------------------------------------------------------------------------------
void ScreenHandler::displayMessage(QString text)
{

   if(p_fglform == NULL)
      return;

   StatusBar *statusBar = (StatusBar*) p_fglform->statusBar();
   statusBar->displayMessage(text);
}

//------------------------------------------------------------------------------
// Method       : setWindowTitle(QString title)
// Filename     : screenhandler.cpp
// Description  : defines window title
//------------------------------------------------------------------------------
void ScreenHandler::setWindowTitle(QString title)
{
   if(p_fglform == NULL)
      return;

   p_fglform->setWindowTitle(title);

}


void ScreenHandler::MsgBox (QString title, QString text, QString logo, QString buttons, QString defButton,int reply)
{
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
      fglFormResponse("<TRIGGERED ID=\""+rstr+"\"/>");
   }
   //return rstr;
}

//------------------------------------------------------------------------------
// Method       : closeWindow(QString windowName)
// Filename     : screenhandler.cpp
// Description  : CLOSE WINDOW
//------------------------------------------------------------------------------
void ScreenHandler::closeWindow(QString windowName)
{

   for(int i=0; i<ql_fglForms.size(); i++){
      FglForm *form = ql_fglForms.at(i);

      if(form->windowName == windowName){
         form->b_allowClose = true;
         form->close();
         int i_Frm = getCurrForm();
         initForm(i_Frm);
         cnt_form--;
         ql_fglForms.takeAt(i);
//         window->deleteLater();
         i_Frm = getCurrForm();


         if(i_Frm > -1){
            p_fglform = ql_fglForms.at(i_Frm);
         }
         else{
            p_fglform = NULL;
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

   for(int i=0; i<ql_fglForms.size(); i++){
      FglForm *form = ql_fglForms.at(i);

      if(form->windowName == windowName){
         p_fglform = form;
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
   int i_Frm = getCurrForm();

   if(i_Frm < 0)
      return;

   if(p_fglform == NULL)
      return;

   if(qh_formActionMenus[i_Frm] == NULL){
      createActionMenu();
      p_fglform->setMenuEnabled(false);
   }


   createActionMenuButton(text, label);

}

//------------------------------------------------------------------------------
// Method       : setScreenRecordEnabled(QStringList qsl_tabNames, bool enable, bool input)
// Filename     : screenhandler.cpp
// Description  : activates table on screen forms
//------------------------------------------------------------------------------
void ScreenHandler::setScreenRecordEnabled(QString fieldName, bool enable, bool input)
{
   Q_UNUSED(enable);
   Context *context = getCurrentContext();

   QList<QWidget*> ql_fields = p_fglform->findFieldsByName(fieldName);
   for(int i=0; i< ql_fields.count(); i++){

      QWidget *widget = ql_fields.at(i);

      if(LineEditDelegate *de = qobject_cast<LineEditDelegate *> (widget)){
         if(TableView *tableView = qobject_cast<TableView *> (de->parent())){
            
            context->addScreenRecord(tableView, input);
         }
      }
   }
}

//------------------------------------------------------------------------------
// Method       : loadArrayValues(QStringList qsl_tabNames, QStringList qsl_arrayValues)
// Filename     : screenhandler.cpp
// Description  : load data on table for being displayed
//------------------------------------------------------------------------------
void ScreenHandler::loadArrayValues(QStringList qsl_tabNames, QStringList qsl_arrayValues)
{
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

//   QList<QWidget*> ql_fields = p_fglform->formElements();
   QList<QWidget*> ql_fields = p_fglform->ql_formFields;
   for(int i=0; i<ql_fields.size(); i++){

      if(TextEdit *edit = qobject_cast<TextEdit *> (ql_fields.at(i))){
           QTextCursor cursor = edit->textCursor();
           cursor.setPosition(pos);
           edit->setTextCursor(cursor);
            return;
      }
   }
}

void ScreenHandler::setInputFields(QStringList qsl_fields)
{

   int i_Frm = getCurrForm();

   if(i_Frm < 0)
      return;

   if(p_fglform == NULL)
      return;

   p_fglform->qsl_fieldOrder = qsl_fields;

}

void ScreenHandler::setClearEvents()
{
   clearFieldEvents = true;
}

void ScreenHandler::setArrLine(int line)
{
   if(p_fglform == NULL)
      return;

   Context *context = getCurrentContext();

   if(context == NULL)
      return;

   for(int i=0; i<context->fieldList().count(); i++){
      if(TableView *tableView = qobject_cast<TableView *> (context->fieldList().at(i))){
            tableView->setArrLine(line-1);
      }
   }
}

void ScreenHandler::setScrLine(int line)
{
   if(p_fglform == NULL)
      return;

//   QList<QWidget*> ql_fields = p_fglform->formElements();
   QList<QWidget*> ql_fields = p_fglform->ql_formFields;
   for(int i=0; i<ql_fields.size(); i++){
      if(TableView *tableView = qobject_cast<TableView *> (ql_fields.at(i))){
         tableView->setScrLine(line-1);
      }
   }
}

Context* ScreenHandler::getContext(int i_context)
{
   int contextCount = contexts.count()-1;

   for(int i=contextCount; i<i_context; i++){
      Context *context = new Context;
      contexts << context;
   }

   return contexts.at(i_context);

}

Context* ScreenHandler::getCurrentContext()
{
   if(contexts.count() > 0){
      return contexts.at(contexts.count()-1);
   }

   return NULL;

}

void ScreenHandler::freeContext(int i_context)
{
   int contextCount = contexts.count()-1;
   if(contextCount >= i_context){
      Context *context = contexts.takeAt(i_context);
      for(int i=0; i<context->fieldList().count(); i++){
         QWidget *field = context->fieldList().at(i);
         field->blockSignals(true);
         field->setEnabled(false);
         if(LineEdit *le = qobject_cast<LineEdit *> (field)){
             le->setTouchendEnabled(false);
         }
         field->blockSignals(false);
      }
      delete context;

      context = getCurrentContext();
      p_fglform->context = context;

      //->deleteLater();
   }
      //contexts.removeAt(i_context);

}

void ScreenHandler::fileBrowser(QString function, QString defPath, QString fileNames, QString fileTypes, QString caption)
{
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

   QDomElement syncValuesElement = doc.createElement("SYNCVALUES");
   docElement.appendChild(syncValuesElement);

   QDomElement paramElement = doc.createElement("SYNCVALUE");
   QDomText param = doc.createTextNode(fileName);
   paramElement.appendChild(param);

   syncValuesElement.appendChild(paramElement);

   qs_resp = doc.toString();
   fglFormResponse(qs_resp);
   p_fglform->b_getch_swin = false;
}

void ScreenHandler::setSearchPaths()
{
   //set the separator depending on the OS
   QChar sep;
#ifdef __WIN32__
sep = QChar(';');
#else
sep = QChar(':');
#endif

   QStringList dbPaths;

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

   // Clean search Paths
   QDir::setSearchPaths("pics", dbPaths);
}

void ScreenHandler::checkFields()
{
   return;
   if(p_fglform == NULL)
      return;

   bool enable = (p_fglform->state() != Fgl::CONSTRUCT);
   Q_UNUSED(enable);
}


void ScreenHandler::setUpdatesEnabled(bool en)
{
   for(int i=0; i<ql_fglForms.size(); i++){
         FglForm *form = ql_fglForms.at(i);

      if(form != NULL){
         form->setUpdatesEnabled(en);
      }
   }
}

void ScreenHandler::setEnv(QString name, QString env)
{
   Fgl::env[name] = env;
}


bool ScreenHandler::eventFilter(QObject *obj, QEvent *event)
{

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

   return QObject::eventFilter(obj, event);

}

void ScreenHandler::setInterfaceText(QString text)
{
   qs_interfaceTitle = text;
   for(int i=0; i<ql_fglForms.size(); i++){
       ql_fglForms.at(i)->setWindowTitle(text);
   }
}
