h62725
s 00001/00001/00017
d D 5.2 89/07/05 19:28:40 john 27 26
c Ensure that arguments are passed on correctly
e
s 00002/00001/00016
d D 5.1 89/06/20 16:48:52 john 26 25
c Update SCCS headers
e
s 00001/00001/00016
d D 4.2 88/09/26 10:54:33 john 25 24
c Convert back to Osiris
e
s 00000/00000/00017
d D 4.1 88/09/25 19:40:31 john 24 23
c Upgrade to release 4
e
s 00002/00002/00015
d D 3.4 88/09/17 00:13:22 john 23 22
c Configure for Sun
e
s 00003/00000/00014
d D 3.3 88/09/08 09:28:01 john 22 21
c Set path too
e
s 00003/00000/00011
d D 3.2 88/08/02 22:05:13 john 21 20
c Add LIBDIR
e
s 00006/00053/00005
d D 3.1 88/08/01 13:07:31 john 20 17
c Cut down even further
e
s 00011/00006/00172
d D 1.5.1.2 88/07/28 10:18:33 john 19 18
c Misc minor improvements
e
s 00005/00003/00173
d D 1.5.1.1 88/07/28 10:00:19 john 18 5
c Reduce dependency on KPIDIRECTORY
e
s 00019/00227/00039
d D 2.5 88/07/13 19:59:49 john 17 16
c Truncate to use fglbld.alt
e
s 00004/00000/00262
d D 2.4 88/07/05 18:25:13 john 16 15
c Add before field code
e
s 00001/00001/00261
d D 2.3 88/07/04 18:24:29 john 15 14
c Correct bug in generated form
e
s 00001/00002/00261
d D 2.2 88/07/02 21:50:16 john 14 12
c remove trace; fix Xmk_key and Xrm_key
e
s 00001/00001/00262
d R 2.2 88/07/02 21:47:19 john 13 12
c Reinsert mod for Xmk_key and Xrm_key
e
s 00013/00004/00250
d D 2.1 88/07/02 21:29:51 john 12 11
c Various improvements
e
s 00002/00001/00252
d D 1.11 88/06/30 15:34:38 john 11 10
c Add dlist to files
e
s 00013/00003/00240
d D 1.10 88/06/29 18:04:15 john 10 9
c Add prev_field and iucode
e
s 00030/00035/00213
d D 1.9 88/06/17 17:59:07 john 9 8
c Add makefile and reduce dependency on KPIDIRECTORY
e
s 00040/00004/00208
d D 1.8 88/06/16 21:13:09 john 8 7
c Route ^P away from primary key
e
s 00003/00001/00209
d D 1.7 88/06/16 19:59:50 john 7 6
c A couple of minor fixes -- serial next fields to be resolved
e
s 00047/00013/00163
d D 1.6 88/06/16 18:45:42 john 6 5
c Upgraded
e
s 00063/00000/00113
d D 1.5 88/04/22 17:54:32 john 5 4
c Add ^P facility -- not trivial
e
s 00004/00000/00109
d D 1.4 88/03/17 17:44:26 john 4 3
c Add test for editing forms
e
s 00005/00004/00104
d D 1.3 88/03/17 17:04:09 john 3 2
c KPI customised
e
s 00063/00053/00045
d D 1.2 88/03/17 16:59:35 john 2 1
c Make it work -- change most embedded names
e
s 00098/00000/00000
d D 1.1 88/03/08 19:57:41 john 1 0
c date and time created 88/03/08 19:57:41 by john
e
u
U
f d 6
f i 
f n 
t
T
I 1
D 26
:	"%W%"
E 26
I 26
:	"%W% %E%"
E 26
#
D 20
#	%Z%Sphinx Informix Tools
#	%Z%Simple Perform Interface in Informix 4GL
#	%Z%Author: Jonathan Leffler, Sphinx Ltd.
#	%Z%(C) Copyright Sphinx Ltd. 1988
E 20
I 20
#	Environment setting front-end for FGLBLD
I 26
#	Development version
E 26
E 20

I 12
D 20
# Configuration Section
FGLBLDDIR=${FGLBLDDIR:-$KPIDIRECTORY/etc}
#FGLVERSION=I4GL1.00
FGLVERSION=I4GL1.10
# End of configuration section
E 20
I 20
D 23
FGLBLDDIR=/u/consult/john/src/sqltools/fglbld
E 23
I 23
D 25
FGLBLDDIR=/usr/john/src/sqltools/fglbld
E 25
I 25
FGLBLDDIR=/u/consult/john/src/sqltools/fglbld
E 25
E 23
export FGLBLDDIR
E 20

I 22
PATH=$FGLBLDDIR:$PATH
export PATH

E 22
I 21
D 23
LIBDIR=/u/consult/john/lib
E 23
I 23
LIBDIR=/usr/john/lib
E 23
export LIBDIR

E 21
E 12
D 2
echo "Enter name of database: \c"; read DBNAME
echo "Enter name of    table: \c"; read TABNAME
echo "Enter primary key cols: \c"; read SERNAME
echo "Enter name of  program: \c"; read PRGNAME
echo "Enter name of     menu: \c"; read MENUNAME
E 2
I 2
D 6
echo "Enter name of database  : \c"; read Xdbase
echo "Enter name of table     : \c"; read Xtable
echo "Enter primary key column: \c"; read Xpkey
echo "Enter name of menu      : \c"; read Xmenu
echo "Enter name of program   : \c"; read program
E 6
I 6
D 20
echo "Enter name of database   : \c"; read Xdbase
echo "Enter name of table      : \c"; read Xtable
echo "Enter primary key column : \c"; read Xpkey
echo "Enter type of primary key: \c"; read Xpktype
echo "Enter name of menu       : \c"; read Xmenu
echo "Enter name of program    : \c"; read program
E 20
I 20
DBPATH=$DBPATH:$FGLBLDDIR
export DBPATH
E 20
E 6
E 2

D 2
PRGNAME=`expr $PRGNAME : '\([A-Za-z0-9]\{1,8\}\].*' | tr '[A-Z]' '[a-z]'`
s_table=`expr $TABNAME : '\([A-Za-z0-9]\{1,12\}\].*' | tr '[A-Z]' '[a-z]'`
E 2
I 2
D 6
# Make sure names are in lower or upper case, and  not too long
E 6
I 6
D 20
# Make sure names are in lower or upper case, and not too long
E 6
D 9
program=`expr $program : '\([A-Za-z0-9]\{1,8\}\).*' | tr '[A-Z]' '[a-z]'`
xtable=`expr $Xtable : '\([A-Za-z0-9]\{1,12\}\).*' | tr '[A-Z]' '[a-z]'`
E 9
I 9
program=`expr $program : '\([A-Z_a-z0-9]\{1,8\}\).*' | tr '[A-Z]' '[a-z]'`
I 17
xdbase=`expr $Xdbase | tr '[A-Z]' '[a-z]'`
E 17
xtable=`expr $Xtable : '\([A-Z_a-z0-9]\{1,12\}\).*' | tr '[A-Z]' '[a-z]'`
E 9
xpkey=`echo $Xpkey | tr '[A-Z]' '[a-z]'`
Xmenu=`echo $Xmenu | tr '[a-z]' '[A-Z]'`
xtabname=`echo $Xtable | tr '[A-Z]' '[a-z]'`
I 17
Xform=$program
E 17
E 2

I 6
# Validate data type
I 8
D 17
Xserial=no
E 8
SERIALDELETE='-e /^#SERIALONLY/d'
E 17
Xpktype=`echo $Xpktype | tr "[a-z]" "[A-Z]"`
case $Xpktype in
CHAR*)
D 17
	Xabbr=str ;;
E 17
I 17
	: OK ;;
E 17
SERIAL*)
D 17
	Xabbr=int
	SERIALDELETE='-e s/^#SERIALONLY//'
I 8
	Xserial=yes
E 8
I 7
	Xpktype=INTEGER
E 7
	;;
E 17
I 17
	: OK ;;
E 17
D 9
INTEGER|SMALLINT)
E 9
I 9
INTEGER|SMALLINT|DATE)
E 9
D 17
	Xabbr=int ;;
E 17
I 17
	: OK ;;
E 17
FLOAT|SMALLFLOAT)
D 17
	Xabbr=dbl ;;
E 17
I 17
	: OK ;;
E 17
DECIMAL*|MONEY*)
D 17
	Xabbr=dec ;;
E 17
I 17
	: OK ;;
E 17
D 9
*)	echo "$0: unknown I4GL data type $1" >&2 ; exit 1 ;;
E 9
I 9
*)	echo "$0: unknown I4GL data type $Xpktype" >&2 ; exit 1 ;;
E 9
esac

E 6
I 3
D 17
# Set up various output file names
E 3
D 2
FGL=${PRGNAME}.4gl
FGE=${PRGNAME}.4ge
PER=${PRGNAME}.per
FRM=${PRGNAME}.frm
MSG=${PRGNAME}.msg
IEM=${PRGNAME}.iem
E 2
I 2
FGL=${program}.4gl
PER=${program}.per
FRM=${program}.frm
MSG=${program}.msg
IEM=${program}.iem
I 5
CTL=${program}.inp
I 10
AFT=${program}.aft
E 10
I 6
LIB=dlist$Xabbr.c
AUX=perfaux.4gl
POP=popstr.c
H=dlist.h
I 9
MK4GL=mk.4gl
I 11
DLIST=dlist.c
E 11
E 9
E 6
E 5
D 8
EC="${program}.ec ${program}2.ec"
C="${program}.c ${program}2.c"
E 8
I 8
EC="${program}.ec perfaux.ec"
C="${program}.c perfaux.c"
E 17
I 17
export Xtable
export Xdbase
export Xpkey
export xpkey
export Xpktype
export xdbase
export xtable
export xtabname
export Xmenu
export Xform
export program
E 17
E 8
E 2

I 18
D 19
: ${FGLBLDDIR:=${KPIDIRECTORY:-/usr/db/kpi}}
E 19
I 19
: ${FGLBLDDIR:=${KPIDIRECTORY:-/usr/db/kpi}/etc}
E 19

E 18
D 17
help=100
I 9
D 12
FGLBLDDIR=${FGLBLDDIR:-$KPIDIRECTORY/etc}
E 12
E 9
FORMBUILD=${FORMBUILD:-form4gl}
C4GL=${C4GL:-c4gl}
I 2
D 3
PROGRAM=perform.4gl
MESSAGES=perform.msg
AUXFILE=perfaux.4gl
E 3
I 3
D 9
D 18
PROGRAM=${KPIDIRECTORY}/etc/perform.4gl
MESSAGE=${KPIDIRECTORY}/etc/perform.msg
D 6
AUXFILE=${KPIDIRECTORY}/etc/perfaux.4gl
E 18
I 18
D 19
PROGRAM=${FGLBLDDIR}/etc/perform.4gl
MESSAGE=${FGLBLDDIR}/etc/perform.msg
AUXFILE=${FGLBLDDIR}/etc/perfaux.4gl
E 19
I 19
PROGRAM=${FGLBLDDIR}/perform.4gl
MESSAGE=${FGLBLDDIR}/perform.msg
AUXFILE=${FGLBLDDIR}/perfaux.4gl
E 19
E 18
E 6
I 6
AUXFILE=${KPIDIRECTORY}/etc/$AUX
LIBFILE=${KPIDIRECTORY}/etc/$LIB
POPFILE=${KPIDIRECTORY}/etc/$POP
E 9
I 9
PROGRAM=$FGLBLDDIR/perform.4gl
MESSAGE=$FGLBLDDIR/perform.msg
MKFILE=$FGLBLDDIR/perform.mk
E 9
I 8
EDFILE=${TMPDIR:-/tmp}/fglblda.$$
TMPFILE=${TMPDIR:-/tmp}/fglbldb.$$
E 8
D 9
HFILE=${KPIDIRECTORY}/etc/$H
E 9
E 6
E 3
E 2

D 2
echo "*** Phase 1:  Building default fgl and help source ..."
cat > $TMP <<!
E 2
I 2
echo "Phase 1: Building default form"
D 12
$FORMBUILD -q -d $program $Xdbase $xtable
E 12
I 12
$FORMBUILD -q -d $program $Xdbase $xtabname
E 12

ed - $PER >/dev/null 2>&1 <<!
3a
------------------------------------------------ CTRL-W for Help -----------

.
\$a
instructions
D 15
screen record s_$xtable ($xtable.*)
E 15
I 15
screen record s_$xtable ($xtabname.*)
E 15
end
.
w
q
E 2
!
D 2
cat > $MSG <<!
!
E 2
I 2
$FORMBUILD -q $program
I 4
D 9
if grep -i '^[a-z].* = .*[a-z_0-9]\[[0-9]*,[0-9]*\];' $program.per >/dev/null
E 9
I 9
if grep -i '^[_a-z].* = .*[a-z_0-9]\[[0-9]*,[0-9]*\];' $program.per >/dev/null
E 9
then
	echo "$0: warning -- the screen form $program.per needs editing" >&2
fi
E 4
E 2

I 12
D 14
set -x
E 14
E 12
D 2
echo "*** Phase 2:  Building and compiling help files ..."
E 2
I 2
echo "Phase 2: Building help and source files"
I 19
>$CTL
E 19
I 8
trap "rm -f $TMPFILE $EDFILE ; exit 1" 1 2 3 14 15
E 8
E 2
{
D 2
rdsql -d$DBNAME <<!
select	syscolumns.colname
E 2
I 2
DBDELIMITER=' ' rdsql -d$Xdbase <<!
select	syscolumns.colname, syscolumns.colno
E 2
from	syscolumns
where   syscolumns.tabid =
	(
	select	systables.tabid
 	from 	systables
D 2
	where	systables.tabname = "$TABNAME"
E 2
I 2
	where	systables.tabname = "$xtabname"
E 2
	)
D 2
order by colno
E 2
I 2
order by syscolumns.colno
E 2
!
} | {

I 5
echo
echo "{ Help function }"
E 5
D 2
echo "FUNCTION help_Qtabname()"
E 2
I 2
echo "FUNCTION help_xtable()"
E 2
echo
echo "	CASE"

I 5
{
echo
echo "{ Input function }"
D 10
echo "FUNCTION inp_xtable()"
E 10
I 10
echo "FUNCTION inp_xtable(iucode)"
E 10
echo
echo "	DEFINE"
I 16
echo "		pr_xtable	RECORD LIKE Xtable.*, { Previous contents of fields }"
E 16
D 10
echo "		instatus	INTEGER"
E 10
I 10
echo "		instatus	INTEGER,"
echo "		iucode		CHAR(1) { 'I' Insert, 'U' Update }"
E 10
echo
echo "	LET instatus = TRUE { OK }"
I 10
echo "	LET prev_field = \"\""
E 10
D 6
echo "	INPUT gr_xtable.* WITHOUT DEFAULTS FROM s_xtable.* HELP 20"
E 6
I 6
echo "	INPUT wr_xtable.* WITHOUT DEFAULTS FROM s_xtable.* HELP 20"
E 6
echo
echo "	ON KEY (CONTROL-F)"
echo "		CALL help_xtable()"
echo
echo "	ON KEY (CONTROL-P)"
echo "		CASE"
} >>$CTL

E 5
D 2
while read COLNAME
E 2
I 2
D 3
cat $MESSAGES >$MSG
E 3
I 3
cat $MESSAGE >$MSG
E 3

I 8
firstcol=
nextcol=
prevcol=

E 8
while read colname colno
E 2
do
I 8
	firstcol=${firstcol:-$colname}
	if [ "$prevcol" = $Xpkey ]
	then
		nextcol=$colname
	fi
	prevcol=$colname

E 8
	{
	echo ".$help"
	echo
D 2
	echo "This is the default help for "$TABNAME.$COLNAME
E 2
I 2
	echo "This is the default help for \"$Xtable.$colname\""
E 2
	echo
	} >> $MSG
I 5

	{
	echo "			NEXT FIELD $colname"
	echo "		WHEN INFIELD($colname)"
D 6
	echo "			LET gr_$xtable.$colname = cp_$xtable.$colname"
#	echo "			DISPLAY BY NAME gr_$xtable.colname"
E 6
I 6
	echo "			LET wr_$xtable.$colname = cp_$xtable.$colname"
	echo "			DISPLAY BY NAME wr_$xtable.$colname"
E 6
	} >>$CTL

I 10
	{
I 16
	echo "		BEFORE FIELD $colname"
	echo "			LET pr_xtable.$colname = wr_xtable.$colname"
	echo
E 16
	echo "		AFTER FIELD $colname"
	echo "			LET prev_field = \"$colname\""
	echo
	} >>$AFT

E 10
E 5
D 2
	echo "	WHEN INFIELD($COLNAME)		CALL SHOWHELP($help)"
E 2
I 2
	echo "	WHEN INFIELD($colname)		CALL SHOWHELP($help)"
E 2
	help=`expr $help + 1`
done

I 8
D 9
set -x
echo "s/NEXT FIELD $Xpkey/NEXT FIELD ${nextcol:-$firstcol}/" >$EDFILE
set +x
E 9
I 9
if [ $Xserial = yes ]
then
	echo "s/NEXT FIELD $Xpkey/NEXT FIELD ${nextcol:-$firstcol}/" >$EDFILE
else
	echo "s/@/@/" >$EDFILE	# A no-op
fi
E 9

E 8
echo "	END CASE"
echo
D 2
echo "END FUNCTION {help_Qtabname}"
} >>$TMP
E 2
I 2
echo "END FUNCTION {help_xtable}"
I 5

{
echo "		END CASE"
echo
I 10
cat $AFT
E 10
echo "	END INPUT"
echo
echo "	IF INT_FLAG = FALSE THEN"
echo "		LET instatus = TRUE"
echo "		{"
echo "		You should modify this to include any validation"
echo "		required after the input -- it is generally more reliable"
echo "		here than in an AFTER INPUT clause within the INPUT"
echo "		statement"
echo "		}"
echo "		MESSAGE \"\""
echo "	ELSE"
echo "		MESSAGE \"\""
echo "		LET INT_FLAG = FALSE"
echo "		LET instatus = FALSE"
echo "	END IF"
echo
echo "	RETURN instatus"
echo
echo "END FUNCTION {inp_xtable}"
} >>$CTL
ed - $CTL <<!
1
/NEXT FIELD/m/END CASE/-1
w
q
!
cat $CTL
D 10
rm -f $CTL
E 10
I 10
rm -f $CTL $AFT
E 10

E 5
} |
D 8
cat $PROGRAM - |
E 8
I 8
cat $PROGRAM - >$TMPFILE

D 9
set -x
E 9
D 12
cat $TMPFILE |
E 12
I 12
# Do not connect this pipeline with previous pipeline
# The file $EDFILE must be created before running sed
E 12
E 8
D 6
sed -e "s/Xdbase/$Xdbase/g" \
E 6
I 6
sed $SERIALDELETE \
I 12
	-e "s/^#$FGLVERSION//"\
	-e "/^#/d"\
E 12
I 8
	-e "`cat $EDFILE`" \
E 8
	-e "s/Xdbase/$Xdbase/g" \
E 6
	-e "s/Xtable/$Xtable/g" \
	-e "s/xtable/$xtable/g" \
	-e "s/Xpkey/$Xpkey/g" \
	-e "s/xpkey/$xpkey/g" \
I 6
	-e "s/Xpktype/$Xpktype/g" \
D 14
	-e "s/X\\(...\\)_key/sc_\\1$Xabbr/g" \
E 14
I 14
	-e "s/X\\([a-z]*\\)_key/sc_\\1$Xabbr/g" \
E 14
E 6
	-e "s/Xform/$program/g" \
	-e "s/Xmenu/$Xmenu/g" \
D 12
	>$FGL
E 12
I 12
	$TMPFILE >$FGL
E 12
I 8
D 9
set +x
E 9
E 8
E 2

I 8
D 9
rm -f $TMPFILE $EDFILE
E 9
I 9
rm -f $TMPFILE $EDFILE $TMP
E 9

I 9
D 11
for file in $AUX $LIB $POP $H $MK4GL
E 11
I 11
for file in $AUX $LIB $POP $H $MK4GL $DLIST
E 11
do
	if [ ! -f $file ]
	then
		if cmp -s $FGLBLDDIR/$file $file
		then : OK
		else cat $FGLBLDDIR/$file >$file
		fi
	fi
done

E 9
E 8
mkmessage $MSG $IEM
D 2

echo "*** Phase 3:  Building and compiling default form ..."

$FORMBUILD -d $PRGNAME $DBNAME $TABNAME >/dev/null 2>&1

ed - $PER >/dev/null 2>&1 <<!
3a
------------------------------------------------ CTRL-W for Help -----------

.
w
q
!
$FORMBUILD $PRGNAME >/dev/null 2>&1

echo "*** Phase 4:  Building and compiling fgl source ..."

sed -e"s/Qdbname/$DBNAME/g" \
	-e"s/Qtabname/$TABNAME/g" \
	-e"s/Qsername/$SERNAME/g" \
	-e"s/Qprgname/$PRGNAME/g" \
	-e"s/Qmenuname/$MENUNAME/g" \
	$TMP >$FGL

E 2
D 9
rm -f $TMP
E 9
I 9
sed -e "s/Xprog/$program/g" -e "s/Xdlist/dlist$Xabbr/g" $MKFILE >$program.mk
E 9

D 2
$C4GL -o $FGE $FGL -s
E 2
I 2
D 6
D 19
cp $AUXFILE ${program}2.4gl
E 19
I 19
if [ ! -f ${program}2.4gl ]
then
	cp $AUXFILE ${program}2.4gl
fi
E 19
E 6
I 6
D 9
cat $AUXFILE >$AUX
cat $LIBFILE >$LIB
cat $POPFILE >$POP
cat $HFILE >$H
SOURCE="$FGL $AUX $LIB $POP"
E 6

I 8
if [ $Xserial = yes ]
then
	echo "$0: warning -- using ^P on the column before $Xpkey"
	echo "\twill cause the program to lock up with the terminal beeping."
	echo "\tTo fix this, edit the source and change the line which reads:"
	echo "\t\tNEXT FIELD $Xpkey"
	echo "\tso that it goes to the next field after $Xpkey"
fi >&2

E 9
E 8
echo "Phase 3: Compiling I4GL source"
D 6
D 19
$C4GL -o $program $FGL ${program}2.4gl -s
E 19
I 19
$C4GL -o $program $FGL ${program}2.4gl -s 2>&1 |
	grep -v 'statement not reached'
E 19
E 6
I 6
D 7
$C4GL -o $program $SOURCE -s
E 7
I 7
D 9
$C4GL -o $program $SOURCE -s 2>&1 |
E 9
I 9
make -f $program.mk $program 2>&1 |
E 9
D 8
	grep -v 'warning: statement not reached'
E 8
I 8
	grep -v 'warning: statement not reached' >&2
E 17
I 17
exec fglbld.alt
E 20
I 20
D 27
exec $FGLBLDDIR/fglbld.4ge
E 27
I 27
exec $FGLBLDDIR/fglbld.4ge ${@+"$@"}
E 27
E 20
E 17
E 8
E 7
E 6
E 2
D 9
rm -f $C $EC
E 9
E 1
