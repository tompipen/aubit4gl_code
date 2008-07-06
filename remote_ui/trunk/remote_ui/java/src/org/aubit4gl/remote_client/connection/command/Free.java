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

import java.util.ArrayList;

import org.aubit4gl.remote_client.connection.ClientUICommand;
import org.w3c.dom.Element;

/**
 * Sended by the 4gl program (acting as a server) to inform the client that  
 * some UI widget should be removed from the screen.
 * 
 * The context is the number of the command that should originate an answer,
 * 
 * 
 * @author Sérgio Ferreira
 */
public class Free implements ClientUICommand {
	private int context;
	private String type;

	public Free() {
		super();
	}

	public void execute() {
		// TODO Auto-generated method stub

	}

	public String getXml() {
		// TODO Auto-generated method stub
		return null;
	}

	/**
	 * Initialize the UI command from the corresponding element on the
	 * DOM.
	 * 
	 * @param dom The Document Object Model that contains the information
	 */
	public void initFromDom(Element dom) {
		context = Integer.parseInt(dom.getAttribute("CONTEXT"));
		type = dom.getAttribute("TYPE");
	}

	public String toString() {
		return "Free[type=" + type + "context=" + context + "]";
	}

	public int getContext() {
		return context;
	}

	public void setContext(int context) {
		this.context = context;
	}

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
	}

}
