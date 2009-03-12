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
#include <QKeyEvent>
#include <QSpacerItem>

#include "ringmenu.h"


//------------------------------------------------------------------------------
// Method       : RingMenu()
// Filename     : ringmenu.cpp
// Description  : Constructs the RingMenu for the MenuButtons
//------------------------------------------------------------------------------
RingMenu::RingMenu(QWidget *parent) : QGroupBox(parent)
{
   this->setAlignment(Qt::AlignTop);
   // disable widget until it it gets called
   this->setEnabled(false);

   QVBoxLayout *layout = new QVBoxLayout;
   layout->setAlignment(Qt::AlignTop);

   buttonGroup = new QButtonGroup(this);

   this->layout = layout;
   setLayout(this->layout);
}

//------------------------------------------------------------------------------
// Method       : RingMenu()
// Filename     : ringmenu.cpp
// Description  : Constructs the RingMenu for the MenuButtons
//------------------------------------------------------------------------------
RingMenu::RingMenu(QString title, QString style, QString image, 
                   QWidget *parent) : QGroupBox(title, parent)
{

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

   buttonGroup = new QButtonGroup(this);
   connect(buttonGroup, SIGNAL(buttonClicked(int)), 
           this, SLOT(buttonClicked(int)));

   this->layout = layout;
   setLayout(this->layout);

}

//------------------------------------------------------------------------------
// Method       : createButton()
// Filename     : ringmenu.cpp
// Description  : creates the Buttons and adds them to the RingMenu
//------------------------------------------------------------------------------
void RingMenu::createButton(int id, QString text, QString tooltip)
{

   // Make Shortcut for Button
   QString pic = text.toLower();
   QString shortcut = text.at(0);
   text.prepend("&");

   // Create the Button and set Text + ToolTip
   QPushButton *button = new QPushButton(text.trimmed());
   button->setObjectName(text.trimmed());
   button->installEventFilter(this);
   button->setShortcut(shortcut);
   button->setToolTip(tooltip);
   QIcon icon(QString("pics:%0").arg(pic));
   button->setIcon(icon);
   button->setIconSize(QSize(15,15));

   // Add the Button to the Layout
   if(QHBoxLayout *layout = qobject_cast<QHBoxLayout *> (this->layout)){
      layout->addWidget(button);
   }

   if(QVBoxLayout *layout = qobject_cast<QVBoxLayout *> (this->layout)){
      layout->addWidget(button);
   }

   buttonGroup->addButton(button, id);
}

//------------------------------------------------------------------------------
// Method       : hideButton()
// Filename     : ringmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void RingMenu::hideButton(int id)
{
   //TODO Implement
}

//------------------------------------------------------------------------------
// Method       : hideButton()
// Filename     : ringmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void RingMenu::hideButton(QString name)
{
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         QString text = button->text();
         if(text.indexOf("&") > -1){
            text.remove(text.indexOf("&"), 1);
         }

         if(text == name){
            button->setVisible(false);
            return;
         }
      }
   }
}

//------------------------------------------------------------------------------
// Method       : hideButton()
// Filename     : ringmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void RingMenu::showButton(QString name)
{
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         QString text = button->text();
         if(text.indexOf("&") > -1){
            text.remove(text.indexOf("&"), 1);
         }

         if(text == name)
            button->setVisible(true);
      }
   }
}

//------------------------------------------------------------------------------
// Method       : selectButton()
// Filename     : ringmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void RingMenu::selectButton(QString name)
{
   name.prepend("&");
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         if(button->text() == name)
            button->setFocus();
      }
   }
}


//------------------------------------------------------------------------------
// Method       : buttons()
// Filename     : ringmenu.cpp
// Description  : returns all buttons in the Menu
//------------------------------------------------------------------------------
QList<QPushButton*> RingMenu::buttons()
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
// Filename     : ringmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void RingMenu::buttonClicked(int id)
{

   emit menuButtonPressed(QString::number(id));

}

//------------------------------------------------------------------------------
// Method       : createAction()
// Filename     : ringmenu.cpp
// Description  : creates the Buttons and adds them to the RingMenu
//------------------------------------------------------------------------------
void RingMenu::createAction(int id, QString text)
{

   // Create the Button and set Text + ToolTip
   QPushButton *button = new QPushButton(text.trimmed());
   button->setVisible(false);
   button->setObjectName(text.trimmed());
   button->installEventFilter(this);

   // Add the Button to the Layout
   if(QHBoxLayout *layout = qobject_cast<QHBoxLayout *> (this->layout)){
      layout->addWidget(button);
   }

   if(QVBoxLayout *layout = qobject_cast<QVBoxLayout *> (this->layout)){
      layout->addWidget(button);
   }

   buttonGroup->addButton(button, id);
}

//------------------------------------------------------------------------------
// Method       : resizeEvent()
// Filename     : ringmenu.cpp
// Description  : handles the resize Event ( whenever the RingMenu 
//                gets too small some buttons get invisible and
//                up and down arrows are displayed
//------------------------------------------------------------------------------
void RingMenu::resizeEvent(QResizeEvent *event)
{
   return QGroupBox::resizeEvent(event);
}

void RingMenu::focusInEvent(QFocusEvent* event)
{
   this->focusNextChild();
   return QGroupBox::focusInEvent(event);
}

bool RingMenu::eventFilter(QObject *obj, QEvent *event)
{
   if(obj->inherits("QPushButton")){
      if(event->type() == QEvent::KeyPress){
         QKeyEvent *keyEvent = (QKeyEvent*) event;
         if(keyEvent->key() == Qt::Key_Enter ||
            keyEvent->key() == Qt::Key_Return){
            QPushButton *button = (QPushButton*) obj;
            button->animateClick();
            return true;
         }
      }
   }

   if(event->type() == QEvent::KeyPress){
      QKeyEvent *key = (QKeyEvent*) event;


      if(key->key() == Qt::Key_Down ||
         key->key() == Qt::Key_Up){
         QPushButton *firstBtn = NULL;
         QPushButton *lastBtn = NULL;

         for(int i=0; i<buttons().count(); i++){
            QPushButton *btn = buttons().at(i);
            if(btn->isVisible() && btn->isEnabled()){
               firstBtn = btn;
               break;
            }
            
         }

         for(int i=buttons().count()-1; i>0; i--){
            QPushButton *btn = buttons().at(i);
            if(btn->isVisible() && btn->isEnabled()){
               lastBtn = btn;
               break;
            }
         }

         if(key->key() == Qt::Key_Down){
            if(this->focusWidget() == lastBtn){
               firstBtn->setFocus();
               return true;
            }
         }

         if(key->key() == Qt::Key_Up){
            if(this->focusWidget() == firstBtn){
               lastBtn->setFocus();
               return true;
            }
         }
      }
   }


   return QGroupBox::eventFilter(obj, event);
}

void RingMenu::setMenuStyle(const QString &ms)
{
   if(ms == "none"){
      this->setVisible(false);
   }
}

void RingMenu::setOrientation(const Qt::Orientation &o){

   if(QBoxLayout *layout = qobject_cast<QBoxLayout *> (this->layout)){
      if(o == Qt::Horizontal){
         layout->setDirection(QBoxLayout::TopToBottom);
      }
      else{
         if(o == Qt::Vertical) layout->setDirection(QBoxLayout::LeftToRight);
      }
   }
}
