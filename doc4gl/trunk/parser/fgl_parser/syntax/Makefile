
fgl.o: fgl.c
	$(CXX) $(CFLAGS) -I .. -I ../ast -I ../lexer -I ../error -c fgl.c

fgl.c : fgl.y
	bison -y -r all -d -v fgl.y
	mv -f y.tab.c fgl.c
	cd ..; ./mk_states_c syntax/y.output

../generated/kw.yh : ../kwords
	cd .. ; ./convkw_hash kwords 

fgl.y : all_rules.y fgl_y.m4 preamble.y ../generated/kw.yh 
	m4 fgl_y.m4 > $@

clean:
	rm -f y.tab.c y.tab.h *.o y.output fgl.y fgl.c

