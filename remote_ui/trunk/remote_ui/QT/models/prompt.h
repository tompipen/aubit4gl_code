//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : prompt.h
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
#ifndef PROMPT_H
#define PROMPT_H

#include <QDialog>
#include <QLayout>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include "models/vwidgets.h"
class Prompt : public QDialog
{
   Q_OBJECT

public:
   Prompt(QWidget* parent = 0, Qt::WindowFlags f=0);
   Prompt(QString, int, int, QWidget* parent = 0, Qt::WindowFlags f=0);
   
private:
   QLayout* layout;
   QLayout* buttonLayout;
   LineEdit *p_lineEdit;
   bool isAccepted;
   bool isCharOnlyMode;

protected:
   void keyPressEvent(QKeyEvent *event);
   void closeEvent(QCloseEvent *event);

signals:
   void sendDirect(QString);

private slots:
   void promptLineEditTextChanged(const QString &text);

};
#endif
