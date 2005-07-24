:	"@(#)$Id: mktest.sh,v 1.1.1.1 2002-06-15 05:07:13 afalout Exp $"
#
#	Auto-build of test version of FGLBLD

set -x -e
rmk GFLAGS=-k shar
rm -fr Test
mkdir ./Test
relink fglbld.sa ./Test
(
	set -x -e
	cd ./Test
	sh fglbld.sa
	rmk
)
