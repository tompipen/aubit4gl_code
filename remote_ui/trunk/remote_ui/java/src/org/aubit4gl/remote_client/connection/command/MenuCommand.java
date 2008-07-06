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

/**
 * The menu command information. This is to be used inside the 
 * UI Command for MENU. 
 * 
 * @author Sérgio Ferreira
 *
 */
public class MenuCommand {
	private int context;
	private Key key;
	private int id;
	private String text;
	private String description;
	private int helpNumber;
	public int getContext() {
		return context;
	}
	public void setContext(int context) {
		this.context = context;
	}
	public Key getKey() {
		return key;
	}
	public void setKey(Key key) {
		this.key = key;
	}
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getText() {
		return text;
	}
	public void setText(String text) {
		this.text = text;
	}
	public String getDescription() {
		return description;
	}
	public void setDescription(String description) {
		this.description = description;
	}
	public int getHelpNumber() {
		return helpNumber;
	}
	public void setHelpNumber(int helpNumber) {
		this.helpNumber = helpNumber;
	}
	public MenuCommand(int context, Key key, int id, String text,
			String description, int helpNumber) {
		super();
		this.context = context;
		this.key = key;
		this.id = id;
		this.text = text;
		this.description = description;
		this.helpNumber = helpNumber;
	}
}
