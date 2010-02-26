//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : screenhandler.h
// Description  : contains the screenhandler class definition
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
#ifndef SCREENHANDLER_H
#define SCREENHANDLER_H

#include <QObject>
#include <QTcpSocket>
#include <QDomDocument>

#include <models/fglform.h>
#include <models/ringmenu.h>
#include <models/actionmenu.h>
#include <models/toolbar.h>
#include <models/dialog.h>
#include <models/prompt.h>

class ScreenHandler : public QObject
{
   Q_OBJECT

public:

   ScreenHandler(QTcpSocket *parent = 0);
   ~ScreenHandler();
   //void handleXMLForm(const QDomDocument&);
   int getCurrForm();
   int getCurrWindow();
   FglForm* currForm();

   QList<QSize*> ql_formSizes;
   QList<FglForm*> ql_fglForms;
   QStringList qsl_activeFieldNames;

   bool b_menuEnabled;
   //QStringList qsl_arrayValues;
   //
   void setInputFields(QStringList);
   Prompt *p_prompt;
   Context* getContext(int);
   Context* getCurrentContext();
   void freeContext(int);

   QHash<QString, QString> qh_env;
   void setSearchPaths();
   void setEnv(QString, QString);
   void setInterfaceText(QString);

protected:
   bool eventFilter(QObject *obj, QEvent *ev);

private:
   QList<Context*> contexts;
   bool cursorPos;
   QString qs_interfaceTitle;

   FglForm *p_fglform;
//   QList<QWidget*> ql_formFields;
   QHash<QString, QLayout* > qh_fglLayouts;
   QHash<QString, QString > qh_formFiles;
   QHash<int, QList<QWidget*> > qh_formFields;
   QHash<int, ActionMenu*> qh_formActionMenus;
   //QWidget *startMenu;
   QDomDocument startMenu;
//   ToolBar* formsToolBar;
   QDomDocument formsToolBar;
   QDomDocument formsActions;
   QDomDocument formsStyles;
   int cnt_form;

   void createDialog(QString, QString, QString, QString);
   void createDialogButton(int, QString, QString);
   void createDialogAction(int, QString);
   void checkFields();
   bool b_newForm;


   QWidget *p_screenRecord;
   void initForm(int);

   QString clearEventsForField;

   bool clearFieldEvents;

public slots:
   void createWindow(QString, QString = "", int=0, int=0, int = 0, int = 0, QString = "");
   void createPrompt(QString, int, QString);
   void handleAubitForm(QString, QString, bool);
   void handleXMLForm(QString, QString, bool);
   void displayForm(QString);
   void handleXMLToolBar(QString);
   void handleXMLStartMenu(QString);
   void handleXMLActions(QString);
   void handleXMLStyles(QString);
   //void setFieldBuffer(QString, QString);
   void setFieldBuffer(int, QString);
   void clearFieldBuffer(QString);
   //void setFieldBuffer(QString, QStringList);
   void setFieldBuffer(QStringList, QStringList);
   void setArrayBuffer(QWidget*, QString, QString);
   void setArrayBuffer(int, QString, QStringList);
   void setArrayBuffer(int, QStringList);
   void loadArrayValues(QStringList, QStringList);
   void loadArrayValues(QStringList);
   void setArrLine(int);
   void setScrLine(int);
   void setFieldEnabled(QString, bool, bool);
   void setFieldFocus(QString);
   void setFieldHidden(QString, bool);
   void setElementHidden(QString, bool);
   void setArrayFocus(QWidget*, QString);
   void createMenu(QString, QString, QString, QString);
   void createMenuButton(int, QString, QString, QStringList);
   void createMenuAction(int, QString);
   void setMenuEnabled(bool);
   void setScreenRecordEnabled(QString, bool, bool);
   void createActionMenu();
   void createActionMenuButton(QString, QString);
   void setKeyLabel(QString, QString);
   void waitForEvent();
   void processResponse();
   void hideOption(QString);
   void showOption(QString);
   void nextOption(QString);
   void free(QString);
   void MsgBox(QString,QString,QString,QString,QString,int);
   void closeWindow(QString);
   void activeWindow(QString);
   void setFormOpts(QString, bool,int);
   void setFormOpts(QString, QString, int);
   void setEvent(QString, QString, int);
   void clearEvents();
   void displayError(QString);
   void displayMessage(QString);
   void setWindowTitle(QString);
   void sendDirect(QString);
   void setFieldOrder(QStringList);
   void setCursorPosition(int);

   void setClearEvents();
   void fileBrowser(QString, QString, QString, QString, QString);

   void setUpdatesEnabled(bool);

signals:
   void fglFormResponse(QString);
};

#endif
