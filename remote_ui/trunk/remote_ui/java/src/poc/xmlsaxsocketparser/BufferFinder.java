/*
 * BufferFinder
 *
 * Classe utilizada para abstrair o controlo da existencia de uma string
 * num buffer. 
 */

package poc.xmlsaxsocketparser;

/**
 *
 * @author dinis
 */
public class BufferFinder {
    String find=null;
    String buffer;
    
    /*
     * Criamos o objecto com a String a ser controlada
     */ 
    public BufferFinder( String str) {
        this.find = str;
        buffer = "";
    }
    
    // encontramos a string nesta ultima posicao do buffer
    public boolean found() {
        return find.equalsIgnoreCase( buffer);
    }
    
    // devolve a string de controlo
    public String get() {
        return find;
    }
    
    /*
     * adicionamos o caracter do buffer ao nosso controlo
     */
    public void append( char c) {
        if( buffer.length() < find.length())
            buffer+=c;
        else {
            buffer=buffer.substring(2)+c;
        }
    }
    public void append( int i) {
        this.append((char) i);
    }
    
}
