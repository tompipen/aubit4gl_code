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

import info.clearthought.layout.TableLayout;

import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.Font;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;

import javax.swing.JFrame;
import javax.swing.JPanel;

import org.aubit4gl.remote_client.connection.Connection;
import org.aubit4gl.remote_client.connection.DriverManager;
import org.aubit4gl.remote_client.connection.FGLUIException;
import org.aubit4gl.remote_client.connection.UICommand;
import org.aubit4gl.remote_client.connection.command.DisplayAt;
import org.aubit4gl.remote_client.connection.command.Menu;
import org.aubit4gl.remote_client.connection.command.OpenForm;
import org.aubit4gl.remote_client.connection.command.OpenWindow;
import org.aubit4gl.remote_client.connection.command.ProgramStartup;
import org.aubit4gl.remote_client.connection.command.ProgramStop;
import org.aubit4gl.remote_client.swing_ui.events.FglKeyListener;
import org.aubit4gl.remote_client.swing_ui.widget.DisplayAtUI;
import org.aubit4gl.remote_client.swing_ui.widget.FormUI;
import org.aubit4gl.remote_client.swing_ui.widget.MenuUI;
import org.aubit4gl.remote_client.swing_ui.widget.OpenFormUI;
import org.aubit4gl.remote_client.swing_ui.widget.WindowUI;

/**
 * UI Session is a visual placeholder for everithing we need to control
 * and show.
 * 
 * Each UI Session have its specific panel where the application is
 * shown and iteract.
 * 
 * It acts like some sort of controller in a visual application.
 * 
 * TODO : This should be cleaned at the end
 * 
 * @author Sergio Ferreira
 */
public class UISession {
	JFrame frame;
	private Connection connection = null;
	// The display panel of this application
	//DisplayPanel display 

	// Panel where the application works
	//JPanel uiPanel;
	Container uiPanel ;
	TableLayout layout;
	
	// Should have information about what is in the screen:
	ArrayList<WindowUI> windows = new ArrayList<WindowUI>();
	ArrayList<FormUI> forms = new ArrayList<FormUI>();
	ArrayList<MenuUI> menus = new ArrayList<MenuUI>();
	FglKeyListener keyListener = new FglKeyListener();
	
	WindowUI currentWindow;

	public UISession(Connection _connection,JFrame _frame) {
		frame = _frame;
		connection = _connection;
		initUiPanel();
		mainLoop();
		// TODO : Need to create a window called SCREEN with the default size 
	}

	/**
	 * Main loop where commands are received and showed
	 */
	public void mainLoop() {

		while (true) {
			try {
				UICommand cmd = connection.receive();
				execute(cmd);

			} catch (FGLUIException e) {
				// TODO : This should be changed by an exception
				System.out.println("Error receiving a command");
			}
		}
	}

	/**
	 * Initialize the user interface panel
	 * 
	 * TODO : Take the frame code. The frame should be global and one
	 * TODO : The size of each cell should be parametrized and decided based 
	 * TODO : Most of this should be made on the WindowUI
	 * TODO : What is todo is;
	 *    Create a window called SCREEN with 80 by 24
	 *    Open a frame for screen (decided as flag on WindowUI)
	 *    Add screen to window list
	 *    Assign current window to Screen
	 * on the font size
	 */
	private void initUiPanel() {
		
		// Initialize SCREEN window
		OpenWindow screen = new OpenWindow();
		screen.setName("SCREEN");
		screen.setHeigth(24);
		screen.setWidth(80);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(new FlowLayout());
		
		int lines = 24;
		int columns = 80;
		
		double rowHeight = 25.0;
		double columnWidth = 9.0;
		double rowSize[] = new double[24];
		double columnSize[] = new double[80];
		for (int i = 0 ; i < lines ; i++ ) {
			rowSize[i] = rowHeight;
		}
		
		for (int i = 0 ; i < columns ; i++ ) {
			columnSize[i] = columnWidth;
		}
		
		layout = new TableLayout(columnSize,rowSize);
		layout.setVGap(2);
		layout.setHGap(5);
		
		uiPanel = new JPanel();
		uiPanel.setLayout(layout);
		// TODO : It does not work on the panel
		frame.addKeyListener(keyListener);
		// TODO : This is just for test purpose.
		
		frame.getContentPane().add(uiPanel);
		
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
		frame.pack();
		frame.setVisible(true);
		frame.toFront();
	}

	/**
	 * Execute a UI Command
	 * TODO : Handle the exception in a proper way
	 * 
	 * @param uiCommand The user interface abstract command information.
	 */
	private void execute(UICommand uiCommand) {
		String className = uiCommand.getClass().getSimpleName();
		String methodName = className.substring(0,1).toLowerCase() + 
		className.substring(1);
		System.out.println("UI method name " + methodName);
		Method method = null;
		try {
			Class[] argType = { UICommand.class };
			method = this.getClass().getMethod(methodName,argType);
		} catch (Exception e) {
			// TODO : Handle the exception
			System.out.println("Method  <" + methodName + "> for remote command does not exist : " + e.getMessage());
			return;
		}

		System.out.println(" Method " + method.getName() );
		Object[] args = { uiCommand };
		try {
			method.invoke(this, args);
		} catch (IllegalArgumentException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		uiPanel.repaint();
	}

	/**
	 * Create a MenuUI widget and add it to the panel in the 
	 * correct position.
	 * 
	 * TODO : Remove the message to stdout
	 * 
	 * @param uiCommand The Menu user interface command.
	 */
	public void menu(UICommand uiCommand) {
		Menu mnu = (Menu) uiCommand;
		System.out.println("Menu invoked with argument <" + mnu.toString() + ">");
		MenuUI mnuUI = new MenuUI(mnu,connection,keyListener);
		// TODO : Remove this
		// keyListener.setListeningKeys(mnuUI.getListeningKeys());
		uiPanel.add(mnuUI,"1, 1, 79, 2");
		menus.add(mnuUI);
		// TODO : The menu should only be active when the wait for event was received 
	}
	
	/**
	 * Create a MenuUI widget and add it to the panel in the 
	 * correct position
	 * 
	 * @param uiCommand The DisplayAt command information.
	 */
	public void displayAt(UICommand uiCommand) {		
		DisplayAt dsp = (DisplayAt) uiCommand;
		System.out.println("Display AT invoked with argument <" + dsp.toString() + ">");
		DisplayAtUI dspUi = new DisplayAtUI(dsp);
		int startLine = dsp.getLine();
		int startCol = dsp.getColumn();
		int endLine = dsp.getLine();
		int endCol = dsp.getColumn() + dsp.getText().length();
		String pos = startCol + ", " + startLine + ", " + endCol + ", " + endLine;
		uiPanel.add(dspUi,pos);
		uiPanel.repaint();
	}
	
	/**
	 * Open a new form in the current window.
	 * 
	 * TODO : Create the concept of current window
	 * 
	 * @param uiCommand The OpenForm information including the form layout.
	 */
	public void openForm(UICommand uiCommand) {
		OpenForm openForm = (OpenForm) uiCommand;
		OpenFormUI openFormUI = new OpenFormUI(uiPanel,openForm);
		forms.add(openFormUI.getFormUI());
	}

	/**
	 * The remote program stopped his execution.
	 * 
	 * TODO : Clean the frames and everything on the session
	 */
	public void programStop(UICommand uiCommand) {
		ProgramStop programStop = (ProgramStop) uiCommand;
		System.out.println("Remote program stopped with exit status : " + programStop.getExitCode());
	}
	


	/**
	 * TODO : This is for testing purpose only
	 * @param args
	 */
	/*
	public static void main(String args[]) {
		UISession us = new UISession();
		//us.mainLoop();
	}
	*/
}
