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

import java.util.Arrays;
import org.aubit4gl.remote_client.connection.ClientUICommand;
import org.aubit4gl.remote_client.connection.FGLUIException;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * A form description sended by the 4gl program to be shown or
 * interact with the user.
 * 
 * @author Sergio Ferreira
 */
public class Form implements ClientUICommand {

    ArrayList<Label> labels = new ArrayList<Label>();
    ArrayList<Field> fields = new ArrayList<Field>();

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
		
        NodeList labelTags = dom.getElementsByTagName("LABEL");
        int labelCount = labelTags.getLength();
        for (int i = 0; i < labelCount; i++) {
            Element labelTag = (Element) labelTags.item(i);
            Label label = new Label();
            label.initFromDom(labelTag);
            labels.add(label);
        }

        NodeList fieldTags = dom.getElementsByTagName("FIELD");
        int fieldCount = fieldTags.getLength();
        for (int i = 0; i < fieldCount; i++) {
            Element fieldTag = (Element) fieldTags.item(i);
            Field field = new Field();
            field.initFromDom(fieldTag);
            fields.add(field);
        }
    }

    public ArrayList<Label> getLabels() {
        return labels;
    }

    public void setLabels(ArrayList<Label> labels) {
        this.labels = labels;
    }

    /**
     * This method agregates adjacent labels of same row
     */
    public void agregateLabels() {
        final int delta = 1;
        Label[] oldLabels = labels.toArray(new Label[0]);
        ArrayList<Label> newLabels = new ArrayList<Label>();
        Arrays.sort(oldLabels, null);
        if (oldLabels.length == 0) {
            return;
        }
        Label actual = oldLabels[0];
        for (int i = 1; i < oldLabels.length; i++) {
            Label seguinte = oldLabels[i];
            if (actual.getRow() != seguinte.getRow()) {
                newLabels.add(actual);
                actual = seguinte;
            } else {
                int actualEnd = actual.getColumn() + actual.getText().length();
                int diff = seguinte.getColumn() - actualEnd;
                if ( diff <= delta) {
                    actual.setText(actual.getText() + " " + seguinte.getText());
                } else {
                    newLabels.add(actual);
                    actual = seguinte;
                }
            }
        }
        newLabels.add(actual);
        this.labels = newLabels;
    }

    public ArrayList<Field> getFields() {
        return fields;
    }

    public void setFields(ArrayList<Field> fields) {
        this.fields = fields;
    }
}
