/*
 * ConnectionUtilities.java
 *
 */

package org.aubit4gl.dbdocumenter.actions;

import java.util.ArrayList;
import java.util.HashMap;
import java.sql.Connection;
import java.io.File;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.w3c.dom.Element;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.TransformerException;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult; 
import org.aubit4gl.dbdocumenter.actions.ErrorHandler;

/**
 * Utilities used to connect to the databases.
 *
 * The goal of this class is to have utility methods that help(s) in the database
 * connection.
 * 
 * It should handle:
 *    - A XML file where the most used drivers could be configured
 *    - A XML file where the repository and operational connection could be 
 *      configured.
 * @author  Sergio Ferreira
 */
public class Utilities {
    
    /** Holds value of property driversFileName. */
    private String driversFileName;
    
    /** Holds value of property connectionsFileName. */
    private String connectionsFileName;
    
    /** Holds value of property errorHandler. */
    private ErrorHandler errorHandler;
    
    /** Creates a new instance of ConnectionUtilities */
    public Utilities() {
        // Getproperties.home
        driversFileName = ".dbdoc/db_drivers.xml";
        connectionsFileName = ".dbdoc/connections.xml";
    }
    
    /** 
     * Connect to a repository and (or) operational database.
     */
    public Connection connect() {
        Connection connection = null;
        return connection;
    }
    
    /**
     * Load the drivers from the XML drivers configuration file.
     *
     * @implement this.
     */
    public HashMap loadDrivers() {
        HashMap drivers = new HashMap();
        return drivers;
    }
    
    /**
     * Load the connections configured in a XML file
     */
    public HashMap loadConnections() {
        HashMap connections = new HashMap();
        return connections;
    }
    
    /** Getter for property driversFile.
     * @return Value of property driversFile.
     *
     */
    public String getDriversFileName() {
        return this.driversFileName;
    }
    
    /** Setter for property driversFile.
     * @param driversFile New value of property driversFile.
     *
     */
    public void setDriversFileName(String driversFileName) {
        this.driversFileName = driversFileName;
    }
    
    /** Getter for property connectionsFileName.
     * @return Value of property connectionsFileName.
     *
     */
    public String getConnectionsFileName() {
        return this.connectionsFileName;
    }
    
    /** Setter for property connectionsFileName.
     * @param connectionsFileName New value of property connectionsFileName.
     *
     */
    public void setConnectionsFileName(String connectionsFileName) {
        this.connectionsFileName = connectionsFileName;
    }
    
    /**
     * Save connections in the connections file name
     *
     * @param connections An array list containing all connections definition
     * to be saved.
     * @todo : Implement and test this
     */
    public void saveConnections(ArrayList connections) {
        // Fill the DOM with the information
        // Save the DOM to the file
        Document connectionsDOM = null;
        writeDom2Xml(connectionsDOM, connectionsFileName);
    }
    
    /**
     * Read a DOM tree from a XML file.
     *
     * @todo Learn how to read the XML file.
     *
     * @param fileName The name of the XML file to be readed.
     * @return The DOM tree readed.
     */
    public Document readDomFromXml(String fileName) {
       Document dom = null;
       return dom;
    }
    
    /**
     * Write the dom tree generated in memory to the output stream as XML
     *
     * @param document The DOM tree to be writed.
     * @param fileName The complete filename where to write the tree.
     */
    public void writeDom2Xml(Document document,String fileName)
    {
       // Use a Transformer for output
       Transformer transformer = null;
       TransformerFactory tFactory = TransformerFactory.newInstance();
       try {
         transformer = tFactory.newTransformer();
       }
       catch (TransformerException e)
       {
           errorHandler.handle(e,"Error writing the XML File");
           return;
       }

       DOMSource source = new DOMSource(document);
       StreamResult result = new StreamResult(new File(fileName));
       try {
         transformer.transform(source, result);
       }
       catch (TransformerException e)
       {
           errorHandler.handle(e,"Error writing the XML File");
           return;
       }
    }

    /**
     * Print the DOM tree with System.out.println
     */
    void printDOM(Document doc) {
        NodeList nodes = doc.getDocumentElement().getChildNodes();
	for (int i=0; i<nodes.getLength(); i++)
	{
	    Node n = nodes.item(i);
            System.out.println("NODE " + n.getNodeName());
	    NodeList ndl = n.getChildNodes();
	    for (int k=0; k<ndl.getLength(); k++)
	    {
		Node m = ndl.item(k);
		if ( (m.getNodeName() == "dept") && (m.getFirstChild().getNodeValue() == "cse") )
		{
		    NodeList ncl = ((Element) m).getElementsByTagName("tel");
		    for (int j=0; j<ncl.getLength(); j++)
		    {
			Node nc = ncl.item(j);
			System.out.print(nc.getFirstChild().getNodeValue());
		    }
		}
	    }
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
