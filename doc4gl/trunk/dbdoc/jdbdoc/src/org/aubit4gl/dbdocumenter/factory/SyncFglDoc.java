/*
 * SyncFglDoc.java
 *
 */

package org.aubit4gl.dbdocumenter.Factory;

import java.sql.Connection;
import org.aubit4gl.dbdocumenter.model.DbDocModel;

/**
 * Syncronize the information with the one that was loaded in a 4gl documentation
 * repository.
 *
 * <BR>From there we can get:
 *    - The table description.
 *    - Business process association
 *
 * @author  sergio
 */
public class SyncFglDoc {
    
    /** Holds value of property override. */
    private boolean override;
    
    /** Holds value of property model. */
    private DbDocModel model;
    
    /** Holds value of property fgldocConnection. */
    private Connection fgldocConnection;
    
    /** Creates a new instance of SyncFglDoc */
    public SyncFglDoc() {
    }
    
    /** Getter for property override.
     * @return Value of property override.
     *
     */
    public boolean isOverride() {
        return this.override;
    }
    
    /** Setter for property override.
     * @param override New value of property override.
     *
     */
    public void setOverride(boolean override) {
        this.override = override;
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
    
    /** Getter for property fgldocConnection.
     * @return Value of property fgldocConnection.
     *
     */
    public Connection getFgldocConnection() {
        return this.fgldocConnection;
    }
    
    /** Setter for property fgldocConnection.
     * @param fgldocConnection New value of property fgldocConnection.
     *
     */
    public void setFgldocConnection(Connection fgldocConnection) {
        this.fgldocConnection = fgldocConnection;
    }
    
}
