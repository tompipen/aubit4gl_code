

<!-- TODO - Mensagens independentes de locale -->
<%@ page import="java.sql.*" %>
<jsp:useBean id="implicitDS" scope="session" 
  class="pt.moredata.fgldocumenter.browser.P4glConnection" />

<HTML>


<HEAD>
  <TITLE>Módulos de processo/funcionalidade</TITLE>
  <LINK REL ="stylesheet" TYPE="text/css" HREF="stylesheet.css" TITLE="Style">
</HEAD>

<BODY>
  <H2>Módulos</H2>

	<%
	  String strSql;
	  String process = request.getParameter("process");
	  if ( process == null || process.equals("all") )
	    strSql = "select module_name from p4gl_module ";
          else
          {
	    strSql = "select unique module_name from p4gl_fun_process " +
		           " where id_process = '" + process + "'";
          }
	  Statement stmt = implicitDS.getConnection().createStatement();
	  ResultSet rs = stmt.executeQuery(strSql);
	%>

	<FONT CLASS=FrameItemFont">
	<% while ( rs.next() ) { %>
		<BR>
		<FONT SIZE=-1>
	  <A HREF="module.jsp?module=<%= rs.getString(1)%>"
		  TARGET="descriptionFrame">
		<%= rs.getString(1) %> 
	<% } %> </A>
	  </FONT>

	 <BR><A HREF="function_list.jsp?process=<%= request.getParameter("process")%>"
		  TARGET="descriptionFrame">
		  All functions
	  </A>
	</FONT>

</BODY>

</HTML>
