all: parser  ebnftodot diagrams ace_diagrams per_diagrams



ace_diagrams:
	make -C ace diagrams

per_diagrams:
	make -C per diagrams

CFLAGS=-g -I. -I../4glc/rules/generated -I../4glc/rules -Wall

y.tab.c: parser.yacc
	bison -y parser.yacc

y.tab.o: y.tab.c lex.yy.c 
	gcc $(CFLAGS) -g -c y.tab.c

lex.yy.c: parser.lex
	flex parser.lex

kw.c: ../4glc/rules/generated/kw.c
	cp ../4glc/rules/generated/kw.c .

parser:  main.o y.tab.o kw.o
	gcc $(CFLAGS) y.tab.o main.o kw.o -o parser


clean:
	rm main.o y.tab.o parser ebnf.tab.cacc ebnf.tab.c kw.c ebnf.output y.output ebnf.tab.o kw.o main_ebnf.o *.png *.vcg *.dot *.gif lex.yyx.c lex.yy.c y.tab.c ebnftodot ./per/ebnf-eps-directory/screen.ebnf ./ebnf-eps-directory/fgl.ebnf ./ace/ebnf-eps-directory/ace.ebnf


mja1.gif:  mja1.dot
	dot -o mja1.gif -Tgif mja1.dot && gimp mja1.gif 

mja1.dot: ebnftodot dump_nodes
	ebnftodot > mja1.dot

ebnf.tab.cacc: ebnf.yacc
	bison ebnf.yacc

ebnf.tab.c: ebnf.tab.cacc
	cp ebnf.tab.cacc ebnf.tab.c

ebnf.tab.o: ebnf.tab.c lex.yyx.c
	gcc $(CFLAGS) -o ebnf.tab.o -c ebnf.tab.c

ebnftodot:  main_ebnf.o ebnf.tab.o
	gcc $(CFLAGS) -o ebnftodot main_ebnf.o ebnf.tab.o
	
ebnf.tab.cacc: ebnf.yacc


lex.yyx.c:  ebnf.lex
	flex -Pyyx ebnf.lex

diagrams: parser commands entries
	./parser > ebnf-eps-directory/fgl.ebnf
	sh process_to_eps
	#rm ebnf-eps-directory/*.eps

commands: mkcommands ../4glc/rules/generated/fgl.infx.yacc
	sh mkcommands
	
upload:
	scp  ebnf-eps-directory/*.pdf aubit@www.aubit.com:/home/aubit/public_html/aubit4gl/syntax
	scp  per/ebnf-eps-directory/*.pdf aubit@www.aubit.com:/home/aubit/public_html/aubit4gl/syntax/per
	scp  ace/ebnf-eps-directory/*.pdf aubit@www.aubit.com:/home/aubit/public_html/aubit4gl/syntax/ace
