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
#include "mainframe.h"
#include "vwidgets.h"
#include "table.h"
#include "include/fgl.h"



Response::Response(Fgl::Event id, FglForm* p_currForm, bool cursorPos) : QDomDocument()
{
MainFrame::vdcdebug("Response","Response", "QString id, FglForm* p_currForm, bool cursorPos");
  
   this->p_currForm = p_currForm;

   this->showCursorPos = cursorPos;

for(int i = 0; i<id.id.size(); i++)
{
    if(id.id.at(i).isLetter() || id.id.at(i).isDigit())
    {
        continue;
    }
    else
    {
        qFatal("Invalid TRIGGERED ID");
    }
}
   if(id.id.isEmpty()){
      qFatal("TRIGGERED ID is empty");
      return;
   }

   QList<Fgl::Event> ql_events = p_currForm->ql_contextEvents.last();
   Fgl::Event currEvent;


   //Funktion nicht genau bekannt, deaktivieren

   /*for(int i=0; i<ql_events.size(); i++){
      Fgl::Event ev = ql_events.at(i);
      bool ok = false;
      int i_id = id.toInt(&ok);
      if(ok){
         if(ev.id == i_id){
            currEvent = ev;
            break;
         }
      }
   }*/


   for(int i=0; i<ql_events.size(); i++)
   {
       Fgl::Event ev = ql_events.at(i);
       //Failsafe das wenn die actions wirklich in die loop gehängt werden auch ausgewählt wird
       if(id.id == "ACCEPT")
       {
           currEvent = id;
           break;
       }
       if(id.id == "INTERRUPT")
       {
           currEvent = id;
           break;
       }
       if(ev.id == id.id)
       {

           currEvent = id;
           if(id.attribute.isEmpty())
           {
               currEvent.attribute = ev.attribute;

           }

           if((ev.type == Fgl::BEFORE_FIELD_EVENT || ev.type == Fgl::BEFORE_ROW_EVENT) && (p_currForm->state() == Fgl::INPUTARRAY || p_currForm->state() == Fgl::DISPLAYARRAY))
           {
               p_currForm->context->refreshInputArrayAttributes();
           }
           break;
       }

       //Wenn das Event nicht gefunden wurde, brech hart ab um den Fehler aufzudecken.
       if((i+1) == ql_events.size())
       {
           qWarning("Event not found");
       }
   }

   this->appendChild(responseElement = this->createElement("TRIGGERED"));
   responseElement.setAttribute("ID", currEvent.id);

   responseElement.setAttribute("BUFFERTOUCHED", p_currForm->bufferTouched());
   responseElement.setAttribute("LASTCURSOR", p_currForm->lastCursor());

   if(currEvent.type == Fgl::AFTER_FIELD_EVENT)
       p_currForm->setBufferNotTouched();

   //focusWidget ist leer, da wir hier im disabled zustand sind. in getWidgetColName wird auf TV geprüft, also können
   //wir currentWidget aus p_fglform verwenden.
   //QWidget *focusWidget = p_currForm->focusWidget();
   QString colName = "";
   if(id.field.size() > 0)
   {
       colName = id.field;
   }
   else
   {
       colName = WidgetHelper::getWidgetColName(p_currForm->currentField());
   }
   if(!colName.isNull() && !colName.isEmpty() &&  (p_currForm->dialog() == NULL && (p_currForm->menu() == NULL || !p_currForm->menu()->isEnabled()))){
      responseElement.setAttribute("INFIELD", colName);
   }

   if(p_currForm->inputArray() || p_currForm->displayArray()){
      int arrCount = p_currForm->context->getOption("ARRCOUNT");
      if(arrCount <= 0) arrCount = 1;

      responseElement.setAttribute("ARRCOUNT", arrCount);

      int scrLine = p_currForm->context->getOption("SCRLINE")+1;
      if(scrLine <= 0) scrLine = 1;

      int arrLine = p_currForm->context->getOption("ARRLINE")+1;
      if(arrLine <= 0) arrLine = 1;




      responseElement.setAttribute("SCRLINE", scrLine);

      responseElement.setAttribute("ARRLINE", arrLine);
   }

   //if(!(currEvent.type == Fgl::ONKEY_EVENT ||
   //   currEvent.type == Fgl::ONACTION_EVENT)){
         if((p_currForm->input() || p_currForm->construct()) && p_currForm->b_svs){
            addSyncValues();
         }
         else{
            if((p_currForm->inputArray() || p_currForm->displayArray()) && p_currForm->b_svs){
               addScreenRecSyncValues(id.id);
            }
         }
   //}

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
MainFrame::vdcdebug("Response","addSyncValues", "");

   QDomElement syncValuesElement = this->createElement("SVS");
   responseElement.appendChild(syncValuesElement);

   for(int i=0; i<p_currForm->context->fieldList().count(); i++){
      QDomElement syncValueElement = this->createElement("SV");
      QWidget *widget = p_currForm->context->fieldList().at(i);

      QString text;
      if(LineEditDelegate *de = qobject_cast<LineEditDelegate *> (widget)){
         // TODO
         syncValueElement.setAttribute("FN", de->objectName());
         syncValueElement.setAttribute("T", 0);
      }
      else{
         syncValueElement.setAttribute("FN", widget->objectName());
         syncValueElement.setAttribute("T", widget->property("touched").toInt());
         text = WidgetHelper::fieldText(widget);
      }

      if(!text.isEmpty()){
         text.replace("\n", "&#x0A;");
         QDomText domText = this->createTextNode(text);
         syncValueElement.appendChild(domText);
      }
      syncValuesElement.appendChild(syncValueElement);

   }
}

void Response::addScreenRecSyncValues(TableView *p_screenRecord)
{
MainFrame::vdcdebug("Response","addScreenRecSyncValues", "TableView *p_screenRecord");


   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (p_screenRecord->model());

   int arrCount = p_screenRecord->arrCount();
   if(arrCount <= 0) arrCount = 1;
   
   responseElement.setAttribute("ARRCOUNT", arrCount);

   int scrLine = p_screenRecord->currentIndex().row()+1;

   int arrLine = proxyModel->mapFromSource(p_screenRecord->currentIndex()).row()+1;

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
      QDomElement syncValuesElement = this->createElement("SYS");
      syncRowElement.appendChild(syncValuesElement);
      for(int j=0; j<p_screenRecord->model()->columnCount(); j++){
         QModelIndex currIndex = p_screenRecord->model()->index(i, j);
         QDomElement syncValueElement = this->createElement("SV");
         QString text = p_screenRecord->model()->data(currIndex).toString();
         if(!text.isEmpty()){
            QDomText syncValueText = this->createTextNode(text);
            syncValueElement.appendChild(syncValueText);
         }
            syncValuesElement.appendChild(syncValueElement);
      }
   }
}

void Response::addScreenRecSyncValues(QString id)
{
MainFrame::vdcdebug("Response","addScreenRecSyncValues", "");

   int arrCount = p_currForm->context->getOption("ARRCOUNT");
   //if(arrCount <= 0) arrCount = 1;

   //responseElement.setAttribute("ARRCOUNT", arrCount);

   int scrLine = p_currForm->context->getOption("SCRLINE")+1;
   if(scrLine <= 0) scrLine = 1;

   int arrLine = p_currForm->context->getOption("ARRLINE")+1;
   if(arrLine <= 0) arrLine = 1;

   //responseElement.setAttribute("SCRLINE", scrLine);

   //responseElement.setAttribute("ARRLINE", arrLine);

   if(p_currForm->context->state() != Fgl::INPUTARRAY)
      return;

   QDomElement syncRowsElement = this->createElement("SYNCROWS");
   responseElement.appendChild(syncRowsElement);
   if(id == "ACCEPT" || id == "INTERRUPT")
   {

   for(int i=0; i<arrCount; i++){
      QDomElement syncRowElement = this->createElement("ROW");
      syncRowElement.setAttribute("SUBSCRIPT", QString::number(i+1));
      syncRowsElement.appendChild(syncRowElement);
      QDomElement syncValuesElement = this->createElement("SVS");
      syncRowElement.appendChild(syncValuesElement);
      QStringList values = p_currForm->context->getScreenRecordValues(i);
      for(int j=0; j<values.count(); j++){
         QDomElement syncValueElement = this->createElement("SV");
         QString text = values.at(j);
         if(!text.isEmpty()){
            QDomText syncValueText = this->createTextNode(text);
            syncValueElement.appendChild(syncValueText);
         }
         syncValuesElement.appendChild(syncValueElement);
      }
   }
   } else if(p_currForm->context->arrcountchanged())
   {
       if(arrCount >= 2)
       {
           for(int i=arrCount-2; i < arrCount; i++)
           {
               QDomElement syncRowElement = this->createElement("ROW");
               syncRowElement.setAttribute("SUBSCRIPT", QString::number(i+1));
               syncRowsElement.appendChild(syncRowElement);
               QDomElement syncValuesElement = this->createElement("SVS");
               syncRowElement.appendChild(syncValuesElement);
               QStringList values = p_currForm->context->getScreenRecordValues(i);
               for(int j=0; j<values.count(); j++){
                  QDomElement syncValueElement = this->createElement("SV");
                  QString text = values.at(j);
                  if(!text.isEmpty()){
                     QDomText syncValueText = this->createTextNode(text);
                     syncValueElement.appendChild(syncValueText);
                  }
                  syncValuesElement.appendChild(syncValueElement);
               }
           }
       } else {
           QDomElement syncRowElement = this->createElement("ROW");
           syncRowElement.setAttribute("SUBSCRIPT", QString::number(arrCount+1));
           syncRowsElement.appendChild(syncRowElement);
           QDomElement syncValuesElement = this->createElement("SVS");
           syncRowElement.appendChild(syncValuesElement);
           QStringList values = p_currForm->context->getScreenRecordValues(arrCount);
           for(int j=0; j<values.count(); j++){
              QDomElement syncValueElement = this->createElement("SV");
              QString text = values.at(j);
              if(!text.isEmpty()){
                 QDomText syncValueText = this->createTextNode(text);
                 syncValueElement.appendChild(syncValueText);
              }
              syncValuesElement.appendChild(syncValueElement);
           }
       }
   }
   else
   {
       QDomElement syncRowElement = this->createElement("ROW");
       syncRowElement.setAttribute("SUBSCRIPT", QString::number(scrLine));
       syncRowsElement.appendChild(syncRowElement);
       QDomElement syncValuesElement = this->createElement("SVS");
       syncRowElement.appendChild(syncValuesElement);
       QStringList values = p_currForm->context->getScreenRecordValues(scrLine-1);
       for(int j=0; j<values.count(); j++){
          QDomElement syncValueElement = this->createElement("SV");
          QString text = values.at(j);
          if(!text.isEmpty()){
             QDomText syncValueText = this->createTextNode(text);
             syncValueElement.appendChild(syncValueText);
          }
          syncValuesElement.appendChild(syncValueElement);
       }
   }
}
