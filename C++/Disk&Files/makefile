all: P4

P4: main.o disk.o fileSystem.o
	@g++ main.o disk.o fileSystem.o -o P4

main.o : main.cpp
	@g++ -c main.cpp
	
disk.o : disk.cpp disk.hpp
	@g++ -c disk.cpp
	
fileSystem.o : fileSystem.cpp fileSystem.hpp
	@g++ -c fileSystem.cpp
	
inode.o : inode.cpp inode.hpp
	@g++ -c inode.cpp
	
clean :
	@rm -rf *o P4
	@echo ooo shiney...
