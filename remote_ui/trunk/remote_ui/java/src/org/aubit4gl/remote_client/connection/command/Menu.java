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
 * Command sended by the 4gl program that instruct the client to show an 
 * interact with a menu.
 * 
 * The menu waits for some answer that should be done with <TRIGGERED>
 * 
 * 
 * @author Sérgio Ferreira
 */
public class Menu implements ClientUICommand {
	private int context;
	private String title;
	private ArrayList<MenuCommand> menuCommands = new ArrayList<MenuCommand>();

	public Menu() {
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
	 * TODO : Implement the loading of the XML
	 * 
	 * @param dom The Document Object Model that contains the information
	 * @throws FGLUIException 
	 */
	public void initFromDom(Element dom) throws FGLUIException {
		context = Integer.parseInt(dom.getAttribute("CONTEXT"));
		title = dom.getAttribute("TITLE");
		NodeList commandTags = dom.getElementsByTagName("MENUCOMMAND");
		int commandCount = commandTags.getLength(); 
		for ( int i = 0 ; i < commandCount ; i++ ) {
			Element commandTag = (Element) commandTags.item(i);
			MenuCommand cmd = new MenuCommand(
					Integer.parseInt(commandTag.getAttribute("CONTEXT")),
					new Key(commandTag.getAttribute("KEYS")),
					Integer.parseInt(commandTag.getAttribute("ID")),
					commandTag.getAttribute("TEXT"),
					commandTag.getAttribute("DESCRIPTION"),
					Integer.parseInt(commandTag.getAttribute("HELPNO"))
			);
			menuCommands.add(cmd);
		}
		fixMenuKeys();
	}
	
	/**
	 * Check the keys that the menus should answer.
	 * The keys are choosed in the folowing way:
	 *   1 - The specific key(s) in the MENU COMMAND
	 *   2 - The first key in the each option
	 *   3 - If the first is allready used try another
	 *   
	 *   TODO : Finish the implementation.
	 */
	private void fixMenuKeys() {
		
	}

	/**
	 * TODO : Implement it
	 */
	public String toString() {
		StringBuffer str = new StringBuffer("Menu[title='" + title);
		for (MenuCommand command : menuCommands ) {
			str.append("command='");
			str.append(command.getText());
			str.append("'");
		}
		str.append("]");
		return str.toString();
	}

	public int getContext() {
		return context;
	}

	public void setContext(int context) {
		this.context = context;
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public ArrayList<MenuCommand> getMenuCommands() {
		return menuCommands;
	}

	public void setMenuCommands(ArrayList<MenuCommand> menuCommands) {
		this.menuCommands = menuCommands;
	}
}
