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

import org.aubit4gl.remote_client.connection.command.Display;
import org.aubit4gl.remote_client.connection.command.ProgramStartup;
import org.aubit4gl.remote_client.connection.command.ProgramStop;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * Test if the remote execution of a test 4gl program works
 * @author Sérgio
 *
 */
public class ConnectToRemoteProgram extends TestCase {
	Connection conn;
	
	@Before
	public void setUp() throws Exception {
	}
	
	/**
	 * Test if the connection works.
	 * The username, password, host and program are hardcoded for now
	 * TODO : Add asserts
	 */
	@Test public void testConnect() {
		String host = "192.168.152.128";
        String user = "sergio";
        String password = "jfola45";
        String program = "./test_aubit.sh";
        //program = "ls";

		try {
			conn = DriverManager.getConnection(host,user,password,program);
		} catch (FGLUIException e) {
			fail("Cannot execute 4gl program " + e.getMessage());
		}
		
		UICommand recCmd = null;
		try {
			recCmd = (ProgramStartup) conn.receive();
			System.out.println("Command received " + recCmd);
			recCmd = (Display) conn.receive();
			System.out.println("Command received " + recCmd);
			recCmd = (ProgramStop) conn.receive();
			System.out.println("Command received " + recCmd);
		} catch (FGLUIException e) {
			fail("Did not received any command : " + e.getMessage());
		}
	}

	@After
	public void tearDown() throws Exception {
	}

}
