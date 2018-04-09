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
   ignoreFieldChangeEvent = false;
   setAutoRepeat(false);
 //  b_palette = false;
   this->setMouseTracking(true);
   const int rowHeight = fontMetrics().height() + 2;
   verticalHeader()->setDefaultSectionSize(rowHeight);
   verticalHeader()->setFocusPolicy(Qt::NoFocus);
   horizontalHeader()->setFocusPolicy(Qt::NoFocus);
   this->setDragEnabled(true);
   //Keine Auswirkung
   setTabKeyNavigation(false);
   this->verticalHeader()->hide();
   QHeaderView *header = this->horizontalHeader();
   header->setDefaultAlignment(Qt::AlignLeft);
   #if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
      header->setClickable(true);
   #else
      header->setSectionsClickable(true);
   #endif
   header->setSortIndicatorShown(true);
   //header->setSortIndicator(1, Qt::DescendingOrder);
   header->installEventFilter(this);
   this->setContextMenuPolicy(Qt::CustomContextMenu);

   connect(this, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(accept()));
   connect(this, SIGNAL(entered(QModelIndex)), this, SLOT(setMousePos(QModelIndex)));
   QObject::connect(header, SIGNAL(sectionClicked(int)),
                    this, SLOT(sortByColumn(int)));

   QObject::connect(header, SIGNAL(sortIndicatorChanged(int,Qt::SortOrder)),
                    this, SLOT(saveSortOrder(int, Qt::SortOrder)));

   connect(header, SIGNAL(sectionResized(int,int,int)), this, SLOT(updateSectionWidth(int,int,int)));
   connect(header, SIGNAL(sectionMoved(int,int,int)), this, SLOT(saveNewSectionOrder(int,int,int)));

   QObject::disconnect(header, SIGNAL(sectionPressed(int)),
                       this, SLOT(selectColumn(int)));
   //Show only the Scrollbars when needed
   this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
   this->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
   this->setInputEnabled(false);
   this->setEnabled(false);

   int logicalIndex = 0;
   QString sortIndicator;

   if(FglForm *fglform = qobject_cast<FglForm*> (p_fglform))
   {
       logicalIndex = VDC::readSettingsFromIni(fglform->formName(), "sortLogicalIndex").toInt();
       sortIndicator = VDC::readSettingsFromIni(fglform->formName(), "sortIndicator");
   }

   horizontalHeader()->blockSignals(true);
   if(sortIndicator == "ASC")
   {
       this->horizontalHeader()->setSortIndicator(logicalIndex,Qt::AscendingOrder);
   }

   if(sortIndicator == "DESC")
   {
       this->horizontalHeader()->setSortIndicator(logicalIndex,Qt::DescendingOrder);
   }
   horizontalHeader()->blockSignals(false);

}

void TableView::restoreSortOrder()
{

    QHeaderView *header = this->horizontalHeader();
    QObject::disconnect(header, SIGNAL(sortIndicatorChanged(int,Qt::SortOrder)),
                     this, SLOT(saveSortOrder(int, Qt::SortOrder)));
    int logicalIndex = 0;
    QString sortIndicator;

    if(FglForm *fglform = qobject_cast<FglForm*> (p_fglform))
    {
        logicalIndex = VDC::readSettingsFromIni(fglform->formName(), "sortLogicalIndex").toInt();
        sortIndicator = VDC::readSettingsFromIni(fglform->formName(), "sortIndicator");
    }

    this->setSortingEnabled(false);
    if(sortIndicator == "ASC")
    {
        this->horizontalHeader()->setSortIndicator(logicalIndex,Qt::AscendingOrder);
    }

    if(sortIndicator == "DESC")
    {
        this->horizontalHeader()->setSortIndicator(logicalIndex,Qt::DescendingOrder);
    }
    this->setSortingEnabled(true);

    QObject::connect(header, SIGNAL(sortIndicatorChanged(int,Qt::SortOrder)),
                     this, SLOT(saveSortOrder(int, Qt::SortOrder)));
}


void TableView::saveSortOrder(int logicalIndex, Qt::SortOrder sortOrder)
{
    if(this->isEnabled() && this->isVisible())
    {
        QString sortIndicator;

        switch (sortOrder)
        {
        case Qt::AscendingOrder:
            sortIndicator = "ASC";
            break;
        case Qt::DescendingOrder:
            sortIndicator = "DESC";
            break;
        default:
            break;
        }

        if(FglForm *fglform = qobject_cast<FglForm*> (p_fglform))
        {
            VDC::saveSettingsToIni(fglform->formName(), "sortIndicator", sortIndicator);
            VDC::saveSettingsToIni(fglform->formName(), "sortLogicalIndex", QString::number(logicalIndex));

            Fgl::Event event;
            event.type = Fgl::ONKEY_EVENT;
            event.attribute = "3028";
            emit fieldEvent(event);
            return;
        }
    }
}

void TableView::saveNewSectionOrder(int, int, int)
{
    if(FglForm *fglform = qobject_cast<FglForm*> (p_fglform))
    {
        QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
        TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

        if(!table->b_input)
        {
            QHeaderView *header = this->horizontalHeader();
            VDC::saveSettingsToIni(fglform->formName(), QString(this->accessibleName() + "/state"), header->saveState());
        }
    }
}
void TableView::oldSectionOrder()
{
    if(FglForm *fglform = qobject_cast<FglForm*> (p_fglform))
    {
        QHeaderView *header = this->horizontalHeader();
        header->restoreState(VDC::readSettingsFromIni1(fglform->formName(), QString(this->accessibleName() + "/oldstate")));
        VDC::removeSettingsFromIni(fglform->formName(), QString(this->accessibleName() + "/state"));
        this->update();
    }
}
void TableView::resetSort()
{
    QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
    proxyModel->sort(1, Qt::DescendingOrder);
}

/*void TableView::restoreViewPalette()
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
  tablepal.



Color(QPalette::Disabled, QPalette::Background, tablepal.color(QPalette::Background));
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

    if(getColumnLabel(logicalIndex) != NULL && logicalIndex > -1 && this->isEnabled())
    {
        QLabel *columnName = getColumnLabel(logicalIndex);
        if(columnName != NULL)
        {
            VDC::saveSettingsToIni(this->getForm()->formName(), this->accessibleName() + "/" + columnName->objectName() + "/columnWidth", QString::number(newSize));
            VDC::saveSettingsToIni(this->getForm()->formName(), this->accessibleName() + "/" + columnName->objectName() + "/columnWidthId", QString::number(logicalIndex));
            //qDebug() << "columnName: " << columnName->objectName();
        }
    }
}

void TableView::insertRow()
{
  int row = -1;
  int col = -1;
  int arrCount = getForm()->context->getOption("ARRCOUNT");

  row = currentIndex().row();
  col = currentIndex().column();
  qDebug()<<row;
  qDebug()<<col;
  //Nothing selected
  if(row == -1)
  {
     qDebug() << "NO INDEX FOUND!"; //test, otherwise qdebug
     return;
  }

  if(arrCount >= i_maxArrSize) {
      qWarning("Max rows reached. Insert row failed.");
      getForm()->error("Max rows reached. Insert row failed.");
      return;
  }

  QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
  TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
  table->insertRows(row, 1, QModelIndex());
  getForm()->context->setOption("ARRCOUNT", arrCount+1);
  b_ignoreFocus = true;
 // setCurrentField(row, col);



  Fgl::Event event, diffevent;
  QList<Fgl::Event> ql_events;
  event.id = "-1";


  event.type = Fgl::BEFORE_ROW_EVENT;
  diffevent = getForm()->getFormEvent(event);
  if(diffevent.id != event.id)
  {
    ql_events += diffevent;
  }


  event.type = Fgl::BEFORE_FIELD_EVENT;
  event.attribute = table->qsl_colNames.at(col);
  diffevent = getForm()->getFormEvent(event);
  if(diffevent.id != event.id)
  {
  ql_events += diffevent;
  }

  Fgl::Event returnevent;

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

void TableView::deleteRow()
{
  int row = -1;
  int col = -1;

  row = currentIndex().row();
  col = currentIndex().column();
  qDebug()<<"row:"<<row;
  //Nothing selected
  if(row == -1)
  {
     qDebug() << "NO INDEX FOUND!";
     return;
  }

  QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
  TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
  blockSignals(true);
  table->removeRows(row, 1, QModelIndex());
  blockSignals(false);

  getForm()->context->setOption("ARRCOUNT", getForm()->context->getOption("ARRCOUNT")-1);

  QModelIndex tindex = table->index(getForm()->context->getOption("ARRCOUNT")+1, col);
  QModelIndex index = proxyModel->mapFromSource(tindex);

  setCurrentIndex(index);

  Fgl::Event event, diffevent;
  QList<Fgl::Event> ql_events;
  event.id = "-1";


  event.type = Fgl::BEFORE_ROW_EVENT;
  diffevent = getForm()->getFormEvent(event);
  if(diffevent.id != event.id)
  {
    ql_events += diffevent;
  }


  Fgl::Event returnevent;

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

  QModelIndex tindex1;
  QModelIndex index1;
  if(row > 0)
  {
      tindex1 = table->index(row-1, col);
      index1 = proxyModel->mapFromSource(tindex1);
  } else {
      tindex1 = table->index(row, col);
      index1 = proxyModel->mapFromSource(tindex1);
  }

  setCurrentIndex(index1);
}

void TableView::copyRow()
{
    QString columnText;

    foreach(const QModelIndex& index, this->selectedIndexes())
    {
        columnText.append(index.data().toString() + "\t");
    }

    QApplication::clipboard()->setText(columnText);

}

void TableView::copyTable()
{
    QString tableText;
    int rows = this->model()->rowCount(QModelIndex());
    int columns = this->model()->columnCount(QModelIndex());

    for(int i=0; i < columns; i++)
    {
        if(getColumnLabel(i) != NULL)
        {
                tableText.append(getColumnLabel(i)->text());
        }
        tableText.append("\t");
    }
    tableText.append("\n");

    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < columns; j++)
        {
            QModelIndex index = this->model()->index(i, j);
            QString value = index.data().toString();

            value.remove("\"");
            value.remove("\n");

            tableText.append(value + "\t");

            if(j+1 == columns)
            {
                tableText.append("\n");
            }
        }
    }
    QApplication::clipboard()->setText(tableText);
}

void TableView::copyCell()
{
    int row = currentIndex().row();
    int col = currentIndex().column();
    QString cellText;


    cellText = this->model()->index(row, col).data().toString();

    QApplication::clipboard()->setText(cellText);
}

void TableView::copyColumn()
{
    QString tableText;
    int rows = this->model()->rowCount(QModelIndex());
    int col = currentIndex().column();

    for(int i=0; i < rows; i++)
    {
        tableText.append(this->model()->index(i, col).data().toString() + "\n");
    }

    QApplication::clipboard()->setText(tableText);
}

bool TableView::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::ContextMenu)
    {
        QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
        TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
        Pulldown *pulldownMenu = new Pulldown();
        int i =0;
        standardAct = new QAction(tr("Reset the width of all columns"), this);
        resetAct    = new QAction(tr("Reset order"), this);
        restoreSort   = new QAction(tr("Spaltensortierung wiederherstellen"), this);

        //read all Column Names in a QList QLabel and Add the Pulldown Action dynamicly.
        for (i=0; i < table->qsl_colNames.count(); i++)
        {
            if(FglForm *fglform = qobject_cast<FglForm*> (p_fglform))
            {
                if(getColumnName(i) != NULL)
                {
                    columnLabels << getColumnLabel(i);
                    if(columnLabels.toVector().at(i) != NULL)
                    {
                       Label *la = qobject_cast<Label*> (columnLabels.at(i));
                       if(!la->getIsHidden()) {
                           columnAct = new QAction(columnLabels.at(i)->text(), this);
                           columnAct->setObjectName(columnLabels.at(i)->objectName());
                           pulldownMenu->addAction(columnAct);
                           columnAct->setCheckable(true);
                           int hideColumn = VDC::readSettingsFromIni(fglform->formName(), QString(this->accessibleName() + "/" + columnLabels.at(i)->objectName() + "/hideColumn")).toInt();

                           if(!columnLabels.at(i)->objectName().isNull()) {
                               if(hideColumn == 0)
                               {
                               columnAct->setChecked(true);
                               }
                           } else {
                               if(hideColumn == 0)
                               {
                               columnAct->setChecked(true);
                               }
                           }
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
        connect(resetAct, SIGNAL(triggered()), this, SLOT(oldSectionOrder()));
        pulldownMenu->addAction(resetAct);
        connect(restoreSort, SIGNAL(triggered()), this, SLOT(resetSort()));
        //pulldownMenu->addAction(restoreSort);
        pulldownMenu->exec(QCursor::pos());

        return true;
    }

    return QTableView::eventFilter(obj, event);
}

void TableView::resetSettings()
{
    for(int i = 0; i < columnLabels.count(); i++)
    {
        if(FglForm *fglform = qobject_cast<FglForm *> (p_fglform))
        {
            if(columnLabels.at(i) != NULL)
            {
                VDC::removeSettingsFromIni(fglform->formName(), this->accessibleName() + "/" + columnLabels.at(i)->objectName() + "/columnWidth");
            }
        }
    }
}

void TableView::writeSettings(QAction *action)
{
    //QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
    //TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
    int i = 0;

    for(i=0; i < columnLabels.count(); i++)
    {
        if(FglForm *fglform = qobject_cast<FglForm*> (p_fglform))
        {
            if(columnLabels.at(i) != NULL && action->objectName() != NULL)
            {
                if(columnLabels.at(i)->objectName() == action->objectName())
                {
                    if(!columnLabels.at(i)->objectName().isNull())
                    {
                        int hideColumn = VDC::readSettingsFromIni(fglform->formName(), QString(this->accessibleName() + "/" + columnLabels.at(i)->objectName() + "/hideColumn")).toInt();
                        if(hideColumn == 0)
                        {
                            VDC::saveSettingsToIni(fglform->formName(), QString(this->accessibleName() + "/" + columnLabels.at(i)->objectName() + "/hideColumn"), QString::number(1));
                            VDC::saveSettingsToIni(fglform->formName(), QString(this->accessibleName() + "/" + columnLabels.at(i)->objectName() + "/columnId"), QString::number(i));
                            this->horizontalHeader()->hideSection(i);
                            break;
                        } else {
                            VDC::saveSettingsToIni(fglform->formName(), QString(this->accessibleName() + "/" + columnLabels.at(i)->objectName() + "/hideColumn"), QString::number(0));
                            this->horizontalHeader()->showSection(i);
                            break;
                        }
                    } else {
                        int hideColumn = VDC::readSettingsFromIni(fglform->formName(), QString(this->accessibleName() + "/hideColumn")).toInt();

                        if(hideColumn == 0)
                        {
                            VDC::saveSettingsToIni(fglform->formName(), QString(this->accessibleName() + "/" + columnLabels.at(i)->objectName() + "/hideColumn"), QString::number(1));
                            VDC::saveSettingsToIni(fglform->formName(), QString(this->accessibleName() + "/" + columnLabels.at(i)->objectName() + "/columnId"), QString::number(i));
                            this->horizontalHeader()->hideSection(i);
                            break;
                        } else {
                            VDC::saveSettingsToIni(fglform->formName(), QString(this->accessibleName() + "/" + columnLabels.at(i)->objectName() + "/hideColumn"), QString::number(1));
                            this->horizontalHeader()->showSection(i);
                            break;
                        }
                    }
                }
            }
        }
    }

    if(FglForm *fglform = qobject_cast<FglForm*> (p_fglform))
    {
        QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
        TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

        if(!table->b_input)
        {
            QHeaderView *header = this->horizontalHeader();
            VDC::saveSettingsToIni(fglform->formName(), QString(this->accessibleName() + "/state"), header->saveState());
        }
    }
}


void TableView::playkey(QKeyEvent *ev)
{
    QApplication::sendEvent(curr_editor, ev);
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
      if(i_arrCount < table->rowCount(QModelIndex()) && i_arrCount > 0 && !table->b_input){
         int newRows = table->rowCount(QModelIndex()) - i_arrCount;
         table->removeRows(i_arrCount-1, newRows, QModelIndex());
      }
   }

}

void TableView::setMaxArrSize(int cnt)
{
MainFrame::vdcdebug("TableView","setMaxArrSize", "int cnt");
   i_maxArrSize = cnt;
   int setMaxRows = 1;

   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

   if(table->b_input && this->pageSize < i_maxArrSize && i_arrCount > 0)
   {
       if(this->pageSize > setMaxRows)
       {
           if(this->pageSize > i_arrCount)
           {
               setMaxRows = this->pageSize;
           } else {
               setMaxRows = i_arrCount;
           }
       }
   } else {
       if(i_arrCount > 0)
       {
           setMaxRows = i_arrCount;
       }
   }

   if(setMaxRows > table->rowCount(QModelIndex())){
      int newRows = setMaxRows - table->rowCount(QModelIndex());
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
   if(col == -1)
   {
       return QString();
   }

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
   if(table->rowCount(current) == current.row() + 1 && current.row() > 0 && current.row()+1  < i_maxArrSize)
   {
       table->insertRow(current.row()+1, current);
   }

   Fgl::Event event;
   Fgl::Event returnevent;
   Fgl::Event diffevent;

   QList<Fgl::Event> ql_events = QList<Fgl::Event>();
   QList<Fgl::Event> ql_events2 = QList<Fgl::Event>();

   if(prev.column() > -1 && this->b_sendevents){
      // ignore field event if the before field was also ignored
      if(!b_ignoreFocus){
         event.type = Fgl::AFTER_FIELD_EVENT;
         event.attribute = table->qsl_colNames.at(prev.column());
         diffevent = getForm()->getFormEvent(event);
         if(diffevent.id != event.id)
         {
         eventfield = prev;
         ql_events2 += diffevent;
         }
      }
   }

   if(current.row() != prev.row()){
       if(prev.row() > -1){
         if(!b_ignoreFocus){
            event.type = Fgl::AFTER_ROW_EVENT;
            diffevent = getForm()->getFormEvent(event);
            if(diffevent.id != event.id)
            {
               eventfield = prev;
               ql_events2 += diffevent;
            }
         }
      }

      if(current.row() > -1){
         if(!b_ignoreFocus){
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

   if(current.column() > -1 && current.row() > -1 && current.column() <= table->qsl_colNames.count()){
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
    //         emit nextfield();
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

       if(b_sendevents)
       //if(!ignoreFieldChangeEvent || b_sendevents)
       {
           addToQueue(returnevent);
       }
   }
   else
   {
       FglForm *fglform = (FglForm*) p_fglform;
       int arrLine;

       if(fglform->mIsSortAllowed)
       {
           arrLine = proxyModel->mapToSource(current).row();
       } else {
           arrLine = current.row();
       }
       int scrLine = current.row();

       targetfield = current;
       fglform->context->refreshInputArrayAttributes();

       fglform->context->setOption("SCRLINE", scrLine);
       fglform->context->setOption("ARRLINE", arrLine);
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
         //if(!ignoreFieldChangeEvent)
         if(!isAutoRepeat())
         {
             addToQueue(returnevent);
         }
         targetfield = current;
   }

   b_sendevents = true;


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
    QModelIndex proxyIndex = model()->index(currentIndex().row(), line);
    if(proxyIndex.isValid())
    {
        setCurrentIndex(proxyIndex);
    }
}

void TableView::setArrLine(int line)
{
MainFrame::vdcdebug("TableView","setArrLine", "int line");
    QModelIndex proxyIndex = model()->index(line, currentIndex().column());
    if(proxyIndex.isValid())
    {
        setCurrentIndex(proxyIndex);
    }
}

void TableView::setCurrentColumn(int col)
{
MainFrame::vdcdebug("TableView","setCurrentColumn", "int col");
   if(QSortFilterProxyModel *proxyModel = qobject_cast<QSortFilterProxyModel *> (this->model())){

      //if(TableModel *table = qobject_cast<TableModel *> (proxyModel->sourceModel())){
         QModelIndex proxyIndex = proxyModel->index(currentIndex().row(), col);
         QModelIndex index = proxyModel->mapToSource(proxyIndex);
         setCurrentIndex(index);
     // }
   }
}

void TableView::setCurrentField(int row, int col, bool b_sendevents)
{
   MainFrame::vdcdebug("TableView","setCurrentField", "int row, int col");
   if(QSortFilterProxyModel *proxyModel = qobject_cast<QSortFilterProxyModel *> (this->model())){
      if(TableModel *table = qobject_cast<TableModel *> (proxyModel->sourceModel())){
         QModelIndex tindex = table->index(row-1, col-1);
         QModelIndex index = proxyModel->mapFromSource(tindex);
         //Unter Mac enfernt er das gesammte TableView wenn nen PaintEvent kommt... Das sieht noch beschissener aus als so eine dumme Feldselektierung. Deswegen für Mac raus
         #ifndef Q_OS_MAC
         //Fuer p_veinswb mit der kranken BeforeField/Nextfield Logik über mehrere Zeilen... Sah zwischen den Events einfach scheisse aus mit der Feldselektierung.
         //dk: Temporaer deaktiviert da das DISPLAY ARRAY nicht aktualisiert wird.
         //this->setUpdatesEnabled(false);
         #endif
         this->b_sendevents = b_sendevents;

         //If fieldchange is not emitted, run before field

         if(this->currentIndex() == index && index.column() != -1) {
             Fgl::Event event;
             event.type = Fgl::BEFORE_FIELD_EVENT;
             event.attribute = table->qsl_colNames.at(index.column());
             emit fieldEvent(event);
         }

         selectionModel()->setCurrentIndex(index, QItemSelectionModel::NoUpdate);

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
         }
      }
   }
    
}

void TableView::setText(QString text, int row, int col)
{
MainFrame::vdcdebug("TableView","setText", "QString text, int row, int col");
   if(QSortFilterProxyModel *proxyModel = qobject_cast<QSortFilterProxyModel *> (this->model())){
      Q_UNUSED(proxyModel);
      QModelIndex modelIndex;
      modelIndex = this->model()->index(row, col, QModelIndex());
      if(LineEditDelegate *dele = qobject_cast<LineEditDelegate *> (this->itemDelegateForColumn(col))){
         if(LineEdit *widget = qobject_cast<LineEdit *> (dele->qw_editor)){
            text = Fgl::usingFunc(widget->format(), text, widget->dataType(), widget->picture());
         }
      }

      model()->setData(modelIndex, text, Qt::DisplayRole);
      if(this->currentIndex().column() == modelIndex.column() && this->currentIndex().row() == modelIndex.row())
      {
          QMetaObject::invokeMethod(this->curr_editor, "markup", Qt::QueuedConnection);
      }
   }
}

void TableView::setUnsortedFields(int row,QStringList values)
{
    QVector<QString> myString;
    for(int i=0; i < values.count(); i++)
    {
        myString << values.at(i);
    }
    unsortedFields.insert(row, myString);
}

void TableView::clearUnsortedFields()
{
    unsortedFields.clear();
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

   if(role == Qt::DecorationRole)
   {
       if(index.data().toString().contains(".png") || index.data().toString().contains(".jpg") || index.data().toString().contains(".jpeg") || index.data().toString().contains(".gif"))
       {
           QPixmap pix(":pics/" + index.data().toString());
           return pix;
       }
   }

   if(LineEditDelegate *dele = qobject_cast<LineEditDelegate *> (getTableView()->itemDelegateForColumn(column))){
       if(LineEdit *widget = qobject_cast<LineEdit *> (dele->qw_editor)){
           if(widget->dataType() == 2 || widget->dataType() == 3 || widget->dataType() == 5 || widget->dataType() == 6) {
               if (role == Qt::TextAlignmentRole) {
                   return int(Qt::AlignRight | Qt::AlignVCenter);
               }
           } else {
               if (role == Qt::TextAlignmentRole) {
                   return int(Qt::AlignLeft | Qt::AlignVCenter);
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
       QString buffer = value.toString();
       buffer = buffer.trimmed();
       this->fields[row][column] = buffer;

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

   /*if(getTableView()->isReadOnlyColumn(index.column()) && b_input) {
       f = Qt::NoItemFlags;
       return f;
   }*/

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
    Q_UNUSED(indexes);
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
        QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (getTableView()->model());
        QModelIndex index1 = proxyModel->mapToSource(index);
        text = data(index1, Qt::DisplayRole).toString().trimmed();
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
      QVector<QString> colValues;
      for(int col=0; col < columnCount(QModelIndex()); col++){
         colValues.insert(col, "");
      }
      for(int row=0; row < rows; row++){
         this->fields.insert(position+row, colValues);
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
   if(position > position+rows-1)
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

              beginRemoveRows(QModelIndex(), position, position+rows-1);

              for(int row=0; row < rows; row++){
                 if(this->fields.count() > position)
                 {
                     this->fields.remove(position);
                 }
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

/*QVariant MyFilter::data(const QModelIndex &index, int role) const
{
    if(TableModel *mod = qobject_cast<TableModel*> (sourceModel()))
    {
        return mod->data(index, role);

    }
    else
    {
        Q_D(const QAbstractProxyModel);
        return d->model->data(mapToSource(proxyIndex), role);
    }
    return QVariant();
   }
*/

MyFilter::MyFilter(QWidget *widget)
{
    p_fglform = widget;

}

void MyFilter::sort(int column, Qt::SortOrder order)
{
    if(FglForm *fglform = qobject_cast<FglForm*> (p_fglform))
    {
        if(fglform->mIsSortAllowed)
        {
            QSortFilterProxyModel::sort(column, order);
        }
    }
}

bool MyFilter::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
MainFrame::vdcdebug("MyFilter","lessThan", "const QModelIndex &left, const QModelIndex &right const");

      QVariant v0 = left.data(Qt::DisplayRole);
      QVariant v1 = right.data(Qt::DisplayRole);


      if(TableModel *model = qobject_cast<TableModel*> (sourceModel()))
      {

          if(LineEditDelegate *led = qobject_cast<LineEditDelegate*> (model->getTableView()->itemDelegateForColumn(left.column())))
          {

              if(LineEdit *widget = qobject_cast<LineEdit *> (led->qw_editor)){

                  //Integers
                  if(widget->dataType() == Fgl::DTYPE_SMINT || widget->dataType() == Fgl::DTYPE_INT || widget->dataType() == Fgl::DTYPE_INT8 || widget->dataType() == Fgl::DTYPE_SERIAL || widget->dataType() == Fgl::DTYPE_SERIAL8) {
                      //enum DataType { DTYPE_CHAR, DTYPE_SMINT, DTYPE_INT, DTYPE_FLOAT, DTYPE_SMFLOAT, DTYPE_DECIMAL, DTYPE_SERIAL, DTYPE_DATE, DTYPE_MONEY, DTYPE_NULL, DTYPE_DTIME, DTYPE_BYTE, DTYPE_TEXT, DTYPE_VCHAR, DTYPE_INTERVAL, DTYPE_NCHAR, DTYPE_INT8, DTYPE_SERIAL8}
                      return v0.toInt() < v1.toInt();

              }
                  //Strings + Chars
                  if(widget->dataType() == Fgl::DTYPE_CHAR || widget->dataType() == Fgl::DTYPE_BYTE || widget->dataType() == Fgl::DTYPE_NCHAR || widget->dataType() == Fgl::DTYPE_TEXT || widget->dataType() == Fgl::DTYPE_VCHAR) {
                      //enum DataType { DTYPE_CHAR, DTYPE_SMINT, DTYPE_INT, DTYPE_FLOAT, DTYPE_SMFLOAT, DTYPE_DECIMAL, DTYPE_SERIAL, DTYPE_DATE, DTYPE_MONEY, DTYPE_NULL, DTYPE_DTIME, DTYPE_BYTE, DTYPE_TEXT, DTYPE_VCHAR, DTYPE_INTERVAL, DTYPE_NCHAR, DTYPE_INT8, DTYPE_SERIAL8}
                      return v0.toString().toLower() < v1.toString().toLower();

              }

                  //Decimal + Float + Money
                  if(widget->dataType() == Fgl::DTYPE_FLOAT || widget->dataType() == Fgl::DTYPE_DECIMAL || widget->dataType() == Fgl::DTYPE_MONEY || widget->dataType() == Fgl::DTYPE_SMFLOAT) {
                      //enum DataType { DTYPE_CHAR, DTYPE_SMINT, DTYPE_INT, DTYPE_FLOAT, DTYPE_SMFLOAT, DTYPE_DECIMAL, DTYPE_SERIAL, DTYPE_DATE, DTYPE_MONEY, DTYPE_NULL, DTYPE_DTIME, DTYPE_BYTE, DTYPE_TEXT, DTYPE_VCHAR, DTYPE_INTERVAL, DTYPE_NCHAR, DTYPE_INT8, DTYPE_SERIAL8}
                      return v0.toString().remove(".").replace(",", ".").toFloat() < v1.toString().remove(".").replace(",", ".").toFloat();

              }

                  //Date
                  if(widget->dataType() == Fgl::DTYPE_DATE || widget->dataType() == Fgl::DTYPE_DTIME) {
                      //enum DataType { DTYPE_CHAR, DTYPE_SMINT, DTYPE_INT, DTYPE_FLOAT, DTYPE_SMFLOAT, DTYPE_DECIMAL, DTYPE_SERIAL, DTYPE_DATE, DTYPE_MONEY, DTYPE_NULL, DTYPE_DTIME, DTYPE_BYTE, DTYPE_TEXT, DTYPE_VCHAR, DTYPE_INTERVAL, DTYPE_NCHAR, DTYPE_INT8, DTYPE_SERIAL8}
                      QString s0 = v0.toString();
                      QString s1 = v1.toString();
                      //dateFromString crashed when the string is null
                      if(s0.isEmpty())
                         return true;
                      if(s1.isEmpty())
                         return false;

                      QDate d1 = dateFromString(v0.toString());
                      QDate d2 = dateFromString(v1.toString());
                      return d1 < d2;
              }



              }

          }


       }


      return QSortFilterProxyModel::lessThan(left, right);
}

QVariant MyFilter::headerData(int section, Qt::Orientation orientation, int role) const
{
  return sourceModel()->headerData(section, orientation, role);
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

void LineEditDelegate::textChanged(QString text)
{
    if(FglForm *fglform = qobject_cast<FglForm*> (p_fglform))
    {
        if(TableView *view = qobject_cast<TableView*> (fglform->currentField()))
        {
           if(view->curr_editor && fglform->inputArray())
            {
                if(LineEdit *edit = qobject_cast<LineEdit*> (view->curr_editor))
                {
                    int pos = edit->cursorPosition();
                    view->model()->setData(view->currentIndex(), text);
                    edit->setText(text);
                    edit->setCursorPosition(pos);
                }
            }
        }
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
   const QModelIndex &index) const
{
   QWidget *editor = WidgetHelper::createFormWidget(this->formElement, parent);
   if(TableView *tv = qobject_cast<TableView*> (parent->parentWidget()))
   {
       tv->curr_editor = editor;
       if(ComboBox *n_cb = qobject_cast<ComboBox*> (editor))
       {
           n_cb->setStyleSheet(" QComboBox::drop-down { padding-right: 1px; } ");
          if(LineEditDelegate *le = qobject_cast<LineEditDelegate*> (tv->itemDelegateForColumn(index.column())))
          {
             ComboBox *c_cb = (ComboBox*) le->qw_editor;

             n_cb->setModel(c_cb->model());
          }
       }
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
      if(be->getButtonObj())
      {
          be->getButtonObj()->installEventFilter(p_fglform);
      }
      connect(editor, SIGNAL(textEdited(QString)), this, SLOT(textChanged(QString)));
   }

   if(DateEdit *de = qobject_cast<DateEdit*> (editor))
   {
      if(de->getButtonObj())
      {
          de->getButtonObj()->installEventFilter(p_fglform);
      }
   }
   connect(editor, SIGNAL(fieldEvent(Fgl::Event)), p_fglform, SLOT(fieldEvent(Fgl::Event)));
   connect(this, SIGNAL(nextfield()), p_fglform, SLOT(nextfield()));
   connect(this, SIGNAL(prevfield()), p_fglform, SLOT(prevfield()));
   connect(editor, SIGNAL(textEdited(QString)), p_fglform, SLOT(setBufferTouched()));
   connect(editor, SIGNAL(editingFinished()), p_fglform, SLOT(checkField()));
   connect(editor, SIGNAL(cursorPositionChanged(int, int)), p_fglform, SLOT(setLastCursor(int, int)));


   return editor;
}

void LineEditDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const
{
   QString value = index.model()->data(index, Qt::EditRole).toString();
   if(LineEdit *edit = qobject_cast<LineEdit*> (editor))
   {
       edit->setText(value);
   }
   return;
}


void LineEditDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    //LineEdit *lineEdit = static_cast<LineEdit*>(editor);
    //QString value = WidgetHelper::fieldText(editor); //lineEdit->text();
   QString value;
    if(LineEdit *edit = qobject_cast<LineEdit*> (editor))
    {
       value = edit->text();

        if(value.isEmpty())
        {
            value = WidgetHelper::fieldText(editor);

            switch(edit->dataType())
            {
            case Fgl::DTYPE_CHAR:
            case Fgl::DTYPE_DATE:
            case Fgl::DTYPE_DTIME:
            case Fgl::DTYPE_INT:
            case Fgl::DTYPE_SMINT:
                  value = Fgl::usingFunc(edit->format(), value, edit->dataType(), edit->picture());
                  break;
            default:
                break;
            }
        }
    }

    if(ComboBox *cb =  qobject_cast<ComboBox*> (editor)) {
        value = cb->currentText();
    }

    model->setData(index, value);
}

void LineEditDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(!m_color.isEmpty()) {
        if(index.data().isValid()){
            QStyleOptionViewItem viewOption(option);
            painter->save();
            painter->fillRect(option.rect, VDC::getVentasColor(m_color)); // background color
            painter->restore();
            QStyledItemDelegate::paint(painter, viewOption, index);
        }
    } else {
        QStyledItemDelegate::paint(painter,option,index);
    }
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


//Events sollen im fglform abgefangen werden. Die Signale dürfen nicht zum QStyledItemDelegate Eventfilter, da diese dann
//auf die Steuerung der View zugreift

  if(event->type() == QEvent::KeyPress )
  {
      QKeyEvent *key = (QKeyEvent*) event;

      if(key->key() == Qt::Key_Backtab)
      {
          event->ignore();
          if (TableView *tableView = qobject_cast<TableView*> (parent())) {
             tableView->prevfield();
          }
              return true;
      }

      /*if(key->key() == Qt::Key_Tab || key->key() == Qt::Key_Enter) {
          event->ignore();

          if (TableView *tableView = qobject_cast<TableView*> (parent())) {
             tableView->nextfield();
          }

          return true;
      }

      if(key->key() == Qt::Key_Up) {
          event->ignore();

          if (TableView *tableView = qobject_cast<TableView*> (parent())) {
             tableView->setCurrentField(tableView->currentIndex().row()-1, tableView->currentIndex().column());
          }

          return true;
      }

      if(key->key() == Qt::Key_Down) {
          event->ignore();

          if (TableView *tableView = qobject_cast<TableView*> (parent())) {
             tableView->setCurrentField(tableView->currentIndex().row()+1, tableView->currentIndex().column());
          }

          return true;
      }*/

      if(key->key() == Qt::Key_Left)
      {
          if(LineEdit *edit = qobject_cast<LineEdit*> (object))
          {
              edit->setCursorPosition(edit->cursorPosition()-1);
              return true;
          }
      }
      if(key->key() == Qt::Key_Right)
      {
          if(LineEdit *edit = qobject_cast<LineEdit*> (object))
          {
              if (edit->text().length() < edit->cursorPosition())
              {
                  edit->setCursorPosition(edit->cursorPosition()+1);
                  return true;
              }
          }
      }
   }

  /*(event->type() == QEvent::KeyPress || event->type() == QEvent::KeyRelease)
  {
      QKeyEvent *key = (QKeyEvent*) event;

      if(key->key() == Qt::Key_Down || key->key() == Qt::Key_Up || key->key() == Qt::Key_Tab || key->key() == Qt::Key_Enter || key->key() == Qt::Key_Backtab || key->key() == Qt::Key_Return || key->key() == Qt::Key_Escape)
      {
          QKeyEvent *mykev = new QKeyEvent(key->type(),
                                           key->key(),
                                           key->modifiers(),
                                           key->text(),
                                           key->isAutoRepeat(),
                                           key->count());

         if (TableView *tableView = qobject_cast<TableView*> (parent())) {
            tableView->hasIndexChanged.stop();
         }
         QApplication::postEvent(p_fglform, mykev);
         return true;
      }

          if((event->type() == QEvent::KeyPress || event->type() == 1400) || (event->type() == QEvent::KeyRelease || event->type() == 1401))
      {
          if(FglForm *form = qobject_cast<FglForm*> (p_fglform))
          {
             if(form->b_keybuffer && !form->b_keybufferrunning)
             {
                 if((event->type() == QEvent::KeyRelease || event->type() == 1401) && form->ql_keybuffer.size() < 1)
                 {
                    return true;
                 }

                      QKeyEvent *mykev = new QKeyEvent(key->type(),
                                                       key->key(),
                                                       key->modifiers(),
                                                       key->text(),
                                                       key->isAutoRepeat(),
                                                       key->count());

                     form->ql_keybuffer << mykev;
                     return true;
             }
         }

      }

  }*/

  //Verhindert beim disablen von p_fglform, das der Editor geschlossen wird. Kommt durch synchronisation des
  //Protokolls.


    if(event->type() == QEvent::FocusOut){
      QFocusEvent *fe = (QFocusEvent*) event;
      if(fe->reason() == Qt::ActiveWindowFocusReason ||
         fe->reason() == Qt::OtherFocusReason ||
         fe->reason() == Qt::PopupFocusReason ||
         fe->reason() == Qt::TabFocusReason   ||
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
