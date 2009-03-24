/*
 *  Copyright (c) 2008 The Aubit Development Team. 
 *  All rights reserved. See CREDITS file.
 *  
 *  
 *  This file is part of Aubit 4gl.
 *
 *  Aubit 4gl is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as 
 *  published by the Free Software Foundation.
 *
 *  Aubit 4gl is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Aubit 4gl.  If not, see <http://www.gnu.org/licenses/>.
 */

package org.aubit4gl.remote_client.swing_ui.widget;

import javax.swing.JLabel;

import org.aubit4gl.remote_client.connection.command.DisplayAt;

/**
 * User interface representation of a display AT command.
 * TODO : The Display at should have attributes
 * 
 * @author Sérgio Ferreira
 */
public class DisplayAtUI extends JLabel {
	
	public DisplayAtUI(DisplayAt dsp) {
		super(dsp.getText());
	}
	
	/*
    LinedLabel linedlabel = new LinedLabel();
    linedlabel.setScale(getScale().width);
    java.awt.geom.Point2D.Double double1 = new java.awt.geom.Point2D.Double(d, d1);
    java.awt.geom.Point2D.Double double2 = new java.awt.geom.Point2D.Double(s.length(), 1.0D);
    MyComponent mycomponent = new MyComponent(nameString(s), linedlabel, true, true, double1, double2);
    linedlabel.setIsDisplayAt(true);
    mycomponent.setColor(s1);
    linedlabel.setOpaque(false);
    linedlabel.setText(s);
    add(mycomponent);
    */
}
