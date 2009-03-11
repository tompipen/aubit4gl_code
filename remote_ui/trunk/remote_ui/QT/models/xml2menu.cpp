//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : xml2menu.cpp
// Description  : contains the xml2menu class definition
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
#include <QTextEdit>
#include <QTableWidget>
#include <QPushButton>
#include <QAction>
#include <QTreeWidget>

#include "xml2menu.h"


//------------------------------------------------------------------------------
// Method       : XML2Menu()
// Filename     : xml2menu.cpp
// Description  : constructor for the instances
//------------------------------------------------------------------------------

XML2Menu::XML2Menu(QLayout *layout, QString startMenuPosition) : QWidget()
{
   i_cnt = 0;
   i_cntTopLevel = 0;
   i_cntGroup = 0;
   i_cntFolder = 0;

   this->menu = startMenuPosition;
   if(menu=="tree"){
      treeWidget = new QTreeWidget;
      //
      //Animate the tree if it gets expanded
      //not really needed but looks cool :)
      treeWidget->setAnimated(true);

         treeWidget->setMinimumSize(50*5,20*10);
   }
   if(menu=="menu"){
      //dropdown
      menuWidget = new QMenuBar;

      if(layout->inherits("QBoxLayout")){
         QBoxLayout* boxLayout = (QBoxLayout*)layout;
         boxLayout->addWidget(menuWidget);
         boxLayout->setSpacing(6);
         setSizePolicy(QSizePolicy(QSizePolicy::Fixed,
                                QSizePolicy::Fixed));
         boxLayout->setMenuBar(menuWidget);
     }
   }
}


//------------------------------------------------------------------------------
// Method       : ~XML2Menu()
// Filename     : xml2menu.cpp
// Description  : destructor for the instances
//------------------------------------------------------------------------------

XML2Menu::~XML2Menu(){
}


//------------------------------------------------------------------------------
// Method       : outputTree()
// Filename     : xml2menu.cpp
// Description  : prepares the xml for a form and provide its layout
//                - makes recursion 
//------------------------------------------------------------------------------

void XML2Menu::outputTree(const QDomNode& domNode)
{
   QDomNodeList children = domNode.childNodes();

   // checking domNodes childNodes for relevant form elements
   // and handle theire attributes 
   //
   
   bool dummy = false;
   for(int i=0; i<children.count(); ++i){

      if(menu == "tree"){
         QDomNode child = children.at(i);
         if(!child.isElement()){
            continue;
         }

         QDomElement childElement = child.toElement();
         if(childElement.nodeName() == "StartMenu"){
               treeWidget->setHeaderLabel(childElement.attribute("text"));
         }


         if(childElement.nodeName() == "StartMenuGroup"){
            treeWidgetItem = new QTreeWidgetItem;
            treeWidgetItem->setText(0,childElement.attribute("text"));
            if(i_cnt != 0){
               if(i_cntGroup > 0){
                  if(i_cntTopLevel>1){
                     parentTreeItem = parentTreeItems.at(i_cntFolder-i+(i_cntTopLevel-1));
                  }
                  else{
                     parentTreeItem = parentTreeItems.at(i_cntFolder-i);
                  }
               }
               else{
                  parentTreeItem = topLevelTreeItems.at(i_cntTopLevel-1);
               }
               parentTreeItem->addChild(treeWidgetItem);
               i_cntFolder++;
               i_cntGroup++;
            }
            else{
                  treeWidget->addTopLevelItem(treeWidgetItem);
               i_cnt++;
               i_cntTopLevel++;
               topLevelTreeItems << treeWidgetItem;
               dummy = true;
            }
            parentTreeItems << treeWidgetItem;
         }

         if(childElement.nodeName() == "StartMenuCommand"){
            if(i_cntTopLevel>1){
               parentTreeItem = parentTreeItems.at(i_cntFolder+(i_cntTopLevel-1));
            }
            else{
               parentTreeItem = parentTreeItems.at(i_cntFolder);
            }
            treeWidgetItem = new QTreeWidgetItem;
            treeWidgetItem->setText(0,childElement.attribute("text"));
            parentTreeItem->addChild(treeWidgetItem);
            treeCommands << treeWidgetItem;
            treeActions << childElement.attribute("exec");
         }


         if(child == domNode.lastChild()){
            if((childElement.nodeName() == "StartMenuGroup" && i_cntGroup > 1) || childElement.nodeName() == "StartMenuCommand"){
               i_cntGroup--;
            }
         }

         outputTree(childElement);
         if(i_cntGroup == 0 && childElement.nodeName() == "StartMenuGroup" && dummy){
            i_cnt--;
         }
      }
      if(menu == "menu"){
         //DropDown
         QDomNode child = children.at(i);
         if(!child.isElement()){
            continue;
         }

         QDomElement childElement = child.toElement();
         if(childElement.nodeName() == "StartMenuGroup"){
            menuWidgetItem = new QMenu(childElement.attribute("text"));
            if(i_cnt != 0){
               if(i_cntGroup > 0){
                  if(i_cntTopLevel>1){
                     parentMenuItem = parentMenuItems.at(i_cntFolder-i+(i_cntTopLevel-1));
                  }
                  else{
                     parentMenuItem = parentMenuItems.at(i_cntFolder-i);
                  }
               }
               else{
                  parentMenuItem = topLevelMenuItems.at(i_cntTopLevel-1);
               }
               parentMenuItem->addMenu(menuWidgetItem);
               i_cntFolder++;
               i_cntGroup++;
            }
            else{
               menuWidget->addMenu(menuWidgetItem);
               i_cnt++;
               i_cntTopLevel++;
               topLevelMenuItems << menuWidgetItem;
               dummy = true;
            }
            parentMenuItems << menuWidgetItem;
         }

         if(childElement.nodeName() == "StartMenuCommand"){
            if(i_cntTopLevel>1){
               parentMenuItem = parentMenuItems.at(i_cntFolder+(i_cntTopLevel-1));
            }
            else{
               parentMenuItem = parentMenuItems.at(i_cntFolder);
            }
            menuWidgetAction = new QAction(childElement.attribute("text"),this);
            parentMenuItem->addAction(menuWidgetAction);
            connect(menuWidgetAction, SIGNAL(triggered()), this, SLOT(execAction()));
            menuCommands << menuWidgetAction;
            menuActions << childElement.attribute("exec");
         }


         if(child == domNode.lastChild()){
            if((childElement.nodeName() == "StartMenuGroup" && i_cntGroup > 1) || childElement.nodeName() == "StartMenuCommand"){
               i_cntGroup--;
            }
         }

         outputTree(childElement);
         if(i_cntGroup == 0 && childElement.nodeName() == "StartMenuGroup" && dummy){
            i_cnt--;
         }      
      }
   }
}


//------------------------------------------------------------------------------
// Method       : readXML()
// Filename     : xml2menu.cpp
// Description  : reads the xml file for further operations 
//------------------------------------------------------------------------------

int XML2Menu::readXML(const QDomDocument& doc)
{

   QString err;
   int i_err;
   int i_err2;

   // first call of outputTree
   //
   outputTree(doc);
   if(this->treeWidget != NULL){
      connect(this->treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this, SLOT(execAction()));
   }
  
   return 1;
}


//------------------------------------------------------------------------------
// Method       : execAction()
// Filename     : xml2menu.cpp
// Description  : Action to start the clicked Module
//------------------------------------------------------------------------------
void XML2Menu::execAction()
{
   QObject *widget = QObject::sender();
   if (widget->inherits("QAction")) {
      QAction *item = static_cast<QAction*>(widget);
      for(int i=0; i<menuCommands.size(); i++){
         if(item == menuCommands.at(i)){
            sendMenuCommand(treeActions.at(i));
         }
      }
      
   }
   if (widget->inherits("QTreeWidget")) {
      QTreeWidgetItem *item = static_cast<QTreeWidget*>(widget)->currentItem();
      for(int i=0; i<treeCommands.size(); i++){
         if(item == treeCommands.at(i)){
            sendMenuCommand(treeActions.at(i));
         }
      }
   }
}


