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

#include "pulldown.h"
#include "actions.h"
#include "mainframe.h"
#include "fglform.h"

RingMenuPulldown::RingMenuPulldown(QString title, QString comment, QString style, QString image,
                                   QWidget *parent) : QGroupBox(parent)
{
   b_hideButtons = true;
   this->setAlignment(Qt::AlignRight | Qt::AlignTop);
   // disable widget until it it gets called
   this->setTitle(title.trimmed());
   //this->setEnabled(false);
   //this->setVisible(false);
   this->installEventFilter(this);
   this->setWindowFlags(Qt::WindowStaysOnTopHint);

   QVBoxLayout *layout = new QVBoxLayout;
   layout->setAlignment(Qt::AlignTop);
   layout->setSpacing(0);
   buttonGroup = new QButtonGroup(this);

   this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);

   this->layout = layout;
   this->setLayout(this->layout);

   QWidget *d = QApplication::desktop();
   int w = d->width();
   int h = d->height();
   int mw = 200;
   int mh = 100;

   this->move(mw, mh);
   //this->setWindowFlags(Qt::FramelessWindowHint);

}

void RingMenuPulldown::closeWindow()
{
    this->setEnabled(false);
    //this->deleteLater();
    this->close();
}

//------------------------------------------------------------------------------
// Method       : createButton()
// Filename     : ringmenu.cpp
// Description  : creates the Buttons and adds them to the RingMenu
//------------------------------------------------------------------------------
void RingMenuPulldown::createButton(int id, QString text, QString tooltip)
{
MainFrame::vdcdebug("RingMenu","createButton", "int id, QString text, QString tooltip");

   // Make Shortcut for Button

   QString buttonText;
   if(text.contains("&")){
      if(text.length() > text.indexOf("&")){
         buttonText = text;
      }
   }
   else{
      buttonText = QString("&%1").arg(text.trimmed());
   }

   // Create the Button and set Text + ToolTip
   QPushButton *button = new QPushButton(buttonText);
   button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
   button->setToolTip(tooltip);
   button->setFlat(true);
   button->installEventFilter(this);
   button->setStyleSheet("QPushButton {text-align:left;}");
//   QPushButton *button = new QPushButton(text.trimmed());
   //button->setIcon(QIcon(QString("pics:blank.png")));
   if(button->text() == "&Ende")
   {
       button->setIcon(QIcon("pics:pulldown-abbrechen.png"));
   } else {
       button->setIcon(QIcon(QString("pics:%1.png").arg(id)));
   }
   button->setIconSize(QSize(40,25));
   button->setShortcut(QString("&%1").arg(id));

   if(text.toLower() == "abbruch" || text.toLower() == "ende")
   {
       connect(button, SIGNAL(clicked()), this, SLOT(close()));
   } else {
       Action *action = new Action(text.toLower(), text, button);
       action->setComment(tooltip);
       action->setImage(QString("%1.png").arg(id));
       button->addAction(action);
       connect(button, SIGNAL(clicked()), action, SLOT(trigger()));
   }

   if(text.toLower().trimmed() == "fgl_exit_menu")
   {
       button->setVisible(false);
   }

   // Add the Button to the Layout
   if(QHBoxLayout *layout = qobject_cast<QHBoxLayout *> (this->layout)){
      layout->addWidget(button);
   }

   if(QVBoxLayout *layout = qobject_cast<QVBoxLayout *> (this->layout)){
      layout->addWidget(button);
   }

   buttonGroup->addButton(button, id);
}

void RingMenuPulldown::hideButton(QString name)
{
MainFrame::vdcdebug("RingMenu","hideButton", "QString name");
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

void RingMenuPulldown::showButton(QString name)
{
MainFrame::vdcdebug("RingMenu","showButton", "QString name");
   for(int i=0; i<buttonGroup->buttons().size(); i++){
      if(QPushButton *button = qobject_cast<QPushButton *> (buttonGroup->buttons().at(i))){
         QString text = button->text();
         if(text.indexOf("&") > -1){
            text.remove(text.indexOf("&"), 1);
         }

         if(text == name){
            if(b_hideButtons){
               button->setVisible(true);
               ql_buttons << button;
               button->setIcon(QIcon(QString("pics:%1.png").arg(ql_buttons.count())));
            }
            else{
               button->setEnabled(true);
            }
         }
      }
   }
}

QAction* RingMenuPulldown::getAction(QString name)
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

void RingMenuPulldown::showWindow()
{
    this->show();
}
QList<QAction*> RingMenuPulldown::actions()
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
void RingMenuPulldown::moveToPos(QPoint const pos)
{
    this->move(pos);
}

bool RingMenuPulldown::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = (QKeyEvent*) event;
        if(keyEvent->key() <= 57)
        {
            int shortcut1 = 0;
        //if(QString::number(mev->button()) <= "9" && QString::number(mev->button()) >= "0")
        //{
        //    shortcut = QString::number(mev->button() - 28);
        //} else {
        //{
            shortcut1 = keyEvent->key() - 49;
            //}
            qDebug() << "tastatur: " << keyEvent->key();
            qDebug() << "shortcut: " << shortcut1;
            if(ql_buttons.count() > shortcut1 && shortcut1 >= 0)
            {
               if(QPushButton *button = qobject_cast<QPushButton *> (ql_buttons.at(shortcut1))){
                   if(button->isVisible())
                   {
                       button->click();
                   }
               }
            }
            return true;
        } else if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter)
        {
            if(QPushButton *pb = qobject_cast<QPushButton *> (obj))
            {
                pb->click();
            }
            return false;
        } else if(keyEvent->key() == Qt::Key_Escape)
        {
            this->close();
        }
    }

    return QGroupBox::eventFilter(obj,event);
    //return false;
}

//------------------------------------------------------------------------------
// Method       : createAction()
// Filename     : ringmenu.cpp
// Description  : creates the Buttons and adds them to the RingMenu
//------------------------------------------------------------------------------
void RingMenuPulldown::createAction(int id, QString text)
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
   button->setIcon(QIcon(QString("pics:blank.png")));
   button->setIconSize(QSize(40,25));
   button->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

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
// Method       : Pulldown()
// Filename     : pulldown.cpp
// Description  : Constructs the RingMenu for the MenuButtons
//------------------------------------------------------------------------------
Pulldown::Pulldown(QWidget *parent) : QMenu(parent)
{
MainFrame::vdcdebug("Pulldown","Pulldown", "QWidget *parent");

}

//------------------------------------------------------------------------------
// Method       : Pulldown()
// Filename     : dialog.cpp
// Description  : Constructs the RingMenu for the MenuButtons
//------------------------------------------------------------------------------
Pulldown::Pulldown(QString title, QString comment, QString style, QString image,
               QWidget *parent) : QMenu(parent)
{
   Q_UNUSED(style);
   this->setTitle(title);
}

//------------------------------------------------------------------------------
// Method       : createAction()
// Filename     : dialog.cpp
// Description  : creates the Buttons and adds them to the RingMenu
//------------------------------------------------------------------------------
void Pulldown::createAction(int id, QString text, QString icon)
{
MainFrame::vdcdebug("Pulldown","createAction", "int id, QString text");
   // Make Shortcut for Button
   QString pic = text.toLower();
   QString shortcut = text.at(0);
   QString image = pic + ".png";

   if(ql_actions.count() < 1) {
          QString title = this->title();
          title = title.trimmed();

          Action *action1 = new Action (title, title);
          action1->setDisabled(true);
          action1->setObjectName(title);

          this->ql_actions.insert(0, action1);
          this->addAction(action1);
   }

  /* QFile img(QString("pics:%1").arg(image));
   if (!img.open(QIODevice::ReadOnly))
       image = "blank.png";
   qDebug()<<QString("pics:%1").arg(image);*/

   Action *action = new Action(text.toLower(), text);
   //action->setIcon(QIcon(QString(":pics/%1.png").arg(id)));
   action->setIconVisibleInMenu(true);

   //action->setImage(QString("pics:%1").arg(image));
   //Hide the default close action.(Calls fgl_exit_menu action)

   if(text.toLower().trimmed() == "fgl_exit_menu")
   {
       action->setVisible(false);
   }

   this->ql_actions.insert(id, action);
   this->addAction(action);

   connect(action, SIGNAL(triggered()), parent(), SLOT(actionTriggered()));

}

//------------------------------------------------------------------------------
// Method       : hideButton()
// Filename     : ringmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void Pulldown::hideAction(QString name)
{
MainFrame::vdcdebug("Pulldown","hideButton", "QString name");
for(int i=0; i<this->actions().size();i++){
   QAction *action = this->actions().at(i);
   if(action->text() == name)
      action->setVisible(false);
}
this->clear();
this->addActions(this->actions());
}

void Pulldown::hideEvent(QHideEvent *e)
{
    //If the click is inside the menu, dont close the menu
    if(this->geometry().contains(QCursor::pos()))
    {
        e->accept();
        return QMenu::hideEvent(e);
    }
    emit closeEvent();

}

//------------------------------------------------------------------------------
// Method       : hideButton()
// Filename     : ringmenu.cpp
// Description  : 
//------------------------------------------------------------------------------
void Pulldown::showAction(QString name)
{
//Todo

MainFrame::vdcdebug("Pulldown","showButton", "QString name");
   for(int i=0; i<this->actions().size();i++){
      QAction *action = this->actions().at(i);
      if(action->text() == name)
         action->setVisible(true);
   }
this->clear();
this->addActions(this->actions());
}

//------------------------------------------------------------------------------
// Method       : refresh()
// Filename     : pulldown.cpp
// Description  :
//------------------------------------------------------------------------------

void Pulldown::refresh()
{
    this->clear();
    this->addActions(this->actions());
}

//------------------------------------------------------------------------------
// Method       : buttonClicked()
// Filename     : pulldown.cpp
// Description  :
//------------------------------------------------------------------------------
void Pulldown::actionClicked(int id)
{
MainFrame::vdcdebug("Pulldown","buttonClicked", "int id");

   emit PulldownActionPressed(QString::number(id));

}

//------------------------------------------------------------------------------
// Method       : keyPressEvent()
// Filename     : pulldown.cpp
// Description  : when ENTER or Return Key is pressed the buttons
//                should be activated also
//------------------------------------------------------------------------------
void Pulldown::keyPressEvent(QKeyEvent *event)
{
    if(event->key()) {
        QString shortcut;
        if(QString::number(event->key()) > "49" && QString::number(event->key()) < "58")
        {
            shortcut = QString::number(event->key()-48);
        } else {
            shortcut = QString::number(event->key()-55);
        }
        if(FglForm *bla = qobject_cast<FglForm *> (parent())) {
            Fgl::Event sevent;
            sevent.id = shortcut;
            bla->addToQueue(sevent);
        }
    }
}

//void Pulldown::keyPressEvent(QKeyEvent *event)
//{
//MainFrame::vdcdebug("Pulldown","keyPressEvent", "QKeyEvent *event");
//   if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
//      QWidget *widget = this->focusWidget();
 //Todo:  
 
//    if(QAction *action = qobject_cast<QAction *> (widget)){
//         action->triggered();
//         return;
//      }
//   }
//   if(event->key() == Qt::Key_Escape){
//      event->ignore();
//      return;
//   //}

//   QPulldown::keyPressEvent(event);
//}

QList<QAction*> Pulldown::actions()
{
MainFrame::vdcdebug("Pulldown","actions", "");

   return this->ql_actions;
}

QAction* Pulldown::getAction(QString name)
{
MainFrame::vdcdebug("Pulldown","getAction", "QString name");

   for(int i = 0; i<this->actions().size(); i++)
   {
      QAction *action = this->actions().at(i);
      if(action->text().toLower() == name.toLower())
      {
          return action;
      }
   }

   return new QAction(NULL);
}

