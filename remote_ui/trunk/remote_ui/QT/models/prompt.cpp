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
#include "mainframe.h"


//------------------------------------------------------------------------------
// Method       : Prompt()
// Filename     : prompt.cpp
// Description  : 
//------------------------------------------------------------------------------
Prompt::Prompt(QWidget *parent, Qt::WindowFlags f) : QDialog(parent, f)
{
MainFrame::vdcdebug("Prompt","Prompt", "QWidget *parent, Qt");

}

//------------------------------------------------------------------------------
// Method       : Prompt()
// Filename     : prompt.cpp
// Description  : 
//------------------------------------------------------------------------------
Prompt::Prompt(QString text, int charMode, int fieldAttribute, QWidget *parent, Qt::WindowFlags f) : QDialog(parent, f)
{
MainFrame::vdcdebug("Prompt","Prompt", "QString text, int charMode, int fieldAttribute, QWidget *parent, Qt");
  isAccepted = false;
  //this->setWindowFlags(Qt::Dialog);

  //dont let other windows get Focus
  this->setModal(true);

  this->isCharOnlyMode=charMode;

  //add a Layout
  this->layout = new QHBoxLayout;
  this->setLayout(layout);

  //also create a Label with the text
  QLabel *p_label = new QLabel(text);
  layout->addWidget(p_label);

  //create Input Field
  p_lineEdit = new LineEdit;

  WidgetHelper::setDisplayAttributes(fieldAttribute, p_lineEdit);


  layout->addWidget(p_lineEdit);
  p_lineEdit->setEnabled(true);
  p_lineEdit->setFocus();




   if (this->isCharOnlyMode) {
		connect(p_lineEdit, SIGNAL( textChanged( const QString& ) ), this, SLOT( promptLineEditTextChanged( const QString& ) ) );
   }



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
MainFrame::vdcdebug("Prompt","keyPressEvent", "QKeyEvent *event");

   if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
      isAccepted = true;
      this->close();
   }

   if(event->key() == Qt::Key_Escape){
      this->close();
   }


   return QDialog::keyPressEvent(event);

}

void Prompt::promptLineEditTextChanged(const QString &text) {
  Q_UNUSED(text);
      isAccepted = true;
      this->close();

}

void Prompt::closeEvent(QCloseEvent *event)
{
MainFrame::vdcdebug("Prompt","closeEvent", "QCloseEvent *event");
   if(this->isVisible()){
      QDomDocument doc;
      QDomElement triggered = doc.createElement("TRIGGERED");
      doc.appendChild(triggered);

      if(isAccepted){
         triggered.setAttribute("ID", "ACCEPT");
  
         QDomElement syncValues = doc.createElement("SVS");
         triggered.appendChild(syncValues);

         QDomElement syncValue = doc.createElement("SV");
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
