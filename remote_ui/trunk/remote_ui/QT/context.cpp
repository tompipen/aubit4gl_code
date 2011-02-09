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

         connect(tableView->selectionModel(), SIGNAL(currentRowChanged (const QModelIndex&, const QModelIndex&)), 
                 this, SLOT(screenRecordRowChanged(const QModelIndex&, const QModelIndex&)));

         connect(tableView->selectionModel(), SIGNAL(currentColumnChanged ( const QModelIndex&, const QModelIndex&)), 
                 this, SLOT(screenRecordColumnChanged(const QModelIndex&, const QModelIndex&)));

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
            if(current.row()+1 > tableView->arrCount()){
               setOption("ARRCOUNT", current.row()+1);
            }
            else{
               setOption("ARRCOUNT", tableView->arrCount());
            }
         }
      }
   }

   setRowChanged();
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
            fieldValues << tableView->model()->data(currIndex).toString();
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

   rowChangedCnt++;
   if(rowChangedCnt == ql_fieldList.count()){
      
      Fgl::Event event;
      event.type = Fgl::AFTER_ROW_EVENT;
      //emit fieldEvent(event);
      rowChangedCnt=0;
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
}

void Context::checkOptions()
{
MainFrame::vdcdebug("Context","checkOptions", "");

   QStringList qsl_keys = qh_options.keys();

   for(int i=0; i<qsl_keys.count(); i++){
      QString key = qsl_keys.at(i);

      if(key == "ARRCOUNT"){
         //return;
         for(int i=0; i<ql_fieldList.count(); i++){
            if(TableView *tableView = qobject_cast<TableView *> (ql_fieldList.at(i))){
               tableView->setArrCount(qh_options[key]);
               QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (tableView->model());
               TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

               if(qh_options[key] > table->rowCount(QModelIndex()))
                  table->insertRows(table->rowCount(QModelIndex()), (qh_options[key]-table->rowCount(QModelIndex())), QModelIndex());

               if(qh_options[key] < table->rowCount(QModelIndex()))
                  table->removeRows(table->rowCount(QModelIndex()), (table->rowCount(QModelIndex())-qh_options[key]), QModelIndex());
            }
         }
      }

      if(key == "MAXARRSIZE"){
         for(int i=0; i<ql_fieldList.count(); i++){
            if(TableView *tableView = qobject_cast<TableView *> (ql_fieldList.at(i))){
               tableView->setMaxArrSize(qh_options[key]);
            }
         }
      }
   }

}

