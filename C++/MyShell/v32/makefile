all: P1

P1: main.o commands.o
	g++ main.o commands.o -o P1

main.o: main.cpp
	g++ -c main.cpp
	
commands.o: commands.cpp
	g++ -c commands.cpp
	  
clean:
	rm -rf *o P1
