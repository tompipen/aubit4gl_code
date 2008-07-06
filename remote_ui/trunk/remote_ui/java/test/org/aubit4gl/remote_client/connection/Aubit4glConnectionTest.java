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

import junit.framework.TestCase;

import org.aubit4gl.remote_client.connection.command.ProgramStartup;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;


/**
 * Test the connection mechanism for the aubit 4gl UI client
 * TODO : Tests to add:
 *   - Accept a connection and kill 4gl program
 *   - Error of message (badly formed message) sended by 4gl program
 *   - Close the UI 
 *   
 * @author Sérgio Ferreira
 */
public class Aubit4glConnectionTest extends TestCase {
    FglProgramSimulator fglProg;
	Connection conn;

	/**
	 * Test if the connection works 
	 */
	@Test public void testConnect() {

		// It waits 1 seconds before trying to connect to the UI client
		fglProg = new FglProgramSimulator(1);
		
		// I need to use a thread that keeps waiting for connection
		/*
		try {
			// TODO : FIX THIS TEST
			//connection = DriverManager.getConnection();
		} catch (FGLUIException e) {
			fail("Cannot receive connection from the 4gl program " + e.getMessage());
		}
		*/

		if ( ! fglProg.isConnected() )
			fail("The 4gl program server did not connected to the UI client");
	}
	

	/**
	 * @throws java.lang.Exception
	 */
	@After public void tearDown() throws Exception {
		// Shut down the 4gl program simulator
		// Shut down the client
		conn.disconnect();
	}

}
