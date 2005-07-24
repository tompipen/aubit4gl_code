/*
 * BusinessProcess.java
 *
 */

package org.aubit4gl.dbdocumenter.model;

/**
 * A business process just as defined in the corresponding table from the
 * repository.
 *
 * @author  sergio
 */
public class BusinessProcess {
    
    /** Holds value of property id. */
    private String id;
    
    /** Holds value of property shortDescription. */
    private String shortDescription;
    
    /** Holds value of property longDescription. */
    private String longDescription;
    
    /** Holds value of property comments. */
    private String comments;
    
    /** Holds value of property subProcesses. */
    private BusinessProcess[] subProcesses;
    
    /** Creates a new instance of BusinessProcess */
    public BusinessProcess() {
    }
    
    /** Getter for property id.
     * @return Value of property id.
     *
     */
    public String getId() {
        return this.id;
    }
    
    /** Setter for property id.
     * @param id New value of property id.
     *
     */
    public void setId(String id) {
        this.id = id;
    }
    
    /** Getter for property shortDescription.
     * @return Value of property shortDescription.
     *
     */
    public String getShortDescription() {
        return this.shortDescription;
    }
    
    /** Setter for property shortDescription.
     * @param shortDescription New value of property shortDescription.
     *
     */
    public void setShortDescription(String shortDescription) {
        this.shortDescription = shortDescription;
    }
    
    /** Getter for property longDescription.
     * @return Value of property longDescription.
     *
     */
    public String getLongDescription() {
        return this.longDescription;
    }
    
    /** Setter for property longDescription.
     * @param longDescription New value of property longDescription.
     *
     */
    public void setLongDescription(String longDescription) {
        this.longDescription = longDescription;
    }
    
    /** Getter for property comments.
     * @return Value of property comments.
     *
     */
    public String getComments() {
        return this.comments;
    }
    
    /** Setter for property comments.
     * @param comments New value of property comments.
     *
     */
    public void setComments(String comments) {
        this.comments = comments;
    }
    
    /** Indexed getter for property subProcesses.
     * @param index Index of the property.
     * @return Value of the property at <CODE>index</CODE>.
     *
     */
    public BusinessProcess getSubProcesses(int index) {
        return this.subProcesses[index];
    }
    
    /** Getter for property subProcesses.
     * @return Value of property subProcesses.
     *
     */
    public BusinessProcess[] getSubProcesses() {
        return this.subProcesses;
    }
    
    /** Indexed setter for property subProcesses.
     * @param index Index of the property.
     * @param subProcesses New value of the property at <CODE>index</CODE>.
     *
     */
    public void setSubProcesses(int index, BusinessProcess subProcesses) {
        this.subProcesses[index] = subProcesses;
    }
    
    /** Setter for property subProcesses.
     * @param subProcesses New value of property subProcesses.
     *
     */
    public void setSubProcesses(BusinessProcess[] subProcesses) {
        this.subProcesses = subProcesses;
    }
    
}
