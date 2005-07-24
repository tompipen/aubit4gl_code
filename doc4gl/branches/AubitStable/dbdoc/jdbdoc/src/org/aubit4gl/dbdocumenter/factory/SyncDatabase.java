/*
 * SyncDatabase.java
 *
 */

package org.aubit4gl.dbdocumenter.Factory;

import java.sql.Connection;

/**
 * Synchronize the information in the repository with the structure of the 
 * operational database.
 *
 * Performs the folowing actions:
 *    - If a description it is nott filled, fill it with the db name
 *      changing the _ to spaces and the first letters to uppercase.
 *    - Insert a record to all tables that does not exist.
 *    - Insert a column to all columns that does not exist.
 *
 * @author  Sergio Ferreira
 */
public class SyncDatabase {
    
    /** Holds value of property operationalConnection. */
    private Connection operationalConnection;
    
    /** Creates a new instance of SyncDatabase */
    public SyncDatabase() {
    }
    
    /** Getter for property operationalConnection.
     * @return Value of property operationalConnection.
     *
     */
    public Connection getOperationalConnection() {
        return this.operationalConnection;
    }
    
    /** Setter for property operationalConnection.
     * @param operationalConnection New value of property operationalConnection.
     *
     */
    public void setOperationalConnection(Connection operationalConnection) {
        this.operationalConnection = operationalConnection;
    }
    
}
