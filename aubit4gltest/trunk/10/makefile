



ui_contrl.4ae: ui_contrl.4gl form.per
	${FGLC} ui_contrl.4gl -o ui_contrl.4ae
	fcompile form.per

compile: ui_contrl.4ae
	
run: ui_contrl.4ae
	sh ./run_ui_contrl

ansi_sql_compat:
	@echo "1"


desc:
	@echo "Simple combination of UI commands"
