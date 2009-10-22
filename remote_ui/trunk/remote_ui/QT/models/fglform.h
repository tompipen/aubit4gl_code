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

#include "vwidgets.h"
#include "ringmenu.h"
#include "actionmenu.h"
#include "actions.h"
#include "toolbar.h"
#include "dialog.h"
#include "table.h"
#include <include/fgl.h>
#include <context.h>

class FglForm : public QMainWindow
{
   Q_OBJECT

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
   FglForm(QString windowName = "", QWidget *parent=0);
   ~FglForm();
   QString windowName;
   bool b_getch_swin;
   bool b_allowClose;
   QList<QString> ql_responseQueue;
   void setMenuEnabled(bool);
   void setMenu(RingMenu*);
   void removeMenu();
   RingMenu* menu(){ if(ql_menus.count() > 0) return ql_menus.last(); else return NULL; };
   void setActionMenuEnabled(bool);
   void setActionMenu(ActionMenu*);
   ActionMenu* actionMenu(){ return p_actionMenu; };
   void setDialog(Dialog*);
   Dialog* dialog(){ return p_dialog; };
   void setToolBar(ToolBar*);
   void setToolBar(QDomDocument);
   void checkToolBar();
   void checkMenu();
   void checkActions();
   ToolBar* toolBar(){ return p_toolBar; };
   Qt::ToolBarArea toolBarPosition();
   void setActions(QDomDocument);
   QList<QAction*> actions(){ return ql_formActions; };
   QList<QAction*> defActions(){ return ql_defaultActions; };
   void focusNextField() { this->focusNextChild(); };
   QWidget* currentField() { return currentWidget; };
   void setCurrentField(QWidget* widget = NULL) { widget->setFocus(); currentWidget = widget; };

   bool input() { return (ql_states.last() == Fgl::INPUT); };
   bool construct() { return (ql_states.last() == Fgl::CONSTRUCT); };
   bool screenRecord() { return (ql_states.last() == Fgl::DISPLAYARRAY || ql_states.last() == Fgl::INPUTARRAY); };
   bool displayArray() { return (ql_states.last() == Fgl::DISPLAYARRAY); };
   bool inputArray() { return (ql_states.last() == Fgl::INPUTARRAY); };

   void enableActions(bool);
   /*
   void setConstructEnabled(bool enable ) { b_construct = enable; };
   bool construct() { return b_construct; };
   */
   QStringList qsl_fieldOrder;

   //QDomDocument *recordView;
   QHash<QString, QList<Fgl::Link> > recordView;
   
   void initActions();

   bool b_denyFocus;

   //TableView *p_screenRecord;
   
   void setFormLayout(const QDomDocument&);
   void setStyles(const QDomDocument&);

   QList<Fgl::Event> ql_formEvents;
   QList<QWidget*> ql_formFields;

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

   void setState(Fgl::State state) { ql_states << state; } ;
   void revertState(Fgl::State);
   Fgl::State state() { return ql_states.last(); };
   void checkState();

   QList<QWidget*> formElements();

   Context *context;

   QWidget* findFieldByName(QString);
   QList<QWidget*> findFieldsByName(QString);
   void setId(QString id) { i_id = id.toInt(); };
   int id() { return i_id; };


public slots:
   void buttonClicked(QString);
   void fieldEvent(Fgl::Event, QWidget* = NULL);

   //action defaults
   void cancelTriggered();
   void acceptTriggered();

   void accept();
   void interrupt();

   void editcopy();
   void editcut();
   void editpaste();
   void nextfield();
   void prevfield();
   void nextrow();
   void prevrow();
   void firstrow();
   void lastrow();
   void nextpage();
   void prevpage();
   void nexttab();
   void prevtab();

   void validateFields();

   void clearCurrentFocus();

   //void interrupt();

   //XML Menu
   void sendMenuCommand(QString);

   //void setStartMenu(XML2Menu* menu);
   void setStartMenu(const QDomDocument &doc);
   void createContextMenu(const QPoint&);
   void setScreenRecordArrLine(int);
   void error(const QString&);


private:
   QList<Fgl::State> ql_states;
   QWidget *formWidget;
   QWidget *currentWidget;
   QList<RingMenu*> ql_menus;
   ActionMenu *p_actionMenu;
   Dialog *p_dialog;
   ToolBar *p_toolBar;
   QList<QAction*> ql_formActions;
   QList<QAction*> ql_defaultActions;
   void addToQueue(QString);
   void createStatusBar();
   void writeSettingsLocal();
   void readSettingsLocal();

   bool b_menu;
   bool b_input;
   bool b_screenRecord;
   //bool b_construct;

   //PROPERTIES
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

private slots:
   void actionTriggered();
   void toolBarActionTriggered();

signals:
   void processResponse();
   void sendDirect(QString);
   void accepted();
   void setClearEvents();
   void setArrLine(int);

protected:
   bool eventFilter(QObject *obj, QEvent *event);
   void closeEvent(QCloseEvent *event);
   void contextMenuEvent(QContextMenuEvent*);
};

#endif
