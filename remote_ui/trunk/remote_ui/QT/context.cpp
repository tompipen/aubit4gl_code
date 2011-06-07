#include <QDebug>
#include <context.h>
#include <models/vwidgets.h>
#include <models/table.h>
#include <mainframe.h>

Context::Context(QObject *parent) : QObject(parent)
{
MainFrame::vdcdebug("Context","Context", "QObject *parent");
   this->rowChangedCnt = 0;
   this->fgl_state = Fgl::IDLE;

   sendBeforeEvent();
}

Context::Context(Fgl::State state, QObject *parent) : QObject(parent)
{
MainFrame::vdcdebug("Context","Context", "Fgl");
   this->rowChangedCnt = 0;
   this->fgl_state = state;

   sendBeforeEvent();
}

Context::~Context()
{
MainFrame::vdcdebug("Context","~Context", "");
   return;
   for(int i=0; i<ql_fieldList.count(); i++){
      QWidget *field = ql_fieldList.at(i);
      field->blockSignals(true);
      if(LineEditDelegate *de = qobject_cast<LineEditDelegate *> (field)){
         TableView *tableView = (TableView*) de->parent();
         tableView->setEnabled(false);
      }
      else{

         //field->setEnabled(false);

         switch(fgl_state){
            case Fgl::INPUT:
               break;
            case Fgl::CONSTRUCT:
               if(LineEdit *lineEdit = qobject_cast<LineEdit *> (field)){
                  lineEdit->setMaxLength(lineEdit->w);
                  lineEdit->setValidator(lineEdit->getValidator());
                  lineEdit->setInputMask(lineEdit->picture());
               }

               break;
            default:
               break;
         }
      }
      field->blockSignals(false);
   }

   sendAfterEvent();
}

void Context::sendBeforeEvent()
{
MainFrame::vdcdebug("Context","sendBeforeEvent", "");

   Fgl::Event event;

   switch(fgl_state){
      case Fgl::MENU:
         event.type = Fgl::BEFORE_MENU_EVENT;
         emit fieldEvent(event);
         break;
      case Fgl::INPUT:
         event.type = Fgl::BEFORE_INPUT_EVENT;
         emit fieldEvent(event);
         break;
      case Fgl::CONSTRUCT:
         event.type = Fgl::BEFORE_CONSTRUCT_EVENT;
         emit fieldEvent(event);
         break;
      case Fgl::DISPLAYARRAY:
         event.type = Fgl::BEFORE_DISPLAY_EVENT;
         emit fieldEvent(event);
         break;
      case Fgl::INPUTARRAY:
         event.type = Fgl::BEFORE_INPUT_EVENT;
         emit fieldEvent(event);
         break;

      default: break;
   }


}

void Context::sendAfterEvent()
{
MainFrame::vdcdebug("Context","sendAfterEvent", "");
   return;

   Fgl::Event event;

   switch(fgl_state){
      case Fgl::MENU:
         event.type = Fgl::AFTER_MENU_EVENT;
         emit fieldEvent(event);
         break;
      case Fgl::INPUT:
         event.type = Fgl::AFTER_INPUT_EVENT;
         emit fieldEvent(event);
         break;
      case Fgl::CONSTRUCT:
         event.type = Fgl::AFTER_CONSTRUCT_EVENT;
         emit fieldEvent(event);
         break;
      case Fgl::DISPLAYARRAY:
         event.type = Fgl::AFTER_DISPLAY_EVENT;
         emit fieldEvent(event);
         break;
      case Fgl::INPUTARRAY:
         event.type = Fgl::AFTER_INPUT_EVENT;
         emit fieldEvent(event);
         break;

      default: break;
   }
}

void Context::addField(QWidget *field)
{
MainFrame::vdcdebug("Context","addField", "QWidget *field");

   if(!ql_fieldList.contains(field)){
      ql_fieldList << field;

      field->setEnabled(true);

      // INPUT || CONSTRUCT for TABLE // MATRIX (just one row)
     // if(TableView *tableView = qobject_cast<TableView *> (field)){
         //TODO
     // }
     // else{

         if(LineEditDelegate *de = qobject_cast<LineEditDelegate *> (field)){
            TableView *tableView = (TableView*) de->parent();
            tableView->setEnabled(true);
            ql_fieldList << field;
         }
//         else{
            /*
            if(ql_fieldList.count() == 1)
               field->setFocus();
               */


            if(!qh_options["WITHOUT_DEFAULTS"]){
               WidgetHelper::setDefaultFieldText(field);
            }

            switch(fgl_state){
               case Fgl::INPUT:
                  break;
               case Fgl::CONSTRUCT:
                  if(LineEdit *lineEdit = qobject_cast<LineEdit *> (field)){
                     lineEdit->setMaxLength(32767);
                     //lineEdit->setValidator(NULL);
                     lineEdit->setInputMask(NULL);
                  }

                  break;
               default:
                  break;
          //  }
         //}
      }
   }
}

void Context::addScreenRecord(QWidget *screenRec, bool input)
{
MainFrame::vdcdebug("Context","addScreenRecord", "QWidget *screenRec, bool input");

   if(!ql_fieldList.contains(screenRec)){
      ql_fieldList << screenRec;

      if(TableView *tableView = qobject_cast<TableView *> (screenRec)){

          connect(tableView->selectionModel(), SIGNAL(currentRowChanged (const QModelIndex&, const QModelIndex&)),
                  this, SLOT(screenRecordRowChanged(const QModelIndex&, const QModelIndex&)));

          connect(tableView->selectionModel(), SIGNAL(currentColumnChanged ( const QModelIndex&, const QModelIndex&)),
                  this, SLOT(screenRecordColumnChanged(const QModelIndex&, const QModelIndex&)));

         tableView->setInputEnabled(input);
         tableView->setEnabled(true);
         if(ql_fieldList.count() == 1){
            if(!input){
               tableView->selectRow(0);
            }
            else{
               tableView->setCurrentField(1,1);
            }
         }

         setOption("ARRLINE", 0);
         setOption("SCRLINE", 0);



         QStringList qsl_keys = qh_options.keys();

      }
   }
}

void Context::screenRecordRowChanged(const QModelIndex & current, const QModelIndex & previous)
{
MainFrame::vdcdebug("Context","screenRecordRowChanged", "const QModelIndex & current, const QModelIndex & previous");

   Q_UNUSED(previous);

   if(fgl_state != Fgl::INPUTARRAY && fgl_state != Fgl::DISPLAYARRAY)
      return;


   for(int i=0; i<ql_fieldList.count(); i++){
      if(TableView *tableView = qobject_cast<TableView *> (ql_fieldList.at(i))){
         if(tableView->model() == current.model()){
            QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (tableView->model());
            int arrLine = proxyModel->mapToSource(tableView->currentIndex()).row();
            int scrLine = tableView->currentIndex().row();

            setOption("SCRLINE", scrLine);
            setOption("ARRLINE", arrLine);

            /*
            if(fgl_state == Fgl::INPUTARRAY){
               QModelIndex index = tableView->model()->index(current.row(), current.column());
               tableView->selectionModel()->select(index, QItemSelectionModel::Select);
            }
            else{
               QModelIndex index = tableView->model()->index(current.row(), current.column());
               tableView->setCurrentIndex(index);
            }
            */

            if(this->state() == Fgl::INPUTARRAY){
               if(current.row()+1 > tableView->arrCount() || (previous.row() < 0 && current.row() == 0)){
                  setOption("ARRCOUNT", current.row()+1);
               }
               /*
               else{
                  setOption("ARRCOUNT", tableView->arrCount());
               }
               */
            }

         }
      }
   }

   //setRowChanged();
}

void Context::screenRecordColumnChanged(const QModelIndex & current, const QModelIndex & previous)
{
MainFrame::vdcdebug("Context","screenRecordColumnChanged", "const QModelIndex & current, const QModelIndex & previous");
   Q_UNUSED(previous);
   Q_UNUSED(current);
}

QStringList Context::getScreenRecordValues(int row)
{
MainFrame::vdcdebug("Context","getScreenRecordValues", "int row");
   QStringList fieldValues;

   for(int i=0; i<ql_fieldList.count(); i++){

      if(TableView *tableView = qobject_cast<TableView *> (ql_fieldList.at(i))){
         for(int j=0; j<tableView->model()->columnCount(); j++){
            QModelIndex currIndex = tableView->model()->index(row, j);
            if(LineEditDelegate *dele = qobject_cast<LineEditDelegate *> (tableView->itemDelegateForColumn(j))){
               if(LineEdit *widget = qobject_cast<LineEdit *> (dele->qw_editor)){
                   if(widget->sqlType().contains("FLOAT") || widget->sqlType().contains("DECIMAL"))
                   {
                      fieldValues << tableView->model()->data(currIndex).toString().replace(",",".");
                  }
                  else
                  {
                      fieldValues << tableView->model()->data(currIndex).toString();
                  }
               }
               else{
                   fieldValues << WidgetHelper::fieldText(dele->qw_editor);
               }
            }

         }
      }
      else{
         fieldValues << WidgetHelper::fieldText(ql_fieldList.at(i));
      }
   }

   return fieldValues;
}

void Context::setRowChanged()
{
MainFrame::vdcdebug("Context","setRowChanged", "");

   if(this->state() == Fgl::INPUTARRAY){

      for(int i=0; i<ql_fieldList.count(); i++){
         if(TableView *tableView = qobject_cast<TableView *> (ql_fieldList.at(i))){
             this->setOption("ARRCOUNT", tableView->arrCount());
         }
      }
   }
}

QList<QWidget*> Context::fieldList()
{
MainFrame::vdcdebug("Context","fieldList", "");
   return ql_fieldList;
}

void Context::setOption(QString name, int value)
{
MainFrame::vdcdebug("Context","setOption", "QString name, int value");
   qh_options[name] = value;
   checkOptions();

   if(name == "ARRCOUNT"){
      //return;
      for(int i=0; i<ql_fieldList.count(); i++){
         if(TableView *tableView = qobject_cast<TableView *> (ql_fieldList.at(i))){
            tableView->setArrCount(qh_options[name]);
         }
      }
      return;
   }
   if(name == "MAXARRSIZE"){
      for(int i=0; i<ql_fieldList.count(); i++){
         if(TableView *tableView = qobject_cast<TableView *> (ql_fieldList.at(i))){
            tableView->setMaxArrSize(qh_options[name]);
         }
      }
   }
}

void Context::checkOptions()
{
MainFrame::vdcdebug("Context","checkOptions", "");

   QStringList qsl_keys = qh_options.keys();

   for(int i=0; i<qsl_keys.count(); i++){
      QString key = qsl_keys.at(i);

      if(key == "MAXARRSIZE"){
         for(int i=0; i<ql_fieldList.count(); i++){
            if(TableView *tableView = qobject_cast<TableView *> (ql_fieldList.at(i))){
               tableView->setMaxArrSize(qh_options[key]);
            }
         }
      }

      if(key == "ARRCOUNT" && this->state() == Fgl::DISPLAYARRAY){
         //return;
         for(int i=0; i<ql_fieldList.count(); i++){
            if(TableView *tableView = qobject_cast<TableView *> (ql_fieldList.at(i))){
               tableView->setArrCount(qh_options[key]);
            }
         }
         return;
      }
   }

}

