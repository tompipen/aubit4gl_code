/*
 * DbConnection.java
 *
 */

package org.aubit4gl.dbdocumenter.repository;

import javax.sql.DataSource;
import java.sql.Connection;
import org.aubit4gl.dbdocumenter.actions.ErrorHandler;

/**
 * Define the information of a database connection.
 *
 * @author  Sergio Ferreira
 */
public class DbConnection {
    
    /** Holds value of property className. */
    private String className;
    
    /** Holds value of property url. */
    private String url;
    
    /** Holds value of property errorHandler. */
    private ErrorHandler errorHandler;
    
    /** Creates a new instance of DbConnection */
    public DbConnection() {
    }
    
    /** Getter for property className.
     * @return Value of property className.
     *
     */
    public String getClassName() {
        return this.className;
    }
    
    /** Setter for property className.
     * @param className New value of property className.
     *
     */
    public void setClassName(String className) {
        this.className = className;
    }
    
    /** Getter for property url.
     * @return Value of property url.
     *
     */
    public String getUrl() {
        return this.url;
    }
    
    /** Setter for property url.
     * @param url New value of property url.
     *
     */
    public void setUrl(String url) {
        this.url = url;
    }
    
    /** Getter for property errorHandler.
     * @return Value of property errorHandler.
     *
     */
    public ErrorHandler getErrorHandler() {
        return this.errorHandler;
    }
    
    /** Setter for property errorHandler.
     * @param errorHandler New value of property errorHandler.
     *
     */
    public void setErrorHandler(ErrorHandler errorHandler) {
        this.errorHandler = errorHandler;
    }

    /**
     * Connect to the database
     *
     * @todo Learn to use the data source factory and see if it is better
     * @return A reference to the connection.
     */
    public Connection connect() {
       Connection connection;
       return connection;
    }
}
