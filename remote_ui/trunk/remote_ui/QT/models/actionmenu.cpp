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
#include "actions.h"
#include "mainframe.h"

//------------------------------------------------------------------------------
// Method       : ActionMenu()
// Filename     : actionmenu.cpp
// Description  : Constructs the ActionMenu for the MenuButtons
//------------------------------------------------------------------------------
ActionMenu::ActionMenu(QWidget *parent) : QGroupBox(parent)
{
MainFrame::vdcdebug("ActionMenu","ActionMenu", "QWidget *parent");

   this->setFocusPolicy(Qt::NoFocus);
   this->setAlignment(Qt::AlignTop);
   // disable widget until it it gets called
   this->setEnabled(false);
   this->setVisible(false);

   QVBoxLayout *layout = new QVBoxLayout;
   layout->setAlignment(Qt::AlignTop);

   buttonGroup = new QButtonGroup;
/*
   connect(buttonGroup, SIGNAL(buttonClicked(int)), 
           this, SLOT(buttonClicked(int)));
*/

   this->layout = layout;
   setLayout(this->layout);
   this->setFixedWidth(this->minimumWidth());
}

//------------------------------------------------------------------------------
// Method       : ActionMenu()
// Filename     : actionmenu.cpp
// Description  : Constructs the ActionMenu for the MenuButtons
//------------------------------------------------------------------------------
ActionMenu::ActionMenu(QString title, QString style, QWidget *parent) : QGroupBox(title, parent)
{
MainFrame::vdcdebug("ActionMenu","ActionMenu", "QString title, QString style, QWidget *parent");

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

/*
   connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), 
           this, SLOT(buttonClicked(QAbstractButton*)));
*/

   this->layout = layout;
   setLayout(this->layout);

}

//------------------------------------------------------------------------------
// Method       : createButton()
// Filename     : actionmenu.cpp
// Description  : creates the Buttons and adds them to the ActionMenu
//------------------------------------------------------------------------------
void ActionMenu::createButton(QString id, QString text, QString shortcut, QAction *action)
{
MainFrame::vdcdebug("ActionMenu","createButton", "QString id, QString text, QString shortcut, QAction *action");
   Q_UNUSED(id);

   bool visible = true;
   if(text.isEmpty()){
      visible = false;
//      text = id;
   }

   // Make Shortcut for Button
   QString pic = text.toLower();
   //QString shortcut = text.at(0);

   // Create the Button and set Text + ToolTip
   QPushButton *button = new QPushButton(text.trimmed(), this);
   button->setFocusPolicy(Qt::NoFocus);
   button->setShortcut(shortcut);
   button->setIcon(QIcon(QString("pics:blank.png")));
   button->setIconSize(QSize(40,25));
   button->setVisible(visible);

   if(action != NULL){
      button->setIcon(action->icon());
      button->addAction(action);
      connect(button, SIGNAL(clicked()), action, SLOT(trigger()));
   }

/*
   Action *action = new Action(text.toLower(), text, button);
   //action->setComment(tooltip);
   action->setImage("blank.png");
   button->addAction(action);
   connect(button, SIGNAL(clicked()), action, SLOT(trigger()));
*/

   // Add the Button to the Layout
   if(QHBoxLayout *layout = qobject_cast<QHBoxLayout *> (this->layout)){
      layout->addWidget(button);
   }

   if(QVBoxLayout *layout = qobject_cast<QVBoxLayout *> (this->layout)){
      layout->addWidget(button);
   }

   buttonGroup->addButton(button); //, id);
}

//------------------------------------------------------------------------------
// Method       : hideButton()
// Filename     : actionmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void ActionMenu::hideButton(QString name)
{
MainFrame::vdcdebug("ActionMenu","hideButton", "QString name");
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
MainFrame::vdcdebug("ActionMenu","buttons", "");
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
MainFrame::vdcdebug("ActionMenu","buttonClicked", "int id");
   emit menuButtonPressed(QString::number(id));
}

//------------------------------------------------------------------------------
// Method       : buttonClicked()
// Filename     : actionmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void ActionMenu::buttonClicked(QAbstractButton * button )
{
MainFrame::vdcdebug("ActionMenu","buttonClicked", "QAbstractButton * button ");
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
MainFrame::vdcdebug("ActionMenu","resizeEvent", "QResizeEvent *event");

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
MainFrame::vdcdebug("ActionMenu","keyPressEvent", "QKeyEvent *event");
   if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
      QWidget *widget = this->focusWidget();
      if(QPushButton *button = qobject_cast<QPushButton *> (widget)){
         button->animateClick();
      }
   }

   QGroupBox::keyPressEvent(event);
}

void ActionMenu::removeButton(QString name)
{

MainFrame::vdcdebug("ActionMenu","removeButton", "QString name");
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         if(button->text() == name){
            buttonGroup->removeButton(button);
            button->deleteLater();
            break;
         }
      }
   }

}

void ActionMenu::removeButtons()
{
MainFrame::vdcdebug("ActionMenu","removeButtons", "");

   QList<QPushButton*> buttons;
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         buttonGroup->removeButton(button);
         button->deleteLater();
      }
   }
}

void ActionMenu::hideButtons(bool hide)
{
MainFrame::vdcdebug("ActionMenu","hideButtons", "bool hide");

   QList<QPushButton*> buttons;
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         button->setVisible(!hide);
      }
   }
   
}

QList<QAction*> ActionMenu::actions()
{
MainFrame::vdcdebug("ActionMenu","actions", "");

   QList<QAction*> ql_actions;
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         if(button->isVisible() && button->isEnabled())
            ql_actions << button->actions();
      }
   }

   return ql_actions;
}

QAction* ActionMenu::getAction(QString name)
{
MainFrame::vdcdebug("ActionMenu","getAction", "QString name");
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         //if(button->text().toLower() == QString("%1").arg(name)){
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

void ActionMenu::setAction(QString name, QAction* action){

   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         if(button->text().toLower() == QString("%1").arg(name)){
            button->addAction(action);
         }
      }
   }
}
void ActionMenu::setOrientation(const Qt::Orientation &o){

   if(QBoxLayout *layout = qobject_cast<QBoxLayout *> (this->layout)){
      if(o == Qt::Horizontal){
         layout->setDirection(QBoxLayout::TopToBottom);
      }
      else{
         if(o == Qt::Vertical) layout->setDirection(QBoxLayout::LeftToRight);
      }
   }
}

