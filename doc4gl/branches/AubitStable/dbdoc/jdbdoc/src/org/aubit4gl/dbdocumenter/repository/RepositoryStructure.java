/*
 * CreateRepository.java
 *
 */

package org.aubit4gl.dbdocumenter.repository;

import java.sql.Connection;

/**
 * Create the repository where the model information could be saved.
 *
 * Generate only the SQL needed to handle the creation and removal of the 
 * repository.
 *
 * @todo Test this script(s) in severall database engines:
 *     - HSQL
 *     - Postgresql
 *     - MySql
 *     - SapDb
 *     - 
 * @author  Sergio Ferreira
 */
public class RepositoryStructure {
    
    /** Creates a new instance of CreateRepository */
    public RepositoryStructure() {
    }
    
    /**
     * Create the table where we can identify how to access to the operational
     * databases that are refered in the repository.
     *
     * @return The SQL that create this table.
     */
    public String getSqlDatabase() {
        String str = "create table ext_database ( " +
          "database char(64) not null primary key," +
          "jdbc_driver_class varchar(64,255)," +
          "url varchar(64,255)" +
        ");";
        return str;
    }
    
    /**
     * Create the table where the extended information about each table
     * should be stored.
     */
    String getSqlExtendedTable() {
        String str = "create table ext_table ( " +
        "database char(64) not null reference ext_database (database)," +
        "owner char(32) not null," +
        "table_name char(64) not null," +
        "alias char(64)," +
        "remarks varchar(32,256)"+
        "primary key (database,owner,table_name)"+
        ");";
        return str;
    }
    
    /**
     * Create the table where the extended information about each column it will
     * be stored.
     */
    String getSqlExtendedColumn() {
        String str = "create table ext_column ( " +
          "database char(64) not null," +
          "owner char(32) not null," + 
          "table_name char(64) not null," + 
          "column_name char(64) not null," +
          "alias char(64)," +
          "label char(64)," +
          "title char(64)," +
          "remarks varchar(32,256),"+
          "primary key (database,owner,table_name,column_name)," +
          "foreign key (database,owner,table_name) references ext_table " +
          " (database,owner,table_name)"+
        ");";
        return str;
    }
    
    /**
     * Create the table where the process will be defined
     */
    String getSqlBusinessProcess() {
        String str = "create table process (" +
          "id_process char(20) not null primary key," +
          "disp_process char(20) not null," +
          "den_process char(64) not null," +
          "sub_process_of char(20)," +
          "comments varchar(32,255)," + 
        ");";
        return str;
    }
    
    /**
     * Create the table where a process is asociated to a table
     */
    protected String getSqlTableBP() {
        String str = "create table table_process ( "+
          "id_process char(20) not null references process (id_process)" +
          "database char(64) not null,"+
          "owner char(64) not null,"+
          "table_name char(64) not null,"+
          "primary key (id_process,database,owner,table_name),"+
          "foreign_key (database,owner,table_name) references ext_process " +
            "(database,owner,table_name)"+
        ");";
        return str;
    }
    
    /**
     * Drop all tables with a name used on the repository that exist in the
     * database.
     */
    String getSqlDropTables() {
        StringBuffer str = new StringBuffer();
        
        str.append(dropTable("ext_table"));
        str.append(dropTable("ext_column"));
        str.append(dropTable("process"));
        str.append(dropTable("table_process"));
        return str.toString();
    }
    
    /**
     * Drop a table from the database.
     *
     * @param name The name of the table to be droped.
     */
    String dropTable(String name) {
        String str = "drop table " + name.trim() + ";";
        return str;
    }
    
}
