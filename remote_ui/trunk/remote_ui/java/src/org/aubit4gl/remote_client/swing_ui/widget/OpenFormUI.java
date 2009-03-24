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

package org.aubit4gl.remote_client.swing_ui.widget;

import java.awt.Container;

import org.aubit4gl.remote_client.connection.command.Form;
import org.aubit4gl.remote_client.connection.command.Label;
import org.aubit4gl.remote_client.connection.command.OpenForm;

/**
 * Open Form user interface.
 * 
 * Open and show a form in the current window.
 * TODO : 
 *   When the fields are opened they should be disabled and became enabled when
 *   an INPUT or CONSTRUCT statement is executed.
 * 
 * @author Sérgio Ferreira
 */
public class OpenFormUI {
	private OpenForm openForm;
	private Form form;
	private FormUI formUI;

	public OpenFormUI(Container container,OpenForm _openForm) {
		openForm = _openForm;
		form = openForm.getForm();
		form.agregateLabels();
		
		formUI = new FormUI(container,form);
	}

	public FormUI getFormUI() {
		return formUI;
	}
}
