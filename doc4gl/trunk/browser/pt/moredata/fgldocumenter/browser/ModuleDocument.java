
package pt.moredata.fgldocumenter.browser;

import java.util.*;
import java.io.*;
import java.sql.*;


/**
 * Gets and show (used in JSP) all the information about a 4gl module.
 */
public class ModuleDocument {
    /** Nome do m�dulo de 4gl */
    String module;
    
    /** Chave prim�ria do processo a documentar */
    String idProcess;
    
    /** Comentarios textuais do m�dulo de 4gl */
    String comments;
    
    /** Lista de fun��es do m�dulo */
    ArrayList functionList = new ArrayList();
    
    /** Module table usage list */
    ArrayList tableUsageList = new ArrayList();

    /** Module target inclusion list */
    ArrayList targetInclusionList = new ArrayList();

    /** Op��es para documenta��o do m�dulo */
    ModuleDocumentOptions options;
    
    /**  */
    Writer out;
    
    /** Empty constructor.
     * Does nothing.
     */    
    public ModuleDocument() {  }
    
    /** Assign the 4gl module name.
     * @param _module The module name.
     */    
    public void setModule(String _module) {
        module = _module;
    }
    
    /** Gets the 4gl module name.
     * @return The module name.
     */    
    public String getModule() {
        return module;
    }
    
    /** Assign the process name that we want.
     * This is to document a whole process agregated as if a module.
     * @param _idProcess The process identification.
     */    
    public void setProcess(String _idProcess) {
        idProcess = _idProcess;
    }
    
    /** Gets the process that we are trying to document.
     * @return The process identification.
     */    
    public String getProcess() {
        return idProcess;
    }
    
    /** Assign the text comment of the module.
     * @param _comments The texxt comment.
     */    
    public void setComments(String _comments) {
        comments = _comments;
    }
    
    /** Gets the text comments of the module.
     * @return The comment of the module.
     */    
    public String getComments() {
        return comments;
    }
    
    
    /** Set the display options to use when documenting the module.
     * @param _options The options.
     */    
    public void setModuleDocumentOptions(ModuleDocumentOptions _options) {
        options = _options;
    }
    
    /** Assign the output writer where to display the html.
     * @param _out The output writer.
     */    
    public void setOut(Writer _out) {
        out = _out;
    }
    
    /** Initialize a module documentation.
     *
     * Select the information from the repository, etc.
     */
    public void initModuleDocument() {
        functionList.clear();
        System.out.println("Modulo " + module);
        
        if ( module == null ) {
            return;
        }
        initModuleInfo();
        selectTableUsageList();
        selectTargetInclusionList();
        initModuleFunctions();
    }
    
    /**
     * Inicializa��o da documenta��o de um conjunto de fun��es que n�o fazem
     * necess�riamente todas parte do mesmo m�dulo 4gl.
     */
    public void initFunctionsDocument() {
        String strWhere;
        
        strWhere = null;
        functionList.clear();
        initFunctionList(strWhere);
    }
    
    /**
     * Inicializa a informa��o especifica sobre o m�dulo
     */
    private void initModuleInfo() {
        String strSql = "select comments from p4gl_module " +
        " where module_name = '" + module + "'";
        System.out.println("<BR>" + strSql);
        try {
            Statement stmt=P4glConnection.getConnection().createStatement();
            ResultSet rs = stmt.executeQuery(strSql);
            if ( rs.next() )
                setComments(rs.getString(1));
        }
        catch (SQLException e) {
            // ???? TODO : ver como se gerem excep��es no JSP
        }
    }
    
    /**
     * Inicializa um array list que passa a conter a lista de fun��es do m�dulo
     * @todo Inserir package como par�metro
     */
    private void initModuleFunctions() {
        String strSql = "select module_name, function_name from p4gl_function " +
        " where module_name = '" + module + "'";
        System.out.println("<BR>" + strSql);
        try {
            Statement stmt=P4glConnection.getConnection().createStatement();
            ResultSet rs = stmt.executeQuery(strSql);
            while ( rs.next() ) {
                FunctionDescription fd = new FunctionDescription();
                fd.setModule(rs.getString(1));
                fd.setName(rs.getString(2));
                fd.select();
                functionList.add(fd);
            }
        }
        catch (SQLException e) {
            // ???? TODO : ver como se gerem excep��es no JSP
        }
    }
    
    /**
     * Select the usage of tables in the module and insert them as elements of the array
     * list.
     *
     * @todo Inserir package como par�metro
     */
    private void selectTableUsageList() {
        String strSql = "SELECT unique table_name " +
        " FROM p4gl_table_usage " +
        " WHERE module_name = '" + module +"'";
        System.out.println("<BR>" + strSql);
        try {
            Statement stmt=P4glConnection.getConnection().createStatement();
            ResultSet rs = stmt.executeQuery(strSql);
            while ( rs.next() ) {
                TableUsage tu = new TableUsage();
                tu.setTableName(rs.getString(1));
                tableUsageList.add(tu);
            }
        }
        catch (SQLException e) {
            // ???? TODO : ver como se gerem excep��es no JSP
        }
    }

    /**
     * Select the target inclusion list and insert them as elements of the array
     * list.
     *
     * @todo Inserir package como par�metro
     */
    private void selectTargetInclusionList() {
        String strSql = "select p4gl_program.program_name, p4gl_program.comments " +
        " from p4gl_program, p4gl_module_prog " +
        " WHERE p4gl_program.program_name = p4gl_module_prog.program_name and p4gl_module_prog.module_name = '" + module +"'";
		// "G13a.4gl"

		System.out.println("<BR>" + strSql);
        try {
            Statement stmt=P4glConnection.getConnection().createStatement();
            ResultSet rs = stmt.executeQuery(strSql);
            while ( rs.next() ) {
                TargetInclusion ti = new TargetInclusion();
                ti.setTargetName(rs.getString(1));
                targetInclusionList.add(ti);
            }
        }
        catch (SQLException e) {
            // ???? TODO : ver como se gerem excep��es no JSP
        }
    }


    /**
     * Inicializa um array list que passa a conter a lista de fun��es do m�dulo
     *
     * @param whereStr String que contem a restri��o para a cl�usula de where
     *
     */
    private void initFunctionList(String whereStr) {
        String strSql;
        if ( idProcess != null && ! idProcess.equalsIgnoreCase("null") ) {
            strSql =
            "select p4gl_function.module_name, p4gl_function.function_name " +
            " from p4gl_function,p4gl_fun_process " +
            " where p4gl_function.id_package = p4gl_fun_process.id_package " +
            " and p4gl_function.module_name = p4gl_fun_process.module_name " +
            " and p4gl_function.function_name = p4gl_fun_process.function_name " +
            " and id_process = '" + idProcess + "'"
            ;
        }
        else {
            strSql = "select module_name, function_name from p4gl_function ";
        }
        
        try {
            Statement stmt = P4glConnection.getConnection().createStatement();
            ResultSet rs = stmt.executeQuery(strSql);
            while ( rs.next() ) {
                FunctionDescription fd = new FunctionDescription();
                fd.setModule(rs.getString(1));
                fd.setName(rs.getString(2));
                fd.select();
                functionList.add(fd);
            }
        }
        catch (SQLException e) {
            // ???? TODO : ver como se gerem excep��es no JSP
        }
    }
    
    /**
     * Mostra o sum�rio do m�dulo
     */
    public void showModuleSummary() {
        //TODO: move this URL to .properties file or in database
		String CVSURL = "http://cvs.sourceforge.net/cgi-bin/viewcvs.cgi/apps4gl/apps/erp/src/";

		println("<HR><H2>");
		println("<BR>Module: " +
//		"<a href='http://cvs.sourceforge.net/cgi-bin/viewcvs.cgi/apps4gl/apps/erp/src/" +
		"<a href='" + CVSURL +
        getProcess() + "/" + getModule() + "'>" + getModule() + "</a></H2>");

        println("<HR>");
        if ( getComments() != null && ! getComments().trim().equals("") ) {
            println("<HR>");
            println("<P>" + getComments() );
            println("<HR>");
        }
    }
    
    /**
     * Mostra o sum�rio do processo
     *
     * @todo - Terminar implementa��o lendo dados da tabela do processo
     */
    public void showProcessSummary() {
        if ( idProcess == null || idProcess.equalsIgnoreCase("null") ) {
            println("<HR><H2><BR>Functions of all processes</H2><HR>");
            return;
        }
        println("<HR><H2>");
        println("<BR>Process: " +  idProcess + "</H2>");
        println("<HR>");
    }
    
    /**
     * Mostra o sum�rio da tabela de acordo com as op��es configuradas
     * Efectua a inicializa��o da informa��o sobre cada tabela nesta fase
     */
    public void showFunctionSummary() {
        for ( int i = 0 ; i <  functionList.size() ; i++ ) {
            FunctionDescription fd = (FunctionDescription) functionList.get(i);
            showFunctionSummary(fd);
        }
    }
    
    /** Show the summary information of the function.
     * Used in the function index.
     * @param fd The function description information.
     */
    public void showFunctionSummary(FunctionDescription fd) {
        println("<TR BGCOLOR='white' CLASS='TableRowColor'>");
        println("<TD ALIGN='right' VALIGN='top' WIDTH='1%'><FONT SIZE='-1'>");
        println("<CODE>&nbsp;<A HREF=#" +
        fd.getName() + ">" + fd.getName().trim() + "</A></CODE></FONT></TD>"
        );
        if ( fd.getComments() == null || fd.getComments().trim().equals("") )
            println("<TD><CODE>-</CODE></TD>");
        else
            println("<TD><CODE>" + fd.getComments().trim() + "</CODE></TD>");
        println("</TR>");
    }

    /** Show the table usage summary.
     */
    public void showTableSummary() {
        for (int i = 0 ; i < tableUsageList.size() ; i++ ) {
            String tableName;

            TableUsage tableUsage = (TableUsage)tableUsageList.get(i);
            tableName = tableUsage.getTableName();
            println("<TR BGCOLOR='white' CLASS='TableRowColor'>");
            println("<TD><CODE><B>" +
            tableName +
            "</B></CODE></TD></TR>"
            );
        }
    }

    /** Show the target inclusion summary.
     * @todo Show the target (program or library) comment
     * @todo Show target type
     * @todo create a TargetDocument page
	 * @todo Make target name in this table a hyper link to TargetDocument page
     */
    public void showInclusionSummary() {
        for (int i = 0 ; i < targetInclusionList.size() ; i++ ) {
            String targetName;

            TargetInclusion targetInclusion = (TargetInclusion)targetInclusionList.get(i);
            targetName = targetInclusion.getTargetName();
            println("<TR BGCOLOR='white' CLASS='TableRowColor'>");
            println("<TD><CODE><B>" +
            targetName +
            "</B></CODE></TD></TR>"
            );
        }
    }

/* TODO:
moduleDocument.showFormSummary()
moduleDocument.showHelpSummary()
moduleDocument.showMenuSummary()
*/


	/**
     * Devolve em html a informa��o detalhada sobre as fun��es do m�dulo
     */
    public void showFunctionDetail() {
        for ( int i = 0 ; i < functionList.size() ; i++ ) {
            FunctionDescription ti = (FunctionDescription)functionList.get(i);
            showFunctionDetail(ti);
        }
    }
    
    /**
     * Mostra os dados especificos e detalhados de uma fun��o
     *
     * @param functionInfo Informa��o descritiva da fun��o
     */
    public void showFunctionDetail(FunctionDescription functionInfo) {
        println("<A NAME='" + functionInfo.getName().trim() + "'><!-- --></A>");
        println("<H3>" + functionInfo.getName().trim() + "</H3>");
        
        showFunctionDeclaration(functionInfo);
        println("<DL>");
        if ( functionInfo.getComments() != null &&
        ! functionInfo.getComments().trim().equals("") )
            println("<DD>" + functionInfo.getComments().trim() + "</DD>");
        showFunctionParameters(functionInfo);
        showFunctionReturns(functionInfo);
        showFunctionTodos(functionInfo);
        println("</DL>");
        println(
        "<TABLE BORDER='1' CELLPADDING='3' CELLSPACING='0' WIDTH='100%'>"
        );
        println("<HR>");
    }
    
    /**
     * Mostra a declara��o da fun��o
     */
    private void showFunctionDeclaration(FunctionDescription functionInfo) {
        println("<PRE>");
        if ( functionInfo.getFunctionType().equals("R") )
            print("REPORT ");
        else
            print("FUNCTION ");
        /* FALTAM REPORTS */
        print(functionInfo.getName().trim() + "(" );
        
        ArrayList paramList = functionInfo.getParameters();
        for ( int i = 0 ; i < paramList.size() ; i++ ) {
            if ( i > 0 ) print(",");
            FunctionParameter par = (FunctionParameter)paramList.get(i);
            print(par.getVarName().trim());
        }
        println(")</PRE>");
    }
    
    /**
     * Mostra os par�metros da fun��o
     * @param functionInfo Refer�ncia para o objectop que descreve a fun��o
     */
    private void showFunctionParameters(FunctionDescription functionInfo) {
        ArrayList paramList = functionInfo.getParameters();
        if ( paramList.size() <= 0 )
            return;
        
        println("<BR><DD>");
        println("<DL>");
        println("<DT><B>Parameters:</B>");
        for ( int i = 0 ; i < paramList.size() ; i++ ) {
            FunctionParameter par = (FunctionParameter)paramList.get(i);
            println("<DD><CODE>" + par.getVarName().trim() + " " +
            par.getDataType() + "</CODE> ");
            println(par.getComments());
        }
        println("</DL>");
        println("</DD>");
    }
    
    private void print(String str) {
        try {
            out.write(str);
        }
        catch (IOException e) {
            /// ???? TODO - Gest�o dos erros
        }
    }
    
    /**
     * Mostra os coment�rios aos returns da fun��o
     *
     * @param functionInfo Refer�ncia para o objecto que descreve a fun��o
     */
    private void showFunctionReturns(FunctionDescription functionInfo) {
        ArrayList retList = functionInfo.getReturns();
        if ( retList.size() <= 0 )
            return;
        
        println("<BR><DD>");
        println("<DL>");
        println("<DT><B>Return values:</B>");
        for ( int i = 0 ; i < retList.size() ; i++ ) {
            FunctionReturn ret = (FunctionReturn)retList.get(i);
                        /* @todo Nome da vari�vel e tipo
                  println("<DD><CODE>" + par.getVarName().trim() + " " +
                          par.getDataType() + "</CODE> ");
                         */
            println("<DD><CODE>" + ret.getComment().trim() + "</CODE> ");
        }
        println("</DL>");
        println("</DD>");
    }
    
    private void println(String str) {
        try {
            out.write(str.trim() + "\n");
        }
        catch (IOException e) {
            /// ???? TODO - Gest�o dos erros
        }
    }
    
    /**
     * Mostra a lista de todos da fun��o
     *
     * @param functionInfo Refer�ncia para o objecto que descreve a fun��o
     */
    private void showFunctionTodos(FunctionDescription functionInfo) {
        ArrayList todoList = functionInfo.getTodos();
        if ( todoList.size() <= 0 )
            return;
        
        println("<BR><DD>");
        println("<DL>");
        println("<DT><B>Todo task list:</B>");
        for ( int i = 0 ; i < todoList.size() ; i++ ) {
            String todo = (String)todoList.get(i);
                        /* @todo Nome da vari�vel e tipo
                  println("<DD><CODE>" + par.getVarName().trim() + " " +
                          par.getDataType() + "</CODE> ");
                         */
            println("<DD><CODE>" + todo.trim() + "</CODE> ");
        }
        println("</DL>");
        println("</DD>");
    }
    
    /** Just for testing purpose
     * @param args  */    
    public static void main(String args[]) {
        ModuleDocument td = new ModuleDocument();
        System.out.println("Hello world");
    }
}
