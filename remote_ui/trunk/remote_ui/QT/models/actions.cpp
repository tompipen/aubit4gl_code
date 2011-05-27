//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : actions.cpp
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
#include <QIcon>
#include <QKeySequence>

#include "actions.h"
#include "include/fgl.h"
#include "mainframe.h"

Actions::Actions(QWidget *form, QObject *parent) : QObject(parent)
{
MainFrame::vdcdebug("Actions","Actions", "QWidget *form, QObject *parent");

   this->p_fglform = form;

}

void Actions::parseFile(QDomDocument xmlActions)
{
MainFrame::vdcdebug("Actions","parseFile", "QDomDocument xmlActions");
   QDomElement actionsElement = xmlActions.documentElement();
   parseElement(actionsElement);
}

void Actions::parseElement(QDomNode xmlNode)
{
MainFrame::vdcdebug("Actions","parseElement", "QDomNode xmlNode");
   QDomNodeList children = xmlNode.childNodes();
   for(int i=0; i<children.count(); ++i){

      QDomNode child = children.at(i);
      if(!child.isElement()){
         continue;
      }

      // Start parsing the first element
      QDomElement currentElement = child.toElement();

      QString nodeName = currentElement.nodeName();
      

      if(nodeName == "ActionDefault"){
         QList<QKeySequence> ql_shortcutList;
         QString name = currentElement.attribute("name");
         qsl_names << name;
         QString text = currentElement.attribute("text");
         Action *action = new Action(name, text, p_fglform);

         QKeySequence shortcut(currentElement.attribute("acceleratorName"));
         if(!shortcut.isEmpty()){
            action->setAcceleratorName(shortcut);
            ql_shortcutList << shortcut;
         }

         QKeySequence shortcut2(currentElement.attribute("acceleratorName2"));
         if(!shortcut2.isEmpty()){
            action->setAcceleratorName2(shortcut2);
            ql_shortcutList << shortcut2;
         }

         QKeySequence shortcut3(currentElement.attribute("acceleratorName3"));
         if(!shortcut3.isEmpty()){
            action->setAcceleratorName3(shortcut3);
            ql_shortcutList << shortcut3;
         }

         QKeySequence shortcut4(currentElement.attribute("acceleratorName4"));
         if(!shortcut4.isEmpty()){
            action->setAcceleratorName4(shortcut4);
            ql_shortcutList << shortcut4;
         }

         //action->setVisible(true);
         //action->setEnabled(true);
         action->setShortcuts(ql_shortcutList);

         QString image = currentElement.attribute("image");
         if(!image.isEmpty())
            action->setImage(image);

         QString defaultView = currentElement.attribute("defaultView");
         if(!defaultView.isEmpty())
            action->setDefaultView(defaultView);

         ql_actions << action;
      }
   }
}

Action::Action(QObject *parent) : QAction(parent)
{
MainFrame::vdcdebug("Action","Action", "QObject *parent");
   this->setDefaultView("auto");
   this->setEnabled(false);
   this->setVisible(false);
   this->b_accName1 = false;
   this->b_accName2 = false;
   this->b_accName3 = false;
   this->b_accName4 = false;
}

Action::Action(QString name, QString text, QObject *parent) : QAction(text, parent)
{
MainFrame::vdcdebug("Action","Action", "QString name, QString text, QObject *parent");
   this->setDefaultView("auto");
   this->setName(name);
   this->b_accName1 = false;
   this->b_accName2 = false;
   this->b_accName3 = false;
   this->b_accName4 = false;
}

void Action::setName(QString name)
{
MainFrame::vdcdebug("Action","setName", "QString name");
   name = Fgl::stringToKey(name);
   this->qs_name = name;
   this->setObjectName(name);
}

void Action::setComment(QString comment)
{
MainFrame::vdcdebug("Action","setComment", "QString comment");
   this->setToolTip(comment);
}

void Action::setImage(QString image)
{
MainFrame::vdcdebug("Action","setImage", "QString image");
//qDebug()<<"msi : "<<image<<"name :"<<this->name();
   this->setIcon(QIcon(QString("pics:%1").arg(image)));
   qs_image = image;
}

void Action::setAcceleratorName(QString ac)
{
MainFrame::vdcdebug("Action","setAcceleratorName", "QString ac");
   this->qs_acceleratorName = ac;
   b_accName1 = true;
   checkAccelerators();
}

void Action::setAcceleratorName2(QString ac)
{
MainFrame::vdcdebug("Action","setAcceleratorName2", "QString ac");
   this->qs_acceleratorName2 = ac;
   b_accName2 = true;
   checkAccelerators();
}

void Action::setAcceleratorName3(QString ac)
{
MainFrame::vdcdebug("Action","setAcceleratorName3", "QString ac");
   this->qs_acceleratorName3 = ac;
   b_accName3 = true;
   checkAccelerators();
}

void Action::setAcceleratorName4(QString ac)
{
MainFrame::vdcdebug("Action","setAcceleratorName4", "QString ac");
   this->qs_acceleratorName4 = ac;
   b_accName4 = true;
   checkAccelerators();
}

void Action::checkAccelerators()
{
MainFrame::vdcdebug("Action","checkAccelerators", "");
   QList<QKeySequence> ql_shortcuts;
   
   QString acc1 = this->qs_acceleratorName;
   QString acc2 = this->qs_acceleratorName2;
   QString acc3 = this->qs_acceleratorName3;
   QString acc4 = this->qs_acceleratorName4;

   QKeySequence s1(acc1.replace("-", "+"));
   QKeySequence s2(acc2.replace("-", "+"));
   QKeySequence s3(acc3.replace("-", "+"));
   QKeySequence s4(acc4.replace("-", "+"));

   if(b_accName1)
      ql_shortcuts << s1;

   if(b_accName2)
      ql_shortcuts << s2;

   if(b_accName3)
      ql_shortcuts << s3;

   if(b_accName4)
      ql_shortcuts << s4;

   this->setShortcuts(ql_shortcuts);

}

void Action::setDefaultView(QString dv)
{
MainFrame::vdcdebug("Action","setDefaultView", "QString dv");
   this->qs_defaultView = dv;
}
