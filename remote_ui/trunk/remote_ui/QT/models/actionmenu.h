//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : actionmenu.h
// Description  : contains class definition for the ActionMenu
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
#ifndef ACTIONMENU_H
#define ACTIONMENU_H

#include <QGroupBox>
#include <QButtonGroup>
#include <QPushButton>
#include <QLayout>
#include <QHash>

class ActionMenu : public QGroupBox
{
   Q_OBJECT

public:
   ActionMenu(QString title = "", QString style = "", QWidget *parent = 0);

   void createButton(QString id = "", QString text = "", QString desc = "", QAction* action=NULL);
   void setAction(QString, QAction*);
   void hideButton(QString);
   QList<QPushButton*> buttons();
   void setOrientation(const Qt::Orientation &o);
   void removeButton(QString);
   void removeButtons();
   void hideButtons(bool);
   /*
   void restoreButtonPalette();
   void setButtonPalette();
   void setPaletteForButton(QPushButton*);
   */
   QList<QAction*> actions();
   QAction* getAction(QString);
   /*
   void setIconForButton(QPushButton*);
   void restoreButtonIcon();
   void setButtonIcons();
*/
private:
   QHash<QString, QPalette> qh_buttonpals;
   QHash<QString, QIcon> qh_buttonicon;
   QLayout* layout;
   QButtonGroup *buttonGroup;
   /*
   bool b_disabledp;
   bool b_disabledi;
*/
protected:
   void resizeEvent(QResizeEvent *);
   void keyPressEvent(QKeyEvent *event);

signals:
   void menuButtonPressed(QString);

private slots:
   void buttonClicked(int);
   void buttonClicked(QAbstractButton*);

};
#endif
