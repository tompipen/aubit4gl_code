//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : matrix.cpp
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
#include <QDebug>
#include <QKeyEvent>
#include <QSpacerItem>

#include "matrix.h"
#include "vwidgets.h"


//------------------------------------------------------------------------------
// Method       : Matrix()
// Filename     : matrix.cpp
// Description  : Constructs the Matrix for the MenuButtons
//------------------------------------------------------------------------------
Matrix::Matrix(QWidget *parent) : QGroupBox(parent)
{
MainFrame::vdcdebug("Matrix","Matrix", "QWidget *parent");
   b_input = false;
   this->setAlignment(Qt::AlignTop);
   // disable widget until it it gets called
   this->setEnabled(false);

   QVBoxLayout *layout = new QVBoxLayout;
   layout->setAlignment(Qt::AlignTop);
   layout->setSpacing(0);
   layout->setMargin(0);

   this->layout = layout;
   setLayout(this->layout);
}

//------------------------------------------------------------------------------
// Method       : Matrix()
// Filename     : matrix.cpp
// Description  : Constructs the Matrix for the MenuButtons
//------------------------------------------------------------------------------
Matrix::Matrix(QString title, QString style, QString image, 
                   QWidget *parent) : QGroupBox(title, parent)
{
   b_input = false;

   if(!style.isEmpty()){
      this->setProperty("menuStyle", style);
   }

   this->setAlignment(Qt::AlignRight | Qt::AlignTop);
   // disable widget until it it gets called
   this->setEnabled(false);
   this->setVisible(false);

   // TODO: Layout is set by style
   if(style == "TODO"){
   }


   QVBoxLayout *layout = new QVBoxLayout;
   layout->setAlignment(Qt::AlignTop);
   layout->setSpacing(0);
   layout->setMargin(0);

   this->layout = layout;
   setLayout(this->layout);

}

void Matrix::addWidget(QWidget* widget)
{
MainFrame::vdcdebug("Matrix","addWidget", "QWidget* widget");
   ql_fields << widget;
   layout->addWidget(widget);
}

void Matrix::focusInEvent(QFocusEvent* event)
{
MainFrame::vdcdebug("Matrix","focusInEvent", "QFocusEvent* event");
   this->focusNextChild();
   return QGroupBox::focusInEvent(event);
}

bool Matrix::eventFilter(QObject *obj, QEvent *event)
{
MainFrame::vdcdebug("Matrix","eventFilter", "QObject *obj, QEvent *event");
   return QGroupBox::eventFilter(obj, event);
}

void Matrix::setMenuStyle(const QString &ms)
{
MainFrame::vdcdebug("Matrix","setMenuStyle", "const QString &ms");
   if(ms == "none"){
      this->setVisible(false);
   }
}

void Matrix::setOrientation(const Qt::Orientation &o){

   if(QBoxLayout *layout = qobject_cast<QBoxLayout *> (this->layout)){
      if(o == Qt::Horizontal){
         layout->setDirection(QBoxLayout::TopToBottom);
      }
      else{
         if(o == Qt::Vertical) layout->setDirection(QBoxLayout::LeftToRight);
      }
   }
}

void Matrix::setEnabled(bool enable)
{
MainFrame::vdcdebug("Matrix","setEnabled", "bool enable");

   if(b_input){
      for(int i=0; i<ql_fields.count(); i++){
         ql_fields.at(i)->setEnabled(enable);
      }
   }
   QWidget::setEnabled(enable);

}

void Matrix::setText(int row, QString value)
{
MainFrame::vdcdebug("Matrix","setText", "int row, QString value");

   if(ql_fields.count() < row) 
      return;

   WidgetHelper::setFieldText(ql_fields.at(row), value);

}

QString Matrix::text(int row)
{
MainFrame::vdcdebug("Matrix","text", "int row");

   if(ql_fields.count() < row) 
      return "";

   return WidgetHelper::fieldText(ql_fields.at(row));

}
