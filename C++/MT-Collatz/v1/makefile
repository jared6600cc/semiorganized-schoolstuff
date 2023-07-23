CFLAGS = -g -Wall
CC = g++

objects = mt-collatz.o collatz.o histogram.o

mt-collatz: $(objects)
	$(CC) -o mt-collatz $(objects) -pthread

mt-collatz.o: mt-collatz.cpp

.PHONY : clean
clean: 
	rm mt-collatz $(objects)
