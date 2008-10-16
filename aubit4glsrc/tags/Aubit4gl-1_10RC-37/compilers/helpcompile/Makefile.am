##Since mkmess is a user program, you want to install it where the rest of
##the user programs go: bindir. Additionally, mkmess has some Texinfo
##documentation. Your configure.in script uses AC_REPLACE_FUNCS, so you
##need to link against @LIBOBJS@. So here's what you'd write:

##localedir = $(datadir)/locale

bin_PROGRAMS = mkmess
mkmess_SOURCES = mkmess.c a4gl_mkmess_int.h
##INCLUDES = -I../../incl
INCLUDES = -I../fcompile

##INCLUDES = -I../intl -DLOCALEDIR=\"$(localedir)\"
##mkmess_LDADD = @LIBOBJS@ @INTLLIBS@ @ALLOCA@
mkmess_LDADD = -laubit4gl

##info_TEXINFOS = mkmess.texi
