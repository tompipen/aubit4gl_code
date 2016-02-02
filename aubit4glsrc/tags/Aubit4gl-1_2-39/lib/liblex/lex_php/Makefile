
ROOT        =../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common



CFLAGS=-g -I../../.. -I../../../incl -I../../../compilers/4glc -I.. -fPIC -Wall
${PLUGINDIR}/libLEX_PHP${SO_EXT}: php.c expr.c compile_php.h
	gcc $(CFLAGS) -shared php.c expr.c -o ${PLUGINDIR}/libLEX_PHP${SO_EXT}
