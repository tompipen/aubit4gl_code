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

int defHeight = 21;

//------------------------------------------------------------------------------
// Method       : Button()
// Filename     : xml2form.cpp
// Description  : 
//------------------------------------------------------------------------------
Button::Button(QWidget *parent)
    : QPushButton(parent)
{

   setProperty("touched", false);
   if(parent == NULL){
      connect(this, SIGNAL(clicked()), this, SLOT(buttonClicked()));
   }

}

void Button::buttonClicked()
{
   Fgl::Event event;
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
   this->qs_sqlType = sqlType;
   WidgetHelper::setValidator(this);
   valid = this->validator();
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
      button = new Button(this);
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
}

void ButtonEdit::setButtonKey(QString bk)
{
  qs_buttonKey = bk;
  QAction *keyButton = new QAction(bk, this);
  QKeySequence shortcut(bk);
  connect(keyButton, SIGNAL(triggered()), this, SLOT(buttonClicked()));
  this->addAction(keyButton);
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

   bool ok = false;
   int keyNum = buttonKey().mid(1,buttonKey().length()-1).toInt(&ok);

   if(ok){
      keyNum += 2999;
      Fgl::Event event;
      event.type = Fgl::ONKEY_EVENT;
      event.attribute = QString::number(keyNum);
      emit fieldEvent(event);
   }
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
   button = new Button(this);
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
   PopupCalendar *calendar = new PopupCalendar(QDate::fromString(this->text(), "d.M.yyyy"),
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
   if(!wantReturns()){
      int key = ev->key();
      if(key == Qt::Key_Return || key == Qt::Key_Enter){
         ev->ignore();
         emit returnPressed();
         return;
      }
   }
   
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
      Label *label = createLabel(formField, parent);
      QPixmap pixmap("");
      label->setPixmap(pixmap);
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


   QPalette p = label->palette();
   p.setColor(QPalette::Foreground, Qt::blue);
   label->setPalette(p);
   label->setFixedHeight(defHeight);

   return label;
}

WebView* WidgetHelper::createWebView(const QDomElement& formField, QWidget *parent)
{   
   QDomElement browserElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");

   bool hidden   = formField.attribute("hidden").toInt();

   int w  = browserElement.attribute("width").toInt();
   WebView *browser = new WebView(parent);
   browser->setAccessibleName(name);
   browser->setObjectName(colName);
   browser->name = name;
   browser->colName = colName;

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

   browser->setFixedHeight(defHeight);

   return browser;
}

Button* WidgetHelper::createButton(const QDomElement& formField, QWidget *parent)
{
   QDomElement buttonElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");

   QString action = buttonElement.attribute("action");

   bool hidden   = formField.attribute("hidden").toInt();

   Button *button = new Button();
   button->action = action;
   button->setAccessibleName(name);
   button->setObjectName(colName);
   button->name = name;
   button->colName = colName;

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

   QString comments = lineEditElement.attribute("comments");
   if(!comments.isEmpty()){
      lineEdit->setToolTip(comments);
   }

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

   QString comments = lineEditElement.attribute("comments");
   if(!comments.isEmpty()){
      lineEdit->setToolTip(comments);
   }

   QFontMetrics fm = lineEdit->fontMetrics();
   int width = w*fm.width("W")+10;
   lineEdit->setFixedWidth(width);
   lineEdit->setFixedHeight(defHeight);

   if(hidden)
      lineEdit->setVisible(false);

   return lineEdit;
}

DateEdit* WidgetHelper::createDateEdit(const QDomElement& formField,QWidget *parent)
{
   QDomElement lineEditElement = formField.firstChild().toElement();

   QString name    = formField.attribute("name");
   QString colName = formField.attribute("colName");
   QString tabName = formField.attribute("sqlTabName");
   QString sqlType = formField.attribute("sqlType");
   bool hidden   = formField.attribute("hidden").toInt();

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

   QString comments = lineEditElement.attribute("comments");
   if(!comments.isEmpty()){
      lineEdit->setToolTip(comments);
   }

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

   bool required = formField.attribute("required").toInt();
   bool notNull = formField.attribute("notNull").toInt();

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
   bool wantReturns = textEditElement.attribute("wantReturns").toInt();

   TextEdit *textEdit = new TextEdit;
   textEdit->setAccessibleName(name);
   textEdit->setObjectName(colName);
   textEdit->name = name;
   textEdit->colName = colName;
   textEdit->sqlTabName = tabName;
   textEdit->setWantTabs(wantTabs);
   textEdit->setWantReturns(wantReturns);

   QString comments = textEditElement.attribute("comments");
   if(!comments.isEmpty()){
      textEdit->setToolTip(comments);
   }

   int height = textEditElement.attribute("height").toInt();
   if(height < 1) height = 1;

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
   bool hidden   = formField.attribute("hidden").toInt();

   bool required = formField.attribute("required").toInt();
   bool notNull = formField.attribute("notNull").toInt();

   int w  = comboBoxElement.attribute("width").toInt();

   QString color = comboBoxElement.attribute("color").toLower();
   QString colorCondition = comboBoxElement.attribute("colorCondition");
   QString comment = comboBoxElement.attribute("comment");

   QString shift = comboBoxElement.attribute("shift");
   QString fontPitch = comboBoxElement.attribute("fontPitch");

   QString include = comboBoxElement.attribute("include");

   bool noEntry  = comboBoxElement.attribute("noEntry").toInt();
   bool autoNext = comboBoxElement.attribute("autoNext").toInt();

   QString scrollBars = comboBoxElement.attribute("scrollBars");
   QString sizePolicy = comboBoxElement.attribute("sizePolicy");
   QString style = comboBoxElement.attribute("style");
   QString stretch = comboBoxElement.attribute("stretch");

   ComboBox *comboBox = new ComboBox(parent);
   comboBox->setAccessibleName(name);
   comboBox->setObjectName(colName);

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
   bool hidden   = formField.attribute("hidden").toInt();

   bool required = formField.attribute("required").toInt();
   bool notNull = formField.attribute("notNull").toInt();

   int w  = checkBoxElement.attribute("width").toInt();

   QString color = checkBoxElement.attribute("color").toLower();
   QString colorCondition = checkBoxElement.attribute("colorCondition");
   QString comment = checkBoxElement.attribute("comment");

   QString qs_default = checkBoxElement.attribute("default");
   QString fontPitch = checkBoxElement.attribute("fontPitch");

   QString include = checkBoxElement.attribute("include");

   bool noEntry  = checkBoxElement.attribute("noEntry").toInt();
   bool autoNext = checkBoxElement.attribute("autoNext").toInt();

   QString sizePolicy = checkBoxElement.attribute("sizePolicy");
   QString style = checkBoxElement.attribute("style");
   QString valueChecked = checkBoxElement.attribute("valueChecked");
   QString valueUnchecked = checkBoxElement.attribute("valueUnchecked");

   QString text = checkBoxElement.attribute("text");

   CheckBox *checkBox = new CheckBox(text, parent);
   checkBox->setAccessibleName(name);
   checkBox->setObjectName(colName);

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
   bool hidden   = formField.attribute("hidden").toInt();

   bool required = formField.attribute("required").toInt();
   bool notNull = formField.attribute("notNull").toInt();

   int w  = progressBarElement.attribute("width").toInt();

   QString color = progressBarElement.attribute("color").toLower();
   QString colorCondition = progressBarElement.attribute("colorCondition");
   QString comment = progressBarElement.attribute("comment");

   QString include = progressBarElement.attribute("include");

   bool noEntry  = progressBarElement.attribute("noEntry").toInt();
   bool autoNext = progressBarElement.attribute("autoNext").toInt();

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
      if(widget->pixmap() == 0){
         widget->setText(fieldValue);
      }
      else{
         QPixmap pixmap(fieldValue);
         widget->setPixmap(pixmap);
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
      widget->setText(fieldValue);
      return;
   }

   if(TextEdit *widget = qobject_cast<TextEdit *> (object)){
      widget->setText(fieldValue);
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
  dateEdit->setText(day.toString("dd.MM.yyyy"));
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
