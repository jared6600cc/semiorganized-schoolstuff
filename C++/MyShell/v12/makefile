all: P1

P1: main.o myshell.o
	@g++ main.o myshell.o -o P1
	
main.o : main.cpp
	@g++ -c main.cpp
	
myshell.o : myshell.cpp
	@g++ -c myshell.cpp

clean : 
	@rm -rf *o P1
	@echo oooo shiney...
