#See files "00_LEAME" and "compila_todos"

FILES.4gl= \
		00_test1.4gl \
		exec_sql.4gl \
		kk.4gl \
		fecha.4gl \
		menu.4gl \
		float.4gl \
		resta.4gl \
		01_ventanas.4gl \
		for.4gl \
		form.4gl \
		test.sql \
		update.4gl \
		datetime.4gl \
		interval.4gl


FILES.4gl.db = \
		whenever.4gl \
		51_sel_order.4gl \
		cursor.4gl \
		06_sel_where.4gl \
		05_insert.4gl \
		browse.4gl \
		inventario.4gl \
		declare_expr.4gl \
		52_select.4gl \

PROG.hye  = ${FILES.4gl:.4gl=.hye}
PROG.hye.db  = ${FILES.4gl.db:.4gl=.hye}

#all: 00_test1

all: nodb
	@echo "To compile programs that access database, create required database"
	@echo "and execute 'make withdb' command."

nodb: ${PROG.hye}
	@echo "All non-db programs compiled."

withdb: ${PROG.hye.db}
	@echo "All db access programs compiled."

00_test1:
	hy4gl 00_test1.4gl -o 00_test1.hye

#.4gl.hye:
%.hye: %.4gl
	hy4gl $^ -o $@

clean:
	rm *.hye *.bak *.c