CC = gcc
CFLAGS = -g -Wall
DEPS = errorReporter.h parser.h symTable.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

p2: main.o parser.o symTable.o
	$(CC) -o p2 main.o parser.o symTable.o

clean:
	$(RM) p2 *.o
