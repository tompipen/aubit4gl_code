<!--

  Página de auditoria a erros/avisos relativos à documentação.

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

  <jsp:useBean id="documentAudit" scope="request" class="pt.moredata.fgldocumenter.browser.DocumentAudit"/>

	<% documentAudit.setOut(out); %>
	<% documentAudit.setProcess(request.getParameter("process")); %>
	<% documentAudit.initErrors(); %>

	<% documentAudit.showProcessSummary(); %>

  <A NAME='error_summary'></A>
	<TABLE BORDER='1' CELLPADDING='3' CELLSPACING='0' WIDTH='100%'>
    <TR BGCOLOR='#CCCCFF' CLASS='TableHeadingColor'>
      <TD COLSPAN=2><FONT SIZE='+2'><B>Function Summary</B></FONT></TD>
    </TR>
	  <% documentAudit.showErrorSummary(); %>
  </TABLE>

  &nbsp;<BR>

  <A NAME="error_detail"><!-- --></A>
  <TABLE BORDER="1" CELLPADDING="3" CELLSPACING="0" WIDTH="100%">
    <TR BGCOLOR="#CCCCFF" CLASS="TableHeadingColor">
      <TD COLSPAN=1><FONT SIZE="+2">
      <B>Function Detail</B></FONT></TD>
    </TR>
  </TABLE>
	<% documentAudit.showErrorDetail(); %>

	</FONT>
</BODY>

</HTML>
