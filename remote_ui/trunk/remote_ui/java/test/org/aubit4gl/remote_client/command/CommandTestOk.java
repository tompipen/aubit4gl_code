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
import org.aubit4gl.remote_client.connection.command.ClearWindow;
import org.aubit4gl.remote_client.connection.command.CloseWindow;
import org.aubit4gl.remote_client.connection.command.CurrentWindow;
import org.aubit4gl.remote_client.connection.command.Display;
import org.aubit4gl.remote_client.connection.command.DisplayAt;
import org.aubit4gl.remote_client.connection.command.ErrorCmd;
import org.aubit4gl.remote_client.connection.command.Form;
import org.aubit4gl.remote_client.connection.command.Free;
import org.aubit4gl.remote_client.connection.command.Menu;
import org.aubit4gl.remote_client.connection.command.MenuCommand;
import org.aubit4gl.remote_client.connection.command.Message;
import org.aubit4gl.remote_client.connection.command.OpenForm;
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
public class CommandTestOk extends TestCase {
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
	 * Prove that the Display command will work 
	 */
	@Test public void testDisplay() {
		String program = buildProgram("display");
		try {
			conn = DriverManager.getConnection(host,user,password,program);
		} catch (FGLUIException e) {
			fail("Cannot execute 4gl program <" + program + "> :" + e.getMessage());
		}
		
		try {
			ProgramStartup ps = (ProgramStartup) conn.receive();
			assertEquals(buildRemoteProgram("display"), ps.getProgramName());
			Display d = (Display) conn.receive();
			assertEquals("Hello world",d.getText());
			ProgramStop pe = (ProgramStop) conn.receive();
			assertEquals(0,pe.getExitCode());
		} catch (FGLUIException e) {
			fail("Did not received any command : " + e.getMessage());
		}
	}
	
	/**
	 * Prove that the Error command will be properly received and converted from
	 * XML to object. 
	 */
	@Test public void testError() {
		String program = buildProgram("error");
		try {
			conn = DriverManager.getConnection(host,user,password,program);
		} catch (FGLUIException e) {
			fail("Cannot execute 4gl program <" + program + "> :" + e.getMessage());
		}
		
		try {
			ProgramStartup ps = (ProgramStartup) conn.receive();
			assertEquals(buildRemoteProgram("error"), ps.getProgramName());
			ErrorCmd d = (ErrorCmd) conn.receive();
			assertEquals("This is an error",d.getMessage());
			d = (ErrorCmd) conn.receive();
			assertEquals("Error on variable",d.getMessage());
			ProgramStop pe = (ProgramStop) conn.receive();
			assertEquals(0,pe.getExitCode());
		} catch (FGLUIException e) {
			fail("Did not received any command : " + e.getMessage());
		}
	}

	/**
	 * Prove that the Message command will be properly received and converted from
	 * XML to object. 
	 */
	@Test public void testMessage() {
		String program = buildProgram("message");
		try {
			conn = DriverManager.getConnection(host,user,password,program);
		} catch (FGLUIException e) {
			fail("Cannot execute 4gl program <" + program + "> :" + e.getMessage());
		}
		
		try {
			ProgramStartup ps = (ProgramStartup) conn.receive();
			assertEquals(buildRemoteProgram("message"), ps.getProgramName());
			Message d = (Message) conn.receive();
			assertEquals("This is a message",d.getMessage());
			ProgramStop pe = (ProgramStop) conn.receive();
			assertEquals(0,pe.getExitCode());
		} catch (FGLUIException e) {
			fail("Did not received any command : " + e.getMessage());
		}
	}
	
	/**
	 * Prove that the Display command will work 
	 */
	@Test public void testDisplayAt() {
		String program = buildProgram("display_at");
		try {
			conn = DriverManager.getConnection(host,user,password,program);
		} catch (FGLUIException e) {
			fail("Cannot execute 4gl program <" + program + "> :" + e.getMessage());
		}
		
		try {
			ProgramStartup ps = (ProgramStartup) conn.receive();
			assertEquals(buildRemoteProgram("display_at"), ps.getProgramName());
			DisplayAt da = (DisplayAt) conn.receive();
			assertEquals("Hello world",da.getText());
			assertEquals(3,da.getX());
			assertEquals(2,da.getY());
			ProgramStop pe = (ProgramStop) conn.receive();
			assertEquals(0,pe.getExitCode());
		} catch (FGLUIException e) {
			fail("Did not received any command : " + e.getMessage());
		}
	}
	
	/**
	 * Prove that the Message command will be properly received and converted from
	 * XML to object. 
	 */
	@Test public void testClearWindow() {
		String program = buildProgram("clear_window");
		try {
			conn = DriverManager.getConnection(host,user,password,program);
		} catch (FGLUIException e) {
			fail("Cannot execute 4gl program <" + program + "> :" + e.getMessage());
		}
		
		try {
			ProgramStartup ps = (ProgramStartup) conn.receive();
			assertEquals(buildRemoteProgram("clear_window"), ps.getProgramName());
			CurrentWindow cu = (CurrentWindow) conn.receive();
			ClearWindow cw = (ClearWindow) conn.receive();
			assertEquals("screen",cw.getWindow());
			cw = (ClearWindow) conn.receive();
			assertEquals("w_name",cw.getWindow());
			ProgramStop pe = (ProgramStop) conn.receive();
			assertEquals(0,pe.getExitCode());
		} catch (FGLUIException e) {
			fail("Did not received any command : " + e.getMessage());
		}
	}
	
	/**
	 * Prove that the Menu command will work 
	 */
	@Test public void testMenu() {
		String program = buildProgram("menu");
		try {
			conn = DriverManager.getConnection(host,user,password,program);
		} catch (FGLUIException e) {
			fail("Cannot execute 4gl program <" + program + "> :" + e.getMessage());
		}
		
		try {
			ProgramStartup ps = (ProgramStartup) conn.receive();
			assertEquals(buildRemoteProgram("menu"), ps.getProgramName());
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
	
	/**
	 * Prove that the OpenForm command will be received in a proper way 
	 */
	@Test public void testSimpleForm() {
		String program = buildProgram("simple_form");
		try {
			conn = DriverManager.getConnection(host,user,password,program);
		} catch (FGLUIException e) {
			fail("Cannot execute 4gl program <" + program + "> :" + e.getMessage());
		}
		
		try {
			ProgramStartup ps = (ProgramStartup) conn.receive();
			assertEquals(buildRemoteProgram("simple_form"), ps.getProgramName());
			OpenForm openForm = (OpenForm) conn.receive();
			assertEquals("form_name",openForm.getName());
			Form form = openForm.getForm();
			assertNotNull(form);
			assertEquals(10, form.getLabels().size());
			assertEquals(2,form.getFields().size());
			// TODO must test labels and fields
			ProgramStop pe = (ProgramStop) conn.receive();
			assertEquals(0,pe.getExitCode());
		} catch (FGLUIException e) {
			fail("Did not received any command : " + e.getMessage());
		}
	}
	
	/**
	 * Prove that the CLOSE FORM command will be properly received and converted 
	 * from	XML to object. 
	 */
	@Test public void testCloseForm() {
		String program = buildProgram("close_window");
		try {
			conn = DriverManager.getConnection(host,user,password,program);
		} catch (FGLUIException e) {
			fail("Cannot execute 4gl program <" + program + "> :" + e.getMessage());
		}
		
		try {
			ProgramStartup ps = (ProgramStartup) conn.receive();
			assertEquals(buildRemoteProgram("close_window"), ps.getProgramName());
			CloseWindow cw = (CloseWindow) conn.receive();
			assertEquals("w_name",cw.getWindow());
			ProgramStop pe = (ProgramStop) conn.receive();
			assertEquals(0,pe.getExitCode());
		} catch (FGLUIException e) {
			fail("Did not received any command : " + e.getMessage());
		}
	}

	/**
	 * Prove that the CLOSE FORM command will be properly received and converted 
	 * from	XML to object. 
	 */
	@Test public void testCloseWindow() {
		String program = buildProgram("close_window");
		try {
			conn = DriverManager.getConnection(host,user,password,program);
		} catch (FGLUIException e) {
			fail("Cannot execute 4gl program <" + program + "> :" + e.getMessage());
		}
		
		try {
			ProgramStartup ps = (ProgramStartup) conn.receive();
			assertEquals(buildRemoteProgram("close_window"), ps.getProgramName());
			CloseWindow cw = (CloseWindow) conn.receive();
			assertEquals("w_name",cw.getWindow());
			ProgramStop pe = (ProgramStop) conn.receive();
			assertEquals(0,pe.getExitCode());
		} catch (FGLUIException e) {
			fail("Did not received any command : " + e.getMessage());
		}
	}
	
	/**
	 * Prove that the CURRENT WINDOW IS command will be properly received and converted 
	 * from	XML to object. 
	 */
	@Test public void testCurrentWindow() {
		String program = buildProgram("current_window");
		try {
			conn = DriverManager.getConnection(host,user,password,program);
		} catch (FGLUIException e) {
			fail("Cannot execute 4gl program <" + program + "> :" + e.getMessage());
		}
		
		try {
			ProgramStartup ps = (ProgramStartup) conn.receive();
			assertEquals(buildRemoteProgram("current_window"), ps.getProgramName());
			CurrentWindow cw = (CurrentWindow) conn.receive();
			assertEquals("screen",cw.getWindow());
			cw = (CurrentWindow) conn.receive();
			assertEquals("w_name",cw.getWindow());
			ProgramStop pe = (ProgramStop) conn.receive();
			assertEquals(0,pe.getExitCode());
		} catch (FGLUIException e) {
			fail("Did not received any command : " + e.getMessage());
		}
	}

}
