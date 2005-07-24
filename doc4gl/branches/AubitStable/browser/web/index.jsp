<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN""http://www.w3.org/TR/REC-html40/loose.dtd>
<!--NewPage-->


<%@ page import="pt.moredata.fgldocumenter.browser.P4glConnection" %>

<!--
  Não foi possivel estabelecer ligação à Base de dados
jdbc:informix-sqli://localhost:1543/p4gl_repository:INFORMIXSERVER=aptiva_ids;USER=root;PASSWORD=babaroga
com.informix.asf.IfxASFException: Attempt to connect to database server (aptiva_ids) failed.

OK : jdbc:informix-sqli://192.168.1.12:1543/maxdev:INFORMIXSERVER=aptiva_ids;user=root;password=babaroga
BAD: jdbc:informix-sqli://localhost:1543/p4gl_repository:INFORMIXSERVER=aptiva_ids;USER=root;PASSWORD=babaroga
BAD: jdbc:informix-sqli://192.168.1.12:1543/p4gl_repository:INFORMIXSERVER=aptiva_ids;USER=root;PASSWORD=babaroga

-->
<!--
	Values starting with DOC4GL_ will get replaced automatically by make file install target
	this should be in .properties file:
-->

<jsp:useBean id="implicitDS" scope="session" class="pt.moredata.fgldocumenter.browser.P4glConnection">
<!--
    There is something very wrong with this statement (tag markers removed);

	jsp:setProperty name="implicitDS" property="connectionType" 	value="DOC4GL_CONNECTIONTYPE"

	it's causing:

org.apache.jasper.JasperException: Cannot find any information on
property 'connectionType' in a bean of type 'pt.moredata.fgldocumenter.browser.P4glConnection'

Once again i had problem like that when i switched from Jrun to Tomcat, the reason
for my problem is that i used some jsp:setProperty  and Tomcat is more case-sensitive
than Jrun for the Parameter names and i had to verify all my parameterNames so that the
follow the convention : theParameterNameMustStartWithLowerCase and the according method
name in my bean would be: setTheParameterNameMustStartWithLowerCase(String aParamValue);


-->
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
	  <B>Database connection failed. See JSP container log file for details.</B>
      TOMCAT_HOME/logs/catalina.out
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
