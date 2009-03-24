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

import java.awt.BorderLayout;
import java.awt.Font;
import java.util.ArrayList;
import java.util.HashMap;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JToolBar;

import org.aubit4gl.remote_client.connection.Connection;
import org.aubit4gl.remote_client.connection.FGLUIException;
import org.aubit4gl.remote_client.connection.command.Key;
import org.aubit4gl.remote_client.connection.command.Menu;
import org.aubit4gl.remote_client.connection.command.MenuCommand;
import org.aubit4gl.remote_client.connection.response.MenuCommandChoosed;
import org.aubit4gl.remote_client.swing_ui.events.FglKeyListener;
import org.aubit4gl.remote_client.swing_ui.events.UIEvent;

/**
 * The User interface implementation for 4gl Menu.
 * The UI is maked based on a Tool Bar.
 * 
 * TODO : It should be a panel with some scrollbar when does not fit
 * TODO : The message of each option should be optional or displayed on the status line
 * TODO : Have the ability to change the text to image buttons automaticaly and controled by scripts
 * TODO : Implement HIDE OPTION and SHOW OPTION
 * @author Sérgio Ferreira
 */
public class MenuUI extends JPanel {
	//private Font font;
	private Menu menu;
	private JToolBar menuToolbar = new JToolBar();
	private JLabel menuMessageLabel = new JLabel();
	private ArrayList<MenuCommandUI> commandList = new ArrayList<MenuCommandUI>();
	HashMap<String,UIEvent> listeningKeys = new HashMap<String,UIEvent>();
	private int currentOption;
	Connection connection;

	/* TODO : CHANGE TO enumerated */
	public static final int PREVIOUS = -1;
	public static final int NEXT     = -2;
	public static final int FIRST    = -3;
	public static final int LAST     = -4;

	FglKeyListener kl;
	

	/**
	 * TODO : I don't think the menu UI should know the connection.
	 * TODO : Check if I receive the listener
	 * @param _menu
	 * @param connection
	 */
	public MenuUI(Menu _menu,Connection _connection,FglKeyListener _kl) {
		menu = _menu;
		kl = _kl;
		connection = _connection;

		// Adding sub components of menu
		menuToolbar.setOrientation(JToolBar.HORIZONTAL);
		menuToolbar.setFloatable(false);

		this.setLayout(new BorderLayout());
		this.add(menuToolbar, BorderLayout.PAGE_START);
		this.add(menuMessageLabel,BorderLayout.PAGE_END);

		this.addKeyListener(kl);


		int i = 1;
		for ( MenuCommand menuCommand : menu.getMenuCommands() ) {
			MenuCommandUI mci = new MenuCommandUI(menuCommand);
			commandList.add(mci);
			//mci.setFont(font);
			mci.addKeyListener(kl);
			this.add(mci);
			menuToolbar.add(mci);

			// This is not working. I need to have an event to where I pass the number of the 
			// elements
			MenuCommandChoosed mcc = new MenuCommandChoosed(menuCommand.getId()) {
				public void actionPerformed(Object o) {
					nextOption(getCommandChoosed());
					sendToFgl(this);
				}
			};
			Key key = menuCommand.getKey();
			System.out.println("Listening key " + key );
			listeningKeys.put(key.toString(), mcc);
			// TODO : Create a mouse listener for choose the option of the menu
			i++;
		}

		MenuCommandChoosed mcc = new MenuCommandChoosed() {
			public void actionPerformed(Object o) {
				nextOption(NEXT);
			}
		};
		listeningKeys.put("SPACE", mcc);
		listeningKeys.put("RIGHT", mcc);
		mcc = new MenuCommandChoosed() {
			public void actionPerformed(Object o) {
				nextOption(PREVIOUS);
			}
		};
		listeningKeys.put("LEFT", mcc);
		
		mcc = new MenuCommandChoosed() {
			public void actionPerformed(Object o) {
				setCommandChoosed(currentOption);
				sendToFgl(this);
			}
		};
		listeningKeys.put("ENTER", mcc);

		kl.setListeningKeys(listeningKeys);
		// TODO : Add some kind of border
		// ??? invalidate();
		currentOption = 1;
		showCurrentOption();
	}

	/**
	 * Change the current menu option by his position.
	 *  
	 * @param option Option order to where change.
	 */
	public void nextOption(int option) {
		switch (option) {
		case PREVIOUS:
			if ( currentOption == 1 )
				currentOption = commandList.size();
			else
				currentOption--;
			break;
		case NEXT:
			if ( currentOption == commandList.size() )
				currentOption = 1;
			else
				currentOption++;
			break;
		case FIRST:
			currentOption = 1;
			break;
		case LAST:
			currentOption = commandList.size();
			break;
		default:
			if ( option < 1 || option > commandList.size() )
				// TODO : Should throw an exception
				System.out.println("Option non existant chossed");
		currentOption = option;
		}
		showCurrentOption();
	}

	/**
	 * Change to other menu option by the string
	 * 
	 * @param option A string with the option name.
	 */
	public void nextOption(String option) {
		for (int i = 0 ; i < commandList.size(); i++ ) {
			MenuCommandUI mci = commandList.get(i); 
			if ( mci.getText().equals(option) ) {
				currentOption = i;
				break;
			}
		}
		// TODO : Check if it should throw an exception on non existant option
		System.out.println("Non existent option asked to change to");
	}

	/**
	 * Focus the current option and show the comment to the option
	 * in the menu message line (if thats the case). 
	 */
	private void showCurrentOption() {
		MenuCommandUI mci = commandList.get(currentOption-1);
		if ( ! mci.hasFocus() )
			mci.requestFocus();
		menuMessageLabel.setText(mci.getDescription());
	}

	public void setKeyListener(FglKeyListener _kl) {
		kl = _kl;
	}
	
	/**
	 * Send the answer to the 4gl program. 
	 * 
	 * @param response The menu command that was choosed by the user.
	 */
	private void sendToFgl(MenuCommandChoosed response) {
		if ( connection == null )
			// TODO : Should throw an exception or log things
			return;
		try {
		connection.send(response);
		} catch (FGLUIException e) {
			// TODO : Need to handle the exception
			// TODO : Need to log things
			System.out.println("Error " + e.getMessage());
		}
	}

	// Main just for test
	public static void main(String args[]) {
		// Create a menu with options
		Menu menu = new Menu();

		ArrayList<MenuCommand> mcs = new ArrayList<MenuCommand>();
		MenuCommand mc = new MenuCommand(1,new Key("1"),1,"Op 1","First option",0);
		mcs.add(mc);
		mc = new MenuCommand(1,new Key("2"),2,"Op 2","Second option",0);
		mcs.add(mc);
		mc = new MenuCommand(1,new Key("3"),3,"Op 3","Third option",0);
		mcs.add(mc);
		menu.setMenuCommands(mcs);

		//Create and set up the window.
		JFrame frame = new JFrame("BorderLayoutDemo");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//Set up the content pane.
		FglKeyListener kl = new FglKeyListener();
		//kl.setListeningKeys(mnu.getListeningKeys());
		//mnu.setKeyListener(kl);

		MenuUI mnu = new MenuUI(menu,null,kl);
		frame.getContentPane().add(mnu);
		//Use the content pane's default BorderLayout. No need for
		//setLayout(new BorderLayout());
		//Display the window.
		//frame.addKeyListener(kl);
		frame.pack();
		frame.setVisible(true);

		// Create a frame 
		// Add a menuUI to the frame
		// SHOW
	}
}

