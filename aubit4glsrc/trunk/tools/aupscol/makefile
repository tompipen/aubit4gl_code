# Notes :
#
# You must make with A4GL_LEXTYPE=EC for now...
#
# Currently Informix only
#
#
# Set A4GL_UPSCOL_VAL, A4GL_UPSCOL_ATT to point to
# different tablenames if required
# (Tables will be created if they don't exist)
#
# You must have pick.ao in the asql directory first (compile asql before this one..)
#

aupscol: main.o upscol.o infx.o ../asql/pick.ao val.o att.o
	4glpc main.o upscol.o infx.o att.o ../asql/pick.ao val.o -o aupscol

att.o: att.4gl
	4glpc -g -c att.4gl -o att.o
main.o:main.4gl
	4glpc -g -c main.4gl -o main.o

val.o:val.4gl
	4glpc  -g -c val.4gl -o val.o

infx.o: infx.4gl
	4glpc -g -c infx.4gl -o infx.o

upscol.o: upscol.4gl
	4glpc -g -c upscol.4gl -o upscol.o


