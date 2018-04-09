//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// File name    : parser.cpp
// Description  : 
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
#ifndef PARSER_H
#define PARSER_H

#include <QtGui>
#include <QDomDocument>
#include <QDomNode>
#include <models/vwidgets.h>

class XmlParser : public QWidget
{

   Q_OBJECT

public:
   XmlParser(QWidget *p_fglform);
   void parseForm(QDomDocument);
   QWidget* getFormWidget();
   QList<QWidget*> getFieldList();
   QList<FormField*> getFglFields();
   QList<QWidget*> getFieldListConst();
private:
   QHBoxLayout* layout;
   QWidget *p_fglform;
   QList<QWidget*> ql_formFieldsConst;
   QList<QWidget*> ql_formFields;
   QList<FormField*> ql_fglFields;
   QColor qcol_BaseColor;
   QLayout *currentLayout;
   QWidget *currentWidget;
   int gridWidth;
   bool layoutChanged;
   bool hidden;
   bool hasTabs = false;

   void parseElement(const QDomNode&);
   void handleTableColumn(const QDomNode&);
   void handleMatrixColumn(const QDomNode&);
   void handleRecordView(const QDomNode&);
   void addWidgets(QWidget*, bool add=false, int y=0, int x=0, int gridWidth=0, int span = 1);
   void addLayout(QLayout*);


};

#endif
