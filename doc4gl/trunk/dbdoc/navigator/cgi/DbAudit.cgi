#!/usr/local/bin/perl -w


#  ============================================================================ 
#
#  Autor: Sergio Ferreira
#                                                        
#  Data de criacao: Seg Fev 14 10:59:37 WET 2000
#
#  Programa      : Db audit report
#  ---------------------------------------------------------------------------
#  DESCRICAO: 
#
#  ---------------------------------------------------------------------------
#  FUNCOES: 
# 
#  ---------------------------------------------------------------------------
#  FORMS: 
#
#  REPORTS: 
#
#  NOTAS: Por agora so valido se as tabelas tem ou nao descricao
#         ??? Devia validar se as tabelas de informacao adicional estao criadas
#
#  ============================================================================ 

use DBI;
use CGI qw(:standard);
use CGI::Carp qw(fatalsToBrowser);

#  ===========================================================================
#  ??? Falam retirar espacos no fim das strings
#  ===========================================================================
#  debug(): prints arguments visibly for debug
#  ===========================================================================
sub debug()
{
   print "<TABLE BGCOLOR=#FF0000><TR><TD><FONT FACE='Courier' COLOR=#FFFFFF SIZE=-1>",
				 "<B>", @_, "</B></FONT><TD></TR></TABLE><BR>";
}

#  ===========================================================================
#  It  get(s) the environment for access to a specific database
#  It make(s) a query to Despodata Database
#  ===========================================================================
sub getDBEnvironment()
{
	$server = param("server");
  if ( defined($server) ) {
		$ENV{INFORMIXSERVER}=$server;
	} else {
		$ENV{INFORMIXSERVER}="unstable";
	}
}

#  ===========================================================================
#  It set(s) the informix environment
#  ??? Isto deveria ser testado
#  ===========================================================================
sub InformixEnvironment()
{
   $ENV{INFORMIXDIR}="/usr/informix";
}

#  ===========================================================================
#  Verifiy the tables with no descriptions set 
#  ??? Devia tambem ver as que tem descricoes iguais a nome
#  ===========================================================================
sub auditDescriptions() {

	 $selectList = "systables.tabid,systables.tabname";
	 $strFrom    = "systables";
	 $orderBy    = "systables.tabname";

	 if (defined($StrWhere) ) { $strWhere .= " and "; }
	 $strWhere .= " systables.tabname not in (select systableext.tabname from " .
				               " systableext ) and tabid > 100";
   print h2('Tabelas sem descriçao');
	 
	 $str = "select $selectList from $strFrom where $strWhere ";
	 if ( defined($StrJoin) ) {
	    $str = $str . " and $StrJoin";
	 }
	 $str = $str . " order by $orderBy";

	$st = $db->prepare($str);
	$st->execute or die "Cant execute statement";

	print "<table border>";
	while ( @Linha = $st->fetchrow )
	{
		if (defined(@Linha))
		{
		  print "<tr>";
		  print "<td>";
			print "<a href=/cgi-bin/DbDocUpdDescription.cgi?server=$server&" .
				 "database=$DBName&table=$Linha[1]>";
			print "$Linha[1]";
      print "</a>";
			print "</td>";
		  print "</tr>";
    }
	}
	print "</table>";
}

#  ===========================================================================
#  Main
#  ===========================================================================
   # Tenho de receber o DBName como Parametro (metodo post)
	 getDBEnvironment();
	 InformixEnvironment();

	 # This should be possible to configure with some .ini
	 my $ModTabTableName = "d_mod_tab";
	 my $TabPK           = "tabname";
	 my $TablesTableName = "systables";
	 my $TablesPK        = "tabid";
	 my $ModuleDesc      = "tabname";


	 $DBName = param("database");
	 if (!defined($DBName))
	    { $DBName = "despodata"; }

   $db = DBI->connect ( "dbi:Informix:".$DBName ) 
	   or die "Error connecting to DB";

   print header, start_html('Auditoria da BD ' . $DBName );

	 $action = param("action");
	 if (!defined($action)) {
	   $action = "NO_TBL_DESC";
	 }

	 if ( $action eq "NO_TBL_DESC" ) {
	   auditDescriptions();
	 }
   $db->disconnect ;
#  End main
