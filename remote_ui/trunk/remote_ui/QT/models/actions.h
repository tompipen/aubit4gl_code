//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : actions.h
// Description  : contains class definition for the Actions
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
#ifndef ACTIONS_H
#define ACTIONS_H

#include <QObject>
#include <QAction>

#include <QDomDocument>
#include <QDomNode>
#include <QDomElement>

class Actions : public QObject
{
   Q_OBJECT

public:
   Actions(QWidget *form, QObject *parent = 0);
   Actions(QString title, QObject *parent = 0);
   void parseFile(QDomDocument);
   void parseElement(QDomNode);
   QList<QAction*> actions() { return ql_actions; };
   QStringList names() { return qsl_names; };

   QList<QAction*> ql_actions;
   QStringList qsl_names;
//   void checkActions(QList<QString> actions);

private:
   QWidget *p_fglform;
};
#endif
