#!/usr/bin/perl -w

# ============================================================================
# 
# Load the information of the process tree into the process table.
#
# developed by Sergio Ferreira from Moredata (http://www.moredata.pt), 
# Lisboa Portugal.
#
# $Id: LoadProcess.pm,v 1.1 2003-04-14 17:58:02 saferreira Exp $
# 
# ============================================================================

package FglDocumenter::LoadProcess;


use strict;
use DBI;        

#  =========================================================================
#  Constructor
#  =========================================================================
sub new
{
  my $loadProcess = {
    "unloadFileName"    => 0,
  };
  bless $loadProcess, "FglDocumenter::LoadProcess";
  return $loadProcess;
}


#  ===========================================================================
#  Assign the object of error management used
#  ===========================================================================
sub setError
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
#  Assigns the name of the file to loaded to the process table.
#    @param unloadFileName : The name of the unload file to be loaded
#  ===========================================================================
sub setUnloadFile
{
  my $obj = shift;
  $obj->{unloadFileName} = shift;
}

#  ===========================================================================
#  Set the reference to the repository that contains the database where
#  the process should be loaded.
#  ===========================================================================
sub setRepository
{
  my $obj = shift;
  $obj->{repository} = shift;
  $obj->{dbh} = $obj->{repository}->getConnection();
}

#  ===========================================================================
#  Afecta o pointer ( referencia ) para a rotina que afecta o progresso
#  ===========================================================================
sub addProgressListener
{
  my $obj = shift;
  $obj->{progressListener} = shift;
}

#  ===========================================================================
#  Conta o numero de linhas do ficheiro
#  ===========================================================================
sub lineCount
{
  my $obj = shift;
  my $numLines = 0;
  open(SHEET,"< $obj->{unloadFileName}");
  my $sheetRow;
  foreach $sheetRow ( <SHEET> )
  {
    $numLines++;
  }
  close(SHEET);
  return $numLines
}

#  ===========================================================================
#  Carrega os dados existentes na folha de cálculo excel com separador <TAB>
#  e insere na tabela desnormalizada
#  ===========================================================================
sub loadFile
{
  my $obj = shift;
  if ( $obj->{unloadFileName} eq "" )
  {
    $obj->{err}->error(
      "Process file load",
      "unload file not defined...not loaded"
    );
    return 0;
  }

  my $processColumns = 5;
  my $line = 1;
  if ( !open(PROCESS_UNL_FILE,"< $obj->{unloadFileName}") )
  {
		# @todo : Fix the error that does not in CUI
		print "Error : $!\n";
			
    $obj->{err}->error(
      "Opening file",
      "Cannot open unload file :$obj->{unloadFileName}:$!"
    );
    return 0;
  }

  #$obj->deleteAllFromTable("p4gl_excel");
  $obj->setConstraintsDisabled();
  my $processRow;
  foreach $processRow ( <PROCESS_UNL_FILE> )
  {
    my @row = split(/\|/,$processRow);
    if ( $#row + 1 != $processColumns )
    {
      if ( $obj->{log} ) 
      {
        $obj->{log}->log(
          "Error : Number of columns $#row+1 != $processColumns in line $line", 
        );
      }
    }
    else
    {
      if ( ! $obj->insertProcessRow(@row) )
      {
        return 0;
      }
    }
    $line++;
  }
  $obj->setConstraintsEnabled();

  if ( !close(PROCESS_UNL_FILE) )
  {
    $obj->{err}->error(
      "Closing file",
      "Cannot close process file\n($obj->{processFile}):$!"
    );
  }
  return 1;
}

sub setSendLineToLog
{
  my $obj = shift;
  $obj->{sendLineToLog} = shift;
}

#  ===========================================================================
#  Insert a process line, validating if it exist allready.
#  ===========================================================================
sub insertProcessRow
{
  my $obj = shift;
  my $processId   = $_[0];
  $processId =~ s/^ *//g;
  $processId =~ s/ *$//g;
  if ( $processId eq "" )
  {
    return;
  }
  if ( length($processId) > 10 )
  {
    $obj->{err}->error(
      "Carregar linha de CSV",
      "Process ID > 10 : ($processId)"
    );
  }
  my $displayProcess    = $_[1];
  $displayProcess =~ s/^ *//g;
  $displayProcess =~ s/ *$//g;
  my $denProcess = $_[2];
  my $subProcessOf = $_[3];
  $subProcessOf =~ s/^ *//g;
  $subProcessOf =~ s/ *$//g;
  my $comments = $_[4];
  if ( $subProcessOf eq "" )
	{
		# Sub process to null
	  undef($subProcessOf);
	}

	if ( $obj->existProcess($processId) )
	{
	  $obj->deleteProcess($processId);
	}

  my $sth = $obj->{dbh}->prepare(q%
    insert into p4gl_process (
      id_process,disp_process,den_process,sub_process_of,comments
    ) values (?,?,?,?,?)
  %);
  if ( !$sth )
  {
    $obj->{err}->error(
      "Inserção de registo",
      "Can't prepare insert into p4gl_process\n$DBI::errstr\n"
    );
    return 0;
  }

  if ( $obj->{sendLineToLog} == 1 )
  {
    $obj->{log}->log("LINE $processId, $displayProcess, $denProcess, $subProcessOf, $comments");
  }
  $sth->bind_param(1,$processId);
  $sth->bind_param(2,$displayProcess);
  $sth->bind_param(3,$denProcess);
  $sth->bind_param(4,$subProcessOf);
  $sth->bind_param(5,$comments);
  if ( !$sth->execute() )
  {
    $obj->{err}->error(
      "Inserting process",
      "Can't insert into p4gl_process\n$!\n"
    );
    return 0;
  }
  undef $sth;
  return 1;
}

#  ===========================================================================
#  ===========================================================================
sub setConstraintsDisabled
{
  my $obj = shift;
  my $res = $obj->{dbh}->do("set constraints for p4gl_fun_process disabled") ||
  $obj->{err}->error(
    "Disable constraints",
    "Can't disable constraints for p4gl_fun_process\n$DBI::errstr\n"
  );
  my $res = $obj->{dbh}->do("set constraints for p4gl_process disabled") ||
  $obj->{err}->error(
    "Disable constraints",
    "Can't disable constraints for p4gl_process\n$DBI::errstr\n"
  );
}

#  ===========================================================================
#  ===========================================================================
sub setConstraintsEnabled
{
  my $obj = shift;
  my $res = $obj->{dbh}->do("set constraints for p4gl_process enabled") ||
  $obj->{err}->error(
    "Disable constraints",
    "Can't disable constraints for p4gl_process\n$DBI::errstr\n"
  );
  my $res = $obj->{dbh}->do("set constraints for p4gl_fun_process enabled") ||
  $obj->{err}->error(
    "Disable constraints",
    "Can't disable constraints for p4gl_fun_process\n$DBI::errstr\n"
  );
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
#  ===========================================================================
sub existProcess
{
  my $obj = shift;
	my $idProcess = shift;
  my $sthPack = $obj->{dbh}->prepare(q%
	  SELECT count(*) FROM p4gl_process where id_process != '$idProcess'
	%);
  if ( !$sthPack )
	{
		$obj->{err}->error(
		  "Selecção de package",
	    "Can't prepare select from p4gl_package\n$DBI::errstr\n"
    );
		return 0;
	}
  $sthPack->execute() || 
		$obj->{err}->error(
		  "Selecção de package",
	    "Can't select from p4gl_package\n$DBI::errstr\n"
    );
  my(@row);
	my $numProcesses = 0;
  while (@row = $sthPack->fetchrow_array())
  {
		$numProcesses = $row[0];
  }
  undef $sthPack;

	if ( $numProcesses > 0 )
	{
	  return 1;
	}
	else
	{
	  return 0;
	}
}

#  ===========================================================================
#  Delete the process sended as parameter
#  ===========================================================================
sub deleteProcess
{
  my $obj = shift;
  my $process_id   = shift;
  my $funcName = shift;

  my $procsDeleted = $obj->{dbh}->do(qq%
    delete from p4gl_process 
      where id_process='$process_id'
    %) || 
    $obj->{err}->error(
      "Limpeza de processos",
      "Impossivel limpar processos de funçoes\n$DBI::errstr\n"
    );
  $obj->{log}->log("Processes deleted: $procsDeleted");
  $procsDeleted = $obj->{dbh}->do(qq%
    delete from p4gl_fun_process 
      where id_process='$process_id'
    %) || 
    $obj->{err}->error(
      "Limpeza de processos",
      "Impossivel limpar processos de funçoes\n$DBI::errstr\n"
    );
  $obj->{log}->log("Function Processes deleted: $procsDeleted");
}

return 1;

