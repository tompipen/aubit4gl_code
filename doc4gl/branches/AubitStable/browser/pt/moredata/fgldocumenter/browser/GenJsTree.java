package pt.moredata.fgldocumenter.browser;


import java.sql.*;
import java.util.*;

/**
 * Generate the information of the process tree to be used by TreeView.js.
 *
 *
 * Do the recursive querys to the repository (p4gl format).
 *
 */
public class GenJsTree {
    /** Conexão para acesso à base de dados */
    private Connection connection;
    
    /** String que contem o java script a enviar para o browser */
    private StringBuffer js;
    
    /** Empty constructor.
     * Does nothing.
     */    
    public GenJsTree() {
    }
    
    /** Assign the database connection to use to access to the repository.
     * @param _connection The database JDBC connection.
     */
    public void setConnection(Connection _connection) {
        connection = _connection;
    }
    
    /**
     *  Selecciona os processos por pai
     *  @param $parentProcess O código do processo pai
     *  @return Lista de processos filhos
     */
    private ArrayList selectDetailProcesses(Process parentProcess) {
        PreparedStatement sth = null;
        
        try {
            if ( parentProcess == null ) {
                sth = connection.prepareStatement(
                "SELECT id_process, disp_process, den_process, " +
                " sub_process_of, comments "+
                " FROM p4gl_process "  +
                " where sub_process_of is null"
                );
            }
            else {
                sth = connection.prepareStatement(
                "SELECT id_process, disp_process, den_process, " +
                " sub_process_of, comments "+
                " FROM p4gl_process where sub_process_of = '" +
                parentProcess.getIdProcess() + "'"
                );
            }
        }
        catch (SQLException e) {
            System.out.println("Erro a preparar processo" + e.getMessage());
        }
        
        ResultSet rs = null;
        try {
            rs = sth.executeQuery();
        }
        catch (SQLException e) {
            System.out.println(
            "Selecção de processos" +
            "Can't select from p4gl_process\n" + e.getMessage()
            );
        }
        
        ArrayList processList = new ArrayList();
        try {
            while ( rs.next() ) {
                Process process = new Process();
                process.setIdProcess(rs.getString(1).trim());
                process.setDispProcess(rs.getString(2).trim());
                process.setDenProcess(rs.getString(3));
                process.setSubProcessOf(rs.getString(4));
                process.setComments(rs.getString(5));
                processList.add(process);
            }
        }
        catch (SQLException e) {
            System.out.println(
            "Selecção de processos" +
            "Can't access to p4gl_process row\n" + e.getMessage()
            );
        }
        return processList;
    }
    
    
    /**
     *  Gera o javascript para o processo
     *    @todo Resolver o problema do(s) link(s).
     *    @param Processo para o qual se vai detalhar a arvore
     */
    private void genJsForProcess(Process parentProcess,String lastFolder) {
        ArrayList processList = selectDetailProcesses(parentProcess);
        if ( processList.size() > 0 ) {
            String processName;
            if ( parentProcess == null ) {
                processName = "Processos";
            }
            else {
                processName = parentProcess.getDispProcess();
                js.append("  " + parentProcess.getIdProcess() +
                "= insFld(" + lastFolder + ",gFld(\"" + processName +
                "\", \"\", \"module_list.jsp?process=" +
                parentProcess.getIdProcess().trim() +
                "\"))\n\n"
                );
                lastFolder = parentProcess.getIdProcess();
            }
        }
        else {
            js.append("  insDoc(" + lastFolder + ", " +
            "gLnk(\"" + parentProcess.getDispProcess() + "\", \"\", \"" +
            "module_list.jsp?process=" + parentProcess.getIdProcess().trim() +
            "\",\"modulesFrame\"))\n"
            );
        }
        for(int i = 0 ; i < processList.size() ; i++ ) {
            genJsForProcess((Process)processList.get(i),lastFolder);
        }
    }
    
    
    /** Generate the process tree.
     * @return A string containing the initialization javascript tree to be ues by TreeView.js
     */
    public String genProcessTree() {
        js = new StringBuffer("<script>\n");
        js.append("  foldersTree = gFld(\"<b>Processes</b>\", \"\", \"\")\n");
        js.append("  insDoc(foldersTree,gLnk(\"All Modules\", \"\", \"module_list.jsp?process=all\",\"modulesFrame\"))\n\n");

		js.append("  insDoc(foldersTree,gLnk(\"Home page\", \"\", \"module.jsp\",\"descriptionFrame\"))\n\n");


		js.append("  NEW= insFld(foldersTree,gFld(\"Resources\", \"\", \"morestuff.jsp\"))\n\n");
		js.append("  insDoc(NEW, gLnk(\"Database tables\", \"\", \"table_list.jsp?process=all\",\"modulesFrame\"))\n\n");
		js.append("  insDoc(NEW, gLnk(\"Help files\", \"\", \"help_list.jsp?process=all\",\"modulesFrame\"))\n\n");
		js.append("  insDoc(NEW, gLnk(\"Menus\", \"\", \"menu_list.jsp?process=all\",\"modulesFrame\"))\n\n");
		js.append("  insDoc(NEW, gLnk(\"Forms\", \"\", \"form_list.jsp?process=all\",\"modulesFrame\"))\n\n");


		js.append("  insDoc(foldersTree,gLnk(\"Search\", \"\", \"search.jsp\",\"descriptionFrame\"))\n\n");
		js.append("  insDoc(foldersTree,gLnk(\"Targets\", \"\", \"target_list.jsp?process=all\",\"modulesFrame\"))\n\n");


        genJsForProcess(null,"foldersTree");
        js.append("</script>");
        return js.toString();
    }
    
    /** Main for testing purpose only.
     * @param args  */
    public static void main(String args[]) {
        GenJsTree jsTree = new GenJsTree();
        
        P4glConnection implicitDS = new P4glConnection();
        implicitDS.setSgbdUrl("informix-sqli");
        implicitDS.setHostName("localhost");
        implicitDS.setService("1530");
        implicitDS.setDbName("p4gl_repository");
        implicitDS.setServer("INFORMIXSERVER=unstable");
        implicitDS.setUserName("sergio");
        implicitDS.setPassword("jfola45");
        implicitDS.connect();
        
        jsTree.setConnection(implicitDS.getConnection());
        System.out.println(jsTree.genProcessTree());
    }
}
