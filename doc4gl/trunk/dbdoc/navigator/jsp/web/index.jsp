<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN""http://www.w3.org/TR/REC-html40/loose.dtd>
<!--NewPage-->


<%@ page import="pt.moredata.dao.DataSource" %>

<%@
    /* no longer exists:
	page import="pt.moredata.java.ddata.connection.DDataSourcePool"
    */
%>

<!--

pt.moredata.java.ddata.DDataSource = pt.moredata.dao.DataSource

	despo-data is obsolete - now moredata

	Values starting with DOC4GL_ will get replaced automatically by make file install target
	this should be in .properties file:

  <jsp:setProperty name="implicitDS" property="connectionType" value="jdbc"/>
  <jsp:setProperty name="implicitDS" property="sgbdUrl"        value="informix-sqli"/>
  <jsp:setProperty name="implicitDS" property="hostName" value="ninja"/>
  <jsp:setProperty name="implicitDS" property="service"  value="1530"/>
  <jsp:setProperty name="implicitDS" property="dbName"   value="geproducao"/>
  <jsp:setProperty name="implicitDS" property="server"  value="INFORMIXSERVER=unstable"/>
  <jsp:setProperty name="implicitDS" property="userName" value="sergio"/>
  <jsp:setProperty name="implicitDS" property="password" value="jfola45"/>

-->

<jsp:useBean id="implicitDS" scope="session" class="pt.moredata.dao.DataSource">
  <jsp:setProperty name="implicitDS" property="connectionType" 	value="DBDOC_CONNECTIONTYPE"/>
  <jsp:setProperty name="implicitDS" property="sgbdUrl"        	value="DBDOC_SGDBURL"/>
  <jsp:setProperty name="implicitDS" property="hostName"		value="DBDOC_HOSTNAME"/>
  <jsp:setProperty name="implicitDS" property="service"  		value="DBDOC_SERVICE"/>
  <jsp:setProperty name="implicitDS" property="dbName"   		value="DBDOC_DBNAME"/>
  <jsp:setProperty name="implicitDS" property="server"  		value="DBDOC_SERVER"/>
  <jsp:setProperty name="implicitDS" property="userName" 		value="DBDOC_USERNAME"/>
  <jsp:setProperty name="implicitDS" property="password" 		value="DBDOC_PASSWORD"/>
	<% 
		/* no longer exists:
		implicitDS.connect();
		*/
	%>
</jsp:useBean>

<!-- no longer exists

<jsp:useBean id="connection" scope="session" class="pt.moredata.java.ddata.connection.DDataSourcePool">
  <% connection.setImplicitDataSource(implicitDS); %>
</jsp:useBean>

          Statement stmt=DbDocumenter.getConnection().createStatement();
		  /*
			  Statement stmt=DataSourcePool.getImplicitDataSource().
				getConnection().createStatement();
          */

-->

<HTML>
<HEAD>
  <!-- TODO - Receber a base de dados como parametros -->
  <TITLE> Database Documentation </TITLE>
</HEAD>
	<% if ( implicitDS.getConnection() == null ) { %>
		<BODY>
	  <B>Conexão impossivel</B>
		</BODY>
  <% } %>

<FRAMESET cols="20%,80%">
  <FRAMESET rows="30%,70%">
    <FRAME src="modules.jsp" name="moduleListFrame">
    <FRAME src="tables.jsp" name="tablesFrame">
  </FRAMESET>
  <FRAME src="tables_detail.jsp" name="tablesDetailFrame">
</FRAMESET>

<NOFRAMES>
  <H2>Frame Alert</H2>

  <P>
  This document is designed to be viewed using the frames feature. 
	If you see this message, you are using a non-frame-capable web client.
  <BR>Link to <A HREF="tabledetail.jsp">Non-frame version.</A>
</NOFRAMES>
</HTML>
