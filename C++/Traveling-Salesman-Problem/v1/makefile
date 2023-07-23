all: P3

P3: main.o bfTSP.o gaTSP.o
	@g++ main.o bfTSP.o gaTSP.o -o P3

main.o : main.cpp
	@g++ -c main.cpp
	
bfTSP.o : bfTSP.cpp bfTSP.hpp
	@g++ -c bfTSP.cpp
	
gaTSP.o : gaTSP.cpp gaTSP.hpp
	@g++ -c gaTSP.cpp
	
clean :
	@rm -rf *o P3
	@echo ooo shiney...
