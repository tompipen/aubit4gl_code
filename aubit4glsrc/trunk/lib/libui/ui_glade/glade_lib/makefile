
$(AUBITDIR)/lib/libA4GL_glade.so : list.o common.o form.o sbar.o field.o entry.o text_view.o mlist.o
	export A4GL_LEXTYPE=C && 4glpc -g  -as-dll sbar.o form.o list.o common.o field.o entry.o text_view.o mlist.o -o $(AUBITDIR)/lib/libA4GL_glade.so `pkg-config libglade-2.0 --libs`

list.o: list.4gl
	export A4GL_LEXTYPE=C && 4glc list.4gl 
	gcc -g  -c list.c -o list.o `pkg-config libglade-2.0 --cflags` -I$(AUBITDIR)/incl 


mlist.o: mlist.4gl
	export A4GL_LEXTYPE=C && 4glc mlist.4gl 
	gcc -g  -c mlist.c -o mlist.o `pkg-config libglade-2.0 --cflags` -I$(AUBITDIR)/incl 


common.o: common.4gl
	export A4GL_LEXTYPE=C && 4glc common.4gl 
	gcc -g  -c common.c -o common.o `pkg-config libglade-2.0 --cflags` -I$(AUBITDIR)/incl

form.o: form.4gl
	export A4GL_LEXTYPE=C && 4glc form.4gl 
	gcc -g  -c form.c -o form.o `pkg-config libglade-2.0 --cflags` -I$(AUBITDIR)/incl

sbar.o: sbar.4gl
	export A4GL_LEXTYPE=C && 4glc sbar.4gl 
	gcc -g  -c sbar.c -o sbar.o `pkg-config libglade-2.0 --cflags` -I$(AUBITDIR)/incl

field.o: field.4gl
	export A4GL_LEXTYPE=C && 4glc field.4gl 
	gcc -g  -c field.c -o field.o `pkg-config libglade-2.0 --cflags` -I$(AUBITDIR)/incl


entry.o: entry.4gl
	export A4GL_LEXTYPE=C && 4glc entry.4gl 
	gcc -g  -c entry.c -o entry.o `pkg-config libglade-2.0 --cflags` -I$(AUBITDIR)/incl


text_view.o: text_view.4gl
	export A4GL_LEXTYPE=C && 4glc text_view.4gl 
	gcc -g  -c text_view.c -o text_view.o `pkg-config libglade-2.0 --cflags` -I$(AUBITDIR)/incl
