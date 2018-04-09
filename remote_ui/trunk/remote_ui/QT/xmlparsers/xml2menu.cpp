//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : xml2menu.h
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
#include <QItemDelegate>
#include <QTreeWidget>
#include <QHeaderView>

#include "xml2menu.h"
#include "include/vdc.h"


//------------------------------------------------------------------------------
// Method       : XML2Menu()
// Filename     : xml2menu.cpp
// Description  : constructor for the instances
//------------------------------------------------------------------------------

XML2Menu::XML2Menu(QString startMenuPosition, QString name) : QWidget()
{
   i_cnt = 0;
   i_cntTopLevel = 0;
   i_cntGroup = 0;
   i_cntFolder = 0;
   mFormName = name;

   this->menu = startMenuPosition;
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
   // and handle their attributes
   //
   bool dummy = false;
   for(int i=0; i<children.count(); ++i){

      if(menu == "tree"){
         QDomNode child = children.at(i);
         if(!child.isElement()){
            continue;
         }

         QDomElement childElement = child.toElement();
//         if(childElement.nodeName() == "StartMenu"){
//               treeWidget->setHeaderLabel(childElement.attribute("text"));
//         }


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

   QString menu;
   QString menuType = VDC::readSettingsFromLocalIni("","startMenuPosition");

   if(!menuType.isEmpty() && menuType != "-1")
   {
       menu = menuType;
   } else {
       menu = "tree";
   }

   if(menu == "tree"){
      treeWidget = new QTreeWidget;
      treeWidget->setMinimumSize(50*5,20*10);
      treeWidget->setSelectionMode(QAbstractItemView::SingleSelection);
      treeWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
      treeWidget->header()->hide();
      treeWidget->setStyleSheet("QTreeWidget { border: none; outline: none; margin-top: 2px; } QTreeView::item:selected { background-color: #005a9f; color: white; }"
                                                   "QTreeView::item:hover:!selected { background-color: #f7f7f7; }" );
      createTreeMenu(doc);
      connect(this->treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this, SLOT(execAction()));
      connect(this->treeWidget, SIGNAL(itemExpanded(QTreeWidgetItem*)), this, SLOT(saveExpanded()));
      connect(this->treeWidget, SIGNAL(itemCollapsed(QTreeWidgetItem*)), this, SLOT(saveExpanded()));
      return 1;
   }

   if(menu == "menu"){
      menuWidget = new QMenuBar;
      createActionMenu(doc);
      return 1;
   }

   return -1;
}

void XML2Menu::createTreeMenu(const QDomNode &domNode)
{
   QDomNodeList children = domNode.childNodes();

   // checking domNodes childNodes for relevant form elements
   // and handle theire attributes 
   //
   bool dummy = false;
   int cnt_childs = children.count();
   for(int i=0; i<cnt_childs; ++i){
      QDomNode child = children.at(i);
      if(!child.isElement()){
         continue;
      }

      QDomElement childElement = child.toElement();
//      if(childElement.nodeName() == "StartMenu"){
//            treeWidget->setHeaderLabel(childElement.attribute("text"));
//      }


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

      createTreeMenu(childElement);
      if(i_cntGroup == 0 && childElement.nodeName() == "StartMenuGroup" && dummy){
         i_cnt--;
      }
   }
}

void XML2Menu::createActionMenu(const QDomNode &domNode)
{
   QDomNodeList children = domNode.childNodes();

   // checking domNodes childNodes for relevant form elements
   // and handle theire attributes 
   //
   bool dummy = false;

   for(int i=0; i<children.count(); ++i){
      QDomNode child = children.at(i);
      if(!child.isElement()){
         continue;
      }

      QDomElement childElement = child.toElement();
      if(childElement.nodeName() == "StartMenuGroup"){
         menuWidgetItem = new QMenu("&" + childElement.attribute("text"));
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
         menuWidgetAction = new QAction("&" + childElement.attribute("text"),this);
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

      createActionMenu(childElement);
      if(i_cntGroup == 0 && childElement.nodeName() == "StartMenuGroup" && dummy){
         i_cnt--;
      }      
   }
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
            sendMenuCommand(menuActions.at(i));
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

void XML2Menu::saveExpanded()
{
    //If rememberMainMenu is 2 then do not save the expand state from the menu
    int saveExpand = VDC::readSettingsFromLocalIni("","rememberMainMenu").toInt();

    if(saveExpand == 2)
    {
        return;
    }

    if(treeWidget->isVisible())
    {
        VDC::removeSettingsKeysWith(getFormName(), "setAutoExpanded");
        for(int i=0; i < treeWidget->topLevelItemCount(); i++) {
            if(treeWidget->topLevelItem(i)) {
                QTreeWidgetItem *tWidgetItem = treeWidget->topLevelItem(i);
                for(int j=0; j < tWidgetItem->childCount(); j++) {
                    if(tWidgetItem->isExpanded()) {
                        VDC::saveSettingsToIni(getFormName(), QString(tWidgetItem->text(0) + "/setAutoExpanded"), QString::number(tWidgetItem->isExpanded()));
                    }

                    if(tWidgetItem->child(j)) {
                        QTreeWidgetItem *childWidgetItem = tWidgetItem->child(j);
                        if(childWidgetItem->isExpanded()) {
                            VDC::saveSettingsToIni(getFormName(), QString(tWidgetItem->text(0) + "/" + childWidgetItem->text(0) + "/setAutoExpanded"), QString::number(childWidgetItem->isExpanded()));
                        }

                        for(int k=0; k < childWidgetItem->childCount(); k++) {
                            if(childWidgetItem->child(k)) {
                                QTreeWidgetItem *child2WidgetItem = childWidgetItem->child(k);
                                if(child2WidgetItem->isExpanded()) {
                                    VDC::saveSettingsToIni(getFormName(), QString(tWidgetItem->text(0) + "/" + childWidgetItem->text(0) + "/" + child2WidgetItem->text(0) + "/setAutoExpanded"), QString::number(child2WidgetItem->isExpanded()));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

QWidget* XML2Menu::getMenu()
{
   if(menu == "tree"){
      return treeWidget;
   }

   if(menu == "menu"){
      return menuWidget;
   }

   return NULL;
}
