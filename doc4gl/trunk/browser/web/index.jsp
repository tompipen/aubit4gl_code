<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN""http://www.w3.org/TR/REC-html40/loose.dtd>
<!--NewPage-->


<%@ page import="pt.moredata.fgldocumenter.browser.P4glConnection" %>

<jsp:useBean id="implicitDS" scope="session" class="pt.moredata.fgldocumenter.browser.P4glConnection">
  <jsp:setProperty name="implicitDS" property="connectionType" value="jdbc"/>
  <jsp:setProperty name="implicitDS" property="sgbdUrl"        value="informix-sqli"/>
  <jsp:setProperty name="implicitDS" property="hostName" value="localhost"/>
  <jsp:setProperty name="implicitDS" property="service"  value="1530"/>
  <jsp:setProperty name="implicitDS" property="dbName"   value="p4gl_repository"/>
  <jsp:setProperty name="implicitDS" property="server"  value="INFORMIXSERVER=unstable"/>
  <jsp:setProperty name="implicitDS" property="userName" value="sergio"/>
  <jsp:setProperty name="implicitDS" property="password" value="jfola45"/>	
	<% implicitDS.connect(); %>
</jsp:useBean>


<HTML>
<HEAD>
  <!-- TODO - Receber a base de dados como parametros -->
  <TITLE> Fgl Project Documentation </TITLE>
</HEAD>
	<% if ( implicitDS.getConnection() == null ) { %>
		<BODY>
	  <B>Conexão impossivel</B>
		</BODY>
  <% } %>

<FRAMESET cols="20%,80%">
  <FRAMESET rows="30%,70%">
    <FRAME src="process_list.jsp" name="agregatorFrame">
    <FRAME src="module_list.jsp" name="modulesFrame">
  </FRAMESET>
  <FRAME src="module.jsp" name="descriptionFrame">
</FRAMESET>

<NOFRAMES>
  <H2>Frame Alert</H2>

  <P>
  This document is designed to be viewed using the frames feature. 
	If you see this message, you are using a non-frame-capable web client.
  <BR>Link to <A HREF="tabledetail.jsp">Non-frame version.</A>
</NOFRAMES>
</HTML>
