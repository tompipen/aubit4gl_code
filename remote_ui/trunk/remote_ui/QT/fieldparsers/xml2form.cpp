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
#include <QTextEdit> 
#include <QTableWidget> 
#include <QPushButton> 
#include <QAction> 
#include <QItemDelegate> 
#include <QScrollBar> 
#include <QStandardItemModel> 
#include <QHeaderView> 
#include <QBuffer> 
#include <QtWebKit> 
 
#include "xml2form.h" 
#include <models/table.h>
 
 
//------------------------------------------------------------------------------ 
// Method       : XML2Form() 
// Filename     : xml2form.cpp 
// Description  : constructor for the instances 
//------------------------------------------------------------------------------ 
 
XML2Form::XML2Form() : QWidget() 
{ 
MainFrame::vdcdebug("XML2Form","XML2Form", "");
   i_cnt= 0; 
   tableV = NULL; 
   xmlformLayout = new QGridLayout; 
 
   {  // create dummy label to detect the used colors 
      // 
      QLabel colorDummyLabel; 
      qcol_BaseColor =  
         colorDummyLabel.palette().color(QPalette::Background); 
   } 
 
 
   i_cntFolder   = 0; 
   i_cntPage     = 0; 
 
   b_table = false; 
 
   inp_arr_fields.appendChild(inp_arr_fields.createElement("INPARRFIELDS")); 
  
   p_screenRecord = NULL; 
 
   // init the pageLayouts array for later QTabWidget handling 
   // 
   for(int i=0; i<5; i++){ 
      p_arr_PageLayouts[5] = NULL; 
      p_arr_PageTitle[5]   = NULL; 
   } 
 
   i_cntFields = 0; 
 
   // init the XMLFields array for later field handling 
   // 
   for(int i=0; i<800; i++){ 
      p_arr_XMLFields[i]=NULL; 
   } 
 
   b_tableColumnUsed=false; 
} 
 
 
//------------------------------------------------------------------------------ 
// Method       : ~XML2Form() 
// Filename     : xml2form.cpp 
// Description  : destructor for the instances 
//------------------------------------------------------------------------------ 
 
XML2Form::~XML2Form(){ 
} 
 
 
//------------------------------------------------------------------------------ 
// Method       : outputTree() 
// Filename     : xml2form.cpp 
// Description  : prepares the xml for a form and provide its layout 
//                - makes recursion  
//------------------------------------------------------------------------------ 
 
void XML2Form::outputTree(const QDomNode& domNode, QLayout* parent) 
{ 
MainFrame::vdcdebug("XML2Form","outputTree", "const QDomNode& domNode, QLayout* parent");
   QDomNodeList children = domNode.childNodes(); 
   tableWidget = new TableView(); 
 
   // checking domNodes childNodes for relevant form elements 
   // and handle theire attributes  
   // 
   for(int i=0; i<children.count(); ++i){ 
 
      QDomNode child = children.at(i); 
      if(!child.isElement()){ 
         continue; 
      } 
 
      QDomElement childElement = child.toElement(); 
 
      if(childElement.nodeName() == "Form"){ 
         i_formWidth  = childElement.attribute("width").toInt(); 
         i_formHeight = childElement.attribute("height").toInt(); 
 
      } 
 
      if(childElement.nodeName() == "RecordView"){ 
         recordViews << childElement; 
      } 
 
      if(childElement.nodeName() == "Folder"){ 
         if(!i_cntFolder){ 
            i_cntFolder++; 
         } 
      } 
 
      if(childElement.nodeName() == "Page"){ 
         // getting the tabs title 
         // 
         p_arr_PageTitle[i_cntPage] =  
               new QString(childElement.attribute("text")); 
 
         i_cntPage++; 
      } 
 
      if(childElement.nodeName() == "FormField" || 
         childElement.nodeName() == "Label"     || 
         childElement.nodeName() == "HLine"     || 
         childElement.nodeName() == "Matrix"){ 
 
 
         // form field relevant elements found 
         // so we've to handle them 
         // 
         handleFormField(childElement, parent); 
 
      }else if(childElement.nodeName() == "TableColumn"){ 
         QSortFilterProxyModel *proxyModel; 
         TableModel *tab;  
 
         if(!b_table){ 
            i_screenRecRow = domNode.toElement().attribute("pageSize").toInt(); 
            i_screenRecCol = children.count(); 
            i_formWidth  = childElement.attribute("width").toInt(); 
            i_formHeight = childElement.attribute("height").toInt(); 
 
            handleTableColumn(childElement.parentNode().toElement(), parent); 
 
            b_table = true; 
             
            proxyModel = static_cast<QSortFilterProxyModel*> (p_screenRecord->model());; 
            tab = static_cast<TableModel*> (proxyModel->sourceModel()); 
 
            tab->qs_tabName = childElement.parentNode().toElement().attribute("tabName"); 
            p_screenRecord->tabName = childElement.parentNode().toElement().attribute("tabName"); 
 
            inp_arr_fields.appendChild(inp_arr_fields.createElement("INPARRFIELDS")); 
         } 
         proxyModel = static_cast<QSortFilterProxyModel*> (p_screenRecord->model());; 
         tab = static_cast<TableModel*> (proxyModel->sourceModel()); 
 
         QString colName; 
         colName.append(childElement.attribute("colName")); 
         if(tab != NULL){ 
            tab->qsl_colNames << colName; 
         } 
 
         QDomElement firstChild = childElement.firstChild().toElement(); 
         if(firstChild.nodeName() == "Edit" || 
            firstChild.nodeName() == "ButtonEdit" || 
            firstChild.nodeName() == "TextEdit" || 
            firstChild.nodeName() == "DateEdit" || 
            firstChild.nodeName() == "ComboBox"){ 
 
           tab->v_colTabNames << childElement.attribute("colName"); 
         } 
 
          
      }else{ 
        
         // checking the layout type we have to deal with: 
         // 
         layout = 0; 
         if(childElement.nodeName() == "VBox"){ 
            int i_vboxWidth; 
            int i_vboxHeight; 
 
            i_vboxWidth  = childElement.attribute("width").toInt(); 
            i_vboxHeight = childElement.attribute("height").toInt(); 
 
            layout = new QVBoxLayout; 
            layout->setAlignment(Qt::AlignLeft | Qt::AlignTop); 
 
 
         }else{  
 
            if(childElement.nodeName() == "Grid" || 
               childElement.nodeName() == "Screen"){ 
               int i_gridWidth; 
               int i_gridHeight; 
 
               i_gridWidth  = childElement.attribute("width").toInt(); 
               i_gridHeight = childElement.attribute("height").toInt(); 
 
               if(i_cntFolder){ 
                  p_arr_PageLayouts[i_cntPage] = new QGridLayout; 
                  layout = p_arr_PageLayouts[i_cntPage]; 
 
               }else{ 
                  layout = new QGridLayout; 
               } 
 
               if(childElement.attribute("hidden").toInt()){ 
                  layout->setEnabled(false); 
               } 
 
               QSize sizeGrid(i_gridWidth, i_gridHeight); 
            } 
         } 
 
         // if a new layout node was found we make a recursive call  
         // with that layout otherwise we make the recursive call 
         // with the old layout wich is represented by the parent pointer 
         // 
         if(layout){ 
            if(parent->inherits("QBoxLayout")) { 
               QBoxLayout* boxLayout = (QBoxLayout*)parent; 
 
               if(!childElement.attribute("hidden").toInt()){ 
                  boxLayout->addLayout(layout); 
               } 
 
            }else{  
 
               if(parent->inherits("QGridLayout")){ 
               } 
            } 
 
            outputTree(childElement, layout); // call with the new layout 
 
         }else{ 
 
            outputTree(childElement, parent); // call with the old layout 
         } 
      } 
       
   } // end for 
} 
 
 
void XML2Form::parseForm(QDomDocument formFile) 
{ 
MainFrame::vdcdebug("XML2Form","parseForm", "QDomDocument formFile");
   this->formLayout = new QVBoxLayout; 
 
   outputTree(formFile, formLayout); 
   this->setLayout(this->formLayout); 
} 
 
//------------------------------------------------------------------------------ 
// Method       : handleFormField() 
// Filename     : xml2form.cpp 
// Description  : proceeds the forms field handling 
//------------------------------------------------------------------------------ 
 
bool XML2Form::handleFormField(const QDomElement& childElement, QLayout* parent) 
{ 
MainFrame::vdcdebug("XML2Form","handleFormField", "const QDomElement& childElement, QLayout* parent");
 
   QDomElement formFieldType = childElement.firstChild().toElement(); 
   //QWidget* childWidget = 0; 
   int i_widthFactor = 20; 
   childWidget       = NULL; 
   grandChildWidget  = NULL; 
    
   if(childElement.nodeName() == "HLine" ){ 
      label = new Label; 
      label->setAccessibleName("HLine"); 
 
      label->setFrameShape(QFrame::HLine); 
      label->setFrameShadow(QFrame::Sunken); 
      int w = childElement.attribute("gridWidth").toInt(); 
      label->w = w;
       
      // if attribute is hidden - we hide this widget on the layout 
      // 
      if(childElement.attribute("hidden").toInt()) 
      { 
         label->setHidden(true); 
      } 
 
      childWidget = label; 
 
      i_cntFields++; 
   } 
 
   if(formFieldType.nodeName() == "Label" ){ 
 
      QFont buttTxtFont; 
      buttTxtFont.setPixelSize(12); 
      label = new Label; 
      label->sqlTabName = childElement.attribute("sqlTabName"); 
      label->colName    = childElement.attribute("colName"); 
      label->name       = childElement.attribute("name"); 
      label->setProperty("fieldId", childElement.attribute("fieldId"));

      label->setAccessibleName(label->name);
 
      label->setFont(buttTxtFont); 
      QString labelName = childElement.attribute("text"); 
      if(labelName.isNull()){ 
         labelName = childElement.attribute("colName"); 
      } 
      label->setAccessibleName(labelName); 
 
      int w = formFieldType.attribute("width").toInt(); 
      label->w = w;
 
      // faking the labels identifier, till we can read it from 
      // the protocol 
      // 
      labelName.trimmed(); 
 
      label->setText(labelName); 
      label->setMaximumWidth(w*i_widthFactor); 
       
      QPalette p = label->palette(); 
 
      p.setColor(QPalette::Foreground, Qt::blue); 
      label->setPalette(p); 
 
      // if attribute is hidden - we hide this widget on the layout 
      // 
      if(childElement.attribute("hidden").toInt()){ 
         label->setHidden(true); 
      } 
 
      childWidget = label; 
 
      ql_formFields << label; 
 
      i_cntFields++; 
 
   }else if(formFieldType.nodeName() == "Edit"){ 
 
      Edit *lineEdit = new Edit; 
      lineEdit->setProperty("style", formFieldType.attribute("style"));
      lineEdit->setProperty("fieldId", childElement.attribute("fieldId"));
      lineEdit->setAccessibleName(childElement.attribute("name")); 
      lineEdit->sqlTabName = childElement.attribute("sqlTabName"); 
      lineEdit->colName    = childElement.attribute("colName"); 
      lineEdit->name       = childElement.attribute("name"); 
 
//    int isScrollable = formFieldType.attribute("scroll").toInt(); 
      int w            = formFieldType.attribute("width").toInt(); 
      int i_noEntry    = childElement.attribute("noEntry").toInt(); 
 
      QString qs_sqlType =  childElement.attribute("sqlType"); 
      lineEdit->setSqlType(qs_sqlType);
      int i_inputLength = getLengthBySqlType(qs_sqlType); 
 
      lineEdit->setFixedWidth((i_inputLength+10)*5); 
 
      if(i_noEntry){ 
         lineEdit->setReadOnly(true); 
      }else{ 
         lineEdit->setReadOnly(false); 
      } 
 
      // create a regular expression depending on the  
      // datatype of the field wich is represented by the 
      // elements attribute "sqlType".  
      // 
      if(childElement.attribute("sqlType")=="INTEGER" || 
          childElement.attribute("sqlType")=="SMALLINT") 
      { 
         QString valiRange;      
         QString exprStr;      
         QString range; 
         range.setNum(w); 
 
         exprStr = "^[0-9]{1,"; 
         exprStr.append(range); 
         exprStr.append("}$"); 
 
         QRegExp regExp(exprStr); 
         QRegExpValidator *validator = new QRegExpValidator(regExp, lineEdit); 
         lineEdit->setValidator(validator); 
 
      }else{ 
     
 
         QString valiRange;      
         QString exprStr;      
         QString range; 
         range.setNum(w); 
 
         exprStr = ".{1,"; 
         exprStr.append(range); 
         exprStr.append("}$"); 
         exprStr.append(range); 
 
         QRegExp regExp(exprStr); 
         QRegExpValidator *validator = new QRegExpValidator(regExp, lineEdit); 
          
         if(i_inputLength==0){ 
            lineEdit->setMaxLength(w); 
         }else{ 
            lineEdit->setMaxLength(i_inputLength); 
         } 
         
         if(formFieldType.attribute("shift")=="up"){ 
    
            myValidatorToUpper *validator =  
                                new myValidatorToUpper(regExp, lineEdit); 
 
            lineEdit->setMaxLength(w); 
            lineEdit->setValidator(validator); 
         }else if(formFieldType.attribute("shift")=="down"){ 
   
            myValidatorToLower *validator =  
                                new myValidatorToLower(regExp, lineEdit); 
 
            lineEdit->setMaxLength(w); 
            lineEdit->setValidator(validator); 
 
         }else{ 
  
            QRegExpValidator *validator =  
                              new QRegExpValidator(regExp, lineEdit); 
 
            lineEdit->setValidator(validator); 
         } 
      } 
 
      lineEdit->clear(); 
      lineEdit->setEnabled(false); 
 
      // if attribute is hidden - we hide this widget on the layout 
      // 
      if(childElement.attribute("hidden").toInt()){ 
         lineEdit->setHidden(true); 
      } 
 
      childWidget = lineEdit; 
 
      ql_formFields << lineEdit; 
      i_cntFields++; 
 
   }else if(formFieldType.nodeName() == "Image"){ 
        
      QPixmap *image = new QPixmap("pics/ventas.png"); 
      QLabel *imageLabel = new QLabel; 
      imageLabel->setFocusPolicy(Qt::NoFocus);
 
      int x = formFieldType.attribute("posX").toInt(); 
      int y = formFieldType.attribute("posY").toInt(); 
      int w = formFieldType.attribute("width").toInt(); 
 
      imageLabel->setPixmap(*image); 
 
      // if attribute is hidden - we hide this widget on the layout 
      // 
      if(childElement.attribute("hidden").toInt()){ 
         imageLabel->setHidden(true); 
      } 
 
      childWidget = imageLabel; 
 
      QGridLayout* gridLayout = (QGridLayout*)parent; 
      gridLayout->addWidget(childWidget, y, x); 
 
      childWidget = NULL; 
 
      ql_formFields << imageLabel; 
      i_cntFields++; 
 
   }else if(formFieldType.nodeName() == "Browser"){ 
      WebView *view = new WebView;
      view->colName    = childElement.attribute("colName"); 
      view->name       = childElement.attribute("name"); 
      childWidget = view;
      ql_formFields << view; 
      i_cntFields++; 
   }else if(formFieldType.nodeName() == "ButtonEdit"){ 
 
      QString iconFileName = formFieldType.attribute("image");
      QString buttonKey = formFieldType.attribute("action"); 
 
      ButtonEdit *lineEdit = new ButtonEdit(iconFileName); 
      lineEdit->setProperty("style", formFieldType.attribute("style"));
      lineEdit->setProperty("fieldId", childElement.attribute("fieldId"));
      lineEdit->sqlTabName = childElement.attribute("sqlTabName"); 
      lineEdit->colName    = childElement.attribute("colName"); 
      lineEdit->name       = childElement.attribute("name"); 
 
      lineEdit->setButtonKey(buttonKey);
      lineEdit->setAccessibleName(childElement.attribute("name")); 
      QList<QPushButton *> list = lineEdit->findChildren<QPushButton *>(); 
      if(!list.isEmpty()){
         QPushButton *editButton = list.first(); 
         editButton->setFixedWidth(i_widthFactor); 
         editButton->setFixedHeight(i_widthFactor); 
      }
 
      // width for buttonEdit has to be reduced by 6 
      // because the button size is already included 
      // 
      int w = formFieldType.attribute("width").toInt()-2; 
      QString qs_sqlType =  childElement.attribute("sqlType"); 
      lineEdit->setSqlType(qs_sqlType);
      int i_inputLength = getLengthBySqlType(qs_sqlType); 
      lineEdit->setFixedWidth((i_inputLength+10)*5); 
 
      // create a regular expression depending on the  
      // datatype of the field wich is represented by the 
      // elements attribute "sqlType".  
      // 
      if(childElement.attribute("sqlType")=="INTEGER" || 
         childElement.attribute("sqlType")=="SMALLINT") 
      { 
         QString valiRange;      
         QString exprStr;      
         QString range; 
         range.setNum(w); 
 
         exprStr = "^[0-9]{1,"; 
         exprStr.append(range); 
         exprStr.append("}$"); 
 
         QRegExp regExp(exprStr); 
         QRegExpValidator *validator = new QRegExpValidator(regExp, lineEdit); 
         lineEdit->setValidator(validator); 
         lineEdit->setValidator(validator); 
 
      }else{ 
 
         QString valiRange;      
         QString exprStr;      
         QString range; 
         range.setNum(w); 
 
         exprStr = "^[A-Za-z0-9]{1,"; 
         exprStr.append(range); 
         exprStr.append("}$"); 
 
         QRegExp regExp(exprStr); 
 
         if(i_inputLength==0){ 
            lineEdit->setMaxLength(w); 
         }else{ 
            lineEdit->setMaxLength(i_inputLength); 
         } 
 
 
         if(formFieldType.attribute("shift")=="up"){ 
            myValidatorToUpper *validator = new myValidatorToUpper(regExp, lineEdit); 
            lineEdit->setValidator(validator); 
         }else if(formFieldType.attribute("shift")=="down"){ 
            myValidatorToLower *validator = new myValidatorToLower(regExp, lineEdit); 
            lineEdit->setValidator(validator); 
         }else{ 
            QRegExpValidator *validator = new QRegExpValidator(regExp, lineEdit); 
            lineEdit->setValidator(validator); 
         } 
      } 
 
      lineEdit->clear(); 
      lineEdit->setCursorPosition(1); 
 
      // if attribute is hidden - we hide these widgets on the layout 
      // 
      if(childElement.attribute("hidden").toInt()){ 
         lineEdit->setHidden(true); 
      } 
 
      lineEdit->setEnabled(false); 
 
      childWidget = lineEdit; 
 
      ql_formFields << lineEdit; 
 
      i_cntFields++; 
 
   }else if(formFieldType.nodeName() == "RipBMP"){ 
      // we don't need them, but somethimes these nodes  
      // apears in the xmlform 
      //p_currForm->i_cntXMLFields++; 
      //i_cntFields++; 

   }else if(formFieldType.nodeName() == "RipCHECK"){ 
      CheckBox *checkBox = new CheckBox;
      QString config = formFieldType.attribute("config");
      int width = formFieldType.attribute("width").toInt();
      bool autoNext = formFieldType.attribute("autoNext").toInt();

      childWidget = checkBox;
      ql_formFields << checkBox; 
 
   }else if(formFieldType.nodeName() == "ComboBox"){ 
 
   }else if(formFieldType.nodeName() == "ComboBox"){ 
 
      QComboBox *comboBox = new QComboBox; 
 
      int w = formFieldType.attribute("width").toInt(); 
 
      comboBox->setMaximumWidth(w*i_widthFactor); 
      comboBox->setEditable(false); 
 
      // if attribute is hidden - we hide this widget on the layout 
      // 
      if(childElement.attribute("hidden").toInt()){ 
         comboBox->setHidden(true); 
      } 
      childWidget = comboBox; 
 
      i_cntFields++; 
                          
   }else if(formFieldType.nodeName() == "DateEdit"){ 
 
      DateEdit *dateEdit =  new DateEdit(); 
      dateEdit->setProperty("fieldId", childElement.attribute("fieldId"));
      dateEdit->setProperty("style", formFieldType.attribute("style"));
      dateEdit->sqlTabName = childElement.attribute("sqlTabName"); 
      dateEdit->colName    = childElement.attribute("colName"); 
      dateEdit->name       = childElement.attribute("name"); 
 
      dateEdit->setAccessibleName(childElement.attribute("name")); 
      QDate date; 
 
      QString qs_sqlType =  childElement.attribute("sqlType"); 
      dateEdit->setSqlType(qs_sqlType);
 
      int w = formFieldType.attribute("width").toInt(); 
      int i_noEntry  = childElement.attribute("noEntry").toInt(); 
 
      if(i_noEntry){ 
         dateEdit->setReadOnly(true); 
      }else{ 
         dateEdit->setReadOnly(false); 
      } 
 
      date = QDate::currentDate(); 
 
      QString valiRange;      
      QString exprStr;      
 
      exprStr = "[0-9.]*"; 
      exprStr.append("$"); 
      QRegExp regExp(exprStr); 
      QRegExpValidator *validator = new QRegExpValidator(regExp, dateEdit); 
      dateEdit->setFixedWidth(5*i_widthFactor); 
 
      // if attribute is hidden - we hide this widget on the layout 
      // 
      if(childElement.attribute("hidden").toInt()){ 
         dateEdit->setHidden(true); 
      } 
 
      QList<QPushButton *> list = dateEdit->findChildren<QPushButton *>(); 
      QPushButton *editButton = list.first(); 
 
      dateEdit->setEnabled(false); 
 
      childWidget = dateEdit; 
 
      ql_formFields << dateEdit; 
      i_cntFields++; 
 
   }else if(formFieldType.nodeName() == "TextEdit"){ 
 
      TextEdit *textEdit = new TextEdit; 
      textEdit->setProperty("style", formFieldType.attribute("style"));
      textEdit->setProperty("fieldId", childElement.attribute("fieldId"));
 
      int i_wantReturns = formFieldType.attribute("wantReturns").toInt(); 
      int i_wantTabs    = formFieldType.attribute("wantTabs").toInt(); 
      int w             = formFieldType.attribute("width").toInt(); 
      int h             = formFieldType.attribute("height").toInt(); 
 
      textEdit->name = childElement.attribute("name"); 
      textEdit->colName = childElement.attribute("colName"); 
 
      // tabulators can be used in the textedit to format text 
      // 
      if(i_wantTabs) 
         textEdit->setTabChangesFocus(false); 
      else 
         textEdit->setTabChangesFocus(true); 
 
      // if attribute is hidden - we hide this widget on the layout 
      // 
      if(childElement.attribute("hidden").toInt()){ 
         textEdit->setHidden(true); 
      } 
 
      childWidget = textEdit; 
 
      ql_formFields << textEdit; 
      i_cntFields++; 
 
 
      // exception for textedits in matrix - when more then 1 textEditLine we  
      // have to alter the field counter.   #jobnr: 18042 
      if(childElement.nodeName()=="Matrix") 
      { 
         LineEdit *le = new LineEdit; 
 
         QString qs_sqlType =  childElement.attribute("sqlType"); 
         le->setSqlType(qs_sqlType);
         le->setAccessibleName(childElement.attribute("name")); 
         QSize widgetSize; 
         widgetSize = le->sizeHint(); 
         childWidget->setFixedHeight(widgetSize.height() * 
         childElement.attribute("pageSize").toInt()); 
      }else{ 
 
         //when textedit is inside a formfield the the height holds 
         //the number of lines. 
         for(int i=0; i<formFieldType.attribute("height").toInt(); i++){ 
            //p_currForm->i_cntXMLFields++; 
            i_cntFields++; 
         } 
 
         LineEdit *le = new LineEdit; 
         le->setAccessibleName(childElement.attribute("name")); 
 
         QSize widgetSize; 
         widgetSize = le->sizeHint(); 
         childWidget->setFixedHeight(widgetSize.height() * 
         formFieldType.attribute("height").toInt()); 
      } 
 
   }else if(formFieldType.nodeName() == "ProgressBar"){ 
 
      QProgressBar *progressBar = new QProgressBar; 
      int min = formFieldType.attribute("valueMin").toInt(); 
      int max = formFieldType.attribute("valueMax").toInt(); 
 
      progressBar->setRange(min,max); 
      progressBar->setValue(max/3); 
 
      // if attribute is hidden - we hide this widget on the layout 
      // 
      if(childElement.attribute("hidden").toInt()){ 
         progressBar->setHidden(true); 
      } 
 
      childWidget = progressBar; 
   } 
 
   // if widget is valid prepare to add it to the layout 
   // 
   if(childWidget) 
   { 
      int i_noEntry  = childElement.attribute("noEntry").toInt(); 
      int x          = formFieldType.attribute("posX").toInt(); 
      int y          = formFieldType.attribute("posY").toInt(); 
      int w          = formFieldType.attribute("width").toInt(); 
 
      if(i_noEntry){ 
         childWidget->setFocusPolicy(Qt::NoFocus); 
      } 
 
      // get the current color palette object for this 
      // widget 
      // 
      QPalette p = childWidget->palette(); 
      
      // switch the palettes base color to that value 
      // wich was detected in the consturctor of this object 
      // 
      p.setColor(QPalette::Disabled, QPalette::Base, qcol_BaseColor); 
 
      // now set the switched palette to the widget 
      // 
      childWidget->setPalette(p); 
 
      // now adding the widget to the relevant layout 
      // 
      if(parent->inherits("QBoxLayout")){ 
         QBoxLayout* boxLayout = (QBoxLayout*)parent; 
         boxLayout->addWidget(childWidget); 
 
      }else if(parent->inherits("QGridLayout")){ 
 
         // exception for HLine seperators. 
         // position data is stored in the childElement because 
         // because HLine comes without a formFieldType node. 
         // so we simple overwrite  the x, y and w value 
         // 
         if(childElement.nodeName() == "HLine" ){ 
            x = childElement.attribute("posX").toInt(); 
            y = childElement.attribute("posY").toInt(); 
            w = childElement.attribute("gridWidth").toInt(); 
         } 
         QString qs_sqlType =  childElement.attribute("sqlType"); 
         int i_inputLength = getLengthBySqlType(qs_sqlType); 
 
         if(i_inputLength==0) 
            i_inputLength=w; 
 
         QGridLayout* gridLayout = (QGridLayout*)parent; 
 
         gridLayout->addWidget(childWidget, y, x, 1, w); 
          
         gridLayout->setSpacing(1); 
         gridLayout->setColumnMinimumWidth(x,1); 
         if(grandChildWidget){ 
 
            gridLayout->addWidget(grandChildWidget, y, x+w, 1, 1); 
 
            grandChildWidget=NULL; 
         } 
      } 
   } 
 
   // exception for hard coded form labels 
   // 
   if(childElement.nodeName() == "Label"){ 
 
      int x = childElement.attribute("posX").toInt(); 
      int y = childElement.attribute("posY").toInt(); 
      int w = childElement.attribute("gridWidth").toInt(); 
 
      label = new Label; 
      label->w = w;
      QString labelName = childElement.attribute("text"); 
      label->setAccessibleName(labelName); 
 
      QPalette p = label->palette(); 
      p.setColor(QPalette::Foreground, Qt::blue); 
      label->setPalette(p); 
 
      label->setText(labelName); 
      label->setMaximumWidth(w*i_widthFactor); 
 
      // dont show hardcoded labels when it is a colon ':' #jobnr: 18038 
      // 
      if(labelName==":"){ 
         label->setHidden(true); 
      } 
 
      i_cntFields++; 
 
      if(parent->inherits("QBoxLayout")){ 
 
         QBoxLayout* boxLayout = (QBoxLayout*)parent; 
         boxLayout->addWidget(label); 
 
      }else if(parent->inherits("QGridLayout")){ 
 
         QGridLayout* gridLayout = (QGridLayout*)parent; 
         gridLayout->addWidget(label, y, x, 1, w); 
 
         gridLayout->setColumnMinimumWidth(x,w); 
         gridLayout->setColumnStretch(x,0); 
      } 
   } 
   return true; 
} 
 
 
//------------------------------------------------------------------------------ 
// Method       : handleTableColumn() 
// Filename     : xml2form.cpp 
// Description  : proceeds the table columns handling - display array 
//------------------------------------------------------------------------------ 
 
bool XML2Form::handleTableColumn(const QDomElement& childElement, QLayout* parent) 
{ 
MainFrame::vdcdebug("XML2Form","handleTableColumn", "const QDomElement& childElement, QLayout* parent");
   QString firstNodeName = childElement.nodeName(); 
 
   if(firstNodeName == "Table"){ 
      TableModel *model = new TableModel(i_screenRecRow, 
                                         i_screenRecCol, 0); 
 
      QSortFilterProxyModel *proxy = new MyFilter(); 
      proxy->setSourceModel(model); 
 
      p_screenRecord = new TableView(); 
      p_screenRecord->pageSize = i_screenRecRow;
      ql_formFields << p_screenRecord; 
      p_screenRecord->tabName = childElement.attribute("tabName"); 
      p_screenRecord->setShowGrid(true); 
      p_screenRecord->setModel(proxy); 
      //p_screenRecord->setItemDelegate(p_delegate); 
      p_screenRecord->verticalHeader()->hide(); 
      p_screenRecord->setAlternatingRowColors(true); 
      p_screenRecord->setShowGrid(true); 
      //p_screenRecord->setMinimumSize(500,500); 

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
   } 
 
   QSize screenRecordSize(0, 0);

   QDomNodeList children = childElement.childNodes(); 
   for(int i=0; i<children.count(); ++i){ 
 
      QDomNode child = children.at(i); 
      if(!child.isElement()){ 
         continue; 
      } 
 
      QDomElement currentElement = child.toElement().firstChildElement(); 
 
      QString nodeName = currentElement.nodeName(); 
 
      int w = currentElement.attribute("width").toInt()*10; 

      screenRecordSize.rwidth() += w;

      QHeaderView *header = p_screenRecord->horizontalHeader(); 
      header->resizeSection(i, w); 
      w = header->sectionSize(i); 
 
      if(nodeName == "Edit"){
         LineEditDelegate *delegate = new LineEditDelegate(currentElement.parentNode().toElement()); 
         p_screenRecord->setItemDelegateForColumn(i, delegate); 

         int fieldCount = ql_formFields.count();
         int colCount = children.count();

         int fieldAt = fieldCount - 1 - colCount;
         if(fieldAt >= 0 && ql_formFields.at(fieldAt)->inherits("Label")){
            Label *wi = (Label*) ql_formFields.at(fieldAt);
            if(wi->w == (w/10) ||
               wi->w == (w/10)-1 ||
               wi->w-1 == (w/10)){
               p_screenRecord->setColumnLabel(i, wi);
               wi->setVisible(false);
            }
         }
         ql_formFields << delegate; 
      }

      if(nodeName == "ButtonEdit"){ 
         LineEditDelegate *delegate = new LineEditDelegate(currentElement.parentNode().toElement()); 
         p_screenRecord->setItemDelegateForColumn(i, delegate); 

         int fieldCount = ql_formFields.count();
         int colCount = children.count();

         int fieldAt = fieldCount - 1 - colCount;
         if(fieldAt >= 0 && ql_formFields.at(fieldAt)->inherits("Label")){
            Label *wi = (Label*) ql_formFields.at(fieldAt);
            if(wi->w == (w/10) ||
               wi->w == (w/10)-1 ||
               wi->w-1 == (w/10)){
               p_screenRecord->setColumnLabel(i, wi);
               wi->setVisible(false);
            }
         }
         ql_formFields << delegate; 
      }

      if(nodeName == "DateEdit"){ 
         LineEditDelegate *delegate = new LineEditDelegate(currentElement.parentNode().toElement()); 
         p_screenRecord->setItemDelegateForColumn(i, delegate); 

         int fieldCount = ql_formFields.count();
         int colCount = children.count();

         int fieldAt = fieldCount - 1 - colCount;
         if(fieldAt >= 0 && ql_formFields.at(fieldAt)->inherits("Label")){
            Label *wi = (Label*) ql_formFields.at(fieldAt);
            if(wi->w == (w/10) ||
               wi->w == (w/10)-1 ||
               wi->w-1 == (w/10)){
               p_screenRecord->setColumnLabel(i, wi);
               wi->setVisible(false);
            }
         }
         ql_formFields << delegate; 
      } 
 
      if(nodeName == "TextEdit"){ 
         TextEdit *textEdit = WidgetHelper::createTextEdit(currentElement); 
      } 
       
   } 

   p_screenRecord->setMinimumSize(screenRecordSize);

   if(firstNodeName == "Table" && p_screenRecord != NULL){ 
      if(parent->inherits("QBoxLayout")) 
      { 
         QBoxLayout* boxLayout = (QBoxLayout*)parent; 
         boxLayout->addWidget(p_screenRecord); 
         boxLayout->setAlignment(Qt::AlignTop); 
 
      }else if(parent->inherits("QGridLayout")){ 
 
         int x = childElement.parentNode().toElement().attribute("posX").toInt(); 
         int y = childElement.parentNode().toElement().attribute("posY").toInt(); 
         int w = childElement.parentNode().toElement().attribute("gridWidth").toInt(); 
 
         QGridLayout* gridLayout = (QGridLayout*)parent; 
         gridLayout->addWidget(p_screenRecord, y, x, 1, w); 
    
         gridLayout->setColumnMinimumWidth(x,w); 
         gridLayout->setColumnStretch(x,0); 
      } 
   } 
   return true; 
 
} 
 
//------------------------------------------------------------------------------ 
// Method       : handleTableColumn() 
// Filename     : xml2form.cpp 
// Description  : proceeds the table columns handling - display array 
//------------------------------------------------------------------------------ 
 
bool XML2Form::handleTableColumn2(const QDomElement& childElement, QLayout* parent) 
{ 
MainFrame::vdcdebug("XML2Form","handleTableColumn2", "const QDomElement& childElement, QLayout* parent");
   QDomElement formTableType = childElement.firstChild().toElement(); 
   childWidget    = NULL; 
 
   //-------------------------------- Arrays -------------------------------- // 
 
 
   for(int i=0; i<childElement.parentNode().childNodes().count(); i++){ 
      i_cntFields++; 
   } 
   if(formTableType.nodeName() == "Edit" ){ 
 
      b_tableColumnUsed=true; 
      childWidget = tableWidget; 
   } 
 
   TableModel *model = new TableModel(i_screenRecRow, 
                            i_screenRecCol,  
                            0); 
 
 
  	QSortFilterProxyModel *proxy = new MyFilter(); 
	  proxy->setSourceModel(model); 
 
   QString qs_sqlType =  childElement.attribute("sqlType"); 
   QString icon = "pics/"; 
   icon.append(formTableType.attribute("image")); 
   int i_inputLength = getLengthBySqlType(qs_sqlType); 
 
   p_screenRecord = new TableView(); 
   p_screenRecord->tabName = childElement.attribute("tabName"); 
   p_screenRecord->setShowGrid(true); 
   p_screenRecord->setModel(proxy); 
   p_screenRecord->setItemDelegate(p_delegate); 
   p_screenRecord->verticalHeader()->hide(); 
 
   QHeaderView *header = p_screenRecord->horizontalHeader(); 
   header->setContextMenuPolicy(Qt::ActionsContextMenu); 
	header->setMovable(true); 
 
 	header->setStretchLastSection(true); 
   // when one column is clicked by the user  
   // the entire row hast to be highlighted 
   // 
	p_screenRecord->setSelectionBehavior(QAbstractItemView::SelectRows); 
    
   // allow to click the header sections 
   // 
   header->setClickable(true); 
 
   // display the sort indicator in the relevant header section 
   // 
   header->setSortIndicatorShown(true);  
 
   // set the sort indicators directions 
   // 
   header->setSortIndicator(0, Qt::AscendingOrder); //sortieren 
 
   // column should only use the space it really needs 
   // 
   p_screenRecord->resizeColumnsToContents(); //fdinfo: jobnr:18049 
 
  	QObject::connect(header, SIGNAL(sectionClicked(int)), 
						  p_screenRecord, SLOT(sortByColumn(int))); 
 
  	QObject::disconnect(header, SIGNAL(sectionPressed(int)), 
							  p_screenRecord, SLOT(selectColumn(int))); 
 
   p_screenRecord->setAlternatingRowColors(true); 
   p_screenRecord->setShowGrid(true); 
   p_screenRecord->setSelectionBehavior(QAbstractItemView::SelectRows); 
   p_screenRecord->setSelectionMode(QAbstractItemView::SingleSelection); 
 
   childWidget = p_screenRecord; 
   childWidget->setMinimumSize(500,500); 
   ql_formFields << p_screenRecord; 
 
   if(childWidget){ 
 
      if(parent->inherits("QBoxLayout")) 
      { 
         QBoxLayout* boxLayout = (QBoxLayout*)parent; 
         boxLayout->addWidget(childWidget); 
         boxLayout->setAlignment(Qt::AlignTop); 
 
      }else if(parent->inherits("QGridLayout")){ 
 
         int x = formTableType.attribute("posX").toInt(); 
         int y = formTableType.attribute("posY").toInt(); 
         int w = formTableType.attribute("gridWidth").toInt(); 
 
         QGridLayout* gridLayout = (QGridLayout*)parent; 
         gridLayout->addWidget(childWidget, y, x, 1, w); 
    
         gridLayout->setColumnMinimumWidth(x,w); 
         gridLayout->setColumnStretch(x,0); 
      } 
   } 
   return true; 
} 
 
//------------------------------------------------------------------------------ 
// Method       : getLengthBySqlType() 
// Filename     : xml2form.cpp 
// Description  : detect length for input  
//------------------------------------------------------------------------------ 
 
int XML2Form::getLengthBySqlType(const QString& sqlType) 
{ 
MainFrame::vdcdebug("XML2Form","getLengthBySqlType", "const QString& sqlType");
   // jobnr: 18037  
   // reading the type size from the xml file 
   // it's an element attribute of this form e.g.: 
   //    sqlType="CHAR(25)" 
   if(sqlType.contains("CHAR")){ 
      int start = sqlType.indexOf("("); 
      int end   = sqlType.indexOf(")"); 
 
      QString result = ""; 
      for(int i=start+1;i<end;i++){ 
         result.append(sqlType.at(i)); 
      } 
 
      return result.toInt(); 
   } 
 
   return 0; 
 
} 
 
 
//------------------------------------------------------------------------------ 
// Method       : PageTab() 
// Filename     : xml2form.cpp 
// Description  : constructor for the TabWidgetItem 
//------------------------------------------------------------------------------ 
 
PageTab::PageTab() : QWidget() 
{ 
MainFrame::vdcdebug("PageTab","PageTab", "");
   QGridLayout *tabLayout = new QGridLayout; 
//   tabLayout->setSpacing(1); 
 
   QLabel *test = new QLabel; 
 
   test->setText("test"); 
   tabLayout->addWidget(test); 
   setLayout(tabLayout); 
} 
 
 
QValidator::State myValidatorToUpper::validate(QString &input, int &pos) 
const 
{ 
   // the input has to be upshift in any case 
   // 
   input = input.toUpper(); 
   return QValidator::Acceptable;
} 
 
 
QValidator::State myValidatorToLower::validate(QString &input, int &pos) 
const 
{ 
   // the input has to be downshift in any case 
   // 
   input = input.toLower(); 
   return QValidator::Acceptable;
} 
