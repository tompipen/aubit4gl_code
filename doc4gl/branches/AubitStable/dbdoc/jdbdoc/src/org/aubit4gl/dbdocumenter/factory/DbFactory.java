/*
 * DbFactory.java
 *
 */

package org.aubit4gl.dbdocumenter.Factory;

import java.sql.Connection;
import java.sql.DatabaseMetaData;
import java.sql.ResultSet;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import org.aubit4gl.dbdocumenter.model.DbDocModel;
import org.aubit4gl.dbdocumenter.model.Table;
import org.aubit4gl.dbdocumenter.model.BusinessProcess;
import org.aubit4gl.dbdocumenter.model.ProcessTree;
import org.aubit4gl.dbdocumenter.actions.ErrorHandler;
/**
 * This factory create a dbdoc model based on the information loaded on 
 * a repostory database and or an operational database.
 *
 * <BR>The repository database is the place where the comments for the tables
 * are loaded, and the operational database is the one that have the data 
 * model created.
 *
 * <BR>From the oprational database we get the metadata relating to the database.
 * (column names, datatypes, nulls, etc).
 *
 * <BR>If we want we can use the operational database as the repository.
 *
 * <BR>The folowing scheme tryes to describe the way this class works.
 *
 * <PRE>
 *
 *                                             |
 *   +------------------+                      | Connection info
 *   | DbDoc Repository | ------+             \/
     +------------------+       |         +--------+         +-------------+
 *                              +----+--->| Factory|-------->| DbDoc Model |
 *                                   |    +--------+         +-------------+
 *   +---------------------------+   |
 *   | Database to be documented |---+
 *   +---------------------------+
 *
 * </PRE>
 *
 * The connection(s) should be made in other class and it provided to this one.
 * 
 * So, to build a Model it is just necessary to set the connecions and call the
 * method build that return(s) the generated module.
 *
 * @todo : Implement table restrictions
 *
 * @author  sergio
 */
public class DbFactory {
    
    /** Holds value of property repositoryConnection. */
    private Connection repositoryConnection;
    
    /** Holds value of property opDbConnection. */
    private Connection opDbConnection;
    
    /** Holds value of property errorHandler. */
    private ErrorHandler errorHandler;
    
    /** Creates a new instance of DbFactory */
    public DbFactory() {
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
    
    /** Getter for property opDbConnection.
     * @return Value of property opDbConnection.
     *
     */
    public Connection getOpDbConnection() {
        return this.opDbConnection;
    }
    
    /** Setter for property opDbConnection.
     * @param opDbConnection New value of property opDbConnection.
     *
     */
    public void setOpDbConnection(Connection opDbConnection) {
        this.opDbConnection = opDbConnection;
    }
    
    /**
     * Create a dbdocumenter model in memory that describes a database.
     */
    public DbDocModel build() {
        /** @todo
        if (repositoryConnection == null)
            trow new Exception("NULL connection to the repository");
        if (opDbConnection == null)
            trow new Exception("NULL connection to the operational database");
         */
        DbDocModel model = new DbDocModel();
        loadTables(model);
        loadFromRepository();
        loadProcessTree(model);
        associateTablesToProcesses(model);
    }
    
    /**
     * Load the information about all tables in the operational database.
     *
     * @todo : Have some restrictions in order to load just parts of the model.
     * @param model The model reference to be filled.
     */
    private void loadTables(DbDocModel model) {
        DatabaseMetaData dbmd = opDbConnection.getMetaData();
        ResultSet rs = dbmd.getTables(null,null, null, null);
        while ( rs.next() ) {
            //model.addTable(???);
        }
        loadColumns(model,dbmd);
        loadPrimaryKeys(model,dbmd);
        loadForeignKeys(model,dbmd);
        loadIndexes(model,dbmd);
    }
    
    /**
     * Load all information of all columns 
     * @todo : Have some restrictions in order to load just parts of the model.
     */
    private void loadColumns(DbDocModel model, DatabaseMetaData dbmd) {
    }
    
    /**
     * Load all information of primary keys of all loaded tables.
     *
     * @todo : Have some restrictions in order to load just parts of the model.
     */
    private void loadPrimaryKeys(DbDocModel model, DatabaseMetaData dbmd) {
    }
    
    /**
     * Load all information of all foreign keys of all loaded columns.
     *
     * @todo : Have some restrictions in order to load just parts of the model.
     */
    private void loadForeignKeys(DbDocModel model, DatabaseMetaData dbmd) {
    }
    
    /**
     * Load the index information from the operational database.
     *
     * @param model A reference to the model where the indexes should be loaded.
     * @param dbmd Database metadata
     */
    private void loadIndexes(DbDocModel model, DatabaseMetaData dbmd) {
    }
    
    /**
     * Load the information that exist in the repository about the tables
     * that was loaded from the operational database.
     */
    private void loadFromRepository() {
        // Iterate in tables loaded
        //For each table
        Table table;
        String tableName;
        loadExtendedTable(table, tableName);
    }
    
    /**
     * Load the table information from the extended table information
     * and store it in the model for the table.
     */
    private void loadExtendedTable(Table tableModel,String tableName) {
        String sql = "select alias,remarks " + 
          " from ext_table where database=? and owner=? and table_name=?";
        
        PreparedStatement st = null;
        try {
          st = repositoryConnection.prepareStatement(sql);
        }
        catch (SQLException e) {
            errorHandler.handle(e,"Getting table information");
        }
        st.setObject(1,tableModel.getDatabase());
        st.setObject(2,tableModel.getOwner());
        st.setObject(3,tableModel.getName());
        ResultSet rs = st.executeQuery();
        /** @todo
        if ( rs.next() )
          tableModel.setDescription(rs.getObject(1));
        */
        // Load the column information
    }
    
    /**
     * Load the information about the business processes available in the 
     * repository database.
     *
     * @param model A reference to the model to be filled
     */
    private void loadProcessTree(DbDocModel model) {
        // Select all processes from the table
        // Store them in a MultiMap
        // Iterate in the root processes
        // For each process process 
          // Get the sub tree
    }
    
    /**
     * Load and return the information that is leave from a process.
     */
    ProcessTree loadProcessTree(String parentProcess) {
    }
    
    
    /**
     * Associate the information of tables to processes.
     *
     * @param model A reference to the model to be filled
     */
    private void associateTablesToProcesses(DbDocModel model) {
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
