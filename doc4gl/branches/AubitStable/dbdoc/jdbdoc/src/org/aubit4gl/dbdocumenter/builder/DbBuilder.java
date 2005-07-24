/*
 * DbBuilder.java
 *
 */

package org.aubit4gl.dbdocumenter.builder;

import java.sql.Connection;

/**
 * Save the information of a model in a repostory.
 *
 * @author  Sergio Ferreira
 */
public class DbBuilder {

    /** Holds value of property repositoryConnection. */
	private Connection repositoryConnection;

    /** Holds value of property deleteAllContent. */
    private boolean deleteAllContent;

    /** Creates a new instance of DbBuilder */
    public DbBuilder() {
    }

    /** Getter for property repositoryConnection.
     * @return Value of property repositoryConnection.
     *
     */
	public Connection getRepositoryConnection() {
        return this.repositoryConnection;
    }

    /** Setter for property repositoryConnection.
     * @param repositoryConnection New value of property repositoryConnection.
     *
     */
	public void setRepositoryConnection(Connection repositoryConnection) {
        this.repositoryConnection = repositoryConnection;
    }


    /** Getter for property deleteAllContent.
     * @return Value of property deleteAllContent.
     *
     */
    public boolean isDeleteAllContent() {
        return this.deleteAllContent;
    }

    /** Setter for property deleteAllContent.
     * @param deleteAllContent New value of property deleteAllContent.
     *
     */
    public void setDeleteAllContent(boolean deleteAllContent) {
        this.deleteAllContent = deleteAllContent;
    }
    
}
