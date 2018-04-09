//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : statusbar.h
// Description  : contains class definition for the StatusBar
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
#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QObject>
#include <QStatusBar>
#include <QLabel>
#include <QKeyEvent>

class StatusBar : public QStatusBar
{
   Q_OBJECT

public:
   StatusBar(QWidget *parent = 0);
   void displayComment(QString);
   void displayMessage(QString);
   void displayError(QString);
   void toggleOverwriteMode();
   bool b_overwrite;

public slots:
   void clearStylesheet();

private:
   QLabel *commentLabel;
   QLabel *messageLabel;
   QLabel *errorLabel;
   QLabel *writeModeLabel;

   QTimer *m_timer;



};
#endif
