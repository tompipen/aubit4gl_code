
package pt.moredata.fgldocumenter.browser;

import java.util.*;
import java.io.*;
import java.sql.*;
//import pt.despodata.java.ddata.*;
//import pt.despodata.java.ddata.connection.*;


/**
 * Gera a documenta��o relativa a eventuais erros existentes na documenta��o
 *
 * @author $Author: saferreira $
 * @version $Revision: 1.1 $
 *
 * Faz as seguintes valida��es:
 *   - Fun��es sem coment�rios
 *   - Parametros sem coment�rios.
 *   - Parametros errados
 *   - M�dulos sem coment�rios
 */

public class DocumentAudit {
    
    /** Refer�ncia para a stream de output */
    Writer out;
    
    /** Chave prim�ria do processo a documentar */
    String idProcess;
    
    /** Nome do m�dulo */
    String moduleName;
    
    /** Nome da fun��o */
    String functionName;
    
    /** Lista de erros */
    ArrayList errorList = new ArrayList();
    
    String idModuleName;
    String idFunctionName;
    public void setProcess(String _idProcess) {
        idProcess = _idProcess;
    }
    
    public String getProcess() {
        return idProcess;
    }
    
    
    public void setModuleName(String _idModuleName) {
        idModuleName = _idModuleName;
    }
    
    public String getModuleName() {
        return idModuleName;
    }
    
    
    public void setFunctionName(String _idFunctionName) {
        idFunctionName = _idFunctionName;
    }
    
    public String getFunctionName() {
        return idFunctionName;
    }
    
    /**
     * Selecciona da base de dados os eventuais erros ocorridos
     */
    public void initErrors() {
        selectModuleWithoutComments();
        selectFunctionWithoutComments();
        selectParametersWithoutComments();
        selectWrongParameters();
    }
    
    /**
     * Seleccionar m�dulos sem coment�rios e guardar erros no array list
     */
    private void selectModuleWithoutComments() {
        StringBuffer buffSql = new StringBuffer("select module_name from p4gl_module " +
        " where comments is null ");
        
        if ( idProcess != null )
            buffSql.append(" and module_name in ( select module_name " +
            " from p4gl_fun_process where id_process='" +
            idProcess.trim() + "')");
        
        if ( moduleName != null )
            buffSql.append(" and module_name = '" + moduleName + "'");
        if ( functionName == null )
            buffSql.append(" and module_name in ( "  +
            "select module_name from  p4gl_function where function_name='" +
            functionName + "')");
        
        String strSql = buffSql.toString();
        
        try {
            Statement stmt = null;
            //Statement stmt=DDataSourcePool.getImplicitDataSource().
            //getConnection().createStatement();
            ResultSet rs = stmt.executeQuery(strSql);
            while ( rs.next() ) {
                //setComments(rs.getString(1));
            }
        }
        catch (SQLException e) {
            // ???? TODO : ver como se gerem excep��es no JSP
        }
    }
    
    private void selectFunctionWithoutComments() {
    }
    
    private void selectParametersWithoutComments() {
    }
    
    private void selectWrongParameters() {
    }
    
    
    /**
     * Mostra o sum�rio de documenta��o do processo, caso exista
     */
    public void showProcessSummary() {
    }
    
    /**
     * Mostra um sum�rio do(s) erros
     */
    public void showErrorSummary() {
    }
    
    /**
     * Mostra o detalhe completo dos erros encontrados na documenta��o
     */
    public void showErrorDetail() {
    }
    
    public void setOut(Writer _out) {
        out = _out;
    }
    
}

