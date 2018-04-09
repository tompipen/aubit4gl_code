//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : dialog.h
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
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLayout>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>

class Dialog : public QDialog
{
   Q_OBJECT

public:
   Dialog(QString, QString, QString, QString, QWidget* parent = 0, Qt::WindowFlags f=0, bool vdc = false);
   Dialog(QWidget* parent = 0, Qt::WindowFlags f=0);
   
   void createButton(int id = 0, QString text = "", QString desc = "", QString icon = "");
   void createAction(int id = 0, QString text = "");
   void hideButton(QString);
   void showButton(QString);
   void closeEvent(QCloseEvent *event);
   void setText(QString);
   QList<QAction*> actions();
   QAction* getAction(QString);
   QButtonGroup* getButtons() { return buttonGroup; }

   bool b_allowCloseDialog;

   void setVentasStyle();

   void setFocusOnButton();


private:
   QLayout* buttonLayout;
   QLayout* layout;
   QButtonGroup *buttonGroup;
   QLabel *mLabel;

protected:
   //void keyPressEvent(QKeyEvent *event);
   bool eventFilter(QObject *, QEvent *);
   void keyPressEvent(QKeyEvent*);

signals:
   void dialogButtonPressed(QString);

public slots:
   void buttonClicked(int);
};
#endif
