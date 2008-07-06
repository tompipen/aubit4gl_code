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
import java.awt.Dimension;
import java.util.ArrayList;

import org.aubit4gl.remote_client.connection.command.Field;
import org.aubit4gl.remote_client.connection.command.Form;
import org.aubit4gl.remote_client.connection.command.Label;

/**
 * A form shown in the screen.
 * This will be the responsible for the User Interface of a form in 
 * a screen window.
 * 
 * @author Sérgio Ferreira
 */
public class FormUI {
	private Form form;
	private ArrayList<LabelUI> labels = new ArrayList<LabelUI>();
	private ArrayList<FieldUI> fields = new ArrayList<FieldUI>();
	
	/**
	 * Constructor of a form user interface
	 * The container where the components should be added use the TableLayout
	 * This way the fields and labels can be added directly on the
	 * column and row.
	 * 
	 * @param container The container where the form is shown.
	 * @param _form The form information to be shown.
	 */
	public FormUI(Container container,Form _form) {
		form = _form;
		for ( Label label : form.getLabels() ) {
			LabelUI labelUI = new LabelUI(label);
			labels.add(labelUI);
			int startLine = label.getRow();
			int startCol = label.getColumn();
			int endLine = label.getRow();
			int endCol = label.getColumn() + label.getText().length();
			String pos = startCol + ", " + startLine + ", " + endCol + ", " + endLine;
			container.add(labelUI,pos);
		}
		for ( Field field : form.getFields() ) {
			FieldUI fieldUI = new FieldUI(field);
			fields.add(fieldUI);
			int startLine = field.getRow();
			int startCol = field.getColumn();
			int endLine = field.getRow();
			int endCol = field.getColumn() + field.getCols();
			String pos = startCol + ", " + startLine + ", " + endCol + ", " + endLine;
			container.add(fieldUI,pos);
			//fieldUI.setPreferredSize(new Dimension(9,17));
		}	
		container.repaint();
	}
}
