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
#include <QSortFilterProxyModel>
#include <QComboBox>
#include <QProgressBar>
#include <QHeaderView>
#include <QWidget>
#include <QTabWidget>

#include "xml2fields.h"
#include <models/vwidgets.h>
#include <models/table.h>

XML2Fields::XML2Fields() : QWidget()
{
MainFrame::vdcdebug("XML2Fields","XML2Fields", "");
   // create dummy label to detect the used colors 
   // 
   QLabel colorDummyLabel;
   qcol_BaseColor =
      colorDummyLabel.palette().color(QPalette::Background);
}

QObject* XML2Fields::getLayout()
{
MainFrame::vdcdebug("XML2Fields","getLayout", "");
   return layout;
}

QList<QObject*> XML2Fields::getFieldList()
{
MainFrame::vdcdebug("XML2Fields","getFieldList", "");
   return ql_formFields;
}

void XML2Fields::parseForm(QDomDocument xmlForm)
{
MainFrame::vdcdebug("XML2Fields","parseForm", "QDomDocument xmlForm");
   QDomElement formElement = xmlForm.documentElement(); // <Form>
   parseElement(formElement);
}

void XML2Fields::parseElement(QDomNode xmlNode)
{
MainFrame::vdcdebug("XML2Fields","parseElement", "QDomNode xmlNode");
   QDomNodeList children = xmlNode.childNodes();
   for(int i=0; i<children.count(); ++i){

      QDomNode child = children.at(i);
      if(!child.isElement()){
         continue;
      }

      // Start parsing the first element
      QDomElement currentElement = child.toElement();

      QString nodeName = currentElement.nodeName();

      // Parse for Layouts
      if(nodeName == "VBox"){
         QVBoxLayout *vboxLayout = new QVBoxLayout;
         vboxLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
         vboxLayout->setSpacing(1);

         hidden = currentElement.attribute("hidden").toInt();

         if(currObject == NULL){
            layout = vboxLayout;
            currObject = vboxLayout;
         }
         else{
            parentObject = currObject;
            addToForm(vboxLayout, true);
         }
      }

      if(nodeName == "HBox"){
         QHBoxLayout *hboxLayout = new QHBoxLayout;
         hboxLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
         hboxLayout->setSpacing(1);

         hidden = currentElement.attribute("hidden").toInt();

         if(currObject == NULL){
            layout = hboxLayout;
            currObject = hboxLayout;
         }
         else{
            parentObject = currObject;
            addToForm(hboxLayout, true);
         }
      }

      if(nodeName == "Grid" || nodeName == "Screen"){
         QGridLayout *gridLayout = new QGridLayout;
         gridLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
         gridLayout->setSpacing(0);

         hidden = currentElement.attribute("hidden").toInt();

         if(currObject == NULL){
            layout = gridLayout;
            currObject = gridLayout;
         }
         else{
            parentObject = currObject;
            addToForm(gridLayout, true);
         }
      }

      if(nodeName == "ScrollGrid"){
         QGridLayout *gridLayout = new QGridLayout;
         if(currObject == NULL){
            layout = gridLayout;
            currObject = gridLayout;
         }
         else{
            parentObject = currObject;
            addToForm(gridLayout, true);
         }
      }

      if(nodeName == "Group"){
         QGroupBox *widget = new QGroupBox;
         if(currObject == NULL){
            currObject = widget;
         }
         else{
            parentObject = currObject;
            addToForm(widget, true);
         }
      }

      if(nodeName == "Folder"){
         QTabWidget *widget = new QTabWidget;
         if(currObject == NULL){
            currObject = widget;
         }
         else{
            parentObject = currObject;
            addToForm(widget, true);
         }
      }

      if(nodeName == "Page"){
         QWidget *widget = new QWidget;
         if(currObject == NULL){
            currObject = widget;
         }
         else{
            if(currObject->inherits("QTabWidget")){
               QTabWidget *tabWidget = (QTabWidget*) currObject;
               tabWidget->addTab(widget, currentElement.attribute("text"));
            }
            parentObject = currObject;
            currObject = widget;
         }
      }

      if(nodeName == "Table"){
      }

      // Parse for Fields
      if(nodeName == "HLine" ||
         nodeName == "FormField" ||
         nodeName == "Label" ||
         nodeName == "Matrix" ||
         nodeName == "Table"){
         handleField(currentElement);
      }
      // -- end Fiels

      parseElement(currentElement);
   if(nodeName == "VBox" ||
      nodeName == "HBox" ||
      nodeName == "Grid" ||
      nodeName == "ScrollGrid" ||
      nodeName == "Group" ||
      nodeName == "Folder"){
      if(parentObject != NULL){
         currObject = parentObject;
         hidden = false;
      }
   }
   }


}



void XML2Fields::addToForm(QObject* obj, bool add, int x, int y, int w)
{
MainFrame::vdcdebug("XML2Fields","addToForm", "QObject* obj, bool add, int x, int y, int w");
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
            gridLayout->addWidget(widget, y, x, 1, w);
         }
  
         if(layout != NULL){
            w *= 10;
            gridLayout->addLayout(layout, y, x, Qt::AlignLeft);
         }
      }
   }
  

   if(currObject->inherits("QTabWidget")){
      QTabWidget *tabWidget = (QTabWidget*) currObject;
      if(widget != NULL){
      }
   }
   else{
      if(currObject->inherits("QGroupBox")){
         
      }
      else{
         if(currObject->inherits("QWidget")){
            QWidget *currWidget = (QWidget*) currObject;
            if(layout != NULL){
               currWidget->setLayout(layout);
            }
         }
      }
   }

   if(add){
      this->currObject = obj;
   }
}

void XML2Fields::handleField(const QDomNode& domNode)
{
MainFrame::vdcdebug("XML2Fields","handleField", "const QDomNode& domNode");
   QDomElement xmlField = domNode.toElement();
   QString nodeName = domNode.nodeName();

   if(nodeName == "HLine"){
      Label *label = new Label;
      label->setProperty("style", xmlField.attribute("style"));
      label->setAccessibleName(nodeName);

      label->setFrameShape(QFrame::HLine);
      label->setFrameShadow(QFrame::Sunken);
   
      int x = xmlField.attribute("posX").toInt();
      int y = xmlField.attribute("posY").toInt();
      int w = xmlField.attribute("gridWidth").toInt();
 
      // if attribute is hidden - we hide this widget on the layout
      if(xmlField.attribute("hidden").toInt() || this->hidden)
      {
         label->setHidden(true);
      }

      addToForm(label, false, x, y, w);
   }

  if(nodeName == "Label"){
      Label *label = new Label(xmlField.attribute("text"));
      label->setProperty("style", xmlField.attribute("style"));
      label->setAccessibleName(nodeName);

      int x = xmlField.attribute("posX").toInt();
      int y = xmlField.attribute("posY").toInt();
      int w = xmlField.attribute("gridWidth").toInt();
 
      // if attribute is hidden - we hide this widget on the layout
      if(xmlField.attribute("hidden").toInt() || xmlField.attribute("text") == ":" || this->hidden)
      {
         label->setHidden(true);
      }

      addToForm(label, false, x, y, w);
  }

  if(nodeName == "FormField" ||
     nodeName == "Matrix"){
     handleFormField(xmlField);
  }

  if(nodeName == "Table"){
     handleTableColumn(xmlField);
  }
}

void XML2Fields::handleFormField(const QDomNode& domNode)
{
MainFrame::vdcdebug("XML2Fields","handleFormField", "const QDomNode& domNode");

   QDomElement xmlFormField = domNode.toElement();
   QDomElement xmlField = xmlFormField.firstChild().toElement();
   QString nodeName = xmlField.nodeName();
 
   // Set Font size etc for Texts in Labels etc
   QFont textFont;
   textFont.setPixelSize(12);
   QFontMetrics fm(textFont);
   widthFactor = fm.maxWidth();
   heightFactor = fm.height();

   int w = xmlField.attribute("width").toInt();
   int x = xmlField.attribute("posX").toInt();
   int y = xmlField.attribute("posY").toInt();

   if(nodeName == "Label"){
      Label *label = new Label;
      label->setProperty("style", xmlField.attribute("style"));
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

      QPalette p = label->palette();

      p.setColor(QPalette::Foreground, Qt::blue);
      label->setPalette(p);


      addToForm(label, false, x, y, w);

      ql_formFields << label;

   }

   if(nodeName == "ButtonEdit"){

      //ButtonEdit *lineEdit = WidgetHelper::createLineEdit(xmlFormField);
      QString iconFileName = xmlField.attribute("image");

      ButtonEdit *lineEdit = new ButtonEdit(QString("pics/%1").arg(iconFileName));
      lineEdit->setAccessibleName(xmlFormField.attribute("name"));
      lineEdit->setProperty("style", xmlField.attribute("style"));

      // switch the palettes base color to that value 
      // wich was detected in the consturctor of this object 
      // 
      QPalette p = lineEdit->palette();
      p.setColor(QPalette::Disabled, QPalette::Base, qcol_BaseColor);
      lineEdit->setPalette(p);

      lineEdit->sqlTabName = xmlFormField.attribute("sqlTabName");
      lineEdit->name       = xmlFormField.attribute("name");
      lineEdit->colName    = xmlFormField.attribute("colName");
      lineEdit->setButtonKey(xmlField.attribute("action"));
      QString shift = xmlField.attribute("shift");

      if(!shift.isEmpty())
         lineEdit->setShift(shift);


      lineEdit->setNoEntry(xmlFormField.attribute("noEntry").toInt());
      lineEdit->setSqlType(xmlFormField.attribute("sqlType"));

      //lineEdit->setFixedWidth(w*widthFactor);

      // if attribute is hidden - we hide this widget on the layout
      //
      if(xmlFormField.attribute("hidden").toInt() || this->hidden){
         lineEdit->setHidden(true);
      }

      //WidgetHelper::setValidator(lineEdit);
      //lineEdit->setVisible(true);

      addToForm(lineEdit, false, x, y, w);

      ql_formFields << lineEdit;
   }
}

void XML2Fields::handleTableColumn(const QDomNode& domNode)
{
MainFrame::vdcdebug("XML2Fields","handleTableColumn", "const QDomNode& domNode");

   QDomElement currentElement = domNode.toElement();

   QString nodeName = currentElement.nodeName();

   if(nodeName == "Table"){
      TableModel *model = new TableModel(currentElement.attribute("pageSize").toInt(),
                                         currentElement.childNodes().count());
 
      QSortFilterProxyModel *proxy = new MyFilter(); 
      proxy->setSourceModel(model); 
 
      p_screenRecord = new TableView(); 
      ql_formFields << p_screenRecord; 
      p_screenRecord->tabName = currentElement.attribute("tabName"); 
      p_screenRecord->setShowGrid(true); 
      p_screenRecord->setModel(proxy); 
      //p_screenRecord->setItemDelegate(p_delegate); 
      p_screenRecord->verticalHeader()->hide(); 
      p_screenRecord->setAlternatingRowColors(true); 
      p_screenRecord->setShowGrid(true); 
      p_screenRecord->setMinimumSize(500,500); 

      // when one column is clicked by the user  
      // the entire row hast to be highlighted 
      // 
      p_screenRecord->setSelectionBehavior(QAbstractItemView::SelectRows); 
      p_screenRecord->setSelectionMode(QAbstractItemView::SingleSelection); 
    
      // column should only use the space it really needs 
      // 
      p_screenRecord->resizeColumnsToContents(); //fdinfo: jobnr:18049 
 
      connect(p_screenRecord->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)), p_screenRecord, SLOT(fieldChanged(QModelIndex, QModelIndex))); 
 
      QHeaderView *header = p_screenRecord->horizontalHeader(); 
      header->setMinimumSectionSize(-1); 
      header->setContextMenuPolicy(Qt::ActionsContextMenu); 
      header->setMovable(true); 
      header->setStretchLastSection(true); 
 
      // allow to click the header sections 
      // 
      header->setClickable(true); 
 
      // display the sort indicator in the relevant header section 
      // 
      header->setSortIndicatorShown(true);  
 
      // set the sort indicators directions 
      // 
      header->setSortIndicator(0, Qt::AscendingOrder); //sortieren 
 
      QObject::connect(header, SIGNAL(sectionClicked(int)), 
                       p_screenRecord, SLOT(sortByColumn(int))); 
 
      QObject::disconnect(header, SIGNAL(sectionPressed(int)), 
                          p_screenRecord, SLOT(selectColumn(int))); 

      addToForm(p_screenRecord);
   } 
 
   QDomNodeList children = currentElement.childNodes(); 
   for(int i=0; i<children.count(); ++i){ 
 
      QDomNode child = children.at(i); 
      if(!child.isElement()){ 
         continue; 
      } 
 
      QDomElement currentElement = child.toElement().firstChildElement(); 
 
      QString nodeName = currentElement.nodeName(); 
 
      int w = currentElement.attribute("width").toInt()*10; 
 
      QHeaderView *header = p_screenRecord->horizontalHeader(); 
      header->resizeSection(i, w); 
      w = header->sectionSize(i); 
 
      if(nodeName == "Edit" || 
         nodeName == "ButtonEdit" || 
         nodeName == "DateEdit"){ 
         LineEditDelegate *delegate = new LineEditDelegate(currentElement); 
         p_screenRecord->setItemDelegateForColumn(i, delegate); 

         int fieldCount = ql_formFields.count();
         int colCount = children.count();
            
         int fieldAt = fieldCount - 1 - colCount;
         if(fieldAt >= 0 && ql_formFields.at(fieldAt)->inherits("Label")){
            Label *wi = (Label*) ql_formFields.at(fieldAt);
            if(wi->w == (w/10)){
               p_screenRecord->setColumnLabel(i, wi);
               wi->setVisible(false);
            }
         }
         ql_formFields << delegate;
      } 
 
      if(nodeName == "TextEdit"){ 
         TextEdit *textEdit = WidgetHelper::createTextEdit(currentElement); 
      } 

      if(nodeName == "ComboBox"){
         int fieldCount = ql_formFields.count();
         int colCount = children.count();
            
         int fieldAt = fieldCount - 1 - colCount;

         if( ql_formFields.at(fieldAt)->inherits("Label")){
            Label *wi = (Label*) ql_formFields.at(fieldAt);
            if(wi->w == (w/10)){
               p_screenRecord->setColumnLabel(i, wi);
               wi->setVisible(false);
            }
         }
      }
   } 
}
