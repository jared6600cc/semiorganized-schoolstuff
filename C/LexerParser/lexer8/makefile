CC = gcc
CFLAGS = -g -Wall
DEPS = errorReporter.h parser.h symTable.h lexicalAnalyzer.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

p1: main.o parser.o symTable.o lexicalAnalyzer.o
	$(CC) -o p1 main.o parser.o symTable.o lexicalAnalyzer.o

clean:
	$(RM) p1 *.o
