//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : table.h
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
#ifndef TABLE_H
#define TABLE_H
#include <QTableView>
#include <QSortFilterProxyModel>
#include <QStyledItemDelegate>
#include <QDate>
#include <QDomElement>
#include <QHeaderView>
#include <models/fglform.h>
#include "vwidgets.h"
#include <include/fgl.h>
#include <QPointer>

class TableView : public QTableView
{
   Q_OBJECT;

public:
   TableView(QWidget *parent = 0);
   bool isReadOnlyColumn(int);
   int pageSize;
   QString tabName;
   int arrCount() { return i_arrCount; };
   int maxArrSize() { return i_maxArrSize; };
   int arrLine() { return i_arrLine; };
   int scrLine() { return i_scrLine; };
   QWidget *p_fglform;
   QList<QLabel*> columnLabels;
   QAction *standardAct;
   QAction *resetAct;
   QAction *restoreSort;
   QPointer<QWidget> curr_editor;
   QAction *columnAct;
   QModelIndex eventfield;
   QModelIndex targetfield;
   /*
   void setViewPalette();
   void restoreViewPalette();
*/
//   void resize();
    bool b_ignoreFocus;
    void setInputEnabled(bool);
    void setColumnLabel(int, Label*);
    QLabel* getColumnLabel(int);
    void setColumnName(int, QString);
    QString getColumnName(int);
    void setArrCount(int cnt);// { i_arrCount = cnt; };
    void setMaxArrSize(int max);// { i_maxArrSize = max; };

    void setIgnoreRowChange(bool b) { b_ignoreRowChange = b; };
    bool ignoreRowChange() { return b_ignoreRowChange; };
    FglForm* getForm() const;
    void setScrLine(int);
    void setArrLine(int);
    void setCurrentColumn(int);
    void setCurrentField(int, int, bool b_sendevents = true);
    void setText(QString, int, int);
    void setAutoRepeat(bool value) { b_isAutoRepeat = value; }
    virtual QSize sizeHint () const;

    void setCurrMouseRow(int);
    int getCurrMouseRow();
    void setCurrMouseColumn(int);
    int getCurrMouseColumn();
    void setMouseModelIndex(QModelIndex);
    QModelIndex getMouseModelIndex();
    bool isAutoRepeat() { return b_isAutoRepeat; }

    void restoreSortOrder();
    void setUnsortedFields(int, QStringList);
    void clearUnsortedFields();

    bool  ignoreFieldChangeEvent;

private:
    int i_arrCount;
    int i_arrLine;
    int i_scrLine;
    int i_maxArrSize;
    bool b_sendevents;
    QVector< QVector<QString> >unsortedFields;
  //  bool b_palette;

    bool b_isAutoRepeat;
    bool b_ignoreRowChange;
    bool checkBounds(const QModelIndex);
    int i_currrowmouse;
    int i_currcolumnmouse;

    /*
    QPalette header;
    QPalette tableview;
    QPalette scrollbars;
*/
public slots:

   void saveSortOrder(int, Qt::SortOrder);
   void fieldChanged(QModelIndex, QModelIndex);
   void accept();
   void setMousePos(QModelIndex);
   void dragSuccess();
   void writeSettings(QAction*);
   void updateSectionWidth(int logicalIndex, int oldSize, int newSize);
   void resetSettings();
   void playkey(QKeyEvent*);
   void copyRow();
   void copyTable();
   void copyCell();
   void copyColumn();
   void insertRow();
   void deleteRow();
   void saveNewSectionOrder(int, int, int);
   void oldSectionOrder();
   void resetSort();

protected:
   QModelIndex mouseindex;
   bool eventFilter(QObject *, QEvent *);

/*
   void nextfield();
   void prevfield();
*/

/*
protected:
 //  void keyPressEvent(QKeyEvent *event);
*/

signals:
   void fieldEvent(Fgl::Event);
   void addToQueue(Fgl::Event);
   void setArrLineSignal(int);
   void accepted();
   void error(QString);
   void nextfield();
   void prevfield();
   
};


class TableModel : public QAbstractTableModel
{
   Q_OBJECT;

public:
    TableModel(int rows, int columns, QObject *parent = 0);
    TableModel(QObject *parent = 0);

    int rowCount(const QModelIndex&) const;
    int columnCount(const QModelIndex&) const;
    
    QVariant data(const QModelIndex &index, int role) const;
    QStringList mimeTypes() const;
    QMimeData* mimeData(const QModelIndexList &indexes) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Qt::ItemFlags flags(const QModelIndex &index) const;

    QVariant headerData( int section, Qt::Orientation orientation, int role ) const ;

    QStringList qsl_colNames;
    QStringList qsl_colTitleNames;
    QStringList qsl_colTitleTabNames;
    QVector<QString> v_colTabNames;
    TableView* getTableView() const{return mytv;}
    void setTableView(TableView*);

    int pageSize() const{return pagesize;}
    void setPageSize(int lines){this->pagesize = lines;}

    bool insertRows(int position, int rows, const QModelIndex &index=QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex());
    //bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex());

    TableView *mytv;
    //defines if its an input array or an display array
    bool b_input;
    QString qs_tabName;
    QHash<int, Label*> qh_colLabels;
    QStringList qsl_a;

    QList<QList<QString> > cb_AddItem;
    QString cb_removeItem;

    QVector< QVector<QString> > getFields() { return fields; }

private:
    int columns;
    int rows;

    int pagesize;

    //QHash<QModelIndex,QVariant> displayValues;
    QVector< QVector<QString> >fields;
    QVector< QVector<QString> >fields5;
//    QHash<int, QHash<int, QString> > fields2;

};

class MyFilter : public QSortFilterProxyModel
{
   Q_OBJECT

public:
    MyFilter(QWidget*);
   bool lessThan (const QModelIndex &left, const QModelIndex &right) const;
   virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;
   void sort(int column, Qt::SortOrder order);
   //virtual QVariant data(const QModelIndex &index, int role) const;
private:
   QWidget *p_fglform;
};

   // return number represented by a digit character
   int intFromChar(QChar);

   // assumes dd.mm.yy formatted date
   // // idx: 01234567
   QDate dateFromString(const QString&);

class LineEditDelegate : public QStyledItemDelegate
{
   Q_OBJECT

public:
   LineEditDelegate(QObject *parent=0);
   LineEditDelegate(QDomElement, QObject *parent=0);

   QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const;

   void setEditorData(QWidget *editor, const QModelIndex &index) const;
   void setModelData(QWidget *editor, QAbstractItemModel *model,
                     const QModelIndex &index) const;

   void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
   void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
   QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
   QSize *fieldSize;

   void setForm(QWidget *form);// {p_fglform = form; };

   void setColor(QString value) { m_color = value; }
   void setColumn(int c) { i_column = c; };
   int column() { return i_column; } ;
   bool readOnly() { return b_readOnly; };
   void setReadOnly(bool value) { b_readOnly = value; };
   QWidget *qw_editor;

protected:
   bool eventFilter(QObject *editor, QEvent *event);

signals:
   void fieldEvent(Fgl::Event, QWidget*);
   void nextfield();
   void prevfield();
public slots:
   void textChanged(QString text);

private:
   QWidget *p_fglform;
   QDomElement formElement;
   QString qs_text;
   bool b_readOnly;

   QString m_color;

   int i_column;
};

#endif
