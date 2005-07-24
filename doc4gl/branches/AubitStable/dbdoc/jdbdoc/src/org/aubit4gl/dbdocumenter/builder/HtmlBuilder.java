/*
 * HtmlBuilder.java
 *
 */

package org.aubit4gl.dbdocumenter.builder;

import org.aubit4gl.dbdocumenter.model.DbDocModel;

/**
 * Build an html file tree based on a database documenter module.
 *
 * @author  sergio
 */
public class HtmlBuilder {
    
    /** Holds value of property model. */
    private DbDocModel model;
    
    /** Creates a new instance of HtmlBuilder */
    public HtmlBuilder() {
    }
    
    /** Getter for property model.
     * @return Value of property model.
     *
     */
    public DbDocModel getModel() {
        return this.model;
    }
    
    /** Setter for property model.
     * @param model New value of property model.
     *
     */
    public void setModel(DbDocModel model) {
        this.model = model;
    }
    
}
