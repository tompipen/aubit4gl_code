//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : toolbar.cpp
// Description  : contains class definition for the toolbar
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
#include <QResizeEvent>
#include <QIcon>

#include "toolbar.h"
#include "actions.h"
#include "mainframe.h"

ToolBar::ToolBar(QWidget *parent) : QToolBar(parent)
{
MainFrame::vdcdebug("ToolBar","ToolBar", "QWidget *parent");
   setObjectName("ToolBar");
   setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));
   setIconSize(QSize(15,15));
}

void ToolBar::parseFile(QDomDocument xmlToolBar)
{
MainFrame::vdcdebug("ToolBar","parseFile", "QDomDocument xmlToolBar");
   QDomElement toolBarElement = xmlToolBar.documentElement();
   parseElement(toolBarElement);
}

void ToolBar::parseElement(QDomNode xmlNode)
{
MainFrame::vdcdebug("ToolBar","parseElement", "QDomNode xmlNode");
   // Start parsing the first element
   QDomElement currentElement = xmlNode.toElement();
   QString nodeName = currentElement.nodeName();

   if(nodeName == "ToolBar"){
      // not used atm
      QString name = currentElement.attribute("name");


      // If true hides the Toolbar icon
      bool iconHidden = currentElement.attribute("iconHidden").toInt();
      
      // If true hides the text for the icon (default = true)
      bool buttonTextHidden = currentElement.attribute("buttonTextHidden").toInt();
      
      // If true hides the text for the icon (default = true)
      bool hidden = currentElement.attribute("hidden").toInt();
      
      //defines where the text is shown - options are beside and under 
      QString buttonTextPosition = currentElement.attribute("buttonTextPosition");

      if(!buttonTextPosition.isEmpty()){
        if(buttonTextPosition == "beside"){
           setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        }

        if(buttonTextPosition == "under"){
           setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        }
      }

      if(iconHidden){
         setToolButtonStyle(Qt::ToolButtonTextOnly);
      }

      if(buttonTextHidden){
         setToolButtonStyle(Qt::ToolButtonIconOnly);
      }

      if(hidden){
         setVisible(false);
      }
   }
  

   QDomNodeList children = xmlNode.childNodes();
   for(int i=0; i<children.count(); ++i){

      QDomNode child = children.at(i);
      if(!child.isElement()){
         continue;
      }

      // Start parsing the first element
      currentElement = child.toElement();

      nodeName = currentElement.nodeName();
      

      if(nodeName == "ToolBarSeparator"){
         this->addSeparator();
      }

      if(nodeName == "ToolBarItem"){
         QString name = currentElement.attribute("name");

/*
         QString image = ":pics/";
         image.append(currentElement.attribute("image"));
*/
         QString image = currentElement.attribute("image");

         QString text = currentElement.attribute("text");

         QString comment = currentElement.attribute("comment");
 
         //Action *action = new Action(QIcon(image), text, 0);
         Action *action = new Action(name, text, 0);
         action->setImage(image);
         action->setComment(comment);

         action->setEnabled(false);


         this->addAction(action);
         ql_toolBarActions << action;
      }
   }
}

void ToolBar::checkActions(QList<QString> menuActions, bool input)
{
MainFrame::vdcdebug("ToolBar","checkActions", "QList<QString> menuActions, bool input");

   QList<QAction* > toolBarActions = this->actions();
   for(int i=0; i<toolBarActions.size(); i++){
      toolBarActions.at(i)->setEnabled(false);
   }

   for(int i=0; i<menuActions.size(); i++){
      QString menuAction = menuActions.at(i);
      for(int k=0; k<toolBarActions.size(); k++){
         QString toolBarAction = toolBarActions.at(k)->text();
         if(menuAction == toolBarAction){
            toolBarActions.at(k)->setEnabled(true);
         }
      }
   }

   if(input){
      for(int i=0; i<toolBarActions.size(); i++){
         if(toolBarActions.at(i)->objectName() == "accept" ||
             toolBarActions.at(i)->objectName() == "cancel"){
             toolBarActions.at(i)->setEnabled(true);
         }
      }
   }
}
