# Power-4gl demo program compilation.
echo "Compiling the 4gl and c modules..."
#c4gl -o demo.4ge *.4gl

c4gl -o demo.4ge demo.4gl underl.4gl account.4gl acctgrp.4gl acctran.4gl\
  bank.4gl func.4gl interf.4gl irate.4gl list.4gl menu.4gl printer.4gl\
  prntype.4gl qatran.4gl qirsum.4gl report.4gl state.4gl\
  format.c gettx.c misc.c math.c
