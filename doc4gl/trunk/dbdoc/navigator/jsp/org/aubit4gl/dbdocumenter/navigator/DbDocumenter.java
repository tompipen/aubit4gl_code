/*
 * DbDocumenter.java
 *
 * Created on July 28, 2003, 4:22 PM
 */

package org.aubit4gl.dbdocumenter.navigator;

import java.sql.Connection;

/**
 * Dummy class with convenience static methods to use with JSP.
 * Just to put dbdocumenter to work.
 *
 * @author  sergio
 */
public class DbDocumenter {
    
    private static Connection connection;
    
    /** Creates a new instance of DbDocumenter */
    public DbDocumenter() {
    }
    
    public static void setConnection(Connection _connection) {
        connection = _connection;
    }
    
    public static Connection getConnection() {
        return connection;
    }
}
