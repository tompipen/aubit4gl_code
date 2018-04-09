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

class Action : public QAction
{
   Q_OBJECT

public:
   Action(QObject *parent);
   Action(QString name, QString text="", QObject *parent=NULL);
   void setName(QString);
   void setComment(QString);
   void setImage(QString);
   void setAcceleratorName(QString);
   void setAcceleratorName2(QString);
   void setAcceleratorName3(QString);
   void setAcceleratorName4(QString);
   void setAccNameEnabled(bool e) { b_accName1 = e;  checkAccelerators(); };
   void setAccName2Enabled(bool e) { b_accName2 = e;  checkAccelerators(); };
   void setAccName3Enabled(bool e) { b_accName3 = e; checkAccelerators(); };
   void setAccName4Enabled(bool e) { b_accName4 = e; checkAccelerators(); };
   bool accNameEnabled() { return b_accName1; };
   bool accName2Enabled() { return b_accName2; };
   bool accName3Enabled() { return b_accName3; };
   bool accName4Enabled() { return b_accName4; };
   void checkAccelerators();
   void setDefaultView(QString);
   QString name() { return qs_name; };
   QString comment() { return toolTip(); };
   QString image() { return qs_image; };
   QString acceleratorName() { return qs_acceleratorName; };
   QString acceleratorName2() { return qs_acceleratorName2; };
   QString acceleratorName3() { return qs_acceleratorName3; };
   QString acceleratorName4() { return qs_acceleratorName4; };
   QString defaultView() { return qs_defaultView; };

private:
   QString qs_name;
   QString qs_comment;
   QString qs_image;
   QString qs_acceleratorName;
   QString qs_acceleratorName2;
   QString qs_acceleratorName3;
   QString qs_acceleratorName4;
   bool b_accName1;
   bool b_accName2;
   bool b_accName3;
   bool b_accName4;
   QString qs_defaultView;

public slots:

};

class Actions : public QObject
{
   Q_OBJECT

public:
   Actions(QObject *parent = 0);
   Actions(QString title, QObject *parent = 0);
   void parseFile(QDomDocument);
   void parseElement(QDomNode);
   QList<Action*> actions() { return ql_actions; };
   QStringList names() { return qsl_names; };

   QList<Action*> ql_actions;
   QStringList qsl_names;
//   void checkActions(QList<QString> actions);

private:
   QWidget *p_fglform;

};

#endif
