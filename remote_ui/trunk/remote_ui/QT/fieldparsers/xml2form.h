//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : xml2form.h
// Description  : contains the xml2form class definition
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
#ifndef XML2FORM_H
#define XML2FORM_H

#include <QObject>
#include <QDomDocument>
#include <QDomNodeList>
#include <QFile>
#include <QApplication>
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QErrorMessage>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QMainWindow>
#include <QProgressBar>
#include <QRegExpValidator>
#include <QDebug>
#include <QItemDelegate>

#include <models/table.h>
#include <models/vwidgets.h>

class myValidatorToUpper : public QRegExpValidator
{

public:
   //myValidatorToUpper(const QRegExp &rx, QObject *parent) : QRegExpValidator::QRegExpValidator ( rx, parent ) {}
   myValidatorToUpper(const QRegExp &rx, QObject *parent) {
       Q_UNUSED(rx);
       Q_UNUSED(parent);
   }

   QValidator::State validate(QString& input, int &pos) const ;

};

//class XML2Form : public QObject : public QMainWindow
class XML2Form : public QWidget
{
   Q_OBJECT

public:
   XML2Form();
   ~XML2Form();

   QLayout* getLayout() { return this->formLayout; };
   QList<QObject*> getFieldList() { return ql_formFields; };

   QColor qcol_BaseColor;

   bool b_tableColumnUsed;

   int i_cntFolder;
   int i_cntPage;

   int i_formWidth;
   int i_formHeight;

   QWidget *p_arr_XMLFields[800];
   int i_cntFields;

   TableView *p_screenRecord;

   QLayout *xmlformLayout;
   void parseForm(QDomDocument);

   //bool setFieldContent(FglField**);

   QLayout *p_arr_PageLayouts[5];
   QString *p_arr_PageTitle[5];

   //dbudebug
   TableView *tableV;
   LineEditDelegate *p_delegate;
   QStandardItemModel *model;
   int i_cnt;

   // new
   int i_screenRecRow;
   int i_screenRecCol;
   QList<QDomElement> recordViews;
private:
   QList<QObject*> ql_formFields;
   Label   *label;
   QWidget  *childWidget;
   QWidget  *grandChildWidget;
   QLayout  *layout;
   QLayout *formLayout;

   bool b_table;
   QDomDocument inp_arr_fields;

   int getLengthBySqlType(const QString&);


   //QTableWidget     *tableWidget;
   TableView       *tableWidget;

   QTableWidgetItem *tableWidgetItem;

   QStringList qsl_horizontalHeader;

// QWidget root;

   void outputTree(const QDomNode&, QLayout*);
   bool handleFormField(const QDomElement&, QLayout*);
   bool handleTableColumn(const QDomElement&, QLayout*);
   bool handleTableColumn2(const QDomElement&, QLayout*);

};

class PageTab : public QWidget
{
   Q_OBJECT

public:
   PageTab();

};

#endif

