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
#include <QFile>
#include <QKeyEvent>
#include <QSpacerItem>

#include "ringmenu.h"
#include "actions.h"


//------------------------------------------------------------------------------
// Method       : RingMenu()
// Filename     : ringmenu.cpp
// Description  : Constructs the RingMenu for the MenuButtons
//------------------------------------------------------------------------------
RingMenu::RingMenu(QWidget *parent) : QGroupBox(parent)
{
   b_hideButtons = false;
   this->setAlignment(Qt::AlignTop);
   // disable widget until it it gets called
   this->setEnabled(false);

   QVBoxLayout *layout = new QVBoxLayout;
   layout->setAlignment(Qt::AlignTop);
   layout->setSpacing(0);

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
   b_hideButtons = false;

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

   buttonGroup = new QButtonGroup(this);
/*
   connect(buttonGroup, SIGNAL(buttonClicked(int)), 
           this, SLOT(buttonClicked(int)));
*/

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

   QString image = pic + ".png";

   QFile img(QString("pics/%1").arg(image));
   if (!img.open(QIODevice::ReadOnly))
         image = "blank.png";

   // Create the Button and set Text + ToolTip
   QPushButton *button = new QPushButton(text.trimmed().prepend('&'));
//   QPushButton *button = new QPushButton(text.trimmed());
   //button->setIcon(QIcon(QString("pics:blank.png")));
   button->setIcon(QIcon(QString("pics:%1").arg(image)));
   button->setIconSize(QSize(40,25));
   button->setShortcut(shortcut);

   Action *action = new Action(text.toLower(), text, button);
   action->setComment(tooltip);
   action->setImage(image);
   //action->setAcceleratorName(shortcut);
   button->addAction(action);
   connect(button, SIGNAL(clicked()), action, SLOT(trigger()));

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
   if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(id))){
      if(b_hideButtons){
         button->setVisible(false);
      }
      else{
         button->setEnabled(false);
      }
   }
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
            if(b_hideButtons){
               button->setVisible(false);
            }
            else{
               button->setEnabled(false);
            }
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

         if(text == name){
            if(b_hideButtons){
               button->setVisible(true);
            }
            else{
               button->setEnabled(true);
            }
         }
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
         if(button->text() == name){
            button->setFocus();
            return;
         }
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

   // Make Shortcut for Button
   QString pic = text.toLower();
   QString shortcut = text.at(0);

   // Create the Button and set Text + ToolTip
   //QPushButton *button = new QPushButton(text.trimmed().prepend("&"));
   QPushButton *button = new QPushButton(text.trimmed());
   button->setVisible(false);
//   button->setShortcut(shortcut);
   button->setIcon(QIcon(QString("pics:blank.png")));
   button->setIconSize(QSize(40,25));

   Action *action = new Action(text.toLower(), text, button);
   action->setImage("blank.png");
   button->addAction(action);
   connect(button, SIGNAL(clicked()), action, SLOT(trigger()));

   // Add the Button to the Layout
   if(QHBoxLayout *layout = qobject_cast<QHBoxLayout *> (this->layout)){
      layout->addWidget(button);
   }

   if(QVBoxLayout *layout = qobject_cast<QVBoxLayout *> (this->layout)){
      layout->addWidget(button);
   }

   buttonGroup->addButton(button, id);
   button->setVisible(false);

   //createButton(id, text, "");
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

void RingMenu::keyPressEvent(QKeyEvent *keyEvent)
{
         if(keyEvent->key() == Qt::Key_Enter ||
            keyEvent->key() == Qt::Key_Return){

            if(QPushButton *btn = qobject_cast<QPushButton *> (this->focusWidget())){
               btn->animateClick();
            }

            return ;
         }

/*
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
*/

   return QGroupBox::keyPressEvent(keyEvent);
}

void RingMenu::setMenuStyle(const QString &ms)
{
   if(ms == "none"){
      this->setVisible(false);
   }
}

void RingMenu::setHideButtons(const QString &ms)
{

   if(ms == "disable"){
      b_hideButtons = false;
   }
   else {
      b_hideButtons = true;
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

QList<QAction*> RingMenu::actions()
{

   QList<QAction*> ql_actions;
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         if(button->isVisible() && button->isEnabled())
            ql_actions << button->actions();
      }
   }

   return ql_actions;
}

QAction* RingMenu::getAction(QString name)
{

   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
//         if(button->text().toLower() == QString("&%1").arg(name)){
            QList<QAction*> actions = button->actions();
            for(int j=0; j<actions.count(); j++){
               if(Action *action = qobject_cast<Action *> (actions.at(j))){
                  if(action->name() == name)
                     return action;
               }
            }
         //}
      }
   }

   return new QAction(NULL);
}

bool RingMenu::isActionButton(QPushButton* button)
{
   return false;
}
