//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : toolbar.h
// Description  : contains class definition for the ToolBar
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
#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QObject>
#include <QToolBar>

#include <QDomDocument>
#include <QDomNode>
#include <QDomElement>

class ToolBar : public QToolBar
{
   Q_OBJECT

public:
   ToolBar(QWidget *parent = 0);
   void parseFile(QDomDocument);
   void parseElement(QDomNode);
   QList<QAction*> actions(){ return ql_toolBarActions; };

   ToolBar  operator= (ToolBar* toolBar);
   QList<QAction*> ql_toolBarActions;
   void checkActions(QList<QString> actions, bool input);

};
#endif
