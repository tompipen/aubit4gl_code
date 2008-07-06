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
import org.w3c.dom.NodeList;

/**
 * 4gl Prompt command information.
 * 
 * TODO : Implement the attributes
 * TODO : Implement the missing methods
 * TODO : Implement the events
 * 
 * @author Sérgio Ferreira
 */
public class InputArray implements ClientUICommand {
	private int context;
	private ArrayList<Attribute> attributes = new ArrayList<Attribute>();
	private int arrCount;
	private int maxArrSize;
	private boolean withoutDefaults;
	private ArrayList<String> fieldList = new ArrayList<String>();
	// TODO : Add events that this command is waiting for
	private ArrayList<Event> events = new ArrayList<Event>();
	
	public InputArray() {
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
	 * TODO : Implement it
	 */
	public String toString() {
		return "";
	}

	/**
	 * Initialize the UI command from the corresponding element on the
	 * DOM.
	 * 
	 * TODO : Implement the loading of the XML
	 * 
	 * @param dom The Document Object Model that contains the information
	 * @throws FGLUIException 
	 */
	public void initFromDom(Element dom) throws FGLUIException {
		context = Integer.parseInt(dom.getAttribute("CONTEXT"));
		arrCount = Integer.parseInt(dom.getAttribute("ARRCOUNT"));
		maxArrSize = Integer.parseInt(dom.getAttribute("MAXARRSIZE"));
		int wd = Integer.parseInt(dom.getAttribute("WITHOUT_DEFAULTS"));
		if ( wd == 1)
			withoutDefaults = true;
		else
			withoutDefaults = false;
		// TODO : Must get the attributes
		// TODO : Check if I need to get FIELDLIST first
		NodeList commandTags = dom.getElementsByTagName("FIELD");
		int commandCount = commandTags.getLength(); 
		for ( int i = 0 ; i < commandCount ; i++ ) {
			Element fieldTag = (Element) commandTags.item(i);
			fieldList.add(fieldTag.getAttribute("NAME"));
		}
		// TODO : Must get the events
	}
}

