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
ScreenHandler::ScreenHandler(QTcpSocket *parent) : QObject(parent)
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

//------------------------------------------------------------------------------
// Method       : createWindow()
// Filename     : screenhandler.cpp
// Description  : creates the Form. prepares for displaying it
//------------------------------------------------------------------------------
void ScreenHandler::createWindow(QString windowTitle,QString style, int x, int y, int h, int w)
{
   Q_UNUSED(x);
   Q_UNUSED(y);

   cnt_form++;
   int i_Frm = getCurrForm();

   QWidget *parent = NULL;

   if(i_Frm > 0 && p_fglform != NULL){
      parent = p_fglform;
   }

   p_fglform = new FglForm(windowTitle, parent);

   connect(p_fglform, SIGNAL(processResponse()), this, SLOT(processResponse()));
   connect(p_fglform, SIGNAL(sendDirect(QString)), this, SLOT(sendDirect(QString)));
   connect(p_fglform, SIGNAL(setClearEvents()), this, SLOT(setClearEvents()));

   p_fglform->setWindowTitle(windowTitle);
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
void ScreenHandler::handleXMLForm(QString formName, QString xmlFormString)
{
   Q_UNUSED(formName);

   QDomDocument xmlForm;
   xmlForm.setContent(xmlFormString);

   p_fglform->setFormLayout(xmlForm);
}

//------------------------------------------------------------------------------
// Method       : handleAubitForm()
// Filename     : screenhandler.cpp
// Description  : passes the FormFile to the parsing function and adds
//                the returning layouts and fields to the FglForm
//------------------------------------------------------------------------------
void ScreenHandler::handleAubitForm(QString formName, QString xmlFormString)
{

   Q_UNUSED(formName);

   // Before Creating a form we increase the counter
   // so the form knows there is a layout waiting
   cnt_form++;

   QDomDocument xmlForm;
   xmlForm.setContent(xmlFormString);

   int height = xmlForm.documentElement().attribute("height").toInt();
   int width = xmlForm.documentElement().attribute("width").toInt();

   QSize *size = new QSize(width, height);
   ql_formSizes << size;

   p_fglform->setFormLayout(xmlForm);
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

   startMenu = xmlFile;
}

//------------------------------------------------------------------------------
// Method       : handleXMLActions(QString xmlFile)
// Filename     : screenhandler.cpp
// Description  : action defaults like "Find" etc. 4ad file
//------------------------------------------------------------------------------
void ScreenHandler::handleXMLActions(QString xmlFileString)
{

   QDomDocument xmlFile;
   xmlFile.setContent(xmlFileString);

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

   // If form already has a menu then display
   // the menu as a dialog
   if(style == "dialog"){
      createDialog(title, comment, style, image);
      return;
   }


   RingMenu *ringMenu = new RingMenu(title, style, image);

   p_fglform->setMenu(ringMenu);
}

//------------------------------------------------------------------------------
// Method       : createMenuButton(int buttonId, QString text, QString desc)
// Filename     : screenhandler.cpp
// Description  : creates the menubutton and adds it to the buttongroup
//------------------------------------------------------------------------------
void ScreenHandler::createMenuButton(int buttonId, QString text, QString desc, QStringList keys)
{

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
// Method       : hideOption(QString title, QString FieldValue)
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

   Dialog *p_dialog = new Dialog(title, comment, style, image, p_fglform);
   p_fglform->setDialog(p_dialog);

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

}

//------------------------------------------------------------------------------
// Method       : createDialog(QString title, QString FieldValue)
// Filename     : screenhandler.cpp
// Description  : creates the horizontal ring menu or some other dialog
//------------------------------------------------------------------------------
void ScreenHandler::createPrompt(QString text, int charMode, QString style)
{
   Q_UNUSED(style);

   p_prompt = new Prompt(text, charMode);
   p_prompt->activateWindow();
   p_prompt->raise();
   connect(p_prompt, SIGNAL(sendDirect(QString)), this, SLOT(sendDirect(QString)));
}


//------------------------------------------------------------------------------
// Method       : setFieldBuffer(QStringList FieldNames, QStringList FieldValues)
// Filename     : screenhandler.cpp
// Description  : sets the Text for the Field
//------------------------------------------------------------------------------
void ScreenHandler::setFieldBuffer(QStringList fieldNames, QStringList fieldValues)
{

   int i_Frm = getCurrForm();

   if(i_Frm < 0)
      return;

   int value_cnt = 0;

   for(int i=0; i<fieldNames.count(); i++){
      QString fieldName = fieldNames.at(i);

      int index = fieldName.indexOf(".*");

      if(index <= -1){
         // DISPLAY BY NAME
         QList<QWidget*> ql_fields = p_fglform->formElements();
         for(int j=0; j<ql_fields.size(); j++){

            QWidget *widget = ql_fields.at(j);

            if(TableView *tableView = qobject_cast<TableView *> (widget)){
               int index = fieldName.indexOf(".");
               int index2 = fieldName.indexOf("[");

               if(index2 > -1 && index2 < index)
                  index = index2;

               QString tabName;
               if(index < 0){
                  tabName = fieldName;
               }
               else{
                  tabName = fieldName.mid(0,index);
               }

               if(tableView->accessibleName() == tabName){
                   setArrayBuffer(widget, fieldName, fieldValues.at(value_cnt));
                   value_cnt++;
                   break;
               }
            }
            else{
               if(widget->accessibleName() == fieldName ||
                  widget->objectName() == fieldName){
                  WidgetHelper::setFieldText(widget, fieldValues.at(value_cnt));
                  value_cnt++;
                  break;
               }
            }
            if(j == ql_fields.size()-1){
               value_cnt++;
               break;
            }
         }
      }
      else{
         //DISPLAY record.* TO fieldrecords.*
         QRegExp rx(fieldName);


         int count = value_cnt + p_fglform->recordView[fieldName.mid(0, index)].count();
         int widget_cnt = 0;

         for(int j=value_cnt; j<fieldValues.size(); j++){

            QList<QWidget*> ql_fields = p_fglform->formElements();
            for(int k=widget_cnt; k<ql_fields.size(); k++){

               QWidget *widget = ql_fields.at(k);

               if(TableView *tableView = qobject_cast<TableView *> (widget)){
                  int index = -1;
                  int index1 = fieldName.indexOf(".");
                  int index2 = fieldName.indexOf("[");

                  if(index2 > -1 && index2 < index1){
                     index = index2;
                  }
                  else{
                     index = index1;
                  }

                  QString tabName;
                  if(index < 0){
                     tabName = fieldName;
                  }
                  else{
                     tabName = fieldName.mid(0,index);
                  }

                  if(tableView->accessibleName() == tabName){
                     if(j <= tableView->model()->columnCount(QModelIndex())){
                        //get row and set fieldName right
                        if(p_fglform->recordView[fieldName.mid(0, index)].count() > 0){
                           Fgl::Link link = p_fglform->recordView[fieldName.mid(0, index)].at(j);
                           if(index2 < 0){
                              fieldName = QString("%1[1].%2").arg(tabName).arg(link.colName);
                           }
                           else{
                              fieldName = QString("%1.%2").arg(fieldName.mid(0,index1)).arg(link.colName);
                           }
                        }
                        else{
                           QString colName = tableView->getColumnName(j);
                           fieldName = QString("%1.%2").arg(fieldName.mid(0,index1)).arg(colName);
                        }
                        setArrayBuffer(widget, fieldName, fieldValues.at(j));
                        widget_cnt = k;
                        value_cnt = j+1;
                        break;
                     }
                  }
               }
               else{
                  if(rx.exactMatch(widget->accessibleName()) || rx.exactMatch(widget->objectName())){
                     WidgetHelper::setFieldText(widget, fieldValues.at(j));
                     widget_cnt = k+1;
                     value_cnt = j+1;
                     break;
                  }
               }
            }

            if(j == count-1){
               value_cnt = j+1;
               break;
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
void ScreenHandler::setFieldBuffer(int fieldNo, QString fieldValue)
{

   int i_Frm = getCurrForm();
   if(i_Frm < 0)
      return;

   Fgl::Context *context = getCurrentContext();
   if(context == NULL)
      return;

   QString fieldName;
   if(context->fieldList.count()-1 >= fieldNo){
      fieldName = context->fieldList.at(fieldNo);
   }
   else{
      return;
   }

   QList<QWidget*> ql_fields = p_fglform->formElements();
   for(int i=0; i<ql_fields.size(); i++){

     QWidget *widget = ql_fields.at(i);

     if(widget->accessibleName() == fieldName || widget->objectName() == fieldName){
        WidgetHelper::setFieldText(widget, fieldValue);
        return;
     }

      if(TableView *tableView = qobject_cast<TableView *> (widget)){
         QString tabName;
         int index = fieldName.indexOf(".");
         if(index >= 0){
            tabName.append(fieldName.mid(0,index));
         }

         if(tableView->tabName == tabName){
            setArrayBuffer(tableView, fieldName, fieldValue);
            return;
         }
      }
   }
}

//------------------------------------------------------------------------------
// Method       : setFieldBuffer(QString FieldName, QString FieldValue)
// Filename     : screenhandler.cpp
// Description  : sets the Text for the Field
//------------------------------------------------------------------------------
void ScreenHandler::clearFieldBuffer(QString fieldName)
{
   // For fieldlist = table.*
   int index = fieldName.indexOf(".*");

   if(index > -1){
      QRegExp rx(fieldName);
      QList<QWidget*> ql_fields = p_fglform->formElements();
      for(int i=0; i<ql_fields.size(); i++){
         if(LineEdit *lineEdit = qobject_cast<LineEdit *> (ql_fields.at(i))){
            if(rx.exactMatch(lineEdit->accessibleName())){
               lineEdit->clear();
            }
         }

         if(TextEdit *textEdit = qobject_cast<TextEdit *> (ql_fields.at(i))){
            if(rx.exactMatch(textEdit->accessibleName())){
               textEdit->clear();
            }
         }
      }
   }
   else{
      QList<QWidget*> ql_fields = p_fglform->formElements();
      for(int i=0; i<ql_fields.size(); i++){

         if(LineEdit *lineEdit = qobject_cast<LineEdit *> (ql_fields.at(i))){
            if(lineEdit->objectName() == fieldName || lineEdit->accessibleName() == fieldName){
               lineEdit->clear();
               break;
            }
         }

         if(TextEdit *textEdit = qobject_cast<TextEdit *> (ql_fields.at(i))){
            if(textEdit->objectName() == fieldName || textEdit->accessibleName() == fieldName){
               textEdit->clear();
               break;
            }
         }
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
      QModelIndex modelIndex = proxyModel->index(row, col, QModelIndex());
      modelIndex = proxyModel->mapFromSource(modelIndex);
      screenRecord->model()->setData(modelIndex, fieldValue);
   }
}

void ScreenHandler::setArrayBuffer(int row, QString tabName, QStringList fieldValues)
{
   int index = tabName.indexOf(".*");
   if(index >= 0)
      tabName.remove(index, 2);

   QList<QWidget*> ql_fields = p_fglform->formElements();
   for(int i=0; i<ql_fields.size(); i++){

      QWidget *widget = ql_fields.at(i);

      if(widget->accessibleName() == tabName){
         if(TableView *tableView = qobject_cast<TableView *> (widget)){
            QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (tableView->model());
            TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

            if(table->rowCount(QModelIndex()) < row+1){
               table->insertRow(row, QModelIndex());
            }

            for(int col=0; col<fieldValues.count(); col++){
               QString fieldValue = fieldValues.at(col);
               QModelIndex modelIndex = table->index(row, col, QModelIndex());
               table->setData(modelIndex, fieldValue, Qt::EditRole);
            }
         }
      }
      else{
         if(Matrix *matrix = qobject_cast<Matrix *> (widget)){
            QList<Fgl::Link> ql_links = p_fglform->recordView[tabName];
            for(int l=0; l<ql_links.count(); l++){
               Fgl::Link link = ql_links.at(l);
               if(link.fieldIdRef == matrix->property("fieldId").toInt()){
                  for(int col=0; col<fieldValues.count(); col++){
                     matrix->setText(row, fieldValues.at(col));
                  }
               }
            }
         }
      }
   }
}

void ScreenHandler::setArrayBuffer(int row, QStringList fieldValues)
{
   QList<QWidget*> ql_fields = p_fglform->formElements();
   for(int i=0; i<ql_fields.size(); i++){

      QWidget *widget = ql_fields.at(i);

      if(widget->isEnabled()){
         if(TableView *tableView = qobject_cast<TableView *> (widget)){
            QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (tableView->model());
            TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

            if(table->rowCount(QModelIndex()) < row+1){
               table->insertRow(row, QModelIndex());
            }

            for(int col=0; col<fieldValues.count(); col++){
               QString fieldValue = fieldValues.at(col);
               QModelIndex modelIndex = table->index(row, col, QModelIndex());
               table->setData(modelIndex, fieldValue, Qt::EditRole);
            }
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

   QList<QWidget*> ql_fields = p_fglform->formElements();
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
            int rowCount = table->rowCount(QModelIndex());
            int row = 0;

            for(int i=0; i<qsl_arrayValues.count(); i+=colCount){
               if(i+colCount<=qsl_arrayValues.count()){
                  for(int j=0; j<colCount; j++){
                     // if table has not enough rows add one
                     if(table->rowCount(QModelIndex()) < row+1){
                        table->insertRows(row, 1, QModelIndex());
                     }

                     QModelIndex index = table->index(row, j);
                     table->setData(index, qsl_arrayValues.at(i+j), Qt::EditRole);
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
void ScreenHandler::setFieldEnabled(QString fieldName, bool enable, bool focus)
{

   fieldName = fieldName.trimmed();

   int i_Frm = getCurrForm();
   if(i_Frm < 0)
      return;

   Fgl::Context *context = getCurrentContext();
   if(context == NULL)
      return;

   // For fieldlist = table.*
   int index = fieldName.indexOf(".*");

   if(index > -1){
      // For fieldlist = table.*
      QRegExp rx(fieldName);

      QList<QWidget*> ql_fields = p_fglform->formElements();
      for(int i=0; i<ql_fields.size(); i++){
         QWidget *widget = ql_fields.at(i);
         //dbu: Labels dont have to be enabled or disabled
         if(widget->inherits("QLabel")) continue;

         if(rx.exactMatch(widget->accessibleName())){ 
            widget->setEnabled(enable);
            if(enable) {
               context->fieldList << widget->accessibleName();
            }
            else{
            }

            if(focus){
               widget->setFocus();
               widget->update();
               focus = false;
            }
         }

         if(LineEdit *lineEdit = qobject_cast<LineEdit *> (ql_fields.at(i))){
            if(rx.exactMatch(lineEdit->accessibleName())){
               if(!context->options["WITHOUT_DEFAULTS"]){
                  lineEdit->setText("");
               }
               if(enable){
                  if(p_fglform->construct()){
                     lineEdit->setMaxLength(32767);
                     lineEdit->setValidator(NULL);
                  }
                  else{
                     lineEdit->setMaxLength(lineEdit->w);
                     lineEdit->setValidator(lineEdit->getValidator());
                  }
               }
            }
         }
      }
   }
   else{
      QList<QWidget*> ql_fields = p_fglform->formElements();
      for(int i=0; i<ql_fields.size(); i++){
         QWidget *widget = ql_fields.at(i);
         //dbu: Labels dont have to be enabled or disabled
         if(widget->inherits("QLabel")) continue;

         if((widget->objectName() == fieldName || widget->accessibleName() == fieldName)){ //&& !widget->inherits("QLabel")){
            widget->setEnabled(enable);
            if(enable)
               context->fieldList << widget->accessibleName();

            if(focus){
               widget->setFocus();
               widget->update();
               focus = false;
            }
         }

         if(LineEdit *lineEdit = qobject_cast<LineEdit *> (ql_fields.at(i))){
            if(lineEdit->objectName() == fieldName || lineEdit->accessibleName() == fieldName){
               if(enable){
                  if(!context->options["WITHOUT_DEFAULTS"]){
                     lineEdit->setText("");
                  }
                  if(p_fglform->construct()){
                     lineEdit->setMaxLength(32767);
                     lineEdit->setValidator(NULL);
                  }
                  else{
                     lineEdit->setMaxLength(lineEdit->w);
                     lineEdit->setValidator(lineEdit->getValidator());
                  }
               }
               break;
            }
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

   int index = -1;

   index = fieldName.indexOf("[");

   if(p_fglform->focusWidget() != NULL && !p_fglform->screenRecord()){
      p_fglform->focusWidget()->clearFocus();
      clearEvents();
   }


   if(fieldName == "NEXT"){
      if(p_fglform->currentField() != NULL){
         p_fglform->currentField()->setFocus();
         clearEvents();
         p_fglform->nextfield();
      }else{
         p_fglform->nextfield();
      }
      return;
   }

   QList<QWidget*> ql_fields = p_fglform->formElements();
   for(int i=0; i<ql_fields.size(); i++){
      QWidget *widget = ql_fields.at(i);

      if(TableView *tableView = qobject_cast<TableView *> (widget)){
         if(!p_fglform->screenRecord())
            continue;

         QString tabName;
         int index = fieldName.indexOf(".");

         // Fieldname can be table.Field[n] or field[0]
         if(index >= 0){
            tabName.append(fieldName.mid(0,index));
            index = -1;
         }
         else{
            index = fieldName.indexOf("[");
            if(p_fglform->screenRecord() && index < 0){
              fieldName.append(QString("[%1]").arg(tableView->currentIndex().row()+1));
              index = fieldName.indexOf("[");
            }
         }

         if(tableView->tabName == tabName || index >= 0){
            setArrayFocus(tableView, fieldName);
            return;
         }
      }
      else{
         if(widget->accessibleName() == fieldName || widget->objectName() == fieldName){
            widget->setFocus();
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
      QModelIndex modelIndex = proxyModel->index(row, col, QModelIndex());
      modelIndex = proxyModel->mapFromSource(modelIndex);

      QModelIndex index = screenRecord->currentIndex();
      QItemSelectionModel *selection = screenRecord->selectionModel();

      if(modelIndex.isValid()){
         if(index != modelIndex){
            selection->setCurrentIndex(modelIndex, QItemSelectionModel::NoUpdate);
         }
      }
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
   if(event == "BEFORE_INPUT_EVENT" ||
      event == "BEFORE_CONSTRUCT_EVENT" ||
      event == "BEFORE_DISPLAY_EVENT"){
      if(p_fglform != NULL)
         p_fglform->ql_responseQueue << QString::number(id);
   }

   if(event == "AFTER_INPUT_EVENT"){
      Fgl::Event event;
      event.type = Fgl::AFTER_INPUT_EVENT;
      event.id = id;

      p_fglform->ql_formEvents << event;
      return;
   }

   if(event == "AFTER_CONSTRUCT_EVENT"){
      Fgl::Event event;
      event.type = Fgl::AFTER_CONSTRUCT_EVENT;
      event.id = id;

      p_fglform->ql_formEvents << event;
      return;
   }

   if(event == "AFTER_DISPLAY_EVENT"){
      Fgl::Event event;
      event.type = Fgl::AFTER_DISPLAY_EVENT;
      event.id = id;

      p_fglform->ql_formEvents << event;
      return;
   }

   if(event == "BEFORE_FIELD_EVENT"){
      Fgl::Event event;
      event.type = Fgl::BEFORE_FIELD_EVENT;
      event.id = id;
      event.attribute= attribute;

      p_fglform->ql_formEvents << event;
      return;
   }

   if(event == "AFTER_FIELD_EVENT"){
      Fgl::Event event;
      event.type = Fgl::AFTER_FIELD_EVENT;
      event.id = id;
      event.attribute= attribute;

      p_fglform->ql_formEvents << event;
      return;
   }

   if(event == "BEFORE_ROW_EVENT"){
      Fgl::Event event;
      event.type = Fgl::BEFORE_ROW_EVENT;
      event.id = id;

      p_fglform->ql_formEvents << event;
      return;
   }

   if(event == "AFTER_ROW_EVENT"){
      Fgl::Event event;
      event.type = Fgl::AFTER_ROW_EVENT;
      event.id = id;

      p_fglform->ql_formEvents << event;
      return;
   }

   if(event == "ONKEY_EVENT"){
      Fgl::Event event;
      event.type = Fgl::ONKEY_EVENT;
      event.id = id;
      event.attribute= attribute;

      p_fglform->ql_formEvents << event;
      return;
   }

   if(event == "ON_ACTION_EVENT"){
      Fgl::Event event;
      event.type = Fgl::ONACTION_EVENT;
      event.id = id;
      event.attribute= attribute;

      p_fglform->ql_formEvents << event;
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
      ActionMenu *actionMenu = new ActionMenu("", "", "");
      qh_formActionMenus[i_Frm] = actionMenu;
      p_fglform->setActionMenu(qh_formActionMenus[i_Frm]);
      p_fglform->setMenuEnabled(false);
   }

}

//------------------------------------------------------------------------------
// Method       : createActionMenuButton(QString buttonId, QString text, QString desc)
// Filename     : screenhandler.cpp
// Description  : defines and show F-keys buttons
//------------------------------------------------------------------------------
void ScreenHandler::createActionMenuButton(QString buttonId, QString text, QString desc)
{

  int i_Frm = getCurrForm();

   if(i_Frm < 0)
      return;

   if(p_fglform == NULL)
      return;

   if(qh_formActionMenus[i_Frm] == NULL)
      return;

   ActionMenu *actionMenu = qh_formActionMenus[i_Frm];

   actionMenu->createButton(buttonId, text, desc);
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

   Fgl::Context *context = getContext(i_context);

   if(value){
      if(type == "MENU"){
         p_fglform->setState(Fgl::MENU);
         context->state = Fgl::MENU;
      }

      if(type == "INPUT"){
         p_fglform->setState(Fgl::INPUT);
         context->state = Fgl::INPUT;
      }

      if(type == "CONSTRUCT"){
         p_fglform->setState(Fgl::CONSTRUCT);
         context->state = Fgl::CONSTRUCT;
      }

      if(type == "DISPLAYARRAY"){
         p_fglform->setState(Fgl::DISPLAYARRAY);
         context->state = Fgl::DISPLAYARRAY;
      }

      if(type == "INPUTARRAY"){
         p_fglform->setState(Fgl::INPUTARRAY);
         context->state = Fgl::INPUTARRAY;
      }
   }
   else{
      if(type == "MENU"){
         if(p_fglform->dialog() != NULL){
            p_fglform->dialog()->close();
            p_fglform->setDialog(NULL);
            p_fglform->revertState(Fgl::MENU);
            freeContext(i_context);
            return;
         }
         else{
            p_fglform->removeMenu();
            p_fglform->revertState(Fgl::MENU);
            freeContext(i_context);
         }
      }

      if(type == "INPUT"){
         if(p_fglform->input()){
            p_fglform->revertState(Fgl::INPUT);

            for(int i=0; i<context->fieldList.count(); i++){
               setFieldEnabled(context->fieldList.at(i), false, false);
            }
            freeContext(i_context);
            p_fglform->ql_responseQueue.clear();
            p_fglform->ql_formEvents.clear();
            return;
         }

         if(p_fglform->inputArray()){
            QList<QWidget*> ql_fields = p_fglform->formElements();
            for(int i=0; i<ql_fields.size(); i++){
               QWidget *widget = (QWidget*) ql_fields.at(i);

               if(widget->isEnabled()){
                  if(TableView *tableView = qobject_cast<TableView *> (ql_fields.at(i))){
                     tableView->setEnabled(false);
                  }
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
         QList<QWidget*> ql_fields = p_fglform->formElements();
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
         freeContext(i_context);
      }
   }

   if(type == "DISPLAY"){
      QList<QWidget*> ql_fields = p_fglform->formElements();
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
   freeContext(i_context);
   }

}

//------------------------------------------------------------------------------
// Method       : setFormOpts(QString type, QString attribute, bool int)
// Filename     : screenhandler.cpp
// Description  : activate input construct etc (or deactivate it)
//------------------------------------------------------------------------------
void ScreenHandler::setFormOpts(QString type, QString attribute, int value)
{
   if(value < 0)
      return;

   Fgl::Context *context = getCurrentContext();

   if(type == "MENU"){
   }

   if(type == "DISPLAY"){
   }

   if(type == "INPUT"){
      context->options[attribute] = value;
   }

   if(type == "CONSTRUCT"){
      context->options[attribute] = value;
   }

   if(type == "DISPLAYARRAY"){
      QList<QWidget*> ql_fields = p_fglform->formElements();
      for(int i=0; i<ql_fields.size(); i++){
         QWidget *widget = (QWidget*) ql_fields.at(i);

         if(widget->isEnabled()){
            if(TableView *tableView = qobject_cast<TableView *> (ql_fields.at(i))){
               if(attribute == "ARRCOUNT"){
                  tableView->setArrCount(value);
               }

               if(attribute == "ARRVARIABLES"){
               }
            }
         }
      }
   }

   if(type == "INPUTARRAY"){
      QList<QWidget*> ql_fields = p_fglform->formElements();
      for(int i=0; i<ql_fields.size(); i++){
         QWidget *widget = (QWidget*) ql_fields.at(i);

         if(widget->isEnabled()){
            if(TableView *tableView = qobject_cast<TableView *> (ql_fields.at(i))){
               if(attribute == "ARRCOUNT"){
                  tableView->setArrCount(value);
               }

               if(attribute == "ARRVARIABLES"){
               }

               if(attribute == "MAXARRSIZE"){
                  tableView->setMaxArrSize(value);
               }

               if(attribute == "WITHOUT_DEFAULTS"){
               }

               if(attribute == "ALLOWINSERT"){

               }

               if(attribute == "ALLOWELETE"){
               }

               if(attribute == "NONEWLINES"){
               }

               if(attribute == "WRAP"){
               }
            }
         }
      }
   }
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


   p_fglform->context = getCurrentContext();

   if(b_newForm && p_fglform->dialog () == NULL){
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
   p_fglform->raise();

   p_fglform->checkState();
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

   int i_Frm = getCurrForm();

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
         QList<QWidget*> ql_fields = p_fglform->formElements();
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
      QList<QWidget*> ql_fields = p_fglform->formElements();
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
      QList<QWidget*> ql_fields = p_fglform->formElements();
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
// Description  : displays error in message line
//------------------------------------------------------------------------------
void ScreenHandler::displayError(QString text)
{

   if(p_fglform == NULL)
      return;

   StatusBar *statusBar = (StatusBar*) p_fglform->statusBar();

   statusBar->displayError(text);
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
         delete ql_fglForms.takeAt(i);
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
void ScreenHandler::setKeyLabel(int dialog, QString label, QString text)
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


   createActionMenuButton(QString::number(dialog), text, label);

}

//------------------------------------------------------------------------------
// Method       : setScreenRecordEnabled(QStringList qsl_tabNames, bool enable, bool input)
// Filename     : screenhandler.cpp
// Description  : activates table on screen forms
//------------------------------------------------------------------------------
void ScreenHandler::setScreenRecordEnabled(QString fieldName, bool enable, bool input)
{
   QString tabName;
   int index = fieldName.indexOf(".");
   if(index >= 0){
      tabName.append(fieldName.mid(0,index));
   }

   QList<QWidget*> ql_fields = p_fglform->formElements();
   //QList<QWidget*> ql_fields = p_fglform->ql_formFields;
   for(int k=0; k<ql_fields.size(); k++){
      if(TableView *tableView = qobject_cast<TableView *> (ql_fields.at(k))){

         if(tableView->tabName == tabName){
            tableView->setInputEnabled(input);
            tableView->setEnabled(enable);
            if(enable){
               if(!input){
                  tableView->selectRow(0);
               }
               else{
                  QModelIndex index = tableView->model()->index(0, 0, QModelIndex());
                  if(index.isValid()){
                     tableView->selectionModel()->setCurrentIndex(index, QItemSelectionModel::NoUpdate);
                     //tableView->edit(index);
                  }
               }
            }
            return;
         }
      }
      else{
         if(Matrix *matrix = qobject_cast<Matrix *> (ql_fields.at(k))){
            QList<Fgl::Link> ql_links = p_fglform->recordView[tabName];
            for(int l=0; l<ql_links.count(); l++){
               Fgl::Link link = ql_links.at(l);
               if(link.fieldIdRef == matrix->property("fieldId").toInt()){
                     matrix->setInputEnabled(input);
                     matrix->setEnabled(enable);
               }
            }
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

      QList<QWidget*> ql_fields = p_fglform->formElements();
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
               int rowCount = table->rowCount(QModelIndex());
               int row = 0;

               for(int i=0; i<qsl_arrayValues.count(); i+=colCount){
                  if(i+colCount<=qsl_arrayValues.count()){
                     for(int j=0; j<colCount; j++){
                        // if table has not enough rows add one
                        if(table->rowCount(QModelIndex()) < row+1){
                           table->insertRows(row, 1, QModelIndex());
                        }

                        QModelIndex index = table->index(row, j);
                        table->setData(index, qsl_arrayValues.at(i+j), Qt::EditRole);
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
      QList<QWidget*> ql_fields = p_fglform->formElements();
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

   QList<QWidget*> ql_fields = p_fglform->formElements();
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

   QList<QWidget*> ql_fields = p_fglform->formElements();
   for(int i=0; i<ql_fields.size(); i++){
      if(TableView *tableView = qobject_cast<TableView *> (ql_fields.at(i))){
         if(tableView->isEnabled()){
            QModelIndex index = tableView->currentIndex();
            QModelIndex newIndex = tableView->model()->index(line-1, index.column(), QModelIndex());
            if(newIndex.isValid()){
               tableView->selectionModel()->setCurrentIndex(newIndex, QItemSelectionModel::NoUpdate);
            }
            return;
         }
      }
   }
}

void ScreenHandler::setScrLine(int line)
{
   if(p_fglform == NULL)
      return;

   QList<QWidget*> ql_fields = p_fglform->formElements();
   for(int i=0; i<ql_fields.size(); i++){
      if(TableView *tableView = qobject_cast<TableView *> (ql_fields.at(i))){
         if(tableView->isEnabled()){
            QModelIndex index = tableView->currentIndex();
            QModelIndex newIndex = tableView->model()->index(line-1, index.column(), QModelIndex());
            if(newIndex.isValid()){
               tableView->selectionModel()->setCurrentIndex(newIndex, QItemSelectionModel::NoUpdate);
            }
            return;
         }
      }
   }
}

Fgl::Context* ScreenHandler::getContext(int i_context)
{
   int contextCount = contexts.count()-1;

   for(int i=contextCount; i<i_context; i++){
      contexts << new Fgl::Context;
   }

   return contexts.at(i_context);

}

Fgl::Context* ScreenHandler::getCurrentContext()
{
   if(contexts.count() > 0){
      return contexts.at(contexts.count()-1);
   }

   return NULL;

}

void ScreenHandler::freeContext(int i_context)
{
   int contextCount = contexts.count()-1;
   if(contextCount >= i_context)
      contexts.removeAt(i_context);

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
   QStringList dbPaths;

   if(qh_env["DBPATH"].isEmpty()) return;
   QString fullDBPath = qh_env["DBPATH"];

//set the separator depending on the OS

QChar sep;
bool windows = false;
#ifdef __WIN32__
sep = QChar(';');
windows = true;
#else
sep = QChar(':');
#endif

   int s = fullDBPath.count(sep);

   if(s > 0 ){
      dbPaths = qh_env["DBPATH"].split(sep);
   }
   else{
      // we assume theres only one Path in there
      dbPaths << qh_env["DBPATH"];
   }

   for(int i=0; i<dbPaths.size(); i++){
      //Add Search Path for Pics
      QDir picPath = QDir(dbPaths.at(i));
      picPath.cd("pics");
      QDir imgPath = QDir(dbPaths.at(i));
      imgPath.cd("images");
//      QString picPath = dbPaths.at(i) + QString("%1pics").arg(sep2);
//      QString imgPath = dbPaths.at(i) + QString("%1images").arg(sep2);

      //Check if its Path is already search path
      QStringList searchPaths = QDir::searchPaths("pics");
      if(!searchPaths.contains(picPath.absolutePath())){
         QDir::addSearchPath("pics", picPath.absolutePath());
      }
      if(!searchPaths.contains(imgPath.absolutePath())){
         QDir::addSearchPath("pics", imgPath.absolutePath());
      }
   }
}

void ScreenHandler::checkFields()
{
   if(p_fglform == NULL)
      return;

   bool enable = (p_fglform->state() != Fgl::CONSTRUCT);

   QList<QWidget*> ql_fields = p_fglform->formElements();
   for(int i=0; i<ql_fields.size(); i++){
      QWidget *widget = ql_fields.at(i);

      //switch(widget->sqlType()){
      //}
   }
}

