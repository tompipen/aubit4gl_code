<!--

  Documenta o m�dulo que � enviado como par�metro
	Caso o par�metro n�o seja definido apresenta apenas uma mensagem

-->

<HTML>

<HEAD>
  <TITLE>Documenta��o do m�dulo <%= request.getParameter("module") %>
  </TITLE>
</HEAD>

<BODY>

	<FONT CLASS="FrameItemFont">

	<% if ( request.getParameter("module") == null )
	  // TODO - Fazer um reencaminhamento para outra p�gina
		out.println("<B>Modulo de 4gl indefinido</B>");
	%>

  <jsp:useBean id="moduleDocument" scope="request" class="pt.moredata.fgldocumenter.browser.ModuleDocument"/>
  <jsp:setProperty name="moduleDocument" property="module"/>

	<% moduleDocument.setOut(out); %>
	<% moduleDocument.initModuleDocument(); %>

	<% moduleDocument.showModuleSummary(); %>

  <A NAME='table_summary'></A>
	<TABLE BORDER='1' CELLPADDING='3' CELLSPACING='0' WIDTH='100%'>
    <TR BGCOLOR='#CCCCFF' CLASS='TableHeadingColor'>
      <TD COLSPAN=2><FONT SIZE='+2'><B>Function Summary</B></FONT></TD>
    </TR>
	  <% moduleDocument.showFunctionSummary(); %>
  </TABLE>
 &nbsp;

  <!-- ========== TABLE USAGE SUMMARY =========== -->
  
  <A NAME='table_summary'><!-- --></A>
  <TABLE BORDER='1' CELLPADDING='3' CELLSPACING='0' WIDTH='100%'>
    <TR BGCOLOR='#CCCCFF' CLASS='TableHeadingColor'>
      <TD COLSPAN=2><FONT SIZE='+2'><B>Table Usage</B></FONT></TD>
    </TR>
      <% moduleDocument.showTableSummary(); %>
  </TABLE>
&nbsp;

  <A NAME="function_detail"><!-- --></A>
  <TABLE BORDER="1" CELLPADDING="3" CELLSPACING="0" WIDTH="100%">
    <TR BGCOLOR="#CCCCFF" CLASS="TableHeadingColor">
      <TD COLSPAN=1><FONT SIZE="+2">
      <B>Function Detail</B></FONT></TD>
    </TR>
  </TABLE>
  <% moduleDocument.showFunctionDetail(); %>

</FONT>
</BODY>

</HTML>
