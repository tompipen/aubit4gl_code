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
#include "mainframe.h"
#include "fglform.h"


//------------------------------------------------------------------------------
// Method       : RingMenu()
// Filename     : ringmenu.cpp
// Description  : Constructs the RingMenu for the MenuButtons
//------------------------------------------------------------------------------
RingMenu::RingMenu(QWidget *parent) : QGroupBox(parent)
{
MainFrame::vdcdebug("RingMenu","RingMenu", "QWidget *parent");
   //Switch for Hide/Disable
   b_hideButtons = true;
   this->setAlignment(Qt::AlignTop);
   // disable widget until it it gets called
   this->setEnabled(false);
   this->installEventFilter(this);
   QVBoxLayout *layout = new QVBoxLayout(this);
   layout->setAlignment(Qt::AlignTop);
   layout->setSpacing(0);
   //layout->setSizeConstraint(QLayout::SetFixedSize);
   buttonGroup = new QButtonGroup(this);

   this->layout = layout;
   setLayout(this->layout);
}

//------------------------------------------------------------------------------
// Method       : RingMenu()
// Filename     : ringmenu.cpp
// Description  : Constructs the RingMenu for the MenuButtons
//------------------------------------------------------------------------------
RingMenu::RingMenu(QString title, QWidget *fglform, QString style,
                   QWidget *parent) : QGroupBox(title, parent)
{
       //Switch for Hide/Disable
   b_hideButtons = true;
   this->ql_fglform = fglform;

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
   layout->setAlignment(Qt::AlignRight | Qt::AlignTop);
   layout->setSpacing(0);
   layout->setContentsMargins(4,21,11,11);
   //layout->insertSpacing(0,61); //NS
   QGroupBox::setStyleSheet("QGroupBox {border: 0px; }");
   //layout->setSizeConstraint(QLayout::SetFixedSize);
   buttonGroup = new QButtonGroup(this);

   this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);

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
QPushButton* RingMenu::createButton(int id, QString text, QString tooltip)
{
MainFrame::vdcdebug("RingMenu","createButton", "int id, QString text, QString tooltip");

   // Make Shortcut for Button
   QString pic = text.toLower();

   pic.replace(QString::fromUtf8("ö"), "oe");
   pic.replace(QString::fromUtf8("ü"), "ue");
   pic.replace(QString::fromUtf8("ä"), "ae");
   pic.replace(QString::fromUtf8("ß"), "ss");

   QString shortcut;
   QString buttonText;
   if(text.contains("&")){
      if(text.length() > text.indexOf("&")){
         shortcut = text.at(text.indexOf("&")+1);
         buttonText = text;
      }
   }
   else{
      buttonText = QString("&%1").arg(text.trimmed());
      shortcut = text.at(0);
   }

   QString image = pic + ".png";

   QFile img(QString(":pics/%1").arg(image));
   if (!img.open(QIODevice::ReadOnly))
         image = "blank.png";

   // Create the Button and set Text + ToolTip
   QPushButton *button = new QPushButton(buttonText);
   //button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
   button->setToolTip(tooltip);
   button->setFlat(true);
   button->installEventFilter(this);
  // button->setStyleSheet("QPushButton {text-align:left;}");
  //QPushButton *button = new QPushButton(text.trimmed());
  //button->setIcon(QIcon(QString(":pics/blank.png")));
   button->setIcon(QIcon(QString(":pics/%1").arg(image)));
   button->setIconSize(QSize(53,37));
   button->setShortcut(shortcut);

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

   /*if(FglForm *fglform = qobject_cast<FglForm*> (ql_fglform))
   {
       for(int i=0; i < fglform->ql_shortcuts.count(); i++)
       {
           if(QString("&%1").arg(fglform->ql_shortcuts.at(i).first).contains(buttonText))
           {
               button->setShortcut(fglform->ql_shortcuts.at(i).second);
           }
       }
   }*/

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

   return button;
}

//------------------------------------------------------------------------------
// Method       : hideButton()
// Filename     : ringmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void RingMenu::hideButton(int id)
{
MainFrame::vdcdebug("RingMenu","hideButton", "int id");
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
MainFrame::vdcdebug("RingMenu","hideButton", "QString name");
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         if(name.toLower() == "_all_")
         {
             if(b_hideButtons){
                button->setVisible(false);
             }
             else{
                button->setEnabled(false);
             }
         } else {
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
}

//------------------------------------------------------------------------------
// Method       : hideButton()
// Filename     : ringmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void RingMenu::showButton(QString name)
{
MainFrame::vdcdebug("RingMenu","showButton", "QString name");
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
          if(name.toLower() == "_all_")
          {
              if(button->text() != "fgl_exit_menu")
              {
                  if(b_hideButtons)
                  {
                     button->setVisible(true);
                  }
                  else{
                     button->setEnabled(true);
                  }
              }
          } else {
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
}

//------------------------------------------------------------------------------
// Method       : selectButton()
// Filename     : ringmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void RingMenu::selectButton(QString name)
{
MainFrame::vdcdebug("RingMenu","selectButton", "QString name");
   name.prepend("&");
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         if(button->text() == name){
//            nextButton = button;
            QMetaObject::invokeMethod(button, "setFocus", Qt::QueuedConnection);
            nextOptionName = "";
            return;
         }
      }
   }
}

void RingMenu::setFocusName(QString name)
{
    this->focusName = name;
}


//------------------------------------------------------------------------------
// Method       : buttons()
// Filename     : ringmenu.cpp
// Description  : returns all buttons in the Menu
//------------------------------------------------------------------------------
QList<QPushButton*> RingMenu::buttons()
{
MainFrame::vdcdebug("RingMenu","buttons", "");
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
MainFrame::vdcdebug("RingMenu","buttonClicked", "int id");

   emit menuButtonPressed(QString::number(id));

}

//------------------------------------------------------------------------------
// Method       : createAction()
// Filename     : ringmenu.cpp
// Description  : creates the Buttons and adds them to the RingMenu
//------------------------------------------------------------------------------
void RingMenu::createAction(int id, QString text)
{
MainFrame::vdcdebug("RingMenu","createAction", "int id, QString text");

   // Make Shortcut for Button
   QString pic = text.toLower();
   //QString shortcut = text.at(0);
   QString shortcut;
   if(text.contains("&")){
      if(text.length() > text.indexOf("&")){
         shortcut = text.at(text.indexOf("&")+1);
      }
   }
   else{
      shortcut = text.at(0);
   }

   // Create the Button and set Text + ToolTip
   //QPushButton *button = new QPushButton(text.trimmed().prepend("&"));
   QPushButton *button = new QPushButton(text.trimmed());
   button->setVisible(false);
//   button->setShortcut(shortcut);
   button->setIcon(QIcon(QString(":pics/blank.png")));
   button->setIconSize(QSize(53,37));
//   button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

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
MainFrame::vdcdebug("RingMenu","resizeEvent", "QResizeEvent *event");
   return QGroupBox::resizeEvent(event);
}

void RingMenu::focusInEvent(QFocusEvent* event)
{
MainFrame::vdcdebug("RingMenu","focusInEvent", "QFocusEvent* event");
   //this->focusNextChild();
   return QGroupBox::focusInEvent(event);
}

void RingMenu::keyPressEvent(QKeyEvent *keyEvent)
{
MainFrame::vdcdebug("RingMenu","keyPressEvent", "QKeyEvent *keyEvent");
         if(keyEvent->key() == Qt::Key_Enter ||
            keyEvent->key() == Qt::Key_Return){

            if(QPushButton *btn = qobject_cast<QPushButton *> (this->focusWidget())){
               btn->animateClick();
            }

            return ;
         }

   /*if(keyEvent->type() == QEvent::KeyPress){
      if(keyEvent->key() == Qt::Key_Down){
         focusNextChild();
      }
      if(keyEvent->key() == Qt::Key_Up){
         focusPreviousChild();
      }
   }*/

   return QGroupBox::keyPressEvent(keyEvent);
}

void RingMenu::setMenuStyle(const QString &ms)
{
MainFrame::vdcdebug("RingMenu","setMenuStyle", "const QString &ms");
   if(ms == "none"){
      this->setVisible(false);
   }
}

void RingMenu::setHideButtons(const QString &ms)
{
MainFrame::vdcdebug("RingMenu","setHideButtons", "const QString &ms");

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
MainFrame::vdcdebug("RingMenu","actions", "");

   QList<QAction*> ql_actions;
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
       //  if(button->isVisible() && button->isEnabled())
            ql_actions << button->actions();
      }
   }

   return ql_actions;
}

QAction* RingMenu::getAction(QString name)
{
MainFrame::vdcdebug("RingMenu","getAction", "QString name");

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
MainFrame::vdcdebug("RingMenu","isActionButton", "QPushButton* button");
   Q_UNUSED(button);
   return false;
}


bool RingMenu::eventFilter(QObject *obj, QEvent *event)
{

    if(event->type() == QEvent::MouseButtonRelease)
    {
        if(QPushButton *btn = qobject_cast<QPushButton *> (obj)){
           focusName = btn->text().remove("&");
        }
    }

    if(event->type() == QEvent::KeyPress){
       QKeyEvent *keyEvent = (QKeyEvent*) event;

       if(QPushButton *btn = qobject_cast<QPushButton *> (obj)){
          focusName = btn->text().remove("&");
       }

       if(keyEvent->key() == Qt::Key_Backtab)
       {

       }
       if(keyEvent->key() == Qt::Key_Tab)
       {

       }

       if(keyEvent->key() == Qt::Key_Down) {
           if(QPushButton *bt = qobject_cast<QPushButton*> (obj)) {
               QPushButton *lastButton = NULL;
               for(int i=buttonGroup->buttons().count()-1; i > 0; i--) {
                   if(buttonGroup->buttons().at(i)->isVisible()) {
                       lastButton = qobject_cast<QPushButton*> (buttonGroup->buttons().at(i));
                       break;
                   }
               }

               if(bt == lastButton) {
                   for(int k=0; k < buttonGroup->buttons().count(); k++) {
                       QPushButton *firstButton = qobject_cast<QPushButton*> (buttonGroup->buttons().at(k));

                       if(!firstButton->isVisible()) {
                           continue;
                       }

                       QMetaObject::invokeMethod(firstButton, "setFocus", Qt::QueuedConnection);
                       break;
                   }
               } else {
                   int buttonIndex = buttonGroup->buttons().indexOf(bt);
                   while(buttonIndex < buttonGroup->buttons().count()) {
                       buttonIndex++;

                       if(buttonIndex < buttonGroup->buttons().count()) {
                           break;
                       }

                       QPushButton *nextButton = qobject_cast<QPushButton*> (buttonGroup->buttons().at(buttonIndex));
                       if(nextButton->isVisible()) {
                           QMetaObject::invokeMethod(nextButton, "setFocus", Qt::QueuedConnection);
                           break;
                       }
                   }
               }
           }
       }

       if(keyEvent->key() == Qt::Key_Up ) {
           if(QPushButton *bt = qobject_cast<QPushButton*> (obj)) {
               QPushButton *firstButton = NULL;
               for(int i=0; i < buttonGroup->buttons().count(); i++) {
                   if(buttonGroup->buttons().at(i)->isVisible()) {
                       firstButton = qobject_cast<QPushButton*> (buttonGroup->buttons().at(i));
                       break;
                   }
               }

               if(bt == firstButton) {
                   for(int k=buttonGroup->buttons().count()-1; k > 0; k--) {
                       QPushButton *lastButton = qobject_cast<QPushButton*> (buttonGroup->buttons().at(k));

                       if(!lastButton->isVisible()) {
                           continue;
                       }

                       QMetaObject::invokeMethod(lastButton, "setFocus", Qt::QueuedConnection);
                       break;
                   }
               } else {
                   int buttonIndex = buttonGroup->buttons().indexOf(bt);
                   while(buttonIndex < buttonGroup->buttons().count()) {
                       buttonIndex--;

                       if(buttonIndex < buttonGroup->buttons().count()) {
                           break;
                       }

                       QPushButton *nextButton = qobject_cast<QPushButton*> (buttonGroup->buttons().at(buttonIndex));
                       if(nextButton->isVisible()) {
                           QMetaObject::invokeMethod(nextButton, "setFocus", Qt::QueuedConnection);
                           break;
                       }
                   }
               }
           }
       }
    }
    if(event->type() == QEvent::FocusIn) {
        if(QPushButton *pb = qobject_cast<QPushButton*> (obj)) {
            if (!nextOptionName.isEmpty()) {
                selectButton(nextOptionName);
            }
        }
    }
    return QGroupBox::eventFilter(obj,event);
}
