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
import org.aubit4gl.remote_client.connection.FGLUIException;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * Command sended by the 4gl program that instruct the client to show a form
 * 
 * @author Sérgio Ferreira
 */
public class OpenForm implements ClientUICommand {
	private String name;
	private Form form;

	public OpenForm() {
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
	 * @throws FGLUIException 
	 */
	public void initFromDom(Element dom) throws FGLUIException {
		name = dom.getAttribute("FORM");
		form = new Form();

		NodeList commandTags = dom.getChildNodes();
		int commandCount = commandTags.getLength();
		Node formDom = null;
		for ( int i = 0 ; i < commandCount ; i++ ) {
			formDom =  commandTags.item(i);

			if ( formDom instanceof Element && ((Element)formDom).getNodeName().equals("FORM"))
				break;
		}
		if ( formDom == null )
			throw new FGLUIException("Did not found any form in OpenForm command ");
		form.initFromDom((Element)formDom);
	}

	/**
	 * TODO : Implement it
	 */
	public String toString() {
		StringBuffer str = new StringBuffer("OpenForm[name='" + name);
		return str.toString();
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Form getForm() {
		return form;
	}

	public void setForm(Form form) {
		this.form = form;
	}


}
