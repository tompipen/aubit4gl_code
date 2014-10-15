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
#include <QDomDocument>

class FglForm;
//#include <models/fglform.h>
#include <context.h>
#include <models/ringmenu.h>
#include <models/actionmenu.h>
#include <models/toolbar.h>
#include <models/dialog.h>
#include <models/prompt.h>
#include <include/vdc.h>
#ifdef KDChart_Version
#include "models/charts/chartInterface.h"
#include "models/charts/chartTableModel.h"
#include "models/charts/ganttTable.h"
#include "models/charts/ganttnode.h"
#include "models/charts/ganttWidget.h"
#endif
#include "models/webbrowser.h"
#include "models/progress.h"
#include "models/texteditor.h"
#include "tools/htmleditor.h"
class ProtocolHandler;
#include <QVector>
#include <QVariant>
//#include <poppler/qt4/poppler-qt4.h>

class ScreenHandler : public QObject
{
   Q_OBJECT

public:
   static int cnt_screenhandler;
   ScreenHandler(QObject *parent = 0);
   ~ScreenHandler();
   //void handleXMLForm(const QDomDocument&);
   int getCurrForm();
   int getCurrWindow();
   bool b_runinfo;
   QString cmd;
   int i_mode;
   FglForm* currForm();
   int pid;
   QString programm_name;
   int p_pid;
   QString programm_name_run;
   int p_pid_p;
   QList<QSize*> ql_formSizes;
   QList<FglForm*> ql_fglForms;
   QList<WebBrowser*> ql_browser;
   TextEditorWidget *mTextEditor;
   HtmlEditor *mHtmlEditor;
   QStringList qsl_activeFieldNames;
   QStringList qsl_triggereds;
   QDomDocument xmlIconDocDe;
   QDomDocument xmlIconDocEn;
   QDomDocument xmlIconDocSp;
   QDomDocument xmlIconDocFr;
   QDomDocument xmlShortcutDoc;
   int openFileSuccess;
   void executeFile(int, QString);
   ProtocolHandler *ph;
   void makeFglFormResponse(QString);

   #ifdef KDChart_Version
   QList<GanttWidget*> ql_ganttWidget;
   #endif

   bool b_menuEnabled;
   //QStringList qsl_arrayValues;
   //
   void setInputFields(QStringList);
   Prompt *p_prompt;
   Context* getContext(int);
   Context* getCurrentContext();
   QList<Context*> getContexts(){ return contexts; }
   void freeContext(int);

   QHash<QString, QString> qh_env;
   static void setSearchPaths();
   //void setInterfaceText(QString);
   int stdOfficeProg;


      FglForm *p_fglform;
   typedef QVector<QVariant> chartVector;

      void closeAllWindows();
protected:
   bool eventFilter(QObject *obj, QEvent *ev);

private:

   Dialog *mDummyMessageDialogBox;
   QComboBox *mOfficeComboBox;
   #ifdef KDChart_Version
   ChartInterface *m_chart;
   ChartTableModel m_model;
   KDChart::PieDiagram* m_pie;
   KDChart::BarDiagram* m_bar;
   #endif
   QTimer *timer;
   QList<Context*> contexts;
   bool cursorPos;
   QString qs_interfaceTitle;
   FglForm *dummy_fglform;
   Progress *w_progress;
   int i_runcnt;
   int i_currthread;
   int hasWindow;
   QTimer *protocolTimer;
   QString lastProtocolCmd;
   int protocolCnt;


//   QList<QWidget*> ql_formFields;
   QHash<QString, QLayout* > qh_fglLayouts;
   QHash<QString, QString > qh_formFiles;
   QHash<int, QList<QWidget*> > qh_formFields;
   QHash<QString, QString> qh_formcolors;

   QHash<int, ActionMenu*> qh_formActionMenus;
   //QWidget *startMenu;
   QDomDocument startMenu;
//   ToolBar* formsToolBar;
   QDomDocument formsToolBar;
   QDomDocument formsActions;
   QDomDocument formsActions1;
   QDomDocument formsActions2;
   QDomDocument formsStyles;
   QDomDocument formsColors;
   int cnt_form;

   void createDialog(QString, QString, QString, QString);
   void createDialogButton(int, QString, QString);
   void createPulldown(QString, QString, QString, QString);
   void createPulldownButton(int, QString, QString);
   void createDialogAction(int, QString);
   void checkFields();
   void checkColors();
   bool b_newForm;

   QWidget *p_screenRecord;
   void initForm(int);

   QString clearEventsForField;

   bool clearFieldEvents;
public slots:

   void checkFglformState();
   void getItemCountComboBox(int);

   void setEnv(QString, QString);
   void closeErrorDialog();
   void saveOfficeInstallation();
   void createStdProgWindow();
   void setOptions(QString, QString);
   void createWindow(QString, QString = "", int=0, int=0, int = 0, int = 0, QString = "",QString = "");
   void createPrompt(QString, int, int, QString);
   void handleAubitForm(QString, QString, bool);
   void handleXMLForm(QString, QString, bool);
   void displayForm(QString);
   void handleXMLToolBar(QString);
   void handleXMLStartMenu(QString); 
   void activeFocus();
   void handleXMLActions(QString);
   void handleXMLColors(QString xmlFile);
   void handleShortcutsFile(QDomDocument xmlFileString);
   //void setEnv(QString, QString);
   void handleIconFile(QDomDocument);
   void setProgramName(QString);
   #ifdef KDChart_Version
   void createChart(QString);
   void addChartValue(QString, QString);
   void addChartValue(const chartVector &name, const chartVector &wert);
   void displayChart(QString, int);
   void createGantt();
   void setTitle(int, const QString);
   void readCsv(int, QString);
   void openChartWindow(QString);
   #endif
   void openChartWindow(QString, QString);
   void createTextEditor(QString, QString, int);
   void createEditor(QString);
   void createBrowser();
   void setUrl(int id, const QUrl &http);
   void closeBrowser(int id);
   void handleXMLStyles(QString);
   //void setFieldBuffer(QString, QString);
   void setFieldBuffer(int, QString, int);
   void clearFieldBuffer(QString);
   //void setFieldBuffer(QString, QStringList);
   void setFieldBuffer(QStringList, QStringList, int);
   //void setArrayBuffer(QWidget*, QString, QString);
   void setArrayBuffer(int, QString, QStringList);
   void setArrayBuffer(int, QStringList);
   void loadArrayValues(QStringList, QStringList);
   void loadArrayValues(QStringList);
   void setArrLine(int);
   void setScrLine(int);
   void setFieldEnabled(QString, bool, bool, int = 0);
   void setFieldFocus(QString);
   void setNewTabName(QString, QString);
   void setAttributes(QString, QString, QString);
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
   void nextOption(QString, int);
   void free(QString);
   void MsgBox(QString,QString,QString,QString,QString,int);
   void closeWindow(QString);
   void activeWindow(QString);
   void setFormOpts(QString, bool,int);
   void setFormOpts(QString, QString, int);
   void setEvent(QString, QString, QString);
   void clearEvents();
   void displayError(QString);
   void displayMessage(QString);
   void setWindowTitle(QString);
   void sendDirect(QString);
   void setFieldOrder(QStringList);
   void setCursorPosition(int);
   void setRuninfo(int, QString, int, bool);
   void closeProgramm();
   void setClearEvents();
   void fileBrowser(QString, QString, QString, QString, QString);

   void setUpdatesEnabled(bool);
   void setCurrentFocus(QWidget*, QWidget*);
   void checkForUpdate();
   void setInterfaceText(QString);
   //ui.progress

   void setProgressTitle(int, QString);
   void setProgressText(int, QString);
   void setProgressVisible(int, bool);
   void createProgressWindow(int);
   void closeProgressWindow(int obj);
   int isProgressWindowOpen();


   //ui.vdc.printpdf
   void printpdf(QString);


   void fornameComboBox(QString);
   void getColumnNameComboBox(int);

   void clearComboBox(int);
   void addComboBoxItem(int, QString, QString);
   void removeComboBoxItem(int, QString);
   void getItemNameComboBox(int, int);
   void getItemTextComboBox(int, int);
   void getTableNameComboBox(int);
   void getIndexOfComboBox(int, QString);

   void clearDisplayArrayRows(QStringList fieldNames);

   void setClipboard(QString);

   void setWaitCursor();
   void showWindow();

   void startProtocolTimer(QString cmd);
   void stopProtocolTimer(QString);
   void protocolTimeout();
   void resetProtocolCnt();

   void openLocalFile(QString);
   void openEmailWithAttach(QString);
   void openEmail(QString);

   void getFileBrowser(QString, QString);

signals:
   void fglFormResponse(QString);
   void windowCreated();

};

class waitTimer : public QThread
{
    public:
    static void sleep(unsigned long secs)
    {
        QThread::sleep(secs);
    }
    static void msleep(unsigned long msecs)
    {
        QThread::msleep(msecs);
    }
    static void usleep(unsigned long usecs)
    {
        QThread::usleep(usecs);
    }
};

#endif
