
package pt.moredata.fgldocumenter.browser;

/**
 * Information about a 4gl parameter.
 */

class FunctionParameter {
    private String varName;
    private String dataType;
    private String comments;
    
    /** Get the name of the variable that is parameter from a function.
     * @return The name of the variable.
     */    
    public String getVarName() {
        return varName;
    }
    
    /** Assign the variable name used as parameter
     * @param _varName The name of the variable.
     */    
    public void setVarName(String _varName) {
        varName = _varName;
    }
    
    /** Get a string representing the data type of the parameter.
     * @return The text representation of the data type.
     */    
    public String getDataType() {
        if ( dataType == null )
            return "";
        return dataType;
    }
    
    /** Assign the data type of the parameter passed to the 4gl function.
     * @param _dataType The string retpresentation of the data type.
     */    
    public void setDataType(String _dataType) {
        dataType = _dataType;
    }
    
    /** Get the text comment of the parameter
     * @return The comment of the parameter
     */    
    public String getComments() {
        if ( comments == null )
            return "";
        return comments;
    }
    
    /**
     * Assign the text comment about the parameter
     * @param _comments The comment
     */    
    public void setComments(String _comments) {
        dataType = _comments;
    }
}
