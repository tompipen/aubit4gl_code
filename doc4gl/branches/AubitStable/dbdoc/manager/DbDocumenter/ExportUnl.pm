#!/usr/bin/perl -w

# ============================================================================
# Classe que trata de exportar o conteudo das tabelas para formato de unload
#
#
#  $Id: ExportUnl.pm,v 1.1 2003-05-22 08:48:23 afalout Exp $
#  $Author: afalout $
# ============================================================================

package DbDocumenter::ExportUnl;

# Nao trabalha por causa do FILE HANDLER
#use strict;
#use Shell;

# ============================================================================
# Construtor
# ============================================================================
sub new
{

	my $exportUnl = {
    "exportDirectory" => "",
    "err"             => 0,
    "log"             => 0,
    "processesUnl"    => "d_modules.unl",
    "tablesUnl"       => "systableext.unl",
    "tabProcUnl"      => "d_mod_tab.unl",
    "columnsUnl"      => "syscolumnext.unl",
		"ignoreExistDir"  => 1,
    "dbh"             => 0,
	};
	bless $exportUnl, "DbDocumenter::ExportUnl";
	return $exportUnl;
}

#  ===========================================================================
#  Assign the object of error management used
#  ===========================================================================
sub setErr
{
  my $obj = shift;
	$obj->{err} = shift;
}

#  ===========================================================================
#  Afecta a referência para o objecto de gestão de log(s)
#  ===========================================================================
sub setLog
{
  my $obj = shift;
	$obj->{log} = shift;
}

#  ===========================================================================
#  Afecta o nome do directório de exportação
#  ===========================================================================
sub setExportDirectory
{
  my $obj = shift;
	$obj->{exportDirectory} = shift;
}


#  ===========================================================================
#  ===========================================================================
sub setProcessesUnl
{
  my $obj = shift;
  $obj->{processesUnl} = shift;
}

#  ===========================================================================
#  ===========================================================================
sub setTablesUnl
{
  my $obj = shift;
  $obj->{tablesUnl} = shift;
}

#  ===========================================================================
#  ===========================================================================
sub setTabProcUnl
{
  my $obj = shift;
  $obj->{tabProcUnl} = shift;
}

#  ===========================================================================
#  ===========================================================================
sub setColumnsUnl
{
  my $obj = shift;
  $obj->{columnsUnl} = shift;
}

#  ===========================================================================
#  Afecta a referencia para o handler de acesso à base de dados
#  ===========================================================================
sub setDbh
{
  my $obj = shift;
  $obj->{dbh} = shift;
}

#  ===========================================================================
#  Testa se existe e cria o directorio enviado como parametro
#  @todo Testar se existe ficheiro com o mesmo nome
#
#  @return 1 - OK, 0 caso contrario
#  ===========================================================================
sub testCreateDir
{
  my $obj = shift;
  my $dir = shift;
	if ( -d $dir )
	{
		if ( $obj->{ignoreExistDir} == 0 )
		{
		  return 0;
		}
    $obj->{log}->log("Directory $dir exists allready \n");
		return 1;
	}

	unless (mkdir($dir,0777 ))
	{
	  $obj->{err}->error(
			"Criaçao de directorio para gerar unload",
		  "Error creating $dir :$!"
    );		
		return 0;
  }
  $obj->{log}->log("Directory $dir created \n");
  return 1;
}

# ============================================================================
# Cria o directório para onde os dados são exportados
#
# @return 0 : Ocorreu erro ; 1 : Tudo correcto
# ============================================================================
sub createDir
{
  my $obj = shift;
	if ( $obj->testCreateDir($obj->{exportDirectory}) )
	{
	}
}

# ============================================================================
# Faz um unload generico de uma tabela
# ============================================================================
sub unloadTable
{
  my $obj       = shift;
	my $tableName = shift;
	my $UNL_FILE  = shift;

  my $sthUnl = $obj->{dbh}->prepare(qq% SELECT * FROM $tableName %);
  unless ($sthUnl->execute())
	{
	  die "Can't select from p4gl_excel: $!";
		return 0;
	}
  my @row;
  while (@row = $sthUnl->fetchrow_array())
  {
		my $i = 0;
		while ( $i <= $#row )
		{
			my $val;
			if ( defined $row[$i] )
			{
			  $val = $row[$i];
			  $val =~ s/ *$//g;
			}
			else
			{
			  $val = "";
			}
		  print $UNL_FILE "$val|" ;
			$i++;
		}
		print $UNL_FILE "\n";
  }
  undef $sthUnl;
  return 1;
}

# ============================================================================
# Descarrega os processos que existem na tabela (d_modulos)
# @todo Confirmação de ficheiro existente e se se deve ou não escrever por cima
# ============================================================================
sub unloadProcesses
{  
  my $obj       = shift;
	my $fileName = $obj->{exportDirectory} . "/" . $obj->{processesUnl};
  unless (open(PROCESS_UNL, "> $fileName"))
	{
    $obj->{log}->log("Cant open file $fileName\n");
		return 0;
  }
	my $PROCESS_UNL=PROCESS_UNL;
	$obj->unloadTable("d_modulos",$PROCESS_UNL);
  $obj->{log}->log("Pocesses unloaded to $fileName");
	close(PROCESS_UNL);
	return 1;
}

# ============================================================================
# Descarrega a informação adicional de uma tabela para um ficheiro de unload
# ============================================================================
sub unloadTablesInfo
{
  my $obj       = shift;
	my $fileName = $obj->{exportDirectory} . "/" . $obj->{tablesUnl};
  unless (open(TABLES_UNL, "> $fileName"))
	{
    $obj->{log}->log("Cant open file $fileName\n");
		return 0;
  }
	my $TABLES_UNL=TABLES_UNL;
	$obj->unloadTable("systableext",$TABLES_UNL);
	close(TABLES_UNL);
  $obj->{log}->log("Tables unloaded to $fileName");
	return 1;
}

# ============================================================================
# Descarrega os dados relativos à tabela que associa tabelas a processos
# ============================================================================
sub unloadTablesProcesses
{
  my $obj       = shift;
	my $fileName = $obj->{exportDirectory} . "/" . $obj->{tabProcUnl};
  unless (open(TAB_PROC_UNL, "> $fileName"))
	{
    $obj->{log}->log("Cant open file $fileName\n");
		return 0;
  }
	my $TAB_PROC_UNL=TAB_PROC_UNL;
	$obj->unloadTable("d_mod_tab",$TAB_PROC_UNL);
	close(TAB_PROC_UNL);
  $obj->{log}->log("Modules unloaded to $fileName");
	return 1;
}

# ============================================================================
# Descarrega a informação adicional relativa a colunas
# ============================================================================
sub unloadColumns
{
  my $obj       = shift;
	my $fileName = $obj->{exportDirectory} . "/" . $obj->{columnsUnl};
  unless (open(COLUMNS_UNL, "> $fileName"))
	{
    $obj->{log}->log("Cant open file $fileName\n");
		return 0;
  }
	my $COLUMNS_UNL=COLUMNS_UNL;
	$obj->unloadTable("syscolumnext",$COLUMNS_UNL);
	close(COLUMNS_UNL);
  $obj->{log}->log("Columns unloaded to $fileName");
	return 1;
}

# ============================================================================
# Descarrega as tabelas
# ============================================================================
sub unloadTables
{
  my $obj       = shift;
  $obj->unloadProcesses();
  $obj->unloadTablesInfo();
  $obj->unloadTablesProcesses();
  $obj->unloadColumns();
}

# ============================================================================
# Executa a exportação do modelo de dados para unload
# ============================================================================
sub exportUnl
{
  my $obj       = shift;
  $obj->createDir();
	$obj->unloadTables();
}

return 1;
