:	"@(#)$Id: test02.sh,v 1.1.1.1 2002-06-15 05:07:14 afalout Exp $"
#
#	Script to test FGLBLD.ALT
#	PKEY: ROWID

Xdbase="CONSULT" export Xdbase
xdbase="consult" export xdbase
xtabname="timesheet" export xtabname
xtable="timesheet" export xtable
Xtable="Timesheet" export Xtable
xpkey="rowid" export xpkey
xpkvalue="ct_timesheet.rowid" export xpkvalue
Xpkey_dec="Y" export Xpkey_dec
Xpkey="Rowid" export Xpkey
Xpktype="INTEGER" export Xpktype
Xmenu="TIMESHEET" export Xmenu
Xform="ts" export Xform
program="ts" export program
Xcollist="" export Xcollist
Xcollist="$Xcollist ts_date"
Xcollist="$Xcollist ts_from"
Xcollist="$Xcollist ts_upto"
Xcollist="$Xcollist jobid"
Xcollist="$Xcollist notes"
Xopt_ins="Y" export Xopt_ins
Xopt_del="Y" export Xopt_del
Xopt_upd="Y" export Xopt_upd
Xopt_rep="Y" export Xopt_rep
Xopt_sh="Y" export Xopt_sh
Xafterfield="Y" export Xafterfield
Xbeforefield="Y" export Xbeforefield
Xcontrolp="Y" export Xcontrolp
Xcontrolb="Y" export Xcontrolb
${SHELL:-/bin/sh} ${-+'-$-'} fglbld.alt
