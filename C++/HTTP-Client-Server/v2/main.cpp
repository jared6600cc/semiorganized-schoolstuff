/*
 *
 *
 */
 
 
#include <exception>
#include <iostream>
#include "Server.h"
#include "ServerException.h"

using namespace std;


#define PORT 60001			// valid range: 60001 - 60099

 /* Main */
 int main(){

	 // Try to create server; exit if error.
	 try {
		 Server s = Server(PORT);
		 s.run();
	 }
	 catch (ServerException& e) {
		 cout << "Error creating server...exiting...\n";
		 exit(EXIT_FAILURE);
	 }
	 
	 return 0;
 }