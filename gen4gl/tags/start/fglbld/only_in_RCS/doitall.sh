:	"@(#)$Id: doitall.sh,v 1.1.1.1 2002-06-15 05:07:13 afalout Exp $"
#
#	FGLBLD -- test compilation facility

tmp=${TMPDIR:-/tmp}/dia.$$
trap "rm -f $tmp ; exit 1" 1 2 3 13 15

FGLBLDDIR=$HOME/tmp/fglbld
export FGLBLDDIR

cat >$tmp <<!
rm -fr $FGLBLDDIR
mkdir $FGLBLDDIR
rmk shar
mv fglbld.sa $FGLBLDDIR
rmk cleanup
cd $FGLBLDDIR
sh fglbld.sa
rmk
mv Distribution I4GL.RDS
FGLTYPE=C4GL
export FGLTYPE
rmk c4gl
mkdist
mv Distribution I4GL.C4GL
rmk cleanup
rm -f $tmp
!

LOGFILE=$HOME/tmp/fglbld.log
export LOGFILE
rm -f $LOGFILE
bg ksh -x $tmp

# Do not remove the file $tmp -- it is still in use
# The script will remove it in due course
exit 0
