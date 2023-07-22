CXX = gcc
CXXFLAGS = -g -Wall

OBJECTS = fileOps.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm *.o main

