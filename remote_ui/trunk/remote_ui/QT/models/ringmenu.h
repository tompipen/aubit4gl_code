//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : ringmenu.h
// Description  : contains class definition for the RingMenu
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
#ifndef RINGMENU_H
#define RINGMENU_H

#include <QGroupBox>
#include <QButtonGroup>
#include <QPushButton>
#include <QLayout>

class RingMenu : public QGroupBox
{
   Q_OBJECT

   enum ButtonHideStyle { hidden, disabled };

   Q_PROPERTY(QString menuStyle
              READ getMenuStyle
              WRITE setMenuStyle
              DESIGNABLE true)

   Q_PROPERTY(QString hideButtons
              READ getHideButtons
              WRITE setHideButtons
              DESIGNABLE true)


public:
   RingMenu(QWidget *parent = 0);
   RingMenu(QString title, QWidget *fglform, QString style = "", QWidget *parent = 0);


   QPushButton* createButton(int id = 0, QString text = "", QString desc = "");
   void hideButton(int);
   void hideButton(QString);
   void showButton(QString);
   void selectButton(QString);
   void setFocusName (QString);
   QString getFocusName() const { return focusName; };
   QList<QPushButton*> buttons();
   int buttonId(QPushButton* button){ return buttonGroup->id(button); };
   void createAction(int id = 0, QString text = "");

   QString getMenuStyle() const { return m_menuStyle; };
   void setMenuStyle(const QString &ms);
   QString getHideButtons() const { return m_hideButtons; };
   void setHideButtons(const QString &ms);
   void setOrientation(const Qt::Orientation &o);
   QList<QAction*> actions();
   QAction* getAction(QString);
   bool isActionButton(QPushButton*);
   bool eventFilter(QObject *obj, QEvent *event);
   QString nextOptionName;


private:
   QLayout* layout;
   QButtonGroup *buttonGroup;
   QString m_menuStyle;
   QString m_hideButtons;
   bool b_hideButtons;
   QList<QAction*> ql_menuCommands;
   QList<QAction*> ql_menuActions;
   QWidget *ql_fglform;
   QString focusName;

protected:
   void resizeEvent(QResizeEvent *);
   void focusInEvent(QFocusEvent*);
   void keyPressEvent(QKeyEvent*);


signals:
   void menuButtonPressed(QString);

private slots:
   void buttonClicked(int);
};
#endif
