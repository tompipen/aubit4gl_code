:	"@(#)$Id: test01.sh,v 1.1.1.1 2002-06-15 05:07:14 afalout Exp $"
#
#	Script to test FGLBLD.ALT
#	PKEY: SERIAL

Xdbase="CONSULT" export Xdbase
xdbase="consult" export xdbase
xtabname="clients" export xtabname
xtable="clients" export xtable
Xtable="Clients" export Xtable
xpkey="clientid" export xpkey
Xpkey="Clientid" export Xpkey
Xpktype="SERIAL" export Xpktype
Xmenu="CLIENTS" export Xmenu
Xform="ccc" export Xform
program="ccc" export program
Xcollist="" export Xcollist
Xcollist="$Xcollist clientid"
Xcollist="$Xcollist client"
Xcollist="$Xcollist contact"
Xcollist="$Xcollist phone"
Xcollist="$Xcollist telex"
Xcollist="$Xcollist ansback"
Xcollist="$Xcollist fax"
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

${SHELL:-/bin/sh} ${-+"-$-"} fglbld.alt
