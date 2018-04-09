//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : matrix.h
// Description  : contains class definition for the Matrix
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
#ifndef MATRIX_H
#define MATRIX_H

#include <QGroupBox>
#include <QLayout>

class Matrix : public QGroupBox
{
   Q_OBJECT

   Q_PROPERTY(QString menuStyle
              READ getMenuStyle
              WRITE setMenuStyle
              DESIGNABLE true)


public:
   Matrix(QWidget *parent = 0);
   Matrix(QString title, QString style = "", QString image = "", QWidget *parent = 0);

   void addWidget(QWidget*);


   QString getMenuStyle() const { return m_menuStyle; };
   void setMenuStyle(const QString &ms);
   void setOrientation(const Qt::Orientation &o);
   void setEnabled(bool);
   void setText(int, QString);
   QString text(int);
   void setInputEnabled(bool en) { b_input = en; };
   int arrCount() { return ql_fields.count(); };


private:
   QLayout* layout;
   QString m_menuStyle;
   bool b_input;

   QList<QWidget*> ql_fields;

protected:
   bool eventFilter(QObject *obj, QEvent *event);
   void focusInEvent(QFocusEvent*);
};
#endif
