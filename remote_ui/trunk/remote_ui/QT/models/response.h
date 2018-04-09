//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : response.h
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
#ifndef RESPONSE_H
#define RESPONSE_H

#include <QDomDocument>
#include <QDomNode>
#include <QDomElement>

#include "fglform.h"
#include "matrix.h"

class Response : public QDomDocument
{

public:
   Response(Fgl::Event, FglForm*, bool cursorPos = false);


private:
   bool showCursorPos;
   FglForm* p_currForm;
   QDomElement responseElement;
   void addSyncValues();
   void addScreenRecSyncValues(TableView*);
   void addScreenRecSyncValues(Matrix*);
   void addScreenRecSyncValues(QString);
};

#endif
