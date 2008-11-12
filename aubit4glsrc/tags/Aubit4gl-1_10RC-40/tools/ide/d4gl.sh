#	"@(#)$Id: d4gl.sh,v 1.2 2004-09-28 09:49:27 afalout Exp $"
#
#	Run D4GL -- alternative D4GL compiling front-end
#	Assume that it is installed under :D4GL_DIR:


#Command line switches: 
#d4gl [-c fgl2p] [-m make] [-p program] [-f form4gl] [-t target] [file.4gl ...]

#--------D4GL related options---------
# Defaults:
#D4GL_SOURCE_COMPILER="fgl2p"
#D4GL_SOURCE_OPTIONS=""
#D4GL_FORM_COMPILER="fglform"
#D4GL_FORM_OPTIONS="-q"
#D4GL_MAKE_PROGRAM="make"
#D4GL_MAKE_OPTIONS=""
#D4GL_MAKE_TARGET=""
#D4GL_MAKE_MAKEFILE="Makefile"
#D4GL_PROGRAM_NAME= ""
#D4GL_EDITOR=$DBEDIT
#VISUAL="vi"
#4js in GUI mode only:
#D4GL_WINDOWCMD_PREFIX="xterm -sb -e"
#D4GL_WINDOWCMD_SUFFIX="; sleep 5"
#-------------------------------------
#For Aubit 4gl:
if test "$FGLPCEXEC" != ""
	export D4GL_SOURCE_COMPILER="$FGLPCEXEC"
else
	export D4GL_SOURCE_COMPILER="4glpc"
fi
endif
export D4GL_SOURCE_OPTIONS=""
export D4GL_FORM_COMPILER="fcompile"
export D4GL_FORM_OPTIONS=""
export D4GL_MAKE_PROGRAM="make"
export D4GL_MAKE_OPTIONS=""
export D4GL_MAKE_TARGET=""
export D4GL_MAKE_MAKEFILE="makefile"
export D4GL_PROGRAM_NAME=""
export D4GL_EDITOR="vi"
export VISUAL="gedit"
#-------------------------------------
D4GLDIR=${D4GLDIR:-:D4GL_DIR:}
export D4GLDIR

# Location for form files and message files
DBPATH=$D4GLDIR:$DBPATH
export DBPATH
arg0=`basename $0 .sh`


# Run GUI-mode D4GL programs in background!
for progfile in $arg0.42r $arg0.42e $arg0.4gi $arg0.4ge $arg0.4ae
do
	progpath=$D4GLDIR/$progfile
	if [ -x $progpath ]
	then
		case "$progfile" in
		*.42e)
			if [ ${FGLGUI:-0} = 1 ]
			then      $progpath ${@+"$@"} & exit
			else exec $progpath ${@+"$@"}
			fi;;
		*.42r)
			export FGLLDPATH=$D4GLDIR:$FGLLDPATH
			if [ ${FGLGUI:-0} = 1 ]
			then      ${FGLRUN:-$D4GLDIR/fglrun} $progpath ${@+"$@"} & exit
			else exec ${FGLRUN:-$D4GLDIR/fglrun} $progpath ${@+"$@"}
			fi;;
		*.4ge)
			exec $progpath ${@+"$@"};;
		*.4ae)
			exec $progpath ${@+"$@"};;

		*.4gi)
			exec ${FGLGO:-$D4GLDIR/fglgo} $progpath ${@+"$@"};;
		esac
	fi
done

echo "$arg0: could not find an executable in ${D4GLDIR}" 1>&2
exit 1




