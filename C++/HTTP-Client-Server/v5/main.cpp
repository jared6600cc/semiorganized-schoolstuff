/*
 *
 *
 */
 
 
#include <exception>
#include "../../../../../Users/jared/source/repos/P1HTTP/P1HTTP/Server.h"
#include <iostream>
#include "../../../../../Users/jared/source/repos/P1HTTP/P1HTTP/Socket.h"
using namespace std;


#define PORT 60001			// valid range: 60001 - 60099

 /* Main */
 int main(int argc, char *argv[]){

	 // Try to create server; exit if error.
	 try {
		 Server s = Server(PORT);
		 // Start listening for connections (forever)
		 while (true) {
			 Socket newSock;
			 s.accept(newSock);
		 }
	 }
	 catch (exception e) {
		 cout << "Error creating server...exiting...\n";
		 exit(EXIT_FAILURE);
	 }
	 
	 return 0;
 }