package pt.moredata.fgldocumenter.browser;

/**
 * The information about a 4gl return 
 */

class FunctionReturn {
    private String varName;
    private String dataType;
    private String comment;
    
    /** Gets the name of the variable returned (if so)
     * @return The name of the variable name.
     */    
    public String getVarName() {
        return varName;
    }
    
    /** Assign the variable name used in the 4gl return statement.
     * @param _varName The variable name
     */    
    public void setVarName(String _varName) {
        varName = _varName;
    }
    
    /** Gets the data type returned.
     * @return The data type used.
     */    
    public String getDataType() {
        return dataType;
    }
    
    /** Set the data type returned.
     * @param _dataType The data type
     */    
    public void setDataType(String _dataType) {
        dataType = _dataType;
    }
    
    /** Assign a text comment to the return.
     * @return The text comment.
     */    
    public String getComment() {
        return comment;
    }
    
    /** Assign the comment of the return value
     * @param _comment  */    
    public void setComment(String _comment) {
        comment = _comment;
    }
}
