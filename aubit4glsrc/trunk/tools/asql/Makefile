all : asql.4ae

asql.4ae: asql.o connection_menu.o database.o lex.yy.o main_menu.o query.o session.o simple_parse.o table.o pick.o dir.o execute.o  paginate.o
	4glpc -g  $^ -o asql.4ae  -lUI_TUI

lex.yy.c: parse.l
	flex -i parse.l

asql.o: asql.4gl
	4glpc -g -c $^

connection_menu.o: connection_menu.4gl
	4glpc -g -c $^

pick.o: pick.4gl
	4glpc -g -c $^

database.o: database.4gl
	4glpc -g -c $^

main_menu.o: main_menu.4gl
	4glpc -g -c $^

query.o: query.4gl
	4glpc -g -G -c $^

session.o: session.4gl
	4glpc -g -c $^

table.o: table.4gl
	4glpc -g -c $^

execute.o: execute.4gl
	4glpc -g -G -c $^

paginate.o: paginate.4gl
	4glpc -g -c $^

dir.o: dir.c
	gcc -g -c dir.c 

clean:
	rm -f \
	asql.4ae asql.4ae.err asql.c asql.ec asql.glb asql.h asql.o \
	connection_menu.c connection_menu.ec connection_menu.glb connection_menu.h connection_menu.o \
	database.c database.ec database.glb database.h database.o \
	dir.o \
	execute.c execute.ec execute.glb execute.h execute.o \
	lex.yy.c lex.yy.o \
	main_menu.c main_menu.ec main_menu.glb main_menu.h main_menu.o \
	pick.c pick.ec pick.glb pick.h pick.o \
	query.c query.ec query.glb query.h query.o \
	session.c session.ec session.glb session.h session.o \
	simple_parse.o \
	table.c table.ec table.glb table.h table.o
