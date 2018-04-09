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
  this->qw_lastfocus = NULL;

  b_arrlinech = false;
  b_scrlinech = false;
  b_arrcountch = false;
  b_constrained = false;
  sendBeforeEvent();
}

Context::Context(Fgl::State state, QObject *parent) : QObject(parent)
{
  MainFrame::vdcdebug("Context","Context", "Fgl");
  this->rowChangedCnt = 0;
  this->fgl_state = state;
  b_arrlinech = false;
  b_scrlinech = false;
  b_arrcountch = false;
  this->qw_lastfocus = NULL;

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
                  lineEdit->resetDataType();
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

/*
void Context::restoreFieldPalette()
{
  if(ql_fieldList.size() < 1)
    {
      return;
    }

  foreach(QWidget *qw, ql_fieldList)
    {
      QPalette pal = qh_palette[qw->objectName()];
      if(pal != qw->palette())
        {
          qw->setPalette(pal);
          if(TextEdit *te = qobject_cast<TextEdit*> (qw))
            {
              te->viewport()->setPalette(pal);
            }
          if(TableView *tv = qobject_cast<TableView*> (qw))
          {
             tv->restoreViewPalette();
          }
        }
    }


}

void Context::setPaletteForWidget(QWidget *field)
{

  if(!field)
    {
      return;
    }

  qh_palette[field->objectName()] = field->palette();

  QPalette pal = field->palette();
  QPalette tmp(pal);

  tmp.setCurrentColorGroup(QPalette::Active);
  tmp.setColor(QPalette::Disabled, QPalette::WindowText, tmp.color(QPalette::WindowText));
  tmp.setColor(QPalette::Disabled, QPalette::Text, tmp.color(QPalette::Text));
  tmp.setColor(QPalette::Disabled, QPalette::Button, tmp.color(QPalette::Button));
  tmp.setColor(QPalette::Disabled, QPalette::ButtonText, tmp.color(QPalette::ButtonText));
  tmp.setColor(QPalette::Disabled, QPalette::Background, tmp.color(QPalette::Background));
  tmp.setColor(QPalette::Disabled, QPalette::Base, tmp.color(QPalette::Base));
  tmp.setColor(QPalette::Disabled, QPalette::AlternateBase, tmp.color(QPalette::AlternateBase));

  //LineEdits disable Palette is not Base, its window but the enabled is base(wtf?)
  if(LineEdit *le = qobject_cast<LineEdit*> (field))
    {
      tmp.setColor(QPalette::Disabled, QPalette::Window, tmp.color(QPalette::Base));
      tmp.setColor(QPalette::Active, QPalette::Window, tmp.color(QPalette::Base));

    }
  else
    {
      tmp.setColor(QPalette::Disabled, QPalette::Window, tmp.color(QPalette::Window));
    }

  if(TableView *tv = qobject_cast<TableView*> (field))
  {
     tv->setViewPalette();
  }

  field->setPalette(tmp);

  if(TextEdit *te = qobject_cast<TextEdit*> (field))
    {
      te->viewport()->setPalette(tmp);
    }


}
void Context::setPaletteList()
{
  if(ql_fieldList.size() < 1)
    {
      return;
    }

  foreach(QWidget *field, ql_fieldList)
    {
      setPaletteForWidget(field);
    }
}
*/
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

              //lineEdit->setValidator(NULL);
              lineEdit->setInputMask(NULL);
              lineEdit->setSqlType("CHAR");
              lineEdit->setMaxLength(32767);
            }

          break;
        default:
          break;
          //  }
          //}
        }
    }
}


void Context::refreshInputArrayAttributes()
{
    //Only Inputarray
    if(fgl_state != Fgl::INPUTARRAY && fgl_state != Fgl::DISPLAYARRAY)
        return;

    for(int i=0; i<ql_fieldList.count(); i++){

        if(TableView *tableView = qobject_cast<TableView *> (ql_fieldList.at(i))){
            this->screenRecordRowChanged(tableView->targetfield, tableView->targetfield);
            tableView->targetfield = QModelIndex();
            return;
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
          if(!input)
          {
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
            tableView->horizontalHeader()->setMovable(true);
#else
			tableView->horizontalHeader()->setSectionsMovable(true);
#endif
          }
          /*
          //set palette for inputarrays
          if(input)
          {
             setPaletteForWidget(screenRec);
             tableView->setViewPalette();
          }*/
          tableView->setEnabled(true);
          setOption("ARRLINE", 0);
          setOption("SCRLINE", 0);

          if(ql_fieldList.count() == 1){
              if(!input){
                  tableView->selectRow(0);
                }
              else{

                //  tableView->setCurrentField(1,1);
                  if(QSortFilterProxyModel *proxyModel = qobject_cast<QSortFilterProxyModel *> (tableView->model())){
                     if(TableModel *table = qobject_cast<TableModel *> (proxyModel->sourceModel())){
                         int col = 0;
                         for(int i = 0; i<table->columnCount(QModelIndex()); i++)
                         {
                             if(tableView->isReadOnlyColumn(i) || tableView->isColumnHidden(i))
                             {
                                continue;
                             }
                             else
                             {
                                col = i;
                                break;
                             }
                         }

                         tableView->setCurrentField(1,col+1);

                         QModelIndex tindex = table->index(0,col);
                         QModelIndex index = proxyModel->mapFromSource(tindex);
                         tableView->edit(index);
                       }
                }
            }




          QStringList qsl_keys = qh_options.keys();

        }
    }
}
}

void Context::screenRecordRowChanged(const QModelIndex & current, const QModelIndex & previous)
{
  MainFrame::vdcdebug("Context","screenRecordRowChanged", "const QModelIndex & current, const QModelIndex & previous");
  this->checkOptions();
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

                  if(current.row()+1 > tableView->arrCount()){// || (previous.row() < 0 && current.row() == 0)){

                      setOption("ARRCOUNT", current.row()+1);
                    }

                  /*else{
                   setOption("ARRCOUNT", tableView->model()->rowCount(QModelIndex()));
               }*/

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
              QString val;
              if(LineEditDelegate *dele = qobject_cast<LineEditDelegate *> (tableView->itemDelegateForColumn(j))){
                  Fgl::DataType sqlType = Fgl::DTYPE_CHAR;
                  QString format = "";

                    if(LineEdit *le = qobject_cast<LineEdit*> (dele->qw_editor))
                    {
                      sqlType = le->dataType();
                      format  = le->format();
                    }

                 val = tableView->model()->data(currIndex).toString();
                 fieldValues << Fgl::vdc_to_fgl(format, val, sqlType);
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
  /*if(ql_fieldList == NULL)
{
    return QList<QWidget*> ql_tmp;
}*/
    return ql_fieldList;
}

void Context::setOption(QString name, int value)
{
  MainFrame::vdcdebug("Context","setOption", "QString name, int value");


  if(name == "ARRLINE" && (value != qh_options[name]))
  {
     b_arrlinech = true;
  }


  if(name == "SCRLINE" && (value != qh_options[name]))
  {
     b_scrlinech = true;
  }

  qh_options[name] = value;
  checkOptions();




  if(name == "ARRCOUNT"){
      //return;
      for(int i=0; i<ql_fieldList.count(); i++){
          if(TableView *tableView = qobject_cast<TableView *> (ql_fieldList.at(i))){
              b_arrcountch = true;
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

      if(key == "ARRCOUNT"){
          //return;
          for(int i=0; i<ql_fieldList.count(); i++){
              if(TableView *tableView = qobject_cast<TableView *> (ql_fieldList.at(i))){
                  tableView->setArrCount(qh_options[key]);
                }
            }
        }
  }

}

void Context::setLastFocusWidget(QWidget *w)
{
  this->qw_lastfocus = w;
}

QWidget* Context::lastFocusWidget()
{
  return qw_lastfocus;
}


void Context::focusChanged()
{
    if(QObject::sender())
    {
        if(QPushButton *pe = qobject_cast<QPushButton*> (QObject::sender()))
        {
            this->setLastFocusWidget(pe);
        }
    }
}



