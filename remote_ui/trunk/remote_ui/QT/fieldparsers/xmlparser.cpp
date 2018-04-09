//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// File name    : parser.cpp
// Description  : parses xml form files
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


#include "xmlparser.h"
#include <models/vwidgets.h>
#include <models/matrix.h>
#include <models/table.h>
#include <models/fglform.h>
#include "mainframe.h"

XmlParser::XmlParser(QWidget *p_fglform) : QWidget(p_fglform)
{
MainFrame::vdcdebug("Parser","Parser", "QWidget *p_fglform");
   this->setFocusPolicy(Qt::NoFocus);
   this->p_fglform = p_fglform;
   layout = new QHBoxLayout;
   layout->setSpacing(0);
   this->setLayout(layout);
   currentWidget = new QWidget(this);
   currentWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
   this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
   currentLayout = NULL;
   layoutChanged = false;
   hidden = false;
   gridWidth = 0;
   // create dummy label to detect the used colors 
   // 

}

QWidget* XmlParser::getFormWidget()
{
MainFrame::vdcdebug("Parser","getFormWidget", "");
   return this;
}

QList<QWidget*> XmlParser::getFieldListConst()
{
MainFrame::vdcdebug("Parser","getFieldListConst", "");
   return ql_formFieldsConst;
}

QList<QWidget*> XmlParser::getFieldList()
{
MainFrame::vdcdebug("Parser","getFieldList", "");
   return ql_formFields;
}
QList<FormField*> XmlParser::getFglFields()
{
    return ql_fglFields;
}

void XmlParser::parseForm(QDomDocument xmlForm)
{
MainFrame::vdcdebug("Parser","parseForm", "QDomDocument xmlForm");
   // get first element of XML form and start parsing
   QDomElement formElement = xmlForm.documentElement();
   parseElement(formElement);

   layout->addWidget(currentWidget);
   layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

   //order fields by fieldid
   int cnt=0;
   bool sorted = false;
   while(!sorted){
      for(int i=0; i<ql_formFields.count(); i++){
         QWidget *w = ql_formFields.takeAt(i);

         if(w->property("fieldId").toInt() >= 0) {
             ql_formFields.insert(w->property("fieldId").toInt(), w);
         }
      }
      sorted = true;
      for(int i=0; i<ql_formFields.count(); i++){
         if(ql_formFields.at(i)->property("fieldId").toInt() != i){
            sorted = false;
         }
      }

      if(cnt > ql_formFields.count()*ql_formFields.count()*10){
         return;
         qFatal("SORTING FIELDS FAILED EXITING");
         break;
      }
      cnt++;
   }
}

void XmlParser::parseElement(const QDomNode& xmlNode)
{
MainFrame::vdcdebug("Parser","parseElement", "const QDomNode& xmlNode");
   // start parsing specific nodes
   QDomElement xmlFormElement = xmlNode.toElement();

   bool layoutChanged = false;
   bool b_folder = false;
   bool hidden = false;

   QString nodeName;
   QDomElement currentElement;

   nodeName = xmlNode.nodeName();
   currentElement = xmlNode.toElement();
   if(nodeName == "Form")
   {

       int gridWidth      = currentElement.attribute("width").toInt();
       /*int gridHeight     = currentElement.attribute("height").toInt();
       QString delimiters = currentElement.attribute("delimiters");
       QString sqldbname  = currentElement.attribute("sqlDbName");
       QString formname   = currentElement.attribute("name");
       QString encoding   = currentElement.attribute("encoding");*/

       this->gridWidth = gridWidth;

   }



   QDomNodeList children = xmlNode.childNodes();
   for(int i=0; i<children.count(); ++i){

      QDomNode child = children.at(i);
      if(!child.isElement()){
         continue;
      }

      // start parsing the first element
      currentElement = child.toElement();

      nodeName = currentElement.nodeName();



/*
      if(nodeName == "Screen"){
         QGridLayout *layout = new QGridLayout;
         layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

         if(currentLayout == NULL){
            currentWidget->setLayout(layout);
         }
         else{
            addLayout(layout);
            layoutChanged = true;
         }

         currentLayout = layout;

         hidden = currentElement.attribute("hidden").toInt();
         if(hidden){
            this->hidden = true;
         }
      }
*/

      if(nodeName == "Grid" ||
         nodeName == "Screen"){
         QGridLayout *layout = new QGridLayout;
         layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
         layout->setSpacing(0);
         layout->setVerticalSpacing(3);
         layout->setHorizontalSpacing(3);
      //   layout->setSizeConstraint(QLayout::SetMinimumSize);
         if(currentLayout == NULL){
            currentWidget->setLayout(layout);
         }
         else{
            addLayout(layout);
            layoutChanged = true;
         }

         currentLayout = layout;

         hidden = currentElement.attribute("hidden").toInt();
         if(hidden){
            this->hidden = true;
         }

      }

      if(nodeName == "VBox"){
         QVBoxLayout *layout = new QVBoxLayout;
         layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
         if(currentLayout == NULL){
            currentWidget->setLayout(layout);
         }
         else{
            addLayout(layout);
            layoutChanged = true;
         }

         currentLayout = layout;

         hidden = currentElement.attribute("hidden").toInt();
         if(hidden){
            this->hidden = true;
         }
      }

      if(nodeName == "HBox"){
         QHBoxLayout *layout = new QHBoxLayout;
         layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
         if(currentLayout == NULL){
            currentWidget->setLayout(layout);
         }
         else{
            addLayout(layout);
            layoutChanged = true;
         }

         currentLayout = layout;

         hidden = currentElement.attribute("hidden").toInt();
         if(hidden){
            this->hidden = true;
         }
      }


      if(nodeName == "Folder"){
         TabWidget *folder = new TabWidget;
         folder->setAccessibleName("Folder");
         currentWidget = folder;
         b_folder = true;
      }

      if(nodeName == "Page"){
         QString text = currentElement.attribute("text");

         if(QTabWidget *tabWidget = qobject_cast<QTabWidget *> (currentWidget)){
            QWidget *wi = new QWidget;
            wi->setAccessibleName(text);
            tabWidget->addTab(wi, text);
            currentWidget = wi;
            currentLayout = NULL;
            hasTabs = true;            
         }
         else{
            if(QTabWidget *tabWidget = qobject_cast<QTabWidget *> (currentWidget->parent()->parent())){
               QWidget *wi = new QWidget;
               wi->setAccessibleName(text);
               tabWidget->addTab(wi, text);
               currentWidget = wi;
               currentLayout = NULL;
            }
         }

      }

      if(nodeName == "FormField"){

         FormField *formField = WidgetHelper::createFormField(currentElement, p_fglform);
         ql_fglFields << formField;

         QWidget *widget = WidgetHelper::createFormWidget(currentElement, p_fglform);
         formField->addField(widget);

         QDomElement fieldElement = currentElement.firstChildElement();

         //int w = fieldElement.attribute("width").toInt();
         int posX = fieldElement.attribute("posX").toInt();
         int posY = fieldElement.attribute("posY").toInt();
         int gridWidth = fieldElement.attribute("gridWidth").toInt();

         widget->setProperty("fieldId", currentElement.attribute("fieldId").toInt());

         addWidgets(widget, true, posY, posX, gridWidth);
         continue;
      }

      if(nodeName == "Matrix"){
         int pageSize = currentElement.attribute("pageSize").toInt();

         QDomElement fieldElement = currentElement.firstChildElement();

         QWidget *widget = WidgetHelper::createFormWidget(currentElement, p_fglform);
         if(TextEdit *te = qobject_cast<TextEdit*> (widget))
         {
             if(!te->b_stretch)
             {
                te->setFixedHeight(widget->height()*pageSize);
             }
             else
             {
                 te->setMinimumSize(widget->width(), widget->height()*pageSize);
             }
         }
         else
         {
             widget->setFixedHeight(widget->height()*pageSize);
         }
         //int w = fieldElement.attribute("width").toInt();
         int posX = fieldElement.attribute("posX").toInt();
         int posY = fieldElement.attribute("posY").toInt();
         int gridWidth = fieldElement.attribute("gridWidth").toInt();

         widget->setProperty("fieldId", currentElement.attribute("fieldId").toInt());

         addWidgets(widget, true, posY, posX, gridWidth, pageSize);
         continue;
      }

      if(nodeName == "HLine"){
         int posX = currentElement.attribute("posX").toInt();
         int posY = currentElement.attribute("posY").toInt();
         int gridWidth = currentElement.attribute("gridWidth").toInt();
         bool hidden = currentElement.attribute("hidden").toInt();

         QLabel *label = new QLabel;
         QPalette palette;
         palette.setColor(QPalette::WindowText, Qt::lightGray);

         label->setFrameShape(QFrame::HLine);
         label->setFrameShadow(QFrame::Plain);
         label->setPalette(palette);
         QFontMetrics fm(label->font());
         //label->setFixedWidth((gridWidth*fm.width("W")));
         label->setAccessibleName(nodeName);

         if(hidden)
            label->setHidden(hidden);

         addWidgets(label, false, posY, posX, gridWidth);
      }

      if(nodeName == "Label" || nodeName == "RipLABEL"  || nodeName == "BlankLine"){
         QString text = currentElement.attribute("text");
         int posX = currentElement.attribute("posX").toInt();
         int posY = currentElement.attribute("posY").toInt();
         int gridWidth = currentElement.attribute("gridWidth").toInt();

         if(text == ":")
            continue;

         QLabel *label = new QLabel(text);
         if(nodeName == "BlankLine") {
             label->setObjectName("BlankLine");
         }

         label->setProperty("fieldId", posY);
         label->setProperty("posX", posX);

         //label->setAccessibleName(text);

         addWidgets(label, false, posY, posX, gridWidth);
      }

      if(nodeName == "Table"){
         handleTableColumn(currentElement);
      }

      /*
      if(nodeName == "Matrix"){
         handleMatrixColumn(currentElement);
      }
      */

      if(nodeName == "RecordView"){
         handleRecordView(currentElement);
      }


      parseElement(currentElement);

      if(hidden){
         this->hidden = false;
      }

      if(layoutChanged){
         if(QLayout *layout = qobject_cast<QLayout *> (currentLayout->parent())){
            currentLayout = layout;
            layoutChanged = false;
         }
      }

      if(b_folder){
         if(QTabWidget *tabWidget = qobject_cast<QTabWidget *> (currentWidget->parent()->parent())){
            currentWidget = tabWidget;
            b_folder = false;
         }
         
      }

   }

}

void XmlParser::handleTableColumn(const QDomNode& xmlNode){

   QDomElement tableElement = xmlNode.toElement();
   
   int pageSize = tableElement.attribute("pageSize").toInt();
   QString name = tableElement.attribute("tabName");
   int colCount = tableElement.childNodes().count();
   QString formName = "";
   if(FglForm *fglform = qobject_cast<FglForm*> (p_fglform))
   {
      formName = fglform->formName();
   }

   TableModel *model = new TableModel(pageSize, colCount);

   TableView *p_screenRecord = new TableView(p_fglform);

   p_screenRecord->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
   p_screenRecord->setParent(this->p_fglform);

   p_screenRecord->tabName = name;
   p_screenRecord->setAccessibleName(name);
   p_screenRecord->setObjectName(name);

   p_screenRecord->setEditTriggers(QAbstractItemView::AllEditTriggers);
   QSortFilterProxyModel *proxy = new MyFilter(p_fglform);
   proxy->setSourceModel(model);

   p_screenRecord->setModel(proxy);
   model->setTableView(p_screenRecord);

   connect(p_screenRecord->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)), p_screenRecord, SLOT(fieldChanged(QModelIndex, QModelIndex))); 

   QHeaderView *header = p_screenRecord->horizontalHeader(); 

   int recordHeight = header->height()+4;
   int recordWidth = 0;

   QHeaderView *vert = p_screenRecord->verticalHeader();

   const int rowHeight = fontMetrics().height() + 2;
   int rowHeightXml = VDC::getTableViewRowHeight();

   if(rowHeight < rowHeightXml){
       vert->setDefaultSectionSize(rowHeightXml);
   } else {
       vert->setDefaultSectionSize(rowHeight);
   }

   int height = p_screenRecord->verticalHeader()->defaultSectionSize();


   for(int i=0; i<pageSize; i++){
       recordHeight += height;
   }

   QList<QWidget*> labelList = ql_formFields;
   int lastColumnCount = VDC::readSettingsFromIni(formName, "columnCount").toInt();
   QByteArray state = VDC::readSettingsFromIni1(formName, QString(p_screenRecord->accessibleName() + "/state"));

   if(!state.isEmpty()) {
      if(labelList.count() == lastColumnCount || lastColumnCount == 0) {
         header->restoreState(state);
      } else {
         VDC::removeSettingsFromIni(formName, QString(p_screenRecord->accessibleName() + "/state"));
         for(int i=0; i < ql_formFields.count(); i++) {
             VDC::removeSettingsFromIni(formName, QString(p_screenRecord->accessibleName() + "/" + ql_formFields.at(i)->objectName() + "/hideColumn"));
         }
      }
   }

   VDC::saveSettingsToIni(formName, "columnCount", QString::number(labelList.count()));

   QDomNodeList children = xmlNode.childNodes();
   for(int i=0; i<children.count(); ++i){

      QDomNode child = children.at(i);
      if(!child.isElement()){
         continue;
      }

      QDomElement currentElement = child.toElement();

      QString colText = currentElement.attribute("text");
      QString colName = currentElement.attribute("colName");
      QString name = currentElement.attribute("name");
      int hidden = currentElement.attribute("hidden").toInt();
      bool noshow = currentElement.attribute("noshow").toInt();
      int fieldId = currentElement.attribute("fieldId").toInt();
      p_screenRecord->setColumnName(i,colName);
 
      QString nodeName = currentElement.nodeName();

      int formW = currentElement.firstChild().toElement().attribute("width").toInt();
      QWidget *wi = WidgetHelper::createFormWidget(currentElement);
      TableColumn *tableColumn = (TableColumn*) WidgetHelper::createFormField(currentElement, p_screenRecord);
      ql_fglFields << tableColumn;
      tableColumn->addField(wi);
      int w = wi->width()-5;
      delete wi;
 
      //int fieldCount = ql_formFields.count();
 
      int fieldAt = ql_formFields.count() - children.count();

      for(int k=fieldAt; k<= ql_formFields.size(); k++){
 
 
      if(colText.isEmpty()){
         if(k >= 0 && k <= ql_formFields.size()-1){
            if(Label *wi = qobject_cast<Label *> (ql_formFields.at(k))){
               if(wi->w == formW && p_screenRecord->getColumnLabel(i) == NULL){ 
                  p_screenRecord->setColumnLabel(i, wi);
                  wi->setVisible(false);
               }
            }
         }
      }
      else{
         Label *label = new Label;
         label->setText(colText);
         p_screenRecord->setColumnLabel(i, label);
      }
      }
 
 
      recordWidth += w + 8;
 
      // restore if the column is hidden/shown

      if(p_screenRecord->getColumnLabel(i)!= NULL)
      {
          int hideColumn = VDC::readSettingsFromIni(formName, QString(p_screenRecord->accessibleName() + "/" + p_screenRecord->getColumnLabel(i)->objectName() + "/hideColumn")).toInt();
          if(hideColumn > 0)
          {
             header->hideSection(VDC::readSettingsFromIni(formName, QString(p_screenRecord->accessibleName() + "/" + p_screenRecord->getColumnLabel(i)->objectName() + "/columnId")).toInt());
          }
          // restore the width for each column.
          int columnId = VDC::readSettingsFromIni(formName, QString(p_screenRecord->accessibleName() + "/" + p_screenRecord->getColumnLabel(i)->objectName() + "/columnWidthId")).toInt();
          int columnWidth = VDC::readSettingsFromIni(formName, QString(p_screenRecord->accessibleName() + "/" + p_screenRecord->getColumnLabel(i)->objectName() + "/columnWidth")).toInt();
          if( columnWidth > 0 && columnId > 0)
          {
             header->resizeSection(columnId, columnWidth);
          }
          else
          {
             header->resizeSection(i, w+1);
          }
   }
      else
      {
         header->resizeSection(i, w+1);
      }




      LineEditDelegate *de = new LineEditDelegate(currentElement, p_screenRecord);
      de->setObjectName(name);
      de->setProperty("fieldId", fieldId);
      de->setForm(p_fglform);
      de->setColumn(i);

      ScreenHandler *p_screen = MainFrame::ql_screenhandler->last();

      de->installEventFilter(p_screen);


      p_screenRecord->setItemDelegateForColumn(i,de);

      if(i > 0 && noshow)
      {
          if(p_screenRecord->getColumnLabel(i)->objectName() != NULL)
          {
              int columnIsInvisible = VDC::readSettingsFromIni(formName, QString(p_screenRecord->accessibleName() + "/" + p_screenRecord->getColumnLabel(i)->objectName() + "/hideColumn"), "-1").toInt();

              if(columnIsInvisible == -1){
                  VDC::saveSettingsToIni(formName, QString(p_screenRecord->accessibleName() + "/" + p_screenRecord->getColumnLabel(i)->objectName() + "/hideColumn"), QString::number(1));
                  VDC::saveSettingsToIni(formName, QString(p_screenRecord->accessibleName() + "/" + p_screenRecord->getColumnLabel(i)->objectName() + "/columnId"), QString::number(i));
                  p_screenRecord->hideColumn(i);
              }
          }
      }

      if(hidden)
      {
         p_screenRecord->hideColumn(i);
      }

      ql_formFields << (QWidget*) de;
   }

   //Its enough to save the state at the end of the creation. otherwise on every column it will be saved all states(with 15 coloumns 15 times)
   if(state.isEmpty())
   {
       VDC::saveSettingsToIni(formName, QString(p_screenRecord->accessibleName() + "/oldstate"), header->saveState());
   }

/*
   for(int i=0; i<vert->count(); i++){
      vert->resizeSection(i, VDC::DEFAULT_HEIGHT);
   }
*/


   //p_screenRecord->setFixedSize(recordWidth, recordHeight);
   //p_screenRecord->resize();


   addWidgets(p_screenRecord);
 
}

void XmlParser::handleMatrixColumn(const QDomNode& xmlNode){

   QDomElement matrixElement = xmlNode.toElement();
   
   int pageSize = matrixElement.attribute("pageSize").toInt();
   QString name = matrixElement.attribute("name");
   //int colCount = matrixElement.childNodes().count();

   TableModel *model = new TableModel(pageSize, 1);

   TableView *p_screenRecord = new TableView(p_fglform);
   p_screenRecord->tabName = name;
   p_screenRecord->setAccessibleName(name);
   p_screenRecord->setObjectName(name);

   p_screenRecord->setEditTriggers(QAbstractItemView::AllEditTriggers);
   QSortFilterProxyModel *proxy = new MyFilter(p_fglform);
   proxy->setSourceModel(model);

   p_screenRecord->setModel(proxy);

   connect(p_screenRecord->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)), p_screenRecord, SLOT(fieldChanged(QModelIndex, QModelIndex))); 

   p_screenRecord->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   p_screenRecord->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


   QHeaderView *header = p_screenRecord->horizontalHeader(); 
   header->setStretchLastSection(true);
   header->setVisible(false);

   QHeaderView *vert = p_screenRecord->verticalHeader();
   vert->setVisible(false);

   int recordHeight = 0;
   int recordWidth = 0;

   //int formW = matrixElement.firstChild().toElement().attribute("width").toInt();
   //int gridWidth = matrixElement.firstChild().toElement().attribute("gridWidth").toInt();

   QWidget *wi = WidgetHelper::createFormWidget(matrixElement);
   int w = wi->width();
   int h = wi->height();
   delete wi;
 
   recordWidth += w+6;

   for(int i=0; i<pageSize; i++){
      recordHeight += h+4;
   }

   p_screenRecord->setColumnName(0,matrixElement.attribute("colName"));
 
   LineEditDelegate *de = new LineEditDelegate(matrixElement, p_screenRecord);
   de->setObjectName(matrixElement.attribute("name"));
   de->setProperty("fieldId", matrixElement.attribute("fieldId").toInt());
   de->setForm(p_fglform);
   ql_formFields << (QWidget*) de;
 
   p_screenRecord->setItemDelegate(de);
/*
   for(int i=0; i<header->count(); i++){
      header->resizeSection(i, w+2);
   }

   for(int i=0; i<vert->count(); i++){
      vert->resizeSection(i, h+2);
   }
   p_screenRecord->setFixedWidth(recordWidth);
   p_screenRecord->setFixedHeight(recordHeight);
   //p_screenRecord->setFixedSize(recordWidth, recordHeight);
*/
   int x = matrixElement.firstChild().toElement().attribute("posX").toInt();
   int y = matrixElement.firstChild().toElement().attribute("posY").toInt();

   addWidgets(p_screenRecord, false, y, x);
}

void XmlParser::addWidgets(QWidget *widget, bool add, int x, int y, int gridWidth, int span)
{
MainFrame::vdcdebug("Parser","addWidgets", "QWidget *widget, bool add, int x, int y, int gridWidth, int span");
   if(currentLayout == NULL)
      return;

   if(hidden){
      widget->setHidden(hidden);
   }


   if(add)
   {
      if(Label *la = qobject_cast<Label*> (widget))
      {
          Q_UNUSED(la);
      } else {
          ql_formFieldsConst << widget;
      }

      ql_formFields << widget;
   }


   if(QGridLayout *layout = qobject_cast<QGridLayout *> (currentLayout)){
      layout->setColumnMinimumWidth(y,0);
      layout->setRowMinimumHeight(x,0);

//        if (hasTabs == false) {
//           QLabel *spacerLabel = new QLabel;
//           spacerLabel->setMinimumHeight(50); //NS
//           layout->addWidget(spacerLabel,0,5);
//        }

      //The HLine have no Qt::AlignLeft, because the HLine are not strechting then.
      if(Label *w = qobject_cast<Label *> (widget)){
          if(w->img)
          {
                layout->addWidget(widget, x, y, span, -1, Qt::AlignTop);
                return;
          }
      }
      if(widget->accessibleName() == "HLine")
      {
          layout->addWidget(widget, x, y, span, gridWidth, Qt::AlignTop);
      }
      else
      {
          if(TextEdit *te = qobject_cast<TextEdit*> (widget))
          {
              if(te->qs_stretch == "both")
              {
                  layout->addWidget(widget, x, y);//), Qt::AlignTop);
                  return;
              }
              if(te->qs_stretch == "y")
              {
                  layout->addWidget(widget, x, y, -1, gridWidth);//), Qt::AlignTop);
                  return;
              }
              if(te->qs_stretch == "x")
              {
                  layout->addWidget(widget, x, y, span, -1);//), Qt::AlignTop);
                  return;
              }

          }
          layout->addWidget(widget, x, y, span, gridWidth, Qt::AlignLeft|Qt::AlignTop);
      }
   }

   if(QVBoxLayout *layout = qobject_cast<QVBoxLayout *> (currentLayout)){
      layout->addWidget(widget);
   }

   if(QHBoxLayout *layout = qobject_cast<QHBoxLayout *> (currentLayout)){
      layout->addWidget(widget);
   }

}

void XmlParser::addLayout(QLayout *newLayout)
{
MainFrame::vdcdebug("Parser","addLayout", "QLayout *newLayout");
   if(currentLayout == NULL)
      return;

//   if(QGridLayout *layout = qobject_cast<QGridLayout *> (currentLayout)){
//   }

   if(QVBoxLayout *layout = qobject_cast<QVBoxLayout *> (currentLayout)){
      layout->addLayout(newLayout);
      currentLayout = newLayout;
      return;
   }

   if(QHBoxLayout *layout = qobject_cast<QHBoxLayout *> (currentLayout)){
      layout->addLayout(newLayout);
      currentLayout = newLayout;
      return;
   }

}

void XmlParser::handleRecordView(const QDomNode& xmlNode)
{
MainFrame::vdcdebug("Parser","handleRecordView", "const QDomNode& xmlNode");
   QString tabName = xmlNode.toElement().attribute("tabName");

   FglForm *form = (FglForm*) p_fglform;

   QDomNodeList children = xmlNode.childNodes();
   for(int i=0; i<children.count(); ++i){

      QDomNode child = children.at(i);
      if(!child.isElement()){
         continue;
      }

      QDomElement currentElement = child.toElement();

      QString nodeName = currentElement.nodeName();

      if(nodeName == "Link"){
         Fgl::Link link;
         link.colName = currentElement.attribute("colName");
         link.fieldIdRef = currentElement.attribute("fieldIdRef").toInt();
         form->recordView[tabName] << link;
      }
   }
}

