#
# Test script just to try to assemble all the components that create the
# 4gl parser and compile it as a simple standalone parser.
#
# The goal is then use it inside fgldoc as an alternative parser.
#

# Main 

rm y.tab.c y.tab.h
rm y.output
rm generated/*

# Gera generated/kw.c e generated/kw.h
./convkw_hash kwords 
# Gera generated/states.c
./procstates defstates
bison -y -r all -d -v fgl.y
# Gera generated/mk_states.c
./mk_states_c y.output

# Compilar .c(s) para .o(s)

# Linkar
