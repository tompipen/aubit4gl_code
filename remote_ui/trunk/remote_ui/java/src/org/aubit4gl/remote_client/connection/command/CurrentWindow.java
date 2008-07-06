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

/**
 * Definition of current window screen interaction instruction
 * 
 * @author Sérgio Ferreira
 *
 * TODO : Implement
 * TODO : Make a unit test for this instruction
 * TODO : Make the toString()
 *
 */
public class CurrentWindow implements ClientUICommand {
	private String window;

	public void execute() {
		// TODO Auto-generated method stub
	}
	
	public String getXml() {
		// TODO Auto-generated method stub
		return null;
	}
	
	public void initFromDom(Element dom) {
		window = dom.getAttribute("WINDOW");
	}
	
	public String getWindow() {
		return window;
	}

	public void setWindow(String window) {
		this.window = window;
	}

}
