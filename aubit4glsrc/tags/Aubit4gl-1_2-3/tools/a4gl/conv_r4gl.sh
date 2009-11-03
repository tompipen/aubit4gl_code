echo " "
echo "Note: You must have already created the new syspgma4gl database"
echo "and populated it with the create_tables.sql file in $AUBITDIR/tools/a4gl"
echo " "
echo " "

if [ ! -d syspgm4gl.data ]
then
   mkdir syspgm4gl.data 
fi

echo "
	unload to 'syspgm4gl.data/global.unl'      select 0,'G',progname,' ',globname,gpath from global;
	unload to 'syspgm4gl.data/libraries.unl'   select 0,'L',progname,' ',libraries,' ' from libraries;
	unload to 'syspgm4gl.data/source4gl.unl'   select 0,'M',progname,' ',fglsourcename,spath from source4gl;
	unload to 'syspgm4gl.data/sourceother_c.unl' select 0,'C',progname,' ',othersourcename,spath from sourceother where extension='c';
	unload to 'syspgm4gl.data/sourceother_e.unl' select 0,'E',progname,' ',othersourcename,spath from sourceother where extension='ec';
	unload to 'syspgm4gl.data/otherobj.unl'    select 0,'O',progname,' ',othername,opath from otherobj;
	unload to 'syspgm4gl.data/otherobj.unl'    select 0,'O',progname,' ',othername,opath from otherobj;
" | asql_i.4ae syspgm4gl - 


if [ "$A4GL_SQLTYPE" = pg8 -o  "$A4GL_SQLTYPE" = "postgres" ]
then
	asql=asql_p.4ae
else
	asql=asql_i.4ae
fi
echo "asql=$asql"

echo "
	delete from entity;
	load from 'syspgm4gl.data/global.unl' insert into entity;
	load from 'syspgm4gl.data/libraries.unl' insert into entity;
	load from 'syspgm4gl.data/source4gl.unl' insert into entity;
	load from 'syspgm4gl.data/sourceother_c.unl' insert into entity;
	load from 'syspgm4gl.data/sourceother_e.unl' insert into entity;
	load from 'syspgm4gl.data/otherobj.unl' insert into entity;
	delete from program where progname in (select distinct progname from entity);
	insert into program (progname,justuser,lastupd,genmakefile)  select distinct progname,' ',0,0 from entity;
" | $asql -e syspgma4gl -

