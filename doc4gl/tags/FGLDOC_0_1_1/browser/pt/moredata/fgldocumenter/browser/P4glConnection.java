package pt.moredata.fgldocumenter.browser;

import java.util.*;
import java.sql.*;

/**
 * Database repository connection handling.
 */
public class P4glConnection {
    /**
     * Conexao a base de dados
     */
    private static Connection connection;
    
    /** URL de acesso à base de dados */
    private String dbURL = "jdbc:informix-sqli://dpinid03.iapmei.pt:1526/giap:INFORMIXSERVER=teste;USER=p4gl;PASSWORD=p4gl_pass";
    
    /** Tipo de conexão */
    private String connectionType = "jdbc";
    
    /** Url para driver de JDBC */
    private String sgbdUrl = "informix-sqli";
    
    /** Nome do host onde se encontra a base de dados */
    private String hostName    = "180.168.130.8";
    
    /** Service / port de acesso à base de dados */
    private String service     = "1530";
    
    /** Nome da base de dados */
    private String dbName      = "p4gl_repository";
    
    /** Nome do server / instancia */
    private String server      = "INFORMIXSERVER=unstable";
    
    /** Nome do utilizador */
    private String userName    = "p4gl";
    
    /** Password do utilizador */
    private String password    = "p4gl_pass";
    
    /** Assign the JDBC connection used (if estabelished outside this bean)
     * @param _connection The JDBC connection object.
     */
    public static void setConnection(Connection _connection) {
        connection       = _connection;
    }
    
    /** Gets the JDBC connection to the repository.
     * @return The JDBC connection.
     */
    public static Connection getConnection() {
        return connection;
    }
    
    
    /** Assign the complete DBMS JDBC Urls to access to the database repository.
     * @param _sgbdUrl The database URL
     */    
    public void setSgbdUrl(String _sgbdUrl) {
        sgbdUrl = _sgbdUrl;
    }
    
    /** Gets the database url used to access to the database repository.
     * @return The database url
     */    
    public String getSgbdUrl() {
        return sgbdUrl;
    }
    
    /** Assign the host name where the database repository is instaled.
     * @param _hostName The hostname.
     */    
    public void setHostName(String _hostName) {
        hostName = _hostName;
    }
    
    /** Gets the hostname where the database is instaled.
     * @return The hostname.
     */    
    public String getHostName() {
        return hostName;
    }
    
    /** Assign the service name or port number used to access to the database repository.
     * @param _service The service name or TCP port number.
     */    
    public void setService(String _service) {
        service = _service;
    }
    
    /** Gets the service name or TCP port number used in the access to the database repository.
     * @return The service name or TCP port number.
     */    
    public String getService() {
        return service;
    }
    
    /** Assign the database name used as repository.
     * @param _dbName The database name.
     */    
    public void setDbName(String _dbName) {
        dbName = _dbName;
    }
    
    /** Gets the database name of the repository.
     * @return The database name.
     */    
    public String getDbName() {
        return dbName;
    }
    
    /** The server instance of the database repository.
     * @param _server The server name.
     */    
    public void setServer(String _server) {
        server = _server;
    }
    
    /** Gets the server name.
     * @return The server instance name.
     */    
    public String getServer() {
        return server;
    }
    
    /** Assign the server name used as repository.
     * @param _userName The user name.
     */    
    public void setUserName(String _userName) {
        userName = _userName;
    }
    
    /** Gets the user name used to access to t6he database.
     * @return The user name.
     */    
    public String getUserName() {
        return userName;
    }
    
    /** Assign the password to access to the databse.
     * @param _password The password.
     */    
    public void setPassword(String _password) {
        password = _password;
    }
    
    /** Gets the password.
     * @return The password.
     */    
    public String getPassword() {
        return password;
    }
    
    
    /** Estabelish the connection to the database.
     */
    public void connect() {
        loadDbDriver();
        buildDbUrl();
        setConnection(connectDB(dbURL));
    }
    
    
    /**
     * Carrega o driver de JDBC especificado como parametro
     */
    private void loadDbDriver() {
        String driver;
        
        if ( sgbdUrl.equalsIgnoreCase("informix-sqli"))
            driver = "com.informix.jdbc.IfxDriver";
        if ( sgbdUrl.equalsIgnoreCase("mysql"))
            driver = "org.gjt.mm.mysql.Driver";
        else
            driver = "com.informix.jdbc.IfxDriver";
        try {
            Class.forName(driver);
            // ??? No caso do mySql eventualmente tenho de fazer newInstance
        }
        catch (ClassNotFoundException ex) {
            System.err.println("Cannot find the database driver classes.");
            System.err.println(ex);
        }
    }
    
    /**
     * Constroi a url de ligação à base de dados
     */
    private void buildDbUrl() {
        if ( sgbdUrl.equalsIgnoreCase("mysql"))
            buildDbUrlMySql();
        else
            buildDbUrlInfx();
    }
    
    /**
     * Constroi a conexão à base de dados quando esta é do tipo informix
     */
    private void buildDbUrlInfx() {
        StringBuffer tmpDbUrl = new StringBuffer();
        
        tmpDbUrl.append(connectionType + ":" + sgbdUrl + "://" + hostName);
        
        if ( service != null && ! service.equals("") )
            tmpDbUrl.append(":" + service);
        if ( dbName != null && ! dbName.equals(""))
            tmpDbUrl.append("/" + dbName);
        if ( server != null && ! server.equals(""))
            tmpDbUrl.append(":" + server);
        if ( userName != null && password != null )
            tmpDbUrl.append(";USER=" + userName + ";PASSWORD=" + password);
        dbURL = new String(tmpDbUrl);
        //  System.out.println("URL de acesso à BD " + dbURL);
    }
    
    /**
     * Constroi a url de ligação a uma base de dados mySql
     */
    private void buildDbUrlMySql() {
        StringBuffer tmpDbUrl = new StringBuffer();
        
        tmpDbUrl.append(connectionType + ":" + sgbdUrl + "://" + hostName);
        
        if ( dbName != null )
            tmpDbUrl.append("/" + dbName);
        if ( userName != null && password != null )
            tmpDbUrl.append("?USER=" + userName + "&PASSWORD=" + password);
        dbURL = new String(tmpDbUrl);
        //  System.out.println("URL de acesso à BD " + dbURL);
    }
    
    /**
     * Efectua a ligação à base de dados
     */
    private Connection connectDB(String url) {
        Connection connection = null;
        
        try {
            connection = DriverManager.getConnection(url);
        }
        catch (SQLException ex) {
            System.err.println("Não foi possivel estabelecer ligação à " +
            "Base de dados\n" + url + "\n" +
            ex.getMessage()
            );
            return null;
        }
        return connection;
    }
    
    
}
