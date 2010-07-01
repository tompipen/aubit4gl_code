//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : prompt.cpp
// Description  : contains class definition for the RingMenu
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
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>

#include "prompt.h"
#include "include/fgl.h"

//------------------------------------------------------------------------------
// Method       : Prompt()
// Filename     : prompt.cpp
// Description  : 
//------------------------------------------------------------------------------
Prompt::Prompt(QWidget *parent, Qt::WindowFlags f) : QDialog(parent, f)
{

}

//------------------------------------------------------------------------------
// Method       : Prompt()
// Filename     : prompt.cpp
// Description  : 
//------------------------------------------------------------------------------
Prompt::Prompt(QString text, int charMode, int fieldAttribute, QWidget *parent, Qt::WindowFlags f) : QDialog(parent, f)
{
  Q_UNUSED(charMode);
  isAccepted = false;
  //this->setWindowFlags(Qt::Dialog);

  //dont let other windows get Focus
  this->setModal(true);

  //add a Layout
  this->layout = new QHBoxLayout;
  this->setLayout(layout);

  //also create a Label with the text
  QLabel *p_label = new QLabel(text);
  layout->addWidget(p_label);

  //create Input Field
  p_lineEdit = new QLineEdit;

  switch(fieldAttribute) {
     case Fgl::AUBIT_COLOR_BLACK:
          {
          QPalette p = p_lineEdit->palette();
          QColor col("black");
          p.setColor(QPalette::Active, QPalette::Text, col);
          p_lineEdit->setPalette(p);
          }
          break;
     case Fgl::AUBIT_COLOR_RED:
          {
          QPalette p = p_lineEdit->palette();
          QColor col("red");
          p.setColor(QPalette::Active, QPalette::Text, col);
          p_lineEdit->setPalette(p);
          }
          break;
     case Fgl::AUBIT_COLOR_GREEN:
          {
          QPalette p = p_lineEdit->palette();
          QColor col("green");
          p.setColor(QPalette::Active, QPalette::Text, col);
          p_lineEdit->setPalette(p);
          }
          break;
     case Fgl::AUBIT_COLOR_YELLOW:
          {
          QPalette p = p_lineEdit->palette();
          QColor col("yellow");
          p.setColor(QPalette::Active, QPalette::Text, col);
          p_lineEdit->setPalette(p);
          }
          break;
     case Fgl::AUBIT_COLOR_BLUE:
          {
          QPalette p = p_lineEdit->palette();
          QColor col("blue");
          p.setColor(QPalette::Active, QPalette::Text, col);
          p_lineEdit->setPalette(p);
          }
          break;
     case Fgl::AUBIT_COLOR_MAGENTA:
          {
          QPalette p = p_lineEdit->palette();
          QColor col("magenta");
          p.setColor(QPalette::Active, QPalette::Text, col);
          p_lineEdit->setPalette(p);
          }
          break;
     case Fgl::AUBIT_COLOR_CYAN:
          {
          QPalette p = p_lineEdit->palette();
          QColor col("cyan");
          p.setColor(QPalette::Active, QPalette::Text, col);
          p_lineEdit->setPalette(p);
          }
          break;
     case Fgl::AUBIT_COLOR_WHITE:
          {
          QPalette p = p_lineEdit->palette();
          QColor col("white");
          p.setColor(QPalette::Active, QPalette::Text, col);
          p_lineEdit->setPalette(p);
          }
          break;
     case Fgl::AUBIT_ATTR_REVERSE:
          {
          }
          break;
     case Fgl::AUBIT_ATTR_UNDERLINE:
          {
          QFont font = p_lineEdit->font();
          font.setUnderline(true);
          p_lineEdit->setFont(font);
          }
          break;
     case Fgl::AUBIT_ATTR_BOLD:
          {
          QFont font = p_lineEdit->font();
          font.setBold(true);
          p_lineEdit->setFont(font);
          }
          break;
     case Fgl::AUBIT_ATTR_BLINK:
          {
          }
          break;
     case Fgl::AUBIT_ATTR_DIM:
          {
          QFont font = p_lineEdit->font();
          font.setBold(true);
          p_lineEdit->setFont(font);
          }
          break;
     case Fgl::AUBIT_ATTR_INVISIBLE:
          p_lineEdit->setEchoMode(QLineEdit::Password);
          break;
     case Fgl::AUBIT_ATTR_ALTCHARSET:
          {
          }
          break;
     case Fgl::AUBIT_ATTR_LEFT:
          {
          }
          break;
  };

  layout->addWidget(p_lineEdit);
  p_lineEdit->setEnabled(true);
  p_lineEdit->setFocus();

  //show the Prompt
  this->show();
}

//------------------------------------------------------------------------------
// Method       : keyPressEvent()
// Filename     : prompt.cpp
// Description  : 
//                
//------------------------------------------------------------------------------
void Prompt::keyPressEvent(QKeyEvent *event)
{
   if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
      isAccepted = true;
      this->close();
   }

   if(event->key() == Qt::Key_Escape){
      this->close();
   }

   return QDialog::keyPressEvent(event);

}

void Prompt::closeEvent(QCloseEvent *event)
{
   if(this->isVisible()){
      QDomDocument doc;
      QDomElement triggered = doc.createElement("TRIGGERED");
      doc.appendChild(triggered);

      if(isAccepted){
         triggered.setAttribute("ID", "ACCEPT");
  
         QDomElement syncValues = doc.createElement("SYNCVALUES");
         triggered.appendChild(syncValues);

         QDomElement syncValue = doc.createElement("SYNCVALUE");
         if(!p_lineEdit->text().isNull()){
            syncValue.appendChild(doc.createTextNode(p_lineEdit->text()));
         }
         syncValues.appendChild(syncValue);
      }
      else{
         triggered.setAttribute("ID", "INTERRUPT");
      }

      emit sendDirect(doc.toString());

    }
    event->accept();
}
