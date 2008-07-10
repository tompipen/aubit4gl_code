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

package org.aubit4gl.remote_client.command;

import junit.framework.TestCase;

import org.aubit4gl.remote_client.connection.Connection;
import org.aubit4gl.remote_client.connection.DriverManager;
import org.aubit4gl.remote_client.connection.FGLUIException;
import org.aubit4gl.remote_client.connection.FglProgramSimulator;
import org.aubit4gl.remote_client.connection.command.ProgramStartup;
import org.aubit4gl.remote_client.connection.command.ProgramStop;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;


/**
 * Test if the specific commands are received in a proper way.
 * It uses a 4gl program simulation but in the near future the tests should be also made 
 * with real 4gl programs.
 * 
 * @author Sérgio Ferreira
 */
public class UICommandTest extends TestCase {
	FglProgramSimulator fglProg;
	Connection conn = null;

	@Before public void setUp() {

		fglProg = new FglProgramSimulator(1);
/* TODO : FIX THIS
		try {
			conn = DriverManager.getConnection();
		} catch (FGLUIException e) {
			fail("Cannot receive connection from the 4gl program " + e.getMessage());
		}
		*/

	}

	/**
	 * Check if program startup works in a proper way.
	 */
	@Test public void testProgramStartup() {
		fglProg.addCommand(new ProgramStartup("prog_name",0));

		ProgramStartup recCmd = null;
		try {
			recCmd = (ProgramStartup) conn.receive();
		} catch (FGLUIException e) {
			fail("Did not received any command");
		}
		if ( !(recCmd instanceof ProgramStartup) )
			fail("The received command was not a ProgramStartup");
		assertEquals("prog_name",recCmd.getProgramName());
		assertEquals(0,recCmd.getId());
	}

	/**
	 * Check if program startup works in a proper way.
	 */
	@Test public void testProgramStop() {
		fglProg.addCommand(new ProgramStop(0,1));

		ProgramStop recCmd = null;
		try {
			recCmd = (ProgramStop) conn.receive();
		} catch (FGLUIException e) {
			fail("Did not received any command : " + e.getMessage());
		}
		if ( !(recCmd instanceof ProgramStop) )
			fail("The received command was not a ProgramStartup");
		assertEquals(0,recCmd.getId());
		assertEquals(1,recCmd.getExitCode());
	}

	@After public void tearDown() {
		fglProg = null;
		try {
			conn.disconnect();
		} catch (FGLUIException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		conn = null;
	}
}
