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
 * A key identification for getting interaction of the user from the 
 * keyboard.
 * 
 * This is to be used on the user interact command received from the server. 
 * 
 * TODO : Implement a table of keys 
 * TODO : Implement the keys
 * TODO : Have an integer codification of key(s) - Use an hash function
 * 
 * @author Sergio Ferreira
 *
 */
public class Key {
	String key;
	int keyCode;
	public Key(String _key) {
		key = _key;
	}
	
	/**
	 * TODO : Implement it
	 */
	private int encodeKey(String key) {
		return 0;
	}
	
	/**
	 * TODO : Implement it
	 * @param _keyCode
	 * @return
	 */
	private String decodeKey(int _keyCode) {
		return "";
	}
}
