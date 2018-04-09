//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : xml2fields.h
// Description  : parses an XMLForm and returns a layout
//                with the avilabe fields
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
#ifndef XML2FIELDS_H
#define XML2FIELDS_H
#include <QObject>
#include <QWidget>

#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

#include <QGroupBox>

#include <QDomDocument>
#include <QDomNode>
#include <QDomElement>

#include <QMainWindow>
#include <models/table.h>

class XML2Fields : public QWidget
{

   Q_OBJECT

public:
   XML2Fields();
   void parseForm(QDomDocument);
   void parseElement(QDomNode);

   TableView *p_screenRecord;

   QList<QObject*> ql_formFields;
   QList<QObject*> getFieldList();

   QObject* getLayout();
private:
   //FglForm* p_fglform;
   QObject *currObject;
   QObject *parentObject;
   QLayout *layout;
   QColor qcol_BaseColor;

   void addToForm(QObject*, bool add=false, int x=0, int y=0, int w=0);
   void handleField(const QDomNode&);
   void handleFormField(const QDomNode&);
   void handleTableColumn(const QDomNode&);

   bool hidden;

   int widthFactor;
   int heightFactor;

   QList<QObject*> ql_objectList;
};

#endif
