#!/usr/bin/perl -w

# ============================================================================
# Classe que trata de exportar o conteudo das tabelas para formato de unload
#
#
#  $Id: ImportUnl.pm,v 1.1 2003-05-22 08:48:23 afalout Exp $
#  $Author: afalout $
# ============================================================================

package DbDocumenter::ImportUnl;

# Nao trabalha por causa do FILE HANDLER
#use strict;
#use Shell;

# ============================================================================
# Construtor
# ============================================================================
sub new
{

	my $exportUnl = {
    "importDirectory" => "",
    "err"             => 0,
    "log"             => 0,
    "processesUnl"    => "d_modules.unl",
    "tablesUnl"       => "systableext.unl",
    "tabProcUnl"      => "d_mod_tab.unl",
    "columnsUnl"      => "syscolumnext.unl",
		"ignoreExistDir"  => 1,
    "dbh"             => 0,
	};
	bless $exportUnl, "DbDocumenter::ImportUnl";
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
#  Afecta o nome da tabela de unload de onde são carregados os processos
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
#  Apaga tudo da tabela 
#    @param nome da tabela de onde se pretende apagar
#  ===========================================================================
sub deleteAllFromTable
{
  my $obj = shift;
	my $tableName = $_[0];
  my $numDeleted = $obj->{dbh}->do("delete from $tableName") ||
		$obj->{err}->error(
		  "Remoção da tabela",
	    "Can't delete from $tableName\n$DBI::errstr\n"
    );
}


#  ===========================================================================
#  Insere uma linha numa tabela.
#  Faz uma serie de limpezas a linha, nomeadamente trim()
#    @param row The row to be loaded
#    @param tableName Nome da tabela a ser carregada.
#  ===========================================================================
sub insertUnlRow
{
  my $obj = shift;
	my $refRowToInsert = shift;
	my $tableName = shift;
	my @row = @$refRowToInsert;

  my $insertStr = "insert into $tableName values (";
	my $i = 0;
	while ( $i < $#row )
	{
	  if ($i > 0 )
		{
		  $insertStr .= ",";
		}
	  $insertStr .= "?";
		$i++;
	}
	$insertStr .= ")";

  my $sth = $obj->{dbh}->prepare($insertStr);
  if ( !$sth )
	{
		$obj->{err}->error(
		  "Inserção de registo",
	    "Can't prepare insert into $tableName\n$DBI::errstr\n"
    );
		return 0;
	}

	$i = 0;
	while ( $i < $#row )
	{
		my $cell;
		if ( defined($row[$i]) )
		{
		  $cell = $row[$i];
      $cell =~ s/^ *//g;
      $cell =~ s/ *$//g;
		}
		else
		{
		  $cell = "";
		}
		#print "Valor em $i : $cell\n";
	  $sth->bind_param($i+1,$cell);
		$i++;
	}
  if ( !$sth->execute() )
	{
		$obj->{err}->error(
		  "Inserção de registo",
	    "Can't insert into $tableName\n$!\n"
    );
		return 0;
	}
  undef $sth;
	return 1;
}


#  ===========================================================================
#  Carrega os dados existentes na folha de cálculo excel com separador <TAB>
#  e insere na tabela desnormalizada.
#
#    @todo Meter o delimiter configuravel
#    @param tableName O nome da tabela a carregar.
#    @param unlFileHandler Um file handler que aponta para o ficheiro aberto.
#    @param deleteAllRows Flag que indica se devemos ou não fazer delete a 
#           todas as linhas antes de inserir.
#  ===========================================================================
sub loadTable
{
  my $obj = shift;
	my $tableName      = shift;
	my $unlFileHandler = shift;
	my $deleteAllRows  = shift;

	my $line = 1;

	if ( $deleteAllRows == 1)
	{
    $obj->deleteAllFromTable($tableName);
	}
	my $unlRow;
	foreach $unlRow ( <$unlFileHandler> )
	{
		my @row = split(/\|/,$unlRow);
		if ( ! $obj->insertUnlRow(\@row,$tableName) )
	  {
			return 0;
	  }
	  $line++;
	}
	return 1;
}


# ============================================================================
# Descarrega os processos que existem na tabela (d_modulos)
# ============================================================================
sub loadProcesses
{  
  my $obj       = shift;
	my $fileName = $obj->{exportDirectory} . "/" . $obj->{processesUnl};
  unless (open(PROCESS_UNL, "< $fileName"))
	{
    $obj->{log}->log("Cant open file $fileName\n");
		return 0;
  }
	my $PROCESS_UNL=PROCESS_UNL;
	$obj->loadTable("d_modulos",$PROCESS_UNL,1);
	close(PROCESS_UNL);
  $obj->{log}->log("Processes loaded from $fileName");
	return 1;
}

# ============================================================================
# Descarrega a informação adicional de uma tabela para um ficheiro de unload
# ============================================================================
sub loadTablesInfo
{
  my $obj       = shift;
	my $fileName = $obj->{exportDirectory} . "/" . $obj->{tablesUnl};
  unless (open(TABLES_UNL, "< $fileName"))
	{
    $obj->{log}->log("Cant open file $fileName\n");
		return 0;
  }
	my $TABLES_UNL=TABLES_UNL;
	$obj->loadTable("systableext",$TABLES_UNL,1);
	close(TABLES_UNL);
  $obj->{log}->log("Tables loaded from $fileName");
	return 1;
}

# ============================================================================
# Descarrega os dados relativos à tabela que associa tabelas a processos
# ============================================================================
sub loadTablesProcesses
{
  my $obj       = shift;
	my $fileName = $obj->{exportDirectory} . "/" . $obj->{tabProcUnl};
  unless (open(TAB_PROC_UNL, "< $fileName"))
	{
    $obj->{log}->log("Cant open file $fileName\n");
		return 0;
  }
	my $TAB_PROC_UNL=TAB_PROC_UNL;
	$obj->loadTable("d_mod_tab",$TAB_PROC_UNL,1);
	close(TAB_PROC_UNL);
  $obj->{log}->log("Process table loaded from $fileName");
	return 1;
}

# ============================================================================
# Descarrega a informação adicional relativa a colunas
# ============================================================================
sub loadColumns
{
  my $obj       = shift;
	my $fileName = $obj->{exportDirectory} . "/" . $obj->{columnsUnl};
  unless (open(COLUMNS_UNL, "< $fileName"))
	{

    $obj->{log}->log("Cant open file $fileName\n");
		return 0;
  }
	my $COLUMNS_UNL=COLUMNS_UNL;
	$obj->loadTable("syscolumnext",$COLUMNS_UNL,1);
	close(COLUMNS_UNL);
  $obj->{log}->log("Columns table loaded from $fileName");
	return 1;
}

# ============================================================================
# Descarrega as tabelas
# ============================================================================
sub loadTables
{
  my $obj       = shift;
  $obj->loadProcesses();
  $obj->loadTablesInfo();
  $obj->loadTablesProcesses();
  $obj->loadColumns();
}

# ============================================================================
# Executa a exportação do modelo de dados para unload
# ============================================================================
sub importUnl
{
  my $obj       = shift;
	$obj->loadTables();
}

return 1;
