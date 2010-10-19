//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : vwidgets.cpp
// Description  : contains class definition for all customized widgets
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
#include <QStyle>
#include <QDir>
#include <QFile>
#include <QAction>
#include <QDebug>
#include <QFocusEvent>
#include <QRegExp>
#include <QRegExpValidator>
#include <QDomElement>

#include "vwidgets.h"
#include "table.h"
#include "actions.h"

int defHeight = 21;

FormField::FormField(QObject *parent) : QObject(parent)
{
   b_noEntry =  false;
   b_notNull = false;
   b_required = false;
   b_touched = false;

   i_fieldId = -1;
   i_tabIndex = -1;
   p_field = NULL;
   
}


QString FormField::name()
{
   return qs_name;
}

void FormField::setName(QString name)
{
   qs_name = name;
}

QString FormField::colName()
{
   return qs_colName;
}

void FormField::setColName(QString colName)
{
   qs_colName = colName;
}

QString FormField::sqlTabName()
{
   return qs_sqlTabName;
}

void FormField::setSqlTabName(QString tabName)
{
   qs_sqlTabName = tabName;
}

QString FormField::sqlType()
{
   return qs_sqlType;
}

void FormField::setSqlType(QString sqlType)
{
   qs_sqlType = sqlType;
}

bool FormField::noEntry()
{
   return b_noEntry;
}

void FormField::setNoEntry(bool noEntry)
{
   b_noEntry = noEntry;
}

bool FormField::notNull()
{
   return b_notNull;
}

void FormField::setNotNull(bool notNull)
{
   b_notNull = notNull;
}

bool FormField::hidden()
{
   return b_hidden;
}

void FormField::setHidden(bool hidden)
{
   b_hidden = hidden;
}

bool FormField::required()
{
   return b_required;
}

void FormField::setRequired(bool req)
{
   b_required = req;
}

int FormField::fieldId()
{
   return i_fieldId;
}

void FormField::setFieldId(int id)
{
   i_fieldId = id;
}

int FormField::tabIndex()
{
   return i_tabIndex;
}

void FormField::setTabIndex(int ti)
{
   i_tabIndex = ti;
}

bool FormField::touched()
{
   return b_touched;
}

/*
QString FormField::text(int row)
{
   return QString();
}

void FormField::setText(QString text, int row)
{
  
}
*/

QString FormField::defaultValue()
{
   return qs_defaultValue;
}

void FormField::setDefaultValue(QString val)
{
   qs_defaultValue = val;
}

void FormField::addField(QWidget *widget)
{
//   widget->setParent(this);
    p_field = widget;
}

QDomDocument FormField::toXML()
{
   QDomDocument doc("");

   QString cName = QString(this->metaObject()->className());
   QDomElement formFieldElement = doc.createElement(cName);
   formFieldElement.setAttribute("name", name());
   formFieldElement.setAttribute("colName", colName());
   formFieldElement.setAttribute("fieldId", fieldId());
   formFieldElement.setAttribute("sqlTabName", sqlTabName());
   formFieldElement.setAttribute("sqlTabName", sqlTabName());
   formFieldElement.setAttribute("sqlType", sqlType());
   formFieldElement.setAttribute("tabIndex", tabIndex());

   if(p_field != NULL){
//      formFieldElement.appendChild(p_field->toXML());
   }

   doc.appendChild(formFieldElement);

   return doc;
}

TableColumn::TableColumn(QObject *parent) : FormField(parent)
{
   b_noEntry =  false;
   b_notNull = false;
   b_required = false;
   b_touched = false;

   i_fieldId = -1;
   i_tabIndex = -1;
   p_field = NULL;

}

void TableColumn::setText(QString text, int row)
{
   Q_UNUSED(text);
   Q_UNUSED(row);
}

//------------------------------------------------------------------------------
// Method       : Button()
// Filename     : xml2form.cpp
// Description  :
//------------------------------------------------------------------------------
Button::Button(QWidget *parent)
    : QPushButton(parent)
{
   // Set enabled as long as Protocol says to enable it
   this->setEnabled(false);

   setProperty("touched", false);
   if(parent == NULL){
      connect(this, SIGNAL(clicked()), this, SLOT(buttonClicked()));
   }

}

void Button::buttonClicked()
{
   Fgl::Event event;
   //event.type = Fgl::ONKEY_EVENT;
   event.type = Fgl::ONACTION_EVENT;
   event.attribute = this->action;
   emit fieldEvent(event);
}

//------------------------------------------------------------------------------
// Method       : Edit()
// Filename     : xml2form.cpp
// Description  : ButtonEdit is a QLineEdit with a QPushButton inside
//------------------------------------------------------------------------------
LineEdit::LineEdit(QWidget *parent)
    : QLineEdit(parent)
{
   setProperty("touched", false);
   this->setFixedHeight(defHeight);
   setContextMenuPolicy(Qt::CustomContextMenu);

   QFont textFont;
   textFont.setPixelSize(12);
   QFontMetrics fm(textFont);

   b_denyFocus = false;
   b_noEntry = false;
   b_autoNext = false;
   b_required = false;
   b_compress = false;
   w = 0;
   valid = NULL;

   // Set enabled as long as Protocol says to enable it
   this->setEnabled(false);

   connect(this, SIGNAL(textChanged(const QString)), this, SLOT(isTouched()));
   connect(this, SIGNAL(editingFinished()), this, SLOT(check()));
//   connect(this, SIGNAL(textChanged(const QString)), this, SLOT(checkNext(const QString)));
}

void LineEdit::check()
{

   QString text = this->text();

   //Set textformat if format given
   if(Fgl::isValidForType(dt_dataType, text, qs_format)){
      text = Fgl::usingFunc(qs_format, text, dt_dataType);
      this->setText(text);
   }
   else{
      emit error("ERROR in Character conversion");
      this->setText("");
   }
}

void LineEdit::setNoEntry(bool ro)
{
   if(ro){
      this->setFocusPolicy(Qt::NoFocus);
   }
   else{
      this->setFocusPolicy(Qt::StrongFocus);
   }

   this->setReadOnly(ro); 
   this->b_noEntry = ro; 
}

void LineEdit::setSqlType(QString sqlType)
{ 
   Fgl::DataType dataType = Fgl::decodeDataType(sqlType);


   dt_dataType = dataType;

   switch(dt_dataType){
       case Fgl::DTYPE_SMINT:
       case Fgl::DTYPE_INT:
       case Fgl::DTYPE_SMFLOAT:
       case Fgl::DTYPE_FLOAT:
       case Fgl::DTYPE_DECIMAL:
          this->setAlignment(Qt::AlignRight);
          if(ButtonEdit *edit = qobject_cast<ButtonEdit *> (this))
          {
              int left = 0;
              int right = 0;
              int top = 0;
              int bottom = 0;
              edit->getTextMargins(&left,&top,&right,&bottom);
              right = edit->getButtonObj()->width();
              edit->setTextMargins(left,top,right,bottom);
          }
          break;

       default:
          this->setAlignment(Qt::AlignJustify|Qt::AlignLeft);
   }
   this->qs_sqlType = sqlType;
   WidgetHelper::setValidator(this);
   valid = this->validator();
} 

void LineEdit::checkNext(const QString &textr){
   QString test = this->text();
   if((textr.length() >= this->maxLength()) && 
      this->hasFocus() && 
      (textr != test))
      emit nextField();
}

//------------------------------------------------------------------------------
// Method       : Edit()
// Filename     : xml2form.cpp
// Description  : ButtonEdit is a QLineEdit with a QPushButton inside
//------------------------------------------------------------------------------
Edit::Edit(QWidget *parent)
    : LineEdit(parent)
{
   // Set enabled as long as Protocol says to enable it
   this->setEnabled(false);

}

//------------------------------------------------------------------------------
// Method       : ButtonEdit()
// Filename     : xml2form.cpp
// Description  : ButtonEdit is a QLineEdit with a QPushButton inside
//------------------------------------------------------------------------------
ButtonEdit::ButtonEdit(QString iconFileName, QWidget *parent)
    : LineEdit(parent)
{
   
   // Set enabled as long as Protocol says to enable it
   this->setEnabled(false);

   this->iconFileName = iconFileName;
   if(this->iconFileName != NULL){
      button = new QPushButton(this);
      connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  //    button->setFocusPolicy(Qt::NoFocus);
      button->setFocusProxy(this);
      QPixmap pixmap("pics:" + iconFileName);
      button->setIcon(QIcon(pixmap));
      QSize siz(18,18);
      button->setFixedSize(siz);
      button->setCursor(Qt::ArrowCursor);
      int frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
      setStyleSheet(QString("QLineEdit { padding-right: %0px; } ").arg(button->size().width() + frameWidth-1 ));
   }
}

void ButtonEdit::setButtonKey(QString bk)
{
  qs_buttonKey = bk;
  /*
  Action *keyButton = new Action(bk, bk, this);
  keyButton->setAcceleratorName(bk);
  QKeySequence shortcut(bk);
  connect(keyButton, SIGNAL(triggered()), this, SLOT(buttonClicked()));
  this->addAction(keyButton);
  */
}

QPushButton* ButtonEdit::getButtonObj()
{
    return this->button;
}

void ButtonEdit::resizeEvent(QResizeEvent *)
{
    if(this->iconFileName == NULL){
      return;
    }

    button->setFixedHeight(this->height()-4);
    QSize sz = button->size();
    button->move(rect().right() - sz.width(),
                      (rect().bottom() + 1 - sz.height())/2);
}

void ButtonEdit::buttonClicked()
{
    if(buttonKey().isEmpty())
      return;

   // For F-Key Events
   Fgl::Event event;
   event.type = Fgl::ONACTION_EVENT;
   event.attribute = Fgl::stringToKey(buttonKey());
   emit fieldEvent(event);
}

//------------------------------------------------------------------------------
// Method       : DateEdit()
// Filename     : xml2form.cpp
// Description  : DateEdit is a QLineEdit with a QPushButton inside
//                and opens a PopupCalendar when clicked
//------------------------------------------------------------------------------
DateEdit::DateEdit(QWidget *parent)
    : LineEdit(parent)
{
   // Set enabled as long as Protocol says to enable it
   this->setEnabled(false);

   this->iconFileName = "calendar";
   button = new QPushButton(this);
   connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
   button->setFocusPolicy(Qt::NoFocus);
   QPixmap pixmap("pics:" + iconFileName);
   button->setIcon(QIcon(pixmap));
   QSize siz(18,18);
   button->setFixedSize(siz);
   button->setCursor(Qt::ArrowCursor);
   int frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
   setStyleSheet(QString("QLineEdit { padding-right: %0px; } ").arg(button->size().width() + frameWidth-1 ));
}

void DateEdit::resizeEvent(QResizeEvent *)
{
    QSize sz = button->size();
    button->move(rect().right() - sz.width(),
                      (rect().bottom() + 1 - sz.height())/2);
}

void DateEdit::buttonClicked()
{
    PopupCalendar *calendar = new PopupCalendar(QDate::fromString(this->text(), Fgl::dbDateToFormat(Fgl::env["DBDATE"])),
                                 this->mapToGlobal(QPoint(0, this->height()-3))
                                 ,0,this);
   calendar->show();
}

//------------------------------------------------------------------------------
// Method       : TextEdit()
// Filename     : xml2form.cpp
// Description  : 
//------------------------------------------------------------------------------
TextEdit::TextEdit(QWidget *parent)
    : QTextEdit(parent)
{
   setProperty("touched", false);
   b_noEntry = false;
   b_autoNext = false;
   b_required = false;
   b_compress = false;

   b_denyFocus = false;
   setWantTabs(false);
   setWantReturns(true);

   setEnabled(false);
}

int TextEdit::getCursorPosition(){
   QTextCursor c = this->textCursor();
   int index= this->getIndex(c);
   return index;
}

int TextEdit::getIndex (const QTextCursor &crQTextCursor ){
  QTextBlock           b;
  int                  column = 1;
  b = crQTextCursor.block();
  column = crQTextCursor.position() - b.position();
  return column;
}

void TextEdit::setSqlType(QString sqlType)
{ 
   this->qs_sqlType = sqlType;
   WidgetHelper::setValidator(this);

} 


void TextEdit::setWantTabs(bool wt)
{
  // tabulators can be used in the textedit to format text
  //
  this->setTabChangesFocus(!wt) ;
  b_wantTabs = wt;

}

void TextEdit::setWantReturns(bool wr)
{
  // return can be used in the textedit to format text
  //
  b_wantReturns = wr;

}



void TextEdit::keyPressEvent(QKeyEvent *ev)
{
 //comment out because shift+enter in don't work

 //  if(!wantReturns()){
 //     int key = ev->key();
 //     if(key == Qt::Key_Return || key == Qt::Key_Enter){
 //        ev->ignore();
 //        emit returnPressed();
 //        return;
 //     }
 // }
   
   return QTextEdit::keyPressEvent(ev);
}

void TextEdit::setNoEntry(bool ro)
{ 
   if(ro){
      this->setFocusPolicy(Qt::NoFocus);
   }
   else{
      this->setFocusPolicy(Qt::StrongFocus);
   }

   this->setReadOnly(ro); 
   this->b_noEntry = ro; 
}


int WidgetHelper::getLengthBySqlType(const QString& sqlType)
{
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

QString WidgetHelper::getWidgetName(QObject* widget)
{
   QString widgetName;

   if(Label *label = qobject_cast<Label *> (widget)){
      return label->name;
   }

   if(LineEdit *lineEdit = qobject_cast<LineEdit *> (widget)){
         return lineEdit->name;
   }

   if(TextEdit *textEdit = qobject_cast<TextEdit *> (widget)){
      return textEdit->name;
   }

   return widgetName;

}

QString WidgetHelper::getWidgetColName(QObject* widget)
{
   QString widgetColName;

   if(Label *label = qobject_cast<Label *> (widget)){
      return label->colName;
   }

   if(LineEdit *lineEdit = qobject_cast<LineEdit *> (widget)){
         return lineEdit->colName;
   }

   if(TextEdit *textEdit = qobject_cast<TextEdit *> (widget)){
      return textEdit->colName;
   }

   if(TableView *table = qobject_cast<TableView *> (widget)){
      return table->getColumnName(table->currentIndex().column());
   }

   return widgetColName;
}

QWidget* WidgetHelper::createFormWidget(const QDomElement& formField, QWidget *parent)
{
   QDomElement lineEditElement = formField.firstChild().toElement();


   if(lineEditElement.nodeName() == "Label" || lineEditElement.nodeName() == "RipLabel"){
      return createLabel(formField, parent);
   }

   if(lineEditElement.nodeName() == "Edit"){
      return createEdit(formField, parent);
   }

   if(lineEditElement.nodeName() == "ButtonEdit"){
      return createButtonEdit(formField, parent);
   }

   if(lineEditElement.nodeName() == "DateEdit"){
      return createDateEdit(formField, parent);
   }

   if(lineEditElement.nodeName() == "TextEdit"){
      return createTextEdit(formField, parent);
   }

   
   if(lineEditElement.nodeName() == "Image"){
      Label *label = createImage(formField, parent);
      label->setEnabled(true);
      return label;
   }

   if(lineEditElement.nodeName() == "Button"){
      Button *button = createButton(formField, parent);
      return button;
   }

   if(lineEditElement.nodeName() == "Browser"){
      WebView *browser = createWebView(formField, parent);
      return browser;
   }

   if(lineEditElement.nodeName() == "ComboBox"){
      ComboBox *comboBox = createComboBox(formField, parent);
      return comboBox;
   }

   if(lineEditElement.nodeName() == "CheckBox"){
      CheckBox *checkBox = createCheckBox(formField, parent);
      return checkBox;
   }

   if(lineEditElement.nodeName() == "ProgressBar"){
      ProgressBar *progressBar = createProgressBar(formField, parent);
      return progressBar;
   }

   return new QWidget(parent);
}

FormField* WidgetHelper::createFormField(const QDomElement& formField, QWidget *parent)
{
   Q_UNUSED(parent);

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");

   bool hidden   = formField.attribute("hidden").toInt();
   bool noEntry  = formField.attribute("noEntry").toInt();
   bool notNull  = formField.attribute("notNull").toInt();
   bool required  = formField.attribute("required").toInt();

   int fieldId  = formField.attribute("fieldId").toInt();
   int tabIndex = formField.attribute("tabIndex").toInt();

   QString defaultValue = formField.attribute("defaultValue");

   FormField *fField = new FormField;
   fField->setName(name);
   fField->setColName(colName);
   fField->setSqlTabName(tabName);
   fField->setSqlType(sqlType);
   fField->setHidden(hidden);
   fField->setNoEntry(noEntry);
   fField->setNotNull(notNull);
   fField->setRequired(required);
   fField->setFieldId(fieldId);
   fField->setTabIndex(tabIndex);
   fField->setDefaultValue(defaultValue);

   //QWidget *childWidget = WidgetHelper::createFormWidget(formField.firstChild().toElement(), fField);
   //QWidget *childWidget = WidgetHelper::createFormWidget(formField, fField);
   //fField->addField(childWidget);

   return fField;
}

Label* WidgetHelper::createLabel(const QDomElement& formField, QWidget *parent)
{   
   QDomElement labelElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");

   bool hidden   = formField.attribute("hidden").toInt();

   int w  = labelElement.attribute("width").toInt();

   QString shift  = labelElement.attribute("shift");
   QString action = labelElement.attribute("action");
   QString image  = labelElement.attribute("image");
   image.prepend("pics:");

   Label *label = new Label(parent);
   label->setAccessibleName(name);
   label->setObjectName(colName);
   label->name = name;
   label->colName = colName;
   label->sqlTabName = tabName;
   label->w = w;

   QString comments = labelElement.attribute("comments");
   if(!comments.isEmpty()){
      label->setToolTip(comments);
   }

   if(hidden){
      label->setVisible(false);
   }


  // QPalette p = label->palette();
  // p.setColor(QPalette::Foreground, Qt::blue);
 //  label->setPalette(p);
   label->setFixedHeight(defHeight);

   return label;
}

Label* WidgetHelper::createImage(const QDomElement& formField, QWidget *parent)
{   
   QDomElement labelElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");

   bool hidden   = formField.attribute("hidden").toInt();

   int w  = labelElement.attribute("pixelWidth").toInt();
   int h  = labelElement.attribute("pixelHeight").toInt();

   bool autoScale  = labelElement.attribute("autoScale").toInt();
   QString image  = labelElement.attribute("image");
   image.prepend("pics:");

   Label *label = new Label(parent);
   label->setAccessibleName(name);
   label->setObjectName(colName);
   label->name = name;
   label->colName = colName;
   label->sqlTabName = tabName;
   label->w = w;

   QString comments = labelElement.attribute("comments");
   if(!comments.isEmpty()){
      label->setToolTip(comments);
   }

   if(hidden){
      label->setVisible(false);
   }

   QPixmap pixmap("");
   label->setPixmap(pixmap);


  // QPalette p = label->palette();
  // p.setColor(QPalette::Foreground, Qt::blue);
 //  label->setPalette(p);
   //label->setFixedSize(defHeight);

   return label;
}

WebView* WidgetHelper::createWebView(const QDomElement& formField, QWidget *parent)
{   
   QDomElement browserElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");
   QString defaultValue = formField.attribute("defaultValue");

   bool hidden   = formField.attribute("hidden").toInt();

   int w  = browserElement.attribute("width").toInt();
   int h  = browserElement.attribute("height").toInt();
   int wPixel  = browserElement.attribute("pixelWidth").toInt();
   int hPixel  = browserElement.attribute("pixelHeight").toInt();

   WebView *browser = new WebView(parent);
   browser->setAccessibleName(name);
   browser->setObjectName(colName);
   browser->name = name;
   browser->colName = colName;
   browser->setDefaultValue(defaultValue);


//std::cout "w="<< wPixel << "h=" << hPixel ;

   QString comments = browserElement.attribute("comments");
   if(!comments.isEmpty()){
      browser->setToolTip(comments);
   }
   QString url = browserElement.attribute("url");
   if(!url.isEmpty()){
      browser->load(QUrl(url,QUrl::TolerantMode));
   }

   if(hidden){
      browser->setVisible(false);
   }

   if (wPixel>0) {
   	browser->setFixedWidth(wPixel);
   } else {
   	QFontMetrics fm = browser->fontMetrics();
   	int width = w*fm.width("W")+10;
   	browser->setFixedWidth(width);
   }
   if (hPixel>0) {
	// Specified a pixel height...
   	browser->setFixedHeight(hPixel);
   } else {
	if (h>0) { 
		// Specified a Line height...
   		browser->setFixedHeight(defHeight*h);
	} else {
   		browser->setFixedHeight(defHeight);
	}
   }

   return browser;
}

Button* WidgetHelper::createButton(const QDomElement& formField, QWidget *parent)
{
   QDomElement buttonElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString defaultValue = formField.attribute("defaultValue");

   QString action = buttonElement.attribute("action");

   bool hidden   = formField.attribute("hidden").toInt();

   Button *button = new Button(parent);
   button->action = action;
   button->setAccessibleName(name);
   button->setObjectName(colName);
   button->name = name;
   button->colName = colName;
   button->setDefaultValue(defaultValue);

   QString comments = buttonElement.attribute("comments");
   if(!comments.isEmpty()){
      button->setToolTip(comments);
   }

   if(hidden){
      button->setVisible(false);
   }

   int w = buttonElement.attribute("width").toInt();

   QFontMetrics fm = button->fontMetrics();
   int width = w*fm.width("W");
   if(w == 1){
      width += 10;
   }
   button->setFixedWidth(width);

   return button;
}

Edit* WidgetHelper::createEdit(const QDomElement& formField, QWidget *parent)
{   
   QDomElement lineEditElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");
   bool hidden   = formField.attribute("hidden").toInt();
   QString defaultValue = formField.attribute("defaultValue");

   int w  = lineEditElement.attribute("width").toInt();

   QString shift  = lineEditElement.attribute("shift");
   QString action = lineEditElement.attribute("action");
   QString image  = lineEditElement.attribute("image");
   image.prepend("pics:");

   bool autoNext = lineEditElement.attribute("autoNext").toInt();
   bool noEntry  = formField.attribute("noEntry").toInt();

   Edit *lineEdit = new Edit(parent);
   lineEdit->setAccessibleName(name);
   lineEdit->setObjectName(colName);
   lineEdit->name = name;
   lineEdit->colName = colName;
   lineEdit->sqlTabName = tabName;
   lineEdit->w = w;
   lineEdit->setShift(shift);
   lineEdit->setNoEntry(noEntry);
   lineEdit->setAutoNext(autoNext);
   lineEdit->setSqlType(sqlType);
   lineEdit->setDefaultValue(defaultValue);

   QString comments = lineEditElement.attribute("comments");
   if(!comments.isEmpty()){
      lineEdit->setToolTip(comments);
   }

   QString picture = lineEditElement.attribute("picture");
   lineEdit->setPicture(picture);

   QString format = lineEditElement.attribute("format");
   lineEdit->setFormat(format);

   QFontMetrics fm = lineEdit->fontMetrics();
   int width = w*fm.width("W")+10;
   lineEdit->setFixedWidth(width);
   lineEdit->setFixedHeight(defHeight);

   if(hidden)
      lineEdit->setVisible(false);

   return lineEdit;
}

ButtonEdit* WidgetHelper::createButtonEdit(const QDomElement& formField,QWidget *parent)
{   
   QDomElement lineEditElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");
   bool hidden   = formField.attribute("hidden").toInt();
   QString defaultValue = formField.attribute("defaultValue");

   int w  = lineEditElement.attribute("width").toInt();

   QString shift  = lineEditElement.attribute("shift");
   QString action = lineEditElement.attribute("action");
   QString image  = lineEditElement.attribute("image");

   bool autoNext = lineEditElement.attribute("autoNext").toInt();
   bool noEntry  = lineEditElement.attribute("noEntry").toInt();

   ButtonEdit *lineEdit = new ButtonEdit(image, parent);
   lineEdit->setAccessibleName(name);
   lineEdit->setObjectName(colName);
   lineEdit->name = name;
   lineEdit->colName = colName;
   lineEdit->sqlTabName = tabName;
   lineEdit->w = w;
   lineEdit->setButtonKey(action);
   lineEdit->setShift(shift);
   lineEdit->setNoEntry(noEntry);
   lineEdit->setAutoNext(autoNext);
   lineEdit->setSqlType(sqlType);
   lineEdit->setDefaultValue(defaultValue);

   QString comments = lineEditElement.attribute("comments");
   if(!comments.isEmpty()){
      lineEdit->setToolTip(comments);
   }

   QString picture = lineEditElement.attribute("picture");
   lineEdit->setPicture(picture);

   QFontMetrics fm = lineEdit->fontMetrics();
   int width = w*fm.width("W")+10;
   lineEdit->setFixedWidth(width);
   lineEdit->setFixedHeight(defHeight);

   if(hidden)
      lineEdit->setVisible(false);

   return lineEdit;
}

bool WidgetHelper::setDisplayAttributes(int fieldAttribute, QWidget *widget)
   {
         int col_int = (fieldAttribute & 0xf00);
         if(fieldAttribute == -1)
            fieldAttribute = 0;

         if(Label *la = qobject_cast<Label *> (widget))
         {
            Q_UNUSED(la);
            QLabel dummy;
            dummy.setEnabled(widget->isEnabled());
            QColor dummycol = dummy.palette().color(QPalette::Foreground);
            QPalette p = widget->palette();
            QColor col(dummycol.red(), dummycol.green(), dummycol.blue());
            p.setColor(QPalette::Foreground, col);
            widget->setPalette(p);
            widget->setFont(dummy.font());
         }
         else if(LineEditDelegate *led = qobject_cast<LineEditDelegate *> (widget))
         {
             Q_UNUSED(led);
         }
         else
         {
            QLineEdit dummy;
            dummy.setEnabled(widget->isEnabled());
            QColor dummycol = dummy.palette().color(QPalette::Text);
            QPalette p = widget->palette();
            QColor col(dummycol.red()-10, dummycol.green()-10, dummycol.blue()-10);
            p.setColor(QPalette::Text, col);
            widget->setPalette(p);
            widget->setFont(dummy.font());
         }


         switch(col_int) {
            case Fgl::AUBIT_COLOR_BLACK:
                {
                   QPalette p = widget->palette();
                   QColor col("black");
                   if(Label *la = qobject_cast<Label *> (widget))
                   {
                      Q_UNUSED(la);
                      p.setColor(QPalette::Foreground, col);
                   }
                   else
                   {
                       p.setColor(QPalette::Text, col);
                   }
                   widget->setPalette(p);
                }
             break;
             case Fgl::AUBIT_COLOR_RED:
                {
                   QPalette p = widget->palette();
                   QColor col("red");
                   if(Label *la = qobject_cast<Label *> (widget))
                   {
                       Q_UNUSED(la);
                       p.setColor(QPalette::Foreground, col);
                   }
                   else
                   {
                       p.setColor(QPalette::Text, col);
                   }
                   widget->setPalette(p);
                }
                break;
                case Fgl::AUBIT_COLOR_GREEN:
                {
                   QPalette p = widget->palette();
                   QColor col("green");
                   if(Label *la = qobject_cast<Label *> (widget))
                   {
                      Q_UNUSED(la);
                      p.setColor(QPalette::Foreground, col);
                   }
                   else
                   {
                       p.setColor(QPalette::Text, col);
                   }
                   widget->setPalette(p);
                }
                break;
                case Fgl::AUBIT_COLOR_YELLOW:
                {
                   QPalette p = widget->palette();
                   QColor col("yellow");
                   if(Label *la = qobject_cast<Label *> (widget))
                   {
                      Q_UNUSED(la);
                      p.setColor(QPalette::Foreground, col);
                   }
                   else
                   {
                       p.setColor(QPalette::Text, col);
                   }
                   widget->setPalette(p);
                }
                break;
                case Fgl::AUBIT_COLOR_BLUE:
                {
                   QPalette p = widget->palette();
                   QColor col("blue");
                   if(Label *la = qobject_cast<Label *> (widget))
                   {
                      Q_UNUSED(la);
                      p.setColor(QPalette::Foreground, col);
                   }
                   else
                   {
                       p.setColor(QPalette::Text, col);
                   }
                    widget->setPalette(p);
                }
                break;
                case Fgl::AUBIT_COLOR_MAGENTA:
                {
                   QPalette p = widget->palette();
                   QColor col("magenta");
                   if(Label *la = qobject_cast<Label *> (widget))
                   {
                      Q_UNUSED(la);
                      p.setColor(QPalette::Foreground, col);
                   }
                   else
                   {
                       p.setColor(QPalette::Text, col);
                   }
                   widget->setPalette(p);
                }
                break;
                case Fgl::AUBIT_COLOR_CYAN:
                {
                   QPalette p = widget->palette();
                   QColor col("cyan");
                   if(Label *la = qobject_cast<Label *> (widget))
                   {
                      Q_UNUSED(la);
                      p.setColor(QPalette::Foreground, col);
                   }
                   else
                   {
                       p.setColor(QPalette::Text, col);
                   }
                   widget->setPalette(p);
                }
                break;
                case Fgl::AUBIT_COLOR_WHITE:
                {
                   QPalette p = widget->palette();
                   QColor col("white");
                   if(Label *la = qobject_cast<Label *> (widget))
                   {
                      Q_UNUSED(la);
                      p.setColor(QPalette::Foreground, col);
                   }
                   else
                   {
                       p.setColor(QPalette::Text, col);
                   }
                   widget->setPalette(p);
                }
                break;
        };

        if (fieldAttribute & Fgl::AUBIT_ATTR_REVERSE)
        {
        }
        if (fieldAttribute & Fgl::AUBIT_ATTR_UNDERLINE)
           {
              QFont font = widget->font();
              font.setUnderline(true);
              widget->setFont(font);
           }

         if (fieldAttribute & Fgl::AUBIT_ATTR_BOLD)
            {
               QFont font = widget->font();
               font.setBold(true);
               widget->setFont(font);
            }

         if (fieldAttribute & Fgl::AUBIT_ATTR_BLINK)
            {
            }

         if (fieldAttribute & Fgl::AUBIT_ATTR_DIM)
            {
               QFont font = widget->font();
               font.setBold(true);
               widget->setFont(font);
            }

         if (fieldAttribute & Fgl::AUBIT_ATTR_INVISIBLE)
   //widget->setEchoMode(QLineEdit::Password);

         if (fieldAttribute & Fgl::AUBIT_ATTR_ALTCHARSET)
            {
            }
         if (fieldAttribute & Fgl::AUBIT_ATTR_LEFT)
             {
             }

     return true;
   }


DateEdit* WidgetHelper::createDateEdit(const QDomElement& formField,QWidget *parent)
{
   QDomElement lineEditElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");
   bool hidden   = formField.attribute("hidden").toInt();
   QString defaultValue = formField.attribute("defaultValue");

   int w  = lineEditElement.attribute("width").toInt();

   QString shift  = lineEditElement.attribute("shift");
   QString action = lineEditElement.attribute("action");

   bool autoNext = lineEditElement.attribute("autoNext").toInt();
   bool noEntry  = lineEditElement.attribute("noEntry").toInt();

   DateEdit *lineEdit = new DateEdit(parent);
   lineEdit->setAccessibleName(name);
   lineEdit->setObjectName(colName);
   lineEdit->name = name;
   lineEdit->colName = colName;
   lineEdit->sqlTabName = tabName;
   lineEdit->w = w;
   lineEdit->setShift(shift);
   lineEdit->setNoEntry(noEntry);
   lineEdit->setAutoNext(autoNext);
   lineEdit->setSqlType(sqlType);
   lineEdit->setDefaultValue(defaultValue);

   QString comments = lineEditElement.attribute("comments");
   if(!comments.isEmpty()){
      lineEdit->setToolTip(comments);
   }

   QString picture = lineEditElement.attribute("picture");
   lineEdit->setPicture(picture);

   QFontMetrics fm = lineEdit->fontMetrics();
   int width = w*fm.width("W")+10;
   lineEdit->setFixedWidth(width);
   lineEdit->setFixedHeight(defHeight);

   if(hidden)
      lineEdit->setVisible(false);

   return lineEdit;
}

TextEdit* WidgetHelper::createTextEdit(const QDomElement& formField, QWidget *parent)
{   
   QDomElement textEditElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");
   bool hidden   = formField.attribute("hidden").toInt();
   QString defaultValue = formField.attribute("defaultValue");

  // bool required = formField.attribute("required").toInt();
  // bool notNull = formField.attribute("notNull").toInt();

   int w  = textEditElement.attribute("width").toInt();

   QString color = textEditElement.attribute("color").toLower();
   QString colorCondition = textEditElement.attribute("colorCondition");
   QString comment = textEditElement.attribute("comment");

   QString shift = textEditElement.attribute("shift");
   QString fontPitch = textEditElement.attribute("fontPitch");

   QString include = textEditElement.attribute("include");

   bool noEntry  = textEditElement.attribute("noEntry").toInt();
   bool autoNext = textEditElement.attribute("autoNext").toInt();

   QString scrollBars = textEditElement.attribute("scrollBars");
   QString sizePolicy = textEditElement.attribute("sizePolicy");
   QString style = textEditElement.attribute("style");
   QString stretch = textEditElement.attribute("stretch");

   bool wantTabs = textEditElement.attribute("wantTabs").toInt();
   bool wantReturns = true;
   if(!textEditElement.attribute("wantReturns").isEmpty()){
      wantReturns = textEditElement.attribute("wantReturns").toInt();
   }

   TextEdit *textEdit = new TextEdit(parent);
   textEdit->setAccessibleName(name);
   textEdit->setObjectName(colName);
   textEdit->name = name;
   textEdit->colName = colName;
   textEdit->sqlTabName = tabName;
   textEdit->setWantTabs(wantTabs);
   textEdit->setWantReturns(wantReturns);
   textEdit->setDefaultValue(defaultValue);

   QString comments = textEditElement.attribute("comments");
   if(!comments.isEmpty()){
      textEdit->setToolTip(comments);
   }

   int height = textEditElement.attribute("height").toInt();
   if(height < 1) height = 1;

   if(hidden)
      textEdit->setVisible(false);

   textEdit->setFixedHeight(defHeight*height);
   

   QFontMetrics fm = textEdit->fontMetrics();
   int width = w*fm.width("W")+10;
   textEdit->setFixedWidth(width);

   textEdit->setShift(shift);
   textEdit->setNoEntry(noEntry);
   textEdit->setAutoNext(autoNext);
   textEdit->setSqlType(sqlType);

   Edit *edit = new Edit;
   QPalette pal = edit->palette();

   QColor col = pal.color(QPalette::Disabled, QPalette::Window);

   QPalette p = textEdit->palette();
   p.setColor(QPalette::Disabled,QPalette::Base, col);
   textEdit->setPalette(p);

   return textEdit;

}

ComboBox* WidgetHelper::createComboBox(const QDomElement& formField, QWidget *parent)
{   
   QDomElement comboBoxElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");
   //bool hidden   = formField.attribute("hidden").toInt();
   QString defaultValue = formField.attribute("defaultValue");

   //bool required = formField.attribute("required").toInt();
   //bool notNull = formField.attribute("notNull").toInt();

   int w  = comboBoxElement.attribute("width").toInt();

   QString color = comboBoxElement.attribute("color").toLower();
   QString colorCondition = comboBoxElement.attribute("colorCondition");
   QString comment = comboBoxElement.attribute("comment");

   QString shift = comboBoxElement.attribute("shift");
   QString fontPitch = comboBoxElement.attribute("fontPitch");

   QString include = comboBoxElement.attribute("include");

   //bool noEntry  = comboBoxElement.attribute("noEntry").toInt();
   //bool autoNext = comboBoxElement.attribute("autoNext").toInt();

   QString scrollBars = comboBoxElement.attribute("scrollBars");
   QString sizePolicy = comboBoxElement.attribute("sizePolicy");
   QString style = comboBoxElement.attribute("style");
   QString stretch = comboBoxElement.attribute("stretch");

   ComboBox *comboBox = new ComboBox(parent);
   comboBox->setAccessibleName(name);
   comboBox->setObjectName(colName);
   comboBox->setDefaultValue(defaultValue);

   int height = comboBoxElement.attribute("height").toInt();
   if(height < 1) height = 1;

   comboBox->setFixedHeight(defHeight*height);

   QString comments = comboBoxElement.attribute("comments");
   if(!comments.isEmpty()){
      comboBox->setToolTip(comments);
   }


   for(int i=0; i<comboBoxElement.childNodes().count(); i++){
      QDomElement itemElement = comboBoxElement.childNodes().at(i).toElement();

      if(itemElement.nodeName() == "Item"){
         QString name = itemElement.attribute("name");
         QString text = itemElement.attribute("text");

         comboBox->addItem(name, text);
      }
   }

   QFontMetrics fm = comboBox->fontMetrics();
   int width = w*fm.width("W")+10;
   comboBox->setFixedWidth(width);

   Edit *edit = new Edit;
   QPalette pal = edit->palette();

   QColor col = pal.color(QPalette::Disabled, QPalette::Window);

   QPalette p = comboBox->palette();
   p.setColor(QPalette::Disabled,QPalette::Base, col);
   comboBox->setPalette(p);

   return comboBox;

}

CheckBox* WidgetHelper::createCheckBox(const QDomElement& formField, QWidget *parent)
{   
   QDomElement checkBoxElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");
   //bool hidden   = formField.attribute("hidden").toInt();
   QString defaultValue = formField.attribute("defaultValue");

   //bool required = formField.attribute("required").toInt();
   bool notNull = formField.attribute("notNull").toInt();

   int w  = checkBoxElement.attribute("width").toInt();

   QString color = checkBoxElement.attribute("color").toLower();
   QString colorCondition = checkBoxElement.attribute("colorCondition");
   QString comment = checkBoxElement.attribute("comment");

   QString qs_default = checkBoxElement.attribute("default");
   QString fontPitch = checkBoxElement.attribute("fontPitch");

   QString include = checkBoxElement.attribute("include");

   //bool noEntry  = checkBoxElement.attribute("noEntry").toInt();
   //bool autoNext = checkBoxElement.attribute("autoNext").toInt();

   QString sizePolicy = checkBoxElement.attribute("sizePolicy");
   QString style = checkBoxElement.attribute("style");
   QString valueChecked = checkBoxElement.attribute("valueChecked");
   QString valueUnchecked = checkBoxElement.attribute("valueUnchecked");

   QString text = checkBoxElement.attribute("text");

   CheckBox *checkBox = new CheckBox(text, parent);
   checkBox->setAccessibleName(name);
   checkBox->setObjectName(colName);
   checkBox->setDefaultValue(defaultValue);

   if(!valueChecked.isEmpty()){
      checkBox->setValueChecked(valueChecked);
   }

   if(!valueUnchecked.isEmpty()){
      checkBox->setValueUnchecked(valueUnchecked);
   }

   if(notNull){
      checkBox->setTristate(false);
   }

   int height = checkBoxElement.attribute("height").toInt();
   if(height < 1) height = 1;

   checkBox->setFixedHeight(defHeight*height);

   QString comments = checkBoxElement.attribute("comments");
   if(!comments.isEmpty()){
      checkBox->setToolTip(comments);
   }
   

   QFontMetrics fm = checkBox->fontMetrics();
   int width = w*fm.width("W")+10;
   checkBox->setFixedWidth(width);

   Edit *edit = new Edit;
   QPalette pal = edit->palette();

   QColor col = pal.color(QPalette::Disabled, QPalette::Window);

   QPalette p = checkBox->palette();
   p.setColor(QPalette::Disabled,QPalette::Base, col);
   checkBox->setPalette(p);

   return checkBox;

}

ProgressBar* WidgetHelper::createProgressBar(const QDomElement& formField, QWidget *parent)
{   
   QDomElement progressBarElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");
   //bool hidden   = formField.attribute("hidden").toInt();
   QString defaultValue = formField.attribute("defaultValue");

   //bool required = formField.attribute("required").toInt();
   //bool notNull = formField.attribute("notNull").toInt();

   int w  = progressBarElement.attribute("width").toInt();

   QString color = progressBarElement.attribute("color").toLower();
   QString colorCondition = progressBarElement.attribute("colorCondition");
   QString comment = progressBarElement.attribute("comment");

   QString include = progressBarElement.attribute("include");

   //bool noEntry  = progressBarElement.attribute("noEntry").toInt();
   //bool autoNext = progressBarElement.attribute("autoNext").toInt();

   QString sizePolicy = progressBarElement.attribute("sizePolicy");
   QString style = progressBarElement.attribute("style");
   int valueMin = progressBarElement.attribute("valueMin").toInt();
   int valueMax = progressBarElement.attribute("valueMax").toInt();

   ProgressBar *progressBar = new ProgressBar(parent);
   progressBar->setAccessibleName(name);
   progressBar->setObjectName(colName);

   progressBar->setMinimum(valueMin);
   progressBar->setMaximum(valueMax);

   int height = progressBarElement.attribute("height").toInt();
   if(height < 1) height = 1;

   progressBar->setFixedHeight(defHeight*height);

   QString comments = progressBarElement.attribute("comments");
   if(!comments.isEmpty()){
      progressBar->setToolTip(comments);
   }
   

   QFontMetrics fm = progressBar->fontMetrics();
   int width = w*fm.width("W")+10;
   progressBar->setFixedWidth(width);

   Edit *edit = new Edit;
   QPalette pal = edit->palette();

   QColor col = pal.color(QPalette::Disabled, QPalette::Window);

   QPalette p = progressBar->palette();
   p.setColor(QPalette::Disabled,QPalette::Base, col);
   progressBar->setPalette(p);

   return progressBar;

}

bool WidgetHelper::isFieldWidget(QObject *object)
{

   if(object->inherits("LineEdit") ||
      object->inherits("TextEdit") ||
      object->inherits("Label") ||
      object->inherits("ProgressBar") ||
      object->inherits("WebView")){
      return true;
   }


   return false;

}

bool WidgetHelper::isFieldWidget(QObject *object, QString fieldName)
{

   if(Label *widget = qobject_cast<Label *> (object)){
      if(widget->name == fieldName || widget->colName == fieldName){
         return true;
      }
   }

   if(WebView *widget = qobject_cast<WebView *> (object)){
      if(widget->name == fieldName || widget->colName == fieldName){
         return true;
      }
   }

   if(LineEdit *widget = qobject_cast<LineEdit *> (object)){
      if(widget->name == fieldName || widget->colName == fieldName){
         return true;
      }
   }

   if(TextEdit *widget = qobject_cast<TextEdit *> (object)){
      if(widget->name == fieldName || widget->colName == fieldName){
         return true;
      }
   }

   if(ProgressBar *widget = qobject_cast<ProgressBar *> (object)){
      if(widget->name == fieldName || widget->colName == fieldName){
         return true;
      }
   }

   return false;

}

void WidgetHelper::copy(QObject* object)
{
   if(LineEdit *widget = qobject_cast<LineEdit *> (object)){
      widget->copy();
   }

   if(TextEdit *widget = qobject_cast<TextEdit *> (object)){
      widget->copy();
   }
}

void WidgetHelper::cut(QObject* object)
{
   if(LineEdit *widget = qobject_cast<LineEdit *> (object)){
      widget->cut();
   }

   if(TextEdit *widget = qobject_cast<TextEdit *> (object)){
      widget->cut();
   }
}

void WidgetHelper::paste(QObject* object)
{
   if(LineEdit *widget = qobject_cast<LineEdit *> (object)){
      widget->paste();
   }

   if(TextEdit *widget = qobject_cast<TextEdit *> (object)){
      widget->paste();
   }
}

void WidgetHelper::setFieldText(QObject *object, QString fieldValue)
{

   if(Label *widget = qobject_cast<Label *> (object)){
      fieldValue = Fgl::fgl_convert_money(fieldValue);
      if(widget->pixmap() == 0){
         widget->setText(fieldValue);
      }
      else{
         QPixmap pixmap(fieldValue);
         widget->setPixmap(pixmap);
         widget->setFixedSize(pixmap.size());
      }
      return;
   }

   if(Button *widget = qobject_cast<Button *> (object)){
      widget->setText(fieldValue);
      return;
   }

   if(WebView *widget = qobject_cast<WebView *> (object)){
		
      		widget->load(QUrl(fieldValue,QUrl::TolerantMode));
	
      return;
   }

   if(LineEdit *widget = qobject_cast<LineEdit *> (object)){
      //widget->clear();
      //widget->insert(fieldValue);
      if(!widget->format().isEmpty()){
         fieldValue = Fgl::usingFunc(widget->format(), fieldValue, widget->dataType());
      }
      else{
         fieldValue = Fgl::fgl_convert_money(fieldValue);
      }

      if(fieldValue.trimmed() != widget->text())
         widget->setText(fieldValue.trimmed());
      return;
   }

   if(TextEdit *widget = qobject_cast<TextEdit *> (object)){
      fieldValue = Fgl::fgl_convert_money(fieldValue);
      if(fieldValue.trimmed() != widget->toPlainText())
         widget->setPlainText(fieldValue.trimmed());
      return;
   }

   if(ComboBox *widget = qobject_cast<ComboBox *> (object)){
      widget->addItem(fieldValue);
      return;
   }

   if(ProgressBar *widget = qobject_cast<ProgressBar *> (object)){
      widget->setValue(fieldValue.toInt());
      return;
   }

}

QString WidgetHelper::fieldText(QObject *object)
{

   if(Label *widget = qobject_cast<Label *> (object)){
      return widget->text();
   }

   if(Button *widget = qobject_cast<Button *> (object)){
      return widget->text();
   }

   if(WebView *widget = qobject_cast<WebView *> (object)){
      return widget->url().toString();
   }

   if(LineEdit *widget = qobject_cast<LineEdit *> (object)){
      return widget->text();
   }

   if(TextEdit *widget = qobject_cast<TextEdit *> (object)){
      return widget->toPlainText();
   }

   if(ComboBox *widget = qobject_cast<ComboBox *> (object)){
      return widget->currentText();
   }

   if(CheckBox *widget = qobject_cast<CheckBox *> (object)){
      switch(widget->checkState()){
         case Qt::PartiallyChecked:
            return QString();
            break;
         case Qt::Checked:
            return widget->valueChecked();
            break;
         case Qt::Unchecked:
            return widget->valueUnchecked();
            break;
      }
   }

   if(ProgressBar *widget = qobject_cast<ProgressBar *> (object)){
      return QString::number(widget->value());
   }

   return QString("Widget not found");

}

void WidgetHelper::setDefaultFieldText(QObject *object)
{

   if(Button *widget = qobject_cast<Button *> (object)){
      QString fieldValue = widget->defaultValue();
      widget->setText(fieldValue);
      return;
   }

   if(WebView *widget = qobject_cast<WebView *> (object)){
      QString fieldValue = widget->defaultValue();
		
      widget->load(QUrl(fieldValue,QUrl::TolerantMode));
	
      return;
   }

   if(LineEdit *widget = qobject_cast<LineEdit *> (object)){
      QString fieldValue = widget->defaultValue();
      widget->clear();
      widget->insert(fieldValue);
      return;
   }

   if(TextEdit *widget = qobject_cast<TextEdit *> (object)){
      QString fieldValue = widget->defaultValue();
      widget->setText(fieldValue);
      return;
   }

   if(ComboBox *widget = qobject_cast<ComboBox *> (object)){
      QString fieldValue = widget->defaultValue();
      widget->addItem(fieldValue);
      return;
   }

   if(ProgressBar *widget = qobject_cast<ProgressBar *> (object)){
      QString fieldValue = widget->defaultValue();
      widget->setValue(fieldValue.toInt());
      return;
   }

}

QString WidgetHelper::defaultFieldText(QObject *object)
{

   if(Button *widget = qobject_cast<Button *> (object)){
      return widget->defaultValue();
   }

   if(WebView *widget = qobject_cast<WebView *> (object)){
      return widget->defaultValue();
   }

   if(LineEdit *widget = qobject_cast<LineEdit *> (object)){
      return widget->defaultValue();
   }

   if(TextEdit *widget = qobject_cast<TextEdit *> (object)){
      return widget->defaultValue();
   }

   if(ComboBox *widget = qobject_cast<ComboBox *> (object)){
      return widget->defaultValue();
   }

   if(CheckBox *widget = qobject_cast<CheckBox *> (object)){
      return widget->defaultValue();
   }

   if(ProgressBar *widget = qobject_cast<ProgressBar *> (object)){
      return widget->defaultValue();
   }

   return QString("Widget not found");

}

void WidgetHelper::setValidator(QWidget* widget){

   //QRegExpValidator *validator;
   QString exprString;
   QString sqlType;
   QString shift;
   int w = 0; 

   if(LineEdit *lineEdit = qobject_cast<LineEdit *> (widget)){
      sqlType = lineEdit->sqlType();
      shift = lineEdit->shift();
      w = getLengthBySqlType(sqlType);
      if(w <= 0)
         w = lineEdit->w;
      lineEdit->setMaxLength(w);
   }

   if(TextEdit *textEdit = qobject_cast<TextEdit *> (widget)){
      sqlType = textEdit->sqlType();
      shift = textEdit->shift();
      w = getLengthBySqlType(sqlType);
      if(w <= 0)
         w = textEdit->w;
   }

   if(sqlType == "INTEGER" ||
      sqlType == "SMALLINT" ||
      sqlType == "SERIAL"){
      exprString = QString("^[0-9]+$");
   }

   if(sqlType == "DATE"){
      return;
   }

   QRegExp regExp(exprString);

   if(!shift.isEmpty()){
      if(shift == "up"){
         UppercaseValidator *validator = new UppercaseValidator(regExp, widget);
         if(LineEdit *lineEdit = qobject_cast<LineEdit *> (widget)){
            lineEdit->setValidator(validator);
         }
      }

      if(shift == "down"){
         LowercaseValidator *validator = new LowercaseValidator(regExp, widget);
        if(LineEdit *lineEdit = qobject_cast<LineEdit *> (widget)){
           lineEdit->setValidator(validator);
        }
      }
   }
   else{
      if(exprString.isEmpty())
         return;

      QRegExpValidator *validator = new QRegExpValidator(regExp, widget);
      if(LineEdit *lineEdit = qobject_cast<LineEdit *> (widget)){
         lineEdit->setValidator(validator);
      }

   }
}

Label::Label(const QString &text, QWidget *parent)
    : QLabel(text, parent)
{
   QFont font;
   font.setPixelSize(12);

   this->setFont(font);

   this->setFocusPolicy(Qt::NoFocus);
   w = 0;
}

void WidgetHelper::setFieldAttribute(QObject* object){
   Q_UNUSED(object);

/*
   if(Button *widget = qobject_cast<Button *> (object)){
      return;
   }

   if(WebView *widget = qobject_cast<WebView *> (object)){
      return;
   }

   if(LineEdit *widget = qobject_cast<LineEdit *> (object)){
      return;
   }

   if(TextEdit *widget = qobject_cast<TextEdit *> (object)){
      return;
   }

   if(ComboBox *widget = qobject_cast<ComboBox *> (object)){
      return;
   }

   if(ProgressBar *widget = qobject_cast<ProgressBar *> (object)){
      return;
   }
*/
}

Label::Label(QWidget *parent)
    : QLabel(parent)
{
   QFont font;
   font.setPixelSize(12);

   this->setFont(font);
}

PopupCalendar::PopupCalendar(QDate day, QPoint pos,
                             QWidget *parent, QLineEdit *sender)
    : QDialog(parent, Qt::FramelessWindowHint)
{
    if (!pos.isNull())
        move(pos);

    vboxLayout = new QVBoxLayout;
    Calendar *calendar = new Calendar(0, sender);

    if(day != QDate::currentDate())
    calendar->setSelectedDate(day);

    vboxLayout->addWidget(calendar);
    vboxLayout->setSpacing(0);
    vboxLayout->setMargin(0);
    vboxLayout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(vboxLayout);

    connect(calendar, SIGNAL(activated(const QDate &)), calendar, SLOT(setDay()));
    connect(calendar, SIGNAL(activated(const QDate &)), this, SLOT(close()));
    calendar->installEventFilter(this);

    setFixedSize(calendar->sizeHint());
    resize(calendar->sizeHint());
    calendar->setDay();
}




bool PopupCalendar::eventFilter(QObject *obj, QEvent *ev)
{

   if (ev->type() == QEvent::WindowDeactivate)
   {
       close();
       return true;
   }
   return QWidget::eventFilter(obj, ev);
}

Calendar::Calendar(QWidget *parent, QLineEdit *sender)
   : QCalendarWidget(parent)
{
   this->setFocusPolicy(Qt::NoFocus);
   dateEdit = sender;
   setWindowFlags(Qt::FramelessWindowHint);
   connect(this, SIGNAL(activated(const QDate &)), this, SLOT(setDay()));
   connect(this, SIGNAL(activated(const QDate &)), this, SLOT(close()));
}

void Calendar::setDay(){
  day = this->selectedDate(); 
  dateEdit->setText(day.toString(Fgl::dbDateToFormat(Fgl::env["DBDATE"])));
}

ProgressBar::ProgressBar(QWidget *parent) : QProgressBar(parent)
{
   setProperty("touched", false);
   setTextVisible(false);
}

WebView::WebView(QWidget *parent) : QWebView(parent)
{
   
}

ComboBox::ComboBox(QWidget *parent) : QComboBox(parent)
{
   setProperty("touched", false);
   setEnabled(false);
   setEditable(false);
}

CheckBox::CheckBox(QWidget *parent) : QCheckBox(parent)
{
   setProperty("touched", false);
   setValueChecked(QString::number(1));
   setValueUnchecked(QString::number(0));
   setTristate(true);
   setCheckState(Qt::PartiallyChecked);
}

CheckBox::CheckBox(QString text, QWidget *parent) : QCheckBox(text, parent)
{
   setProperty("touched", false);
   setValueChecked(QString::number(1));
   setValueUnchecked(QString::number(0));
   setTristate(true);
   setCheckState(Qt::PartiallyChecked);
}

TabWidget::TabWidget(QWidget *parent) : QTabWidget(parent)
{
}
