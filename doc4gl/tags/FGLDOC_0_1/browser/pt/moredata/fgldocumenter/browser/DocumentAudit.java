
package pt.moredata.fgldocumenter.browser;

import java.util.*;
import java.io.*;
import java.sql.*;
//import pt.despodata.java.ddata.*;
//import pt.despodata.java.ddata.connection.*;


/**
 * Gera a documentação relativa a eventuais erros existentes na documentação
 *
 * @author $Author: saferreira $
 * @version $Revision: 1.1 $
 *
 * Faz as seguintes validações:
 *   - Funções sem comentários
 *   - Parametros sem comentários.
 *   - Parametros errados
 *   - Módulos sem comentários
 */

public class DocumentAudit {
    
    /** Referência para a stream de output */
    Writer out;
    
    /** Chave primária do processo a documentar */
    String idProcess;
    
    /** Nome do módulo */
    String moduleName;
    
    /** Nome da função */
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
     * Seleccionar módulos sem comentários e guardar erros no array list
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
            // ???? TODO : ver como se gerem excepções no JSP
        }
    }
    
    private void selectFunctionWithoutComments() {
    }
    
    private void selectParametersWithoutComments() {
    }
    
    private void selectWrongParameters() {
    }
    
    
    /**
     * Mostra o sumário de documentação do processo, caso exista
     */
    public void showProcessSummary() {
    }
    
    /**
     * Mostra um sumário do(s) erros
     */
    public void showErrorSummary() {
    }
    
    /**
     * Mostra o detalhe completo dos erros encontrados na documentação
     */
    public void showErrorDetail() {
    }
    
    public void setOut(Writer _out) {
        out = _out;
    }
    
}

