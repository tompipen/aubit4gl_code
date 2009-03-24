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

import org.aubit4gl.remote_client.connection.command.Input;

/**
 * The command INPUT was asked to be executed from the 4gl server program.
 * When this happens the input should know:
 *   - The current form 
 * And should:
 *   - Turn the fields received in the list enabled
 *   - Add event(s) to each field that correspond to the events that should answer to:
 *     BEFORE FIELD
 *     AFTER FIELD
 *     ON KEY
 *   - Answer to his events:
 *     ACCEPT KEY
 *     DELETE KEY (CONTROL-C by default)
 *     BREAK KEY (CONTROL| by default)
 *     BEFORE INPUT
 *     AFTER INPUT
 *   - Return the buffer (to fgl_lastkey() function) when answer to 4gl program. 
 *     
 *   When the input is finished should answer to 4gl and disable the fields that where enabled
 *   
 *   TODO : Implement all command 
 * @author Sergio Ferreira
 *
 */
public class InputUI {

	public InputUI(Input input) {
		
	}
}
