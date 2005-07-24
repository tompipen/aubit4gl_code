#
# Compilation of the 4gl AST.
# In this attempt the AST is created with treecc tool.
#

CXXFLAGS=-g

FGL_AST_OBJECTS=Fgl.o 
#FunctionList.o 

SO_LDFLAGS=-shared

fgl_ast.so : $(FGL_AST_OBJECTS)
	${LD} ${SO_LDFLAGS} $^ -o $@  ${LINKLIBS}

all: fgl_ast.so

Fgl.o: Fgl.tc FglDefinition.tc ScreenInteraction.tc
	treecc Fgl.tc
	$(CXX) $(CXXFLAGS) -c Fgl.cpp

clean:
	rm -f *.o *.a *.so Fgl.cpp Fgl.h


