/*
 * CreateRepository.java
 *
 */

package org.aubit4gl.dbdocumenter.repository;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import org.aubit4gl.dbdocumenter.actions.ErrorHandler;


/**
 * Create a db documenter repository in a database.
 * The repository could be in a diferent database of the operational database.
 *
 * @author  Sergio Ferreira
 */
public class CreateRepository extends RepositoryStructure {
    
    /** Holds value of property connection. */
    private Connection connection;
    
    /** Holds value of property errorHandler. */
    private ErrorHandler errorHandler;
    
    /** Creates a new instance of CreateRepository */
    public CreateRepository() {

    }

    /**
     * Create the database repository, if defined to do so.
     *
     * @todo Understand if i can create the database from the java program.
     */
    private void createDatabase() {
    }

    /** Getter for property connection.
     * @return Value of property connection.
     *
     */
    public Connection getConnection() {
        return this.connection;
    }
    
    /** Setter for property connection.
     * @param connection New value of property connection.
     *
     */
    public void setConnection(Connection connection) {
        this.connection = connection;
    }

    /**
     * Create the repository
     */
    public void create() {
        createDatabase();
        createTables();
    }
    
    /**
     * Create the tables
     */
    private void createTables() {
        createTable(getSqlDatabase(),"ext_database");
        createTable(getSqlExtendedTable(),"ext_table");
        createTable(getSqlExtendedColumn(),"ext_column");
        createTable(getSqlBusinessProcess(),"process");
        createTable(getSqlTableBP(),"table_process");
    }
    
    
    /**
     *  Execute the creation of a table in the repository database.
     *
     * @param sql The SQL create statement.
     * @param table The name of the table to be created.
     */
    private void createTable(String sql, String table) {
        PreparedStatement st = null;
        try {
            st = connection.prepareStatement(sql);
        }
        catch (SQLException e) {
            errorHandler.handle(e,"Preparing the statement for creation of table:" + table);
        }
        
        try {
            st.execute();
        }
        catch (SQLException e) {
            errorHandler.handle(e,"Creating a repository table:" + table);
        }
        
    }
    
    /**
     * Drop the repository.
     * Just drop the tables.
     */
    public void drop() {
    }
    
    /**
     * Delete all information from the repository
     */
    public void delete() {
        deleteFromTable("ext_database");
        deleteFromTable("ext_database");
        deleteFromTable("ext_table");
        deleteFromTable("ext_column");
        deleteFromTable("process");
        deleteFromTable("table_process");
    }
    
    /**
     * Delete all information from a table.
     */
    private void deleteFromTable(String tableName) {
        String sql = "delete from " + tableName;
        try {
            PreparedStatement stSql = connection.prepareStatement(sql);
            stSql.execute();
        }
        catch (SQLException e) {
            errorHandler.handle(e,"Deleting information from " + tableName);
        }
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
    
}
