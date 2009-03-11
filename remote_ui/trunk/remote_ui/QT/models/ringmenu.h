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

   Q_PROPERTY(QString menuStyle
              READ getMenuStyle
              WRITE setMenuStyle
              DESIGNABLE true)


public:
   RingMenu(QWidget *parent = 0);
   RingMenu(QString title, QString style = "", QString image = "", QWidget *parent = 0);


   void createButton(int id = 0, QString text = "", QString desc = "");
   void hideButton(int);
   void hideButton(QString);
   void showButton(QString);
   void selectButton(QString);
   QList<QPushButton*> buttons();
   int buttonId(QPushButton* button){ return buttonGroup->id(button); };
   void createAction(int id = 0, QString text = "");

   QString getMenuStyle() const { return m_menuStyle; };
   void setMenuStyle(const QString &ms);
   void setOrientation(const Qt::Orientation &o);


private:
   QLayout* layout;
   QButtonGroup *buttonGroup;
   QString m_menuStyle;

protected:
   void resizeEvent(QResizeEvent *);
   bool eventFilter(QObject *obj, QEvent *event);
   void focusInEvent(QFocusEvent*);

signals:
   void menuButtonPressed(QString);

private slots:
   void buttonClicked(int);
};
#endif
