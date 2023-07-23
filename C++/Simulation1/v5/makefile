all: P2

P2: main.o heap.o
	@g++ main.o heap.o -o P2

main.o : main.cpp
	@g++ -c main.cpp
	
heap.o : heap.cpp heap.hpp
	@g++ -c heap.cpp
	
clean :
	@rm -rf *o P2
	@echo ooo shiney...
