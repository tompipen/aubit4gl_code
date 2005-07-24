:	"@(#)mkscript.sh	6.3 89/11/14"
#
#	@(#)FGLBLD Version 6.12 (04/04/1990)
#	Edit front-end scripts (file(s) specified as argument)

:	${FGLBLDDIR:?}
:	${FGLBLDBIN:?}
:	${FGLUSR:?}
:	${FGLGRP:?}
:	${FGLTYPE:?}

sed -e "s%XXFGLBLDDIR%$FGLBLDDIR%" \
    -e "s%XXFGLBLDBIN%$FGLBLDBIN%" \
    -e "s%XXFGLUSR%$FGLUSR%" \
    -e "s%XXFGLGRP%$FGLGRP%" \
    -e "s%XXFGLTYPE%$FGLTYPE%" \
	$*
