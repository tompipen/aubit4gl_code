
//package pt.moredata.fgldocumenter.browser;
package org.aubit4gl.dbdocumenter.navigator;


import java.util.*;
import java.io.*;
import java.sql.*;
import pt.despodata.java.ddata.*;
import pt.despodata.java.ddata.connection.*;

/**
 * Compila e mostra informação sobre um conjunto de tabelas
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
	 * Inicialização da documentação de tabelas
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
	 */
	private void initModuleTables()
	{
	  String strSql = "select tabname from d_mod_tab " +
		                " where codmod = '" + module + "'";
		System.out.println("<BR>" + strSql);
		try {
		  Statement stmt=DDataSourcePool.getImplicitDataSource().
			  getConnection().createStatement();
		  ResultSet rs = stmt.executeQuery(strSql);
		  while ( rs.next() )
			  tableList.add(rs.getString(1));
	  }
		catch (SQLException e)
		{
		  // ???? TODO : ver como se gerem excepções no JSP
		}
	}

	/**
	 * Mostra todos os dados de documentação da(s) tabela(s) de acordo com os 
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
	 * Mostra uma página que contem apenas a descrição do módulo 
	 */
	public void showDbDocumenter()
	{
	  println("<H1>Documentação da base de dados</H1>");
	}

	/**
	 * Mostra o sumário da tabela de acordo com as opções configuradas
	 * Efectua a inicialização da informação sobre cada tabela nesta fase
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
			DDataTableInfo ti = new DDataTableInfo();
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
	public void showTableSummary(DDataTableInfo ti)
	{
	  println("<TR BGCOLOR='white' CLASS='TableRowColor'>");
    println("<TD ALIGN='right' VALIGN='top' WIDTH='1%'><FONT SIZE='-1'>");
    println("<CODE>&nbsp;<A HREF=#" + 
		  ti.getTable() + ">" + ti.getTable() + "</A></CODE></FONT></TD>"
    );
    println("<TD><CODE>" + ti.getRemarks() + "</CODE></TD>");
    println("</TR>");
	}

	/**
	 * Devolve em html a informação total sobre a tabela
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
		  DDataTableInfo ti = (DDataTableInfo)tableInfoList.get(i);
			showTableDetail(ti);
		}
	}

	/*
	 * Mostra os dados especificos de uma tabela
	 */
	public void showTableDetail(DDataTableInfo tableInfo)
	{
	  println("<BR>");
    println("<A NAME='" + tableInfo.getTable().trim() + "'><!-- --></A>");
    println("<H3>" + tableInfo.getTable().trim() + "</H3>");

    println("<DL>");
    println("<DD>" + tableInfo.getRemarks().trim() + "</DD></DL>");
    println(
		  "<TABLE BORDER='1' CELLPADDING='3' CELLSPACING='0' WIDTH='100%'>"
		);

		ArrayList columns = tableInfo.getColumns();
		DDataFieldInfo ci;
		for (int i = 0 ; i < columns.size() ; i++ )
		{
		  ci = (DDataFieldInfo)columns.get(i);
      showColumn(ci);
	  }
		println("</TABLE>");
		println("<HR>");
	}

	/**
	 * Mostra os dados relativos a cada coluna
	 */
	public void showColumn(DDataFieldInfo columnInfo)
	{
	  println("<TR BGCOLOR='white' CLASS='TableRowColor'>");
    println("<TD ALIGN='right' VALIGN='top' WIDTH='1%'><FONT SIZE='-1'>");
    println("<CODE>&nbsp;" + 
		  columnInfo.getColumn() + "</CODE></FONT></TD>"
    );
    println("<TD WIDTH='1%'><CODE>" + columnInfo.getDbDataType() + "</CODE></TD>");
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
		   /// ???? TODO - Gestão dos erros
		}
	}

	public static void main(String args[])
	{
	  TablesDocument td = new TablesDocument();
		System.out.println("Hello world");
	}
}
