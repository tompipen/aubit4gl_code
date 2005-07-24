/*
 * CuiErrorHandler.java
 *
 */

package org.aubit4gl.cui;

import org.aubit4gl.dbdocumenter.actions.ErrorHandler;
import java.lang.Exception;

/**
 * The error handler used when dbdocumenter is executed in CUI mode.
 *
 * @author  Sergio Ferreira
 */
public class CuiErrorHandler extends ErrorHandler {
    
    /** Creates a new instance of CuiErrorHandler */
    public CuiErrorHandler() {
    }
   
    /**
     * Handle an exception ocurred.
     * 
     * @param The original exception ocurred.
     * @param action The textual description of the action being executed.
     */
    public void handle(Exception e, String action) {
        logger.error(action + " : " + e.getMessage());
    }    
    
}
