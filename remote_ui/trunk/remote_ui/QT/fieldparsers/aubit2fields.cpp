//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : xml2fields.cpp
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
#include <QDebug>

#include "aubit2fields.h"
#include <models/vwidgets.h>

Aubit2Fields::Aubit2Fields() : QWidget()
{
MainFrame::vdcdebug("Aubit2Fields","Aubit2Fields", "");
   layout = new QVBoxLayout;
   layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
   layout->setSpacing(0);
   QGridLayout *gridLayout = new QGridLayout;
   layout->addLayout(gridLayout);
   currObject = (QObject*) gridLayout;
}

QLayout* Aubit2Fields::getLayout()
{
MainFrame::vdcdebug("Aubit2Fields","getLayout", "");
   return layout;
}

QList<QWidget*> Aubit2Fields::getFieldList()
{
MainFrame::vdcdebug("Aubit2Fields","getFieldList", "");
   return ql_formFields;
}

void Aubit2Fields::parseForm(QDomDocument xmlForm)
{
MainFrame::vdcdebug("Aubit2Fields","parseForm", "QDomDocument xmlForm");

   QDomElement formElement = xmlForm.documentElement(); // <Form>
   parseElement(formElement);

}

void Aubit2Fields::parseElement(QDomNode xmlNode)
{
MainFrame::vdcdebug("Aubit2Fields","parseElement", "QDomNode xmlNode");
   QDomNodeList children = xmlNode.childNodes();
   for(int i=0; i<children.count(); ++i){

      QDomNode child = children.at(i);
      if(!child.isElement()){
         continue;
      }

      // Start parsing the first element
      QDomElement currentElement = child.toElement();

      QString nodeName = currentElement.nodeName();

      if(nodeName == "FORMFIELD"){
         int x = currentElement.attribute("ROW").toInt();
         int y = currentElement.attribute("COLUMN").toInt();
         int w = currentElement.attribute("COLS").toInt();
         QString name = currentElement.attribute("TABCOL");
         int index = name.indexOf(".");
         name.remove(0, index+1);
         QString colName = currentElement.attribute("TABCOL");

         if(currentElement.attribute("WIDGET").toUpper() == "LABEL"){
            Label *label = new Label;
            label->name = name;
            label->colName = colName;
            addToForm(label, false, y, x, w);
            ql_formFields << label;
         }

         if(currentElement.attribute("WIDGET").isEmpty()){
            ButtonEdit *lineEdit = new ButtonEdit;
            lineEdit->setFixedWidth(w*7);
            lineEdit->name = name;
            lineEdit->colName = colName;
            addToForm(lineEdit, false, y, x, w);
            ql_formFields << lineEdit;
         }
      }

      if(nodeName == "FORMLABEL"){
         int x = currentElement.attribute("ROW").toInt();
         int y = currentElement.attribute("COLUMN").toInt();
         QLabel *label = new QLabel(currentElement.text());
         addToForm(label, false, y, x);
      }

      parseElement(currentElement);

   } // end for
}

void Aubit2Fields::addToForm(QObject* obj, bool add, int x, int y, int w)
{
MainFrame::vdcdebug("Aubit2Fields","addToForm", "QObject* obj, bool add, int x, int y, int w");
// TODO: Find a way to determine if obj will be currObject in the end

   QLayout *layout = NULL;
   QWidget *widget = NULL;

   if(obj->inherits("QLayout")){
      layout = (QLayout*) obj;
   }

   if(obj->inherits("QWidget")){
      widget = (QWidget*) obj;
   }

   if(currObject->inherits("QLayout")){
      if(currObject->inherits("QBoxLayout")){
         QBoxLayout *boxLayout = (QBoxLayout*) currObject;
         if(widget != NULL){
            boxLayout->addWidget(widget);
         }
  
         if(layout != NULL){
            boxLayout->addLayout(layout);
         }
      }

      if(currObject->inherits("QGridLayout")){
         QGridLayout *gridLayout = (QGridLayout*) currObject;
         if(widget != NULL){
            gridLayout->addWidget(widget, y, x, Qt::AlignTop|Qt::AlignLeft);
            gridLayout->setColumnMinimumWidth(x, w);
         }
  
         if(layout != NULL){
            w *= 10;
            gridLayout->addLayout(layout, y, x, Qt::AlignTop|Qt::AlignLeft);
            gridLayout->setColumnMinimumWidth(x, w);
         }
      }
   }
  
   if(currObject->inherits("QWidget")){
      QWidget *currWidget = (QWidget*) currObject;
      if(widget != NULL){
         widget->setParent(currWidget);
      }
      if(layout != NULL){
         currWidget->setLayout(layout);
      }
   }

   if(add){
      this->currObject = obj;
   }
}

void Aubit2Fields::handleField(const QDomNode& domNode)
{
MainFrame::vdcdebug("Aubit2Fields","handleField", "const QDomNode& domNode");
   QDomElement xmlField = domNode.toElement();
   QString nodeName = domNode.nodeName();

   if(nodeName == "HLine"){
      Label *label = new Label;
      label->setAccessibleName(nodeName);

      label->setFrameShape(QFrame::HLine);
      label->setFrameShadow(QFrame::Sunken);
   
      int x = xmlField.attribute("posX").toInt();
      int y = xmlField.attribute("posY").toInt();
      int w = xmlField.attribute("gridWidth").toInt();
 
      // if attribute is hidden - we hide this widget on the layout
      if(xmlField.attribute("hidden").toInt())
      {
         label->setHidden(true);
      }

      addToForm(label, false, x, y, w);
   }

  if(nodeName == "Label"){
      Label *label = new Label(xmlField.attribute("text"));
      label->setAccessibleName(nodeName);

      int x = xmlField.attribute("posX").toInt();
      int y = xmlField.attribute("posY").toInt();
      int w = xmlField.attribute("gridWidth").toInt();
 
      // if attribute is hidden - we hide this widget on the layout
      if(xmlField.attribute("hidden").toInt() || xmlField.attribute("text") == ":")
      {
         label->setHidden(true);
      }

      addToForm(label, false, x, y, w);
  }

  if(nodeName == "FormField" ||
     nodeName == "Matrix"){
     handleFormField(xmlField);
  }
}

void Aubit2Fields::handleFormField(const QDomNode& domNode)
{
MainFrame::vdcdebug("Aubit2Fields","handleFormField", "const QDomNode& domNode");
   QDomElement xmlFormField = domNode.toElement();
   QDomElement xmlField = xmlFormField.firstChild().toElement();
   QString nodeName = xmlField.nodeName();
   int width_factor = 1;
   
   // Set Font size etc for Texts in Labels etc
   QFont textFont;
   textFont.setPixelSize(12);

   if(nodeName == "Label"){
      Label *label = new Label;
      label->setFont(textFont);
      
      label->sqlTabName = xmlFormField.attribute("sqlTabName");
      label->name       = xmlFormField.attribute("name");
      label->colName    = xmlFormField.attribute("colName");

      QString labelName = xmlFormField.attribute("text");

      if(labelName.isNull()){
         labelName = xmlFormField.attribute("colName");
      }

      label->setAccessibleName(labelName);
      label->setText(labelName);

      int w = xmlField.attribute("width").toInt();
      int x = xmlField.attribute("posX").toInt();
      int y = xmlField.attribute("posY").toInt();

      QPalette p = label->palette();

      p.setColor(QPalette::Foreground, Qt::blue);
      label->setPalette(p);

      // if attribute is hidden - we hide this widget on the layout
      //
      if(xmlFormField.attribute("hidden").toInt()){
         label->setHidden(true);
      }

      addToForm(label, false, x, y, w);

      ql_formFields << label;

   }

   if(nodeName == "Edit"){
      ButtonEdit *lineEdit = new ButtonEdit(xmlField.attribute("image"));
      lineEdit->setAccessibleName(xmlFormField.attribute("name"));

      lineEdit->sqlTabName = xmlFormField.attribute("sqlTabName");
      lineEdit->name       = xmlFormField.attribute("name");
      lineEdit->colName    = xmlFormField.attribute("colName");

      int w = xmlField.attribute("width").toInt() * width_factor;
      int x = xmlField.attribute("posX").toInt();
      int y = xmlField.attribute("posY").toInt();
      lineEdit->setNoEntry(xmlFormField.attribute("noEntry").toInt());
      lineEdit->setSqlType(xmlFormField.attribute("sqlType"));
      lineEdit->setButtonKey(xmlField.attribute("action"));

      // if attribute is hidden - we hide this widget on the layout
      //
      if(xmlFormField.attribute("hidden").toInt()){
         lineEdit->setHidden(true);
      }

      addToForm(lineEdit, false, x, y, w);

      ql_formFields << lineEdit;
   }

   if(nodeName == "ButtonEdit"){

      QString iconFileName = xmlField.attribute("image");

      ButtonEdit *lineEdit = new ButtonEdit(iconFileName);
      lineEdit->setAccessibleName(xmlFormField.attribute("name"));

      lineEdit->sqlTabName = xmlFormField.attribute("sqlTabName");
      lineEdit->name       = xmlFormField.attribute("name");
      lineEdit->colName    = xmlFormField.attribute("colName");

      int w = xmlField.attribute("width").toInt() * width_factor;
      int x = xmlField.attribute("posX").toInt();
      int y = xmlField.attribute("posY").toInt();
      lineEdit->setNoEntry(xmlFormField.attribute("noEntry").toInt());
      lineEdit->setSqlType(xmlFormField.attribute("sqlType"));

      // if attribute is hidden - we hide this widget on the layout
      //
      if(xmlFormField.attribute("hidden").toInt()){
         lineEdit->setHidden(true);
      }

      addToForm(lineEdit, false, x, y, w);

      ql_formFields << lineEdit;
   }

   if(nodeName == "TextEdit"){
      TextEdit *textEdit = new TextEdit;
      
      int w = xmlField.attribute("width").toInt() * width_factor;
      int x = xmlField.attribute("posX").toInt();
      int y = xmlField.attribute("posY").toInt();

      textEdit->sqlTabName = xmlFormField.attribute("sqlTabName");
      textEdit->name       = xmlFormField.attribute("name");
      textEdit->colName    = xmlFormField.attribute("colName");

      // if attribute is hidden - we hide this widget on the layout
      //
      if(xmlFormField.attribute("hidden").toInt()){
         textEdit->setHidden(true);
      }

      // exception for textedits in matrix - when more then 1 textEditLine we 
      // have to alter the field counter.   #jobnr: 18042
      int pageSize = 0;
      ButtonEdit *lineEdit = new ButtonEdit;
      if(xmlFormField.nodeName()=="Matrix")
      {
         pageSize = xmlFormField.attribute("pageSize").toInt();
      }
      else{
         pageSize = xmlField.attribute("height").toInt();
      }

      QSize widgetSize;
      textEdit->setFixedHeight(lineEdit->sizeHint().height() *
                               pageSize);

      addToForm(textEdit, false, x, y, w);

      ql_formFields << textEdit;
   }


   if(nodeName == "Image"){
      QPixmap *image = new QPixmap("pics/ventas.png");
      Label *imageLabel = new Label;

      int x = xmlField.attribute("posX").toInt();
      int y = xmlField.attribute("posY").toInt();
      int w = xmlField.attribute("width").toInt();

      imageLabel->setPixmap(*image);

      // if attribute is hidden - we hide this widget on the layout
      //
      if(xmlFormField.attribute("hidden").toInt()){
         imageLabel->setHidden(true);
      }
   }

   if(nodeName == "ComboBox"){
   }

   if(nodeName == "ProgressBar"){
   }
}
