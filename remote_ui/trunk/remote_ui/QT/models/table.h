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

#include "vwidgets.h"
#include <include/fgl.h>

class TableView : public QTableView
{
   Q_OBJECT;

public:
   TableView(QWidget *parent = 0);
   int pageSize;
   QString tabName;
   int arrCount() { return i_arrCount; };
   int maxArrSize() { return i_maxArrSize; };
   int arrLine() { return i_arrLine; };
   int scrLine() { return i_scrLine; };

    void setInputEnabled(bool);
    void setColumnLabel(int, Label*);
    QLabel* getColumnLabel(int);
    void setColumnName(int, QString);
    QString getColumnName(int);
    void setArrCount(int cnt);// { i_arrCount = cnt; };
    void setMaxArrSize(int max);// { i_maxArrSize = max; };

    void setIgnoreRowChange(bool b) { b_ignoreRowChange = b; };
    bool ignoreRowChange() { return b_ignoreRowChange; };

private:
    int i_arrCount;
    int i_arrLine;
    int i_scrLine;
    int i_maxArrSize;
    bool b_ignoreFocus;
    bool b_ignoreRowChange;

public slots:
   void fieldChanged(QModelIndex, QModelIndex);
   void accept();
   void nextfield();
   void prevfield();

protected:
   void keyPressEvent(QKeyEvent *event);
   bool eventFilter(QObject*, QEvent*);

signals:
   void fieldEvent(Fgl::Event);
   void setArrLine(int);
   void accepted();
   
};


class TableModel : public QAbstractTableModel
{
public:
    TableModel(int rows, int columns, QObject *parent = 0);
    TableModel(QObject *parent = 0);

    int rowCount(const QModelIndex&) const;
    int columnCount(const QModelIndex&) const;
    
    QVariant data(const QModelIndex &index, int role) const;
    
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool load(QStringList);

    QVariant headerData( int section, Qt::Orientation orientation, int role ) const ;

    QStringList qsl_colNames;
    QStringList qsl_colTitleNames;
    QStringList qsl_colTitleTabNames;
    QVector<QString> v_colTabNames;

    bool insertRows(int position, int rows, const QModelIndex &index=QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex());
    //bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex());


    //defines if its an input array or an display array
    bool b_input;
    QString qs_tabName;
    QHash<int, Label*> qh_colLabels;
    QStringList qsl_a;

private:
    int columns;
    int rows;
    //QHash<QModelIndex,QVariant> displayValues;
    QVector< QVector<QString> >fields;
    QVector< QVector<QString> >fields5;
//    QHash<int, QHash<int, QString> > fields2;

};

class MyFilter : public QSortFilterProxyModel
{
   Q_OBJECT

public:
   bool lessThan (const QModelIndex &left, const QModelIndex &right) const;
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

   void updateEditorGeometry(QWidget *editor,
   const QStyleOptionViewItem &option, const QModelIndex &index) const;
   QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
   QSize *fieldSize;

   void setForm(QWidget *form);// {p_fglform = form; };

   void setColumn(int c) { i_column = c; };
   int column() { return i_column; } ;

protected:
   bool eventFilter(QObject *editor, QEvent *event);

signals:
   void fieldEvent(Fgl::Event, QWidget*);

public slots:
   void sendEvent(QString);

private:
   QWidget *p_fglform;
   QDomElement formElement;
   QString qs_text;

   int i_column;
};

#endif
