CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -ftest-coverage -fprofile-arcs

OBJECTS = Node.hpp Encryption.o HashTable.o TextReader.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf main.o
	$(RM) *.o *.gc* test/*.o test/*.gc* *.dSYM test/test core main

testBuild: $(OBJECTS) test/test.o
	$(CXX) $(CXXFLAGS) -o test/test $^

test: testBuild
	$(RM) *.gcda *.gcov test/*.gcda test/*.gcov
	test/test