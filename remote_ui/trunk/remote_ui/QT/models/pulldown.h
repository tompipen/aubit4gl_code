//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : Pulldown.h
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
#ifndef Pulldown_H
#define Pulldown_H

#include <QMenu>
#include <QGroupBox>
#include <QLayout>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

class RingMenuPulldown : public QWidget
{
    Q_OBJECT

public:
    RingMenuPulldown(QString, QString, QString, QString, QWidget* parent = 0);
    RingMenuPulldown(QWidget* parent = 0);
    void createButton(int id, QString text, QString tooltip);
    void createAction(int id = 0, QString text = "");
    QList<QAction*> actions();
    QAction* getAction(QString);
    QButtonGroup* getButtons() { return buttonGroup;};
    void showWindow();
    void closeWindow();
    void hideButton(QString);
    void showButton(QString name);
    bool eventFilter(QObject *, QEvent *);
    void moveToPos(const QPoint pos);
    void closeEvent(QCloseEvent *);

    void setFocusOnButton();
public slots:
    void closeWindowAndTrigger();

private:
    QButtonGroup *buttonGroup;
    QLayout *layout;
    bool b_hideButtons;
    QList<QPushButton*> ql_buttons;
    int closeWindowInt;

};

class Pulldown : public QMenu
{
   Q_OBJECT

public:
   Pulldown(QString, QString, QString, QString, QWidget* parent = 0);
   Pulldown(QWidget* parent = 0);
   

   void createAction(int id = 0, QString text = "", QString icon = "");
   void hideAction(QString);
   void showAction(QString);
   QList<QAction*> actions();
   QAction* getAction(QString);
   void refresh();
   void hideEvent(QHideEvent *);

private:
   QLayout* layout;
   QList<QAction*> ql_actions;
   QLayout* buttonLayout;
   QButtonGroup *buttonGroup;

protected:
   void keyPressEvent(QKeyEvent *event);

signals:
   void PulldownActionPressed(QString);
   void closeEvent();

public slots:
   void actionClicked(int);
};
#endif
