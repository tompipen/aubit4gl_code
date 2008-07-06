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

import java.util.Comparator;
import org.aubit4gl.remote_client.connection.ClientUICommand;
import org.aubit4gl.remote_client.connection.FGLUIException;
import org.w3c.dom.Element;

/**
 * Represent a label of text in a form received to be shown in the User Interface 
 * 
 * @author Sergio Ferreira
 */
public class Label implements ClientUICommand, Comparator<Label>, Comparable<Label> {
    private int row;
    private int column;
    private String text;
    
	
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
		text = dom.getTextContent();
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

	public String getText() {
		return text;
	}

	public void setText(String text) {
		this.text = text;
	}


    public int compare(Label l0, Label l1) {
        int ret = l0.getRow() - l1.getRow();
        if( ret == 0 )
            return l0.getColumn() - l1.getColumn();
        
        return ret;
    }

    public int compareTo(Label arg0) {
       return compare( this, arg0);
    }
	
}
