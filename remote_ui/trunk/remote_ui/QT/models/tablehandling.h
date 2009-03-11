//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : tablehandling.h
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
#ifndef TABLEHANDLING_H
#define TABLEHANDLING_H

#include <QHeaderView>
#include <QAbstractTableModel>
#include <QTableView>
#include <QTextStream>
#include <QAbstractItemView>
#include <QSortFilterProxyModel>
#include <QDate>
#include <QStringList>
#include <QDebug>
#include <QFile>

// return number represented by a digit character
int intFromChar(QChar);

// assumes dd.mm.yy formatted date
// // idx: 01234567
QDate dateFromString(const QString&);


class MyFilter : public QSortFilterProxyModel
{
   Q_OBJECT

public:

   bool lessThan (const QModelIndex &left, const QModelIndex &right) const;
};



class Table : public QAbstractTableModel
{
public:
    Table(int rows, int columns, QObject *parent = 0);

    int rowCount(const QModelIndex&) const;
    int columnCount(const QModelIndex&) const;
    
    QVariant data(const QModelIndex &index, int role) const;
    
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool load(QStringList);

    QVariant headerData( int section, Qt::Orientation orientation, int role ) const ;

    QStringList qsl_colNames;
    QStringList qsl_fieldNames;
    QVector<QString> v_colTabNames;

    //defines if its an input array or an display array
    bool b_input;
    QString qs_tabName;
private:
    int rows;
    int columns;
    //QHash<QModelIndex,QVariant> displayValues;
    QVector< QVector<QString> >fields;
};

#endif
