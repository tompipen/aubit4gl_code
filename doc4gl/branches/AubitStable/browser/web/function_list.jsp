<!--

  Documenta as funções do processo que é enviado como parametro
	Caso o parâmetro não seja definido apresenta apenas uma mensagem

-->

<HTML>

<HEAD>
  <TITLE>Funções do processo<%= request.getParameter("process") %></TITLE>
</HEAD>

<BODY>

	<FONT CLASS=FrameItemFont">

	<% if ( request.getParameter("process") == null )
	  // @todo - Fazer um reencaminhamento para outra página
		out.println("<B>Processo indefinido</B>");
	%>

  <jsp:useBean id="moduleDocument" scope="request" 
	  class="pt.moredata.fgldocumenter.browser.ModuleDocument"/>
  <jsp:setProperty name="moduleDocument" property="module"/>

	<% moduleDocument.setOut(out); %>
	<% moduleDocument.setProcess(request.getParameter("process")); %>
	<% moduleDocument.initFunctionsDocument(); %>

	<% moduleDocument.showProcessSummary(); %>

  <A NAME='table_summary'></A>
	<TABLE BORDER='1' CELLPADDING='3' CELLSPACING='0' WIDTH='100%'>
    <TR BGCOLOR='#CCCCFF' CLASS='TableHeadingColor'>
      <TD COLSPAN=2><FONT SIZE='+2'><B>Function Summary</B></FONT></TD>
    </TR>
	  <% moduleDocument.showFunctionSummary(); %>
  </TABLE>

  &nbsp;<BR>

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
