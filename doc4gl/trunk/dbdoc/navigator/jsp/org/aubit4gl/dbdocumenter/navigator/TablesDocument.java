
//package pt.moredata.fgldocumenter.browser;
package org.aubit4gl.dbdocumenter.navigator;


import java.util.*;
import java.io.*;
import java.sql.*;
//import pt.despodata.java.ddata.*;
//import pt.despodata.java.ddata.connection.*;
import pt.moredata.dao.*;


/**
 * Compila e mostra informa??o sobre um conjunto de tabelas
 * <BR>
 */

public class TablesDocument
{
	String module;
	String table;
	ArrayList tableList = new ArrayList();
	ArrayList tableInfoList = new ArrayList();
	TableDocumentOptions options;
	Writer out;

  public TablesDocument() {  }

	public void setModule(String _module)
	{
		table = null;
	  module = _module;
	}

	public void setTable(String _table)
	{
		System.out.println("SET TABLE " + _table);
	  table = _table;
	}

	public void setTableDocumentOptions(TableDocumentOptions _options)
	{
	  options = _options;
	}

	public void setOut(Writer _out)
	{
	  out = _out;
	}

	/**
	 * Inicializa??o da documenta??o de tabelas
	 */
	public void initTablesDocument()
	{
		tableList.clear();
		tableInfoList.clear();
		System.out.println("Tabela " + table);
	  if ( module == null && table == null )
		  return;

		if ( module == null )
		{
      tableList.add(table);
      return;
	  }
	  initModuleTables();
	}

	/**
	 * Inicializa um array list que passa a conter a lista de tabelas
	 * a documentar
     *
	 * Initialize an Array list that starts to contain the table list
	 * to register
	 */
	private void initModuleTables()
	{
	  String strSql = "select tabname from d_mod_tab " +
		                " where codmod = '" + module + "'";
		System.out.println("<BR>" + strSql);
		try {
                  Statement stmt=DbDocumenter.getConnection().createStatement();
		  //Statement stmt=DDataSourcePool.getImplicitDataSource().

		  // it looks like class DataSourcePool was removed - see DAOPool.java
            // cannot find method getImplicitDataSource anywhere!
//		System.out.println("<BR>FIXXXMMMEEEE<BR>");
//	  Statement stmt=DataSourcePool.getImplicitDataSource().
			  //getConnection().createStatement();

		  ResultSet rs = stmt.executeQuery(strSql);
		  while ( rs.next() )
			  tableList.add(rs.getString(1));
	  }
		catch (SQLException e)
		{
		  // ???? TODO : ver como se gerem excep??es no JSP
		}
	}

	/**
	 * Mostra todos os dados de documenta??o da(s) tabela(s) de acordo com os 
	 * parametros.
	 */
  public void showTableDocument()
	{
		initTablesDocument();
	  if ( tableList.size() == 0 )
		{
		  showDbDocumenter();
			return;
    }

		showTablesSummary();
		showTablesDetail();
	}

	/**
	 * Mostra uma p?gina que contem apenas a descri??o do m?dulo 
	 */
	public void showDbDocumenter()
	{
	  println("<H1>Documenta??o da base de dados</H1>");
	}

	/**
	 * Mostra o sum?rio da tabela de acordo com as op??es configuradas
	 * Efectua a inicializa??o da informa??o sobre cada tabela nesta fase
	 */
	public void showTablesSummary()
	{

		println("<A NAME='table_summary'></A>");
    println(
		  "<TABLE BORDER='1' CELLPADDING='3' CELLSPACING='0' WIDTH='100%'>"
		);
    println("<TR BGCOLOR='#CCCCFF' CLASS='TableHeadingColor'>");
    println("<TD COLSPAN=2><FONT SIZE='+2'>");
    println("<B>Table Summary</B></FONT></TD>");
    println("</TR>");
		for ( int i = 0 ; i <  tableList.size() ; i++ )
		{
			//DDataTableInfo ti = new DDataTableInfo();
            DataTableInfo ti = new DataTableInfo();
			ti.setTable((String) tableList.get(i));
			ti.initTableInfo();
			tableInfoList.add(ti);
		  showTableSummary(ti);
		}
    println("</TABLE>");
	}

	/**
	 * Mostra os dados resumidos da tabela 
	 * @param i Indice da tabela no array list
	 */
	//public void showTableSummary(DDataTableInfo ti)
    public void showTableSummary(DataTableInfo ti)
	{
	  println("<TR BGCOLOR='white' CLASS='TableRowColor'>");
    println("<TD ALIGN='right' VALIGN='top' WIDTH='1%'><FONT SIZE='-1'>");
    println("<CODE>&nbsp;<A HREF=#" + 
		  ti.getTableName() + ">" + ti.getTableName() + "</A></CODE></FONT></TD>"
    );
    println("<TD><CODE>" + ti.getRemarks() + "</CODE></TD>");
    println("</TR>");
	}

	/**
	 * Devolve em html a informa??o total sobre a tabela
	 */
	public void showTablesDetail()
	{
    println("<P><BR>&nbsp;<BR><A NAME='method_detail'><!-- --></A>");
    println("<TABLE BORDER='1' CELLPADDING='3' CELLSPACING='0' WIDTH='100%'>");
    println("<TR BGCOLOR='#CCCCFF' CLASS='TableHeadingColor'>");
    println("<TD COLSPAN=1><FONT SIZE='+2'>");
    println("<B>Table Detail</B></FONT></TD>");
    println("</TR>");
    println("</TABLE>");

	  for ( int i = 0 ; i < tableList.size() ; i++ )
		{
		  //DDataTableInfo ti = (DDataTableInfo)tableInfoList.get(i);
          DataTableInfo ti = (DataTableInfo)tableInfoList.get(i);
			showTableDetail(ti);
		}
	}

	/*
	 * Mostra os dados especificos de uma tabela
	 */
	//public void showTableDetail(DDataTableInfo tableInfo)
    	public void showTableDetail(DataTableInfo tableInfo)
	{
	  println("<BR>");
    println("<A NAME='" + tableInfo.getTableName().trim() + "'><!-- --></A>");
    println("<H3>" + tableInfo.getTableName().trim() + "</H3>");

    println("<DL>");
    println("<DD>" + tableInfo.getRemarks().trim() + "</DD></DL>");
    println(
		  "<TABLE BORDER='1' CELLPADDING='3' CELLSPACING='0' WIDTH='100%'>"
		);

		ArrayList columns = tableInfo.getColumns();
		//DDataFieldInfo ci;
        DataFieldInfo ci;
		for (int i = 0 ; i < columns.size() ; i++ )
		{
		  //ci = (DDataFieldInfo)columns.get(i);
   		  ci = (DataFieldInfo)columns.get(i);
      showColumn(ci);
	  }
		println("</TABLE>");
		println("<HR>");
	}

	/**
	 * Mostra os dados relativos a cada coluna
	 */
	//public void showColumn(DDataFieldInfo columnInfo)
	public void showColumn(DataFieldInfo columnInfo)
	{
	  println("<TR BGCOLOR='white' CLASS='TableRowColor'>");
    println("<TD ALIGN='right' VALIGN='top' WIDTH='1%'><FONT SIZE='-1'>");
    println("<CODE>&nbsp;" +
		  columnInfo.getColumnName() + "</CODE></FONT></TD>"
    );

	//println("<TD WIDTH='1%'><CODE>" + columnInfo.getDbDataType() + "</CODE></TD>");
    // there is no methot called getDbDataType in DataFieldInfo class !!
	println("<TD WIDTH='1%'><CODE> FIXMEEEE </CODE></TD>");

    if ( columnInfo.getRemarks() == null || 
		     columnInfo.getRemarks().trim().equals("") )
      println("<TD><CODE> - </CODE></TD>");
    else
      println("<TD><CODE>" + columnInfo.getRemarks() + "</CODE></TD>");
    println("</TR>");
	}

	public void showPrimaryKey()
	{
	}

	public void showForeignKey()
	{
	}


	private void println(String str)
	{
		try
		{
	    out.write(str.trim() + "\n");
	  }
		catch (IOException e)
		{
		   /// ???? TODO - Gest?o dos erros
		}
	}

	public static void main(String args[])
	{
	  TablesDocument td = new TablesDocument();
		System.out.println("Hello world");
	}
}
