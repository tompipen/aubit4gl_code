##############################################################################
#							Functions
##############################################################################

##
# Log resilts into Informix-style .unl file
#
##
result_unl() {
host="host"
flags="all_flags"
aubit_ver="version"
test_no=$1
db_type=$2
db_ver=$3
db_method=$4
result=$5

dl="|"
unl_file=results.unl

	#if test -f "$unl_file"; then 
	#	
	#else
	#
	#fi
	
	echo "$host$dl$DATE$dl$flags$dl$aubit_ver$dl$test_no$dl$db_type$dl\
		$db_ver$dl$db_method$dl$result" >> $unl_file


}
##
# Compare Aubit settings comming from aubit-config and environment
#
##
compare_settings() {

			if test "$A4GL_INIFILE" != ""; then 
				echo "Note: using Aubit rc file $A4GL_INIFILE"
			fi
			aubit-config -a > aubit-config.log
			cat -n aubit-config.log > aubit-config-num.log
			LINES=`grep -c "" aubit-config.log`
			SETTINGS=`grep -c = aubit-config.log`
			echo "aubit-config output has $LINES lines, $SETTINGS settings"

			a=0
			cnt=0
			SKIP_BLOCK=1
			echo " "
			echo "name			env		aubitrc		aubit-config"
			echo "------------------------------------------------------------------"
			while test "1" = "1" ; do
				let a=a+1
				LINE=`grep -e "^ \+$a	" aubit-config-num.log`
				VALUES=`echo "$LINE" | awk '{print $2}'`
				
				if test "$VALUES" = "User"; then
					#User resources block begins
					SKIP_BLOCK=0
				fi
				if test "$SKIP_BLOCK" = "1"; then
					#Skip everything before User Resources block
					continue
				fi
				if test "$VALUES" != "Built-in"; then
					let cnt=cnt+1
					#echo $VALUES
					TMP=`echo $VALUES | sed -e 's/=/ /'`
					NAME=`echo $TMP |  awk '{print $1}'`
					VALUE=`echo $TMP |  awk '{print $2}'`
					#echo "$cnt: Name=$NAME Value=$VALUE"
					dollar="$"
					EXEC="if test \"$dollar$NAME\" != \"\"; then echo \"$dollar$NAME\"; fi"
					#we are running this as external script to see only what
					#is exported to environment, since only that will affect
					#makefiles we will run from run_test script
					echo $EXEC > run.sh					
					ENV_VALUE=`bash ./run.sh`
					if test "$ENV_VALUE" != ""; then
						if test "$ENV_VALUE" != "$VALUE"; then
							x=`aubit-config $NAME`
							#echo "$NAME : env: '$ENV_VALUE' aubitrc: '$VALUE'"
							#echo "aubit-config returns $NAME=`aubit-config $NAME` x=$x"
							echo "$NAME		'$ENV_VALUE'		'$VALUE'		'$x'"
						#else
						#	echo "$NAME IS in environment as '$ENV_VALUE' and in Aubit as "$VALUE""
						fi
					#else
					#	echo "$NAME not in environment"					
					fi
					
					#if test "$cnt" = "10"; then
					#	break
					#fi
				fi
				
				if test "$a" = "$LINES"; then
					break
				fi
			done
	echo "------------------------------------------------------------------"
	echo " "

	set | grep "^A4GL_" > set.log
	LINES=`grep -c "" set.log`
	echo "$LINES Aubit settings in environment"
	if test "$LINES" != "0"; then 
		cat set.log
	fi

	#rm -f aubit-config-num.log aubit-config.log run.sh set.log
	
	
	
	
}

##
# Change setting in makefile
#
##
change_setting() {
look_for="$1:"
change_to=$2
test_no=$3
makefile=`ls $CURR_DIR/$test_no/?akefile`
if test "$makefile" = ""; then
	echo "ERROR: can't get makefile name"
	pwd
	echo "$CURR_DIR/$test_no/?akefile"
	exit 5
fi
tmp_out="$makefile.tmp"

	if test "$VERBOSE" = "1" ; then
		echo "Changing value of $look_for to $change_to in $makefile..."
	fi

	awk -v look_for="$look_for" -v change_to="$change_to" '
	BEGIN {
	}
	{
		if (skip_next==1) {
			skip_next=0
			next
		} else {
			if (look_for==$1) {
				print
				print "	@echo \"" change_to "\""
				skip_next=1
			} else {
				print
			}
		}
	}
	' < $makefile > $tmp_out
	
	if test "$VERBOSE" = "1" ; then
		diff $makefile $tmp_out
		RET=$?
	else
		diff $makefile $tmp_out > /dev/null
		RET=$?
	fi
	if test "$RET" = "0"; then 
		if test "$VERBOSE" = "1" ; then
			echo "Nothing changed"
		fi
	else
		if test "$VERBOSE" = "1" ; then
			echo "Changed."
		fi
		mv $tmp_out $makefile
	fi

}

##
# Create API code for Four J's custom runner
#
##
create_4js_api() {
rm -f $FGIUSR_4JS_C

#ERROR(-6200):Module 'prog': The function <extern C>.aclfgl_dump_screen(2,1) 
#will be called as aclfgl_dump_screen(1,0).

cat<<EOF > $FGIUSR_4JS_C
#include <f2c/fglExt.h>
int aclfgl_dump_screen (int n);
	UsrData usrData[] = {
	  {0, 0}
	};
	
	UsrFunction usrFunctions[] = {
	  {"aclfgl_dump_screen", aclfgl_dump_screen, 1, 0},
	  {0, 0, 0, 0}
	};

EOF
}

##
# Create API code for Informix custom runner
#
##
create_ifx_api() {
rm -f $FGIUSR_IFX_C
cat<<EOF > $FGIUSR_IFX_C
#include "fgicfunc.h"
int aclfgl_dump_screen (int n);
cfunc_t usrcfuncs[] =
{
	"aclfgl_dump_screen", aclfgl_dump_screen, 1,
	0, 0, 0
};

EOF
}

##
# Create runner with C function for dumping screen to file.
#
# Test 252 is nice to try screen dumps :
# 	bash run_tests -cert [-querix|-ifx-p|-4js-p] 252
#
# NOTE: Aubit has built-in dump_screen function
# Querix and Informix C-compiled do not need a runner - they will get
# dump_screen function linked in when compiling 4GL programs (in Makefile-common)
#
# @param COMPILER Type of 4GL compiler to create runner for
##
create_runner() {
COMPILER=$1

SRC_CUSTOM="$CUSTOM.c"
OBJ_CUSTOM="$CUSTOM.o"
		
	case $COMPILER in
	informix)
		if test "$INFORMIXDIR" = ""; then 
			echo "ERROR: INFORMIXDIR not set"
			exit 3
		fi
		if test "$AUBITDIR_SRC" = ""; then 
			echo "ERROR: AUBITDIR_SRC not set"
			exit 3
		fi		
		create_ifx_api
		rm -f $IFX_RUNNER 
		SOURCES="$SRC_CUSTOM $FGIUSR_IFX_C"
		#CFGLGO_FLAGS="-dumpspecs"
		#CFGLGO_FLAGS="-v"
		#CFGLGO_FLAGS="-DDEBUG"
		EXEC="cfglgo -DI4GL_RDS $CFGLGO_FLAGS $LIBS $SOURCES -o $IFX_RUNNER "
		echo $EXEC
		rm -f tmp.log
		eval $EXEC > tmp.log 2>&1
		RET=$?
		if test "$RET" != "0"; then
			less tmp.log
			echo "ERROR: creation of Informix custom runner failed"
			exit $RET
		else
			echo "Informix custom runner ($IFX_RUNNER) created" 
			rm -f tmp.log
		fi
		;;
	4js)
		#assuming we will be uiing Informix RDBMS
		if test "$INFORMIXDIR" = ""; then 
			echo "ERROR: INFORMIXDIR not set"
			exit 3
		fi
		if test "$FGLDIR" = ""; then 
			echo "ERROR: FGLDIR (Four J's) not set"
			exit 3
		fi
		if test "$AUBITDIR_SRC" = ""; then 
			echo "ERROR: AUBITDIR_SRC not set"
			exit 3
		fi		
		create_4js_api
		
		#decap program strips away the termcap escape sequences
		EXEC="gcc $AUBITDIR_SRC/lib/extra_libs/infx_dump_screen/decap.c -o ./bin/decap"
		echo $EXEC
		eval $EXEC
		RET=$?
		if test "$RET" != "0"; then
			echo "ERROR: compiling C code failed"
			exit 3
		fi
		
		#Specify version of database on your system; see 'fglmkrun -dl'
		#DB=ifx9** #ERROR(-6197):'Open Database Interface' extension is not allowed with this license type.
		#DB=ix711
		DB=ix720
		#4Js apprently DOES NOT use curses
		#LFLAGS="-lkf \"-lncurses\""
		
		#/opt/aubit/gen4gl/fglbld/include/decimal.h
		#/opt/informix/incl/tools/decimal.h
		#/opt/querix/incl/decimal.h
		FJS_CFLAGS="-cpf \"-DC4GL=1 -DDEBUG -DFOURJS \
			-I$FGLDIR/include -I$INFORMIXDIR/incl/tools \
			-I$INFORMIXDIR/incl\""
		
		rm -f $FJSRUNNER
		LINKER="esql"	#assumes there is Informix ESQL/C installed
		SRC_CUSTOM="$AUBITDIR_SRC/lib/extra_libs/infx_dump_screen/fgl_prtscr.c"
		EXEC="fglmkrun -d $DB -o $FJSRUNNER -l $LINKER \
			$FJS_CFLAGS \
			-acs \"$SRC_CUSTOM\" \
			$LFLAGS \
			-ext $FGIUSR_4JS_C"
		echo $EXEC
		rm -f tmp.log
		eval $EXEC > tmp.log 2>&1
		RET=$?
		if test "$RET" != "0"; then
			less tmp.log
			echo "ERROR: creation of Four J's custom runner failed"
			exit $RET
		else
			echo "Four J's custom runner ($FJSRUNNER) created"
			rm -f tmp.log
		fi
		;;
	*)
		echo "ERROR: unknown compiler type: $COMPILER"
		;;
	esac

}

##
# Convert SQL script for particular RDBMS dialect
#
# @param TYPE Type of conversion (ddl or data)
# @param RDBMS Type of RDBMS to convert SQL dialect to
# @param RESULT Filename of resulting converted SQL script
##
convert_sql() {
TYPE=$1
RDBMS=$2
RESULT=$3
SQL_DDL=./testdb-ddl.sql
SQL_DATA=./testdb-data.sql
TMP1=tmp1
TMP2=tmp2

	echo "Translating $TYPE script for $RDBMS ..."
	case $RDBMS in
	informix)
		case $TYPE in
		ddl)
			cat $SQL_DDL | sed -e "s/systables/dummy_systables/g" | sed -e "s/sysusers/dummy_sysusers/g" > $TMP1
			cat $TMP1 | grep -v "^/\*" | grep -v "^\*/" | grep -v "^//" > $TMP2
			mv $TMP2 $RESULT
			;;
		data)
			cat $SQL_DATA | sed -e "s/systables/dummy_systables/g" | sed -e "s/sysusers/dummy_sysusers/g" > $TMP1
			cat $TMP1 | grep -v "^/\*" | grep -v "^\*/" | grep -v "^//" > $TMP2
			mv $TMP2 $RESULT
			;;
		*)
			echo "ERROR: unknown translation type: $TYPE"
			exit 3
			;;
		esac
		;;
	postgres)
		case $TYPE in
		ddl)
			cat $SQL_DDL | grep -v "^/\*" | grep -v "^\*/" | grep -v "^//" | sed -e 's/128,0/128/g' | tr "\"" "'" > $TMP1			
			mv $TMP1 $RESULT
			;;
		data)
			cat $SQL_DATA | grep -v "^/\*" | grep -v "^\*/" | grep -v "^//" | sed -e 's/128,0/128/g' | tr "\"" "'" > $TMP1			
			mv $TMP1 $RESULT
			;;
		*)
			echo "ERROR: unknown translation type: $TYPE"
			exit 3
			;;
		esac
		;;
	*)
		echo "ERROR: don't know how to translate SQL for $RDBMS"
		exit 4
		;;
	esac
	
	rm -f $TMP1 $TMP2
	
}


##
# Run SQL script 
#
# @param RDBMS Type of RDBMS to create test database in
# @param DB Database name
# @param SCRIPT SQL script to run
# @param File to log execution into
##
run_sql_script() {
RDBMS=$1
DB=$2
SCRIPT=$3
LOGFILE=$4
LOGFILE_CMD="> $LOGFILE 2>&1"
AS_USER=$5

   case $RDBMS in
	informix)
		EXEC="dbaccess $DB -qcr $SCRIPT $LOGFILE_CMD"
		eval $EXEC
		RET=$?
		;;
	postgres)
		EXEC="$PSQL -d $DB -f $SCRIPT $LOGFILE_CMD"
		if test "$AS_USER" != ""; then 
			EXEC="su -l $AS_USER -c '$EXEC'"
		fi
		eval $EXEC
		RET=$?
		;;
	*)
		echo "ERROR: don't know how to run script for $RDBMS"
		exit 4
		;;
	esac
	
	if test "$RET" != "0"; then
		echo "Statement:"
		echo $EXEC
		echo "returned code $RET. See $LOGFILE"
		exit $RET
	fi
}


##
# Create a new test database.
# Populte test data
#
# @param RDBMS Type of RDBMS to create test database in
##
new_testdb() {
RDBMS=$1
SCRIPT=converted.sql
LOGFILE=/tmp/testdb.log
	
   case $RDBMS in
	informix | postgres)
		convert_sql ddl $RDBMS $SCRIPT
		echo "Creating tables..."
		run_sql_script $RDBMS $TEST_DB $SCRIPT $LOGFILE
		convert_sql data $RDBMS $SCRIPT
		echo "Loading data..."
		run_sql_script $RDBMS $TEST_DB $SCRIPT $LOGFILE
		;;
	*)
		echo "ERROR: don't know how to create test data for $RDBMS"
		exit 4
		;;
	esac
	
	rm -f $SCRIPT
}

##
# Create a new test.
# Copy the template of the makefile into the directory and the .cvsignore also
# Try to copy the files if they not exist but the directory yes.
# Exit the program after doing it.
#
# @param dir The name of the test.
##
new_test() {
dir=$1
nothing_done="1"
  echo "Adding new test $dir"
if ! test -d $dir; then
    mkdir $dir
	cp template/makefile template/prog.4gl template/.cvsignore $dir
	
    if ! test "$NO_CVS" = "1"; then
      cvs add $dir
      cvs add $dir/makefile $dir/prog.4gl $dir/.cvsignore
    fi
    echo "Template for test $dir created. Steps to complete:"
    echo " 1) edit test files to create test code"
    echo " 2) describe test in makefile"
    echo " 3) perform 'cvs add' on additional files test needs, if any"
    echo " 4) perform 'cvs commit'"
    nothing_done=0
else
	#add mandatory files to allready existing directory if they are missing
	CVS_ADD=""
	if ! test -f $dir/makefile && ! test -f $dir/Makefile ; then
		cp template/makefile $dir
		CVS_ADD="$dir/makefile"
		echo "makefile added from template"
		nothing_done="0"
	fi
	if ! test -f $dir/.cvsignore; then
		cp template/.cvsignore $dir
		CVS_ADD="$CVS_ADD $dir/.cvsignore"
		echo ".cvsignore added from template"
		nothing_done="0"
	fi
    if ! test "$NO_CVS" = "1" && test "$CVS_ADD" != ""; then
      cvs add $CVS_ADD
    fi
fi
  if test $nothing_done = "1"; then
    echo "ERROR: test $a already exists with makefile and .cvsignore"
  fi
  exit
}

