/*
 * Column.java
 *
 */

package org.aubit4gl.dbdocumenter.model;

/**
 * The definition of the information that describes a column.
 *
 * @author  Sergio Ferreira
 */
public class Column {
    
    /** Holds value of property name. */
    private String name;
    
    /** Holds value of property dataType. */
    private String dataType;
    
    /** Holds value of property label. */
    private String label;
    
    /** Holds value of property title. */
    private String title;
    
    /** Holds value of property description. */
    private String description;
    
    /** Holds value of property column. */
    private Column[] column;
    
    /** Holds value of property primaryKey. */
    private Column[] primaryKey;
    
    /** Holds value of property foreignKey. */
    private ForeignKey[] foreignKey;
    
    /** Creates a new instance of Column */
    public Column() {
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
    
    /** Getter for property dataType.
     * @return Value of property dataType.
     *
     */
    public String getDataType() {
        return this.dataType;
    }
    
    /** Setter for property dataType.
     * @param dataType New value of property dataType.
     *
     */
    public void setDataType(String dataType) {
        this.dataType = dataType;
    }
    
    /** Getter for property label.
     * @return Value of property label.
     *
     */
    public String getLabel() {
        return this.label;
    }
    
    /** Setter for property label.
     * @param label New value of property label.
     *
     */
    public void setLabel(String label) {
        this.label = label;
    }
    
    /** Getter for property title.
     * @return Value of property title.
     *
     */
    public String getTitle() {
        return this.title;
    }
    
    /** Setter for property title.
     * @param title New value of property title.
     *
     */
    public void setTitle(String title) {
        this.title = title;
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
    
    /** Indexed getter for property column.
     * @param index Index of the property.
     * @return Value of the property at <CODE>index</CODE>.
     *
     */
    public Column getColumn(int index) {
        return this.column[index];
    }
    
    /** Getter for property column.
     * @return Value of property column.
     *
     */
    public Column[] getColumn() {
        return this.column;
    }
    
    /** Indexed setter for property column.
     * @param index Index of the property.
     * @param column New value of the property at <CODE>index</CODE>.
     *
     */
    public void setColumn(int index, Column column) {
        this.column[index] = column;
    }
    
    /** Setter for property column.
     * @param column New value of property column.
     *
     */
    public void setColumn(Column[] column) {
        this.column = column;
    }
    
    /** Indexed getter for property primaryKey.
     * @param index Index of the property.
     * @return Value of the property at <CODE>index</CODE>.
     *
     */
    public Column getPrimaryKey(int index) {
        return this.primaryKey[index];
    }
    
    /** Getter for property primaryKey.
     * @return Value of property primaryKey.
     *
     */
    public Column[] getPrimaryKey() {
        return this.primaryKey;
    }
    
    /** Indexed setter for property primaryKey.
     * @param index Index of the property.
     * @param primaryKey New value of the property at <CODE>index</CODE>.
     *
     */
    public void setPrimaryKey(int index, Column primaryKey) {
        this.primaryKey[index] = primaryKey;
    }
    
    /** Setter for property primaryKey.
     * @param primaryKey New value of property primaryKey.
     *
     */
    public void setPrimaryKey(Column[] primaryKey) {
        this.primaryKey = primaryKey;
    }
    
    /** Indexed getter for property foreignKey.
     * @param index Index of the property.
     * @return Value of the property at <CODE>index</CODE>.
     *
     */
    public ForeignKey getForeignKey(int index) {
        return this.foreignKey[index];
    }
    
    /** Getter for property foreignKey.
     * @return Value of property foreignKey.
     *
     */
    public ForeignKey[] getForeignKey() {
        return this.foreignKey;
    }
    
    /** Indexed setter for property foreignKey.
     * @param index Index of the property.
     * @param foreignKey New value of the property at <CODE>index</CODE>.
     *
     */
    public void setForeignKey(int index, ForeignKey foreignKey) {
        this.foreignKey[index] = foreignKey;
    }
    
    /** Setter for property foreignKey.
     * @param foreignKey New value of property foreignKey.
     *
     */
    public void setForeignKey(ForeignKey[] foreignKey) {
        this.foreignKey = foreignKey;
    }
    
}
