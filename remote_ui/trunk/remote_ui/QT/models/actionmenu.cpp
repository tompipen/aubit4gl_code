//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// File name    : actionmenu.cpp
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
#include <QKeyEvent>

#include "actionmenu.h"

//------------------------------------------------------------------------------
// Method       : ActionMenu()
// Filename     : actionmenu.cpp
// Description  : Constructs the ActionMenu for the MenuButtons
//------------------------------------------------------------------------------
ActionMenu::ActionMenu(QWidget *parent) : QGroupBox(parent)
{

   this->setFocusPolicy(Qt::NoFocus);
   this->setAlignment(Qt::AlignTop);
   // disable widget until it it gets called
   this->setEnabled(false);
   this->setVisible(false);

   QVBoxLayout *layout = new QVBoxLayout;
   layout->setAlignment(Qt::AlignTop);

   buttonGroup = new QButtonGroup;
   connect(buttonGroup, SIGNAL(buttonClicked(int)), 
           this, SLOT(buttonClicked(int)));

   this->layout = layout;
   setLayout(this->layout);
   this->setFixedWidth(this->minimumWidth());
}

//------------------------------------------------------------------------------
// Method       : ActionMenu()
// Filename     : actionmenu.cpp
// Description  : Constructs the ActionMenu for the MenuButtons
//------------------------------------------------------------------------------
ActionMenu::ActionMenu(QString title, QString style, QString image, 
                   QWidget *parent) : QGroupBox(title, parent)
{

   this->setAlignment(Qt::AlignRight | Qt::AlignTop);
   // disable widget until it it gets called
   this->setEnabled(false);
   this->setVisible(false);

   // TODO: Layout is set by style
   if(style == "TODO"){
   }


   QVBoxLayout *layout = new QVBoxLayout;
   layout->setAlignment(Qt::AlignTop);

   buttonGroup = new QButtonGroup;

   connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), 
           this, SLOT(buttonClicked(QAbstractButton*)));

   this->layout = layout;
   setLayout(this->layout);

}

//------------------------------------------------------------------------------
// Method       : createButton()
// Filename     : actionmenu.cpp
// Description  : creates the Buttons and adds them to the ActionMenu
//------------------------------------------------------------------------------
void ActionMenu::createButton(QString id, QString text, QString shortcut)
{

   if(text.trimmed().isEmpty()){
      return;
   }

   for(int i=0; i<buttonGroup->buttons().size(); i++){
      QString btnTxt = buttonGroup->buttons().at(i)->text();
      if(btnTxt == text || text.trimmed().isEmpty())
         return;
      
   }

   // Create the Button and set Text + ToolTip
   QPushButton *button = new QPushButton(text);
   button->setFocusPolicy(Qt::NoFocus);
   button->setObjectName(shortcut);


   // Add the Button to the Layout
   if(QHBoxLayout *layout = qobject_cast<QHBoxLayout *> (this->layout)){
      layout->addWidget(button);
   }

   if(QVBoxLayout *layout = qobject_cast<QVBoxLayout *> (this->layout)){
      layout->addWidget(button);
   }

   buttonGroup->addButton(button);
}

//------------------------------------------------------------------------------
// Method       : hideButton()
// Filename     : actionmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void ActionMenu::hideButton(int id)
{
   //TODO Implement
}

//------------------------------------------------------------------------------
// Method       : hideButton()
// Filename     : actionmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void ActionMenu::hideButton(QString name)
{
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         if(button->text() == name)
            button->setVisible(false);
      }
   }
}


//------------------------------------------------------------------------------
// Method       : buttons()
// Filename     : actionmenu.cpp
// Description  : returns all buttons in the Menu
//------------------------------------------------------------------------------
QList<QPushButton*> ActionMenu::buttons()
{
   QList<QPushButton*> buttons;
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         buttons << button;
      }
   }
   
   return buttons;
}

//------------------------------------------------------------------------------
// Method       : buttonClicked()
// Filename     : actionmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void ActionMenu::buttonClicked(int id)
{

   emit menuButtonPressed(QString::number(id));

}

//------------------------------------------------------------------------------
// Method       : buttonClicked()
// Filename     : actionmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void ActionMenu::buttonClicked(QAbstractButton * button )
{
      QString text = button->text();
      if(text == "INTERRUPT" ||
         text == "ACCEPT" ||
         text == "CANCEL"){
         emit menuButtonPressed(text);
      }
      else{
         text = button->objectName();

         // For F-Key Events
         bool ok = false;
         int keyNum = text.mid(1,text.length()-1).toInt(&ok);

         if(ok){
            keyNum += 2999;
            emit menuButtonPressed(QString::number(keyNum));
         }
      }
}

//------------------------------------------------------------------------------
// Method       : resizeEvent()
// Filename     : actionmenu.cpp
// Description  : handles the resize Event ( whenever the ActionMenu 
//                gets too small some buttons get invisible and
//                up and down arrows are displayed
//------------------------------------------------------------------------------
void ActionMenu::resizeEvent(QResizeEvent *event)
{

   //TODO: IMPLEMENT resize and show UP and DOWN Buttons
   QGroupBox::resizeEvent(event);
}

//------------------------------------------------------------------------------
// Method       : keyPressEvent()
// Filename     : actionmenu.cpp
// Description  : when ENTER or Return Key is pressed the buttons
//                should be activated also
//------------------------------------------------------------------------------
void ActionMenu::keyPressEvent(QKeyEvent *event)
{
   if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
      QWidget *widget = this->focusWidget();
      if(QPushButton *button = qobject_cast<QPushButton *> (widget)){
         button->animateClick();
      }
   }

   QGroupBox::keyPressEvent(event);
}

void ActionMenu::removeButtons()
{

   QList<QPushButton*> buttons;
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         buttonGroup->removeButton(button);
         button->deleteLater();
      }
   }
   
}
