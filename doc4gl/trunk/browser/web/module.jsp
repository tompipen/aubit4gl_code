<!--

  Documenta o módulo que é enviado como parâmetro
	Caso o parâmetro não seja definido apresenta apenas uma mensagem

-->

<HTML>

<HEAD>
  <TITLE>Documentation for module <%= request.getParameter("module") %>
  </TITLE>
</HEAD>

<BODY>

	<FONT CLASS="FrameItemFont">

	<% if ( request.getParameter("module") == null )
	  // TODO - Fazer um reencaminhamento para outra página
		out.println("<B>Name of the 4gl module not specified</B>");

		//has no effect:
		//out.println("</BODY></HTML>");
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


  <!-- ========== TARGET INCLUSION SUMMARY =========== -->

  <A NAME='inclusion_summary'><!-- --></A>
  <TABLE BORDER='1' CELLPADDING='3' CELLSPACING='0' WIDTH='100%'>
    <TR BGCOLOR='#CCCCFF' CLASS='TableHeadingColor'>
      <TD COLSPAN=2><FONT SIZE='+2'><B>Target Inclusion Summary</B></FONT></TD>
    </TR>
      <% moduleDocument.showInclusionSummary(); %>
  </TABLE>
&nbsp;

  <!-- ========== FORM USAGE SUMMARY =========== -->

  <A NAME='form_summary'><!-- --></A>
  <TABLE BORDER='1' CELLPADDING='3' CELLSPACING='0' WIDTH='100%'>
    <TR BGCOLOR='#CCCCFF' CLASS='TableHeadingColor'>
      <TD COLSPAN=2><FONT SIZE='+2'><B>Form Usage Summary</B></FONT></TD>
    </TR>
      <% /* moduleDocument.showFormSummary(); */ %>
  </TABLE>
&nbsp;

  <!-- ========== HELP USAGE SUMMARY =========== -->

  <A NAME='help_summary'><!-- --></A>
  <TABLE BORDER='1' CELLPADDING='3' CELLSPACING='0' WIDTH='100%'>
    <TR BGCOLOR='#CCCCFF' CLASS='TableHeadingColor'>
      <TD COLSPAN=2><FONT SIZE='+2'><B>Help Usage Summary</B></FONT></TD>
    </TR>
      <% /* moduleDocument.showHelpSummary(); */ %>
  </TABLE>
&nbsp;

  <!-- ========== MENU USAGE SUMMARY =========== -->

  <A NAME='menu_summary'><!-- --></A>
  <TABLE BORDER='1' CELLPADDING='3' CELLSPACING='0' WIDTH='100%'>
    <TR BGCOLOR='#CCCCFF' CLASS='TableHeadingColor'>
      <TD COLSPAN=2><FONT SIZE='+2'><B>Menu Usage Summary</B></FONT></TD>
    </TR>
      <% /* moduleDocument.showMenuSummary(); */ %>
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
