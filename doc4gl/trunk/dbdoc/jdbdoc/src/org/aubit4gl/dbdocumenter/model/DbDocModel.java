/*
 * DbDocModel.java
 *
 */

package org.aubit4gl.dbdocumenter.model;

/**
 * Encapsulate all the information about a database model created by a factory.
 * 
 * @todo The table in this class should be an HashMap and not an array.
 *
 * @author  sergio
 */
public class DbDocModel {
    
    /** Holds value of property table. */
    private Table[] table;
    
    /** Holds value of property processTree. */
    private ProcessTree[] processTree;
    
    /** Creates a new instance of DbDocModel */
    public DbDocModel() {
    }
    
    /** Indexed getter for property table.
     * @param index Index of the property.
     * @return Value of the property at <CODE>index</CODE>.
     *
     */
    public Table getTable(int index) {
        return this.table[index];
    }
    
    /** Getter for property table.
     * @return Value of property table.
     *
     */
    public Table[] getTable() {
        return this.table;
    }
    
    /** Indexed setter for property table.
     * @param index Index of the property.
     * @param table New value of the property at <CODE>index</CODE>.
     *
     */
    public void setTable(int index, Table table) {
        this.table[index] = table;
    }
    
    /** Setter for property table.
     * @param table New value of property table.
     *
     */
    public void setTable(Table[] table) {
        this.table = table;
    }
    
    /** Indexed getter for property processTree.
     * @param index Index of the property.
     * @return Value of the property at <CODE>index</CODE>.
     *
     */
    public ProcessTree getProcessTree(int index) {
        return this.processTree[index];
    }
    
    /** Getter for property processTree.
     * @return Value of property processTree.
     *
     */
    public ProcessTree[] getProcessTree() {
        return this.processTree;
    }
    
    /** Indexed setter for property processTree.
     * @param index Index of the property.
     * @param processTree New value of the property at <CODE>index</CODE>.
     *
     */
    public void setProcessTree(int index, ProcessTree processTree) {
        this.processTree[index] = processTree;
    }
    
    /** Setter for property processTree.
     * @param processTree New value of property processTree.
     *
     */
    public void setProcessTree(ProcessTree[] processTree) {
        this.processTree = processTree;
    }
    
}
