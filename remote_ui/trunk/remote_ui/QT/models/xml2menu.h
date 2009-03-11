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
#ifndef XML2MENU_H
#define XML2MENU_H

#include <QObject>
#include <QDomDocument>
#include <QDomNodeList>
#include <QErrorMessage>
#include <QBuffer>
#include <QGridLayout>
#include <QList>
#include <QStringList>
#include <QMenuBar>
#include <QMenu>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QWidget>
#include <QDebug>

class XML2Menu : public QWidget
{
   Q_OBJECT

public:
   XML2Menu(QLayout *layout, QString);
   ~XML2Menu();

   QLayout *xmlformLayout;
   int readXML(const QDomDocument&);
   QString menu;
   int i_cnt;
   int i_cntTopLevel;
   int i_cntGroup;
   int i_cntFolder;

   QTreeWidget       *treeWidget;
   QMenuBar *menuWidget;

private:

   //TreeView
   QTreeWidgetItem *treeWidgetItem;
   QTreeWidgetItem *parentTreeItem;
   QList<QTreeWidgetItem*> parentTreeItems;
   QList<QTreeWidgetItem*> treeCommands;
   QList<QTreeWidgetItem*> topLevelTreeItems;
   QStringList treeActions;

   //DropDown
   QMenu    *menuWidgetItem;
   QMenu    *parentMenuItem;
   QAction  *menuWidgetAction;
   QList<QMenu*> parentMenuItems;
   QList<QMenu*> topLevelMenuItems;
   QList<QAction*> menuCommands;
   QStringList menuActions;


   void outputTree(const QDomNode&);

public slots:
   
   void execAction();

signals:

void sendMenuCommand(QString);
};


#endif

