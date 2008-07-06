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

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Logger;

/**
 * For now it dosen't connect. It starts and waits for receiving
 * the connections.
 * TODO : MUST connect using the APPServer.
 * TODO : Use a URL in oposition to specific fields.
 * 
 * @author Sérgio
 *
 */
public class Aubit4glDriver implements Driver {
	Logger logger = Logger.getLogger(this.getClass().getName());

	// The name of the server to where it should connect
	// TODO : Use it
	String server;

	Aubit4glProperties p = new Aubit4glProperties();

	/**
	 * Connect to the remote program using ssh. Then it waits for the connection
	 * from the 4gl program.
	 *
	 * @param userName The name of the user for ssh authentication 
	 * @param password  The password of the user for ssh authentication
	 * @param programName The name of the program to execute
	 * @return The connection already established from the 4gl program
	 */
	public Connection connect(String hostname,String userName,String password,String programName) 
	throws FGLUIException 
	{
		Connection connection = null;

		SshRemoteExecution re = new SshRemoteExecution(hostname,userName,password,programName);
		re.execute();
		connection = waitForServerToConnect();
		re.close();
		return connection;
	}

	/**
	 * Wait for the 4gl program to connect to.
	 * 
	 * @return A connection to the 4gl program.
	 * @throws FGLUIException
	 */
	public Connection connect() throws FGLUIException {
		return waitForServerToConnect();
	}

	/**
	 * Waits the connection from the server 4gl program.
	 * TODO : Must have a timeout defined
	 * 
	 * @return The connection to the server.
	 */
	private Connection waitForServerToConnect() throws FGLUIException{
		ServerSocket serverSocket = null;
		System.out.println("New socket on port " + p.getReturnPort());
		try {
			serverSocket = new ServerSocket(p.getReturnPort());
		} catch (IOException e) {
			// TODO : Must add the exception that caused and a description
			throw new FGLUIException("Error waiting for connection : " + e.getMessage());
		}

		System.out.println("Waiting for connection");
		Socket socket = null;
		try {
			socket = serverSocket.accept();
			socket.setTcpNoDelay(true);
		} catch (IOException e) {
			throw new FGLUIException("Error waiting for connection : " + e.getMessage());
		}
		System.out.println("Got the connection");
		try {
			serverSocket.close();
		} catch (IOException e) {
			throw new FGLUIException("Error closing the server socket : " + e.getMessage());		}
		Connection connection = new Aubit4glConnection(socket);
		return connection;
	}


}
