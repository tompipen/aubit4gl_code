include ../Makefile.global

FUENTES=4gl.c fecha.c pila.c menu.c browse.c pgres.c 4glforms.c fecha.c \
   fun_fecha.c runtime.c
OBJS=4gl.o fecha.o pila.o menu.o browse.o pgres.o 4glforms.o \
   fun_fecha.o runtime.o

all: lib4gl.so.$(VERSION) lib4gl.$(VERSION).a 

   
static: lib4gl.$(VERSION).a

.c.o: 
	gcc -g -DVERSION='"$(VERSION)"' -Wall -c $< -I $(INCL_PGRES)

lib4gl.so.$(VERSION): $(OBJS)
	ld -x -Bshareable -o lib4gl.so.$(VERSION) $(OBJS)

lib4gl.$(VERSION).a: $(OBJS)
	ar crs lib4gl.$(VERSION).a $(OBJS) 
	ranlib lib4gl.$(VERSION).a

install: 
	cp hy4gl.h $(INST_DIR)
	cp lib4gl.so.$(VERSION) $(INST_DIR)
	ln -sf lib4gl.so.$(VERSION) $(INST_DIR)/lib4gl.so 
	cp lib4gl.$(VERSION).a $(INST_DIR)
	ln -sf lib4gl.$(VERSION).a $(INST_DIR)/lib4gl.a
    
clean:
	rm -f *.o lib4gl.so.$(VERSION) lib4gl.$(VERSION).a *.bak *~
