/*
 * ForeignKey.java
 *
 */

package org.aubit4gl.dbdocumenter.model;

/**
 * The information that defines a foreign key.
 *
 * @author  Sergio Ferreira
 */
public class ForeignKey {
    
    /** Holds value of property referencedTable. */
    private Table referencedTable;
    
    /** Holds value of property join. */
    private Join[] join;
    
    /** Creates a new instance of ForeignKey */
    public ForeignKey() {
    }
    
    /** Getter for property referencedTable.
     * @return Value of property referencedTable.
     *
     */
    public Table getReferencedTable() {
        return this.referencedTable;
    }
    
    /** Setter for property referencedTable.
     * @param referencedTable New value of property referencedTable.
     *
     */
    public void setReferencedTable(Table referencedTable) {
        this.referencedTable = referencedTable;
    }
    
    /** Indexed getter for property join.
     * @param index Index of the property.
     * @return Value of the property at <CODE>index</CODE>.
     *
     */
    public Join getJoin(int index) {
        return this.join[index];
    }
    
    /** Getter for property join.
     * @return Value of property join.
     *
     */
    public Join[] getJoin() {
        return this.join;
    }
    
    /** Indexed setter for property join.
     * @param index Index of the property.
     * @param join New value of the property at <CODE>index</CODE>.
     *
     */
    public void setJoin(int index, Join join) {
        this.join[index] = join;
    }
    
    /** Setter for property join.
     * @param join New value of property join.
     *
     */
    public void setJoin(Join[] join) {
        this.join = join;
    }
    
}
