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

import java.awt.Font;
import java.util.HashMap;

import javax.swing.ButtonGroup;
import javax.swing.JToolBar;

import org.aubit4gl.remote_client.connection.Connection;
import org.aubit4gl.remote_client.connection.UIResponse;
import org.aubit4gl.remote_client.connection.command.Key;
import org.aubit4gl.remote_client.connection.command.Menu;
import org.aubit4gl.remote_client.connection.command.MenuCommand;
import org.aubit4gl.remote_client.connection.response.MenuCommandChoosed;

/**
 * The User interface implementation for 4gl Menu.
 * The UI is maked based on a Tool Bar.
 * 
 * TODO : I need to create button for left and rigth when the menu does not fit.
 * TODO : It should be a panel with some scrollbar when does not fit
 * @author Sérgio Ferreira
 */
public class MenuUI extends JToolBar {
	private Font font;
	private Menu menu;
	private ButtonGroup buttonGroup;
	HashMap<String,UIResponse> listeningKeys = new HashMap<String,UIResponse>();
	
	public MenuUI(Menu _menu,Connection connection) {
		super(HORIZONTAL);
		menu = _menu;
		buttonGroup = new ButtonGroup();
		int numOption = 1;
		for ( MenuCommand menuCommand : menu.getMenuCommands() ) {
			MenuCommandUI mci = new MenuCommandUI(menuCommand);
			//mci.setFont(font);
			this.add(mci);
			buttonGroup.add(mci);
			MenuCommandChoosed mcc = new MenuCommandChoosed(numOption,connection);
			Key key = menuCommand.getKey();
		System.out.println("Listening key " + key );
			listeningKeys.put(key.toString(), mcc);
			numOption++;
		}
		setFloatable(false);
		// TODO : Add some kind of border
		// ??? invalidate();
	}
	
	/**
	 * Get the keys that the menu should answer to.
	 * 
	 * @return An hash map containing the keys and the command to be received.
	 */
	public HashMap<String,UIResponse> getListeningKeys() {
		return listeningKeys;
	}
}

