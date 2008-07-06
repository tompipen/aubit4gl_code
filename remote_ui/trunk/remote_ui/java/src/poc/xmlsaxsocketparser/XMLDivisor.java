/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package poc.xmlsaxsocketparser;

import java.io.IOException;
import java.io.InputStream;
import java.util.LinkedList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author dinis
 */
public class XMLDivisor implements Runnable {

    private InputStream is = null;
    private BufferFinder inicio = null;
    private BufferFinder fim = null;
    private boolean save = false;
    private String out = "";
    private List lout = new LinkedList();

    public XMLDivisor(InputStream is, String tag) {
        this.is = is;
        this.inicio = new BufferFinder("<" + tag);
        this.fim = new BufferFinder("</" + tag + ">");
    }

    public String getXML() {
        String ret = null;
        while (lout.size() == 0) {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(XMLDivisor.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        synchronized (lout) {
            ret = (String) lout.remove(0);
        }

        if (ret.equals("XMLDivisor.close")) {
            return null;
        }
        return ret;
    }

    public void run() {
        try {
            int c = 0;
            save = false;
            while ((c = is.read()) >= 0) {
                inicio.append(c);
                fim.append(c);
                if (save) {
                    out += (char) c;
                }
                if (inicio.found()) {
                    save = true;
                    this.out = inicio.get();
                }
                if (fim.found()) {
                    save = false;
                    synchronized (lout) {
                        lout.add(out);
                    }
                }
            }
            is.close();
            lout.add("XMLDivisor.close");
        } catch (IOException ex) {
            Logger.getLogger(XMLDivisor.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
