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
import org.aubit4gl.remote_client.connection.command.CurrentWindow;
import org.aubit4gl.remote_client.connection.command.Display;
import org.aubit4gl.remote_client.connection.command.Free;
import org.aubit4gl.remote_client.connection.command.Menu;
import org.aubit4gl.remote_client.connection.command.MenuCommand;
import org.aubit4gl.remote_client.connection.command.ProgramStartup;
import org.aubit4gl.remote_client.connection.command.ProgramStop;
import org.aubit4gl.remote_client.connection.command.WaitForEvent;
import org.aubit4gl.remote_client.connection.response.MenuCommandChoosed;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

/**
 * Test all the remote command received
 * 
 * For each comnand it should exist a remote 4gl program
 * 
 * TODO : This is very incomplete
 * 
 * @author Sérgio Ferreira
 *
 */
public class CommandTest extends TestCase {
    Connection conn;
	String host = "192.168.152.128";
    String user = "sergio";
    String password = "jfola45";
    String baseProgram = "./test_aubit.sh";

	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
	}

	@AfterClass
	public static void tearDownAfterClass() throws Exception {
	}

	@Before
	public void setUp() throws Exception {

	}

	@After
	public void tearDown() throws Exception {
      conn.disconnect();
	}
	
	private String buildProgram(String program) {
		return baseProgram + " WORK/4gl_ui_client/test/4gl/" + program + "/" + program;
	}
	
	private String buildRemoteProgram(String program) {
		return "WORK/4gl_ui_client/test/4gl/" + program + "/" + program;
	}
	
	/**
	 * Prove that the Menu command will work 
	 */
	@Test public void testDisplayArray() {
		String program = buildProgram("display_array");
		try {
			conn = DriverManager.getConnection(host,user,password,program);
		} catch (FGLUIException e) {
			fail("Cannot execute 4gl program <" + program + "> :" + e.getMessage());
		}
		
		try {
			ProgramStartup ps = (ProgramStartup) conn.receive();
			assertEquals(buildRemoteProgram("display_array"), ps.getProgramName());
			Menu mnu = (Menu) conn.receive();
			System.out.println("Received menu ");
			assertEquals("Options",mnu.getTitle());
			assertEquals(3,mnu.getMenuCommands().size());
			MenuCommand mc = mnu.getMenuCommands().get(0);
			//assertEquals(null,mc.getKey());
			assertEquals(1, mc.getId());
			assertEquals("First command",mc.getText());
			WaitForEvent w = (WaitForEvent) conn.receive();
			MenuCommandChoosed mcc = new MenuCommandChoosed(1,conn);
			conn.send(mcc);
			Display d = (Display) conn.receive();
			w = (WaitForEvent) conn.receive();
			assertEquals("First command choosed",d.getText());
			mcc = new MenuCommandChoosed(2,conn);
			conn.send(mcc);
			Free free = (Free) conn.receive();
			ProgramStop pe = (ProgramStop) conn.receive();
			assertEquals(0,pe.getExitCode());
		} catch (FGLUIException e) {
			fail("Did not received any command : " + e.getMessage());
		}
	}

}
