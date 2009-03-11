//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : statusbar.cpp
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
#include <QDebug>
#include <QResizeEvent>
#include <QTimer>

#include "statusbar.h"

StatusBar::StatusBar(QWidget *parent) : QStatusBar(parent)
{
   setObjectName("StatusBar");
   setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));

   b_overwrite = false;

   //init Labels
   commentLabel = new QLabel;
   messageLabel = new QLabel;
   errorLabel = new QLabel;

   writeModeLabel = new QLabel("OVR");
   writeModeLabel->setEnabled(b_overwrite);

   addWidget(commentLabel, 10);
   addWidget(errorLabel, 10);

   addPermanentWidget(writeModeLabel);
}


void StatusBar::displayComment(QString text)
{
   commentLabel->setText(text);
   QTimer::singleShot(5000, commentLabel, SLOT(clear()));
}

void StatusBar::displayMessage(QString text)
{
   errorLabel->setText(text);
   QTimer::singleShot(5000, errorLabel, SLOT(clear()));
}

void StatusBar::displayError(QString text)
{
   errorLabel->setText(text);
   QTimer::singleShot(5000, errorLabel, SLOT(clear()));
}

void StatusBar::toggleOverwriteMode()
{
   b_overwrite = !b_overwrite;
   writeModeLabel->setEnabled(b_overwrite);
}
