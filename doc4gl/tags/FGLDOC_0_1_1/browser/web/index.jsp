<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN""http://www.w3.org/TR/REC-html40/loose.dtd>
<!--NewPage-->


<%@ page import="pt.moredata.fgldocumenter.browser.P4glConnection" %>

  <!-- Values starting with DOC4GL_ will get replaced automatically by make file install target -->
<!--
org.apache.jasper.JasperException: Cannot find any information on 
property 'connectionType' in a bean of type 'pt.moredata.fgldocumenter.browser.P4glConnection'
-->


<jsp:useBean id="implicitDS" scope="session" class="pt.moredata.fgldocumenter.browser.P4glConnection">
  <jsp:setProperty name="implicitDS" property="connectionType" 	value="DOC4GL_CONNECTIONTYPE"/>
  <jsp:setProperty name="implicitDS" property="sgbdUrl"        	value="DOC4GL_SGDBURL"/>
  <jsp:setProperty name="implicitDS" property="hostName"		value="DOC4GL_HOSTNAME"/>
  <jsp:setProperty name="implicitDS" property="service"  		value="DOC4GL_SERVICE"/>
  <jsp:setProperty name="implicitDS" property="dbName"   		value="DOC4GL_DBNAME"/>
  <jsp:setProperty name="implicitDS" property="server"  		value="DOC4GL_SERVER"/>
  <jsp:setProperty name="implicitDS" property="userName" 		value="DOC4GL_USERNAME"/>
  <jsp:setProperty name="implicitDS" property="password" 		value="DOC4GL_PASSWORD"/>
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
