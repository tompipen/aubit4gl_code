cd $AUBITDIR/node/baseProgs
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/aubit4gl/aubit4glsrc/lib/libui/ui_json/json/libjson/libjson-0.8
export A4GL_UI=JSON
export ALWAYSUSEXMLFORMS=N
unset CALLERRHOOK
unset A4GL_GDB_ATTACH
export DUMP_CORE=Y

if [ "$1" = "" ]
then
	./prog.4ae
else
	$AUBITDIR/node/baseProgs/$1.4ae
fi

