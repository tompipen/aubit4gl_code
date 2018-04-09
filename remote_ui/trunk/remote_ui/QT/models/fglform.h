//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : fglform.h
// Description  : contains the fglform class definition
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
#ifndef FGLFORM_H
#define FGLFORM_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QAction>
#include <QDomDocument>
#include <QKeyEvent>
#include <QPointer>
#include <QSplitter>

//class ScreenHandler;
#include "screenhandler.h"
#include "vwidgets.h"
#include "ringmenu.h"
#include "actionmenu.h"
#include "actions.h"
#include "toolbar.h"
#include "pulldown.h"
#include "dialog.h"
#include "table.h"
#include <include/fgl.h>
#include <context.h>
#include <xmlparsers/xml2menu.h>
#include <QPointer>

class FglForm : public QMainWindow
{
   Q_OBJECT;

   Q_PROPERTY(QString windowType
              READ getWindowType
              WRITE setWindowType
              DESIGNABLE true)

   Q_PROPERTY(QString startMenuPosition 
              READ getStartMenuPosition 
              WRITE setStartMenuPosition
              DESIGNABLE true)

   Q_PROPERTY(QString sizable 
              READ sizable
              WRITE setSizable
              DESIGNABLE true)

   Q_PROPERTY(bool defaultStatusBar 
              READ getDefaultStatusBar
              WRITE setDefaultStatusBar
              DESIGNABLE true)

   Q_PROPERTY(QString toolBarPosition
              READ getToolBarPosition
              WRITE setToolBarPosition
              DESIGNABLE true)

   Q_PROPERTY(QString actionPanelPosition
              READ getActionPanelPosition
              WRITE setActionPanelPosition
              DESIGNABLE true)

   Q_PROPERTY(QString ringMenuPosition
              READ getRingMenuPosition
              WRITE setRingMenuPosition
              DESIGNABLE true)

public:

   bool hasTable = false;
   int getWindowWidth() { return widgetWidth; }
   FglForm(QString windowName = "", int posX = 0, int posY = 0, QWidget *parent=0);
   ~FglForm();
//Flag for Response. Only sending the values of the first triggered, rest blanked
   bool b_svs;
   QString windowName;
   QWidget *currentWidget;
   QPointer<QPushButton> nextclick;
   QPointer<XML2Menu> mXmlMenu;
   Actions *ql_actions;
   bool b_getch_swin;
   bool b_layout;
   bool b_allowClose;
   bool b_dummy;
   void jumpToField(QWidget*, bool b_after=true);
   QList<Fgl::Event> getInputEvents(int, int, bool, bool, bool);
   QList<Fgl::Event> ql_responseQueue;
   void setMenuEnabled(bool);
   void setMenu(RingMenu*);
   void removeMenu();
   RingMenu* menu(){ if(ql_menus.count() > 0) return ql_menus.last(); else return NULL; };
   void setActionMenuEnabled(bool);
   void setActionMenu(ActionMenu*);
   ActionMenu* actionMenu(){ if(p_actionMenu != NULL) return p_actionMenu; else return NULL;}
   void setDialog(Dialog*);
   void setPulldown(Pulldown*);
   void setRingMenuPulldown(RingMenuPulldown*);
   Dialog* dialog(){ return p_dialog; };
   Pulldown* pulldown() { return p_pulldown;};
   RingMenuPulldown* ringMenuPulldown() { return p_ringMenuPulldown;};
   void setBrowser(WebBrowser *webBrowser) { b_browser = webBrowser; };
   WebBrowser* getBrowser() { return b_browser; };

   void setConstrained(bool value) { b_constrained = value; }
   void showEvent(QShowEvent *);
   void setToolBar(ToolBar*);
   void setToolBar(QDomDocument);
   void checkToolBar();
   void checkMenu();
   ScreenHandler* screenhandler(){ return p_currscreenhandler.data(); }
   void setScreenHandler(ScreenHandler*);
   void checkActions();
   void checkShortcuts();
   void checkGuiActions();
   bool handleGuiAction(Action*);
   void remove();
   void insert();
   ToolBar* toolBar(){ return p_toolBar; };
   Qt::ToolBarArea toolBarPosition();
   void setActions(QDomDocument);
   QList<Action*> formActions(){ return ql_formActions; };
   QList<Action*> defActions(){ return ql_defaultActions; };
   QList<Action*> actionDefaults(){ return ql_actionDefaults; };
   void addFormAction(QAction*);
   void addFormAction(QString name, QString text="", QString comment="", QString image="", QString accName="", QString accName2="", QString accName3="", QString accName4="", QString defaultView="");
   void addFormEvent(Fgl::Event);
   void focusNextField() { this->focusNextChild(); };
   QWidget* currentField() { return currentWidget; };
   void setCurrentWidget(QWidget*);
   //void setCurrentField(QWidget* widget = NULL) { widget->setFocus(); currentWidget = widget; };
   void setCurrentField(QString, bool sendEvents = true);
   QMenu* createMenuHideShowFields(QObject*);
   QString formName() { return this->qs_formfile; }
   void setFormName(QString);
   void showColorBar(QString);

   bool input() { return (ql_states.last() == Fgl::INPUT); };
   bool construct() { return (ql_states.last() == Fgl::CONSTRUCT); };
   bool screenRecord() { return (ql_states.last() == Fgl::DISPLAYARRAY || ql_states.last() == Fgl::INPUTARRAY); };
   bool displayArray() { return (ql_states.last() == Fgl::DISPLAYARRAY); };
   bool inputArray() { return (ql_states.last() == Fgl::INPUTARRAY); };

   bool bufferTouched() { return b_bufferTouched; };
   int lastCursor() { return i_lastCursor; };
   void changeEvent(QEvent *);

   /*
   void setConstructEnabled(bool enable ) { b_construct = enable; };
   bool construct() { return b_construct; };
   */
   QStringList qsl_fieldOrder;
   //QDomDocument *recordView;
   QHash<QString, QList<Fgl::Link> > recordView;
   
   void initActions();
   bool b_newForm;
   bool b_denyFocus;
   int gridWidth;
   //TableView *p_screenRecord;
   
   void setFormLayout(const QDomDocument&);
   void setStyles(const QDomDocument&);

   QList<Fgl::Event> ql_menuEvents;
   QList<Fgl::Event> ql_dialogEvents;
   QList<Fgl::Event> ql_pulldownEvents;
   QList<Fgl::Event> ql_formEvents;
   QList< QList<Fgl::Event> > ql_contextEvents;
   QList<QWidget*> ql_formFields;
   QList<QWidget*> ql_formFieldsConst;

   // Contains all Fieldnames in the order they get their focus
   QStringList qsl_activeFields;

   QString getStartMenuPosition() const { return m_startMenuPosition; };
   void setStartMenuPosition(const QString &sm) { m_startMenuPosition = sm; };

   QString getToolBarPosition() const { return m_toolBarPosition; };
   void setToolBarPosition(const QString &sm);//{ m_toolBarPosition = sm; };

   QString getWindowType() const { return m_windowType; };
   void setWindowType(const QString &sm);

   QString sizable() const { return m_sizable; };
   void setSizable(const QString &sm);

   bool getDefaultStatusBar() const { return m_defaultStatusBar; };
   void setDefaultStatusBar(const bool &sm);

   QString getActionPanelPosition() const { return m_actionPanelPosition; };
   void setActionPanelPosition(const QString &sm);

   QString getRingMenuPosition() const { return m_ringMenuPosition; };
   void setRingMenuPosition(const QString &sm);

   void setState(Fgl::State state) { ql_states << state;  ql_contextEvents << QList<Fgl::Event>(); } ;
   void revertState(Fgl::State);
   Fgl::State state() { return ql_states.last(); };
   void checkState();

   QSplitter* getSplitter() { return p_splitter; }
//   QHBoxLayout* gethLayout() { return hLayout; }
//   QWidget* getFormWidget() { return formWidget; }
//   QScrollArea* getScroll() { return p_scroll; }

   QList<QWidget*> formElements();

   Context *context;
   QWidget* findFieldByName(QString);
   QList<QWidget*> findFieldsByName(QString);
   int findFieldIdByName(QString);
   QWidget* findFieldById(int);
   void setId(QString id) { i_id = id.toInt(); };
   int id() { return i_id; };

   // enables/disables all user input elements
   void setUserInputEnabled(bool enabled);
   QList<QPair<QString, QString> > ql_shortcuts;

   //PROPERTIES
   int widgetWidth;
   int widgetHeight;
   int widgetPosX;
   int widgetPosY;

   bool mIsSortAllowed;
   QElapsedTimer *keyTimer;
   QTimer *fieldChangeTimer;
   bool isFieldChangeSend;
   int lastKeyPressed;
   void setLogo(QString);

public slots:

   void sendFieldChange();
   void saveScreenshot();
   void printScreenshot();
   void disableForm();
   void buttonClicked(QString);
   void fieldEvent(Fgl::Event, QWidget* = NULL);
   Fgl::Event getFormEvent(Fgl::Event, QWidget* widget = NULL);
   void setBufferTouched() { b_bufferTouched = true; };
   void setLastCursor(int,int);
   void setLastCursor();
   void setBufferNotTouched() { b_bufferTouched = false; };
   bool getConstrained() { return b_constrained; };

   //action defaults
   void cancelTriggered();
   void acceptTriggered();
   void addToQueue(QList<Fgl::Event>);
   void addToQueue(Fgl::Event);

   void accept();
   void interrupt();
   void editcopy();
   void editcut();
   void editpaste();
   QList<QWidget*> getConstrainList();
   void nextfield(bool change=true);
   void prevfield(bool sendEvent = true);
   void nextrow(bool sendEvent = true);
   void prevrow(bool sendEvent = true);
   void firstrow();
   void lastrow();
   void nextpage();
   void prevpage();
   void nexttab();
   void prevtab();
   void exitMenu();
   void reopenPulldown();
   void dropSuccess();
   void dragSuccess();
   void sendactivateinputevent();
   void resetFieldSettings();
   void saveFieldSettings(QAction *);

   void clearCurrentFocus();
   void clearFieldFocus();
   void setFocusOnWidget(QWidget*, Qt::FocusReason = Qt::OtherFocusReason);

   //void interrupt();

   //XML Menu
   void sendMenuCommand(QString);

   //void setStartMenu(XML2Menu* menu);
   void setStartMenu(const QDomDocument &doc);
   void createContextMenu(const QPoint&);
   void setScreenRecordArrLine(int);
   void error(const QString&);
   void setMessageWithIcon(const QString&, const QString&);
   void checkField();
   void writeSettingsLocal();
   void readSettingsLocal();

   void closeMessageWithIcon();



private:

   bool wasMinimized = false;
   QLabel *textLabel;
   QLabel *iconLabel;
   QLabel *m_logoLabel;

   QList<Fgl::State> ql_states;

   QWidget *formWidget;

   QList<RingMenu*> ql_menus;
   QPointer<ScreenHandler> p_currscreenhandler;
   ActionMenu *p_actionMenu;
   Dialog *p_dialog;
   Pulldown *p_pulldown;
   RingMenuPulldown *p_ringMenuPulldown;
   WebBrowser *b_browser;
   ToolBar *p_toolBar;
   QAction *rightAct;
   QAction *resetAct;
   QList<Action*> ql_formActions;
   QList<Action*> ql_defaultActions;
   QList<Action*> ql_actionDefaults;
   QList<FormField*> ql_fglFields;
   void createStatusBar();

   bool b_constrained;
   bool b_menu;
   bool b_input;
   bool b_screenRecord;
   QTimer *saveTimer;

   //bool b_construct;

   QString m_windowType;
   QString m_startMenuPosition;
   QString m_toolBarPosition;
   QString m_ringMenuPosition;
   QString m_actionPanelPosition;
   QString m_sizable;
   bool m_defaultStatusBar;

   QWidget *widget;

   QLabel *insLabel;
   int i_currentField;
   QWidget *fieldsContainer;
   int i_id;
   bool b_bufferTouched;
   int i_lastCursor;
   QString qs_currentFieldBuffer;
   QString qs_formfile;
   QWidget *qw_colorbar;
   QSplitter *p_splitter;
   QHBoxLayout *hLayout;
   QVBoxLayout *hb_lay;
   QScrollArea *p_scroll;

   int gridHeight;
 //  virtual QSize sizeHint() const;


private slots:
   void actionTriggered();
   void toolBarActionTriggered();
   void saveWindowPos();

signals:
   void processResponse();
   void sendDirect(QString);
   void accepted();
   void setClearEvents();
   void setArrLine(int);
   void closeAction();

protected:
   bool eventFilter(QObject *obj, QEvent *event);
   void moveEvent(QMoveEvent *);
   void closeEvent(QCloseEvent *event);
   void contextMenuEvent(QContextMenuEvent*);
   bool focusNextPrevChild(bool);
};

#endif
