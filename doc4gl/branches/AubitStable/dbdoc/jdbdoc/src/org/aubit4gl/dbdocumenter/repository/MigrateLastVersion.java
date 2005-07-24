/*
 * MigrateLastVersion.java
 *
 */

package org.aubit4gl.dbdocumenter.repository;

import java.sql.Connection;

/**
 * Migrate the last version of the dbdocumenter in perl, and his repository 
 * format to the new one.
 *
 * @author  sergio
 */
public class MigrateLastVersion {
    
    /** Holds value of property oldRepConnection. */
    private Connection oldRepConnection;
    
    /** Holds value of property newRepConnection. */
    private Connection newRepConnection;
    
    /** Creates a new instance of MigrateLastVersion */
    public MigrateLastVersion() {
    }
    
    /** Getter for property oldRepConnection.
     * @return Value of property oldRepConnection.
     *
     */
    public Connection getOldRepConnection() {
        return this.oldRepConnection;
    }
    
    /** Setter for property oldRepConnection.
     * @param oldRepConnection New value of property oldRepConnection.
     *
     */
    public void setOldRepConnection(Connection oldRepConnection) {
        this.oldRepConnection = oldRepConnection;
    }
    
    /** Getter for property newRepConnection.
     * @return Value of property newRepConnection.
     *
     */
    public Connection getNewRepConnection() {
        return this.newRepConnection;
    }
    
    /** Setter for property newRepConnection.
     * @param newRepConnection New value of property newRepConnection.
     *
     */
    public void setNewRepConnection(Connection newRepConnection) {
        this.newRepConnection = newRepConnection;
    }
    
    /**
     * Execute the migration 
     */
    void migrate() {
        migrateSystableExt();
        migrateSysColumnExt();
        migrateModules();
        migrateTableModules();
    }
    
    /** 
     * Create the information of systableext in the new table
     */
    private void migrateSystableExt() {
        String selSTE = " select owner, tabname, extowner, tabalias, remarks " +
          " from systableext";
        
    }
    
    private void migrateSysColumnExt() {
    }
    
    private void migrateModules() {
    }
    
    private void migrateTableModules() {
    }
}
