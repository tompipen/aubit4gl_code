/*
 * ErrorHandler.java
 *
 */

package org.aubit4gl.dbdocumenter.actions;

import org.apache.log4j.Category;

/**
 * Interface that a specific error handler must implement.
 * This interface exist(s) because the tool can be executed in 
 * GUI and(or) CUI mode.
 *
 * @author  Sergio Ferreira
 */
public abstract class ErrorHandler {
    
    //static Category logger = Category.getInstance(ErrorHandler.class.getName());
    public Category logger = Category.getInstance(ErrorHandler.class.getName());
    public abstract void handle(Exception e, String action);
}
