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

import java.io.IOException;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.HashMap;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.aubit4gl.remote_client.connection.command.ProgramStartup;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;

/**
 * Utility class to make the conversion between the XML and 
 * object representation.
 * 
 * Its here that every command received from the 4gl program should be added.
 * 
 * @author Sérgio Ferreira
 *
 */
public class UICommandBuilder {
	// TODO : Add logger with java.util.logging 
	ArrayList<ClientUICommand> cmdList = new ArrayList<ClientUICommand>();
	
	// Equivalence table of elements and classes that load the object
	HashMap<String, String> elements = new HashMap<String,String>();
	String xmlCmd;
	Document doc;

	/**
	 * @param xmlCommand An XML representation of a UI command 
	 */
	public UICommandBuilder(String xmlCommand) {
		initElementTable();
		xmlCmd = xmlCommand;
	}

	/**
	 * Get the command in object representation.
	 * Put the command on a DOM, analize it and instantiate the corresponding
	 * object.
	 * 
	 * TODO : Implement the DOM loading/parsing and the object instantiation.
	 * 
	 * @return The object with the command.
	 * @throws FGLUIException 
	 */
	public ArrayList<ClientUICommand> getCommands() throws FGLUIException {
		loadDom();
		convertToUiCommands();
		return cmdList;
	}
	
	/**
	 * Load the Document Object Model with the result of the XML strin
	 * parse. 
	 * @throws FGLUIException 
	 */	
	private void loadDom() throws FGLUIException {
		try {
			// Loading the xml string into a DOM
			DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
			DocumentBuilder builder = factory.newDocumentBuilder();
			doc = builder.parse(new InputSource(new StringReader(xmlCmd)));
			System.out.println("XML to be readed " + xmlCmd);
		} catch (SAXException e) {
			throw new FGLUIException("Error parsing XML command: " + e.getMessage());
			// TODO Add logging
		} catch (ParserConfigurationException e) {
			throw new FGLUIException("Error on XML parser configuration: " + e.getMessage());
			// TODO Add logging
		} catch (IOException e) {
			throw new FGLUIException("IO Error reading XML to DOM: " + e.getMessage());
			// TODO Add logging
		}	
	}
	
	/**
	 * Analise the content of the dom and generate the proper
	 * UICommand objects that will be inserted on a list.
	 */
	private void convertToUiCommands() {
		// Get the Envelope
		Element root = doc.getDocumentElement();
		
		// Number of command(s)
		// TODO : Should check if there are other different then command
		NodeList commandTags = root.getChildNodes();
		int commandCount = commandTags.getLength();
		for ( int i = 0 ; i < commandCount ; i++ ) {
			Node kid =  commandTags.item(i);
			if ( ! ( kid instanceof Element) )
				continue;
			Element commandTag = (Element) commandTags.item(i);
			NodeList commands = commandTag.getChildNodes();
			for ( int j=0; j < commands.getLength() ;  j++) {
				kid =  commands.item(j);
				if ( ! (kid instanceof Element) )
					continue;
				Element command = (Element) kid;
				ClientUICommand cmd = loadCommand(command);
				if ( cmd != null )
					cmdList.add(cmd);
			}
		}
		
	}
	
	/**
	 * Load a command from a DOM part to an object representation.
	 * 
	 * TODO : The exceptions should be treated in a proper way.
	 * @param command The DOM representation of a single command
	 * @return An object representation of the command
	 */
	private ClientUICommand loadCommand(Element command) {
		//ClientUICommand _cmd = null;
		
		// I should use an hash to get the class to intantiate
		String tagName = command.getTagName();

		// Get the class from the hash that make the correspondence between XML and class name
		String className = elements.get(tagName);
		if ( className == null ) {
			System.out.println("Command for tag " + tagName + " not found on command list");
			// TODO : Should throw an exception
			return null;
		}
		
		Class cls = null;
		try {
			cls = Class.forName(className);
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		ClientUICommand uiCmd = null;
		try {
			uiCmd = (ClientUICommand) cls.newInstance();
		} catch (InstantiationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		try {
		   uiCmd.initFromDom(command);
		} catch (FGLUIException e) {
			// TODO : I should make something with this
		}
		
		return uiCmd;
	}
	
	
	/**
	 * Initialize the element table
	 * Every  command should be added here to the hash table.
	 */
	private void initElementTable() {
		elements.put("PROGRAMSTARTUP", addCmdPackage("ProgramStartup"));
		elements.put("PROGRAMSTOP", addCmdPackage("ProgramStop"));
		elements.put("DISPLAY", addCmdPackage("Display"));
		elements.put("DISPLAYAT", addCmdPackage("DisplayAt"));
		elements.put("MENU", addCmdPackage("Menu"));
		elements.put("WAITFOREVENT", addCmdPackage("WaitForEvent"));
		elements.put("FREE", addCmdPackage("Free"));
		elements.put("OPENWINDOW", addCmdPackage("OpenWindow"));
		elements.put("CURRENTWINDOW", addCmdPackage("CurrentWindow"));
		elements.put("CLEARWINDOW", addCmdPackage("ClearWindow"));
		elements.put("OPENFORM", addCmdPackage("OpenForm"));
		elements.put("CLOSEFORM", addCmdPackage("CloseForm"));
		elements.put("CLOSEWINDOW", addCmdPackage("CloseWindow"));
		elements.put("ERROR", addCmdPackage("ErrorCmd"));
		elements.put("MESSAGE", addCmdPackage("Message"));
		elements.put("PROMPT", addCmdPackage("Prompt"));
		elements.put("DISPLAYFORM", addCmdPackage("DisplayForm"));
		elements.put("INPUT", addCmdPackage("Input"));
	}
	
	/**
	 * Add the namespace of the command to be loaded with introspection.
	 * @param cmd
	 * @return
	 */
	private String addCmdPackage(String cmd) {
		return "org.aubit4gl.remote_client.connection.command." + cmd;
	}
}
