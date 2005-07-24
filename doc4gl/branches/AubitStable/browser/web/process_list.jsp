
<%@ page import="java.sql.*" %>


<HTML>
<%@ page import="pt.moredata.fgldocumenter.browser.GenJsTree"%>
<%@ page import="pt.moredata.fgldocumenter.browser.P4glConnection" %>
<%@ page import="java.sql.*" %>

<jsp:useBean id="implicitDS" scope="session" class="P4glConnection" />
<HEAD>
  <TITLE>Processos / Funcionalidades</TITLE>
  <LINK REL ="stylesheet" TYPE="text/css" HREF="stylesheet.css" TITLE="Style">

  <script src="treeview.js"></script>
	<%
	  GenJsTree jsTree = new GenJsTree();
		jsTree.setConnection(implicitDS.getConnection());
		out.println(jsTree.genProcessTree());
	%>
  <script>initializeDocument()</script>

</HEAD>

<BODY>

</BODY>


</HTML>
