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

import javax.swing.JButton;
import org.aubit4gl.remote_client.connection.command.MenuCommand;

/**
 * Graphical Button used to implement a menu option.
 * 
 * @author Sérgio Ferreira
 */
public class MenuCommandUI extends JButton {
	MenuCommand menuCommand;

	public MenuCommandUI(MenuCommand menuCommand) {
		super(menuCommand.getText());
		this.menuCommand = menuCommand;
		setToolTipText(menuCommand.getDescription());
		setBorderPainted(false);
		// Maybe I need to take the border off and put when mouse over
		// setMnemonic with the Key
	}
	
	public String getDescription() {
		return menuCommand.getDescription();
	}
}
