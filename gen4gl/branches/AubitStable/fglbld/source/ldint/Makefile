
ROOT=../../

INCL_DIR=${ROOT}include

IFLAGS=-I${INFORMIXDIR}/incl -I${INFORMIXDIR}/incl/tools -I${INFORMIXDIR}/incl/esql -I${INCL_DIR}
CFLAGS=-O ${IFLAGS} -DI4GL_${FGLTYPE}

CMODS= \
ldchar.c    ldlong.c   ldsint8.c  lduint4.c  stdouble.c  stsint1.c  stuint4.c \
lddouble.c  ldsint1.c  ldstdec.c  lduint8.c  stfloat.c   stsint4.c  stuint8.c \
ldfloat.c   ldsint2.c  lduint1.c  stint.c     stuint1.c \
ldint.c     ldsint4.c  lduint2.c  stchar.c   stlong.c    stuint2.c

OBJS=${CMODS:.c=.o}


all: ${OBJS}