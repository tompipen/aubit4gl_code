
CXX=g++
CXXFLAGS=-g

FglParserTest_OBJECTS = FglParserTest.o SimpleFglTest.o 

FglParserTest: $(FglParserTest_OBJECTS) 
	$(CXX) $(CXXFLAGS) -o $@ $(FglParserTest_OBJECTS) -ldl /usr/local/cppunit-1.9.11/src/cppunit/.libs/libcppunit.so ../fgl_parser.so ../ast/fgl_ast.so


clean:
	rm *.o *.so FglParserTest


