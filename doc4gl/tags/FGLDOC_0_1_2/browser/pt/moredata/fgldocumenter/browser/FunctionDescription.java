package pt.moredata.fgldocumenter.browser;

import java.util.*;
import java.sql.*;


/**
 * Store all the information that describe a 4gl function.
 * Can fill the information acessing to the information in the repository (p4gl
 * structure).
 * @todo : get and store the table usage information
 */
class FunctionDescription {
    private String name;
    private String module;
    private String comments;
    private String functionType;
    
    /** Lista de parâmetros da função */
    private ArrayList parameters = new ArrayList();
    
    /** Lista de retornos da função */
    private ArrayList returns = new ArrayList();
    
    /** Lista de todo tasks da função */
    private ArrayList todos = new ArrayList();
    
    /** Gets the name of the function.
     * @return The name of the function described
     */    
    public String getName() {
        return name;
    }
    
    /** Assign the name of the function.
     * @param _name The name of the function described
     */    
    public void setName(String _name) {
        name = _name;
    }
    
    /** Gets the text comment of the 4gl function.
     * @return The comment of the function described
     */    
    public String getComments() {
        return comments;
    }
    
    /** Assign the text comment of the function
     * @param _comments The text comment to be assigned
     */    
    public void setComments(String _comments) {
        comments = _comments;
    }
    
    /** Gets the type of the 4gl function.
     * @return The function Type:
     * - R : Report
     * - F : Function
     * - M : Main
     */    
    public String getFunctionType() {
        return functionType;
    }
    
    /** Assign the type of the function.
     * @param _functionType The type of the function:
     *  - F : regular 4gl function.
     *  - R : 4gl Report.
     *  - M : Main function.
     */    
    public void setFunctionType(String _functionType) {
        functionType = _functionType;
    }
    /** Gets the module where the function is implemented.
     * @return The name of the 4gl module where the function is declared.
     */    
    public String getModule() {
        return module;
    }
    
    /** Assign the name of the 4gl module where the function is declared.
     * @param _module The name of the 4gl module where the functions is declared.
     */    
    public void setModule(String _module) {
        module = _module;
    }
    
    /** Get the parameter list of the function.
     * @return An array list with the function parameters.
     */
    public ArrayList getParameters() {
        return parameters;
    }
    
    /** Get the list of the values/ variables returned by the function
     * @return An array list of the values returned.
     */
    public ArrayList getReturns() {
        return returns;
    }
    
    /** Gets the list of to do tasks of the described function.
     * @return The list of the the task to be done.
     */
    public ArrayList getTodos() {
        return todos;
    }
    
    
    
    /** Select the information about the function from the database.
     */
    public void select() {
        String strSql;
        
        try {
            // @todo - Package
            // @todo - Meter excepção se nome e módulo indefinido
            strSql = " select function_name, comments, function_type " +
            " from p4gl_function " +
            " where module_name = '" + getModule() + "' and function_name='" +
            getName() + "'"
            ;
            Statement stmt = P4glConnection.getConnection().
            createStatement()
            ;
            ResultSet rs = stmt.executeQuery(strSql);
            boolean ans = rs.next();
            setComments(rs.getString(2));
            setFunctionType(rs.getString(3));
        }
        catch(SQLException e) {
            // ??? Não esquecer de tratar erros
        }
        selectParameters();
        selectReturns();
        selectTodos();
    }
    
    /**
     * Selecciona os parâmetros da função e carrega-os no array list
     */
    private void selectParameters() {
        String strSql;
        
        try {
            // @todo - Package
            // @todo - Meter excepção se nome e módulo indefinido
            strSql = " select var_name, data_type, comments " +
            " from p4gl_fun_parameter " +
            " where module_name = '" + getModule() + "' and function_name='" +
            getName() + "'"
            ;
            System.out.println(strSql);
            Statement stmt = P4glConnection.getConnection().
            createStatement()
            ;
            ResultSet rs = stmt.executeQuery(strSql);
            while (rs.next()) {
                FunctionParameter fp = new FunctionParameter();
                fp.setVarName(rs.getString(1));
                fp.setDataType(rs.getString(2));
                fp.setComments(rs.getString(3));
                parameters.add(fp);
            }
        }
        catch(SQLException e) {
            System.out.println("Erro a obter informação sobre parâmetros");
            //new DDataException
        }
    }
    
    /**
     * Selecciona os retornos da função e carrega-os no array list
     */
    private void selectReturns() {
        String strSql;
        
        try {
            // @todo - Package
            // @todo - Meter excepção se nome e módulo indefinido
            strSql = " select var_name, data_type, comments from p4gl_fun_return " +
            " where module_name = '" + getModule() + "' and function_name='" +
            getName() + "'"
            ;
            System.out.println(strSql);
            Statement stmt = P4glConnection.getConnection().
            createStatement()
            ;
            ResultSet rs = stmt.executeQuery(strSql);
            while (rs.next()) {
                FunctionReturn fr = new FunctionReturn();
                fr.setVarName(rs.getString(1));
                fr.setDataType(rs.getString(2));
                fr.setComment(rs.getString(3));
                returns.add(fr);
            }
        }
        catch(SQLException e) {
            System.out.println("Erro a obter informação sobre retornos");
            //new DDataException
        }
    }
    
    /**
     * Selecciona os todos da função e carrega-os no array list
     */
    private void selectTodos() {
        String strSql;
        
        try {
            // @todo - Package
            // @todo - Meter excepção se nome e módulo indefinido
            strSql = " select comments from p4gl_fun_todo " +
            " where module_name = '" + getModule() + "' and function_name='" +
            getName() + "'"
            ;
            System.out.println(strSql);
            Statement stmt = P4glConnection.getConnection().
            createStatement()
            ;
            ResultSet rs = stmt.executeQuery(strSql);
            while (rs.next()) {
                String ft = rs.getString(1);
                todos.add(ft);
            }
        }
        catch(SQLException e) {
            System.out.println("Erro a obter informação sobre todo tasks");
            //new DDataException
        }
    }
}
