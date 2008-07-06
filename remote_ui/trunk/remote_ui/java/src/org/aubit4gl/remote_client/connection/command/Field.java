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

import org.aubit4gl.remote_client.connection.ClientUICommand;
import org.aubit4gl.remote_client.connection.FGLUIException;
import org.w3c.dom.Element;

public class Field implements ClientUICommand {
	    private int row;
	    private int column;
	    private int rows;
	    private int cols;
	    // TODO The widget should be a class
	    private String widget;
	    // TODO : Config should be decoded
	    private String config;
	    // TODO Include should be a class or collection properly decoded
	    private String include;
	    private int id;
	    private Column tableColumn;
	    // TODO : Action should be a class
	    private String action;
	    
		
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
			row = Integer.parseInt(dom.getAttribute("ROW"));
			column = Integer.parseInt(dom.getAttribute("COLUMN"));
			rows = Integer.parseInt(dom.getAttribute("ROWS"));
			cols = Integer.parseInt(dom.getAttribute("COLS"));
			widget = dom.getAttribute("WIDGET");
			config = dom.getAttribute("CONFIG");
			include = dom.getAttribute("INC");
			id = Integer.parseInt(dom.getAttribute("ID"));
			tableColumn = new Column(dom.getAttribute("TABCOL"));
			action = dom.getAttribute("ACTION");
		}

		public int getRow() {
			return row;
		}

		public void setRow(int row) {
			this.row = row;
		}

		public int getColumn() {
			return column;
		}

		public void setColumn(int column) {
			this.column = column;
		}

		public int getRows() {
			return rows;
		}

		public void setRows(int rows) {
			this.rows = rows;
		}

		public int getCols() {
			return cols;
		}

		public void setCols(int cols) {
			this.cols = cols;
		}

		public String getWidget() {
			return widget;
		}

		public void setWidget(String widget) {
			this.widget = widget;
		}

		public String getConfig() {
			return config;
		}

		public void setConfig(String config) {
			this.config = config;
		}

		public String getInclude() {
			return include;
		}

		public void setInclude(String include) {
			this.include = include;
		}

		public int getId() {
			return id;
		}

		public void setId(int id) {
			this.id = id;
		}

		public Column getTableColumn() {
			return tableColumn;
		}

		public void setTableColumn(Column tableColumn) {
			this.tableColumn = tableColumn;
		}

		public String getAction() {
			return action;
		}

		public void setAction(String action) {
			this.action = action;
		}
}
