#!/usr/bin/perl -w

#  ======================================================================
#  Mensagens em Português para o fglDocumenter.
#
#  O functionamento localizado é suportado pelo package Locale::Maketext
#
#  A ferramenta usa como base a lingua inglesa.
#  ======================================================================

package FglDocumenter::L10N::pt_pt;
use base qw(FglDocumenter::L10N);

%Lexicon = (
	# Geral
  'OK'         => 'Está bem',
  'Cancel'     => 'Cancelar',

  # Menus TK
  'File'       => 'Ficheiro',
  'Import'     => 'Importar',
  'Export'     => 'Exportar',
  'Repository' => 'Repositório',
  'Options'    => 'Opções',
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

	# Form de importação de CSV
  'CSV Import'             => 'Importação de ficheiro CSV',
  'Import canceled'        => 'Importação cancelada',

  'Import options'         => 'Opções de importação',
  'File to import'         => 'Ficheiro a importar',
  'Clear Repository'       => 'Limpar repositório',
  'Normalize'              => 'Normalizar',
  'Send line to Log'       => 'Escreve linha no log',
  'Text'                   => 'Texto',
  'All Files'              => 'Todos os ficheiros',
  'Select CSV File'        => 'Seleccionar ficheiro CSV',

	# Form de exportação para 4gl
  '4gl source export options' => 'Opções de exportação para fontes 4gl',
  'Location'                  => 'Directório de localização',

  # Testes unitários
	'File [_1] File does not contain correct values'
	  => 'Ficheiro [_1] não contem os valores correctos',
	'Fgl IMPORT: Should be one record only in p4gl_module'
	  => 'Importação 4gl : Devia existir apenas uma linha em p4gl_module',
	'CSV IMPORT: Should be two records from CsvImportTest.4gl in p4gl_excel'
	  => 'Importação CSV : Deviam existir duas linhas em p4gl_module',
	'CSV IMPORT: Should be one module only in p4gl_module'
	  => 'Importação CSV : Devia existir apenas uma linha em p4gl_module',
	"CSV IMPORT: Should be two functions only in p4gl_function"
	  => 'Importação CSV : Deviam existir duas linhas em p4gl_function',
	'Fgl IMPORT: Should be one function called OneFunctionTest in p4gl_function'
	  => 'Importação 4gl : Devia existir uma função chamada OneFunctionTest em p4gl_function',
	
	# Form de importação de 4gl(s) - FormP4gl.pm
	'4gl source information import' => 'Importação de informação de sources 4gl',
	'Import canceled' => 'Importação cancelada',
	'4gl source import options' => 'Opçoes de importaçao de fontes 4gl',
	'Package' => 'Pacote',
	'Location (Directory)' => 'Directorio',
	'Modules' => 'Modulos',
	'Load comments' => 'Carregar comentarios',
	'Parse Only' => 'Apenas analise',
	'Load Table Usage' => 'Carregar utilizaçao de tabelas',
	'Load Parameters' => 'Carregar parametros',
	'Load Strings' => 'Carregar strings',
	'Load Local Variables' => 'Carregar variaveis locais',
	'Recursive' => 'Recursivo',

	# De ExportHtml.pm
	'Processes' => 'Processos',
	'All modules' => 'Todos os modulos',
	'Function Summary' => 'Resumo de Funções',
	'Package' => 'Pacote',
	'Module' => 'Módulo',
	'Overview' => 'Introdução',
	'Function Detail' => 'Descrição de funções',
	'Table Usage Summary' => 'Resumo de utilização de tabelas',

	# De FormDb.pm
	'Database access configuration' => 'Configuração de acesso à base de dados',
	'Login' => 'Utilizador',
	'Password' => 'Palavra passe',
	'Database' => 'Base de dados',
	'Test' => 'Testar',
	'Connection test' => 'Testar conexão',
	'Connection test' => 'Testar conexão',
	'Connection established' => 'Conexão estabelecida',
	'Login to database' => 'Ligação à base de dados',

	# De FormOptions
	'Options configuration' => 'Configuração de opções',
	'4gl Doc Repository' => 'Repositório de documentação 4gl',
	'XML file' => 'Ficheiro XML',
	'CSV Export File' => 'Ficheiro para exportação de CSV',
	'Select XML File' => 'Seleccionar ficheiro de XML',
	'Select CSV File' => 'Seleccionar ficheiro CSV',

	# Acções sobre o repositorio
  'Clean repository' => 'Limpar repositório',
	'Repository cleaned' => 'Repositório Limpo',
	'Drop repository' => 'Repositório removido',
	'Repository database dropped' => 'Base de dados do repositório removida',
	'Create repository' => 'Criar repositório',
	'Repository database created' => 'Base de dados de repositório criada',
  '_AUTO' => 1,
);

1;



