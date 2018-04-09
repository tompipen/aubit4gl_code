//--------------------------------------------------------- (C) VENTAS AG 2009 -
// Project      : VENTAS Desktop Client for A4gl
// Filename     : xml2style.h
// Description  : contains the xml2style class definition
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
#include "xml2style.h"
#include "mainframe.h"


//------------------------------------------------------------------------------
// Method       : XML2Style()
// Filename     : xml2style.cpp
// Description  : constructor for the instances
//------------------------------------------------------------------------------

XML2Style::XML2Style() : QWidget()
{
MainFrame::vdcdebug("XML2Style","XML2Style", "FglForm *p_currForm");


}


//------------------------------------------------------------------------------
// Method       : ~XML2Style()
// Filename     : xml2style.cpp
// Description  : destructor for the instances
//------------------------------------------------------------------------------

XML2Style::~XML2Style(){
}


//------------------------------------------------------------------------------
// Method       : outputTree()
// Filename     : xml2style.cpp
// Description  : prepares the xml for a form and provide its layout
//                - makes recursion 
//------------------------------------------------------------------------------

void XML2Style::outputTree(const QDomNode& domNode)
{
MainFrame::vdcdebug("XML2Style","outputTree", "const QDomNode& domNode");
   QDomNodeList children = domNode.childNodes();

   // checking domNodes childNodes for relevant form elements
   // and handle their attributes
   //
   
   QString styleName;
   QString styleSheet;

//   bool dummy = false;
   for(int i=0; i<children.count(); ++i){

      QDomNode child = children.at(i);

      if(child.isElement()){
         QDomElement childElement = child.toElement();

         if(childElement.nodeName() == "Style"){
            qs_styleName = childElement.attribute("name");
            qs_styleName.replace("Window", "FglForm");

            int index = qs_styleName.indexOf(".");
            if(index > 0){
               QString tmp = qs_styleName.mid(index+1, qs_styleName.length()-index-1);
               QString name = qs_styleName.mid(0, index);
               qs_styleName = QString("%1[style=\"%2\"]").arg(name, tmp);
            }

         }

         if(childElement.nodeName() == "StyleAttribute"){
            bool quote = false;
            QString qs_name = childElement.attribute("name");
            QString qs_value = childElement.attribute("value");

            qs_name.replace("Window", "FglForm");

            //windowstyle attributes
            if(qs_name == "windowType" ||
               qs_name == "windowState" ||
               qs_name == "windowOptionClose" ||
               qs_name == "windowOptionMinimize" ||
               qs_name == "windowOptionMaximize" ||
               qs_name == "windowSystemMenu" ||
               qs_name == "sizable" ||
               qs_name == "forceDefaultSettings" ||
               qs_name == "actionPanelPosition" ||
               qs_name == "actionPanelButtonSize" ||
               qs_name == "actionPanelButtonSpace" ||
               qs_name == "actionPanelDecoration" ||
               qs_name == "actionPanelScroll" ||
               qs_name == "actionPanelScrollStep" ||
               qs_name == "actionPanelHAlign" ||
               qs_name == "ringMenuPosition" ||
               qs_name == "ringMenuButtonSize" ||
               qs_name == "ringMenuButtonSpace" ||
               qs_name == "ringMenuDecoration" ||
               qs_name == "ringMenuScroll" ||
               qs_name == "ringMenuScrollStep" ||
               qs_name == "ringMenuHAlign" ||
               qs_name == "toolBarPosition" ||
               qs_name == "commentPosition" ||
               qs_name == "messagePosition" ||
               qs_name == "errorMessagePosition" ||
               qs_name == "statusBarType" ||
               qs_name == "hideButtons"){  
        
               qs_name.prepend("qproperty-");
               quote = true;
            }

            //startmenustyle attributes
            if(qs_name == "startMenuPosition" ||
               qs_name == "startMenuSize" ||
               qs_name == "startMenuShortcut" ||
               qs_name == "startMenuAccelerator" ||
               qs_name == "startMenuExecShortcut2"){
               qs_name.prepend("qproperty-");
               quote = true;
            }
            
            //tablestyle attributes
            if(qs_name == "forceDefaultSettings" ||
               qs_name == "highlightColor" ||
               qs_name == "highlightTextColor" ||
               qs_name == "highlightCurrentRow" ||
               qs_name == "highlightCurrentCell" ||
               qs_name == "showGrid" ||
               qs_name == "headerHidden" ||
               qs_name == "resizeFillsEmptySpace" ||
               qs_name == "scrollTracking" ||
               qs_name == "tableType"){
               qs_name.prepend("qproperty-");
               quote = true;
            }

            if(qs_name == "fontSize"){
               qs_name = "font-size";
               qs_value.append("px");
            }

            if(qs_name == "fontFamily"){
               qs_name = "font-family";
            }

            if(qs_name == "row-min-height"){
                VDC::setTableViewRowHeight(qs_value.toInt());
            }

            if(quote){
               qs_styleSheet.append(QString("%1 { %2: \"%3\" } \n").arg(qs_styleName, qs_name, qs_value));
            }
            else{
               qs_styleSheet.append(QString("%1 { %2: %3 } \n").arg(qs_styleName, qs_name, qs_value));
            }
         }

         outputTree(childElement);
      }
   }
}


//------------------------------------------------------------------------------
// Method       : readXML()
// Filename     : xml2style.cpp
// Description  : reads the xml file for further operations 
//------------------------------------------------------------------------------

int XML2Style::readXML(const QDomDocument& doc)
{
MainFrame::vdcdebug("XML2Style","readXML", "const QDomDocument& doc");


   // first call of outputTree
   //
   outputTree(doc);
  
   return 1;
}
