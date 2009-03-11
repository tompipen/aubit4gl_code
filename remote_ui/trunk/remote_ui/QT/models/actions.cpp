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

Actions::Actions(QWidget *form, QObject *parent) : QObject(parent)
{

   this->p_fglform = form;

}

Actions::Actions(QString title, QObject *parent)  : QObject(parent)
{
}

void Actions::parseFile(QDomDocument xmlActions)
{
   QDomElement actionsElement = xmlActions.documentElement();
   parseElement(actionsElement);
}

void Actions::parseElement(QDomNode xmlNode)
{
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

         QKeySequence shortcut(currentElement.attribute("acceleratorName"));
         if(!shortcut.isEmpty())
            ql_shortcutList << shortcut;

         QKeySequence shortcut2(currentElement.attribute("acceleratorName2"));
         if(!shortcut2.isEmpty())
            ql_shortcutList << shortcut2;

         QKeySequence shortcut3(currentElement.attribute("acceleratorName3"));
         if(!shortcut3.isEmpty())
            ql_shortcutList << shortcut3;

         QAction *action = new QAction(text, p_fglform);
         action->setObjectName(name);
         action->setVisible(true);
         action->setEnabled(true);
         action->setShortcuts(ql_shortcutList);

         ql_actions << action;
      }
   }
}
