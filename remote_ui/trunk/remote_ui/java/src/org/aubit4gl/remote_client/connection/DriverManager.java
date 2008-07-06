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
 * Driver manager to handle how to make connections from a 4gl
 * UI client to a 4gl program acting as a XML client.
 * 
 * The basic ideas come from DriverManager of JDBC.
 *  
 * @author Sérgio
 *
 */
public class DriverManager {
	
	/**
	 * Establish a connection to a 4gl program.
	 * In the momment of this writing uses ssh to start the program.
	 * 
	 * @param hostname
	 * @param userName
	 * @param password
	 * @param programName
	 * @return The connection
	 * @throws FGLUIException If cannot connect to the 4gl remote program
	 */
	public static Connection getConnection(String hostname,String userName,String password,String programName) 
	throws FGLUIException 
	{
		Driver driver = new Aubit4glDriver();
		Connection conn = driver.connect(hostname,userName,password,programName);
		return conn;
	}
}
