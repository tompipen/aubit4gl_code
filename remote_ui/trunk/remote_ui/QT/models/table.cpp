//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : table.cpp
// Description  : 
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
#include <QDebug>
#include <QHeaderView>
#include <QSortFilterProxyModel>
#include <QItemSelectionModel>
#include <QKeyEvent>
#include <QFontMetrics>
#include <QScrollBar>
#include <QSettings>

#include "mainframe.h"
#include "table.h"

TableView::TableView(QWidget *parent) : QTableView(parent)
{
MainFrame::vdcdebug("TableView","TableView", "QWidget *parent");

   this->setFocusPolicy(Qt::NoFocus);
   this->p_fglform = parent;
   i_arrCount = 0;
   i_arrLine = 0;
   i_scrLine = 0;
   i_maxArrSize = 1;
   b_ignoreFocus = false;
   b_ignoreRowChange = false;
 //  b_palette = false;
   this->setMouseTracking(true);
   const int rowHeight = fontMetrics().height() + 2;
   verticalHeader()->setDefaultSectionSize(rowHeight);
   verticalHeader()->setFocusPolicy(Qt::NoFocus);
   horizontalHeader()->setFocusPolicy(Qt::NoFocus);
   this->setDragEnabled(true);
   //Keine Auswirkung
   // setTabKeyNavigation(false);
   this->verticalHeader()->hide();
   QHeaderView *header = this->horizontalHeader();
   header->setMovable(true);
   header->setClickable(true);
   header->setSortIndicatorShown(true);
   header->setSortIndicator(0, Qt::AscendingOrder);
   header->installEventFilter(this);

   connect(this, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(accept()));
   connect(this, SIGNAL(entered(QModelIndex)), this, SLOT(setMousePos(QModelIndex)));
   QObject::connect(header, SIGNAL(sectionClicked(int)),
                    this, SLOT(sortByColumn(int)));
   connect(header, SIGNAL(sectionResized(int,int,int)), this, SLOT(updateSectionWidth(int,int,int)));

   QObject::disconnect(header, SIGNAL(sectionPressed(int)),
                       this, SLOT(selectColumn(int)));
   //Show only the Scrollbars when needed
   this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
   this->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
   this->setInputEnabled(false);
   this->setEnabled(false);
}
/*

void TableView::restoreViewPalette()
{



  if(!b_palette)
  {
     return;
  }


  this->horizontalHeader()->setPalette(this->header);
  this->verticalScrollBar()->setPalette(this->scrollbars);
  this->horizontalScrollBar()->setPalette(this->scrollbars);
  this->viewport()->setPalette(this->tableview);


  b_palette = false;
}

void TableView::setViewPalette()
{

  if(b_palette)
  {
      return;

  }

  b_palette = true;

  QPalette tablepal(this->viewport()->palette());
  QHeaderView *headerview = this->horizontalHeader();
  QPalette headerpal(headerview->palette());
  QScrollBar *verticalBar = this->verticalScrollBar();
  QScrollBar *horizontalBar = this->horizontalScrollBar();

  //verticalBar = new QScrollBar(Qt::Vertical, this);

  QPalette verticalbarpal(verticalBar->palette());

  this->tableview = tablepal;
  this->header = headerpal;
  this->scrollbars = verticalbarpal;


  //Palette for QTableView
  tablepal.setCurrentColorGroup(QPalette::Active);
  tablepal.setColor(QPalette::Disabled, QPalette::WindowText, tablepal.color(QPalette::WindowText));
  tablepal.setColor(QPalette::Disabled, QPalette::Text, tablepal.color(QPalette::Text));
  tablepal.setColor(QPalette::Disabled, QPalette::Button, tablepal.color(QPalette::Button));
  tablepal.setColor(QPalette::Disabled, QPalette::ButtonText, tablepal.color(QPalette::ButtonText));
  tablepal.setColor(QPalette::Disabled, QPalette::Background, tablepal.color(QPalette::Background));
  tablepal.setColor(QPalette::Disabled, QPalette::Base, tablepal.color(QPalette::Base));
  tablepal.setColor(QPalette::Disabled, QPalette::AlternateBase, tablepal.color(QPalette::AlternateBase));
  tablepal.setColor(QPalette::Disabled, QPalette::Window, tablepal.color(QPalette::Window));
  //Palette for HeaderView
  headerpal.setCurrentColorGroup(QPalette::Active);
  headerpal.setColor(QPalette::Disabled, QPalette::WindowText, headerpal.color(QPalette::WindowText));
  headerpal.setColor(QPalette::Disabled, QPalette::Text, headerpal.color(QPalette::Text));
  headerpal.setColor(QPalette::Disabled, QPalette::Button, headerpal.color(QPalette::Button));
  headerpal.setColor(QPalette::Disabled, QPalette::ButtonText, headerpal.color(QPalette::ButtonText));
  headerpal.setColor(QPalette::Disabled, QPalette::Background, headerpal.color(QPalette::Background));
  headerpal.setColor(QPalette::Disabled, QPalette::Base, headerpal.color(QPalette::Base));
  headerpal.setColor(QPalette::Disabled, QPalette::AlternateBase, headerpal.color(QPalette::AlternateBase));
  headerpal.setColor(QPalette::Disabled, QPalette::Window, headerpal.color(QPalette::Window));
  //Palette for Scrollbars
  verticalbarpal.setCurrentColorGroup(QPalette::Active);
  verticalbarpal.setColor(QPalette::Disabled, QPalette::WindowText, verticalbarpal.color(QPalette::WindowText));
  verticalbarpal.setColor(QPalette::Disabled, QPalette::Text, verticalbarpal.color(QPalette::Text));
  verticalbarpal.setColor(QPalette::Disabled, QPalette::Button, verticalbarpal.color(QPalette::Button));
  verticalbarpal.setColor(QPalette::Disabled, QPalette::ButtonText, verticalbarpal.color(QPalette::ButtonText));
  verticalbarpal.setColor(QPalette::Disabled, QPalette::Background, verticalbarpal.color(QPalette::Background));
  verticalbarpal.setColor(QPalette::Disabled, QPalette::Base, verticalbarpal.color(QPalette::Base));
  verticalbarpal.setColor(QPalette::Disabled, QPalette::AlternateBase, verticalbarpal.color(QPalette::AlternateBase));
  verticalbarpal.setColor(QPalette::Disabled, QPalette::Window, verticalbarpal.color(QPalette::Window));
  verticalbarpal.setColor(QPalette::Disabled, QPalette::Mid, verticalbarpal.color(QPalette::ButtonText));





  this->viewport()->setPalette(tablepal);
  verticalBar->setPalette(verticalbarpal);
  horizontalBar->setPalette(verticalbarpal);
  headerview->setPalette(headerpal);



}

*/
void TableView::updateSectionWidth(int logicalIndex, int, int newSize)
{
    QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
    TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
    columnLabels << getColumnLabel(logicalIndex);
/*
    if(isVisible()){
        if(columnLabels.toVector().at(logicalIndex) != NULL){
            if(logicalIndex != NULL){
                QSettings settings(columnLabels.at(logicalIndex)->objectName(), table->mytv->accessibleName());
                    settings.setValue("width", newSize);
                    settings.setValue("columnId", logicalIndex);
            }
        }

        }*/
}


bool TableView::eventFilter(QObject *object, QEvent *event)
{
    if(event->type() == QEvent::ContextMenu)
    {
        QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
        TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
        Pulldown *pulldownMenu = new Pulldown();
        int i =0;

        standardAct = new QAction(tr("Standard Einstellung der Spaltenbreite wiederherstellen"), this);
        resetAct    = new QAction(tr("Standard Reihenfolge der Spalten wiederherstellen"), this);

        //read all Column Names in a QList QLabel and Add the Pulldown Action dynamicly.
        for (i=0; i < table->qsl_colNames.count(); i++)
        {
            if(getColumnName(i) != NULL)
            {
                columnLabels << getColumnLabel(i);
                if(columnLabels.toVector().at(i) != NULL)
                {
                   columnAct = new QAction(columnLabels.at(i)->text(), this);
                   pulldownMenu->addAction(columnAct);
                   columnAct->setCheckable(true);

                   if(!columnLabels.at(i)->objectName().isNull()) {
                       QSettings settings(columnLabels.at(i)->objectName(), table->mytv->accessibleName());
                       if(settings.value("hideColumn").isNull())
                       {
                       columnAct->setChecked(true);
                       }
                   } else {
                       QSettings settings(columnLabels.at(i)->text(), table->mytv->accessibleName());
                       if(settings.value("hideColumn").isNull())
                       {
                       columnAct->setChecked(true);
                       }
                   }

                }
            }
        }
        // own signal to save the state for the hidden/shown column
        connect(pulldownMenu, SIGNAL(triggered(QAction*)), this, SLOT(writeSettings(QAction*)));

        // add the standardmenu to the pulldown and execute the pulldown menu
        pulldownMenu->addSeparator();
        connect(standardAct, SIGNAL(triggered()), this, SLOT(resetSettings()));
        pulldownMenu->addAction(standardAct);
        pulldownMenu->addSeparator();
        pulldownMenu->addAction(resetAct);
        pulldownMenu->exec(QCursor::pos());

        return true;
    } else {
        return false;
    }
}

void TableView::resetSettings()
{
    QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
    TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

    for(int i = 0; i < columnLabels.count(); i++)
    {
        if(columnLabels.at(i) != NULL)
        {
            QSettings settings(columnLabels.at(i)->objectName(), table->mytv->accessibleName());
            settings.remove("width");
        }

    }
}

void TableView::writeSettings(QAction *action)
{
    QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
    TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
    int i = 0;

    for(i=0; i < columnLabels.count(); i++)
    {
        if(columnLabels.at(i) != NULL)
        {
            if(columnLabels.at(i)->text() == action->text())
            {
                if(!columnLabels.at(i)->objectName().isNull())
                {
                    QSettings settings(columnLabels.at(i)->objectName(), table->mytv->accessibleName());
                    if(settings.value("hideColumn").isNull())
                    {
                        settings.setValue("hideColumn", "1");
                        settings.setValue("columnId", i);
                        this->horizontalHeader()->hideSection(i);
                        return;
                    } else {
                        settings.remove("hideColumn");
                        settings.remove("columnId");
                        this->horizontalHeader()->showSection(i);
                        return;
                    }
                } else {
                    QSettings settings(columnLabels.at(i)->text(), table->mytv->accessibleName());
                    if(settings.value("hideColumn").isNull())
                    {
                        settings.setValue("hideColumn", "1");
                        settings.setValue("columnId", i);
                        this->horizontalHeader()->hideSection(i);
                        return;
                    } else {
                        settings.remove("hideColumn");
                        settings.remove("columnId");
                        this->horizontalHeader()->showSection(i);
                        return;
                    }
                }
            }
        }
    }
}

/*
void TableView::resize()
{
MainFrame::vdcdebug("TableView","resize", "");
   if(QSortFilterProxyModel *proxyModel = qobject_cast<QSortFilterProxyModel *> (this->model())){
      if(TableModel *table = qobject_cast<TableModel *> (proxyModel->sourceModel())){
         int height = 0;
         int width = 4;

         if(!this->verticalHeader()->isHidden()){
            width += this->verticalHeader()->width();
         }

         for(int i=0; i<table->rowCount(QModelIndex());i++){
            height += this->rowHeight(i);
         }

         for(int j=0; j<table->columnCount(QModelIndex()); j++){
            width += this->columnWidth(j);
         }

         if(!this->horizontalScrollBar()->isHidden()){
            height+= this->horizontalScrollBar()->height();
         }

         if(!this->verticalScrollBar()->isHidden()){
            width+= this->verticalScrollBar()->width();
         }

//         this->setFixedSize(width, height);
         this->setMinimumSize(width+5, height);
//         this->setFixedWidth(width);
      }
   }
}
*/
//Getter+Setter to save the MousePos(Needed for Drag&Drop
void TableView::setCurrMouseRow(int row)
{
    this->i_currrowmouse = row;
}

int TableView::getCurrMouseRow()
{
    return this->i_currrowmouse;
}

void TableView::setCurrMouseColumn(int col)
{
    this->i_currcolumnmouse = col;
}

int TableView::getCurrMouseColumn()
{
    return this->i_currcolumnmouse;
}


void TableView::setMouseModelIndex(QModelIndex mouse)
{
    this->mouseindex = mouse;
}

QModelIndex TableView::getMouseModelIndex()
{
    return this->mouseindex;
}

void TableView::setMousePos(QModelIndex mousepos)
{
   this->setMouseModelIndex(mousepos);
}



QSize TableView::sizeHint() const
{
MainFrame::vdcdebug("TableView","sizeHint", " const");
   int height = 0;
   int width = 0;

   if(QSortFilterProxyModel *proxyModel = qobject_cast<QSortFilterProxyModel *> (this->model())){
      if(TableModel *table = qobject_cast<TableModel *> (proxyModel->sourceModel())){


         if(this->horizontalHeader())
            height += this->horizontalHeader()->height();


         if(this->verticalHeader()){
            width += this->verticalHeader()->width();
         }

         for(int i=0; i<table->pageSize();i++){
            height += this->rowHeight(i);
         }

         for(int j=0; j<table->columnCount(QModelIndex()); j++){
            width += this->columnWidth(j);
         }

         if(this->horizontalScrollBar()&& this->horizontalScrollBarPolicy() != Qt::ScrollBarAlwaysOff){
            height+= this->horizontalScrollBar()->height();
         }




         if(this->verticalScrollBar() && this->verticalScrollBarPolicy() != Qt::ScrollBarAlwaysOff){
            width+= this->verticalScrollBar()->width();
         }

         width  += frameWidth() * 2;
         height += frameWidth() * 2;

//         this->setFixedSize(width, height);
//         this->setMinimumSize(width+5, height);
//         this->setFixedWidth(width);
      }
   }

   return QSize(width, height);
}


void TableView::setArrCount(int cnt)
{
MainFrame::vdcdebug("TableView","setArrCount", "int cnt");

   i_arrCount = cnt;
   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());




   if(i_arrCount > table->rowCount(QModelIndex())){
      int newRows = i_arrCount - table->rowCount(QModelIndex());
      table->insertRows(table->rowCount(QModelIndex()), newRows, QModelIndex());
   }
   else{
      if(i_arrCount < table->rowCount(QModelIndex()) && i_arrCount > 1 && !table->b_input){
         int newRows = table->rowCount(QModelIndex()) - i_arrCount;
         table->removeRows(i_arrCount-1, newRows, QModelIndex());
      }
   }

}

void TableView::setMaxArrSize(int cnt)
{
MainFrame::vdcdebug("TableView","setMaxArrSize", "int cnt");
   i_maxArrSize = cnt;



   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

   if(i_maxArrSize > table->rowCount(QModelIndex())){
      int newRows = i_maxArrSize - table->rowCount(QModelIndex());
      table->insertRows(table->rowCount(QModelIndex()), newRows, QModelIndex());
   }


}

void TableView::setColumnLabel(int col, Label *label)
{
MainFrame::vdcdebug("TableView","setColumnLabel", "int col, Label *label");

   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

   table->qh_colLabels[col] = label;
}

QLabel* TableView::getColumnLabel(int col)
{
MainFrame::vdcdebug("TableView","getColumnLabel", "int col");

   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

   return table->qh_colLabels[col];
}

void TableView::setColumnName(int col, QString name)
{
MainFrame::vdcdebug("TableView","setColumnName", "int col, QString name");

   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

   if(table->qsl_colNames.count()-1 >= col){
      table->qsl_colNames.removeAt(col);
   }
   table->qsl_colNames.insert(col,name);
}

QString TableView::getColumnName(int col)
{
MainFrame::vdcdebug("TableView","getColumnName", "int col");

   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

   if(table->qsl_colNames.count()-1 >= col){
      return table->qsl_colNames[col];
   }

   return QString();
}

void TableView::accept()
{
MainFrame::vdcdebug("TableView","accept", "");
   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
   if(!table->b_input){
      //emit accepted();
      Fgl::Event ev;
      ev.type = Fgl::ONACTION_EVENT;
      ev.attribute = "accept";
      emit fieldEvent(ev);

   }
   else{
      b_ignoreFocus = true;
      emit nextfield();
   }
}


void TableView::dragSuccess()
{
    qDebug()<<"Done";
}


void TableView::setInputEnabled(bool enable)
{ 
MainFrame::vdcdebug("TableView","setInputEnabled", "bool enable");
   if(enable){
      this->setSelectionBehavior(QAbstractItemView::SelectItems);
      this->setSelectionMode(QAbstractItemView::NoSelection);
      this->setEditTriggers(QAbstractItemView::AllEditTriggers);
      this->setShowGrid(true);
      this->setAlternatingRowColors(false);
      QHeaderView *header = this->horizontalHeader();
      QObject::disconnect(header, SIGNAL(sectionClicked(int)),
                          this, SLOT(sortByColumn(int)));
   }
   else{
      this->setSelectionBehavior(QAbstractItemView::SelectRows);
      this->setSelectionMode(QAbstractItemView::SingleSelection);
      this->setEditTriggers(QAbstractItemView::NoEditTriggers);
      this->setShowGrid(false);
      this->setAlternatingRowColors(true);
      QHeaderView *header = this->horizontalHeader();
      QObject::connect(header, SIGNAL(sectionClicked(int)),
                       this, SLOT(sortByColumn(int)));
   }

   if(this->model() != NULL){
      QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
      TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
      table->b_input = enable;
      //QItemSelectionModel *selection = this->selectionModel();
      QModelIndex index = table->index(0,0, QModelIndex());
      //selection->select(index, QItemSelectionModel::Clear);
   }
}
/*!
 * \brief Method to get the FglForm. It cast the classmember QWidget p_fglform to FglForm and returns it.
          If the cast fail or the member is not set, the returnvalue is NULL.
 */

FglForm* TableView::getForm() const
{
  if(!p_fglform)
     return NULL;

  if(FglForm *form = qobject_cast<FglForm*> (this->p_fglform))
     return form;
  else
     return NULL;
}

void TableView::fieldChanged(QModelIndex current, QModelIndex prev)
{
MainFrame::vdcdebug("TableView","fieldChanged", "QModelIndex current, QModelIndex prev");

if(!p_fglform)
  return;

   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
  /* if(table->b_input && !checkBounds(current)){
      //QModelIndex tindex = table->index(i_maxArrSize-1,current.column());
      //QModelIndex index = proxyModel->mapFromSource(tindex);



     //  table->insertRows(current.row(), 1, QModelIndex());
      //setCurrentIndex(index);

      //QModelIndex tindex = table->index(prev.row(),prev.column());
      //QModelIndex index = proxyModel->mapFromSource(tindex);
      setCurrentIndex(current);

     // emit error(QString("There are no more Rows in this direction"));

     // return;
   }*/

   Fgl::Event event;
   Fgl::Event returnevent;
   Fgl::Event diffevent;

   QList<Fgl::Event> ql_events = QList<Fgl::Event>();
   QList<Fgl::Event> ql_events2 = QList<Fgl::Event>();
   if(prev.column() > -1){
      // ignore field event if the before field was also ignored
      if(!b_ignoreFocus){
         event.type = Fgl::AFTER_FIELD_EVENT;
         event.attribute = table->qsl_colNames.at(prev.column());
         diffevent = getForm()->getFormEvent(event);
         if(diffevent.id != event.id)
         {
         ql_events2 += diffevent;
         }
      }
      else{
         b_ignoreFocus = false;
      }
   }

   if(current.row() != prev.row()){
       if(prev.row() > -1){
         if(!b_ignoreRowChange){
            event.type = Fgl::AFTER_ROW_EVENT;
            diffevent = getForm()->getFormEvent(event);
            if(diffevent.id != event.id)
            {
            ql_events2 += diffevent;
            }
         }
      }

      if(current.row() > -1){
         if(!b_ignoreRowChange){
          //  emit setArrLineSignal(current.row()+1);
            event.type = Fgl::BEFORE_ROW_EVENT;
            diffevent = getForm()->getFormEvent(event);
            if(diffevent.id != event.id)
            {
            ql_events += diffevent;
            }
        //    i_arrLine = current.row()+1;
        //    i_scrLine = current.row()+1;
         }
      }
   }

   if(current.column() > -1 && current.row() > -1){
      event.type = Fgl::BEFORE_FIELD_EVENT;
      event.attribute = table->qsl_colNames.at(current.column());
      diffevent = getForm()->getFormEvent(event);
      if(diffevent.id != event.id)
      {
      ql_events += diffevent;
      }
      
      // only allow focus for fields that have a focus policy
      if(table->b_input && isReadOnlyColumn(current.column())){
//         if(current.column() > prev.column() || (current.row() > prev.row())){
             emit nextfield();
 /*        }
         else{
            emit prevfield();
            return;
         }
         */
      }



      /*
      if(!isReadOnlyColumn(current.column())){
            event.type = Fgl::BEFORE_FIELD_EVENT;
            event.attribute = table->qsl_colNames.at(current.column());
            emit fieldEvent(event);
      }
      else{
         // if field has no focus policy then it should not get the focus!
         // set ignore = true so the after field event also does not get triggered
         b_ignoreFocus = true;
         if(current.column() > prev.column()){
            if(table->b_input){
               this->nextfield();
            }
         }
         else{
            if(table->b_input){
               this->prevfield();
            }
         }
      }
      */
   }


   if(!ql_events2.isEmpty())
   {
       int resp_cnt = ql_events2.size();
       for(int i = 0; i<resp_cnt; i++)
       {

           returnevent.id += ql_events2.at(i).id;
           if(i+1 != resp_cnt)
              returnevent.id += ",";
       }

       addToQueue(returnevent);
   }
   returnevent.id = "";
   if(!ql_events.isEmpty())
   {
       int resp_cnt = ql_events.size();
       for(int i = 0; i<resp_cnt; i++)
       {

           returnevent.id += ql_events.at(i).id;
           if(i+1 != resp_cnt)
              returnevent.id += ",";
       }

       addToQueue(returnevent);
   }


}

bool TableView::isReadOnlyColumn(int col)
{
MainFrame::vdcdebug("TableView","isReadOnlyColumn", "int col");
   if(LineEditDelegate *dele = qobject_cast<LineEditDelegate *> (this->itemDelegateForColumn(col))){
      return dele->readOnly();
   }
   return false;
}

void TableView::setScrLine(int line)
{
MainFrame::vdcdebug("TableView","setScrLine", "int line");
   if(QSortFilterProxyModel *proxyModel = qobject_cast<QSortFilterProxyModel *> (this->model())){

      //if(TableModel *table = qobject_cast<TableModel *> (proxyModel->sourceModel())){
         QModelIndex proxyIndex = proxyModel->index(currentIndex().column(), line);
         setCurrentIndex(proxyIndex);
    //  }

   }
}

void TableView::setArrLine(int line)
{
MainFrame::vdcdebug("TableView","setArrLine", "int line");
   return;
   if(QSortFilterProxyModel *proxyModel = qobject_cast<QSortFilterProxyModel *> (this->model())){

//      if(TableModel *table = qobject_cast<TableModel *> (proxyModel->sourceModel())){
         QModelIndex proxyIndex = proxyModel->index(currentIndex().column(), line);
         QModelIndex index = proxyModel->mapToSource(proxyIndex);
         setCurrentIndex(index);
//      }

   }
}

void TableView::setCurrentColumn(int col)
{
MainFrame::vdcdebug("TableView","setCurrentColumn", "int col");
   if(QSortFilterProxyModel *proxyModel = qobject_cast<QSortFilterProxyModel *> (this->model())){

      //if(TableModel *table = qobject_cast<TableModel *> (proxyModel->sourceModel())){
         QModelIndex proxyIndex = proxyModel->index(col, currentIndex().row());
         QModelIndex index = proxyModel->mapToSource(proxyIndex);
         setCurrentIndex(index);
     // }
   }
}

void TableView::setCurrentField(int row, int col)
{
MainFrame::vdcdebug("TableView","setCurrentField", "int row, int col");
//   this->setFocus();
   if(QSortFilterProxyModel *proxyModel = qobject_cast<QSortFilterProxyModel *> (this->model())){

      if(TableModel *table = qobject_cast<TableModel *> (proxyModel->sourceModel())){
         QModelIndex tindex = table->index(row-1, col-1);
         QModelIndex index = proxyModel->mapFromSource(tindex);
         selectionModel()->setCurrentIndex(index, QItemSelectionModel::NoUpdate);
         if(this->currentIndex() == index){
             Fgl::Event event;
             event.type = Fgl::BEFORE_FIELD_EVENT;
             event.attribute = table->qsl_colNames.at(index.column());
             emit fieldEvent(event);
         }

         //setCurrentIndex(index);
//         if(table->b_input && (currentIndex().row() == 0 && currentIndex().column() == 0)){
         if(table->b_input){
             if(FglForm *form = qobject_cast<FglForm*> (this->p_fglform))
             {
                 if(form != NULL)
                 {
                     form->setCurrentWidget(this);
                 }
             }
             edit(index);
         }
      }
   }
    
}

void TableView::setText(QString text, int row, int col)
{
MainFrame::vdcdebug("TableView","setText", "QString text, int row, int col");
   if(QSortFilterProxyModel *proxyModel = qobject_cast<QSortFilterProxyModel *> (this->model())){
         //row-1 cause the proxyModel counts at 0
       TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
       QModelIndex modelIndex;
       modelIndex = proxyModel->index(row, col, QModelIndex());
       /*if(table->b_input)
       {

       }
       else
       {
                   modelIndex = proxyModel->index(row-1, col, QModelIndex());
       }*/

         if(LineEditDelegate *dele = qobject_cast<LineEditDelegate *> (this->itemDelegateForColumn(col))){
            if(LineEdit *widget = qobject_cast<LineEdit *> (dele->qw_editor)){
               text = Fgl::usingFunc(widget->format(), text, widget->dataType());
            }
         }
       

         model()->setData(modelIndex, text);
   }
}

bool TableView::checkBounds(const QModelIndex current){

   if((i_maxArrSize > 0 && current.row() > i_maxArrSize-1) || current.row() < 0){
      return false;
   }

   return true;
}

TableModel::TableModel(int rows, int columns, QObject *parent) : QAbstractTableModel(parent), columns(columns)
{
MainFrame::vdcdebug("TableModel","TableModel", "int rows, int columns, QObject *parent");
   this->rows = 0;
   for(int i=0; i<rows; i++){
      insertRows(i, 1, QModelIndex());
   }

   this->setPageSize(rows);

   b_input = true;
}

TableModel::TableModel(QObject *parent) : QAbstractTableModel(parent)
{
MainFrame::vdcdebug("TableModel","TableModel", "QObject *parent");
   b_input = true;
   this->columns = 0;
   this->setPageSize(0);
}

int TableModel::rowCount(const QModelIndex&) const { return this->rows; }//fields2.count(); }

int TableModel::columnCount(const QModelIndex&) const { return columns; }

QVariant TableModel::data(const QModelIndex &index, int role) const
{
//MainFrame::vdcdebug("TableModel","data", "const QModelIndex &index, int role const");
   int row = index.row();
   int column = index.column();

   if(LineEditDelegate *dele = qobject_cast<LineEditDelegate *> (getTableView()->itemDelegateForColumn(column))){
       if(LineEdit *widget = qobject_cast<LineEdit *> (dele->qw_editor)){
           if(widget->dataType() == 2 || widget->dataType() == 3 || widget->dataType() == 5 || widget->dataType() == 6) {
               if (role == Qt::TextAlignmentRole) {
                   return int(Qt::AlignRight);
               }
           } else {
               if (role == Qt::TextAlignmentRole) {
                   return int(Qt::AlignLeft);
               }
           }
       }

   }

   if(column == -1 || row == -1)
      return QVariant();

   if (role == Qt::DisplayRole || role == Qt::EditRole)
   {
      if(this->fields.count() > row){
         if(this->fields[row].count() > column){
            QString s = this->fields[row][column];
            return s;
         }
      }

   }else{
      /*
      //Job 18105: Align Text Left and Int Right
      if(role == Qt::TextAlignmentRole){
         bool ok = false;
         if(this->fields.count() > row){
            if(this->fields[row].count() > column){
               this->fields[row][column].toInt(&ok,10);
               if(ok){
                  return Qt::AlignRight;
               }
               else{
                  return Qt::AlignLeft;
               }
            }
         }
      }
      */

      //return QAbstractTableModel::data(index, role);
      return QVariant();   // hier sollte man den Datentyp der Spalte aus der
                           // xml-Maske auswerten und je nachdem auch Int o.ae.
                           // zurueckgeben (damit die Sortierung (z.b. Datum,
                           // Zahlen) richtig wird)
   }

   return QVariant();

}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
MainFrame::vdcdebug("TableModel","setData", "const QModelIndex &index, const QVariant &value, int role");
    if(index.isValid() && ( role == Qt::EditRole || role == Qt::DisplayRole ))
    {
       int row = index.row();
       int column = index.column();

       this->fields[row][column] = value.toString();

       emit dataChanged ( index,index );
       return true;
    }
    return false;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
//MainFrame::vdcdebug("TableModel","ItemFlags TableModel", """");
   Qt::ItemFlags f; // = QAbstractTableModel::flags(index);
   if (index.isValid()){
       f = Qt::ItemIsEnabled ;
      f |= b_input ? Qt::ItemIsEditable : Qt::ItemIsSelectable;
   }

   if(getTableView()->isReadOnlyColumn(index.column()) && b_input) {
       f = Qt::NoItemFlags;
       return f;
   }

   f |= Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled;
   return f;
}

QStringList TableModel::mimeTypes() const
{
   QStringList types;
   types << "text/plain";
   return types;
}

QMimeData* TableModel::mimeData(const QModelIndexList &indexes) const
{
   QMimeData *mimeData = new QMimeData();
  // QByteArray encodedData;
  // encodedData.clear();
  // QDataStream stream(&encodedData, QIODevice::WriteOnly);
   QModelIndex index;
   if(TableView *tv = qobject_cast<TableView *> (getTableView()))
   {
       index = tv->getMouseModelIndex();
   }
   QString text;
   if (index.isValid())
   {

           text = data(index, Qt::DisplayRole).toString().trimmed();
   }

   mimeData->setText(text);
   return mimeData;
}


bool TableModel::insertRows(int position, int rows, const QModelIndex &index)
{
MainFrame::vdcdebug("TableModel","insertRows", "int position, int rows, const QModelIndex &index");
   Q_UNUSED(index);

   if(this->rows >= 0){
      this->rows += rows;

      beginInsertRows(QModelIndex(), position, position+rows-1);

      for(int row=0; row < rows; row++){
         QVector<QString> colValues;
         for(int col=0; col < columnCount(QModelIndex()); col++){
            colValues.insert(col, "");
         }
         this->fields.insert(this->rows-rows, colValues);
      }

      endInsertRows();
      return true;
   }
   return false;

}

bool TableModel::removeRows(int position, int rows, const QModelIndex &index)
{
MainFrame::vdcdebug("TableModel","removeRows", "int position, int rows, const QModelIndex &index");
   Q_UNUSED(index);
   if(position > rows)
   {
       if(this->rows > 0 && this->fields.count() > position+rows-1){

          beginRemoveRows(QModelIndex(), position, position+rows-1);
          this->rows -= rows;
          for(int i=1; i<rows; i++){
             if(this->fields.count() > position+i){
             this->fields.remove(position+i);
             }
          }
          endRemoveRows();

          return true;
       }

       return false;
   }
   else {
       if(this->rows >= 0){
          this->rows -= rows;

              beginRemoveRows(QModelIndex(), position, rows-1);

              for(int row=1; row < rows; row++){
                  qDebug() << "row" << row;
                 this->fields.remove(this->rows);
              }

              endRemoveRows();
              return true;
       }
       return false;

   }
}

void TableModel::setTableView(TableView *tv)
{
    this->mytv = tv;
}

QVariant TableModel::headerData ( int section, Qt::Orientation orientation, int role ) const
{
//MainFrame::vdcdebug("TableModel","headerData ", " int section, Qt");
   if ( role != Qt::DisplayRole )
      return QVariant();

   if ( orientation == Qt::Horizontal )
   {
      if(qh_colLabels[section] != NULL){
         if(!qh_colLabels[section]->text().isEmpty()){
            return qh_colLabels[section]->text();
         }
         else{
            return qh_colLabels[section]->accessibleName();
         }
      }
   }
   else{
      return section;
   }

   return QVariant();
}

bool MyFilter::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
MainFrame::vdcdebug("MyFilter","lessThan", "const QModelIndex &left, const QModelIndex &right const");
   int column = left.column();
   if (column == 9)
   {
      QVariant v0 = left.data(Qt::DisplayRole);
      QVariant v1 = right.data(Qt::DisplayRole);
      QString  s0 = v0.toString();
      QString  s1 = v1.toString();
      QDate    d0 = dateFromString(s0);
      QDate    d1 = dateFromString(s1);

      return d0 < d1;

   }else{

      return QSortFilterProxyModel::lessThan(left, right);
   }
}

// return number represented by a digit character
int intFromChar(QChar c)
{
   return c.unicode() - '0';
}


// assumes dd.mm.yy formatted date
// // idx: 01234567
QDate dateFromString(const QString &s)
{
   int day   = intFromChar(s[0]) * 10 + intFromChar(s[1]);

   int month = intFromChar(s[3]) * 10 + intFromChar(s[4]);
   //y2k bug
   //int year = 1900 + intFromChar(s[6]) * 10 + intFromChar(s[7]);
   int year = intFromChar(s[6]) * 1000 + intFromChar(s[7]) * 100 +
              intFromChar(s[8]) * 10   + intFromChar(s[9]);

   return QDate(year, month, day);
}

LineEditDelegate::LineEditDelegate(QObject *parent)
   : QStyledItemDelegate(parent)
{
   i_column = -1;
}

LineEditDelegate::LineEditDelegate(QDomElement formElement, QObject *parent)
   : QStyledItemDelegate(parent)
{
   i_column = -1;
   this->p_fglform = NULL;
   this->formElement = formElement;

   qw_editor = WidgetHelper::createFormWidget(this->formElement);

   b_readOnly = false;

   if(LineEdit *le = qobject_cast<LineEdit *> (qw_editor)){
      b_readOnly = le->noEntry();
      le->setDragEnabled(true);
   }
}

QSize LineEditDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
MainFrame::vdcdebug("LineEditDelegate","sizeHint", "const QStyleOptionViewItem &option, const QModelIndex &index const");
   Q_UNUSED(option);
   Q_UNUSED(index);
   /*
   ButtonEdit *editor = new ButtonEdit(icon);
   editor->setFixedWidth((w+5)*5);
   QSize size = editor->sizeHint();
   delete editor;
   */
   //QSize size = this->line->sizeHint();
   return QSize();
}




QWidget* LineEditDelegate::createEditor(QWidget *parent,
   const QStyleOptionViewItem &/* option */,
   const QModelIndex &/* index */) const
{
   QWidget *editor = WidgetHelper::createFormWidget(this->formElement, parent);
   if(TableView *tv = qobject_cast<TableView*> (parent->parentWidget()))
   {
            tv->curr_editor = editor;
   }

   editor->setAutoFillBackground(true);
   editor->setEnabled(true);
   //remove borders from inputfields in inputarray
   QString className = editor->metaObject()->className();
   QString style = QString("%0 { border-top-width: 0; border-top-style: none; border-bottom-width: 0; border-bottom-style: none; }").arg(className) + " " + editor->styleSheet();
   editor->setStyleSheet(style);

   if(p_fglform != NULL)
       editor->installEventFilter(p_fglform);
   if(ButtonEdit *be = qobject_cast<ButtonEdit*> (editor))
   {
      be->getButtonObj()->installEventFilter(p_fglform);
   }

   if(DateEdit *de = qobject_cast<DateEdit*> (editor))
   {
      de->getButtonObj()->installEventFilter(p_fglform);
   }
   connect(editor, SIGNAL(fieldEvent(Fgl::Event)), p_fglform, SLOT(fieldEvent(Fgl::Event)));

   return editor;
}

void LineEditDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const
{
   QString value = index.model()->data(index, Qt::DisplayRole).toString();

   WidgetHelper::setFieldText(editor, value);
}


void LineEditDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
//   LineEdit *lineEdit = static_cast<LineEdit*>(editor);
   QString value = WidgetHelper::fieldText(editor); //lineEdit->text();

   model->setData(index, value);
}


void LineEditDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
   editor->setGeometry(option.rect);
}

void LineEditDelegate::setForm(QWidget *form)
{
MainFrame::vdcdebug("LineEditDelegate","setForm", "QWidget *form");
   p_fglform = form;
   //connect(this, SIGNAL(fieldEvent(Fgl::Event, QWidget*)), p_fglform, SLOT(fieldEvent(Fgl::Event, QWidget*)));
}

bool LineEditDelegate::eventFilter(QObject *object, QEvent *event)
{
//MainFrame::vdcdebug("LineEditDelegate","eventFilter", "QObject *object, QEvent *event");



//Verhindert beim disablen von p_fglform, das der Editor geschlossen wird. Kommt durch synchronisation des
//Protokolls.

    if(event->type() == QEvent::FocusOut){
      QFocusEvent *fe = (QFocusEvent*) event;
      if(fe->reason() == Qt::ActiveWindowFocusReason ||
         fe->reason() == Qt::OtherFocusReason ||
         fe->reason() == Qt::PopupFocusReason ||
         fe->reason() == Qt::MouseFocusReason){
         fe->ignore();
         return true;
      }
   }

   if(event->type() == QEvent::ShortcutOverride){
      //QKeyEvent *ke = (QKeyEvent*) event;
      event->ignore();
      return true;
   }

   return QStyledItemDelegate::eventFilter(object, event);
}

