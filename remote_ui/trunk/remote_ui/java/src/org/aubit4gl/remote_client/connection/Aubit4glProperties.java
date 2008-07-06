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

public class Aubit4glProperties {
   // The port used to connect to the 4gl 
   private int port = 3490;
   
   // Port used to receive incoming connections
   private int returnPort = 1300;

public int getPort() {
	return port;
}

public void setPort(int port) {
	this.port = port;
}

public int getReturnPort() {
	return returnPort;
}

public void setReturnPort(int returnPort) {
	this.returnPort = returnPort;
}
   
}
