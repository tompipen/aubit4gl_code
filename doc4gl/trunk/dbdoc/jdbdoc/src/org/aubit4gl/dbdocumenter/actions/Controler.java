/*
 * Controler.java
 *
 */

package org.aubit4gl.dbdocumenter.actions;

import java.sql.Connection;
import java.util.HashMap;
import java.util.Iterator;
import java.io.File;
import org.w3c.dom.Document;
import org.w3c.dom.DOMException;
import org.w3c.dom.Element;
import org.xml.sax.SAXException;
import javax.xml.parsers.DocumentBuilder; 
import javax.xml.parsers.DocumentBuilderFactory; 
import javax.xml.parsers.ParserConfigurationException; 
import javax.xml.parsers.ParserConfigurationException;
import org.apache.log4j.Category;
import org.apache.log4j.BasicConfigurator;
import org.aubit4gl.dbdocumenter.gui.DbDocGui;


/**
 * The main class where we store some global information.
 *
 * @author  Sergio Ferreira
 */
public class Controler {

    /** Logger to messages */
    static Category logger = Category.getInstance(ErrorHandler.class.getName());
     
    /** Holds value of property repositoryConnection. */
    private Connection repositoryConnection;
    
    /** Holds value of property dbConnection. */
    private Connection dbConnection;
    
    /** Holds value of property errorHandler. */
    private ErrorHandler errorHandler;
   
    /** 
     * An Hash Map containing all the possible connections defined in a 
     *  a configuration file
     */
    private HashMap connections;
    
    /** Actions that the user want to execute in CUI mode */
    private HashMap actions = new HashMap();

    /**
     * An utilities object with severall utility methods.
     */
    private Utilities utilities;

    /** Parameters file name */
    private String parametersFileName;

    /** Graphical User Interface Type */
    private static final int GUI = 1;
    
    /** Command Line User interface type */
    private static final int CUI = 2;
    
    /** Type of user interface to be executed */
    private int userInterface = CUI;
    
    /** Actions available to executed in CUI mode */
    private static final int IMPORT_XML = 1;
    
    /** Creates a new instance of Controler */
    public Controler() {
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
    
    /** Getter for property dbConnection.
     * @return Value of property dbConnection.
     *
     */
    public Connection getDbConnection() {
        return this.dbConnection;
    }
    
    /** Setter for property dbConnection.
     * @param dbConnection New value of property dbConnection.
     *
     */
    public void setDbConnection(Connection dbConnection) {
        this.dbConnection = dbConnection;
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
     * Save the user parameters in a XML file.
     */
    public void saveUserParameters() {
       logger.info("Saving user parameters");
       DocumentBuilder builder = null;
       DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
       try {
         builder = factory.newDocumentBuilder();
       }
       catch(ParserConfigurationException e)
       {
           // @todo : Handle the exception properly
           logger.error("Exception ocurred " + e.getMessage());
           return;
       }
       Document parametersDOM = builder.newDocument(); 
       
       Element parametersRoot = (Element) parametersDOM.createElement("PARAMETERS"); 
       parametersDOM.appendChild(parametersRoot);
       Element repConn = (Element) parametersDOM.createElement("REPOSITORY_CONNECTION");
       repConn.setAttribute("name", "XX");
       parametersRoot.appendChild(repConn);
       Element opConn = (Element) parametersDOM.createElement("OPERATIONAL_DB_CONNECTION");
       opConn.setAttribute("name", "XX");
       parametersRoot.appendChild(opConn);
       utilities.writeDom2Xml(parametersDOM,parametersFileName);
       logger.info("User parameters saved");
    }
    
    /**
     * Read the user parameters of the last session..
     *
     * @todo : This can go to other class
     * @todo : Create a unit test to save and read the parameters
     */
    public void loadUserParameters() {
        logger.info("Loading user parameters");
        // Step 1: create a DocumentBuilderFactory
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DocumentBuilder db = null;
        // Step 2: create a DocumentBuilder
        try {
           db = dbf.newDocumentBuilder();
        }
        catch ( ParserConfigurationException e) 
        {
            logger.error("Exception loading error parameters " + e.getMessage());
            exitDbDocumenter();
        }
        // Step 3: parse the input file to get a Document object
        Document doc = null;
        try {
          doc = db.parse(new File(parametersFileName));
        }
        catch ( Exception e) 
        {
            logger.error("Exception loading user parameters " + e.getMessage());
            exitDbDocumenter();
        }
        utilities.printDOM(doc);
        logger.info("User parameters loaded");
    }
    
 
    
    /**
     * Connect to the repository and operational database.
     */
    private void connectToDatabases() {
        
    }
    
    /**
     * Execute the dbdocumenter management in GUI mode.
     */
    private void executeGUI() {
        // GuiErrorHandler errorHandler = new GuiErrorHandler();
        // Configure the logger to GUI
        // Assign the error handler
        DbDocGui gui = new DbDocGui();
        gui.setVisible(true);
    }
    
    /**
     * Execute the action wanted in CUI mode
     *
     * @todo : Implement the code to handle all the actions 
     */
    private void executeCUI() {
        // CuiErrorHandler errorHandler = new CuiErrorHandler();
        // Configure the logger to CUI
        // Assign the log
        // Assign the error handler
        Iterator ai = actions.values().iterator();
        while ( ai.hasNext() ) {
            int action = ((Integer) ai.next()).intValue();
            switch(action) {
                case IMPORT_XML:
                    break;
            }
        }
        exitDbDocumenter();
    }
    
    /**
     * Parse the parameters using the gnu getopt implementation.
     *
     * @todo : Implement it.
     */
    private void parseParameters() {
    }
    
    /**
     * Initialization of all dbdocumenter system.
     *
     * Loads the information stored in XML configuration file(s) and (or)
     * other saved information.
     *
     * Try to estabilish a connection to the operational and repository
     * database.
     */
    public void initManager() {
        utilities = new Utilities();
        initLogger();
        parametersFileName = "dbdoc.xml";
        loadUserParameters();
        utilities.loadDrivers();
        utilities.loadConnections();
        connectToDatabases();
        // initLog4J();
        if ( userInterface == GUI )
           executeGUI();
        else
           executeCUI();
    }
    
    /**
     * Make all needed intializations to let the browser working OK.
     * In the browse we need to:
     *    - Connect to reository
     *    - Connect to operational database
     *    - Load the processes
     *    - Load the table list and association to model
     *    - Initialize the Process List and store it
     *    - Let the JSP have control over it.
     */
    public void initBrowser() {
        
    }
    
    /**
     * Executed whenever some action asked to close the dbdocumenter.
     * Save the user parameters in the XML file.
     */
    private void exitDbDocumenter() {
      parametersFileName = "test.xml";
      saveUserParameters();
    }
    
    /**
     * Initialize the log4j in order that we do not need
     * to have a configuration file.
     * 
     * This may change in the future.
     */
    private void initLogger() {
        BasicConfigurator.configure();
        logger.info("Logger in dbdocumenter started");
    }
    
    /**
     * Analize the execution arguments passed to the program and initialize the 
     * the corresponding options.
     *
     * It will use the gnu.getopt package available at: 
     *    http://www.urbanophile.com/arenn/hacking/download.html 
     */
    void parseArgs(String args[]) {
        userInterface = CUI;
    }
    
    public static void main(String args[]) {
        Controler controler = new Controler();
        controler.parseArgs(args);
        controler.initManager();
    }
}
