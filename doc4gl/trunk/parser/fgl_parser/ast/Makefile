
CXXFLAGS=-g

FGL_AST_OBJECTS=FglNode.o FglToken.o FglFunction.o FglIdentifier.o

SO_LDFLAGS=-shared

fgl_ast.so : $(FGL_AST_OBJECTS)
	${LD} ${SO_LDFLAGS} $^ -o $@  ${LINKLIBS}

fgl_ast.a : $(FGL_AST_OBJECTS)
#ar rv $@ $(FGL_AST_OBJECTS)

clean:
	rm -f *.o *.a *.so
