

<%@ page import="pt.despodata.java.ddata.DDataControl" %>

<HTML>


<%@ page import="pt.despodata.java.ddata.DDataSource" %>
<%@ page import="java.sql.*" %>


<jsp:useBean id="implicitDS" scope="session" class="pt.despodata.java.ddata.DDataSource" />
<!-- TODO - Mensagens independentes de locale -->

<HEAD>
  <TITLE>Tabelas do módulo
	<%= request.getParameter("database") %> 
	da instância <%= request.getParameter("informixserver") %>
	no host <%= request.getParameter("host") %>
  </TITLE>
</HEAD>

<BODY>
  <H1>Tabelas</H1>

	<%
	  String strSql;
		String module = request.getParameter("module");
		if ( module == null || module.equals("all") )
	    strSql = "select tabname from systables " +
		           " where tabname not like 'sys%'";
    else
	    strSql = "select tabname from d_mod_tab " +
		           " where codmod = '" + module + "'";
		System.out.println("<BR>" + strSql);
		Statement stmt = implicitDS.getConnection().createStatement();
		ResultSet rs = stmt.executeQuery(strSql);
	%>

	<FONT CLASS=FrameItemFont">
	<BR><A HREF="tables_detail.jsp?module=<%= module %>" TARGET="tablesDetailFrame">Todas do módulo</A>
	<% while ( rs.next() ) { %>
	  <BR><A HREF="tables_detail.jsp?table=<%= rs.getString(1)%>"
		  TARGET="tablesDetailFrame">
		<%= rs.getString(1) %> 
	<% } %>
	</FONT>

</BODY>

</HTML>
