/*
 * ScriptRepository.java
 *
 */

package org.aubit4gl.dbdocumenter.repository;

/**
 * Create the repository into an SQL script.
 * @author  sergio
 */
public class ScriptRepository extends RepositoryStructure {
    
    /** Holds value of property fileName. */
    private String fileName;
    
    /** Creates a new instance of ScriptRepository */
    public ScriptRepository() {
    }
    
    /** Getter for property fileName.
     * @return Value of property fileName.
     *
     */
    public String getFileName() {
        return this.fileName;
    }
    
    /** Setter for property fileName.
     * @param fileName New value of property fileName.
     *
     */
    public void setFileName(String fileName) {
        this.fileName = fileName;
    }
    
    public void create() {
        
        // Check if the file name exist
        // Open the stream
        StringBuffer str = new StringBuffer();

        // Write the strings to the stream
        str.append(getSqlDatabase() + "\n");
        str.append(getSqlDropTables() + "\n");
        str.append(getSqlExtendedTable() + "\n");
        str.append(getSqlExtendedColumn() + "\n");
        str.append(getSqlBusinessProcess() + "\n");
        str.append(getSqlTableBP() + "\n");
    }
}
