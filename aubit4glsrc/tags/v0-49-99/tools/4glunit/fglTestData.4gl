{**
 * Test data generation API.
 * 
 * This functions are usefull to generate information in tables in order 
 * to execute some tests
 *}


{**
 * Array de colunas para geraçao de dados de teste
 * ??? Foreign keys para ja nao suportadas
 * @todo Send this feature to a test data generation framework
 *}
define paColumns array[50] of record
  columnName char(18),
	pk smallint,
  nulls smallint,
  datatype char(18)
end record
define idxColumns smallint

# Nome da tabela para geraçao de dados de teste
define tableName char(18)


{**
 * Gera dados de teste numa tabela
 * <BR>Depende de algumas funçoes acessoras que afectam a tabela(s) e coluna(s)
 * para os quais se quer gerar os dados
 *}
function fglUnitGenTestData(numRecords)
	 define numrecords smallint
   define i smallint

	 for i = 1 to numRecords
	   call fglUnitInsertTableRow(i)
	 end for
end function

function fglUnitInitGenTestData()
  let idxColumns = 0
end function

{**
 * Gera a instrução SQL de inserção e executa-a
 *}
function fglUnitInsertTableRow(rowNum)
  define rowNum smallint
	define strSql char(640)
	define i smallint

	let strSql = "insert into ", tableName clipped, " ("
	for i = 1 to idxColumns
		if i > 1 then   let strSql = strSql clipped, ","   end if
	  let strSql = strSql clipped, " ", paColumns[i].columnName
	end for
	let strSql = strSql clipped, ") values ("
	for i = 1 to idxColumns
		if i > 1 then   let strSql = strSql clipped, ","   end if
		case paColumns[i].datatype
			when "char"
	      let strSql = strSql clipped, "'", ascii(rowNum+48) , "'"
		  when "integer"
	      let strSql = strSql clipped, rowNum using "<<<<<"
		  when "date"
	      let strSql = strSql clipped, "today+", rowNum, ""
		  when "datetime"
	      let strSql = strSql clipped, "current"
			otherwise
	      let strSql = strSql clipped, "'", rowNum using "<<<<<", "'"
	  end case
	end for
	let strSql = strSql clipped, ")"
	#display "<SQL> : ", strSql clipped
	prepare stInsertColumn from strSql
	execute stInsertColumn
end function

function fglUnitSetTableName(_tableName)
  define _tableName char(18)

	let tableName = _tableName
end function

function fglUnitSetColumn(idx,columnName,pk,nulls,datatype)
	define idx smallint
	define columnName char(18)
	define pk smallint
	define nulls smallint
	define datatype char(18)

  if idx > 50 then
	  return
	end if
	let paColumns[idx].columnName = columnName
	let paColumns[idx].pk = pk
	let paColumns[idx].nulls = nulls
	let paColumns[idx].datatype = datatype
	if idx > idxColumns or idxColumns is null then
	  let idxColumns = idx
  end if
end function
