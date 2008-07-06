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

package org.aubit4gl.remote_client.swing_ui;

import java.util.HashMap;

import javax.swing.JFrame;

import org.aubit4gl.remote_client.connection.Connection;
import org.aubit4gl.remote_client.connection.DriverManager;
import org.aubit4gl.remote_client.connection.FGLUIException;
import org.aubit4gl.remote_client.connection.command.ProgramStartup;

/**
 * Entry class of a remote UI maked in swing for Aubit4gl
 * The remote UI communicate with 4gl by a socket transfering XML 
 * @author Sérgio
 *
 */
public class Main {
	private Parameters parameters;
	private Configuration configuration = new Configuration();
	private MainFrame mainFrame;
	private HashMap<String,UISession> sessions = new HashMap<String,UISession>();
	
	/**
	 * Connect to the server
	 * TODO : This should be removed from here. It is for test only
	 * The information should be originated on configuration 
	 * and (or) edited from an UI
	 */
	private Connection connect() {
		String host = "192.168.152.128";
		String user = "sergio";
		String password = "jfola45";
		String baseProgram = "./test_aubit.sh";
		//String program = baseProgram + " menu";
		//String program = baseProgram + " display_at";
		String program = baseProgram + " WORK/4gl_ui_client/test/4gl/test_ui/test_ui";
		Connection connection = null;

		try {
			connection = DriverManager.getConnection(host,user,password,program);
		} catch (FGLUIException e) {
			// TODO : Good exception presentation
			System.out.println("Error connecting ");
		}

		try {
			ProgramStartup ps = (ProgramStartup) connection.receive();
		} catch (FGLUIException e) {
			System.out.println("The program did'n started ");
		}
		return connection;
	}
	
	/**
	 * Start a new session / remote program.
	 */
	private void startNewSession() {
	  Connection connection = connect();
	  UISession session = new UISession(connection,mainFrame);
	  sessions.put("Test", session);
	}
	
	/**
	 * Check the parameters and initialize a Parameters object.
	 * TODO : Implement it
	 * @param args
	 */
	private Parameters analizeParameters(String args[]) {
		return null;
	}
	
	/**
	 * Dynamic main entry
	 * 
	 * @param args
	 */
	public void mainUi(String args[]) {
		parameters = analizeParameters(args);
		executeSwingUI();
	}
	
	/**
	 * Start the main application frame where all session should be shown
	 */
	private void startApplicationFrame() {
		mainFrame = new MainFrame();
	}
	
	public void executeSwingUI() {
		//configuration.read();
		startApplicationFrame();
		// Just for testing purpose
		startNewSession();
	}
	
	public static void main(String args[]) {
      Main m = new Main();
      m.mainUi(args);
	}
}
