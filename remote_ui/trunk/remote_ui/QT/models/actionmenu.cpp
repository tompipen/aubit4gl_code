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
/*ActionMenu::ActionMenu(QWidget *parent) : QGroupBox(parent)
{
MainFrame::vdcdebug("ActionMenu","ActionMenu", "QWidget *parent");

   this->setFocusPolicy(Qt::NoFocus);
   this->setAlignment(Qt::AlignTop);
   // disable widget until it it gets called
   this->setEnabled(false);
   this->setVisible(false);

   QVBoxLayout *layout = new QVBoxLayout;
   layout->setAlignment(Qt::AlignTop);

   buttonGroup = new QButtonGroup(this);

   this->layout = layout;
   setLayout(this->layout);
  // layout->setSizeConstraint(QLayout::SetFixedSize);

}*/

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
/*
   b_disabledi = false;
   b_disabledp = false;
*/
   // TODO: Layout is set by style
   if(style == "TODO"){
   }


   QVBoxLayout *layout = new QVBoxLayout;
   layout->setAlignment(Qt::AlignRight | Qt::AlignTop);
   layout->setContentsMargins(4,21,11,11);
   //layout->insertSpacing(0,61); //NS
   QGroupBox::setStyleSheet("QGroupBox {border: 0px; }");

   buttonGroup = new QButtonGroup(this);

   this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
/*
   connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), 
           this, SLOT(buttonClicked(QAbstractButton*)));
*/

   this->layout = layout;
 //  layout->setSizeConstraint(QLayout::SetFixedSize);
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
   button->setIcon(QIcon(QString(":pics/blank.png")));
   button->setIconSize(QSize(53,37));
   //button->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

   if (pic == "ende" || pic == "nein" || pic == "abbruch" || pic == "quit" || pic == "no" || pic == "cancel" || pic == "cancelar" || pic == "fin" || pic == "non" || pic == "interrompre") {
       button->setStyleSheet("QPushButton { border-image: url(:pics/VENTAS_11_btn_rot.png);}"
                                            "QPushButton:focus { border-image: url(:pics/VENTAS_11_btn_gelb.png);}"
                                            "QPushButton:hover { border-image: url(:pics/VENTAS_11_btn_rot_grau.png);}"
                                            "QPushButton:focus:hover { border-image: url(:pics/VENTAS_11_btn_gelb_grau.png);}");
   } else if (pic == "ok" || pic == "ja" || pic == "yes" || pic == "si" || pic == "oui") {
       button->setStyleSheet("QPushButton { border-image: url(:pics/VENTAS_11_btn_gruen.png);}"
                                             "QPushButton:focus { border-image: url(:pics/VENTAS_11_btn_gelb.png);}"
                                             "QPushButton:hover { border-image: url(:pics/VENTAS_11_btn_gruen_grau.png);}"
                                             "QPushButton:focus:hover { border-image: url(:pics/VENTAS_11_btn_gelb_grau.png);}");
   }

   qh_buttonpals[text.trimmed()] = button->palette();

   button->setVisible(visible);

   if(action != NULL){
      button->setIcon(action->icon());
      button->addAction(action);
      connect(button, SIGNAL(clicked()), action, SLOT(trigger()));
   }

   qh_buttonicon[text.trimmed()] = button->icon();

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
         {
            button->setVisible(false);
            break;
         }
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

   return new QAction(this);
}

void ActionMenu::setAction(QString name, QAction* action){

   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         if(button->text().toLower() == QString("%1").arg(name)){
            button->addAction(action);
            break;
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

/*
void ActionMenu::setPaletteForButton(QPushButton *button)
{

  if(!button)
    {
      return;
    }

  if(button->text().isEmpty())
  {
     qWarning("Button without Text");
     return;
  }



  QPalette pal = button->palette();
  QPalette tmp(pal);

  tmp.setCurrentColorGroup(QPalette::Active);
  tmp.setColor(QPalette::Disabled, QPalette::WindowText, tmp.color(QPalette::WindowText));
  tmp.setColor(QPalette::Disabled, QPalette::Text, tmp.color(QPalette::Text));
  tmp.setColor(QPalette::Disabled, QPalette::Button, tmp.color(QPalette::Button));
  tmp.setColor(QPalette::Disabled, QPalette::ButtonText, tmp.color(QPalette::ButtonText));
  tmp.setColor(QPalette::Disabled, QPalette::Background, tmp.color(QPalette::Background));
  tmp.setColor(QPalette::Disabled, QPalette::Base, tmp.color(QPalette::Base));
  tmp.setColor(QPalette::Disabled, QPalette::AlternateBase, tmp.color(QPalette::AlternateBase));
  tmp.setColor(QPalette::Disabled, QPalette::Window, tmp.color(QPalette::Window));

  if(tmp != pal)
  {
     qh_buttonpals[button->text().trimmed()] = button->palette();
     button->setPalette(tmp);
  }
}

void ActionMenu::setButtonPalette()
{

  if(b_disabledp)
  {
     return;
  }

  b_disabledp = true;

  if(buttonGroup->buttons().size() < 1)
    {
      return;
    }

  foreach(QAbstractButton *button, buttonGroup->buttons())
    {
      QPushButton *pbutton = (QPushButton*) button;
      setPaletteForButton(pbutton);
    }
}


void ActionMenu::setButtonIcons()
{
  if(b_disabledi)
  {
     return;
  }

  b_disabledi = true;

  if(!buttonGroup)
  {
      return;
  }


  if(buttonGroup->buttons().size() < 1)
    {
      return;
    }

  foreach(QAbstractButton *button, buttonGroup->buttons())
    {
      QPushButton *pbutton = (QPushButton*) button;
      setIconForButton(pbutton);
    }
}


void ActionMenu::restoreButtonPalette()
{
  b_disabledp = false;


  if(buttonGroup->buttons().size() < 1)
    {
      return;
    }

  foreach(QAbstractButton *button, buttonGroup->buttons())
    {
      QPalette pal = qh_buttonpals[button->text().trimmed()];
      if(pal != button->palette())
        {
          button->setPalette(pal);
        }
    }


}

void ActionMenu::setIconForButton(QPushButton *button)
{

  if(!button)
  {
      qWarning("Button not found");
  }

  QIcon icon = button->icon();

  qh_buttonicon[button->text()] = icon;

  //How i get the Pixmap without knowing the Qsize?
  QPixmap pix(icon.pixmap(QSize(40,25)));
  icon.addPixmap(pix, QIcon::Disabled);

  button->setIcon(icon);

}

void ActionMenu::restoreButtonIcon()
{
  b_disabledi = false;

  if(buttonGroup->buttons().size() < 1)
    {
      return;
    }

  foreach(QAbstractButton *button, buttonGroup->buttons())
    {
      QIcon ic = qh_buttonicon[button->text().trimmed()];
      if(!ic.isNull())
        {
          button->setIcon(ic);
        }
    }


}
*/
