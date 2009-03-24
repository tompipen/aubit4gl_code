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

package org.aubit4gl.remote_client.connection.response;

import org.aubit4gl.remote_client.connection.UIResponse;
import org.aubit4gl.remote_client.swing_ui.events.UIEvent;

/**
 * Represent an answer to a menu option choosed by the user in the user interface.
 * TODO : The menu command choosed should be a UIEvent and not necessarilly an UIResponse
 * @author Sérgio Ferreira
 */
public abstract class MenuCommandChoosed extends UIResponse implements UIEvent {
	private int commandChoosed;

	/**
	 * @param o The event object 
	 */
	public abstract void actionPerformed(Object o);

	/**
	 * Default constructor
	 */
	public MenuCommandChoosed() {
	}

	/**
	 * Create a response to send to the 4gl because the user 
	 * choosed a menu option
	 * 
	 * @param commandChoosed The number of the menu command/option choosed by the user
	 */
	public MenuCommandChoosed(int commandChoosed) {
		super();
		this.commandChoosed = commandChoosed;
		buildCommand();
	}

	/**
	 * Assign the command choosed.
	 * Used for <ENTER> key choosing the current one.
	 * 
	 * @param _commandChoosed
	 */
	public void setCommandChoosed(int _commandChoosed) {
		this.commandChoosed = _commandChoosed;
		buildCommand();
	}

	/**
	 * Getter for command choosed by the user.
	 * 
	 * @return The command choosed by the user.
	 */
	public int getCommandChoosed() {
		return commandChoosed;
	}

	/**
	 * Build the XML command to answer to 4gl programThe svn is allready working on SVN
	 */
	public void buildCommand() {
		strXml="<TRIGGERED ID='" + commandChoosed + "'/>\n";
	}

}
