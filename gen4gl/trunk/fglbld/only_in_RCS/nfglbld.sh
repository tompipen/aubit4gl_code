:	"@(#)$Id: nfglbld.sh,v 1.1.1.1 2002-06-15 05:07:13 afalout Exp $"
#
#	Auto-install of FGLBLD

set -x -e
rmk shar
rm -fr $HOME/nfglbld $HOME/ofglbld
mkdir $HOME/nfglbld
relink fglbld.sa $HOME/nfglbld
(
	set -x -e
	cd $HOME/nfglbld
	sh fglbld.sa
	if rmk
	then
		rmk cleanup
		cd ..
		mv fglbld ofglbld
		mv nfglbld fglbld
	fi
)
rmk cleanup
