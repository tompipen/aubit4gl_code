/*
 * Table.java
 *
 * Created on May 13, 2003, 2:45 PM
 */

package org.aubit4gl.dbdocumenter.model;

/**
 * The information that defines a table.
 *
 * @author  Sergio Ferreira
 */
public class Table {
    
    /** Holds value of property name. */
    private String name;
    
    /** Holds value of property description. */
    private String description;
    
    /** Holds value of property owner. */
    private String owner;
    
    /** Holds value of property database. */
    private String database;
    
    /** Creates a new instance of Table */
    public Table() {
    }
    
    /** Getter for property name.
     * @return Value of property name.
     *
     */
    public String getName() {
        return this.name;
    }
    
    /** Setter for property name.
     * @param name New value of property name.
     *
     */
    public void setName(String name) {
        this.name = name;
    }
    
    /** Getter for property description.
     * @return Value of property description.
     *
     */
    public String getDescription() {
        return this.description;
    }
    
    /** Setter for property description.
     * @param description New value of property description.
     *
     */
    public void setDescription(String description) {
        this.description = description;
    }
    
    /** Getter for property owner.
     * @return Value of property owner.
     *
     */
    public String getOwner() {
        return this.owner;
    }
    
    /** Setter for property owner.
     * @param owner New value of property owner.
     *
     */
    public void setOwner(String owner) {
        this.owner = owner;
    }
    
    /** Getter for property database.
     * @return Value of property database.
     *
     */
    public String getDatabase() {
        return this.database;
    }
    
    /** Setter for property database.
     * @param database New value of property database.
     *
     */
    public void setDatabase(String database) {
        this.database = database;
    }
    
}
