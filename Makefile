CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -ftest-coverage -fprofile-arcs

OBJECTS = Node.hpp Encryption.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf main.o