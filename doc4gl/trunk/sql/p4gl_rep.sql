
-- ============================================================================
-- Repositório de sobre informação de programas de 4gl 
-- Formato p4gl (desenvolvido na Despodata)
-- ============================================================================

drop table p4gl_package;
drop table p4gl_program;
drop table p4gl_module;
drop table p4gl_module_prog;
drop table p4gl_function;
drop table p4gl_process;
drop table p4gl_fun_process;
drop table p4gl_fun_parameter;
drop table p4gl_fun_return;
drop table p4gl_fun_todo;
drop table p4gl_table_usage;
drop table p4gl_excel;

-- ============================================================================
-- Identifica um package que tipicamente corresponde a uma directoria
-- ============================================================================
create table p4gl_package (
  id_package char(64) not null primary key ,
	comments varchar(255)
);

-- ============================================================================
-- Programa executável para ser compilado
-- Não suporta programas com o mesmo nome
-- Obtido com um count distinct a source4gl
-- ============================================================================
create table p4gl_program (
  program_name char(64) not null primary key,
	comments varchar(255)
);

-- ============================================================================
-- Identifica um módulo 4gl (ficheiro 4gl compilável)
-- ============================================================================
create table p4gl_module (
	id_package char(64) not null references p4gl_package (id_package),
  module_name char(64) not null,
	comments varchar(255),
	primary key (id_package,module_name)
);

-- ============================================================================
-- Definição de dependências de sources (4gl) para a construção de um programa
-- ============================================================================
create table p4gl_module_prog (
  program_name char(64) not null references p4gl_program (program_name),
	id_package char(64) not null,
	module_name char(64) not null,
	primary key (program_name,id_package,module_name),
	foreign key (id_package,module_name) references 
	  p4gl_module (id_package,module_name)
);

-- ============================================================================
-- Identifica uma função 4gl
-- ============================================================================
create table p4gl_function (
	id_package     char(64) not null,
	module_name    char(64) not null,
	function_name  char(50) not null,
	function_type  char(1) default 'F' 
	  not null check (function_type in ('F','R')),
	deprecated     char(1) default 'N' 
	    not null check (deprecated in ('Y','N')),
	comments       varchar(255),
	foreign key (id_package,module_name) references 
	  p4gl_module (id_package,module_name),
	primary key (id_package,module_name,function_name)
);

-- ============================================================================
-- Identifica um processo analisado e desenhado
-- ============================================================================
create table p4gl_process (
  id_process char(10) not null primary key,
	den_process char(64) not null,
	sub_process_of char(10) references p4gl_process(id_process),
	comments varchar(255)
);

-- ============================================================================
-- Associa funções a processos
-- ============================================================================
create table p4gl_fun_process (
  id_process char(10) not null references p4gl_process (id_process),
	id_package char(64) not null,
	module_name char(64) not null,
	function_name char(50) not null,
	primary key (id_process,id_package,module_name,function_name),
	foreign key (id_package,module_name,function_name)
	  references p4gl_function (id_package,module_name,function_name)
);

-- ============================================================================
-- Associa parametros a funções
-- ============================================================================
create table p4gl_fun_parameter (
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

-- ============================================================================
-- Valores de retorno de uma função
-- ============================================================================
create table p4gl_fun_return (
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

-- ============================================================================
-- Tarefas a executar de uma função
-- ============================================================================
create table p4gl_fun_todo (
	id_package char(64) not null,
	module_name char(64) not null,
	function_name char(50) not null,
	item_num smallint not null,
	comments char(255),
	primary key (id_package,module_name,function_name,item_num),
	foreign key (id_package,module_name,function_name)
	  references p4gl_function (id_package,module_name,function_name)
);

/**
 * Utilizações de tabelas
 */
create table p4gl_table_usage (
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

/**
 * Dados desnormalizados carregados directamente de uma folha de cálculo
 */
create table p4gl_excel (
  module_name   char(64) not null,
  id_process    char(10),
	function_name char(50) not null,
	parameters    char(100),
	returns       char(100),
	called        char(100),
	comments      char(255)
);

--load from mobilix_process.u insert into p4gl_process;
