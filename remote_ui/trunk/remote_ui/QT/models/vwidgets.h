//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : vwidgets.h
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
#ifndef VWIDGETS_H
#define VWIDGETS_H
#include <QDebug>
#include <QLineEdit>
#include <QTextEdit>
#include <QTimeEdit>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QGroupBox>
#include <QObject>
#include <QApplication>
#include <QRegExpValidator>
#include <QDomElement>
#include <QVBoxLayout>
#include <QDate>
#include <QCalendarWidget>
#include <QDialog>
#include <QProgressBar>
#include <QWebView>
#include <QTabWidget>
#include <QTextBlock>
#include <QTextCursor>
#include <include/fgl.h>

class LineEdit : public QLineEdit
{
   Q_OBJECT;

public:
    LineEdit(QWidget *parent = 0);
    QString sqlTabName;
    QString name;
    QString colName;
    int x;
    int y;
    int w;


    void setNoEntry(bool ro);
    bool noEntry() { return b_noEntry; };
    void setAutoNext(bool ro) { b_autoNext = ro; };
    bool autoNext() { return b_autoNext; };
    void setRequired(bool ro) { b_required = ro; };
    bool required() { return b_required; };
    void setCompress(bool ro) { b_compress = ro; };
    bool compress() { return b_compress; };
    void setShift(QString s) { qs_shift = s; };
    QString shift() { return qs_shift; };
    void setSqlType(QString);
    QString sqlType() { return qs_sqlType; };
    const QValidator* getValidator() { return valid; };
    void setTouchendEnabled(bool t) { setProperty("touched", t); };
    bool touched() { return property("touched").toInt(); };
    void setDefaultValue(QString def) { qs_default = def; };
    QString defaultValue() { return qs_default; };
    void setPicture(QString pic) { qs_picture = pic; setInputMask(pic); };
    QString picture() { return qs_picture; };

    bool b_denyFocus;

protected:
   bool eventFilter(QEvent*, QObject*);

private:
    // Attributes to know wich Validators to use
    QString qs_sqlType;
    bool b_noEntry;
    bool b_autoNext;
    bool b_required;
    bool b_compress;
    QString qs_shift;
    const QValidator* valid;
    QString qs_default;
    QString qs_picture;

public slots:
    void isTouched() { setProperty("touched", true); };

signals:
   void widgetOpen();
   void nextField();
   void fieldEvent(Fgl::Event);
};

class Edit : public LineEdit
{
   Q_OBJECT

public:
    Edit(QWidget *parent = 0);

/*
protected:
   void focusInEvent(QFocusEvent *);
   void focusOutEvent(QFocusEvent *);
*/
};

class Button : public QPushButton
{
   Q_OBJECT

public:
    Button(QWidget *parent = 0);
    QString sqlTabName;
    QString name;
    QString colName;
    QString action;
    void setDefaultValue(QString def) { qs_default = def; };
    QString defaultValue() { return qs_default; };

private:
   QString qs_default;

signals:
   void fieldEvent(Fgl::Event);

private slots:
   void buttonClicked();

};

class ButtonEdit : public LineEdit
{
   Q_OBJECT

public:
    ButtonEdit(QString iconFileName = NULL, QWidget *parent = 0);
    void setButtonKey(QString bk);
    QString buttonKey() { return qs_buttonKey; };

private:
    Button *button;
    QString iconFileName;
    QString qs_buttonKey;
    
protected:
   void resizeEvent(QResizeEvent *);

private slots:
   void buttonClicked();

signals:
};

//Canvas ....

class ComboBox : public QComboBox
{
   Q_OBJECT

public:
   ComboBox(QWidget *parent = 0);
   void setDefaultValue(QString def) { qs_default = def; };
   QString defaultValue() { return qs_default; };

private:
   QString qs_default;

signals:
   void fieldEvent(Fgl::Event);
};

class CheckBox : public QCheckBox
{
   Q_OBJECT

public:
   CheckBox(QWidget *parent=NULL);
   CheckBox(QString, QWidget *parent=NULL);

   void setValueChecked(QString val) { qs_valueChecked = val; };
   QString valueChecked() { return qs_valueChecked;};
   void setValueUnchecked(QString val) { qs_valueUnchecked = val; };
   QString valueUnchecked() { return qs_valueUnchecked;};
   void setDefaultValue(QString def) { qs_default = def; };
   QString defaultValue() { return qs_default; };

private:
   QString qs_valueChecked;
   QString qs_valueUnchecked;
   QString qs_default;

signals:
   void fieldEvent(Fgl::Event);
};

class DateEdit : public LineEdit
{
   Q_OBJECT

public:
    DateEdit(QWidget *parent = 0);

protected:
   void resizeEvent(QResizeEvent *);

private:
    Button *button;
    QString iconFileName;
    
private slots:
   void buttonClicked();
};

// VIMAGE
// VLABEL
class Label : public QLabel
{
   Q_OBJECT

public:
    Label(QWidget *parent = 0);
    Label(const QString &text, QWidget *parent = 0);
    QString sqlTabName;
    QString name;
    QString colName;

    int x,y,w;
};

class ProgressBar : public QProgressBar
{
   Q_OBJECT

public:
   ProgressBar(QWidget *parent = 0);
   QString name;
   QString colName;
   void setDefaultValue(QString def) { qs_default = def; };
   QString defaultValue() { return qs_default; };

private:
   QString qs_default;
};

class VRadioGroup : public QGroupBox
{
   Q_OBJECT

public:
   VRadioGroup(QWidget *parent = 0);
   QString name;
   QString colName;

signals:
   void fieldEvent(Fgl::Event);
};

class Slider : public QSlider
{
   Q_OBJECT

public:
   Slider(QWidget *parent = 0);
   QString name;
   QString colName;
   void setDefaultValue(QString def) { qs_default = def; };
   QString defaultValue() { return qs_default; };

private:
   QString qs_default;

signals:
   void fieldEvent(Fgl::Event);
};


class TextEdit : public QTextEdit
{
   Q_OBJECT

public:
   TextEdit(QWidget *parent = 0);
   QString qs_sqlType;
   QString sqlTabName;
   QString name;
   QString colName;

   int x;
   int y;
   int w;

   void setNoEntry(bool ro);
   bool noEntry() { return b_noEntry; };
   void setAutoNext(bool ro) { b_autoNext = ro; };
   bool autoNext() { return b_autoNext; };
   void setRequired(bool ro) { b_required = ro; };
   bool required() { return b_required; };
   void setCompress(bool ro) { b_compress = ro; };
   bool compress() { return b_compress; };
   void setShift(QString s) { qs_shift = s; };
   QString shift() { return qs_shift; };
   void setSqlType(QString);
   QString sqlType() { return qs_sqlType; };
   void setDefaultValue(QString def) { qs_default = def; };
   QString defaultValue() { return qs_default; };

   void setWantTabs(bool wt);
   bool wantTabs(){ return b_wantTabs; };
   void setWantReturns(bool wr);
   bool wantReturns() { return b_wantReturns; };

   bool b_denyFocus;
   int getCursorPosition();

   int getIndex (const QTextCursor &crQTextCursor );

private:
   // Attributes to know wich Validators to use
   bool b_noEntry;
   bool b_autoNext;
   bool b_required;
   bool b_compress;
   QString qs_shift;
   bool b_wantTabs;
   bool b_wantReturns;
   QString qs_default;

protected:
   void keyPressEvent(QKeyEvent*);

signals:
   void returnPressed();
   void fieldEvent(QString);
   void fieldEvent(Fgl::Event);

};

class TimeEdit : public QTimeEdit
{
   Q_OBJECT

public:
   TimeEdit(QWidget *parent = 0);
   QString name;
   QString colName;
   void setDefaultValue(QString def) { qs_default = def; };
   QString defaultValue() { return qs_default; };

private:
   QString qs_default;

signals:
   void fieldEvent(Fgl::Event);
};

class UppercaseValidator : public QRegExpValidator
{
 Q_OBJECT

public:
   UppercaseValidator(const QRegExp &input, QObject *parent) : QRegExpValidator(input, parent){};
   QValidator::State validate(QString &input, int &pos) const 
   {
     Q_UNUSED(pos);
     fixup(input);
     return Acceptable;
   }

   void fixup(QString &input) const
   {
      input = input.toUpper();
   }
};

class LowercaseValidator : public QRegExpValidator
{
 Q_OBJECT

public:
   LowercaseValidator(const QRegExp &input, QObject *parent) : QRegExpValidator(input, parent){};
   QValidator::State validate(QString &input, int &pos) const 
   {
     Q_UNUSED(pos);

     fixup(input);
     return Acceptable;
   }

   void fixup(QString &input) const
   {
      input = input.toLower();
   }
};

class Validator : public QRegExpValidator
{
 Q_OBJECT

public:
   Validator(const QRegExp &input, QObject *parent) : QRegExpValidator(input, parent){};
   QValidator::State validate(QString &input, int &pos) const 
   {
     Q_UNUSED(input);
     Q_UNUSED(pos);

     return Acceptable;
   }

   void fixup(QString &input) const
   {
      input = input.toUpper();
   }
};

class PopupCalendar : public QDialog
{
   Q_OBJECT

public:
   PopupCalendar(const QDate day = QDate::currentDate(),
                 QPoint pos = QPoint(), QWidget *parent = 0, 
                 QLineEdit *sender = 0);

private:
   QVBoxLayout *vboxLayout;

protected:
   bool eventFilter(QObject *obj, QEvent *ev);

  
};

class Calendar : public QCalendarWidget
{
   Q_OBJECT

public:
   Calendar(QWidget *parent = 0, QLineEdit *sender = 0);
   QDate day;
   QLineEdit *dateEdit;

public slots:
   void setDay();

};


class TabWidget : public QTabWidget
{
   Q_OBJECT

public:
   TabWidget(QWidget *parent = 0);

};

class WebView : public QWebView
{
   Q_OBJECT

public:
   WebView(QWidget *parent = 0);
   QString name;
   QString colName;
   void setDefaultValue(QString def) { qs_default = def; };
   QString defaultValue() { return qs_default; };

private:
   QString qs_default;



signals:
   void fieldEvent(Fgl::Event);
};

class WidgetHelper
{

public:
   static int getLengthBySqlType(const QString& sqlType);
   static QString getWidgetName(QObject*);
   static QString getWidgetColName(QObject*);
   static Edit* createEdit(const QDomElement&, QWidget *parent = NULL);
   static Label* createLabel(const QDomElement&, QWidget *parent = NULL);
   static Button* createButton(const QDomElement&, QWidget *parent = NULL);
   static QWidget* createFormWidget(const QDomElement&, QWidget *parent = NULL);
   static ButtonEdit* createButtonEdit(const QDomElement&, QWidget *parent = NULL);
   static DateEdit* createDateEdit(const QDomElement&, QWidget *parent = NULL);
   static TextEdit* createTextEdit(const QDomElement&, QWidget *parent = NULL);
   static WebView* createWebView(const QDomElement&, QWidget *parent = NULL);
   static ComboBox* createComboBox(const QDomElement&, QWidget *parent = NULL);
   static CheckBox* createCheckBox(const QDomElement&, QWidget *parent = NULL);
   static ProgressBar* createProgressBar(const QDomElement&, QWidget *parent = NULL);
   static void setValidator(QWidget*);
   static bool isFieldWidget(QObject*); //returns true if the Widget is a Field Element (Edit, ButtonEdit)
   static bool isFieldWidget(QObject*, QString); // returns true if the Widget is a Field Element
                                                 // and has the given Name
   static void setFieldText(QObject*, QString);
   static QString fieldText(QObject*);

   static void setDefaultFieldText(QObject*);
   static QString defaultFieldText(QObject*);

   static void copy(QObject*);
   static void cut(QObject*);
   static void paste(QObject*);
};

#endif
