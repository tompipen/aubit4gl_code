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

import info.clearthought.layout.TableLayout;

import java.awt.Container;
import java.awt.Font;

import javax.swing.JFrame;
import javax.swing.JPanel;

import org.aubit4gl.remote_client.connection.command.OpenWindow;

/**
 * 4gl window interface.
 * All windows including the one called SCREEN are of this type.
 * This extends a panel because there is no need to expose the frame to the exterior.
 * 
 * TODO : Do I need list of opened widgets on the window :
 *   - menu(s)
 *   - Forms
 *   - Display at(s)
 * TODO : Only Screen should have a JFrame. All other should be JInternalFrame
 * TODO : A window without a border is a panel ?
 * TODO : How frames can not have the top bar : With a JWindow ?
 * TODO : There should be a way to decide wich ones are frames and wich are not
 * @author Sérgio Ferreira
 *
 */
public class WindowUI extends JPanel {
	// The information about the window
	OpenWindow  window;

	TableLayout layout;
	Container frame;
	
	WindowUI(OpenWindow _window) {
      window = _window;
      initFrame();
      initUiPanel();
	}
	
	/**
	 * Initialize the frame where the window will be putted 
	 */
	private void initFrame() {
		if ( window.getName().equals("SCREEN") ) {
			frame = new JFrame("4gl application - To be changed");
			return;
		}
		
		// If 
	}
	
	/**
	 * 
	 * @return The frame object that will be added.
	 */
	public Container getFrame() {
		return frame;
	}
	
	/**
	 * Initialize the user interface panel
	 * 
	 * TODO : Take the frame code. The frame should be global and one
	 * TODO : The size of each cell should be parametrized and decided based 
	 * on the font size
	 * TODO : I should use a null layout and have methods that give me:
	 *   - The x,y where the component should be added
	 *   - The width and height of the component
	 *   - I think there is a class called Bounds or something like that
	 *   It is a Rectangle and it is returned by setBounds()
	 */
	private void initUiPanel() {
		int lines = window.getHeigth();
		int columns = window.getWidth();
		
		double rowHeight = 25.0;
		double columnWidth = 9.0;
		double rowSize[] = new double[lines];
		double columnSize[] = new double[columns];
		for (int i = 0 ; i < lines ; i++ ) {
			rowSize[i] = rowHeight;
		}
		
		for (int i = 0 ; i < columns ; i++ ) {
			columnSize[i] = columnWidth;
		}
		
		layout = new TableLayout(columnSize,rowSize);
		layout.setVGap(2);
		layout.setHGap(5);
		
		// uiPanel = new JPanel();
		setLayout(layout);
		// TODO : It does not work on the panel
		// frame.addKeyListener(keyListener);
		// TODO : This is just for test purpose.
		
		// TODO : This should be made somewhere. Maibe on the UISession 
		// frame.getContentPane().add(uiPanel);
		
		Font f = new Font("Times New Roman",Font.PLAIN,12);
		//FontMetrics fm = new FontMetrics(f);
		/*
		int h = 40; //fm.getHeight();
		int w = 40; //fm.charWidth('W');
		for (int i = 1 ; i <= lines ; i++ ) {
			JLabel l = new JLabel("|");
			String pos = "1, " + i + ", 1," + i; 
			uiPanel.add(l,pos);

		}
		for (int i = 1 ; i <= columns ; i++ ) {
			JLabel l = new JLabel("|");
			String pos =  i + ", 1," + i + ", 1"; 
			uiPanel.add(l,pos);
		}
		*/
		// TODO : This should be made somewhere. Maibe on the UISession
		/*
		frame.pack();
		frame.setVisible(true);
		frame.toFront();
		*/
	}
}
