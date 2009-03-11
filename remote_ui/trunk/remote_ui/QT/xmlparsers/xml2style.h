//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : xml2menu.h
// Description  : contains the xml2menu class definition
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
#ifndef XML2STYLE_H
#define XML2STYLE_H

#include <QObject>
#include <QDomDocument>
#include <QDomNodeList>
#include <QWidget>
#include <QDebug>
#include "../models/fglform.h"

class XML2Style : public QWidget
{
   Q_OBJECT

public:
   XML2Style(FglForm*);
   ~XML2Style();

   int readXML(const QDomDocument&);
   QStringList qsl_styleSheets;
   QString getStyleSheet(){ return qs_styleSheet; };

private:
   void outputTree(const QDomNode&);
   QString qs_styleName;
   QString qs_styleSheet;
   FglForm *p_currForm;
};


#endif

