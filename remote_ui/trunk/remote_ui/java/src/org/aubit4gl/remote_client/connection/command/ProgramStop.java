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

package org.aubit4gl.remote_client.connection.command;

import org.aubit4gl.remote_client.connection.ClientUICommand;
import org.w3c.dom.Element;

public class ProgramStop implements ClientUICommand {
	private int id;
	private int exitCode;

	public ProgramStop() {
		super();
	}
	
	public ProgramStop(int id, int exitCode) {
		super();
		this.id = id;
		this.exitCode = exitCode;
	}

	public void execute() {
		// TODO Auto-generated method stub
	}

	public String getXml() {
		StringBuffer xml = new StringBuffer();
		xml.append("<PROGRAMSTOP \" ID =\"" + id + "\" EXITCODE=\"" + exitCode + "\"/>");
		return xml.toString();
	}

	public void initFromDom(Element dom) {
		id = Integer.parseInt(dom.getAttribute("ID"));
		exitCode = Integer.parseInt(dom.getAttribute("EXITCODE"));
	}

	public int getId() {
		return id;
	}

	public int getExitCode() {
		return exitCode;
	}
	
	public String toString() {
		return "ProgramStop[exitCode=" + exitCode + ",id=" + id + "]";
	}

}
