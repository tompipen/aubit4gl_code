#!/bin/sh
#################################################
#
# Install GTK+ libraries and there dependencies needed to compile
# Aubit GTK+ support, on CygWin/Windows
#
# Tested using (from http://www.gimp.org/~tml/gimp/win32/downloads.html):
#
#gtk+-dev-2.0.6-20020921.zip
#gtk+-2.0.6-20020921.zip
#glib-2.0.6-20020802.zip
#glib-dev-2.0.6-20020802.zip
#pango-1.0.4-20020928.zip
#libintl-0.10.40-tml-20020904.zip
#libiconv-1.7-w32.bin.zip
#atk-1.0.3-20020821.zip
#pango-dev-1.0.4-20020928.zip
#atk-dev-1.0.3-20020821.zip
#################################################

ARCH_PATH=/tmp/aubit_gtk_inst
INST_ROOT=/usr
UNZIP="unzip -o"
TARBALL=GTK+*-WIN32-for-Aubit.zip
CURR_DIR=`pwd`
LOGFILE=$ARCH_PATH/aubit_gtk_inst.log
LOGCMD=" >> $LOGFILE"

echo "Start:" > $LOGFILE

if ! [ -d "$ARCH_PATH" ]; then
    mkdir "$ARCH_PATH"
fi

if [ "$CURR_DIR" != "$ARCH_PATH" ] && [ -f "$TARBALL" ]; then
	mv $TARBALL $ARCH_PATH
fi
cd $ARCH_PATH
$UNZIP $TARBALL >> $LOGFILE

cd $INST_ROOT

	$UNZIP $ARCH_PATH/glib-?.?.?-*.zip >> $LOGFILE
	$UNZIP $ARCH_PATH/glib-dev-?.?.?-*.zip >> $LOGFILE
	$UNZIP $ARCH_PATH/atk-?.?.?-*.zip >> $LOGFILE
	$UNZIP $ARCH_PATH/atk-dev-?.?.?-*.zip >> $LOGFILE
	$UNZIP $ARCH_PATH/pango-?.?.?-*.zip >> $LOGFILE
	$UNZIP $ARCH_PATH/pango-dev-*-*.zip >> $LOGFILE
	$UNZIP $ARCH_PATH/gtk+-?.?.?-*.zip >> $LOGFILE
	$UNZIP $ARCH_PATH/gtk+-dev-*-*.zip >> $LOGFILE
	$UNZIP $ARCH_PATH/libintl-*-*-*.zip >> $LOGFILE

cd $ARCH_PATH
	$UNZIP $ARCH_PATH/libiconv-*-w32.bin.zip >> $LOGFILE
	LIBICONV_PATH=`ls -d libiconv-*-w32.bin`

	cp $LIBICONV_PATH/*.dll $INST_ROOT/lib >> $LOGFILE
	cp $LIBICONV_PATH/*.lib $INST_ROOT/lib >> $LOGFILE
	cp $LIBICONV_PATH/*.exe $INST_ROOT/bin >> $LOGFILE
	cp $LIBICONV_PATH/*.h $INST_ROOT/include >> $LOGFILE
	
	if ! [ -d /etc/pango ]; then
		mkdir /etc/pango
    fi
	cp /usr/etc/pango/pango.modules /etc/pango/ >> $LOGFILE

	#not needed cp atk.pc $INST_ROOT/lib/pkgconfig
	#not needed cp pangowin32.pc $INST_ROOT/lib/pkgconfig

echo ""
echo "GTK+ for Aubit installed - see log file:"
echo "$LOGFILE for details."
echo "Please re-run ./configure, and re-make Aubit compiler."
echo ""
