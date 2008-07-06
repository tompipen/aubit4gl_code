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

import org.w3c.dom.Element;

/**
 * Options 4gl statement sended from the 4gl server program to the UI client
 * 
 * @author Sérgio Ferreira
 *
 */
public class Option {
	String type;
	String value;

	/**
	 * Default constructor.
	 */
	public Option() {
	}
	
	/**
	 * Initialize the UI command from the corresponding element on the
	 * DOM.
	 * 
	 * @param dom The Document Object Model that contains the information
	 */
	public void initFromDom(Element dom) {
		type = dom.getAttribute("TYPE");
		value = dom.getAttribute("VALUE");
	}
	
	/**
	 * TODO : Implement it. This should work with events
	 */
	public void execute() {
	}

	public String getType() {
		return type;
	}

	public String getValue() {
		return value;
	}
	
	
}
