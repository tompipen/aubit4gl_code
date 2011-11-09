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
/*    if(this->parentWidget()->geometry().contains(QCursor::pos()))
    {
        e->accept();
        return QMenu::hideEvent(e);
    }
    emit closeEvent();*/

    if(!this->geometry().contains(QCursor::pos())) {
        this->show();
    }
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
            bla->addToQueue(shortcut);
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

