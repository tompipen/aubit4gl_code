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
 * Command sended by the 4gl program that instruct the client to show a message
 * on a window.
 * 
 * The message is appended to the last DISPLAY(s) already executed.
 * 
 *  TODO : This command is not implemented. The data is not loaded from the dom
 * 
 * @author Sérgio Ferreira
 */
public class DisplayAt implements ClientUICommand {
	private int x;
	private int y;
	private ArrayList<Attribute> attributes = new ArrayList<Attribute>();
	private String text;

	public DisplayAt() {
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
	 * TODO : Implement the attributes
	 * 
	 * @param dom The Document Object Model that contains the information
	 */
	public void initFromDom(Element dom) {
		text = dom.getTextContent();
		x = Integer.parseInt(dom.getAttribute("X"));
		y = Integer.parseInt(dom.getAttribute("Y"));
		String strAttributes = dom.getAttribute("ATTRIBUTE");
		
		Attribute attribute = new Attribute();
	}

	public String toString() {
		return "DisplayAt[text=" + text + ";x=" + x + ";y=" + y + "]";
	}

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public ArrayList<Attribute> getAttributes() {
		return attributes;
	}

	public void setAttributes(ArrayList<Attribute> attributes) {
		this.attributes = attributes;
	}

	public String getText() {
		return text;
	}

	public void setText(String text) {
		this.text = text;
	}
}
