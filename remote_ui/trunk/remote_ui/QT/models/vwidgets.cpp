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
#include <QMovie>
#include <QFocusEvent>
#include <QRegExp>
#include <QRegExpValidator>
#include <QDomElement>
#include <QDragEnterEvent>
#include <QSplitter>
#include <QSettings>

#include "fglform.h"
#include "mainframe.h"
#include "vwidgets.h"
#include "table.h"
#include "actions.h"
#include "tools/umlauts.h"

//int defHeight = 21;

FormField::FormField(QObject *parent) : QObject(parent)
{
MainFrame::vdcdebug("FormField","FormField", "QObject *parent");
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
MainFrame::vdcdebug("FormField","name", "");
   return qs_name;
}

void FormField::setName(QString name)
{
MainFrame::vdcdebug("FormField","setName", "QString name");
   qs_name = name;
}

QString FormField::colName()
{
MainFrame::vdcdebug("FormField","colName", "");
   return qs_colName;
}

void FormField::setColName(QString colName)
{
MainFrame::vdcdebug("FormField","setColName", "QString colName");
   qs_colName = colName;
}

QString FormField::sqlTabName()
{
MainFrame::vdcdebug("FormField","sqlTabName", "");
   return qs_sqlTabName;
}

void FormField::setSqlTabName(QString tabName)
{
MainFrame::vdcdebug("FormField","setSqlTabName", "QString tabName");
   qs_sqlTabName = tabName;
}

QString FormField::sqlType()
{
MainFrame::vdcdebug("FormField","sqlType", "");
   return qs_sqlType;
}

void FormField::setSqlType(QString sqlType)
{
MainFrame::vdcdebug("FormField","setSqlType", "QString sqlType");
   qs_sqlType = sqlType;
}

bool FormField::noEntry()
{
MainFrame::vdcdebug("FormField","noEntry", "");
   return b_noEntry;
}

void FormField::setNoEntry(bool noEntry)
{
MainFrame::vdcdebug("FormField","setNoEntry", "bool noEntry");
   b_noEntry = noEntry;
}

bool FormField::notNull()
{
MainFrame::vdcdebug("FormField","notNull", "");
   return b_notNull;
}

void FormField::setNotNull(bool notNull)
{
MainFrame::vdcdebug("FormField","setNotNull", "bool notNull");
   b_notNull = notNull;
}

bool FormField::hidden()
{
MainFrame::vdcdebug("FormField","hidden", "");
   return b_hidden;
}

void FormField::setHidden(bool hidden)
{
MainFrame::vdcdebug("FormField","setHidden", "bool hidden");
   b_hidden = hidden;
}

bool FormField::required()
{
MainFrame::vdcdebug("FormField","required", "");
   return b_required;
}

void FormField::setRequired(bool req)
{
MainFrame::vdcdebug("FormField","setRequired", "bool req");
   b_required = req;
}

int FormField::fieldId()
{
MainFrame::vdcdebug("FormField","fieldId", "");
   return i_fieldId;
}

void FormField::setFieldId(int id)
{
MainFrame::vdcdebug("FormField","setFieldId", "int id");
   i_fieldId = id;
}

int FormField::tabIndex()
{
MainFrame::vdcdebug("FormField","tabIndex", "");
   return i_tabIndex;
}

void FormField::setTabIndex(int ti)
{
MainFrame::vdcdebug("FormField","setTabIndex", "int ti");
   i_tabIndex = ti;
}

bool FormField::touched()
{
MainFrame::vdcdebug("FormField","touched", "");
   return b_touched;
}

/*
QString FormField::text(int row)
{
MainFrame::vdcdebug("FormField","text", "int row");
   return QString();
}

void FormField::setText(QString text, int row)
{
MainFrame::vdcdebug("FormField","setText", "QString text, int row");
  
}
*/

QString FormField::defaultValue()
{
MainFrame::vdcdebug("FormField","defaultValue", "");
   return qs_defaultValue;
}

void FormField::setDefaultValue(QString val)
{
MainFrame::vdcdebug("FormField","setDefaultValue", "QString val");
   qs_defaultValue = val;
}

void FormField::addField(QWidget *widget)
{
MainFrame::vdcdebug("FormField","addField", "QWidget *widget");
//   widget->setParent(this);
    p_field = widget;
}

QDomDocument FormField::toXML()
{
MainFrame::vdcdebug("FormField","toXML", "");
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
MainFrame::vdcdebug("TableColumn","TableColumn", "QObject *parent");
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
MainFrame::vdcdebug("TableColumn","setText", "QString text, int row");
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
MainFrame::vdcdebug("Button","buttonClicked", "");
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
   //this->setFixedHeight(VDC::DEFAULT_HEIGHT);
   this->setContextMenuPolicy(Qt::CustomContextMenu);

/*   QFont textFont;
   textFont.setPixelSize(12);
   QFontMetrics fm(textFont);
  */ //this->installEventFilter(this);
   b_denyFocus = false;
   b_noEntry = false;
   b_autoNext = false;
   b_required = false;
   b_compress = false;
   b_isHidden = false;
   b_isOnlyHidden = false;

   qs_oldsql  = "";
   //this->setDragEnabled(true);
   w = 0;
   valid = NULL;


   // Set enabled as long as Protocol says to enable it
   //this->setEnabled(false);
   this->setAcceptDrops(true);

   connect(this, SIGNAL(textChanged(const QString)), this, SLOT(isTouched()));
//   connect(this, SIGNAL(editingFinished()), this, SLOT(check()));
//   connect(this, SIGNAL(textChanged(const QString)), this, SLOT(checkNext(const QString)));
}

void LineEdit::check()
{
MainFrame::vdcdebug("LineEdit","check", "");

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
MainFrame::vdcdebug("LineEdit","setNoEntry", "bool ro");
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
MainFrame::vdcdebug("LineEdit","setSqlType", "QString sqlType");
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
              /*int left = 0;
              int right = 0;
              int top = 0;
              int bottom = 0;
              edit->getTextMargins(&left,&top,&right,&bottom);
              right = edit->getButtonObj()->width();
              edit->setTextMargins(left,top,right,bottom);*/
              edit->setAlignment(Qt::AlignRight);
          }
          break;

       default:
          this->setAlignment(Qt::AlignJustify|Qt::AlignLeft);
   }
   this->qs_oldsql  = this->qs_sqlType;
   this->qs_sqlType = sqlType;
   WidgetHelper::setValidator(this);
   valid = this->validator();
} 

void LineEdit::resetDataType()
{
  if(!qs_oldsql.isEmpty())
  {
     setSqlType(qs_oldsql);
     qs_oldsql = "";
  }
}

void LineEdit::checkNext(const QString &textr){
   QString test = this->text();
   if((textr.length() >= this->maxLength()) && 
      this->hasFocus() && 
      (textr != test))
      emit nextField();
}

void LineEdit::dragEnterEvent(QDragEnterEvent *e)
{
   //Accept Events for dropEvent
   e->acceptProposedAction();
}

//void LineEdit::

//DropEvent for Drop files into a ButtonEdit/LineEdit
void LineEdit::dropEvent(QDropEvent *e)
{
    TableView *tv = NULL;
    if(TableView *tv1 = qobject_cast<TableView*> (e->source()))
    {
       tv = tv1;
       if(FglForm *p_fglform = qobject_cast<FglForm*> (tv->p_fglform))
       {
          connect(this, SIGNAL(dropSuccess()), p_fglform, SLOT(dragSuccess()));
       }

    }

    connect(this, SIGNAL(dropSuccess()), parent(), SLOT(dropSuccess()));
    //Handle drop for files and directories (paste path into the field (without file://)
    if(e->mimeData()->hasUrls() || e->mimeData()->hasText() ){
        QString text;
        if (e->mimeData()->hasUrls() )
        {
           QList<QUrl> listUrls = e->mimeData()->urls();
           //some fancy stuff in here for a list of URLs maybe?
           text = QString(listUrls[0].toLocalFile());
        }
        else
        {
           text =  e->mimeData()->text();
        }
        text = text.replace("file://","").trimmed();

        text = VDC::removeUmlauts(text);
        this->setText(text);
        /*Fgl::Event event;
        event.type = Fgl::AFTER_FIELD_EVENT;
        event.attribute = this->objectName();
        if(FglForm *p_fglform = qobject_cast<FglForm*> (parent()))
        {
            p_fglform->raise();
        }
        emit fieldEvent(event);*/
        emit dropSuccess();

    }
}

void LineEdit::markup()
{

  if(this->noEntry()) {
      return;
  }

  this->setCursorPosition(0);
  if(this->text().isEmpty())
  {
     this->home(false);
  }
  else
  {
     this->end(true);
  }
}

void LineEdit::copyText()
{
    if(!this->hasSelectedText()) {
        this->selectAll();
    }
    this->copy();
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
   //this->setDragEnabled(true);

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
    button = NULL;

   this->iconFileName = iconFileName;
    if(this->iconFileName != NULL){
      button = new QPushButton(this);
      //connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
      button->setFocusPolicy(Qt::NoFocus);
      button->setFocusProxy(this);
      QSize siz(27,25);
      button->setFixedSize(siz);
      button->setCursor(Qt::ArrowCursor);

      if(!iconFileName.contains("."))
      {
            iconFileName.append(".png");
      }
      int frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
      setStyleSheet(QString(" ButtonEdit QPushButton {outline: none; border-image: url(:pics/" + iconFileName + ");}"
                                           " QPushButton:focus { border-image: url(:pics/open_weiss.png);}"
                                           " QLineEdit { padding-right: %0px; } ").arg(button->size().width() + frameWidth-1 ));
   }
}

void ButtonEdit::setButtonKey(QString bk)
{
MainFrame::vdcdebug("ButtonEdit","setButtonKey", "QString bk");
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
MainFrame::vdcdebug("ButtonEdit","getButtonObj", "");
    return this->button;
}

void ButtonEdit::resizeEvent(QResizeEvent *)
{
MainFrame::vdcdebug("ButtonEdit","resizeEvent", "QResizeEvent *");
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
MainFrame::vdcdebug("ButtonEdit","buttonClicked", "");
    if(buttonKey().isEmpty())
      return;
   // For F-Key Events
   Fgl::Event event;
   event.type = Fgl::ONACTION_EVENT;
   event.attribute = Fgl::stringToKey(buttonKey());
   event.field = this->colName;
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
  // connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
   button->setFocusPolicy(Qt::NoFocus);
   button->setFocusProxy(this);

   if(!iconFileName.contains("."))
   {
       iconFileName.append(".png");
   }
   //QPixmap pixmap(":pics/" + iconFileName);
   //   It's now a Stylesheet cause on MAC there is a little border around the button
   //   button->setIcon(QIcon(pixmap));

   QSize siz(28,25);
   button->setFixedSize(siz);
   button->setCursor(Qt::ArrowCursor);
   int frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
   setStyleSheet(QString(" DateEdit QPushButton {outline: none;border-image: url(:pics/" + iconFileName + ");}"
                                        " QPushButton:focus { border-image: url(:pics/calendar_weiss.png);}"
                                        " QLineEdit { padding-right: %0px; } ").arg(button->size().width() + frameWidth-1 ));
}

void DateEdit::resizeEvent(QResizeEvent *)
{
MainFrame::vdcdebug("DateEdit","resizeEvent", "QResizeEvent *");
    QSize sz = button->size();
    button->move(rect().right() - sz.width(),
                      (rect().bottom() + 1 - sz.height())/2);
}

void DateEdit::buttonClicked()
{
MainFrame::vdcdebug("DateEdit","buttonClicked", "");
    PopupCalendar *calendar = new PopupCalendar(QDate::fromString(this->text(), Fgl::dbDateToFormat(Fgl::env["DBDATE"])),
                                 this->mapToGlobal(QPoint(0, this->height()-3))
                                 ,0,this);
   calendar->show();
}


QPushButton* DateEdit::getButtonObj()
{
MainFrame::vdcdebug("ButtonEdit","getButtonObj", "");
    return this->button;
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
   b_stretch = false;
   b_denyFocus = false;
   setWantTabs(false);
   setWantReturns(true);
   setContextMenuPolicy(Qt::CustomContextMenu);
  // setAutoFillBackground(true);

   connect(this, SIGNAL(textChanged()), this, SLOT(checkLength()));

   setEnabled(false);
}

void TextEdit::checkLength()
{
    if(this->toPlainText().length() > getLengthBySqlType())
    {
        this->textCursor().deletePreviousChar();
    }
}

int TextEdit::getLengthBySqlType()
{
    QString sqlType = this->qs_sqlType;

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

void TextEdit::setStretching(QString stretch)
{
    this->qs_stretch = stretch;
    if(stretch == "none")
    {
        this->b_stretch = false;
        return;
    }

    this->b_stretch = true;
}

void TextEdit::copyText()
{
    QTextCursor cursor = this->textCursor();
    if(!cursor.hasSelection()) {
        this->selectAll();
    }

    this->copy();
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
MainFrame::vdcdebug("TextEdit","setSqlType", "QString sqlType");
   this->qs_sqlType = sqlType;
   WidgetHelper::setValidator(this);

} 


void TextEdit::setWantTabs(bool wt)
{
MainFrame::vdcdebug("TextEdit","setWantTabs", "bool wt");
  // tabulators can be used in the textedit to format text
  //
  this->setTabChangesFocus(!wt) ;
  b_wantTabs = wt;

}

void TextEdit::setWantReturns(bool wr)
{
MainFrame::vdcdebug("TextEdit","setWantReturns", "bool wr");
  // return can be used in the textedit to format text
  //
  b_wantReturns = wr;

}



void TextEdit::keyPressEvent(QKeyEvent *ev)
{
MainFrame::vdcdebug("TextEdit","keyPressEvent", "QKeyEvent *ev");
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
MainFrame::vdcdebug("TextEdit","setNoEntry", "bool ro");
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
MainFrame::vdcdebug("WidgetHelper","getLengthBySqlType", "const QString& sqlType");
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
MainFrame::vdcdebug("WidgetHelper","getWidgetName", "QObject* widget");
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
MainFrame::vdcdebug("WidgetHelper","getWidgetColName", "QObject* widget");
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

   if(ComboBox *comboBox = qobject_cast<ComboBox *> (widget)){
      return comboBox->colName;
   }

   if(TableView *table = qobject_cast<TableView *> (widget)){
      return table->getColumnName(table->currentIndex().column());
   }

   return widgetColName;
}

QString WidgetHelper::getWidgetTabName(QObject* widget)
{
MainFrame::vdcdebug("WidgetHelper","getWidgetColName", "QObject* widget");
   QString widgetTabName;

   if(Label *label = qobject_cast<Label *> (widget)){
      return label->sqlTabName;
   }

   if(LineEdit *lineEdit = qobject_cast<LineEdit *> (widget)){
         return lineEdit->sqlTabName;
   }

   if(TextEdit *textEdit = qobject_cast<TextEdit *> (widget)){
      return textEdit->sqlTabName;
   }

   if(ComboBox *comboBox = qobject_cast<ComboBox *> (widget)){
      return comboBox->sqlTabName;
   }

   return widgetTabName;
}

QWidget* WidgetHelper::createFormWidget(const QDomElement& formField, QWidget *parent)
{
MainFrame::vdcdebug("WidgetHelper","createFormWidget", "const QDomElement& formField, QWidget *parent");
   QDomElement lineEditElement = formField.firstChild().toElement();

   if(lineEditElement.nodeName().isEmpty()) {
       lineEditElement.nodeName() = "BlankLine";
   }

   if(lineEditElement.nodeName() == "Label" || lineEditElement.nodeName() == "RipLabel" || lineEditElement.nodeName()  == "BlankLine"){
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
MainFrame::vdcdebug("WidgetHelper","createFormField", "const QDomElement& formField, QWidget *parent");


   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");

   bool hidden   = formField.attribute("hidden").toInt();
   bool noShow   = formField.attribute("noshow").toInt();
   bool noEntry  = formField.attribute("noEntry").toInt();
   bool notNull  = formField.attribute("notNull").toInt();
   bool required  = formField.attribute("required").toInt();

   int fieldId  = formField.attribute("fieldId").toInt();
   int tabIndex = formField.attribute("tabIndex").toInt();


   QString defaultValue = formField.attribute("defaultValue");

   FormField *fField = new FormField(parent);
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
   fField->setIsHidden(hidden);
   fField->setNoShow(noShow);

   //QWidget *childWidget = WidgetHelper::createFormWidget(formField.firstChild().toElement(), fField);
   //QWidget *childWidget = WidgetHelper::createFormWidget(formField, fField);
   //fField->addField(childWidget);

   return fField;
}

Label* WidgetHelper::createLabel(const QDomElement& formField, QWidget *parent)
{   
MainFrame::vdcdebug("WidgetHelper","createLabel", "const QDomElement& formField, QWidget *parent");
   QDomElement labelElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   //QString sqlType = formField.attribute("sqlType");

   bool hidden     = formField.attribute("hidden").toInt();
   bool noShow     = formField.attribute("noshow").toInt();
   bool noHideMenu = formField.attribute("nohidemenu").toInt();

   int w  = labelElement.attribute("width").toInt();

   Label *label = new Label(parent);
   label->setAccessibleName(name);
   label->setObjectName(colName);
   label->name = name;
   label->colName = colName;
   label->sqlTabName = tabName;
   label->w = w;
   label->setIsHidden(hidden);
   label->setNoShow(noShow);
   label->setNoHideMenu(noHideMenu);


   QString comments = labelElement.attribute("comments");
   if(!comments.isEmpty()){
      label->setToolTip(comments);
   }
   if(FglForm *p_fglform = qobject_cast<FglForm*> (parent)) {
       int hideColumn = VDC::readSettingsFromIni(p_fglform->formName(), QString(label->colName + "/hideColumn"), "-1").toInt();
       if(hideColumn > 0 || label->getIsHidden()) {
           label->hide();
       }

       if(hideColumn == -1 && noShow) {
           label->setVisible(false);
       }
   }
   if(hidden){
      label->setVisible(false);
   }

   QFontMetrics fm = label->fontMetrics();
   w = w*fm.averageCharWidth()*VDC::getFieldSizeFactor();

  // QPalette p = label->palette();
  // p.setColor(QPalette::Foreground, Qt::blue);
 //  label->setPalette(p);
   //label->setFixedHeight(VDC::DEFAULT_HEIGHT);
  // label->setFixedWidth(w);
   return label;
}

Label* WidgetHelper::createImage(const QDomElement& formField, QWidget *parent)
{   
MainFrame::vdcdebug("WidgetHelper","createImage", "const QDomElement& formField, QWidget *parent");
   QDomElement labelElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   //QString sqlType = formField.attribute("sqlType");

   bool hidden   = formField.attribute("hidden").toInt();
   bool autoScale = labelElement.attribute("autoScale").toInt();  //Used in WidgetHelper::setFieldText

   int w  = labelElement.attribute("pixelWidth").toInt();
   int h  = labelElement.attribute("pixelHeight").toInt();

   Label *label = new Label(parent);
   label->setAccessibleName(name);
   label->setObjectName(colName);
   label->name = name;
   label->colName = colName;
   label->sqlTabName = tabName;
   label->w = w;
   label->img = true;
   label->autoScale = autoScale;

   QString comments = labelElement.attribute("comments");
   if(!comments.isEmpty()){
      label->setToolTip(comments);
   }

   if(hidden){
      label->setVisible(false);
   }

   QPixmap pixmap("");
   label->setPixmap(pixmap);

   label->setFixedSize(w,h);

   return label;
}

WebView* WidgetHelper::createWebView(const QDomElement& formField, QWidget *parent)
{   
MainFrame::vdcdebug("WidgetHelper","createWebView", "const QDomElement& formField, QWidget *parent");
   QDomElement browserElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   //QString tabName = formField.attribute("sqlTabName");
   //QString sqlType = formField.attribute("sqlType");
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
        int width = w*fm.averageCharWidth()*VDC::getFieldSizeFactor()+10;
   	browser->setFixedWidth(width);
   }
   if (hPixel>0) {
	// Specified a pixel height...
   	browser->setFixedHeight(hPixel);
   } else {
	if (h>0) { 
		// Specified a Line height...
		browser->setFixedHeight(VDC::DEFAULT_HEIGHT*h);
	} else {
		browser->setFixedHeight(VDC::DEFAULT_HEIGHT);
	}
   }

   return browser;
}

Button* WidgetHelper::createButton(const QDomElement& formField, QWidget *parent)
{
MainFrame::vdcdebug("WidgetHelper","createButton", "const QDomElement& formField, QWidget *parent");
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
   int width = w*fm.averageCharWidth()*VDC::getFieldSizeFactor();
   if(w == 1){
      width += 10;
   }
   button->setFixedWidth(width);

   return button;
}

Edit* WidgetHelper::createEdit(const QDomElement& formField, QWidget *parent)
{   
MainFrame::vdcdebug("WidgetHelper","createEdit", "const QDomElement& formField, QWidget *parent");
   QDomElement lineEditElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");
   bool hidden   = formField.attribute("hidden").toInt();
   bool noShow   = formField.attribute("noshow").toInt();

   QString defaultValue = formField.attribute("defaultValue");

   int w  = lineEditElement.attribute("width").toInt();

   QString shift  = lineEditElement.attribute("shift");

   bool autoNext = lineEditElement.attribute("autoNext").toInt();
   bool noEntry  = formField.attribute("noEntry").toInt();
   bool scroll  = lineEditElement.attribute("scroll").toInt();

   Edit *lineEdit = new Edit(parent);
   lineEdit->setAccessibleName(name);
   lineEdit->setObjectName(colName);
   lineEdit->name = name;
   lineEdit->colName = colName;
   lineEdit->sqlTabName = tabName;
   lineEdit->w = w;
   lineEdit->scroll = scroll;
   lineEdit->setShift(shift);
   lineEdit->setNoEntry(noEntry);
   lineEdit->setProperty("noEntry", noEntry);
   lineEdit->setAutoNext(autoNext);
   lineEdit->setSqlType(sqlType);
   lineEdit->setDefaultValue(defaultValue);

   lineEdit->setNoShow(noShow);

   QString comments = lineEditElement.attribute("comments");
   if(!comments.isEmpty()){
      lineEdit->setToolTip(comments);
   }

   QString picture = lineEditElement.attribute("picture").trimmed();
   lineEdit->setPicture(picture);

   QString format = lineEditElement.attribute("format");

   QString screenFormat = VDC::readSettingsFromLocalIni("","screenFormat");

   switch(lineEdit->dataType())
   {
   case Fgl::DTYPE_SMFLOAT:
   case Fgl::DTYPE_FLOAT:
   case Fgl::DTYPE_DECIMAL:
      if(!screenFormat.isEmpty() && screenFormat != "-1")
      {
          if(screenFormat != "-" && screenFormat != "--")
          {
              lineEdit->setFormat(screenFormat);
          } else {
              lineEdit->setFormat("######&.&&");
          }
      } else {
          lineEdit->setFormat(format);
      }
      break;
   default:
       lineEdit->setFormat("");
       break;
   }

   QFontMetrics fm = lineEdit->fontMetrics();

   int width = w*fm.averageCharWidth()*VDC::getFieldSizeFactor()+10;
   /*lineEdit->setFixedWidth(width);
   lineEdit->setFixedHeight(defHeight);*/

   if(parent != NULL) {
       if(parent->accessibleName() != "FGLFORM") {
           if(parent->isEnabled()) {
           lineEdit->resize(QSize(width, VDC::DEFAULT_HEIGHT));
           }
       } else {
           lineEdit->setFixedWidth(width);
       }
   } else {
       lineEdit->setFixedWidth(width);
   }

   if(FglForm *p_fglform = qobject_cast<FglForm*> (parent)) {
       int hideColumn = VDC::readSettingsFromIni(p_fglform->formName(), lineEdit->colName+"/hideColumn", "-1").toInt();
       if(hideColumn > 0) {
           lineEdit->hide();
       }

       if(hideColumn == -1 && noShow) {
           lineEdit->setVisible(false);
       }
   }
   if(hidden)
      lineEdit->setVisible(false);

   return lineEdit;
}

ButtonEdit* WidgetHelper::createButtonEdit(const QDomElement& formField,QWidget *parent)
{   
MainFrame::vdcdebug("WidgetHelper","createButtonEdit", "const QDomElement& formField,QWidget *parent");
   QDomElement lineEditElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");
   bool hidden   = formField.attribute("hidden").toInt();
   bool noShow   = formField.attribute("noshow").toInt();

   QString defaultValue = formField.attribute("defaultValue");

   int w  = lineEditElement.attribute("width").toInt();

   QString shift  = lineEditElement.attribute("shift");
   QString action = lineEditElement.attribute("action");
   QString image  = lineEditElement.attribute("image");

   bool autoNext = lineEditElement.attribute("autoNext").toInt();
   bool noEntry  = formField.attribute("noEntry").toInt();

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

   QString screenFormat = VDC::readSettingsFromLocalIni("","screenFormat");

   switch(lineEdit->dataType())
   {
   case Fgl::DTYPE_SMFLOAT:
   case Fgl::DTYPE_FLOAT:
   case Fgl::DTYPE_DECIMAL:
      if(!screenFormat.isEmpty() && screenFormat != "-1")
      {
          if(screenFormat != "-" && screenFormat != "--")
          {
              lineEdit->setFormat(screenFormat);
          } else {
             lineEdit->setFormat("######&.&&&&&&&&&&&&&&&&");
          }
      }
      break;
   default:
       break;
   }

   QString comments = lineEditElement.attribute("comments");
   if(!comments.isEmpty()){
      lineEdit->setToolTip(comments);
   }

   QString picture = lineEditElement.attribute("picture");
   lineEdit->setPicture(picture);

   QFontMetrics fm = lineEdit->fontMetrics();
   int width = w*fm.averageCharWidth()*VDC::getFieldSizeFactor()+10;
   /*lineEdit->setFixedWidth(width);
   lineEdit->setFixedHeight(defHeight);*/

   if(parent != NULL) {
       if(parent->accessibleName() != "FGLFORM") {
           if(parent->isEnabled()) {
           lineEdit->resize(QSize(width, VDC::DEFAULT_HEIGHT));
           }
       } else {
           lineEdit->setFixedWidth(width);
           //lineEdit->setFixedHeight(VDC::DEFAULT_HEIGHT);
       }
   } else {
       lineEdit->setFixedWidth(width);
       //lineEdit->setFixedHeight(VDC::DEFAULT_HEIGHT);
   }

   if(FglForm *p_fglform = qobject_cast<FglForm*> (parent)) {
       int hideColumn = VDC::readSettingsFromIni(p_fglform->formName(), QString(lineEdit->colName + "/hideColumn"), "-1").toInt();
       if(hideColumn > 0 || lineEdit->getIsHidden()) {
           lineEdit->hide();
       }

       if(hideColumn == -1 && noShow) {
           lineEdit->setVisible(false);
       }
   }
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
            p.setColor(QPalette::Active, QPalette::Foreground, col);
            widget->setPalette(p);

            QString fontconv = dummy.font().toString();
            QStringList splitlist = fontconv.split(",");
            int fsize = splitlist[1].toInt();

            if (splitlist[0] == "Open Sans Semibold")
            {
                QFont f("Open Sans", fsize, QFont::Bold);
                widget->setFont(f);
            }else{
                QFont f(splitlist[0], fsize, QFont::Bold);
                widget->setFont(f);
            }


         } else if (LineEdit *le = qobject_cast<LineEdit*> (widget))
         {
             Q_UNUSED(le);
             //LineEdit dummy;
             //dummy.setEnabled(widget->isEnabled());
             //widget->setFont(dummy.font());
             //Stylesheet set in default.4st
             //QColor lightgrey(247, 247, 247);
             //QPalette p = widget->palette();
             //p.setColor(QPalette::Disabled, widget->backgroundRole(), lightgrey);
             //widget->setPalette(p);

         }else if (TextEdit *le = qobject_cast<TextEdit*> (widget))
         {
             Q_UNUSED(le);
             //LineEdit dummy;
             //dummy.setEnabled(widget->isEnabled());
             //widget->setFont(dummy.font());     
             //Stylesheet set in default.4st
             //widget->setStyleSheet(" QTextEdit:disabled {background-color: #f7f7f7}; ");

         }
         else if(LineEditDelegate *led = qobject_cast<LineEditDelegate *> (widget))
         {
             Q_UNUSED(led);
         }
         else
         {/*
            QLineEdit dummy;
            dummy.setEnabled(widget->isEnabled());
            QColor dummycol = dummy.palette().color(QPalette::Text);
            QPalette p = widget->palette();
            if(dummycol.red() < 10 || dummycol.blue() < 10 || dummycol.green() < 10)
            {
                QColor col(0,0,0);
                p.setColor(QPalette::Text, col);
            }
            else
            {
                QColor col(dummycol.red()-10, dummycol.green()-10, dummycol.blue()-10);
                p.setColor(QPalette::Active, QPalette::Foreground, col);
                //p.setColor(QPalette::Text, col);
            }
            widget->setPalette(p);
            widget->setFont(dummy.font());*/
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
                 //  QColor col(25, 59, 165);
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
         {
             if(LineEdit *le = qobject_cast<LineEdit*> (widget))
                le->setEchoMode(QLineEdit::Password);
         }
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
MainFrame::vdcdebug("WidgetHelper","createDateEdit", "const QDomElement& formField,QWidget *parent");
   QDomElement lineEditElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");
   bool hidden   = formField.attribute("hidden").toInt();
   bool noShow   = formField.attribute("noshow").toInt();
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
   int width = w*fm.averageCharWidth()*VDC::getFieldSizeFactor()+10;
   //lineEdit->setFixedWidth(width);
   //lineEdit->setFixedHeight(defHeight);
   if(parent != NULL) {
       if(parent->accessibleName() != "FGLFORM") {
           if(parent->isEnabled()) {
           lineEdit->resize(QSize(width, VDC::DEFAULT_HEIGHT));
           }
       } else {
           lineEdit->setFixedWidth(width);
           //lineEdit->setFixedHeight(VDC::DEFAULT_HEIGHT);
       }
   } else {
       lineEdit->setFixedWidth(width);
       //lineEdit->setFixedHeight(VDC::DEFAULT_HEIGHT);
   }

   if(FglForm *p_fglform = qobject_cast<FglForm*> (parent)) {
       int hideColumn = VDC::readSettingsFromIni(p_fglform->formName(), QString(lineEdit->colName + "/hideColumn"),"-1").toInt();
       if(hideColumn > 0) {
           lineEdit->hide();
       }

       if(hideColumn == -1 && noShow) {
           lineEdit->setVisible(false);
       }
   }
   if(hidden)
      lineEdit->setVisible(false);

   return lineEdit;
}

TextEdit* WidgetHelper::createTextEdit(const QDomElement& formField, QWidget *parent)
{   
MainFrame::vdcdebug("WidgetHelper","createTextEdit", "const QDomElement& formField, QWidget *parent");
   QDomElement textEditElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");
   bool hidden   = formField.attribute("hidden").toInt();
   bool noShow   = formField.attribute("noshow").toInt();
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

   QString scrollBars = textEditElement.attribute("scrollBars").toLower();
   QString sizePolicy = textEditElement.attribute("sizePolicy");
   QString style = textEditElement.attribute("style");
   QString stretch = textEditElement.attribute("stretch","none").toLower();
   bool wantTabs = textEditElement.attribute("wantTabs").toInt();
   bool wantReturns = true;
   if(!textEditElement.attribute("wantReturns").isEmpty()){
      wantReturns = textEditElement.attribute("wantReturns").toInt();
   }

   TextEdit *textEdit = new TextEdit(parent);
   textEdit->setAccessibleName(name);
   textEdit->setObjectName(colName);
   textEdit->setProperty("style", style);
   textEdit->name = name;
   textEdit->colName = colName;
   textEdit->sqlTabName = tabName;
   textEdit->b_stretch = false;

   if(stretch == "both")
   {
      textEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
   }
   if(stretch == "y")
   {
       textEdit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
   }
   if(stretch == "x")
   {
       textEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
   }


   textEdit->setStretching(stretch);
   textEdit->setWantTabs(wantTabs);
   textEdit->setWantReturns(wantReturns);
   textEdit->setDefaultValue(defaultValue);




   if(scrollBars == "both" || scrollBars == "x")
   {
       textEdit->setLineWrapMode(QTextEdit::NoWrap);
       textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
   }
   if(scrollBars=="both" || scrollBars == "y")
   {
       textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
   }









   QString comments = textEditElement.attribute("comments");
   if(!comments.isEmpty()){
      textEdit->setToolTip(comments);
   }

   int height = textEditElement.attribute("height", "0").toInt();
   if(height < 1) height = 1;

   if(FglForm *p_fglform = qobject_cast<FglForm*> (parent)) {
       int hideColumn = VDC::readSettingsFromIni(p_fglform->formName(), QString(textEdit->colName + "/hideColumn"), "-1").toInt();
       if(hideColumn > 0) {
           textEdit->hide();
       }

       if(hideColumn == -1 && noShow) {
           textEdit->setVisible(false);
       }
   }
   if(hidden)
      textEdit->setVisible(false);

   QFontMetrics fm = textEdit->fontMetrics();

   int width = w*fm.averageCharWidth()*VDC::getFieldSizeFactor()+10;

   if(stretch == "none")
   {
      textEdit->setFixedHeight(height*fm.height()+6);
      //textEdit->setFixedHeight(height*VDC::DEFAULT_HEIGHT);
      textEdit->setFixedWidth(width);

   }
   if(stretch == "both")
   {
       //textEdit->setMinimumSize(width,VDC::DEFAULT_HEIGHT*height);
       textEdit->setMinimumSize(width,height*fm.height()+6);
   }
   if(stretch == "y")
   {
       //textEdit->setMinimumHeight(VDC::DEFAULT_HEIGHT*height);
       textEdit->setMinimumHeight(height*fm.height()+6);
       textEdit->setFixedWidth(width);
   }
   if(stretch == "x")
   {
       textEdit->setFixedHeight(VDC::DEFAULT_HEIGHT*height);
       textEdit->setMinimumWidth(width);
   }


   textEdit->setShift(shift);
   textEdit->setNoEntry(noEntry);
   textEdit->setAutoNext(autoNext);
   textEdit->setSqlType(sqlType);


   return textEdit;

}

ComboBox* WidgetHelper::createComboBox(const QDomElement& formField, QWidget *parent)
{   
MainFrame::vdcdebug("WidgetHelper","createComboBox", "const QDomElement& formField, QWidget *parent");
   QDomElement comboBoxElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");
   bool hidden   = formField.attribute("hidden").toInt();
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
   comboBox->colName = colName;
   comboBox->sqlTabName = tabName;
   comboBox->setAccessibleName(name);
   comboBox->setObjectName(colName);
   comboBox->setDefaultValue(defaultValue);

   int height = comboBoxElement.attribute("height").toInt();
   if(height < 1) height = 1;

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

   if(hidden)
      comboBox->setVisible(false);

   QFontMetrics fm = comboBox->fontMetrics();
   int width = w*fm.averageCharWidth()*VDC::getFieldSizeFactor()+10;
   //  comboBox->resize(QSize(width, VDC::DEFAULT_HEIGHT*height));
   comboBox->setFixedWidth(width);
   comboBox->setFixedHeight(VDC::DEFAULT_HEIGHT*height);


   return comboBox;

}

CheckBox* WidgetHelper::createCheckBox(const QDomElement& formField, QWidget *parent)
{   
MainFrame::vdcdebug("WidgetHelper","createCheckBox", "const QDomElement& formField, QWidget *parent");
   QDomElement checkBoxElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   bool notNull = formField.attribute("notNull").toInt();
   int w  = checkBoxElement.attribute("width").toInt();
   QString defaultValue = formField.attribute("defaultValue");


   // NOT IMPLENTED AT THIS TIME
   /*QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");
   bool hidden   = formField.attribute("hidden").toInt();

   //bool required = formField.attribute("required").toInt();

   QString color = checkBoxElement.attribute("color").toLower();
   QString colorCondition = checkBoxElement.attribute("colorCondition");
   QString comment = checkBoxElement.attribute("comment");

   QString qs_default = checkBoxElement.attribute("default");
   QString fontPitch = checkBoxElement.attribute("fontPitch");

   QString include = checkBoxElement.attribute("include");

   //bool noEntry  = checkBoxElement.attribute("noEntry").toInt();
   //bool autoNext = checkBoxElement.attribute("autoNext").toInt();

   QString sizePolicy = checkBoxElement.attribute("sizePolicy");
   QString style = checkBoxElement.attribute("style");*/
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

   checkBox->setFixedHeight(VDC::DEFAULT_HEIGHT*height);

   QString comments = checkBoxElement.attribute("comments");
   if(!comments.isEmpty()){
      checkBox->setToolTip(comments);
   }
   

   QFontMetrics fm = checkBox->fontMetrics();
   int width = w*fm.averageCharWidth()*VDC::getFieldSizeFactor()+10;
   checkBox->setFixedWidth(width);



   return checkBox;

}

ProgressBar* WidgetHelper::createProgressBar(const QDomElement& formField, QWidget *parent)
{   
MainFrame::vdcdebug("WidgetHelper","createProgressBar", "const QDomElement& formField, QWidget *parent");
   QDomElement progressBarElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");
   bool hidden   = formField.attribute("hidden").toInt();
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

   progressBar->setFixedHeight(VDC::DEFAULT_HEIGHT*height);

   QString comments = progressBarElement.attribute("comments");
   if(!comments.isEmpty()){
      progressBar->setToolTip(comments);
   }

   if(hidden)
      progressBar->setVisible(false);
   

   QFontMetrics fm = progressBar->fontMetrics();
   int width = w*fm.averageCharWidth()*VDC::getFieldSizeFactor()+10;
   progressBar->setFixedWidth(width);

   return progressBar;

}

bool WidgetHelper::isFieldWidget(QObject *object)
{
MainFrame::vdcdebug("WidgetHelper","isFieldWidget", "QObject *object");

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
MainFrame::vdcdebug("WidgetHelper","isFieldWidget", "QObject *object, QString fieldName");

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
MainFrame::vdcdebug("WidgetHelper","copy", "QObject* object");
   if(LineEdit *widget = qobject_cast<LineEdit *> (object)){
      widget->copy();
   }

   if(TextEdit *widget = qobject_cast<TextEdit *> (object)){
      widget->copy();
   }
}

void WidgetHelper::cut(QObject* object)
{
MainFrame::vdcdebug("WidgetHelper","cut", "QObject* object");
   if(LineEdit *widget = qobject_cast<LineEdit *> (object)){
      widget->cut();
   }

   if(TextEdit *widget = qobject_cast<TextEdit *> (object)){
      widget->cut();
   }
}

void WidgetHelper::paste(QObject* object)
{
MainFrame::vdcdebug("WidgetHelper","paste", "QObject* object");
   if(LineEdit *widget = qobject_cast<LineEdit *> (object)){
      widget->paste();
   }

   if(TextEdit *widget = qobject_cast<TextEdit *> (object)){
      widget->paste();
   }
}

void WidgetHelper::setFieldText(QObject *object, QString fieldValue)
{
MainFrame::vdcdebug("WidgetHelper","setFieldText", "QObject *object, QString fieldValue");

   if(Label *widget = qobject_cast<Label *> (object)){
       if(widget->pixmap() == 0 && widget->movie() == 0 && !fieldValue.contains(".png") && !fieldValue.contains(".jpg") && !fieldValue.contains(".jepg") && !fieldValue.contains(".gif")){
         widget->setText(fieldValue);
         widget->fieldValue = fieldValue;
         widget->repaint();
      }
      else{


         if(QFile::exists(":pics/" + fieldValue))
         {
                 fieldValue = ":pics/" + fieldValue;
         }
         else if(!QFile::exists(fieldValue))
         {
             fieldValue.prepend(QDir::tempPath().append("/"));
         }
         if(fieldValue.endsWith(".gif",Qt::CaseInsensitive))
         {

             if(widget->fieldValue == fieldValue)
             {
                return; // Avoid repaint event
             }
             QMovie *movie = new QMovie(widget);
             movie->setFileName(fieldValue);
             widget->setMovie(movie);
             movie->start();
             widget->fieldValue = fieldValue;

         }
         else
         {

             if(widget->fieldValue == fieldValue)
             {
                return; // Avoid repaint event
             }
             QPixmap pixmap(fieldValue);

             if (widget->autoScale) {
                 widget->setPixmap(pixmap.scaled(widget->size(), Qt::KeepAspectRatio));
             } else {
                 widget->setPixmap(pixmap);
             }
             widget->setAlignment(Qt::AlignTop);
             widget->fieldValue = fieldValue;
         }
         //widget->setFixedSize(pixmap.size());
      }

      return;
   }

   if(Button *widget = qobject_cast<Button *> (object)){
      widget->setText(fieldValue);
      return;
   }

   if(WebView *widget = qobject_cast<WebView *> (object)){

       if(QFile::exists(QDir::tempPath() + "/" + fieldValue.split("?").at(0)))
       {
           #ifdef Q_OS_WIN
              fieldValue = "file:///" + QDir::tempPath() + "/" + fieldValue;
           #else
              fieldValue = "file://" +  QDir::tempPath() + "/" + fieldValue;
           #endif
       }
       if(fieldValue.contains("vdc_google_api"))
       {
           widget->setPage(new WebPage());
       }
       widget->setUrl(QUrl(fieldValue, QUrl::TolerantMode));//widget->load(QUrl(fieldValue,QUrl::TolerantMode));
       return;
   }

   if(LineEdit *widget = qobject_cast<LineEdit *> (object)){
       fieldValue = Fgl::usingFunc(widget->format(), fieldValue, widget->dataType(), widget->picture()).trimmed();

       if(fieldValue != widget->text()){
           widget->setText(fieldValue);
           if(!widget->isEnabled())
           {
              widget->setCursorPosition(0);
           }
       }
      return;
   }

   if(TextEdit *widget = qobject_cast<TextEdit *> (object)){
       fieldValue = Fgl::usingFunc("", fieldValue, Fgl::DTYPE_CHAR);
       if(fieldValue.trimmed() != widget->toPlainText()){
         widget->setPlainText(fieldValue);
       }
      return;
   }

   if(ComboBox *widget = qobject_cast<ComboBox *> (object)){
      if(!fieldValue.trimmed().isEmpty())
      {
          int index = widget->findData(fieldValue.trimmed());
        widget->setCurrentIndex(index);
      }
}

   if(ProgressBar *widget = qobject_cast<ProgressBar *> (object)){
      widget->setValue(fieldValue.toInt());
      return;
   }

}

QString WidgetHelper::fieldText(QObject *object)
{
MainFrame::vdcdebug("WidgetHelper","fieldText", "QObject *object");

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
       QString text = Fgl::vdc_to_fgl(widget->format(), widget->text(), widget->dataType());
       return text;
  /*   if(widget->sqlTabName == "formonly")
      {
         int cnt_comma = 0;
//  text.replace(".","");
         for(int i = 0; i<text.size(); i++)
          {
             QString zeichen = text.at(i);
             if(zeichen == ",")
             {
                 cnt_comma++;
                 if(cnt_comma > 1)
                 {
                     return text;
                 }
                 continue;
             }
             if(!zeichen.at(0).isNumber())
             {
                 return text;
             }
         }
         return text;//.replace(",",".");

      }
      if(widget->sqlType().contains("FLOAT") || widget->sqlType().contains("DECIMAL"))
      {
         return text;//.replace(",",".");
      }*/

   }

   if(TextEdit *widget = qobject_cast<TextEdit *> (object)){
/*       if(widget->sqlType().contains("FLOAT") || widget->sqlType().contains("DECIMAL"))
       {
          return widget->toPlainText();//.replace(",",".");
       }
   */
       /*if(VDC::getDBLocale() == "ISO-8859-1") {
           int enableFilter = VDC::readSettingsFromLocalIni("","convertText").toInt();

           if(enableFilter != 2) {
               return Umlauts::replaceUmlauts(widget->toPlainText());
           } else {
               return widget->toPlainText();
           }
       } else {
           return widget->toPlainText();
       }*/
       return widget->toPlainText();
   }

   if(ComboBox *widget = qobject_cast<ComboBox *> (object)){
      return widget->itemData(widget->currentIndex()).toString();
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
MainFrame::vdcdebug("WidgetHelper","setDefaultFieldText", "QObject *object");

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
         for (int idx = 0; idx <= widget->count(); idx++)
         {
            if (widget->itemText(idx) == fieldValue )
            {
               widget->setCurrentIndex(idx);
               break;
            }
         }
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
MainFrame::vdcdebug("WidgetHelper","defaultFieldText", "QObject *object");

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
   QString exprString = ".*";
   QString sqlType;
   QString shift;
   int w = 0; 

   if(LineEdit *lineEdit = qobject_cast<LineEdit *> (widget)){
      sqlType = lineEdit->sqlType();
      shift = lineEdit->shift();
      w = getLengthBySqlType(sqlType);
      if(lineEdit->scroll && w < 250) {
          w = 250;
      }

      if(w <= 0) {
         w = lineEdit->w;
      }

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
      sqlType == "SMALLINT"){
      exprString = QString("^[-0-9]+$");
   }

   if(sqlType == "SERIAL"){
      exprString = QString("^[0-9]+$");
   }

   if(sqlType == "DATE"){
      return;
   }

   QRegExp regExp(exprString);

   if(!shift.isEmpty()){
      if(shift == "up"){
         UppercaseValidator *validator = new UppercaseValidator(regExp,widget);
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
       /*
      if(exprString.isEmpty())
         return;
*/
      QRegExpValidator *validator = new QRegExpValidator(regExp, widget);
      if(LineEdit *lineEdit = qobject_cast<LineEdit *> (widget)){
         lineEdit->setValidator(validator);
      }

   }
}

Label::Label(const QString &text, QWidget *parent)
    : QLabel(text, parent)
{
   //QFont font;
  // font.setPixelSize(12);
   this->img = false;
  // this->setFont(font);
   this->fieldValue = "";
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
 //  QFont font;
  // font.setPixelSize(12);
   this->img = false;
  // this->setFont(font);
   this->fieldValue = "";
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
MainFrame::vdcdebug("PopupCalendar","eventFilter", "QObject *obj, QEvent *ev");

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
MainFrame::vdcdebug("ProgressBar","ProgressBar", "QWidget *parent");
   setProperty("touched", false);
   setTextVisible(false);
}

WebView::WebView(QWidget *parent) : QWebEngineView(parent)
{
MainFrame::vdcdebug("WebView","WebView", "QWidget *parent");
   
}

ComboBox::ComboBox(QWidget *parent) : QComboBox(parent)
{
MainFrame::vdcdebug("ComboBox","ComboBox", "QWidget *parent");
   setProperty("touched", false);
   setEnabled(false);
   setEditable(false);
   connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(isTouched()));

}

CheckBox::CheckBox(QWidget *parent) : QCheckBox(parent)
{
MainFrame::vdcdebug("CheckBox","CheckBox", "QWidget *parent");
   setProperty("touched", false);
   setValueChecked(QString::number(1));
   setValueUnchecked(QString::number(0));
   setTristate(true);
   setCheckState(Qt::PartiallyChecked);
}

CheckBox::CheckBox(QString text, QWidget *parent) : QCheckBox(text, parent)
{
MainFrame::vdcdebug("CheckBox","CheckBox", "QString text, QWidget *parent");
   setProperty("touched", false);
   setValueChecked(QString::number(1));
   setValueUnchecked(QString::number(0));
   setTristate(true);
   setCheckState(Qt::PartiallyChecked);
}

TabWidget::TabWidget(QWidget *parent) : QTabWidget(parent)
{
MainFrame::vdcdebug("TabWidget","TabWidget", "QWidget *parent");
}
