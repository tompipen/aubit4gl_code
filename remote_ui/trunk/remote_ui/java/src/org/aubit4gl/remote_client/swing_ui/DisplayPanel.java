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

package org.aubit4gl.remote_client.swing_ui;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

/**
 * Panel for show the text of a display command
 *  
 * @author Sérgio Ferreira
 */
public class DisplayPanel extends JPanel {
	private final JScrollPane displayScrollPane = new JScrollPane();
	private final JTextArea displayTextArea = new JTextArea("", 20, 40);

	public DisplayPanel(String s)
	{
		add(displayScrollPane, "Center");
		displayScrollPane.getViewport().add(displayTextArea);
		displayTextArea.setText("");
	}

	public void display(String s)
	{
		displayTextArea.append(s + "\n");
	}
}

