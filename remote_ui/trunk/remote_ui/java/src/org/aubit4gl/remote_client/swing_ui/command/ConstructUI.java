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

package org.aubit4gl.remote_client.swing_ui.command;

import org.aubit4gl.remote_client.connection.command.Construct;

/**
 * The construct is used to that the user can make a Query by Example.
 * 
 * When executed it should:
 *   - Activate all fields in the field list received in the CONSTRUCT command
 *   - Add events to all fields
 *   - Activate is own events:
 *     * ACCEPT KEY
 *     * INTERRUPT
 *     * BREAK
 *   
 *   TODO : Implement the construct command received by 4gl
 *   TODO : Implement the behaviour of this User Interface command
 *   
 * @author Sérgio
 *
 */
public class ConstructUI {
  public ConstructUI(Construct construct) {
	  
  }
}
