//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : ringmenu.cpp
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

#include "dialog.h"

//------------------------------------------------------------------------------
// Method       : Dialog()
// Filename     : dialog.cpp
// Description  : Constructs the RingMenu for the MenuButtons
//------------------------------------------------------------------------------
Dialog::Dialog(QWidget *parent, Qt::WindowFlags f) : QDialog(parent, f)
{

}

//------------------------------------------------------------------------------
// Method       : Dialog()
// Filename     : dialog.cpp
// Description  : Constructs the RingMenu for the MenuButtons
//------------------------------------------------------------------------------
Dialog::Dialog(QString title, QString comment, QString style, QString image,
               QWidget *parent, Qt::WindowFlags f) : QDialog(parent, f)
{

   this->setAttribute(Qt::WA_DeleteOnClose);

   QVBoxLayout *layout = new QVBoxLayout;
   QHBoxLayout *buttonLayout = new QHBoxLayout;
   buttonLayout->setAlignment(Qt::AlignCenter);

   buttonGroup = new QButtonGroup;
   connect(buttonGroup, SIGNAL(buttonClicked(int)),
           this, SLOT(buttonClicked(int)));


   this->layout = layout;
   setLayout(this->layout);
   this->layout->setAlignment(Qt::AlignTop);
   this->buttonLayout = buttonLayout;
 
   this->setWindowTitle(title);

   QHBoxLayout *pixLayout = new QHBoxLayout;

   QLabel *p_label    = new QLabel(comment);
   QLabel *p_pixLabel = new QLabel();
   QString filename   = "./pics/";

   filename.append(image);
   filename.append(".png");

   p_pixLabel->setPixmap(filename);
   pixLayout->addWidget(p_pixLabel);
   pixLayout->addWidget(p_label);
   pixLayout->addStretch();

   layout->addLayout(pixLayout);

   layout->addLayout(buttonLayout);

   this->setModal(true);
   this->adjustSize();
}

//------------------------------------------------------------------------------
// Method       : createButton()
// Filename     : dialog.cpp
// Description  : creates the Buttons and adds them to the RingMenu
//------------------------------------------------------------------------------
void Dialog::createButton(int id, QString text, QString tooltip)
{

   // Make Shortcut for Button
   QString shortcut = text.at(0);
   text.prepend("&");

   // Create the Button and set Text + ToolTip
   QPushButton *button = new QPushButton(text);
   button->setShortcut(shortcut);
   button->setToolTip(tooltip);


   // Add the Button to the Layout
   if(QHBoxLayout *layout = qobject_cast<QHBoxLayout *> (this->layout)){
      buttonLayout->addWidget(button);
   }

   if(QVBoxLayout *layout = qobject_cast<QVBoxLayout *> (this->layout)){
      buttonLayout->addWidget(button);
   }

   buttonGroup->addButton(button, id);
}

//------------------------------------------------------------------------------
// Method       : createAction()
// Filename     : dialog.cpp
// Description  : creates the Buttons and adds them to the RingMenu
//------------------------------------------------------------------------------
void Dialog::createAction(int id, QString text)
{

   // Create the Button and set Text + ToolTip
   QPushButton *button = new QPushButton(text);
   button->setVisible(false);

   // Add the Button to the Layout
   if(QHBoxLayout *layout = qobject_cast<QHBoxLayout *> (this->layout)){
      buttonLayout->addWidget(button);
   }

   if(QVBoxLayout *layout = qobject_cast<QVBoxLayout *> (this->layout)){
      buttonLayout->addWidget(button);
   }

   buttonGroup->addButton(button, id);
}

//------------------------------------------------------------------------------
// Method       : hideButton()
// Filename     : ringmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void Dialog::hideButton(int id)
{
   //TODO Implement
}

//------------------------------------------------------------------------------
// Method       : hideButton()
// Filename     : ringmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void Dialog::hideButton(QString name)
{
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      QPushButton *button = (QPushButton*) buttonGroup->buttons().at(i);
      QString text = button->text().remove(0,1);

      if(text == name)
         button->setVisible(false);
   }
   this->adjustSize();
}

//------------------------------------------------------------------------------
// Method       : hideButton()
// Filename     : ringmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void Dialog::showButton(QString name)
{
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      QPushButton *button = (QPushButton*) buttonGroup->buttons().at(i);
      QString text = button->text().remove(0,1);

      if(text == name)
         button->setVisible(true);
   }
   this->adjustSize();
}

//------------------------------------------------------------------------------
// Method       : buttonClicked()
// Filename     : ringmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void Dialog::buttonClicked(int id)
{

   emit dialogButtonPressed(QString::number(id));

}

//------------------------------------------------------------------------------
// Method       : keyPressEvent()
// Filename     : ringmenu.cpp
// Description  : when ENTER or Return Key is pressed the buttons
//                should be activated also
//------------------------------------------------------------------------------
void Dialog::keyPressEvent(QKeyEvent *event)
{
   if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
      QWidget *widget = this->focusWidget();
      if(QPushButton *button = qobject_cast<QPushButton *> (widget)){
         button->animateClick();
         return;
      }
   }
   if(event->key() == Qt::Key_Escape){
      event->ignore();
      return;
   }

   QDialog::keyPressEvent(event);
}
