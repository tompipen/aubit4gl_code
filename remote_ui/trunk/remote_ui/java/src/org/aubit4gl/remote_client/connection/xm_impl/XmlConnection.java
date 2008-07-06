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

package org.aubit4gl.remote_client.connection.xm_impl;

import org.aubit4gl.remote_client.connection.ClientUICommand;
import org.aubit4gl.remote_client.connection.Connection;
import org.aubit4gl.remote_client.connection.FGLUIException;
import org.aubit4gl.remote_client.connection.UICommand;
import org.aubit4gl.remote_client.connection.UIResponse;

public class XmlConnection implements Connection {

	// I need to have a private socket / stream here
	
	/**
	 * Receive a command from the opened socket.
	 */
	public ClientUICommand receive() {
		return null;
	}

	public void send(UICommand uiCommand) {
		// TODO Auto-generated method stub

	}
	
	public void disconnect() {
		
	}

    public void send(UIResponse uiResponse) throws FGLUIException {
        throw new UnsupportedOperationException("Not supported yet.");
    }

}
