
<%@ page import="pt.moredata.java.ddata.DDataControl" %>

<HTML>


<%@ page import="pt.moredata.java.ddata.DDataSource" %>
<%@ page import="java.sql.*" %>


<jsp:useBean id="implicitDS" scope="session" class="DDataSource" />
<!-- TODO - Mensagens independentes de locale -->

<HEAD>
  <TITLE>Módulos da base de dados 
	<%= implicitDS.getDbName() %>
	da instância <%= implicitDS.getServer() %>
	no host <%= implicitDS.getHostName() %>
  </TITLE>
  <LINK REL ="stylesheet" TYPE="text/css" HREF="stylesheet.css" TITLE="Style">
</HEAD>

<BODY>
  <H1>Módulos</H1>

	<%
	  String strSql = "select codigo,nome from d_modulos";
		Statement stmt = implicitDS.getConnection().createStatement();
		ResultSet rs = stmt.executeQuery(strSql);
	%>

	<FONT CLASS=FrameItemFont">
	<BR><A HREF="tables.jsp?module=all" TARGET="tablesFrame">Todas as tabelas</A>
	<% while ( rs.next() ) { %>
	  <BR> <A HREF="tables.jsp?module=<%= rs.getString(1)%>"
		  TARGET="tablesFrame">
		<%= rs.getString(1) %></A> - 
	  <%= rs.getString(2) %>
	<% } %>
	</FONT>

</BODY>

</HTML>
