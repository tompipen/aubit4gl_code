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

import org.aubit4gl.remote_client.connection.command.ProgramStop;

public class MainTest {
	Connection conn;
	
	public static void main(String args[]) {
		MainTest m = new MainTest();
		m.exec();
	}
	
	public void exec() {
		String host = "192.168.152.128";
        String user = "sergio";
        String password = "jfola45";
        String program = "./test_aubit.sh";
        //program = "ls";

		try {
			conn = DriverManager.getConnection(host,user,password,program);
		} catch (FGLUIException e) {
			System.err.println("Cannot execute 4gl program " + e.getMessage());
		}
		
		UICommand recCmd = null;
		try {
			 recCmd = conn.receive();
			System.out.println("Command received " + recCmd);
			recCmd =  conn.receive();
			System.out.println("Command received " + recCmd);
			recCmd =  conn.receive();
			System.out.println("Command received " + recCmd);
		} catch (FGLUIException e) {
			System.err.println("Did not received any command : " + e.getMessage());
		}
	}
}
