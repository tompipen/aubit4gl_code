#!/usr/bin/perl -w

#  =========================================================================
#
#  Methods to interact with a repository in p4gl format.
#
#  $Author: afalout $
#  $Id: P4glRepository.pm,v 1.6 2003-05-15 10:23:26 afalout Exp $
#
#  @todo Correcto tratamento de erros e mensagens
#  @todo Retirar dependencia directa de outros packages (sempre por objecto)
#  @todo Possibilidade de criar o repositorio com o nome de base de dados
#        a definir
#
#  =========================================================================

package FglDocumenter::P4glRepository;

use strict;
use DBI;


#  =========================================================================
#  Construtora
#  =========================================================================
sub new
{
  my $p4glRepository = {
    "log"                => 0,
    "err"                => 0,
    "connection"         => 0,
    "dbh"                => 0,
  };
  bless $p4glRepository, "FglDocumenter::P4glRepository";
  return $p4glRepository;
}

#  =========================================================================
#  Afecta o objecto de acesso à base de dados
#  =========================================================================
sub setConnection
{
  my $obj = shift;
  $obj->{connection} = shift;
  $obj->{dbh} = $obj->{connection}->getConnection();
}

#  =========================================================================
#  Afecta o handler de acesso a base de dados
#  =========================================================================
sub setDbh
{
  my $obj = shift;
  $obj->{dbh} = shift;
}

#  =========================================================================
#  Afecta uma variável local com uma referência para o objecto de erros
#  =========================================================================
sub setError
{
  my $obj = shift;
  $obj->{err} = shift;
}

#  =========================================================================
#  Afecta uma variável local com uma referência para o objecto de escrita
#  no log
#  =========================================================================
sub setLog
{
  my $obj = shift;
  $obj->{log} = shift;
}

#  =========================================================================
#  Obtem a lista de packages existentes na BD (repositório)
#    @return Lista de packages
#  =========================================================================
sub selectPackages
{
  my $obj = shift;
  my @packageList = ();

  my $sth = $obj->{dbh}->prepare("select id_package from p4gl_package")
    || die "Can´t prepare insert into p4gl_fun_process: $! ";
  $sth->execute() || die "Can't insert into p4gl_fun_process: $!";
  my @row;
  while (@row = $sth->fetchrow_array())
  {
    $row[0] =~ s/ *$//;
    push(@packageList,$row[0]);
  }
  undef $sth;
  return \@packageList;
}

#  =========================================================================
#  Obtem a lista de modulos no repositório para o 
#  package corrente
#  =========================================================================
sub selectModules
{
  my $obj = shift;
  my @moduleList = ();

  my $sth = $obj->{dbh}->prepare("select module_name from p4gl_module")
    || die "Can´t prepare insert into p4gl_fun_process: $! ";
  $sth->execute() || die "Can't insert into p4gl_fun_process: $!";
  my @row;
  while (@row = $sth->fetchrow_array())
  {
    $row[0] =~ s/ *$//;
    push(@moduleList,$row[0]);
  }
  undef $sth;
  return @moduleList;
}

#  =========================================================================
#  Obtem a lista de funções no repositório para o  package corrente e 
#  módulo(s) corrente(s)
#  =========================================================================
sub selectFunctions
{
  my $obj = shift;
  my @functionList = ();

  my $sth = $obj->{dbh}->prepare("select function_name from p4gl_function")
    || die "Can´t prepare insert into p4gl_fun_process: $! ";
  $sth->execute() || die "Can't insert into p4gl_fun_process: $!";
  my @row;
  while (@row = $sth->fetchrow_array())
  {
    $row[0] =~ s/ *$//;
    push(@functionList,$row[0]);
  }
  undef $sth;
  return @functionList;
}

#  ===========================================================================
#  Insere um package na tabela p4gl_package
#  ===========================================================================
sub insertPackage
{
  my $obj = shift;
  my $idPackage = shift;
  my $comments = shift;
  my $numMods;
  unless ( $numMods = $obj->{dbh}->do(qq%
    insert into p4gl_package (id_package,comments) values
    ('$idPackage','$comments')
  %))
  {
    $obj->{err}->error(
      "Inserçao de package",
      "Impossivel inserir em p4gl_package\n$DBI::errstr\n"
    );
    return 0;
  }
  return 1;
}

#  ===========================================================================
#  Insere um modulo 4gl na tabela p4gl_module
#  ===========================================================================
sub insertModule
{
  my $obj = shift;
  my $idPackage = shift;
  my $moduleName = shift;
  my $numMods;
  unless ( $numMods = $obj->{dbh}->do(qq%
    insert into p4gl_module (id_package,module_name) values
    ('$idPackage','$moduleName')
  %))
  {
    $obj->{err}->error(
      "Inserçao de módulo",
      "Impossivel inserir em p4gl_module\n$DBI::errstr\n"
    );
    return 0;
  }
  return 1;
}

#  ===========================================================================
#  Insere uma função na tabela p4gl_function
#  ===========================================================================
sub insertFunction
{
  my $obj = shift;
  my $id_package    = shift;
  my $module_name   = shift;
  my $function_name = shift;
  my $function_type = shift;
  my $deprecated    = shift;
  my $comments      = shift;
  my $numMods;
  unless ( $numMods = $obj->{dbh}->do(qq%
    insert into p4gl_function ( id_package, module_name, function_name,
      function_type, deprecated, comments
    ) 
    values ('$id_package','$module_name',
      '$function_name','$function_type', '$deprecated', '$comments'
    );
  %))
  {
    $obj->{err}->error(
      "Inserçao de funçao",
      "Impossivel inserir em p4gl_function\n$DBI::errstr\n"
    );
    return 0;
  }
  return 1;
}

#  ===========================================================================
#  Insere um processo na tabela p4gl_process
#  ===========================================================================
sub insertProcess
{
  my $obj = shift;
  my $id_process     = shift;
  my $den_process    = shift;
  my $sub_process_of = shift;
  my $comments       = shift;
  my $numMods;
  unless ( $numMods = $obj->{dbh}->do(qq%
    insert into p4gl_process (id_process,den_process,comments) 
    values ('$id_process','$den_process', '$comments');
  %))
  {
    $obj->{err}->error(
      "Inserçao de funçao",
      "Impossivel inserir em p4gl_process\n$DBI::errstr\n"
    );
    return 0;
  }
  return 1;
}

#  ===========================================================================
#  Insere uma associaçao de processo a funçao
#  ===========================================================================
sub insertFunctionProcess
{
  my $obj = shift;
  my $id_process    = shift;
  my $id_package    = shift;
  my $module_name   = shift;
  my $function_name = shift;
  my $numMods;
  unless ( $numMods = $obj->{dbh}->do(qq%
    insert into p4gl_fun_process (
      id_process,id_package,module_name,function_name 
    )
    values ( '$id_process','$id_package','$module_name','$function_name' );
  %))
  {
    $obj->{err}->error(
      "Inserçao de funçao",
      "Impossivel inserir em p4gl_fun_process\n$DBI::errstr\n"
    );
    return 0;
  }
  return 1;
}

#  ===========================================================================
#  Apaga tudo da tabela 
#    @param nome da tabela de onde se pretende apagar
#  ===========================================================================
sub deleteAllFromTable
{
  my $obj = shift;
  my $tableName = $_[0];
  my $numDeleted;
  unless ( $numDeleted = $obj->{connection}->getConnection()->do(
    "delete from $tableName")
  )
  {
    $obj->{err}->error(
      "Remoção da tabela",
      "Can't delete from $tableName\n$DBI::errstr\n"
    );
  }
  return $numDeleted;
}



#  =========================================================================
#  Limpa os dados todos do repositório
#  =========================================================================
sub clean
{
  my $obj = shift;
  $obj->deleteAllFromTable("p4gl_excel");
  $obj->deleteAllFromTable("p4gl_fun_parameter");
  $obj->deleteAllFromTable("p4gl_fun_process");
  $obj->deleteAllFromTable("p4gl_fun_return");
  $obj->deleteAllFromTable("p4gl_fun_todo");
  $obj->deleteAllFromTable("p4gl_function");
  $obj->deleteAllFromTable("p4gl_table_usage");
  $obj->deleteAllFromTable("p4gl_process");
  $obj->deleteAllFromTable("p4gl_module_prog");
  $obj->deleteAllFromTable("p4gl_program");
  $obj->deleteAllFromTable("p4gl_module");
  $obj->deleteAllFromTable("p4gl_package");
}

#  =========================================================================
#  Executa um comando SQL
#  =========================================================================
sub execSql
{
  my $obj    = shift;
  my $sqlStr = shift;
  my $numRecords;
  unless ( $numRecords = $obj->{connection}->getConnection()->do($sqlStr))
  {
    $obj->{err}->error(
      "Execução de SQL",
      "Can't execute $sqlStr\n$DBI::errstr\n"
    );
  }
  return $numRecords;
}

#  =========================================================================
#  Create all tables that are part of the repository
#  =========================================================================
sub create
{

  my $obj = shift;
  my $retval = 1;

  my $rv;
  $rv = $obj->execSql(qq/create table p4gl_package (
    id_package char(64) not null primary key ,
    comments varchar(255)
  );
  /);


  $rv = $obj->execSql(qq/create table p4gl_program (
    program_name char(64) not null primary key,
    comments varchar(255)
  );
  /);


  $rv = $obj->execSql(qq/create table p4gl_module (
    id_package char(64) not null references p4gl_package (id_package),
    module_name char(64) not null,

    author char(64),
    revision char(64),
    deprecated     char(1) default 'N'
      not null check (deprecated in ('Y','N')),
    since char(64),
    see char(64),
    comments varchar(255),
    primary key (id_package,module_name)
  );
  /);


  $rv = $obj->execSql(qq/create table p4gl_module_prog (
    program_name char(64) not null references p4gl_program (program_name),
    id_package char(64) not null,
    module_name char(64) not null,
    primary key (program_name,id_package,module_name),
    foreign key (id_package,module_name) references 
      p4gl_module (id_package,module_name)
  );
  /);

  $rv = $obj->execSql(qq/create table p4gl_mod_todo (
    id_package char(64) not null,
    module_name char(64) not null,
    item_num smallint not null,
    comments char(255),
    primary key (id_package,module_name,item_num),
    foreign key (id_package,module_name) references 
      p4gl_module (id_package,module_name)
  );
  /);


  $rv = $obj->execSql(qq/create table p4gl_function (
    id_package     char(64) not null,
    module_name    char(64) not null,
    function_name  char(50) not null,
    function_type  char(1) default 'F' 
      not null check (function_type in ('F','R')),
    deprecated     char(1) default 'N' 
      not null check (deprecated in ('Y','N')),
    author char(64),
    since char(64),
    comments       varchar(255),
    foreign key (id_package,module_name) references 
      p4gl_module (id_package,module_name),
    primary key (id_package,module_name,function_name)
  );
  /);


  $rv = $obj->execSql(qq/create table p4gl_process (
    id_process char(20) not null primary key,
    disp_process char(20) not null,
    den_process char(64) not null,
    sub_process_of char(20) references p4gl_process(id_process),
    comments varchar(255)
  );
  /);


  $rv = $obj->execSql(qq/create table p4gl_fun_process (
    id_process char(20) not null references p4gl_process (id_process),
    id_package char(64) not null,
    module_name char(64) not null,
    function_name char(50) not null,
    primary key (id_process,id_package,module_name,function_name),
    foreign key (id_package,module_name,function_name)
      references p4gl_function (id_package,module_name,function_name)
  );
  /);


  $rv = $obj->execSql(qq/create table p4gl_fun_parameter (
    id_package char(64) not null,
    module_name char(64) not null,
    function_name char(50) not null,
    item_num smallint not null,
    var_name char(64) not null,
    data_type char(64) not null,
    comments char(255),
    primary key (id_package,module_name,function_name,item_num),
    foreign key (id_package,module_name,function_name)
      references p4gl_function (id_package,module_name,function_name)
  );
  /);


  $rv = $obj->execSql(qq/create table p4gl_fun_return (
    id_package char(64) not null,
    module_name char(64) not null,
    function_name char(50) not null,
    item_num smallint not null,
    var_name char(64),
    data_type char(64),
    comments char(255),
    primary key (id_package,module_name,function_name,item_num),
    foreign key (id_package,module_name,function_name)
      references p4gl_function (id_package,module_name,function_name)
  );
  /);


  $rv = $obj->execSql(qq/create table p4gl_fun_todo (
    id_package char(64) not null,
    module_name char(64) not null,
    function_name char(50) not null,
    item_num smallint not null,
    comments char(255),
    primary key (id_package,module_name,function_name,item_num),
    foreign key (id_package,module_name,function_name)
      references p4gl_function (id_package,module_name,function_name)
  );
  /);

  $rv = $obj->execSql(qq/create table p4gl_form_usage (
    id_package char(64) not null,
    module_name char(64) not null,
    function_name char(50) not null,
    item_num smallint not null,
    form_name char(64),
    primary key (id_package,module_name,function_name,item_num),
    foreign key (id_package,module_name,function_name)
      references p4gl_function (id_package,module_name,function_name)
  );
  /);


  $rv = $obj->execSql(qq/create table p4gl_table_usage (
    id_table_usage serial not null primary key,
    id_package    char(64) not null,
    module_name   char(64) not null,
    function_name char(50) not null,
    table_name    char(50) not null,
    operation char(1) not null
      check (operation IN ('I' ,'U' ,'D' ,'S' )),
    foreign key (id_package,module_name,function_name)
      references p4gl_function (id_package,module_name,function_name)
  );
  /);


# Use Sergio's DD tool tables instead for table and columns:
#  $rv = $obj->execSql(qq/create table p4gl_table (
#    table_name    char(50) not null primary key,
#	id_package    char(64) not null,
#    comments char(255)
#  );
#  /);


  $rv = $obj->execSql(qq/create table p4gl_excel (
    module_name   char(64) not null,
    id_process    char(10),
    function_name char(50) not null,
    parameters    char(100),
    returns       char(100),
    called        char(100),
    comments      char(255)
  );
  /);

  return $retval;
}

#  =========================================================================
#  Apaga todas as tabelas relativas ao repositorio da base de dados corrente
#  =========================================================================
sub drop
{
  my $obj = shift;
  my $retval = 1;
  my $rv;
  $rv = $obj->execSql("drop table p4gl_package;");
  #$retval = $rv : 1 
  $rv = $obj->execSql("drop table p4gl_program;");
  $rv = $obj->execSql("drop table p4gl_module;");
  $rv = $obj->execSql("drop table p4gl_module_prog;");
  $rv = $obj->execSql("drop table p4gl_function;");
  $rv = $obj->execSql("drop table p4gl_process;");
  $rv = $obj->execSql("drop table p4gl_fun_process;");
  $rv = $obj->execSql("drop table p4gl_fun_parameter;");
  $rv = $obj->execSql("drop table p4gl_fun_return;");
  $rv = $obj->execSql("drop table p4gl_fun_todo;");
  $rv = $obj->execSql("drop table p4gl_table_usage;");
  $rv = $obj->execSql("drop table p4gl_excel;");
  return $retval;
}

#  =========================================================================
#  Create a new database for the repository.
#  The name should be defined in the $database object property.
#  @return 
#     - 0 :  Database created
#     - 1 :  Error creating the database.
#  =========================================================================
sub createRepositoryFromScrach
{
  my $obj    = shift;
  my $database = $obj->{connection}->getDatabase();
  my $retval = 1;
  $obj->{dbh} = $obj->{connection}->connectWithoutDatabase();

  #
  # Now it include the LOG 
  # It was
  #         my $sqlStr = "create database $database; with log";
  # Passa para (teresa):
  #
  my $sqlStr = "create database $database with log;";
  my $numRecords;
  print("CREATE DATABASE $database\n");
  unless ( $numRecords = $obj->{connection}->getConnection()->do($sqlStr))
  {
    $obj->{err}->error(
      "Execução de SQL",
      "Can't create database $\n$DBI::errstr\n"
    );
    $retval = 0;
  }
  $retval = $obj->create();
  $obj->{connection}->disconnect();
  return $retval;
}

#  =========================================================================
#  Apaga completamente o repositorio efectuando um drop a base de dados
#  =========================================================================
sub dropRepository
{
  my $obj    = shift;
  my $database = $obj->{connection}->getDatabase();
  my $retval = 1;
  $obj->{dbh} = $obj->{connection}->connectWithoutDatabase();
  my $sqlStr = "drop database $database;";
  my $numRecords;
  unless ( $numRecords = $obj->{connection}->getConnection()->do($sqlStr))
  {
    $obj->{err}->error(
      "Execução de SQL",
      "Can't drop database $\n$DBI::errstr\n"
    );
    $retval = 0;
  }
  $obj->{connection}->disconnect();
  return $retval;
}

return 1;
