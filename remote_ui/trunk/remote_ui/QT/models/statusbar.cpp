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
#include "mainframe.h"

StatusBar::StatusBar(QWidget *parent) : QStatusBar(parent)
{
MainFrame::vdcdebug("StatusBar","StatusBar", "QWidget *parent");
   setObjectName("StatusBar");
   setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));

   b_overwrite = false;

   //init Labels
   commentLabel = new QLabel(this);
   messageLabel = new QLabel(this);
   errorLabel = new QLabel(this);
   m_timer = NULL;

   writeModeLabel = new QLabel("OVR", this);
   writeModeLabel->setEnabled(b_overwrite);

   //addWidget(commentLabel, 10);
   addWidget(errorLabel, 10);


   addPermanentWidget(writeModeLabel);
}


void StatusBar::displayComment(QString text)
{
MainFrame::vdcdebug("StatusBar","displayComment", "QString text");
   QPalette pal = errorLabel->palette();
   pal.setColor(QPalette::Background, QColor("#ffffff"));
   pal.setColor(errorLabel->foregroundRole(), Qt::red);
   errorLabel->setAutoFillBackground(true);
   errorLabel->setText(" " + text);
   QTimer::singleShot(5000, errorLabel, SLOT(clear()));
   QTimer::singleShot(5000, this, SLOT(clearStylesheet()));
}

void StatusBar::displayMessage(QString text)
{
MainFrame::vdcdebug("StatusBar","displayMessage", "QString text");
   QPalette pal = errorLabel->palette();
   pal.setColor(QPalette::Background, QColor("#ffffff"));
   pal.setColor(errorLabel->foregroundRole(), Qt::black);
   errorLabel->setAutoFillBackground(true);
   errorLabel->setPalette(pal);
   errorLabel->setText(" " + text.trimmed());

   if(!m_timer) {
       m_timer = new QTimer(this);
       m_timer->setSingleShot(true);
       connect(m_timer, SIGNAL(timeout()), errorLabel, SLOT(clear()));
       connect(m_timer, SIGNAL(timeout()), this, SLOT(clearStylesheet()));
       m_timer->start(5000);
   }
}

void StatusBar::displayError(QString text)
{
MainFrame::vdcdebug("StatusBar","displayError", "QString text");
   QPalette pal = errorLabel->palette();
   pal.setColor(QPalette::Background, QColor("#ffffff"));
   pal.setColor(errorLabel->foregroundRole(), Qt::red);
   errorLabel->setAutoFillBackground(true);
   errorLabel->setPalette(pal);
   errorLabel->setText(" " + text.trimmed());

   if(!m_timer) {
       m_timer = new QTimer(this);
       m_timer->setSingleShot(true);
       connect(m_timer, SIGNAL(timeout()), errorLabel, SLOT(clear()));
       connect(m_timer, SIGNAL(timeout()), this, SLOT(clearStylesheet()));
       m_timer->start(5000);
   }
}

void StatusBar::clearStylesheet()
{
    errorLabel->setAutoFillBackground(false);
    m_timer = NULL;
}

void StatusBar::toggleOverwriteMode()
{
MainFrame::vdcdebug("StatusBar","toggleOverwriteMode", "");
   b_overwrite = !b_overwrite;
   writeModeLabel->setEnabled(b_overwrite);
}
