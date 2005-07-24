
# ================================================================
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#
#  Divisao de desenvolvimento e producao de software.
#
#  Autor:  Sergio Alexandre Ferreira
#
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      :
#  ----------------------------------------------------------------
#  DESCRICAO: Modulo para acesso ao conteudo de directorias
#  ----------------------------------------------------------------
#  FUNCOES:  d_opdir(nome_directoria)
#            d_cldir()
#  ----------------------------------------------------------------
#  FORMS: Nao tem
#
#
#  NOTAS:
#
#  ===================================================================


GLOBALS "4glsrc/functions_4gl/d_libglob.4gl"

function d_opdir(dirname)
{}
  define 
	 dirname char(64),
	 st,did INTEGER


  let d_dir_nome = dirname
  let did = d_opendir(dirname)
  if did <= 0 then
	 return did
  end if
  create temp table d_tmpdir (
		{
	   nome char(20),
	   modo char(10),
	   st_ino smallint,
	   st_dev smallint,
	   st_rdev smallint,
	   st_nlink smallint,
	   st_uid smallint,
	   st_gid smallint,
	   st_size integer,
	   st_atime integer,
	   st_mtime integer,
	   st_ctime integer
		}
	   nome char(20),
	   modo char(10),
	   st_ino integer,
	   st_dev integer,
	   st_rdev integer,
	   st_nlink integer,
	   st_uid integer,
		nome_uid char(14),
	   st_gid integer,
	   st_size integer,
	   st_atime integer,
	   st_mtime integer,
	   st_ctime integer
	)
  let d_pr_dir.nome = "."
  while d_pr_dir.nome is not null 
    call  d_readdir(did) returning d_pr_dir.*
    if d_pr_dir.nome is null then
      continue while
    end if
    insert into d_tmpdir values (d_pr_dir.*)
  end while
  call d_closedir(did)
  initialize d_pr_dir.* to null
  return did
end function

function d_newdir(dirname)
{}
  define 
	 dirname char(64),
	 st,did INTEGER


  delete from d_tmpdir       # Apagar dados antigos
  let d_dir_nome = dirname
  let did = d_opendir(dirname)
  let d_pr_dir.nome = "."
  while d_pr_dir.nome is not null 
    call  d_readdir(did) returning d_pr_dir.*
    if d_pr_dir.nome is null then
      continue while
    end if
    insert into d_tmpdir values (d_pr_dir.*)
  end while
  call d_closedir(did)
  initialize d_pr_dir.* to null
  return did
end function

function d_cldir()
{}
  drop table d_tmpdir
end function
