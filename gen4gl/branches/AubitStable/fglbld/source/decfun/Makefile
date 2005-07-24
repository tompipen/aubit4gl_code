
ROOT=../../

INCL_DIR=${ROOT}include

IFLAGS=-I${INFORMIXDIR}/incl -I${INFORMIXDIR}/incl/tools -I${INFORMIXDIR}/incl/esql -I${INCL_DIR}
CFLAGS=-O ${IFLAGS} -DI4GL_${FGLTYPE}

CMODS= \
	decabs.c  deceng.c  decfix.c  decneg.c  decsci.c   decvfy.c \
	decchk.c  decexp.c  decfmt.c  decpwr.c  decsqrt.c



OBJS=${CMODS:.c=.o}


all: ${OBJS}