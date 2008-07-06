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

/**
 * Example of components spanning cells.
 *
 * @author  Daniel E. Barbalace
 * @version 1.0, June 14, 2005
 */

public class Multicell
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

		// Items to display in list control
		Vector listElement = new Vector();
		listElement.add("Client for Microsoft Networks");
		listElement.add("File and Print Sharing for Microsoft Networks");
		listElement.add("QoS Packet Scheduler");
		listElement.add("Microsoft TCP/IP version 6");
		listElement.add("Internet Protocol (TCP/IP");

		// Create controls
		JLabel labelConnect = new JLabel("Connect using:");
		JTextField textfieldConnect = new JTextField("Intel(R) PRO/100 VE Network Connection");
		JButton buttonConfigure = new JButton("Configure...");
		JLabel labelUse = new JLabel("This connection uses the following items:");
		JList list = new JList(listElement);
		JScrollPane scrollPane = new JScrollPane(list);
		JButton buttonInstall = new JButton("Install");
		JButton buttonUninstall = new JButton("Uninstall");
		JButton buttonProperties = new JButton("Properties");
		JCheckBox checkboxShowIcon = new JCheckBox("Show icon in notification area when connected");
		JCheckBox checkboxNotify = new JCheckBox("Notify me when this connection has limited or no connectivity");
		JButton buttonOK = new JButton("OK");
		JButton buttonCancel = new JButton("Cancel");

		// Create and set layout
		double p = TableLayout.PREFERRED;
		double border = 10; 
		double emptySpace = 10;
		double [] columnSize = {border, 1.0 / 3.0, TableLayout.FILL, 1.0 / 3.0, border};
		double [] rowSize = {border, border};
		TableLayout layout = new TableLayout(columnSize, rowSize);
		layout.setVGap(2);
		layout.setHGap(5);
		Container container = frame.getContentPane();
		container.setLayout(layout);

		
		// Add controls
		layout.insertRow(1, p);
		container.add(labelConnect, "1, 1, 3, 1");
		layout.insertRow(2, p);
		container.add(textfieldConnect, "1, 2, 2, 2");
		container.add(buttonConfigure, "3, 2");
		layout.insertRow(3, emptySpace);
		layout.insertRow(4, p);
		container.add(labelUse, "1, 4, 3, 4");
		layout.insertRow(5, TableLayout.FILL);
		container.add(scrollPane, "1, 5, 3, 5");
		layout.insertRow(6, p);
		// Show frame
		frame.pack();
		frame.setVisible(true);
		frame.toFront();
		container.add(buttonInstall, "1, 6");
		container.add(buttonUninstall, "2, 6");
		container.add(buttonProperties, "3, 6");
		layout.insertRow(7, emptySpace);
		layout.insertRow(8, p);
		container.add(checkboxShowIcon, "1, 8, 3, 8");
		layout.insertRow(9, p);
		container.add(checkboxNotify, "1, 9, 3, 9");
		layout.insertRow(10, emptySpace);
		layout.insertRow(11, p);

		container.add(buttonOK, "2, 11");
		container.add(buttonCancel, "3, 11");


	}



}

