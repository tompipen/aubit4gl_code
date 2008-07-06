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
 * Representation of 4gl command CloseForm
 * TODO Document it
 * TODO Test it
 * TODO Review the code
 * TODO Add to command table
 * TODO I need to handle the attributes very soon
 * @author Sérgio Ferreira
 */
public class ErrorCmd implements ClientUICommand {
	private String message;
	
	public void execute() {
		// TODO Auto-generated method stub
	}

	public String getXml() {
		// TODO Auto-generated method stub
		return null;
	}
	
	public void initFromDom(Element dom) {
		// window = dom.getAttribute("WINDOW");
		// TODO : Need to handle the attributes
		message = dom.getTextContent();
	}

	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}
}