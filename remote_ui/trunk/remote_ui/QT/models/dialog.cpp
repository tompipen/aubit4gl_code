//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : dialog.cpp
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
#include "actions.h"
#include "mainframe.h"

//------------------------------------------------------------------------------
// Method       : Dialog()
// Filename     : dialog.cpp
// Description  : Constructs the RingMenu for the MenuButtons
//------------------------------------------------------------------------------
Dialog::Dialog(QWidget *parent, Qt::WindowFlags f) : QDialog(parent, f)
{
MainFrame::vdcdebug("Dialog","Dialog", "QWidget *parent, Qt");

}

//------------------------------------------------------------------------------
// Method       : Dialog()
// Filename     : dialog.cpp
// Description  : Constructs the RingMenu for the MenuButtons
//------------------------------------------------------------------------------
Dialog::Dialog(QString title, QString comment, QString style, QString image,
               QWidget *parent, Qt::WindowFlags f) : QDialog(parent, f)
{
MainFrame::vdcdebug("*parent,","WindowFlags f)", """");

   Q_UNUSED(style);
   this->setWindowModality(Qt::WindowModal);

   this->setAttribute(Qt::WA_DeleteOnClose);

   QVBoxLayout *layout = new QVBoxLayout(this);
   QHBoxLayout *buttonLayout = new QHBoxLayout(this);
   buttonLayout->setAlignment(Qt::AlignCenter);

   buttonGroup = new QButtonGroup(this);
/*
   connect(buttonGroup, SIGNAL(buttonClicked(int)),
           this, SLOT(buttonClicked(int)));
*/

   this->layout = layout;
   setLayout(this->layout);
   this->layout->setAlignment(Qt::AlignTop);
   this->buttonLayout = buttonLayout;
 
   this->setWindowTitle(title);

   QHBoxLayout *pixLayout = new QHBoxLayout(this);
   QLabel *p_label    = new QLabel(comment, this);
   QLabel *p_pixLabel = new QLabel(this);
   QString filename   = "pics:";

   filename.append(image);
   filename.append(".png");

   p_pixLabel->setPixmap(filename);
   pixLayout->addWidget(p_pixLabel);
   pixLayout->addWidget(p_label);
   pixLayout->addStretch();

   layout->addLayout(pixLayout);

   layout->addLayout(buttonLayout);

  // this->setModal(true);
   this->adjustSize();
}

//------------------------------------------------------------------------------
// Method       : createButton()
// Filename     : dialog.cpp
// Description  : creates the Buttons and adds them to the RingMenu
//------------------------------------------------------------------------------
void Dialog::createButton(int id, QString text, QString tooltip, QString icon)
{
MainFrame::vdcdebug("Dialog","createButton", "int id, QString text, QString tooltip, QString icon");

   // Make Shortcut for Button
   QString pic = text.toLower();
   QString shortcut = text.at(0);

   // Create the Button and set Text + ToolTip
   QPushButton *button = new QPushButton(text.trimmed(), this);
   button->setShortcut(shortcut);
   if(icon == "")
   {
      button->setIcon(QIcon(QString("pics:blank.png")));
      button->setIconSize(QSize(40,25));
   }
   else
   {
      button->setIcon(QIcon(QString("pics:" + icon)));
      button->setIconSize(QSize(40,25));
   }

 /*  Action *action = (Action*) this->getAction(text);
   if(action->text() != text){
      action = new Action(text.toLower(), text, button);
      action->setComment(tooltip);
      if(icon == "")
      {
         action->setImage("pics:blank.png");
      }
      else
      {
         action->setImage("pics:" + icon);
      }
   }*/
   
   Action *action = new Action(text.toLower(), text, button);
   action->setComment(tooltip);
   if(icon == "")
   {
      action->setImage("pics:blank.png");
   }
   else
   {
      action->setImage("pics:" + icon);
   }
   button->addAction(action);

   connect(button, SIGNAL(clicked()), action, SLOT(trigger()));

   buttonLayout->addWidget(button);

   buttonGroup->addButton(button, id);
}

//------------------------------------------------------------------------------
// Method       : createAction()
// Filename     : dialog.cpp
// Description  : creates the Buttons and adds them to the RingMenu
//------------------------------------------------------------------------------
void Dialog::createAction(int id, QString text)
{
MainFrame::vdcdebug("Dialog","createAction", "int id, QString text");
   // Make Shortcut for Button
   QString pic = text.toLower();
   QString shortcut = text.at(0);

   // Create the Button and set Text + ToolTip
   QPushButton *button = new QPushButton(text.trimmed(), this);
   button->setVisible(false);
   button->setShortcut(shortcut);
   button->setIcon(QIcon(QString("pics:blank.png")));
   button->setIconSize(QSize(40,25));

   Action *action = new Action(text.toLower(), text, button);
   action->setImage("blank.png");
   button->addAction(action);
   //connect(button, SIGNAL(clicked()), action, SLOT(trigger()));

   // Add the Button to the Layout
   buttonLayout->addWidget(button);

   buttonGroup->addButton(button, id);
}

//------------------------------------------------------------------------------
// Method       : hideButton()
// Filename     : ringmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void Dialog::hideButton(QString name)
{
MainFrame::vdcdebug("Dialog","hideButton", "QString name");
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      QPushButton *button = (QPushButton*) buttonGroup->buttons().at(i);
      QString text = button->text(); //.remove(0,1);
      if(text.startsWith("&")){
         text = text.remove(0,1);
      }

      if(text == name){
         button->setVisible(false);
         this->adjustSize();
         return;
      }
   }
}

//------------------------------------------------------------------------------
// Method       : hideButton()
// Filename     : ringmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void Dialog::showButton(QString name)
{
MainFrame::vdcdebug("Dialog","showButton", "QString name");
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
MainFrame::vdcdebug("Dialog","buttonClicked", "int id");

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
MainFrame::vdcdebug("Dialog","keyPressEvent", "QKeyEvent *event");
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

QList<QAction*> Dialog::actions()
{
MainFrame::vdcdebug("Dialog","actions", "");

   QList<QAction*> ql_actions;
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         if(button->isEnabled())
            ql_actions << button->actions();
      }
   }

   return ql_actions;
}

QAction* Dialog::getAction(QString name)
{
MainFrame::vdcdebug("Dialog","getAction", "QString name");

   for(int i=buttonGroup->buttons().size()-1; i>=0; i--){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         if(button->text().toLower() == name.toLower()){
            QList<QAction*> actions = button->actions();
            for(int j=0; j<actions.count(); j++){
               if(Action *action = qobject_cast<Action *> (actions.at(j))){
                  if(action->name().toLower() == name.toLower())
                     return action;
               }
            }
         }
      }
   }

   return new QAction(NULL);
}

