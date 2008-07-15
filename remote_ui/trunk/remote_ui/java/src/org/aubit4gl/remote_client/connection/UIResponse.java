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

package org.aubit4gl.remote_client.connection;

/**
 * User interface response to send to the 4gl program derived from a user interaction.
 * 
 * @author Sérgio Ferreira
 */
public abstract class UIResponse {
	protected String strXml;
	
	public byte[] getBytes() {
		return strXml.getBytes();
	}
	
	/**
	 * To obtain the XML reptresentation of the command to trigger to the 
	 * 4gl remote program.
	 *  
	 * @return The 4gl <TRIGGERED> command
	 */
	public String getXml() {
		return strXml;
	}
	
	public void send(Connection connection) throws FGLUIException {
		System.out.println("Send a response");
		connection.send(this);
	}
	
	public String getCommand() {
		return strXml;
	}
	
	public abstract void buildCommand();
}
