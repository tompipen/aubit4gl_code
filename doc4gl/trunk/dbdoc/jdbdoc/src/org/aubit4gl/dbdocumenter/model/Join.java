/*
 * Join.java
 *
 */

package org.aubit4gl.dbdocumenter.model;

/**
 * Define the information of a join between two columns.
 *
 * @author  sergio
 */
public class Join {
    
    /** Holds value of property leftColumn. */
    private Column leftColumn;
    
    /** Holds value of property rightColumn. */
    private Column rightColumn;
    
    /** Creates a new instance of Join */
    public Join() {
    }
    
    /** Getter for property leftColumn.
     * @return Value of property leftColumn.
     *
     */
    public Column getLeftColumn() {
        return this.leftColumn;
    }
    
    /** Setter for property leftColumn.
     * @param leftColumn New value of property leftColumn.
     *
     */
    public void setLeftColumn(Column leftColumn) {
        this.leftColumn = leftColumn;
    }
    
    /** Getter for property rightColumn.
     * @return Value of property rightColumn.
     *
     */
    public Column getRightColumn() {
        return this.rightColumn;
    }
    
    /** Setter for property rightColumn.
     * @param rightColumn New value of property rightColumn.
     *
     */
    public void setRightColumn(Column rightColumn) {
        this.rightColumn = rightColumn;
    }
    
}
