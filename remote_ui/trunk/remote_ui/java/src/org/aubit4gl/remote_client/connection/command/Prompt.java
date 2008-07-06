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

/**
 * 4gl Prompt command information.
 * 
 * TODO : Implement the attributes
 * TODO : Implement the missing methods
 * TODO : Implement the events
 * 
 * @author Sérgio Ferreira
 */
public class Prompt implements ClientUICommand {
	private int context;
	private ArrayList<Attribute> attributes = new ArrayList<Attribute>();
	private ArrayList<Attribute> fieldAttributes = new ArrayList<Attribute>();
	private String text;
	private boolean charMode;
	private int helpNumber;
	//private ArrayList<Event> events = new ArrayList<Event>;
	
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
	 * TODO : Add the attributes
	 * 
	 * @param dom The Document Object Model that contains the information
	 * @throws FGLUIException 
	 */
	public void initFromDom(Element dom) throws FGLUIException {
		context = Integer.parseInt(dom.getAttribute("CONTEXT"));
		text = dom.getAttribute("TEXT");
		int intCharMode = Integer.parseInt(dom.getAttribute("CONTEXT"));
		if ( intCharMode == 0)
			charMode = false;
		else
			charMode = true;
		helpNumber = Integer.parseInt(dom.getAttribute("HELPNO"));
	}

	public int getContext() {
		return context;
	}

	public void setContext(int context) {
		this.context = context;
	}

	public ArrayList<Attribute> getAttributes() {
		return attributes;
	}

	public void setAttributes(ArrayList<Attribute> attributes) {
		this.attributes = attributes;
	}

	public ArrayList<Attribute> getFieldAttributes() {
		return fieldAttributes;
	}

	public void setFieldAttributes(ArrayList<Attribute> fieldAttributes) {
		this.fieldAttributes = fieldAttributes;
	}

	public String getText() {
		return text;
	}

	public void setText(String text) {
		this.text = text;
	}

	public boolean isCharMode() {
		return charMode;
	}

	public void setCharMode(boolean charMode) {
		this.charMode = charMode;
	}

	public int getHelpNumber() {
		return helpNumber;
	}

	public void setHelpNumber(int helpNumber) {
		this.helpNumber = helpNumber;
	}
}
