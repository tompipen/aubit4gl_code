
#VPATH       =./4glsrc

PROG		= alllib.lib

#GLOBALS.4gl	= Llibfgldd.4gl
GLOBALS.4gl	= d_libglob.4gl

FILES.4gl	= \
			${GLOBALS.4gl} \
d_auth.4gl      d_env.4gl      d_pjPS.4gl     d_uteis.4gl     menuVCasc.4gl \
d_cheque.4gl    d_erro.4gl     d_print.4gl    d_wait.4gl      menuVM13.4gl \
d_col.4gl       d_printer.4gl  menuVMarc.4gl  d_scr.4gl \
d_collen.4gl    geral.4gl      menuV.4gl \
d_copia.4gl     d_rep.4gl      gscr.4gl       open_win.4gl \
d_count.4gl     d_log.4gl      d_round.4gl    ispool.4gl      PSUtils.4gl \
d_datas.4gl     d_lov.4gl      libPS.4gl      \
d_desc.4gl      dLov.4gl       d_selfich.4gl  st_count.4gl \
d_dialog.4gl    d_string.4gl   d_dir.4gl      d_null.4gl      d_transac.4gl \
d_ecrans.4gl    d_tty.4gl      menuMarc.4gl   spool.4gl \
d_perutil.4gl   d_users.4gl    d_mostra.4gl   d_extenso.4gl


#Not nedded - do not compile
#d_etiq.4gl d_prt.4gl d_oficios.4gl d_empCentr.4gl

#od_rep.4gl copy of d_rep.4gl

#libPSold.4gl is old version of libPS.4gl

#extenso4gl.4gl is copy of d_extenso.4gl

#Contain main block:
# maindmst.4gl main_drep.4gl teste_ps.4gl test_edit.4gl


