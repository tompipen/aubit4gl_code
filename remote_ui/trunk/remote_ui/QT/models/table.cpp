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

#include "table.h"

TableView::TableView(QWidget *parent) : QTableView(parent)
{
   this->setFocusPolicy(Qt::NoFocus);
   this->installEventFilter(this);
   i_arrCount = 0;
   i_arrLine = 0;
   i_scrLine = 0;
   i_maxArrSize = 0;
   b_ignoreFocus = false;
   b_ignoreRowChange = false;

   const int rowHeight = fontMetrics().height() + 2;
   verticalHeader()->setDefaultSectionSize(rowHeight);

   setTabKeyNavigation(true);
   this->verticalHeader()->hide();
   QHeaderView *header = this->horizontalHeader();
   header->setMovable(true);
   header->setClickable(true);
   header->setSortIndicatorShown(true);
   header->setSortIndicator(0, Qt::AscendingOrder);

   connect(this, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(accept()));

   QObject::connect(header, SIGNAL(sectionClicked(int)),
                    this, SLOT(sortByColumn(int)));

   QObject::disconnect(header, SIGNAL(sectionPressed(int)),
                       this, SLOT(selectColumn(int)));

   this->setInputEnabled(false);
   this->setEnabled(false);
}

void TableView::setArrCount(int cnt)
{

   i_arrCount = cnt;

   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

   if(i_arrCount > table->rowCount(QModelIndex())){
      int newRows = i_arrCount - table->rowCount(QModelIndex());
      table->insertRows(table->rowCount(QModelIndex()), newRows, QModelIndex());
   }
   else{
      if(i_arrCount < table->rowCount(QModelIndex()) && i_arrCount > 0){
         int newRows = table->rowCount(QModelIndex()) - i_arrCount;
         table->removeRows(i_arrCount-1, newRows, QModelIndex());
      }
   }

}

bool TableView::eventFilter(QObject *object, QEvent *event)
{
   return QTableView::eventFilter(object, event);
}

void TableView::setMaxArrSize(int cnt)
{

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

   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

   table->qh_colLabels[col] = label;
}

QLabel* TableView::getColumnLabel(int col)
{

   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

   return table->qh_colLabels[col];
}

void TableView::setColumnName(int col, QString name)
{

   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

   if(table->qsl_colNames.count()-1 >= col){
      table->qsl_colNames.removeAt(col);
   }
   table->qsl_colNames.insert(col,name);
}

QString TableView::getColumnName(int col)
{

   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

   if(table->qsl_colNames.count()-1 >= col){
      return table->qsl_colNames[col];
   }

   return QString();
}

void TableView::keyPressEvent(QKeyEvent *event)
{
   if(event->key() == QKeySequence("Enter") ||
      event->key() == QKeySequence("Return")){
      accept();
   }
   return QTableView::keyPressEvent(event);
}

void TableView::accept()
{
   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
   if(!table->b_input){
      emit accepted();
   }
   else{
      b_ignoreFocus = true;
      nextfield();
   }
}

void TableView::nextfield()
{
   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

   if(table->b_input){
      this->focusNextChild();
   }
   else{
      int currentRow = currentIndex().row();
      int rowCount = table->rowCount(QModelIndex());

      if(currentRow <= rowCount){
         selectRow(currentRow+1);
      }
   }
}

void TableView::prevfield()
{
   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

   if(table->b_input){
      this->focusNextChild();
   }
   else{
      int currentRow = currentIndex().row();

      if(currentRow > 0){
         selectRow(currentRow-1);
      }
   }
}

void TableView::setInputEnabled(bool enable)
{ 
   if(enable){
      this->setSelectionBehavior(QAbstractItemView::SelectItems);
      this->setSelectionMode(QAbstractItemView::NoSelection);
      this->setEditTriggers(QAbstractItemView::AllEditTriggers);
      this->setShowGrid(true);
      this->setAlternatingRowColors(false);
   }
   else{
      this->setSelectionBehavior(QAbstractItemView::SelectRows);
      this->setSelectionMode(QAbstractItemView::SingleSelection);
      this->setEditTriggers(QAbstractItemView::NoEditTriggers);
      this->setShowGrid(false);
      this->setAlternatingRowColors(true);
   }

   if(this->model() != NULL){
      QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
      TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());
      table->b_input = enable;
      QItemSelectionModel *selection = this->selectionModel();
      QModelIndex index = table->index(0,0, QModelIndex());
      selection->select(index, QItemSelectionModel::Clear);
   }
}

void TableView::fieldChanged(QModelIndex current, QModelIndex prev)
{
   QSortFilterProxyModel *proxyModel = static_cast<QSortFilterProxyModel*> (this->model());
   TableModel *table = static_cast<TableModel*> (proxyModel->sourceModel());

   Fgl::Event event;

   if(prev.column() > -1){
      // ignore field event if the before field was also ignored
      if(!b_ignoreFocus){
         event.type = Fgl::AFTER_FIELD_EVENT;
         event.attribute = table->qsl_colNames.at(prev.column());
         emit fieldEvent(event);
      }
      else{
         b_ignoreFocus = false;
      }
   }

   if(current.row() != prev.row()){
      if(prev.row() > -1){
         if(!b_ignoreRowChange){
            emit setArrLine(current.row()+1);
            event.type = Fgl::AFTER_ROW_EVENT;
            emit fieldEvent(event);
         }

         if(current.row()+1 > i_arrCount){
            i_arrCount = current.row()+1;
         }
      }

      if(current.row() > -1){
         if(!b_ignoreRowChange){
            emit setArrLine(current.row()+1);
            event.type = Fgl::BEFORE_ROW_EVENT;
            emit fieldEvent(event);
            i_arrLine = current.row()+1;
            i_scrLine = current.row()+1;
         }
      }
   }

   if(current.column() > -1 && current.row() > -1){
      // only allow focus for fields that have a focus policy
      if(this->focusWidget() != NULL){
         if(this->focusWidget()->focusPolicy() != Qt::NoFocus){
            event.type = Fgl::BEFORE_FIELD_EVENT;
            event.attribute = table->qsl_colNames.at(current.column());
            emit fieldEvent(event);
         }
         else{
            // if field has no focus policy then it should not get the focus!
            // set ignore = true so the after field event also does not get triggered
            b_ignoreFocus = true;
            if(table->b_input){
               this->focusNextChild();
            }
         }
      }
   }
}

TableModel::TableModel(int rows, int columns, QObject *parent) : QAbstractTableModel(parent), columns(columns)
{
   this->rows = 0;
   for(int i=0; i<rows; i++){
      insertRows(i, 1, QModelIndex());
   }

   b_input = true;
}

TableModel::TableModel(QObject *parent) : QAbstractTableModel(parent)
{
   b_input = true;
   this->columns = 0;
}

int TableModel::rowCount(const QModelIndex&) const { return this->rows; }//fields2.count(); }

int TableModel::columnCount(const QModelIndex&) const { return columns; }

QVariant TableModel::data(const QModelIndex &index, int role) const
{
   int row = index.row();
   int column = index.column();

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
   Qt::ItemFlags f = QAbstractTableModel::flags(index);
   if (index.isValid()){
      f = Qt::ItemIsEnabled;
      f |= b_input ? Qt::ItemIsEditable : Qt::ItemIsSelectable;
   }

   return f;
}

bool TableModel::load(QStringList qsl_screenRecValues)
{
   return false;

   QVector<QString> v(columns);

   for(int i=0;i<qsl_screenRecValues.count();i+=columns) {
      if(i+columns<=qsl_screenRecValues.count()){
         int idx = 0;
         for(int k=0;k<columns;k++){
            v[idx] = qsl_screenRecValues.at(i+k);
            idx++;
         }

         bool isNullRow = true;
         for(int k=0;k<columns;k++){
            if(v[k].size()>0)
               isNullRow=false;
         }

         if(!isNullRow){
            this->fields.append(v);
         }
      }
   }

   for(int i=0; i<columns; i++){
      qsl_colNames << QString().number(i+1);
   }

   for(int i=0; i<this->fields.count(); i++){
      if(i >= rows && i >= this->rows){
         insertRows(i, 1, QModelIndex());
      }
   }

   if(this->rows > this->fields.count()){
      for(int i=this->rows; i>this->fields.count(); i--){
         removeRows(i, 1, QModelIndex());
      }
   }
   return true;


   return false;

   int rows = this->rows;

   for(int i=0;i<qsl_screenRecValues.count();i+=columns) {
      if(i+columns<=qsl_screenRecValues.count()){
         int idx = 0;
         for(int k=0;k<columns;k++){
            v[idx] = qsl_screenRecValues.at(i+k);
            idx++;
         }

         bool isNullRow = true;
         for(int k=0;k<columns;k++){
            if(v[k].size()>0)
               isNullRow=false;
         }

         if(!isNullRow){
            this->fields.append(v);
         }
      }
   }

   for(int i=0; i<columns; i++){
      qsl_colNames << QString().number(i+1);
   }

   for(int i=0; i<this->fields.count(); i++){
      if(i >= rows && i >= this->rows){
         insertRows(i, 1, QModelIndex());
      }
      for(int j=0; j<this->fields[i].count(); j++){
      }
   }

   if(this->rows > this->fields.count()){
      for(int i=this->rows; i>this->fields.count(); i--){
         removeRows(i, 1, QModelIndex());
      }
   }
   return true;

}

bool TableModel::insertRows(int position, int rows, const QModelIndex &index)
{
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
   if(this->rows > 0 && this->fields.count() > position+rows){

      beginRemoveRows(QModelIndex(), position, position+rows-1);
      this->rows -= rows;
      this->fields.remove(position);
      endRemoveRows();

      return true;
   }

   return false;

}




QVariant TableModel::headerData ( int section, Qt::Orientation orientation, int role ) const
{
   if ( role != Qt::DisplayRole )
      return QVariant();

   if ( orientation == Qt::Horizontal )
   {
      if(qh_colLabels[section] != NULL){
         return qh_colLabels[section]->text();
      }
   }
   else{
      return section;
   }

   return QVariant();
}

bool MyFilter::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
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
}

QSize LineEditDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
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
   editor->setAutoFillBackground(true);
   
   editor->setEnabled(true);
   //remove borders from inputfields in inputarray
   QString className = editor->metaObject()->className();
   QString style = QString("%0 { border-top-width: 0; border-top-style: none; border-bottom-width: 0; border-bottom-style: none; }").arg(className);
   editor->setStyleSheet(style);

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

void LineEditDelegate::sendEvent(QString id)
{
   //emit fieldEvent(id);
}

void LineEditDelegate::setForm(QWidget *form)
{
   p_fglform = form;
   //connect(this, SIGNAL(fieldEvent(Fgl::Event, QWidget*)), p_fglform, SLOT(fieldEvent(Fgl::Event, QWidget*)));
}

bool LineEditDelegate::eventFilter(QObject *object, QEvent *event)
{
   if(event->type() == QEvent::FocusOut){
      QFocusEvent *fe = (QFocusEvent*) event;
      if(fe->reason() == Qt::ActiveWindowFocusReason ||
         fe->reason() == Qt::PopupFocusReason){
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

