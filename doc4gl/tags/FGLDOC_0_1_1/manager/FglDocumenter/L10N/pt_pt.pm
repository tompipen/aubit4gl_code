#!/usr/bin/perl -w

#  ======================================================================
#  Mensagens em Portugu�s para o fglDocumenter.
#
#  O functionamento localizado � suportado pelo package Locale::Maketext
#
#  A ferramenta usa como base a lingua inglesa.
#  ======================================================================

package FglDocumenter::L10N::pt_pt;
use base qw(FglDocumenter::L10N);

%Lexicon = (
	# Geral
  'OK'         => 'Est� bem',
  'Cancel'     => 'Cancelar',

  # Menus TK
  'File'       => 'Ficheiro',
  'Import'     => 'Importar',
  'Export'     => 'Exportar',
  'Repository' => 'Reposit�rio',
  'Options'    => 'Op��es',
  'Help'       => 'Ajuda',

  '~Open'       => '~Abrir',
  '~Save'       => '~Guardar',
  '~Exit'       => '~Sair',

  '~CSV (Tab separated)'   => '~Ficheiro com caracter separador',
  '~4gl Sources'           => '~Fontes 4gl',

  '~Create'                => '~Criar',
  '~Drop'                  => '~Remover',
  '~Clean'                 => '~Limpar',

  '~Show Log'              => '~Mostra registo',
  '~Configure'             => '~Configurar',

	# Form de importa��o de CSV
  'CSV Import'             => 'Importa��o de ficheiro CSV',
  'Import canceled'        => 'Importa��o cancelada',

  'Import options'         => 'Op��es de importa��o',
  'File to import'         => 'Ficheiro a importar',
  'Clear Repository'       => 'Limpar reposit�rio',
  'Normalize'              => 'Normalizar',
  'Send line to Log'       => 'Escreve linha no log',
  'Text'                   => 'Texto',
  'All Files'              => 'Todos os ficheiros',
  'Select CSV File'        => 'Seleccionar ficheiro CSV',

	# Form de exporta��o para 4gl
  '4gl source export options' => 'Op��es de exporta��o para fontes 4gl',
  'Location'                  => 'Direct�rio de localiza��o',

  # Testes unit�rios
	'File [_1] File does not contain correct values'
	  => 'Ficheiro [_1] n�o contem os valores correctos',
	'Fgl IMPORT: Should be one record only in p4gl_module'
	  => 'Importa��o 4gl : Devia existir apenas uma linha em p4gl_module',
	'CSV IMPORT: Should be two records from CsvImportTest.4gl in p4gl_excel'
	  => 'Importa��o CSV : Deviam existir duas linhas em p4gl_module',
	'CSV IMPORT: Should be one module only in p4gl_module'
	  => 'Importa��o CSV : Devia existir apenas uma linha em p4gl_module',
	"CSV IMPORT: Should be two functions only in p4gl_function"
	  => 'Importa��o CSV : Deviam existir duas linhas em p4gl_function',
	'Fgl IMPORT: Should be one function called OneFunctionTest in p4gl_function'
	  => 'Importa��o 4gl : Devia existir uma fun��o chamada OneFunctionTest em p4gl_function',
	
	# Form de importa��o de 4gl(s) - FormP4gl.pm
	'4gl source information import' => 'Importa��o de informa��o de sources 4gl',
	'Import canceled' => 'Importa��o cancelada',
	'4gl source import options' => 'Op�oes de importa�ao de fontes 4gl',
	'Package' => 'Pacote',
	'Location (Directory)' => 'Directorio',
	'Modules' => 'Modulos',
	'Load comments' => 'Carregar comentarios',
	'Parse Only' => 'Apenas analise',
	'Load Table Usage' => 'Carregar utiliza�ao de tabelas',
	'Load Parameters' => 'Carregar parametros',
	'Load Strings' => 'Carregar strings',
	'Load Local Variables' => 'Carregar variaveis locais',
	'Recursive' => 'Recursivo',

	# De ExportHtml.pm
	'Processes' => 'Processos',
	'All modules' => 'Todos os modulos',
	'Function Summary' => 'Resumo de Fun��es',
	'Package' => 'Pacote',
	'Module' => 'M�dulo',
	'Overview' => 'Introdu��o',
	'Function Detail' => 'Descri��o de fun��es',
	'Table Usage Summary' => 'Resumo de utiliza��o de tabelas',

	# De FormDb.pm
	'Database access configuration' => 'Configura��o de acesso � base de dados',
	'Login' => 'Utilizador',
	'Password' => 'Palavra passe',
	'Database' => 'Base de dados',
	'Test' => 'Testar',
	'Connection test' => 'Testar conex�o',
	'Connection test' => 'Testar conex�o',
	'Connection established' => 'Conex�o estabelecida',
	'Login to database' => 'Liga��o � base de dados',

	# De FormOptions
	'Options configuration' => 'Configura��o de op��es',
	'4gl Doc Repository' => 'Reposit�rio de documenta��o 4gl',
	'XML file' => 'Ficheiro XML',
	'CSV Export File' => 'Ficheiro para exporta��o de CSV',
	'Select XML File' => 'Seleccionar ficheiro de XML',
	'Select CSV File' => 'Seleccionar ficheiro CSV',

	# Ac��es sobre o repositorio
  'Clean repository' => 'Limpar reposit�rio',
	'Repository cleaned' => 'Reposit�rio Limpo',
	'Drop repository' => 'Reposit�rio removido',
	'Repository database dropped' => 'Base de dados do reposit�rio removida',
	'Create repository' => 'Criar reposit�rio',
	'Repository database created' => 'Base de dados de reposit�rio criada',
  '_AUTO' => 1,
);

1;



