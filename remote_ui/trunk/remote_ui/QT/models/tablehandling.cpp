//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : tablehandling.cpp
// Description  : contains class definition for the ActionMenu
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
#include <QLineEdit>
#include <QLabel>
#include "tablehandling.h"

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

Table::Table(int rows, int columns, QObject *parent) : QAbstractTableModel(parent), rows(rows), columns(columns)
{
   b_input = false;
}

int Table::rowCount(const QModelIndex&) const { return rows; }

int Table::columnCount(const QModelIndex&) const { return columns; }

QVariant Table::data(const QModelIndex &index, int role) const
{
   int row = index.row();
   int column = index.column();
   if (role == Qt::DisplayRole || role == Qt::EditRole)
   {
      if(fields.count() > row){
         if(fields[row].count() > column){
            QString s = fields[row][column];
            return s;
         }
      }

   }else{
      //Job 18105: Align Text Left and Int Right
      if(role == Qt::TextAlignmentRole){
         bool ok;
         if(fields.count() > row){
            if(fields[row].count() > column){
               if(fields[row][column].toInt(&ok,10) && ok){
                  //return Qt::AlignRight;
                  return Qt::AlignLeft;
               }
               else{
                  return Qt::AlignLeft;
               }
            }
         }
      }

      //return QAbstractTableModel::data(index, role);
      return QVariant();   // hier sollte man den Datentyp der Spalte aus der
                           // xml-Maske auswerten und je nachdem auch Int o.ae.
                           // zurueckgeben (damit die Sortierung (z.b. Datum,
                           // Zahlen) richtig wird)
   }

   return QVariant();

}

bool Table::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && ( role == Qt::EditRole || role == Qt::DisplayRole ))
    {
       int row = index.row();
       int column = index.column();

       fields[row][column] = value.toString();
       emit dataChanged ( index,index );
       return true;
    }
    return false;
}

Qt::ItemFlags Table::flags(const QModelIndex &index) const
{
   Qt::ItemFlags f = QAbstractTableModel::flags(index);
   if (index.isValid() && b_input) f |= Qt::ItemIsEditable;
      return f;
}

bool Table::load(QStringList qsl_screenRecValues)
{
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

            fields.append(v);
      }
   }

      for(int i=fields.count(); i<rows; i++){
         for(int i=0; i<columns; i++){
            v[i] = QString();
         }
         fields.append(v);
      }

   for(int i=0; i<columns; i++){
      qsl_colNames << QString().number(i+1);
   }

   return true;

}

QVariant Table::headerData ( int section, Qt::Orientation orientation, int role ) const
{
   if ( role != Qt::DisplayRole )
      return QVariant();

   if ( orientation == Qt::Horizontal )
   {
      if(section < qsl_colNames.size()){
            return qsl_colNames.at(section);
      }
   }
   else{
      return section;
   }

   return QVariant();
}
