-- don't use this - use "fgldoc --action=dropRepository"
-- to drop Doc4gl/DBdoc database repository, or
-- 	"fgldoc --clean_repository" to delete data


-- ============================================================================
-- Limpeza do Reposit�rio de sobre informa��o de programas de 4gl 
-- Formato p4gl (desenvolvido na Despodata)
-- ============================================================================

delete from  p4gl_package where 1=1;
delete from  p4gl_program where 1=1;
delete from p4gl_module where 1=1;
delete from p4gl_module_prog where 1=1;
delete from p4gl_function where 1=1;
--delete from p4gl_process where 1=1; garantir existencia de processos
delete from p4gl_fun_process where 1=1;
delete from p4gl_fun_parameter where 1=1;
delete from p4gl_fun_return where 1=1;
delete from  p4gl_fun_todo where 1=1;
delete from p4gl_table_usage where 1=1;
delete from p4gl_excel where 1=1;

