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

import org.w3c.dom.Element;

/**
 * Definition of an open window instruction.
 * 
 * @author Sérgio Ferreira
 * 
 * TODO : No test for this command available
 *
 */
public class OpenWindow {
	private String name;
	private int x;
	private int y;
	private int width;
	private int heigth;
	private int formLine;
	private int errorLine;
	private int promptLine;
	private int menuLine;
	private int commentLine;
	private int messageLine;
	private boolean border;
	ArrayList<Attribute> attributes;
	String style;
	private String text;
	
	/**
	 * Initialize the UI command from the corresponding element on the
	 * DOM.
	 * 
	 * @param dom The Document Object Model that contains the information
	 */
	public void initFromDom(Element dom) {
		name = dom.getAttribute("NAME");
		x = Integer.parseInt(dom.getAttribute("X"));
		y = Integer.parseInt(dom.getAttribute("Y"));
		width = Integer.parseInt(dom.getAttribute("W"));
		heigth = Integer.parseInt(dom.getAttribute("H"));
		formLine = Integer.parseInt(dom.getAttribute("FORMLINE"));
		errorLine = Integer.parseInt(dom.getAttribute("ERRORLINE"));
		promptLine = Integer.parseInt(dom.getAttribute("PROMPTLINE"));
		menuLine = Integer.parseInt(dom.getAttribute("MENULINE"));
		messageLine = Integer.parseInt(dom.getAttribute("MESSAGELINE"));
		if ( Integer.parseInt(dom.getAttribute("BORDER")) == 1)
			border = true;
		else
			border = false;
		// TODO : Attributes
		style = dom.getAttribute("STYLE");
		text = dom.getAttribute("TEXT");
	}

	// TODO : Implement the toString
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
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

	public int getWidth() {
		return width;
	}

	public void setWidth(int width) {
		this.width = width;
	}

	public int getHeigth() {
		return heigth;
	}

	public void setHeigth(int heigth) {
		this.heigth = heigth;
	}

	public int getFormLine() {
		return formLine;
	}

	public void setFormLine(int formLine) {
		this.formLine = formLine;
	}

	public int getErrorLine() {
		return errorLine;
	}

	public void setErrorLine(int errorLine) {
		this.errorLine = errorLine;
	}

	public int getPromptLine() {
		return promptLine;
	}

	public void setPromptLine(int promptLine) {
		this.promptLine = promptLine;
	}

	public int getMenuLine() {
		return menuLine;
	}

	public void setMenuLine(int menuLine) {
		this.menuLine = menuLine;
	}

	public int getCommentLine() {
		return commentLine;
	}

	public void setCommentLine(int commentLine) {
		this.commentLine = commentLine;
	}

	public int getMessageLine() {
		return messageLine;
	}

	public void setMessageLine(int messageLine) {
		this.messageLine = messageLine;
	}

	public boolean isBorder() {
		return border;
	}

	public void setBorder(boolean border) {
		this.border = border;
	}

	public ArrayList<Attribute> getAttributes() {
		return attributes;
	}

	public void setAttributes(ArrayList<Attribute> attributes) {
		this.attributes = attributes;
	}

	public String getStyle() {
		return style;
	}

	public void setStyle(String _style) {
		style = _style;
	}

	public String getText() {
		return text;
	}

	public void setText(String text) {
		this.text = text;
	}
}
