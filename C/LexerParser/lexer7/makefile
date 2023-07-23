CC = gcc
CFLAGS = -g -Wall
DEPS = errorReporter.h parser.h symTable.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
p1: main.o parser.o
	$(CC) -o p1 main.o parser.o

clean:
	$(RM) p1 *.o