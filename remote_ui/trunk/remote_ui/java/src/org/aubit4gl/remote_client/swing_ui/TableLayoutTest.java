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


import java.awt.*;
import javax.swing.*;

import java.util.*;
import info.clearthought.layout.TableLayout;



public class TableLayoutTest
{

	/**
	 * Runs the program.
	 */

	public static void main (String args[])
	{
		// Create frame
		JFrame frame = new JFrame("Local Area Connection - Primary Properties");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(new FlowLayout());



		// Create and set layout
		double p = TableLayout.PREFERRED;

		int lines = 24;
		int columns = 80;
		double rowSize[] = new double[24];
		double columnSize[] = new double[80];
		for (int i = 0 ; i < lines ; i++ ) {
			rowSize[i] = 17.0;
		}
		
		for (int i = 0 ; i < columns ; i++ ) {
			columnSize[i] = 5.0;
		}
		TableLayout layout = new TableLayout(columnSize, rowSize);
		layout.setVGap(2);
		layout.setHGap(5);
		Container container = frame.getContentPane();
		container.setLayout(layout);
		
		frame.pack();
		frame.setVisible(true);
		frame.toFront();
		
		JLabel labelConnect = new JLabel("Connect using:");
		int dim = labelConnect.getText().length() + 5;
		container.add(labelConnect, "5, 2, " + dim+ ", 2");
		
		JToolBar tb = new JToolBar();
		ButtonGroup bg = new ButtonGroup();
		JButton b1 = new JButton("OK");
		b1.setBorderPainted(false);
		b1.setToolTipText("Button one");
		JButton b2 = new JButton("Cancel");
		b2.setBorderPainted(false);
		bg.add(b1);
		bg.add(b2);
		tb.add(b1);
		tb.add(b2);
		tb.setFloatable(false);
		container.add(tb,"1, 1, 10, 1");
	}



}

