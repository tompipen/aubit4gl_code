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

import org.aubit4gl.remote_client.connection.Connection;
import org.aubit4gl.remote_client.connection.UIResponse;

/**
 * Represent an answer to a menu option choosed by the user in the user interface.
 * 
 * @author Sérgio Ferreira
 */
public class MenuCommandChoosed extends UIResponse  {
    private int commandChoosed;
	
   
    /**
     * Create a response to send to the 4gl because the user 
     * choosed a menu option
     * 
     * @param commandChoosed The number of the menu command/option choosed by the user
     */
	public MenuCommandChoosed(int commandChoosed,Connection _connection) {
		super();
		this.commandChoosed = commandChoosed;
		this.connection = _connection;
		buildCommand();
	}

	/**
	 * Build the XML command to answer to 4gl programThe svn is allready working on SVN
	 */
	public void buildCommand() {
		strXml="<TRIGGERED ID='" + commandChoosed + "'/>\n";
	}
}
