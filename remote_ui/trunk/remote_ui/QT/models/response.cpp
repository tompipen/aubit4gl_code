//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : response.cpp
// Description  : contains class definition for the RingMenu
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
#include <QModelIndex>

#include "response.h"
#include "vwidgets.h"
#include "table.h"

Response::Response(QString id, FglForm* p_currForm, bool cursorPos) : QDomDocument()
{
  
   this->p_currForm = p_currForm;

   this->showCursorPos = cursorPos;

   if(id.isEmpty()){
      qDebug() << "Error Occured";
      return;
   }

   if(id == "CANCEL" || id == "Esc")
      id = "INTERRUPT";

   checkOnActionEvents(&id);
   
   this->appendChild(responseElement = this->createElement("TRIGGERED"));
   responseElement.setAttribute("ID", id);

   QWidget *focusWidget = p_currForm->focusWidget();
   QString colName = WidgetHelper::getWidgetColName(focusWidget);

   if(!colName.isNull() && !colName.isEmpty() &&  (p_currForm->dialog() == NULL && (p_currForm->menu() == NULL || !p_currForm->menu()->isEnabled()))){
      responseElement.setAttribute("INFIELD", colName);
   }

   if(p_currForm->input() || p_currForm->construct()){
      addSyncValues();
   }
   else{
      if(p_currForm->inputArray() || p_currForm->displayArray()){
         addScreenRecSyncValues();
      }
   }

   /*
   if(p_currForm->dialog() == NULL && 
      (p_currForm->menu() == NULL || !p_currForm->menu()->isEnabled())){
      if(p_currForm->input() || p_currForm->construct()){
         addSyncValues();
      }

      if(p_currForm->screenRecord()){

         for(int i=0; i<p_currForm->formElements().size(); i++){
            if(TableView *tableView = qobject_cast<TableView *> (p_currForm->formElements().at(i))){
               if(tableView->isEnabled()){
                  addScreenRecSyncValues(tableView);
               }
            }
            if(Matrix *matrix = qobject_cast<Matrix *> (p_currForm->formElements().at(i))){
               if(matrix->isEnabled()){
                  addScreenRecSyncValues(matrix);
               }
            }
         }
      }
   }
   */
}

void Response::addSyncValues()
{

   QDomElement syncValuesElement = this->createElement("SYNCVALUES");
   responseElement.appendChild(syncValuesElement);

   for(int i=0; i<p_currForm->context->fieldList().count(); i++){
      QDomElement syncValueElement = this->createElement("SYNCVALUE");
      QWidget *widget = p_currForm->context->fieldList().at(i);

      QString text;
      if(LineEditDelegate *de = qobject_cast<LineEditDelegate *> (widget)){
         // TODO
         syncValueElement.setAttribute("FIELDNAME", de->objectName());
         //syncValueElement.setAttribute("TOUCHED", 0);
      }
      else{
         syncValueElement.setAttribute("FIELDNAME", widget->objectName());
         //syncValueElement.setAttribute("TOUCHED", widget->property("touched").toInt());
         text = WidgetHelper::fieldText(widget);
      }

      if(!text.isEmpty()){
         QDomText domText = this->createTextNode(text);
         syncValueElement.appendChild(domText);
      }
      syncValuesElement.appendChild(syncValueElement);

   }
   return;

   for(int j=0; j<p_currForm->context->fieldList().count(); j++){
      for(int i=0; i<p_currForm->ql_formFields.size(); i++){
         QWidget *widget = (QWidget*) p_currForm->ql_formFields.at(i);

         QDomElement syncValueElement = this->createElement("SYNCVALUE");
         if(widget == p_currForm->context->fieldList().at(j)){
            
            syncValueElement.setAttribute("FIELDNAME", widget->accessibleName());
//            syncValueElement.setAttribute("TOUCHED", widget->property("touched").toInt());
            QString text = WidgetHelper::fieldText(widget);

            if(!text.isEmpty()){
               QDomText domText = this->createTextNode(text);
               syncValueElement.appendChild(domText);
            }
            syncValuesElement.appendChild(syncValueElement);
         }

      }
   }
}

void Response::addScreenRecSyncValues(TableView *p_screenRecord)
{


   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (p_screenRecord->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

   int arrCount = p_screenRecord->arrCount();
   if(arrCount <= 0) arrCount = 1;
   

   responseElement.setAttribute("ARRCOUNT", arrCount);

   int scrLine = p_screenRecord->scrLine();
   if(scrLine <= 0) scrLine = 1;

   int arrLine = p_screenRecord->scrLine();
   if(arrLine <= 0) arrLine = 1;

   responseElement.setAttribute("SCRLINE", scrLine);

   responseElement.setAttribute("ARRLINE", arrLine);

   if(!p_currForm->inputArray())
      return;

   QDomElement syncRowsElement = this->createElement("SYNCROWS");
   responseElement.appendChild(syncRowsElement);

   for(int i=0; i<arrCount; i++){
      QDomElement syncRowElement = this->createElement("ROW");
      syncRowElement.setAttribute("SUBSCRIPT", QString::number(i+1));
      syncRowsElement.appendChild(syncRowElement);
      QDomElement syncValuesElement = this->createElement("SYNCVALUES");
      syncRowElement.appendChild(syncValuesElement);
      for(int j=0; j<p_screenRecord->model()->columnCount(); j++){
         QModelIndex currIndex = p_screenRecord->model()->index(i, j);
         QDomElement syncValueElement = this->createElement("SYNCVALUE");
         QString text = p_screenRecord->model()->data(currIndex).toString();
         if(!text.isEmpty()){
            QDomText syncValueText = this->createTextNode(text);
            syncValueElement.appendChild(syncValueText);
         }
            syncValuesElement.appendChild(syncValueElement);
      }
   }
}

void Response::addScreenRecSyncValues()
{

   int arrCount = p_currForm->context->getOption("ARRCOUNT")+1;
   if(arrCount <= 0) arrCount = 1;

   responseElement.setAttribute("ARRCOUNT", arrCount);

   int scrLine = p_currForm->context->getOption("SCRLINE")+1;
   if(scrLine <= 0) scrLine = 1;

   int arrLine = p_currForm->context->getOption("ARRLINE")+1;
   if(arrLine <= 0) arrLine = 1;

   responseElement.setAttribute("SCRLINE", scrLine);

   responseElement.setAttribute("ARRLINE", arrLine);

   if(p_currForm->context->state() != Fgl::INPUTARRAY)
      return;

   QDomElement syncRowsElement = this->createElement("SYNCROWS");
   responseElement.appendChild(syncRowsElement);

   for(int i=0; i<arrCount; i++){
      QDomElement syncRowElement = this->createElement("ROW");
      syncRowElement.setAttribute("SUBSCRIPT", QString::number(i+1));
      syncRowsElement.appendChild(syncRowElement);
      QDomElement syncValuesElement = this->createElement("SYNCVALUES");
      syncRowElement.appendChild(syncValuesElement);
      QStringList values = p_currForm->context->getScreenRecordValues(i);
      for(int j=0; j<values.count(); j++){
         QDomElement syncValueElement = this->createElement("SYNCVALUE");
         QString text = values.at(j);
         if(!text.isEmpty()){
            QDomText syncValueText = this->createTextNode(text);
            syncValueElement.appendChild(syncValueText);
         }
         syncValuesElement.appendChild(syncValueElement);
      }
   }
}

bool Response::checkOnActionEvents(QString *id){
   return false;
}
