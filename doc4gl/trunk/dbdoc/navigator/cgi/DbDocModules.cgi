#!/usr/local/bin/perl -w

#  ==========================================================================
#  DbDocumenter - Utilitario para documentacao de BD Informix
#  
#  Apresentacao e gestao dos modulos
#
#  Autor : Sergio Ferreira
#
#  ==========================================================================


use DBI;
use CGI qw(:standard);
use CGI::Carp qw(fatalsToBrowser);

#  ==========================================================================
#  It  get(s) the environment for access to a specific database
#  It make(s) a query to Despodata Database
#  ==========================================================================
sub GetDBEnvironment()
{
	 # ??? This should no t be like this
	$server = param("server");
   if ( defined($server) ) {
		$ENV{INFORMIXSERVER}=$server;
	} else {
		$ENV{INFORMIXSERVER}="unstable";
	}
}

#  ==========================================================================
#  It obtains and validate the parameters needed 
#  ==========================================================================
sub getParameters {
  $action = param("action");
}


#  ==========================================================================
#  It set(s) the informix environment
#  ??? This is not correct - it should see if is used or not ???
#  ==========================================================================
sub InformixEnvironment()
{
   $ENV{INFORMIXDIR}="/usr/informix";
}


#  ==========================================================================
#  It show(s) the modules existing in the database
#  ==========================================================================
sub showOptions() {
	 # This should be possible to configure with some .ini
   my $nome = $_[0];

	 connectDatabase();
	 $BDEsquema = "/cgi-bin/DbDocument.cgi?server=$server&database=" . $DBName;
	 $Modules   = "/cgi-bin/DbDocModules.cgi?server=$server&database=" . $DBName;
	 $DBAudit   = "/cgi-bin/DbAudit.cgi?server=$server&database=" . $DBName;

  print header, start_html('DBDocumenter - Base de dados - ' . $DBName);
	showModules();
	auditOptions();
	otherOptions();
  $db->disconnect ;
}

#  ==========================================================================
#  Show the options available
#  ==========================================================================
sub showModules() {

   print h1('Modulos da BD '. $DBName);

	 my $ModuleTableName = "d_modulos";
	 my $ModulePK        = "codigo";
	 my $ModuleDesc      = "nome";

	 # Tenho de vrificar se existe ou nao tabela de modulos na base de dados
   $str = 'select ' . $ModulePK . ',' . $ModuleDesc .
	        ' from ' . $ModuleTableName  . ' order by 1';


   if ( ($st = $db->prepare( $str)) and ($st->execute) ) {
      while( @linha = $st->fetchrow ) {
        print br, '<A HREF=', $BDEsquema, '&module_code=', $linha[0], '>', 
							$linha[1], '</A>';
      }
      $st->finish ;
	 } else {
        print br, b('Não há módulos definidos');
	 }

	print br,br,' <A HREF=', $BDEsquema, '&module_code=NOMODULE' .
	      '>Tabelas nao associadas a modulos</A>';
	print br,br,' <A HREF=', $BDEsquema, '>Todas as tabelas da base de dados</A>';
}

#  ==========================================================================
#  Database audit
#  ==========================================================================
sub auditOptions() {
  print hr;
	print "<center>";
	print h2('Auditoria da BD');
	print "</center>";
  print br, '<A HREF=', $DBAudit, '&action=NO_TBL_DESC>',
				'Tabelas sem descriçao</A>';
  print hr;
}

#  ==========================================================================
#  Other options available
#  ==========================================================================
sub otherOptions() {
	print hr,br, " <A HREF=$Modules&action=NewModule>Inserir novos módulos</A>";
	print br, " <A HREF=$Modules&action=ChangeModules>Alterar módulos</A>";
  print hr;
}

#  ==========================================================================
#  Ligacao a base de dados
#  ==========================================================================
sub connectDatabase {
	$DBName = param("database");
	if (!defined($DBName)) {
		$DBName = "despodata";
	}
  $db = DBI->connect ( "dbi:Informix:".$DBName ) or 
				die "Impossivel conectar à BD\n";
}


#  ==========================================================================
#  Validate if the table sysmodules exist(s)
#  If not it ask to the user if it want to create it and execute it self
#  with action=CreateSysmodules
#  ==========================================================================
sub validateTable {
}

#  ==========================================================================
#  It create or rename the sysmodules table
#  ==========================================================================
sub createSysmodules {
	connectDatabase();
	$str_create = "create table sysmodules (" .
						       "codigo char(5) not null primary key," .
						       "nome char(40) not null, " .
						       "cod_projecto char(5)," .
						       "sub_modulo_de char(5))";
	$st_create = $db->do($str_ins);   

	# ??? Falta testar o erro
  print header,start_html,"<p><b>Tabela de módulos criada ou deu erro", 
				end_html;
}

#  ==========================================================================
#  Insercao de um novo modulo
#  ==========================================================================
sub newModule {

	validateTable();
	# ??? rename (se existir d_modulos) 
	if ( param('submit')) {
		insertModule();
		return;
	}
  print header, start_html('Modulos da BD ' . $DBName),
         h1('Inserção de novo modulos na BD '. $DBName);

  print start_form;
	print "<table align=center>\n";
	print "<tr><td>Código</td><td>";
  print textfield(-name=>cod_modulo,
									-size=>5);
									#-value=>$syscolumnext[4]); 
	print "</td></tr>\n";

	print "<tr><td>Denominação</td><td>";
  print textfield(-name=>den_modulo,
									-size=>40);
	print "</td></tr>\n";

	print "<tr><td>Sub-Módulo</td><td>";
	# ??? Isto tem de passar a list box
  print textfield(-name=>sub_modulo,
									-size=>5);
	print "</td></tr>\n";

	print "<tr><td>";
	print submit(-name=>'submit',
							-value=>'Gravar');
	print reset(-value=>'Refrescar');    
	print "</td></tr>";
	print "</table>\n";

	print hidden(-name=>'database',
						-default=>$database);
	print hidden(-name=>'server',
						-default=>$server);
	print hidden(-name=>'action',
						-default=>'NewModule');

  print end_form;
}


#  ==========================================================================
#  Insrere um novo modulo na base de dados
#  ==========================================================================
sub insertModule {
	connectDatabase();
	$str_ins = "insert into sysmodules (codigo,nome,sub_modulo_de) values " .
				"('$cod_modulo','$den_modulo','$sub_modulo')";
	$st_ins = $db->do($str_ins);   

	# ??? Falta testar o erro
  print header,start_html,"<p><b>Modulo inserido ou entao deu erro", end_html;
}


#  ==========================================================================
#  Main
#  ==========================================================================
  # Tenho de receber o DBName como Parametro (metodo post)
  GetDBEnvironment();
  InformixEnvironment();

  getParameters();
	if ( $action eq "NewModule" ) {
		newModule();
	}
	elsif ( $action eq "ChangeModules" ) {
		changeModules();
	}
	elsif ( $action eq "UpdateModule" ) {
		updateModule();
	}
	elsif ( $action eq "createSysmodules" ) {
		createSysModules();
	}
	else {
		showOptions();
	}
#  End main
