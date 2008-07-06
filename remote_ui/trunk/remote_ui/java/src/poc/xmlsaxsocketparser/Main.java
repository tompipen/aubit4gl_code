/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package poc.xmlsaxsocketparser;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author dinis
 */
public class Main {

    /**
     * @param args Ficheiros XML a processar
     */
    public static void main(String[] args) throws IOException {
        FileInputStream fis = null;
        PipedOutputStream outStream = new PipedOutputStream();
        PipedInputStream inStream = new PipedInputStream(outStream);
        XMLDivisor xmldivisor = new XMLDivisor(inStream, "ENVELOPE");

        try {

            Thread t1 = new Thread(xmldivisor);
            t1.setDaemon(false);
            t1.start();

            //    outStream.connect(inStream);
            for (int i = 0; i < args.length; i++) {
                File f = new File(args[i]);
                System.err.println(f.getAbsolutePath() + "   " + f.isFile());
                fis = new FileInputStream(f);
                int c = 0;
                while ((c = fis.read()) >= 0) {
                    outStream.write(c);
                }
                fis.close();
            }
            outStream.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }

        String xml ="";
        while ( (xml = xmldivisor.getXML()) != null ) {
            System.out.println( ">>>>"+xml+"<<<<<");
        }
    }
}
