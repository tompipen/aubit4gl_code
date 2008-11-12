:	"@(#)$Id: mkversion.sh,v 1.1 2002-11-28 06:40:47 afalout Exp $"
#
#	Poor Man's version of VC(1)

VERSION="14 (1998-11-04)"

sed -e "s%[:]SQLFMT:%SQLFMT Version $VERSION%" \
	-e "s%[:]PRODUCT:%SQLFMT Version $VERSION%" $*
