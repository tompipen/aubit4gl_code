
<%@ page import="java.sql.*" %>

<HTML>

<HEAD>
  <TITLE>Definição de tabela <%= request.getParameter("table") %>
  </TITLE>
</HEAD>

<BODY>

	<FONT CLASS=FrameItemFont">

  <jsp:useBean id="tablesDocument" scope="session" class="TablesDocument"/>
  <jsp:setProperty name="tablesDocument" property="table"/>
  <jsp:setProperty name="tablesDocument" property="module"/>

	<!-- Só para testar meta informação -->
  <jsp:useBean id="implicitDS" scope="session" 
	  class="pt.despodata.java.ddata.DDataSource" />	

	<%
		/*
	  DatabaseMetaData md = implicitDS.getConnection().getMetaData();
		ResultSet rs = md.getTypeInfo();
		while ( rs.next() )
		{
		  out.println("<BR><B>Type Name : </B>" + rs.getString(1));
		  out.println("<BR><B>Data Type: </B>" + rs.getShort(2));
		  out.println("<BR><B>Precision: </B>" + rs.getInt(3));
		  out.println("<BR><B>Literal Prefix : </B>" + rs.getString(4));
		  out.println("<BR><B>Literal Suffix : </B>" + rs.getString(5));
		  out.println("<BR><B>Create params : </B>" + rs.getString(6));
		  out.println("<BR><B>Nullable :  </B>" + rs.getShort(7));
		  out.println("<BR><B>Case sensitive  : </B>" + rs.getBoolean(8));
		  out.println("<BR><B>Searchable</B> : " + rs.getString(9));
		  out.println("<BR><B>Unsigned attribute</B> : " + rs.getBoolean(10));
		  out.println("<BR><B>Fixed Precision scale</B> : " + rs.getBoolean(11));
		  out.println("<BR><B>Auto increment</B> : " + rs.getBoolean(11));
		  out.println("<BR><B>Minimum scale</B> : " + rs.getShort(14));
		  out.println("<BR><B>Maximum scale</B> : " + rs.getShort(15));
		  out.println("<BR><B>SQL Data Type</B> : " + rs.getInt(16));
		  out.println("<BR><B>SQL Datetime sub</B> : " + rs.getInt(17));
		  out.println("<BR><B>Num prec Radix</B> : " + rs.getInt(18));
			out.println("<HR><BR><BR>");
		}
		*/
	%>

	<% tablesDocument.setOut(out); %>
	<% tablesDocument.showTableDocument(); %>
  
	</FONT>

</BODY>

</HTML>
