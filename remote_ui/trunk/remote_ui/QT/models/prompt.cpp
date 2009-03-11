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
Prompt::Prompt(QString text, int charMode, QWidget *parent, Qt::WindowFlags f) : QDialog(parent, f)
{
  this->setWindowFlags(Qt::Dialog);

  //dont let other windows get Focus
  this->setModal(true);

  //add a Layout
  this->layout = new QHBoxLayout;
  this->setLayout(layout);

  //also create a Label with the text
  Label *p_label = new Label(text);
  layout->addWidget(p_label);

  //create Input Field
  p_lineEdit = new LineEdit;
  p_lineEdit->setEnabled(true);
  p_lineEdit->setFocus();
  layout->addWidget(p_lineEdit);

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

      QDomDocument doc;
      QDomElement triggered = doc.createElement("TRIGGERED");
      triggered.setAttribute("ID", "ACCEPT");
      doc.appendChild(triggered);

      QDomElement syncValues = doc.createElement("SYNCVALUES");
      triggered.appendChild(syncValues);

      QDomElement syncValue = doc.createElement("SYNCVALUE");
      if(!p_lineEdit->text().isNull()){
         syncValue.appendChild(doc.createTextNode(p_lineEdit->text()));
      }
      syncValues.appendChild(syncValue);

      emit sendDirect(doc.toString());

   }

   if(event->key() == Qt::Key_Escape){
      QDomDocument doc;
      QDomElement triggered = doc.createElement("TRIGGERED");
      triggered.setAttribute("ID", "INTERRUPT");
      doc.appendChild(triggered);
      emit sendDirect(doc.toString());
   }

   QDialog::keyPressEvent(event);
}
