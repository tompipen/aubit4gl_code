package pt.moredata.fgldocumenter.browser;

/*
 * Process.java
 *
 * Created on February 15, 2002, 2:41 PM
 */

/**
 * Information about a fgldoc process.
 * @author  sergio
 * @version $Revision: 1.1 $
 */
public class Process {

    /** Holds value of property idProcess. */
    private String idProcess;
    
    /** Holds value of property dispProcess. */
    private String dispProcess;
    
    /** Holds value of property denProcess. */
    private String denProcess;
    
    /** Holds value of property subProcessOf. */
    private String subProcessOf;
    
    /** Holds value of property comments. */
    private String comments;
    
    /** Creates new Process */
    public Process() {
    }

    /** Getter for property idProcess.
     * @return Value of property idProcess.
     */
    public String getIdProcess() {
        return idProcess;
    }
    
    /** Setter for property idProcess.
     * @param idProcess New value of property idProcess.
     */
    public void setIdProcess(String idProcess) {
        this.idProcess = idProcess;
    }
    
    /** Getter for property dispProcess.
     * @return Value of property dispProcess.
     */
    public String getDispProcess() {
        return dispProcess;
    }
    
    /** Setter for property dispProcess.
     * @param dispProcess New value of property dispProcess.
     */
    public void setDispProcess(String dispProcess) {
        this.dispProcess = dispProcess;
    }
    
    /** Getter for property denProcess.
     * @return Value of property denProcess.
     */
    public String getDenProcess() {
        return denProcess;
    }
    
    /** Setter for property denProcess.
     * @param denProcess New value of property denProcess.
     */
    public void setDenProcess(String denProcess) {
        this.denProcess = denProcess;
    }
    
    /** Getter for property subProcessOf.
     * @return Value of property subProcessOf.
     */
    public String getSubProcessOf() {
        return subProcessOf;
    }
    
    /** Setter for property subProcessOf.
     * @param subProcessOf New value of property subProcessOf.
     */
    public void setSubProcessOf(String subProcessOf) {
        this.subProcessOf = subProcessOf;
    }
    
    /** Getter for property comments.
     * @return Value of property comments.
     */
    public String getComments() {
        return comments;
    }
    
    /** Setter for property comments.
     * @param comments New value of property comments.
     */
    public void setComments(String comments) {
        this.comments = comments;
    }
    
}
